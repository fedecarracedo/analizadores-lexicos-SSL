%option noyywrap
%option yylineno

%{
    #include "tpi.tab.h"
    #include "funciones.h"
%}

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

comentarioUnaLinea      \/\/.*
comentarioMultiLinea    \/\*([^*]|(\*+[^*/]))*\*+\/

%%

"auto"			            {yylval.cadena = strdup(yytext); return AUTO;}
"break"			            {yylval.cadena = strdup(yytext); return BREAK;}
"case"			            {yylval.cadena = strdup(yytext); return CASE;}
"char"			            {yylval.cadena = strdup(yytext); return CHAR;}
"const"			            {yylval.cadena = strdup(yytext); return CONST;}
"continue"		            {yylval.cadena = strdup(yytext); return CONTINUE;}
"default"		            {yylval.cadena = strdup(yytext); return DEFAULT;}
"do"			            {yylval.cadena = strdup(yytext); return DO;}
"double"		            {yylval.cadena = strdup(yytext); return DOUBLE;}
"else"			            {yylval.cadena = strdup(yytext); return ELSE;}
"enum"			            {yylval.cadena = strdup(yytext); return ENUM;}
"extern"		            {yylval.cadena = strdup(yytext); return EXTERN;}
"float"			            {yylval.cadena = strdup(yytext); return FLOAT;}
"for"			            {yylval.cadena = strdup(yytext); return FOR;}
"goto"			            {yylval.cadena = strdup(yytext); return GOTO;}
"if"			            {yylval.cadena = strdup(yytext); return IF;}
"int"			            {yylval.cadena = strdup(yytext); return INT;}
"long"			            {yylval.cadena = strdup(yytext); return LONG;}
"register"		            {yylval.cadena = strdup(yytext); return REGISTER;}
"return"		            {yylval.cadena = strdup(yytext); return RETURN;}
"short"			            {yylval.cadena = strdup(yytext); return SHORT;}
"signed"		            {yylval.cadena = strdup(yytext); return SIGNED;}
"sizeof"		            {yylval.cadena = strdup(yytext); return SIZEOF;}
"static"		            {yylval.cadena = strdup(yytext); return STATIC;}
"struct"		            {yylval.cadena = strdup(yytext); return STRUCT;}
"switch"		            {yylval.cadena = strdup(yytext); return SWITCH;}
"typedef"		            {yylval.cadena = strdup(yytext); return TYPEDEF;}
"union"			            {yylval.cadena = strdup(yytext); return UNION;}
"unsigned"		            {yylval.cadena = strdup(yytext); return UNSIGNED;}
"void"			            {yylval.cadena = strdup(yytext); return VOID;}
"volatile"		            {yylval.cadena = strdup(yytext); return VOLATILE;}
"while"			            {yylval.cadena = strdup(yytext); return WHILE;}

{identificador}             {yylval.cadena = strdup(yytext); return IDENTIFIER;}
{constanteDecimal}          {/*yylval.entero = atoi(yytext);*/              yylval.cadena = "int"; return DEC_CONST;}
{constanteOctal}            {/*yylval.entero = strtol(yytext, NULL, 8);*/   yylval.cadena = "int"; return OCT_CONST;}
{constanteHexa}             {/*yylval.entero = strtol(yytext, NULL, 16);*/  yylval.cadena = "int"; return HEX_CONST;}
{constanteReal}             {/*yylval.real = atof(yytext);*/                yylval.cadena = "float"; return REAL_CONST;}
{constanteCaracter}         {/*yylval.cadena = strdup(yytext);*/            yylval.cadena = "char"; return CHAR_CONST;}
{literalCadena}             {/*yylval.cadena = strdup(yytext);*/            yylval.cadena = "char*";return STR_LIT;}

"..."			            {return ELLIPSIS;}
">>="			            {return RIGHT_ASSIGN;}
"<<="			            {return LEFT_ASSIGN;}
"+="			            {return ADD_ASSIGN;}
"-="			            {return SUB_ASSIGN;}
"*="			            {return MUL_ASSIGN;}
"/="			            {return DIV_ASSIGN;}
"%="			            {return MOD_ASSIGN;}
"&="			            {return AND_ASSIGN;}
"^="			            {return XOR_ASSIGN;}
"|="			            {return OR_ASSIGN;}
">>"			            {return RIGHT_OP;}
"<<"			            {return LEFT_OP;}
"++"			            {return INC_OP;}
"--"			            {return DEC_OP;}
"->"			            {return PTR_OP;}
"&&"			            {return AND_OP;}
"||"			            {return OR_OP;}
"<="			            {return LE_OP;}
">="			            {return GE_OP;}
"=="			            {return EQ_OP;}
"!="			            {return NE_OP;}
";"			                {return ';';}
"{"		                    {return '{';}
"}"		                    {return '}';}
","			                {return ',';}
":"			                {return ':';}
"="			                {return '=';}
"("			                {return '(';}
")"			                {return ')';}
"["		                    {return '[';}
"]"		                    {return ']';}
"."			                {return '.';}
"&"			                {return '&';}
"!"			                {return '!';}
"~"			                {return '~';}
"-"			                {return '-';}
"+"			                {return '+';}
"*"			                {return '*';}
"/"			                {return '/';}
"%"			                {return '%';}
"<"			                {return '<';}
">"			                {return '>';}
"^"			                {return '^';}
"|"			                {return '|';}
"?"			                {return '?';}

{comentarioUnaLinea}        {}
{comentarioMultiLinea}      {}
[\t \n]                     {}
.                           {printf("Error Lexico -> Linea %03d, lexema \"%s\" no reconocido\n", yylineno, yytext);}
%%