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
    #include <string>
    #include <cstring>
    #include <vector>
    #include <iostream>

    #include "ast/ast.hpp"

    Node* root = nullptr;

    #define YYDEBUG 1
    extern FILE *yyin;
    extern int yylineno;
    extern int yylex();
    void yyerror(const char *s);


#line 91 "parser.tab.c"

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
  YYSYMBOL_IDENT = 3,                      /* IDENT  */
  YYSYMBOL_INTEGER = 4,                    /* INTEGER  */
  YYSYMBOL_REAL = 5,                       /* REAL  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_TRUE = 7,                       /* TRUE  */
  YYSYMBOL_FALSE = 8,                      /* FALSE  */
  YYSYMBOL_VAR = 9,                        /* VAR  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_THEN = 11,                      /* THEN  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_FOR = 14,                       /* FOR  */
  YYSYMBOL_IN = 15,                        /* IN  */
  YYSYMBOL_RETURN = 16,                    /* RETURN  */
  YYSYMBOL_PRINT = 17,                     /* PRINT  */
  YYSYMBOL_AND = 18,                       /* AND  */
  YYSYMBOL_OR = 19,                        /* OR  */
  YYSYMBOL_XOR = 20,                       /* XOR  */
  YYSYMBOL_NOT = 21,                       /* NOT  */
  YYSYMBOL_IS = 22,                        /* IS  */
  YYSYMBOL_ASSIGN = 23,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 24,                      /* PLUS  */
  YYSYMBOL_MINUS = 25,                     /* MINUS  */
  YYSYMBOL_MUL = 26,                       /* MUL  */
  YYSYMBOL_DIV = 27,                       /* DIV  */
  YYSYMBOL_LT = 28,                        /* LT  */
  YYSYMBOL_LE = 29,                        /* LE  */
  YYSYMBOL_GT = 30,                        /* GT  */
  YYSYMBOL_GE = 31,                        /* GE  */
  YYSYMBOL_EQ = 32,                        /* EQ  */
  YYSYMBOL_NEQ = 33,                       /* NEQ  */
  YYSYMBOL_LPAREN = 34,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 35,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 36,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 37,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 38,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 39,                  /* RBRACKET  */
  YYSYMBOL_COMMA = 40,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 41,                 /* SEMICOLON  */
  YYSYMBOL_READINT = 42,                   /* READINT  */
  YYSYMBOL_READREAL = 43,                  /* READREAL  */
  YYSYMBOL_READSTRING = 44,                /* READSTRING  */
  YYSYMBOL_LOOP = 45,                      /* LOOP  */
  YYSYMBOL_DOT = 46,                       /* DOT  */
  YYSYMBOL_END = 47,                       /* END  */
  YYSYMBOL_INT_TYPE = 48,                  /* INT_TYPE  */
  YYSYMBOL_REAL_TYPE = 49,                 /* REAL_TYPE  */
  YYSYMBOL_BOOL_TYPE = 50,                 /* BOOL_TYPE  */
  YYSYMBOL_STRING_TYPE = 51,               /* STRING_TYPE  */
  YYSYMBOL_EMPTY = 52,                     /* EMPTY  */
  YYSYMBOL_VECTOR = 53,                    /* VECTOR  */
  YYSYMBOL_TUPLE = 54,                     /* TUPLE  */
  YYSYMBOL_FUNC = 55,                      /* FUNC  */
  YYSYMBOL_INVALID_CHARACTER = 56,         /* INVALID_CHARACTER  */
  YYSYMBOL_RANGE = 57,                     /* RANGE  */
  YYSYMBOL_IMPLICATION = 58,               /* IMPLICATION  */
  YYSYMBOL_MOD = 59,                       /* MOD  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_Program = 61,                   /* Program  */
  YYSYMBOL_Statement = 62,                 /* Statement  */
  YYSYMBOL_Declaration = 63,               /* Declaration  */
  YYSYMBOL_FunctionDeclaration = 64,       /* FunctionDeclaration  */
  YYSYMBOL_VariableDefinition = 65,        /* VariableDefinition  */
  YYSYMBOL_Assignment = 66,                /* Assignment  */
  YYSYMBOL_If = 67,                        /* If  */
  YYSYMBOL_Loop = 68,                      /* Loop  */
  YYSYMBOL_Return = 69,                    /* Return  */
  YYSYMBOL_Print = 70,                     /* Print  */
  YYSYMBOL_Body = 71,                      /* Body  */
  YYSYMBOL_Expression = 72,                /* Expression  */
  YYSYMBOL_Relation = 73,                  /* Relation  */
  YYSYMBOL_Factor = 74,                    /* Factor  */
  YYSYMBOL_Term = 75,                      /* Term  */
  YYSYMBOL_Unary = 76,                     /* Unary  */
  YYSYMBOL_FunctionCall = 77,              /* FunctionCall  */
  YYSYMBOL_Primary = 78,                   /* Primary  */
  YYSYMBOL_Literal = 79,                   /* Literal  */
  YYSYMBOL_Tuple = 80,                     /* Tuple  */
  YYSYMBOL_TupleElement = 81,              /* TupleElement  */
  YYSYMBOL_TupleElementList = 82,          /* TupleElementList  */
  YYSYMBOL_Array = 83,                     /* Array  */
  YYSYMBOL_ExpressionList = 84,            /* ExpressionList  */
  YYSYMBOL_Reference = 85,                 /* Reference  */
  YYSYMBOL_TypeIndicator = 86,             /* TypeIndicator  */
  YYSYMBOL_OptIdentifierList = 87,         /* OptIdentifierList  */
  YYSYMBOL_FunBody = 88                    /* FunBody  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   251

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   314


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
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    57,    57,    62,    69,    70,    71,    72,    73,    74,
      75,    79,    85,    91,    94,    97,   103,   109,   112,   118,
     121,   127,   130,   136,   142,   146,   152,   153,   154,   155,
     159,   160,   161,   162,   163,   164,   165,   169,   170,   171,
     175,   176,   177,   178,   182,   183,   184,   185,   186,   187,
     191,   196,   197,   198,   202,   203,   204,   205,   206,   207,
     208,   209,   213,   217,   218,   222,   223,   224,   227,   233,
     237,   242,   248,   249,   250,   251,   255,   256,   257,   258,
     259,   260,   261,   262,   266,   271,   275,   281,   284,   289
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENT", "INTEGER",
  "REAL", "STRING", "TRUE", "FALSE", "VAR", "IF", "THEN", "ELSE", "WHILE",
  "FOR", "IN", "RETURN", "PRINT", "AND", "OR", "XOR", "NOT", "IS",
  "ASSIGN", "PLUS", "MINUS", "MUL", "DIV", "LT", "LE", "GT", "GE", "EQ",
  "NEQ", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET",
  "COMMA", "SEMICOLON", "READINT", "READREAL", "READSTRING", "LOOP", "DOT",
  "END", "INT_TYPE", "REAL_TYPE", "BOOL_TYPE", "STRING_TYPE", "EMPTY",
  "VECTOR", "TUPLE", "FUNC", "INVALID_CHARACTER", "RANGE", "IMPLICATION",
  "MOD", "$accept", "Program", "Statement", "Declaration",
  "FunctionDeclaration", "VariableDefinition", "Assignment", "If", "Loop",
  "Return", "Print", "Body", "Expression", "Relation", "Factor", "Term",
  "Unary", "FunctionCall", "Primary", "Literal", "Tuple", "TupleElement",
  "TupleElementList", "Array", "ExpressionList", "Reference",
  "TypeIndicator", "OptIdentifierList", "FunBody", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-75)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -75,   213,   -75,   -19,    30,    13,    13,    32,    13,    13,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,    33,    13,
      20,   -75,   -75,   -75,   -75,   -75,   -75,    79,    79,    79,
      13,    69,    13,   -75,   122,   212,    87,    -4,   -75,   -75,
     -75,   -75,   -75,   -75,   -14,    90,    31,   109,   109,    17,
      13,    66,    85,    10,     6,   -19,   -75,   -75,   -75,   180,
       2,   109,    38,    58,   146,   -75,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
     159,   -75,    13,    13,   109,    67,   -75,   -75,   -75,    80,
     -75,   109,   -75,    13,    69,   -75,   -75,    50,   212,   212,
     212,    87,    87,    87,    87,    87,    87,    -4,    -4,   -75,
     -75,   -75,    93,    77,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,   147,    82,   109,   -75,   120,   109,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,    13,   -75,    64,   156,   106,   -17,
     131,   -75,   -75,   -75,   222,   -75,   -75,   165,   174,    96,
     -75,   -75,   -75
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     1,    72,     0,     0,     0,     0,    21,    71,
       2,     4,     5,     6,     7,     8,     9,    10,     0,    71,
      13,    11,    54,    55,    56,    57,    58,     0,     0,     0,
       0,    67,    71,    61,     0,    26,    30,    37,    40,    53,
      46,    51,    59,    60,    44,     0,     0,    22,    70,    23,
       0,     0,     0,     0,     0,     0,    49,    47,    48,     0,
      72,    64,    65,     0,     0,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,     0,     0,    16,     0,    74,    75,    50,     0,
      15,    14,    52,     0,    67,    62,    68,     0,    27,    28,
      29,    31,    32,    33,    34,    35,    36,    38,    39,    41,
      42,    43,     0,     0,    76,    77,    78,    79,    80,    83,
      45,     0,     0,    69,    73,    86,    63,    66,    25,    17,
      24,    82,    81,    19,     0,    84,     0,     0,     0,     0,
       0,    18,    25,    25,     0,    12,    85,     0,     0,    88,
      20,    87,    89
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -75,   -75,     0,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,   -74,    -2,    86,   177,    43,   127,    -1,   190,   -75,
     -75,   -75,    61,   -75,     7,     1,   -75,   -75,   -75
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,   130,    11,    90,    21,    12,    13,    14,    15,
      16,    97,    48,    35,    36,    37,    38,    39,    40,    41,
      42,    62,    63,    43,    49,    44,   120,   136,   145
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      17,    10,    18,    34,    45,   143,    47,   121,    80,     3,
      22,    23,    24,    25,    26,    19,     3,    22,    23,    24,
      25,    26,    77,    78,    51,    93,    53,    27,    59,    61,
      28,    29,    52,    20,    27,    46,    19,    28,    29,    64,
      30,   144,    31,    54,    32,    88,    82,    30,    84,    31,
      83,    32,    91,     3,   137,    79,    50,    83,    33,     4,
       5,    89,   128,     6,     7,    33,     8,     9,   147,   148,
      85,    51,    60,    22,    23,    24,    25,    26,    94,    52,
     122,   123,    55,    22,    23,    24,    25,    26,    86,    87,
      27,   126,    61,    28,    29,    95,    17,   129,    18,   139,
      66,    67,    68,    30,   140,    31,   124,    32,    66,    67,
      68,    75,    76,    30,   125,    31,   132,    32,   107,   108,
      17,    33,    18,   135,    66,    67,    68,    66,    67,    68,
     131,    33,   138,    65,   146,    81,    17,   152,    18,   134,
      66,    67,    68,    17,   149,    18,    17,    17,    18,    18,
       3,   142,    98,    99,   100,   127,     4,     5,     0,     3,
       6,     7,     0,     8,     9,     4,     5,     0,     3,     6,
       7,     0,     8,     9,     4,     5,     0,     3,     6,     7,
       0,     8,     9,     4,     5,    96,    83,     6,     7,     0,
       8,     9,     0,     0,   133,   112,     0,   113,    66,    67,
      68,     0,     0,   141,   109,   110,   111,   114,   115,   116,
     117,   118,   150,     2,   119,    92,     3,    56,    57,    58,
       0,   151,     4,     5,     0,     3,     6,     7,     0,     8,
       9,     4,     5,     0,     0,     6,     7,     0,     8,     9,
      69,    70,    71,    72,    73,    74,   101,   102,   103,   104,
     105,   106
};

static const yytype_int16 yycheck[] =
{
       1,     1,     1,     5,     6,    22,     8,    81,    22,     3,
       4,     5,     6,     7,     8,    34,     3,     4,     5,     6,
       7,     8,    26,    27,    38,    23,    19,    21,    30,    31,
      24,    25,    46,     3,    21,     3,    34,    24,    25,    32,
      34,    58,    36,    23,    38,    35,    15,    34,    50,    36,
      40,    38,    54,     3,   128,    59,    23,    40,    52,     9,
      10,    55,    12,    13,    14,    52,    16,    17,   142,   143,
       4,    38,     3,     4,     5,     6,     7,     8,    40,    46,
      82,    83,     3,     4,     5,     6,     7,     8,     3,     4,
      21,    93,    94,    24,    25,    37,    97,    47,    97,    35,
      18,    19,    20,    34,    40,    36,    39,    38,    18,    19,
      20,    24,    25,    34,    34,    36,    39,    38,    75,    76,
     121,    52,   121,     3,    18,    19,    20,    18,    19,    20,
      37,    52,   134,    11,     3,    45,   137,    41,   137,    57,
      18,    19,    20,   144,   144,   144,   147,   148,   147,   148,
       3,    45,    66,    67,    68,    94,     9,    10,    -1,     3,
      13,    14,    -1,    16,    17,     9,    10,    -1,     3,    13,
      14,    -1,    16,    17,     9,    10,    -1,     3,    13,    14,
      -1,    16,    17,     9,    10,    39,    40,    13,    14,    -1,
      16,    17,    -1,    -1,    47,    36,    -1,    38,    18,    19,
      20,    -1,    -1,    47,    77,    78,    79,    48,    49,    50,
      51,    52,    47,     0,    55,    35,     3,    27,    28,    29,
      -1,    47,     9,    10,    -1,     3,    13,    14,    -1,    16,
      17,     9,    10,    -1,    -1,    13,    14,    -1,    16,    17,
      28,    29,    30,    31,    32,    33,    69,    70,    71,    72,
      73,    74
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    61,     0,     3,     9,    10,    13,    14,    16,    17,
      62,    63,    66,    67,    68,    69,    70,    77,    85,    34,
       3,    65,     4,     5,     6,     7,     8,    21,    24,    25,
      34,    36,    38,    52,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    83,    85,    72,     3,    72,    72,    84,
      23,    38,    46,    84,    23,     3,    78,    78,    78,    72,
       3,    72,    81,    82,    84,    11,    18,    19,    20,    28,
      29,    30,    31,    32,    33,    24,    25,    26,    27,    59,
      22,    45,    15,    40,    72,     4,     3,     4,    35,    55,
      64,    72,    35,    23,    40,    37,    39,    71,    73,    73,
      73,    74,    74,    74,    74,    74,    74,    75,    75,    76,
      76,    76,    36,    38,    48,    49,    50,    51,    52,    55,
      86,    71,    72,    72,    39,    34,    72,    82,    12,    47,
      62,    37,    39,    47,    57,     3,    87,    71,    72,    35,
      40,    47,    45,    22,    58,    88,     3,    71,    71,    62,
      47,    47,    41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    61,    62,    62,    62,    62,    62,    62,
      62,    63,    64,    65,    65,    65,    66,    67,    67,    68,
      68,    69,    69,    70,    71,    71,    72,    72,    72,    72,
      73,    73,    73,    73,    73,    73,    73,    74,    74,    74,
      75,    75,    75,    75,    76,    76,    76,    76,    76,    76,
      77,    78,    78,    78,    79,    79,    79,    79,    79,    79,
      79,    79,    80,    81,    81,    82,    82,    82,    83,    84,
      84,    84,    85,    85,    85,    85,    86,    86,    86,    86,
      86,    86,    86,    86,    87,    87,    87,    88,    88,    88
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     2,     5,     1,     3,     3,     3,     5,     7,     5,
       9,     1,     2,     2,     2,     0,     1,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     3,     1,     2,     2,     2,
       4,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     1,     3,     0,     3,     3,
       1,     0,     1,     4,     3,     3,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     3,     0,     3,     2,     3
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
  case 2: /* Program: Program Statement  */
#line 57 "parser.y"
                        {
        (yyvsp[-1].node)->Add((yyvsp[0].node)); 
        (yyval.node) = (yyvsp[-1].node);
        root = (yyval.node);
    }
#line 1297 "parser.tab.c"
    break;

  case 3: /* Program: %empty  */
#line 62 "parser.y"
                  {
        (yyval.node) = new ProgramNode(); 
        root = (yyval.node); 
    }
#line 1306 "parser.tab.c"
    break;

  case 4: /* Statement: Declaration  */
#line 69 "parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1312 "parser.tab.c"
    break;

  case 5: /* Statement: Assignment  */
#line 70 "parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1318 "parser.tab.c"
    break;

  case 6: /* Statement: If  */
#line 71 "parser.y"
         { (yyval.node) = (yyvsp[0].node); }
#line 1324 "parser.tab.c"
    break;

  case 7: /* Statement: Loop  */
#line 72 "parser.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 1330 "parser.tab.c"
    break;

  case 8: /* Statement: Return  */
#line 73 "parser.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1336 "parser.tab.c"
    break;

  case 9: /* Statement: Print  */
#line 74 "parser.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 1342 "parser.tab.c"
    break;

  case 10: /* Statement: FunctionCall  */
#line 75 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1348 "parser.tab.c"
    break;

  case 11: /* Declaration: VAR VariableDefinition  */
#line 79 "parser.y"
                             {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1356 "parser.tab.c"
    break;

  case 12: /* FunctionDeclaration: FUNC LPAREN OptIdentifierList RPAREN FunBody  */
#line 85 "parser.y"
                                                   {
        (yyval.node) = new FunctionNode((BlocksNode*)(yyvsp[0].node), (Parameters*)(yyvsp[-2].node));
    }
#line 1364 "parser.tab.c"
    break;

  case 13: /* VariableDefinition: IDENT  */
#line 91 "parser.y"
            {
        (yyval.node) = new Declaration(std::string((yyvsp[0].value))); 
    }
#line 1372 "parser.tab.c"
    break;

  case 14: /* VariableDefinition: IDENT ASSIGN Expression  */
#line 94 "parser.y"
                              { 
        (yyval.node) = new Declaration(std::string((yyvsp[-2].value)), (ExpressionNode*)(yyvsp[0].node));
    }
#line 1380 "parser.tab.c"
    break;

  case 15: /* VariableDefinition: IDENT ASSIGN FunctionDeclaration  */
#line 97 "parser.y"
                                       {
        (yyval.node) = new Declaration(std::string((yyvsp[-2].value)), (FunctionNode*)(yyvsp[0].node));
    }
#line 1388 "parser.tab.c"
    break;

  case 16: /* Assignment: Reference ASSIGN Expression  */
#line 103 "parser.y"
                                  {
        (yyval.node) = new AssignmentNode((LocationValue*)(yyvsp[-2].node), (ExpressionNode*)(yyvsp[0].node));
    }
#line 1396 "parser.tab.c"
    break;

  case 17: /* If: IF Expression THEN Body END  */
#line 109 "parser.y"
                                  {
        (yyval.node) = new IfStatement((ExpressionNode*)(yyvsp[-3].node), (BlocksNode*)(yyvsp[-1].node));
    }
#line 1404 "parser.tab.c"
    break;

  case 18: /* If: IF Expression THEN Body ELSE Body END  */
#line 112 "parser.y"
                                            {
        (yyval.node) = new IfStatement((ExpressionNode*)(yyvsp[-5].node), (BlocksNode*)(yyvsp[-3].node), (BlocksNode*)(yyvsp[-1].node));
    }
#line 1412 "parser.tab.c"
    break;

  case 19: /* Loop: WHILE Expression LOOP Body END  */
#line 118 "parser.y"
                                     {
        (yyval.node) = new WhileStatement((ExpressionNode*)(yyvsp[-3].node), (BlocksNode*)(yyvsp[-1].node));
    }
#line 1420 "parser.tab.c"
    break;

  case 20: /* Loop: FOR IDENT IN Expression RANGE Expression LOOP Body END  */
#line 121 "parser.y"
                                                             {
        (yyval.node) = new ForStatement(std::string((yyvsp[-7].value)), (ExpressionNode*)(yyvsp[-5].node), (ExpressionNode*)(yyvsp[-3].node), (BlocksNode*)(yyvsp[-1].node));
    }
#line 1428 "parser.tab.c"
    break;

  case 21: /* Return: RETURN  */
#line 127 "parser.y"
             {
        (yyval.node) = new ReturnNode();
    }
#line 1436 "parser.tab.c"
    break;

  case 22: /* Return: RETURN Expression  */
#line 130 "parser.y"
                        {
        (yyval.node) = new ReturnNode((ExpressionNode*)(yyvsp[0].node));
    }
#line 1444 "parser.tab.c"
    break;

  case 23: /* Print: PRINT ExpressionList  */
#line 136 "parser.y"
                           { 
        (yyval.node) = new PrintNode((Elements*)(yyvsp[0].node)); 
    }
#line 1452 "parser.tab.c"
    break;

  case 24: /* Body: Body Statement  */
#line 142 "parser.y"
                     { 
        (yyvsp[-1].node)->Add((yyvsp[0].node)); 
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1461 "parser.tab.c"
    break;

  case 25: /* Body: %empty  */
#line 146 "parser.y"
                  {
        (yyval.node) = new BlocksNode();
    }
#line 1469 "parser.tab.c"
    break;

  case 26: /* Expression: Relation  */
#line 152 "parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1475 "parser.tab.c"
    break;

  case 27: /* Expression: Expression AND Relation  */
#line 153 "parser.y"
                              { (yyval.node) = new BooleanOperation((ExpressionNode*)(yyvsp[-2].node), (ExpressionNode*)(yyvsp[0].node), "AND"); }
#line 1481 "parser.tab.c"
    break;

  case 28: /* Expression: Expression OR Relation  */
#line 154 "parser.y"
                              { (yyval.node) = new BooleanOperation((ExpressionNode*)(yyvsp[-2].node), (ExpressionNode*)(yyvsp[0].node), "OR"); }
#line 1487 "parser.tab.c"
    break;

  case 29: /* Expression: Expression XOR Relation  */
#line 155 "parser.y"
                              { (yyval.node) = new BooleanOperation((ExpressionNode*)(yyvsp[-2].node), (ExpressionNode*)(yyvsp[0].node), "XOR"); }
#line 1493 "parser.tab.c"
    break;

  case 30: /* Relation: Factor  */
#line 159 "parser.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1499 "parser.tab.c"
    break;

  case 31: /* Relation: Relation LT Factor  */
#line 160 "parser.y"
                          { (yyval.node) = new RelationOperation((ExpressionNode*)(yyvsp[-2].node), (ExpressionNode*)(yyvsp[0].node), "<"); }
#line 1505 "parser.tab.c"
    break;

  case 32: /* Relation: Relation LE Factor  */
#line 161 "parser.y"
                          { (yyval.node) = new RelationOperation((ExpressionNode*)(yyvsp[-2].node), (ExpressionNode*)(yyvsp[0].node), "<="); }
#line 1511 "parser.tab.c"
    break;

  case 33: /* Relation: Relation GT Factor  */
#line 162 "parser.y"
                          { (yyval.node) = new RelationOperation((ExpressionNode*)(yyvsp[-2].node), (ExpressionNode*)(yyvsp[0].node), ">"); }
#line 1517 "parser.tab.c"
    break;

  case 34: /* Relation: Relation GE Factor  */
#line 163 "parser.y"
                          { (yyval.node) = new RelationOperation((ExpressionNode*)(yyvsp[-2].node), (ExpressionNode*)(yyvsp[0].node), ">="); }
#line 1523 "parser.tab.c"
    break;

  case 35: /* Relation: Relation EQ Factor  */
#line 164 "parser.y"
                          { (yyval.node) = new RelationOperation((ExpressionNode*)(yyvsp[-2].node), (ExpressionNode*)(yyvsp[0].node), "="); }
#line 1529 "parser.tab.c"
    break;

  case 36: /* Relation: Relation NEQ Factor  */
#line 165 "parser.y"
                          { (yyval.node) = new RelationOperation((ExpressionNode*)(yyvsp[-2].node), (ExpressionNode*)(yyvsp[0].node), "/="); }
#line 1535 "parser.tab.c"
    break;

  case 37: /* Factor: Term  */
#line 169 "parser.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 1541 "parser.tab.c"
    break;

  case 38: /* Factor: Factor PLUS Term  */
#line 170 "parser.y"
                        { (yyval.node) = new ArithmeticOperation((ExpressionNode*)(yyvsp[-2].node), (ExpressionNode*)(yyvsp[0].node), '+'); }
#line 1547 "parser.tab.c"
    break;

  case 39: /* Factor: Factor MINUS Term  */
#line 171 "parser.y"
                        { (yyval.node) = new ArithmeticOperation((ExpressionNode*)(yyvsp[-2].node), (ExpressionNode*)(yyvsp[0].node),'-'); }
#line 1553 "parser.tab.c"
    break;

  case 40: /* Term: Unary  */
#line 175 "parser.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 1559 "parser.tab.c"
    break;

  case 41: /* Term: Term MUL Unary  */
#line 176 "parser.y"
                     { (yyval.node) = new ArithmeticOperation((ExpressionNode*)(yyvsp[-2].node), (ExpressionNode*)(yyvsp[0].node), '*'); }
#line 1565 "parser.tab.c"
    break;

  case 42: /* Term: Term DIV Unary  */
#line 177 "parser.y"
                     { (yyval.node) = new ArithmeticOperation((ExpressionNode*)(yyvsp[-2].node), (ExpressionNode*)(yyvsp[0].node), '/'); }
#line 1571 "parser.tab.c"
    break;

  case 43: /* Term: Term MOD Unary  */
#line 178 "parser.y"
                     { (yyval.node) = new ArithmeticOperation((ExpressionNode*)(yyvsp[-2].node), (ExpressionNode*)(yyvsp[0].node), '%'); }
#line 1577 "parser.tab.c"
    break;

  case 44: /* Unary: Reference  */
#line 182 "parser.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1583 "parser.tab.c"
    break;

  case 46: /* Unary: Primary  */
#line 184 "parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1589 "parser.tab.c"
    break;

  case 50: /* FunctionCall: IDENT LPAREN ExpressionList RPAREN  */
#line 191 "parser.y"
                                         {
        (yyval.node) = new FunctionCall(std::string((yyvsp[-3].value)), (Elements*)(yyvsp[-1].node));
    }
#line 1597 "parser.tab.c"
    break;

  case 51: /* Primary: Literal  */
#line 196 "parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1603 "parser.tab.c"
    break;

  case 52: /* Primary: LPAREN Expression RPAREN  */
#line 197 "parser.y"
                               { (yyval.node) = (yyvsp[-1].node); }
#line 1609 "parser.tab.c"
    break;

  case 53: /* Primary: FunctionCall  */
#line 198 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1615 "parser.tab.c"
    break;

  case 54: /* Literal: INTEGER  */
#line 202 "parser.y"
              { (yyval.node) = new ConstantNode(yylval.iconst); }
#line 1621 "parser.tab.c"
    break;

  case 55: /* Literal: REAL  */
#line 203 "parser.y"
           { (yyval.node) = new ConstantNode(yylval.fconst); }
#line 1627 "parser.tab.c"
    break;

  case 56: /* Literal: STRING  */
#line 204 "parser.y"
             { (yyval.node) = new ConstantNode(yylval.sconst); }
#line 1633 "parser.tab.c"
    break;

  case 57: /* Literal: TRUE  */
#line 205 "parser.y"
           { (yyval.node) = new ConstantNode(true); }
#line 1639 "parser.tab.c"
    break;

  case 58: /* Literal: FALSE  */
#line 206 "parser.y"
            { (yyval.node) = new ConstantNode(false); }
#line 1645 "parser.tab.c"
    break;

  case 60: /* Literal: Array  */
#line 208 "parser.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 1651 "parser.tab.c"
    break;

  case 61: /* Literal: EMPTY  */
#line 209 "parser.y"
            { (yyval.node) = new ConstantNode(); }
#line 1657 "parser.tab.c"
    break;

  case 68: /* Array: LBRACKET ExpressionList RBRACKET  */
#line 227 "parser.y"
                                       {
        (yyval.node) = new ArrayNode((Elements*) (yyvsp[-1].node));
    }
#line 1665 "parser.tab.c"
    break;

  case 69: /* ExpressionList: ExpressionList COMMA Expression  */
#line 233 "parser.y"
                                      {
        ((Elements*)(yyvsp[-2].node))->Add((ExpressionNode*)(yyvsp[0].node));
        (yyval.node) = (yyvsp[-2].node);
    }
#line 1674 "parser.tab.c"
    break;

  case 70: /* ExpressionList: Expression  */
#line 237 "parser.y"
                 {
        Elements* e = new Elements();
        e->Add((ExpressionNode*)(yyvsp[0].node));
        (yyval.node) = e;
    }
#line 1684 "parser.tab.c"
    break;

  case 71: /* ExpressionList: %empty  */
#line 242 "parser.y"
                   {
        (yyval.node) = new Elements();
    }
#line 1692 "parser.tab.c"
    break;

  case 72: /* Reference: IDENT  */
#line 248 "parser.y"
            { (yyval.node) = new LocationValue(std::string((yyvsp[0].value))); }
#line 1698 "parser.tab.c"
    break;

  case 73: /* Reference: Reference LBRACKET INTEGER RBRACKET  */
#line 249 "parser.y"
                                          { std::cout << "here" << std::endl; }
#line 1704 "parser.tab.c"
    break;

  case 84: /* OptIdentifierList: IDENT  */
#line 266 "parser.y"
            {
        auto param = new Parameters();
        param->Add(std::string((yyvsp[0].value)));
        (yyval.node) = param;
    }
#line 1714 "parser.tab.c"
    break;

  case 85: /* OptIdentifierList: OptIdentifierList COMMA IDENT  */
#line 271 "parser.y"
                                       {
        ((Parameters*)(yyvsp[-2].node))->Add(std::string((yyvsp[0].value)));
        (yyval.node) = (yyvsp[-2].node);
    }
#line 1723 "parser.tab.c"
    break;

  case 86: /* OptIdentifierList: %empty  */
#line 275 "parser.y"
                  {
        (yyval.node) = new Parameters();
    }
#line 1731 "parser.tab.c"
    break;

  case 87: /* FunBody: IS Body END  */
#line 281 "parser.y"
                  {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1739 "parser.tab.c"
    break;

  case 88: /* FunBody: IMPLICATION Statement  */
#line 284 "parser.y"
                            {
        auto block = new BlocksNode();
        block->Add((yyvsp[0].node));
        (yyval.node) = block;
    }
#line 1749 "parser.tab.c"
    break;

  case 89: /* FunBody: IMPLICATION Statement SEMICOLON  */
#line 289 "parser.y"
                                      {
        auto block = new BlocksNode();
        block->Add((yyvsp[-1].node));
        (yyval.node) = block;
    }
#line 1759 "parser.tab.c"
    break;


#line 1763 "parser.tab.c"

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

#line 296 "parser.y"


void yyerror(const char *s)
{
  fprintf(stderr, "Syntax error at line %d: %s\n", yylineno, s);
  exit(1);
}

void PrintMessage(const std::string& message) {
    for (int i = 0; i < 10; i++) {
        std::cout << "==";
    }
    std::cout << ' ' << message << ' ';
    for (int i = 0; i < 10; i++) {
        std::cout << "==";
    }
    std::cout << std::endl;
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
      if (!root) {
        std::cout << "Root is null" << std::endl;
      } else {
        
        std::cout << "Root is not null" << std::endl;
        PrintMessage("AST Tree");
        root->Print(0);
        
        PrintMessage("Program Start");
        root->Execute(nullptr);
        PrintMessage("Program Finish");
      }
      if (flag == 0) {
        std::cout << "Success :)" << std::endl;
      } else {
        std::cout << "Failure :(" << std::endl;
      }
    }
    fclose(yyin);

    return 0;
}
