/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse itex2MML_yyparse
#define yylex   itex2MML_yylex
#define yyerror itex2MML_yyerror
#define yylval  itex2MML_yylval
#define yychar  itex2MML_yychar
#define yydebug itex2MML_yydebug
#define yynerrs itex2MML_yynerrs


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




/* Copy the first part of user declarations.  */
#line 5 "itex2MML.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "itex2MML.h"

#define YYSTYPE char *
#define YYPARSE_PARAM_TYPE char **
#define YYPARSE_PARAM ret_str

#define yytext itex2MML_yytext

 extern int yylex ();

 extern char * yytext;

 static void itex2MML_default_error (const char * msg)
   {
     if (msg)
       fprintf(stderr, "Line: %d Error: %s\n", itex2MML_lineno, msg);
   }

 void (*itex2MML_error) (const char * msg) = itex2MML_default_error;

 static void yyerror (char * s)
   {
     char * msg = itex2MML_copy3 (s, " at token ", yytext);
     if (itex2MML_error)
       (*itex2MML_error) (msg);
     itex2MML_free_string (msg);
   }

 /* Note: If length is 0, then buffer is treated like a string; otherwise only length bytes are written.
  */
 static void itex2MML_default_write (const char * buffer, unsigned long length)
   {
     if (buffer)
       {
	 if (length)
	   fwrite (buffer, 1, length, stdout);
	 else
	   fputs (buffer, stdout);
       }
   }

 static void itex2MML_default_write_mathml (const char * mathml)
   {
     if (itex2MML_write)
       (*itex2MML_write) (mathml, 0);
   }

#ifdef itex2MML_CAPTURE
    static char * itex2MML_output_string = "" ;

    const char * itex2MML_output ()
    {
        char * copy = (char *) malloc((itex2MML_output_string ? strlen(itex2MML_output_string) : 0) + 1);
        if (copy)
          {
           if (itex2MML_output_string)
             {
               strcpy(copy, itex2MML_output_string);
               if (*itex2MML_output_string != '\0')
                   free(itex2MML_output_string);
             }
           else
             copy[0] = 0;
           itex2MML_output_string = "";
          }
        return copy;
    }

 static void itex2MML_capture (const char * buffer, unsigned long length)
    {
     if (buffer)
       {
         if (length)
           {
              unsigned long first_length = itex2MML_output_string ? strlen(itex2MML_output_string) : 0;
              char * copy  = (char *) malloc(first_length + length + 1);
              if (copy)
                {
                  if (itex2MML_output_string)
                    {
                       strcpy(copy, itex2MML_output_string);
                       if (*itex2MML_output_string != '\0')
                          free(itex2MML_output_string);
                    }
                  else
                     copy[0] = 0;
                  strncat(copy, buffer, length);
                  itex2MML_output_string = copy;
                 }
            }
         else
            {
              char * copy = itex2MML_copy2(itex2MML_output_string, buffer);
              if (*itex2MML_output_string != '\0')
                 free(itex2MML_output_string);
              itex2MML_output_string = copy;
            }
        }
    }

    static void itex2MML_capture_mathml (const char * buffer)
    {
       char * temp = itex2MML_copy2(itex2MML_output_string, buffer);
       if (*itex2MML_output_string != '\0')
         free(itex2MML_output_string);
       itex2MML_output_string = temp;
    }
    void (*itex2MML_write) (const char * buffer, unsigned long length) = itex2MML_capture;
    void (*itex2MML_write_mathml) (const char * mathml) = itex2MML_capture_mathml;
#else
    void (*itex2MML_write) (const char * buffer, unsigned long length) = itex2MML_default_write;
    void (*itex2MML_write_mathml) (const char * mathml) = itex2MML_default_write_mathml;
#endif 

 char * itex2MML_empty_string = "";

 /* Create a copy of a string, adding space for extra chars
  */
 char * itex2MML_copy_string_extra (const char * str, unsigned extra)
   {
     char * copy = (char *) malloc(extra + (str ? strlen (str) : 0) + 1);
     if (copy)
       {
	 if (str)
	   strcpy(copy, str);
	 else
	   copy[0] = 0;
       }
     return copy ? copy : itex2MML_empty_string;
   }

 /* Create a copy of a string, appending two strings
  */
 char * itex2MML_copy3 (const char * first, const char * second, const char * third)
   {
     int  first_length =  first ? strlen( first) : 0;
     int second_length = second ? strlen(second) : 0;
     int  third_length =  third ? strlen( third) : 0;

     char * copy = (char *) malloc(first_length + second_length + third_length + 1);

     if (copy)
       {
	 if (first)
	   strcpy(copy, first);
	 else
	   copy[0] = 0;

	 if (second) strcat(copy, second);
	 if ( third) strcat(copy,  third);
       }
     return copy ? copy : itex2MML_empty_string;
   }

 /* Create a copy of a string, appending a second string
  */
 char * itex2MML_copy2 (const char * first, const char * second)
   {
     return itex2MML_copy3(first, second, 0);
   }

 /* Create a copy of a string
  */
 char * itex2MML_copy_string (const char * str)
   {
     return itex2MML_copy3(str, 0, 0);
   }

 /* Create a copy of a string, escaping unsafe characters for XML
  */
 char * itex2MML_copy_escaped (const char * str)
   {
     unsigned long length = 0;

     const char * ptr1 = str;

     char * ptr2 = 0;
     char * copy = 0;

     if ( str == 0) return itex2MML_empty_string;
     if (*str == 0) return itex2MML_empty_string;

     while (*ptr1)
       {
	 switch (*ptr1)
	   {
	   case '<':  /* &lt;   */
	   case '>':  /* &gt;   */
	     length += 4;
	     break;
	   case '&':  /* &amp;  */
	     length += 5;
	     break;
	   case '\'': /* &apos; */
	   case '"':  /* &quot; */
	   case '-':  /* &#x2d; */
	     length += 6;
	     break;
	   default:
	     length += 1;
	     break;
	   }
	 ++ptr1;
       }

     copy = (char *) malloc (length + 1);

     if (copy)
       {
	 ptr1 = str;
	 ptr2 = copy;

	 while (*ptr1)
	   {
	     switch (*ptr1)
	       {
	       case '<':
		 strcpy (ptr2, "&lt;");
		 ptr2 += 4;
		 break;
	       case '>':
		 strcpy (ptr2, "&gt;");
		 ptr2 += 4;
		 break;
	       case '&':  /* &amp;  */
		 strcpy (ptr2, "&amp;");
		 ptr2 += 5;
		 break;
	       case '\'': /* &apos; */
		 strcpy (ptr2, "&apos;");
		 ptr2 += 6;
		 break;
	       case '"':  /* &quot; */
		 strcpy (ptr2, "&quot;");
		 ptr2 += 6;
		 break;
	       case '-':  /* &#x2d; */
		 strcpy (ptr2, "&#x2d;");
		 ptr2 += 6;
		 break;
	       default:
		 *ptr2++ = *ptr1;
		 break;
	       }
	     ++ptr1;
	   }
	 *ptr2 = 0;
       }
     return copy ? copy : itex2MML_empty_string;
   }

 /* Create a hex character reference string corresponding to code
  */
 char * itex2MML_character_reference (unsigned long int code)
   {
#define ENTITY_LENGTH 10
     char * entity = (char *) malloc(ENTITY_LENGTH);
     sprintf(entity, "&#x%05lx;", code);
     return entity;
   }

 void itex2MML_free_string (char * str)
   {
     if (str && str != itex2MML_empty_string)
       free(str);
   }



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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 724 "y.tab.c"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  199
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   5009

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  169
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  117
/* YYNRULES -- Number of rules.  */
#define YYNRULES  323
/* YYNRULES -- Number of states.  */
#define YYNSTATES  574

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   423

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    10,    13,    16,    18,
      21,    24,    28,    32,    34,    37,    43,    47,    53,    57,
      63,    67,    73,    77,    83,    89,    93,    97,   100,   103,
     105,   107,   109,   111,   113,   115,   117,   119,   121,   123,
     125,   127,   129,   131,   133,   135,   137,   139,   141,   143,
     145,   147,   149,   151,   153,   155,   157,   159,   161,   163,
     165,   167,   169,   171,   173,   175,   177,   179,   181,   183,
     185,   187,   189,   191,   193,   195,   197,   199,   201,   203,
     205,   207,   209,   211,   213,   215,   217,   219,   221,   223,
     225,   227,   229,   231,   233,   235,   237,   239,   241,   243,
     247,   251,   255,   257,   259,   261,   263,   266,   269,   272,
     275,   278,   281,   284,   287,   290,   293,   296,   299,   302,
     305,   308,   311,   314,   317,   320,   323,   326,   329,   332,
     335,   338,   341,   343,   345,   347,   349,   351,   353,   356,
     358,   360,   362,   364,   366,   368,   370,   372,   374,   376,
     378,   380,   382,   384,   387,   390,   393,   396,   407,   411,
     415,   419,   423,   427,   431,   435,   439,   442,   445,   448,
     451,   454,   457,   460,   463,   466,   469,   472,   475,   478,
     481,   484,   489,   491,   494,   499,   501,   504,   506,   508,
     510,   515,   517,   520,   522,   527,   529,   532,   534,   536,
     538,   540,   542,   544,   546,   548,   550,   553,   557,   563,
     567,   576,   583,   590,   592,   595,   600,   603,   606,   610,
     614,   618,   621,   627,   633,   639,   645,   649,   653,   656,
     659,   662,   665,   668,   671,   674,   677,   680,   683,   686,
     689,   692,   695,   698,   701,   704,   707,   713,   717,   723,
     730,   735,   741,   745,   750,   756,   760,   763,   767,   773,
     778,   780,   786,   792,   798,   804,   810,   816,   822,   828,
     834,   840,   850,   859,   864,   868,   871,   873,   878,   883,
     892,   894,   897,   899,   901,   903,   905,   907,   909,   911,
     913,   915,   917,   920,   923,   926,   929,   932,   935,   938,
     941,   944,   947,   949,   953,   955,   957,   959,   963,   969,
     971,   974,   976,   978,   979,   981,   987,   989,   992,   994,
     996,   998,  1000,  1003
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     170,     0,    -1,   171,    -1,    -1,   172,    -1,   173,    -1,
     171,   172,    -1,   171,   173,    -1,     5,    -1,     6,     8,
      -1,     7,     8,    -1,     6,   174,     8,    -1,     7,   174,
       8,    -1,   175,    -1,   174,   175,    -1,   186,    14,   176,
      13,   176,    -1,   186,    14,   176,    -1,   186,    13,   176,
      14,   176,    -1,   186,    13,   176,    -1,   184,    14,   176,
      13,   176,    -1,   184,    14,   176,    -1,   184,    13,   176,
      14,   176,    -1,   184,    13,   176,    -1,   176,    14,   176,
      13,   176,    -1,   176,    13,   176,    14,   176,    -1,   176,
      14,   176,    -1,   176,    13,   176,    -1,    14,   176,    -1,
      13,   176,    -1,   176,    -1,   262,    -1,   181,    -1,   182,
      -1,   184,    -1,   183,    -1,   185,    -1,   187,    -1,   231,
      -1,   232,    -1,   235,    -1,   239,    -1,   252,    -1,   253,
      -1,   254,    -1,   255,    -1,   256,    -1,   243,    -1,   244,
      -1,   251,    -1,   245,    -1,   246,    -1,   247,    -1,   248,
      -1,   250,    -1,   249,    -1,   242,    -1,   240,    -1,   241,
      -1,   257,    -1,   258,    -1,   197,    -1,   196,    -1,   195,
      -1,   199,    -1,   200,    -1,   201,    -1,   202,    -1,   203,
      -1,   204,    -1,   205,    -1,   206,    -1,   209,    -1,   210,
      -1,   211,    -1,   212,    -1,   215,    -1,   207,    -1,   208,
      -1,   218,    -1,   188,    -1,   198,    -1,   221,    -1,   222,
      -1,   223,    -1,   224,    -1,   225,    -1,   226,    -1,   227,
      -1,   228,    -1,   229,    -1,   230,    -1,   189,    -1,   190,
      -1,   191,    -1,   192,    -1,   193,    -1,   194,    -1,   237,
      -1,   238,    -1,    15,   176,    16,    -1,    15,   174,    16,
      -1,   177,   174,   178,    -1,   259,    -1,   261,    -1,   236,
      -1,   180,    -1,    17,    40,    -1,    17,    39,    -1,    17,
      38,    -1,    18,    41,    -1,    18,    39,    -1,    18,    38,
      -1,    19,    40,    -1,    19,    41,    -1,    19,    39,    -1,
      20,    40,    -1,    20,    41,    -1,    20,    39,    -1,    21,
      40,    -1,    21,    41,    -1,    21,    39,    -1,    22,    40,
      -1,    22,    41,    -1,    22,    39,    -1,    23,    40,    -1,
      23,    39,    -1,    24,    40,    -1,    24,    39,    -1,    25,
      40,    -1,    25,    39,    -1,    26,    40,    -1,    26,    39,
      -1,   115,    -1,   142,    -1,   143,    -1,     9,    -1,    10,
      -1,    11,    -1,   166,   100,    -1,    43,    -1,   186,    -1,
     179,    -1,    12,    -1,    34,    -1,    35,    -1,    41,    -1,
      40,    -1,    39,    -1,    36,    -1,    38,    -1,    42,    -1,
      33,    -1,    37,    -1,    29,   100,    -1,    30,   100,    -1,
      31,   100,    -1,    32,   100,    -1,   124,    81,   125,    82,
      81,   126,    82,    81,   127,    82,    -1,   117,   100,   176,
      -1,   118,   100,   176,    -1,   119,   176,   176,    -1,   120,
     174,   121,    -1,   122,    72,   176,    -1,   123,    72,   176,
      -1,   161,    72,   174,    -1,   162,    72,   174,    -1,    92,
     176,    -1,    91,   176,    -1,    90,   176,    -1,    99,   100,
      -1,    97,   174,    -1,    98,   174,    -1,    94,   174,    -1,
      95,   174,    -1,    96,   174,    -1,    73,   176,    -1,    74,
     176,    -1,    75,   176,    -1,    78,   176,    -1,    77,   176,
      -1,    76,   176,    -1,    79,    81,   211,    82,    -1,   160,
      -1,   211,   160,    -1,    80,    81,   213,    82,    -1,   214,
      -1,   213,   214,    -1,    83,    -1,    84,    -1,    85,    -1,
      89,    81,   216,    82,    -1,   217,    -1,   216,   217,    -1,
      87,    -1,    88,    81,   219,    82,    -1,   220,    -1,   219,
     220,    -1,    86,    -1,   105,    -1,   106,    -1,   107,    -1,
     108,    -1,   109,    -1,   110,    -1,   111,    -1,   112,    -1,
     113,   176,    -1,   114,   100,   176,    -1,    54,   176,    15,
     233,    16,    -1,    54,   176,   233,    -1,    55,    15,   233,
      16,   176,    15,   233,    16,    -1,    55,    15,   233,    16,
     176,   116,    -1,    55,   116,   176,    15,   233,    16,    -1,
     234,    -1,   233,   234,    -1,    14,   176,    13,   176,    -1,
      14,   176,    -1,    13,   176,    -1,    14,    13,   176,    -1,
      27,   176,   176,    -1,    28,   176,   176,    -1,   159,   176,
      -1,    15,   174,     4,   174,    16,    -1,   177,   174,     4,
     174,   178,    -1,    15,   174,     3,   174,    16,    -1,   177,
     174,     3,   174,   178,    -1,    46,   176,   176,    -1,    47,
     176,   176,    -1,    52,   176,    -1,    51,   176,    -1,    50,
     176,    -1,   128,   176,    -1,   129,   176,    -1,   130,   176,
      -1,   131,   176,    -1,   138,   176,    -1,   139,   176,    -1,
     140,   176,    -1,   141,   176,    -1,   136,   176,    -1,   137,
     176,    -1,   134,   176,    -1,   135,   176,    -1,   132,   176,
      -1,   133,   176,    -1,    44,   176,    -1,    44,   164,   174,
     165,   176,    -1,    45,   176,   176,    -1,   167,   100,   100,
     100,   176,    -1,   167,   168,   100,   100,   100,   176,    -1,
     167,   100,   100,   176,    -1,   167,   168,   100,   100,   176,
      -1,   167,   100,   176,    -1,   167,   168,   100,   176,    -1,
     163,   164,   174,   165,   116,    -1,    48,   176,   176,    -1,
     163,   176,    -1,    49,   176,   176,    -1,   163,   164,   174,
     165,   176,    -1,    53,   176,   176,   176,    -1,   116,    -1,
     144,   146,   275,   145,   146,    -1,   144,   157,   275,   145,
     157,    -1,   144,   147,   275,   145,   147,    -1,   144,   148,
     275,   145,   148,    -1,   144,   150,   275,   145,   150,    -1,
     144,   149,   275,   145,   149,    -1,   144,   151,   275,   145,
     151,    -1,   144,   154,   275,   145,   154,    -1,   144,   155,
     275,   145,   155,    -1,   144,   156,   275,   145,   156,    -1,
     144,    58,    56,    81,   260,    82,   275,   145,    58,    -1,
     144,    58,    81,   260,    82,   275,   145,    58,    -1,   144,
     152,   101,   153,    -1,   144,   152,   153,    -1,   260,    57,
      -1,    57,    -1,   158,    15,   275,    16,    -1,    58,    15,
     275,    16,    -1,    58,    15,    61,    15,   263,    16,   275,
      16,    -1,   264,    -1,   263,   264,    -1,   265,    -1,   266,
      -1,   267,    -1,   268,    -1,   269,    -1,   270,    -1,   271,
      -1,   272,    -1,   273,    -1,   274,    -1,    62,    72,    -1,
      63,    72,    -1,    64,    72,    -1,    65,    72,    -1,    66,
      72,    -1,    67,    72,    -1,    68,    72,    -1,    69,    72,
      -1,    70,    72,    -1,    71,    72,    -1,   276,    -1,   275,
      60,   276,    -1,   277,    -1,   278,    -1,   281,    -1,   277,
      59,   281,    -1,    93,    15,   279,    16,   277,    -1,   280,
      -1,   279,   280,    -1,   266,    -1,   267,    -1,    -1,   174,
      -1,   102,    15,   282,    16,   174,    -1,   283,    -1,   282,
     283,    -1,   266,    -1,   267,    -1,   284,    -1,   285,    -1,
     103,    72,    -1,   104,    72,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   284,   284,   287,   288,   289,   290,   291,   293,   295,
     296,   297,   313,   330,   334,   340,   359,   373,   392,   406,
     425,   439,   458,   472,   482,   492,   499,   506,   510,   514,
     519,   520,   521,   522,   523,   527,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     598,   602,   610,   611,   612,   613,   615,   620,   625,   631,
     635,   639,   644,   649,   653,   657,   662,   666,   670,   675,
     679,   683,   688,   692,   696,   701,   706,   711,   716,   721,
     726,   731,   737,   741,   745,   749,   751,   757,   758,   764,
     770,   771,   772,   777,   782,   787,   791,   796,   800,   804,
     808,   813,   818,   823,   828,   833,   838,   844,   855,   863,
     871,   878,   883,   891,   899,   906,   914,   919,   924,   929,
     934,   939,   944,   949,   954,   959,   964,   969,   974,   979,
     984,   989,   994,   998,  1004,  1009,  1013,  1019,  1023,  1027,
    1035,  1040,  1044,  1050,  1055,  1060,  1064,  1070,  1075,  1079,
    1083,  1087,  1091,  1095,  1099,  1103,  1107,  1112,  1122,  1129,
    1137,  1147,  1156,  1164,  1168,  1174,  1179,  1183,  1187,  1192,
    1199,  1207,  1212,  1219,  1233,  1240,  1254,  1261,  1269,  1274,
    1279,  1284,  1288,  1293,  1297,  1302,  1307,  1312,  1317,  1322,
    1326,  1331,  1335,  1340,  1344,  1349,  1354,  1361,  1369,  1382,
    1395,  1405,  1417,  1426,  1436,  1443,  1451,  1458,  1466,  1476,
    1485,  1489,  1493,  1497,  1501,  1505,  1509,  1513,  1517,  1521,
    1525,  1529,  1539,  1546,  1550,  1554,  1559,  1564,  1569,  1573,
    1581,  1585,  1591,  1595,  1599,  1603,  1607,  1611,  1615,  1619,
    1623,  1627,  1632,  1637,  1642,  1647,  1652,  1657,  1662,  1667,
    1672,  1677,  1684,  1688,  1694,  1698,  1703,  1707,  1713,  1721,
    1725,  1731,  1735,  1740,  1743,  1747,  1755,  1759,  1765,  1769,
    1773,  1777,  1782,  1787
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TEXATOP", "TEXOVER", "CHAR",
  "STARTMATH", "STARTDMATH", "ENDMATH", "MI", "MIB", "MN", "MO", "SUP",
  "SUB", "MROWOPEN", "MROWCLOSE", "LEFT", "RIGHT", "BIG", "BBIG", "BIGG",
  "BBIGG", "BIGL", "BBIGL", "BIGGL", "BBIGGL", "FRAC", "TFRAC",
  "OPERATORNAME", "MATHOP", "MATHBIN", "MATHREL", "MOP", "MOL", "MOLL",
  "MOF", "MOR", "PERIODDELIM", "OTHERDELIM", "LEFTDELIM", "RIGHTDELIM",
  "MOS", "MOB", "SQRT", "ROOT", "BINOM", "TBINOM", "UNDER", "OVER",
  "OVERBRACE", "UNDERLINE", "UNDERBRACE", "UNDEROVER", "TENSOR", "MULTI",
  "ARRAYALIGN", "COLUMNALIGN", "ARRAY", "COLSEP", "ROWSEP", "ARRAYOPTS",
  "COLLAYOUT", "COLALIGN", "ROWALIGN", "ALIGN", "EQROWS", "EQCOLS",
  "ROWLINES", "COLLINES", "FRAME", "PADDING", "ATTRLIST", "ITALICS",
  "SANS", "TT", "BOLD", "BOXED", "SLASHED", "RM", "BB", "ST", "END",
  "BBLOWERCHAR", "BBUPPERCHAR", "BBDIGIT", "CALCHAR", "FRAKCHAR", "CAL",
  "FRAK", "CLAP", "LLAP", "RLAP", "ROWOPTS", "TEXTSIZE", "SCSIZE",
  "SCSCSIZE", "DISPLAY", "TEXTSTY", "TEXTBOX", "TEXTSTRING", "XMLSTRING",
  "CELLOPTS", "ROWSPAN", "COLSPAN", "THINSPACE", "MEDSPACE", "THICKSPACE",
  "QUAD", "QQUAD", "NEGSPACE", "NEGMEDSPACE", "NEGTHICKSPACE", "PHANTOM",
  "HREF", "UNKNOWNCHAR", "EMPTYMROW", "STATLINE", "TOOLTIP", "TOGGLE",
  "TOGGLESTART", "TOGGLEEND", "FGHIGHLIGHT", "BGHIGHLIGHT", "SPACE",
  "INTONE", "INTTWO", "INTTHREE", "BAR", "WIDEBAR", "VEC", "WIDEVEC",
  "HAT", "WIDEHAT", "CHECK", "WIDECHECK", "TILDE", "WIDETILDE", "DOT",
  "DDOT", "DDDOT", "DDDDOT", "UNARYMINUS", "UNARYPLUS", "BEGINENV",
  "ENDENV", "MATRIX", "PMATRIX", "BMATRIX", "BBMATRIX", "VMATRIX",
  "VVMATRIX", "SVG", "ENDSVG", "SMALLMATRIX", "CASES", "ALIGNED",
  "GATHERED", "SUBSTACK", "PMOD", "RMCHAR", "COLOR", "BGCOLOR", "XARROW",
  "OPTARGOPEN", "OPTARGCLOSE", "ITEXNUM", "RAISEBOX", "NEG", "$accept",
  "doc", "xmlmmlTermList", "char", "expression", "compoundTermList",
  "compoundTerm", "closedTerm", "left", "right", "bigdelim",
  "unrecognized", "unaryminus", "unaryplus", "mi", "mib", "mn", "mob",
  "mo", "space", "statusline", "tooltip", "toggle", "fghighlight",
  "bghighlight", "color", "mathrlap", "mathllap", "mathclap", "textstring",
  "displaystyle", "textstyle", "textsize", "scriptsize",
  "scriptscriptsize", "italics", "sans", "mono", "slashed", "boxed",
  "bold", "roman", "rmchars", "bbold", "bbchars", "bbchar", "frak",
  "frakletters", "frakletter", "cal", "calletters", "calletter",
  "thinspace", "medspace", "thickspace", "quad", "qquad", "negspace",
  "negmedspace", "negthickspace", "phantom", "href", "tensor", "multi",
  "subsupList", "subsupTerm", "mfrac", "pmod", "texover", "texatop",
  "binom", "munderbrace", "munderline", "moverbrace", "bar", "vec", "dot",
  "ddot", "dddot", "ddddot", "tilde", "check", "hat", "msqrt", "mroot",
  "raisebox", "munder", "mover", "munderover", "emptymrow", "mathenv",
  "columnAlignList", "substack", "array", "arrayopts", "anarrayopt",
  "collayout", "colalign", "rowalign", "align", "eqrows", "eqcols",
  "rowlines", "collines", "frame", "padding", "tableRowList", "tableRow",
  "simpleTableRow", "optsTableRow", "rowopts", "arowopt", "tableCell",
  "cellopts", "acellopt", "rowspan", "colspan", 0
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
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   169,   170,   171,   171,   171,   171,   171,   172,   173,
     173,   173,   173,   174,   174,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   177,   177,   177,   178,
     178,   178,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   180,   181,   182,   183,   184,   185,   185,   186,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   188,   189,   190,
     191,   191,   192,   193,   194,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   211,   212,   213,   213,   214,   214,   214,
     215,   216,   216,   217,   218,   219,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   231,
     232,   232,   232,   233,   233,   234,   234,   234,   234,   235,
     235,   236,   237,   237,   238,   238,   239,   239,   240,   241,
     242,   243,   243,   244,   244,   245,   246,   247,   248,   249,
     249,   250,   250,   251,   251,   252,   253,   253,   254,   254,
     254,   254,   254,   254,   255,   255,   256,   256,   257,   257,
     258,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   260,   260,   261,   262,   262,
     263,   263,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   275,   276,   276,   277,   277,   278,   279,
     279,   280,   280,   281,   281,   281,   282,   282,   283,   283,
     283,   283,   284,   285
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     1,     2,     2,     1,     2,
       2,     3,     3,     1,     2,     5,     3,     5,     3,     5,
       3,     5,     3,     5,     5,     3,     3,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,    10,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     4,     1,     2,     4,     1,     2,     1,     1,     1,
       4,     1,     2,     1,     4,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     5,     3,
       8,     6,     6,     1,     2,     4,     2,     2,     3,     3,
       3,     2,     5,     5,     5,     5,     3,     3,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     5,     3,     5,     6,
       4,     5,     3,     4,     5,     3,     2,     3,     5,     4,
       1,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     9,     8,     4,     3,     2,     1,     4,     4,     8,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     3,     1,     1,     1,     3,     5,     1,
       2,     1,     1,     0,     1,     5,     1,     2,     1,     1,
       1,     1,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       3,     8,     0,     0,     0,     2,     4,     5,     9,   135,
     136,   137,   142,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   151,   143,   144,   148,   152,   149,   147,   146,   145,
     150,   139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   198,   199,   200,   201,   202,   203,
     204,   205,     0,     0,   132,   260,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   133,   134,     0,
       0,     0,   182,     0,     0,     0,     0,     0,     0,    13,
      29,     0,   141,   105,    31,    32,    34,    33,    35,   140,
      36,    79,    91,    92,    93,    94,    95,    96,    62,    61,
      60,    80,    63,    64,    65,    66,    67,    68,    69,    70,
      76,    77,    71,    72,    73,    74,    75,    78,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    37,    38,
      39,   104,    97,    98,    40,    56,    57,    55,    46,    47,
      49,    50,    51,    52,    54,    53,    48,    41,    42,    43,
      44,    45,    58,    59,   102,   103,    30,    10,     0,     1,
       6,     7,    28,    33,   140,    27,     0,    29,   108,   107,
     106,   114,   112,   113,   117,   115,   116,   120,   118,   119,
     123,   121,   122,   125,   124,   127,   126,   129,   128,   131,
     130,     0,     0,   153,   154,   155,   156,     0,   245,     0,
       0,     0,     0,     0,   230,   229,   228,     0,     0,     0,
       0,   313,   175,   176,   177,   180,   179,   178,     0,     0,
       0,     0,   168,   167,   166,   172,   173,   174,   170,   171,
     169,   206,     0,     0,     0,     0,     0,     0,     0,     0,
     231,   232,   233,   234,   243,   244,   241,   242,   239,   240,
     235,   236,   237,   238,     0,   313,   313,   313,   313,   313,
     313,     0,   313,   313,   313,   313,   313,   221,     0,     0,
       0,   256,   138,     0,     0,    11,    14,     0,     0,     0,
       0,     0,     0,     0,   183,    12,     0,     0,   100,    99,
     219,   220,     0,   247,   226,   227,   255,   257,     0,     0,
       0,     0,   209,   213,     0,     0,     0,     0,     0,   314,
       0,   302,   304,   305,   306,     0,   187,   188,   189,     0,
     185,   197,     0,   195,   193,     0,   191,   207,   158,   159,
     160,   161,   162,   163,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   274,     0,     0,     0,     0,     0,
     164,   165,     0,     0,   252,     0,    26,    25,     0,     0,
       0,   101,    22,    20,    18,    16,     0,     0,     0,   259,
     217,     0,   216,     0,   214,     0,     0,     0,     0,     0,
     278,   313,   313,   181,   184,   186,   194,   196,   190,   192,
       0,     0,   276,     0,     0,     0,     0,     0,     0,     0,
     273,     0,     0,     0,     0,   277,     0,     0,   250,     0,
     253,     0,     0,     0,     0,   111,   110,   109,     0,     0,
       0,     0,   224,   222,   246,   218,     0,   208,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   280,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   311,   312,     0,   309,     0,     0,   318,   319,
       0,   316,   320,   321,   303,   307,     0,     0,   275,   313,
     261,   263,   264,   266,   265,   267,   268,   269,   270,   262,
     254,   258,   248,     0,   251,    24,    23,   225,   223,    21,
      19,    17,    15,   215,     0,   211,   212,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   313,   281,   313,
     310,   322,   323,     0,   317,     0,   313,     0,   249,     0,
       0,   308,   315,     0,     0,     0,   210,   279,     0,     0,
     272,     0,   271,   157
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,   349,   119,   120,   121,   401,
     122,   123,   124,   125,   126,   203,   128,   204,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   359,   360,   156,   365,   366,   157,
     362,   363,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   342,   343,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   433,   195,   196,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   350,   351,   352,   353,
     494,   495,   354,   500,   501,   502,   503
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -377
static const yytype_int16 yypact[] =
{
     165,  -377,  1341,  1501,    22,   165,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  4683,  4683,  3411,   145,   162,   166,   170,
     173,    32,   185,   187,   189,  4683,  4683,   -80,   -51,   -49,
     -38,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  3570,  4683,  4683,  4683,  4683,  4683,  4683,  4683,
    4683,  4683,  4683,   -11,    44,  4683,  4683,  4683,  4683,  4683,
    4683,    -5,     5,     8,    12,  4683,  4683,  4683,  3411,  3411,
    3411,  3411,  3411,   -21,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  4683,    15,  -377,  -377,    17,    21,  4683,  3411,
      55,    57,    50,  4683,  4683,  4683,  4683,  4683,  4683,  4683,
    4683,  4683,  4683,  4683,  4683,  4683,  4683,  -377,  -377,   -10,
     128,  4683,  -377,   117,   121,  3729,    58,   -91,  1661,  -377,
     217,  3411,  -377,  -377,  -377,  -377,  -377,   219,  -377,   223,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,    35,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  1821,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  1020,   109,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  4683,  4683,  -377,  -377,  -377,  -377,  3411,  -377,  4683,
    4683,  4683,  4683,  4683,  -377,  -377,  -377,  4683,   204,   232,
    4683,  1980,  -377,  -377,  -377,  -377,  -377,  -377,    39,   138,
      95,   147,  -377,  -377,  -377,  3411,  3411,  3411,  3411,  3411,
    -377,  -377,  4683,  4683,  4683,  4683,  2298,  4683,  4683,    90,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,    -6,  2139,  2139,  2139,  2139,  2139,
    2139,   -90,  2139,  2139,  2139,  2139,  2139,  -377,  3411,  3411,
    3411,  -377,  -377,  3888,   153,  -377,  -377,  4683,  4683,  1181,
    4683,  4683,  4683,  4683,  -377,  -377,  3411,  3411,  -377,  -377,
    -377,  -377,  2457,  -377,  -377,  -377,  -377,  -377,  4683,  4683,
    4047,   232,   232,  -377,   119,   239,   240,   241,   242,  3411,
      20,  -377,   179,  -377,  -377,   -72,  -377,  -377,  -377,    93,
    -377,  -377,   -28,  -377,  -377,   -30,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,   176,   180,   202,   -53,   -48,   -46,
     -42,   -41,   -39,   115,  -377,   -37,   -36,   -35,   -34,    30,
    3411,  3411,  2616,  4206,  -377,  4365,   248,   256,  3411,  3411,
     141,  -377,   257,   259,   266,   260,  2775,  2934,  4683,  -377,
    -377,  4683,   268,   174,  -377,  4683,   232,    86,   188,    -3,
    -377,  2139,  3093,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
     203,   202,  -377,    -4,   124,   136,   137,   139,   140,   148,
    -377,   151,   154,   155,   156,  -377,  4842,  4683,  -377,  4524,
    -377,  4683,  4683,  3252,  3252,  -377,  -377,  -377,  4683,  4683,
    4683,  4683,  -377,  -377,  -377,  -377,  4683,  -377,    -9,   178,
     238,   243,   244,   246,   247,   254,   255,   261,   262,   263,
      97,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,     1,  -377,   264,   265,  -377,  -377,
      -8,  -377,  -377,  -377,  -377,  -377,   186,    16,  -377,  2139,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  4683,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,   232,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  2139,  -377,  3093,
    -377,  -377,  -377,  3411,  -377,   249,  2139,   -33,  -377,   184,
      31,   179,  3411,   233,   -31,   270,  -377,  -377,   193,   274,
    -377,   267,  -377,  -377
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -377,  -377,  -377,   333,   336,    13,    10,   561,  -377,  -206,
    -377,  -377,  -377,  -377,  -377,    -2,  -377,   171,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,    85,  -377,  -377,   -15,  -377,  -377,   -20,  -377,
    -377,   -16,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,  -247,  -339,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,   -83,  -377,  -377,  -377,  -130,  -377,  -376,  -374,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -265,   -70,  -197,  -377,
    -377,  -141,   -68,  -377,  -145,  -377,  -377
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     127,   127,   344,   414,   249,   414,   534,   421,   553,   313,
     423,   383,   421,   127,   421,   118,   198,   549,   421,   421,
     233,   421,   199,   421,   421,   421,   421,   421,   206,   421,
     377,   378,   379,   380,   381,   382,   420,   385,   386,   387,
     388,   389,   492,   498,   493,   499,   445,   567,   294,   234,
     375,   235,   428,   508,   426,   471,   472,   364,   361,   251,
     471,   472,   236,   384,   471,   472,   127,   127,   127,   127,
     127,   223,   224,   508,   414,   376,   258,   314,   509,   270,
     421,   265,   266,   267,   268,   269,   259,   127,   324,   260,
     421,   421,   434,   261,   413,   496,   497,   435,   556,   436,
     496,   497,   276,   437,   438,   250,   439,   535,   441,   442,
     443,   444,   565,   547,   569,   272,   127,   273,   492,   127,
     493,   274,   317,   318,   498,   329,   499,   277,   316,   278,
     414,   279,   339,   340,   319,   415,   295,   296,   297,   298,
     299,   300,   301,   306,   302,   303,   304,   305,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   312,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   469,
       1,     2,     3,   129,   129,   424,   356,   357,   358,   455,
     456,   361,   457,   208,   209,   210,   129,   339,   340,   308,
     467,   339,   340,   309,   536,   324,   127,   339,   340,   112,
     566,   211,   212,   213,   127,   214,   215,   216,   316,   217,
     218,   219,   220,   221,   222,   374,   316,   339,   340,   341,
     414,   356,   357,   358,   225,   226,   227,   228,   229,   230,
     317,   318,   320,   321,   364,   127,   322,   323,   422,   129,
     129,   129,   129,   129,   557,   339,   340,   527,   528,   127,
     332,   471,   472,   395,   416,   417,   418,   419,   430,   432,
     129,   431,   451,   127,   127,   127,   127,   127,   440,   452,
     510,   458,   459,   461,   127,   316,   316,   316,   316,   316,
     460,   466,   560,   511,   506,   512,   316,   559,   513,   129,
     514,   564,   129,   127,   127,   127,   127,   127,   127,   515,
     127,   127,   127,   127,   127,   516,   127,   127,   127,   517,
     537,   518,   555,   519,   568,   538,   539,   127,   540,   541,
     571,   390,   391,   392,   127,   127,   542,   543,   570,   316,
     127,   563,   572,   544,   545,   546,   551,   552,   200,   406,
     407,   201,   316,   355,   425,   429,   427,   127,   507,   573,
     548,   504,   561,   550,   505,   554,     0,     0,     0,   316,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
       0,     0,     0,     0,     0,     0,     0,   129,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   127,   127,
     127,     0,     0,     0,     0,     0,   127,   127,     0,     0,
     316,   316,   316,     0,   127,   127,     0,     0,   129,     0,
       0,   453,   454,     0,     0,     0,   316,   316,     0,   127,
     127,     0,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   129,   129,   129,
     129,     0,     0,     0,     0,     0,     0,   129,     0,     0,
       0,   127,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   316,   316,     0,   129,   129,   129,   129,
     129,   129,     0,   129,   129,   129,   129,   129,     0,   129,
     129,   129,     0,     0,     0,     0,     0,     0,     0,     0,
     129,     0,     0,     0,     0,     0,     0,   129,   129,     0,
       0,     0,     0,   129,     0,     0,     0,   127,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,     0,   127,     0,     0,
       0,   127,     0,     0,   127,     0,     0,     0,     0,     0,
     127,   129,   129,   129,     0,     0,   562,     0,     0,   129,
     129,     0,   316,     0,   202,   205,   207,   129,   129,     0,
       0,     0,     0,     0,     0,     0,   231,   232,     0,     0,
       0,     0,   129,   129,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,     0,     0,   252,   253,   254,   255,
     256,   257,     0,     0,   129,   129,   262,   263,   264,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   271,     0,     0,     0,     0,     0,   275,
       0,     0,     0,     0,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,     0,     0,
       0,     0,   307,     0,     0,     0,   311,     0,     0,     0,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,     0,
     129,     0,     0,     0,   129,     0,     0,   129,     0,     0,
       0,     0,     0,   129,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   330,   331,     0,     0,     0,     0,     0,     0,
     333,   334,   335,   336,   337,     0,     0,     0,   338,     0,
       0,   345,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   367,   368,   369,   370,     0,   372,   373,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   394,     0,     0,     0,   396,   397,
       0,   402,   403,   404,   405,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   409,
     410,   412,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   448,     0,   450,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   464,
       0,     0,   465,     0,     0,     0,   468,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   521,   522,     0,
     524,     0,   525,   526,     0,     0,     0,     0,     0,   529,
     530,   531,   532,   326,   327,     0,     0,   533,     0,     9,
      10,    11,    12,    13,    14,    15,   328,    16,     0,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,    54,     0,
       0,     0,     0,     0,   558,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    56,    57,    58,    59,    60,    61,
      62,     0,     0,     0,     0,     0,     0,     0,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,    72,    73,
       0,     0,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,     0,    90,    91,    92,     0,     0,     0,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   110,   111,
     112,   113,   114,   115,   398,   399,   116,   117,     0,     0,
       9,    10,    11,    12,    13,    14,    15,     0,    16,   400,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,    56,    57,    58,    59,    60,
      61,    62,     0,     0,     0,     0,     0,     0,     0,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,    72,
      73,     0,     0,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     0,    90,    91,    92,     0,     0,     0,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
     111,   112,   113,   114,   115,     0,     0,   116,   117,     8,
       9,    10,    11,    12,    13,    14,    15,     0,    16,     0,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,    56,    57,    58,    59,    60,
      61,    62,     0,     0,     0,     0,     0,     0,     0,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,    72,
      73,     0,     0,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     0,    90,    91,    92,     0,     0,     0,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
     111,   112,   113,   114,   115,     0,     0,   116,   117,   197,
       9,    10,    11,    12,    13,    14,    15,     0,    16,     0,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,    56,    57,    58,    59,    60,
      61,    62,     0,     0,     0,     0,     0,     0,     0,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,    72,
      73,     0,     0,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     0,    90,    91,    92,     0,     0,     0,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
     111,   112,   113,   114,   115,     0,     0,   116,   117,   315,
       9,    10,    11,    12,    13,    14,    15,     0,    16,     0,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,    56,    57,    58,    59,    60,
      61,    62,     0,     0,     0,     0,     0,     0,     0,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,    72,
      73,     0,     0,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     0,    90,    91,    92,     0,     0,     0,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
     111,   112,   113,   114,   115,     0,     0,   116,   117,   325,
       9,    10,    11,    12,    13,    14,    15,     0,    16,     0,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,    56,    57,    58,    59,    60,
      61,    62,     0,     0,     0,     0,     0,     0,     0,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,    72,
      73,     0,     0,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     0,    90,    91,    92,     0,     0,     0,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
     111,   112,   113,   114,   115,     0,     0,   116,   117,     9,
      10,    11,    12,    13,    14,    15,     0,    16,     0,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,    54,     0,
       0,   346,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    56,    57,    58,    59,    60,    61,
      62,     0,     0,     0,     0,     0,     0,     0,    63,    64,
      65,    66,    67,   347,    68,    69,    70,    71,    72,    73,
       0,     0,   348,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,     0,    90,    91,    92,     0,     0,     0,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   110,   111,
     112,   113,   114,   115,     0,     0,   116,   117,     9,    10,
      11,    12,    13,    14,    15,     0,    16,     0,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,    56,    57,    58,    59,    60,    61,    62,
       0,     0,     0,     0,     0,     0,     0,    63,    64,    65,
      66,    67,   347,    68,    69,    70,    71,    72,    73,     0,
       0,   348,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
       0,    90,    91,    92,     0,     0,     0,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   110,   111,   112,
     113,   114,   115,     0,     0,   116,   117,     9,    10,    11,
      12,    13,    14,    15,     0,    16,     0,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,    56,    57,    58,    59,    60,    61,    62,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,    72,    73,     0,     0,
       0,     0,     0,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,   371,
      90,    91,    92,     0,     0,     0,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,   111,   112,   113,
     114,   115,     0,     0,   116,   117,     9,    10,    11,    12,
      13,    14,    15,     0,    16,     0,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,     0,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,    56,    57,    58,    59,    60,    61,    62,     0,     0,
       0,     0,     0,     0,     0,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,    72,    73,     0,     0,     0,
       0,     0,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     0,    90,
      91,    92,     0,     0,     0,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   110,   111,   112,   113,   114,
     115,     0,   408,   116,   117,     9,    10,    11,    12,    13,
      14,    15,     0,    16,     0,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     0,     0,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
      56,    57,    58,    59,    60,    61,    62,     0,     0,     0,
       0,     0,     0,     0,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,    72,    73,     0,     0,     0,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,    90,    91,
      92,     0,     0,     0,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   110,   111,   112,   113,   114,   115,
       0,   446,   116,   117,     9,    10,    11,    12,    13,    14,
      15,   462,    16,     0,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,     0,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,    56,
      57,    58,    59,    60,    61,    62,     0,     0,     0,     0,
       0,     0,     0,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,    72,    73,     0,     0,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,     0,    90,    91,    92,
       0,     0,     0,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   110,   111,   112,   113,   114,   115,     0,
       0,   116,   117,     9,    10,    11,    12,    13,    14,    15,
     463,    16,     0,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,    56,    57,
      58,    59,    60,    61,    62,     0,     0,     0,     0,     0,
       0,     0,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,    72,    73,     0,     0,     0,     0,     0,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,    90,    91,    92,     0,
       0,     0,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   110,   111,   112,   113,   114,   115,     0,     0,
     116,   117,     9,    10,    11,    12,    13,    14,    15,     0,
      16,     0,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,    56,    57,    58,
      59,    60,    61,    62,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,    72,    73,     0,     0,   348,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,     0,    90,    91,    92,     0,     0,
       0,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   110,   111,   112,   113,   114,   115,     0,     0,   116,
     117,     9,    10,    11,    12,    13,    14,    15,     0,    16,
     400,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,    56,    57,    58,    59,
      60,    61,    62,     0,     0,     0,     0,     0,     0,     0,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
      72,    73,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     0,    90,    91,    92,     0,     0,     0,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,   111,   112,   113,   114,   115,     0,     0,   116,   117,
       9,    10,    11,    12,    13,    14,    15,     0,    16,     0,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,    56,    57,    58,    59,    60,
      61,    62,     0,     0,     0,     0,     0,     0,     0,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,    72,
      73,     0,     0,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     0,    90,    91,    92,     0,     0,     0,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
     111,   112,   113,   114,   115,     0,     0,   116,   117,     9,
      10,    11,    12,     0,     0,    15,     0,    16,     0,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    56,    57,    58,    59,    60,    61,
      62,     0,     0,     0,     0,     0,     0,     0,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,    72,    73,
       0,     0,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,     0,    90,    91,    92,     0,     0,     0,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   110,   111,
     112,   113,   114,   115,   237,     0,   116,   117,     9,    10,
      11,    12,     0,     0,    15,     0,    16,     0,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,    56,    57,    58,    59,    60,    61,    62,
       0,     0,     0,     0,     0,     0,     0,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,    72,    73,     0,
       0,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
       0,    90,    91,    92,     0,     0,     0,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   110,   111,   112,
     113,   114,   115,   310,     0,   116,   117,     9,    10,    11,
      12,     0,     0,    15,     0,    16,     0,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,    56,    57,    58,    59,    60,    61,    62,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,    72,    73,   393,     0,
       0,     0,     0,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
      90,    91,    92,     0,     0,     0,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,   111,   112,   113,
     114,   115,     0,     0,   116,   117,     9,    10,    11,    12,
     411,     0,    15,     0,    16,     0,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,     0,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,    56,    57,    58,    59,    60,    61,    62,     0,     0,
       0,     0,     0,     0,     0,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,    72,    73,     0,     0,     0,
       0,     0,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     0,    90,
      91,    92,     0,     0,     0,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   110,   111,   112,   113,   114,
     115,     0,     0,   116,   117,     9,    10,    11,    12,     0,
       0,    15,     0,    16,     0,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     0,     0,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
      56,    57,    58,    59,    60,    61,    62,     0,     0,     0,
       0,     0,     0,     0,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,    72,    73,   447,     0,     0,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,    90,    91,
      92,     0,     0,     0,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   110,   111,   112,   113,   114,   115,
       0,     0,   116,   117,     9,    10,    11,    12,     0,     0,
      15,     0,    16,     0,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,     0,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,    56,
      57,    58,    59,    60,    61,    62,     0,     0,     0,     0,
       0,     0,     0,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,    72,    73,   449,     0,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,     0,    90,    91,    92,
       0,     0,     0,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   110,   111,   112,   113,   114,   115,     0,
       0,   116,   117,     9,    10,    11,    12,     0,     0,    15,
       0,    16,     0,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,    56,    57,
      58,    59,    60,    61,    62,     0,     0,     0,     0,     0,
       0,     0,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,    72,    73,   523,     0,     0,     0,     0,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,    90,    91,    92,     0,
       0,     0,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   110,   111,   112,   113,   114,   115,     0,     0,
     116,   117,     9,    10,    11,    12,     0,     0,    15,     0,
      16,     0,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,    56,    57,    58,
      59,    60,    61,    62,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,    72,    73,     0,     0,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,     0,    90,    91,    92,     0,     0,
       0,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   110,   111,   112,   113,   114,   115,     0,     0,   116,
     117,     9,    10,    11,    12,     0,     0,    15,     0,    16,
       0,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,    56,    57,    58,    59,
      60,    61,    62,     0,     0,     0,     0,     0,     0,     0,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
      72,    73,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,   520,    86,
      87,    88,    89,     0,    90,    91,    92,     0,     0,     0,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,   111,   112,   113,   114,   115,     0,     0,   116,   117
};

static const yytype_int16 yycheck[] =
{
       2,     3,   249,   342,    15,   344,    15,    60,    16,   100,
      82,   101,    60,    15,    60,     2,     3,    16,    60,    60,
     100,    60,     0,    60,    60,    60,    60,    60,    15,    60,
     295,   296,   297,   298,   299,   300,    16,   302,   303,   304,
     305,   306,   418,   419,   418,   419,    16,    16,    58,   100,
      56,   100,    82,    57,    82,    63,    64,    87,    86,    15,
      63,    64,   100,   153,    63,    64,    68,    69,    70,    71,
      72,    39,    40,    57,   413,    81,    81,   168,    82,   100,
      60,    68,    69,    70,    71,    72,    81,    89,   160,    81,
      60,    60,   145,    81,   341,   103,   104,   145,    82,   145,
     103,   104,    89,   145,   145,   116,   145,   116,   145,   145,
     145,   145,   145,    16,   145,   100,   118,   100,   494,   121,
     494,   100,    13,    14,   500,    16,   500,    72,   118,    72,
     469,    81,    13,    14,   121,    16,   146,   147,   148,   149,
     150,   151,   152,    15,   154,   155,   156,   157,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,   100,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,   416,
       5,     6,     7,     2,     3,    82,    83,    84,    85,    38,
      39,    86,    41,    38,    39,    40,    15,    13,    14,    72,
      16,    13,    14,    72,    16,   160,   198,    13,    14,   160,
      16,    39,    40,    41,   206,    39,    40,    41,   198,    39,
      40,    41,    39,    40,    41,   125,   206,    13,    14,    15,
     559,    83,    84,    85,    39,    40,    39,    40,    39,    40,
      13,    14,    13,    14,    87,   237,    13,    14,    59,    68,
      69,    70,    71,    72,   509,    13,    14,   453,   454,   251,
     237,    63,    64,   100,    15,    15,    15,    15,    82,    57,
      89,    81,    14,   265,   266,   267,   268,   269,   153,    13,
     146,    14,    13,    13,   276,   265,   266,   267,   268,   269,
      14,    13,   547,   147,    81,   148,   276,   534,   149,   118,
     150,   556,   121,   295,   296,   297,   298,   299,   300,   151,
     302,   303,   304,   305,   306,   154,   308,   309,   310,   155,
      72,   156,   126,   157,    81,    72,    72,   319,    72,    72,
     127,   308,   309,   310,   326,   327,    72,    72,    58,   319,
     332,    82,    58,    72,    72,    72,    72,    72,     5,   326,
     327,     5,   332,   258,   359,   365,   362,   349,   431,    82,
     480,   421,   549,   494,   422,   500,    -1,    -1,    -1,   349,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   198,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,   391,
     392,    -1,    -1,    -1,    -1,    -1,   398,   399,    -1,    -1,
     390,   391,   392,    -1,   406,   407,    -1,    -1,   237,    -1,
      -1,   398,   399,    -1,    -1,    -1,   406,   407,    -1,   421,
     422,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   265,   266,   267,   268,
     269,    -1,    -1,    -1,    -1,    -1,    -1,   276,    -1,    -1,
      -1,   453,   454,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   453,   454,    -1,   295,   296,   297,   298,
     299,   300,    -1,   302,   303,   304,   305,   306,    -1,   308,
     309,   310,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     319,    -1,    -1,    -1,    -1,    -1,    -1,   326,   327,    -1,
      -1,    -1,    -1,   332,    -1,    -1,    -1,   509,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   547,    -1,   549,    -1,    -1,
      -1,   553,    -1,    -1,   556,    -1,    -1,    -1,    -1,    -1,
     562,   390,   391,   392,    -1,    -1,   553,    -1,    -1,   398,
     399,    -1,   562,    -1,    13,    14,    15,   406,   407,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,
      -1,    -1,   421,   422,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    -1,    55,    56,    57,    58,
      59,    60,    -1,    -1,   453,   454,    65,    66,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,    88,
      -1,    -1,    -1,    -1,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,   115,    -1,    -1,    -1,
     509,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   547,    -1,
     549,    -1,    -1,    -1,   553,    -1,    -1,   556,    -1,    -1,
      -1,    -1,    -1,   562,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   231,   232,    -1,    -1,    -1,    -1,    -1,    -1,
     239,   240,   241,   242,   243,    -1,    -1,    -1,   247,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   272,   273,   274,   275,    -1,   277,   278,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   313,    -1,    -1,    -1,   317,   318,
      -1,   320,   321,   322,   323,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   338,
     339,   340,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   393,    -1,   395,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   408,
      -1,    -1,   411,    -1,    -1,    -1,   415,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   446,   447,    -1,
     449,    -1,   451,   452,    -1,    -1,    -1,    -1,    -1,   458,
     459,   460,   461,     3,     4,    -1,    -1,   466,    -1,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,    -1,
      -1,    -1,    -1,    -1,   523,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    98,    99,
      -1,    -1,    -1,    -1,    -1,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,   122,   123,   124,    -1,    -1,    -1,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,   162,   163,     3,     4,   166,   167,    -1,    -1,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,    78,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,   122,   123,   124,    -1,    -1,    -1,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,   162,   163,    -1,    -1,   166,   167,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,    78,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,   122,   123,   124,    -1,    -1,    -1,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,   162,   163,    -1,    -1,   166,   167,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,    78,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,   122,   123,   124,    -1,    -1,    -1,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,   162,   163,    -1,    -1,   166,   167,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,    78,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,   122,   123,   124,    -1,    -1,    -1,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,   162,   163,    -1,    -1,   166,   167,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,    78,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,   122,   123,   124,    -1,    -1,    -1,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,   162,   163,    -1,    -1,   166,   167,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
      -1,    -1,   102,    -1,    -1,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,   122,   123,   124,    -1,    -1,    -1,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,   162,   163,    -1,    -1,   166,   167,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    78,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,    -1,
      -1,   102,    -1,    -1,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,   122,   123,   124,    -1,    -1,    -1,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,   162,   163,    -1,    -1,   166,   167,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,    -1,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    99,    -1,    -1,
      -1,    -1,    -1,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,    -1,    -1,    -1,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
     162,   163,    -1,    -1,   166,   167,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    75,    76,    77,    78,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,   122,
     123,   124,    -1,    -1,    -1,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   159,   160,   161,   162,
     163,    -1,   165,   166,   167,     9,    10,    11,    12,    13,
      14,    15,    -1,    17,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      74,    75,    76,    77,    78,    79,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,   122,   123,
     124,    -1,    -1,    -1,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,   162,   163,
      -1,   165,   166,   167,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,
      75,    76,    77,    78,    79,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,   122,   123,   124,
      -1,    -1,    -1,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,   162,   163,    -1,
      -1,   166,   167,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,   122,   123,   124,    -1,
      -1,    -1,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,   162,   163,    -1,    -1,
     166,   167,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,
      77,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    98,    99,    -1,    -1,   102,    -1,    -1,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    -1,   122,   123,   124,    -1,    -1,
      -1,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   159,   160,   161,   162,   163,    -1,    -1,   166,
     167,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,
      78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,   122,   123,   124,    -1,    -1,    -1,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,   162,   163,    -1,    -1,   166,   167,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,    78,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,   122,   123,   124,    -1,    -1,    -1,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,   162,   163,    -1,    -1,   166,   167,     9,
      10,    11,    12,    -1,    -1,    15,    -1,    17,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    98,    99,
      -1,    -1,    -1,    -1,    -1,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,   122,   123,   124,    -1,    -1,    -1,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,   162,   163,   164,    -1,   166,   167,     9,    10,
      11,    12,    -1,    -1,    15,    -1,    17,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    78,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    98,    99,    -1,
      -1,    -1,    -1,    -1,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,   122,   123,   124,    -1,    -1,    -1,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,   162,   163,   164,    -1,   166,   167,     9,    10,    11,
      12,    -1,    -1,    15,    -1,    17,    -1,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    99,   100,    -1,
      -1,    -1,    -1,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
     122,   123,   124,    -1,    -1,    -1,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
     162,   163,    -1,    -1,   166,   167,     9,    10,    11,    12,
      13,    -1,    15,    -1,    17,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    75,    76,    77,    78,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,   122,
     123,   124,    -1,    -1,    -1,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   159,   160,   161,   162,
     163,    -1,    -1,   166,   167,     9,    10,    11,    12,    -1,
      -1,    15,    -1,    17,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      74,    75,    76,    77,    78,    79,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    99,   100,    -1,    -1,    -1,
      -1,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,   122,   123,
     124,    -1,    -1,    -1,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,   162,   163,
      -1,    -1,   166,   167,     9,    10,    11,    12,    -1,    -1,
      15,    -1,    17,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,
      75,    76,    77,    78,    79,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    98,    99,   100,    -1,    -1,    -1,    -1,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,   122,   123,   124,
      -1,    -1,    -1,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,   162,   163,    -1,
      -1,   166,   167,     9,    10,    11,    12,    -1,    -1,    15,
      -1,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    99,   100,    -1,    -1,    -1,    -1,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,   122,   123,   124,    -1,
      -1,    -1,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,   162,   163,    -1,    -1,
     166,   167,     9,    10,    11,    12,    -1,    -1,    15,    -1,
      17,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,
      77,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    98,    99,    -1,    -1,    -1,    -1,    -1,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    -1,   122,   123,   124,    -1,    -1,
      -1,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   159,   160,   161,   162,   163,    -1,    -1,   166,
     167,     9,    10,    11,    12,    -1,    -1,    15,    -1,    17,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,
      78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,   122,   123,   124,    -1,    -1,    -1,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,   162,   163,    -1,    -1,   166,   167
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     5,     6,     7,   170,   171,   172,   173,     8,     9,
      10,    11,    12,    13,    14,    15,    17,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    58,    73,    74,    75,    76,    77,
      78,    79,    80,    88,    89,    90,    91,    92,    94,    95,
      96,    97,    98,    99,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     122,   123,   124,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     158,   159,   160,   161,   162,   163,   166,   167,   174,   175,
     176,   177,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   215,   218,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   261,   262,     8,   174,     0,
     172,   173,   176,   184,   186,   176,   174,   176,    38,    39,
      40,    39,    40,    41,    39,    40,    41,    39,    40,    41,
      39,    40,    41,    39,    40,    39,    40,    39,    40,    39,
      40,   176,   176,   100,   100,   100,   100,   164,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,    15,
     116,    15,   176,   176,   176,   176,   176,   176,    81,    81,
      81,    81,   176,   176,   176,   174,   174,   174,   174,   174,
     100,   176,   100,   100,   100,   176,   174,    72,    72,    81,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,    58,   146,   147,   148,   149,   150,
     151,   152,   154,   155,   156,   157,    15,   176,    72,    72,
     164,   176,   100,   100,   168,     8,   175,    13,    14,   174,
      13,    14,    13,    14,   160,     8,     3,     4,    16,    16,
     176,   176,   174,   176,   176,   176,   176,   176,   176,    13,
      14,    15,   233,   234,   233,   176,    61,    93,   102,   174,
     275,   276,   277,   278,   281,   211,    83,    84,    85,   213,
     214,    86,   219,   220,    87,   216,   217,   176,   176,   176,
     176,   121,   176,   176,   125,    56,    81,   275,   275,   275,
     275,   275,   275,   101,   153,   275,   275,   275,   275,   275,
     174,   174,   174,   100,   176,   100,   176,   176,     3,     4,
      18,   178,   176,   176,   176,   176,   174,   174,   165,   176,
     176,    13,   176,   233,   234,    16,    15,    15,    15,    15,
      16,    60,    59,    82,    82,   214,    82,   220,    82,   217,
      82,    81,    57,   260,   145,   145,   145,   145,   145,   145,
     153,   145,   145,   145,   145,    16,   165,   100,   176,   100,
     176,    14,    13,   174,   174,    38,    39,    41,    14,    13,
      14,    13,    16,    16,   176,   176,    13,    16,   176,   233,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   266,   267,   279,   280,   103,   104,   266,   267,
     282,   283,   284,   285,   276,   281,    81,   260,    57,    82,
     146,   147,   148,   149,   150,   151,   154,   155,   156,   157,
     116,   176,   176,   100,   176,   176,   176,   178,   178,   176,
     176,   176,   176,   176,    15,   116,    16,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    16,   264,    16,
     280,    72,    72,    16,   283,   126,    82,   275,   176,   233,
     275,   277,   174,    82,   275,   145,    16,    16,    81,   145,
      58,   127,    58,    82
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
        case 2:
#line 284 "itex2MML.y"
    {/* all processing done in body*/}
    break;

  case 3:
#line 287 "itex2MML.y"
    {/* nothing - do nothing*/}
    break;

  case 4:
#line 288 "itex2MML.y"
    {/* proc done in body*/}
    break;

  case 5:
#line 289 "itex2MML.y"
    {/* all proc. in body*/}
    break;

  case 6:
#line 290 "itex2MML.y"
    {/* all proc. in body*/}
    break;

  case 7:
#line 291 "itex2MML.y"
    {/* all proc. in body*/}
    break;

  case 8:
#line 293 "itex2MML.y"
    {printf("%s", (yyvsp[(1) - (1)]));}
    break;

  case 9:
#line 295 "itex2MML.y"
    {/* empty math group - ignore*/}
    break;

  case 10:
#line 296 "itex2MML.y"
    {/* ditto */}
    break;

  case 11:
#line 297 "itex2MML.y"
    {
  char ** r = (char **) ret_str;
  char * p = itex2MML_copy3("<math xmlns='http://www.w3.org/1998/Math/MathML' display='inline'><semantics><mrow>", (yyvsp[(2) - (3)]), "</mrow><annotation encoding='application/x-tex'>");
  char * s = itex2MML_copy3(p, (yyvsp[(3) - (3)]), "</annotation></semantics></math>");
  itex2MML_free_string(p);
  itex2MML_free_string((yyvsp[(2) - (3)]));  
  itex2MML_free_string((yyvsp[(3) - (3)]));
  if (r) {
    (*r) = (s == itex2MML_empty_string) ? 0 : s;
  }
  else {
    if (itex2MML_write_mathml)
      (*itex2MML_write_mathml) (s);
    itex2MML_free_string(s);
  }
}
    break;

  case 12:
#line 313 "itex2MML.y"
    {
  char ** r = (char **) ret_str;
  char * p = itex2MML_copy3("<math xmlns='http://www.w3.org/1998/Math/MathML' display='block'><semantics><mrow>", (yyvsp[(2) - (3)]), "</mrow><annotation encoding='application/x-tex'>");
  char * s = itex2MML_copy3(p, (yyvsp[(3) - (3)]), "</annotation></semantics></math>");
  itex2MML_free_string(p);
  itex2MML_free_string((yyvsp[(2) - (3)]));  
  itex2MML_free_string((yyvsp[(3) - (3)]));
  if (r) {
    (*r) = (s == itex2MML_empty_string) ? 0 : s;
  }
  else {
    if (itex2MML_write_mathml)
      (*itex2MML_write_mathml) (s);
    itex2MML_free_string(s);
  }
}
    break;

  case 13:
#line 330 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 14:
#line 334 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(1) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 15:
#line 340 "itex2MML.y"
    {
  if (itex2MML_displaymode == 1) {
    char * s1 = itex2MML_copy3("<munderover>", (yyvsp[(1) - (5)]), " ");
    char * s2 = itex2MML_copy3((yyvsp[(3) - (5)]), " ", (yyvsp[(5) - (5)]));
    (yyval) = itex2MML_copy3(s1, s2, "</munderover>");
    itex2MML_free_string(s1);
    itex2MML_free_string(s2);
  }
  else {
    char * s1 = itex2MML_copy3("<msubsup>", (yyvsp[(1) - (5)]), " ");
    char * s2 = itex2MML_copy3((yyvsp[(3) - (5)]), " ", (yyvsp[(5) - (5)]));
    (yyval) = itex2MML_copy3(s1, s2, "</msubsup>");
    itex2MML_free_string(s1);
    itex2MML_free_string(s2);
  }
  itex2MML_free_string((yyvsp[(1) - (5)]));
  itex2MML_free_string((yyvsp[(3) - (5)]));
  itex2MML_free_string((yyvsp[(5) - (5)]));
}
    break;

  case 16:
#line 359 "itex2MML.y"
    {
  if (itex2MML_displaymode == 1) {
    char * s1 = itex2MML_copy3("<munder>", (yyvsp[(1) - (3)]), " ");
    (yyval) = itex2MML_copy3(s1, (yyvsp[(3) - (3)]), "</munder>");
    itex2MML_free_string(s1);
  }
  else {
    char * s1 = itex2MML_copy3("<msub>", (yyvsp[(1) - (3)]), " ");
    (yyval) = itex2MML_copy3(s1, (yyvsp[(3) - (3)]), "</msub>");
    itex2MML_free_string(s1);
  }
  itex2MML_free_string((yyvsp[(1) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 17:
#line 373 "itex2MML.y"
    {
  if (itex2MML_displaymode == 1) {
    char * s1 = itex2MML_copy3("<munderover>", (yyvsp[(1) - (5)]), " ");
    char * s2 = itex2MML_copy3((yyvsp[(5) - (5)]), " ", (yyvsp[(3) - (5)]));
    (yyval) = itex2MML_copy3(s1, s2, "</munderover>");
    itex2MML_free_string(s1);
    itex2MML_free_string(s2);
  }
  else {
    char * s1 = itex2MML_copy3("<msubsup>", (yyvsp[(1) - (5)]), " ");
    char * s2 = itex2MML_copy3((yyvsp[(5) - (5)]), " ", (yyvsp[(3) - (5)]));
    (yyval) = itex2MML_copy3(s1, s2, "</msubsup>");
    itex2MML_free_string(s1);
    itex2MML_free_string(s2);
  }
  itex2MML_free_string((yyvsp[(1) - (5)]));
  itex2MML_free_string((yyvsp[(3) - (5)]));
  itex2MML_free_string((yyvsp[(5) - (5)]));
}
    break;

  case 18:
#line 392 "itex2MML.y"
    {
  if (itex2MML_displaymode == 1) {
    char * s1 = itex2MML_copy3("<mover>", (yyvsp[(1) - (3)]), " ");
    (yyval) = itex2MML_copy3(s1, (yyvsp[(3) - (3)]), "</mover>");
    itex2MML_free_string(s1);
  }
  else {
    char * s1 = itex2MML_copy3("<msup>", (yyvsp[(1) - (3)]), " ");
    (yyval) = itex2MML_copy3(s1, (yyvsp[(3) - (3)]), "</msup>");
    itex2MML_free_string(s1);
  }
  itex2MML_free_string((yyvsp[(1) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 19:
#line 406 "itex2MML.y"
    {
  if (itex2MML_displaymode == 1) {
    char * s1 = itex2MML_copy3("<munderover>", (yyvsp[(1) - (5)]), " ");
    char * s2 = itex2MML_copy3((yyvsp[(3) - (5)]), " ", (yyvsp[(5) - (5)]));
    (yyval) = itex2MML_copy3(s1, s2, "</munderover>");
    itex2MML_free_string(s1);
    itex2MML_free_string(s2);
  }
  else {
    char * s1 = itex2MML_copy3("<msubsup>", (yyvsp[(1) - (5)]), " ");
    char * s2 = itex2MML_copy3((yyvsp[(3) - (5)]), " ", (yyvsp[(5) - (5)]));
    (yyval) = itex2MML_copy3(s1, s2, "</msubsup>");
    itex2MML_free_string(s1);
    itex2MML_free_string(s2);
  }
  itex2MML_free_string((yyvsp[(1) - (5)]));
  itex2MML_free_string((yyvsp[(3) - (5)]));
  itex2MML_free_string((yyvsp[(5) - (5)]));
}
    break;

  case 20:
#line 425 "itex2MML.y"
    {
  if (itex2MML_displaymode == 1) {
    char * s1 = itex2MML_copy3("<munder>", (yyvsp[(1) - (3)]), " ");
    (yyval) = itex2MML_copy3(s1, (yyvsp[(3) - (3)]), "</munder>");
    itex2MML_free_string(s1);
  }
  else {
    char * s1 = itex2MML_copy3("<msub>", (yyvsp[(1) - (3)]), " ");
    (yyval) = itex2MML_copy3(s1, (yyvsp[(3) - (3)]), "</msub>");
    itex2MML_free_string(s1);
  }
  itex2MML_free_string((yyvsp[(1) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 21:
#line 439 "itex2MML.y"
    {
  if (itex2MML_displaymode == 1) {
    char * s1 = itex2MML_copy3("<munderover>", (yyvsp[(1) - (5)]), " ");
    char * s2 = itex2MML_copy3((yyvsp[(5) - (5)]), " ", (yyvsp[(3) - (5)]));
    (yyval) = itex2MML_copy3(s1, s2, "</munderover>");
    itex2MML_free_string(s1);
    itex2MML_free_string(s2);
  }
  else {
    char * s1 = itex2MML_copy3("<msubsup>", (yyvsp[(1) - (5)]), " ");
    char * s2 = itex2MML_copy3((yyvsp[(5) - (5)]), " ", (yyvsp[(3) - (5)]));
    (yyval) = itex2MML_copy3(s1, s2, "</msubsup>");
    itex2MML_free_string(s1);
    itex2MML_free_string(s2);
  }
  itex2MML_free_string((yyvsp[(1) - (5)]));
  itex2MML_free_string((yyvsp[(3) - (5)]));
  itex2MML_free_string((yyvsp[(5) - (5)]));
}
    break;

  case 22:
#line 458 "itex2MML.y"
    {
  if (itex2MML_displaymode == 1) {
    char * s1 = itex2MML_copy3("<mover>", (yyvsp[(1) - (3)]), " ");
    (yyval) = itex2MML_copy3(s1, (yyvsp[(3) - (3)]), "</mover>");
    itex2MML_free_string(s1);
  }
  else {
    char * s1 = itex2MML_copy3("<msup>", (yyvsp[(1) - (3)]), " ");
    (yyval) = itex2MML_copy3(s1, (yyvsp[(3) - (3)]), "</msup>");
    itex2MML_free_string(s1);
  }
  itex2MML_free_string((yyvsp[(1) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 23:
#line 472 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<msubsup>", (yyvsp[(1) - (5)]), " ");
  char * s2 = itex2MML_copy3((yyvsp[(3) - (5)]), " ", (yyvsp[(5) - (5)]));
  (yyval) = itex2MML_copy3(s1, s2, "</msubsup>");
  itex2MML_free_string(s1);
  itex2MML_free_string(s2);
  itex2MML_free_string((yyvsp[(1) - (5)]));
  itex2MML_free_string((yyvsp[(3) - (5)]));
  itex2MML_free_string((yyvsp[(5) - (5)]));
}
    break;

  case 24:
#line 482 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<msubsup>", (yyvsp[(1) - (5)]), " ");
  char * s2 = itex2MML_copy3((yyvsp[(5) - (5)]), " ", (yyvsp[(3) - (5)]));
  (yyval) = itex2MML_copy3(s1, s2, "</msubsup>");
  itex2MML_free_string(s1);
  itex2MML_free_string(s2);
  itex2MML_free_string((yyvsp[(1) - (5)]));
  itex2MML_free_string((yyvsp[(3) - (5)]));
  itex2MML_free_string((yyvsp[(5) - (5)]));
}
    break;

  case 25:
#line 492 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<msub>", (yyvsp[(1) - (3)]), " ");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(3) - (3)]), "</msub>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(1) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 26:
#line 499 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<msup>", (yyvsp[(1) - (3)]), " ");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(3) - (3)]), "</msup>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(1) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 27:
#line 506 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<msub><mo/>", (yyvsp[(2) - (2)]), "</msub>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 28:
#line 510 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<msup><mo/>", (yyvsp[(2) - (2)]), "</msup>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 29:
#line 514 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 34:
#line 523 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mi>", (yyvsp[(1) - (1)]), "</mi>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 35:
#line 527 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mn>", (yyvsp[(1) - (1)]), "</mn>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 99:
#line 594 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(2) - (3)]));
}
    break;

  case 100:
#line 598 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow>", (yyvsp[(2) - (3)]), "</mrow>");
  itex2MML_free_string((yyvsp[(2) - (3)]));
}
    break;

  case 101:
#line 602 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mrow>", (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]));
  (yyval) = itex2MML_copy3(s1, (yyvsp[(3) - (3)]), "</mrow>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(1) - (3)]));
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 106:
#line 615 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo>", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 107:
#line 620 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo>", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 108:
#line 625 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy_string("");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 109:
#line 631 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo>", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 110:
#line 635 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo>", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 111:
#line 639 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 112:
#line 644 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.2em\" minsize=\"1.2em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 113:
#line 649 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.2em\" minsize=\"1.2em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 114:
#line 653 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.2em\" minsize=\"1.2em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 115:
#line 657 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.8em\" minsize=\"1.8em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 116:
#line 662 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.8em\" minsize=\"1.8em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 117:
#line 666 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.8em\" minsize=\"1.8em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 118:
#line 670 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"2.4em\" minsize=\"2.4em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 119:
#line 675 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo maxsize=\"2.4em\" minsize=\"2.4em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 120:
#line 679 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo maxsize=\"2.4em\" minsize=\"2.4em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 121:
#line 683 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"3em\" minsize=\"3em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 122:
#line 688 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo maxsize=\"3em\" minsize=\"3em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 123:
#line 692 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo maxsize=\"3em\" minsize=\"3em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 124:
#line 696 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.2em\" minsize=\"1.2em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 125:
#line 701 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.2em\" minsize=\"1.2em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 126:
#line 706 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.8em\" minsize=\"1.8em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 127:
#line 711 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.8em\" minsize=\"1.8em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 128:
#line 716 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"2.4em\" minsize=\"2.4em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 129:
#line 721 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"2.4em\" minsize=\"2.4em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 130:
#line 726 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"3em\" minsize=\"3em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 131:
#line 731 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"3em\" minsize=\"3em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 132:
#line 737 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<merror><mtext>Unknown character</mtext></merror>");
}
    break;

  case 133:
#line 741 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mo lspace=\"verythinmathspace\" rspace=\"0em\">&minus;</mo>");
}
    break;

  case 134:
#line 745 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mo lspace=\"verythinmathspace\" rspace=\"0em\">+</mo>");
}
    break;

  case 136:
#line 751 "itex2MML.y"
    {
  itex2MML_rowposn=2;
  (yyval) = itex2MML_copy3("<mi>", (yyvsp[(1) - (1)]), "</mi>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 138:
#line 758 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy_string((yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 139:
#line 764 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo lspace=\"thinmathspace\" rspace=\"thinmathspace\">", (yyvsp[(1) - (1)]), "</mo>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 142:
#line 772 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo>", (yyvsp[(1) - (1)]), "</mo>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 143:
#line 777 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo>", (yyvsp[(1) - (1)]), "</mo>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 144:
#line 782 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mstyle scriptlevel=\"0\"><mo>", (yyvsp[(1) - (1)]), "</mo></mstyle>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 145:
#line 787 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo stretchy=\"false\">", (yyvsp[(1) - (1)]), "</mo>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 146:
#line 791 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo stretchy=\"false\">", (yyvsp[(1) - (1)]), "</mo>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 147:
#line 796 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo stretchy=\"false\">", (yyvsp[(1) - (1)]), "</mo>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 148:
#line 800 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo stretchy=\"false\">", (yyvsp[(1) - (1)]), "</mo>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 149:
#line 804 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo>", (yyvsp[(1) - (1)]), "</mo>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 150:
#line 808 "itex2MML.y"
    {
  itex2MML_rowposn=2;
  (yyval) = itex2MML_copy3("<mo lspace=\"mediummathspace\" rspace=\"mediummathspace\">", (yyvsp[(1) - (1)]), "</mo>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 151:
#line 813 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo lspace=\"0em\" rspace=\"thinmathspace\">", (yyvsp[(1) - (1)]), "</mo>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 152:
#line 818 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo lspace=\"verythinmathspace\">", (yyvsp[(1) - (1)]), "</mo>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 153:
#line 823 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo lspace=\"0em\" rspace=\"thinmathspace\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 154:
#line 828 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo lspace=\"thinmathspace\" rspace=\"thinmathspace\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 155:
#line 833 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo lspace=\"mediummathspace\" rspace=\"mediummathspace\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 156:
#line 838 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo lspace=\"thickmathspace\" rspace=\"thickmathspace\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 157:
#line 844 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mspace height=\"", (yyvsp[(3) - (10)]), "ex\" depth=\"");
  char * s2 = itex2MML_copy3((yyvsp[(6) - (10)]), "ex\" width=\"", (yyvsp[(9) - (10)]));
  (yyval) = itex2MML_copy3(s1, s2, "em\"/>");
  itex2MML_free_string(s1);
  itex2MML_free_string(s2);
  itex2MML_free_string((yyvsp[(3) - (10)]));
  itex2MML_free_string((yyvsp[(6) - (10)]));
  itex2MML_free_string((yyvsp[(9) - (10)]));
}
    break;

  case 158:
#line 855 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<maction actiontype=\"statusline\">", (yyvsp[(3) - (3)]), "<mtext>");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(2) - (3)]), "</mtext></maction>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 159:
#line 863 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<maction actiontype=\"tooltip\">", (yyvsp[(3) - (3)]), "<mtext>");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(2) - (3)]), "</mtext></maction>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 160:
#line 871 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<maction actiontype=\"toggle\" selection=\"2\">", (yyvsp[(2) - (3)]), " ");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(3) - (3)]), "</maction>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 161:
#line 878 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<maction actiontype=\"toggle\">", (yyvsp[(2) - (3)]), "</maction>");
  itex2MML_free_string((yyvsp[(2) - (3)]));
}
    break;

  case 162:
#line 883 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<maction actiontype=\"highlight\" other='color=", (yyvsp[(2) - (3)]), "'>");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(3) - (3)]), "</maction>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 163:
#line 891 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<maction actiontype=\"highlight\" other='background=", (yyvsp[(2) - (3)]), "'>");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(3) - (3)]), "</maction>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 164:
#line 899 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mstyle mathcolor=", (yyvsp[(2) - (3)]), ">");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(3) - (3)]), "</mstyle>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 165:
#line 906 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mstyle mathbackground=", (yyvsp[(2) - (3)]), ">");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(3) - (3)]), "</mstyle>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 166:
#line 914 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mpadded width=\"0\">", (yyvsp[(2) - (2)]), "</mpadded>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 167:
#line 919 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mpadded width=\"0\" lspace=\"-100%width\">", (yyvsp[(2) - (2)]), "</mpadded>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 168:
#line 924 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mpadded width=\"0\" lspace=\"-50%width\">", (yyvsp[(2) - (2)]), "</mpadded>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 169:
#line 929 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mtext>", (yyvsp[(2) - (2)]), "</mtext>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 170:
#line 934 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mstyle displaystyle=\"true\">", (yyvsp[(2) - (2)]), "</mstyle>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 171:
#line 939 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mstyle displaystyle=\"false\">", (yyvsp[(2) - (2)]), "</mstyle>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 172:
#line 944 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mstyle scriptlevel=\"0\">", (yyvsp[(2) - (2)]), "</mstyle>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 173:
#line 949 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mstyle scriptlevel=\"1\">", (yyvsp[(2) - (2)]), "</mstyle>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 174:
#line 954 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mstyle scriptlevel=\"2\">", (yyvsp[(2) - (2)]), "</mstyle>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 175:
#line 959 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mstyle mathvariant=\"italic\">", (yyvsp[(2) - (2)]), "</mstyle>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 176:
#line 964 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mstyle mathvariant=\"sans-serif\">", (yyvsp[(2) - (2)]), "</mstyle>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 177:
#line 969 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mstyle mathvariant=\"monospace\">", (yyvsp[(2) - (2)]), "</mstyle>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 178:
#line 974 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<menclose notation=\"updiagonalstrike\">", (yyvsp[(2) - (2)]), "</menclose>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 179:
#line 979 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<menclose notation=\"box\">", (yyvsp[(2) - (2)]), "</menclose>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 180:
#line 984 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mstyle mathvariant=\"bold\">", (yyvsp[(2) - (2)]), "</mstyle>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 181:
#line 989 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mi mathvariant=\"normal\">", (yyvsp[(3) - (4)]), "</mi>");
  itex2MML_free_string((yyvsp[(3) - (4)]));
}
    break;

  case 182:
#line 994 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 183:
#line 998 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(1) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 184:
#line 1004 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mi>", (yyvsp[(3) - (4)]), "</mi>");
  itex2MML_free_string((yyvsp[(3) - (4)]));
}
    break;

  case 185:
#line 1009 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 186:
#line 1013 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(1) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 187:
#line 1019 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("&", (yyvsp[(1) - (1)]), "opf;");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 188:
#line 1023 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("&", (yyvsp[(1) - (1)]), "opf;");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 189:
#line 1027 "itex2MML.y"
    {
  /* Blackboard digits 0-9 correspond to Unicode characters 0x1D7D8-0x1D7E1 */
  char * end = (yyvsp[(1) - (1)]) + 1;
  int code = 0x1D7D8 + strtoul((yyvsp[(1) - (1)]), &end, 10);
  (yyval) = itex2MML_character_reference(code);
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 190:
#line 1035 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mi>", (yyvsp[(3) - (4)]), "</mi>");
  itex2MML_free_string((yyvsp[(3) - (4)]));
}
    break;

  case 191:
#line 1040 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 192:
#line 1044 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(1) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 193:
#line 1050 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("&", (yyvsp[(1) - (1)]), "fr;");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 194:
#line 1055 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mi>", (yyvsp[(3) - (4)]), "</mi>");
  itex2MML_free_string((yyvsp[(3) - (4)]));
}
    break;

  case 195:
#line 1060 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 196:
#line 1064 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(1) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 197:
#line 1070 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("&", (yyvsp[(1) - (1)]), "scr;");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 198:
#line 1075 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mspace width=\"thinmathspace\"/>");
}
    break;

  case 199:
#line 1079 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mspace width=\"mediummathspace\"/>");
}
    break;

  case 200:
#line 1083 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mspace width=\"thickmathspace\"/>");
}
    break;

  case 201:
#line 1087 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mspace width=\"1em\"/>");
}
    break;

  case 202:
#line 1091 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mspace width=\"2em\"/>");
}
    break;

  case 203:
#line 1095 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mspace width=\"negativethinmathspace\"/>");
}
    break;

  case 204:
#line 1099 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mspace width=\"negativemediummathspace\"/>");
}
    break;

  case 205:
#line 1103 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mspace width=\"negativethickmathspace\"/>");
}
    break;

  case 206:
#line 1107 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mphantom>", (yyvsp[(2) - (2)]), "</mphantom>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 207:
#line 1112 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mrow href=\"", (yyvsp[(2) - (3)]), "\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" xlink:type=\"simple\" xlink:href=\"");
  char * s2 = itex2MML_copy3(s1, (yyvsp[(2) - (3)]), "\">");
  (yyval) = itex2MML_copy3(s2, (yyvsp[(3) - (3)]), "</mrow>");
  itex2MML_free_string(s1);
  itex2MML_free_string(s2);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 208:
#line 1122 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mmultiscripts>", (yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
  (yyval) = itex2MML_copy2(s1, "</mmultiscripts>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (5)]));
  itex2MML_free_string((yyvsp[(4) - (5)]));
}
    break;

  case 209:
#line 1129 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mmultiscripts>", (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  (yyval) = itex2MML_copy2(s1, "</mmultiscripts>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 210:
#line 1137 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mmultiscripts>", (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
  char * s2 = itex2MML_copy3("<mprescripts/>", (yyvsp[(3) - (8)]), "</mmultiscripts>");
  (yyval) = itex2MML_copy2(s1, s2);
  itex2MML_free_string(s1);
  itex2MML_free_string(s2);
  itex2MML_free_string((yyvsp[(3) - (8)]));
  itex2MML_free_string((yyvsp[(5) - (8)]));
  itex2MML_free_string((yyvsp[(7) - (8)]));
}
    break;

  case 211:
#line 1147 "itex2MML.y"
    {
  char * s1 = itex2MML_copy2("<mmultiscripts>", (yyvsp[(5) - (6)]));
  char * s2 = itex2MML_copy3("<mprescripts/>", (yyvsp[(3) - (6)]), "</mmultiscripts>");
  (yyval) = itex2MML_copy2(s1, s2);
  itex2MML_free_string(s1);
  itex2MML_free_string(s2);
  itex2MML_free_string((yyvsp[(3) - (6)]));
  itex2MML_free_string((yyvsp[(5) - (6)]));
}
    break;

  case 212:
#line 1156 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mmultiscripts>", (yyvsp[(3) - (6)]), (yyvsp[(5) - (6)]));
  (yyval) = itex2MML_copy2(s1, "</mmultiscripts>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(3) - (6)]));
  itex2MML_free_string((yyvsp[(5) - (6)])); 
}
    break;

  case 213:
#line 1164 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 214:
#line 1168 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3((yyvsp[(1) - (2)]), " ", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(1) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 215:
#line 1174 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3((yyvsp[(2) - (4)]), " ", (yyvsp[(4) - (4)]));
  itex2MML_free_string((yyvsp[(2) - (4)]));
  itex2MML_free_string((yyvsp[(4) - (4)]));
}
    break;

  case 216:
#line 1179 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2((yyvsp[(2) - (2)]), " <none/>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 217:
#line 1183 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("<none/> ", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 218:
#line 1187 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("<none/> ", (yyvsp[(3) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 219:
#line 1192 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mfrac>", (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  (yyval) = itex2MML_copy2(s1, "</mfrac>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 220:
#line 1199 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mstyle displaystyle=\"false\"><mfrac>", (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  (yyval) = itex2MML_copy2(s1, "</mfrac></mstyle>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 221:
#line 1207 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3( "<mrow><mo lspace=\"mediummathspace\">(</mo><mo rspace=\"thinmathspace\">mod</mo>", (yyvsp[(2) - (2)]), "<mo rspace=\"mediummathspace\">)</mo></mrow>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 222:
#line 1212 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mfrac><mrow>", (yyvsp[(2) - (5)]), "</mrow><mrow>");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(4) - (5)]), "</mrow></mfrac>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (5)]));
  itex2MML_free_string((yyvsp[(4) - (5)]));
}
    break;

  case 223:
#line 1219 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mrow>", (yyvsp[(1) - (5)]), "<mfrac><mrow>");
  char * s2 = itex2MML_copy3((yyvsp[(2) - (5)]), "</mrow><mrow>", (yyvsp[(4) - (5)]));
  char * s3 = itex2MML_copy3("</mrow></mfrac>", (yyvsp[(5) - (5)]), "</mrow>");
  (yyval) = itex2MML_copy3(s1, s2, s3);
  itex2MML_free_string(s1);
  itex2MML_free_string(s2);
  itex2MML_free_string(s3);
  itex2MML_free_string((yyvsp[(1) - (5)]));
  itex2MML_free_string((yyvsp[(2) - (5)]));
  itex2MML_free_string((yyvsp[(4) - (5)]));
  itex2MML_free_string((yyvsp[(5) - (5)]));
}
    break;

  case 224:
#line 1233 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mfrac linethickness=\"0\"><mrow>", (yyvsp[(2) - (5)]), "</mrow><mrow>");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(4) - (5)]), "</mrow></mfrac>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (5)]));
  itex2MML_free_string((yyvsp[(4) - (5)]));
}
    break;

  case 225:
#line 1240 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mrow>", (yyvsp[(1) - (5)]), "<mfrac linethickness=\"0\"><mrow>");
  char * s2 = itex2MML_copy3((yyvsp[(2) - (5)]), "</mrow><mrow>", (yyvsp[(4) - (5)]));
  char * s3 = itex2MML_copy3("</mrow></mfrac>", (yyvsp[(5) - (5)]), "</mrow>");
  (yyval) = itex2MML_copy3(s1, s2, s3);
  itex2MML_free_string(s1);
  itex2MML_free_string(s2);
  itex2MML_free_string(s3);
  itex2MML_free_string((yyvsp[(1) - (5)]));
  itex2MML_free_string((yyvsp[(2) - (5)]));
  itex2MML_free_string((yyvsp[(4) - (5)]));
  itex2MML_free_string((yyvsp[(5) - (5)]));
}
    break;

  case 226:
#line 1254 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mrow><mo>(</mo><mfrac linethickness=\"0\">", (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  (yyval) = itex2MML_copy2(s1, "</mfrac><mo>)</mo></mrow>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 227:
#line 1261 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mrow><mo>(</mo><mstyle displaystyle=\"false\"><mfrac linethickness=\"0\">", (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  (yyval) = itex2MML_copy2(s1, "</mfrac></mstyle><mo>)</mo></mrow>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 228:
#line 1269 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<munder>", (yyvsp[(2) - (2)]), "<mo>&UnderBrace;</mo></munder>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 229:
#line 1274 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<munder>", (yyvsp[(2) - (2)]), "<mo>&#x00332;</mo></munder>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 230:
#line 1279 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo>&OverBrace;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 231:
#line 1284 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo stretchy=\"false\">&#x000AF;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 232:
#line 1288 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo>&#x000AF;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 233:
#line 1293 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo stretchy=\"false\">&RightVector;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 234:
#line 1297 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo>&RightVector;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 235:
#line 1302 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo>&dot;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 236:
#line 1307 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo>&Dot;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 237:
#line 1312 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo>&tdot;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 238:
#line 1317 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo>&DotDot;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 239:
#line 1322 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo stretchy=\"false\">&tilde;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 240:
#line 1326 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo>&tilde;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 241:
#line 1331 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo stretchy=\"false\">&#x2c7;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 242:
#line 1335 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo>&#x2c7;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 243:
#line 1340 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo stretchy=\"false\">&#x5E;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 244:
#line 1344 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo>&#x5E;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 245:
#line 1349 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<msqrt>", (yyvsp[(2) - (2)]), "</msqrt>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 246:
#line 1354 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mroot>", (yyvsp[(5) - (5)]), (yyvsp[(3) - (5)]));
  (yyval) = itex2MML_copy2(s1, "</mroot>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(3) - (5)]));
  itex2MML_free_string((yyvsp[(5) - (5)]));
}
    break;

  case 247:
#line 1361 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mroot>", (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]));
  (yyval) = itex2MML_copy2(s1, "</mroot>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 248:
#line 1369 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mpadded voffset='", (yyvsp[(2) - (5)]), "' height='");
  char * s2 = itex2MML_copy3(s1, (yyvsp[(3) - (5)]), "' depth='");
  char * s3 = itex2MML_copy3(s2, (yyvsp[(4) - (5)]), "'>");
  (yyval) = itex2MML_copy3(s3, (yyvsp[(5) - (5)]), "</mpadded>");
  itex2MML_free_string(s1);
  itex2MML_free_string(s2);
  itex2MML_free_string(s3);
  itex2MML_free_string((yyvsp[(2) - (5)]));
  itex2MML_free_string((yyvsp[(3) - (5)]));
  itex2MML_free_string((yyvsp[(4) - (5)]));
  itex2MML_free_string((yyvsp[(5) - (5)]));
}
    break;

  case 249:
#line 1382 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mpadded voffset='-", (yyvsp[(3) - (6)]), "' height='");
  char * s2 = itex2MML_copy3(s1, (yyvsp[(4) - (6)]), "' depth='");
  char * s3 = itex2MML_copy3(s2, (yyvsp[(5) - (6)]), "'>");
  (yyval) = itex2MML_copy3(s3, (yyvsp[(6) - (6)]), "</mpadded>");
  itex2MML_free_string(s1);
  itex2MML_free_string(s2);
  itex2MML_free_string(s3);
  itex2MML_free_string((yyvsp[(3) - (6)]));
  itex2MML_free_string((yyvsp[(4) - (6)]));
  itex2MML_free_string((yyvsp[(5) - (6)]));
  itex2MML_free_string((yyvsp[(6) - (6)]));
}
    break;

  case 250:
#line 1395 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mpadded voffset='", (yyvsp[(2) - (4)]), "' height='");
  char * s2 = itex2MML_copy3(s1, (yyvsp[(3) - (4)]), "' depth='depth'>");
  (yyval) = itex2MML_copy3(s2, (yyvsp[(4) - (4)]), "</mpadded>");
  itex2MML_free_string(s1);
  itex2MML_free_string(s2);
  itex2MML_free_string((yyvsp[(2) - (4)]));
  itex2MML_free_string((yyvsp[(3) - (4)]));
  itex2MML_free_string((yyvsp[(4) - (4)]));
}
    break;

  case 251:
#line 1405 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mpadded voffset='-", (yyvsp[(3) - (5)]), "' height='");
  char * s2 = itex2MML_copy3(s1, (yyvsp[(4) - (5)]), "' depth='+");
  char * s3 = itex2MML_copy3(s2, (yyvsp[(3) - (5)]), "'>");
  (yyval) = itex2MML_copy3(s3, (yyvsp[(5) - (5)]), "</mpadded>");
  itex2MML_free_string(s1);
  itex2MML_free_string(s2);
  itex2MML_free_string(s3);
  itex2MML_free_string((yyvsp[(3) - (5)]));
  itex2MML_free_string((yyvsp[(4) - (5)]));
  itex2MML_free_string((yyvsp[(5) - (5)]));
}
    break;

  case 252:
#line 1417 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mpadded voffset='", (yyvsp[(2) - (3)]), "' height='+");
  char * s2 = itex2MML_copy3(s1, (yyvsp[(2) - (3)]), "' depth='depth'>");
  (yyval) = itex2MML_copy3(s2, (yyvsp[(3) - (3)]), "</mpadded>");
  itex2MML_free_string(s1);
  itex2MML_free_string(s2);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 253:
#line 1426 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mpadded voffset='-", (yyvsp[(3) - (4)]), "' height='0pt' depth='+");
  char * s2 = itex2MML_copy3(s1, (yyvsp[(3) - (4)]), "'>");
  (yyval) = itex2MML_copy3(s2, (yyvsp[(4) - (4)]), "</mpadded>");
  itex2MML_free_string(s1);
  itex2MML_free_string(s2);
  itex2MML_free_string((yyvsp[(3) - (4)]));
  itex2MML_free_string((yyvsp[(4) - (4)]));
}
    break;

  case 254:
#line 1436 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<munder><mo>", (yyvsp[(1) - (5)]), "</mo><mrow>");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(3) - (5)]), "</mrow></munder>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(1) - (5)]));
  itex2MML_free_string((yyvsp[(3) - (5)]));
}
    break;

  case 255:
#line 1443 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<munder>", (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]));
  (yyval) = itex2MML_copy2(s1, "</munder>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 256:
#line 1451 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mover><mo>", (yyvsp[(1) - (2)]), "</mo>");
  (yyval) =  itex2MML_copy3(s1, (yyvsp[(2) - (2)]), "</mover>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(1) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 257:
#line 1458 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mover>", (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]));
  (yyval) = itex2MML_copy2(s1, "</mover>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 258:
#line 1466 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<munderover><mo>", (yyvsp[(1) - (5)]), "</mo><mrow>");
  char * s2 = itex2MML_copy3(s1, (yyvsp[(3) - (5)]), "</mrow>");
  (yyval) = itex2MML_copy3(s2, (yyvsp[(5) - (5)]), "</munderover>");
  itex2MML_free_string(s1);
  itex2MML_free_string(s2);
  itex2MML_free_string((yyvsp[(1) - (5)]));
  itex2MML_free_string((yyvsp[(3) - (5)]));
  itex2MML_free_string((yyvsp[(5) - (5)]));
}
    break;

  case 259:
#line 1476 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<munderover>", (yyvsp[(4) - (4)]), (yyvsp[(2) - (4)]));
  (yyval) = itex2MML_copy3(s1, (yyvsp[(3) - (4)]), "</munderover>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (4)]));
  itex2MML_free_string((yyvsp[(3) - (4)]));
  itex2MML_free_string((yyvsp[(4) - (4)]));
}
    break;

  case 260:
#line 1485 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mrow/>");
}
    break;

  case 261:
#line 1489 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mtable rowspacing=\"0.5ex\">", (yyvsp[(3) - (5)]), "</mtable></mrow>");
  itex2MML_free_string((yyvsp[(3) - (5)]));
}
    break;

  case 262:
#line 1493 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mtable rowspacing=\"1.0ex\">", (yyvsp[(3) - (5)]), "</mtable></mrow>");
  itex2MML_free_string((yyvsp[(3) - (5)]));
}
    break;

  case 263:
#line 1497 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mo>(</mo><mrow><mtable rowspacing=\"0.5ex\">", (yyvsp[(3) - (5)]), "</mtable></mrow><mo>)</mo></mrow>");
  itex2MML_free_string((yyvsp[(3) - (5)]));
}
    break;

  case 264:
#line 1501 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mo>[</mo><mrow><mtable rowspacing=\"0.5ex\">", (yyvsp[(3) - (5)]), "</mtable></mrow><mo>]</mo></mrow>");
  itex2MML_free_string((yyvsp[(3) - (5)]));
}
    break;

  case 265:
#line 1505 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mo>&VerticalBar;</mo><mrow><mtable rowspacing=\"0.5ex\">", (yyvsp[(3) - (5)]), "</mtable></mrow><mo>&VerticalBar;</mo></mrow>");
  itex2MML_free_string((yyvsp[(3) - (5)]));
}
    break;

  case 266:
#line 1509 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mo>{</mo><mrow><mtable rowspacing=\"0.5ex\">", (yyvsp[(3) - (5)]), "</mtable></mrow><mo>}</mo></mrow>");
  itex2MML_free_string((yyvsp[(3) - (5)]));
}
    break;

  case 267:
#line 1513 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mo>&DoubleVerticalBar;</mo><mrow><mtable rowspacing=\"0.5ex\">", (yyvsp[(3) - (5)]), "</mtable></mrow><mo>&DoubleVerticalBar;</mo></mrow>");
  itex2MML_free_string((yyvsp[(3) - (5)]));
}
    break;

  case 268:
#line 1517 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mstyle scriptlevel=\"2\"><mrow><mtable rowspacing=\"0.5ex\">", (yyvsp[(3) - (5)]), "</mtable></mrow></mstyle>");
  itex2MML_free_string((yyvsp[(3) - (5)]));
}
    break;

  case 269:
#line 1521 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mo>{</mo><mrow><mtable columnalign=\"left left\">", (yyvsp[(3) - (5)]), "</mtable></mrow></mrow>");
  itex2MML_free_string((yyvsp[(3) - (5)]));
}
    break;

  case 270:
#line 1525 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mtable columnalign=\"right left right left right left right left right left\" columnspacing=\"0em\">", (yyvsp[(3) - (5)]), "</mtable></mrow>");
  itex2MML_free_string((yyvsp[(3) - (5)]));
}
    break;

  case 271:
#line 1529 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mtable rowspacing=\"0.5ex\" align=\"", (yyvsp[(3) - (9)]), "\" columnalign=\"");
  char * s2 = itex2MML_copy3(s1, (yyvsp[(5) - (9)]), "\">");
  (yyval) = itex2MML_copy3(s2, (yyvsp[(7) - (9)]), "</mtable>");
  itex2MML_free_string(s1);
  itex2MML_free_string(s2);
  itex2MML_free_string((yyvsp[(3) - (9)]));
  itex2MML_free_string((yyvsp[(5) - (9)]));
  itex2MML_free_string((yyvsp[(7) - (9)]));
}
    break;

  case 272:
#line 1539 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mtable rowspacing=\"0.5ex\" columnalign=\"", (yyvsp[(4) - (8)]), "\">");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(6) - (8)]), "</mtable>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(4) - (8)]));
  itex2MML_free_string((yyvsp[(6) - (8)]));
}
    break;

  case 273:
#line 1546 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<semantics><annotation-xml encoding=\"SVG1.1\">", (yyvsp[(3) - (4)]), "</annotation-xml></semantics>");
  itex2MML_free_string((yyvsp[(3) - (4)]));
}
    break;

  case 274:
#line 1550 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string(" ");
}
    break;

  case 275:
#line 1554 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3((yyvsp[(1) - (2)]), " ", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(1) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 276:
#line 1559 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 277:
#line 1564 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mtable columnalign=\"center\" rowspacing=\"0.5ex\">", (yyvsp[(3) - (4)]), "</mtable></mrow>");
  itex2MML_free_string((yyvsp[(3) - (4)]));
}
    break;

  case 278:
#line 1569 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mtable>", (yyvsp[(3) - (4)]), "</mtable></mrow>");
  itex2MML_free_string((yyvsp[(3) - (4)]));
}
    break;

  case 279:
#line 1573 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mrow><mtable ", (yyvsp[(5) - (8)]), ">");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(7) - (8)]), "</mtable></mrow>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(5) - (8)]));
  itex2MML_free_string((yyvsp[(7) - (8)]));
}
    break;

  case 280:
#line 1581 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 281:
#line 1585 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3((yyvsp[(1) - (2)]), " ", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(1) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 282:
#line 1591 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 283:
#line 1595 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 284:
#line 1599 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 285:
#line 1603 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 286:
#line 1607 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 287:
#line 1611 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 288:
#line 1615 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 289:
#line 1619 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 290:
#line 1623 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 291:
#line 1627 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 292:
#line 1632 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("columnalign=", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 293:
#line 1637 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("columnalign=", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 294:
#line 1642 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("rowalign=", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 295:
#line 1647 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("align=", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 296:
#line 1652 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("equalrows=", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 297:
#line 1657 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("equalcolumns=", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 298:
#line 1662 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("rowlines=", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 299:
#line 1667 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("columnlines=", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 300:
#line 1672 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("frame=", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 301:
#line 1677 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("rowspacing=", (yyvsp[(2) - (2)]), " columnspacing=");
  (yyval) = itex2MML_copy2(s1, (yyvsp[(2) - (2)]));
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 302:
#line 1684 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 303:
#line 1688 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3((yyvsp[(1) - (3)]), " ", (yyvsp[(3) - (3)]));
  itex2MML_free_string((yyvsp[(1) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 304:
#line 1694 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mtr>", (yyvsp[(1) - (1)]), "</mtr>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 305:
#line 1698 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 306:
#line 1703 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 307:
#line 1707 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3((yyvsp[(1) - (3)]), " ", (yyvsp[(3) - (3)]));
  itex2MML_free_string((yyvsp[(1) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 308:
#line 1713 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mtr ", (yyvsp[(3) - (5)]), ">");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(5) - (5)]), "</mtr>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(3) - (5)]));
  itex2MML_free_string((yyvsp[(5) - (5)]));
}
    break;

  case 309:
#line 1721 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 310:
#line 1725 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3((yyvsp[(1) - (2)]), " ", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(1) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 311:
#line 1731 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 312:
#line 1735 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 313:
#line 1740 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mtd/>");
}
    break;

  case 314:
#line 1743 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mtd>", (yyvsp[(1) - (1)]), "</mtd>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 315:
#line 1747 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mtd ", (yyvsp[(3) - (5)]), ">");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(5) - (5)]), "</mtd>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(3) - (5)]));
  itex2MML_free_string((yyvsp[(5) - (5)]));
}
    break;

  case 316:
#line 1755 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 317:
#line 1759 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3((yyvsp[(1) - (2)]), " ", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(1) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 318:
#line 1765 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 319:
#line 1769 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 320:
#line 1773 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 321:
#line 1777 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 322:
#line 1782 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("rowspan=", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 323:
#line 1787 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("columnspan=", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;


/* Line 1267 of yacc.c.  */
#line 5705 "y.tab.c"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 1792 "itex2MML.y"


char * itex2MML_parse (const char * buffer, unsigned long length)
{
  char * mathml = 0;

  int result;

  itex2MML_setup (buffer, length);
  itex2MML_restart ();

  result = itex2MML_yyparse (&mathml);

  if (result && mathml) /* shouldn't happen? */
    {
      itex2MML_free_string (mathml);
      mathml = 0;
    }
  return mathml;
}

int itex2MML_filter (const char * buffer, unsigned long length)
{
  itex2MML_setup (buffer, length);
  itex2MML_restart ();

  return itex2MML_yyparse (0);
}

#define ITEX_DELIMITER_DOLLAR 0
#define ITEX_DELIMITER_DOUBLE 1
#define ITEX_DELIMITER_SQUARE 2

static char * itex2MML_last_error = 0;

static void itex2MML_keep_error (const char * msg)
{
  if (itex2MML_last_error)
    {
      itex2MML_free_string (itex2MML_last_error);
      itex2MML_last_error = 0;
    }
  itex2MML_last_error = itex2MML_copy_escaped (msg);
}

int itex2MML_html_filter (const char * buffer, unsigned long length)
{
  itex2MML_do_html_filter (buffer, length, 0);
}

int itex2MML_strict_html_filter (const char * buffer, unsigned long length)
{
  itex2MML_do_html_filter (buffer, length, 1);
}

int itex2MML_do_html_filter (const char * buffer, unsigned long length, const int forbid_markup)
{
  int result = 0;

  int type = 0;
  int skip = 0;
  int match = 0;

  const char * ptr1 = buffer;
  const char * ptr2 = 0;

  const char * end = buffer + length;

  char * mathml = 0;

  void (*save_error_fn) (const char * msg) = itex2MML_error;

  itex2MML_error = itex2MML_keep_error;

 _until_math:
  ptr2 = ptr1;

  while (ptr2 < end)
    {
      if (*ptr2 == '$') break;
      if ((*ptr2 == '\\') && (ptr2 + 1 < end))
	{
	  if (*(ptr2+1) == '[') break;
	}
      ++ptr2;
    }
  if (itex2MML_write && ptr2 > ptr1)
    (*itex2MML_write) (ptr1, ptr2 - ptr1);

  if (ptr2 == end) goto _finish;

 _until_html:
  ptr1 = ptr2;

  if (ptr2 + 1 < end)
    {
      if ((*ptr2 == '\\') && (*(ptr2+1) == '['))
	{
	  type = ITEX_DELIMITER_SQUARE;
	  ptr2 += 2;
	}
      else if ((*ptr2 == '$') && (*(ptr2+1) == '$'))
	{
	  type = ITEX_DELIMITER_DOUBLE;
	  ptr2 += 2;
	}
      else
	{
	  type = ITEX_DELIMITER_DOLLAR;
	  ptr2 += 2;
	}
    }
  else goto _finish;

  skip = 0;
  match = 0;

  while (ptr2 < end)
    {
      switch (*ptr2)
	{
	case '<':
	case '>':
	  if (forbid_markup == 1) skip = 1;
	  break;

	case '\\':
	  if (ptr2 + 1 < end)
	    {
	      if (*(ptr2 + 1) == '[')
		{
		  skip = 1;
		}
	      else if (*(ptr2 + 1) == ']')
		{
		  if (type == ITEX_DELIMITER_SQUARE)
		    {
		      ptr2 += 2;
		      match = 1;
		    }
		  else
		    {
		      skip = 1;
		    }
		}
	    }
	  break;

	case '$':
	  if (type == ITEX_DELIMITER_SQUARE)
	    {
	      skip = 1;
	    }
	  else if (ptr2 + 1 < end)
	    {
	      if (*(ptr2 + 1) == '$')
		{
		  if (type == ITEX_DELIMITER_DOLLAR)
		    {
		      ptr2++;
		      match = 1;
		    }
		  else
		    {
		      ptr2 += 2;
		      match = 1;
		    }
		}
	      else
		{
		  if (type == ITEX_DELIMITER_DOLLAR)
		    {
		      ptr2++;
		      match = 1;
		    }
		  else
		    {
		      skip = 1;
		    }
		}
	    }
	  else
	    {
	      if (type == ITEX_DELIMITER_DOLLAR)
		{
		  ptr2++;
		  match = 1;
		}
	      else
		{
		  skip = 1;
		}
	    }
	  break;

	default:
	  break;
	}
      if (skip || match) break;

      ++ptr2;
    }
  if (skip)
    {
      if (type == ITEX_DELIMITER_DOLLAR)
	{
	  if (itex2MML_write)
	    (*itex2MML_write) (ptr1, 1);
	  ptr1++;
	}
      else
	{
	  if (itex2MML_write)
	    (*itex2MML_write) (ptr1, 2);
	  ptr1 += 2;
	}
      goto _until_math;
    }
  if (match)
    {
      mathml = itex2MML_parse (ptr1, ptr2 - ptr1);

      if (mathml)
	{
	  if (itex2MML_write_mathml)
	    (*itex2MML_write_mathml) (mathml);
	  itex2MML_free_string (mathml);
	  mathml = 0;
	}
      else
	{
	  ++result;
	  if (itex2MML_write)
	    {
	      if (type == ITEX_DELIMITER_DOLLAR)
		(*itex2MML_write) ("<math xmlns='http://www.w3.org/1998/Math/MathML' display='inline'><merror><mtext>", 0);
	      else
		(*itex2MML_write) ("<math xmlns='http://www.w3.org/1998/Math/MathML' display='block'><merror><mtext>", 0);

	      (*itex2MML_write) (itex2MML_last_error, 0);
	      (*itex2MML_write) ("</mtext></merror></math>", 0);
	    }
	}
      ptr1 = ptr2;

      goto _until_math;
    }
  if (itex2MML_write)
    (*itex2MML_write) (ptr1, ptr2 - ptr1);

 _finish:
  if (itex2MML_last_error)
    {
      itex2MML_free_string (itex2MML_last_error);
      itex2MML_last_error = 0;
    }
  itex2MML_error = save_error_fn;

  return result;
}

