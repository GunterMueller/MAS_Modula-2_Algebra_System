#include "SYSTEM_.h"

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASLISPU
#include "MASLISPU.h"
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

CHAR MLOGBASE_rcsid [] = "$Id: MLOGBASE.md,v 1.2 1994/11/28 21:04:12 dolzmann Exp $";
CHAR MLOGBASE_copyright [] = "Copyright (c) 1993 Universitaet Passau";
MASSTOR_LIST MLOGBASE_ET, MLOGBASE_VEL, MLOGBASE_NON, MLOGBASE_VERUM, MLOGBASE_FALSUM, MLOGBASE_EXIST, MLOGBASE_FORALL, MLOGBASE_TVAR, MLOGBASE_REP, MLOGBASE_IMP, MLOGBASE_EQUIV, MLOGBASE_ANTIV, MLOGBASE_XOR, MLOGBASE_LVAR;
MASSTOR_LIST MLOGBASE_ANY, MLOGBASE_BOOL;

static CHAR rcsidi [] = "$Id: MLOGBASE.mi,v 1.3 1994/11/28 21:04:13 dolzmann Exp $";
static CHAR copyrighti [] = "Copyright (c) 1993 Universitaet Passau";
static MASSTOR_LIST VARTAB;


MASSTOR_LIST MLOGBASE_FORGOP
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  if (phi == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  if (MASSYM2_SYMBOL(phi)) {
    return phi;
  }
  return MASSTOR_FIRST(phi);
}

MASSTOR_LIST MLOGBASE_FORGARGS
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  return MASSTOR_RED(phi);
}

MASSTOR_LIST MLOGBASE_FORGLVAR
# ifdef __STDC__
(MASSTOR_LIST lvar)
# else
(lvar)
MASSTOR_LIST lvar;
# endif
{
  return MASSTOR_RED(lvar);
}

void MLOGBASE_FORPFOR
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST *op, MASSTOR_LIST *args)
# else
(phi, op, args)
MASSTOR_LIST phi;
MASSTOR_LIST *op;
MASSTOR_LIST *args;
# endif
{
  if (MASSYM2_SYMBOL(phi)) {
    *op = phi;
    *args = MASSTOR_SIL;
  } else {
    MASSTOR_ADV(phi, op, args);
  }
}

void MLOGBASE_FORPARGS
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST *first, MASSTOR_LIST *red)
# else
(phi, first, red)
MASSTOR_LIST phi;
MASSTOR_LIST *first, *red;
# endif
{
  MASSTOR_ADV(phi, first, red);
}

void MLOGBASE_FORPUNOP
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST *op, MASSTOR_LIST *arg)
# else
(phi, op, arg)
MASSTOR_LIST phi;
MASSTOR_LIST *op, *arg;
# endif
{
  MASSTOR_LIST C_26_dummy;

  SACLIST_ADV2(phi, op, arg, &C_26_dummy);
}

void MLOGBASE_FORPBINOP
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST *op, MASSTOR_LIST *first, MASSTOR_LIST *second)
# else
(phi, op, first, second)
MASSTOR_LIST phi;
MASSTOR_LIST *op, *first, *second;
# endif
{
  MASSTOR_LIST C_25_dummy;

  SACLIST_ADV3(phi, op, first, second, &C_25_dummy);
}

void MLOGBASE_FORPUNOPA
# ifdef __STDC__
(MASSTOR_LIST arglist, MASSTOR_LIST *arg)
# else
(arglist, arg)
MASSTOR_LIST arglist;
MASSTOR_LIST *arg;
# endif
{
  MASSTOR_LIST C_24_dummy;

  MASSTOR_ADV(arglist, arg, &C_24_dummy);
}

void MLOGBASE_FORPBINOPA
# ifdef __STDC__
(MASSTOR_LIST red, MASSTOR_LIST *first, MASSTOR_LIST *second)
# else
(red, first, second)
MASSTOR_LIST red;
MASSTOR_LIST *first, *second;
# endif
{
  MASSTOR_LIST C_23_dummy;

  SACLIST_ADV2(red, first, second, &C_23_dummy);
}

void MLOGBASE_FORPQUANT
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST *quant, MASSTOR_LIST *vars, MASSTOR_LIST *formula)
# else
(phi, quant, vars, formula)
MASSTOR_LIST phi;
MASSTOR_LIST *quant, *vars, *formula;
# endif
{
  MASSTOR_LIST C_22_dummy;

  SACLIST_ADV3(phi, quant, vars, formula, &C_22_dummy);
}

void MLOGBASE_FORPQUANTA
# ifdef __STDC__
(MASSTOR_LIST red, MASSTOR_LIST *lvar, MASSTOR_LIST *formula)
# else
(red, lvar, formula)
MASSTOR_LIST red;
MASSTOR_LIST *lvar, *formula;
# endif
{
  MASSTOR_LIST C_21_dummy;

  SACLIST_ADV2(red, lvar, formula, &C_21_dummy);
}

void MLOGBASE_FORPLVAR
# ifdef __STDC__
(MASSTOR_LIST lvar, MASSTOR_LIST *varlist)
# else
(lvar, varlist)
MASSTOR_LIST lvar;
MASSTOR_LIST *varlist;
# endif
{
  MASSTOR_LIST C_20_dummy;

  MASSTOR_ADV(lvar, &C_20_dummy, varlist);
}

void MLOGBASE_FORPVAR
# ifdef __STDC__
(MASSTOR_LIST var, MASSTOR_LIST *name, MASSTOR_LIST *sort)
# else
(var, name, sort)
MASSTOR_LIST var;
MASSTOR_LIST *name, *sort;
# endif
{
  MASSTOR_LIST dummy1, dummy2;

  SACLIST_ADV3(var, &dummy1, name, sort, &dummy2);
}

void MLOGBASE_FORPVARA
# ifdef __STDC__
(MASSTOR_LIST red, MASSTOR_LIST *name, MASSTOR_LIST *sort)
# else
(red, name, sort)
MASSTOR_LIST red;
MASSTOR_LIST *name, *sort;
# endif
{
  MASSTOR_LIST C_19_dummy;

  SACLIST_ADV2(red, name, sort, &C_19_dummy);
}

MASSTOR_LIST MLOGBASE_FORMKFOR
# ifdef __STDC__
(MASSTOR_LIST op, MASSTOR_LIST args)
# else
(op, args)
MASSTOR_LIST op, args;
# endif
{
  if (op == MLOGBASE_VERUM || op == MLOGBASE_FALSUM) {
    return op;
  } else {
    return MASSTOR_COMP(op, args);
  }
}

MASSTOR_LIST MLOGBASE_FORMKCNST
# ifdef __STDC__
(MASSTOR_LIST cnst)
# else
(cnst)
MASSTOR_LIST cnst;
# endif
{
  return cnst;
}

MASSTOR_LIST MLOGBASE_FORMKUNOP
# ifdef __STDC__
(MASSTOR_LIST op, MASSTOR_LIST arg)
# else
(op, arg)
MASSTOR_LIST op, arg;
# endif
{
  return SACLIST_LIST2(op, arg);
}

MASSTOR_LIST MLOGBASE_FORMKBINOP
# ifdef __STDC__
(MASSTOR_LIST op, MASSTOR_LIST arg1, MASSTOR_LIST arg2)
# else
(op, arg1, arg2)
MASSTOR_LIST op, arg1, arg2;
# endif
{
  return SACLIST_LIST3(op, arg1, arg2);
}

MASSTOR_LIST MLOGBASE_FORMKVAR
# ifdef __STDC__
(MASSTOR_LIST name, MASSTOR_LIST sort)
# else
(name, sort)
MASSTOR_LIST name, sort;
# endif
{
  return SACLIST_LIST3(MLOGBASE_TVAR, name, sort);
}

MASSTOR_LIST MLOGBASE_FORMKLVAR
# ifdef __STDC__
(MASSTOR_LIST vars)
# else
(vars)
MASSTOR_LIST vars;
# endif
{
  return MASSTOR_COMP(MLOGBASE_LVAR, vars);
}

MASSTOR_LIST MLOGBASE_FORMKQUANT
# ifdef __STDC__
(MASSTOR_LIST quant, MASSTOR_LIST vars, MASSTOR_LIST formula)
# else
(quant, vars, formula)
MASSTOR_LIST quant, vars, formula;
# endif
{
  return SACLIST_LIST3(quant, vars, formula);
}

BOOLEAN MLOGBASE_FORTST
# ifdef __STDC__
(MASSTOR_LIST L, MLOGBASE_PROCFB1 bbtst)
# else
(L, bbtst)
MASSTOR_LIST L;
MLOGBASE_PROCFB1 bbtst;
# endif
{
  MASSTOR_LIST op, red, arg, arg1, arg2, lvar, qform, C_18_dummy;
  BOOLEAN isformula;

  if (L == MASSTOR_SIL) {
    return FALSE;
  }
  if (MASSYM2_SYMBOL(L)) {
    return L == MLOGBASE_VERUM || L == MLOGBASE_FALSUM;
  }
  if (MASSYM_ATOM(L)) {
    return FALSE;
  }
  MASSTOR_ADV(L, &op, &red);
  if (!MASSYM2_SYMBOL(op)) {
    return FALSE;
  }
  if (op == MLOGBASE_ET || op == MLOGBASE_VEL) {
    if (red == MASSTOR_SIL) {
      return FALSE;
    }
    isformula = TRUE;
    while (red != MASSTOR_SIL && isformula) {
      MASSTOR_ADV(red, &arg, &red);
      isformula = MLOGBASE_FORTST(arg, bbtst);
    }
    return isformula;
  } else if (op == MLOGBASE_NON) {
    if (red == MASSTOR_SIL || MASSTOR_RED(red) != MASSTOR_SIL) {
      return FALSE;
    } else {
      MASSTOR_ADV(red, &arg, &C_18_dummy);
      return MLOGBASE_FORTST(arg, bbtst);
    }
  } else if (op == MLOGBASE_EXIST || op == MLOGBASE_FORALL) {
    if (red == MASSTOR_SIL || MASSTOR_RED(red) == MASSTOR_SIL) {
      return FALSE;
    }
    SACLIST_ADV2(red, &lvar, &qform, &C_18_dummy);
    return C_18_dummy == MASSTOR_SIL && MLOGBASE_FORISLVAR(lvar) && MLOGBASE_FORTST(qform, bbtst);
  } else if (op == MLOGBASE_IMP || op == MLOGBASE_REP || op == MLOGBASE_EQUIV || op == MLOGBASE_XOR) {
    if (red == MASSTOR_SIL) {
      return FALSE;
    }
    MASSTOR_ADV(red, &arg1, &red);
    if (red == MASSTOR_SIL) {
      return FALSE;
    }
    MASSTOR_ADV(red, &arg2, &red);
    if (red != MASSTOR_SIL) {
      return FALSE;
    }
    return MLOGBASE_FORTST(arg1, bbtst) && MLOGBASE_FORTST(arg2, bbtst);
  } else if (op == MLOGBASE_TVAR) {
    return MLOGBASE_FORISBOOLVAR(L);
  } else {
    return (*bbtst)(L);
  }
}

BOOLEAN MLOGBASE_FORISVAR
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST key, name, sort, red;

  if (L == MASSTOR_SIL) {
    return FALSE;
  }
  if (MASSYM_ATOM(L) || MASSYM2_SYMBOL(L)) {
    return FALSE;
  }
  MASSTOR_ADV(L, &key, &red);
  if (!MASSYM2_SYMBOL(key) || key != MLOGBASE_TVAR) {
    return FALSE;
  }
  if (red == MASSTOR_SIL) {
    return FALSE;
  }
  MASSTOR_ADV(red, &name, &red);
  if (red == MASSTOR_SIL) {
    return FALSE;
  }
  MASSTOR_ADV(red, &sort, &red);
  if (red != MASSTOR_SIL) {
    return FALSE;
  }
  return TRUE;
}

BOOLEAN MLOGBASE_FORISBOOLVAR
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST key, name, sort, red;

  if (L == MASSTOR_SIL) {
    return FALSE;
  }
  if (MASSYM_ATOM(L) || MASSYM2_SYMBOL(L)) {
    return FALSE;
  }
  MASSTOR_ADV(L, &key, &red);
  if (!MASSYM2_SYMBOL(key) || key != MLOGBASE_TVAR) {
    return FALSE;
  }
  if (red == MASSTOR_SIL) {
    return FALSE;
  }
  MASSTOR_ADV(red, &name, &red);
  if (red == MASSTOR_SIL || !MASSYM2_SYMBOL(name)) {
    return FALSE;
  }
  MASSTOR_ADV(red, &sort, &red);
  if (red != MASSTOR_SIL || !MASSYM2_SYMBOL(sort)) {
    return FALSE;
  }
  return sort == MLOGBASE_BOOL;
}

BOOLEAN MLOGBASE_FORISLVAR
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST elem, key, red;
  BOOLEAN is;

  if (L == MASSTOR_SIL) {
    return FALSE;
  }
  if (MASSYM2_SYMBOL(L) || MASSYM_ATOM(L)) {
    return FALSE;
  }
  MASSTOR_ADV(L, &key, &red);
  if (red == MASSTOR_SIL || key != MLOGBASE_LVAR) {
    return FALSE;
  }
  do {
    MASSTOR_ADV(red, &elem, &red);
    is = MLOGBASE_FORISVAR(elem);
  } while (!(red == MASSTOR_SIL || !is));
  return is;
}

BOOLEAN MLOGBASE_FORISATOM
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  MASSTOR_LIST op, res;

  MLOGBASE_FORPFOR(phi, &op, &res);
  return op == MLOGBASE_TVAR || op == MLOGBASE_VERUM || op == MLOGBASE_FALSUM || op != MLOGBASE_EXIST && op != MLOGBASE_FORALL && op != MLOGBASE_VEL && op != MLOGBASE_ET && op != MLOGBASE_IMP && op != MLOGBASE_REP && op != MLOGBASE_EQUIV && op != MLOGBASE_XOR && op != MLOGBASE_NON;
}

BOOLEAN MLOGBASE_FORISBBFOR
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  MASSTOR_LIST op;

  op = MLOGBASE_FORGOP(phi);
  return op != MLOGBASE_EXIST && op != MLOGBASE_FORALL && op != MLOGBASE_VEL && op != MLOGBASE_ET && op != MLOGBASE_IMP && op != MLOGBASE_REP && op != MLOGBASE_EQUIV && op != MLOGBASE_XOR && op != MLOGBASE_NON && op != MLOGBASE_TVAR && op != MLOGBASE_VERUM && op != MLOGBASE_FALSUM;
}

MASSTOR_LIST MLOGBASE_FORVTSTORE
# ifdef __STDC__
()
# else
()
# endif
{
  return VARTAB;
}

MASSTOR_LIST MLOGBASE_FORVTRESTORE
# ifdef __STDC__
(MASSTOR_LIST vt)
# else
(vt)
MASSTOR_LIST vt;
# endif
{
  VARTAB = vt;
  return VARTAB;
}

MASSTOR_LIST MLOGBASE_FORVTENTER
# ifdef __STDC__
(MASSTOR_LIST sym)
# else
(sym)
MASSTOR_LIST sym;
# endif
{
  MASSTOR_LIST id, lastid;

  id = MASSYM2_ASSOCQ(sym, VARTAB);
  if (id == MASSTOR_SIL) {
    if (VARTAB == MASSTOR_SIL) {
      lastid = 0;
    } else {
      lastid = SACLIST_SECOND(VARTAB);
    }
    id = lastid + 1;
    VARTAB = SACLIST_COMP2(sym, id, VARTAB);
  } else {
    id = MASSTOR_FIRST(id);
  }
  return id;
}

MASSTOR_LIST MLOGBASE_FORVTGET
# ifdef __STDC__
(MASSTOR_LIST id)
# else
(id)
MASSTOR_LIST id;
# endif
{
  MASSTOR_LIST l, i, s, name;

  if (id <= 0) {
    return MASSTOR_SIL;
  }
  l = VARTAB;
  i = 0;
  while (l != MASSTOR_SIL && i != id) {
    SACLIST_ADV2(l, &s, &i, &l);
  }
  if (id == i) {
    name = s;
  } else {
    name = MASSTOR_SIL;
  }
  return name;
}

void BEGIN_MLOGBASE()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASBIOS();
    BEGIN_MASSTOR();
    BEGIN_MASLISPU();
    BEGIN_MASSYM();
    BEGIN_MASSYM2();
    BEGIN_SACLIST();

    MASSTOR_LISTVAR(&VARTAB);
    VARTAB = MASSTOR_SIL;
    MLOGBASE_BOOL = MLOGBASE_FORVTENTER(MASBIOS_LISTS("BOOL", 4L));
    MLOGBASE_ANY = MLOGBASE_FORVTENTER(MASBIOS_LISTS("ANY", 3L));
    MASLISPU_Declare(&MLOGBASE_ET, "FORAND", 6L);
    MASLISPU_Declare(&MLOGBASE_VEL, "FOROR", 5L);
    MASLISPU_Declare(&MLOGBASE_NON, "FORNOT", 6L);
    MASLISPU_Declare(&MLOGBASE_VERUM, "TRUE", 4L);
    MASLISPU_Declare(&MLOGBASE_FALSUM, "FALSE", 5L);
    MASLISPU_Declare(&MLOGBASE_FORALL, "FORALL", 6L);
    MASLISPU_Declare(&MLOGBASE_EXIST, "FOREX", 5L);
    MASLISPU_Declare(&MLOGBASE_TVAR, "FORVAR", 6L);
    MASLISPU_Declare(&MLOGBASE_LVAR, "LVAR", 4L);
    MASLISPU_Declare(&MLOGBASE_REP, "FORREPL", 7L);
    MASLISPU_Declare(&MLOGBASE_IMP, "FORIMPL", 7L);
    MASLISPU_Declare(&MLOGBASE_EQUIV, "FOREQUIV", 8L);
    MASLISPU_Declare(&MLOGBASE_XOR, "FORXOR", 6L);
  }
}
