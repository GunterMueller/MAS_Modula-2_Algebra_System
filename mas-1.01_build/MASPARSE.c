#include "SYSTEM_.h"

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

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

#ifndef DEFINITION_MASPARSE
#include "MASPARSE.h"
#endif

CHAR MASPARSE_rcsid [] = "$Id: MASPARSE.md,v 1.2 1992/02/12 17:32:25 pesch Exp $";
CHAR MASPARSE_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASPARSE.mi,v 1.5 1995/11/05 08:57:07 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
static MASSTOR_LIST SUM, DIF, PROD, Q, REMAIN, EXP;
static MASSTOR_LIST sum, dif, prod, quot, remain, exp;
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
#define when	16
#define equiv	17
#define arrow	18
#define tinfo	19
#define listex	20
#define comma	21
#define rparen	22
#define rbrace	23
#define rbrack	24
#define lparen	25
#define lbrace	26
#define lbrack	27
#define until	28
#define C_20_else	29
#define then	30
#define C_21_do	31
#define to	32
#define becomes	33
#define string	34
#define number	35
#define colon	36
#define ident	37
#define semicolon	38
#define end	39
#define C_22_if	40
#define repeat	41
#define C_23_while	42
#define begin	43
#define map	44
#define rule	45
#define sig	46
#define var	47
#define sort	48
#define import	49
#define procedure	50
#define expose	51
#define spec	52
#define model	53
#define impl	54
#define axiom	55
#define period	56
#define eof	57
typedef unsigned char Token;
static Token tok;
static MASSTOR_LIST tokval;
static CHAR ch;
static MASSTOR_LIST ach;
static MASSTOR_LIST KW;
static BOOLEAN noerr;
static MASSTOR_LIST blv;
static BOOLEAN genpars;
static void SyntaxErr ARGS((MASELEM_GAMMAINT n));
static void SyntaxWrn ARGS((MASELEM_GAMMAINT n));
static void SyntaxTest ARGS((Token s, MASELEM_GAMMAINT n));
static void KeyWord ARGS((Token s, CHAR S[], LONGCARD ));
static void GetCh ARGS(());
static void Comment ARGS(());
static MASSTOR_LIST GetString ARGS((CHAR c));
static MASSTOR_LIST GetIdent ARGS(());
static void GetToken ARGS(());
static void PutToken ARGS(());
static MASSTOR_LIST Generate ARGS((Token s, MASSTOR_LIST t));
static MASSTOR_LIST TopBlock ARGS(());
static MASSTOR_LIST Block ARGS(());
static MASSTOR_LIST SpecDec ARGS(());
static MASSTOR_LIST ImplDec ARGS(());
static MASSTOR_LIST ModDec ARGS(());
static MASSTOR_LIST AxiomDec ARGS(());
static MASSTOR_LIST ImportDec ARGS((Token t));
static MASSTOR_LIST MapDec ARGS(());
static MASSTOR_LIST RuleDec ARGS(());
static MASSTOR_LIST VarDec ARGS(());
static MASSTOR_LIST SortDec ARGS(());
static MASSTOR_LIST SigDec ARGS(());
static MASSTOR_LIST ProcDec ARGS(());
static MASSTOR_LIST HeadDec ARGS(());
static MASSTOR_LIST StatSeq ARGS(());
static MASSTOR_LIST Statement ARGS(());
static MASSTOR_LIST IdentList ARGS(());
static MASSTOR_LIST ActParms ARGS(());
static MASSTOR_LIST ListExpr ARGS(());
static MASSTOR_LIST Expression ARGS(());
static MASSTOR_LIST Condition ARGS(());
static MASSTOR_LIST Term ARGS(());
static MASSTOR_LIST Power ARGS(());
static MASSTOR_LIST Factor ARGS(());
static MASSTOR_LIST TypeExpression ARGS(());
static void InitScanner ARGS(());
static void InitParser ARGS(());


static void SyntaxErr
# ifdef __STDC__
(MASELEM_GAMMAINT n)
# else
(n)
MASELEM_GAMMAINT n;
# endif
{
  INTEGER m;
  MASSTOR_LIST c;

  MASBIOS_SWRITE("[", 1L);
  SACLIST_AWRITE(n);
  MASBIOS_SWRITE("] ", 2L);
  m = (INTEGER)n;
  noerr = FALSE;
  switch (m) {
  case 1:;
    MASBIOS_SWRITE("=", 1L);
    break;
  case 2:;
    MASBIOS_SWRITE("identifier or , or ;", 20L);
    break;
  case 4:;
    MASBIOS_SWRITE("identifier", 10L);
    break;
  case 5:;
    MASBIOS_SWRITE("; or ,", 6L);
    break;
  case 6:;
    MASBIOS_SWRITE("expression", 10L);
    break;
  case 7:;
    MASBIOS_SWRITE(")", 1L);
    break;
  case 8:;
    MASBIOS_SWRITE("factor", 6L);
    break;
  case 9:;
    MASBIOS_SWRITE(".", 1L);
    break;
  case 10:;
    MASBIOS_SWRITE("assignment", 10L);
    break;
  case 13:;
    MASBIOS_SWRITE(":= or (", 7L);
    break;
  case 14:;
    MASBIOS_SWRITE("statement", 9L);
    break;
  case 15:;
    MASBIOS_SWRITE(":", 1L);
    break;
  case 16:;
    MASBIOS_SWRITE("then", 4L);
    break;
  case 17:;
    MASBIOS_SWRITE("; or end", 8L);
    break;
  case 18:;
    MASBIOS_SWRITE("do", 2L);
    break;
  case 20:;
    MASBIOS_SWRITE("relation", 8L);
    break;
  case 21:;
    MASBIOS_SWRITE(", or )", 6L);
    break;
  case 22:;
    MASBIOS_SWRITE("->", 2L);
    break;
  case 23:;
    MASBIOS_SWRITE("( or ident", 10L);
    break;
  case 24:;
    MASBIOS_SWRITE("(", 1L);
    break;
  case 25:;
    MASBIOS_SWRITE("condition", 9L);
    break;
  case 26:;
    MASBIOS_SWRITE("number", 6L);
    break;
  case 27:;
    MASBIOS_SWRITE(", or ) or ;", 11L);
    break;
  case 28:;
    MASBIOS_SWRITE(";", 1L);
    break;
  case 29:;
    MASBIOS_SWRITE("end or ;", 8L);
    break;
  case 30:;
    MASBIOS_SWRITE(", or ]", 6L);
    break;
  case 31:;
    MASBIOS_SWRITE("/", 1L);
    break;
  case 32:;
    MASBIOS_SWRITE("==", 2L);
    break;
  case 33:;
    MASBIOS_SWRITE("end or ; or begin", 17L);
    break;
  case 34:;
    MASBIOS_SWRITE(", or }", 6L);
    break;
  case 35:;
    MASBIOS_SWRITE("to", 2L);
    break;
  default :
    MASBIOS_SWRITE("don't know what is", 18L);
    break;
  }
  MASBIOS_SWRITE(" expected ", 10L);
  MASBIOS_BKSP();
  MASBIOS_DIBUFF();
  c = MASBIOS_CREAD();
}

static void SyntaxWrn
# ifdef __STDC__
(MASELEM_GAMMAINT n)
# else
(n)
MASELEM_GAMMAINT n;
# endif
{
  INTEGER m;

  MASBIOS_SWRITE("[", 1L);
  SACLIST_AWRITE(n);
  MASBIOS_SWRITE("] ", 2L);
  m = (INTEGER)n;
  switch (m) {
  case 1:;
    MASBIOS_SWRITE("identifier", 10L);
    break;
  case 2:;
    MASBIOS_SWRITE("algorithm name", 14L);
    break;
  default :
    MASBIOS_SWRITE("don't know what is", 18L);
    break;
  }
  MASBIOS_SWRITE(" expected ", 10L);
}

static void SyntaxTest
# ifdef __STDC__
(Token s, MASELEM_GAMMAINT n)
# else
(s, n)
Token s;
MASELEM_GAMMAINT n;
# endif
{
  INTEGER m;

  if (tok < s) {
    SyntaxErr(n);
    do {
      GetToken();
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
  MASSTOR_LIST X;
  MASELEM_GAMMAINT P;

  X = MASSYM2_ENTER(MASBIOS_LISTS(S, O_1));
  P = (MASELEM_GAMMAINT)ORD(s);
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

static void Comment
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST lev;

  lev = 1;
  do {
    GetCh();
    if (ch == '*') {
      GetCh();
      if (ch == ')') {
        GetCh();
        lev = lev - 1;
      }
    }
    if (ch == '(') {
      GetCh();
      if (ch == '*') {
        GetCh();
        lev = lev + 1;
      }
    }
  } while (!(lev == 0));
}

static MASSTOR_LIST GetString
# ifdef __STDC__
(CHAR c)
# else
(c)
CHAR c;
# endif
{
  MASSTOR_LIST s;

  s = MASSTOR_SIL;
  for (;;) {
    GetCh();
    if (ch == c) {
      GetCh();
      if (ch != c) {
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

static void GetToken
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
    tokval = GetString('"');
    break;
  case '\'':;
    tok = string;
    tokval = GetString('\'');
    break;
  case '#':;
    tok = neq;
    GetCh();
    break;
  case '(':;
    GetCh();
    if (ch == '*') {
      Comment();
      GetToken();
    } else {
      tok = lparen;
    }
    break;
  case ')':;
    tok = rparen;
    GetCh();
    break;
  case '[':;
    tok = lbrack;
    GetCh();
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
  case '^':;
    tok = power;
    GetCh();
    break;
  case '*':;
    GetCh();
    if (ch == '*') {
      GetCh();
      tok = power;
    } else {
      tok = times;
    }
    break;
  case '+':;
    tok = plus;
    GetCh();
    break;
  case ',':;
    tok = comma;
    GetCh();
    break;
  case '-':;
    GetCh();
    if (ch == '>') {
      GetCh();
      tok = arrow;
    } else {
      tok = minus;
    }
    break;
  case '.':;
    tok = period;
    ch = '.';
    break;
  case '/':;
    tok = div;
    GetCh();
    break;
  case '%':;
    tok = mod;
    GetCh();
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
  case ':':;
    GetCh();
    if (ch == '=') {
      GetCh();
      tok = becomes;
    } else {
      tok = colon;
    }
    break;
  case ';':;
    tok = semicolon;
    GetCh();
    break;
  case '<':;
    GetCh();
    if (ch == '=') {
      GetCh();
      tok = leq;
    } else if (ch == '>') {
      GetCh();
      tok = neq;
    } else {
      tok = lss;
    }
    break;
  case '=':;
    GetCh();
    if (ch == '=') {
      GetCh();
      tok = equiv;
    } else if (ch == '>') {
      GetCh();
      tok = rule;
    } else {
      tok = eql;
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
  default :
    tok = null;
    GetCh();
    break;
  }
}

static void PutToken
# ifdef __STDC__
()
# else
()
# endif
{
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("Token: ", 7L);
  switch (tok) {
  case times:;
    MASBIOS_SWRITE("times", 5L);
    break;
  case power:;
    MASBIOS_SWRITE("power", 5L);
    break;
  case plus:;
    MASBIOS_SWRITE("plus", 4L);
    break;
  case minus:;
    MASBIOS_SWRITE("minus", 5L);
    break;
  case div:;
    MASBIOS_SWRITE("div", 3L);
    break;
  case mod:;
    MASBIOS_SWRITE("mod", 3L);
    break;
  case semicolon:;
    MASBIOS_SWRITE("semicolon", 9L);
    break;
  case colon:;
    MASBIOS_SWRITE("colon", 5L);
    break;
  case eof:;
    MASBIOS_SWRITE("eof", 3L);
    break;
  case neq:;
    MASBIOS_SWRITE("neq", 3L);
    break;
  case eql:;
    MASBIOS_SWRITE("eql", 3L);
    break;
  case lss:;
    MASBIOS_SWRITE("lss", 3L);
    break;
  case leq:;
    MASBIOS_SWRITE("leq", 3L);
    break;
  case gtr:;
    MASBIOS_SWRITE("gtr", 3L);
    break;
  case geq:;
    MASBIOS_SWRITE("geq", 3L);
    break;
  case and:;
    MASBIOS_SWRITE("and", 3L);
    break;
  case or:;
    MASBIOS_SWRITE("or", 2L);
    break;
  case equiv:;
    MASBIOS_SWRITE("equiv", 5L);
    break;
  case rule:;
    MASBIOS_SWRITE("rule", 4L);
    break;
  case arrow:;
    MASBIOS_SWRITE("arrow", 5L);
    break;
  case comma:;
    MASBIOS_SWRITE("comma", 5L);
    break;
  case becomes:;
    MASBIOS_SWRITE("becomes", 7L);
    break;
  case lparen:;
    MASBIOS_SWRITE("lparen", 6L);
    break;
  case rparen:;
    MASBIOS_SWRITE("rparen", 6L);
    break;
  case rbrack:;
    MASBIOS_SWRITE("rbrack", 6L);
    break;
  case lbrack:;
    MASBIOS_SWRITE("lbrack", 6L);
    break;
  case rbrace:;
    MASBIOS_SWRITE("rbrace", 6L);
    break;
  case lbrace:;
    MASBIOS_SWRITE("lbrace", 6L);
    break;
  case period:;
    MASBIOS_SWRITE("period", 6L);
    break;
  case C_21_do:;
    MASBIOS_SWRITE("do", 2L);
    break;
  case C_22_if:;
    MASBIOS_SWRITE("if", 2L);
    break;
  case end:;
    MASBIOS_SWRITE("end", 3L);
    break;
  case not:;
    MASBIOS_SWRITE("not", 3L);
    break;
  case var:;
    MASBIOS_SWRITE("var", 3L);
    break;
  case expose:;
    MASBIOS_SWRITE("expose", 6L);
    break;
  case spec:;
    MASBIOS_SWRITE("spec", 4L);
    break;
  case impl:;
    MASBIOS_SWRITE("impl", 4L);
    break;
  case model:;
    MASBIOS_SWRITE("model", 5L);
    break;
  case axiom:;
    MASBIOS_SWRITE("axiom", 5L);
    break;
  case sig:;
    MASBIOS_SWRITE("sig", 3L);
    break;
  case map:;
    MASBIOS_SWRITE("map", 3L);
    break;
  case then:;
    MASBIOS_SWRITE("then", 4L);
    break;
  case C_20_else:;
    MASBIOS_SWRITE("else", 4L);
    break;
  case begin:;
    MASBIOS_SWRITE("begin", 5L);
    break;
  case C_23_while:;
    MASBIOS_SWRITE("while", 5L);
    break;
  case repeat:;
    MASBIOS_SWRITE("repeat", 6L);
    break;
  case until:;
    MASBIOS_SWRITE("until", 5L);
    break;
  case procedure:;
    MASBIOS_SWRITE("procedure", 9L);
    break;
  case number:;
    MASBIOS_SWRITE("number ", 7L);
    SACLIST_AWRITE(tokval);
    break;
  case ident:;
    MASBIOS_SWRITE("ident ", 6L);
    MASSYM2_SYWRIT(tokval);
    break;
  case string:;
    MASBIOS_SWRITE("string ", 7L);
    SACLIST_CLOUT(tokval);
    break;
  default :
    MASBIOS_SWRITE("null", 4L);
    break;
  }
  MASBIOS_BLINES(0);
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
  case times:;
    code = MASSTOR_COMP(prod, t);
    break;
  case power:;
    code = MASSTOR_COMP(exp, t);
    break;
  case plus:;
    code = MASSTOR_COMP(sum, t);
    break;
  case minus:;
    code = MASSTOR_COMP(dif, t);
    break;
  case div:;
    code = MASSTOR_COMP(quot, t);
    break;
  case mod:;
    code = MASSTOR_COMP(remain, t);
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
  case not:;
    code = MASSTOR_COMP(MASLISP_NOTS, t);
    break;
  case listex:;
    code = MASSTOR_COMP(MASLISP_LISTX, t);
    break;
  case becomes:;
    code = MASSTOR_COMP(MASLISP_ASSIGN, t);
    break;
  case C_22_if:;
    code = MASSTOR_COMP(MASLISP_IFS, t);
    break;
  case var:;
    code = MASSTOR_COMP(MASLISP_VARS, t);
    break;
  case sort:;
    code = MASSTOR_COMP(MASLISP_SORT, t);
    break;
  case expose:;
    code = MASSTOR_COMP(MASLISP_EXPOS, t);
    break;
  case tinfo:;
    code = SACLIST_COMP2(MASLISP_LISTX, MASLISP_TINFO, t);
    break;
  case import:;
    code = MASSTOR_COMP(MASLISP_IMPRT, t);
    break;
  case sig:;
    code = MASSTOR_COMP(MASLISP_SIG, t);
    break;
  case map:;
    code = MASSTOR_COMP(MASLISP_MAP, t);
    break;
  case rule:;
    code = MASSTOR_COMP(MASLISP_RULE, t);
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
  case C_23_while:;
    code = MASSTOR_COMP(MASLISP_WHL, t);
    break;
  case repeat:;
    code = MASSTOR_COMP(MASLISP_RPT, t);
    break;
  case procedure:;
    code = MASSTOR_COMP(MASLISP_DE, t);
    break;
  case spec:;
    code = MASSTOR_COMP(MASLISP_SPEC, t);
    break;
  case model:;
    code = MASSTOR_COMP(MASLISP_MODEL, t);
    break;
  case impl:;
    code = MASSTOR_COMP(MASLISP_IMPL, t);
    break;
  case axiom:;
    code = MASSTOR_COMP(MASLISP_AXIOM, t);
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

MASSTOR_LIST MASPARSE_Parse
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s;

  noerr = TRUE;
  ch = ' ';
  GetToken();
  s = TopBlock();
  if (tok != period) {
    SyntaxErr(9);
  }
  if (!noerr) {
    s = Generate(null, s);
  }
  return s;
}

static MASSTOR_LIST TopBlock
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST t, u, d;

  t = MASSTOR_SIL;
  for (;;) {
    if (tok == spec) {
      GetToken();
      u = SpecDec();
      t = MASSTOR_COMP(u, t);
    } else if (tok == impl) {
      GetToken();
      u = ImplDec();
      t = MASSTOR_COMP(u, t);
    } else if (tok == model) {
      GetToken();
      u = ModDec();
      t = MASSTOR_COMP(u, t);
    } else if (tok == axiom) {
      GetToken();
      u = AxiomDec();
      t = MASSTOR_COMP(u, t);
    } else if (tok == sort) {
      GetToken();
      u = SortDec();
      t = MASSTOR_COMP(u, t);
    } else if (tok == var) {
      GetToken();
      u = VarDec();
      t = MASSTOR_COMP(u, t);
    } else if (tok == procedure) {
      GetToken();
      u = ProcDec();
      t = MASSTOR_COMP(u, t);
    } else if (tok == expose) {
      GetToken();
      u = ImportDec(expose);
      t = MASSTOR_COMP(u, t);
    } else {
      goto EXIT_2;
    }
    if (tok == semicolon) {
      GetToken();
    } else {
      goto EXIT_2;
    }
  } EXIT_2:;
  u = Statement();
  if (u != MASSTOR_SIL) {
    t = MASSTOR_COMP(u, t);
  }
  t = MASSTOR_INV(t);
  t = Generate(begin, t);
  return t;
}

static MASSTOR_LIST Block
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST t, u, B, B1, B2, d;

  t = MASSTOR_SIL;
  B = blv;
  for (;;) {
    if (tok == var) {
      GetToken();
      u = VarDec();
      t = MASSTOR_COMP(u, t);
    } else if (tok == procedure) {
      GetToken();
      u = ProcDec();
      t = MASSTOR_COMP(u, t);
    } else {
      goto EXIT_3;
    }
    if (tok == semicolon) {
      GetToken();
    } else {
      goto EXIT_3;
    }
  } EXIT_3:;
  B1 = blv;
  u = Statement();
  if (u != MASSTOR_SIL) {
    t = MASSTOR_COMP(u, t);
  }
  t = MASSTOR_INV(t);
  B2 = blv;
  if (B2 != B1) {
    while (MASSTOR_RED(B2) != B1) {
      B2 = MASSTOR_RED(B2);
    }
    MASSTOR_SRED(B2, MASSTOR_SIL);
    MASBIOS_SWRITE("Variable(s) declared: ", 22L);
    MASSYM_UWRITE(blv);
    d = SACLIST_LIST2(blv, MASLISP_LISTX);
    d = Generate(var, d);
    t = MASSTOR_COMP(d, t);
  }
  blv = B;
  t = Generate(begin, t);
  return t;
}

static MASSTOR_LIST SpecDec
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, u, n, B;

  B = blv;
  s = MASSTOR_SIL;
  u = MASSTOR_SIL;
  n = MASSTOR_SIL;
  if (tok == ident) {
    n = tokval;
    s = HeadDec();
    u = SACLIST_CINV(s);
  } else {
    SyntaxErr(4);
  }
  if (tok == semicolon) {
    GetToken();
  } else {
    SyntaxErr(28);
  }
  for (;;) {
    if (tok == sort) {
      GetToken();
      s = SortDec();
      u = MASSTOR_COMP(s, u);
    } else if (tok == sig) {
      GetToken();
      s = SigDec();
      u = MASSTOR_COMP(s, u);
    } else if (tok == import) {
      GetToken();
      s = ImportDec(import);
      u = MASSTOR_COMP(s, u);
    } else if (tok == end) {
      GetToken();
      goto EXIT_4;
    } else if (tok == semicolon) {
      GetToken();
    } else {
      SyntaxErr(29);
      goto EXIT_4;
    }
  } EXIT_4:;
  if (tok == ident) {
    if (tokval != n) {
      SyntaxWrn(2);
    }
    GetToken();
  } else {
    SyntaxWrn(1);
  }
  u = MASSTOR_INV(u);
  u = Generate(spec, u);
  return u;
}

static MASSTOR_LIST ImplDec
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, u, n, B;

  B = blv;
  s = MASSTOR_SIL;
  u = MASSTOR_SIL;
  n = MASSTOR_SIL;
  if (tok == ident) {
    n = tokval;
    s = HeadDec();
    u = SACLIST_CINV(s);
  } else {
    SyntaxErr(4);
  }
  if (tok == semicolon) {
    GetToken();
  } else {
    SyntaxErr(28);
  }
  for (;;) {
    if (tok == var) {
      GetToken();
      s = VarDec();
      u = MASSTOR_COMP(s, u);
    } else if (tok == sort) {
      GetToken();
      s = SortDec();
      u = MASSTOR_COMP(s, u);
    } else if (tok == procedure) {
      GetToken();
      s = ProcDec();
      u = MASSTOR_COMP(s, u);
    } else if (tok == import) {
      GetToken();
      s = ImportDec(import);
      u = MASSTOR_COMP(s, u);
    } else if (tok == begin) {
      goto EXIT_5;
    } else if (tok == end) {
      goto EXIT_5;
    } else if (tok == semicolon) {
      GetToken();
    } else {
      SyntaxErr(33);
      goto EXIT_5;
    }
  } EXIT_5:;
  if (tok == end) {
    GetToken();
  } else if (tok == begin) {
    s = Statement();
    u = MASSTOR_COMP(s, u);
  } else {
    SyntaxErr(33);
  }
  if (tok == ident) {
    if (tokval != n) {
      SyntaxWrn(2);
    }
    GetToken();
  } else {
    SyntaxWrn(1);
  }
  blv = B;
  u = MASSTOR_INV(u);
  u = Generate(impl, u);
  return u;
}

static MASSTOR_LIST ModDec
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, u, n, B;

  B = blv;
  s = MASSTOR_SIL;
  u = MASSTOR_SIL;
  if (tok == ident) {
    n = tokval;
    s = HeadDec();
    u = SACLIST_CINV(s);
  } else {
    SyntaxErr(4);
  }
  if (tok == semicolon) {
    GetToken();
  } else {
    SyntaxErr(28);
  }
  for (;;) {
    if (tok == map) {
      GetToken();
      s = MapDec();
      u = MASSTOR_COMP(s, u);
    } else if (tok == sort) {
      GetToken();
      s = SortDec();
      u = MASSTOR_COMP(s, u);
    } else if (tok == import) {
      GetToken();
      s = ImportDec(import);
      u = MASSTOR_COMP(s, u);
    } else if (tok == semicolon) {
      GetToken();
    } else if (tok == end) {
      GetToken();
      goto EXIT_6;
    } else {
      SyntaxErr(29);
      goto EXIT_6;
    }
  } EXIT_6:;
  if (tok == ident) {
    if (tokval != n) {
      SyntaxWrn(2);
    }
    GetToken();
  } else {
    SyntaxWrn(1);
  }
  blv = B;
  u = MASSTOR_INV(u);
  u = Generate(model, u);
  return u;
}

static MASSTOR_LIST AxiomDec
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, u, n, B;

  B = blv;
  s = MASSTOR_SIL;
  u = MASSTOR_SIL;
  n = MASSTOR_SIL;
  if (tok == ident) {
    n = tokval;
    s = HeadDec();
    u = SACLIST_CINV(s);
  } else {
    SyntaxErr(4);
  }
  if (tok == semicolon) {
    GetToken();
  } else {
    SyntaxErr(28);
  }
  for (;;) {
    if (tok == rule) {
      GetToken();
      s = RuleDec();
      u = MASSTOR_COMP(s, u);
    } else if (tok == sort) {
      GetToken();
      s = SortDec();
      u = MASSTOR_COMP(s, u);
    } else if (tok == import) {
      GetToken();
      s = ImportDec(import);
      u = MASSTOR_COMP(s, u);
    } else if (tok == end) {
      GetToken();
      goto EXIT_7;
    } else if (tok == semicolon) {
      GetToken();
    } else {
      SyntaxErr(29);
      goto EXIT_7;
    }
  } EXIT_7:;
  if (tok == ident) {
    if (tokval != n) {
      SyntaxWrn(2);
    }
    GetToken();
  } else {
    SyntaxWrn(1);
  }
  blv = B;
  u = MASSTOR_INV(u);
  u = Generate(axiom, u);
  return u;
}

static MASSTOR_LIST ImportDec
# ifdef __STDC__
(Token t)
# else
(t)
Token t;
# endif
{
  MASSTOR_LIST s, u, e;

  s = MASSTOR_SIL;
  u = MASSTOR_SIL;
  e = MASSTOR_SIL;
  if (tok == ident) {
    s = HeadDec();
    u = MASSTOR_COMP(s, u);
  } else {
    SyntaxErr(4);
  }
  if (tok == lbrack) {
    GetToken();
    s = MASSTOR_SIL;
    for (;;) {
      if (tok == ident) {
        e = tokval;
        GetToken();
        if (tok == div) {
          GetToken();
        } else {
          SyntaxErr(31);
        }
        if (tok == ident) {
          s = MASSTOR_COMP(tokval, s);
          s = MASSTOR_COMP(e, s);
          GetToken();
        } else {
          SyntaxErr(4);
        }
      }
      if (tok == comma) {
        GetToken();
      } else if (tok == rbrack) {
        GetToken();
        goto EXIT_8;
      } else {
        SyntaxErr(30);
        goto EXIT_8;
      }
    } EXIT_8:;
    s = MASSTOR_INV(s);
    u = MASSTOR_COMP(s, u);
  }
  u = MASSTOR_INV(u);
  u = Generate(t, u);
  return u;
}

static MASSTOR_LIST MapDec
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, u, t;

  s = MASSTOR_SIL;
  u = MASSTOR_SIL;
  t = MASSTOR_SIL;
  if (tok == ident) {
    u = HeadDec();
    t = MASSTOR_COMP(u, t);
  } else {
    SyntaxErr(4);
  }
  if (tok == arrow) {
    GetToken();
  } else {
    SyntaxErr(22);
  }
  if (tok == ident) {
    s = HeadDec();
    t = MASSTOR_COMP(s, t);
  } else {
    SyntaxErr(4);
  }
  if (tok == when) {
    GetToken();
    if (tok == ident) {
      s = HeadDec();
      t = MASSTOR_COMP(s, t);
    } else {
      SyntaxErr(4);
    }
  }
  t = MASSTOR_INV(t);
  t = Generate(map, t);
  return t;
}

static MASSTOR_LIST RuleDec
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, u, t;

  s = MASSTOR_SIL;
  u = MASSTOR_SIL;
  u = Expression();
  t = MASSTOR_LIST1(u);
  if (tok == rule) {
    GetToken();
  } else {
    SyntaxErr(32);
  }
  s = Expression();
  t = MASSTOR_COMP(s, t);
  if (tok == when) {
    GetToken();
    s = Condition();
    t = MASSTOR_COMP(s, t);
  }
  t = MASSTOR_INV(t);
  t = Generate(rule, t);
  return t;
}

static MASSTOR_LIST VarDec
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, u;

  s = MASSTOR_SIL;
  u = MASSTOR_SIL;
  for (;;) {
    if (tok == ident) {
      s = MASSTOR_COMP(tokval, s);
      GetToken();
    } else {
      SyntaxErr(4);
    }
    if (tok == comma) {
      GetToken();
    } else if (tok == colon) {
      goto EXIT_9;
    } else if (tok == ident) {
      SyntaxErr(5);
    } else {
      SyntaxErr(15);
      goto EXIT_9;
    }
  } EXIT_9:;
  s = MASSTOR_INV(s);
  u = MASSTOR_COMP(s, u);
  if (tok == colon) {
    GetToken();
    s = TypeExpression();
    u = MASSTOR_COMP(s, u);
  }
  u = MASSTOR_INV(u);
  u = Generate(var, u);
  return u;
}

static MASSTOR_LIST SortDec
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s;

  s = MASSTOR_SIL;
  for (;;) {
    if (tok == ident) {
      s = MASSTOR_COMP(tokval, s);
      GetToken();
    } else {
      SyntaxErr(4);
    }
    if (tok == comma) {
      GetToken();
    } else if (tok == semicolon) {
      goto EXIT_10;
    } else {
      SyntaxErr(2);
      goto EXIT_10;
    }
  } EXIT_10:;
  s = MASSTOR_INV(s);
  s = Generate(sort, s);
  return s;
}

static MASSTOR_LIST SigDec
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, u;

  s = MASSTOR_SIL;
  u = MASSTOR_SIL;
  if (tok == ident) {
    s = MASSTOR_COMP(tokval, s);
    GetToken();
  } else {
    SyntaxErr(4);
  }
  if (tok == lparen) {
    GetToken();
    u = IdentList();
    if (tok == rparen) {
      GetToken();
    } else {
      SyntaxErr(5);
    }
  } else {
    SyntaxErr(23);
  }
  s = MASSTOR_COMP(u, s);
  u = MASSTOR_SIL;
  if (tok == colon) {
    GetToken();
    if (tok == ident) {
      u = MASSTOR_LIST1(tokval);
      GetToken();
    } else {
      SyntaxErr(23);
    }
  }
  s = MASSTOR_COMP(u, s);
  s = MASSTOR_INV(s);
  s = Generate(sig, s);
  return s;
}

static MASSTOR_LIST ProcDec
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST t, s, u, a, up;
  BOOLEAN ip;

  s = MASSTOR_SIL;
  u = MASSTOR_SIL;
  up = MASSTOR_SIL;
  a = MASSTOR_SIL;
  if (tok == ident) {
    a = tokval;
    s = MASSTOR_COMP(a, s);
    GetToken();
  } else {
    SyntaxErr(4);
  }
  if (tok == lparen) {
    GetToken();
    u = IdentList();
    if (tok == semicolon) {
      GetToken();
      if (tok == var) {
        GetToken();
      }
      up = IdentList();
    }
    if (tok == rparen) {
      GetToken();
    } else {
      SyntaxErr(5);
    }
  }
  u = SACLIST_LIST2(u, up);
  s = MASSTOR_COMP(u, s);
  if (tok == colon) {
    GetToken();
    if (tok == ident) {
      t = tokval;
      GetToken();
    } else {
      SyntaxErr(4);
    }
  }
  if (tok == semicolon) {
    GetToken();
  } else {
    SyntaxErr(5);
  }
  u = Block();
  s = MASSTOR_COMP(u, s);
  s = MASSTOR_INV(s);
  s = Generate(procedure, s);
  if (tok == ident) {
    if (a != tokval) {
      SyntaxWrn(2);
    }
    GetToken();
  } else {
    SyntaxWrn(1);
  }
  return s;
}

static MASSTOR_LIST HeadDec
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, u, a;

  s = MASSTOR_SIL;
  u = MASSTOR_SIL;
  a = MASSTOR_SIL;
  if (tok == ident) {
    a = tokval;
    s = MASSTOR_COMP(a, s);
    GetToken();
  } else {
    SyntaxErr(4);
  }
  if (tok == lparen) {
    GetToken();
    u = IdentList();
    if (tok == rparen) {
      GetToken();
    } else {
      SyntaxErr(24);
    }
  }
  s = MASSTOR_COMP(u, s);
  s = MASSTOR_INV(s);
  return s;
}

static MASSTOR_LIST StatSeq
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, t;

  t = MASSTOR_SIL;
  for (;;) {
    if (tok == semicolon) {
      GetToken();
    }
    if (tok == end) {
      GetToken();
      goto EXIT_11;
    } else if (tok == C_20_else) {
      goto EXIT_11;
    } else if (tok == period) {
      goto EXIT_11;
    } else if (tok == until) {
      GetToken();
      goto EXIT_11;
    }
    s = Statement();
    t = MASSTOR_COMP(s, t);
  } EXIT_11:;
  if (t != MASSTOR_SIL) {
    t = MASSTOR_INV(t);
    t = Generate(begin, t);
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
  MASSTOR_LIST s, t, u;

  t = MASSTOR_SIL;
  SyntaxTest(ident, 14);
  if (tok == ident) {
    s = tokval;
    GetToken();
    if (tok == becomes) {
      GetToken();
      u = ListExpr();
      t = SACLIST_LIST2(s, u);
      t = Generate(becomes, t);
      return t;
    } else if (tok == lparen) {
      GetToken();
      u = ActParms();
      t = MASSTOR_COMP(s, u);
      return t;
    }
    t = MASSTOR_LIST1(s);
    return t;
  }
  if (tok == begin) {
    GetToken();
    t = StatSeq();
    return t;
  }
  if (tok == C_22_if) {
    GetToken();
    s = Condition();
    t = MASSTOR_COMP(s, t);
    if (tok == then) {
      GetToken();
    } else {
      SyntaxErr(16);
    }
    s = StatSeq();
    t = MASSTOR_COMP(s, t);
    if (tok == C_20_else) {
      GetToken();
      s = StatSeq();
      t = MASSTOR_COMP(s, t);
    }
    t = MASSTOR_INV(t);
    t = Generate(C_22_if, t);
    return t;
  }
  if (tok == C_23_while) {
    GetToken();
    s = Condition();
    t = MASSTOR_COMP(s, t);
    if (tok == C_21_do) {
      GetToken();
    } else {
      SyntaxErr(18);
    }
    s = StatSeq();
    t = MASSTOR_COMP(s, t);
    t = MASSTOR_INV(t);
    t = Generate(C_23_while, t);
    return t;
  }
  if (tok == repeat) {
    GetToken();
    s = StatSeq();
    t = MASSTOR_COMP(s, t);
    s = Condition();
    t = MASSTOR_COMP(s, t);
    t = MASSTOR_INV(t);
    t = Generate(repeat, t);
    return t;
  }
  if (tok != period) {
    PutToken();
    SyntaxTest(period, 9);
  }
  return t;
}

static MASSTOR_LIST IdentList
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, u;

  u = MASSTOR_SIL;
  if (tok == rparen || tok == semicolon) {
    return u;
  }
  for (;;) {
    if (tok == ident) {
      u = MASSTOR_COMP(tokval, u);
      GetToken();
    } else {
      SyntaxErr(4);
    }
    if (tok == comma) {
      GetToken();
    } else if (tok == rparen || tok == semicolon) {
      goto EXIT_12;
    } else {
      SyntaxErr(27);
      goto EXIT_12;
    }
  } EXIT_12:;
  u = MASSTOR_INV(u);
  return u;
}

static MASSTOR_LIST ActParms
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, u;

  u = MASSTOR_SIL;
  for (;;) {
    if (tok == rparen) {
      GetToken();
      goto EXIT_13;
    }
    s = ListExpr();
    u = MASSTOR_COMP(s, u);
    if (tok == comma) {
      GetToken();
    } else if (tok == rparen) {
      GetToken();
      goto EXIT_13;
    } else {
      SyntaxErr(21);
      goto EXIT_13;
    }
  } EXIT_13:;
  u = MASSTOR_INV(u);
  return u;
}

static MASSTOR_LIST ListExpr
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, u;

  if (tok == lbrace) {
    GetToken();
  } else {
    u = Expression();
    return u;
  }
  u = MASSTOR_SIL;
  for (;;) {
    if (tok == rbrace) {
      GetToken();
      goto EXIT_14;
    }
    s = Expression();
    u = MASSTOR_COMP(s, u);
    if (tok == comma) {
      GetToken();
    } else if (tok == rbrace) {
      GetToken();
      goto EXIT_14;
    } else {
      SyntaxErr(34);
      goto EXIT_14;
    }
  } EXIT_14:;
  u = MASSTOR_INV(u);
  u = Generate(listex, u);
  return u;
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

  if (plus <= tok && tok <= minus) {
    oper = tok;
    GetToken();
    s = Term();
    if (oper == minus) {
      s = Generate(oper, MASSTOR_LIST1(s));
    }
  } else {
    s = Term();
  }
  while (plus <= tok && tok <= minus) {
    oper = tok;
    GetToken();
    u = Term();
    t = SACLIST_LIST2(s, u);
    s = Generate(oper, t);
  }
  return s;
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
    GetToken();
    t = Condition();
    t = Generate(not, MASSTOR_LIST1(t));
  } else if (tok == lparen) {
    GetToken();
    u = Condition();
    if (tok == rparen) {
      GetToken();
    } else {
      SyntaxErr(7);
    }
    if (and <= tok && tok <= or) {
      oper = tok;
      GetToken();
      if (tok == lparen) {
        GetToken();
      } else {
        SyntaxErr(24);
      }
      s = Condition();
      if (tok == rparen) {
        GetToken();
      } else {
        SyntaxErr(7);
      }
      t = SACLIST_LIST2(u, s);
      t = Generate(oper, t);
    } else {
      SyntaxErr(25);
    }
  } else {
    u = Expression();
    if (eql <= tok && tok <= geq) {
      oper = tok;
      GetToken();
      s = Expression();
      t = SACLIST_LIST2(u, s);
      t = Generate(oper, t);
    } else {
      SyntaxErr(20);
    }
  }
  return t;
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

  s = Power();
  while (times <= tok && tok <= mod) {
    oper = tok;
    GetToken();
    u = Power();
    t = SACLIST_LIST2(s, u);
    s = Generate(oper, t);
  }
  return s;
}

static MASSTOR_LIST Power
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST t, u, s;

  t = MASSTOR_SIL;
  s = 1;
  t = Factor();
  if (tok == power) {
    GetToken();
    if (tok == minus) {
      s = -s;
      GetToken();
    }
    if (tok == number) {
      u = tokval;
      GetToken();
      if (s < 0) {
        u = -u;
      }
      t = SACLIST_LIST2(t, u);
      t = Generate(power, t);
    } else {
      SyntaxErr(26);
    }
  }
  return t;
}

static MASSTOR_LIST Factor
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, t, u;

  t = MASSTOR_SIL;
  SyntaxTest(lparen, 6);
  if (tok == ident) {
    t = tokval;
    GetToken();
    if (tok == lparen) {
      GetToken();
      u = ActParms();
      t = MASSTOR_COMP(t, u);
    }
  } else if (tok == number) {
    t = tokval;
    GetToken();
  } else if (tok == string) {
    t = tokval;
    t = Generate(string, t);
    GetToken();
    if (tok == colon) {
      GetToken();
      s = TypeExpression();
      t = SACLIST_LIST3(MASLISP_CONVVAL, s, t);
    }
  } else if (tok == lparen) {
    GetToken();
    t = Expression();
    if (tok == rparen) {
      GetToken();
    } else {
      SyntaxErr(7);
    }
  } else {
    SyntaxErr(8);
  }
  return t;
}

static MASSTOR_LIST TypeExpression
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s, t, u;

  t = MASSTOR_SIL;
  u = MASSTOR_SIL;
  s = MASSTOR_SIL;
  if (tok == ident) {
    t = tokval;
    GetToken();
    if (tok == lparen) {
      GetToken();
      u = ActParms();
      t = MASSTOR_COMP(t, u);
    }
  } else {
    SyntaxErr(4);
  }
  if (tok == string) {
    s = tokval;
    GetToken();
    s = Generate(string, s);
    s = SACLIST_LIST3(MASLISP_CONVDES, t, s);
  }
  t = SACLIST_LIST3(MASLISP_LISTX, t, s);
  return t;
}

static void InitScanner
# ifdef __STDC__
()
# else
()
# endif
{
  MASLISPU_Declare(&KW, "KeyWord", 7L);
  KeyWord(C_21_do, "DO", 2L);
  KeyWord(to, "TO", 2L);
  KeyWord(C_22_if, "IF", 2L);
  KeyWord(end, "END", 3L);
  KeyWord(not, "NOT", 3L);
  KeyWord(and, "AND", 3L);
  KeyWord(or, "OR", 2L);
  KeyWord(var, "VAR", 3L);
  KeyWord(then, "THEN", 4L);
  KeyWord(C_20_else, "ELSE", 4L);
  KeyWord(begin, "BEGIN", 5L);
  KeyWord(sig, "SIGNATURE", 9L);
  KeyWord(C_23_while, "WHILE", 5L);
  KeyWord(until, "UNTIL", 5L);
  KeyWord(repeat, "REPEAT", 6L);
  KeyWord(procedure, "PROCEDURE", 9L);
  KeyWord(spec, "SPECIFICATION", 13L);
  KeyWord(model, "MODEL", 5L);
  KeyWord(import, "IMPORT", 6L);
  KeyWord(impl, "IMPLEMENTATION", 14L);
  KeyWord(axiom, "AXIOMS", 6L);
  KeyWord(map, "MAP", 3L);
  KeyWord(sort, "SORT", 4L);
  KeyWord(rule, "RULE", 4L);
  KeyWord(when, "WHEN", 4L);
  KeyWord(expose, "EXPOSE", 6L);
  KeyWord(C_21_do, "do", 2L);
  KeyWord(to, "to", 2L);
  KeyWord(C_22_if, "if", 2L);
  KeyWord(end, "end", 3L);
  KeyWord(not, "not", 3L);
  KeyWord(and, "and", 3L);
  KeyWord(or, "or", 2L);
  KeyWord(var, "var", 3L);
  KeyWord(then, "then", 4L);
  KeyWord(C_20_else, "else", 4L);
  KeyWord(begin, "begin", 5L);
  KeyWord(sig, "signature", 9L);
  KeyWord(C_23_while, "while", 5L);
  KeyWord(until, "until", 5L);
  KeyWord(repeat, "repeat", 6L);
  KeyWord(procedure, "procedure", 9L);
  KeyWord(spec, "specification", 13L);
  KeyWord(model, "model", 5L);
  KeyWord(import, "import", 6L);
  KeyWord(impl, "implementation", 14L);
  KeyWord(axiom, "axioms", 6L);
  KeyWord(map, "map", 3L);
  KeyWord(sort, "sort", 4L);
  KeyWord(rule, "rule", 4L);
  KeyWord(when, "when", 4L);
  KeyWord(expose, "expose", 6L);
}

static void InitParser
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST X, s, v;

  InitScanner();
  MASLISPU_Declare(&SUM, "SUM", 3L);
  MASLISPU_Declare(&DIF, "DIF", 3L);
  MASLISPU_Declare(&PROD, "PROD", 4L);
  MASLISPU_Declare(&Q, "Q", 1L);
  MASLISPU_Declare(&REMAIN, "REMAIN", 6L);
  MASLISPU_Declare(&EXP, "EXP", 3L);
  MASPARSE_SwitchParse(FALSE);
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

void MASPARSE_SwitchParse
# ifdef __STDC__
(BOOLEAN g)
# else
(g)
BOOLEAN g;
# endif
{
  if (!g) {
    genpars = FALSE;
    sum = MASLISP_ADD;
    dif = MASLISP_SUB;
    prod = MASLISP_MUL;
    quot = MASLISP_QUOT;
    remain = MASLISP_REM;
    exp = MASLISP_POW;
    return;
  }
  if (g) {
    genpars = TRUE;
    sum = SUM;
    dif = DIF;
    prod = PROD;
    quot = Q;
    remain = REMAIN;
    exp = EXP;
    return;
  }
}

void BEGIN_MASPARSE()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_MASBIOS();
    BEGIN_SACLIST();
    BEGIN_MASSYM2();
    BEGIN_MASSYM();
    BEGIN_MASLISPU();
    BEGIN_MASLISP();

    InitParser();
  }
}
