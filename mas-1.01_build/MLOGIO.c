#include "SYSTEM_.h"

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASERR
#include "MASERR.h"
#endif

#ifndef DEFINITION_MASLISP
#include "MASLISP.h"
#endif

#ifndef DEFINITION_MASLISPU
#include "MASLISPU.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_MASSYM
#include "MASSYM.h"
#endif

#ifndef DEFINITION_MASSYM2
#include "MASSYM2.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_MLOGBASE
#include "MLOGBASE.h"
#endif

#ifndef DEFINITION_MLOGIO
#include "MLOGIO.h"
#endif

CHAR MLOGIO_rcsid [] = "$Id: MLOGIO.md,v 1.2 1994/11/28 21:04:14 dolzmann Exp $";
CHAR MLOGIO_copyright [] = "Copyright (c) 1993 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MLOGIO.mi,v 1.2 1994/11/28 21:04:15 dolzmann Exp $";
static CHAR copyrighti [] = "Copyright (c) 1993 Universitaet Passau";
static MASSTOR_LIST ParserSyms;
static void pprtop ARGS((MASSTOR_LIST op));
static void ptexsymbol ARGS((MASSTOR_LIST sym));
static MASSTOR_LIST FORRDVARA ARGS((MASSTOR_LIST name, MASSTOR_LIST sdefault));
static MASSTOR_LIST FORRDQUANTA ARGS((MASLISPU_PROCF0 bbread));
static MASSTOR_LIST onearg ARGS((MASLISPU_PROCF0 bbread));
static MASSTOR_LIST twoargs ARGS((MASLISPU_PROCF0 bbread));
static MASSTOR_LIST multiarg ARGS((MASLISPU_PROCF0 bbread));
static MASSTOR_LIST atomicread ARGS((MASLISPU_PROCF0 bbread));
static void InitParser ARGS(());
static MASSTOR_LIST upcase ARGS((MASSTOR_LIST clist));
static void pushop ARGS((MASSTOR_LIST op, MASSTOR_LIST *opstack, MASSTOR_LIST *argstack));
static void push ARGS((MASSTOR_LIST elem, MASSTOR_LIST *stack));
static void pop ARGS((MASSTOR_LIST *elem, MASSTOR_LIST *stack));
static void pop2 ARGS((MASSTOR_LIST *elem1, MASSTOR_LIST *elem2, MASSTOR_LIST *stack));
static void gensubformula ARGS((MASSTOR_LIST prio, MASSTOR_LIST *opstack, MASSTOR_LIST *argstack));
static MASSTOR_LIST genformula ARGS((MASSTOR_LIST *opstack, MASSTOR_LIST *argstack));
static void aanop ARGS((MASSTOR_LIST lastsym, MASSTOR_LIST *opstack, MASSTOR_LIST *argstack));
static MASSTOR_LIST rdvlist ARGS(());
static void rdquanta ARGS((MASSTOR_LIST quant, MASSTOR_LIST *opstack, MASSTOR_LIST *argstack, MASLISPU_PROCF0 bbread));
static MASSTOR_LIST rdmasvar ARGS(());
static BOOLEAN isvarname ARGS((MASSTOR_LIST name));


void MLOGIO_FORPPRT
# ifdef __STDC__
(MASSTOR_LIST phi, MASLISPU_PROCP1 bbpprt)
# else
(phi, bbpprt)
MASSTOR_LIST phi;
MASLISPU_PROCP1 bbpprt;
# endif
{
  MASSTOR_LIST op, red, arg, arg1, arg2, vars, qform, C_21_dummy, sort, name;

  if (phi == MASSTOR_SIL) {
    MASBIOS_SWRITE("SIL", 3L);
    return;
  }
  MLOGBASE_FORPFOR(phi, &op, &red);
  if (op == MLOGBASE_VERUM || op == MLOGBASE_FALSUM) {
    pprtop(op);
  } else if (op == MLOGBASE_VEL || op == MLOGBASE_ET) {
    MLOGBASE_FORPARGS(red, &arg, &red);
    MASBIOS_SWRITE("(", 1L);
    MLOGIO_FORPPRT(arg, bbpprt);
    while (red != MASSTOR_SIL) {
      MLOGBASE_FORPARGS(red, &arg, &red);
      pprtop(op);
      MLOGIO_FORPPRT(arg, bbpprt);
    }
    MASBIOS_SWRITE(")", 1L);
  } else if (op == MLOGBASE_NON) {
    MLOGBASE_FORPUNOPA(red, &arg);
    pprtop(op);
    MASBIOS_SWRITE("(", 1L);
    MLOGIO_FORPPRT(arg, bbpprt);
    MASBIOS_SWRITE(")", 1L);
  } else if (op == MLOGBASE_IMP || op == MLOGBASE_REP || op == MLOGBASE_EQUIV || op == MLOGBASE_XOR) {
    MLOGBASE_FORPBINOPA(red, &arg1, &arg2);
    MASBIOS_SWRITE("(", 1L);
    MLOGIO_FORPPRT(arg1, bbpprt);
    pprtop(op);
    MLOGIO_FORPPRT(arg2, bbpprt);
    MASBIOS_SWRITE(")", 1L);
  } else if (op == MLOGBASE_EXIST || op == MLOGBASE_FORALL) {
    MLOGBASE_FORPQUANTA(red, &vars, &qform);
    MASBIOS_SWRITE("(", 1L);
    pprtop(op);
    MLOGIO_FORPPLVAR(vars);
    MASBIOS_SWRITE(":", 1L);
    MLOGIO_FORPPRT(qform, bbpprt);
    MASBIOS_SWRITE(")", 1L);
  } else if (op == MLOGBASE_TVAR) {
    MLOGIO_FORPPVAR(phi);
  } else {
    (*bbpprt)(phi);
  }
}

static void pprtop
# ifdef __STDC__
(MASSTOR_LIST op)
# else
(op)
MASSTOR_LIST op;
# endif
{
  if (op == MLOGBASE_IMP) {
    MASBIOS_SWRITE(" => ", 4L);
    return;
  }
  if (op == MLOGBASE_REP) {
    MASBIOS_SWRITE(" <= ", 4L);
    return;
  }
  if (op == MLOGBASE_EQUIV) {
    MASBIOS_SWRITE(" <=> ", 5L);
    return;
  }
  if (op == MLOGBASE_XOR) {
    MASBIOS_SWRITE(" <#> ", 5L);
    return;
  }
  if (op == MLOGBASE_ET) {
    MASBIOS_SWRITE(" /\\ ", 4L);
    return;
  }
  if (op == MLOGBASE_VEL) {
    MASBIOS_SWRITE(" \\/ ", 4L);
    return;
  }
  if (op == MLOGBASE_NON) {
    MASBIOS_SWRITE("-- ", 3L);
    return;
  }
  if (op == MLOGBASE_EXIST) {
    MASBIOS_SWRITE("EX ", 3L);
    return;
  }
  if (op == MLOGBASE_FORALL) {
    MASBIOS_SWRITE("FA ", 3L);
    return;
  }
  if (op == MLOGBASE_VERUM) {
    MASBIOS_SWRITE("TRUE", 4L);
    return;
  }
  if (op == MLOGBASE_FALSUM) {
    MASBIOS_SWRITE("FALSE", 5L);
    return;
  }
}

void MLOGIO_FORPPVAR
# ifdef __STDC__
(MASSTOR_LIST var)
# else
(var)
MASSTOR_LIST var;
# endif
{
  MASSTOR_LIST name, sort;

  MLOGBASE_FORPVAR(var, &name, &sort);
  SACLIST_CLOUT(MLOGBASE_FORVTGET(name));
  if (sort != MLOGBASE_ANY && sort != MLOGBASE_BOOL) {
    MASBIOS_SWRITE("{", 1L);
    SACLIST_CLOUT(MLOGBASE_FORVTGET(sort));
    MASBIOS_SWRITE("}", 1L);
  }
}

void MLOGIO_FORPPLVAR
# ifdef __STDC__
(MASSTOR_LIST lvar)
# else
(lvar)
MASSTOR_LIST lvar;
# endif
{
  MASSTOR_LIST var, varlist;

  MLOGBASE_FORPLVAR(lvar, &varlist);
  if (varlist == MASSTOR_SIL) {
    return;
  }
  MLOGBASE_FORPARGS(varlist, &var, &varlist);
  MLOGIO_FORPPVAR(var);
  while (varlist != MASSTOR_SIL) {
    MASBIOS_SWRITE(",", 1L);
    MLOGBASE_FORPARGS(varlist, &var, &varlist);
    MLOGIO_FORPPVAR(var);
  }
}

void MLOGIO_FORTEXW
# ifdef __STDC__
(MASSTOR_LIST phi, MASLISPU_PROCP1 bbtexw)
# else
(phi, bbtexw)
MASSTOR_LIST phi;
MASLISPU_PROCP1 bbtexw;
# endif
{
  MASSTOR_LIST op, red, arg, arg1, arg2, vars, qform;

  if (phi == MASSTOR_SIL) {
    MASBIOS_SWRITE("SIL", 3L);
    return;
  }
  MLOGBASE_FORPFOR(phi, &op, &red);
  if (op == MLOGBASE_VERUM || op == MLOGBASE_FALSUM) {
    MASBIOS_BLINES(0);
    ptexsymbol(phi);
  } else if (op == MLOGBASE_ET || op == MLOGBASE_VEL) {
    MASBIOS_BLINES(0);
    MLOGBASE_FORPARGS(red, &arg, &red);
    MASBIOS_SWRITE("(", 1L);
    MLOGIO_FORTEXW(arg, bbtexw);
    while (red != MASSTOR_SIL) {
      MLOGBASE_FORPARGS(red, &arg, &red);
      MASBIOS_SWRITE(" ", 1L);
      ptexsymbol(op);
      MASBIOS_SWRITE(" ", 1L);
      MLOGIO_FORTEXW(arg, bbtexw);
    }
    MASBIOS_SWRITE(")", 1L);
  } else if (op == MLOGBASE_NON) {
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("(", 1L);
    ptexsymbol(op);
    MLOGBASE_FORPUNOPA(red, &arg);
    MLOGIO_FORTEXW(arg, bbtexw);
    MASBIOS_SWRITE(")", 1L);
  } else if (op == MLOGBASE_EXIST || op == MLOGBASE_FORALL) {
    MASBIOS_BLINES(0);
    MLOGBASE_FORPQUANTA(red, &vars, &qform);
    MASBIOS_SWRITE("(", 1L);
    ptexsymbol(op);
    MLOGIO_FORTEXWLVAR(vars);
    MASBIOS_SWRITE("(", 1L);
    MLOGIO_FORTEXW(qform, bbtexw);
    MASBIOS_SWRITE("))", 2L);
  } else if (op == MLOGBASE_IMP || op == MLOGBASE_REP || op == MLOGBASE_EQUIV || op == MLOGBASE_XOR) {
    MASBIOS_BLINES(0);
    MLOGBASE_FORPBINOPA(red, &arg1, &arg2);
    MASBIOS_SWRITE("(", 1L);
    MLOGIO_FORTEXW(arg1, bbtexw);
    ptexsymbol(op);
    MLOGIO_FORTEXW(arg2, bbtexw);
    MASBIOS_SWRITE(")", 1L);
  } else if (op == MLOGBASE_TVAR) {
    MASBIOS_BLINES(0);
    MLOGIO_FORTEXWVAR(phi);
  } else {
    MASBIOS_BLINES(0);
    (*bbtexw)(phi);
  }
}

void MLOGIO_FORTEXWVAR
# ifdef __STDC__
(MASSTOR_LIST var)
# else
(var)
MASSTOR_LIST var;
# endif
{
  MASSTOR_LIST name, sort;

  MLOGBASE_FORPVAR(var, &name, &sort);
  SACLIST_CLOUT(MLOGBASE_FORVTGET(name));
  if (sort != MLOGBASE_ANY && sort != MLOGBASE_BOOL) {
    MASBIOS_SWRITE("{", 1L);
    SACLIST_CLOUT(MLOGBASE_FORVTGET(sort));
    MASBIOS_SWRITE("}", 1L);
  }
}

void MLOGIO_FORTEXWLVAR
# ifdef __STDC__
(MASSTOR_LIST lvar)
# else
(lvar)
MASSTOR_LIST lvar;
# endif
{
  MASSTOR_LIST var, red, sort, name;

  MLOGBASE_FORPLVAR(lvar, &red);
  MASSTOR_ADV(red, &var, &red);
  MLOGIO_FORTEXWVAR(var);
  while (red != MASSTOR_SIL) {
    MASSTOR_ADV(red, &var, &red);
    MASBIOS_SWRITE(", ", 2L);
    MLOGIO_FORTEXWVAR(var);
  }
}

static void ptexsymbol
# ifdef __STDC__
(MASSTOR_LIST sym)
# else
(sym)
MASSTOR_LIST sym;
# endif
{
  if (sym == MLOGBASE_VERUM) {
    MASBIOS_SWRITE("\\mbox{TRUE}", 11L);
    return;
  }
  if (sym == MLOGBASE_FALSUM) {
    MASBIOS_SWRITE("\\mbox{FALSE}", 12L);
    return;
  }
  if (sym == MLOGBASE_NON) {
    MASBIOS_SWRITE("\\lnot", 5L);
    return;
  }
  if (sym == MLOGBASE_ET) {
    MASBIOS_SWRITE("\\land", 5L);
    return;
  }
  if (sym == MLOGBASE_VEL) {
    MASBIOS_SWRITE("\\lor", 4L);
    return;
  }
  if (sym == MLOGBASE_IMP) {
    MASBIOS_SWRITE("\\Rightarrow", 11L);
    return;
  }
  if (sym == MLOGBASE_REP) {
    MASBIOS_SWRITE("\\Leftarrow", 10L);
    return;
  }
  if (sym == MLOGBASE_EQUIV) {
    MASBIOS_SWRITE("\\iff", 4L);
    return;
  }
  if (sym == MLOGBASE_XOR) {
    MASBIOS_SWRITE("\\oplus", 6L);
    return;
  }
  if (sym == MLOGBASE_EXIST) {
    MASBIOS_SWRITE("\\exists ", 8L);
    return;
  }
  if (sym == MLOGBASE_FORALL) {
    MASBIOS_SWRITE("\\forall ", 8L);
    return;
  }
  MASBIOS_SWRITE("\\mbox{???}", 10L);
  return;
}

MASSTOR_LIST MLOGIO_FORPREAD
# ifdef __STDC__
(MASLISPU_PROCF0 bbread)
# else
(bbread)
MASLISPU_PROCF0 bbread;
# endif
{
  MASELEM_GAMMAINT c;
  MASSTOR_LIST result, args, sym, info, noargs, key;

  c = MASBIOS_CREADB();
  if (c == 70) {
    result = MLOGIO_FORPREAD(bbread);
    c = MASBIOS_CREADB();
    if (c != MASBIOS_MASORD(')')) {
      MASBIOS_DIBUFF();
      MASERR_ERROR(MASERR_severe, ") expected", 10L);
      MASBIOS_BKSP();
    }
    return result;
  } else if (c == 85) {
    MASBIOS_BKSP();
    result = atomicread(bbread);
    return result;
  } else {
    MASBIOS_BKSP();
    key = MLOGIO_KEYREAD();
    result = upcase(key);
    info = MASSYM2_ASSOCQ(result, ParserSyms);
    if (info == MASSTOR_SIL) {
      return FORRDVARA(key, MLOGBASE_BOOL);
    } else {
      info = MASSTOR_FIRST(info);
      sym = MASSTOR_FIRST(info);
      noargs = SACLIST_SECOND(info);
      if (noargs == 0) {
        return MLOGBASE_FORMKCNST(sym);
      } else if (noargs == -1) {
        args = multiarg(bbread);
        return MLOGBASE_FORMKFOR(sym, args);
      } else if (noargs == 1) {
        args = onearg(bbread);
        return MLOGBASE_FORMKUNOP(sym, args);
      } else if (noargs == -2) {
        args = FORRDQUANTA(bbread);
        return MLOGBASE_FORMKQUANT(sym, MASSTOR_FIRST(args), SACLIST_SECOND(args));
      } else if (noargs == 2) {
        args = twoargs(bbread);
        return MLOGBASE_FORMKBINOP(sym, MASSTOR_FIRST(args), SACLIST_SECOND(args));
      } else {
        MASERR_ERROR(MASERR_severe, "FORPREAD: unknown noarg", 23L);
        return MASSTOR_SIL;
      }
    }
  }
}

MASSTOR_LIST MLOGIO_FORRDVAR
# ifdef __STDC__
()
# else
()
# endif
{
  MASELEM_GAMMAINT c;
  MASSTOR_LIST name, sort, sname, ssort;

  name = MASSYM2_SREAD1();
  if (!isvarname(name)) {
    MASBIOS_DIBUFF();
    MASERR_ERROR(MASERR_severe, "not valid as a variable name", 28L);
  }
  sname = MLOGBASE_FORVTENTER(name);
  c = MASBIOS_CREAD();
  if (c == 91) {
    sort = MASSYM2_SREAD1();
    if (!isvarname(sort)) {
      MASBIOS_DIBUFF();
      MASERR_ERROR(MASERR_severe, "not valid as a sort name", 24L);
    }
    ssort = MLOGBASE_FORVTENTER(sort);
    c = MASBIOS_CREADB();
    if (c != 92) {
      MASBIOS_DIBUFF();
      MASERR_ERROR(MASERR_severe, "} expected", 10L);
      MASBIOS_BKSP();
    }
  } else {
    MASBIOS_BKSP();
    ssort = MLOGBASE_ANY;
  }
  return MLOGBASE_FORMKVAR(sname, ssort);
}

static MASSTOR_LIST FORRDVARA
# ifdef __STDC__
(MASSTOR_LIST name, MASSTOR_LIST sdefault)
# else
(name, sdefault)
MASSTOR_LIST name, sdefault;
# endif
{
  MASELEM_GAMMAINT c;
  MASSTOR_LIST sort, sname, ssort;

  if (!isvarname(name)) {
    MASBIOS_DIBUFF();
    MASERR_ERROR(MASERR_severe, "not valid as a variable name", 28L);
  }
  sname = MLOGBASE_FORVTENTER(name);
  c = MASBIOS_CREAD();
  if (c == 91) {
    sort = MASSYM2_SREAD1();
    if (!isvarname(sort)) {
      MASBIOS_DIBUFF();
      MASERR_ERROR(MASERR_severe, "not valid as a sort name", 24L);
    }
    ssort = MLOGBASE_FORVTENTER(sort);
    c = MASBIOS_CREADB();
    if (c != 92) {
      MASBIOS_DIBUFF();
      MASERR_ERROR(MASERR_severe, "} expected", 10L);
      MASBIOS_BKSP();
    }
  } else {
    MASBIOS_BKSP();
    ssort = sdefault;
  }
  return MLOGBASE_FORMKVAR(sname, ssort);
}

MASSTOR_LIST MLOGIO_FORRDLVAR
# ifdef __STDC__
()
# else
()
# endif
{
  MASELEM_GAMMAINT c;
  MASSTOR_LIST var, vlist;

  c = MASBIOS_CREADB();
  if (MASBIOS_LETTER(c)) {
    MASBIOS_BKSP();
    var = MLOGIO_FORRDVAR();
    return MLOGBASE_FORMKLVAR(MASSTOR_LIST1(var));
  } else if (c == 70) {
    vlist = MASSTOR_SIL;
    c = MASBIOS_CREADB();
    while (c != 71) {
      MASBIOS_BKSP();
      var = MLOGIO_FORRDVAR();
      vlist = MASSTOR_COMP(var, vlist);
      c = MASBIOS_CREADB();
      if (c == 63) {
        c = MASBIOS_CREADB();
      }
    }
    return MLOGBASE_FORMKLVAR(MASSTOR_INV(vlist));
  } else {
    MASBIOS_DIBUFF();
    MASERR_ERROR(MASERR_severe, ") expected", 10L);
    MASBIOS_BKSP();
    return MASSTOR_SIL;
  }
}

static MASSTOR_LIST FORRDQUANTA
# ifdef __STDC__
(MASLISPU_PROCF0 bbread)
# else
(bbread)
MASLISPU_PROCF0 bbread;
# endif
{
  MASELEM_GAMMAINT c;
  MASSTOR_LIST varlist, phi;

  c = MASBIOS_CREADB();
  if (c != 70) {
    MASBIOS_DIBUFF();
    MASERR_ERROR(MASERR_severe, "( expected", 10L);
    MASBIOS_BKSP();
    return MASSTOR_SIL;
  }
  varlist = MLOGIO_FORRDLVAR();
  c = MASBIOS_CREADB();
  if (c != 63) {
    MASBIOS_BKSP();
  }
  phi = MLOGIO_FORPREAD(bbread);
  c = MASBIOS_CREADB();
  if (c != 71) {
    MASBIOS_DIBUFF();
    MASERR_ERROR(MASERR_severe, ") expected", 10L);
    MASBIOS_BKSP();
    return SACLIST_LIST2(varlist, phi);
  }
  return SACLIST_LIST2(varlist, phi);
}

static MASSTOR_LIST onearg
# ifdef __STDC__
(MASLISPU_PROCF0 bbread)
# else
(bbread)
MASLISPU_PROCF0 bbread;
# endif
{
  MASELEM_GAMMAINT c;
  MASSTOR_LIST arg;

  c = MASBIOS_CREADB();
  if (c != 70) {
    MASBIOS_DIBUFF();
    MASERR_ERROR(MASERR_severe, "( expected", 10L);
    MASBIOS_BKSP();
    return MASSTOR_SIL;
  }
  arg = MLOGIO_FORPREAD(bbread);
  c = MASBIOS_CREADB();
  if (c != 71) {
    MASBIOS_DIBUFF();
    MASERR_ERROR(MASERR_severe, ") expected", 10L);
    MASBIOS_BKSP();
    return arg;
  }
  return arg;
}

static MASSTOR_LIST twoargs
# ifdef __STDC__
(MASLISPU_PROCF0 bbread)
# else
(bbread)
MASLISPU_PROCF0 bbread;
# endif
{
  MASELEM_GAMMAINT c;
  MASSTOR_LIST arg, result;
  INTEGER i;

  c = MASBIOS_CREADB();
  if (c != 70) {
    MASBIOS_DIBUFF();
    MASERR_ERROR(MASERR_severe, "( expected", 10L);
    MASBIOS_BKSP();
    return MASSTOR_SIL;
  }
  result = MASSTOR_SIL;
  for (i = 1; i <= 2; i += 1) {
    arg = MLOGIO_FORPREAD(bbread);
    result = MASSTOR_COMP(arg, result);
    c = MASBIOS_CREADB();
    if (c != 63) {
      MASBIOS_BKSP();
    }
  }
  c = MASBIOS_CREADB();
  if (c != 71) {
    MASBIOS_DIBUFF();
    MASERR_ERROR(MASERR_severe, ") expected", 10L);
    MASBIOS_BKSP();
  }
  return MASSTOR_INV(result);
}

static MASSTOR_LIST multiarg
# ifdef __STDC__
(MASLISPU_PROCF0 bbread)
# else
(bbread)
MASLISPU_PROCF0 bbread;
# endif
{
  MASELEM_GAMMAINT c;
  MASSTOR_LIST arg, result;

  c = MASBIOS_CREADB();
  if (c != 70) {
    MASBIOS_DIBUFF();
    MASERR_ERROR(MASERR_severe, "( expected", 10L);
    MASBIOS_BKSP();
    return MASSTOR_SIL;
  }
  c = MASBIOS_CREADB();
  result = MASSTOR_SIL;
  while (c != 71) {
    MASBIOS_BKSP();
    arg = MLOGIO_FORPREAD(bbread);
    result = MASSTOR_COMP(arg, result);
    c = MASBIOS_CREADB();
    if (c == 63) {
      c = MASBIOS_CREADB();
    }
  }
  return MASSTOR_INV(result);
}

static MASSTOR_LIST atomicread
# ifdef __STDC__
(MASLISPU_PROCF0 bbread)
# else
(bbread)
MASLISPU_PROCF0 bbread;
# endif
{
  MASELEM_GAMMAINT c;
  MASSTOR_LIST result;

  c = MASBIOS_CREADB();
  result = (*bbread)();
  c = MASBIOS_CREADB();
  if (c != 87) {
    MASBIOS_DIBUFF();
    MASERR_ERROR(MASERR_severe, "] expected", 10L);
    MASBIOS_BKSP();
  }
  return result;
}

MASSTOR_LIST MLOGIO_KEYREAD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST C, L;
  MASSTOR_LIST end;

  L = MASSTOR_SIL;
  C = MASBIOS_CREADB();
  if (MASBIOS_LETTER(C)) {
    do {
      L = MASSTOR_COMP(C, L);
      C = MASBIOS_CREAD();
    } while (!(!MASBIOS_DIGIT(C) && !MASBIOS_LETTER(C)));
  } else {
    do {
      L = MASSTOR_COMP(C, L);
      C = MASBIOS_CREAD();
    } while (!(C == 70 || C == 71 || C == 72 || C == 85 || C == 87 || C == 91 || C == 92 || MASBIOS_DIGIT(C) || MASBIOS_LETTER(C)));
  }
  MASBIOS_BKSP();
  L = MASSTOR_INV(L);
  return L;
}

static void InitParser
# ifdef __STDC__
()
# else
()
# endif
{
  ParserSyms = MASSTOR_SIL;
  MASSTOR_LISTVAR(&ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("T", 1L), SACLIST_LIST3(MLOGBASE_VERUM, 0, -1), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("TRUE", 4L), SACLIST_LIST3(MLOGBASE_VERUM, 0, -1), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("VERUM", 5L), SACLIST_LIST3(MLOGBASE_VERUM, 0, -1), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("FALSE", 5L), SACLIST_LIST3(MLOGBASE_FALSUM, 0, -1), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("F", 1L), SACLIST_LIST3(MLOGBASE_FALSUM, 0, -1), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("FALSUM", 6L), SACLIST_LIST3(MLOGBASE_FALSUM, 0, -1), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("ET", 2L), SACLIST_LIST3(MLOGBASE_ET, -1, 2), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("AND", 3L), SACLIST_LIST3(MLOGBASE_ET, -1, 2), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("/\\", 2L), SACLIST_LIST3(MLOGBASE_ET, -1, 2), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("OR", 2L), SACLIST_LIST3(MLOGBASE_VEL, -1, 3), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("VEL", 3L), SACLIST_LIST3(MLOGBASE_VEL, -1, 3), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("\\/", 2L), SACLIST_LIST3(MLOGBASE_VEL, -1, 3), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("NOT", 3L), SACLIST_LIST3(MLOGBASE_NON, 1, 1), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("NOTT", 4L), SACLIST_LIST3(MLOGBASE_NON, 1, 1), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("NON", 3L), SACLIST_LIST3(MLOGBASE_NON, 1, 1), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("~", 1L), SACLIST_LIST3(MLOGBASE_NON, 1, 1), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("--", 2L), SACLIST_LIST3(MLOGBASE_NON, 1, 1), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("FORALL", 6L), SACLIST_LIST3(MLOGBASE_FORALL, -2, 6), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("ALL", 3L), SACLIST_LIST3(MLOGBASE_FORALL, -2, 6), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("FA", 2L), SACLIST_LIST3(MLOGBASE_FORALL, -2, 6), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("EX", 2L), SACLIST_LIST3(MLOGBASE_EXIST, -2, 6), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("EXIST", 5L), SACLIST_LIST3(MLOGBASE_EXIST, -2, 6), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("EXISTS", 6L), SACLIST_LIST3(MLOGBASE_EXIST, -2, 6), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("E", 1L), SACLIST_LIST3(MLOGBASE_EXIST, -2, 6), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("EQUIV", 5L), SACLIST_LIST3(MLOGBASE_EQUIV, 2, 5), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("<===>", 5L), SACLIST_LIST3(MLOGBASE_EQUIV, 2, 5), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("<=>", 3L), SACLIST_LIST3(MLOGBASE_EQUIV, 2, 5), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("IMP", 3L), SACLIST_LIST3(MLOGBASE_IMP, 2, 4), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("IMPL", 4L), SACLIST_LIST3(MLOGBASE_IMP, 2, 4), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("===>", 4L), SACLIST_LIST3(MLOGBASE_IMP, 2, 4), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("==>", 3L), SACLIST_LIST3(MLOGBASE_IMP, 2, 4), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("=>", 2L), SACLIST_LIST3(MLOGBASE_IMP, 2, 4), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("REP", 3L), SACLIST_LIST3(MLOGBASE_REP, 2, 4), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("REPL", 4L), SACLIST_LIST3(MLOGBASE_REP, 2, 4), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("<===", 4L), SACLIST_LIST3(MLOGBASE_REP, 2, 4), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("<==", 3L), SACLIST_LIST3(MLOGBASE_REP, 2, 4), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("<=", 2L), SACLIST_LIST3(MLOGBASE_REP, 2, 4), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("XOR", 3L), SACLIST_LIST3(MLOGBASE_XOR, 2, 5), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("ANTIV", 5L), SACLIST_LIST3(MLOGBASE_XOR, 2, 5), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("+", 1L), SACLIST_LIST3(MLOGBASE_XOR, 2, 5), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("<=/=>", 5L), SACLIST_LIST3(MLOGBASE_XOR, 2, 5), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("</>", 3L), SACLIST_LIST3(MLOGBASE_XOR, 2, 5), ParserSyms);
  ParserSyms = SACLIST_COMP2(MASBIOS_LISTS("<#>", 3L), SACLIST_LIST3(MLOGBASE_XOR, 2, 5), ParserSyms);
}

static MASSTOR_LIST upcase
# ifdef __STDC__
(MASSTOR_LIST clist)
# else
(clist)
MASSTOR_LIST clist;
# endif
{
  MASELEM_GAMMAINT c;
  MASSTOR_LIST result;

  result = MASSTOR_SIL;
  while (clist != MASSTOR_SIL) {
    MASSTOR_ADV(clist, &c, &clist);
    if (MASBIOS_LETTER(c) && MASELEM_MASEVEN(c)) {
      result = MASSTOR_COMP(c + 1, result);
    } else {
      result = MASSTOR_COMP(c, result);
    }
  }
  return MASSTOR_INV(result);
}

MASSTOR_LIST MLOGIO_FORIREAD
# ifdef __STDC__
(MASLISPU_PROCF0 bbread)
# else
(bbread)
MASLISPU_PROCF0 bbread;
# endif
{
  MASELEM_GAMMAINT c;
  MASSTOR_LIST result, info, sym, noargs, args, key, C_20_dummy;
  MASSTOR_LIST opstack, argstack;
  MASSTOR_LIST parlevel;
  BOOLEAN expectop;
  BOOLEAN exitifparl0;

  opstack = MASSTOR_SIL;
  argstack = MASSTOR_SIL;
  expectop = FALSE;
  parlevel = 0;
  c = MASBIOS_CREADB();
  MASBIOS_BKSP();
  exitifparl0 = FALSE;
  for (;;) {
    c = MASBIOS_CREADB();
    if (c == 70) {
      parlevel = parlevel + 1;
      push(SACLIST_LIST3(70, -99, 99), &opstack);
      if (expectop) {
        MASBIOS_DIBUFF();
        MASERR_ERROR(MASERR_severe, "operator expected", 17L);
      }
    } else if (c == 71) {
      if (parlevel <= 0) {
        MASBIOS_DIBUFF();
        MASERR_ERROR(MASERR_severe, "incorrect parenthesis", 21L);
      }
      if (!expectop) {
        MASBIOS_DIBUFF();
        MASERR_ERROR(MASERR_severe, "argument expected", 17L);
      }
      parlevel = parlevel - 1;
      gensubformula(99, &opstack, &argstack);
      pop(&C_20_dummy, &opstack);
      if (MASSTOR_FIRST(C_20_dummy) != 70) {
        MASBIOS_DIBUFF();
        MASERR_ERROR(MASERR_severe, "incocrect parenthesis", 21L);
      }
      if (exitifparl0) {
        goto EXIT_1;
      }
    } else if (c == 85) {
      if (expectop) {
        MASBIOS_DIBUFF();
        MASERR_ERROR(MASERR_severe, "operator expected", 17L);
      }
      expectop = TRUE;
      MASBIOS_BKSP();
      result = atomicread(bbread);
      push(result, &argstack);
    } else if (c == 75) {
      if (expectop) {
        MASBIOS_DIBUFF();
        MASERR_ERROR(MASERR_severe, "operator expected", 17L);
      }
      push(rdmasvar(), &argstack);
      expectop = TRUE;
    } else if (c == 62) {
      goto EXIT_1;
    } else {
      MASBIOS_BKSP();
      key = MLOGIO_KEYREAD();
      result = upcase(key);
      info = MASSYM2_ASSOCQ(result, ParserSyms);
      if (info == MASSTOR_SIL) {
        if (expectop) {
          MASBIOS_DIBUFF();
          MASERR_ERROR(MASERR_severe, "operator expected", 17L);
        }
        push(FORRDVARA(key, MLOGBASE_BOOL), &argstack);
        expectop = TRUE;
      } else {
        info = MASSTOR_FIRST(info);
        sym = MASSTOR_FIRST(info);
        noargs = SACLIST_SECOND(info);
        if (noargs == 0) {
          if (expectop) {
            MASBIOS_DIBUFF();
            MASERR_ERROR(MASERR_severe, "operator expected", 17L);
          }
          expectop = TRUE;
          push(MLOGBASE_FORMKCNST(sym), &argstack);
        } else if (noargs == 1) {
          if (expectop) {
            MASBIOS_DIBUFF();
            MASERR_ERROR(MASERR_severe, "operator expected", 17L);
          }
          pushop(info, &opstack, &argstack);
        } else if (noargs == 2) {
          if (!expectop) {
            MASBIOS_DIBUFF();
            MASERR_ERROR(MASERR_severe, "argument expected", 17L);
          }
          pushop(info, &opstack, &argstack);
          expectop = FALSE;
        } else if (noargs == -1) {
          if (!expectop) {
            MASBIOS_DIBUFF();
            MASERR_ERROR(MASERR_severe, "argument expected", 17L);
          }
          pushop(info, &opstack, &argstack);
          expectop = FALSE;
        } else if (noargs == -2) {
          if (expectop) {
            MASBIOS_DIBUFF();
            MASERR_ERROR(MASERR_severe, "operator expected", 17L);
          }
          rdquanta(info, &opstack, &argstack, bbread);
        } else {
          MASERR_ERROR(MASERR_severe, "parity not valid", 16L);
          pushop(info, &opstack, &argstack);
        }
      }
    }
  } EXIT_1:;
  if (parlevel > 0) {
    MASBIOS_DIBUFF();
    MASERR_ERROR(MASERR_severe, "incorrect parenthesis", 21L);
  }
  return genformula(&opstack, &argstack);
}

static void pushop
# ifdef __STDC__
(MASSTOR_LIST op, MASSTOR_LIST *opstack, MASSTOR_LIST *argstack)
# else
(op, opstack, argstack)
MASSTOR_LIST op;
MASSTOR_LIST *opstack, *argstack;
# endif
{
  MASSTOR_LIST sym, noargs, prio, lastop, lastsym, lastnoargs, lastprio;
  MASSTOR_LIST phi;

  if (*opstack == MASSTOR_SIL) {
    push(op, opstack);
    return;
  }
  sym = MASSTOR_FIRST(op);
  noargs = SACLIST_SECOND(op);
  prio = SACLIST_THIRD(op);
  lastop = MASSTOR_FIRST(*opstack);
  lastsym = MASSTOR_FIRST(lastop);
  lastnoargs = SACLIST_SECOND(lastop);
  lastprio = SACLIST_THIRD(lastop);
  if (prio < lastprio) {
    push(op, opstack);
    return;
  } else if (prio > lastprio) {
    gensubformula(prio, opstack, argstack);
    push(op, opstack);
  } else if (prio == lastprio) {
    if (noargs == 1) {
      push(op, opstack);
    } else if (noargs > 1) {
      gensubformula(prio, opstack, argstack);
      push(op, opstack);
    } else if (noargs == -1 && sym == lastsym) {
      push(op, opstack);
    } else if (noargs == -1 && sym != lastsym) {
      gensubformula(prio, opstack, argstack);
      push(op, opstack);
    } else if (noargs == -2) {
      if (lastnoargs == -2) {
        push(op, opstack);
      } else {
        gensubformula(prio, opstack, argstack);
        push(op, opstack);
      }
    } else {
      MASBIOS_DIBUFF();
      MASERR_ERROR(MASERR_severe, "INTERNAL ERROR (pushop): wrong noargs ", 38L);
    }
  }
}

static void push
# ifdef __STDC__
(MASSTOR_LIST elem, MASSTOR_LIST *stack)
# else
(elem, stack)
MASSTOR_LIST elem;
MASSTOR_LIST *stack;
# endif
{
  *stack = MASSTOR_COMP(elem, *stack);
}

static void pop
# ifdef __STDC__
(MASSTOR_LIST *elem, MASSTOR_LIST *stack)
# else
(elem, stack)
MASSTOR_LIST *elem, *stack;
# endif
{
  if (*stack == MASSTOR_SIL) {
    MASERR_ERROR(MASERR_fatal, "POP: pop to empty stack", 23L);
    *elem = MASSTOR_SIL;
    return;
  } else {
    MASSTOR_ADV(*stack, elem, stack);
    return;
  }
}

static void pop2
# ifdef __STDC__
(MASSTOR_LIST *elem1, MASSTOR_LIST *elem2, MASSTOR_LIST *stack)
# else
(elem1, elem2, stack)
MASSTOR_LIST *elem1, *elem2, *stack;
# endif
{
  if (*stack == MASSTOR_SIL || MASSTOR_RED(*stack) == MASSTOR_SIL) {
    MASERR_ERROR(MASERR_fatal, "POP2: pop to empty stack", 24L);
    *elem1 = MASSTOR_SIL;
    *elem2 = MASSTOR_SIL;
    return;
  } else {
    SACLIST_ADV2(*stack, elem1, elem2, stack);
    return;
  }
}

static void gensubformula
# ifdef __STDC__
(MASSTOR_LIST prio, MASSTOR_LIST *opstack, MASSTOR_LIST *argstack)
# else
(prio, opstack, argstack)
MASSTOR_LIST prio;
MASSTOR_LIST *opstack, *argstack;
# endif
{
  MASSTOR_LIST lastop, lastsym, lastnoargs, lastprio, result;
  MASSTOR_LIST arg, arg1, arg2;

  while (*opstack != MASSTOR_SIL && SACLIST_THIRD(MASSTOR_FIRST(*opstack)) <= prio && MASSTOR_FIRST(MASSTOR_FIRST(*opstack)) != 70) {
    pop(&lastop, opstack);
    lastsym = MASSTOR_FIRST(lastop);
    lastnoargs = SACLIST_SECOND(lastop);
    lastprio = SACLIST_THIRD(lastop);
    if (lastnoargs == 1) {
      pop(&arg, argstack);
      push(MLOGBASE_FORMKUNOP(lastsym, arg), argstack);
    } else if (lastnoargs == 2) {
      pop2(&arg2, &arg1, argstack);
      push(MLOGBASE_FORMKBINOP(lastsym, arg1, arg2), argstack);
    } else if (lastnoargs == -1) {
      aanop(lastsym, opstack, argstack);
    } else if (lastnoargs == -2) {
      pop2(&arg2, &arg1, argstack);
      push(MLOGBASE_FORMKQUANT(lastsym, arg1, arg2), argstack);
    } else {
      MASBIOS_DIBUFF();
      MASERR_ERROR(MASERR_severe, "INTERNAL ERROR (gensubf): wrong noargs", 38L);
    }
  }
}

static MASSTOR_LIST genformula
# ifdef __STDC__
(MASSTOR_LIST *opstack, MASSTOR_LIST *argstack)
# else
(opstack, argstack)
MASSTOR_LIST *opstack, *argstack;
# endif
{
  MASSTOR_LIST result;

  if (*opstack == MASSTOR_SIL) {
    if (*argstack == MASSTOR_SIL) {
      return MLOGBASE_VERUM;
    }
    MASSTOR_ADV(*argstack, &result, argstack);
  } else {
    gensubformula(99, opstack, argstack);
    MASSTOR_ADV(*argstack, &result, argstack);
  }
  return result;
}

static void aanop
# ifdef __STDC__
(MASSTOR_LIST lastsym, MASSTOR_LIST *opstack, MASSTOR_LIST *argstack)
# else
(lastsym, opstack, argstack)
MASSTOR_LIST lastsym;
MASSTOR_LIST *opstack, *argstack;
# endif
{
  MASSTOR_LIST arg, arg1, arg2, arglist, op;

  arglist = MASSTOR_SIL;
  pop2(&arg2, &arg1, argstack);
  arglist = SACLIST_LIST2(arg1, arg2);
  while (*opstack != MASSTOR_SIL && MASSTOR_FIRST(MASSTOR_FIRST(*opstack)) == lastsym) {
    MASSTOR_ADV(*opstack, &op, opstack);
    MASSTOR_ADV(*argstack, &arg, argstack);
    arglist = MASSTOR_COMP(arg, arglist);
  }
  push(MLOGBASE_FORMKFOR(lastsym, arglist), argstack);
  return;
}

static MASSTOR_LIST rdvlist
# ifdef __STDC__
()
# else
()
# endif
{
  MASELEM_GAMMAINT c;
  MASSTOR_LIST var, vlist;

  vlist = MASSTOR_SIL;
  c = MASBIOS_CREADB();
  while (c != 79 && c != 70) {
    MASBIOS_BKSP();
    var = MLOGIO_FORRDVAR();
    vlist = MASSTOR_COMP(var, vlist);
    c = MASBIOS_CREADB();
    if (c == 63) {
      c = MASBIOS_CREADB();
    }
  }
  if (c == 70) {
    MASBIOS_BKSP();
  }
  return MLOGBASE_FORMKLVAR(MASSTOR_INV(vlist));
}

static void rdquanta
# ifdef __STDC__
(MASSTOR_LIST quant, MASSTOR_LIST *opstack, MASSTOR_LIST *argstack, MASLISPU_PROCF0 bbread)
# else
(quant, opstack, argstack, bbread)
MASSTOR_LIST quant;
MASSTOR_LIST *opstack, *argstack;
MASLISPU_PROCF0 bbread;
# endif
{
  MASELEM_GAMMAINT c;
  MASSTOR_LIST varlist, phi, vars, alist;

  c = MASBIOS_CREADB();
  if (c == 70) {
    MASBIOS_BKSP();
    alist = FORRDQUANTA(bbread);
    vars = MASSTOR_FIRST(alist);
    phi = SACLIST_SECOND(alist);
    push(MLOGBASE_FORMKQUANT(quant, vars, phi), argstack);
    return;
  }
  MASBIOS_BKSP();
  varlist = rdvlist();
  pushop(quant, opstack, argstack);
  push(varlist, argstack);
}

static MASSTOR_LIST rdmasvar
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST s;
  MASSTOR_LIST V, var, val;

  V = MASLISP_ENV;
  s = MASSYM2_SREAD();
  while (V != MASSTOR_SIL) {
    SACLIST_ADV2(V, &var, &val, &V);
    if (var == s) {
      return val;
    }
  }
  MASBIOS_DIBUFF();
  MASERR_ERROR(MASERR_severe, "not defined as a mas variable", 29L);
  return MLOGBASE_VERUM;
}

static BOOLEAN isvarname
# ifdef __STDC__
(MASSTOR_LIST name)
# else
(name)
MASSTOR_LIST name;
# endif
{
  MASSTOR_LIST c;

  if (name == MASSTOR_SIL) {
    return FALSE;
  }
  MASSTOR_ADV(name, &c, &name);
  if (!MASBIOS_LETTER(c)) {
    return FALSE;
  }
  while (name != MASSTOR_SIL) {
    MASSTOR_ADV(name, &c, &name);
    if (!(MASBIOS_LETTER(c) || MASBIOS_DIGIT(c))) {
      return FALSE;
    }
  }
  return TRUE;
}

void BEGIN_MLOGIO()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASLISPU();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_MASERR();
    BEGIN_MASLISP();
    BEGIN_MASLISPU();
    BEGIN_MASBIOS();
    BEGIN_MASSYM();
    BEGIN_MASSYM2();
    BEGIN_SACLIST();
    BEGIN_MLOGBASE();

    InitParser();
  }
}
