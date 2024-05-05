%option noyywrap
%option yylineno

%{
#include <stdio.h>
#include "funciones.h"

typedef enum categoriaLexica {
    IDENTIFICADOR,
    LITERAL_CADENA,
    PR_OTROS,
    PR_TIPOS_DE_DATO,
    PR_EST_CONTROL,
    CTE_OCTAL,
    CTE_HEXA,
    CTE_DECIMAL,
    CTE_REAL,
    CTE_CARACTER,
    PUNCTUATOR,
    COMENTARIO,
    NO_RECONOCIDO,
    CANTIDAD
} t_categoriaLexica;

t_lista* categoriaLexica[CANTIDAD];

void listas_inicializar() {
    for (int indice = 0; indice < CANTIDAD; indice++)
        categoriaLexica[indice] = lista_crear();
}

void listas_mostrar() {
    for (int indice = 0; indice < CANTIDAD; indice++)
        lista_mostrar(categoriaLexica[indice], indice);
}
%}

pr_otros                auto|case|const|default|enum|extern|register|signed|sizeof|static|typedef|union|unsigned|volatile
pr_tipos_de_dato        char|float|int|long|short|void|double
pr_est_control          break|continue|do|else|for|goto|if|return|switch|while|struct

identificador           {noDigito}({noDigito}|{digito})*
noDigito                [_a-zA-Z]
digito                  [0-9]

constanteDecimal        {digitoNoCero}{digito}*{sufijoEntero}?
constanteOctal          0{digitoOctal}*{sufijoEntero}?
constanteHexa           {ceroX}{digitoHexa}+{sufijoEntero}?
ceroX                   0[xX]
digitoNoCero            [1-9]
digitoOctal             [0-7]
digitoHexa              [0-9a-fA-F]
sufijoEntero            {sufijoUnsigned}{sufijoLong}?|{sufijoLong}{sufijoUnsigned}?
sufijoUnsigned          [uU]
sufijoLong              [lL]

constanteReal           {constanteFraccion}{parteExponente}?{sufijoReal}?|{secuenciaDigitos}{parteExponente}{sufijoReal}?      
constanteFraccion       {secuenciaDigitos}?\.{secuenciaDigitos}|{secuenciaDigitos}\.
parteExponente          {operadorE}{signo}?{secuenciaDigitos}
operadorE               [eE]
signo                   [\+\-]
secuenciaDigitos        {digito}+
sufijoReal              [fFlL]

constanteCaracter       \'{caracterC}\'|\'{secuenciaEscape}\'
caracterC               [^\'\\]
secuenciaEscape         {secuenciaEscapeSimple}|{secuenciaEscapeOctal}|{secuenciaEscapeHexa}
secuenciaEscapeSimple   \\['"?\\abfnrtv] 
secuenciaEscapeOctal    \\{digitoOctal}{1,3} 
secuenciaEscapeHexa     \\x{digitoHexa}{1,2}

literalCadena           \"({caracterS}|{secuenciaEscape})*\"
caracterS               [^"\\]

punctuator             (\[|\]|\(|\)|\{|\}|\.|\-\>|\+\+|\-\-|\&|\*|\+|\-|\˜|\!|\/|\%|\<\<|\>\>|\<|\>|\<\=|\>\=|\=\=|\!\=|\ˆ|\||\&\&|\|\||\=|\*\=|\/\=|\%\=|\+\=|\-\=|\<\<\=|\>\>\=|\&\=|\ˆ\=|\|\=|\?|\:|\;|\.\.\.|\,|\#|\#\#)

comentarioUnaLinea      \/\/.*
comentarioMultiLinea    \/\*([^*]|(\*+[^*/]))*\*+\/

%%

{pr_otros}              {lista_agregar(categoriaLexica[PR_OTROS], yytext);}
{pr_tipos_de_dato}      {lista_agregar(categoriaLexica[PR_TIPOS_DE_DATO], yytext);}
{pr_est_control}        {lista_agregar(categoriaLexica[PR_EST_CONTROL], yytext);}
{identificador}         {lista_agregar_sin_repetir(categoriaLexica[IDENTIFICADOR], yytext);}
{constanteDecimal}      {lista_agregar(categoriaLexica[CTE_DECIMAL], yytext);}
{constanteOctal}        {lista_agregar(categoriaLexica[CTE_OCTAL], yytext);}
{constanteHexa}         {lista_agregar(categoriaLexica[CTE_HEXA], yytext);}
{constanteReal}         {lista_agregar(categoriaLexica[CTE_REAL], yytext);}
{constanteCaracter}     {lista_agregar(categoriaLexica[CTE_CARACTER], yytext);}
{literalCadena}         {lista_agregar_con_longitud(categoriaLexica[LITERAL_CADENA], yytext, yyleng);}
{punctuator}            {lista_agregar_sin_repetir(categoriaLexica[PUNCTUATOR], yytext);}
{comentarioUnaLinea}    {lista_agregar_con_linea(categoriaLexica[COMENTARIO], yytext, 0);}
{comentarioMultiLinea}  {lista_agregar_con_linea(categoriaLexica[COMENTARIO], yytext, 1);}
[\t]+|([ ])+            /* eat up whitespace */
\n                      { }
.                       {lista_agregar_con_linea(categoriaLexica[NO_RECONOCIDO], yytext, yylineno);}

%%

int main() {
   
    /* Acciones previas a la invocación den analizador léxico */
    listas_inicializar();

    yyin = fopen("archivo.c", "r");
    
    /* Invocación del analizador léxico */
    yylex();
	
    /* Acciónes posteriores a la ejecución del analizador léxico */
    listas_mostrar();
    return 0;
}
