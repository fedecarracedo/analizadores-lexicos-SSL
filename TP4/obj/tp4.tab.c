
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "../src/tp4.y"

    #include <stdio.h>
    #include <string.h>

    #define YYDEBUG 1

    extern int yylineno;
    extern FILE* yyin;
    int yylex();
    int yywrap() { return(1); }
    void yyerror (char const *s)  {fprintf(stderr, "Error Sintactico -> Linea %03d, %s\n", yylineno, s);}

    char buffer_tipo[100];
    char buffer_identificador[100];

    void copiar_especial(char* str1, char* str2)
    {
        char* auxiliar;
        auxiliar = strdup(str1);
        strcpy(str1, str2);
        if(strlen(str2) != 1) { strcat(str1, " "); }
        strcat(str1, auxiliar);      
    }

    void imprimir_especial(int linea, char* tipo, char* identificador)
    {
        char *token = strtok(identificador, " ");
        if(token != NULL) {
            while(token != NULL) {
                printf("Linea %03d: Declaracion -> %s%s\n", linea, tipo, token);
                token = strtok(NULL, " ");
            } 
        }
    }

    void remover_especial(char* str1)
    {
        char auxiliar[100] = "";
        char *token = strtok(str1, " ");
        token = strtok(NULL, " ");
        token = strtok(NULL, " ");
        if(token != NULL) {           
            while(token != NULL) {
                strcat(auxiliar, token);
                strcat(auxiliar, " ");
                token = strtok(NULL, " ");
            }
        }
        strcpy(str1, auxiliar);
    }


/* Line 189 of yacc.c  */
#line 126 "tp4.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     DEC_CONST = 259,
     OCT_CONST = 260,
     HEX_CONST = 261,
     REAL_CONST = 262,
     CHAR_CONST = 263,
     STR_LIT = 264,
     MUL_ASSIGN = 265,
     DIV_ASSIGN = 266,
     MOD_ASSIGN = 267,
     ADD_ASSIGN = 268,
     SUB_ASSIGN = 269,
     RIGHT_ASSIGN = 270,
     LEFT_ASSIGN = 271,
     AND_ASSIGN = 272,
     XOR_ASSIGN = 273,
     OR_ASSIGN = 274,
     OR_OP = 275,
     AND_OP = 276,
     EQ_OP = 277,
     NE_OP = 278,
     LE_OP = 279,
     GE_OP = 280,
     LEFT_OP = 281,
     RIGHT_OP = 282,
     INC_OP = 283,
     DEC_OP = 284,
     PTR_OP = 285,
     SIZEOF = 286,
     TYPEDEF = 287,
     STATIC = 288,
     AUTO = 289,
     REGISTER = 290,
     EXTERN = 291,
     VOID = 292,
     CHAR = 293,
     SHORT = 294,
     INT = 295,
     LONG = 296,
     FLOAT = 297,
     DOUBLE = 298,
     SIGNED = 299,
     UNSIGNED = 300,
     CONST = 301,
     VOLATILE = 302,
     STRUCT = 303,
     UNION = 304,
     ELLIPSIS = 305,
     ENUM = 306,
     IF = 307,
     ELSE = 308,
     SWITCH = 309,
     WHILE = 310,
     DO = 311,
     FOR = 312,
     CASE = 313,
     DEFAULT = 314,
     CONTINUE = 315,
     BREAK = 316,
     RETURN = 317,
     GOTO = 318
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 53 "../src/tp4.y"

    char* cadena;
    int entero;
    float real;



/* Line 214 of yacc.c  */
#line 233 "tp4.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 245 "tp4.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  51
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   896

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  91
/* YYNRULES -- Number of rules.  */
#define YYNRULES  229
/* YYNRULES -- Number of states.  */
#define YYNSTATES  350

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   318

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    75,     2,     2,     2,    77,    70,     2,
      64,    65,    71,    72,    69,    73,    68,    76,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    83,    85,
      78,    84,    79,    82,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    66,     2,    67,    80,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    86,    81,    87,    74,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      19,    23,    25,    30,    35,    39,    43,    46,    49,    51,
      55,    57,    60,    63,    66,    69,    74,    76,    78,    80,
      82,    84,    86,    88,    93,    95,    99,   103,   107,   109,
     113,   117,   119,   123,   127,   129,   133,   137,   141,   145,
     147,   151,   155,   157,   161,   163,   167,   169,   173,   175,
     179,   181,   185,   187,   193,   195,   199,   201,   203,   205,
     207,   209,   211,   213,   215,   217,   219,   221,   223,   227,
     229,   233,   236,   239,   242,   245,   247,   251,   253,   257,
     259,   261,   263,   265,   267,   269,   271,   273,   275,   277,
     279,   281,   283,   285,   287,   289,   295,   298,   300,   302,
     304,   307,   311,   314,   317,   319,   323,   325,   329,   335,
     338,   340,   344,   346,   350,   352,   354,   356,   359,   361,
     365,   370,   375,   380,   383,   387,   389,   392,   394,   398,
     400,   404,   407,   410,   412,   416,   419,   421,   424,   425,
     427,   431,   436,   441,   443,   447,   452,   454,   458,   460,
     462,   464,   466,   468,   470,   473,   474,   479,   480,   486,
     487,   492,   493,   499,   501,   504,   506,   509,   512,   513,
     517,   518,   525,   530,   537,   538,   545,   546,   555,   556,
     565,   569,   572,   575,   579,   581,   584,   586,   588,   593,
     596,   597,   599,   600,   602,   603,   605,   606,   608,   609,
     611,   612,   614,   615,   617,   618,   620,   621,   623,   624,
     626,   627,   629,   630,   632,   633,   635,   636,   638,   639
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     161,     0,    -1,     4,    -1,     5,    -1,     6,    -1,     7,
      -1,     8,    -1,     3,    -1,    89,    -1,     9,    -1,    64,
     109,    65,    -1,    90,    -1,    91,    66,   109,    67,    -1,
      91,    64,   164,    65,    -1,    91,    68,     3,    -1,    91,
      30,     3,    -1,    91,    28,    -1,    91,    29,    -1,   107,
      -1,    92,    69,   107,    -1,    91,    -1,    28,    93,    -1,
      29,    93,    -1,    94,    95,    -1,    31,    93,    -1,    31,
      64,   136,    65,    -1,    70,    -1,    71,    -1,    72,    -1,
      73,    -1,    74,    -1,    75,    -1,    93,    -1,    64,   136,
      65,    95,    -1,    95,    -1,    96,    71,    95,    -1,    96,
      76,    95,    -1,    96,    77,    95,    -1,    96,    -1,    97,
      72,    96,    -1,    97,    73,    96,    -1,    97,    -1,    98,
      26,    97,    -1,    98,    27,    97,    -1,    98,    -1,    99,
      78,    98,    -1,    99,    79,    98,    -1,    99,    24,    98,
      -1,    99,    25,    98,    -1,    99,    -1,   100,    22,    99,
      -1,   100,    23,    99,    -1,   100,    -1,   101,    70,   100,
      -1,   101,    -1,   102,    80,   101,    -1,   102,    -1,   103,
      81,   102,    -1,   103,    -1,   104,    21,   103,    -1,   104,
      -1,   105,    20,   104,    -1,   105,    -1,   105,    82,   109,
      83,   106,    -1,   106,    -1,    93,   108,   107,    -1,    84,
      -1,    10,    -1,    11,    -1,    12,    -1,    13,    -1,    14,
      -1,    16,    -1,    15,    -1,    17,    -1,    18,    -1,    19,
      -1,   107,    -1,   109,    69,   107,    -1,   106,    -1,   112,
     165,    85,    -1,     1,    85,    -1,   115,   166,    -1,   116,
     166,    -1,   127,   166,    -1,   114,    -1,   113,    69,   114,
      -1,   128,    -1,   128,    84,   140,    -1,    32,    -1,    36,
      -1,    33,    -1,    34,    -1,    35,    -1,    37,    -1,    38,
      -1,    39,    -1,    40,    -1,    41,    -1,    42,    -1,    43,
      -1,    44,    -1,    45,    -1,   117,    -1,   124,    -1,   118,
     167,    86,   119,    87,    -1,   118,     3,    -1,    48,    -1,
      49,    -1,   120,    -1,   119,   120,    -1,   121,   122,    85,
      -1,   116,   168,    -1,   127,   168,    -1,   123,    -1,   122,
      69,   123,    -1,   128,    -1,   169,    83,   110,    -1,    51,
     167,    86,   125,    87,    -1,    51,     3,    -1,   126,    -1,
     125,    69,   126,    -1,     3,    -1,     3,    84,   110,    -1,
      46,    -1,    47,    -1,   129,    -1,   130,   129,    -1,     3,
      -1,    64,   128,    65,    -1,   129,    66,   170,    67,    -1,
     129,    64,   132,    65,    -1,   129,    64,   171,    65,    -1,
      71,   172,    -1,    71,   172,   130,    -1,   127,    -1,   131,
     127,    -1,   133,    -1,   133,    69,    50,    -1,   134,    -1,
     133,    69,   134,    -1,   112,   128,    -1,   112,   173,    -1,
       3,    -1,   135,    69,     3,    -1,   121,   173,    -1,   130,
      -1,   174,   139,    -1,    -1,   139,    -1,    64,   137,    65,
      -1,   138,    66,   170,    67,    -1,   138,    64,   175,    65,
      -1,   107,    -1,    86,   141,    87,    -1,    86,   141,    69,
      87,    -1,   140,    -1,   141,    69,   140,    -1,   143,    -1,
     147,    -1,   151,    -1,   152,    -1,   156,    -1,   160,    -1,
       1,    85,    -1,    -1,     3,    83,   144,   142,    -1,    -1,
      58,   145,   110,    83,   142,    -1,    -1,    59,   146,    83,
     142,    -1,    -1,    86,   148,   176,   177,    87,    -1,   111,
      -1,   149,   111,    -1,   142,    -1,   150,   142,    -1,   178,
      85,    -1,    -1,    52,   153,   155,    -1,    -1,    54,   154,
      64,   109,    65,   142,    -1,    64,   109,    65,   142,    -1,
      64,   109,    65,   142,    53,   142,    -1,    -1,    55,   157,
      64,   109,    65,   142,    -1,    -1,    56,   158,   142,    55,
      64,   109,    65,    85,    -1,    -1,    57,   159,    64,   151,
     151,   178,    65,   142,    -1,    63,     3,    85,    -1,    60,
      85,    -1,    61,    85,    -1,    62,   178,    85,    -1,   162,
      -1,   161,   162,    -1,   163,    -1,   111,    -1,   112,   128,
     176,   147,    -1,     1,    87,    -1,    -1,    92,    -1,    -1,
     113,    -1,    -1,   112,    -1,    -1,     3,    -1,    -1,   121,
      -1,    -1,   128,    -1,    -1,   110,    -1,    -1,   135,    -1,
      -1,   131,    -1,    -1,   137,    -1,    -1,   130,    -1,    -1,
     132,    -1,    -1,   149,    -1,    -1,   150,    -1,    -1,   109,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   125,   125,   126,   127,   128,   129,   135,   136,   137,
     138,   141,   142,   143,   144,   145,   146,   147,   150,   151,
     154,   155,   156,   157,   158,   159,   162,   163,   164,   165,
     166,   167,   170,   171,   174,   175,   176,   177,   180,   181,
     182,   185,   186,   187,   190,   191,   192,   193,   194,   197,
     198,   199,   202,   203,   206,   207,   210,   211,   214,   215,
     218,   219,   222,   223,   226,   227,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   243,   244,   247,
     253,   254,   257,   258,   259,   262,   263,   266,   267,   270,
     271,   272,   273,   274,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   290,   291,   294,   295,   298,
     299,   302,   305,   306,   309,   310,   313,   314,   317,   318,
     321,   322,   325,   326,   329,   330,   333,   334,   337,   338,
     339,   340,   341,   344,   345,   348,   349,   352,   353,   356,
     357,   360,   361,   364,   365,   368,   371,   372,   375,   376,
     379,   380,   381,   384,   385,   386,   389,   390,   396,   397,
     398,   399,   400,   401,   402,   405,   405,   406,   406,   407,
     407,   410,   410,   413,   414,   417,   418,   421,   424,   424,
     425,   425,   428,   429,   432,   432,   433,   433,   434,   434,
     437,   438,   439,   440,   446,   447,   450,   451,   454,   455,
     461,   462,   465,   466,   469,   470,   473,   474,   477,   478,
     481,   482,   485,   486,   489,   490,   493,   494,   497,   498,
     501,   502,   505,   506,   509,   510,   513,   514,   517,   518
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "DEC_CONST", "OCT_CONST",
  "HEX_CONST", "REAL_CONST", "CHAR_CONST", "STR_LIT", "MUL_ASSIGN",
  "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "RIGHT_ASSIGN",
  "LEFT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "OR_OP",
  "AND_OP", "EQ_OP", "NE_OP", "LE_OP", "GE_OP", "LEFT_OP", "RIGHT_OP",
  "INC_OP", "DEC_OP", "PTR_OP", "SIZEOF", "TYPEDEF", "STATIC", "AUTO",
  "REGISTER", "EXTERN", "VOID", "CHAR", "SHORT", "INT", "LONG", "FLOAT",
  "DOUBLE", "SIGNED", "UNSIGNED", "CONST", "VOLATILE", "STRUCT", "UNION",
  "ELLIPSIS", "ENUM", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "CASE",
  "DEFAULT", "CONTINUE", "BREAK", "RETURN", "GOTO", "'('", "')'", "'['",
  "']'", "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'",
  "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'",
  "'}'", "$accept", "constant", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator_opt",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "statement", "labeled_statement", "$@1", "$@2", "$@3",
  "compound_statement", "$@4", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "$@5", "$@6", "if_block",
  "iteration_statement", "$@7", "$@8", "$@9", "jump_statement",
  "translation_unit", "external_declaration", "function_definition",
  "argument_expression_list_opt", "init_declarator_list_opt",
  "declaration_specifiers_opt", "identifier_opt",
  "specifier_qualifier_list_opt", "declarator_opt",
  "constant_expression_opt", "identifier_list_opt",
  "type_qualifier_list_opt", "abstract_declarator_opt", "pointer_opt",
  "parameter_type_list_opt", "declaration_list_opt", "statement_list_opt",
  "expression_opt", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,    40,    41,    91,    93,    46,    44,
      38,    42,    43,    45,   126,    33,    47,    37,    60,    62,
      94,   124,    63,    58,    61,    59,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    88,    89,    89,    89,    89,    89,    90,    90,    90,
      90,    91,    91,    91,    91,    91,    91,    91,    92,    92,
      93,    93,    93,    93,    93,    93,    94,    94,    94,    94,
      94,    94,    95,    95,    96,    96,    96,    96,    97,    97,
      97,    98,    98,    98,    99,    99,    99,    99,    99,   100,
     100,   100,   101,   101,   102,   102,   103,   103,   104,   104,
     105,   105,   106,   106,   107,   107,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   109,   109,   110,
     111,   111,   112,   112,   112,   113,   113,   114,   114,   115,
     115,   115,   115,   115,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   117,   117,   118,   118,   119,
     119,   120,   121,   121,   122,   122,   123,   123,   124,   124,
     125,   125,   126,   126,   127,   127,   128,   128,   129,   129,
     129,   129,   129,   130,   130,   131,   131,   132,   132,   133,
     133,   134,   134,   135,   135,   136,   137,   137,   138,   138,
     139,   139,   139,   140,   140,   140,   141,   141,   142,   142,
     142,   142,   142,   142,   142,   144,   143,   145,   143,   146,
     143,   148,   147,   149,   149,   150,   150,   151,   153,   152,
     154,   152,   155,   155,   157,   156,   158,   156,   159,   156,
     160,   160,   160,   160,   161,   161,   162,   162,   163,   163,
     164,   164,   165,   165,   166,   166,   167,   167,   168,   168,
     169,   169,   170,   170,   171,   171,   172,   172,   173,   173,
     174,   174,   175,   175,   176,   176,   177,   177,   178,   178
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     4,     4,     3,     3,     2,     2,     1,     3,
       1,     2,     2,     2,     2,     4,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     5,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     2,     2,     2,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     2,     1,     1,     1,
       2,     3,     2,     2,     1,     3,     1,     3,     5,     2,
       1,     3,     1,     3,     1,     1,     1,     2,     1,     3,
       4,     4,     4,     2,     3,     1,     2,     1,     3,     1,
       3,     2,     2,     1,     3,     2,     1,     2,     0,     1,
       3,     4,     4,     1,     3,     4,     1,     3,     1,     1,
       1,     1,     1,     1,     2,     0,     4,     0,     5,     0,
       4,     0,     5,     1,     2,     1,     2,     2,     0,     3,
       0,     6,     4,     6,     0,     6,     0,     8,     0,     8,
       3,     2,     2,     3,     1,     2,     1,     1,     4,     2,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    89,    91,    92,    93,    90,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   124,   125,   107,   108,
     206,   197,   202,   204,   204,   103,   206,   104,   204,     0,
     194,   196,    81,   199,   119,     0,   128,     0,   216,   203,
      85,     0,   126,     0,     0,   205,    82,    83,   106,     0,
      84,     1,   195,     0,     0,   135,   217,   133,     0,     0,
       0,   173,   202,     0,     0,   214,   212,   127,    80,     0,
     122,     0,   120,   129,   136,   134,    86,    87,     7,     2,
       3,     4,     5,     6,     9,     0,     0,     0,     0,    26,
      27,    28,    29,    30,    31,     0,     8,    11,    20,    32,
       0,    34,    38,    41,    44,    49,    52,    54,    56,    58,
      60,    62,    64,   153,    88,   174,   171,   198,   143,   218,
       0,   137,   139,   215,     0,    32,    79,   213,     0,   208,
       0,   109,   210,   208,     0,     0,   118,     0,    21,    22,
       0,    24,    77,     0,   220,     0,   156,     0,    16,    17,
       0,   200,     0,     0,    67,    68,    69,    70,    71,    73,
      72,    74,    75,    76,    66,     0,    23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   141,   146,   219,
     142,   148,   131,     0,     0,   132,   130,   209,   112,   105,
     110,     0,   114,   116,     0,   113,   123,   121,     0,    10,
       0,   221,   145,     0,     0,   154,    15,   201,    18,     0,
       0,    14,    65,    35,    36,    37,    39,    40,    42,    43,
      47,    48,    45,    46,    50,    51,    53,    55,    57,    59,
      61,     0,     0,   220,     0,   147,   138,   140,   144,   210,
     111,     0,    25,    78,    33,   155,   157,     0,    13,    12,
       0,     0,     7,   178,   180,   184,   186,   188,   167,   169,
       0,     0,   228,     0,   229,   175,   158,   159,     0,   160,
     161,   162,   163,     0,     0,     0,   222,   212,   115,   117,
      19,    63,   164,   165,     0,     0,     0,     0,     0,     0,
       0,   191,   192,     0,     0,   176,   172,   177,   150,   223,
       0,     0,     0,     0,   179,     0,     0,     0,   228,     0,
       0,   193,   190,   152,   151,   166,     0,     0,     0,     0,
     228,     0,   170,     0,     0,     0,     0,   228,   168,   182,
     181,   185,     0,     0,     0,     0,     0,   183,   187,   189
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    96,    97,    98,   217,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   142,
     165,   274,   127,    21,    45,    39,    40,    23,    24,    25,
      26,   130,   131,   132,   201,   202,    27,    71,    72,    28,
      77,    42,    43,    56,   120,   121,   122,   123,   145,   189,
     244,   245,   114,   147,   275,   276,   312,   299,   300,   277,
     186,    63,   278,   279,   280,   294,   295,   314,   281,   296,
     297,   298,   282,    29,    30,    31,   219,    44,    46,    35,
     198,   204,   128,   124,    57,   190,   191,   310,    64,   283,
     284
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -276
static const yytype_int16 yypact[] =
{
     754,   -49,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,
    -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,
      56,  -276,    29,   845,   845,  -276,    88,  -276,   845,   734,
    -276,  -276,  -276,  -276,    -3,    12,  -276,    29,    91,    34,
    -276,   169,    -6,    61,    66,  -276,  -276,  -276,    -3,    68,
    -276,  -276,  -276,   174,   116,  -276,    91,   119,    29,   100,
     555,  -276,    29,   256,   101,   801,   593,    -6,  -276,   118,
     135,   -59,  -276,  -276,  -276,  -276,  -276,   139,  -276,  -276,
    -276,  -276,  -276,  -276,  -276,   678,   678,   690,   605,  -276,
    -276,  -276,  -276,  -276,  -276,   555,  -276,  -276,   114,     2,
     593,  -276,   -15,   111,    49,    23,   172,   156,   148,   154,
     221,    15,  -276,  -276,  -276,  -276,  -276,  -276,  -276,    24,
     178,   175,  -276,   176,   181,  -276,  -276,  -276,   180,   118,
     769,  -276,    29,   118,   593,   174,  -276,   593,  -276,  -276,
     605,  -276,  -276,   -16,   -19,   183,  -276,   -43,  -276,  -276,
     246,   593,   593,   248,  -276,  -276,  -276,  -276,  -276,  -276,
    -276,  -276,  -276,  -276,  -276,   593,  -276,   593,   593,   593,
     593,   593,   593,   593,   593,   593,   593,   593,   593,   593,
     593,   593,   593,   593,   593,   593,   331,  -276,    30,  -276,
    -276,   192,  -276,   825,   255,  -276,  -276,  -276,  -276,  -276,
    -276,   -35,  -276,   184,   185,  -276,  -276,  -276,   201,  -276,
     593,   204,  -276,   593,   518,  -276,  -276,   202,  -276,   205,
     106,  -276,  -276,  -276,  -276,  -276,   -15,   -15,   111,   111,
      49,    49,    49,    49,    23,    23,   172,   156,   148,   154,
     221,   -38,   406,   119,    18,   110,  -276,  -276,  -276,    29,
    -276,   593,  -276,  -276,  -276,  -276,  -276,   593,  -276,  -276,
     593,   187,   190,  -276,  -276,  -276,  -276,  -276,  -276,  -276,
     189,   191,   593,   272,   208,  -276,  -276,  -276,   443,  -276,
    -276,  -276,  -276,   193,   194,   213,   845,   593,  -276,  -276,
    -276,  -276,  -276,  -276,   217,   218,   219,   481,   242,   593,
     226,  -276,  -276,   236,   237,  -276,  -276,  -276,  -276,  -276,
     258,   257,   481,   593,  -276,   593,   593,   270,   593,   250,
     481,  -276,  -276,  -276,  -276,  -276,     4,    16,    71,   280,
     593,   481,  -276,   481,   481,   481,   593,   593,  -276,   292,
    -276,  -276,    80,   281,   481,   262,   481,  -276,  -276,  -276
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -276,  -276,  -276,  -276,  -276,   -63,  -276,   -89,    51,    27,
      57,    62,   168,   170,   167,   171,   166,  -276,   -62,   -18,
    -276,   -86,  -128,   -33,     0,  -276,   294,  -276,    -1,  -276,
    -276,  -276,   223,    39,  -276,   107,  -276,  -276,   220,     1,
       3,   -42,   -52,  -276,    72,  -276,   164,  -276,   241,   141,
    -276,  -276,   -88,  -276,   392,  -276,  -276,  -276,  -276,   297,
    -276,  -276,  -276,  -275,  -276,  -276,  -276,  -276,  -276,  -276,
    -276,  -276,  -276,  -276,   367,  -276,  -276,  -276,   124,   371,
     265,  -276,   112,  -276,  -276,   264,  -276,  -276,   214,  -276,
    -263
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -229
static const yytype_int16 yytable[] =
{
      22,    67,   143,   125,   126,    75,   206,   146,    61,   303,
     135,   166,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   138,   139,   141,    41,   214,    36,   136,    22,
     115,   210,    36,    36,   249,   184,    32,   125,    33,    55,
      54,    62,   113,   330,   215,   260,  -218,   174,   175,   209,
     250,   143,    38,   210,   143,   337,   167,    74,    65,    34,
      66,   168,   169,    62,    36,   119,   220,   188,   129,   333,
     133,   125,   126,   210,   343,   172,   173,   113,   223,   224,
     225,   334,   286,  -207,   287,   210,   164,   129,    37,   133,
    -220,    48,   211,    37,    37,    38,  -221,   185,    53,   241,
      38,   176,   177,    58,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   187,   289,   254,    37,   256,   144,   129,   129,
     133,   133,   129,   218,   133,   203,   335,    16,    17,   129,
     210,   133,   148,   149,   150,   345,    67,   222,    47,   210,
     125,    68,    50,    61,    69,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,   197,    20,
      59,   319,   197,   259,  -149,   210,  -149,    70,   151,   144,
     152,    73,   153,   170,   171,    32,    62,   116,   125,   126,
      38,   211,   253,   119,   178,   179,   113,   125,   291,   228,
     229,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,   134,
      20,   226,   227,    60,   125,   126,   180,   326,   181,   327,
     328,   230,   231,   232,   233,   182,   125,   126,   -87,   290,
     234,   235,   183,   192,   193,   194,   195,   196,   213,   216,
     342,   221,   203,    60,   -87,  -224,   243,    59,   248,  -225,
    -225,  -225,  -225,  -225,  -225,  -225,   252,  -211,   251,  -146,
     258,   257,   292,   293,   301,   304,   302,   210,   308,   307,
     306,   313,   315,   316,  -225,  -225,   119,  -225,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,   318,    20,  -225,   320,
    -225,  -225,  -225,  -225,  -225,  -225,  -225,  -225,  -225,  -225,
    -225,   321,   322,   323,   324,   329,  -225,  -225,  -225,  -225,
    -225,  -225,    59,   331,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -225,  -225,  -225,   336,   344,   346,   348,   236,   238,
     240,   237,    76,   200,   239,   207,   288,   247,   309,  -224,
    -224,   117,  -224,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,   208,    20,  -224,   285,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,    52,    49,   205,   311,
     242,  -224,  -224,  -224,  -224,  -224,  -224,   261,   212,   262,
      79,    80,    81,    82,    83,    84,  -224,  -224,  -224,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,    86,     0,    87,     0,     0,
       0,     0,     0,     0,   261,     0,   262,    79,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,   263,     0,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
      88,    85,    86,     0,    87,     0,    89,    90,    91,    92,
      93,    94,   261,     0,   262,    79,    80,    81,    82,    83,
      84,  -228,   116,  -226,     0,   263,     0,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,    88,     0,    85,
      86,     0,    87,    89,    90,    91,    92,    93,    94,     0,
       0,    78,    79,    80,    81,    82,    83,    84,  -228,   116,
    -227,     0,     0,   263,     0,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,    88,    85,    86,     0,    87,
       0,    89,    90,    91,    92,    93,    94,     0,    78,    79,
      80,    81,    82,    83,    84,     0,  -228,   116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    88,    85,    86,     0,    87,     0,    89,    90,
      91,    92,    93,    94,     0,     0,    78,    79,    80,    81,
      82,    83,    84,     0,    95,   255,     0,     0,    78,    79,
      80,    81,    82,    83,    84,     0,     0,     0,     0,    88,
       0,    85,    86,     0,    87,    89,    90,    91,    92,    93,
      94,     0,     0,    85,    86,     0,    87,     0,     0,     0,
       0,    95,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,     0,    20,    88,     0,     0,
       0,     0,     0,    89,    90,    91,    92,    93,    94,    88,
     305,     0,     0,     0,     0,    89,    90,    91,    92,    93,
      94,    78,    79,    80,    81,    82,    83,    84,     0,   317,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    84,
       0,     0,     0,     0,   325,     0,    85,    86,     0,    87,
       0,     0,   332,     0,     0,     0,     0,     0,    85,    86,
       0,    87,     0,   338,     0,   339,   340,   341,     0,     0,
       0,     0,     0,     0,    51,     1,   347,     0,   349,     0,
       0,     0,   137,     0,     0,     0,     0,     0,    89,    90,
      91,    92,    93,    94,   140,     1,     0,     0,     0,     0,
      89,    90,    91,    92,    93,    94,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,     0,    20,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,   118,    20,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,     0,    20,     0,     0,     0,   199,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   246,    20,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,     0,    20
};

static const yytype_int16 yycheck[] =
{
       0,    43,    88,    66,    66,    57,   134,    95,    41,   272,
      69,   100,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    85,    86,    87,    22,    69,     3,    87,    29,
      63,    69,     3,     3,    69,    20,    85,   100,    87,    38,
      37,    41,    60,   318,    87,    83,    65,    24,    25,    65,
      85,   137,    71,    69,   140,   330,    71,    56,    64,     3,
      66,    76,    77,    63,     3,    65,   152,   119,    69,    65,
      69,   134,   134,    69,   337,    26,    27,    95,   167,   168,
     169,    65,    64,    86,    66,    69,    84,    88,    64,    88,
      66,     3,   144,    64,    64,    71,    66,    82,    86,   185,
      71,    78,    79,    69,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   119,   251,   213,    64,   214,    88,   129,   130,
     129,   130,   133,   151,   133,   132,    65,    46,    47,   140,
      69,   140,    28,    29,    30,    65,   188,   165,    24,    69,
     213,    85,    28,   186,    86,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,   129,    51,
       1,   299,   133,    67,    64,    69,    66,     3,    64,   140,
      66,    65,    68,    72,    73,    85,   186,    86,   251,   251,
      71,   243,   210,   193,    22,    23,   214,   260,   260,   172,
     173,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    84,
      51,   170,   171,    84,   287,   287,    70,   313,    80,   315,
     316,   174,   175,   176,   177,    81,   299,   299,    69,   257,
     178,   179,    21,    65,    69,    69,    65,    67,    65,     3,
     336,     3,   249,    84,    85,    86,    64,     1,     3,     3,
       4,     5,     6,     7,     8,     9,    65,    83,    83,    65,
      65,    69,    85,    83,    85,     3,    85,    69,    65,    85,
      87,    64,    64,    64,    28,    29,   286,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    64,    51,    52,    83,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    85,    85,    65,    67,    55,    70,    71,    72,    73,
      74,    75,     1,    83,     3,     4,     5,     6,     7,     8,
       9,    85,    86,    87,    64,    53,    65,    85,   180,   182,
     184,   181,    58,   130,   183,   135,   249,   193,   286,    28,
      29,    64,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,   140,    51,    52,   243,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    29,    26,   133,   287,
     186,    70,    71,    72,    73,    74,    75,     1,   144,     3,
       4,     5,     6,     7,     8,     9,    85,    86,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    28,    29,    -1,    31,    -1,    70,    71,    72,    73,
      74,    75,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    85,    86,    87,    -1,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    28,
      29,    -1,    31,    70,    71,    72,    73,    74,    75,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    85,    86,
      87,    -1,    -1,    52,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    28,    29,    -1,    31,
      -1,    70,    71,    72,    73,    74,    75,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    85,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    28,    29,    -1,    31,    -1,    70,    71,
      72,    73,    74,    75,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    86,    87,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,    64,
      -1,    28,    29,    -1,    31,    70,    71,    72,    73,    74,
      75,    -1,    -1,    28,    29,    -1,    31,    -1,    -1,    -1,
      -1,    86,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    51,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    64,
     278,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,     3,     4,     5,     6,     7,     8,     9,    -1,   297,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    -1,   312,    -1,    28,    29,    -1,    31,
      -1,    -1,   320,    -1,    -1,    -1,    -1,    -1,    28,    29,
      -1,    31,    -1,   331,    -1,   333,   334,   335,    -1,    -1,
      -1,    -1,    -1,    -1,     0,     1,   344,    -1,   346,    -1,
      -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    64,     1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    51,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,     3,    51,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    51,    -1,    -1,    -1,    87,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    51
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      51,   111,   112,   115,   116,   117,   118,   124,   127,   161,
     162,   163,    85,    87,     3,   167,     3,    64,    71,   113,
     114,   128,   129,   130,   165,   112,   166,   166,     3,   167,
     166,     0,   162,    86,   128,   127,   131,   172,    69,     1,
      84,   111,   112,   149,   176,    64,    66,   129,    85,    86,
       3,   125,   126,    65,   127,   130,   114,   128,     3,     4,
       5,     6,     7,     8,     9,    28,    29,    31,    64,    70,
      71,    72,    73,    74,    75,    86,    89,    90,    91,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   140,   111,    86,   147,     3,   112,
     132,   133,   134,   135,   171,    93,   106,   110,   170,   116,
     119,   120,   121,   127,    84,    69,    87,    64,    93,    93,
      64,    93,   107,   109,   121,   136,   140,   141,    28,    29,
      30,    64,    66,    68,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    84,   108,    95,    71,    76,    77,
      72,    73,    26,    27,    24,    25,    78,    79,    22,    23,
      70,    80,    81,    21,    20,    82,   148,   128,   130,   137,
     173,   174,    65,    69,    69,    65,    67,   121,   168,    87,
     120,   122,   123,   128,   169,   168,   110,   126,   136,    65,
      69,   130,   173,    65,    69,    87,     3,    92,   107,   164,
     109,     3,   107,    95,    95,    95,    96,    96,    97,    97,
      98,    98,    98,    98,    99,    99,   100,   101,   102,   103,
     104,   109,   176,    64,   138,   139,    50,   134,     3,    69,
      85,    83,    65,   107,    95,    87,   140,    69,    65,    67,
      83,     1,     3,    52,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,   109,   142,   143,   147,   150,   151,
     152,   156,   160,   177,   178,   137,    64,    66,   123,   110,
     107,   106,    85,    83,   153,   154,   157,   158,   159,   145,
     146,    85,    85,   178,     3,   142,    87,    85,    65,   132,
     175,   170,   144,    64,   155,    64,    64,   142,    64,   110,
      83,    85,    85,    65,    67,   142,   109,   109,   109,    55,
     151,    83,   142,    65,    65,    65,    64,   151,   142,   142,
     142,   142,   109,   178,    53,    65,    65,   142,    85,   142
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 80:

/* Line 1455 of yacc.c  */
#line 253 "../src/tp4.y"
    {imprimir_especial(yylineno ,buffer_tipo, buffer_identificador); strcpy(buffer_tipo, ""); strcpy(buffer_identificador, "");;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 254 "../src/tp4.y"
    {yyerrok; strcpy(buffer_tipo, ""); strcpy(buffer_identificador, "");;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 257 "../src/tp4.y"
    {copiar_especial(buffer_tipo, (yyvsp[(1) - (2)].cadena));;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 258 "../src/tp4.y"
    {copiar_especial(buffer_tipo, (yyvsp[(1) - (2)].cadena));;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 259 "../src/tp4.y"
    {copiar_especial(buffer_tipo, (yyvsp[(1) - (2)].cadena));;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 262 "../src/tp4.y"
    {strcat(buffer_identificador, " ");;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 263 "../src/tp4.y"
    {strcat(buffer_identificador, " ");;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 290 "../src/tp4.y"
    {strcat(buffer_identificador, (yyvsp[(2) - (5)].cadena));;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 291 "../src/tp4.y"
    {strcat(buffer_identificador, (yyvsp[(2) - (2)].cadena));;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 317 "../src/tp4.y"
    {strcat(buffer_identificador, (yyvsp[(2) - (5)].cadena));;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 318 "../src/tp4.y"
    {copiar_especial(buffer_tipo, (yyvsp[(2) - (2)].cadena));;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 337 "../src/tp4.y"
    {strcat(buffer_identificador, (yyvsp[(1) - (1)].cadena));;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 338 "../src/tp4.y"
    {copiar_especial(buffer_identificador, "("); strcat(buffer_identificador, ")");;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 339 "../src/tp4.y"
    {strcat(buffer_identificador, "[]");;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 340 "../src/tp4.y"
    {strcpy(buffer_identificador, "");  strcpy(buffer_identificador, ""); strcat(buffer_identificador, (yyvsp[(1) - (4)].cadena)); strcat(buffer_identificador, "()");;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 341 "../src/tp4.y"
    {strcpy(buffer_tipo, ""); strcpy(buffer_identificador, "");;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 344 "../src/tp4.y"
    {strcat(buffer_identificador, "*");;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 352 "../src/tp4.y"
    {remover_especial(buffer_tipo);;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 398 "../src/tp4.y"
    {printf("Linea %03d: Sentencia de Expresion\n", yylineno);;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 401 "../src/tp4.y"
    {printf("Linea %03d: Sentencia de Salto\n", yylineno);;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 402 "../src/tp4.y"
    {yyerrok; strcpy(buffer_tipo, ""); strcpy(buffer_identificador, "");;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 405 "../src/tp4.y"
    {printf("Linea %03d: Sentencia Etiquetada\n", yylineno);;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 406 "../src/tp4.y"
    {printf("Linea %03d: Sentencia Etiquetada\n", yylineno);;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 407 "../src/tp4.y"
    {printf("Linea %03d: Sentencia Etiquetada\n", yylineno);;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 410 "../src/tp4.y"
    {printf("Linea %03d: Sentencia Compuesta\n", yylineno); strcpy(buffer_tipo, ""); strcpy(buffer_identificador, "");;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 424 "../src/tp4.y"
    {printf("Linea %03d: Sentencia de Seleccion\n", yylineno);;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 425 "../src/tp4.y"
    {printf("Linea %03d: Sentencia de Seleccion\n", yylineno);;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 432 "../src/tp4.y"
    {printf("Linea %03d: Sentencia de Iteracion\n", yylineno);;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 433 "../src/tp4.y"
    {printf("Linea %03d: Sentencia de Iteracion\n", yylineno);;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 434 "../src/tp4.y"
    {printf("Linea %03d: Sentencia de Iteracion\n", yylineno);;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 455 "../src/tp4.y"
    {yyerrok; strcpy(buffer_tipo, ""); strcpy(buffer_identificador, "");;}
    break;



/* Line 1455 of yacc.c  */
#line 2143 "tp4.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 520 "../src/tp4.y"


int main(int argc, char *argv[])
{
    #ifdef YYDEBUG
        yydebug = 0;
    #endif

    yyin = fopen(argv[1], "r");
    printf("/******************************/\n");
    printf("/********** REPORTE ***********/\n");
    printf("/******************************/\n");
    yyparse();
    fclose(yyin);

    return 0;
}
