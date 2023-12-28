/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     COMMENT = 258,
     LF = 259,
     CR = 260,
     EOL = 261,
     TAB_H = 262,
     TAB_V = 263,
     TAB = 264,
     FF = 265,
     SPACE_ASCII = 266,
     SPACE_UTF8_2BYTE = 267,
     SPACE_UTF8_3BYTE = 268,
     BLANK = 269,
     BLANK_LINE = 270,
     INDENT = 271,
     DOT = 272,
     COMMA = 273,
     EQUAL = 274,
     SQUARE_L = 275,
     SQUARE_R = 276,
     CURLY_L = 277,
     CURLY_R = 278,
     ANGLE_L = 279,
     ANGLE_R = 280,
     ROUND_L = 281,
     ROUND_R = 282,
     PLUS = 283,
     MINUS = 284,
     MUL = 285,
     SLASH = 286,
     BACK_SLASH = 287,
     SEMICOLON = 288,
     COLON = 289,
     DOLLAR = 290,
     PERCENT = 291,
     SHARP = 292,
     QUOTE_SINGLE = 293,
     QUOTE_DOUBLE = 294,
     QUOTE_BACK = 295,
     UNDERSCORE = 296,
     QUESTION = 297,
     NOT = 298,
     AND = 299,
     AT = 300,
     HAT = 301,
     TILDE = 302,
     OR = 303,
     AT_TOL = 304,
     MUL_MUL = 305,
     INCREMENT = 306,
     DECREMENT = 307,
     ANGLE_L_EQUAL = 308,
     ANGLE_R_EQUAL = 309,
     EQUAL_EQUAL = 310,
     NOT_EQUAL = 311,
     AND_AND = 312,
     OR_OR = 313,
     PLUS_EQUAL = 314,
     MINUS_EQUAL = 315,
     MUL_MUL_EQUAL = 316,
     MUL_EQUAL = 317,
     SLASH_EQUAL = 318,
     PERCENT_EQUAL = 319,
     AND_EQUAL = 320,
     HAT_EQUAL = 321,
     OR_EQUAL = 322,
     AND_AND_EQUAL = 323,
     OR_OR_EQUAL = 324,
     Q_Q_EQUAL = 325,
     ARROW = 326,
     ARROW_SINGLE = 327,
     SPREAD = 328,
     ESC_LF = 329,
     ESC_CR = 330,
     ESC_TAB = 331,
     ESC_QUOTE_SINGLE = 332,
     ESC_QUOTE_DOUBLE = 333,
     ESC_BACK_SLASH = 334,
     MESSAGE = 335,
     LABEL_KEY = 336,
     TAG_KEY = 337,
     TAG_STRING = 338,
     HEX_COLOR = 339,
     NUMERAL_HEX = 340,
     FLOAT = 341,
     INTEGER = 342,
     ZERO = 343,
     DIGIT_NON_ZERO = 344,
     NUMBER = 345,
     NOVEL_KEYS = 346,
     ALPHABET = 347,
     UTF8 = 348
   };
#endif
/* Tokens.  */
#define COMMENT 258
#define LF 259
#define CR 260
#define EOL 261
#define TAB_H 262
#define TAB_V 263
#define TAB 264
#define FF 265
#define SPACE_ASCII 266
#define SPACE_UTF8_2BYTE 267
#define SPACE_UTF8_3BYTE 268
#define BLANK 269
#define BLANK_LINE 270
#define INDENT 271
#define DOT 272
#define COMMA 273
#define EQUAL 274
#define SQUARE_L 275
#define SQUARE_R 276
#define CURLY_L 277
#define CURLY_R 278
#define ANGLE_L 279
#define ANGLE_R 280
#define ROUND_L 281
#define ROUND_R 282
#define PLUS 283
#define MINUS 284
#define MUL 285
#define SLASH 286
#define BACK_SLASH 287
#define SEMICOLON 288
#define COLON 289
#define DOLLAR 290
#define PERCENT 291
#define SHARP 292
#define QUOTE_SINGLE 293
#define QUOTE_DOUBLE 294
#define QUOTE_BACK 295
#define UNDERSCORE 296
#define QUESTION 297
#define NOT 298
#define AND 299
#define AT 300
#define HAT 301
#define TILDE 302
#define OR 303
#define AT_TOL 304
#define MUL_MUL 305
#define INCREMENT 306
#define DECREMENT 307
#define ANGLE_L_EQUAL 308
#define ANGLE_R_EQUAL 309
#define EQUAL_EQUAL 310
#define NOT_EQUAL 311
#define AND_AND 312
#define OR_OR 313
#define PLUS_EQUAL 314
#define MINUS_EQUAL 315
#define MUL_MUL_EQUAL 316
#define MUL_EQUAL 317
#define SLASH_EQUAL 318
#define PERCENT_EQUAL 319
#define AND_EQUAL 320
#define HAT_EQUAL 321
#define OR_EQUAL 322
#define AND_AND_EQUAL 323
#define OR_OR_EQUAL 324
#define Q_Q_EQUAL 325
#define ARROW 326
#define ARROW_SINGLE 327
#define SPREAD 328
#define ESC_LF 329
#define ESC_CR 330
#define ESC_TAB 331
#define ESC_QUOTE_SINGLE 332
#define ESC_QUOTE_DOUBLE 333
#define ESC_BACK_SLASH 334
#define MESSAGE 335
#define LABEL_KEY 336
#define TAG_KEY 337
#define TAG_STRING 338
#define HEX_COLOR 339
#define NUMERAL_HEX 340
#define FLOAT 341
#define INTEGER 342
#define ZERO 343
#define DIGIT_NON_ZERO 344
#define NUMBER 345
#define NOVEL_KEYS 346
#define ALPHABET 347
#define UTF8 348




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 39 "parser.y"
{
    int int_value;
    double double_value;
    char *string_value;
}
/* Line 1529 of yacc.c.  */
#line 241 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

