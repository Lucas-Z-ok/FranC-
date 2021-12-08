/* A Bison parser, made by GNU Bison 3.8.1.  */

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

#ifndef YY_YY_LANGAGE_BISON_HPP_INCLUDED
# define YY_YY_LANGAGE_BISON_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 47 "langage.y"

    typedef struct adr {
        int jmp;  // adresse du jmp
        int jc;  // adrese  du jc
    } type_adresse;
  

#line 57 "langage.bison.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUM = 258,                     /* NUM  */
    STRING = 259,                  /* STRING  */
    VAR = 260,                     /* VAR  */
    SIN = 261,                     /* SIN  */
    COS = 262,                     /* COS  */
    TAN = 263,                     /* TAN  */
    SI = 264,                      /* SI  */
    ALORS = 265,                   /* ALORS  */
    ADDSTRING = 266,               /* ADDSTRING  */
    SINON = 267,                   /* SINON  */
    FINSI = 268,                   /* FINSI  */
    SUP = 269,                     /* SUP  */
    INF = 270,                     /* INF  */
    SUPEG = 271,                   /* SUPEG  */
    INFEG = 272,                   /* INFEG  */
    NEG = 273,                     /* NEG  */
    EGA = 274,                     /* EGA  */
    PRINT = 275,                   /* PRINT  */
    PRINTSTRING = 276,             /* PRINTSTRING  */
    RAND = 277,                    /* RAND  */
    ASSIGN = 278,                  /* ASSIGN  */
    ASSIGNSTRING = 279,            /* ASSIGNSTRING  */
    GOTO = 280,                    /* GOTO  */
    LABEL = 281,                   /* LABEL  */
    JMP = 282,                     /* JMP  */
    JMPCOND = 283,                 /* JMPCOND  */
    TANTQUE = 284,                 /* TANTQUE  */
    FINTANTQUE = 285,              /* FINTANTQUE  */
    ADD = 286,                     /* ADD  */
    SUB = 287,                     /* SUB  */
    MULT = 288,                    /* MULT  */
    DIV = 289                      /* DIV  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 54 "langage.y"

  double valeur;
  char nom[50];
  char valeurString[50];
  type_adresse adresse;  

#line 115 "langage.bison.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_LANGAGE_BISON_HPP_INCLUDED  */
