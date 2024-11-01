/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"
  
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    

    extern FILE *yyin;
    extern int yylineno;
    extern int yylex();
    void yyerror(const char *s);

    // AST Node structure definition
    typedef enum { NODE_DECLARATION, NODE_STATEMENT, NODE_EXPRESSION } NodeType;

    typedef struct ASTNode {
        NodeType type;
        char* value;
        struct ASTNode* left;
        struct ASTNode* right;
    } ASTNode;

    ASTNode* create_node(NodeType type, char* value, ASTNode* left, ASTNode* right);
    void print_ast(ASTNode* node, int indent);

    // Create a new AST node
    ASTNode* create_node(NodeType type, char* value, ASTNode* left, ASTNode* right) {
        ASTNode* node = (ASTNode*) malloc(sizeof(ASTNode));
        node->type = type;
        node->value = strdup(value);  // Copy the string value
        node->left = left;
        node->right = right;
        return node;
    }

    // Print the AST in a readable format
    void print_ast(ASTNode* node, int indent) {
        if (!node) return;
        for (int i = 0; i < indent; i++) printf("  ");
        printf("%s\n", node->value);
        print_ast(node->left, indent + 1);
        print_ast(node->right, indent + 1);
    }

#line 115 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_STRING_LITERAL = 3,             /* STRING_LITERAL  */
  YYSYMBOL_PLUS = 4,                       /* PLUS  */
  YYSYMBOL_MINUS = 5,                      /* MINUS  */
  YYSYMBOL_MULT = 6,                       /* MULT  */
  YYSYMBOL_DIV = 7,                        /* DIV  */
  YYSYMBOL_COMMENT = 8,                    /* COMMENT  */
  YYSYMBOL_ASSIGNMENT = 9,                 /* ASSIGNMENT  */
  YYSYMBOL_RANGE = 10,                     /* RANGE  */
  YYSYMBOL_COLON = 11,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 12,                 /* SEMICOLON  */
  YYSYMBOL_EQ = 13,                        /* EQ  */
  YYSYMBOL_NEQ = 14,                       /* NEQ  */
  YYSYMBOL_LT = 15,                        /* LT  */
  YYSYMBOL_LTE = 16,                       /* LTE  */
  YYSYMBOL_GT = 17,                        /* GT  */
  YYSYMBOL_GTE = 18,                       /* GTE  */
  YYSYMBOL_IMPLICATION = 19,               /* IMPLICATION  */
  YYSYMBOL_AND = 20,                       /* AND  */
  YYSYMBOL_OR = 21,                        /* OR  */
  YYSYMBOL_XOR = 22,                       /* XOR  */
  YYSYMBOL_NOT = 23,                       /* NOT  */
  YYSYMBOL_VAR = 24,                       /* VAR  */
  YYSYMBOL_IS = 25,                        /* IS  */
  YYSYMBOL_THEN = 26,                      /* THEN  */
  YYSYMBOL_EMPTY = 27,                     /* EMPTY  */
  YYSYMBOL_END = 28,                       /* END  */
  YYSYMBOL_FUNCTION = 29,                  /* FUNCTION  */
  YYSYMBOL_IN = 30,                        /* IN  */
  YYSYMBOL_LOOP = 31,                      /* LOOP  */
  YYSYMBOL_FOR = 32,                       /* FOR  */
  YYSYMBOL_WHILE = 33,                     /* WHILE  */
  YYSYMBOL_IF = 34,                        /* IF  */
  YYSYMBOL_ELSE = 35,                      /* ELSE  */
  YYSYMBOL_TRUE = 36,                      /* TRUE  */
  YYSYMBOL_FALSE = 37,                     /* FALSE  */
  YYSYMBOL_RETURN = 38,                    /* RETURN  */
  YYSYMBOL_INT = 39,                       /* INT  */
  YYSYMBOL_REAL = 40,                      /* REAL  */
  YYSYMBOL_BOOL = 41,                      /* BOOL  */
  YYSYMBOL_STRING = 42,                    /* STRING  */
  YYSYMBOL_INT_LITERAL = 43,               /* INT_LITERAL  */
  YYSYMBOL_REAL_LITERAL = 44,              /* REAL_LITERAL  */
  YYSYMBOL_IDENTIFIER = 45,                /* IDENTIFIER  */
  YYSYMBOL_LEFT_BR = 46,                   /* LEFT_BR  */
  YYSYMBOL_RIGHT_BR = 47,                  /* RIGHT_BR  */
  YYSYMBOL_DOT = 48,                       /* DOT  */
  YYSYMBOL_LEFT_SQ_BR = 49,                /* LEFT_SQ_BR  */
  YYSYMBOL_RIGHT_SQ_BR = 50,               /* RIGHT_SQ_BR  */
  YYSYMBOL_COMMA = 51,                     /* COMMA  */
  YYSYMBOL_QUOTE = 52,                     /* QUOTE  */
  YYSYMBOL_INVALID_CHARACTER = 53,         /* INVALID_CHARACTER  */
  YYSYMBOL_PRINT = 54,                     /* PRINT  */
  YYSYMBOL_RIGHT_CURL_BR = 55,             /* RIGHT_CURL_BR  */
  YYSYMBOL_LEFT_CURL_BR = 56,              /* LEFT_CURL_BR  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_Program = 58,                   /* Program  */
  YYSYMBOL_DeclarationsAndStatements = 59, /* DeclarationsAndStatements  */
  YYSYMBOL_Declarations = 60,              /* Declarations  */
  YYSYMBOL_Declaration = 61,               /* Declaration  */
  YYSYMBOL_OptSemicolon = 62,              /* OptSemicolon  */
  YYSYMBOL_OptAssignment = 63,             /* OptAssignment  */
  YYSYMBOL_Expression = 64,                /* Expression  */
  YYSYMBOL_LogicalOp = 65,                 /* LogicalOp  */
  YYSYMBOL_Relation = 66,                  /* Relation  */
  YYSYMBOL_RelOp = 67,                     /* RelOp  */
  YYSYMBOL_Factor = 68,                    /* Factor  */
  YYSYMBOL_AddOp = 69,                     /* AddOp  */
  YYSYMBOL_Term = 70,                      /* Term  */
  YYSYMBOL_MulOp = 71,                     /* MulOp  */
  YYSYMBOL_Unary = 72,                     /* Unary  */
  YYSYMBOL_OptUnary = 73,                  /* OptUnary  */
  YYSYMBOL_OptTypeIndicator = 74,          /* OptTypeIndicator  */
  YYSYMBOL_Primary = 75,                   /* Primary  */
  YYSYMBOL_Statement = 76,                 /* Statement  */
  YYSYMBOL_Assignment = 77,                /* Assignment  */
  YYSYMBOL_TypeIndicator = 78,             /* TypeIndicator  */
  YYSYMBOL_Literal = 79,                   /* Literal  */
  YYSYMBOL_Statements = 80                 /* Statements  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   96

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  82

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   311


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      55,    56
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    83,    83,    89,    92,    95,    98,   105,   106,   109,
     118,   119,   122,   126,   132,   135,   141,   144,   147,   152,
     155,   161,   164,   167,   170,   173,   176,   182,   186,   193,
     197,   204,   205,   208,   209,   212,   220,   223,   228,   232,
     236,   240,   246,   250,   254,   258,   262,   266,   292,   299,
     340,   343,   346,   349,   352,   355,   358,   361,   364,   371,
     377,   383,   387,   391,   427,   430
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "STRING_LITERAL",
  "PLUS", "MINUS", "MULT", "DIV", "COMMENT", "ASSIGNMENT", "RANGE",
  "COLON", "SEMICOLON", "EQ", "NEQ", "LT", "LTE", "GT", "GTE",
  "IMPLICATION", "AND", "OR", "XOR", "NOT", "VAR", "IS", "THEN", "EMPTY",
  "END", "FUNCTION", "IN", "LOOP", "FOR", "WHILE", "IF", "ELSE", "TRUE",
  "FALSE", "RETURN", "INT", "REAL", "BOOL", "STRING", "INT_LITERAL",
  "REAL_LITERAL", "IDENTIFIER", "LEFT_BR", "RIGHT_BR", "DOT", "LEFT_SQ_BR",
  "RIGHT_SQ_BR", "COMMA", "QUOTE", "INVALID_CHARACTER", "PRINT",
  "RIGHT_CURL_BR", "LEFT_CURL_BR", "$accept", "Program",
  "DeclarationsAndStatements", "Declarations", "Declaration",
  "OptSemicolon", "OptAssignment", "Expression", "LogicalOp", "Relation",
  "RelOp", "Factor", "AddOp", "Term", "MulOp", "Unary", "OptUnary",
  "OptTypeIndicator", "Primary", "Statement", "Assignment",
  "TypeIndicator", "Literal", "Statements", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-44)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      22,   -44,   -43,   -44,   -44,   -44,    26,   -44,    22,   -44,
      20,   -44,   -44,    22,    27,   -44,   -44,    24,    50,    11,
     -44,    50,    37,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,    50,    -3,    63,    10,    16,   -44,    24,   -44,    -3,
     -44,   -44,   -13,   -44,   -44,   -44,    50,   -44,   -44,   -44,
     -44,   -44,   -44,    50,   -44,   -44,    50,   -44,   -44,    50,
      14,   -44,    63,    10,    16,   -44,     1,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,    28,     6,    -9,   -44,   -44,   -44,
      50,    -3
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    47,     0,    45,    46,    44,     0,     2,     3,     7,
       0,    64,    48,     4,    13,     1,     8,     5,    41,     6,
      65,    41,    11,    63,    38,    39,    40,    61,    62,    59,
      60,    41,    49,    14,    19,    27,    31,     0,    36,    12,
      10,     9,     0,    16,    17,    18,    41,    25,    26,    21,
      22,    23,    24,    41,    29,    30,    41,    33,    34,    41,
      43,    37,    15,    20,    28,    32,    41,    35,    54,    57,
      50,    51,    52,    53,    41,     0,     0,    42,    56,    55,
      41,    58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -44,   -44,   -44,    39,     2,   -44,   -44,   -18,   -44,    17,
     -44,     4,   -44,    12,   -44,     7,   -44,   -44,    33,     3,
     -44,   -44,   -44,    74
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     6,     7,     8,     9,    41,    22,    42,    46,    33,
      53,    34,    56,    35,    59,    36,    37,    67,    10,    11,
      12,    77,    38,    13
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      32,    80,    14,    39,    23,    24,    25,    43,    44,    45,
      16,    43,    44,    45,    54,    55,    20,    43,    44,    45,
      20,    16,    57,    58,    26,     1,    15,     1,    68,    18,
      69,    23,    24,    25,    61,     2,    21,    27,    28,    66,
      70,    71,    72,    73,    29,    30,     2,    74,    76,    40,
      75,    26,    19,    23,    24,    25,    79,    63,     3,     4,
       3,     4,    81,    62,    27,    28,    65,     5,    64,     5,
      60,    29,    30,    26,    31,    78,    47,    48,    49,    50,
      51,    52,    17,     0,     0,     0,    27,    28,     0,     0,
       0,     0,     0,    29,    30,     0,    31
};

static const yytype_int8 yycheck[] =
{
      18,    10,    45,    21,     3,     4,     5,    20,    21,    22,
       8,    20,    21,    22,     4,     5,    13,    20,    21,    22,
      17,    19,     6,     7,    23,     3,     0,     3,    27,     9,
      29,     3,     4,     5,    47,    24,     9,    36,    37,    25,
      39,    40,    41,    42,    43,    44,    24,    46,    66,    12,
      49,    23,    13,     3,     4,     5,    50,    53,    36,    37,
      36,    37,    80,    46,    36,    37,    59,    45,    56,    45,
      37,    43,    44,    23,    46,    47,    13,    14,    15,    16,
      17,    18,     8,    -1,    -1,    -1,    36,    37,    -1,    -1,
      -1,    -1,    -1,    43,    44,    -1,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    24,    36,    37,    45,    58,    59,    60,    61,
      75,    76,    77,    80,    45,     0,    61,    80,     9,    60,
      76,     9,    63,     3,     4,     5,    23,    36,    37,    43,
      44,    46,    64,    66,    68,    70,    72,    73,    79,    64,
      12,    62,    64,    20,    21,    22,    65,    13,    14,    15,
      16,    17,    18,    67,     4,     5,    69,     6,     7,    71,
      75,    47,    66,    68,    70,    72,    25,    74,    27,    29,
      39,    40,    41,    42,    46,    49,    64,    78,    47,    50,
      10,    64
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    59,    59,    59,    59,    60,    60,    61,
      62,    62,    63,    63,    64,    64,    65,    65,    65,    66,
      66,    67,    67,    67,    67,    67,    67,    68,    68,    69,
      69,    70,    70,    71,    71,    72,    72,    72,    73,    73,
      73,    73,    74,    74,    75,    75,    75,    75,    76,    77,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    79,
      79,    79,    79,    79,    80,    80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     1,     2,     4,
       1,     0,     2,     0,     1,     3,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     3,     1,     3,     1,     1,
       1,     0,     2,     0,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     2,     2,     1,     3,     1,
       1,     1,     1,     1,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: DeclarationsAndStatements  */
#line 83 "parser.y"
                                    {
    print_ast((yyvsp[0].node), 0);  // Print the AST after parsing
    (yyval.node) = (yyvsp[0].node);           // Store the root AST node
}
#line 1253 "parser.tab.c"
    break;

  case 3: /* DeclarationsAndStatements: Declarations  */
#line 89 "parser.y"
                                         {
    (yyval.node) = create_node(NODE_DECLARATION, "DeclarationsAndStatements", (yyvsp[0].node), NULL);
}
#line 1261 "parser.tab.c"
    break;

  case 4: /* DeclarationsAndStatements: Statements  */
#line 92 "parser.y"
             {
    (yyval.node) = create_node(NODE_STATEMENT, "DeclarationsAndStatements", (yyvsp[0].node), NULL);
}
#line 1269 "parser.tab.c"
    break;

  case 5: /* DeclarationsAndStatements: Declarations Statements  */
#line 95 "parser.y"
                          {
    (yyval.node) = create_node(NODE_DECLARATION, "DeclarationsAndStatements", (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1277 "parser.tab.c"
    break;

  case 6: /* DeclarationsAndStatements: Statements Declarations  */
#line 98 "parser.y"
                          {
    (yyval.node) = create_node(NODE_STATEMENT, "DeclarationsAndStatements", (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1285 "parser.tab.c"
    break;

  case 7: /* Declarations: Declaration  */
#line 105 "parser.y"
                           { (yyval.node) = create_node(NODE_DECLARATION, "Declaration", (yyvsp[0].node), NULL); }
#line 1291 "parser.tab.c"
    break;

  case 8: /* Declarations: Declarations Declaration  */
#line 106 "parser.y"
                                        { (yyval.node) = create_node(NODE_DECLARATION, "Declarations", (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1297 "parser.tab.c"
    break;

  case 9: /* Declaration: VAR IDENTIFIER OptAssignment OptSemicolon  */
#line 109 "parser.y"
                                                        {
    // Create an AST node for the variable declaration
    (yyval.node) = create_node(NODE_DECLARATION, "VarDeclaration", create_node(NODE_EXPRESSION, (yyvsp[-2].ident), (yyvsp[-1].node), NULL), NULL);
}
#line 1306 "parser.tab.c"
    break;

  case 12: /* OptAssignment: ASSIGNMENT Expression  */
#line 122 "parser.y"
                                      {
    // Create an AST node for the optional assignment
    (yyval.node) = create_node(NODE_EXPRESSION, "OptAssignment", NULL, (yyvsp[0].node));  // Right side expression
}
#line 1315 "parser.tab.c"
    break;

  case 13: /* OptAssignment: %empty  */
#line 126 "parser.y"
              {
    (yyval.node) = NULL;  // Representing the absence of an assignment
}
#line 1323 "parser.tab.c"
    break;

  case 14: /* Expression: Relation  */
#line 132 "parser.y"
                      {
    (yyval.node) = (yyvsp[0].node);
}
#line 1331 "parser.tab.c"
    break;

  case 15: /* Expression: Expression LogicalOp Relation  */
#line 135 "parser.y"
                                {
    (yyval.node) = create_node(NODE_EXPRESSION, (yyvsp[-1].node)->value, (yyvsp[-2].node), (yyvsp[0].node));  // Use $2->value to get the operator
}
#line 1339 "parser.tab.c"
    break;

  case 16: /* LogicalOp: AND  */
#line 141 "parser.y"
                {
    (yyval.node) = create_node(NODE_EXPRESSION, "AND", NULL, NULL);
}
#line 1347 "parser.tab.c"
    break;

  case 17: /* LogicalOp: OR  */
#line 144 "parser.y"
     {
    (yyval.node) = create_node(NODE_EXPRESSION, "OR", NULL, NULL);
}
#line 1355 "parser.tab.c"
    break;

  case 18: /* LogicalOp: XOR  */
#line 147 "parser.y"
      {
    (yyval.node) = create_node(NODE_EXPRESSION, "XOR", NULL, NULL);
}
#line 1363 "parser.tab.c"
    break;

  case 19: /* Relation: Factor  */
#line 152 "parser.y"
                  {
    (yyval.node) = (yyvsp[0].node);  // Set the relation to the factor node
}
#line 1371 "parser.tab.c"
    break;

  case 20: /* Relation: Relation RelOp Factor  */
#line 155 "parser.y"
                        {
    // Create a new AST node for the relational operation
    (yyval.node) = create_node(NODE_EXPRESSION, (yyvsp[-1].node)->value, (yyvsp[-2].node), (yyvsp[0].node));  // $2 contains the relational operator
}
#line 1380 "parser.tab.c"
    break;

  case 21: /* RelOp: LT  */
#line 161 "parser.y"
           {
    (yyval.node) = create_node(NODE_EXPRESSION, "LT", NULL, NULL);  // Less Than
}
#line 1388 "parser.tab.c"
    break;

  case 22: /* RelOp: LTE  */
#line 164 "parser.y"
      {
    (yyval.node) = create_node(NODE_EXPRESSION, "LTE", NULL, NULL);  // Less Than or Equal
}
#line 1396 "parser.tab.c"
    break;

  case 23: /* RelOp: GT  */
#line 167 "parser.y"
     {
    (yyval.node) = create_node(NODE_EXPRESSION, "GT", NULL, NULL);  // Greater Than
}
#line 1404 "parser.tab.c"
    break;

  case 24: /* RelOp: GTE  */
#line 170 "parser.y"
      {
    (yyval.node) = create_node(NODE_EXPRESSION, "GTE", NULL, NULL);  // Greater Than or Equal
}
#line 1412 "parser.tab.c"
    break;

  case 25: /* RelOp: EQ  */
#line 173 "parser.y"
     {
    (yyval.node) = create_node(NODE_EXPRESSION, "EQ", NULL, NULL);  // Equal
}
#line 1420 "parser.tab.c"
    break;

  case 26: /* RelOp: NEQ  */
#line 176 "parser.y"
      {
    (yyval.node) = create_node(NODE_EXPRESSION, "NEQ", NULL, NULL);  // Not Equal
}
#line 1428 "parser.tab.c"
    break;

  case 27: /* Factor: Term  */
#line 182 "parser.y"
              {
    // When a factor is just a term, return the term directly
    (yyval.node) = (yyvsp[0].node); 
}
#line 1437 "parser.tab.c"
    break;

  case 28: /* Factor: Factor AddOp Term  */
#line 186 "parser.y"
                    {
    // When a factor consists of another factor, an operator, and a term,
    // create an AST node for the operation
    (yyval.node) = create_node(NODE_EXPRESSION, (yyvsp[-1].node)->value, (yyvsp[-2].node), (yyvsp[0].node)); // Use the operator's value and the two terms
}
#line 1447 "parser.tab.c"
    break;

  case 29: /* AddOp: PLUS  */
#line 193 "parser.y"
             {
    // Create an AST node for the addition operator
    (yyval.node) = create_node(NODE_EXPRESSION, "PLUS", NULL, NULL);
}
#line 1456 "parser.tab.c"
    break;

  case 30: /* AddOp: MINUS  */
#line 197 "parser.y"
        {
    // Create an AST node for the subtraction operator
    (yyval.node) = create_node(NODE_EXPRESSION, "MINUS", NULL, NULL);
}
#line 1465 "parser.tab.c"
    break;

  case 35: /* Unary: OptUnary Primary OptTypeIndicator  */
#line 212 "parser.y"
                                          {
    // Create a unary AST node based on the optional unary operator
    if ((yyvsp[-2].node)) {
        (yyval.node) = create_node(NODE_EXPRESSION, (yyvsp[-2].node)->value, (yyvsp[-1].node), NULL); // Operator with primary
    } else {
        (yyval.node) = (yyvsp[-1].node); // No unary operator, just return the primary
    }
}
#line 1478 "parser.tab.c"
    break;

  case 36: /* Unary: Literal  */
#line 220 "parser.y"
          {
    (yyval.node) = (yyvsp[0].node); // Return the literal as an AST node
}
#line 1486 "parser.tab.c"
    break;

  case 37: /* Unary: LEFT_BR Expression RIGHT_BR  */
#line 223 "parser.y"
                              {
    (yyval.node) = (yyvsp[-1].node); // Return the expression inside the parentheses
}
#line 1494 "parser.tab.c"
    break;

  case 38: /* OptUnary: PLUS  */
#line 228 "parser.y"
                {
    // Create an AST node for the unary plus operator
    (yyval.node) = create_node(NODE_EXPRESSION, "PLUS", NULL, NULL);
}
#line 1503 "parser.tab.c"
    break;

  case 39: /* OptUnary: MINUS  */
#line 232 "parser.y"
        {
    // Create an AST node for the unary minus operator
    (yyval.node) = create_node(NODE_EXPRESSION, "MINUS", NULL, NULL);
}
#line 1512 "parser.tab.c"
    break;

  case 40: /* OptUnary: NOT  */
#line 236 "parser.y"
      {
    // Create an AST node for the NOT operator
    (yyval.node) = create_node(NODE_EXPRESSION, "NOT", NULL, NULL);
}
#line 1521 "parser.tab.c"
    break;

  case 41: /* OptUnary: %empty  */
#line 240 "parser.y"
              {
    (yyval.node) = NULL; // No unary operator present
}
#line 1529 "parser.tab.c"
    break;

  case 42: /* OptTypeIndicator: IS TypeIndicator  */
#line 246 "parser.y"
                                    {
    // Create an AST node indicating a type indicator
    (yyval.node) = create_node(NODE_EXPRESSION, "IS", (yyvsp[0].node), NULL);  // $2 contains the type indicator AST node
}
#line 1538 "parser.tab.c"
    break;

  case 43: /* OptTypeIndicator: %empty  */
#line 250 "parser.y"
              {
    (yyval.node) = NULL;  // Return NULL if no type indicator is present
}
#line 1546 "parser.tab.c"
    break;

  case 44: /* Primary: IDENTIFIER  */
#line 254 "parser.y"
                     {
    // Create an AST node for the identifier with its optional tail
    (yyval.node) = create_node(NODE_EXPRESSION, (yyvsp[0].ident), NULL, NULL);  // $1 is the identifier, $2 is the tail
}
#line 1555 "parser.tab.c"
    break;

  case 45: /* Primary: TRUE  */
#line 258 "parser.y"
       {
    // Create an AST node for the boolean literal TRUE
    (yyval.node) = create_node(NODE_EXPRESSION, "TRUE", NULL, NULL);
}
#line 1564 "parser.tab.c"
    break;

  case 46: /* Primary: FALSE  */
#line 262 "parser.y"
        {
    // Create an AST node for the boolean literal FALSE
    (yyval.node) = create_node(NODE_EXPRESSION, "FALSE", NULL, NULL);
}
#line 1573 "parser.tab.c"
    break;

  case 47: /* Primary: STRING_LITERAL  */
#line 266 "parser.y"
                 {
    // Create an AST node for the string literal
    (yyval.node) = create_node(NODE_EXPRESSION, (yyvsp[0].node), NULL, NULL);
}
#line 1582 "parser.tab.c"
    break;

  case 48: /* Statement: Assignment  */
#line 292 "parser.y"
                       {
    (yyval.node) = (yyvsp[0].node);  // The assignment node
}
#line 1590 "parser.tab.c"
    break;

  case 49: /* Assignment: Primary ASSIGNMENT Expression  */
#line 299 "parser.y"
                                           {
    (yyval.node) = create_node(NODE_STATEMENT, "Assignment", create_node(NODE_EXPRESSION, (yyvsp[-2].node)->value, NULL, (yyvsp[0].node)), NULL); // Assign the value to the identifier
}
#line 1598 "parser.tab.c"
    break;

  case 50: /* TypeIndicator: INT  */
#line 340 "parser.y"
                    {
    (yyval.node) = create_node(NODE_EXPRESSION, "INT", NULL, NULL);
}
#line 1606 "parser.tab.c"
    break;

  case 51: /* TypeIndicator: REAL  */
#line 343 "parser.y"
       {
    (yyval.node) = create_node(NODE_EXPRESSION, "REAL", NULL, NULL);
}
#line 1614 "parser.tab.c"
    break;

  case 52: /* TypeIndicator: BOOL  */
#line 346 "parser.y"
       {
    (yyval.node) = create_node(NODE_EXPRESSION, "BOOL", NULL, NULL);
}
#line 1622 "parser.tab.c"
    break;

  case 53: /* TypeIndicator: STRING  */
#line 349 "parser.y"
         {
    (yyval.node) = create_node(NODE_EXPRESSION, "STRING", NULL, NULL);
}
#line 1630 "parser.tab.c"
    break;

  case 54: /* TypeIndicator: EMPTY  */
#line 352 "parser.y"
        {
    (yyval.node) = create_node(NODE_EXPRESSION, "EMPTY", NULL, NULL);
}
#line 1638 "parser.tab.c"
    break;

  case 55: /* TypeIndicator: LEFT_SQ_BR RIGHT_SQ_BR  */
#line 355 "parser.y"
                         {
    (yyval.node) = create_node(NODE_EXPRESSION, "ArrayType", NULL, NULL); // Represents an empty array
}
#line 1646 "parser.tab.c"
    break;

  case 56: /* TypeIndicator: LEFT_BR RIGHT_BR  */
#line 358 "parser.y"
                   {
    (yyval.node) = create_node(NODE_EXPRESSION, "FunctionType", NULL, NULL); // Represents an empty function
}
#line 1654 "parser.tab.c"
    break;

  case 57: /* TypeIndicator: FUNCTION  */
#line 361 "parser.y"
           {
    (yyval.node) = create_node(NODE_EXPRESSION, "FUNCTION", NULL, NULL);
}
#line 1662 "parser.tab.c"
    break;

  case 58: /* TypeIndicator: Expression RANGE Expression  */
#line 364 "parser.y"
                              {
    (yyval.node) = create_node(NODE_EXPRESSION, "Range", (yyvsp[-2].node), (yyvsp[0].node)); // Represents a range type
}
#line 1670 "parser.tab.c"
    break;

  case 59: /* Literal: INT_LITERAL  */
#line 371 "parser.y"
                      {
    // Create an AST node for integer literals with the actual value
    char buffer[20];  // Buffer to hold the string representation of the integer
    snprintf(buffer, sizeof(buffer), "%d", (yyvsp[0].node));  // Convert integer to string
    (yyval.node) = create_node(NODE_EXPRESSION, strdup(buffer), NULL, NULL);
}
#line 1681 "parser.tab.c"
    break;

  case 60: /* Literal: REAL_LITERAL  */
#line 377 "parser.y"
               {
    // Create an AST node for real literals with the actual value
    char buffer[20];  // Buffer to hold the string representation of the real number
    snprintf(buffer, sizeof(buffer), "%.2f", (yyvsp[0].node));  // Convert float to string with 2 decimal precision
    (yyval.node) = create_node(NODE_EXPRESSION, strdup(buffer), NULL, NULL);
}
#line 1692 "parser.tab.c"
    break;

  case 61: /* Literal: TRUE  */
#line 383 "parser.y"
       {
    // Create an AST node for the boolean literal TRUE
    (yyval.node) = create_node(NODE_EXPRESSION, "TRUE", NULL, NULL);
}
#line 1701 "parser.tab.c"
    break;

  case 62: /* Literal: FALSE  */
#line 387 "parser.y"
        {
    // Create an AST node for the boolean literal FALSE
    (yyval.node) = create_node(NODE_EXPRESSION, "FALSE", NULL, NULL);
}
#line 1710 "parser.tab.c"
    break;

  case 63: /* Literal: STRING_LITERAL  */
#line 391 "parser.y"
                 {
    // Create an AST node for string literals with the actual value
    (yyval.node) = create_node(NODE_EXPRESSION, (yyvsp[0].node), NULL, NULL);  // Use the string value directly
}
#line 1719 "parser.tab.c"
    break;

  case 64: /* Statements: Statement  */
#line 427 "parser.y"
                       {
    (yyval.node) = create_node(NODE_STATEMENT, "Statement", (yyvsp[0].node), NULL);
}
#line 1727 "parser.tab.c"
    break;

  case 65: /* Statements: Statements Statement  */
#line 430 "parser.y"
                       {
    (yyval.node) = create_node(NODE_STATEMENT, "Statements", (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1735 "parser.tab.c"
    break;


#line 1739 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 434 "parser.y"


void yyerror(const char *s)
{
  fprintf(stderr, "Syntax error at line %d: %s\n", yylineno, s);
  exit(1);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror(argv[1]);
        return 1;
    }

    if (strcmp(argv[2], "lexer") == 0) {
      int token;
      while ((token = yylex())) {
          // printf("Token: %d\n", token);
      }
    } else {
      int flag = yyparse();
      fprintf(stderr, "Flag %d\n", flag);
    }
    fclose(yyin);

    return 0;
}
