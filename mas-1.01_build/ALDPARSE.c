#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_MASSYM2
#include "MASSYM2.h"
#endif

#ifndef DEFINITION_MASSYM
#include "MASSYM.h"
#endif

#ifndef DEFINITION_MASLISPU
#include "MASLISPU.h"
#endif

#ifndef DEFINITION_MASLISP
#include "MASLISP.h"
#endif

#ifndef DEFINITION_MASSPEC
#include "MASSPEC.h"
#endif

#ifndef DEFINITION_ALDPARSE
#include "ALDPARSE.h"
#endif

CHAR ALDPARSE_rcsid [] = "$Id: ALDPARSE.md,v 1.2 1992/02/12 17:32:18 pesch Exp $";
CHAR ALDPARSE_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: ALDPARSE.mi,v 1.4 1992/10/15 16:27:45 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
#define null	0
#define not	1
#define and	2
#define or	3
#define times	4
#define div	5
#define mod	6
#define plus	7
#define minus	8
#define power	9
#define eql	10
#define neq	11
#define lss	12
#define leq	13
#define gtr	14
#define geq	15
#define sil	16
#define comma	17
#define rparen	18
#define colon	19
#define lbrack	20
#define rbrack	21
#define rbrace	22
#define becomes	23
#define then	24
#define C_20_else	25
#define to	26
#define To	27
#define of	28
#define C_21_do	29
#define lparen	30
#define dollar	31
#define quote	32
#define string	33
#define number	34
#define ident	35
#define lbrace	36
#define label	37
#define procedure	38
#define C_22_return	39
#define print	40
#define C_23_goto	41
#define go	42
#define C_24_if	43
#define C_25_case	44
#define semicolon	45
#define C_26_while	46
#define repeat	47
#define until	48
#define C_27_for	49
#define begald	50
#define begin	51
#define var	52
#define pragma	53
#define const	54
#define global	55
#define safe	56
#define array	57
#define intrinsic	58
#define period	59
#define end	60
#define eof	61
typedef unsigned char Token;
static Token tok;
static MASSTOR_LIST tokval, zwischen;
static CHAR c, ch;
static MASSTOR_LIST ach;
static MASSTOR_LIST KW;
static BOOLEAN noerr, isfunc;
static MASSTOR_LIST prnt, ret, any, prag;
static MASSTOR_LIST blv;
static void FIRST5 ARGS((MASSTOR_LIST L, MASSTOR_LIST *AL1, MASSTOR_LIST *AL2, MASSTOR_LIST *AL3, MASSTOR_LIST *AL4, MASSTOR_LIST *AL5));
static void SyntaxWarning ARGS((MASSTOR_LIST n));
static void SyntaxError ARGS((MASSTOR_LIST n));
static void SyntaxTest ARGS((Token s, MASSTOR_LIST n));
static void KeyWord ARGS((Token s, CHAR S[], LONGCARD ));
static void GetCh ARGS(());
static MASSTOR_LIST GetString ARGS(());
static MASSTOR_LIST GetIdent ARGS(());
static MASSTOR_LIST Comment ARGS(());
static void GetTok ARGS(());
static MASSTOR_LIST Program ARGS(());
static MASSTOR_LIST Algorithm ARGS(());
static MASSTOR_LIST Declaration ARGS(());
static MASSTOR_LIST Header ARGS((BOOLEAN *func));
static MASSTOR_LIST Sequence ARGS(());
static MASSTOR_LIST Statement ARGS(());
static MASSTOR_LIST PrintStat ARGS(());
static MASSTOR_LIST GotoStat ARGS(());
static MASSTOR_LIST GoStat ARGS(());
static MASSTOR_LIST IfStat ARGS(());
static MASSTOR_LIST CaseStat ARGS(());
static MASSTOR_LIST WhileStat ARGS(());
static MASSTOR_LIST RepeatStat ARGS(());
static MASSTOR_LIST ForStat ARGS(());
static MASSTOR_LIST IdentStat ARGS(());
static MASSTOR_LIST GlobDec ARGS(());
static MASSTOR_LIST IntrinsicDec ARGS(());
static MASSTOR_LIST PrCoDec ARGS(());
static MASSTOR_LIST ArrayDec ARGS(());
static MASSTOR_LIST CondSeq ARGS(());
static MASSTOR_LIST Condition ARGS(());
static MASSTOR_LIST IdentifierList ARGS(());
static MASSTOR_LIST TermList ARGS(());
static MASSTOR_LIST Expression ARGS(());
static MASSTOR_LIST Term ARGS(());
static MASSTOR_LIST Factor ARGS(());
static MASSTOR_LIST Potency ARGS(());
static MASSTOR_LIST Variable ARGS(());
static MASSTOR_LIST Generate ARGS((Token s, MASSTOR_LIST t));
static MASSTOR_LIST Genfor ARGS((MASSTOR_LIST t));
static MASSTOR_LIST CaseLabel ARGS((MASSTOR_LIST v));
static void InitAscanner ARGS(());
static void InitAparser ARGS(());


static void FIRST5
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST *AL1, MASSTOR_LIST *AL2, MASSTOR_LIST *AL3, MASSTOR_LIST *AL4, MASSTOR_LIST *AL5)
# else
(L, AL1, AL2, AL3, AL4, AL5)
MASSTOR_LIST L;
MASSTOR_LIST *AL1, *AL2, *AL3, *AL4, *AL5;
# endif
{
  MASSTOR_LIST LP;

  MASSTOR_ADV(L, AL1, &LP);
  MASSTOR_ADV(LP, AL2, &LP);
  MASSTOR_ADV(LP, AL3, &LP);
  MASSTOR_ADV(LP, AL4, &LP);
  *AL5 = MASSTOR_FIRST(LP);
  return;
}

static void SyntaxWarning
# ifdef __STDC__
(MASSTOR_LIST n)
# else
(n)
MASSTOR_LIST n;
# endif
{
  INTEGER m;

  MASBIOS_SWRITE("[", 1L);
  SACLIST_AWRITE(n);
  MASBIOS_SWRITE("] ", 2L);
  m = (INTEGER)n;
  MASBIOS_SWRITE("Syntax warning: ", 16L);
  switch (m) {
  case 2:;
    MASBIOS_SWRITE("intrinsic declaration", 21L);
    break;
  case 3:;
    MASBIOS_SWRITE("pragma declaration", 18L);
    break;
  case 6:;
    MASBIOS_SWRITE(". in header", 11L);
    break;
  case 7:;
    MASBIOS_SWRITE("array as function", 17L);
    break;
  case 8:;
    MASBIOS_SWRITE("global declaration in algorithm", 31L);
    break;
  case 9:;
    MASBIOS_SWRITE("const declaration", 17L);
    break;
  default :
    MASBIOS_SWRITE("???", 3L);
    break;
  }
  MASBIOS_SWRITE(" unsupported.", 13L);
  MASBIOS_DIBUFF();
}

static void SyntaxError
# ifdef __STDC__
(MASSTOR_LIST n)
# else
(n)
MASSTOR_LIST n;
# endif
{
  INTEGER m;

  MASBIOS_SWRITE("[", 1L);
  SACLIST_AWRITE(n);
  MASBIOS_SWRITE("] ", 2L);
  m = (INTEGER)n;
  noerr = FALSE;
  switch (m) {
  case 1:;
    MASBIOS_SWRITE("identifier", 10L);
    break;
  case 2:;
    MASBIOS_SWRITE(")", 1L);
    break;
  case 3:;
    MASBIOS_SWRITE("factor", 6L);
    break;
  case 4:;
    MASBIOS_SWRITE("operator", 8L);
    break;
  case 5:;
    MASBIOS_SWRITE(", or )", 6L);
    break;
  case 6:;
    MASBIOS_SWRITE("variable", 8L);
    break;
  case 7:;
    MASBIOS_SWRITE(", or ;", 6L);
    break;
  case 8:;
    MASBIOS_SWRITE("declaration", 11L);
    break;
  case 9:;
    MASBIOS_SWRITE("=", 1L);
    break;
  case 10:;
    MASBIOS_SWRITE(", or .", 6L);
    break;
  case 11:;
    MASBIOS_SWRITE("[", 1L);
    break;
  case 12:;
    MASBIOS_SWRITE("]", 1L);
    break;
  case 13:;
    MASBIOS_SWRITE("string", 6L);
    break;
  case 14:;
    MASBIOS_SWRITE("number", 6L);
    break;
  case 15:;
    MASBIOS_SWRITE("to", 2L);
    break;
  case 16:;
    MASBIOS_SWRITE("then", 4L);
    break;
  case 17:;
    MASBIOS_SWRITE("of", 2L);
    break;
  case 18:;
    MASBIOS_SWRITE("{", 1L);
    break;
  case 19:;
    MASBIOS_SWRITE("; or }", 6L);
    break;
  case 20:;
    MASBIOS_SWRITE("do", 2L);
    break;
  case 21:;
    MASBIOS_SWRITE(":=", 2L);
    break;
  case 22:;
    MASBIOS_SWRITE(",...,", 5L);
    break;
  case 23:;
    MASBIOS_SWRITE(", or ,...,", 10L);
    break;
  case 24:;
    MASBIOS_SWRITE("(", 1L);
    break;
  case 25:;
    MASBIOS_SWRITE("||", 2L);
    break;
  case 26:;
    MASBIOS_SWRITE("statement", 9L);
    break;
  case 27:;
    MASBIOS_SWRITE("}", 1L);
    break;
  case 28:;
    MASBIOS_SWRITE("} or ;", 6L);
    break;
  case 29:;
    MASBIOS_SWRITE("; or until", 10L);
    break;
  case 30:;
    MASBIOS_SWRITE("and or or un-", 13L);
    break;
  case 31:;
    MASBIOS_SWRITE("/ un-", 5L);
    break;
  case 32:;
    MASBIOS_SWRITE("| un-", 5L);
    break;
  case 33:;
    MASBIOS_SWRITE("= or :=", 7L);
    break;
  case 34:;
    MASBIOS_SWRITE("expression", 10L);
    break;
  case 35:;
    MASBIOS_SWRITE(", or identifier", 15L);
    break;
  case 36:;
    MASBIOS_SWRITE("declaration or algorithm", 24L);
    break;
  case 37:;
    MASBIOS_SWRITE(".", 1L);
    break;
  default :
    MASBIOS_SWRITE("don't know what is", 18L);
    break;
  }
  MASBIOS_SWRITE(" expected ", 10L);
  MASBIOS_DIBUFF();
}

static void SyntaxTest
# ifdef __STDC__
(Token s, MASSTOR_LIST n)
# else
(s, n)
Token s;
MASSTOR_LIST n;
# endif
{
  INTEGER m;

  if (tok < s) {
    SyntaxError(n);
    do {
      GetTok();
    } while (!(tok >= s));
  }
}

static void KeyWord
# ifdef __STDC__
(Token s, CHAR S[], LONGCARD O_1)
# else
(s, S, O_1)
Token s;
CHAR S[];
LONGCARD O_1;
# endif
{
  MASSTOR_LIST X, P;

  X = MASSYM2_ENTER(MASBIOS_LISTS(S, O_1));
  P = (MASSTOR_LIST)ORD(s);
  MASSYM2_PUT(X, KW, P);
}

static void GetCh
# ifdef __STDC__
()
# else
()
# endif
{
  ach = MASBIOS_CREAD();
  ch = MASBIOS_MASCHR(ach);
}

static MASSTOR_LIST GetString
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s;

  s = MASSTOR_SIL;
  for (;;) {
    GetCh();
    if (ch == '"') {
      GetCh();
      if (ch != '"') {
        goto EXIT_1;
      }
    }
    s = MASSTOR_COMP(ach, s);
  } EXIT_1:;
  s = MASSTOR_INV(s);
  return s;
}

static MASSTOR_LIST GetIdent
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, p;

  MASBIOS_BKSP();
  s = MASSYM2_SREAD();
  p = MASSYM2_GET(s, KW);
  if (p != MASSTOR_SIL) {
    tok = VAL(Token, (CARDINAL)p);
  } else {
    p = MASSYM2_GET(s, MASLISPU_EXTYP);
    if (p == MASSTOR_SIL) {
      if (!MASSYM_MEMQ(s, blv)) {
        blv = MASSTOR_COMP(s, blv);
      }
    }
  }
  return s;
}

static MASSTOR_LIST Comment
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST lev, L;

  L = MASSTOR_SIL;
  lev = 1;
  do {
    GetCh();
    if (ch == ']') {
      GetCh();
      lev = lev - 1;
    }
    if (ch == '[') {
      GetCh();
      lev = lev + 1;
    }
  } while (!(lev == 0));
  return L;
}

static void GetTok
# ifdef __STDC__
()
# else
()
# endif
{
  while (ch == ' ') {
    GetCh();
  }
  tokval = MASSTOR_SIL;
  switch (ch) {
  case '"':;
    tok = string;
    tokval = GetString();
    break;
  case '(':;
    GetCh();
    if (ch == ')') {
      GetCh();
      tok = sil;
    } else {
      tok = lparen;
    }
    break;
  case ')':;
    tok = rparen;
    GetCh();
    break;
  case '[':;
    if (tok != ident) {
      tokval = Comment();
      GetTok();
    } else {
      tok = lbrack;
      GetCh();
    }
    break;
  case ']':;
    tok = rbrack;
    GetCh();
    break;
  case '{':;
    tok = lbrace;
    GetCh();
    break;
  case '}':;
    tok = rbrace;
    GetCh();
    break;
  case '~':;
    tok = not;
    GetCh();
    break;
  case '*':;
    tok = times;
    GetCh();
    break;
  case '^':;
    tok = power;
    GetCh();
    break;
  case '/':;
    GetCh();
    if (ch == '\\') {
      tok = and;
      GetCh();
    } else {
      tok = div;
    }
    break;
  case '\\':;
    GetCh();
    if (ch == '/') {
      tok = or;
      GetCh();
    } else {
      SyntaxError(31);
    }
    break;
  case '+':;
    tok = plus;
    GetCh();
    break;
  case '-':;
    tok = minus;
    GetCh();
    break;
  case '=':;
    tok = eql;
    GetCh();
    break;
  case '#':;
    tok = neq;
    GetCh();
    break;
  case '<':;
    GetCh();
    if (ch == '=') {
      GetCh();
      tok = leq;
    } else {
      tok = lss;
    }
    break;
  case '>':;
    GetCh();
    if (ch == '=') {
      GetCh();
      tok = geq;
    } else {
      tok = gtr;
    }
    break;
  case ';':;
    tok = semicolon;
    GetCh();
    break;
  case ',':;
    GetCh();
    if (ch == '.') {
      GetCh();
      if (ch == '.') {
        GetCh();
        if (ch == '.') {
          GetCh();
          if (ch == ',') {
            GetCh();
            tok = To;
          }
        }
      }
    } else {
      tok = comma;
    }
    break;
  case '\'':;
    tok = quote;
    GetCh();
    break;
  case '.':;
    tok = period;
    GetCh();
    break;
  case '$':;
    tok = dollar;
    GetCh();
    break;
  case ':':;
    GetCh();
    if (ch == '=') {
      GetCh();
      tok = becomes;
    } else {
      tok = colon;
    }
    break;
  case '0':;
  case '1':;
  case '2':;
  case '3':;
  case '4':;
  case '5':;
  case '6':;
  case '7':;
  case '8':;
  case '9':;
    tok = number;
    MASBIOS_BKSP();
    tokval = SACLIST_AREAD();
    GetCh();
    break;
  case 'a':;
  case 'b':;
  case 'c':;
  case 'd':;
  case 'e':;
  case 'f':;
  case 'g':;
  case 'h':;
  case 'i':;
  case 'j':;
  case 'k':;
  case 'l':;
  case 'm':;
  case 'n':;
  case 'o':;
  case 'p':;
  case 'q':;
  case 'r':;
  case 's':;
  case 't':;
  case 'u':;
  case 'v':;
  case 'w':;
  case 'x':;
  case 'y':;
  case 'z':;
    tok = ident;
    tokval = GetIdent();
    GetCh();
    break;
  case 'A':;
  case 'B':;
  case 'C':;
  case 'D':;
  case 'E':;
  case 'F':;
  case 'G':;
  case 'H':;
  case 'I':;
  case 'J':;
  case 'K':;
  case 'L':;
  case 'M':;
  case 'N':;
  case 'O':;
  case 'P':;
  case 'Q':;
  case 'R':;
  case 'S':;
  case 'T':;
  case 'U':;
  case 'V':;
  case 'W':;
  case 'X':;
  case 'Y':;
  case 'Z':;
    tok = ident;
    tokval = GetIdent();
    GetCh();
    break;
  case '|':;
    GetCh();
    if (ch == '|') {
      GetCh();
      tok = end;
    } else {
      SyntaxError(32);
    }
    break;
  default :
    tok = null;
    GetCh();
    break;
  }
}

MASSTOR_LIST ALDPARSE_Aparse
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s;

  noerr = TRUE;
  ch = ' ';
  GetTok();
  s = Program();
  if (tok != end) {
    SyntaxError(25);
  }
  if (!noerr) {
    s = Generate(null, s);
  }
  return s;
}

static MASSTOR_LIST Program
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, t;

  s = MASSTOR_SIL;
  t = MASSTOR_SIL;
  for (;;) {
    if (tok == end) {
      goto EXIT_2;
    } else if (var <= tok && tok <= intrinsic) {
      s = Declaration();
      t = MASSTOR_COMP(s, t);
    } else if (tok == ident) {
      s = Algorithm();
      t = MASSTOR_COMP(s, t);
    } else {
      SyntaxTest(end, 36);
    }
  } EXIT_2:;
  t = MASSTOR_INV(t);
  t = Generate(begin, t);
  return t;
}

static MASSTOR_LIST Algorithm
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST d, d1, s, s1, s2, t, t1, u, a, B, B1, B2, b;
  BOOLEAN func;

  d = MASSTOR_SIL;
  t = MASSTOR_SIL;
  u = MASSTOR_SIL;
  s1 = MASSTOR_SIL;
  isfunc = FALSE;
  zwischen = MASSTOR_SIL;
  B = blv;
  t = Header(&func);
  if (func) {
    SACLIST_FIRST2(t, &zwischen, &t1);
    isfunc = TRUE;
  } else {
    t1 = t;
  }
  while (var <= tok && tok <= intrinsic) {
    if (tok <= global) {
      SyntaxWarning(8);
    }
    d1 = Declaration();
    d = MASSTOR_COMP(d1, d);
  }
  B1 = blv;
  a = MASSTOR_SIL;
  do {
    s = MASSTOR_SIL;
    u = MASSTOR_SIL;
    if (tok == lparen) {
      GetTok();
    } else {
      SyntaxError(24);
    }
    if (tok == number) {
      u = tokval;
      GetTok();
    } else {
      SyntaxError(14);
    }
    if (tok == rparen) {
      GetTok();
      u = Generate(label, u);
    } else {
      SyntaxError(2);
    }
    if (u != MASSTOR_SIL) {
      a = MASSTOR_COMP(u, a);
    }
    for (;;) {
      s1 = Statement();
      s = MASSTOR_COMP(s1, s);
      if (tok == semicolon) {
        GetTok();
      } else if (tok == period) {
        GetTok();
        goto EXIT_3;
      } else if (tok == end) {
        goto EXIT_3;
      }
    } EXIT_3:;
    s = MASSTOR_INV(s);
    s = Generate(begin, s);
    if (s != MASSTOR_SIL) {
      a = MASSTOR_COMP(s, a);
    }
  } while (!(tok == end));
  a = MASSTOR_INV(a);
  a = Generate(begald, a);
  d = MASSTOR_COMP(a, d);
  if (func) {
    s1 = Generate(C_22_return, MASSTOR_LIST1(zwischen));
    d = MASSTOR_COMP(s1, d);
  }
  d = MASSTOR_INV(d);
  B2 = blv;
  if (B2 != B1) {
    while (MASSTOR_RED(B2) != B1) {
      B2 = MASSTOR_RED(B2);
    }
    MASSTOR_SRED(B2, MASSTOR_SIL);
    b = SACLIST_LIST2(blv, MASLISP_LISTX);
    b = Generate(var, b);
    d = MASSTOR_COMP(b, d);
    MASBIOS_SWRITE("Variable(s) declared: ", 22L);
    MASSYM_UWRITE(blv);
  }
  blv = B;
  if (func) {
    if (MASSTOR_FIRST(blv) == zwischen) {
      blv = MASSTOR_RED(blv);
    }
  }
  GetTok();
  d = Generate(begin, d);
  t = MASSTOR_COMP(d, t1);
  t = MASSTOR_INV(t);
  b = MASSTOR_FIRST(t);
  if (!MASSYM_MEMQ(b, blv)) {
    blv = MASSTOR_COMP(b, blv);
  }
  t = Generate(procedure, t);
  return t;
}

static MASSTOR_LIST Declaration
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST t;

  t = MASSTOR_SIL;
  if (tok == global || tok == safe) {
    t = GlobDec();
  } else if (tok == intrinsic) {
    t = IntrinsicDec();
  } else if (tok == const) {
    SyntaxWarning(9);
    t = PrCoDec();
  } else if (tok == pragma) {
    SyntaxWarning(3);
    t = PrCoDec();
  } else if (tok == array) {
    t = ArrayDec();
  } else {
    SyntaxError(8);
  }
  if (tok == period) {
    GetTok();
  } else {
    SyntaxError(37);
  }
  return t;
}

static MASSTOR_LIST Header
# ifdef __STDC__
(BOOLEAN *func)
# else
(func)
BOOLEAN *func;
# endif
{
  MASSTOR_LIST s, u, up, v, a;
  MASSTOR_LIST zwischen;

  s = MASSTOR_SIL;
  u = MASSTOR_SIL;
  up = MASSTOR_SIL;
  v = MASSTOR_SIL;
  a = MASSTOR_SIL;
  *func = FALSE;
  if (tok == ident) {
    a = tokval;
    GetTok();
    if (tok == period) {
      SyntaxWarning(6);
      GetTok();
      *func = FALSE;
      s = MASSTOR_COMP(a, s);
    } else if (tok == lparen) {
      s = MASSTOR_COMP(a, s);
      GetTok();
      u = IdentifierList();
      if (tok == semicolon) {
        GetTok();
        up = IdentifierList();
      }
      if (tok == rparen) {
        GetTok();
      } else {
        SyntaxError(2);
      }
      u = SACLIST_LIST2(u, up);
      s = MASSTOR_COMP(u, s);
      *func = FALSE;
    } else if (tok == sil) {
      s = MASSTOR_COMP(a, s);
      u = SACLIST_LIST2(MASSTOR_SIL, MASSTOR_SIL);
      s = MASSTOR_COMP(u, s);
      *func = FALSE;
      GetTok();
    } else if (tok == becomes) {
      zwischen = a;
      GetTok();
      if (tok == ident) {
        a = tokval;
        s = MASSTOR_COMP(a, s);
        GetTok();
      } else {
        SyntaxError(1);
      }
      if (tok == lparen) {
        GetTok();
        u = IdentifierList();
        u = SACLIST_LIST2(u, up);
        s = MASSTOR_COMP(u, s);
      } else if (tok == sil) {
        u = SACLIST_LIST2(MASSTOR_SIL, MASSTOR_SIL);
        s = MASSTOR_COMP(u, s);
      } else {
        SyntaxError(24);
      }
      if (tok == rparen || tok == sil) {
        GetTok();
        *func = TRUE;
      } else {
        SyntaxError(2);
      }
      s = SACLIST_LIST2(zwischen, s);
    }
  } else {
    SyntaxError(1);
  }
  return s;
}

static MASSTOR_LIST Sequence
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, t;

  s = MASSTOR_SIL;
  t = MASSTOR_SIL;
  if (tok != lbrace) {
    t = Statement();
  } else {
    GetTok();
    for (;;) {
      s = Statement();
      t = MASSTOR_COMP(s, t);
      if (tok == semicolon) {
        GetTok();
      } else if (tok == rbrace) {
        GetTok();
        goto EXIT_4;
      } else {
        SyntaxError(19);
      }
    } EXIT_4:;
    if (t != MASSTOR_SIL) {
      t = MASSTOR_INV(t);
      t = Generate(begin, t);
    }
  }
  return t;
}

static MASSTOR_LIST Statement
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST t;

  t = MASSTOR_SIL;
  SyntaxTest(ident, 26);
  switch (tok) {
  case print:;
    t = PrintStat();
    break;
  case C_23_goto:;
    t = GotoStat();
    break;
  case go:;
    t = GoStat();
    break;
  case C_24_if:;
    t = IfStat();
    break;
  case C_25_case:;
    t = CaseStat();
    break;
  case C_26_while:;
    t = WhileStat();
    break;
  case repeat:;
    t = RepeatStat();
    break;
  case C_27_for:;
    t = ForStat();
    break;
  case C_22_return:;
    GetTok();
    if (isfunc) {
      t = Generate(C_22_return, MASSTOR_LIST1(zwischen));
    } else {
      t = Generate(C_22_return, MASSTOR_SIL);
    }
    break;
  case ident:;
    t = IdentStat();
    break;
  default :
    SyntaxTest(period, 26);
    break;
  }
  return t;
}

static MASSTOR_LIST PrintStat
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST t;

  t = MASSTOR_SIL;
  GetTok();
  if (tok == string) {
    t = tokval;
    GetTok();
    t = Generate(print, t);
  } else {
    SyntaxError(13);
  }
  return t;
}

static MASSTOR_LIST GotoStat
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, t;

  t = MASSTOR_SIL;
  GetTok();
  if (tok == lparen) {
    GetTok();
    if (tok == number) {
      s = tokval;
      GetTok();
      if (tok == rparen) {
        t = Generate(C_23_goto, s);
        GetTok();
      } else {
        SyntaxError(2);
      }
    } else {
      SyntaxError(14);
    }
  } else if (tok == number) {
    s = tokval;
    t = Generate(C_23_goto, s);
    GetTok();
  } else {
    SyntaxError(14);
  }
  return t;
}

static MASSTOR_LIST GoStat
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, t;

  t = MASSTOR_SIL;
  GetTok();
  if (tok != to) {
    SyntaxError(15);
  } else {
    GetTok();
    if (tok == lparen) {
      GetTok();
      if (tok == number) {
        s = tokval;
        GetTok();
        if (tok == rparen) {
          t = Generate(C_23_goto, s);
          GetTok();
        } else {
          SyntaxError(2);
        }
      } else {
        SyntaxError(14);
      }
    } else if (tok == number) {
      s = tokval;
      t = Generate(C_23_goto, s);
      GetTok();
    } else {
      SyntaxError(14);
    }
  }
  return t;
}

static MASSTOR_LIST IfStat
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, t;

  t = MASSTOR_SIL;
  GetTok();
  s = CondSeq();
  t = MASSTOR_COMP(s, t);
  if (tok == then) {
    GetTok();
  } else {
    SyntaxError(16);
  }
  s = Sequence();
  t = MASSTOR_COMP(s, t);
  if (tok == C_20_else) {
    GetTok();
    s = Sequence();
    t = MASSTOR_COMP(s, t);
  }
  t = MASSTOR_INV(t);
  t = Generate(C_24_if, t);
  return t;
}

static MASSTOR_LIST CaseStat
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST a, c, s, t, v;

  v = MASSTOR_SIL;
  t = MASSTOR_SIL;
  GetTok();
  a = Expression();
  if (tok == of) {
    GetTok();
  } else {
    SyntaxError(17);
  }
  if (tok == lbrace) {
    GetTok();
  } else {
    SyntaxError(18);
  }
  do {
    c = TermList();
    if (tok == C_21_do) {
      GetTok();
    } else {
      SyntaxError(20);
    }
    s = Sequence();
    if (tok == semicolon) {
      GetTok();
    } else if (tok != rbrace) {
      SyntaxError(27);
    }
    v = MASSTOR_SIL;
    v = SACLIST_LIST3(a, c, s);
    v = CaseLabel(v);
    t = MASSTOR_COMP(v, t);
  } while (!(tok == rbrace));
  GetTok();
  t = MASSTOR_INV(t);
  t = Generate(C_25_case, t);
  return t;
}

static MASSTOR_LIST WhileStat
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST t, s;

  t = MASSTOR_SIL;
  GetTok();
  s = CondSeq();
  if (tok == C_21_do) {
    GetTok();
  } else {
    SyntaxError(20);
  }
  t = Sequence();
  t = MASSTOR_LIST1(t);
  t = MASSTOR_COMP(s, t);
  t = Generate(C_26_while, t);
  return t;
}

static MASSTOR_LIST RepeatStat
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST t, s;

  t = MASSTOR_SIL;
  s = MASSTOR_SIL;
  GetTok();
  if (tok == lbrace) {
    t = Sequence();
    if (tok == until) {
      GetTok();
      s = CondSeq();
      s = MASSTOR_LIST1(s);
      s = MASSTOR_COMP(t, s);
      t = Generate(repeat, s);
    } else {
      s = MASLISP_WT;
      s = MASSTOR_LIST1(s);
      t = MASSTOR_COMP(t, s);
      t = Generate(repeat, t);
    }
  } else {
    for (;;) {
      s = Statement();
      t = MASSTOR_COMP(s, t);
      if (tok == semicolon) {
        GetTok();
      } else if (tok == until) {
        GetTok();
        goto EXIT_5;
      } else {
        SyntaxError(29);
      }
    } EXIT_5:;
    if (t != MASSTOR_SIL) {
      t = MASSTOR_INV(t);
    }
    t = Generate(begin, t);
    s = CondSeq();
    s = MASSTOR_LIST1(s);
    s = MASSTOR_COMP(t, s);
    t = Generate(repeat, s);
  }
  return t;
}

static MASSTOR_LIST ForStat
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST i, s, t, t1, t2, t3, v;

  t = MASSTOR_SIL;
  s = MASSTOR_SIL;
  GetTok();
  if (tok == ident) {
    i = tokval;
    GetTok();
  } else {
    SyntaxError(1);
  }
  if (tok == eql) {
    GetTok();
  } else if (tok == becomes) {
    GetTok();
  } else {
    SyntaxError(33);
  }
  t1 = Expression();
  if (tok == To) {
    GetTok();
    t2 = MASSTOR_SIL;
    t3 = Expression();
  } else if (tok == comma) {
    GetTok();
    t2 = Expression();
    if (tok == To) {
      GetTok();
      t3 = Expression();
    } else {
      SyntaxError(22);
    }
  } else {
    SyntaxError(23);
  }
  if (tok == C_21_do) {
    GetTok();
    s = Sequence();
  } else {
    SyntaxError(20);
  }
  t = SACLIST_LIST5(i, t1, t2, t3, s);
  t = Generate(C_27_for, t);
  return t;
}

static MASSTOR_LIST IdentStat
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, t, u, v;

  t = MASSTOR_SIL;
  u = MASSTOR_SIL;
  v = MASSTOR_SIL;
  s = Variable();
  if (tok == becomes) {
    GetTok();
    u = Expression();
    t = SACLIST_LIST2(s, u);
    t = Generate(becomes, t);
  } else if (tok == sil) {
    u = MASSTOR_SIL;
    if (!MASSYM2_SYMBOL(s)) {
      SyntaxWarning(7);
    }
    t = MASSTOR_COMP(s, u);
    GetTok();
  } else if (tok == lparen) {
    GetTok();
    u = TermList();
    if (tok == semicolon) {
      GetTok();
      v = TermList();
      if (tok == rparen) {
        GetTok();
      } else {
        SyntaxError(2);
      }
    } else {
      if (tok == rparen) {
        GetTok();
      } else {
        SyntaxError(2);
      }
    }
    if (!MASSYM2_SYMBOL(s)) {
      SyntaxWarning(7);
    }
    t = SACLIST_CONC(u, v);
    t = MASSTOR_COMP(s, t);
  } else {
    t = MASSTOR_LIST1(s);
  }
  return t;
}

static MASSTOR_LIST GlobDec
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, t, u, v;

  s = MASSTOR_SIL;
  t = MASSTOR_SIL;
  GetTok();
  for (;;) {
    s = Variable();
    t = MASSTOR_COMP(s, t);
    if (tok == comma) {
      GetTok();
    } else if (tok == period) {
      goto EXIT_6;
    } else {
      SyntaxError(8);
      goto EXIT_6;
    }
  } EXIT_6:;
  t = MASSTOR_INV(t);
  t = SACLIST_LIST2(t, any);
  t = Generate(var, t);
  return t;
}

static MASSTOR_LIST IntrinsicDec
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, t;

  s = MASSTOR_SIL;
  t = MASSTOR_SIL;
  SyntaxWarning(2);
  GetTok();
  s = IdentifierList();
  if (tok != period) {
    SyntaxError(8);
  }
  t = SACLIST_LIST2(s, any);
  t = Generate(var, t);
  return t;
}

static MASSTOR_LIST PrCoDec
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, t, u, x, y;

  GetTok();
  x = MASSTOR_SIL;
  y = MASSTOR_SIL;
  do {
    u = MASSTOR_SIL;
    s = Variable();
    x = MASSTOR_COMP(s, x);
    if (tok == eql) {
      GetTok();
      u = Expression();
    } else {
      SyntaxError(9);
    }
    u = SACLIST_LIST2(s, u);
    u = Generate(becomes, u);
    y = MASSTOR_COMP(u, y);
    if (tok == comma) {
      GetTok();
    } else if (tok != period) {
      SyntaxError(10);
    }
  } while (!(tok == period));
  x = MASSTOR_INV(x);
  y = MASSTOR_INV(y);
  x = SACLIST_LIST2(x, any);
  x = Generate(var, x);
  y = MASSTOR_COMP(x, y);
  y = Generate(begin, y);
  return y;
}

static MASSTOR_LIST ArrayDec
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, t, u;

  s = MASSTOR_SIL;
  u = MASSTOR_SIL;
  GetTok();
  do {
    if (tok == ident) {
      s = tokval;
      GetTok();
    } else {
      SyntaxError(1);
    }
    if (tok == lbrack) {
      GetTok();
    } else {
      SyntaxError(11);
    }
    t = TermList();
    t = SACLIST_LIST2(s, t);
    t = Generate(array, t);
    u = MASSTOR_COMP(t, u);
    if (tok == rbrack) {
      GetTok();
    } else {
      SyntaxError(12);
    }
    if (tok == comma) {
      GetTok();
    } else if (tok != period) {
      SyntaxError(10);
    }
  } while (!(tok == period));
  u = MASSTOR_INV(u);
  u = SACLIST_LIST2(u, any);
  t = Generate(var, u);
  return t;
}

static MASSTOR_LIST CondSeq
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST c, cl, t;
  Token oper;

  t = MASSTOR_SIL;
  cl = MASSTOR_SIL;
  c = Condition();
  cl = MASSTOR_COMP(c, cl);
  if (tok == and) {
    oper = tok;
    GetTok();
    do {
      c = Condition();
      cl = MASSTOR_COMP(c, cl);
      if (tok == and) {
        GetTok();
      }
      if (tok == or) {
        SyntaxError(30);
      }
    } while (!(tok == then || tok == until || tok == C_21_do || tok == period || tok == end || tok == rparen || tok == semicolon || tok == rbrace || tok == or));
    if (cl != MASSTOR_SIL) {
      cl = MASSTOR_INV(cl);
    }
    t = Generate(oper, cl);
  } else if (tok == or) {
    oper = tok;
    GetTok();
    do {
      c = Condition();
      cl = MASSTOR_COMP(c, cl);
      if (tok == or) {
        GetTok();
      }
      if (tok == and) {
        SyntaxError(30);
      }
    } while (!(tok == then || tok == until || tok == C_21_do || tok == period || tok == end || tok == rparen || tok == semicolon || tok == rbrace || tok == and));
    if (cl != MASSTOR_SIL) {
      cl = MASSTOR_INV(cl);
    }
    t = Generate(oper, cl);
  } else {
    t = c;
  }
  return t;
}

static MASSTOR_LIST Condition
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, t, u;
  Token oper;

  t = MASSTOR_SIL;
  if (tok == not) {
    GetTok();
    t = Condition();
    t = Generate(not, MASSTOR_LIST1(t));
  } else if (tok == lparen) {
    GetTok();
    t = CondSeq();
    if (tok == rparen) {
      GetTok();
    } else {
      SyntaxError(2);
    }
  } else {
    u = Expression();
    if (eql <= tok && tok <= geq) {
      oper = tok;
      GetTok();
      s = Expression();
      t = SACLIST_LIST2(u, s);
      t = Generate(oper, t);
    } else {
      SyntaxError(11);
    }
  }
  return t;
}

static MASSTOR_LIST IdentifierList
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, t;

  s = MASSTOR_SIL;
  for (;;) {
    if (tok == ident) {
      s = MASSTOR_COMP(tokval, s);
      GetTok();
    } else {
      SyntaxError(1);
    }
    if (tok == comma) {
      GetTok();
    } else if (tok == semicolon) {
      goto EXIT_7;
    } else if (tok == rparen) {
      goto EXIT_7;
    } else if (tok == period) {
      goto EXIT_7;
    } else {
      SyntaxError(35);
      goto EXIT_7;
    }
  } EXIT_7:;
  s = MASSTOR_INV(s);
  return s;
}

static MASSTOR_LIST TermList
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, t;

  s = MASSTOR_SIL;
  t = MASSTOR_SIL;
  do {
    s = Expression();
    t = MASSTOR_COMP(s, t);
    if (tok == comma) {
      GetTok();
    }
  } while (!(tok == C_21_do || tok == semicolon || tok == rparen || tok == rbrack));
  t = MASSTOR_INV(t);
  return t;
}

static MASSTOR_LIST Expression
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, t, u;
  Token oper;

  s = MASSTOR_SIL;
  t = MASSTOR_SIL;
  u = MASSTOR_SIL;
  if (plus <= tok && tok <= minus) {
    oper = tok;
    GetTok();
    s = Term();
    if (oper == minus) {
      s = Generate(oper, MASSTOR_LIST1(s));
    }
  } else {
    s = Term();
  }
  while (plus <= tok && tok <= minus) {
    oper = tok;
    GetTok();
    u = Term();
    t = SACLIST_LIST2(s, u);
    s = Generate(oper, t);
  }
  return s;
}

static MASSTOR_LIST Term
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, t, u;
  Token oper;

  s = Factor();
  while (times <= tok && tok <= mod) {
    oper = tok;
    GetTok();
    u = Factor();
    t = SACLIST_LIST2(s, u);
    s = Generate(oper, t);
  }
  return s;
}

static MASSTOR_LIST Factor
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, t, u;
  Token oper;

  s = Potency();
  while (tok == power) {
    oper = tok;
    GetTok();
    u = Potency();
    t = SACLIST_LIST2(s, u);
    s = Generate(oper, t);
  }
  return s;
}

static MASSTOR_LIST Potency
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, t, u;
  Token oper;

  t = MASSTOR_SIL;
  s = MASSTOR_SIL;
  u = MASSTOR_SIL;
  SyntaxTest(lparen, 34);
  if (tok == ident) {
    t = tokval;
    GetTok();
    if (tok == lparen) {
      GetTok();
      u = TermList();
      GetTok();
      t = MASSTOR_COMP(t, u);
    } else if (tok == sil) {
      u = MASSTOR_SIL;
      GetTok();
      t = MASSTOR_COMP(t, MASSTOR_LIST1(u));
    } else if (tok == lbrack) {
      GetTok();
      s = TermList();
      t = SACLIST_LIST2(t, s);
      t = Generate(array, t);
      if (tok == rbrack) {
        GetTok();
      } else {
        SyntaxError(12);
      }
    }
  } else if (tok == number) {
    t = tokval;
    GetTok();
  } else if (tok == string) {
    t = tokval;
    t = Generate(string, t);
    GetTok();
  } else if (tok == lparen) {
    GetTok();
    t = Expression();
    if (tok == rparen) {
      GetTok();
    } else {
      SyntaxError(2);
    }
  } else if (tok == sil) {
    t = MASSTOR_SIL;
    GetTok();
  } else {
    SyntaxError(3);
    GetTok();
  }
  return t;
}

static MASSTOR_LIST Variable
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, t;

  t = MASSTOR_SIL;
  s = MASSTOR_SIL;
  if (tok == ident) {
    s = tokval;
    GetTok();
  } else {
    SyntaxError(1);
  }
  if (tok == lbrack) {
    GetTok();
    t = TermList();
    s = SACLIST_LIST2(s, t);
    s = Generate(array, s);
    if (tok == rbrack) {
      GetTok();
    } else {
      SyntaxError(2);
    }
  }
  return s;
}

static MASSTOR_LIST Generate
# ifdef __STDC__
(Token s, MASSTOR_LIST t)
# else
(s, t)
Token s;
MASSTOR_LIST t;
# endif
{
  MASSTOR_LIST code;

  switch (s) {
  case power:;
    code = MASSTOR_COMP(MASLISP_POW, t);
    break;
  case times:;
    code = MASSTOR_COMP(MASLISP_MUL, t);
    break;
  case plus:;
    code = MASSTOR_COMP(MASLISP_ADD, t);
    break;
  case minus:;
    code = MASSTOR_COMP(MASLISP_SUB, t);
    break;
  case div:;
    code = MASSTOR_COMP(MASLISP_QUOT, t);
    break;
  case mod:;
    code = MASSTOR_COMP(MASLISP_REM, t);
    break;
  case neq:;
    code = MASSTOR_COMP(MASLISP_NEQS, t);
    break;
  case eql:;
    code = MASSTOR_COMP(MASLISP_EQS, t);
    break;
  case lss:;
    code = MASSTOR_COMP(MASLISP_LTS, t);
    break;
  case leq:;
    code = MASSTOR_COMP(MASLISP_LEQ, t);
    break;
  case gtr:;
    code = MASSTOR_COMP(MASLISP_GTS, t);
    break;
  case geq:;
    code = MASSTOR_COMP(MASLISP_GEQ, t);
    break;
  case and:;
    code = MASSTOR_COMP(MASLISP_UND, t);
    break;
  case or:;
    code = MASSTOR_COMP(MASLISP_ODER, t);
    break;
  case becomes:;
    code = MASSTOR_COMP(MASLISP_SETAV, t);
    break;
  case C_24_if:;
    code = MASSTOR_COMP(MASLISP_IFS, t);
    break;
  case C_25_case:;
    code = MASSTOR_COMP(MASLISP_COND, t);
    break;
  case not:;
    code = MASSTOR_COMP(MASLISP_NOTS, t);
    break;
  case var:;
    code = MASSTOR_COMP(MASLISP_VARS, t);
    break;
  case array:;
    code = MASSTOR_COMP(MASLISP_ARY, MASSTOR_LIST1(t));
    break;
  case pragma:;
    code = MASSTOR_COMP(prag, t);
    break;
  case begin:;
    if (t == MASSTOR_SIL) {
      code = t;
    } else if (MASSTOR_RED(t) == MASSTOR_SIL) {
      code = MASSTOR_FIRST(t);
    } else {
      code = MASSTOR_COMP(MASLISP_PROGN, t);
    }
    break;
  case C_26_while:;
    code = MASSTOR_COMP(MASLISP_WHL, t);
    break;
  case begald:;
    code = MASSTOR_COMP(MASLISP_PROGA, t);
    break;
  case repeat:;
    code = MASSTOR_COMP(MASLISP_RPT, t);
    break;
  case C_27_for:;
    code = Genfor(t);
    break;
  case print:;
    code = MASSTOR_COMP(prnt, MASSTOR_LIST1(t));
    break;
  case C_23_goto:;
    code = MASSTOR_COMP(MASLISP_GTO, MASSTOR_LIST1(t));
    break;
  case label:;
    code = MASSTOR_COMP(MASLISP_LBEL, MASSTOR_LIST1(t));
    break;
  case ident:;
    if (MASSTOR_RED(t) == MASSTOR_SIL) {
      code = MASSTOR_FIRST(t);
    } else {
      code = MASSTOR_COMP(MASLISP_DE, t);
    }
    break;
  case sil:;
    code = t;
    break;
  case procedure:;
    code = MASSTOR_COMP(MASLISP_DE, t);
    break;
  case C_22_return:;
    code = MASSTOR_COMP(ret, t);
    break;
  case string:;
    code = MASSTOR_COMP(MASLISP_STRNG, t);
    break;
  default :
    code = SACLIST_LIST2(MASLISP_QUOTE, t);
    break;
  }
  return code;
}

static MASSTOR_LIST Genfor
# ifdef __STDC__
(MASSTOR_LIST t)
# else
(t)
MASSTOR_LIST t;
# endif
{
  MASSTOR_LIST h1, h2, h3, h4, i, t1, t2, t3, s, w, v;

  FIRST5(t, &i, &t1, &t2, &t3, &s);
  h1 = SACLIST_LIST2(i, t1);
  h1 = Generate(becomes, h1);
  h1 = MASSTOR_LIST1(h1);
  if (t2 != MASSTOR_SIL) {
    w = MASSYM2_GENSYM();
    h2 = SACLIST_LIST2(t2, t1);
    h2 = Generate(minus, h2);
    h2 = SACLIST_LIST2(w, h2);
    h2 = Generate(becomes, h2);
    h1 = MASSTOR_COMP(h2, h1);
  }
  if (t2 != MASSTOR_SIL) {
    v = MASSYM2_GENSYM();
    h2 = SACLIST_LIST2(v, -1);
    h2 = Generate(becomes, h2);
    h2 = MASSTOR_LIST1(h2);
    h3 = SACLIST_LIST2(v, 1);
    h3 = Generate(becomes, h3);
    h2 = MASSTOR_COMP(h3, h2);
    h3 = SACLIST_LIST2(0, w);
    h3 = Generate(leq, h3);
    h2 = MASSTOR_COMP(h3, h2);
    h2 = Generate(C_24_if, h2);
    h1 = MASSTOR_COMP(h2, h1);
  }
  if (t2 == MASSTOR_SIL) {
    h2 = SACLIST_LIST2(i, t3);
  } else {
    h2 = SACLIST_LIST2(t3, i);
    h2 = Generate(minus, h2);
    h2 = SACLIST_LIST2(v, h2);
    h2 = Generate(times, h2);
    h2 = SACLIST_LIST2(0, h2);
  }
  h2 = Generate(leq, h2);
  if (t2 == MASSTOR_SIL) {
    h3 = SACLIST_LIST2(i, 1);
  } else {
    h3 = SACLIST_LIST2(i, w);
  }
  h3 = Generate(plus, h3);
  h3 = SACLIST_LIST2(i, h3);
  h3 = Generate(becomes, h3);
  h3 = SACLIST_LIST2(s, h3);
  h3 = Generate(begin, h3);
  h3 = MASSTOR_LIST1(h3);
  h2 = MASSTOR_COMP(h2, h3);
  h2 = Generate(C_26_while, h2);
  h1 = MASSTOR_COMP(h2, h1);
  h1 = MASSTOR_INV(h1);
  h1 = Generate(begin, h1);
  return h1;
}

static MASSTOR_LIST CaseLabel
# ifdef __STDC__
(MASSTOR_LIST v)
# else
(v)
MASSTOR_LIST v;
# endif
{
  MASSTOR_LIST h1, a, c, C, s, L;

  SACLIST_FIRST3(v, &a, &C, &s);
  L = MASSTOR_SIL;
  while (C != MASSTOR_SIL) {
    MASSTOR_ADV(C, &c, &C);
    h1 = SACLIST_LIST2(a, c);
    h1 = Generate(eql, h1);
    if (L == MASSTOR_SIL) {
      L = h1;
    } else {
      L = SACLIST_LIST2(L, h1);
      L = Generate(or, L);
    }
  }
  L = SACLIST_LIST2(L, s);
  return L;
}

static void InitAscanner
# ifdef __STDC__
()
# else
()
# endif
{
  MASLISPU_Declare(&KW, "AldesKeyWord", 12L);
  KeyWord(C_21_do, "do", 2L);
  KeyWord(C_24_if, "if", 2L);
  KeyWord(C_25_case, "case", 4L);
  KeyWord(of, "of", 2L);
  KeyWord(then, "then", 4L);
  KeyWord(C_20_else, "else", 4L);
  KeyWord(C_26_while, "while", 5L);
  KeyWord(C_27_for, "for", 3L);
  KeyWord(until, "until", 5L);
  KeyWord(repeat, "repeat", 6L);
  KeyWord(safe, "safe", 4L);
  KeyWord(global, "global", 6L);
  KeyWord(intrinsic, "intrinsic", 9L);
  KeyWord(pragma, "pragma", 6L);
  KeyWord(const, "const", 5L);
  KeyWord(array, "array", 5L);
  KeyWord(To, ",...,", 5L);
  KeyWord(C_23_goto, "goto", 4L);
  KeyWord(go, "go", 2L);
  KeyWord(to, "to", 2L);
  KeyWord(print, "print", 5L);
  KeyWord(C_22_return, "return", 6L);
}

static void InitAparser
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST X, s, v;

  InitAscanner();
  MASLISPU_Compiledp1(SACLIST_CLOUT, "PRINT", 5L);
  MASLISPU_Declare(&prnt, "PRINT", 5L);
  MASLISPU_Declare(&any, "ANY", 3L);
  MASLISPU_Declare(&ret, "RETURN", 6L);
  MASLISPU_Declare(&prag, "PRAGMA", 6L);
  blv = MASSTOR_SIL;
  MASSTOR_LISTVAR(&blv);
  X = MASLISP_ENV;
  while (X != MASSTOR_SIL) {
    SACLIST_ADV2(X, &s, &v, &X);
    if (!MASSYM_MEMQ(s, blv)) {
      blv = MASSTOR_COMP(s, blv);
    }
  }
}

void BEGIN_ALDPARSE()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_MASBIOS();
    BEGIN_SACLIST();
    BEGIN_MASSYM2();
    BEGIN_MASSYM();
    BEGIN_MASLISPU();
    BEGIN_MASLISP();
    BEGIN_MASSPEC();

    InitAparser();
  }
}
