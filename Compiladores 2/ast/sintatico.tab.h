/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SINTATICO_TAB_H_INCLUDED
# define YY_YY_SINTATICO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    INTEGER = 259,                 /* INTEGER  */
    REAL = 260,                    /* REAL  */
    ABOUT = 261,                   /* ABOUT  */
    ABS = 262,                     /* ABS  */
    AXIS = 263,                    /* AXIS  */
    CONNECT_DOTS = 264,            /* CONNECT_DOTS  */
    COS = 265,                     /* COS  */
    DETERMINANT = 266,             /* DETERMINANT  */
    E = 267,                       /* E  */
    ERASE = 268,                   /* ERASE  */
    FLOAT = 269,                   /* FLOAT  */
    H_VIEW = 270,                  /* H_VIEW  */
    INTEGRAL_STEPS = 271,          /* INTEGRAL_STEPS  */
    INTEGRATE = 272,               /* INTEGRATE  */
    LINEAR_SYSTEM = 273,           /* LINEAR_SYSTEM  */
    MATRIX = 274,                  /* MATRIX  */
    OFF = 275,                     /* OFF  */
    ON = 276,                      /* ON  */
    PI = 277,                      /* PI  */
    PLOT = 278,                    /* PLOT  */
    PRECISION = 279,               /* PRECISION  */
    QUIT = 280,                    /* QUIT  */
    RESET = 281,                   /* RESET  */
    RPN = 282,                     /* RPN  */
    SEN = 283,                     /* SEN  */
    SET = 284,                     /* SET  */
    SETTINGS = 285,                /* SETTINGS  */
    SHOW = 286,                    /* SHOW  */
    SOLVE = 287,                   /* SOLVE  */
    SUM = 288,                     /* SUM  */
    SYMBOLS = 289,                 /* SYMBOLS  */
    TAN = 290,                     /* TAN  */
    V_VIEW = 291,                  /* V_VIEW  */
    X = 292,                       /* X  */
    PLUS = 293,                    /* PLUS  */
    MINUS = 294,                   /* MINUS  */
    TIMES = 295,                   /* TIMES  */
    DIVIDE = 296,                  /* DIVIDE  */
    POWER = 297,                   /* POWER  */
    MOD = 298,                     /* MOD  */
    OPEN_PAR = 299,                /* OPEN_PAR  */
    CLOSE_PAR = 300,               /* CLOSE_PAR  */
    COLON = 301,                   /* COLON  */
    EQUAL = 302,                   /* EQUAL  */
    ASSIGN = 303,                  /* ASSIGN  */
    OPEN_BRA = 304,                /* OPEN_BRA  */
    CLOSE_BRA = 305,               /* CLOSE_BRA  */
    SEMICOLON = 306,               /* SEMICOLON  */
    COMMA = 307,                   /* COMMA  */
    ERROR = 308,                   /* ERROR  */
    NEW_LINE = 309,                /* NEW_LINE  */
    EXIT = 310,                    /* EXIT  */
    END_OF_FILE = 311              /* END_OF_FILE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 41 "sintatico.y"

    int intval;
    float realval;
    char *strval;
    TreeNode *ast;

#line 127 "sintatico.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SINTATICO_TAB_H_INCLUDED  */
