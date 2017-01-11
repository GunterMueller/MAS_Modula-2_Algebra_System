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

#ifndef DEFINITION_MASLOG
#include "MASLOG.h"
#endif

#ifndef DEFINITION_MLOGIO
#include "MLOGIO.h"
#endif

#ifndef DEFINITION_MLDEMO
#include "MLDEMO.h"
#endif

CHAR MLDEMO_rcsid [] = "$Id: MLDEMO.md,v 1.5 1995/11/04 18:00:23 pesch Exp $";
CHAR MLDEMO_copyright [] = "Copyright (c) 1993 Universitaet Passau";
MASSTOR_LIST MLDEMO_EQU, MLDEMO_NEQ;

static CHAR rcsidi [] = "$Id: MLDEMO.mi,v 1.5 1995/11/04 18:00:25 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1993 Universitaet Passau";
static MASSTOR_LIST BbfParserSyms;
static BOOLEAN mldbbtst ARGS((MASSTOR_LIST l));
static void mldbbpprt ARGS((MASSTOR_LIST phi));
static void bbpprtop ARGS((MASSTOR_LIST op));
static void mldbbtexw ARGS((MASSTOR_LIST phi));
static void bbtexwop ARGS((MASSTOR_LIST op));
static MASSTOR_LIST mldbbmkneg ARGS((MASSTOR_LIST phi));
static MASSTOR_LIST mldbbsmpl ARGS((MASSTOR_LIST phi));
static MASSTOR_LIST mldbbsubstvar ARGS((MASSTOR_LIST phi, MASSTOR_LIST old, MASSTOR_LIST new));
static BOOLEAN mldbbcontvar ARGS((MASSTOR_LIST phi, MASSTOR_LIST var));
static MASSTOR_LIST mldbblsvars ARGS((MASSTOR_LIST phi));
static MASSTOR_LIST mldbbread ARGS(());
static MASSTOR_LIST readarg ARGS(());
static void InitBbfParser ARGS(());
static MASSTOR_LIST apply ARGS((MASSTOR_LIST phi));


MASSTOR_LIST MLDEMO_MLDMKATOM
# ifdef __STDC__
(MASSTOR_LIST rel, MASSTOR_LIST left, MASSTOR_LIST right)
# else
(rel, left, right)
MASSTOR_LIST rel, left, right;
# endif
{
  return SACLIST_LIST3(rel, left, right);
}

static BOOLEAN mldbbtst
# ifdef __STDC__
(MASSTOR_LIST l)
# else
(l)
MASSTOR_LIST l;
# endif
{
  MASSTOR_LIST op, arg1, arg2, red;

  if (l == MASSTOR_SIL) {
    return FALSE;
  }
  if (MASSYM2_SYMBOL(l) || MASSYM_ATOM(l)) {
    return FALSE;
  }
  MASSTOR_ADV(l, &op, &red);
  if (!MASSYM2_SYMBOL(op)) {
    return FALSE;
  }
  if (MASSYM2_ACOMP(op, MLDEMO_EQU) == 0 || MASSYM2_ACOMP(op, MLDEMO_NEQ) == 0) {
    if (red == MASSTOR_SIL || MASSTOR_RED(red) == MASSTOR_SIL) {
      return FALSE;
    }
    SACLIST_ADV2(red, &arg1, &arg2, &red);
    if (red != MASSTOR_SIL) {
      return FALSE;
    }
    if (!MASSYM_ATOM(arg1) && !MLOGBASE_FORISVAR(arg1) || !MASSYM_ATOM(arg2) && !MLOGBASE_FORISVAR(arg2)) {
      return FALSE;
    } else {
      return TRUE;
    }
  } else {
    return TRUE;
  }
}

static void mldbbpprt
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  MASSTOR_LIST op, red, arg1, arg2, C_23_dummy;

  MASSTOR_ADV(phi, &op, &red);
  if (op == MLDEMO_EQU || op == MLDEMO_NEQ) {
    SACLIST_ADV2(red, &arg1, &arg2, &C_23_dummy);
    MASBIOS_SWRITE("[", 1L);
    if (MLOGBASE_FORISVAR(arg1)) {
      MLOGIO_FORPPVAR(arg1);
    } else {
      MASSYM_UWRIT1(arg1);
    }
    bbpprtop(op);
    if (MLOGBASE_FORISVAR(arg2)) {
      MLOGIO_FORPPVAR(arg2);
    } else {
      MASSYM_UWRIT1(arg2);
    }
    MASBIOS_SWRITE("]", 1L);
  } else {
    MASBIOS_SWRITE("[", 1L);
    MASSYM_UWRIT1(phi);
    MASBIOS_SWRITE("]", 1L);
  }
}

static void bbpprtop
# ifdef __STDC__
(MASSTOR_LIST op)
# else
(op)
MASSTOR_LIST op;
# endif
{
  if (op == MLDEMO_EQU) {
    MASBIOS_SWRITE("=", 1L);
    return;
  }
  if (op == MLDEMO_NEQ) {
    MASBIOS_SWRITE("<>", 2L);
    return;
  }
}

static void mldbbtexw
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  MASSTOR_LIST op, red, arg1, arg2, C_22_dummy;

  MASSTOR_ADV(phi, &op, &red);
  if (op == MLDEMO_EQU || op == MLDEMO_NEQ) {
    MASBIOS_BLINES(0);
    SACLIST_ADV2(red, &arg1, &arg2, &C_22_dummy);
    MASBIOS_SWRITE("(", 1L);
    MASBIOS_SWRITE("\\mbox{\\tt ", 10L);
    MASSYM_UWRIT1(arg1);
    MASBIOS_SWRITE("}", 1L);
    bbtexwop(op);
    MASBIOS_SWRITE("\\mbox{\\tt ", 10L);
    MASSYM_UWRIT1(arg2);
    MASBIOS_SWRITE("}", 1L);
    MASBIOS_SWRITE(")", 1L);
  } else {
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("\\mbox{\\tt ", 10L);
    MASSYM_UWRIT1(phi);
    MASBIOS_SWRITE("}", 1L);
  }
}

static void bbtexwop
# ifdef __STDC__
(MASSTOR_LIST op)
# else
(op)
MASSTOR_LIST op;
# endif
{
  if (op == MLDEMO_EQU) {
    MASBIOS_SWRITE("=", 1L);
    return;
  }
  if (op == MLDEMO_NEQ) {
    MASBIOS_SWRITE("\\neq", 4L);
    return;
  }
}

static MASSTOR_LIST mldbbmkneg
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  MASSTOR_LIST op, res;

  MASSTOR_ADV(phi, &op, &res);
  if (op == MLDEMO_EQU) {
    return SACLIST_CCONC(MASSTOR_LIST1(MLDEMO_NEQ), res);
  } else if (op == MLDEMO_NEQ) {
    return SACLIST_CCONC(MASSTOR_LIST1(MLDEMO_EQU), res);
  } else {
    return MLOGBASE_FORMKUNOP(MLOGBASE_NON, phi);
  }
}

static MASSTOR_LIST mldbbsmpl
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  MASSTOR_LIST op, res, a, b, C_21_dummy;

  if (phi == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  MASSTOR_ADV(phi, &op, &res);
  if (op == MLDEMO_NEQ || op == MLDEMO_EQU) {
    SACLIST_ADV2(res, &a, &b, &C_21_dummy);
    if (MASSYM_ATOM(a) && MASSYM_ATOM(b)) {
      if (op == MLDEMO_EQU && a == b) {
        return MLOGBASE_FORMKCNST(MLOGBASE_VERUM);
      } else if (op == MLDEMO_EQU && a != b) {
        return MLOGBASE_FORMKCNST(MLOGBASE_FALSUM);
      } else if (op == MLDEMO_NEQ && a != b) {
        return MLOGBASE_FORMKCNST(MLOGBASE_VERUM);
      } else {
        return MLOGBASE_FORMKCNST(MLOGBASE_FALSUM);
      }
    } else {
      return phi;
    }
  } else {
    return phi;
  }
}

static MASSTOR_LIST mldbbsubstvar
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST old, MASSTOR_LIST new)
# else
(phi, old, new)
MASSTOR_LIST phi, old, new;
# endif
{
  MASSTOR_LIST op, res, a, b, C_20_dummy, aname, asort, bname, bsort, oname, osort;

  MASSTOR_ADV(phi, &op, &res);
  if (op == MLDEMO_EQU || op == MLDEMO_NEQ) {
    SACLIST_ADV2(res, &a, &b, &C_20_dummy);
    MLOGBASE_FORPVAR(old, &oname, &osort);
    if (!MASSYM_ATOM(a)) {
      MLOGBASE_FORPVAR(a, &aname, &asort);
      if (aname == oname && asort == osort) {
        a = new;
      }
    }
    if (!MASSYM_ATOM(b)) {
      MLOGBASE_FORPVAR(b, &bname, &bsort);
      if (bname == oname && bsort == osort) {
        b = new;
      }
    }
    return SACLIST_LIST3(op, a, b);
  } else {
    return phi;
  }
}

static BOOLEAN mldbbcontvar
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST var)
# else
(phi, var)
MASSTOR_LIST phi, var;
# endif
{
  MASSTOR_LIST op, res, a, b, C_19_dummy;

  MASSTOR_ADV(phi, &op, &res);
  if (op == MLDEMO_EQU || op == MLDEMO_NEQ) {
    SACLIST_ADV2(res, &a, &b, &C_19_dummy);
    if (a == var || b == var) {
      return TRUE;
    } else {
      return FALSE;
    }
  } else {
    return FALSE;
  }
}

static MASSTOR_LIST mldbblsvars
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  MASSTOR_LIST op, lhs, rhs, red, C_18_dummy, result;

  result = MASSTOR_SIL;
  MASSTOR_ADV(phi, &op, &red);
  if (op == MLDEMO_EQU || op == MLDEMO_NEQ) {
    SACLIST_ADV2(red, &lhs, &rhs, &C_18_dummy);
    if (MLOGBASE_FORISVAR(lhs)) {
      result = MASSTOR_COMP(lhs, result);
    }
    if (MLOGBASE_FORISVAR(rhs)) {
      result = MASSTOR_COMP(rhs, result);
    }
    return result;
  } else {
    return MASSTOR_SIL;
  }
}

static MASSTOR_LIST mldbbread
# ifdef __STDC__
()
# else
()
# endif
{
  MASELEM_GAMMAINT c;
  MASSTOR_LIST result;
  MASSTOR_LIST lhs, rhs, rel, sym;

  lhs = readarg();
  rel = MLOGIO_KEYREAD();
  sym = MASSYM2_ASSOCQ(rel, BbfParserSyms);
  if (sym == MASSTOR_SIL) {
    MASBIOS_DIBUFF();
    MASERR_ERROR(MASERR_severe, "unknown relation", 16L);
    return MASSTOR_SIL;
  } else {
    sym = MASSTOR_FIRST(sym);
  }
  rhs = readarg();
  return MLDEMO_MLDMKATOM(sym, lhs, rhs);
}

static MASSTOR_LIST readarg
# ifdef __STDC__
()
# else
()
# endif
{
  MASELEM_GAMMAINT c;
  MASSTOR_LIST result;

  c = MASBIOS_CREADB();
  if (MASBIOS_LETTER(c)) {
    MASBIOS_BKSP();
    result = MLOGIO_FORRDVAR();
    return result;
  } else if (MASBIOS_DIGIT(c)) {
    MASBIOS_BKSP();
    result = SACLIST_AREAD();
    return result;
  } else {
    MASBIOS_DIBUFF();
    MASERR_ERROR(MASERR_severe, "ATOM or SYMBOL expected", 23L);
    return MASSTOR_SIL;
  }
}

static void InitBbfParser
# ifdef __STDC__
()
# else
()
# endif
{
  BbfParserSyms = MASSTOR_SIL;
  MASSTOR_LISTVAR(&BbfParserSyms);
  BbfParserSyms = SACLIST_LIST4(MASBIOS_LISTS("<>", 2L), MLDEMO_NEQ, MASBIOS_LISTS("=", 1L), MLDEMO_EQU);
  return;
}

static MASSTOR_LIST apply
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  MASSYM_UWRITE(phi);
  return phi;
}

MASSTOR_LIST MLDEMO_MLDTST
# ifdef __STDC__
(MASSTOR_LIST l)
# else
(l)
MASSTOR_LIST l;
# endif
{
  if (MLOGBASE_FORTST(l, mldbbtst)) {
    return (MASSTOR_LIST)1;
  } else {
    return (MASSTOR_LIST)0;
  }
}

MASSTOR_LIST MLDEMO_MLDMKPOS
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  return MASLOG_FORMKPOS(phi, MLOGBASE_NON, mldbbmkneg);
}

MASSTOR_LIST MLDEMO_MLDMKPOS1
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST pref)
# else
(phi, pref)
MASSTOR_LIST phi, pref;
# endif
{
  return MASLOG_FORMKPOS(phi, pref, mldbbmkneg);
}

MASSTOR_LIST MLDEMO_MLDMKDNF
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  return MASLOG_FORMKDNF(phi, mldbbmkneg);
}

MASSTOR_LIST MLDEMO_MLDMKCNF
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  return MASLOG_FORMKCNF(phi, mldbbmkneg);
}

MASSTOR_LIST MLDEMO_MLDMKPRENEX
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST pref)
# else
(phi, pref)
MASSTOR_LIST phi, pref;
# endif
{
  return MASLOG_FORMKPRENEX(phi, pref);
}

MASSTOR_LIST MLDEMO_MLDSUBSTVAR
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST old, MASSTOR_LIST new)
# else
(phi, old, new)
MASSTOR_LIST phi, old, new;
# endif
{
  return MASLOG_FORSUBSTVAR(phi, old, new, mldbbsubstvar);
}

MASSTOR_LIST MLDEMO_MLDMKVD
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  return MASLOG_FORMKVD(phi, mldbbsubstvar, mldbblsvars);
}

MASSTOR_LIST MLDEMO_MLDSMPL
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  return MASLOG_FORSMPL(phi, mldbbsmpl, mldbbmkneg);
}

MASSTOR_LIST MLDEMO_MLDPREPQE
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  return MASLOG_FORPREPQE(phi, mldbbmkneg);
}

MASSTOR_LIST MLDEMO_MLDAPPLYAT
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  return MASLOG_FORAPPLYAT(phi, apply);
}

void MLDEMO_MLDPPRT
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  MLOGIO_FORPPRT(phi, mldbbpprt);
  return;
}

void MLDEMO_MLDTEXW
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  MLOGIO_FORTEXW(phi, mldbbtexw);
  return;
}

MASSTOR_LIST MLDEMO_MLDCONTVAR
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST var)
# else
(phi, var)
MASSTOR_LIST phi, var;
# endif
{
  if (MASLOG_FORCONTVAR(phi, var, mldbbcontvar)) {
    return 1;
  } else {
    return 0;
  }
}

MASSTOR_LIST MLDEMO_MLDCONTBDVAR
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST var)
# else
(phi, var)
MASSTOR_LIST phi, var;
# endif
{
  if (MASLOG_FORCONTBDVAR(phi, var)) {
    return (MASSTOR_LIST)1;
  } else {
    return (MASSTOR_LIST)0;
  }
}

MASSTOR_LIST MLDEMO_MLDPREAD
# ifdef __STDC__
()
# else
()
# endif
{
  return MLOGIO_FORPREAD(mldbbread);
}

MASSTOR_LIST MLDEMO_MLDIREAD
# ifdef __STDC__
()
# else
()
# endif
{
  return MLOGIO_FORIREAD(mldbbread);
}

void BEGIN_MLDEMO()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASLISPU();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_MASERR();
    BEGIN_MASLISPU();
    BEGIN_MASBIOS();
    BEGIN_MASSYM();
    BEGIN_MASSYM2();
    BEGIN_SACLIST();
    BEGIN_MLOGBASE();
    BEGIN_MASLOG();
    BEGIN_MLOGIO();

    MASLISPU_Declare(&MLDEMO_EQU, "EQU", 3L);
    MASLISPU_Declare(&MLDEMO_NEQ, "NEQ", 3L);
    InitBbfParser();
  }
}
