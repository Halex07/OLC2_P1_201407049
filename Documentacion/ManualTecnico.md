# Manual Técnico

_Proyecto de Organización de lenguajes y Compiladores 2_

## JavaLang - Proyecto 1



| Nombre:                     | Carné     |
| --------------------------- | --------- |
| Henry Alexander García Montúfar   | 201407049 |

/* del parser */
int yyparse(void);
extern FILE *yyin;

/* arreglo global de instrucciones construido por el parser */
extern struct NodoBase *g_root;

// =========================  archivo dot ===============================
static int nodo_counter = 0;

// --- Función auxiliar: devuelve lista de hijos de un nodo ---
static int get_children(NodoBase *node, NodoBase **out_children, int max_children) {
    int count = 0;

    if (!node) return 0;

    if (strstr(node->nombre, "Operation")) {
        Operation *op = (Operation *)node;
        if (op->izq && count < max_children) out_children[count++] = op->izq;
        if (op->der && count < max_children) out_children[count++] = op->der;
    }
    else if (strstr(node->nombre, "Block")) {
        Block *block = (Block *)node;
        StmtCell *cur = block->head;
        while (cur && count < max_children) {
            out_children[count++] = cur->stmt;
            cur = cur->next;
        }
    }
    else if (strstr(node->nombre, "Function")) {
        Function *func = (Function *)node;
        Param *cur = func->params;
        while (cur && count < max_children) {
            out_children[count++] = (NodoBase *)cur;
            cur = cur->next;
        }
        if (func->body && count < max_children) out_children[count++] = func->body;
    }
    else if (strstr(node->nombre, "Declaration")) {
        Declaration *decl = (Declaration *)node;
        if (decl->expr && count < max_children) out_children[count++] = decl->expr;
    }
    else if (strstr(node->nombre, "CallFunc")) {
        CallFunc *call = (CallFunc *)node;
        ArgList *arg = call->args;
        while (arg && count < max_children) {
            if (arg->expr) out_children[count++] = arg->expr;
            arg = arg->next;
        }
    }

    return count;
}


/**
 * Clase base abstracta para todas las instrucciones/expresiones.
 */
public abstract class Instruction {
    protected int row;
    protected int column;

    public Instruction(int row, int column) {
        this.row = row;
        this.column = column;
    }

    // Ejecutar en interpretación
    public abstract Object execute(Tree tree, Environment table);

    // Compilar / generar C3D (3 direcciones)
    public abstract void compile(Generator generator, Environment env);
}

- compilador que trabaja con un árbol de sintaxis abstracta (AST).

Incluye varios headers (ast.h, declaration.h, function.h, etc.) que definen los tipos de nodos del AST.

Usa un parser generado (probablemente con Flex/Bison), porque aparece yyparse() y yyin.

El AST raíz se guarda en g_root, que es un NodoBase *.

Lo importante: la función get_children
static int get_children(NodoBase *node, NodoBase **out_children, int max_children)


👉 Esta función recibe:

node: un puntero a un nodo del AST.

out_children: un arreglo donde se guardarán los hijos del nodo.

max_children: el tamaño máximo permitido en out_children.

Devuelve un entero que indica cuántos hijos encontró.

Cómo funciona

Si node es NULL, no hace nada → retorna 0.

if (!node) return 0;


Según el tipo de nodo (se detecta con strstr(node->nombre, "...")), busca y guarda los hijos:

Operation
Un nodo binario (por ejemplo, a + b).

if (op->izq) → hijo izquierdo
if (op->der) → hijo derecho


Block
Contiene una lista de sentencias (como { stmt1; stmt2; }).
Recorre la lista enlazada (StmtCell *cur) y va agregando cada stmt como hijo.

Function
Representa una función.

params → lista de parámetros
body   → el bloque de la función


Declaration
Una declaración de variable.

expr → expresión de inicialización (si existe)


CallFunc
Una llamada a función.

args → lista de expresiones que son los argumentos


Cada hijo encontrado se guarda en el arreglo out_children[] y se aumenta count.

Al final, devuelve count, es decir, el número total de hijos encontrados para ese nodo.

### Execute:
    execute(tree, table) {}
Este método es el que se llamara para ejecutar una instrucción If que venga en la gramática.
#### Parámetros
  - #### tree:
    Es una clase que crea un objeto que simulará un AST en el cual guardará toda la información de la entrada a interpretar, variables, funciones, metodos etc.
  - #### table:
    Simula una tabla de símbolos que se ejecutará en los entornos, en esta guardarán todas las variables necesarias para la ejecución de los mismos.


### Compile:

    compile(generator, env){}
  Este método es el que se llamará para traducir una instrucción If que venga en el archivo de entrada para crear el C3D en C.
  

#### Parámetros
- #### generator:
  Es un objeto que se encargá de crear e ir agregando el código traducido en 3 direcciones de la entrada a ejecutar.
- #### env:
  Es un entorno que guarda la tabla de simbolos que se utilizará en la ejecución de la traducción del codigo de 3 direcciones, a diferencia de la tabla de simbolos utilizada en la interpretación, en esta cada simbolo guardá información de la posición en el stack por cada variable.

## 📋 Declaracion
   

public class Declaration extends Instruction {
    private String type;
    private String identifier;
    private Instruction expression;

    public Declaration(String type, String identifier, Instruction expression, int row, int column) {
        super(row, column);
        this.type = type;
        this.identifier = identifier;
        this.expression = expression;
    }

    @Override
    public Object execute(Tree tree, Environment table) {
        throw new UnsupportedOperationException("Implementar ejecución");
    }

    @Override
    public void compile(Generator generator, Environment env) {
        throw new UnsupportedOperationException("Implementar compilación");
    }
}

- ### Descripcion: 
  En la clase Declaracion esta extendida a Instruction esto es porque le definimos que Instruccion sera padre de la clase Declaracion.
  
  Se utiliza para guardar la informacion para declarar variables y asignarles valores .
- ### Constructor: 
  Este constructor nos ayudara para mayor facilidad a la hora de mandar los datos desde jison la gramatica.
  
    #### Parametros
    - identifier: variable que vamos a declarar.
    - expression: la expresion que se le va a asignar a la variable si en un caso tiene una asignacion, si no solo se declara.
    - type: tipo de variable sera int,double entre otras.
    - row:  para llevar control de la linea.
    - column:  para llevar control de la columna.
- ### normalDeclaration: 
  Metodo para solo declarar una variable normal en C3D.

- ### multipleDeclaration: 
  Metodo que sera para declaracion multiple en C3D.

## 📋 Asignacion
    

public class Assignation extends Instruction {
    private String identifier;
    private Instruction expression;
    private String type; // puede ser null

    public Assignation(String identifier, Instruction expression, int row, int column) {
        super(row, column);
        this.identifier = identifier;
        this.expression = expression;
        this.type = null;
    }

    @Override
    public Object execute(Tree tree, Environment table) {
        throw new UnsupportedOperationException();
    }

    @Override
    public void compile(Generator generator, Environment env) {
        throw new UnsupportedOperationException();
    }
}


- ### Descripcion: 
  En la clase Asignacion esta extendida a Instruction esto es porque le definimos que Instruccion sera padre de la clase Asignacion.
  Se utiliza para reasignar el valor de una variable ya declarada.
- ### Constructor: 
  Este constructor nos ayudara para mayor facilidad a la hora de mandar los datos desde jison la gramatica.
  
    #### Parametros
    - identifier: variable que vamos a asignarle nuevo valor.
    - expression: la expresion que se le va a asignar a la variable.
    - type: se le asigna null ya que es una asignacion y la validacion de tipos se hace en execute.
    - row:  para llevar control de la linea.
    - column:  para llevar control de la columna.

## 📋 If
 

import java.util.List;

public class If extends Instruction {
    private Instruction condition;
    private List<Instruction> instructionsIf;
    private List<Instruction> instructionsElse;

    public If(Instruction condition, List<Instruction> instructionsIf, List<Instruction> instructionsElse, int row, int column) {
        super(row, column);
        this.condition = condition;
        this.instructionsIf = instructionsIf;
        this.instructionsElse = instructionsElse;
    }

    @Override
    public Object execute(Tree tree, Environment table) {
        throw new UnsupportedOperationException();
    }

    @Override
    public void compile(Generator generator, Environment env) {
        throw new UnsupportedOperationException();
    }
}


- ### Descripcion: 
  En la clase If esta extendida a Instruction esto es porque le definimos que Instruccion sera padre de la clase If.

  Ejecucion de instrucciones if que adentro pueden venir mas instrucciones desde un print hasta llamadas de funciones.
- ### Constructor: 
  Este constructor nos ayudara para mayor facilidad a la hora de mandar los datos desde jison la gramatica.
  
    #### Parametros
    - condition: la condicional que viene a evaluar en el if.
    - instructionIf: Instrucciones si solo viene un if.
    - InstruccionsElse: Instrucciones si en un caso viene else if o  else.
    - row:  para llevar control de la linea.
    - column:  para llevar control de la columna.
## 📋 Switch
   

import java.util.List;

public class Switch extends Instruction {
    private Instruction condition;
    private List<Instruction> instructionsCase;

    public Switch(Instruction condition, List<Instruction> instructionsCase, int row, int column) {
        super(row, column);
        this.condition = condition;
        this.instructionsCase = instructionsCase;
    }

    @Override
    public Object execute(Tree tree, Environment table) { throw new UnsupportedOperationException(); }

    @Override
    public void compile(Generator generator, Environment env) { throw new UnsupportedOperationException(); }
}

- ### Descripcion: 
  En la clase Switch esta extendida a Instruction esto es porque le definimos que Instruccion sera padre de la clase Switch.
  
  Ejecucion de instrucciones Switch que adentro pueden venir mas instrucciones desde un print hasta llamadas de funciones, tambien se hace el llamado de break cada vez que la condicional sea correcta para poder salir del switch.
- ### Constructor: 
  Este constructor nos ayudara para mayor facilidad a la hora de mandar los datos desde jison la gramatica.
  
    #### Parametros
    - condition: la condicional que viene a evaluar en el switch.
    - instructionCase:  Instrucciones de cada case.
    - row:  para llevar control de la linea.
    - column:  para llevar control de la columna.



## 📋 For
    

import java.util.List;

public class For extends Instruction {
    private Instruction variable;
    private Instruction condition;
    private Instruction incDecre;
    private List<Instruction> instructionsFor;

    public For(Instruction variable, Instruction condition, Instruction incDecre, List<Instruction> instructionsFor, int row, int column) {
        super(row, column);
        this.variable = variable;
        this.condition = condition;
        this.incDecre = incDecre;
        this.instructionsFor = instructionsFor;
    }

    // métodos auxiliares mencionados en el manual (verifyId, verifyExistId) pueden implementarse aquí

    @Override public Object execute(Tree tree, Environment table){ throw new UnsupportedOperationException(); }
    @Override public void compile(Generator generator, Environment env){ throw new UnsupportedOperationException(); }
}

- ### Descripcion: 
  En la clase For esta extendida a Instruction esto es porque le definimos que Instruccion sera padre de la clase For.
- ### Constructor: 
  Este constructor nos ayudara para mayor facilidad a la hora de mandar los datos desde jison la gramatica.
  
    #### Parametros
    - variable: variable que puede ir decrementando o incrementable que se puede declarar ahi mismo o puede que ya exista en un entorno anterior.
    - condition: la condicional que viene a evaluar en el for.
    - instructions_for:  Instrucciones del for.
    - inc_decre: mandamos si es incrementable o decrementable que venga asi se ejecuta.
    - row:  para llevar control de la linea.
    - column:  para llevar control de la columna.

- ### verifyId:
  Verificamos si la varible que viene sea la misma que venga en inc_decre, si no lo tomamos como error semantico.
- ### verifyExistId: 
  Este nos ayuda a verificar si la variable que viene ya existe si en un caso no venga una declaracion, si no viene el tipo para declarar y existe entonces se retorna la informacion de dicha variable.

## 📋 For In
   

import java.util.List;

public class ForIn extends Instruction {
    private String identifier;
    private Instruction expression;
    private List<Instruction> instructions;

    public ForIn(String identifier, Instruction expression, List<Instruction> instructions, int row, int column) {
        super(row, column);
        this.identifier = identifier;
        this.expression = expression;
        this.instructions = instructions;
    }

    @Override public Object execute(Tree tree, Environment table){ throw new UnsupportedOperationException(); }
    @Override public void compile(Generator generator, Environment env){ throw new UnsupportedOperationException(); }
}

    
- ### Descripcion: 
En la clase For in  esta extendida a Instruction esto es porque le definimos que Instruccion sera padre de la clase For in.

Para recorrer una cadena de string o un array de valores desde un rango de posiciones del array.
- ### Constructor: 
  Este constructor nos ayudara para mayor facilidad a la hora de mandar los datos desde jison la gramatica.
  
    #### Parametros
    - identifier: variable que recorrera el for in.
    - expression: la expresion que viene a evaluar en el for puede ser una operacion o un array o string que recorrerlo entre otros.
    - instructions:  Instrucciones del for in.    
    - row:  para llevar control de la linea.
    - column:  para llevar control de la columna.
## 📋 While
    class While extends Instruction{
        constructor(condition, instructions, row, column){
            super(row, column);
            this.condition = condition;
            this.instructions = instructions; 
        }
    }
- ### Descripcion: 
  En la clase While esta extendida a Instruction esto es porque le definimos que Instruccion sera padre de la clase While.

  Validamos las condicionales llamandola desde otra clase que se llama condicion en la cual evaluamos si es falso o verdadero, si es falso seguimos ejecutando las instrucciones del while, si no nos salimos.
- ### Constructor: 
  Este constructor nos ayudara para mayor facilidad a la hora de mandar los datos desde jison la gramatica.
  
    #### Parametros
    - condition: la condicional que viene a evaluar.
    - instructions:  Instrucciones del while.    
    - row:  para llevar control de la linea.
    - column:  para llevar control de la columna.
  
## 📋 Do While
    

import java.util.List;

public class While extends Instruction {
    private Instruction condition;
    private List<Instruction> instructions;

    public While(Instruction condition, List<Instruction> instructions, int row, int column) {
        super(row, column);
        this.condition = condition;
        this.instructions = instructions;
    }

    @Override public Object execute(Tree tree, Environment table){ throw new UnsupportedOperationException(); }
    @Override public void compile(Generator generator, Environment env){ throw new UnsupportedOperationException(); }
}

public class Do extends Instruction {
    private Instruction condition;
    private List<Instruction> instructions;

    public Do(Instruction condition, List<Instruction> instructions, int row, int column) {
        super(row, column);
        this.condition = condition;
        this.instructions = instructions;
    }

    @Override public Object execute(Tree tree, Environment table){ throw new UnsupportedOperationException(); }
    @Override public void compile(Generator generator, Environment env){ throw new UnsupportedOperationException(); }
}

- ### Descripcion: 
 En la clase Do esta extendida a Instruction esto es porque le definimos que Instruccion sera padre de la clase Do.

 ejecutamos y despues Validamos las condicionales llamandola desde otra clase que se llama condicion en la cual evaluamos si es falso o verdadero, si es falso seguimos ejecutando las instrucciones del while, si no nos salimos.
- ### Constructor: 
  Este constructor nos ayudara para mayor facilidad a la hora de mandar los datos desde jison la gramatica.
  
    #### Parametros
    - condition: la condicional que viene a evaluar.
    - instructions:  Instrucciones del do while.    
    - row:  para llevar control de la linea.
    - column:  para llevar control de la columna.


## 📋 Post Fixes
    

public class PostFixed extends Instruction {
    private String identifier;
    private String action; // "++" o "--"
    private String type;

    public PostFixed(String identifier, String action, int row, int column) {
        super(row, column);
        this.identifier = identifier;
        this.action = action;
        this.type = null;
    }

    @Override public Object execute(Tree tree, Environment table){ throw new UnsupportedOperationException(); }
    @Override public void compile(Generator generator, Environment env){ throw new UnsupportedOperationException(); }
}

- ### Descripcion: 
 En la clase Post Fixes esta extendida a Instruction esto es porque le definimos que Instruccion sera padre de la clase Post Fixes.

 Aqui hacemos las validaciones para incrementar o decrementar una variable la podemos hacer llamar desde otra clase cuando la necesitamos.
- ### Constructor: 
  Este constructor nos ayudara para mayor facilidad a la hora de mandar los datos desde jison la gramatica.
  
    #### Parametros
    - identifier: variable que vamos a asignarle nuevo valor.
    - action: la accion si se le incrementa el valor a la variable o decrementa.   
    - row:  para llevar control de la linea.
    - column:  para llevar control de la columna.

## 📋 Print
    package com.JavaLang.ast;

public class Print extends Instruction {
    private Instruction expression;
    private boolean jump;

    public Print(int row, int column, Instruction expression, boolean jump) {
        super(row, column);
        this.expression = expression;
        this.jump = jump;
    }

    @Override public Object execute(Tree tree, Environment table){ throw new UnsupportedOperationException(); }
    @Override public void compile(Generator generator, Environment env){ throw new UnsupportedOperationException(); }
}

- ### Descripcion: 
  En la clase Print esta extendida a Instruction esto es porque le definimos que Instruccion sera padre de la clase Print.
  Aqui podemos mandar a imprimir en consola las ejecuciones desde una funcion que me trae un valor o de un nodo hasta operaciones y condiciones.
- ### Constructor: 
  Este constructor nos ayudara para mayor facilidad a la hora de mandar los datos desde jison la gramatica.
  
    #### Parametros
    - expression: lo que deseamos imprimir en la ejecucion.
    - jump: si es con salto de linea o sin salto.   
    - row:  para llevar control de la linea.
    - column:  para llevar control de la columna.
  
## 📋 Break
    

public class Break extends Instruction {
    public Break(int row, int column) { super(row, column); }
    @Override public Object execute(Tree tree, Environment table){ throw new UnsupportedOperationException(); }
    @Override public void compile(Generator generator, Environment env){ throw new UnsupportedOperationException(); }
}

public class Continue extends Instruction {
    public Continue(int row, int column) { super(row, column); }
    @Override public Object execute(Tree tree, Environment table){ throw new UnsupportedOperationException(); }
    @Override public void compile(Generator generator, Environment env){ throw new UnsupportedOperationException(); }
}

public class Return extends Instruction {
    private Instruction expression;
    private String type;
    private Object result;

    public Return(Instruction expression, int row, int column) {
        super(row, column);
        this.expression = expression;
        this.type = null;
        this.result = null;
    }

    @Override public Object execute(Tree tree, Environment table){ throw new UnsupportedOperationException(); }
    @Override public void compile(Generator generator, Environment env){ throw new UnsupportedOperationException(); }
}

- ### Descripcion: 
  En la clase Break esta extendida a Instruction esto es porque le definimos que Instruccion sera padre de la clase Break.
  Llamada de funcion cuando venga un break en una instruccion hace que salga de dicha instruccion.
- ### Constructor: 
  Este constructor nos ayudara para mayor facilidad a la hora de mandar los datos desde jison la gramatica.
  
    #### Parametros
    - row:  para llevar control de la linea.
    - column:  para llevar control de la columna.
    



## 📋 Return
    class Return extends Instruction {
        constructor(expression, row, column) {
            super(row, column);
            this.expression = expression;
            this.type = null;
            this.result = null;
        }
    }
- ### Descripcion: 
  En la clase return esta extendida a Instruction esto es porque le definimos que Instruccion sera padre de la clase return.
  
  Returna un valor en una funcion en una instruccion, el return puede venir vacio como retornar un valor como tal.
- ### Constructor: 
  Este constructor nos ayudara para mayor facilidad a la hora de mandar los datos desde jison la gramatica.
  
    #### Parametros
    - expresion: que se va a retornar.
    - type: que se le manda bandera null para poder validar en el execute.
    - result: igual es para validar en execute.
    - row:  para llevar control de la linea.
    - column:  para llevar control de la columna.

## 📋 Continue
    class Continue extends Instruction{
        constructor(row, column){
            super(row, column);
        }
    }
- ### Descripcion: 
  En la clase Continue esta extendida a Instruction esto es porque le definimos que Instruccion sera padre de la clase Continue.
  
  
- ### Constructor: 
  Este constructor nos ayudara para mayor facilidad a la hora de mandar los datos desde jison la gramatica.
  
    #### Parametros
    - row:  para llevar control de la linea.
    - column:  para llevar control de la columna.
## 📋 TemplateStruct
    class TemplateStruct extends Instruction {
      constructor(name, parameters, row, column) {
        super(row, column);
        this.name = name;
        this.parameters = parameters;
      }
- ### Descripción: 
  Es utilizada para guardar la información para la creación de structs de este tipo, define las variables que cada objeto contendrá en su interior al igual que el tipo del struct creado.
  
    #### Parámetros del constructor
    - name: Nombre que se le asigna a la plantilla de struct que se cargará al sistema.
    - parameters: Lista de parámetros con los que debe cumplir cada instancia de struct.
    - row: Para llevar control de la línea.
    - column: Para llevar control de la columna.

## 📋 Structs


import java.util.List;

public class TemplateStruct extends Instruction {
    private String name;
    private List<Param> parameters;

    public TemplateStruct(String name, List<Param> parameters, int row, int column) {
        super(row, column);
        this.name = name;
        this.parameters = parameters;
    }

    @Override public Object execute(Tree tree, Environment table){ throw new UnsupportedOperationException(); }
    @Override public void compile(Generator generator, Environment env){ throw new UnsupportedOperationException(); }
}

public class CreateStruct extends Instruction {
    private String structName;
    private String nameObject;
    private String structName2;
    private List<Param> parameters;

    public CreateStruct(String structName, String nameObject, String structName2, List<Param> parameters, int row, int column) {
        super(row, column);
        this.structName = structName;
        this.nameObject = nameObject;
        this.structName2 = structName2;
        this.parameters = parameters;
    }

    @Override public Object execute(Tree tree, Environment table){ throw new UnsupportedOperationException(); }
    @Override public void compile(Generator generator, Environment env){ throw new UnsupportedOperationException(); }
}

public class AccessAtributeStruct extends Instruction {
    private String id;
    private List<Param> parameters;
    private String type;
    private String objectType;

    public AccessAtributeStruct(String id, List<Param> parameters, int row, int column) {
        super(row, column);
        this.id = id;
        this.parameters = parameters;
        this.type = null;
        this.objectType = null;
    }

    @Override public Object execute(Tree tree, Environment table){ throw new UnsupportedOperationException(); }
    @Override public void compile(Generator generator, Environment env){ throw new UnsupportedOperationException(); }
}

public class ChangeValueStruct extends Instruction {
    private String id;
    private List<Param> parameters;
    private Instruction expression;

    public ChangeValueStruct(String id, List<Param> parameters, Instruction expression, int row, int column) {
        super(row, column);
        this.id = id;
        this.parameters = parameters;
        this.expression = expression;
    }

    @Override public Object execute(Tree tree, Environment table){ throw new UnsupportedOperationException(); }
    @Override public void compile(Generator generator, Environment env){ throw new UnsupportedOperationException(); }
}

- ### Descripción: 
  En esta clase se envía la información del struct que se desea crear, obtiene el identificador con el que se nombrará el objeto, el nombre de la plantilla del struct a crear y los Parámetros que se le asignaran a sus variables.
  
    #### Parámetros del constructor
    - structName: Nombre de la plantilla de struct que se solicita crear.
    - nameObject: Nombre que se le asignará a la instancia del objeto struct.
    - parameters: Lista de parámetros con los que debe cumplir cada instancia de struct.
    - row: Para llevar control de la línea.
    - column: Para llevar control de la columna.

## 📋 AccessAtributeStruct
    class AccessAtributeStruct extends Instruction{
      constructor(id, parameters, row, column){
        super(row, column);
        this.id = id;
        this.parameters = parameters;
        this.type = null;
        this.objectType = null;
      }
- ### Descripción: 
  Para obtener el o los valores que un objeto struct contiene utilizamos esta clase en la cual hacemos hacemos una busqueda en los Parámetros que este posee hasta dar en el que se solicita, una vez encontrado se devuelve para la operación que se desea realizar.
  
    #### Parámetros del constructor
    - id: Nombre de la instancia del objeto struct que se solicita.
    - parameters: Lista de parámetros con los que debe cumplir cada instancia de struct.
    - row: Para llevar control de la línea.
    - column: Para llevar control de la columna.

## 📋 ChangeValueStruct
    class ChangeValueStruct extends Instruction{
      constructor(id, parameters, expression, row, column){
        super(row, column);
        this.id = id;
        this.expression = expression;
        this.parameters = parameters;
      }
- ### Descripción: 
  Cuando se desea cambiar el valor que un atributo de los objetos de tipo struct que se  poseen se utiliza esta clase.
  
    #### Parámetros del constructor
    - id: Nombre de la instancia del objeto struct que se solicita.
    - parameters: Lista de parámetros con los que debe cumplir cada instancia de struct.
    - expression: Al ejecutar esta obtenemos el nuevo valor que se asignará al atributo.
    - row: Para llevar control de la línea.
    - column: Para llevar control de la columna.

## 📋 DeclarationArray
    class DeclarationArray extends Instruction {
      constructor(type, identifier, listObjects, row, column) {
        super(row, column);
        this.type = type;
        this.identifier = identifier;
        this.listObjects = listObjects;
      }
- ### Descripción: 
  Esta clase es utilizada para la creación de arreglos y así almacenar toda la información necesaria para guardarlos.
  
    #### Parámetros del constructor
    - tye: Nombre del dato primitivo para referenciar el tipo de dato que contendrá el arreglo.
    - identifier: Identificador del objeto de tipo arreglo que se va a crear.
    - listObjects: Lista de expresiones que que se le asignará al arreglo.
    - row: Para llevar control de la línea.
    - column: Para llevar control de la columna.

## 📋 AccessArray
    class AccessArray extends Instruction{
      constructor(id, parameters, row, column){
        super(row, column);
        this.id = id;
        this.parameters = parameters;
        this.type = null;
        this.objectType = null;
      }
- ### Descripción: 
  Esta clase es utilizada para obtener un valor en específico al cual se desea acceder, el mismo es enviada en una posición.
  
    #### Parámetros del constructor
    - id: Identificador del objeto de tipo arreglo al que se va a acceder.
    - parameters: Lista posiciones en las cuales se buscará un valor.
    - row: Para llevar control de la línea.
    - column: Para llevar control de la columna.

## 📋 ChangeValueArray
    class ChangeValueArray extends Instruction{
      constructor(id, parameters, expression, row, column){
        super(row, column);
        this.id = id;
        this.expression = expression;
        this.parameters = parameters;
        this.type = null;
      }
- ### Descripción: 
  Cuando se desea cambiar el valor de una posición de un arreglo se utiliza esta clase.
  
    #### Parámetros del constructor
    - id: Identificador del objeto de tipo arreglo al que se va a acceder.
    - parameters: Lista posiciones en las cuales se buscará un valor.
    - expression: Al ejecutar esta obtenemos el nuevo valor que se asignará al atributo.
    - row: Para llevar control de la línea.
    - column: Para llevar control de la columna.

## 📋 CopyArray
    class CopyArray extends Instruction{
      constructor(id, row, column){
        super(row, column);
        this.id = id;
        this.type = null;
        this.objectType = null;
      }
- ### Descripción: 
  Debido a que JavaLang maneja los arreglos por referencia, en el momento que se desea crear una copia exactamente igual de un arreglo pero independiente del mismo se utiliza esta clase.
  
    #### Parámetros del constructor
    - id: Identificador del objeto de tipo arreglo al que se va a acceder.
    - row: Para llevar control de la línea.
    - column: Para llevar control de la columna.

## 📋 RangeArray
    class RangeArray extends Instruction{
      constructor(id, left, right, row, column){
        super(row, column);
        this.id = id;
        this.left = left;
        this.right = right;
        this.type = null;
        this.objectType = null;
      }
- ### Descripción: 
  Para interactuar con tramos en específico de un arreglo se hace uso de esta clase, misma que devuelve un tramo del arreglo.
  
    #### Parámetros del constructor
    - id: Identificador del objeto de tipo arreglo al que se va a acceder.
    - left: Posición inicial que se busca del arreglo.
    - right: Posición final que se busca del arreglo.
    - row: Para llevar control de la línea.
    - column: Para llevar control de la columna.

## 📋 Function
    package com.JavaLang.ast;

import java.util.List;

public class Function extends Instruction {
    private String type;
    private String name;
    private List<Param> parameters;
    private List<Instruction> instructions;
    private String objectType;

    public Function(String type, String name, List<Param> parameters, List<Instruction> instructions, int row, int column, String objectType) {
        super(row, column);
        this.type = type;
        this.name = name;
        this.parameters = parameters;
        this.instructions = instructions;
        this.objectType = objectType;
    }

    @Override public Object execute(Tree tree, Environment table){ throw new UnsupportedOperationException(); }
    @Override public void compile(Generator generator, Environment env){ throw new UnsupportedOperationException(); }
}

public class CallFunction extends Instruction {
    private String name;
    private List<Instruction> parameters;
    private boolean forArray;
    private String type;
    private String objectType;

    public CallFunction(String name, List<Instruction> parameters, boolean forArray, int row, int column) {
        super(row, column);
        this.name = name;
        this.parameters = parameters;
        this.forArray = forArray;
        this.type = null;
        this.objectType = null;
    }

    @Override public Object execute(Tree tree, Environment table){ throw new UnsupportedOperationException(); }
    @Override public void compile(Generator generator, Environment env){ throw new UnsupportedOperationException(); }
}

public class Natives extends Instruction { // llamadas nativas del lenguaje
    private String name;
    private List<Instruction> parameters;
    private boolean forArray;
    private String type;
    private String objectType;

    public Natives(String name, List<Instruction> parameters, boolean forArray, int row, int column) {
        super(row, column);
        this.name = name;
        this.parameters = parameters;
        this.forArray = forArray;
        this.type = null;
        this.objectType = null;
    }

    @Override public Object execute(Tree tree, Environment table){ throw new UnsupportedOperationException(); }
    @Override public void compile(Generator generator, Environment env){ throw new UnsupportedOperationException(); }
}

public class NativeMethods extends Instruction {
    private String name;
    private String method;
    private List<Instruction> parameters;
    private String type;

    public NativeMethods(String name, String method, List<Instruction> parameters, int row, int column) {
        super(row, column);
        this.name = name;
        this.method = method;
        this.parameters = parameters;
        this.type = null;
    }

    @Override public Object execute(Tree tree, Environment table){ throw new UnsupportedOperationException(); }
    @Override public void compile(Generator generator, Environment env){ throw new UnsupportedOperationException(); }
}

- ### Descripción: 
  Crea una función en el sistema guardando toda la información necesaria para la posteriór ejecución.
  
    #### Parámetros del constructor
    - type: Tipo de retorno para el valor que develve la función.
    - name: Nombre que se le asignará a la función.
    - parameters: Lista de parámetros que recibe la función.
    - instructions: Lista de instrucciones que se ejecutarán en una llamada de función.
    - row: Para llevar control de la línea.
    - column: Para llevar control de la columna.
    - objectType: Tipo de objeto que retorna, en caso se devuelva un arreglo o struct.

## 📋 CallFunction
    class CallFunction extends Instruction {
      constructor(name, parameters, forArray, row, column) {
        super(row, column);
        this.name = name;
        this.parameters = parameters;
        this.forArray = forArray;
        this.type = null;
        this.objectType = null;
      }
- ### Descripción: 
  Objeto que se encargará de realizar una llamada de función para luego ejecutarla.
  
    #### Parámetros del constructor
    - name: Nombre de la función que se llama.
    - parameters: Lista de parámetros que recibe la función.
    - forArray: Parámetro booleano que se envia para saber si es una función nativa de arreglos.
    - row: Para llevar control de la línea.
    - column: Para llevar control de la columna.

## 📋 Natives
    class Natives extends Instruction {
      constructor(name, parameters, forArray, row, column) {
        super(row, column);
        this.name = name;
        this.parameters = parameters;
        this.forArray = forArray;
        this.type = null;
        this.objectType = null;
      }
- ### Descripción: 
  Objeto que se encargará de realizar una llamada de función nativa, propia de JavaLang, para luego ejecutarla.
  
    #### Parámetros del constructor
    - name: Nombre de la función nativa a llamar.
    - parameters: Lista de parámetros que recibe la función.
    - forArray: Parámetro booleano que se envia para saber si es una función nativa de arreglos.
    - row: Para llevar control de la línea.
    - column: Para llevar control de la columna.

## 📋 NativeMethods
    class NativeMethods extends Instruction {
      constructor(name, method, parameters, row, column) {
        super(row, column);
        this.name = name;
        this.method = method;
        this.parameters = parameters;
        this.type = null;
      }
- ### Descripción: 
  Objeto que se encargará de ejecutar un metodo nativo propia de JavaLang, específico para un  tipo de objeto.
  
    #### Parámetros del constructor
    - name: Nombre del objeto al que se le aplicará el metodo.
    - method: Nombre del método nativo a ejecutar.
    - parameters: Lista de parámetros que recibe el método.
    - row: Para llevar control de la línea.
    - column: Para llevar control de la columna.

## 📋 ErrorList
    static errorList = [];
- ### Descripcion: 
  Esta clase nos ayudara para llevar el control de todos los tipos de error desde lexicos, sintacticos y semanticos.
- ### Metodos:  
    - cleanErrorList: Limpio toda la lista de errores.
    - addError:  Agrego un error a la lista de errores.
    - getErrorList: Obtengo todos los datos de la lista.
    - isErrors: Validar si tiene errores.
    - showErrors: Para imprimir en consola los errores que vengan.


## 📋 ErrorNode
  
    constructor(line, column, errorType, description, environmentType) {
        this.line = line;
        this.column = column;
        this.errorType = errorType;
        this.description = description;
        this.environmentType = environmentType;
    }
- ### Descripcion: 
  Esta clase se utiliza para hacer un nodo el cual nos servira para ingresarlo en la lista en la clase ErrorList.
- ### Constructor: 
  Este constructor nos ayudara para mayor facilidad a la hora de mandar los datos desde jison la gramatica.
  
    #### Parametros
    - errorType: el tipo de error si es lexico, sintactico, semantico.
    - descripcion: una peque;a descripcion del error.
    - environmentType: en que entorno fue el error.
    - line:  para llevar control de la linea.
    - column:  para llevar control de la columna.
## 📋 moveDivs

    function addChild(div_id) {
        const node = document.getElementById('gist-div');
        while (node.hasChildNodes()) {
            node.removeChild(node.lastChild);
        }
        document.getElementById('gist-div').appendChild(document.getElementById(div_id).cloneNode(true))
    }
- ### Descripcion: 
    Esta clase lleva un metodo que nos ayuda a hacer el arbol interactico en ir encogiendo los padres de las producciones.
- ### Function:  
    - addChild: esta funcion nos ayuda para ir creando hijos o nodos en el arbol que se mostrara en la parte inferior de la pagina.
## 📋 ErrorType
        var EnumErrorType;
    (function (EnumErrorType) {
        EnumErrorType["LEXICO"] = "LEXICO";
        EnumErrorType["SYNTACTIC"] = "SINTACTICO";
        EnumErrorType["SEMANTIC"] = "SEMANTICO";
    })(EnumErrorType || (EnumErrorType = {}));
- ### Descripcion: 
    Para llamar el tipo de error que viene y me retorna el tipo de error.

## 📋 Table Report
    package com.JavaLang.ast;

import java.util.List;
import java.util.ArrayList;

public class TableReport {
    private int line;
    private int column;
    private String name;
    private String type;
    private String typeEnvironment;
    private Object value;

    public TableReport(int line, int column, String name, String type, String typeEnvironment, Object value) {
        this.line = line;
        this.column = column;
        this.name = name;
        this.type = type;
        this.typeEnvironment = typeEnvironment;
        this.value = value;
    }

    private static final List<TableReport> symbolList = new ArrayList<>();

    public static void cleanTableReport() { symbolList.clear(); }
    public static void addTableSymbol(TableReport t) { symbolList.add(t); }
    public static List<TableReport> getTableReport() { return new ArrayList<>(symbolList); }
    public static boolean isSymbols() { return !symbolList.isEmpty(); }
    public static void showSymbol() { symbolList.forEach(s -> System.out.println(s.name)); }
}

- ### Descripcion: 
Aqui se crea un Nodo tipo NodeTableSymbols el cual nos servira para guardar de forma ordenada en la lista para la tabla de simbolos.
- ### Metodos:  
    - cleanTableReport: Limpio toda la tabla de simbolos.
    - addTableSymbol:  Agrego un simbolo a la tabla de simbolos.
    - getTableReport: Obtengo todos los datos de la lista.
    - isSymbols: Validar si tiene simbolos.
    - showSymbol: Para imprimir en consola los simbolos que vengan.


## 📋 Aritmetica
    package com.JavaLang.ast;

public class Aritmetica extends Instruction {
    private Instruction operLeft;
    private String operator;
    private Instruction operRight;
    private String type;
    private String objectType;
    private String trueLbl;
    private String falseLbl;
    private String structType;

    public Aritmetica(Instruction operLeft, String operator, Instruction operRight, int row, int column) {
        super(row, column);
        this.operator = operator;
        this.operLeft = operLeft;
        this.operRight = operRight;
        this.type = null;
        this.objectType = null;
        this.trueLbl = "";
        this.falseLbl = "";
        this.structType = "";
    }

    @Override public Object execute(Tree tree, Environment table){ throw new UnsupportedOperationException(); }
    @Override public void compile(Generator generator, Environment env){ throw new UnsupportedOperationException(); }
}

public class Logic extends Instruction {
    private Instruction operLeft;
    private String operator;
    private Instruction operRight;
    private final String type = "BOOLEAN";
    private String trueLbl;
    private String falseLbl;
    private String structType;

    public Logic(Instruction operLeft, String operator, Instruction operRight, int row, int column) {
        super(row, column);
        this.operator = operator;
        this.operLeft = operLeft;
        this.operRight = operRight;
        this.trueLbl = "";
        this.falseLbl = "";
        this.structType = "";
    }

    @Override public Object execute(Tree tree, Environment table){ throw new UnsupportedOperationException(); }
    @Override public void compile(Generator generator, Environment env){ throw new UnsupportedOperationException(); }
}

public class Relational extends Instruction {
    private Instruction operLeft;
    private String operator;
    private Instruction operRight;
    private final String type = "BOOLEAN";
    private String trueLbl;
    private String falseLbl;
    private String structType;

    public Relational(Instruction operLeft, String operator, Instruction operRight, int row, int column) {
        super(row, column);
        this.operator = operator;
        this.operLeft = operLeft;
        this.operRight = operRight;
        this.trueLbl = "";
        this.falseLbl = "";
        this.structType = "";
    }

    @Override public Object execute(Tree tree, Environment table){ throw new UnsupportedOperationException(); }
    @Override public void compile(Generator generator, Environment env){ throw new UnsupportedOperationException(); }
}

public class Identifier extends Instruction {
    private String identifier;
    private String type;
    private String objectType;
    private Environment env;
    private String trueLbl;
    private String falseLbl;

    public Identifier(String identifier, int row, int column, Environment env) {
        super(row, column);
        this.identifier = identifier;
        this.type = null;
        this.objectType = null;
        this.env = env;
        this.trueLbl = "";
        this.falseLbl = "";
    }

    @Override public Object execute(Tree tree, Environment table){ throw new UnsupportedOperationException(); }
    @Override public void compile(Generator generator, Environment env){ throw new UnsupportedOperationException(); }
}

public class Primitive extends Instruction {
    private String type;
    private Object value;
    private String trueLbl;
    private String falseLbl;
    private String objectType;

    public Primitive(String type, Object value, int row, int column) {
        super(row, column);
        this.type = type;
        this.value = value;
        this.trueLbl = "";
        this.falseLbl = "";
        this.objectType = "";
    }

    @Override public Object execute(Tree tree, Environment table){ return value; } // ejemplo simple
    @Override public void compile(Generator generator, Environment env){ throw new UnsupportedOperationException(); }
}

public class Strings extends Instruction {
    private Instruction operLeft;
    private String operator;
    private Instruction operRight;
    private String type;

    public Strings(Instruction operLeft, String operator, Instruction operRight, int row, int column) {
        super(row, column);
        this.operator = operator;
        this.operLeft = operLeft;
        this.operRight = operRight;
        this.type = null;
    }

    @Override public Object execute(Tree tree, Environment table){ throw new UnsupportedOperationException(); }
    @Override public void compile(Generator generator, Environment env){ throw new UnsupportedOperationException(); }
}

- ### Descripción: 
  Clase que se encargará de realizar todas las operaciones relacionadas a interactuar con números, sumas, restas, multiplicaciones, divisiones, modulo, etc.
  
    #### Parámetros del constructor
    - operLeft: Expresión del operador izquierdo a ejecutar.
    - operator: Tipo de operación a ejecutar.
    - operRight: Expresión del operador izquierdo a ejecutar.
    - row: Para llevar control de la línea.
    - column: Para llevar control de la columna.

## 📋 Logic
    class Logic extends Instruction{
      constructor( operLeft, operator, operRight, row, column){
        super(row, column);  
        this.operator = operator;
        this.operLeft = operLeft;
        this.operRight = operRight;
        this.type = Type.BOOLEAN;
        this.trueLbl = '';
        this.falseLbl = '';
        this.structType = '';
      }
- ### Descripción: 
  Clase que se encargará de realizar todas las operaciones lógicas.
  
    #### Parámetros del constructor
    - operLeft: Expresión del operador izquierdo a ejecutar.
    - operator: Tipo de operación a ejecutar.
    - operRight: Expresión del operador izquierdo a ejecutar.
    - row: Para llevar control de la línea.
    - column: Para llevar control de la columna.

## 📋 Relational
    class Relational extends Instruction {
      constructor(operLeft, operator, operRight, row, column) {
        super(row, column);
        this.operator = operator;
        this.operLeft = operLeft;
        this.operRight = operRight;
        this.type = Type.BOOLEAN;
        this.trueLbl = '';
        this.falseLbl = '';
        this.structType = '';
      }
- ### Descripción: 
  Clase que se encargará de realizar todas las operaciones relacionales.
  
    #### Parámetros del constructor
    - operLeft: Expresión del operador izquierdo a ejecutar.
    - operator: Tipo de operación a ejecutar.
    - operRight: Expresión del operador izquierdo a ejecutar.
    - row: Para llevar control de la línea.
    - column: Para llevar control de la columna.

## 📋 Identifier
    class Identifier extends Instruction{
      constructor(identifier, row, column, env){
        super(row, column);    
        this.identifier = identifier;
        this.type = null;
        this.objectType = null;
        this.env = env;
        this.trueLbl = '';
        this.falseLbl = '';
        this.objectType = '';
      }
- ### Descripción: 
  Clase que se encargará de almacenar el identificador de una variable u objeto a buscar para luego obtener su valor.
  
    #### Parámetros del constructor
    - identifier: Valor que identifica a la variable creada.
    - row: Para llevar control de la línea.
    - column: Para llevar control de la columna.
    - env: Entorno en el que se creó la variable.

## 📋 Primitive
    class Primitive extends Instruction {
      constructor(type, value, row, column) {
        super(row, column);
        this.type = type;
        this.value = value;
        this.trueLbl = '';
        this.falseLbl = '';
        this.objectType = '';
      }
- ### Descripción: 
  Valor de tipo primitivo del lenguaje JavaLang, ya sea entero, cadena, caracter, booleano o double.
  
    #### Parámetros del constructor
    - type: Valor que identifica a la variable creada.
    - value: Para llevar control de la línea.
    - row: Para llevar control de la línea.
    - column: Para llevar control de la columna.

## 📋 Strings
    class Strings extends Instruction {
      constructor(operLeft, operator, operRight, row, column) {
        super(row, column);
        this.operator = operator;
        this.operLeft = operLeft;
        this.operRight = operRight;
        this.type = null;
      }
- ### Descripción: 
  Clase utilizada para realizar las operaciones necesarias en variables o datos primitivos que sean de tipo String.
  
    #### Parámetros del constructor
    - operLeft: Expresión del operador izquierdo a ejecutar.
    - operator: Tipo de operación a ejecutar.
    - operRight: Expresión del operador izquierdo a ejecutar.
    - row: Para llevar control de la línea.
    - column: Para llevar control de la columna.
