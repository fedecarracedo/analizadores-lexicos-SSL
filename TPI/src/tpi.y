%{
    #include "funciones.h"

    #define YYDEBUG 1
    extern int yylineno;
    extern FILE* yyin;
    int yylex();
    int yywrap() { return(1); }
    void yyerror (char const *s)  {fprintf(stderr, "Error Sintactico -> Linea %03d, %s\n", yylineno, s);}

    char buffer_tipo[100];
    char buffer_identificador[100];

    t_lista* ts;
    t_lista* parametros;
    bool funcion = false;
%}

%union {
    char* cadena;
    int entero;
    float real;
}   

// TOKENS
/*%token  <cadena>    IDENTIFIER
%token  <entero>    DEC_CONST
%token  <entero>    OCT_CONST
%token  <entero>    HEX_CONST 
%token  <real>      REAL_CONST */
%token  <cadena>    IDENTIFIER
%token  <cadena>    DEC_CONST
%token  <cadena>    OCT_CONST
%token  <cadena>    HEX_CONST 
%token  <cadena>    REAL_CONST 
%token  <cadena>    CHAR_CONST
%token  <cadena>    STR_LIT
%token  MUL_ASSIGN
%token  DIV_ASSIGN
%token  MOD_ASSIGN
%token  ADD_ASSIGN
%token  SUB_ASSIGN
%token  RIGHT_ASSIGN
%token  LEFT_ASSIGN
%token  AND_ASSIGN
%token  XOR_ASSIGN
%token  OR_ASSIGN
%token  OR_OP
%token  AND_OP
%token  EQ_OP
%token  NE_OP
%token  LE_OP
%token  GE_OP
%token  LEFT_OP
%token  RIGHT_OP
%token  INC_OP
%token  DEC_OP
%token  PTR_OP
%token  <cadena>    SIZEOF
%token  <cadena>    TYPEDEF
%token  <cadena>    STATIC
%token  <cadena>    AUTO
%token  <cadena>    REGISTER
%token  <cadena>    EXTERN
%token  <cadena>    VOID
%token  <cadena>    CHAR
%token  <cadena>    SHORT
%token  <cadena>    INT
%token  <cadena>    LONG
%token  <cadena>    FLOAT
%token  <cadena>    DOUBLE
%token  <cadena>    SIGNED
%token  <cadena>    UNSIGNED
%token  <cadena>    CONST
%token  <cadena>    VOLATILE
%token  <cadena>    STRUCT
%token  <cadena>    UNION
%token  <cadena>    ELLIPSIS
%token  <cadena>    ENUM
%token  <cadena>    IF
%token  <cadena>    ELSE
%token  <cadena>    SWITCH
%token  <cadena>    WHILE
%token  <cadena>    DO
%token  <cadena>    FOR
%token  <cadena>    CASE
%token  <cadena>    DEFAULT
%token  <cadena>    CONTINUE
%token  <cadena>    BREAK
%token  <cadena>    RETURN 
%token  <cadena>    GOTO   

%start translation_unit
%% /* A continuacion las reglas gramaticales y las acciones */

constant    :   DEC_CONST
            |   OCT_CONST
            |   HEX_CONST 
            |   REAL_CONST
            |   CHAR_CONST
            ; 

/******************************/
/********* EXPRESIONES ********/
/******************************/
primary_expression  :   IDENTIFIER
                    |   constant
                    |   STR_LIT
                    |   '(' expression ')'
                    ;

postfix_expression  :   primary_expression
                    |   postfix_expression '[' expression ']'
                    |   postfix_expression '(' argument_expression_list_opt ')'     {controlar_invocacion_funcion(ts, $<cadena>1, parametros); vaciar_lista(parametros);}
                    |   postfix_expression '.' IDENTIFIER
                    |   postfix_expression PTR_OP IDENTIFIER
                    |   postfix_expression INC_OP
                    |   postfix_expression DEC_OP
                    ;

argument_expression_list    :   assignment_expression                               {crear_nodo_parametro(parametros, obtener_tipo(ts, $<cadena>1), "na");}
                            |   argument_expression_list ',' assignment_expression  {crear_nodo_parametro(parametros, obtener_tipo(ts, $<cadena>3), "na");}
                            ;

unary_expression    :   postfix_expression
                    |   INC_OP unary_expression
                    |   DEC_OP unary_expression
                    |   unary_operator cast_expression
                    |   SIZEOF unary_expression
                    |   SIZEOF '(' type_name ')'
                    ;

unary_operator  :   '&'
                |   '*'
                |   '+'
                |   '-'
                |   '~'
                |   '!'
                ;

cast_expression :   unary_expression
                |   '(' type_name ')' cast_expression
                ;

multiplicative_expression   :   cast_expression
                            |   multiplicative_expression '*' cast_expression
                            |   multiplicative_expression '/' cast_expression
                            |   multiplicative_expression '%' cast_expression
                            ;

additive_expression :   multiplicative_expression
                    |   additive_expression '+' multiplicative_expression   {validar_suma(obtener_tipo(ts, $<cadena>1), obtener_tipo(ts, $<cadena>3));}
                    |   additive_expression '-' multiplicative_expression
                    ;

shift_expression    :   additive_expression
                    |   shift_expression LEFT_OP additive_expression
                    |   shift_expression RIGHT_OP additive_expression
                    ;

relational_expression   :   shift_expression
                        |   relational_expression '<' shift_expression
                        |   relational_expression '>' shift_expression
                        |   relational_expression LE_OP shift_expression
                        |   relational_expression GE_OP shift_expression
                        ;

equality_expression : relational_expression
                    | equality_expression EQ_OP relational_expression
                    | equality_expression NE_OP relational_expression
                    ;

and_expression  :   equality_expression
                |   and_expression '&' equality_expression
                ;

exclusive_or_expression :   and_expression
                        |   exclusive_or_expression '^' and_expression
                        ;

inclusive_or_expression :   exclusive_or_expression
                        |   inclusive_or_expression '|' exclusive_or_expression
                        ;

logical_and_expression  :   inclusive_or_expression
                        |   logical_and_expression AND_OP inclusive_or_expression
                        ;

logical_or_expression   :   logical_and_expression
                        |   logical_or_expression OR_OP logical_and_expression
                        ;

conditional_expression  :   logical_or_expression
                        |   logical_or_expression '?' expression ':' conditional_expression
                        ;

assignment_expression   :   conditional_expression
                        |   unary_expression assignment_operator assignment_expression
                        ;

assignment_operator :   '='
                    |   MUL_ASSIGN
                    |   DIV_ASSIGN
                    |   MOD_ASSIGN
                    |   ADD_ASSIGN
                    |   SUB_ASSIGN
                    |   LEFT_ASSIGN
                    |   RIGHT_ASSIGN
                    |   AND_ASSIGN
                    |   XOR_ASSIGN
                    |   OR_ASSIGN
                    ;

expression  :   assignment_expression
            |   expression ',' assignment_expression
            ;

constant_expression :   conditional_expression
	                ;

/******************************/
/******* DECLARACIONES ********/
/******************************/
declaration :   declaration_specifiers init_declarator_list_opt ';' {imprimir_especial(yylineno, buffer_tipo, buffer_identificador); strcpy(buffer_tipo, ""); strcpy(buffer_identificador, "");}
            |   error ';'                                           {yyerrok; strcpy(buffer_tipo, ""); strcpy(buffer_identificador, "");}
            ;

declaration_specifiers  :   storage_class_specifier declaration_specifiers_opt  {copiar_especial(buffer_tipo, $<cadena>1);}
                        |   type_specifier declaration_specifiers_opt           {copiar_especial(buffer_tipo, $<cadena>1);}
                        |   type_qualifier declaration_specifiers_opt           {copiar_especial(buffer_tipo, $<cadena>1);}
                        ;

init_declarator_list    :   init_declarator                             {strcat(buffer_identificador, " ");}
                        |   init_declarator_list ',' init_declarator    {strcat(buffer_identificador, " ");}
                        ;

init_declarator :   declarator                  {if (!funcion) {crear_nodo_variable(ts, buffer_tipo, $<cadena>1);}}
                |   declarator '=' initializer  {crear_nodo_variable(ts, buffer_tipo, $<cadena>1);}
                ;

storage_class_specifier :   TYPEDEF
                        |   EXTERN
                        |   STATIC
                        |   AUTO
                        |   REGISTER
                        ;

type_specifier  :   VOID
                |   CHAR
                |   SHORT
                |   INT
                |   LONG
                |   FLOAT
                |   DOUBLE
                |   SIGNED
                |   UNSIGNED
                |   struct_or_union_specifier
                |   enum_specifier
                ;

struct_or_union_specifier   :   struct_or_union identifier_opt '{' struct_declaration_list '}'  {strcat(buffer_identificador, $<cadena>2);}
                            |   struct_or_union IDENTIFIER                                      {strcat(buffer_identificador, $<cadena>2);}
                            ;

struct_or_union :   STRUCT
                |   UNION
                ;

struct_declaration_list : struct_declaration
                        | struct_declaration_list struct_declaration
                        ;

struct_declaration  :   specifier_qualifier_list struct_declarator_list ';'
	                ;

specifier_qualifier_list    :   type_specifier specifier_qualifier_list_opt
                            |   type_qualifier specifier_qualifier_list_opt
                            ;

struct_declarator_list  :   struct_declarator
                        |   struct_declarator_list ',' struct_declarator
                        ;

struct_declarator   :   declarator
                    |   declarator_opt ':' constant_expression
                    ;

enum_specifier  :   ENUM identifier_opt '{' enumerator_list '}' {strcat(buffer_identificador, $<cadena>2);}
                |   ENUM IDENTIFIER                             {copiar_especial(buffer_tipo, $<cadena>2);}
                ;

enumerator_list :   enumerator 
                |   enumerator_list ',' enumerator
                ;

enumerator  :   IDENTIFIER
            |   IDENTIFIER '=' constant_expression
            ;

type_qualifier  :   CONST
                |   VOLATILE
                ;

declarator  :   direct_declarator
            |   pointer direct_declarator
            ;

direct_declarator   :   IDENTIFIER                                          {strcat(buffer_identificador, $<cadena>1);}
                    |   '(' declarator ')'                                  {printf("1\n"); copiar_especial(buffer_identificador, "("); strcat(buffer_identificador, ")");}
                    |   direct_declarator '[' constant_expression_opt ']'   {strcat(buffer_identificador, "[]");}
                    |   direct_declarator '(' parameter_type_list ')'       {funcion = true; crear_nodo_funcion(ts, $<cadena>0, $<cadena>1, parametros, false); vaciar_lista(parametros); strcpy(buffer_identificador, ""); strcat(buffer_identificador, $<cadena>1); strcat(buffer_identificador, "()");}
                    |   direct_declarator '(' identifier_list_opt ')'       {funcion = true; crear_nodo_funcion(ts, $<cadena>0, $<cadena>1, parametros, false); vaciar_lista(parametros); strcpy(buffer_tipo, ""); strcpy(buffer_identificador, "");}
                    ;

pointer :   '*' type_qualifier_list_opt         {strcat(buffer_identificador, "*");}
        |   '*' type_qualifier_list_opt pointer
        ;

type_qualifier_list :   type_qualifier
                    |   type_qualifier_list type_qualifier
	                ;
                       
parameter_type_list :   parameter_list              {remover_especial(buffer_tipo);}
                    |   parameter_list ',' ELLIPSIS
                    ;

parameter_list  :   parameter_declaration
                |   parameter_list ',' parameter_declaration
                ;

parameter_declaration   :   declaration_specifiers declarator               {crear_nodo_parametro(parametros, $<cadena>1, $<cadena>2);}
                        |   declaration_specifiers abstract_declarator_opt
                        ;

identifier_list :   IDENTIFIER
                |   identifier_list ',' IDENTIFIER
                ;

type_name   :   specifier_qualifier_list abstract_declarator_opt
            ;

abstract_declarator :   pointer
                    |   pointer_opt direct_abstract_declarator
                    ;

direct_abstract_declarator_opt  :   /* vacio */
                                |   direct_abstract_declarator
                                ;

direct_abstract_declarator  :   '(' abstract_declarator ')'
                            |   direct_abstract_declarator_opt '[' constant_expression_opt ']'
                            |   direct_abstract_declarator_opt '(' parameter_type_list_opt ')'
                            ;

initializer :   assignment_expression
            |   '{' initializer_list '}'
            |   '{' initializer_list ',' '}'
            ;

initializer_list    :   initializer
                    |   initializer_list ',' initializer
                    ;
   
/******************************/
/********* SENTENCIAS *********/
/******************************/
statement   :   labeled_statement
            |   compound_statement
            |   expression_statement    {printf("Linea %03d: Sentencia de Expresion\n", yylineno);}
            |   selection_statement
            |   iteration_statement     
            |   jump_statement          {printf("Linea %03d: Sentencia de Salto\n", yylineno);}
            |   error ';'               {yyerrok; strcpy(buffer_tipo, ""); strcpy(buffer_identificador, "");}
            ;

labeled_statement   :   IDENTIFIER ':' {printf("Linea %03d: Sentencia Etiquetada\n", yylineno);} statement
                    |   CASE {printf("Linea %03d: Sentencia Etiquetada\n", yylineno);} constant_expression ':' statement
                    |   DEFAULT {printf("Linea %03d: Sentencia Etiquetada\n", yylineno);} ':' statement
                    ;

compound_statement  :   '{' {printf("Linea %03d: Sentencia Compuesta\n", yylineno); strcpy(buffer_tipo, ""); strcpy(buffer_identificador, "");} declaration_list_opt statement_list_opt '}'
                    ;

declaration_list    :   declaration
                    |   declaration_list declaration
                    ;

statement_list  :   statement
                |   statement_list statement
                ;

expression_statement    :   expression_opt ';'
	                    ;

selection_statement :   IF {printf("Linea %03d: Sentencia de Seleccion\n", yylineno);} if_block                
                    |   SWITCH {printf("Linea %03d: Sentencia de Seleccion\n", yylineno);} '(' expression ')' statement
                    ;

if_block    :   '(' expression ')' statement
            |   '(' expression ')' statement ELSE statement
            ;

iteration_statement :   WHILE {printf("Linea %03d: Sentencia de Iteracion\n", yylineno);} '(' expression ')' statement
                    |   DO {printf("Linea %03d: Sentencia de Iteracion\n", yylineno);} statement WHILE '(' expression ')' ';'
                    |   FOR {printf("Linea %03d: Sentencia de Iteracion\n", yylineno);} '(' expression_statement expression_statement expression_opt ')' statement
                    ;

jump_statement  :   GOTO IDENTIFIER ';'
                |   CONTINUE ';'
                |   BREAK ';'
                |   RETURN expression_opt ';'
                ;

/******************************/
/********** EXTERNAS **********/
/******************************/
translation_unit    :   external_declaration
                    |   translation_unit external_declaration
                    ;

external_declaration    :   function_definition {funcion = false;}
                        |   declaration
                        ;

function_definition :   declaration_specifiers declarator declaration_list_opt compound_statement {crear_nodo_funcion(ts, $<cadena>1, $<cadena>2, parametros, true);}
                    |   error '}'   {yyerrok; strcpy(buffer_tipo, ""); strcpy(buffer_identificador, "");}
                    ;

/******************************/
/********* OPCIONALES *********/
/******************************/
argument_expression_list_opt    :   /* vacio */
                                |   argument_expression_list
                                ;

init_declarator_list_opt    :   /* vacio */
                            |   init_declarator_list
                            ;

declaration_specifiers_opt  :   /* vacio */
                            |   declaration_specifiers
                            ;

identifier_opt  :   /* vacio */
                |   IDENTIFIER
                ;

specifier_qualifier_list_opt    :   /* vacio */
                                |   specifier_qualifier_list
                                ;
								
declarator_opt  :   /* vacio */
                |   declarator
                ;

constant_expression_opt :   /* vacio */
                        |   constant_expression
                        ;

identifier_list_opt :   /* vacio */
                    |   identifier_list
                    ;

type_qualifier_list_opt :   /* vacio */
                        |   type_qualifier_list
                        ;

abstract_declarator_opt :   /* vacio */
                        |   abstract_declarator
                        ;

pointer_opt :   /* vacio */
            |   pointer
            ;

parameter_type_list_opt :   /* vacio */
                        |   parameter_type_list
                        ;

declaration_list_opt    :   /* vacio */
                        |   declaration_list
                        ;

statement_list_opt  :   /* vacio */
                    |   statement_list
                    ;

expression_opt  :   /* vacio */
                |   expression
                ;
%%

int main(int argc, char *argv[])
{
    #ifdef YYDEBUG
        yydebug = 0;
    #endif

    ts = crear_lista();
    parametros = crear_lista();

    yyin = fopen(argv[1], "r");
    printf("/******************************/\n");
    printf("/********** REPORTE ***********/\n");
    printf("/******************************/\n");
    yyparse();
    fclose(yyin);
    imprimir_ts(ts);
    return 0;
}