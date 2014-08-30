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
     BOLD = 329,
     BOXED = 330,
     SLASHED = 331,
     RM = 332,
     BB = 333,
     ST = 334,
     END = 335,
     BBLOWERCHAR = 336,
     BBUPPERCHAR = 337,
     BBDIGIT = 338,
     CALCHAR = 339,
     FRAKCHAR = 340,
     CAL = 341,
     FRAK = 342,
     CLAP = 343,
     LLAP = 344,
     RLAP = 345,
     ROWOPTS = 346,
     TEXTSIZE = 347,
     SCSIZE = 348,
     SCSCSIZE = 349,
     DISPLAY = 350,
     TEXTSTY = 351,
     TEXTBOX = 352,
     TEXTSTRING = 353,
     XMLSTRING = 354,
     CELLOPTS = 355,
     ROWSPAN = 356,
     COLSPAN = 357,
     THINSPACE = 358,
     MEDSPACE = 359,
     THICKSPACE = 360,
     QUAD = 361,
     QQUAD = 362,
     NEGSPACE = 363,
     PHANTOM = 364,
     HREF = 365,
     UNKNOWNCHAR = 366,
     EMPTYMROW = 367,
     STATLINE = 368,
     TOOLTIP = 369,
     TOGGLE = 370,
     FGHIGHLIGHT = 371,
     BGHIGHLIGHT = 372,
     SPACE = 373,
     INTONE = 374,
     INTTWO = 375,
     INTTHREE = 376,
     BAR = 377,
     WIDEBAR = 378,
     VEC = 379,
     WIDEVEC = 380,
     HAT = 381,
     WIDEHAT = 382,
     CHECK = 383,
     WIDECHECK = 384,
     TILDE = 385,
     WIDETILDE = 386,
     DOT = 387,
     DDOT = 388,
     DDDOT = 389,
     DDDDOT = 390,
     UNARYMINUS = 391,
     UNARYPLUS = 392,
     BEGINENV = 393,
     ENDENV = 394,
     MATRIX = 395,
     PMATRIX = 396,
     BMATRIX = 397,
     BBMATRIX = 398,
     VMATRIX = 399,
     VVMATRIX = 400,
     SVG = 401,
     ENDSVG = 402,
     SMALLMATRIX = 403,
     CASES = 404,
     ALIGNED = 405,
     GATHERED = 406,
     SUBSTACK = 407,
     PMOD = 408,
     RMCHAR = 409,
     COLOR = 410,
     BGCOLOR = 411,
     XARROW = 412,
     OPTARGOPEN = 413,
     OPTARGCLOSE = 414,
     ITEXNUM = 415
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
#define BOLD 329
#define BOXED 330
#define SLASHED 331
#define RM 332
#define BB 333
#define ST 334
#define END 335
#define BBLOWERCHAR 336
#define BBUPPERCHAR 337
#define BBDIGIT 338
#define CALCHAR 339
#define FRAKCHAR 340
#define CAL 341
#define FRAK 342
#define CLAP 343
#define LLAP 344
#define RLAP 345
#define ROWOPTS 346
#define TEXTSIZE 347
#define SCSIZE 348
#define SCSCSIZE 349
#define DISPLAY 350
#define TEXTSTY 351
#define TEXTBOX 352
#define TEXTSTRING 353
#define XMLSTRING 354
#define CELLOPTS 355
#define ROWSPAN 356
#define COLSPAN 357
#define THINSPACE 358
#define MEDSPACE 359
#define THICKSPACE 360
#define QUAD 361
#define QQUAD 362
#define NEGSPACE 363
#define PHANTOM 364
#define HREF 365
#define UNKNOWNCHAR 366
#define EMPTYMROW 367
#define STATLINE 368
#define TOOLTIP 369
#define TOGGLE 370
#define FGHIGHLIGHT 371
#define BGHIGHLIGHT 372
#define SPACE 373
#define INTONE 374
#define INTTWO 375
#define INTTHREE 376
#define BAR 377
#define WIDEBAR 378
#define VEC 379
#define WIDEVEC 380
#define HAT 381
#define WIDEHAT 382
#define CHECK 383
#define WIDECHECK 384
#define TILDE 385
#define WIDETILDE 386
#define DOT 387
#define DDOT 388
#define DDDOT 389
#define DDDDOT 390
#define UNARYMINUS 391
#define UNARYPLUS 392
#define BEGINENV 393
#define ENDENV 394
#define MATRIX 395
#define PMATRIX 396
#define BMATRIX 397
#define BBMATRIX 398
#define VMATRIX 399
#define VVMATRIX 400
#define SVG 401
#define ENDSVG 402
#define SMALLMATRIX 403
#define CASES 404
#define ALIGNED 405
#define GATHERED 406
#define SUBSTACK 407
#define PMOD 408
#define RMCHAR 409
#define COLOR 410
#define BGCOLOR 411
#define XARROW 412
#define OPTARGOPEN 413
#define OPTARGCLOSE 414
#define ITEXNUM 415




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
#line 708 "y.tab.c"

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
#define YYFINAL  188
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3894

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  161
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  112
/* YYNRULES -- Number of rules.  */
#define YYNRULES  307
/* YYNRULES -- Number of states.  */
#define YYNSTATES  546

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   415

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
     155,   156,   157,   158,   159,   160
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
     225,   227,   229,   231,   233,   237,   241,   245,   247,   249,
     251,   253,   256,   259,   262,   265,   268,   271,   274,   277,
     280,   283,   286,   289,   292,   295,   298,   301,   304,   307,
     310,   313,   316,   319,   322,   325,   328,   331,   333,   335,
     337,   339,   341,   343,   346,   348,   350,   352,   354,   356,
     358,   360,   362,   364,   366,   368,   370,   372,   374,   377,
     380,   383,   386,   397,   401,   405,   409,   413,   417,   421,
     425,   428,   431,   434,   437,   440,   443,   446,   449,   452,
     455,   458,   461,   464,   469,   471,   474,   479,   481,   484,
     486,   488,   490,   495,   497,   500,   502,   507,   509,   512,
     514,   516,   518,   520,   522,   524,   526,   529,   533,   539,
     543,   552,   559,   566,   568,   571,   576,   579,   582,   586,
     590,   594,   597,   603,   609,   615,   621,   625,   629,   632,
     635,   638,   641,   644,   647,   650,   653,   656,   659,   662,
     665,   668,   671,   674,   677,   680,   683,   689,   693,   699,
     703,   706,   710,   716,   721,   723,   729,   735,   741,   747,
     753,   759,   765,   771,   777,   783,   793,   802,   807,   811,
     814,   816,   821,   826,   835,   837,   840,   842,   844,   846,
     848,   850,   852,   854,   856,   858,   860,   863,   866,   869,
     872,   875,   878,   881,   884,   887,   890,   892,   896,   898,
     900,   902,   906,   912,   914,   917,   919,   921,   922,   924,
     930,   932,   935,   937,   939,   941,   943,   946
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     162,     0,    -1,   163,    -1,    -1,   164,    -1,   165,    -1,
     163,   164,    -1,   163,   165,    -1,     5,    -1,     6,     8,
      -1,     7,     8,    -1,     6,   166,     8,    -1,     7,   166,
       8,    -1,   167,    -1,   166,   167,    -1,   178,    14,   168,
      13,   168,    -1,   178,    14,   168,    -1,   178,    13,   168,
      14,   168,    -1,   178,    13,   168,    -1,   176,    14,   168,
      13,   168,    -1,   176,    14,   168,    -1,   176,    13,   168,
      14,   168,    -1,   176,    13,   168,    -1,   168,    14,   168,
      13,   168,    -1,   168,    13,   168,    14,   168,    -1,   168,
      14,   168,    -1,   168,    13,   168,    -1,    14,   168,    -1,
      13,   168,    -1,   168,    -1,   249,    -1,   173,    -1,   174,
      -1,   176,    -1,   175,    -1,   177,    -1,   179,    -1,   219,
      -1,   220,    -1,   223,    -1,   227,    -1,   240,    -1,   241,
      -1,   242,    -1,   243,    -1,   231,    -1,   232,    -1,   239,
      -1,   233,    -1,   234,    -1,   235,    -1,   236,    -1,   238,
      -1,   237,    -1,   230,    -1,   228,    -1,   229,    -1,   244,
      -1,   245,    -1,   189,    -1,   188,    -1,   187,    -1,   191,
      -1,   192,    -1,   193,    -1,   194,    -1,   195,    -1,   196,
      -1,   199,    -1,   200,    -1,   201,    -1,   202,    -1,   205,
      -1,   197,    -1,   198,    -1,   208,    -1,   180,    -1,   190,
      -1,   211,    -1,   212,    -1,   213,    -1,   214,    -1,   215,
      -1,   216,    -1,   217,    -1,   218,    -1,   181,    -1,   182,
      -1,   183,    -1,   184,    -1,   185,    -1,   186,    -1,   225,
      -1,   226,    -1,    15,   168,    16,    -1,    15,   166,    16,
      -1,   169,   166,   170,    -1,   246,    -1,   248,    -1,   224,
      -1,   172,    -1,    17,    40,    -1,    17,    39,    -1,    17,
      38,    -1,    18,    41,    -1,    18,    39,    -1,    18,    38,
      -1,    19,    40,    -1,    19,    41,    -1,    19,    39,    -1,
      20,    40,    -1,    20,    41,    -1,    20,    39,    -1,    21,
      40,    -1,    21,    41,    -1,    21,    39,    -1,    22,    40,
      -1,    22,    41,    -1,    22,    39,    -1,    23,    40,    -1,
      23,    39,    -1,    24,    40,    -1,    24,    39,    -1,    25,
      40,    -1,    25,    39,    -1,    26,    40,    -1,    26,    39,
      -1,   111,    -1,   136,    -1,   137,    -1,     9,    -1,    10,
      -1,    11,    -1,   160,    98,    -1,    43,    -1,   178,    -1,
     171,    -1,    12,    -1,    34,    -1,    35,    -1,    41,    -1,
      40,    -1,    39,    -1,    36,    -1,    38,    -1,    42,    -1,
      33,    -1,    37,    -1,    29,    98,    -1,    30,    98,    -1,
      31,    98,    -1,    32,    98,    -1,   118,    79,   119,    80,
      79,   120,    80,    79,   121,    80,    -1,   113,    98,   168,
      -1,   114,    98,   168,    -1,   115,   168,   168,    -1,   116,
      72,   168,    -1,   117,    72,   168,    -1,   155,    72,   166,
      -1,   156,    72,   166,    -1,    90,   168,    -1,    89,   168,
      -1,    88,   168,    -1,    97,    98,    -1,    95,   168,    -1,
      96,   168,    -1,    92,   168,    -1,    93,   168,    -1,    94,
     168,    -1,    73,   168,    -1,    76,   168,    -1,    75,   168,
      -1,    74,   168,    -1,    77,    79,   201,    80,    -1,   154,
      -1,   201,   154,    -1,    78,    79,   203,    80,    -1,   204,
      -1,   203,   204,    -1,    81,    -1,    82,    -1,    83,    -1,
      87,    79,   206,    80,    -1,   207,    -1,   206,   207,    -1,
      85,    -1,    86,    79,   209,    80,    -1,   210,    -1,   209,
     210,    -1,    84,    -1,   103,    -1,   104,    -1,   105,    -1,
     106,    -1,   107,    -1,   108,    -1,   109,   168,    -1,   110,
      98,   168,    -1,    54,   168,    15,   221,    16,    -1,    54,
     168,   221,    -1,    55,    15,   221,    16,   168,    15,   221,
      16,    -1,    55,    15,   221,    16,   168,   112,    -1,    55,
     112,   168,    15,   221,    16,    -1,   222,    -1,   221,   222,
      -1,    14,   168,    13,   168,    -1,    14,   168,    -1,    13,
     168,    -1,    14,    13,   168,    -1,    27,   168,   168,    -1,
      28,   168,   168,    -1,   153,   168,    -1,    15,   166,     4,
     166,    16,    -1,   169,   166,     4,   166,   170,    -1,    15,
     166,     3,   166,    16,    -1,   169,   166,     3,   166,   170,
      -1,    46,   168,   168,    -1,    47,   168,   168,    -1,    52,
     168,    -1,    51,   168,    -1,    50,   168,    -1,   122,   168,
      -1,   123,   168,    -1,   124,   168,    -1,   125,   168,    -1,
     132,   168,    -1,   133,   168,    -1,   134,   168,    -1,   135,
     168,    -1,   130,   168,    -1,   131,   168,    -1,   128,   168,
      -1,   129,   168,    -1,   126,   168,    -1,   127,   168,    -1,
      44,   168,    -1,    44,   158,   166,   159,   168,    -1,    45,
     168,   168,    -1,   157,   158,   166,   159,   112,    -1,    48,
     168,   168,    -1,   157,   168,    -1,    49,   168,   168,    -1,
     157,   158,   166,   159,   168,    -1,    53,   168,   168,   168,
      -1,   112,    -1,   138,   140,   262,   139,   140,    -1,   138,
     151,   262,   139,   151,    -1,   138,   141,   262,   139,   141,
      -1,   138,   142,   262,   139,   142,    -1,   138,   144,   262,
     139,   144,    -1,   138,   143,   262,   139,   143,    -1,   138,
     145,   262,   139,   145,    -1,   138,   148,   262,   139,   148,
      -1,   138,   149,   262,   139,   149,    -1,   138,   150,   262,
     139,   150,    -1,   138,    58,    56,    79,   247,    80,   262,
     139,    58,    -1,   138,    58,    79,   247,    80,   262,   139,
      58,    -1,   138,   146,    99,   147,    -1,   138,   146,   147,
      -1,   247,    57,    -1,    57,    -1,   152,    15,   262,    16,
      -1,    58,    15,   262,    16,    -1,    58,    15,    61,    15,
     250,    16,   262,    16,    -1,   251,    -1,   250,   251,    -1,
     252,    -1,   253,    -1,   254,    -1,   255,    -1,   256,    -1,
     257,    -1,   258,    -1,   259,    -1,   260,    -1,   261,    -1,
      62,    72,    -1,    63,    72,    -1,    64,    72,    -1,    65,
      72,    -1,    66,    72,    -1,    67,    72,    -1,    68,    72,
      -1,    69,    72,    -1,    70,    72,    -1,    71,    72,    -1,
     263,    -1,   262,    60,   263,    -1,   264,    -1,   265,    -1,
     268,    -1,   264,    59,   268,    -1,    91,    15,   266,    16,
     264,    -1,   267,    -1,   266,   267,    -1,   253,    -1,   254,
      -1,    -1,   166,    -1,   100,    15,   269,    16,   166,    -1,
     270,    -1,   269,   270,    -1,   253,    -1,   254,    -1,   271,
      -1,   272,    -1,   101,    72,    -1,   102,    72,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   284,   284,   287,   288,   289,   290,   291,   293,   295,
     296,   297,   310,   324,   328,   334,   353,   367,   386,   400,
     419,   433,   452,   466,   476,   486,   493,   500,   504,   508,
     513,   514,   515,   516,   517,   521,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   587,   591,   599,   600,   601,
     602,   604,   609,   614,   620,   624,   628,   633,   638,   642,
     646,   651,   655,   659,   664,   668,   672,   677,   681,   685,
     690,   695,   700,   705,   710,   715,   720,   726,   730,   734,
     738,   740,   746,   747,   753,   759,   760,   761,   766,   771,
     776,   780,   785,   789,   793,   797,   802,   807,   812,   817,
     822,   827,   833,   844,   852,   860,   868,   876,   884,   891,
     899,   904,   909,   914,   919,   924,   929,   934,   939,   944,
     949,   954,   959,   964,   969,   973,   979,   984,   988,   994,
     998,  1002,  1010,  1015,  1019,  1025,  1030,  1035,  1039,  1045,
    1050,  1054,  1058,  1062,  1066,  1070,  1074,  1079,  1089,  1096,
    1104,  1114,  1123,  1131,  1135,  1141,  1146,  1150,  1154,  1159,
    1166,  1174,  1179,  1186,  1200,  1207,  1221,  1228,  1236,  1241,
    1246,  1251,  1255,  1260,  1264,  1269,  1274,  1279,  1284,  1289,
    1293,  1298,  1302,  1307,  1311,  1316,  1321,  1328,  1336,  1343,
    1351,  1358,  1366,  1376,  1385,  1389,  1393,  1397,  1401,  1405,
    1409,  1413,  1417,  1421,  1425,  1429,  1439,  1446,  1450,  1454,
    1459,  1464,  1469,  1473,  1481,  1485,  1491,  1495,  1499,  1503,
    1507,  1511,  1515,  1519,  1523,  1527,  1532,  1537,  1542,  1547,
    1552,  1557,  1562,  1567,  1572,  1577,  1584,  1588,  1594,  1598,
    1603,  1607,  1613,  1621,  1625,  1631,  1635,  1640,  1643,  1647,
    1655,  1659,  1665,  1669,  1673,  1677,  1682,  1687
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
  "BOLD", "BOXED", "SLASHED", "RM", "BB", "ST", "END", "BBLOWERCHAR",
  "BBUPPERCHAR", "BBDIGIT", "CALCHAR", "FRAKCHAR", "CAL", "FRAK", "CLAP",
  "LLAP", "RLAP", "ROWOPTS", "TEXTSIZE", "SCSIZE", "SCSCSIZE", "DISPLAY",
  "TEXTSTY", "TEXTBOX", "TEXTSTRING", "XMLSTRING", "CELLOPTS", "ROWSPAN",
  "COLSPAN", "THINSPACE", "MEDSPACE", "THICKSPACE", "QUAD", "QQUAD",
  "NEGSPACE", "PHANTOM", "HREF", "UNKNOWNCHAR", "EMPTYMROW", "STATLINE",
  "TOOLTIP", "TOGGLE", "FGHIGHLIGHT", "BGHIGHLIGHT", "SPACE", "INTONE",
  "INTTWO", "INTTHREE", "BAR", "WIDEBAR", "VEC", "WIDEVEC", "HAT",
  "WIDEHAT", "CHECK", "WIDECHECK", "TILDE", "WIDETILDE", "DOT", "DDOT",
  "DDDOT", "DDDDOT", "UNARYMINUS", "UNARYPLUS", "BEGINENV", "ENDENV",
  "MATRIX", "PMATRIX", "BMATRIX", "BBMATRIX", "VMATRIX", "VVMATRIX", "SVG",
  "ENDSVG", "SMALLMATRIX", "CASES", "ALIGNED", "GATHERED", "SUBSTACK",
  "PMOD", "RMCHAR", "COLOR", "BGCOLOR", "XARROW", "OPTARGOPEN",
  "OPTARGCLOSE", "ITEXNUM", "$accept", "doc", "xmlmmlTermList", "char",
  "expression", "compoundTermList", "compoundTerm", "closedTerm", "left",
  "right", "bigdelim", "unrecognized", "unaryminus", "unaryplus", "mi",
  "mib", "mn", "mob", "mo", "space", "statusline", "tooltip", "toggle",
  "fghighlight", "bghighlight", "color", "mathrlap", "mathllap",
  "mathclap", "textstring", "displaystyle", "textstyle", "textsize",
  "scriptsize", "scriptscriptsize", "italics", "slashed", "boxed", "bold",
  "roman", "rmchars", "bbold", "bbchars", "bbchar", "frak", "frakletters",
  "frakletter", "cal", "calletters", "calletter", "thinspace", "medspace",
  "thickspace", "quad", "qquad", "negspace", "phantom", "href", "tensor",
  "multi", "subsupList", "subsupTerm", "mfrac", "pmod", "texover",
  "texatop", "binom", "munderbrace", "munderline", "moverbrace", "bar",
  "vec", "dot", "ddot", "dddot", "ddddot", "tilde", "check", "hat",
  "msqrt", "mroot", "munder", "mover", "munderover", "emptymrow",
  "mathenv", "columnAlignList", "substack", "array", "arrayopts",
  "anarrayopt", "collayout", "colalign", "rowalign", "align", "eqrows",
  "eqcols", "rowlines", "collines", "frame", "padding", "tableRowList",
  "tableRow", "simpleTableRow", "optsTableRow", "rowopts", "arowopt",
  "tableCell", "cellopts", "acellopt", "rowspan", "colspan", 0
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
     415
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   161,   162,   163,   163,   163,   163,   163,   164,   165,
     165,   165,   165,   166,   166,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   169,   169,   169,   170,   170,   170,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   172,   173,   174,
     175,   176,   177,   177,   178,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   180,   181,   182,   183,   184,   185,   186,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   201,   202,   203,   203,   204,
     204,   204,   205,   206,   206,   207,   208,   209,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   219,
     220,   220,   220,   221,   221,   222,   222,   222,   222,   223,
     223,   224,   225,   225,   226,   226,   227,   227,   228,   229,
     230,   231,   231,   232,   232,   233,   234,   235,   236,   237,
     237,   238,   238,   239,   239,   240,   241,   241,   242,   242,
     243,   243,   244,   244,   245,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   247,
     247,   248,   249,   249,   250,   250,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   262,   263,   263,
     264,   264,   265,   266,   266,   267,   267,   268,   268,   268,
     269,   269,   270,   270,   270,   270,   271,   272
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
       1,     1,     1,     1,     3,     3,     3,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,    10,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     4,     1,     2,     4,     1,     2,     1,
       1,     1,     4,     1,     2,     1,     4,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     5,     3,
       8,     6,     6,     1,     2,     4,     2,     2,     3,     3,
       3,     2,     5,     5,     5,     5,     3,     3,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     5,     3,     5,     3,
       2,     3,     5,     4,     1,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     9,     8,     4,     3,     2,
       1,     4,     4,     8,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     3,     1,     1,
       1,     3,     5,     1,     2,     1,     1,     0,     1,     5,
       1,     2,     1,     1,     1,     1,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       3,     8,     0,     0,     0,     2,     4,     5,     9,   130,
     131,   132,   137,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   146,   138,   139,   143,   147,   144,   142,   141,   140,
     145,   134,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   190,   191,   192,   193,   194,   195,     0,     0,
     127,   244,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   128,   129,     0,     0,     0,   174,     0,     0,
       0,     0,     0,    13,    29,     0,   136,   100,    31,    32,
      34,    33,    35,   135,    36,    76,    86,    87,    88,    89,
      90,    91,    61,    60,    59,    77,    62,    63,    64,    65,
      66,    67,    73,    74,    68,    69,    70,    71,    72,    75,
      78,    79,    80,    81,    82,    83,    84,    85,    37,    38,
      39,    99,    92,    93,    40,    55,    56,    54,    45,    46,
      48,    49,    50,    51,    53,    52,    47,    41,    42,    43,
      44,    57,    58,    97,    98,    30,    10,     0,     1,     6,
       7,    28,    33,   135,    27,     0,    29,   103,   102,   101,
     109,   107,   108,   112,   110,   111,   115,   113,   114,   118,
     116,   117,   120,   119,   122,   121,   124,   123,   126,   125,
       0,     0,   148,   149,   150,   151,     0,   235,     0,     0,
       0,     0,     0,   220,   219,   218,     0,     0,     0,     0,
     297,   169,   172,   171,   170,     0,     0,     0,     0,   162,
     161,   160,   166,   167,   168,   164,   165,   163,   196,     0,
       0,     0,     0,     0,     0,     0,   221,   222,   223,   224,
     233,   234,   231,   232,   229,   230,   225,   226,   227,   228,
       0,   297,   297,   297,   297,   297,   297,     0,   297,   297,
     297,   297,   297,   211,     0,     0,     0,   240,   133,    11,
      14,     0,     0,     0,     0,     0,     0,     0,   175,    12,
       0,     0,    95,    94,   209,   210,     0,   237,   216,   217,
     239,   241,     0,     0,     0,     0,   199,   203,     0,     0,
       0,     0,     0,   298,     0,   286,   288,   289,   290,     0,
     179,   180,   181,     0,   177,   189,     0,   187,   185,     0,
     183,   197,   153,   154,   155,   156,   157,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   258,     0,     0,
       0,     0,     0,   158,   159,     0,    26,    25,     0,     0,
       0,    96,    22,    20,    18,    16,     0,     0,     0,   243,
     207,     0,   206,     0,   204,     0,     0,     0,     0,     0,
     262,   297,   297,   173,   176,   178,   186,   188,   182,   184,
       0,     0,   260,     0,     0,     0,     0,     0,     0,     0,
     257,     0,     0,     0,     0,   261,     0,     0,     0,     0,
       0,   106,   105,   104,     0,     0,     0,     0,   214,   212,
     236,   208,     0,   198,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   264,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   295,   296,
       0,   293,     0,     0,   302,   303,     0,   300,   304,   305,
     287,   291,     0,     0,   259,   297,   245,   247,   248,   250,
     249,   251,   252,   253,   254,   246,   238,   242,    24,    23,
     215,   213,    21,    19,    17,    15,   205,     0,   201,   202,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     297,   265,   297,   294,   306,   307,     0,   301,     0,   297,
       0,     0,     0,   292,   299,     0,     0,     0,   200,   263,
       0,     0,   256,     0,   255,   152
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,   333,   113,   114,   115,   381,
     116,   117,   118,   119,   120,   192,   122,   193,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   343,   344,   148,   349,   350,   149,   346,   347,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     326,   327,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   413,   184,   185,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   334,   335,   336,   337,   470,   471,   338,   476,   477,
     478,   479
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -338
static const yytype_int16 yypact[] =
{
      48,  -338,  1147,  1300,    43,    48,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  3582,  3582,  2974,    84,   147,   150,   155,
     159,    32,    37,    62,   108,  3582,  3582,   -40,   -38,   -29,
       9,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  3126,  3582,  3582,  3582,  3582,  3582,  3582,  3582,
    3582,  3582,  3582,   -12,    77,  3582,  3582,  3582,  3582,    63,
      66,    94,    98,  3582,  3582,  3582,  3582,  3582,  3582,  3582,
    3582,    83,  -338,  -338,  -338,  -338,  -338,  -338,  3582,   118,
    -338,  -338,   119,   120,  3582,    44,   125,   113,  3582,  3582,
    3582,  3582,  3582,  3582,  3582,  3582,  3582,  3582,  3582,  3582,
    3582,  3582,  -338,  -338,   -14,   204,  3582,  -338,   148,   151,
    3278,   127,  1453,  -338,    74,  2974,  -338,  -338,  -338,  -338,
    -338,   170,  -338,   194,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,    72,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  1606,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,   839,    67,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
    3582,  3582,  -338,  -338,  -338,  -338,  2974,  -338,  3582,  3582,
    3582,  3582,  3582,  -338,  -338,  -338,  3582,   188,   196,  3582,
    1758,  -338,  -338,  -338,  -338,    73,   123,   146,   152,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  3582,
    3582,  3582,  3582,  3582,  3582,   112,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
     -11,  1910,  1910,  1910,  1910,  1910,  1910,   -68,  1910,  1910,
    1910,  1910,  1910,  -338,  2974,  2974,  2974,  -338,  -338,  -338,
    -338,  3582,  3582,   994,  3582,  3582,  3582,  3582,  -338,  -338,
    2974,  2974,  -338,  -338,  -338,  -338,  2062,  -338,  -338,  -338,
    -338,  -338,  3582,  3582,  3430,   196,   196,  -338,    92,   217,
     218,   219,   220,  2974,    -1,  -338,   177,  -338,  -338,   -70,
    -338,  -338,  -338,    16,  -338,  -338,   -34,  -338,  -338,   -15,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,   160,   163,   182,
     -49,   -48,   -46,   -36,   -30,   -28,    96,  -338,   -27,   -25,
     -21,   -20,    18,  2974,  2974,  2214,   227,   231,  2974,  2974,
     102,  -338,   232,   234,   235,   237,  2366,  2518,  3582,  -338,
    -338,  3582,   238,   158,  -338,  3582,   196,    88,   149,   -16,
    -338,  1910,  2670,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
     169,   182,  -338,    -6,   105,   111,   114,   110,   115,   109,
    -338,   107,   116,   117,   121,  -338,  3734,  3582,  3582,  2822,
    2822,  -338,  -338,  -338,  3582,  3582,  3582,  3582,  -338,  -338,
    -338,  -338,  3582,  -338,    -8,   162,   186,   189,   190,   191,
     192,   197,   198,   201,   203,   205,    99,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
       0,  -338,   206,   213,  -338,  -338,    -7,  -338,  -338,  -338,
    -338,  -338,   156,    -5,  -338,  1910,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,   196,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
    1910,  -338,  2670,  -338,  -338,  -338,  2974,  -338,   211,  1910,
     -19,   166,    22,   177,  2974,   216,   -18,   210,  -338,  -338,
     178,   242,  -338,   222,  -338,  -338
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -338,  -338,  -338,   298,   299,     2,   209,   404,  -338,  -215,
    -338,  -338,  -338,  -338,  -338,    -2,  -338,    34,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
      60,  -338,  -338,   -37,  -338,  -338,   -42,  -338,  -338,   -35,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
    -236,  -320,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -101,  -338,  -338,  -338,
    -129,  -338,  -337,  -332,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -263,   -69,  -189,  -338,  -338,  -136,   -67,  -338,  -140,
    -338,  -338
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     121,   121,   328,   238,   112,   187,   394,   507,   394,   526,
     403,   401,   401,   121,   401,   400,   522,   195,   360,   361,
     362,   363,   364,   365,   401,   368,   369,   370,   371,   372,
     401,   366,   401,   401,   425,   401,   123,   123,   539,   401,
     401,   401,   401,   188,   280,   358,   406,   447,   448,   123,
     345,   484,   484,     1,     2,     3,   447,   448,   222,   401,
     223,   468,   474,   447,   448,   408,   469,   475,   359,   224,
     348,   212,   213,   394,   485,   529,   214,   215,   401,   367,
     301,   302,   401,   313,   308,   472,   473,   301,   302,   393,
     414,   415,   240,   416,   472,   473,   404,   340,   341,   342,
     239,   216,   217,   417,   508,   323,   324,   225,   395,   418,
     121,   419,   421,   121,   422,   520,   263,   303,   423,   424,
     537,   541,   197,   198,   199,   394,   281,   282,   283,   284,
     285,   286,   287,   468,   288,   289,   290,   291,   469,   474,
     431,   432,   245,   433,   475,   246,   123,   218,   219,   123,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   323,   324,   247,   443,   323,   324,   248,   509,   323,
     324,   257,   538,   304,   305,   121,   200,   201,   202,   203,
     204,   205,   265,   121,   206,   207,   208,   264,   209,   210,
     211,   323,   324,   325,   340,   341,   342,   306,   307,   323,
     324,   394,   447,   448,   500,   501,   259,   260,   261,   292,
     294,   123,   530,   295,   121,   298,   308,   107,   316,   123,
     345,   357,   396,   397,   398,   399,   402,   348,   121,   412,
     410,   427,   411,   420,   428,   486,   434,   435,   482,   436,
     437,   442,   487,   489,   491,   492,   488,   532,   510,   490,
     123,   511,   512,   513,   514,   493,   536,   494,   542,   515,
     516,   531,   495,   517,   123,   518,   528,   519,   524,   121,
     121,   121,   121,   121,   121,   525,   121,   121,   121,   121,
     121,   535,   121,   121,   121,   540,   373,   374,   375,   543,
     544,   121,   545,   189,   190,   339,   405,   409,   121,   121,
     483,   407,   386,   387,   121,   123,   123,   123,   123,   123,
     123,   300,   123,   123,   123,   123,   123,   521,   123,   123,
     123,   121,   480,   533,   523,   481,   527,   123,     0,     0,
       0,     0,     0,     0,   123,   123,     0,     0,     0,     0,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   123,     0,     0,
       0,   121,   121,   121,     0,     0,   121,   121,     0,     0,
     429,   430,     0,     0,   121,   121,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   300,     0,     0,   121,
     121,     0,     0,     0,   300,     0,     0,   123,   123,   123,
       0,     0,   123,   123,     0,     0,     0,   191,   194,   196,
     123,   123,     0,     0,     0,     0,     0,   121,   121,   220,
     221,     0,     0,     0,     0,   123,   123,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,     0,     0,   241,
     242,   243,   244,   123,   123,     0,     0,   249,   250,   251,
     252,   253,   254,   255,   256,     0,     0,     0,     0,     0,
       0,     0,   258,   121,     0,     0,     0,     0,   262,     0,
       0,     0,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,     0,     0,     0,     0,
     293,     0,   300,     0,   297,     0,     0,     0,   121,   123,
     121,     0,     0,     0,   121,   300,     0,   121,   534,     0,
       0,     0,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   300,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   123,     0,   123,     0,     0,     0,
     123,     0,     0,   123,     0,     0,     0,     0,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   300,   300,   300,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   300,   300,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   314,   315,     0,     0,     0,     0,
       0,     0,   317,   318,   319,   320,   321,     0,   300,   300,
     322,     0,     0,   329,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   351,   352,   353,   354,   355,   356,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   376,   377,     0,   382,   383,
     384,   385,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   389,   390,   392,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   300,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   440,     0,     0,   441,     0,     0,     0,   444,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     497,   498,   499,     0,     0,     0,     0,     0,   502,   503,
     504,   505,   310,   311,     0,     0,   506,     0,     9,    10,
      11,    12,    13,    14,    15,   312,    16,     0,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,    56,    57,    58,    59,    60,     0,     0,
       0,     0,     0,     0,     0,    61,    62,    63,    64,    65,
       0,    66,    67,    68,    69,    70,    71,     0,     0,     0,
       0,     0,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     0,     0,
       0,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,   106,   107,   108,   109,   110,   378,   379,   111,
       0,     0,     0,     9,    10,    11,    12,    13,    14,    15,
       0,    16,   380,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,    56,    57,
      58,    59,    60,     0,     0,     0,     0,     0,     0,     0,
      61,    62,    63,    64,    65,     0,    66,    67,    68,    69,
      70,    71,     0,     0,     0,     0,     0,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,     0,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   105,   106,   107,   108,
     109,   110,     0,     0,   111,     8,     9,    10,    11,    12,
      13,    14,    15,     0,    16,     0,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,     0,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,    56,    57,    58,    59,    60,     0,     0,     0,     0,
       0,     0,     0,    61,    62,    63,    64,    65,     0,    66,
      67,    68,    69,    70,    71,     0,     0,     0,     0,     0,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     0,     0,     0,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   105,
     106,   107,   108,   109,   110,     0,     0,   111,   186,     9,
      10,    11,    12,    13,    14,    15,     0,    16,     0,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    56,    57,    58,    59,    60,     0,
       0,     0,     0,     0,     0,     0,    61,    62,    63,    64,
      65,     0,    66,    67,    68,    69,    70,    71,     0,     0,
       0,     0,     0,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   105,   106,   107,   108,   109,   110,     0,     0,
     111,   299,     9,    10,    11,    12,    13,    14,    15,     0,
      16,     0,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,     0,     0,    61,
      62,    63,    64,    65,     0,    66,    67,    68,    69,    70,
      71,     0,     0,     0,     0,     0,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,     0,     0,     0,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   105,   106,   107,   108,   109,
     110,     0,     0,   111,   309,     9,    10,    11,    12,    13,
      14,    15,     0,    16,     0,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     0,     0,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
      56,    57,    58,    59,    60,     0,     0,     0,     0,     0,
       0,     0,    61,    62,    63,    64,    65,     0,    66,    67,
      68,    69,    70,    71,     0,     0,     0,     0,     0,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,     0,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   105,   106,
     107,   108,   109,   110,     0,     0,   111,     9,    10,    11,
      12,    13,    14,    15,     0,    16,     0,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,     0,     0,    54,     0,     0,   330,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,    56,    57,    58,    59,    60,     0,     0,     0,
       0,     0,     0,     0,    61,    62,    63,    64,    65,   331,
      66,    67,    68,    69,    70,    71,     0,     0,   332,     0,
       0,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     0,     0,     0,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     105,   106,   107,   108,   109,   110,     0,     0,   111,     9,
      10,    11,    12,    13,    14,    15,     0,    16,     0,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    56,    57,    58,    59,    60,     0,
       0,     0,     0,     0,     0,     0,    61,    62,    63,    64,
      65,   331,    66,    67,    68,    69,    70,    71,     0,     0,
     332,     0,     0,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   105,   106,   107,   108,   109,   110,     0,     0,
     111,     9,    10,    11,    12,    13,    14,    15,     0,    16,
       0,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,    56,    57,    58,    59,
      60,     0,     0,     0,     0,     0,     0,     0,    61,    62,
      63,    64,    65,     0,    66,    67,    68,    69,    70,    71,
       0,     0,     0,     0,     0,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,     0,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   105,   106,   107,   108,   109,   110,
       0,   388,   111,     9,    10,    11,    12,    13,    14,    15,
       0,    16,     0,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,    56,    57,
      58,    59,    60,     0,     0,     0,     0,     0,     0,     0,
      61,    62,    63,    64,    65,     0,    66,    67,    68,    69,
      70,    71,     0,     0,     0,     0,     0,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,     0,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   105,   106,   107,   108,
     109,   110,     0,   426,   111,     9,    10,    11,    12,    13,
      14,    15,   438,    16,     0,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     0,     0,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
      56,    57,    58,    59,    60,     0,     0,     0,     0,     0,
       0,     0,    61,    62,    63,    64,    65,     0,    66,    67,
      68,    69,    70,    71,     0,     0,     0,     0,     0,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,     0,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   105,   106,
     107,   108,   109,   110,     0,     0,   111,     9,    10,    11,
      12,    13,    14,    15,   439,    16,     0,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,    56,    57,    58,    59,    60,     0,     0,     0,
       0,     0,     0,     0,    61,    62,    63,    64,    65,     0,
      66,    67,    68,    69,    70,    71,     0,     0,     0,     0,
       0,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     0,     0,     0,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     105,   106,   107,   108,   109,   110,     0,     0,   111,     9,
      10,    11,    12,    13,    14,    15,     0,    16,     0,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    56,    57,    58,    59,    60,     0,
       0,     0,     0,     0,     0,     0,    61,    62,    63,    64,
      65,     0,    66,    67,    68,    69,    70,    71,     0,     0,
     332,     0,     0,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   105,   106,   107,   108,   109,   110,     0,     0,
     111,     9,    10,    11,    12,    13,    14,    15,     0,    16,
     380,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,    56,    57,    58,    59,
      60,     0,     0,     0,     0,     0,     0,     0,    61,    62,
      63,    64,    65,     0,    66,    67,    68,    69,    70,    71,
       0,     0,     0,     0,     0,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,     0,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   105,   106,   107,   108,   109,   110,
       0,     0,   111,     9,    10,    11,    12,    13,    14,    15,
       0,    16,     0,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,    56,    57,
      58,    59,    60,     0,     0,     0,     0,     0,     0,     0,
      61,    62,    63,    64,    65,     0,    66,    67,    68,    69,
      70,    71,     0,     0,     0,     0,     0,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,     0,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   105,   106,   107,   108,
     109,   110,     0,     0,   111,     9,    10,    11,    12,     0,
       0,    15,     0,    16,     0,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     0,     0,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
      56,    57,    58,    59,    60,     0,     0,     0,     0,     0,
       0,     0,    61,    62,    63,    64,    65,     0,    66,    67,
      68,    69,    70,    71,     0,     0,     0,     0,     0,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,     0,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   105,   106,
     107,   108,   109,   110,   226,     0,   111,     9,    10,    11,
      12,     0,     0,    15,     0,    16,     0,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,    56,    57,    58,    59,    60,     0,     0,     0,
       0,     0,     0,     0,    61,    62,    63,    64,    65,     0,
      66,    67,    68,    69,    70,    71,     0,     0,     0,     0,
       0,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     0,     0,     0,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     105,   106,   107,   108,   109,   110,   296,     0,   111,     9,
      10,    11,    12,   391,     0,    15,     0,    16,     0,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    56,    57,    58,    59,    60,     0,
       0,     0,     0,     0,     0,     0,    61,    62,    63,    64,
      65,     0,    66,    67,    68,    69,    70,    71,     0,     0,
       0,     0,     0,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   105,   106,   107,   108,   109,   110,     0,     0,
     111,     9,    10,    11,    12,     0,     0,    15,     0,    16,
       0,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,    56,    57,    58,    59,
      60,     0,     0,     0,     0,     0,     0,     0,    61,    62,
      63,    64,    65,     0,    66,    67,    68,    69,    70,    71,
       0,     0,     0,     0,     0,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,     0,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   105,   106,   107,   108,   109,   110,
       0,     0,   111,     9,    10,    11,    12,     0,     0,    15,
       0,    16,     0,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,    56,    57,
      58,    59,    60,     0,     0,     0,     0,     0,     0,     0,
      61,    62,    63,    64,    65,     0,    66,    67,    68,    69,
      70,    71,     0,     0,     0,     0,     0,    72,    73,    74,
      75,    76,    77,    78,    79,    80,   496,    82,    83,    84,
      85,    86,    87,     0,     0,     0,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   105,   106,   107,   108,
     109,   110,     0,     0,   111
};

static const yytype_int16 yycheck[] =
{
       2,     3,   238,    15,     2,     3,   326,    15,   328,    16,
      80,    60,    60,    15,    60,    16,    16,    15,   281,   282,
     283,   284,   285,   286,    60,   288,   289,   290,   291,   292,
      60,    99,    60,    60,    16,    60,     2,     3,    16,    60,
      60,    60,    60,     0,    58,    56,    80,    63,    64,    15,
      84,    57,    57,     5,     6,     7,    63,    64,    98,    60,
      98,   398,   399,    63,    64,    80,   398,   399,    79,    98,
      85,    39,    40,   393,    80,    80,    39,    40,    60,   147,
      13,    14,    60,    16,   154,   101,   102,    13,    14,   325,
     139,   139,    15,   139,   101,   102,    80,    81,    82,    83,
     112,    39,    40,   139,   112,    13,    14,    98,    16,   139,
     112,   139,   139,   115,   139,    16,    72,   115,   139,   139,
     139,   139,    38,    39,    40,   445,   140,   141,   142,   143,
     144,   145,   146,   470,   148,   149,   150,   151,   470,   476,
      38,    39,    79,    41,   476,    79,   112,    39,    40,   115,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
     396,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    13,    14,    79,    16,    13,    14,    79,    16,    13,
      14,    98,    16,    13,    14,   187,    39,    40,    41,    39,
      40,    41,    79,   195,    39,    40,    41,    72,    39,    40,
      41,    13,    14,    15,    81,    82,    83,    13,    14,    13,
      14,   531,    63,    64,   429,   430,    98,    98,    98,    15,
      72,   187,   485,    72,   226,    98,   154,   154,   226,   195,
      84,   119,    15,    15,    15,    15,    59,    85,   240,    57,
      80,    14,    79,   147,    13,   140,    14,    13,    79,    14,
      13,    13,   141,   143,   145,   148,   142,   520,    72,   144,
     226,    72,    72,    72,    72,   149,   529,   150,    58,    72,
      72,   507,   151,    72,   240,    72,   120,    72,    72,   281,
     282,   283,   284,   285,   286,    72,   288,   289,   290,   291,
     292,    80,   294,   295,   296,    79,   294,   295,   296,   121,
      58,   303,    80,     5,     5,   245,   343,   349,   310,   311,
     411,   346,   310,   311,   316,   281,   282,   283,   284,   285,
     286,   112,   288,   289,   290,   291,   292,   456,   294,   295,
     296,   333,   401,   522,   470,   402,   476,   303,    -1,    -1,
      -1,    -1,    -1,    -1,   310,   311,    -1,    -1,    -1,    -1,
     316,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   333,    -1,    -1,
      -1,   373,   374,   375,    -1,    -1,   378,   379,    -1,    -1,
     378,   379,    -1,    -1,   386,   387,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,    -1,    -1,   401,
     402,    -1,    -1,    -1,   195,    -1,    -1,   373,   374,   375,
      -1,    -1,   378,   379,    -1,    -1,    -1,    13,    14,    15,
     386,   387,    -1,    -1,    -1,    -1,    -1,   429,   430,    25,
      26,    -1,    -1,    -1,    -1,   401,   402,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,    55,
      56,    57,    58,   429,   430,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,   485,    -1,    -1,    -1,    -1,    84,    -1,
      -1,    -1,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,    -1,    -1,
     106,    -1,   303,    -1,   110,    -1,    -1,    -1,   520,   485,
     522,    -1,    -1,    -1,   526,   316,    -1,   529,   526,    -1,
      -1,    -1,   534,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   333,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   520,    -1,   522,    -1,    -1,    -1,
     526,    -1,    -1,   529,    -1,    -1,    -1,    -1,   534,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   373,   374,   375,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   386,   387,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   220,   221,    -1,    -1,    -1,    -1,
      -1,    -1,   228,   229,   230,   231,   232,    -1,   429,   430,
     236,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   259,   260,   261,   262,   263,   264,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   301,   302,    -1,   304,   305,
     306,   307,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   322,   323,   324,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   534,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   388,    -1,    -1,   391,    -1,    -1,    -1,   395,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     426,   427,   428,    -1,    -1,    -1,    -1,    -1,   434,   435,
     436,   437,     3,     4,    -1,    -1,   442,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,
      -1,    92,    93,    94,    95,    96,    97,    -1,    -1,    -1,
      -1,    -1,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,    -1,    -1,
      -1,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   152,   153,   154,   155,   156,   157,     3,     4,   160,
      -1,    -1,    -1,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    88,    89,    90,    -1,    92,    93,    94,    95,
      96,    97,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    -1,    -1,    -1,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   152,   153,   154,   155,
     156,   157,    -1,    -1,   160,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    75,    76,    77,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    96,    97,    -1,    -1,    -1,    -1,    -1,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    -1,    -1,    -1,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,
     153,   154,   155,   156,   157,    -1,    -1,   160,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,
      90,    -1,    92,    93,    94,    95,    96,    97,    -1,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    -1,
      -1,    -1,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   152,   153,   154,   155,   156,   157,    -1,    -1,
     160,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    88,    89,    90,    -1,    92,    93,    94,    95,    96,
      97,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    -1,    -1,    -1,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   152,   153,   154,   155,   156,
     157,    -1,    -1,   160,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    17,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      74,    75,    76,    77,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    87,    88,    89,    90,    -1,    92,    93,
      94,    95,    96,    97,    -1,    -1,    -1,    -1,    -1,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    -1,    -1,    -1,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,   153,
     154,   155,   156,   157,    -1,    -1,   160,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,    -1,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    75,    76,    77,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    -1,    -1,   100,    -1,
      -1,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     152,   153,   154,   155,   156,   157,    -1,    -1,   160,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    -1,    -1,
     100,    -1,    -1,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    -1,
      -1,    -1,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   152,   153,   154,   155,   156,   157,    -1,    -1,
     160,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      88,    89,    90,    -1,    92,    93,    94,    95,    96,    97,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    -1,    -1,    -1,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   152,   153,   154,   155,   156,   157,
      -1,   159,   160,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    88,    89,    90,    -1,    92,    93,    94,    95,
      96,    97,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    -1,    -1,    -1,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   152,   153,   154,   155,
     156,   157,    -1,   159,   160,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      74,    75,    76,    77,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    87,    88,    89,    90,    -1,    92,    93,
      94,    95,    96,    97,    -1,    -1,    -1,    -1,    -1,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    -1,    -1,    -1,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,   153,
     154,   155,   156,   157,    -1,    -1,   160,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    75,    76,    77,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,    -1,
      92,    93,    94,    95,    96,    97,    -1,    -1,    -1,    -1,
      -1,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     152,   153,   154,   155,   156,   157,    -1,    -1,   160,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,
      90,    -1,    92,    93,    94,    95,    96,    97,    -1,    -1,
     100,    -1,    -1,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    -1,
      -1,    -1,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   152,   153,   154,   155,   156,   157,    -1,    -1,
     160,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      88,    89,    90,    -1,    92,    93,    94,    95,    96,    97,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    -1,    -1,    -1,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   152,   153,   154,   155,   156,   157,
      -1,    -1,   160,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    88,    89,    90,    -1,    92,    93,    94,    95,
      96,    97,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    -1,    -1,    -1,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   152,   153,   154,   155,
     156,   157,    -1,    -1,   160,     9,    10,    11,    12,    -1,
      -1,    15,    -1,    17,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      74,    75,    76,    77,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    87,    88,    89,    90,    -1,    92,    93,
      94,    95,    96,    97,    -1,    -1,    -1,    -1,    -1,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    -1,    -1,    -1,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,   153,
     154,   155,   156,   157,   158,    -1,   160,     9,    10,    11,
      12,    -1,    -1,    15,    -1,    17,    -1,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    75,    76,    77,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,    -1,
      92,    93,    94,    95,    96,    97,    -1,    -1,    -1,    -1,
      -1,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     152,   153,   154,   155,   156,   157,   158,    -1,   160,     9,
      10,    11,    12,    13,    -1,    15,    -1,    17,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,
      90,    -1,    92,    93,    94,    95,    96,    97,    -1,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    -1,
      -1,    -1,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   152,   153,   154,   155,   156,   157,    -1,    -1,
     160,     9,    10,    11,    12,    -1,    -1,    15,    -1,    17,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      88,    89,    90,    -1,    92,    93,    94,    95,    96,    97,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    -1,    -1,    -1,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   152,   153,   154,   155,   156,   157,
      -1,    -1,   160,     9,    10,    11,    12,    -1,    -1,    15,
      -1,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    88,    89,    90,    -1,    92,    93,    94,    95,
      96,    97,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    -1,    -1,    -1,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   152,   153,   154,   155,
     156,   157,    -1,    -1,   160
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     5,     6,     7,   162,   163,   164,   165,     8,     9,
      10,    11,    12,    13,    14,    15,    17,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    58,    73,    74,    75,    76,    77,
      78,    86,    87,    88,    89,    90,    92,    93,    94,    95,
      96,    97,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   152,   153,   154,   155,   156,
     157,   160,   166,   167,   168,   169,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   205,   208,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   248,   249,     8,   166,     0,   164,
     165,   168,   176,   178,   168,   166,   168,    38,    39,    40,
      39,    40,    41,    39,    40,    41,    39,    40,    41,    39,
      40,    41,    39,    40,    39,    40,    39,    40,    39,    40,
     168,   168,    98,    98,    98,    98,   158,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,    15,   112,
      15,   168,   168,   168,   168,    79,    79,    79,    79,   168,
     168,   168,   168,   168,   168,   168,   168,    98,   168,    98,
      98,    98,   168,    72,    72,    79,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
      58,   140,   141,   142,   143,   144,   145,   146,   148,   149,
     150,   151,    15,   168,    72,    72,   158,   168,    98,     8,
     167,    13,    14,   166,    13,    14,    13,    14,   154,     8,
       3,     4,    16,    16,   168,   168,   166,   168,   168,   168,
     168,   168,   168,    13,    14,    15,   221,   222,   221,   168,
      61,    91,   100,   166,   262,   263,   264,   265,   268,   201,
      81,    82,    83,   203,   204,    84,   209,   210,    85,   206,
     207,   168,   168,   168,   168,   168,   168,   119,    56,    79,
     262,   262,   262,   262,   262,   262,    99,   147,   262,   262,
     262,   262,   262,   166,   166,   166,   168,   168,     3,     4,
      18,   170,   168,   168,   168,   168,   166,   166,   159,   168,
     168,    13,   168,   221,   222,    16,    15,    15,    15,    15,
      16,    60,    59,    80,    80,   204,    80,   210,    80,   207,
      80,    79,    57,   247,   139,   139,   139,   139,   139,   139,
     147,   139,   139,   139,   139,    16,   159,    14,    13,   166,
     166,    38,    39,    41,    14,    13,    14,    13,    16,    16,
     168,   168,    13,    16,   168,   221,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   253,   254,
     266,   267,   101,   102,   253,   254,   269,   270,   271,   272,
     263,   268,    79,   247,    57,    80,   140,   141,   142,   143,
     144,   145,   148,   149,   150,   151,   112,   168,   168,   168,
     170,   170,   168,   168,   168,   168,   168,    15,   112,    16,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      16,   251,    16,   267,    72,    72,    16,   270,   120,    80,
     262,   221,   262,   264,   166,    80,   262,   139,    16,    16,
      79,   139,    58,   121,    58,    80
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
  char * s = itex2MML_copy3("<math xmlns='http://www.w3.org/1998/Math/MathML' display='inline'>", (yyvsp[(2) - (3)]), "</math>");
  itex2MML_free_string((yyvsp[(2) - (3)]));
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
#line 310 "itex2MML.y"
    {
  char ** r = (char **) ret_str;
  char * s = itex2MML_copy3("<math xmlns='http://www.w3.org/1998/Math/MathML' display='block'>", (yyvsp[(2) - (3)]), "</math>");
  itex2MML_free_string((yyvsp[(2) - (3)]));
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
#line 324 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 14:
#line 328 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(1) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 15:
#line 334 "itex2MML.y"
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
#line 353 "itex2MML.y"
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
#line 367 "itex2MML.y"
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
#line 386 "itex2MML.y"
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
#line 400 "itex2MML.y"
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
#line 419 "itex2MML.y"
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
#line 433 "itex2MML.y"
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
#line 452 "itex2MML.y"
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
#line 466 "itex2MML.y"
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
#line 476 "itex2MML.y"
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
#line 486 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<msub>", (yyvsp[(1) - (3)]), " ");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(3) - (3)]), "</msub>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(1) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 26:
#line 493 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<msup>", (yyvsp[(1) - (3)]), " ");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(3) - (3)]), "</msup>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(1) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 27:
#line 500 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<msub><mo></mo>", (yyvsp[(2) - (2)]), "</msub>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 28:
#line 504 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<msup><mo></mo>", (yyvsp[(2) - (2)]), "</msup>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 29:
#line 508 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 34:
#line 517 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mi>", (yyvsp[(1) - (1)]), "</mi>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 35:
#line 521 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mn>", (yyvsp[(1) - (1)]), "</mn>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 94:
#line 583 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(2) - (3)]));
}
    break;

  case 95:
#line 587 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow>", (yyvsp[(2) - (3)]), "</mrow>");
  itex2MML_free_string((yyvsp[(2) - (3)]));
}
    break;

  case 96:
#line 591 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mrow>", (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]));
  (yyval) = itex2MML_copy3(s1, (yyvsp[(3) - (3)]), "</mrow>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(1) - (3)]));
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 101:
#line 604 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo>", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 102:
#line 609 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo>", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 103:
#line 614 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy_string("");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 104:
#line 620 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo>", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 105:
#line 624 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo>", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 106:
#line 628 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 107:
#line 633 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.2em\" minsize=\"1.2em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 108:
#line 638 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.2em\" minsize=\"1.2em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 109:
#line 642 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.2em\" minsize=\"1.2em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 110:
#line 646 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.8em\" minsize=\"1.8em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 111:
#line 651 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.8em\" minsize=\"1.8em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 112:
#line 655 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.8em\" minsize=\"1.8em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 113:
#line 659 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"2.4em\" minsize=\"2.4em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 114:
#line 664 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo maxsize=\"2.4em\" minsize=\"2.4em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 115:
#line 668 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo maxsize=\"2.4em\" minsize=\"2.4em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 116:
#line 672 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"3em\" minsize=\"3em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 117:
#line 677 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo maxsize=\"3em\" minsize=\"3em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 118:
#line 681 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo maxsize=\"3em\" minsize=\"3em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 119:
#line 685 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.2em\" minsize=\"1.2em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 120:
#line 690 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.2em\" minsize=\"1.2em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 121:
#line 695 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.8em\" minsize=\"1.8em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 122:
#line 700 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.8em\" minsize=\"1.8em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 123:
#line 705 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"2.4em\" minsize=\"2.4em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 124:
#line 710 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"2.4em\" minsize=\"2.4em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 125:
#line 715 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"3em\" minsize=\"3em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 126:
#line 720 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"3em\" minsize=\"3em\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 127:
#line 726 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<merror><mtext>Unknown character</mtext></merror>");
}
    break;

  case 128:
#line 730 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mo lspace=\"verythinmathspace\" rspace=\"0em\">&minus;</mo>");
}
    break;

  case 129:
#line 734 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mo lspace=\"verythinmathspace\" rspace=\"0em\">+</mo>");
}
    break;

  case 131:
#line 740 "itex2MML.y"
    {
  itex2MML_rowposn=2;
  (yyval) = itex2MML_copy3("<mi>", (yyvsp[(1) - (1)]), "</mi>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 133:
#line 747 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy_string((yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 134:
#line 753 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo lspace=\"thinmathspace\" rspace=\"thinmathspace\">", (yyvsp[(1) - (1)]), "</mo>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 137:
#line 761 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo>", (yyvsp[(1) - (1)]), "</mo>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 138:
#line 766 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo>", (yyvsp[(1) - (1)]), "</mo>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 139:
#line 771 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mstyle scriptlevel=\"0\"><mo>", (yyvsp[(1) - (1)]), "</mo></mstyle>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 140:
#line 776 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo stretchy=\"false\">", (yyvsp[(1) - (1)]), "</mo>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 141:
#line 780 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo stretchy=\"false\">", (yyvsp[(1) - (1)]), "</mo>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 142:
#line 785 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo stretchy=\"false\">", (yyvsp[(1) - (1)]), "</mo>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 143:
#line 789 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo stretchy=\"false\">", (yyvsp[(1) - (1)]), "</mo>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 144:
#line 793 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo>", (yyvsp[(1) - (1)]), "</mo>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 145:
#line 797 "itex2MML.y"
    {
  itex2MML_rowposn=2;
  (yyval) = itex2MML_copy3("<mo lspace=\"mediummathspace\" rspace=\"mediummathspace\">", (yyvsp[(1) - (1)]), "</mo>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 146:
#line 802 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo lspace=\"0em\" rspace=\"thinmathspace\">", (yyvsp[(1) - (1)]), "</mo>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 147:
#line 807 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo lspace=\"verythinmathspace\">", (yyvsp[(1) - (1)]), "</mo>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 148:
#line 812 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo lspace=\"0em\" rspace=\"thinmathspace\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 149:
#line 817 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo lspace=\"thinmathspace\" rspace=\"thinmathspace\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 150:
#line 822 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo lspace=\"mediummathspace\" rspace=\"mediummathspace\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 151:
#line 827 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo lspace=\"thickmathspace\" rspace=\"thickmathspace\">", (yyvsp[(2) - (2)]), "</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 152:
#line 833 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mspace height=\"", (yyvsp[(3) - (10)]), "ex\" depth=\"");
  char * s2 = itex2MML_copy3((yyvsp[(6) - (10)]), "ex\" width=\"", (yyvsp[(9) - (10)]));
  (yyval) = itex2MML_copy3(s1, s2, "em\"></mspace>");
  itex2MML_free_string(s1);
  itex2MML_free_string(s2);
  itex2MML_free_string((yyvsp[(3) - (10)]));
  itex2MML_free_string((yyvsp[(6) - (10)]));
  itex2MML_free_string((yyvsp[(9) - (10)]));
}
    break;

  case 153:
#line 844 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<maction actiontype=\"statusline\">", (yyvsp[(3) - (3)]), "<mtext>");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(2) - (3)]), "</mtext></maction>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 154:
#line 852 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<maction actiontype=\"tooltip\">", (yyvsp[(3) - (3)]), "<mtext>");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(2) - (3)]), "</mtext></maction>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 155:
#line 860 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<maction actiontype=\"toggle\" selection=\"2\">", (yyvsp[(2) - (3)]), " ");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(3) - (3)]), "</maction>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 156:
#line 868 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<maction actiontype=\"highlight\" other='color=", (yyvsp[(2) - (3)]), "'>");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(3) - (3)]), "</maction>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 157:
#line 876 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<maction actiontype=\"highlight\" other='background=", (yyvsp[(2) - (3)]), "'>");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(3) - (3)]), "</maction>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 158:
#line 884 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mstyle mathcolor=", (yyvsp[(2) - (3)]), ">");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(3) - (3)]), "</mstyle>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 159:
#line 891 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mstyle mathbackground=", (yyvsp[(2) - (3)]), ">");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(3) - (3)]), "</mstyle>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 160:
#line 899 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mpadded width=\"0\">", (yyvsp[(2) - (2)]), "</mpadded>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 161:
#line 904 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mpadded width=\"0\" lspace=\"-100%width\">", (yyvsp[(2) - (2)]), "</mpadded>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 162:
#line 909 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mpadded width=\"0\" lspace=\"-50%width\">", (yyvsp[(2) - (2)]), "</mpadded>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 163:
#line 914 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mtext>", (yyvsp[(2) - (2)]), "</mtext>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 164:
#line 919 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mstyle displaystyle=\"true\">", (yyvsp[(2) - (2)]), "</mstyle>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 165:
#line 924 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mstyle displaystyle=\"false\">", (yyvsp[(2) - (2)]), "</mstyle>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 166:
#line 929 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mstyle scriptlevel=\"0\">", (yyvsp[(2) - (2)]), "</mstyle>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 167:
#line 934 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mstyle scriptlevel=\"1\">", (yyvsp[(2) - (2)]), "</mstyle>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 168:
#line 939 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mstyle scriptlevel=\"2\">", (yyvsp[(2) - (2)]), "</mstyle>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 169:
#line 944 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mstyle mathvariant=\"italic\">", (yyvsp[(2) - (2)]), "</mstyle>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 170:
#line 949 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<menclose notation=\"updiagonalstrike\">", (yyvsp[(2) - (2)]), "</menclose>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 171:
#line 954 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<menclose notation=\"box\">", (yyvsp[(2) - (2)]), "</menclose>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 172:
#line 959 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mstyle mathvariant=\"bold\">", (yyvsp[(2) - (2)]), "</mstyle>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 173:
#line 964 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mi mathvariant=\"normal\">", (yyvsp[(3) - (4)]), "</mi>");
  itex2MML_free_string((yyvsp[(3) - (4)]));
}
    break;

  case 174:
#line 969 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 175:
#line 973 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(1) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 176:
#line 979 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mi>", (yyvsp[(3) - (4)]), "</mi>");
  itex2MML_free_string((yyvsp[(3) - (4)]));
}
    break;

  case 177:
#line 984 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 178:
#line 988 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(1) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 179:
#line 994 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("&", (yyvsp[(1) - (1)]), "opf;");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 180:
#line 998 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("&", (yyvsp[(1) - (1)]), "opf;");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 181:
#line 1002 "itex2MML.y"
    {
  /* Blackboard digits 0-9 correspond to Unicode characters 0x1D7D8-0x1D7E1 */
  char * end = (yyvsp[(1) - (1)]) + 1;
  int code = 0x1D7D8 + strtoul((yyvsp[(1) - (1)]), &end, 10);
  (yyval) = itex2MML_character_reference(code);
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 182:
#line 1010 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mi>", (yyvsp[(3) - (4)]), "</mi>");
  itex2MML_free_string((yyvsp[(3) - (4)]));
}
    break;

  case 183:
#line 1015 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 184:
#line 1019 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(1) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 185:
#line 1025 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("&", (yyvsp[(1) - (1)]), "fr;");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 186:
#line 1030 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mi>", (yyvsp[(3) - (4)]), "</mi>");
  itex2MML_free_string((yyvsp[(3) - (4)]));
}
    break;

  case 187:
#line 1035 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 188:
#line 1039 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(1) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 189:
#line 1045 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("&", (yyvsp[(1) - (1)]), "scr;");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 190:
#line 1050 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mspace width=\"thinmathspace\"></mspace>");
}
    break;

  case 191:
#line 1054 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mspace width=\"mediummathspace\"></mspace>");
}
    break;

  case 192:
#line 1058 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mspace width=\"thickmathspace\"></mspace>");
}
    break;

  case 193:
#line 1062 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mspace width=\"1em\"></mspace>");
}
    break;

  case 194:
#line 1066 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mspace width=\"2em\"></mspace>");
}
    break;

  case 195:
#line 1070 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mspace width=\"-0.1667 em\"></mspace>");
}
    break;

  case 196:
#line 1074 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mphantom>", (yyvsp[(2) - (2)]), "</mphantom>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 197:
#line 1079 "itex2MML.y"
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

  case 198:
#line 1089 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mmultiscripts>", (yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
  (yyval) = itex2MML_copy2(s1, "</mmultiscripts>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (5)]));
  itex2MML_free_string((yyvsp[(4) - (5)]));
}
    break;

  case 199:
#line 1096 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mmultiscripts>", (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  (yyval) = itex2MML_copy2(s1, "</mmultiscripts>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 200:
#line 1104 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mmultiscripts>", (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
  char * s2 = itex2MML_copy3("<mprescripts></mprescripts>", (yyvsp[(3) - (8)]), "</mmultiscripts>");
  (yyval) = itex2MML_copy2(s1, s2);
  itex2MML_free_string(s1);
  itex2MML_free_string(s2);
  itex2MML_free_string((yyvsp[(3) - (8)]));
  itex2MML_free_string((yyvsp[(5) - (8)]));
  itex2MML_free_string((yyvsp[(7) - (8)]));
}
    break;

  case 201:
#line 1114 "itex2MML.y"
    {
  char * s1 = itex2MML_copy2("<mmultiscripts>", (yyvsp[(5) - (6)]));
  char * s2 = itex2MML_copy3("<mprescripts></mprescripts>", (yyvsp[(3) - (6)]), "</mmultiscripts>");
  (yyval) = itex2MML_copy2(s1, s2);
  itex2MML_free_string(s1);
  itex2MML_free_string(s2);
  itex2MML_free_string((yyvsp[(3) - (6)]));
  itex2MML_free_string((yyvsp[(5) - (6)]));
}
    break;

  case 202:
#line 1123 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mmultiscripts>", (yyvsp[(3) - (6)]), (yyvsp[(5) - (6)]));
  (yyval) = itex2MML_copy2(s1, "</mmultiscripts>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(3) - (6)]));
  itex2MML_free_string((yyvsp[(5) - (6)])); 
}
    break;

  case 203:
#line 1131 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 204:
#line 1135 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3((yyvsp[(1) - (2)]), " ", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(1) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 205:
#line 1141 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3((yyvsp[(2) - (4)]), " ", (yyvsp[(4) - (4)]));
  itex2MML_free_string((yyvsp[(2) - (4)]));
  itex2MML_free_string((yyvsp[(4) - (4)]));
}
    break;

  case 206:
#line 1146 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2((yyvsp[(2) - (2)]), " <none></none>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 207:
#line 1150 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("<none></none> ", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 208:
#line 1154 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("<none></none> ", (yyvsp[(3) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 209:
#line 1159 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mfrac>", (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  (yyval) = itex2MML_copy2(s1, "</mfrac>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 210:
#line 1166 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mstyle displaystyle=\"false\"><mfrac>", (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  (yyval) = itex2MML_copy2(s1, "</mfrac></mstyle>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 211:
#line 1174 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3( "<mo lspace=\"mediummathspace\">(</mo><mo rspace=\"thinmathspace\">mod</mo>", (yyvsp[(2) - (2)]), "<mo rspace=\"mediummathspace\">)</mo>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 212:
#line 1179 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mfrac><mrow>", (yyvsp[(2) - (5)]), "</mrow><mrow>");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(4) - (5)]), "</mrow></mfrac>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (5)]));
  itex2MML_free_string((yyvsp[(4) - (5)]));
}
    break;

  case 213:
#line 1186 "itex2MML.y"
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

  case 214:
#line 1200 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mfrac linethickness=\"0\"><mrow>", (yyvsp[(2) - (5)]), "</mrow><mrow>");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(4) - (5)]), "</mrow></mfrac>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (5)]));
  itex2MML_free_string((yyvsp[(4) - (5)]));
}
    break;

  case 215:
#line 1207 "itex2MML.y"
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

  case 216:
#line 1221 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mrow><mo>(</mo><mfrac linethickness=\"0\">", (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  (yyval) = itex2MML_copy2(s1, "</mfrac><mo>)</mo></mrow>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 217:
#line 1228 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mrow><mo>(</mo><mstyle displaystyle=\"false\"><mfrac linethickness=\"0\">", (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  (yyval) = itex2MML_copy2(s1, "</mfrac></mstyle><mo>)</mo></mrow>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 218:
#line 1236 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<munder>", (yyvsp[(2) - (2)]), "<mo>&UnderBrace;</mo></munder>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 219:
#line 1241 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<munder>", (yyvsp[(2) - (2)]), "<mo>&#x00332;</mo></munder>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 220:
#line 1246 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo>&OverBrace;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 221:
#line 1251 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo stretchy=\"false\">&#x000AF;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 222:
#line 1255 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo>&#x000AF;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 223:
#line 1260 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo stretchy=\"false\">&RightVector;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 224:
#line 1264 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo>&RightVector;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 225:
#line 1269 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo>&dot;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 226:
#line 1274 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo>&Dot;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 227:
#line 1279 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo>&tdot;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 228:
#line 1284 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo>&DotDot;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 229:
#line 1289 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo stretchy=\"false\">&tilde;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 230:
#line 1293 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo>&tilde;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 231:
#line 1298 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo stretchy=\"false\">&#x2c7;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 232:
#line 1302 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo>&#x2c7;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 233:
#line 1307 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo stretchy=\"false\">&#x5E;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 234:
#line 1311 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[(2) - (2)]), "<mo>&#x5E;</mo></mover>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 235:
#line 1316 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<msqrt>", (yyvsp[(2) - (2)]), "</msqrt>");
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 236:
#line 1321 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mroot>", (yyvsp[(5) - (5)]), (yyvsp[(3) - (5)]));
  (yyval) = itex2MML_copy2(s1, "</mroot>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(3) - (5)]));
  itex2MML_free_string((yyvsp[(5) - (5)]));
}
    break;

  case 237:
#line 1328 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mroot>", (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]));
  (yyval) = itex2MML_copy2(s1, "</mroot>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 238:
#line 1336 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<munder><mo>", (yyvsp[(1) - (5)]), "</mo><mrow>");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(3) - (5)]), "</mrow></munder>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(1) - (5)]));
  itex2MML_free_string((yyvsp[(3) - (5)]));
}
    break;

  case 239:
#line 1343 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<munder>", (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]));
  (yyval) = itex2MML_copy2(s1, "</munder>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 240:
#line 1351 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mover><mo>", (yyvsp[(1) - (2)]), "</mo>");
  (yyval) =  itex2MML_copy3(s1, (yyvsp[(2) - (2)]), "</mover>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(1) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 241:
#line 1358 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mover>", (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]));
  (yyval) = itex2MML_copy2(s1, "</mover>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 242:
#line 1366 "itex2MML.y"
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

  case 243:
#line 1376 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<munderover>", (yyvsp[(4) - (4)]), (yyvsp[(2) - (4)]));
  (yyval) = itex2MML_copy3(s1, (yyvsp[(3) - (4)]), "</munderover>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (4)]));
  itex2MML_free_string((yyvsp[(3) - (4)]));
  itex2MML_free_string((yyvsp[(4) - (4)]));
}
    break;

  case 244:
#line 1385 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mrow></mrow>");
}
    break;

  case 245:
#line 1389 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mtable rowspacing=\"0.5ex\">", (yyvsp[(3) - (5)]), "</mtable></mrow>");
  itex2MML_free_string((yyvsp[(3) - (5)]));
}
    break;

  case 246:
#line 1393 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mtable rowspacing=\"1.0ex\">", (yyvsp[(3) - (5)]), "</mtable></mrow>");
  itex2MML_free_string((yyvsp[(3) - (5)]));
}
    break;

  case 247:
#line 1397 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mo>(</mo><mrow><mtable rowspacing=\"0.5ex\">", (yyvsp[(3) - (5)]), "</mtable></mrow><mo>)</mo></mrow>");
  itex2MML_free_string((yyvsp[(3) - (5)]));
}
    break;

  case 248:
#line 1401 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mo>[</mo><mrow><mtable rowspacing=\"0.5ex\">", (yyvsp[(3) - (5)]), "</mtable></mrow><mo>]</mo></mrow>");
  itex2MML_free_string((yyvsp[(3) - (5)]));
}
    break;

  case 249:
#line 1405 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mo>&VerticalBar;</mo><mrow><mtable rowspacing=\"0.5ex\">", (yyvsp[(3) - (5)]), "</mtable></mrow><mo>&VerticalBar;</mo></mrow>");
  itex2MML_free_string((yyvsp[(3) - (5)]));
}
    break;

  case 250:
#line 1409 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mo>{</mo><mrow><mtable rowspacing=\"0.5ex\">", (yyvsp[(3) - (5)]), "</mtable></mrow><mo>}</mo></mrow>");
  itex2MML_free_string((yyvsp[(3) - (5)]));
}
    break;

  case 251:
#line 1413 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mo>&DoubleVerticalBar;</mo><mrow><mtable rowspacing=\"0.5ex\">", (yyvsp[(3) - (5)]), "</mtable></mrow><mo>&DoubleVerticalBar;</mo></mrow>");
  itex2MML_free_string((yyvsp[(3) - (5)]));
}
    break;

  case 252:
#line 1417 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mstyle scriptlevel=\"2\"><mrow><mtable rowspacing=\"0.5ex\">", (yyvsp[(3) - (5)]), "</mtable></mrow></mstyle>");
  itex2MML_free_string((yyvsp[(3) - (5)]));
}
    break;

  case 253:
#line 1421 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mo>{</mo><mrow><mtable columnalign=\"left left\">", (yyvsp[(3) - (5)]), "</mtable></mrow></mrow>");
  itex2MML_free_string((yyvsp[(3) - (5)]));
}
    break;

  case 254:
#line 1425 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mtable columnalign=\"right left right left right left right left right left\" columnspacing=\"0em\">", (yyvsp[(3) - (5)]), "</mtable></mrow>");
  itex2MML_free_string((yyvsp[(3) - (5)]));
}
    break;

  case 255:
#line 1429 "itex2MML.y"
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

  case 256:
#line 1439 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mtable rowspacing=\"0.5ex\" columnalign=\"", (yyvsp[(4) - (8)]), "\">");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(6) - (8)]), "</mtable>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(4) - (8)]));
  itex2MML_free_string((yyvsp[(6) - (8)]));
}
    break;

  case 257:
#line 1446 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<semantics><annotation-xml encoding=\"SVG1.1\">", (yyvsp[(3) - (4)]), "</annotation-xml></semantics>");
  itex2MML_free_string((yyvsp[(3) - (4)]));
}
    break;

  case 258:
#line 1450 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string(" ");
}
    break;

  case 259:
#line 1454 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3((yyvsp[(1) - (2)]), " ", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(1) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 260:
#line 1459 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 261:
#line 1464 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mtable columnalign=\"center\" rowspacing=\"0.5ex\">", (yyvsp[(3) - (4)]), "</mtable></mrow>");
  itex2MML_free_string((yyvsp[(3) - (4)]));
}
    break;

  case 262:
#line 1469 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mtable>", (yyvsp[(3) - (4)]), "</mtable></mrow>");
  itex2MML_free_string((yyvsp[(3) - (4)]));
}
    break;

  case 263:
#line 1473 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mrow><mtable ", (yyvsp[(5) - (8)]), ">");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(7) - (8)]), "</mtable></mrow>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(5) - (8)]));
  itex2MML_free_string((yyvsp[(7) - (8)]));
}
    break;

  case 264:
#line 1481 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 265:
#line 1485 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3((yyvsp[(1) - (2)]), " ", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(1) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 266:
#line 1491 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 267:
#line 1495 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 268:
#line 1499 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 269:
#line 1503 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 270:
#line 1507 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 271:
#line 1511 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 272:
#line 1515 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 273:
#line 1519 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 274:
#line 1523 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 275:
#line 1527 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 276:
#line 1532 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("columnalign=", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 277:
#line 1537 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("columnalign=", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 278:
#line 1542 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("rowalign=", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 279:
#line 1547 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("align=", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 280:
#line 1552 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("equalrows=", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 281:
#line 1557 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("equalcolumns=", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 282:
#line 1562 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("rowlines=", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 283:
#line 1567 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("columnlines=", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 284:
#line 1572 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("frame=", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 285:
#line 1577 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("rowspacing=", (yyvsp[(2) - (2)]), " columnspacing=");
  (yyval) = itex2MML_copy2(s1, (yyvsp[(2) - (2)]));
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 286:
#line 1584 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 287:
#line 1588 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3((yyvsp[(1) - (3)]), " ", (yyvsp[(3) - (3)]));
  itex2MML_free_string((yyvsp[(1) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 288:
#line 1594 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mtr>", (yyvsp[(1) - (1)]), "</mtr>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 289:
#line 1598 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 290:
#line 1603 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 291:
#line 1607 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3((yyvsp[(1) - (3)]), " ", (yyvsp[(3) - (3)]));
  itex2MML_free_string((yyvsp[(1) - (3)]));
  itex2MML_free_string((yyvsp[(3) - (3)]));
}
    break;

  case 292:
#line 1613 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mtr ", (yyvsp[(3) - (5)]), ">");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(5) - (5)]), "</mtr>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(3) - (5)]));
  itex2MML_free_string((yyvsp[(5) - (5)]));
}
    break;

  case 293:
#line 1621 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 294:
#line 1625 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3((yyvsp[(1) - (2)]), " ", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(1) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 295:
#line 1631 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 296:
#line 1635 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 297:
#line 1640 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mtd></mtd>");
}
    break;

  case 298:
#line 1643 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mtd>", (yyvsp[(1) - (1)]), "</mtd>");
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 299:
#line 1647 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mtd ", (yyvsp[(3) - (5)]), ">");
  (yyval) = itex2MML_copy3(s1, (yyvsp[(5) - (5)]), "</mtd>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[(3) - (5)]));
  itex2MML_free_string((yyvsp[(5) - (5)]));
}
    break;

  case 300:
#line 1655 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 301:
#line 1659 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3((yyvsp[(1) - (2)]), " ", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(1) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 302:
#line 1665 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 303:
#line 1669 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 304:
#line 1673 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 305:
#line 1677 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[(1) - (1)]));
  itex2MML_free_string((yyvsp[(1) - (1)]));
}
    break;

  case 306:
#line 1682 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("rowspan=", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;

  case 307:
#line 1687 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("columnspan=", (yyvsp[(2) - (2)]));
  itex2MML_free_string((yyvsp[(2) - (2)]));
}
    break;


/* Line 1267 of yacc.c.  */
#line 5306 "y.tab.c"
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


#line 1692 "itex2MML.y"


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

