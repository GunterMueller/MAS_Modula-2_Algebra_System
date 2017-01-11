#include "SYSTEM_.h"

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#ifndef DEFINITION_MASERR
#include "MASERR.h"
#endif

#ifndef DEFINITION_MASLISPU
#include "MASLISPU.h"
#endif

#ifndef DEFINITION_MASSET
#include "MASSET.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASSYM2
#include "MASSYM2.h"
#endif

#ifndef DEFINITION_MLOGBASE
#include "MLOGBASE.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_MASLOG
#include "MASLOG.h"
#endif

CHAR MASLOG_rcsid [] = "$Id: MASLOG.md,v 1.4 1994/11/28 21:03:59 dolzmann Exp $";
CHAR MASLOG_copyright [] = "Copyright (c) 1993 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASLOG.mi,v 1.4 1994/11/28 21:04:08 dolzmann Exp $";
static CHAR copyrighti [] = "Copyright (c) 1993 Universitaet Passau";
static MASSTOR_LIST complement ARGS((MASSTOR_LIST phi, MASSTOR_LIST pref, MASLISPU_PROCF1 bbmkneg));
static MASSTOR_LIST FORMKDNF1 ARGS((MASSTOR_LIST phi, MASLISPU_PROCF1 bbmkneg, BOOLEAN neg));
static MASSTOR_LIST distribetovel ARGS((MASSTOR_LIST L));
static MASSTOR_LIST FORMKCNF1 ARGS((MASSTOR_LIST phi, MASLISPU_PROCF1 bbmkneg, BOOLEAN neg));
static MASSTOR_LIST distribveloet ARGS((MASSTOR_LIST L));
static MASSTOR_LIST pnfquantifier ARGS((MASSTOR_LIST phi));
static MASSTOR_LIST mkquant ARGS((MASSTOR_LIST qf, MASSTOR_LIST vars, MASSTOR_LIST phi, MASSTOR_LIST qbqform));
static MASSTOR_LIST pnfjunctor ARGS((MASSTOR_LIST phi));
static MASSTOR_LIST interchange ARGS((MASSTOR_LIST L, MASSTOR_LIST op, MASSTOR_LIST pref));
static void getqfb ARGS((MASSTOR_LIST phi, MASSTOR_LIST qf, MASSTOR_LIST *qfb, MASSTOR_LIST *qform));
static void collectnames ARGS((MASSTOR_LIST phi, MASSTOR_LIST env, MASLISPU_PROCF1 bblsvars, MASSTOR_LIST *free, MASSTOR_LIST *bound));
static MASSTOR_LIST repvar ARGS((MASSTOR_LIST phi, MASSTOR_LIST old, MASSTOR_LIST new, MASSTOR_LIST *used, MASSTOR_LIST *denied, MASLISPU_PROCF3 bbsubstvar));
static MASSTOR_LIST GENVAR ARGS((MASSTOR_LIST var, MASSTOR_LIST xdenied));
static MASSTOR_LIST smplimpl ARGS((MASSTOR_LIST phi, MASLISPU_PROCF1 bbsmpl, MASLISPU_PROCF1 bbmkneg));
static MASSTOR_LIST SimplifyComp ARGS((MASSTOR_LIST phi, MASSTOR_LIST op, MASSTOR_LIST L));
static MASSTOR_LIST DoSmartSimplify ARGS((MASSTOR_LIST L, MASSTOR_LIST op, MASLISPU_PROCF1 smart));
static MASSTOR_LIST simplifyp ARGS((MASSTOR_LIST phi, MASSTOR_LIST level, MASSTOR_LIST maxlevel, MASLISPU_PROCF1 smart, MASLISPU_PROCF1 bbsmpl, MASLISPU_PROCF1 bbmkneg));
static MASSTOR_LIST notsymbol ARGS((MASSTOR_LIST sym));
static MASSTOR_LIST formkneg ARGS((MASSTOR_LIST phi, MASLISPU_PROCF1 bbmkneg));


MASSTOR_LIST MASLOG_FORMKPOS
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST pref, MASLISPU_PROCF1 bbmkneg)
# else
(phi, pref, bbmkneg)
MASSTOR_LIST phi, pref;
MASLISPU_PROCF1 bbmkneg;
# endif
{
  MASSTOR_LIST op, args, vars, formula, posformula, result, key;
  MASSTOR_LIST arg1, arg2, posarg1, posarg2, nposarg1, nposarg2;

  if (phi == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  if (pref != MLOGBASE_VEL && pref != MLOGBASE_ET && pref != MLOGBASE_NON) {
    MASERR_ERROR(MASERR_severe, "FORMKPOS: wrong preference given (assume NON)", 45L);
    pref = MLOGBASE_NON;
  }
  MLOGBASE_FORPFOR(phi, &op, &args);
  if (op == MLOGBASE_VERUM || op == MLOGBASE_FALSUM) {
    return phi;
  } else if (op == MLOGBASE_NON) {
    MLOGBASE_FORPUNOPA(args, &formula);
    return complement(formula, pref, bbmkneg);
  } else if (op == MLOGBASE_VEL || op == MLOGBASE_ET) {
    result = MASSTOR_SIL;
    while (args != MASSTOR_SIL) {
      MLOGBASE_FORPARGS(args, &formula, &args);
      posformula = MASLOG_FORMKPOS(formula, pref, bbmkneg);
      result = MASSTOR_COMP(posformula, result);
    }
    return MLOGBASE_FORMKFOR(op, MASSTOR_INV(result));
  } else if (op == MLOGBASE_EXIST || op == MLOGBASE_FORALL) {
    MLOGBASE_FORPQUANTA(args, &vars, &formula);
    posformula = MASLOG_FORMKPOS(formula, pref, bbmkneg);
    return MLOGBASE_FORMKQUANT(op, vars, posformula);
  } else if (op == MLOGBASE_IMP && pref != MLOGBASE_NON) {
    MLOGBASE_FORPBINOPA(args, &arg1, &arg2);
    return MLOGBASE_FORMKBINOP(MLOGBASE_VEL, complement(arg1, pref, bbmkneg), MASLOG_FORMKPOS(arg2, pref, bbmkneg));
  } else if (op == MLOGBASE_IMP && pref == MLOGBASE_NON) {
    MLOGBASE_FORPBINOPA(args, &arg1, &arg2);
    return MLOGBASE_FORMKBINOP(MLOGBASE_IMP, MASLOG_FORMKPOS(arg1, pref, bbmkneg), MASLOG_FORMKPOS(arg2, pref, bbmkneg));
  } else if (op == MLOGBASE_REP && pref != MLOGBASE_NON) {
    MLOGBASE_FORPBINOPA(args, &arg1, &arg2);
    return MLOGBASE_FORMKBINOP(MLOGBASE_VEL, MASLOG_FORMKPOS(arg1, pref, bbmkneg), complement(arg2, pref, bbmkneg));
  } else if (op == MLOGBASE_REP && pref == MLOGBASE_NON) {
    MLOGBASE_FORPBINOPA(args, &arg1, &arg2);
    return MLOGBASE_FORMKBINOP(MLOGBASE_REP, MASLOG_FORMKPOS(arg1, pref, bbmkneg), MASLOG_FORMKPOS(arg2, pref, bbmkneg));
  } else if (op == MLOGBASE_EQUIV && pref != MLOGBASE_NON) {
    MLOGBASE_FORPBINOPA(args, &arg1, &arg2);
    posarg1 = MASLOG_FORMKPOS(arg1, pref, bbmkneg);
    posarg2 = MASLOG_FORMKPOS(arg2, pref, bbmkneg);
    nposarg1 = complement(arg1, pref, bbmkneg);
    nposarg2 = complement(arg2, pref, bbmkneg);
    if (pref == MLOGBASE_ET) {
      return MLOGBASE_FORMKBINOP(MLOGBASE_ET, MLOGBASE_FORMKBINOP(MLOGBASE_VEL, nposarg1, posarg2), MLOGBASE_FORMKBINOP(MLOGBASE_VEL, posarg1, nposarg2));
    } else if (pref == MLOGBASE_VEL) {
      return MLOGBASE_FORMKBINOP(MLOGBASE_VEL, MLOGBASE_FORMKBINOP(MLOGBASE_ET, posarg1, posarg2), MLOGBASE_FORMKBINOP(MLOGBASE_ET, nposarg1, nposarg2));
    }
  } else if (op == MLOGBASE_EQUIV && pref == MLOGBASE_NON) {
    MLOGBASE_FORPBINOPA(args, &arg1, &arg2);
    return MLOGBASE_FORMKBINOP(MLOGBASE_EQUIV, MASLOG_FORMKPOS(arg1, pref, bbmkneg), MASLOG_FORMKPOS(arg2, pref, bbmkneg));
  } else if (op == MLOGBASE_XOR && pref != MLOGBASE_NON) {
    MLOGBASE_FORPBINOPA(args, &arg1, &arg2);
    posarg1 = MASLOG_FORMKPOS(arg1, pref, bbmkneg);
    posarg2 = MASLOG_FORMKPOS(arg2, pref, bbmkneg);
    nposarg1 = complement(arg1, pref, bbmkneg);
    nposarg2 = complement(arg2, pref, bbmkneg);
    if (pref == MLOGBASE_VEL) {
      return MLOGBASE_FORMKBINOP(MLOGBASE_VEL, MLOGBASE_FORMKBINOP(MLOGBASE_ET, posarg1, nposarg2), MLOGBASE_FORMKBINOP(MLOGBASE_ET, nposarg1, posarg2));
    } else if (pref == MLOGBASE_ET) {
      return MLOGBASE_FORMKBINOP(MLOGBASE_ET, MLOGBASE_FORMKBINOP(MLOGBASE_VEL, posarg1, posarg2), MLOGBASE_FORMKBINOP(MLOGBASE_VEL, nposarg1, nposarg2));
    }
  } else if (op == MLOGBASE_XOR && pref == MLOGBASE_NON) {
    MLOGBASE_FORPBINOPA(args, &arg1, &arg2);
    return MLOGBASE_FORMKBINOP(MLOGBASE_XOR, MASLOG_FORMKPOS(arg1, pref, bbmkneg), MASLOG_FORMKPOS(arg2, pref, bbmkneg));
  } else if (op == MLOGBASE_TVAR) {
    return phi;
  } else {
    return phi;
  }
}

static MASSTOR_LIST complement
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST pref, MASLISPU_PROCF1 bbmkneg)
# else
(phi, pref, bbmkneg)
MASSTOR_LIST phi, pref;
MASLISPU_PROCF1 bbmkneg;
# endif
{
  MASSTOR_LIST op, args, vars, formula, posformula, result;
  MASSTOR_LIST arg1, arg2, posarg1, posarg2, nposarg1, nposarg2;

  if (phi == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  MLOGBASE_FORPFOR(phi, &op, &args);
  if (op == MLOGBASE_VERUM) {
    return MLOGBASE_FORMKCNST(MLOGBASE_FALSUM);
  } else if (op == MLOGBASE_FALSUM) {
    return MLOGBASE_FORMKCNST(MLOGBASE_VERUM);
  } else if (op == MLOGBASE_NON) {
    MLOGBASE_FORPARGS(args, &formula, &args);
    return MASLOG_FORMKPOS(formula, pref, bbmkneg);
  } else if (op == MLOGBASE_VEL || op == MLOGBASE_ET) {
    result = MASSTOR_SIL;
    while (args != MASSTOR_SIL) {
      MLOGBASE_FORPARGS(args, &formula, &args);
      posformula = complement(formula, pref, bbmkneg);
      result = MASSTOR_COMP(posformula, result);
    }
    return MLOGBASE_FORMKFOR(notsymbol(op), MASSTOR_INV(result));
  } else if (op == MLOGBASE_EXIST || op == MLOGBASE_FORALL) {
    MLOGBASE_FORPQUANTA(args, &vars, &formula);
    posformula = complement(formula, pref, bbmkneg);
    return MLOGBASE_FORMKQUANT(notsymbol(op), vars, posformula);
  } else if (op == MLOGBASE_REP) {
    MLOGBASE_FORPBINOPA(args, &arg1, &arg2);
    posarg1 = complement(arg1, pref, bbmkneg);
    posarg2 = MASLOG_FORMKPOS(arg2, pref, bbmkneg);
    return MLOGBASE_FORMKBINOP(MLOGBASE_ET, posarg1, posarg2);
  } else if (op == MLOGBASE_IMP) {
    MLOGBASE_FORPBINOPA(args, &arg1, &arg2);
    posarg1 = MASLOG_FORMKPOS(arg1, pref, bbmkneg);
    posarg2 = complement(arg2, pref, bbmkneg);
    return MLOGBASE_FORMKBINOP(MLOGBASE_ET, posarg1, posarg2);
  } else if (op == MLOGBASE_XOR && pref != MLOGBASE_NON) {
    MLOGBASE_FORPBINOPA(args, &arg1, &arg2);
    posarg1 = MASLOG_FORMKPOS(arg1, pref, bbmkneg);
    posarg2 = MASLOG_FORMKPOS(arg2, pref, bbmkneg);
    nposarg1 = complement(arg1, pref, bbmkneg);
    nposarg2 = complement(arg2, pref, bbmkneg);
    if (pref == MLOGBASE_ET) {
      return MLOGBASE_FORMKBINOP(MLOGBASE_ET, MLOGBASE_FORMKBINOP(MLOGBASE_VEL, posarg1, nposarg2), MLOGBASE_FORMKBINOP(MLOGBASE_VEL, nposarg1, posarg2));
    } else if (pref == MLOGBASE_VEL) {
      return MLOGBASE_FORMKBINOP(MLOGBASE_VEL, MLOGBASE_FORMKBINOP(MLOGBASE_ET, posarg1, posarg2), MLOGBASE_FORMKBINOP(MLOGBASE_ET, nposarg1, nposarg2));
    }
  } else if (op == MLOGBASE_XOR && pref == MLOGBASE_NON) {
    MLOGBASE_FORPBINOPA(args, &arg1, &arg2);
    return MLOGBASE_FORMKBINOP(MLOGBASE_EQUIV, MASLOG_FORMKPOS(arg1, pref, bbmkneg), MASLOG_FORMKPOS(arg2, pref, bbmkneg));
  } else if (op == MLOGBASE_EQUIV && pref != MLOGBASE_NON) {
    MLOGBASE_FORPBINOPA(args, &arg1, &arg2);
    posarg1 = MASLOG_FORMKPOS(arg1, pref, bbmkneg);
    posarg2 = MASLOG_FORMKPOS(arg2, pref, bbmkneg);
    nposarg1 = complement(arg1, pref, bbmkneg);
    nposarg2 = complement(arg2, pref, bbmkneg);
    if (pref == MLOGBASE_VEL) {
      return MLOGBASE_FORMKBINOP(MLOGBASE_VEL, MLOGBASE_FORMKBINOP(MLOGBASE_ET, posarg1, nposarg2), MLOGBASE_FORMKBINOP(MLOGBASE_ET, nposarg1, posarg2));
    } else if (pref == MLOGBASE_ET) {
      return MLOGBASE_FORMKBINOP(MLOGBASE_ET, MLOGBASE_FORMKBINOP(MLOGBASE_VEL, posarg1, posarg2), MLOGBASE_FORMKBINOP(MLOGBASE_VEL, nposarg1, nposarg2));
    }
  } else if (op == MLOGBASE_EQUIV && pref == MLOGBASE_NON) {
    MLOGBASE_FORPBINOPA(args, &arg1, &arg2);
    return MLOGBASE_FORMKBINOP(MLOGBASE_XOR, MASLOG_FORMKPOS(arg1, pref, bbmkneg), MASLOG_FORMKPOS(arg2, pref, bbmkneg));
  } else if (op == MLOGBASE_TVAR) {
    return MLOGBASE_FORMKUNOP(MLOGBASE_NON, phi);
  } else {
    return (*bbmkneg)(phi);
  }
}

MASSTOR_LIST MASLOG_FORMKDNF
# ifdef __STDC__
(MASSTOR_LIST phi, MASLISPU_PROCF1 bbmkneg)
# else
(phi, bbmkneg)
MASSTOR_LIST phi;
MASLISPU_PROCF1 bbmkneg;
# endif
{
  return FORMKDNF1(phi, bbmkneg, FALSE);
}

static MASSTOR_LIST FORMKDNF1
# ifdef __STDC__
(MASSTOR_LIST phi, MASLISPU_PROCF1 bbmkneg, BOOLEAN neg)
# else
(phi, bbmkneg, neg)
MASSTOR_LIST phi;
MASLISPU_PROCF1 bbmkneg;
BOOLEAN neg;
# endif
{
  MASSTOR_LIST op, red, arg, arg1, arg2, dnfarg, result, opvel, psi, prednf;

  if (phi == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  MLOGBASE_FORPFOR(phi, &op, &red);
  if (op == MLOGBASE_VERUM || op == MLOGBASE_FALSUM) {
    if (neg) {
      return MLOGBASE_FORMKUNOP(MLOGBASE_VEL, MLOGBASE_FORMKUNOP(MLOGBASE_ET, notsymbol(phi)));
    } else {
      return MLOGBASE_FORMKUNOP(MLOGBASE_VEL, MLOGBASE_FORMKUNOP(MLOGBASE_ET, phi));
    }
  } else if (op == MLOGBASE_NON) {
    MLOGBASE_FORPUNOPA(red, &arg);
    return FORMKDNF1(arg, bbmkneg, !neg);
  } else if (op == MLOGBASE_VEL && !neg || op == MLOGBASE_ET && neg) {
    result = MASSTOR_SIL;
    while (red != MASSTOR_SIL) {
      MLOGBASE_FORPARGS(red, &arg, &red);
      dnfarg = FORMKDNF1(arg, bbmkneg, neg);
      MLOGBASE_FORPARGS(dnfarg, &opvel, &psi);
      result = SACLIST_CCONC(result, psi);
    }
    return MLOGBASE_FORMKFOR(MLOGBASE_VEL, result);
  } else if (op == MLOGBASE_ET && !neg || op == MLOGBASE_VEL && neg) {
    prednf = MASSTOR_SIL;
    while (red != MASSTOR_SIL) {
      MLOGBASE_FORPARGS(red, &arg, &red);
      prednf = MASSTOR_COMP(FORMKDNF1(arg, bbmkneg, neg), prednf);
    }
    return distribetovel(MASSTOR_INV(prednf));
  } else if (op == MLOGBASE_IMP) {
    MLOGBASE_FORPBINOPA(red, &arg1, &arg2);
    return FORMKDNF1(MLOGBASE_FORMKBINOP(MLOGBASE_VEL, MLOGBASE_FORMKUNOP(MLOGBASE_NON, arg1), arg2), bbmkneg, neg);
  } else if (op == MLOGBASE_REP) {
    MLOGBASE_FORPBINOPA(red, &arg1, &arg2);
    return FORMKDNF1(MLOGBASE_FORMKBINOP(MLOGBASE_VEL, arg1, MLOGBASE_FORMKUNOP(MLOGBASE_NON, arg2)), bbmkneg, neg);
  } else if (op == MLOGBASE_EQUIV && !neg || op == MLOGBASE_XOR && neg) {
    MLOGBASE_FORPBINOPA(red, &arg1, &arg2);
    return FORMKDNF1(MLOGBASE_FORMKBINOP(MLOGBASE_VEL, MLOGBASE_FORMKBINOP(MLOGBASE_ET, MLOGBASE_FORMKUNOP(MLOGBASE_NON, arg1), MLOGBASE_FORMKUNOP(MLOGBASE_NON, arg2)), MLOGBASE_FORMKBINOP(MLOGBASE_ET, arg1, arg2)), bbmkneg, FALSE);
  } else if (op == MLOGBASE_XOR && !neg || op == MLOGBASE_EQUIV && neg) {
    MLOGBASE_FORPBINOPA(red, &arg1, &arg2);
    return FORMKDNF1(MLOGBASE_FORMKBINOP(MLOGBASE_VEL, MLOGBASE_FORMKBINOP(MLOGBASE_ET, arg1, MLOGBASE_FORMKUNOP(MLOGBASE_NON, arg2)), MLOGBASE_FORMKBINOP(MLOGBASE_ET, MLOGBASE_FORMKUNOP(MLOGBASE_NON, arg1), arg2)), bbmkneg, FALSE);
  } else if (op == MLOGBASE_TVAR) {
    if (neg) {
      return MLOGBASE_FORMKUNOP(MLOGBASE_VEL, MLOGBASE_FORMKUNOP(MLOGBASE_ET, MLOGBASE_FORMKUNOP(MLOGBASE_NON, phi)));
    } else {
      return MLOGBASE_FORMKUNOP(MLOGBASE_VEL, MLOGBASE_FORMKUNOP(MLOGBASE_ET, phi));
    }
  } else {
    if (neg) {
      return MLOGBASE_FORMKUNOP(MLOGBASE_VEL, MLOGBASE_FORMKUNOP(MLOGBASE_ET, (*bbmkneg)(phi)));
    } else {
      return MLOGBASE_FORMKUNOP(MLOGBASE_VEL, MLOGBASE_FORMKUNOP(MLOGBASE_ET, phi));
    }
  }
}

static MASSTOR_LIST distribetovel
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST first, firstpt, tail, elem, redelem, obj, result, prefix;
  MASSTOR_LIST C_15_dummy;

  if (L == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  MLOGBASE_FORPFOR(L, &first, &tail);
  if (tail == MASSTOR_SIL) {
    return first;
  }
  MLOGBASE_FORPARGS(first, &C_15_dummy, &first);
  while (tail != MASSTOR_SIL) {
    MLOGBASE_FORPARGS(tail, &obj, &tail);
    MLOGBASE_FORPARGS(obj, &C_15_dummy, &obj);
    result = MASSTOR_SIL;
    while (obj != MASSTOR_SIL) {
      MLOGBASE_FORPARGS(obj, &elem, &obj);
      redelem = MASSTOR_RED(elem);
      firstpt = first;
      while (firstpt != MASSTOR_SIL) {
        MLOGBASE_FORPARGS(firstpt, &prefix, &firstpt);
        result = MASSTOR_COMP(SACLIST_CCONC(prefix, redelem), result);
      }
    }
    first = result;
  }
  result = MLOGBASE_FORMKFOR(MLOGBASE_VEL, result);
  return result;
}

MASSTOR_LIST MASLOG_FORMKCNF
# ifdef __STDC__
(MASSTOR_LIST phi, MASLISPU_PROCF1 bbmkneg)
# else
(phi, bbmkneg)
MASSTOR_LIST phi;
MASLISPU_PROCF1 bbmkneg;
# endif
{
  return FORMKCNF1(phi, bbmkneg, FALSE);
}

static MASSTOR_LIST FORMKCNF1
# ifdef __STDC__
(MASSTOR_LIST phi, MASLISPU_PROCF1 bbmkneg, BOOLEAN neg)
# else
(phi, bbmkneg, neg)
MASSTOR_LIST phi;
MASLISPU_PROCF1 bbmkneg;
BOOLEAN neg;
# endif
{
  MASSTOR_LIST op, red, arg, arg1, arg2, cnfarg, result, opet, psi, precnf;

  if (phi == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  MLOGBASE_FORPFOR(phi, &op, &red);
  if (op == MLOGBASE_VERUM || op == MLOGBASE_FALSUM) {
    if (neg) {
      return MLOGBASE_FORMKUNOP(MLOGBASE_ET, MLOGBASE_FORMKUNOP(MLOGBASE_VEL, notsymbol(op)));
    } else {
      return MLOGBASE_FORMKUNOP(MLOGBASE_ET, MLOGBASE_FORMKUNOP(MLOGBASE_VEL, phi));
    }
  } else if (op == MLOGBASE_NON) {
    MLOGBASE_FORPUNOPA(red, &arg);
    return FORMKCNF1(arg, bbmkneg, !neg);
  } else if (op == MLOGBASE_ET && !neg || op == MLOGBASE_VEL && neg) {
    result = MASSTOR_SIL;
    while (red != MASSTOR_SIL) {
      MLOGBASE_FORPARGS(red, &arg, &red);
      cnfarg = FORMKCNF1(arg, bbmkneg, neg);
      MLOGBASE_FORPARGS(cnfarg, &opet, &psi);
      result = SACLIST_CCONC(result, psi);
    }
    return MLOGBASE_FORMKFOR(MLOGBASE_ET, result);
  } else if (op == MLOGBASE_VEL && !neg || op == MLOGBASE_ET && neg) {
    precnf = MASSTOR_SIL;
    while (red != MASSTOR_SIL) {
      MLOGBASE_FORPARGS(red, &arg, &red);
      precnf = MASSTOR_COMP(FORMKCNF1(arg, bbmkneg, neg), precnf);
    }
    return distribveloet(MASSTOR_INV(precnf));
  } else if (op == MLOGBASE_IMP) {
    MLOGBASE_FORPBINOPA(red, &arg1, &arg2);
    return FORMKCNF1(MLOGBASE_FORMKBINOP(MLOGBASE_VEL, MLOGBASE_FORMKUNOP(MLOGBASE_NON, arg1), arg2), bbmkneg, neg);
  } else if (op == MLOGBASE_REP) {
    MLOGBASE_FORPBINOPA(red, &arg1, &arg2);
    return FORMKCNF1(MLOGBASE_FORMKBINOP(MLOGBASE_VEL, arg1, MLOGBASE_FORMKUNOP(MLOGBASE_NON, arg2)), bbmkneg, neg);
  } else if (op == MLOGBASE_XOR && !neg || op == MLOGBASE_EQUIV && neg) {
    MLOGBASE_FORPBINOPA(red, &arg1, &arg2);
    return FORMKCNF1(MLOGBASE_FORMKBINOP(MLOGBASE_ET, MLOGBASE_FORMKBINOP(MLOGBASE_VEL, MLOGBASE_FORMKUNOP(MLOGBASE_NON, arg1), MLOGBASE_FORMKUNOP(MLOGBASE_NON, arg2)), MLOGBASE_FORMKBINOP(MLOGBASE_VEL, arg1, arg2)), bbmkneg, FALSE);
  } else if (op == MLOGBASE_EQUIV && !neg || op == MLOGBASE_XOR && neg) {
    MLOGBASE_FORPBINOPA(red, &arg1, &arg2);
    return FORMKCNF1(MLOGBASE_FORMKBINOP(MLOGBASE_ET, MLOGBASE_FORMKBINOP(MLOGBASE_VEL, arg1, MLOGBASE_FORMKUNOP(MLOGBASE_NON, arg2)), MLOGBASE_FORMKBINOP(MLOGBASE_VEL, MLOGBASE_FORMKUNOP(MLOGBASE_NON, arg1), arg2)), bbmkneg, FALSE);
  } else if (op == MLOGBASE_TVAR) {
    if (neg) {
      return MLOGBASE_FORMKUNOP(MLOGBASE_ET, MLOGBASE_FORMKUNOP(MLOGBASE_VEL, MLOGBASE_FORMKUNOP(MLOGBASE_NON, phi)));
    } else {
      return MLOGBASE_FORMKUNOP(MLOGBASE_ET, MLOGBASE_FORMKUNOP(MLOGBASE_VEL, phi));
    }
  } else {
    if (neg) {
      return MLOGBASE_FORMKUNOP(MLOGBASE_ET, MLOGBASE_FORMKUNOP(MLOGBASE_VEL, (*bbmkneg)(phi)));
    } else {
      return MLOGBASE_FORMKUNOP(MLOGBASE_ET, MLOGBASE_FORMKUNOP(MLOGBASE_VEL, phi));
    }
  }
}

static MASSTOR_LIST distribveloet
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST first, firstpt, tail, elem, redelem, obj, result, prefix;
  MASSTOR_LIST C_14_dummy;

  if (L == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  MLOGBASE_FORPFOR(L, &first, &tail);
  if (tail == MASSTOR_SIL) {
    return first;
  }
  MLOGBASE_FORPARGS(first, &C_14_dummy, &first);
  while (tail != MASSTOR_SIL) {
    MLOGBASE_FORPARGS(tail, &obj, &tail);
    MLOGBASE_FORPARGS(obj, &C_14_dummy, &obj);
    result = MASSTOR_SIL;
    while (obj != MASSTOR_SIL) {
      MLOGBASE_FORPARGS(obj, &elem, &obj);
      redelem = MASSTOR_RED(elem);
      firstpt = first;
      while (firstpt != MASSTOR_SIL) {
        MLOGBASE_FORPARGS(firstpt, &prefix, &firstpt);
        result = MASSTOR_COMP(SACLIST_CCONC(prefix, redelem), result);
      }
    }
    first = result;
  }
  result = MLOGBASE_FORMKFOR(MLOGBASE_ET, result);
  return result;
}

MASSTOR_LIST MASLOG_FORMKPRENEX
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST pref)
# else
(phi, pref)
MASSTOR_LIST phi, pref;
# endif
{
  MASSTOR_LIST pnfs, phi1, phi2, qbphi1, qbphi2;

  if (pref != MLOGBASE_EXIST && pref != MLOGBASE_FORALL) {
    MASERR_ERROR(MASERR_severe, "FORMKPRENEX: wrong preference given (assume EXIST)", 50L);
    pref = MLOGBASE_EXIST;
  }
  pnfs = MASLOG_FORMKPRENEX1(phi);
  if (MASSTOR_RED(pnfs) == MASSTOR_SIL) {
    return MASSTOR_FIRST(MASSTOR_FIRST(pnfs));
  }
  phi1 = MASSTOR_FIRST(MASSTOR_FIRST(pnfs));
  phi2 = MASSTOR_FIRST(SACLIST_SECOND(pnfs));
  qbphi1 = SACLIST_SECOND(MASSTOR_FIRST(pnfs));
  qbphi2 = SACLIST_SECOND(SACLIST_SECOND(pnfs));
  if (qbphi1 < qbphi2) {
    return phi1;
  } else if (qbphi1 > qbphi2) {
    return phi2;
  } else if (MLOGBASE_FORGOP(phi1) == pref) {
    return phi1;
  } else {
    return phi2;
  }
}

MASSTOR_LIST MASLOG_FORMKPRENEXI
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST pref)
# else
(phi, pref)
MASSTOR_LIST phi, pref;
# endif
{
  MASSTOR_LIST pnfs, phi1, phi2, qbphi1, qbphi2;

  if (pref != MLOGBASE_EXIST && pref != MLOGBASE_FORALL) {
    MASERR_ERROR(MASERR_severe, "FORMKPRENEX: wrong preference given (assume EXIST)", 50L);
    pref = MLOGBASE_EXIST;
  }
  pnfs = MASLOG_FORMKPRENEX1(phi);
  if (MASSTOR_RED(pnfs) == MASSTOR_SIL) {
    return MASSTOR_FIRST(MASSTOR_FIRST(pnfs));
  }
  phi1 = MASSTOR_FIRST(MASSTOR_FIRST(pnfs));
  phi2 = MASSTOR_FIRST(SACLIST_SECOND(pnfs));
  qbphi1 = SACLIST_SECOND(MASSTOR_FIRST(pnfs));
  qbphi2 = SACLIST_SECOND(SACLIST_SECOND(pnfs));
  if (qbphi1 < qbphi2) {
    return phi1;
  } else if (qbphi1 > qbphi2) {
    return phi2;
  } else if (MASLOG_FORIMQB(phi1) == pref) {
    return phi1;
  } else {
    return phi2;
  }
}

MASSTOR_LIST MASLOG_FORMKPRENEX1
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  MASSTOR_LIST op, res;

  MLOGBASE_FORPFOR(phi, &op, &res);
  if (op == MLOGBASE_EXIST || op == MLOGBASE_FORALL) {
    return pnfquantifier(phi);
  } else if (op == MLOGBASE_VEL || op == MLOGBASE_ET) {
    return pnfjunctor(phi);
  } else {
    return MASSTOR_LIST1(SACLIST_LIST2(phi, 0));
  }
}

static MASSTOR_LIST pnfquantifier
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  MASSTOR_LIST pnfs, qf, vars, nvars, qform, psi1, psi2, qbpsi1, qbpsi2;

  MLOGBASE_FORPQUANT(phi, &qf, &vars, &qform);
  nvars = MLOGBASE_FORGLVAR(vars);
  pnfs = MASLOG_FORMKPRENEX1(qform);
  psi1 = MASSTOR_FIRST(MASSTOR_FIRST(pnfs));
  qbpsi1 = SACLIST_SECOND(MASSTOR_FIRST(pnfs));
  if (MASSTOR_RED(pnfs) == MASSTOR_SIL) {
    return MASSTOR_LIST1(mkquant(qf, nvars, psi1, qbpsi1));
  } else if (MLOGBASE_FORGOP(psi1) == qf) {
    return MASSTOR_LIST1(mkquant(qf, nvars, psi1, qbpsi1));
  } else {
    psi2 = MASSTOR_FIRST(SACLIST_SECOND(pnfs));
    qbpsi2 = SACLIST_SECOND(SACLIST_SECOND(pnfs));
    return MASSTOR_LIST1(mkquant(qf, nvars, psi2, qbpsi2));
  }
}

static MASSTOR_LIST mkquant
# ifdef __STDC__
(MASSTOR_LIST qf, MASSTOR_LIST vars, MASSTOR_LIST phi, MASSTOR_LIST qbqform)
# else
(qf, vars, phi, qbqform)
MASSTOR_LIST qf, vars, phi, qbqform;
# endif
{
  MASSTOR_LIST op, res, form, newvarlist, varlist;

  MLOGBASE_FORPFOR(phi, &op, &res);
  if (op != qf) {
    return SACLIST_LIST2(MLOGBASE_FORMKQUANT(qf, MLOGBASE_FORMKLVAR(vars), phi), qbqform + 1);
  } else {
    MLOGBASE_FORPQUANTA(res, &varlist, &form);
    newvarlist = SACLIST_CCONC(vars, MLOGBASE_FORGLVAR(varlist));
    return SACLIST_LIST2(MLOGBASE_FORMKQUANT(qf, MLOGBASE_FORMKLVAR(newvarlist), form), qbqform);
  }
}

static MASSTOR_LIST pnfjunctor
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  MASSTOR_LIST op, res, arglist, pnfargs, arg, l1, l2, M, qf1, qf2;
  MASSTOR_LIST phi1, qbphi1, phi2, qbphi2;
  BOOLEAN onlyex, onlyfa;

  M = 0;
  onlyex = TRUE;
  onlyfa = TRUE;
  MLOGBASE_FORPFOR(phi, &op, &res);
  arglist = MASSTOR_SIL;
  l1 = MASSTOR_SIL;
  l2 = MASSTOR_SIL;
  while (res != MASSTOR_SIL) {
    MLOGBASE_FORPARGS(res, &arg, &res);
    pnfargs = MASLOG_FORMKPRENEX1(arg);
    phi1 = MASSTOR_FIRST(MASSTOR_FIRST(pnfargs));
    qbphi1 = SACLIST_SECOND(MASSTOR_FIRST(pnfargs));
    if (MASSTOR_RED(pnfargs) == MASSTOR_SIL) {
      l1 = MASSTOR_COMP(phi1, l1);
      l2 = MASSTOR_COMP(phi1, l2);
      phi2 = phi1;
      qbphi2 = qbphi1;
    } else {
      phi2 = MASSTOR_FIRST(SACLIST_SECOND(pnfargs));
      qbphi2 = SACLIST_SECOND(SACLIST_SECOND(pnfargs));
      l1 = MASSTOR_COMP(phi1, l1);
      l2 = MASSTOR_COMP(phi2, l2);
    }
    qf1 = MLOGBASE_FORGOP(phi1);
    qf2 = MLOGBASE_FORGOP(phi2);
    if (M < qbphi1) {
      M = qbphi1;
      onlyex = TRUE;
      onlyfa = TRUE;
    }
    if (M == qbphi1 && qf1 != MLOGBASE_EXIST) {
      onlyex = FALSE;
    }
    if (M == qbphi2 && qf2 != MLOGBASE_FORALL) {
      onlyfa = FALSE;
    }
  }
  if (M == 0) {
    return MASSTOR_LIST1(SACLIST_LIST2(phi, 0));
  }
  if (onlyex && !onlyfa) {
    return MASSTOR_LIST1(interchange(l1, op, MLOGBASE_EXIST));
  } else if (onlyfa && !onlyex) {
    return MASSTOR_LIST1(interchange(l2, op, MLOGBASE_FORALL));
  } else {
    return SACLIST_LIST2(interchange(l1, op, MLOGBASE_EXIST), interchange(l2, op, MLOGBASE_FORALL));
  }
}

static MASSTOR_LIST interchange
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST op, MASSTOR_LIST pref)
# else
(L, op, pref)
MASSTOR_LIST L, op, pref;
# endif
{
  MASSTOR_LIST l1, l2, qf, q, form, qblock, vblock, qform, vars;
  MASSTOR_LIST varlist, result, numqfb, nextop;
  BOOLEAN noqf;

  if (L == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  l1 = L;
  qf = pref;
  qblock = MASSTOR_SIL;
  vblock = MASSTOR_SIL;
  do {
    l2 = MASSTOR_SIL;
    varlist = MASSTOR_SIL;
    noqf = TRUE;
    while (l1 != MASSTOR_SIL) {
      MASSTOR_ADV(l1, &form, &l1);
      getqfb(form, qf, &vars, &qform);
      nextop = MLOGBASE_FORGOP(qform);
      noqf = noqf && (nextop != MLOGBASE_EXIST && nextop != MLOGBASE_FORALL);
      l2 = MASSTOR_COMP(qform, l2);
      varlist = SACLIST_CCONC(varlist, vars);
    }
    if (varlist != MASSTOR_SIL) {
      qblock = MASSTOR_COMP(qf, qblock);
      vblock = MASSTOR_COMP(MLOGBASE_FORMKLVAR(varlist), vblock);
    }
    l1 = l2;
    qf = notsymbol(qf);
  } while (!noqf);
  numqfb = MASSTOR_LENGTH(vblock);
  result = MLOGBASE_FORMKFOR(op, l1);
  while (qblock != MASSTOR_SIL) {
    MASSTOR_ADV(qblock, &q, &qblock);
    MASSTOR_ADV(vblock, &varlist, &vblock);
    result = MLOGBASE_FORMKQUANT(q, varlist, result);
  }
  return SACLIST_LIST2(result, numqfb);
}

static void getqfb
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST qf, MASSTOR_LIST *qfb, MASSTOR_LIST *qform)
# else
(phi, qf, qfb, qform)
MASSTOR_LIST phi, qf;
MASSTOR_LIST *qfb, *qform;
# endif
{
  MASSTOR_LIST op, res, varlist, bound;

  *qfb = MASSTOR_SIL;
  MLOGBASE_FORPFOR(phi, &op, &res);
  if (op != qf) {
    *qform = phi;
    return;
  }
  while (op == qf) {
    MLOGBASE_FORPQUANTA(res, &varlist, qform);
    MLOGBASE_FORPLVAR(varlist, &bound);
    *qfb = SACLIST_CCONC(*qfb, bound);
    MLOGBASE_FORPFOR(*qform, &op, &res);
  }
  return;
}

MASSTOR_LIST MASLOG_FORIMQB
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  MASSTOR_LIST sym, vars, imq;

  sym = MLOGBASE_FORGOP(phi);
  if (sym != MLOGBASE_EXIST && sym != MLOGBASE_FORALL) {
    return MASSTOR_SIL;
  }
  do {
    imq = sym;
    MLOGBASE_FORPQUANT(phi, &sym, &vars, &phi);
  } while (!(sym != MLOGBASE_EXIST && sym != MLOGBASE_FORALL));
  return imq;
}

MASSTOR_LIST MASLOG_FORSUBSTVAR
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST old, MASSTOR_LIST new, MASLISPU_PROCF3 bbsubstvar)
# else
(phi, old, new, bbsubstvar)
MASSTOR_LIST phi, old, new;
MASLISPU_PROCF3 bbsubstvar;
# endif
{
  MASSTOR_LIST op, res, arg, arg1, arg2;
  MASSTOR_LIST parlist, lvar, varlist, var, qform;

  MLOGBASE_FORPFOR(phi, &op, &res);
  if (op == MLOGBASE_VERUM || op == MLOGBASE_FALSUM) {
    return phi;
  } else if (op == MLOGBASE_NON) {
    MLOGBASE_FORPUNOPA(res, &arg);
    return MLOGBASE_FORMKUNOP(op, MASLOG_FORSUBSTVAR(arg, old, new, bbsubstvar));
  } else if (op == MLOGBASE_VEL || op == MLOGBASE_ET) {
    parlist = MASSTOR_SIL;
    while (res != MASSTOR_SIL) {
      MLOGBASE_FORPARGS(res, &arg, &res);
      parlist = MASSTOR_COMP(MASLOG_FORSUBSTVAR(arg, old, new, bbsubstvar), parlist);
    }
    return MLOGBASE_FORMKFOR(op, MASSTOR_INV(parlist));
  } else if (op == MLOGBASE_REP || op == MLOGBASE_IMP || op == MLOGBASE_EQUIV || op == MLOGBASE_XOR) {
    MLOGBASE_FORPBINOPA(res, &arg1, &arg2);
    return MLOGBASE_FORMKBINOP(op, MASLOG_FORSUBSTVAR(arg1, old, new, bbsubstvar), MASLOG_FORSUBSTVAR(arg2, old, new, bbsubstvar));
  } else if (op == MLOGBASE_TVAR) {
    if (SACLIST_EQUAL(phi, old) == 1) {
      return new;
    } else {
      return phi;
    }
  } else if (op == MLOGBASE_EXIST || op == MLOGBASE_FORALL) {
    MLOGBASE_FORPQUANTA(res, &lvar, &qform);
    MLOGBASE_FORPLVAR(lvar, &varlist);
    parlist = MASSTOR_SIL;
    while (varlist != MASSTOR_SIL) {
      MLOGBASE_FORPARGS(varlist, &var, &varlist);
      if (SACLIST_EQUAL(var, old) == 1) {
        parlist = MASSTOR_COMP(new, varlist);
      } else {
        parlist = MASSTOR_COMP(var, parlist);
      }
    }
    return MLOGBASE_FORMKQUANT(op, MLOGBASE_FORMKLVAR(MASSTOR_INV(parlist)), MASLOG_FORSUBSTVAR(qform, old, new, bbsubstvar));
  } else {
    return (*bbsubstvar)(phi, old, new);
  }
}

MASSTOR_LIST MASLOG_FORMKVD
# ifdef __STDC__
(MASSTOR_LIST phi, MASLISPU_PROCF3 bbsubstvar, MASLISPU_PROCF1 bblsvars)
# else
(phi, bbsubstvar, bblsvars)
MASSTOR_LIST phi;
MASLISPU_PROCF3 bbsubstvar;
MASLISPU_PROCF1 bblsvars;
# endif
{
  MASSTOR_LIST all, used, var, xall, name, sort, free, bound, env;

  free = MASSTOR_SIL;
  bound = MASSTOR_SIL;
  env = MASSTOR_SIL;
  collectnames(phi, env, bblsvars, &free, &bound);
  used = free;
  all = SACLIST_CCONC(free, bound);
  xall = MASSTOR_SIL;
  while (all != MASSTOR_SIL) {
    MASSTOR_ADV(all, &var, &all);
    MLOGBASE_FORPVAR(var, &name, &sort);
    xall = MASSTOR_COMP(SACLIST_LIST2(MLOGBASE_FORVTGET(name), MLOGBASE_FORVTGET(sort)), xall);
  }
  return repvar(phi, MASSTOR_SIL, MASSTOR_SIL, &used, &xall, bbsubstvar);
}

static void collectnames
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST env, MASLISPU_PROCF1 bblsvars, MASSTOR_LIST *free, MASSTOR_LIST *bound)
# else
(phi, env, bblsvars, free, bound)
MASSTOR_LIST phi, env;
MASLISPU_PROCF1 bblsvars;
MASSTOR_LIST *free, *bound;
# endif
{
  MASSTOR_LIST op, red, arg, arg1, arg2, lvar, psi, name, sort;
  MASSTOR_LIST varlist, var;

  if (phi == MASSTOR_SIL) {
    return;
  }
  MLOGBASE_FORPFOR(phi, &op, &red);
  if (op == MLOGBASE_VERUM || op == MLOGBASE_FALSUM) {
    return;
  } else if (op == MLOGBASE_NON) {
    MLOGBASE_FORPUNOPA(red, &arg);
    collectnames(arg, env, bblsvars, free, bound);
    return;
  } else if (op == MLOGBASE_VEL || op == MLOGBASE_ET) {
    while (red != MASSTOR_SIL) {
      MLOGBASE_FORPARGS(red, &arg, &red);
      collectnames(arg, env, bblsvars, free, bound);
    }
    return;
  } else if (op == MLOGBASE_IMP || op == MLOGBASE_REP || op == MLOGBASE_EQUIV || op == MLOGBASE_XOR) {
    MLOGBASE_FORPBINOPA(red, &arg1, &arg2);
    collectnames(arg1, env, bblsvars, free, bound);
    collectnames(arg2, env, bblsvars, free, bound);
    return;
  } else if (op == MLOGBASE_EXIST || op == MLOGBASE_FORALL) {
    MLOGBASE_FORPQUANTA(red, &lvar, &psi);
    varlist = MLOGBASE_FORGLVAR(lvar);
    env = SACLIST_CCONC(varlist, env);
    *bound = SACLIST_CCONC(varlist, *bound);
    collectnames(psi, env, bblsvars, free, bound);
    return;
  } else if (op == MLOGBASE_TVAR) {
    *free = MASSTOR_COMP(phi, *free);
    return;
  } else {
    varlist = MASSET_SetComplementQ(env, (*bblsvars)(phi));
    *free = SACLIST_CCONC(varlist, *free);
    return;
  }
}

static MASSTOR_LIST repvar
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST old, MASSTOR_LIST new, MASSTOR_LIST *used, MASSTOR_LIST *denied, MASLISPU_PROCF3 bbsubstvar)
# else
(phi, old, new, used, denied, bbsubstvar)
MASSTOR_LIST phi, old, new;
MASSTOR_LIST *used, *denied;
MASLISPU_PROCF3 bbsubstvar;
# endif
{
  MASSTOR_LIST op, red, arg, arg1, arg2, lvar, psi, name, newvars, newv, sort, result, vars, v, p, t;

  if (phi == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  MLOGBASE_FORPFOR(phi, &op, &red);
  if (op == MLOGBASE_VERUM || op == MLOGBASE_FALSUM) {
    return phi;
  } else if (op == MLOGBASE_NON) {
    MLOGBASE_FORPUNOPA(red, &arg);
    return MLOGBASE_FORMKUNOP(MLOGBASE_NON, repvar(arg, old, new, used, denied, bbsubstvar));
  } else if (op == MLOGBASE_VEL || op == MLOGBASE_ET) {
    result = MASSTOR_SIL;
    while (red != MASSTOR_SIL) {
      MLOGBASE_FORPARGS(red, &arg, &red);
      result = MASSTOR_COMP(repvar(arg, old, new, used, denied, bbsubstvar), result);
    }
    return MLOGBASE_FORMKFOR(op, MASSTOR_INV(result));
  } else if (op == MLOGBASE_IMP || op == MLOGBASE_REP || op == MLOGBASE_EQUIV || op == MLOGBASE_XOR) {
    MLOGBASE_FORPBINOPA(red, &arg1, &arg2);
    return MLOGBASE_FORMKBINOP(op, repvar(arg1, old, new, used, denied, bbsubstvar), repvar(arg2, old, new, used, denied, bbsubstvar));
  } else if (op == MLOGBASE_EXIST || op == MLOGBASE_FORALL) {
    MLOGBASE_FORPQUANTA(red, &lvar, &psi);
    MLOGBASE_FORPLVAR(lvar, &vars);
    newvars = MASSTOR_SIL;
    while (vars != MASSTOR_SIL) {
      MASSTOR_ADV(vars, &v, &vars);
      if (SACLIST_MEMBER(v, *used) == 1) {
        newv = GENVAR(v, *denied);
        MLOGBASE_FORPVAR(newv, &name, &sort);
        *denied = MASSTOR_COMP(SACLIST_LIST2(MLOGBASE_FORVTGET(name), MLOGBASE_FORVTGET(sort)), *denied);
        old = MASSTOR_COMP(v, old);
        new = MASSTOR_COMP(newv, new);
        newvars = MASSTOR_COMP(newv, newvars);
      } else {
        *used = MASSTOR_COMP(v, *used);
        newvars = MASSTOR_COMP(v, newvars);
      }
    }
    return MLOGBASE_FORMKQUANT(op, MLOGBASE_FORMKLVAR(MASSTOR_INV(newvars)), repvar(psi, old, new, used, denied, bbsubstvar));
  } else if (op == MLOGBASE_TVAR) {
    while (old != MASSTOR_SIL) {
      MASSTOR_ADV(old, &p, &old);
      MASSTOR_ADV(new, &t, &new);
      if (SACLIST_EQUAL(phi, p) == 1) {
        return t;
      }
    }
    return phi;
  } else {
    result = phi;
    while (old != MASSTOR_SIL) {
      MASSTOR_ADV(old, &p, &old);
      MASSTOR_ADV(new, &t, &new);
      result = (*bbsubstvar)(result, p, t);
    }
    return result;
  }
}

static MASSTOR_LIST GENVAR
# ifdef __STDC__
(MASSTOR_LIST var, MASSTOR_LIST xdenied)
# else
(var, xdenied)
MASSTOR_LIST var, xdenied;
# endif
{
  MASSTOR_LIST name, sort, xname, xsort, sname, num, q, new;

  MLOGBASE_FORPVAR(var, &name, &sort);
  xname = MLOGBASE_FORVTGET(name);
  xsort = MLOGBASE_FORVTGET(sort);
  if (SACLIST_MEMBER(SACLIST_LIST2(xname, xsort), xdenied) == 0) {
    return var;
  }
  num = 0;
  do {
    new = MASSTOR_SIL;
    num = num + 1;
    q = num;
    do {
      new = MASSTOR_COMP(MASELEM_MASREM(q, 10), new);
      q = q / 10;
    } while (!(q == 0));
    new = MASSTOR_COMP(MASBIOS_MASORD('N'), new);
    new = SACLIST_CCONC(xname, new);
  } while (!(SACLIST_MEMBER(SACLIST_LIST2(new, xsort), xdenied) == 0));
  sname = MLOGBASE_FORVTENTER(new);
  return MLOGBASE_FORMKVAR(sname, sort);
}

MASSTOR_LIST MASLOG_FORSMPL
# ifdef __STDC__
(MASSTOR_LIST phi, MASLISPU_PROCF1 bbsmpl, MASLISPU_PROCF1 bbmkneg)
# else
(phi, bbsmpl, bbmkneg)
MASSTOR_LIST phi;
MASLISPU_PROCF1 bbsmpl, bbmkneg;
# endif
{
  MASSTOR_LIST op, red, arg, arg1, arg2, simparg1, simparg2, newop, newarg;
  MASSTOR_LIST newred, vars, qform, simpqform, elem, result;

  if (phi == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  MLOGBASE_FORPFOR(phi, &op, &red);
  if (op == MLOGBASE_VERUM || op == MLOGBASE_FALSUM) {
    return phi;
  } else if (op == MLOGBASE_NON) {
    MLOGBASE_FORPUNOPA(red, &arg);
    newarg = MASLOG_FORSMPL(arg, bbsmpl, bbmkneg);
    return formkneg(newarg, bbmkneg);
  } else if (op == MLOGBASE_ET) {
    result = MASSTOR_SIL;
    while (red != MASSTOR_SIL) {
      MLOGBASE_FORPARGS(red, &arg, &red);
      newarg = MASLOG_FORSMPL(arg, bbsmpl, bbmkneg);
      if (newarg == MLOGBASE_FALSUM) {
        return MLOGBASE_FORMKCNST(MLOGBASE_FALSUM);
      } else if (newarg != MLOGBASE_VERUM) {
        MLOGBASE_FORPARGS(newarg, &newop, &newred);
        if (newop == MLOGBASE_ET) {
          while (newred != MASSTOR_SIL) {
            MLOGBASE_FORPARGS(newred, &elem, &newred);
            result = MASSTOR_COMP(elem, result);
          }
        } else {
          result = MASSTOR_COMP(newarg, result);
        }
      }
    }
    if (result != MASSTOR_SIL) {
      return MLOGBASE_FORMKFOR(MLOGBASE_ET, MASSTOR_INV(result));
    } else {
      return MLOGBASE_FORMKCNST(MLOGBASE_VERUM);
    }
  } else if (op == MLOGBASE_VEL) {
    result = MASSTOR_SIL;
    while (red != MASSTOR_SIL) {
      MLOGBASE_FORPARGS(red, &arg, &red);
      newarg = MASLOG_FORSMPL(arg, bbsmpl, bbmkneg);
      if (newarg == MLOGBASE_VERUM) {
        return MLOGBASE_VERUM;
      } else if (newarg != MLOGBASE_FALSUM) {
        MLOGBASE_FORPARGS(newarg, &newop, &newred);
        if (newop == MLOGBASE_VEL) {
          while (newred != MASSTOR_SIL) {
            MLOGBASE_FORPARGS(newred, &elem, &newred);
            result = MASSTOR_COMP(elem, result);
          }
        } else {
          result = MASSTOR_COMP(newarg, result);
        }
      }
    }
    if (result != MASSTOR_SIL) {
      return MLOGBASE_FORMKFOR(MLOGBASE_VEL, MASSTOR_INV(result));
    } else {
      return MLOGBASE_FORMKCNST(MLOGBASE_FALSUM);
    }
  } else if (op == MLOGBASE_IMP || op == MLOGBASE_REP) {
    return smplimpl(phi, bbsmpl, bbmkneg);
  } else if (op == MLOGBASE_EQUIV) {
    MLOGBASE_FORPBINOPA(red, &arg1, &arg2);
    simparg1 = MASLOG_FORSMPL(arg1, bbsmpl, bbmkneg);
    simparg2 = MASLOG_FORSMPL(arg2, bbsmpl, bbmkneg);
    if (simparg1 == MLOGBASE_VERUM) {
      return simparg2;
    } else if (simparg2 == MLOGBASE_VERUM) {
      return simparg1;
    } else if (simparg1 == MLOGBASE_FALSUM) {
      return formkneg(simparg2, bbmkneg);
    } else if (simparg2 == MLOGBASE_FALSUM) {
      return formkneg(simparg1, bbmkneg);
    } else {
      return MLOGBASE_FORMKBINOP(MLOGBASE_EQUIV, simparg1, simparg2);
    }
  } else if (op == MLOGBASE_XOR) {
    MLOGBASE_FORPBINOPA(red, &arg1, &arg2);
    simparg1 = MASLOG_FORSMPL(arg1, bbsmpl, bbmkneg);
    simparg2 = MASLOG_FORSMPL(arg2, bbsmpl, bbmkneg);
    if (simparg1 == MLOGBASE_FALSUM) {
      return simparg2;
    } else if (simparg2 == MLOGBASE_FALSUM) {
      return simparg1;
    } else if (simparg1 == MLOGBASE_VERUM) {
      return formkneg(simparg2, bbmkneg);
    } else if (simparg2 == MLOGBASE_VERUM) {
      return formkneg(simparg1, bbmkneg);
    } else {
      return MLOGBASE_FORMKBINOP(MLOGBASE_XOR, simparg1, simparg2);
    }
  } else if (op == MLOGBASE_EXIST || op == MLOGBASE_FORALL) {
    MLOGBASE_FORPQUANTA(red, &vars, &qform);
    simpqform = MASLOG_FORSMPL(qform, bbsmpl, bbmkneg);
    if (simpqform == MLOGBASE_VERUM || simpqform == MLOGBASE_FALSUM) {
      return simpqform;
    } else {
      return MLOGBASE_FORMKQUANT(op, vars, simpqform);
    }
  } else if (op == MLOGBASE_TVAR) {
    return phi;
  } else {
    return (*bbsmpl)(phi);
  }
}

static MASSTOR_LIST smplimpl
# ifdef __STDC__
(MASSTOR_LIST phi, MASLISPU_PROCF1 bbsmpl, MASLISPU_PROCF1 bbmkneg)
# else
(phi, bbsmpl, bbmkneg)
MASSTOR_LIST phi;
MASLISPU_PROCF1 bbsmpl, bbmkneg;
# endif
{
  MASSTOR_LIST sprem, sconcl, prem, concl, op, newarg, newop, arg1, arg2;

  MLOGBASE_FORPBINOP(phi, &op, &arg1, &arg2);
  if (op == MLOGBASE_IMP) {
    prem = arg1;
    concl = arg2;
  } else {
    prem = arg2;
    concl = arg1;
  }
  if (prem == MLOGBASE_FALSUM) {
    return MLOGBASE_FORMKCNST(MLOGBASE_VERUM);
  } else if (prem == MLOGBASE_VERUM) {
    return MASLOG_FORSMPL(concl, bbsmpl, bbmkneg);
  } else if (concl == MLOGBASE_FALSUM) {
    return MASLOG_FORSMPL(MLOGBASE_FORMKUNOP(MLOGBASE_NON, prem), bbsmpl, bbmkneg);
  } else if (concl == MLOGBASE_VERUM) {
    return concl;
  } else {
    sprem = MASLOG_FORSMPL(prem, bbsmpl, bbmkneg);
    sconcl = MASLOG_FORSMPL(concl, bbsmpl, bbmkneg);
    if (sprem == MLOGBASE_FALSUM) {
      return MLOGBASE_FORMKCNST(MLOGBASE_VERUM);
    } else if (sprem == MLOGBASE_VERUM) {
      return sconcl;
    } else if (sconcl == MLOGBASE_FALSUM) {
      MLOGBASE_FORPFOR(sprem, &newop, &newarg);
      if (newop == MLOGBASE_NON) {
        return newarg;
      } else {
        return MLOGBASE_FORMKUNOP(MLOGBASE_NON, sprem);
      }
    } else if (sconcl == MLOGBASE_VERUM) {
      return sconcl;
    } else {
      if (SACLIST_EQUAL(sprem, sconcl) == 1) {
        return MLOGBASE_VERUM;
      }
      if (op == MLOGBASE_IMP) {
        return MLOGBASE_FORMKBINOP(MLOGBASE_IMP, sprem, sconcl);
      } else {
        return MLOGBASE_FORMKBINOP(MLOGBASE_REP, sconcl, sprem);
      }
    }
  }
}

MASSTOR_LIST MASLOG_FORSIMPLIFY
# ifdef __STDC__
(MASSTOR_LIST phi, MASLISPU_PROCF1 smart, MASLISPU_PROCF1 bbsmpl, MASLISPU_PROCF1 bbmkneg)
# else
(phi, smart, bbsmpl, bbmkneg)
MASSTOR_LIST phi;
MASLISPU_PROCF1 smart;
MASLISPU_PROCF1 bbsmpl, bbmkneg;
# endif
{
  MASSTOR_LIST op, red, arg, arg1, arg2, simparg1, simparg2, newop, newarg;
  MASSTOR_LIST newred, vars, qform, simpqform, elem, result;
  MASSTOR_LIST aflist, cflist, psi;

  if (phi == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  MLOGBASE_FORPFOR(phi, &op, &red);
  if (op == MLOGBASE_VERUM || op == MLOGBASE_FALSUM) {
    return phi;
  } else if (op == MLOGBASE_NON) {
    MLOGBASE_FORPUNOPA(red, &arg);
    newarg = MASLOG_FORSIMPLIFY(arg, smart, bbsmpl, bbmkneg);
    return formkneg(newarg, bbmkneg);
  } else if (op == MLOGBASE_ET || op == MLOGBASE_VEL) {
    result = MASSTOR_SIL;
    while (red != MASSTOR_SIL) {
      MLOGBASE_FORPARGS(red, &arg, &red);
      arg = MASLOG_FORSIMPLIFY(arg, smart, bbsmpl, bbmkneg);
      result = SimplifyComp(arg, op, result);
      if (result == MLOGBASE_VERUM || result == MLOGBASE_FALSUM) {
        return result;
      }
    }
    result = DoSmartSimplify(result, op, smart);
    if (result == MLOGBASE_VERUM || result == MLOGBASE_FALSUM) {
      return result;
    }
    if (result == MLOGBASE_VERUM || result == MLOGBASE_FALSUM) {
      return MLOGBASE_FORMKCNST(result);
    } else if (result == MASSTOR_SIL) {
      if (op == MLOGBASE_ET) {
        return MLOGBASE_FORMKCNST(MLOGBASE_VERUM);
      } else {
        return MLOGBASE_FORMKCNST(MLOGBASE_FALSUM);
      }
    } else if (MASSTOR_RED(result) == MASSTOR_SIL) {
      return MASSTOR_FIRST(result);
    } else {
      return MLOGBASE_FORMKFOR(op, result);
    }
  } else if (op == MLOGBASE_IMP || op == MLOGBASE_REP) {
    return smplimpl(phi, bbsmpl, bbmkneg);
  } else if (op == MLOGBASE_EQUIV) {
    MLOGBASE_FORPBINOPA(red, &arg1, &arg2);
    simparg1 = MASLOG_FORSIMPLIFY(arg1, smart, bbsmpl, bbmkneg);
    simparg2 = MASLOG_FORSIMPLIFY(arg2, smart, bbsmpl, bbmkneg);
    if (simparg1 == MLOGBASE_VERUM) {
      return simparg2;
    } else if (simparg2 == MLOGBASE_VERUM) {
      return simparg1;
    } else if (simparg1 == MLOGBASE_FALSUM) {
      return formkneg(simparg2, bbmkneg);
    } else if (simparg2 == MLOGBASE_FALSUM) {
      return formkneg(simparg1, bbmkneg);
    } else {
      if (SACLIST_EQUAL(simparg1, simparg2) == 1) {
        return MLOGBASE_VERUM;
      }
      return MLOGBASE_FORMKBINOP(MLOGBASE_EQUIV, simparg1, simparg2);
    }
  } else if (op == MLOGBASE_XOR) {
    MLOGBASE_FORPBINOPA(red, &arg1, &arg2);
    simparg1 = MASLOG_FORSIMPLIFY(arg1, smart, bbsmpl, bbmkneg);
    simparg2 = MASLOG_FORSIMPLIFY(arg2, smart, bbsmpl, bbmkneg);
    if (simparg1 == MLOGBASE_FALSUM) {
      return simparg2;
    } else if (simparg2 == MLOGBASE_FALSUM) {
      return simparg1;
    } else if (simparg1 == MLOGBASE_VERUM) {
      return formkneg(simparg2, bbmkneg);
    } else if (simparg2 == MLOGBASE_VERUM) {
      return formkneg(simparg1, bbmkneg);
    } else {
      if (SACLIST_EQUAL(simparg1, simparg2) == 1) {
        return MLOGBASE_FALSUM;
      }
      return MLOGBASE_FORMKBINOP(MLOGBASE_XOR, simparg1, simparg2);
    }
  } else if (op == MLOGBASE_EXIST || op == MLOGBASE_FORALL) {
    MLOGBASE_FORPQUANTA(red, &vars, &qform);
    simpqform = MASLOG_FORSIMPLIFY(qform, smart, bbsmpl, bbmkneg);
    if (simpqform == MLOGBASE_VERUM || simpqform == MLOGBASE_FALSUM) {
      return simpqform;
    } else {
      return MLOGBASE_FORMKQUANT(op, vars, simpqform);
    }
  } else if (op == MLOGBASE_TVAR) {
    return phi;
  } else {
    return (*bbsmpl)(phi);
  }
}

static MASSTOR_LIST SimplifyComp
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST op, MASSTOR_LIST L)
# else
(phi, op, L)
MASSTOR_LIST phi, op, L;
# endif
{
  MASSTOR_LIST args, psi;

  if (op == MLOGBASE_ET && phi == MLOGBASE_FALSUM || op == MLOGBASE_VEL && phi == MLOGBASE_VERUM) {
    return phi;
  } else if (phi == MLOGBASE_VERUM || phi == MLOGBASE_FALSUM) {
    return L;
  }
  if (MLOGBASE_FORGOP(phi) == op) {
    args = MLOGBASE_FORGARGS(phi);
    while (args != MASSTOR_SIL) {
      MASSTOR_ADV(args, &psi, &args);
      L = MASSET_SetAddQ(psi, L);
    }
    return L;
  } else {
    return MASSET_SetAddQ(phi, L);
  }
}

static MASSTOR_LIST DoSmartSimplify
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST op, MASLISPU_PROCF1 smart)
# else
(L, op, smart)
MASSTOR_LIST L, op;
MASLISPU_PROCF1 smart;
# endif
{
  MASSTOR_LIST aflist, cflist, psi, result, smartresult;

  aflist = MASSTOR_SIL;
  result = MASSTOR_SIL;
  while (L != MASSTOR_SIL) {
    MASSTOR_ADV(L, &psi, &L);
    if (MLOGBASE_FORISBBFOR(psi)) {
      aflist = MASSTOR_COMP(psi, aflist);
    } else {
      result = MASSTOR_COMP(psi, result);
    }
  }
  if (aflist != MASSTOR_SIL) {
    smartresult = (*smart)(MLOGBASE_FORMKFOR(op, aflist));
    if (!MLOGBASE_FORISATOM(smartresult)) {
      smartresult = MLOGBASE_FORMKFOR(MLOGBASE_FORGOP(smartresult), MASSTOR_INV(MLOGBASE_FORGARGS(smartresult)));
    }
    return SimplifyComp(smartresult, op, result);
  } else {
    return result;
  }
}

MASSTOR_LIST MASLOG_FORSIMPLIFYP
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST maxlevel, MASLISPU_PROCF1 smart, MASLISPU_PROCF1 bbsmpl, MASLISPU_PROCF1 bbmkneg)
# else
(phi, maxlevel, smart, bbsmpl, bbmkneg)
MASSTOR_LIST phi, maxlevel;
MASLISPU_PROCF1 smart;
MASLISPU_PROCF1 bbsmpl, bbmkneg;
# endif
{
  return simplifyp(phi, 1, maxlevel, smart, bbsmpl, bbmkneg);
}

static MASSTOR_LIST simplifyp
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST level, MASSTOR_LIST maxlevel, MASLISPU_PROCF1 smart, MASLISPU_PROCF1 bbsmpl, MASLISPU_PROCF1 bbmkneg)
# else
(phi, level, maxlevel, smart, bbsmpl, bbmkneg)
MASSTOR_LIST phi, level, maxlevel;
MASLISPU_PROCF1 smart;
MASLISPU_PROCF1 bbsmpl, bbmkneg;
# endif
{
  MASSTOR_LIST op, red, arg, arg1, arg2, simparg1, simparg2, newop, newarg;
  MASSTOR_LIST newred, vars, qform, simpqform, elem, result;
  MASSTOR_LIST aflist, cflist, psi;

  if (phi == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  if (level == maxlevel + 1) {
    return phi;
  }
  MLOGBASE_FORPFOR(phi, &op, &red);
  if (op == MLOGBASE_VERUM || op == MLOGBASE_FALSUM) {
    return phi;
  } else if (op == MLOGBASE_NON) {
    MLOGBASE_FORPUNOPA(red, &arg);
    newarg = simplifyp(arg, level + 1, maxlevel, smart, bbsmpl, bbmkneg);
    return formkneg(newarg, bbmkneg);
  } else if (op == MLOGBASE_ET || op == MLOGBASE_VEL) {
    result = MASSTOR_SIL;
    while (red != MASSTOR_SIL) {
      MLOGBASE_FORPARGS(red, &arg, &red);
      arg = simplifyp(arg, level + 1, maxlevel, smart, bbsmpl, bbmkneg);
      result = SimplifyComp(arg, op, result);
      if (result == MLOGBASE_VERUM || result == MLOGBASE_FALSUM) {
        return result;
      }
    }
    result = DoSmartSimplify(result, op, smart);
    if (result == MLOGBASE_VERUM || result == MLOGBASE_FALSUM) {
      return result;
    }
    if (result == MLOGBASE_VERUM || result == MLOGBASE_FALSUM) {
      return MLOGBASE_FORMKCNST(result);
    } else if (result == MASSTOR_SIL) {
      if (op == MLOGBASE_ET) {
        return MLOGBASE_FORMKCNST(MLOGBASE_VERUM);
      } else {
        return MLOGBASE_FORMKCNST(MLOGBASE_FALSUM);
      }
    } else if (MASSTOR_RED(result) == MASSTOR_SIL) {
      return MASSTOR_FIRST(result);
    } else {
      return MLOGBASE_FORMKFOR(op, result);
    }
  } else if (op == MLOGBASE_IMP || op == MLOGBASE_REP) {
    return smplimpl(phi, bbsmpl, bbmkneg);
  } else if (op == MLOGBASE_EQUIV) {
    MLOGBASE_FORPBINOPA(red, &arg1, &arg2);
    simparg1 = simplifyp(arg1, level + 1, maxlevel, smart, bbsmpl, bbmkneg);
    simparg2 = simplifyp(arg2, level + 1, maxlevel, smart, bbsmpl, bbmkneg);
    if (simparg1 == MLOGBASE_VERUM) {
      return simparg2;
    } else if (simparg2 == MLOGBASE_VERUM) {
      return simparg1;
    } else if (simparg1 == MLOGBASE_FALSUM) {
      return formkneg(simparg2, bbmkneg);
    } else if (simparg2 == MLOGBASE_FALSUM) {
      return formkneg(simparg1, bbmkneg);
    } else {
      if (SACLIST_EQUAL(simparg1, simparg2) == 1) {
        return MLOGBASE_VERUM;
      }
      return MLOGBASE_FORMKBINOP(MLOGBASE_EQUIV, simparg1, simparg2);
    }
  } else if (op == MLOGBASE_XOR) {
    MLOGBASE_FORPBINOPA(red, &arg1, &arg2);
    simparg1 = simplifyp(arg1, level + 1, maxlevel, smart, bbsmpl, bbmkneg);
    simparg2 = simplifyp(arg2, level + 1, maxlevel, smart, bbsmpl, bbmkneg);
    if (simparg1 == MLOGBASE_FALSUM) {
      return simparg2;
    } else if (simparg2 == MLOGBASE_FALSUM) {
      return simparg1;
    } else if (simparg1 == MLOGBASE_VERUM) {
      return formkneg(simparg2, bbmkneg);
    } else if (simparg2 == MLOGBASE_VERUM) {
      return formkneg(simparg1, bbmkneg);
    } else {
      if (SACLIST_EQUAL(simparg1, simparg2) == 1) {
        return MLOGBASE_FALSUM;
      }
      return MLOGBASE_FORMKBINOP(MLOGBASE_XOR, simparg1, simparg2);
    }
  } else if (op == MLOGBASE_EXIST || op == MLOGBASE_FORALL) {
    MLOGBASE_FORPQUANTA(red, &vars, &qform);
    simpqform = simplifyp(qform, level + 1, maxlevel, smart, bbsmpl, bbmkneg);
    if (simpqform == MLOGBASE_VERUM || simpqform == MLOGBASE_FALSUM) {
      return simpqform;
    } else {
      return MLOGBASE_FORMKQUANT(op, vars, simpqform);
    }
  } else if (op == MLOGBASE_TVAR) {
    return phi;
  } else {
    return (*bbsmpl)(phi);
  }
}

MASSTOR_LIST MASLOG_FORPREPQE
# ifdef __STDC__
(MASSTOR_LIST phi, MASLISPU_PROCF1 bbmkneg)
# else
(phi, bbmkneg)
MASSTOR_LIST phi;
MASLISPU_PROCF1 bbmkneg;
# endif
{
  MASSTOR_LIST op, quant, red, parg, phi1, lastop, qblocks, vblocks, psi, arg, psi1, lvar;

  if (phi == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  MLOGBASE_FORPFOR(phi, &op, &red);
  if (op != MLOGBASE_EXIST && op != MLOGBASE_FORALL) {
    return phi;
  }
  qblocks = MASSTOR_SIL;
  vblocks = MASSTOR_SIL;
  while (op == MLOGBASE_EXIST || op == MLOGBASE_FORALL) {
    MLOGBASE_FORPQUANTA(red, &lvar, &phi1);
    qblocks = MASSTOR_COMP(op, qblocks);
    vblocks = MASSTOR_COMP(lvar, vblocks);
    MLOGBASE_FORPFOR(phi1, &op, &red);
  }
  MASSTOR_ADV(qblocks, &quant, &qblocks);
  MASSTOR_ADV(vblocks, &lvar, &vblocks);
  if (quant == MLOGBASE_EXIST) {
    psi1 = MASLOG_FORMKDNF(phi1, bbmkneg);
  } else {
    psi1 = MASLOG_FORMKCNF(phi1, bbmkneg);
  }
  MLOGBASE_FORPFOR(psi1, &op, &red);
  psi = MASSTOR_SIL;
  while (red != MASSTOR_SIL) {
    MLOGBASE_FORPARGS(red, &arg, &red);
    parg = MLOGBASE_FORMKQUANT(quant, lvar, arg);
    psi = MASSTOR_COMP(parg, psi);
  }
  psi = MLOGBASE_FORMKFOR(op, psi);
  while (qblocks != MASSTOR_SIL) {
    MASSTOR_ADV(qblocks, &quant, &qblocks);
    MASSTOR_ADV(vblocks, &lvar, &vblocks);
    psi = MLOGBASE_FORMKQUANT(quant, lvar, psi);
  }
  return psi;
}

MASSTOR_LIST MASLOG_FORELIMXOPS
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST pref)
# else
(phi, pref)
MASSTOR_LIST phi;
MASSTOR_LIST pref;
# endif
{
  MASSTOR_LIST op, arglist, arg, arg1, arg2, prem, concl, lvar, qform;
  MASSTOR_LIST elimarg1, elimarg2, res;

  if (phi == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  if (pref == MLOGBASE_NON) {
    return phi;
  }
  if (pref != MLOGBASE_VEL && pref != MLOGBASE_ET) {
    MASERR_ERROR(MASERR_severe, "FORMELIMXOPS: wrong preferenz given (assume NON)", 48L);
    return phi;
  }
  MLOGBASE_FORPFOR(phi, &op, &arglist);
  if (op == MLOGBASE_VERUM || op == MLOGBASE_FALSUM) {
    return phi;
  } else if (op == MLOGBASE_NON) {
    MLOGBASE_FORPUNOPA(arglist, &arg);
    return MLOGBASE_FORMKUNOP(MLOGBASE_NON, MASLOG_FORELIMXOPS(arg, pref));
  } else if (op == MLOGBASE_VEL || op == MLOGBASE_ET) {
    res = MASSTOR_SIL;
    while (arglist != MASSTOR_SIL) {
      MLOGBASE_FORPARGS(arglist, &arg, &arglist);
      res = MASSTOR_COMP(MASLOG_FORELIMXOPS(arg, pref), res);
    }
    return MLOGBASE_FORMKFOR(op, MASSTOR_INV(res));
  } else if (op == MLOGBASE_EXIST || op == MLOGBASE_FORALL) {
    MLOGBASE_FORPQUANTA(arglist, &lvar, &qform);
    return MLOGBASE_FORMKQUANT(op, lvar, MASLOG_FORELIMXOPS(qform, pref));
  } else if (op == MLOGBASE_IMP) {
    MLOGBASE_FORPBINOPA(arglist, &prem, &concl);
    return MLOGBASE_FORMKBINOP(MLOGBASE_VEL, MLOGBASE_FORMKUNOP(MLOGBASE_NON, MASLOG_FORELIMXOPS(prem, pref)), MASLOG_FORELIMXOPS(concl, pref));
  } else if (op == MLOGBASE_REP) {
    MLOGBASE_FORPBINOPA(arglist, &concl, &prem);
    return MLOGBASE_FORMKBINOP(MLOGBASE_VEL, MASLOG_FORELIMXOPS(concl, pref), MLOGBASE_FORMKUNOP(MLOGBASE_NON, MASLOG_FORELIMXOPS(prem, pref)));
  } else if (op == MLOGBASE_EQUIV && pref == MLOGBASE_VEL) {
    MLOGBASE_FORPBINOPA(arglist, &arg1, &arg2);
    elimarg1 = MASLOG_FORELIMXOPS(arg1, pref);
    elimarg2 = MASLOG_FORELIMXOPS(arg2, pref);
    return MLOGBASE_FORMKBINOP(MLOGBASE_VEL, MLOGBASE_FORMKBINOP(MLOGBASE_ET, elimarg1, elimarg2), MLOGBASE_FORMKBINOP(MLOGBASE_ET, MLOGBASE_FORMKUNOP(MLOGBASE_NON, elimarg1), MLOGBASE_FORMKUNOP(MLOGBASE_NON, elimarg2)));
  } else if (op == MLOGBASE_EQUIV && pref == MLOGBASE_ET) {
    MLOGBASE_FORPBINOPA(arglist, &arg1, &arg2);
    elimarg1 = MASLOG_FORELIMXOPS(arg1, pref);
    elimarg2 = MASLOG_FORELIMXOPS(arg2, pref);
    return MLOGBASE_FORMKBINOP(MLOGBASE_ET, MLOGBASE_FORMKBINOP(MLOGBASE_VEL, MLOGBASE_FORMKUNOP(MLOGBASE_NON, elimarg1), elimarg2), MLOGBASE_FORMKBINOP(MLOGBASE_VEL, elimarg1, MLOGBASE_FORMKUNOP(MLOGBASE_NON, elimarg2)));
  } else if (op == MLOGBASE_XOR && pref == MLOGBASE_VEL) {
    MLOGBASE_FORPBINOPA(arglist, &arg1, &arg2);
    elimarg1 = MASLOG_FORELIMXOPS(arg1, pref);
    elimarg2 = MASLOG_FORELIMXOPS(arg2, pref);
    return MLOGBASE_FORMKBINOP(MLOGBASE_VEL, MLOGBASE_FORMKBINOP(MLOGBASE_ET, MLOGBASE_FORMKUNOP(MLOGBASE_NON, elimarg1), elimarg2), MLOGBASE_FORMKBINOP(MLOGBASE_ET, elimarg1, MLOGBASE_FORMKUNOP(MLOGBASE_NON, elimarg2)));
  } else if (op == MLOGBASE_XOR && pref == MLOGBASE_ET) {
    MLOGBASE_FORPBINOPA(arglist, &arg1, &arg2);
    elimarg1 = MASLOG_FORELIMXOPS(arg1, pref);
    elimarg2 = MASLOG_FORELIMXOPS(arg2, pref);
    return MLOGBASE_FORMKBINOP(MLOGBASE_ET, MLOGBASE_FORMKBINOP(MLOGBASE_VEL, elimarg1, elimarg2), MLOGBASE_FORMKBINOP(MLOGBASE_VEL, MLOGBASE_FORMKUNOP(MLOGBASE_NON, elimarg1), MLOGBASE_FORMKUNOP(MLOGBASE_NON, elimarg2)));
  } else {
    return phi;
  }
}

MASSTOR_LIST MASLOG_FORREPAFS
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST rep)
# else
(phi, rep)
MASSTOR_LIST phi, rep;
# endif
{
  MASSTOR_LIST op, arg1, arg2, args, argi, found, result;
  MASSTOR_LIST quantifier, bvars;

  op = MLOGBASE_FORGOP(phi);
  if (op == MLOGBASE_NON) {
    return MLOGBASE_FORMKUNOP(MLOGBASE_NON, MASLOG_FORREPAFS(MASSTOR_FIRST(MLOGBASE_FORGARGS(phi)), rep));
  } else if (op == MLOGBASE_ET || op == MLOGBASE_VEL) {
    args = MLOGBASE_FORGARGS(phi);
    result = MASSTOR_SIL;
    while (args != MASSTOR_SIL) {
      MASSTOR_ADV(args, &argi, &args);
      result = MASSTOR_COMP(MASLOG_FORREPAFS(argi, rep), result);
    }
    return MLOGBASE_FORMKFOR(op, MASSTOR_INV(result));
  } else if (op == MLOGBASE_EXIST || op == MLOGBASE_FORALL) {
    MLOGBASE_FORPQUANT(phi, &quantifier, &bvars, &arg1);
    return MLOGBASE_FORMKQUANT(quantifier, bvars, MASLOG_FORREPAFS(arg1, rep));
  } else if (op == MLOGBASE_IMP || op == MLOGBASE_REP || op == MLOGBASE_EQUIV || op == MLOGBASE_XOR) {
    MLOGBASE_FORPBINOP(phi, &op, &arg1, &arg2);
    return MLOGBASE_FORMKBINOP(op, MASLOG_FORREPAFS(arg1, rep), MASLOG_FORREPAFS(arg2, rep));
  } else {
    found = MASSYM2_ASSOCQ(phi, rep);
    if (found == MASSTOR_SIL) {
      return phi;
    } else {
      return MASSTOR_FIRST(found);
    }
  }
}

MASSTOR_LIST MASLOG_FORAPPLYAT
# ifdef __STDC__
(MASSTOR_LIST phi, MASLISPU_PROCF1 dosomething)
# else
(phi, dosomething)
MASSTOR_LIST phi;
MASLISPU_PROCF1 dosomething;
# endif
{
  MASSTOR_LIST op, red, arg, arg1, arg2, lvar, psi, name, sort, result;

  if (phi == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  MLOGBASE_FORPFOR(phi, &op, &red);
  if (op == MLOGBASE_VERUM || op == MLOGBASE_FALSUM) {
    return (*dosomething)(phi);
  } else if (op == MLOGBASE_NON) {
    MLOGBASE_FORPUNOPA(red, &arg);
    return MLOGBASE_FORMKUNOP(MLOGBASE_NON, MASLOG_FORAPPLYAT(arg, dosomething));
  } else if (op == MLOGBASE_VEL || op == MLOGBASE_ET) {
    result = MASSTOR_SIL;
    while (red != MASSTOR_SIL) {
      MLOGBASE_FORPARGS(red, &arg, &red);
      result = MASSTOR_COMP(MASLOG_FORAPPLYAT(arg, dosomething), result);
    }
    return MLOGBASE_FORMKFOR(op, MASSTOR_INV(result));
  } else if (op == MLOGBASE_IMP || op == MLOGBASE_REP || op == MLOGBASE_EQUIV || op == MLOGBASE_XOR) {
    MLOGBASE_FORPBINOPA(red, &arg1, &arg2);
    return MLOGBASE_FORMKBINOP(op, MASLOG_FORAPPLYAT(arg1, dosomething), MASLOG_FORAPPLYAT(arg2, dosomething));
  } else if (op == MLOGBASE_EXIST || op == MLOGBASE_FORALL) {
    MLOGBASE_FORPQUANTA(red, &lvar, &psi);
    return MLOGBASE_FORMKQUANT(op, lvar, MASLOG_FORAPPLYAT(psi, dosomething));
  } else if (op == MLOGBASE_TVAR) {
    return (*dosomething)(phi);
  } else {
    return (*dosomething)(phi);
  }
}

MASSTOR_LIST MASLOG_FORAPPLYATF2
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST param1, MASLISPU_PROCF2 dosomething)
# else
(phi, param1, dosomething)
MASSTOR_LIST phi, param1;
MASLISPU_PROCF2 dosomething;
# endif
{
  MASSTOR_LIST op, red, arg, arg1, arg2, lvar, psi, name, sort, result;

  if (phi == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  MLOGBASE_FORPFOR(phi, &op, &red);
  if (op == MLOGBASE_VERUM || op == MLOGBASE_FALSUM) {
    return (*dosomething)(phi, param1);
  } else if (op == MLOGBASE_NON) {
    MLOGBASE_FORPUNOPA(red, &arg);
    return MLOGBASE_FORMKUNOP(MLOGBASE_NON, MASLOG_FORAPPLYATF2(arg, param1, dosomething));
  } else if (op == MLOGBASE_VEL || op == MLOGBASE_ET) {
    result = MASSTOR_SIL;
    while (red != MASSTOR_SIL) {
      MLOGBASE_FORPARGS(red, &arg, &red);
      result = MASSTOR_COMP(MASLOG_FORAPPLYATF2(arg, param1, dosomething), result);
    }
    return MLOGBASE_FORMKFOR(op, MASSTOR_INV(result));
  } else if (op == MLOGBASE_IMP || op == MLOGBASE_REP || op == MLOGBASE_EQUIV || op == MLOGBASE_XOR) {
    MLOGBASE_FORPBINOPA(red, &arg1, &arg2);
    return MLOGBASE_FORMKBINOP(op, MASLOG_FORAPPLYATF2(arg1, param1, dosomething), MASLOG_FORAPPLYATF2(arg2, param1, dosomething));
  } else if (op == MLOGBASE_EXIST || op == MLOGBASE_FORALL) {
    MLOGBASE_FORPQUANTA(red, &lvar, &psi);
    return MLOGBASE_FORMKQUANT(op, lvar, MASLOG_FORAPPLYATF2(psi, param1, dosomething));
  } else if (op == MLOGBASE_TVAR) {
    return (*dosomething)(phi, param1);
  } else {
    return (*dosomething)(phi, param1);
  }
}

MASSTOR_LIST MASLOG_FORCOUNTAF
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  MASSTOR_LIST op, red, arg, arg1, arg2, lvar, psi, number;

  if (phi == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  MLOGBASE_FORPFOR(phi, &op, &red);
  if (op == MLOGBASE_VERUM || op == MLOGBASE_FALSUM) {
    return 1;
  } else if (op == MLOGBASE_NON) {
    MLOGBASE_FORPUNOPA(red, &arg);
    return MASLOG_FORCOUNTAF(arg);
  } else if (op == MLOGBASE_VEL || op == MLOGBASE_ET) {
    number = 0;
    while (red != MASSTOR_SIL) {
      MLOGBASE_FORPARGS(red, &arg, &red);
      number = number + MASLOG_FORCOUNTAF(arg);
    }
    return number;
  } else if (op == MLOGBASE_IMP || op == MLOGBASE_REP || op == MLOGBASE_EQUIV || op == MLOGBASE_XOR) {
    MLOGBASE_FORPBINOPA(red, &arg1, &arg2);
    return MASLOG_FORCOUNTAF(arg1) + MASLOG_FORCOUNTAF(arg2);
  } else if (op == MLOGBASE_EXIST || op == MLOGBASE_FORALL) {
    MLOGBASE_FORPQUANTA(red, &lvar, &psi);
    return MASLOG_FORCOUNTAF(psi);
  } else if (op == MLOGBASE_TVAR) {
    return 1;
  } else {
    return 1;
  }
}

BOOLEAN MASLOG_FORCONTBDVAR
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST svar)
# else
(phi, svar)
MASSTOR_LIST phi;
MASSTOR_LIST svar;
# endif
{
  MASSTOR_LIST op, red, arg, arg1, arg2, lvar, psi, varlist, var;

  if (phi == MASSTOR_SIL) {
    return FALSE;
  }
  MLOGBASE_FORPFOR(phi, &op, &red);
  if (op == MLOGBASE_VERUM || op == MLOGBASE_FALSUM) {
    return FALSE;
  } else if (op == MLOGBASE_NON) {
    MLOGBASE_FORPUNOPA(phi, &arg);
    return MASLOG_FORCONTBDVAR(arg, svar);
  } else if (op == MLOGBASE_VEL || op == MLOGBASE_ET) {
    while (red != MASSTOR_SIL) {
      MLOGBASE_FORPARGS(red, &arg, &red);
      if (MASLOG_FORCONTBDVAR(arg, svar)) {
        return TRUE;
      }
    }
    return FALSE;
  } else if (op == MLOGBASE_IMP || op == MLOGBASE_REP || op == MLOGBASE_EQUIV || op == MLOGBASE_XOR) {
    MLOGBASE_FORPBINOPA(red, &arg1, &arg2);
    return MASLOG_FORCONTBDVAR(arg1, svar) || MASLOG_FORCONTBDVAR(arg2, svar);
  } else if (op == MLOGBASE_EXIST || op == MLOGBASE_FORALL) {
    MLOGBASE_FORPQUANTA(red, &lvar, &psi);
    MLOGBASE_FORPLVAR(lvar, &varlist);
    while (varlist != MASSTOR_SIL) {
      MLOGBASE_FORPARGS(varlist, &var, &varlist);
      if (SACLIST_EQUAL(svar, var) == 1) {
        return TRUE;
      }
    }
    return MASLOG_FORCONTBDVAR(psi, svar);
  } else if (op == MLOGBASE_TVAR) {
    return FALSE;
  } else {
    return FALSE;
  }
}

BOOLEAN MASLOG_FORCONTVAR
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST svar, MLOGBASE_PROCFB2 bbcontvar)
# else
(phi, svar, bbcontvar)
MASSTOR_LIST phi;
MASSTOR_LIST svar;
MLOGBASE_PROCFB2 bbcontvar;
# endif
{
  MASSTOR_LIST op, red, arg, arg1, arg2, lvar, psi, varlist, var;

  if (phi == MASSTOR_SIL) {
    return FALSE;
  }
  MLOGBASE_FORPFOR(phi, &op, &red);
  if (op == MLOGBASE_VERUM || op == MLOGBASE_FALSUM) {
    return FALSE;
  } else if (op == MLOGBASE_NON) {
    MLOGBASE_FORPUNOPA(phi, &arg);
    return MASLOG_FORCONTVAR(arg, svar, bbcontvar);
  } else if (op == MLOGBASE_VEL || op == MLOGBASE_ET) {
    while (red != MASSTOR_SIL) {
      MLOGBASE_FORPARGS(red, &arg, &red);
      if (MASLOG_FORCONTVAR(arg, svar, bbcontvar)) {
        return TRUE;
      }
    }
    return FALSE;
  } else if (op == MLOGBASE_IMP || op == MLOGBASE_REP || op == MLOGBASE_EQUIV || op == MLOGBASE_XOR) {
    MLOGBASE_FORPBINOPA(red, &arg1, &arg2);
    return MASLOG_FORCONTVAR(arg1, svar, bbcontvar) || MASLOG_FORCONTVAR(arg2, svar, bbcontvar);
  } else if (op == MLOGBASE_EXIST || op == MLOGBASE_FORALL) {
    MLOGBASE_FORPQUANTA(red, &lvar, &psi);
    MLOGBASE_FORPLVAR(lvar, &varlist);
    while (varlist != MASSTOR_SIL) {
      MLOGBASE_FORPARGS(varlist, &var, &varlist);
      if (SACLIST_EQUAL(svar, var) == 1) {
        return FALSE;
      }
    }
    return MASLOG_FORCONTVAR(psi, svar, bbcontvar);
  } else if (op == MLOGBASE_TVAR) {
    return SACLIST_EQUAL(svar, var) == 1;
  } else {
    return (*bbcontvar)(phi, var);
  }
}

static MASSTOR_LIST notsymbol
# ifdef __STDC__
(MASSTOR_LIST sym)
# else
(sym)
MASSTOR_LIST sym;
# endif
{
  if (sym == MLOGBASE_VERUM) {
    return MLOGBASE_FALSUM;
  }
  if (sym == MLOGBASE_FALSUM) {
    return MLOGBASE_VERUM;
  }
  if (sym == MLOGBASE_VEL) {
    return MLOGBASE_ET;
  }
  if (sym == MLOGBASE_ET) {
    return MLOGBASE_VEL;
  }
  if (sym == MLOGBASE_EXIST) {
    return MLOGBASE_FORALL;
  }
  if (sym == MLOGBASE_FORALL) {
    return MLOGBASE_EXIST;
  }
  if (sym == MLOGBASE_IMP) {
    return MLOGBASE_REP;
  }
  if (sym == MLOGBASE_REP) {
    return MLOGBASE_IMP;
  }
  if (sym == MLOGBASE_EQUIV) {
    return MLOGBASE_XOR;
  }
  if (sym == MLOGBASE_XOR) {
    return MLOGBASE_EQUIV;
  }
}

static MASSTOR_LIST formkneg
# ifdef __STDC__
(MASSTOR_LIST phi, MASLISPU_PROCF1 bbmkneg)
# else
(phi, bbmkneg)
MASSTOR_LIST phi;
MASLISPU_PROCF1 bbmkneg;
# endif
{
  MASSTOR_LIST op, arg, left, right;

  MLOGBASE_FORPFOR(phi, &op, &arg);
  if (op == MLOGBASE_VERUM) {
    return MLOGBASE_FORMKCNST(MLOGBASE_FALSUM);
  } else if (op == MLOGBASE_FALSUM) {
    return MLOGBASE_FORMKCNST(MLOGBASE_VERUM);
  } else if (op == MLOGBASE_NON) {
    return arg;
  } else if (op == MLOGBASE_VEL || op == MLOGBASE_ET || op == MLOGBASE_IMP || op == MLOGBASE_REP || op == MLOGBASE_TVAR || op == MLOGBASE_EXIST || op == MLOGBASE_FORALL) {
    return MLOGBASE_FORMKUNOP(MLOGBASE_NON, phi);
  } else if (op == MLOGBASE_EQUIV) {
    MLOGBASE_FORPBINOPA(arg, &left, &right);
    return MLOGBASE_FORMKBINOP(MLOGBASE_XOR, left, right);
  } else if (op == MLOGBASE_XOR) {
    MLOGBASE_FORPBINOPA(arg, &left, &right);
    return MLOGBASE_FORMKBINOP(MLOGBASE_EQUIV, left, right);
  } else if (op == MLOGBASE_TVAR) {
    return MLOGBASE_FORMKUNOP(MLOGBASE_NON, phi);
  } else {
    return (*bbmkneg)(phi);
  }
}

void BEGIN_MASLOG()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASLISPU();
    BEGIN_MLOGBASE();
    BEGIN_MASBIOS();
    BEGIN_MASELEM();
    BEGIN_MASERR();
    BEGIN_MASLISPU();
    BEGIN_MASSET();
    BEGIN_MASSTOR();
    BEGIN_MASSYM2();
    BEGIN_MLOGBASE();
    BEGIN_SACLIST();

  }
}
