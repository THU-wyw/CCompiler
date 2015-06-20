/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "CParser.y"

#include <stdio.h>
#include <string>
#include "SyntaxNode.h"

Program* program;
extern int yylex();
void yyerror(const char*s) { 
	printf("ERROR: %s\n", s); 
}


/* Line 371 of yacc.c  */
#line 81 "CParser.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "CParser.hpp".  */
#ifndef YY_YY_CPARSER_HPP_INCLUDED
# define YY_YY_CPARSER_HPP_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
/* Line 387 of yacc.c  */
#line 14 "CParser.y"

	#include <vector>
	#include "SyntaxNode.h"
	#include "Type.h"


/* Line 387 of yacc.c  */
#line 120 "CParser.cpp"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     STRING_LITERAL = 259,
     IMMEDIATE_INTEGER = 260,
     INC_OP = 261,
     DEC_OP = 262,
     PTR_OP = 263,
     SHIFT_LEFT_OP = 264,
     SHIFT_RIGHT_OP = 265,
     LE_OP = 266,
     GE_OP = 267,
     EQ_OP = 268,
     NE_OP = 269,
     AND_OP = 270,
     OR_OP = 271,
     ADD_ASSIGN = 272,
     SUB_ASSIGN = 273,
     MUL_ASSIGN = 274,
     DIV_ASSIGN = 275,
     MOD_ASSIGN = 276,
     SHIFT_LEFT_ASSIGN = 277,
     SHIFT_RIGHT_ASSIGN = 278,
     AND_ASSIGN = 279,
     INCLUSIVE_OR_ASSIGN = 280,
     EXCLUSIVE_OR_ASSIGN = 281,
     CASE = 282,
     DEFAULT = 283,
     IF = 284,
     ELSE = 285,
     SWITCH = 286,
     WHILE = 287,
     DO = 288,
     FOR = 289,
     CONTINUE = 290,
     BREAK = 291,
     RETURN = 292,
     CHAR = 293,
     INT = 294,
     FLOAT = 295,
     CONST = 296,
     VOID = 297,
     OR_ASSIGN = 298,
     XOR_ASSIGN = 299,
     UADD = 300,
     UMINUS = 301,
     DEREFERENCE = 302,
     REFERENCE = 303,
     LOWER_THAN_ELSE = 304
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 20 "CParser.y"

	SyntaxNode* node;
	Program* program;
	Expression* expression;
	Identifier* identifier;
	std::vector<Identifier*>* identifier_list;
	ImmediateInteger* immediate_integer;
	StringLiteral* string_literal;
	UnaryExpression* unary_expression;
	BinaryExpression* binary_expression;
	std::vector<Expression*>* expression_list;
	FunctionCall* function_call;
	AssignmentExpression* assignment_expression;
	Statement* statement;
	Declaration* declaration;
	std::vector<Declaration*>* declaration_list;
	VariableDeclaration* variable_declaration;
	std::vector<VariableDeclaration*>* variable_declaration_list;
	StatementsBlock* statements_block;
	IfStatement* if_statement;
	WhileStatement* while_statement;
	ExpressionStatement* expression_statement;
	FunctionDeclaration* function_declaration;
	FunctionDefinition* function_definition;
	std::string* str;
	int number;
	char symbol;
	Type::BasicType vt_t;


/* Line 387 of yacc.c  */
#line 215 "CParser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_CPARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 243 "CParser.cpp"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1399

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNRULES -- Number of states.  */
#define YYNSTATES  197

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,     2,     2,     2,    55,    48,     2,
      65,    66,    54,    51,    68,    52,    62,    53,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    69,
      50,    43,    49,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,    47,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    70,    46,    71,    57,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    44,    45,
      58,    59,    60,    61,    67
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    15,    19,    23,
      27,    31,    35,    39,    43,    47,    51,    55,    59,    63,
      67,    71,    75,    79,    83,    87,    91,    95,    99,   103,
     107,   111,   115,   119,   123,   127,   131,   136,   140,   144,
     147,   150,   153,   156,   159,   162,   165,   168,   171,   174,
     179,   183,   185,   189,   191,   194,   196,   198,   202,   204,
     206,   208,   210,   211,   214,   217,   219,   224,   230,   235,
     237,   241,   244,   246,   248,   250,   252,   254,   256,   258,
     260,   262,   265,   269,   270,   273,   275,   278,   284,   292,
     298,   306,   316,   326,   329,   332,   336,   339,   341,   344,
     346,   348
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      73,     0,    -1,    99,    -1,    87,    -1,     5,    -1,     4,
      -1,    65,    74,    66,    -1,    74,    51,    74,    -1,    74,
      52,    74,    -1,    74,    54,    74,    -1,    74,    53,    74,
      -1,    74,    55,    74,    -1,    74,    47,    74,    -1,    74,
      46,    74,    -1,    74,    48,    74,    -1,    74,     9,    74,
      -1,    74,    10,    74,    -1,    74,    49,    74,    -1,    74,
      50,    74,    -1,    74,    13,    74,    -1,    74,    11,    74,
      -1,    74,    12,    74,    -1,    74,    14,    74,    -1,    74,
      43,    74,    -1,    74,    17,    74,    -1,    74,    18,    74,
      -1,    74,    19,    74,    -1,    74,    20,    74,    -1,    74,
      21,    74,    -1,    74,    24,    74,    -1,    74,    26,    74,
      -1,    74,    25,    74,    -1,    74,    22,    74,    -1,    74,
      23,    74,    -1,    74,    15,    74,    -1,    74,    16,    74,
      -1,    74,    63,    74,    64,    -1,    74,    62,    74,    -1,
      74,     8,    74,    -1,    74,     6,    -1,    74,     7,    -1,
       6,    74,    -1,     7,    74,    -1,    48,    74,    -1,    54,
      74,    -1,    51,    74,    -1,    52,    74,    -1,    57,    74,
      -1,    56,    74,    -1,    87,    65,    75,    66,    -1,    87,
      65,    66,    -1,    74,    -1,    75,    68,    74,    -1,    80,
      -1,    76,    78,    -1,    79,    -1,    82,    -1,    82,    43,
      88,    -1,    42,    -1,    38,    -1,    39,    -1,    40,    -1,
      -1,    54,    81,    -1,    81,    83,    -1,    87,    -1,    83,
      63,    74,    64,    -1,    76,    82,    65,    85,    66,    -1,
      76,    82,    65,    66,    -1,    86,    -1,    85,    68,    86,
      -1,    76,    82,    -1,     3,    -1,    74,    -1,    90,    -1,
      93,    -1,    94,    -1,    95,    -1,    96,    -1,    97,    -1,
      98,    -1,    77,    69,    -1,    70,    91,    71,    -1,    -1,
      91,    92,    -1,    89,    -1,    74,    69,    -1,    29,    65,
      74,    66,    89,    -1,    29,    65,    74,    66,    89,    30,
      89,    -1,    32,    65,    74,    66,    89,    -1,    33,    89,
      32,    65,    74,    66,    69,    -1,    34,    65,    74,    69,
      74,    69,    74,    66,    89,    -1,    34,    65,    77,    69,
      74,    69,    74,    66,    89,    -1,    35,    69,    -1,    36,
      69,    -1,    37,    74,    69,    -1,    37,    69,    -1,   100,
      -1,    99,   100,    -1,   101,    -1,    77,    -1,    84,    90,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   117,   117,   121,   122,   126,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   178,   179,   192,   208,   217,   236,   237,   244,   245,
     246,   247,   251,   252,   256,   265,   270,   283,   287,   294,
     298,   305,   313,   317,   325,   326,   327,   328,   329,   330,
     331,   332,   336,   342,   346,   354,   358,   364,   367,   373,
     376,   383,   386,   393,   396,   402,   405,   415,   419,   425,
     428,   434
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING_LITERAL",
  "IMMEDIATE_INTEGER", "INC_OP", "DEC_OP", "PTR_OP", "SHIFT_LEFT_OP",
  "SHIFT_RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "SHIFT_LEFT_ASSIGN", "SHIFT_RIGHT_ASSIGN", "AND_ASSIGN",
  "INCLUSIVE_OR_ASSIGN", "EXCLUSIVE_OR_ASSIGN", "CASE", "DEFAULT", "IF",
  "ELSE", "SWITCH", "WHILE", "DO", "FOR", "CONTINUE", "BREAK", "RETURN",
  "CHAR", "INT", "FLOAT", "CONST", "VOID", "'='", "OR_ASSIGN",
  "XOR_ASSIGN", "'|'", "'^'", "'&'", "'>'", "'<'", "'+'", "'-'", "'/'",
  "'*'", "'%'", "'!'", "'~'", "UADD", "UMINUS", "DEREFERENCE", "REFERENCE",
  "'.'", "'['", "']'", "'('", "')'", "LOWER_THAN_ELSE", "','", "';'",
  "'{'", "'}'", "$accept", "program", "expression",
  "argument_expression_list", "declaration_specifiers",
  "variable_declaration", "init_declarator_list", "init_declarator",
  "type_specifier", "pointer", "declarator", "direct_declarator",
  "function_declarator", "parameter_list", "parameter_declaration",
  "identifier", "initializer", "statement", "compound_statement",
  "block_item_list", "block_item", "expression_statement", "if_statement",
  "while_statement", "for_statement", "jump_statement", "return_statement",
  "translation_unit", "declaration", "function_declaration", YY_NULL
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
     295,   296,   297,    61,   298,   299,   124,    94,    38,    62,
      60,    43,    45,    47,    42,    37,    33,   126,   300,   301,
     302,   303,    46,    91,    93,    40,    41,   304,    44,    59,
     123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    72,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    75,    75,    76,    77,    78,    79,    79,    80,    80,
      80,    80,    81,    81,    82,    83,    83,    84,    84,    85,
      85,    86,    87,    88,    89,    89,    89,    89,    89,    89,
      89,    89,    90,    91,    91,    92,    93,    94,    94,    95,
      95,    96,    96,    97,    97,    98,    98,    99,    99,   100,
     100,   101
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     3,     3,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     4,
       3,     1,     3,     1,     2,     1,     1,     3,     1,     1,
       1,     1,     0,     2,     2,     1,     4,     5,     4,     1,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     0,     2,     1,     2,     5,     7,     5,
       7,     9,     9,     2,     2,     3,     2,     1,     2,     1,
       1,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    59,    60,    61,    58,     0,    62,   100,    53,     0,
       2,    97,    99,     1,    62,    54,    55,     0,    56,    83,
     101,    98,    63,    72,    64,    65,     0,     0,     0,     0,
       5,     4,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,     3,    57,    68,    62,     0,    69,     0,     0,
       0,     0,     0,     0,     0,    82,     0,    62,     0,    85,
      74,    84,    75,    76,    77,    78,    79,    80,     0,    41,
      42,    43,    45,    46,    44,    48,    47,     0,    39,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    71,    67,     0,     0,     0,     0,     0,
      93,    94,    96,     0,    86,    56,    81,    66,     6,    38,
      15,    16,    20,    21,    19,    22,    34,    35,    24,    25,
      26,    27,    28,    32,    33,    29,    31,    30,    23,    13,
      12,    14,    17,    18,     7,     8,    10,     9,    11,    37,
       0,    50,    51,     0,    70,     0,     0,     0,     0,     0,
      95,    36,    49,     0,     0,     0,     0,     0,     0,    52,
      87,    89,     0,     0,     0,     0,     0,     0,     0,    88,
      90,     0,     0,     0,     0,    91,    92
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,    56,   163,    57,    58,    15,    16,     8,    17,
      18,    24,     9,    46,    47,    42,    43,    59,    60,    28,
      61,    62,    63,    64,    65,    66,    67,    10,    11,    12
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -50
static const yytype_int16 yypact[] =
{
      -3,   -50,   -50,   -50,   -50,     4,   -34,   -50,   -50,   -40,
      -3,   -50,   -50,   -50,   -34,   -50,   -50,    35,   -41,   -50,
     -50,   -50,   -50,   -50,   -22,   -50,   526,   -21,   134,   526,
     -50,   -50,   526,   526,   526,   526,   526,   526,   526,   526,
     526,  1092,   -25,   -50,   -50,   -34,   -43,   -50,   -19,   -13,
     174,   -12,   -27,    20,    44,   -50,   239,   -34,    28,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   974,    25,
      25,    25,    25,    25,    25,    25,    25,   608,   -50,   -50,
     526,   526,   526,   526,   526,   526,   526,   526,   526,   526,
     526,   526,   526,   526,   526,   526,   526,   526,   526,   526,
     526,   526,   526,   526,   526,   526,   526,   526,   526,   526,
     526,   526,   519,   -50,   -50,    -3,   526,   526,    12,   548,
     -50,   -50,   -50,   303,   -50,    51,   -50,   -50,   -50,   -50,
     586,   586,  1298,  1298,  1336,  1336,  1189,  1171,  1113,  1113,
    1113,  1113,  1113,  1113,  1113,  1113,  1113,  1113,  1113,  1247,
    1263,  1278,  1298,  1298,   213,   213,    96,    96,    96,   -50,
    1033,   -50,  1092,   -39,   -50,   669,   730,    34,   367,    36,
     -50,   -50,   -50,   526,   174,   174,   526,   526,   526,  1092,
      76,   -50,   791,   431,   495,   174,    38,   526,   526,   -50,
     -50,   852,   913,   174,   174,   -50,   -50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -50,   -50,   -26,   -50,    16,     5,   -50,   -50,   -50,    94,
     -23,   -50,   -50,   -50,    -5,    95,   -50,   -49,   102,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   104,   -50
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      41,   118,    26,    68,    13,     7,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     7,     6,     1,     2,     3,
      14,     4,   113,   114,    27,   115,     6,   172,   123,   173,
      19,    -1,    -1,    80,   125,     1,     2,     3,    23,     4,
     112,    29,   120,    45,   167,    44,   116,    23,    30,    31,
      32,    33,   117,   119,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   162,   110,   111,   121,
     165,   166,    34,   168,    26,    35,    36,   126,    37,   176,
      38,    39,    78,    79,    80,   178,   185,   190,    22,    40,
     164,    20,    25,   122,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   169,   180,   181,     0,     0,     0,
       0,    45,     0,     0,     0,     0,   189,    23,    30,    31,
      32,    33,     0,     0,   195,   196,     0,   179,     0,     0,
     182,   183,   184,     0,     0,     0,     0,     0,   110,   111,
       0,   191,   192,    48,     0,     0,    49,    50,    51,    52,
      53,    54,     1,     2,     3,     0,     4,    23,    30,    31,
      32,    33,    34,     0,     0,    35,    36,     0,    37,     0,
      38,    39,     0,     0,     0,     0,     0,     0,     0,    40,
       0,     0,     0,    48,    19,    55,    49,    50,    51,    52,
      53,    54,     1,     2,     3,     0,     4,     0,     0,    78,
      79,    80,    34,     0,     0,    35,    36,     0,    37,     0,
      38,    39,     0,     0,     0,     0,     0,     0,     0,    40,
       0,     0,     0,     0,    19,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,   107,   108,   109,     0,
       0,     0,     0,     0,     0,   110,   111,     0,     0,     0,
       0,     0,    99,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,     0,     0,     0,     0,     0,
       0,   110,   111,     0,     0,     0,     0,     0,   124,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    99,     0,     0,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
       0,     0,     0,     0,     0,   110,   111,     0,     0,     0,
       0,     0,   170,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      99,     0,     0,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,     0,     0,     0,     0,     0,   110,
     111,     0,     0,     0,     0,     0,   177,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    99,     0,     0,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,     0,     0,     0,
       0,     0,     0,   110,   111,     0,     0,     0,     0,     0,
     187,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    23,    30,    31,    32,    33,     0,     0,    23,
      30,    31,    32,    33,     0,     0,     0,     0,    99,     0,
       0,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,    23,    30,    31,    32,    33,     0,   110,   111,     0,
       0,     0,     0,     0,   188,     0,     0,    34,     0,     0,
      35,    36,     0,    37,    34,    38,    39,    35,    36,     0,
      37,     0,    38,    39,    40,   161,     1,     2,     3,     0,
       4,    40,    78,    79,    80,     0,    34,     0,     0,    35,
      36,     0,    37,     0,    38,    39,     0,     0,     0,     0,
       0,     0,     0,    40,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,     0,     0,   105,   106,   107,
     108,   109,     0,     0,     0,     0,     0,     0,   110,   111,
       0,    99,     0,     0,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,     0,     0,     0,     0,     0,     0,
     110,   111,     0,     0,   128,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    99,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,     0,     0,     0,     0,     0,
       0,   110,   111,     0,     0,   174,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    99,     0,     0,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,     0,     0,     0,     0,
       0,     0,   110,   111,     0,     0,   175,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    99,     0,     0,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,     0,     0,     0,
       0,     0,     0,   110,   111,     0,     0,   186,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,     0,     0,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,     0,     0,
       0,     0,     0,     0,   110,   111,     0,     0,   193,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    99,     0,     0,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
       0,     0,     0,     0,     0,   110,   111,     0,     0,   194,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    99,     0,     0,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
       0,     0,     0,     0,     0,     0,   110,   111,   127,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    99,     0,     0,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
       0,     0,     0,     0,     0,   110,   111,   171,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       0,     0,     0,     0,     0,    99,     0,     0,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,     0,     0,
       0,     0,     0,     0,   110,   111,     0,     0,     0,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
       0,     0,     0,     0,     0,   110,   111,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     0,     0,     0,
       0,     0,     0,     0,     0,    78,    79,    80,    81,    82,
      83,    84,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,     0,     0,     0,
       0,     0,     0,   110,   111,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,     0,     0,     0,     0,     0,
       0,   110,   111,    78,    79,    80,    81,    82,    83,    84,
      85,    86,     0,     0,     0,     0,     0,     0,     0,    78,
      79,    80,    81,    82,    83,    84,    85,    86,     0,     0,
       0,     0,     0,     0,    78,    79,    80,    81,    82,    83,
      84,    85,    86,     0,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,    78,    79,    80,    81,    82,   110,
     111,   102,   103,   104,   105,   106,   107,   108,   109,     0,
       0,     0,     0,     0,     0,   110,   111,   103,   104,   105,
     106,   107,   108,   109,     0,     0,     0,     0,     0,     0,
     110,   111,    78,    79,    80,    81,    82,    83,    84,   105,
     106,   107,   108,   109,     0,     0,     0,     0,     0,     0,
     110,   111,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   104,   105,   106,   107,
     108,   109,     0,     0,     0,     0,     0,     0,   110,   111
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-50)))

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

static const yytype_int16 yycheck[] =
{
      26,    50,    43,    29,     0,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    10,     0,    38,    39,    40,
      54,    42,    45,    66,    65,    68,    10,    66,    54,    68,
      70,     6,     7,     8,    57,    38,    39,    40,     3,    42,
      65,    63,    69,    27,    32,    66,    65,     3,     4,     5,
       6,     7,    65,    65,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,    62,    63,    69,
     116,   117,    48,   119,    43,    51,    52,    69,    54,    65,
      56,    57,     6,     7,     8,    69,    30,    69,    14,    65,
     115,     9,    17,    69,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   119,   174,   175,    -1,    -1,    -1,
      -1,   115,    -1,    -1,    -1,    -1,   185,     3,     4,     5,
       6,     7,    -1,    -1,   193,   194,    -1,   173,    -1,    -1,
     176,   177,   178,    -1,    -1,    -1,    -1,    -1,    62,    63,
      -1,   187,   188,    29,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,     3,     4,     5,
       6,     7,    48,    -1,    -1,    51,    52,    -1,    54,    -1,
      56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    -1,    29,    70,    71,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    -1,     6,
       7,     8,    48,    -1,    -1,    51,    52,    -1,    54,    -1,
      56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    -1,    -1,    70,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    -1,    -1,    -1,    -1,    -1,    69,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    -1,    -1,    -1,
      -1,    -1,    69,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      63,    -1,    -1,    -1,    -1,    -1,    69,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,
      69,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,     3,     4,     5,     6,     7,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     3,     4,     5,     6,     7,    -1,    62,    63,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    48,    -1,    -1,
      51,    52,    -1,    54,    48,    56,    57,    51,    52,    -1,
      54,    -1,    56,    57,    65,    66,    38,    39,    40,    -1,
      42,    65,     6,     7,     8,    -1,    48,    -1,    -1,    51,
      52,    -1,    54,    -1,    56,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      -1,    43,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    -1,    -1,    66,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    -1,    -1,    66,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    63,    -1,    -1,    66,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    -1,    -1,    66,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    63,    -1,    -1,    66,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    -1,    -1,    66,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    64,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    63,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,     6,     7,     8,     9,    10,    62,
      63,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,     6,     7,     8,     9,    10,    11,    12,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    38,    39,    40,    42,    73,    76,    77,    80,    84,
      99,   100,   101,     0,    54,    78,    79,    81,    82,    70,
      90,   100,    81,     3,    83,    87,    43,    65,    91,    63,
       4,     5,     6,     7,    48,    51,    52,    54,    56,    57,
      65,    74,    87,    88,    66,    76,    85,    86,    29,    32,
      33,    34,    35,    36,    37,    71,    74,    76,    77,    89,
      90,    92,    93,    94,    95,    96,    97,    98,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    43,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      62,    63,    65,    82,    66,    68,    65,    65,    89,    65,
      69,    69,    69,    74,    69,    82,    69,    64,    66,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    66,    74,    75,    86,    74,    74,    32,    74,    77,
      69,    64,    66,    68,    66,    66,    65,    69,    69,    74,
      89,    89,    74,    74,    74,    30,    66,    69,    69,    89,
      69,    74,    74,    66,    66,    89,    89
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

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

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
/* Line 1792 of yacc.c  */
#line 117 "CParser.y"
    { (yyval.program) = (yyvsp[(1) - (1)].program); program = (yyvsp[(1) - (1)].program); }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 121 "CParser.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].identifier); }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 122 "CParser.y"
    { 
		(yyval.expression) = new ImmediateInteger(atol((yyvsp[(1) - (1)].str)->c_str())); 
		delete (yyvsp[(1) - (1)].str);
	}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 126 "CParser.y"
    {
		(yyval.expression) = new StringLiteral(*(yyvsp[(1) - (1)].str));
		delete (yyvsp[(1) - (1)].str);
	}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 130 "CParser.y"
    { (yyval.expression) = (yyvsp[(2) - (3)].expression); }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 131 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), BinaryExpression::Operator::ADD); }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 132 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), BinaryExpression::Operator::SUB); }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 133 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), BinaryExpression::Operator::MUL); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 134 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), BinaryExpression::Operator::DIV); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 135 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), BinaryExpression::Operator::MOD); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 136 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), BinaryExpression::Operator::XOR_BIT); }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 137 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), BinaryExpression::Operator::OR_BIT); }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 138 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), BinaryExpression::Operator::AND_BIT); }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 139 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), BinaryExpression::Operator::SHIFT_LEFT); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 140 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), BinaryExpression::Operator::SHIFT_RIGHT); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 141 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), BinaryExpression::Operator::GREATER); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 142 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), BinaryExpression::Operator::LESS); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 143 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), BinaryExpression::Operator::EQUAL); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 144 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), BinaryExpression::Operator::LESS_EQUAL); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 145 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), BinaryExpression::Operator::GREATER_EQUAL); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 146 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), BinaryExpression::Operator::NOT_EQUAL); }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 147 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), AssignmentExpression::Operator::ASSIGN); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 148 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), AssignmentExpression::Operator::ADD_ASSIGN); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 149 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), AssignmentExpression::Operator::SUB_ASSIGN); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 150 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), AssignmentExpression::Operator::MUL_ASSIGN); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 151 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), AssignmentExpression::Operator::DIV_ASSIGN); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 152 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), AssignmentExpression::Operator::MOD_ASSIGN); }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 153 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), AssignmentExpression::Operator::AND_ASSIGN); }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 154 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), AssignmentExpression::Operator::EXCLUSIVE_OR_ASSIGN); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 155 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), AssignmentExpression::Operator::INCLUSIVE_OR_ASSIGN); }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 156 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), AssignmentExpression::Operator::SHIFT_LEFT_ASSIGN); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 157 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), AssignmentExpression::Operator::SHIFT_RIGHT_ASSIGN); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 158 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), BinaryExpression::Operator::AND); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 159 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), BinaryExpression::Operator::OR); }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 160 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].expression), BinaryExpression::Operator::INDEX); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 161 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), BinaryExpression::Operator::DOT); }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 162 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression), BinaryExpression::Operator::POINTER); }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 163 "CParser.y"
    { (yyval.expression) = new UnaryExpression((yyvsp[(1) - (2)].expression), UnaryExpression::Operator::INC_AFTER); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 164 "CParser.y"
    { (yyval.expression) = new UnaryExpression((yyvsp[(1) - (2)].expression), UnaryExpression::Operator::DEC_AFTER); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 165 "CParser.y"
    { (yyval.expression) = new UnaryExpression((yyvsp[(2) - (2)].expression), UnaryExpression::Operator::INC_PRE); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 166 "CParser.y"
    { (yyval.expression) = new UnaryExpression((yyvsp[(2) - (2)].expression), UnaryExpression::Operator::DEC_PRE); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 167 "CParser.y"
    { (yyval.expression) = new UnaryExpression((yyvsp[(2) - (2)].expression), UnaryExpression::Operator::REFERENCE); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 168 "CParser.y"
    { (yyval.expression) = new UnaryExpression((yyvsp[(2) - (2)].expression), UnaryExpression::Operator::DEREFERENCE); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 169 "CParser.y"
    { (yyval.expression) = (yyvsp[(2) - (2)].expression); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 170 "CParser.y"
    { (yyval.expression) = new UnaryExpression((yyvsp[(2) - (2)].expression), UnaryExpression::Operator::MINUS); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 171 "CParser.y"
    { (yyval.expression) = new UnaryExpression((yyvsp[(2) - (2)].expression), UnaryExpression::Operator::NOT_BIT); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 172 "CParser.y"
    { (yyval.expression) = new UnaryExpression((yyvsp[(2) - (2)].expression), UnaryExpression::Operator::NOT); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 173 "CParser.y"
    { (yyval.expression) = new FunctionCall((yyvsp[(1) - (4)].identifier), (yyvsp[(3) - (4)].expression_list)); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 174 "CParser.y"
    { (yyval.expression) = new FunctionCall((yyvsp[(1) - (3)].identifier), NULL); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 178 "CParser.y"
    { (yyval.expression_list) = new std::vector<Expression*>(); (yyval.expression_list)->push_back((yyvsp[(1) - (1)].expression)); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 179 "CParser.y"
    { (yyval.expression_list)->push_back((yyvsp[(3) - (3)].expression)); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 208 "CParser.y"
    {
		for (auto iterator = (yyvsp[(2) - (2)].variable_declaration_list)->begin(); iterator != (yyvsp[(2) - (2)].variable_declaration_list)->end(); iterator++) {
			(*iterator)->set_basic_type((yyvsp[(1) - (2)].vt_t));
		}
		(yyval.variable_declaration) = *((yyvsp[(2) - (2)].variable_declaration_list)->begin());
	}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 217 "CParser.y"
    {
		(yyval.variable_declaration_list) = new std::vector<VariableDeclaration*>();
		(yyval.variable_declaration_list)->push_back((yyvsp[(1) - (1)].variable_declaration));
	}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 237 "CParser.y"
    {
		(yyval.variable_declaration) = (yyvsp[(1) - (3)].variable_declaration);
		(yyval.variable_declaration)->set_initializer((yyvsp[(3) - (3)].expression));
	}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 244 "CParser.y"
    { (yyval.vt_t) = Type::BasicType::VOID; }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 245 "CParser.y"
    { (yyval.vt_t) = Type::BasicType::CHARACTER; }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 246 "CParser.y"
    { (yyval.vt_t) = Type::BasicType::INTEGER; }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 247 "CParser.y"
    { (yyval.vt_t) = Type::BasicType::FLOAT; }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 251 "CParser.y"
    { (yyval.number) = 0; }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 252 "CParser.y"
    { (yyval.number) = (yyvsp[(2) - (2)].number) + 1; }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 256 "CParser.y"
    {
		for (int i = 0; i < (yyvsp[(1) - (2)].number); i++) {
			(yyvsp[(2) - (2)].variable_declaration)->set_type(Type::CreatePointerType((yyvsp[(2) - (2)].variable_declaration)->get_type())); 
		}
		(yyval.variable_declaration) = (yyvsp[(2) - (2)].variable_declaration);
	}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 265 "CParser.y"
    {
		(yyval.variable_declaration) = new VariableDeclaration();
		(yyval.variable_declaration)->set_type(Type::CreateBasicType());
		(yyval.variable_declaration)->set_identifier((yyvsp[(1) - (1)].identifier));
	}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 270 "CParser.y"
    {
		(yyvsp[(1) - (4)].variable_declaration)->set_type(Type::CreateArrayType((yyvsp[(1) - (4)].variable_declaration)->get_type(), (yyvsp[(3) - (4)].expression))); 
		(yyval.variable_declaration) = (yyvsp[(1) - (4)].variable_declaration);
	}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 283 "CParser.y"
    {
		(yyval.function_declaration) = new FunctionDeclaration((yyvsp[(2) - (5)].variable_declaration)->get_identifier(), (yyvsp[(4) - (5)].variable_declaration_list));
		(yyval.function_declaration)->set_return_type((yyvsp[(2) - (5)].variable_declaration)->get_type());
	}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 287 "CParser.y"
    {
		(yyval.function_declaration) = new FunctionDeclaration((yyvsp[(2) - (4)].variable_declaration)->get_identifier(), new std::vector<VariableDeclaration*>());
		(yyval.function_declaration)->set_return_type((yyvsp[(2) - (4)].variable_declaration)->get_type());
	}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 294 "CParser.y"
    {
		(yyval.variable_declaration_list) = new std::vector<VariableDeclaration*>();
		(yyval.variable_declaration_list)->push_back((yyvsp[(1) - (1)].variable_declaration));
	}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 298 "CParser.y"
    {
		(yyvsp[(1) - (3)].variable_declaration_list)->push_back((yyvsp[(3) - (3)].variable_declaration));
		(yyval.variable_declaration_list) = (yyvsp[(1) - (3)].variable_declaration_list);
	}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 305 "CParser.y"
    {
		std::cout << "parameter_declaration" << std::endl;
		(yyvsp[(2) - (2)].variable_declaration)->set_basic_type((yyvsp[(1) - (2)].vt_t));
		(yyval.variable_declaration) = (yyvsp[(2) - (2)].variable_declaration);
	}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 313 "CParser.y"
    { (yyval.identifier) = new Identifier(*(yyvsp[(1) - (1)].str)); }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 332 "CParser.y"
    { (yyval.statement) = (yyvsp[(1) - (2)].variable_declaration); }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 336 "CParser.y"
    {
		(yyval.statement) = (yyvsp[(2) - (3)].statement);
	}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 342 "CParser.y"
    {
		(yyval.statement) = new StatementsBlock();
		//((StatementsBlock *)$$)->PushStatement($1);
	}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 346 "CParser.y"
    {
		std::cout << "block_item_list" << std::endl;
		((StatementsBlock *)(yyvsp[(1) - (2)].statement))->PushStatement((yyvsp[(2) - (2)].statement));
		(yyval.statement) = (yyvsp[(1) - (2)].statement);
	}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 358 "CParser.y"
    {
		(yyval.statement) = new ExpressionStatement((yyvsp[(1) - (2)].expression));
	}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 364 "CParser.y"
    {
		(yyval.statement) = new IfStatement((yyvsp[(3) - (5)].expression), (yyvsp[(5) - (5)].statement));
	}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 367 "CParser.y"
    {
		(yyval.statement) = new IfStatement((yyvsp[(3) - (7)].expression), (yyvsp[(5) - (7)].statement), (yyvsp[(7) - (7)].statement));
	}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 373 "CParser.y"
    {
		(yyval.statement) = new WhileStatement ((yyvsp[(3) - (5)].expression), (yyvsp[(5) - (5)].statement));
	}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 376 "CParser.y"
    {
		(yyval.statement) = new WhileStatement ((yyvsp[(5) - (7)].expression), (yyvsp[(2) - (7)].statement), true);
	}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 383 "CParser.y"
    {
		(yyval.statement) = new ForStatement(new ExpressionStatement((yyvsp[(3) - (9)].expression)), (yyvsp[(5) - (9)].expression), (yyvsp[(7) - (9)].expression), (yyvsp[(9) - (9)].statement));
	}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 386 "CParser.y"
    {
		(yyval.statement) = new ForStatement((yyvsp[(3) - (9)].variable_declaration), (yyvsp[(5) - (9)].expression), (yyvsp[(7) - (9)].expression), (yyvsp[(9) - (9)].statement));
	}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 393 "CParser.y"
    {
		(yyval.statement) = new JumpStatement(JumpStatement::CONTINUE);
	}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 396 "CParser.y"
    {
		(yyval.statement) = new JumpStatement(JumpStatement::BREAK);
	}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 402 "CParser.y"
    {
		(yyval.statement) = new ReturnStatement((yyvsp[(2) - (3)].expression));
	}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 405 "CParser.y"
    {
		(yyval.statement) = new ReturnStatement(NULL);
	}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 415 "CParser.y"
    {
		(yyval.program) = new Program();
		(yyval.program)->PushDeclaration((yyvsp[(1) - (1)].declaration));
	}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 419 "CParser.y"
    {
		(yyval.program)->PushDeclaration((yyvsp[(2) - (2)].declaration));
	}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 425 "CParser.y"
    {
		(yyval.declaration) = (yyvsp[(1) - (1)].function_declaration);
	}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 428 "CParser.y"
    {
		(yyval.declaration) = (yyvsp[(1) - (1)].variable_declaration);
	}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 434 "CParser.y"
    {
		(yyvsp[(1) - (2)].function_declaration)->set_body((yyvsp[(2) - (2)].statement));
		(yyval.function_declaration) = (yyvsp[(1) - (2)].function_declaration);
	}
    break;


/* Line 1792 of yacc.c  */
#line 2484 "CParser.cpp"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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


