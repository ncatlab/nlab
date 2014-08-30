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
     TEXATOP = 258,
     TEXOVER = 259,
     CHAR = 260,
     STARTMATH = 261,
     STARTDMATH = 262,
     ENDMATH = 263,
     MI = 264,
     MIB = 265,
     MN = 266,
     MO = 267,
     SUP = 268,
     SUB = 269,
     MROWOPEN = 270,
     MROWCLOSE = 271,
     LEFT = 272,
     RIGHT = 273,
     BIG = 274,
     BBIG = 275,
     BIGG = 276,
     BBIGG = 277,
     BIGL = 278,
     BBIGL = 279,
     BIGGL = 280,
     BBIGGL = 281,
     FRAC = 282,
     TFRAC = 283,
     OPERATORNAME = 284,
     MATHOP = 285,
     MATHBIN = 286,
     MATHREL = 287,
     MOP = 288,
     MOL = 289,
     MOLL = 290,
     MOF = 291,
     MOR = 292,
     PERIODDELIM = 293,
     OTHERDELIM = 294,
     LEFTDELIM = 295,
     RIGHTDELIM = 296,
     MOS = 297,
     MOB = 298,
     SQRT = 299,
     ROOT = 300,
     BINOM = 301,
     TBINOM = 302,
     UNDER = 303,
     OVER = 304,
     OVERBRACE = 305,
     UNDERLINE = 306,
     UNDERBRACE = 307,
     UNDEROVER = 308,
     TENSOR = 309,
     MULTI = 310,
     ARRAYALIGN = 311,
     COLUMNALIGN = 312,
     ARRAY = 313,
     COLSEP = 314,
     ROWSEP = 315,
     ARRAYOPTS = 316,
     COLLAYOUT = 317,
     COLALIGN = 318,
     ROWALIGN = 319,
     ALIGN = 320,
     EQROWS = 321,
     EQCOLS = 322,
     ROWLINES = 323,
     COLLINES = 324,
     FRAME = 325,
     PADDING = 326,
     ATTRLIST = 327,
     ITALICS = 328,
     SANS = 329,
     TT = 330,
     BOLD = 331,
     BOXED = 332,
     SLASHED = 333,
     RM = 334,
     BB = 335,
     ST = 336,
     END = 337,
     BBLOWERCHAR = 338,
     BBUPPERCHAR = 339,
     BBDIGIT = 340,
     CALCHAR = 341,
     FRAKCHAR = 342,
     CAL = 343,
     FRAK = 344,
     CLAP = 345,
     LLAP = 346,
     RLAP = 347,
     ROWOPTS = 348,
     TEXTSIZE = 349,
     SCSIZE = 350,
     SCSCSIZE = 351,
     DISPLAY = 352,
     TEXTSTY = 353,
     TEXTBOX = 354,
     TEXTSTRING = 355,
     XMLSTRING = 356,
     CELLOPTS = 357,
     ROWSPAN = 358,
     COLSPAN = 359,
     THINSPACE = 360,
     MEDSPACE = 361,
     THICKSPACE = 362,
     QUAD = 363,
     QQUAD = 364,
     NEGSPACE = 365,
     NEGMEDSPACE = 366,
     NEGTHICKSPACE = 367,
     PHANTOM = 368,
     HREF = 369,
     UNKNOWNCHAR = 370,
     EMPTYMROW = 371,
     STATLINE = 372,
     TOOLTIP = 373,
     TOGGLE = 374,
     TOGGLESTART = 375,
     TOGGLEEND = 376,
     FGHIGHLIGHT = 377,
     BGHIGHLIGHT = 378,
     SPACE = 379,
     INTONE = 380,
     INTTWO = 381,
     INTTHREE = 382,
     BAR = 383,
     WIDEBAR = 384,
     VEC = 385,
     WIDEVEC = 386,
     HAT = 387,
     WIDEHAT = 388,
     CHECK = 389,
     WIDECHECK = 390,
     TILDE = 391,
     WIDETILDE = 392,
     DOT = 393,
     DDOT = 394,
     DDDOT = 395,
     DDDDOT = 396,
     UNARYMINUS = 397,
     UNARYPLUS = 398,
     BEGINENV = 399,
     ENDENV = 400,
     MATRIX = 401,
     PMATRIX = 402,
     BMATRIX = 403,
     BBMATRIX = 404,
     VMATRIX = 405,
     VVMATRIX = 406,
     SVG = 407,
     ENDSVG = 408,
     SMALLMATRIX = 409,
     CASES = 410,
     ALIGNED = 411,
     GATHERED = 412,
     SUBSTACK = 413,
     PMOD = 414,
     RMCHAR = 415,
     COLOR = 416,
     BGCOLOR = 417,
     XARROW = 418,
     OPTARGOPEN = 419,
     OPTARGCLOSE = 420,
     ITEXNUM = 421,
     RAISEBOX = 422,
     NEG = 423
   };
#endif
/* Tokens.  */
#define TEXATOP 258
#define TEXOVER 259
#define CHAR 260
#define STARTMATH 261
#define STARTDMATH 262
#define ENDMATH 263
#define MI 264
#define MIB 265
#define MN 266
#define MO 267
#define SUP 268
#define SUB 269
#define MROWOPEN 270
#define MROWCLOSE 271
#define LEFT 272
#define RIGHT 273
#define BIG 274
#define BBIG 275
#define BIGG 276
#define BBIGG 277
#define BIGL 278
#define BBIGL 279
#define BIGGL 280
#define BBIGGL 281
#define FRAC 282
#define TFRAC 283
#define OPERATORNAME 284
#define MATHOP 285
#define MATHBIN 286
#define MATHREL 287
#define MOP 288
#define MOL 289
#define MOLL 290
#define MOF 291
#define MOR 292
#define PERIODDELIM 293
#define OTHERDELIM 294
#define LEFTDELIM 295
#define RIGHTDELIM 296
#define MOS 297
#define MOB 298
#define SQRT 299
#define ROOT 300
#define BINOM 301
#define TBINOM 302
#define UNDER 303
#define OVER 304
#define OVERBRACE 305
#define UNDERLINE 306
#define UNDERBRACE 307
#define UNDEROVER 308
#define TENSOR 309
#define MULTI 310
#define ARRAYALIGN 311
#define COLUMNALIGN 312
#define ARRAY 313
#define COLSEP 314
#define ROWSEP 315
#define ARRAYOPTS 316
#define COLLAYOUT 317
#define COLALIGN 318
#define ROWALIGN 319
#define ALIGN 320
#define EQROWS 321
#define EQCOLS 322
#define ROWLINES 323
#define COLLINES 324
#define FRAME 325
#define PADDING 326
#define ATTRLIST 327
#define ITALICS 328
#define SANS 329
#define TT 330
#define BOLD 331
#define BOXED 332
#define SLASHED 333
#define RM 334
#define BB 335
#define ST 336
#define END 337
#define BBLOWERCHAR 338
#define BBUPPERCHAR 339
#define BBDIGIT 340
#define CALCHAR 341
#define FRAKCHAR 342
#define CAL 343
#define FRAK 344
#define CLAP 345
#define LLAP 346
#define RLAP 347
#define ROWOPTS 348
#define TEXTSIZE 349
#define SCSIZE 350
#define SCSCSIZE 351
#define DISPLAY 352
#define TEXTSTY 353
#define TEXTBOX 354
#define TEXTSTRING 355
#define XMLSTRING 356
#define CELLOPTS 357
#define ROWSPAN 358
#define COLSPAN 359
#define THINSPACE 360
#define MEDSPACE 361
#define THICKSPACE 362
#define QUAD 363
#define QQUAD 364
#define NEGSPACE 365
#define NEGMEDSPACE 366
#define NEGTHICKSPACE 367
#define PHANTOM 368
#define HREF 369
#define UNKNOWNCHAR 370
#define EMPTYMROW 371
#define STATLINE 372
#define TOOLTIP 373
#define TOGGLE 374
#define TOGGLESTART 375
#define TOGGLEEND 376
#define FGHIGHLIGHT 377
#define BGHIGHLIGHT 378
#define SPACE 379
#define INTONE 380
#define INTTWO 381
#define INTTHREE 382
#define BAR 383
#define WIDEBAR 384
#define VEC 385
#define WIDEVEC 386
#define HAT 387
#define WIDEHAT 388
#define CHECK 389
#define WIDECHECK 390
#define TILDE 391
#define WIDETILDE 392
#define DOT 393
#define DDOT 394
#define DDDOT 395
#define DDDDOT 396
#define UNARYMINUS 397
#define UNARYPLUS 398
#define BEGINENV 399
#define ENDENV 400
#define MATRIX 401
#define PMATRIX 402
#define BMATRIX 403
#define BBMATRIX 404
#define VMATRIX 405
#define VVMATRIX 406
#define SVG 407
#define ENDSVG 408
#define SMALLMATRIX 409
#define CASES 410
#define ALIGNED 411
#define GATHERED 412
#define SUBSTACK 413
#define PMOD 414
#define RMCHAR 415
#define COLOR 416
#define BGCOLOR 417
#define XARROW 418
#define OPTARGOPEN 419
#define OPTARGCLOSE 420
#define ITEXNUM 421
#define RAISEBOX 422
#define NEG 423




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE itex2MML_yylval;

