
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
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "syntax.y"

#include <stdio.h>
#include <time.h>
#include "semantic.h"

clock_t start;
FILE* inputStream;
extern FILE* yyin;

extern int numLn;
extern int numCol;
extern int savedNumCol;
extern int numErrors;

extern int yylex();
extern int yytext;
extern int yyleng;
int yyerror(char* msg);

extern int decType;


/* Line 189 of yacc.c  */
#line 96 "syntax.tab.c"

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
     Program = 258,
     PDEC = 259,
     PINST = 260,
     Begin = 261,
     End = 262,
     FOR = 263,
     WHILE = 264,
     DO = 265,
     ENDFOR = 266,
     IF = 267,
     ELSE = 268,
     ENDIF = 269,
     define = 270,
     ASSIGN = 271,
     Pint = 272,
     Pfloat = 273,
     GRT = 274,
     GRT_EQ = 275,
     EQ = 276,
     NOT_EQ = 277,
     LESS_EQ = 278,
     LESS = 279,
     IDF = 280,
     PintVal = 281,
     PfloatVal = 282
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 23 "syntax.y"

    char* string;
    int pint;
    float pfloat;
    struct expressionData {
            int type;
            float value;
            int hasError;
    } expressionData;



/* Line 214 of yacc.c  */
#line 172 "syntax.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 197 "syntax.tab.c"

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
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   195

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNRULES -- Number of states.  */
#define YYNSTATES  132

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,     2,     2,     2,    29,     2,
      38,    39,    33,    31,     2,    32,     2,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,    36,
       2,    35,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    28,     2,     2,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     7,    10,    13,    18,    26,    33,    39,
      44,    48,    50,    54,    57,    60,    62,    65,    67,    71,
      72,    81,    90,   101,   111,   123,   132,   143,   147,   150,
     154,   158,   162,   164,   166,   168,   170,   172,   174,   176,
     178,   182,   187,   191,   195,   199,   203,   205,   207,   210,
     212,   215,   217,   219
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    42,    43,    44,    -1,     3,    25,    -1,
       4,    45,    -1,     5,     6,    47,     7,    -1,    45,    15,
      55,    25,    35,    56,    36,    -1,    15,    55,    25,    35,
      56,    36,    -1,    45,    46,    37,    55,    36,    -1,    46,
      37,    55,    36,    -1,    46,    28,    25,    -1,    25,    -1,
      47,    48,    36,    -1,    48,    36,    -1,    47,    49,    -1,
      49,    -1,    47,    51,    -1,    51,    -1,    25,    16,    54,
      -1,    -1,     8,    48,     9,    56,    50,    10,    47,    11,
      -1,    10,    48,    37,    12,    38,    52,    39,    14,    -1,
      10,    48,    37,    12,    38,    52,    39,    13,    47,    14,
      -1,    10,    47,    48,    37,    12,    38,    52,    39,    14,
      -1,    10,    47,    48,    37,    12,    38,    52,    39,    13,
      47,    14,    -1,    10,    47,    37,    12,    38,    52,    39,
      14,    -1,    10,    47,    37,    12,    38,    52,    39,    13,
      47,    14,    -1,    38,    52,    39,    -1,    30,    52,    -1,
      52,    29,    52,    -1,    52,    28,    52,    -1,    54,    53,
      54,    -1,    21,    -1,    22,    -1,    19,    -1,    20,    -1,
      24,    -1,    23,    -1,    56,    -1,    25,    -1,    38,    54,
      39,    -1,    57,    38,    54,    39,    -1,    54,    31,    54,
      -1,    54,    32,    54,    -1,    54,    33,    54,    -1,    54,
      34,    54,    -1,    17,    -1,    18,    -1,    57,    26,    -1,
      26,    -1,    57,    27,    -1,    27,    -1,    32,    -1,    31,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    54,    54,    61,    63,    65,    67,    77,    87,    90,
      94,   101,   109,   110,   111,   112,   113,   114,   116,   129,
     129,   134,   135,   136,   137,   138,   139,   141,   142,   143,
     144,   145,   150,   150,   150,   150,   150,   150,   152,   156,
     164,   169,   174,   183,   192,   202,   213,   214,   216,   221,
     226,   231,   237,   237
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Program", "PDEC", "PINST", "Begin",
  "End", "FOR", "WHILE", "DO", "ENDFOR", "IF", "ELSE", "ENDIF", "define",
  "ASSIGN", "Pint", "Pfloat", "GRT", "GRT_EQ", "EQ", "NOT_EQ", "LESS_EQ",
  "LESS", "IDF", "PintVal", "PfloatVal", "'|'", "'&'", "'!'", "'+'", "'-'",
  "'*'", "'/'", "'='", "';'", "':'", "'('", "')'", "$accept", "S",
  "Header", "PartieDeclaration", "PartieInstructions", "Declaration",
  "ListeIdf", "Instruction", "Assignement", "Boucle", "$@1", "DO_IF_Cond",
  "Condition", "OP_Comparison", "Expression", "Type", "Val", "Sign", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   124,    38,
      33,    43,    45,    42,    47,    61,    59,    58,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    43,    44,    45,    45,    45,    45,
      46,    46,    47,    47,    47,    47,    47,    47,    48,    50,
      49,    51,    51,    51,    51,    51,    51,    52,    52,    52,
      52,    52,    53,    53,    53,    53,    53,    53,    54,    54,
      54,    54,    54,    54,    54,    54,    55,    55,    56,    56,
      56,    56,    57,    57
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     2,     4,     7,     6,     5,     4,
       3,     1,     3,     2,     2,     1,     2,     1,     3,     0,
       8,     8,    10,     9,    11,     8,    10,     3,     2,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     3,     3,     3,     1,     1,     2,     1,
       2,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     3,     1,     0,     0,     0,    11,
       4,     0,     0,     2,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,     0,     0,     0,     0,
       0,     0,    15,    17,     0,     0,     0,     9,     0,     0,
       0,     0,     5,     0,    14,    16,    13,    49,    51,    53,
      52,     0,     0,     0,     8,     0,     0,     0,     0,    39,
       0,    18,    38,     0,    12,     7,    48,    50,     0,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     6,
       0,     0,     0,     0,    40,    42,    43,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,    41,     0,    28,
       0,     0,     0,     0,     0,    34,    35,    32,    33,    37,
      36,     0,     0,     0,    20,    27,    30,    29,     0,    25,
      31,     0,     0,    21,     0,     0,    23,     0,    26,     0,
      22,    24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     7,    13,    10,    11,    30,    31,    32,
      80,    33,    93,   111,    94,    16,    62,    63
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -42
static const yytype_int16 yypact[] =
{
       3,    -1,    67,    56,   -42,   -42,    -5,    76,    14,   -42,
     109,    47,    98,   -42,   -42,   -42,    48,    14,   114,   110,
      14,    11,    87,   118,    14,   -42,   105,   120,    11,   163,
      18,   144,   -42,   -42,   138,   146,   147,   -42,   173,    -3,
      16,   106,   -42,   148,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,   149,    62,   138,   -42,   138,   174,   116,   175,   -42,
     106,   140,   -42,    83,   -42,   -42,   -42,   -42,   152,   -42,
     151,   178,   153,   115,   106,   106,   106,   106,   106,   -42,
     182,    60,   155,    60,   -42,   127,   127,   -42,   -42,   124,
      11,    60,    60,    66,    96,    60,    84,   -42,     5,   -42,
      97,    25,    60,    60,   154,   -42,   -42,   -42,   -42,   -42,
     -42,   106,   111,   162,   -42,   -42,   165,   -42,    11,   -42,
     140,   164,    11,   -42,    55,    11,   -42,    58,   -42,    68,
     -42,   -42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -42,   -42,   -42,   -42,   -42,   -42,   185,   -11,   -27,   -28,
     -42,   -21,   -41,   -42,   -37,   142,   -26,   -20
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      38,    40,    44,    43,    61,    27,     1,    28,    51,    45,
       8,    44,    57,    27,    52,    28,   114,    39,    45,    27,
       9,    28,    29,    73,     4,    42,    27,    68,    28,    69,
      29,    14,    15,    52,    56,    52,    29,    85,    86,    87,
      88,    89,    96,    29,   105,   106,   107,   108,   109,   110,
      99,   100,    46,    58,   112,   101,    74,    75,    76,    77,
       6,   116,   117,    27,    84,    28,    27,     5,    28,   128,
      44,    43,   130,    22,   120,    19,    27,    45,    28,    98,
      29,    12,   131,    29,    20,    59,    47,    48,    66,    67,
      91,    49,    50,    29,   102,   103,    44,    43,    92,    44,
      43,    44,    43,    45,    21,   104,    45,   124,    45,    66,
      67,   127,   102,   103,   129,   105,   106,   107,   108,   109,
     110,    78,    34,   113,    17,   102,   103,    74,    75,    76,
      77,    59,    47,    48,     9,    25,   115,    49,    50,   102,
     103,    37,    19,    35,    60,    29,    74,    75,    76,    77,
     121,    24,    64,    71,    84,    74,    75,    76,    77,    23,
      76,    77,    26,    97,    47,    48,    36,   118,   119,    49,
      50,    74,    75,    76,    77,   122,   123,   125,   126,    41,
      46,    53,    55,    54,    64,    65,    70,    72,    79,    81,
      82,    83,    90,    95,   103,    18
};

static const yytype_uint8 yycheck[] =
{
      27,    28,    30,    30,    41,     8,     3,    10,    34,    30,
      15,    39,    39,     8,    34,    10,    11,    28,    39,     8,
      25,    10,    25,    60,    25,     7,     8,    53,    10,    55,
      25,    17,    18,    53,    37,    55,    25,    74,    75,    76,
      77,    78,    83,    25,    19,    20,    21,    22,    23,    24,
      91,    92,    36,    37,    95,    92,    31,    32,    33,    34,
       4,   102,   103,     8,    39,    10,     8,     0,    10,    14,
      98,    98,    14,    25,   111,    28,     8,    98,    10,    90,
      25,     5,    14,    25,    37,    25,    26,    27,    26,    27,
      30,    31,    32,    25,    28,    29,   124,   124,    38,   127,
     127,   129,   129,   124,     6,    39,   127,   118,   129,    26,
      27,   122,    28,    29,   125,    19,    20,    21,    22,    23,
      24,    38,    35,    39,    15,    28,    29,    31,    32,    33,
      34,    25,    26,    27,    25,    25,    39,    31,    32,    28,
      29,    36,    28,    25,    38,    25,    31,    32,    33,    34,
      39,    37,    36,    37,    39,    31,    32,    33,    34,    17,
      33,    34,    20,    39,    26,    27,    24,    13,    14,    31,
      32,    31,    32,    33,    34,    13,    14,    13,    14,    16,
      36,    35,     9,    36,    36,    36,    12,    12,    36,    38,
      12,    38,    10,    38,    29,    10
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    41,    42,    25,     0,     4,    43,    15,    25,
      45,    46,     5,    44,    17,    18,    55,    15,    46,    28,
      37,     6,    25,    55,    37,    25,    55,     8,    10,    25,
      47,    48,    49,    51,    35,    25,    55,    36,    48,    47,
      48,    16,     7,    48,    49,    51,    36,    26,    27,    31,
      32,    56,    57,    35,    36,     9,    37,    48,    37,    25,
      38,    54,    56,    57,    36,    36,    26,    27,    56,    56,
      12,    37,    12,    54,    31,    32,    33,    34,    38,    36,
      50,    38,    12,    38,    39,    54,    54,    54,    54,    54,
      10,    30,    38,    52,    54,    38,    52,    39,    47,    52,
      52,    54,    28,    29,    39,    19,    20,    21,    22,    23,
      24,    53,    52,    39,    11,    39,    52,    52,    13,    14,
      54,    39,    13,    14,    47,    13,    14,    47,    14,    47,
      14,    14
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

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

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

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
       `yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
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
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 54 "syntax.y"
    {
    double duration = (1000.0*(clock() - start)) / CLOCKS_PER_SEC;
    printf("===== Compilation finished in %.2fms with %d error(s) =====\n\n", duration, numErrors);
    afficher();
    YYACCEPT;
;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 67 "syntax.y"
    {
                savedNumCol = (yylsp[(4) - (7)]).first_column;
                if(checkNoDoubleDeclaration((yyvsp[(4) - (7)].string))){
                    savedNumCol = (yylsp[(5) - (7)]).first_column;
                    if(checkTypeCompatAffect((yyvsp[(4) - (7)].string), (yyvsp[(3) - (7)].pint), (yyvsp[(6) - (7)].expressionData).type, "=")){
                        insert((yyvsp[(4) - (7)].string), decType, 1);
                        updateValue((yyvsp[(4) - (7)].string), (yyvsp[(6) - (7)].expressionData).value);
                    }
                }
            ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 77 "syntax.y"
    {
                savedNumCol = (yylsp[(3) - (6)]).first_column;
                if(checkNoDoubleDeclaration((yyvsp[(3) - (6)].string))){
                    savedNumCol = (yylsp[(4) - (6)]).first_column;
                    if(checkTypeCompatAffect((yyvsp[(3) - (6)].string), (yyvsp[(2) - (6)].pint), (yyvsp[(5) - (6)].expressionData).type, "=")){
                        insert((yyvsp[(3) - (6)].string), decType, 1);
                        updateValue((yyvsp[(3) - (6)].string), (yyvsp[(5) - (6)].expressionData).value);
                    }
                }
            ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 87 "syntax.y"
    {
                MAJRecentVariables();
            ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 90 "syntax.y"
    {
                MAJRecentVariables();
            ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 94 "syntax.y"
    {
            savedNumCol = (yylsp[(3) - (3)]).first_column;
            if(checkNoDoubleDeclaration((yyvsp[(3) - (3)].string))){
                insert((yyvsp[(3) - (3)].string), -1, 0);
                updateValue((yyvsp[(3) - (3)].string), 0);
            }
         ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 101 "syntax.y"
    {
            savedNumCol = (yylsp[(1) - (1)]).first_column;
            if(checkNoDoubleDeclaration((yyvsp[(1) - (1)].string))){
                insert((yyvsp[(1) - (1)].string), -1, 0);
                updateValue((yyvsp[(1) - (1)].string), 0);
            }
         ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 116 "syntax.y"
    {
                savedNumCol = (yylsp[(1) - (3)]).first_column;
                (yyval.expressionData).type = (yyvsp[(3) - (3)].expressionData).type;
                (yyval.expressionData).value = (yyvsp[(3) - (3)].expressionData).value;
                (yyval.expressionData).hasError = (yyvsp[(3) - (3)].expressionData).hasError;
                if(checkIsDeclared((yyvsp[(1) - (3)].string))){
                    savedNumCol = (yylsp[(2) - (3)]).first_column;
                    if(checkNotReassigningConstant((yyvsp[(1) - (3)].string)) && checkTypeCompatAffect((yyvsp[(1) - (3)].string), search((yyvsp[(1) - (3)].string))->type, (yyvsp[(3) - (3)].expressionData).type, "<--") && (yyvsp[(3) - (3)].expressionData).hasError==0){
                        updateValue((yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].expressionData).value);
                    }
                }
            ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 129 "syntax.y"
    {
            savedNumCol = (yylsp[(3) - (4)]).first_column;
            checkTypeCompat((yyvsp[(2) - (4)].expressionData).type, "WHILE", (yyvsp[(4) - (4)].expressionData).type);
        ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 145 "syntax.y"
    {
              savedNumCol = (yylsp[(2) - (3)]).first_column;
              checkTypeCompat((yyvsp[(1) - (3)].expressionData).type, (yyvsp[(2) - (3)].string), (yyvsp[(3) - (3)].expressionData).type);
          ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 150 "syntax.y"
    {(yyval.string)="==";}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 150 "syntax.y"
    {(yyval.string)="!=";}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 150 "syntax.y"
    {(yyval.string)=">";}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 150 "syntax.y"
    {(yyval.string)=">=";}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 150 "syntax.y"
    {(yyval.string)="<";}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 150 "syntax.y"
    {(yyval.string)="<=";}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 152 "syntax.y"
    {
        (yyval.expressionData).type = (yyvsp[(1) - (1)].expressionData).type;
        (yyval.expressionData).value = (yyvsp[(1) - (1)].expressionData).value;
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 156 "syntax.y"
    {
        savedNumCol = (yylsp[(1) - (1)]).first_column;
        if(checkIsDeclared((yyvsp[(1) - (1)].string))){
            (yyval.expressionData).type = search((yyvsp[(1) - (1)].string))->type;
            (yyval.expressionData).value = searchValue((yyvsp[(1) - (1)].string))->value;
            (yyval.expressionData).hasError = 0;
        }
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 164 "syntax.y"
    {
        (yyval.expressionData).type = (yyvsp[(2) - (3)].expressionData).type;
        (yyval.expressionData).value = (yyvsp[(2) - (3)].expressionData).value;
        (yyval.expressionData).hasError = (yyvsp[(2) - (3)].expressionData).hasError;
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 169 "syntax.y"
    {
        (yyval.expressionData).type = (yyvsp[(3) - (4)].expressionData).type;
        (yyval.expressionData).value = ((yyvsp[(1) - (4)].pint)==0) ? (yyvsp[(3) - (4)].expressionData).value : -(yyvsp[(3) - (4)].expressionData).value;
        (yyval.expressionData).hasError = (yyvsp[(3) - (4)].expressionData).hasError;
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 174 "syntax.y"
    {
        savedNumCol = (yylsp[(2) - (3)]).first_column;
        (yyval.expressionData).type = (yyvsp[(1) - (3)].expressionData).type;
        if(checkTypeCompat((yyvsp[(1) - (3)].expressionData).type, "+", (yyvsp[(3) - (3)].expressionData).type)){
            (yyval.expressionData).value = (yyvsp[(1) - (3)].expressionData).value + (yyvsp[(3) - (3)].expressionData).value;
            (yyval.expressionData).hasError = (yyvsp[(1) - (3)].expressionData).hasError || (yyvsp[(3) - (3)].expressionData).hasError;
        }else
            (yyval.expressionData).hasError = 1;
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 183 "syntax.y"
    {
        savedNumCol = (yylsp[(2) - (3)]).first_column;
        (yyval.expressionData).type = (yyvsp[(1) - (3)].expressionData).type;
        if(checkTypeCompat((yyvsp[(1) - (3)].expressionData).type, "-", (yyvsp[(3) - (3)].expressionData).type)){
            (yyval.expressionData).value = (yyvsp[(1) - (3)].expressionData).value - (yyvsp[(3) - (3)].expressionData).value;
            (yyval.expressionData).hasError = (yyvsp[(1) - (3)].expressionData).hasError || (yyvsp[(3) - (3)].expressionData).hasError;
        }else
            (yyval.expressionData).hasError = 1;
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 192 "syntax.y"
    {
        savedNumCol = (yylsp[(2) - (3)]).first_column;
        (yyval.expressionData).type = (yyvsp[(1) - (3)].expressionData).type;
        if(checkTypeCompat((yyvsp[(1) - (3)].expressionData).type, "*", (yyvsp[(3) - (3)].expressionData).type)){
            (yyval.expressionData).value = (yyvsp[(1) - (3)].expressionData).value * (yyvsp[(3) - (3)].expressionData).value;
            (yyval.expressionData).hasError = (yyvsp[(1) - (3)].expressionData).hasError || (yyvsp[(3) - (3)].expressionData).hasError;
        }else
            (yyval.expressionData).hasError = 1;
        
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 202 "syntax.y"
    {
        savedNumCol = (yylsp[(2) - (3)]).first_column;
        (yyval.expressionData).type = (yyvsp[(1) - (3)].expressionData).type;
        if(checkTypeCompat((yyvsp[(1) - (3)].expressionData).type, "/", (yyvsp[(3) - (3)].expressionData).type) && checkNoDivisionByZero((yyvsp[(3) - (3)].expressionData).value)){
            if((yyvsp[(1) - (3)].expressionData).type == 0)(yyval.expressionData).value = ((int)(yyvsp[(1) - (3)].expressionData).value)/((int)(yyvsp[(3) - (3)].expressionData).value);// division entiere
            else (yyval.expressionData).value = (yyvsp[(1) - (3)].expressionData).value/(yyvsp[(3) - (3)].expressionData).value; // division réelle
            (yyval.expressionData).hasError = (yyvsp[(1) - (3)].expressionData).hasError || (yyvsp[(3) - (3)].expressionData).hasError;
        }else
            (yyval.expressionData).hasError = 1;
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 213 "syntax.y"
    {(yyval.pint)=0; decType=0;;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 214 "syntax.y"
    {(yyval.pint)=1; decType=1;;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 216 "syntax.y"
    {
        (yyval.expressionData).type = 0; 
        (yyval.expressionData).value = ((yyvsp[(1) - (2)].pint)==0) ? (yyvsp[(2) - (2)].pint) : -(yyvsp[(2) - (2)].pint);
        (yyval.expressionData).hasError = 0;
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 221 "syntax.y"
    {
        (yyval.expressionData).type = 0;
        (yyval.expressionData).value = (yyvsp[(1) - (1)].pint);
        (yyval.expressionData).hasError = 0;
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 226 "syntax.y"
    {
        (yyval.expressionData).type = 1;
        (yyval.expressionData).value = ((yyvsp[(1) - (2)].pint)==0) ? (yyvsp[(2) - (2)].pfloat) : -(yyvsp[(2) - (2)].pfloat);
        (yyval.expressionData).hasError = 0;
    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 231 "syntax.y"
    {
        (yyval.expressionData).type = 1;
        (yyval.expressionData).value = (yyvsp[(1) - (1)].pfloat);
        (yyval.expressionData).hasError = 0;
    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 237 "syntax.y"
    {(yyval.pint)=1;;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 237 "syntax.y"
    {(yyval.pint)=0;;}
    break;



/* Line 1455 of yacc.c  */
#line 1892 "syntax.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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

  yyerror_range[0] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[0] = yylsp[1-yylen];
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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
#line 239 "syntax.y"

int yyerror(char* msg){
    numErrors++;
    double s = (1000.0*(clock() - start)) / CLOCKS_PER_SEC;
    printf("SyntaxError, Ln %d, Col %d: Unexpected '%s'.\n", numLn, numCol-yyleng, yytext);
    showLineHighlightError(numLn, numCol-yyleng);
    printf("===== Compilation stopped in %.2fms with %d error(s) =====\n\n", s, numErrors);
    return 1;
}
int main( int argc, char *argv[] ){
    start = clock();
    if (argc > 1){
        inputStream = fopen( argv[1], "r" );
        yyin = fopen( argv[1], "r" );
    }else{
        inputStream = stdin;
        yyin = stdin;
    }
    yyparse();
    return 0;
}
