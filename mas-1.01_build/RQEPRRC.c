#include "SYSTEM_.h"

#ifndef DEFINITION_ADTOOLS
#include "ADTOOLS.h"
#endif

#ifndef DEFINITION_CGBDSTR
#include "CGBDSTR.h"
#endif

#ifndef DEFINITION_CGBFUNC
#include "CGBFUNC.h"
#endif

#ifndef DEFINITION_CGBMISC
#include "CGBMISC.h"
#endif

#ifndef DEFINITION_CGBMAIN
#include "CGBMAIN.h"
#endif

#ifndef DEFINITION_DIPADOM
#include "DIPADOM.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPDIM
#include "DIPDIM.h"
#endif

#ifndef DEFINITION_DIPRF
#include "DIPRF.h"
#endif

#ifndef DEFINITION_DIPTOOLS
#include "DIPTOOLS.h"
#endif

#ifndef DEFINITION_LINALG
#include "LINALG.h"
#endif

#ifndef DEFINITION_LISTTOOLS
#include "LISTTOOLS.h"
#endif

#ifndef DEFINITION_MASADOM
#include "MASADOM.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_MASCOMB
#include "MASCOMB.h"
#endif

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#ifndef DEFINITION_MASERR
#include "MASERR.h"
#endif

#ifndef DEFINITION_MASLOG
#include "MASLOG.h"
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

#ifndef DEFINITION_PQBASE
#include "PQBASE.h"
#endif

#ifndef DEFINITION_RRADOM
#include "RRADOM.h"
#endif

#ifndef DEFINITION_SACCOMB
#include "SACCOMB.h"
#endif

#ifndef DEFINITION_SACIPOL
#include "SACIPOL.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_SYSINFO
#include "SYSINFO.h"
#endif

#ifndef DEFINITION_TFORM
#include "TFORM.h"
#endif

#ifndef DEFINITION_RQEPRRC
#include "RQEPRRC.h"
#endif

CHAR RQEPRRC_rcsid [] = "$Id: RQEPRRC.md,v 1.1 1994/11/28 21:10:05 dolzmann Exp $";
CHAR RQEPRRC_copyright [] = "Copyright (c) 1994 Universitaet Passau";
RQEPRRC_RQEOPTIONS RQEPRRC_RqeOpt;
struct RQEPRRC_2 RQEPRRC_PolFmt;

static CHAR rcsidi [] = "$Id: RQEPRRC.mi,v 1.3 1996/05/19 07:54:56 dolzmann Exp $";
static CHAR copyrighti [] = "Copyright (c) 1994 Universitaet Passau";
static MASSTOR_LIST PolFmtStack;
static BOOLEAN RqeIterate;
static BOOLEAN AdjoinedEq;
static MASSTOR_LIST RqeExists ARGS((MASSTOR_LIST phi, MASSTOR_LIST bvlist));
static MASSTOR_LIST RqeConjunction ARGS((MASSTOR_LIST phi, MASSTOR_LIST psi, MASSTOR_LIST bvlist));
static MASSTOR_LIST RqeBranch ARGS((MASSTOR_LIST Cond, MASSTOR_LIST Plist, MASSTOR_LIST Gre, MASSTOR_LIST Neq, MASSTOR_LIST CPols));
static MASSTOR_LIST RQEPRRC ARGS((MASSTOR_LIST G, MASSTOR_LIST F, MASSTOR_LIST NQ));
static MASSTOR_LIST CharPolQ1 ARGS((MASSTOR_LIST G, MASSTOR_LIST R, MASSTOR_LIST U, MASSTOR_LIST beta));
static MASSTOR_LIST PiChi ARGS((MASSTOR_LIST F, MASSTOR_LIST N, MASSTOR_LIST G, MASSTOR_LIST R, MASSTOR_LIST U, MASSTOR_LIST beta));
static MASSTOR_LIST ChiQf ARGS((MASSTOR_LIST f, MASSTOR_LIST D, MASSTOR_LIST R, MASSTOR_LIST U, MASSTOR_LIST beta, MASSTOR_LIST *L));
static void NextProduct ARGS((MASSTOR_LIST F, MASSTOR_LIST *last, MASSTOR_LIST *PF));
static MASSTOR_LIST TfEvalVars ARGS((MASSTOR_LIST phi, MASSTOR_LIST C_188_A));
static MASSTOR_LIST tfevaf ARGS((MASSTOR_LIST phi, MASSTOR_LIST C_187_A));
static MASSTOR_LIST RqeNoEq ARGS((MASSTOR_LIST phi, MASSTOR_LIST bvlist));
static MASSTOR_LIST RqeNonTriviality ARGS((MASSTOR_LIST N, MASSTOR_LIST var));
static MASSTOR_LIST RqeDerivationCondition ARGS((MASSTOR_LIST G, MASSTOR_LIST phi, MASSTOR_LIST var, MASSTOR_LIST psi));
static MASSTOR_LIST RqeDifferenceCondition ARGS((MASSTOR_LIST G, MASSTOR_LIST phi, MASSTOR_LIST var, MASSTOR_LIST psi));
static MASSTOR_LIST RqeLimitCondition ARGS((MASSTOR_LIST G, MASSTOR_LIST var));
static MASSTOR_LIST RqeLimP ARGS((MASSTOR_LIST p));
static MASSTOR_LIST RqeLimN ARGS((MASSTOR_LIST p));
static MASSTOR_LIST cgbinput1 ARGS((MASSTOR_LIST P, MASSTOR_LIST V, MASSTOR_LIST D, MASSTOR_LIST Cond));
static MASSTOR_LIST CondFC ARGS((MASSTOR_LIST C));
static MASSTOR_LIST DIMISS ARGS((MASSTOR_LIST PL, MASSTOR_LIST VL, MASSTOR_LIST *SMAXVL));
static MASSTOR_LIST CondUnion ARGS((MASSTOR_LIST c1, MASSTOR_LIST c2));
static MASSTOR_LIST ParamPol2CommonPol ARGS((MASSTOR_LIST p, MASSTOR_LIST Uvlist, MASSTOR_LIST Xvlist, MASSTOR_LIST iperm));
static MASSTOR_LIST ParamPol2CommonPolL ARGS((MASSTOR_LIST P, MASSTOR_LIST Uvlist, MASSTOR_LIST Xvlist, MASSTOR_LIST iperm));
static MASSTOR_LIST RecPol2CommonPol ARGS((MASSTOR_LIST p, MASSTOR_LIST Uvlist, MASSTOR_LIST Xvlist, MASSTOR_LIST iperm));
static MASSTOR_LIST RecPol2CommonPolL ARGS((MASSTOR_LIST P, MASSTOR_LIST Uvlist, MASSTOR_LIST Xvlist, MASSTOR_LIST iperm));
static MASSTOR_LIST CommonPol2RecPol ARGS((MASSTOR_LIST p, MASSTOR_LIST Uvlist, MASSTOR_LIST Xvlist, MASSTOR_LIST valis, MASSTOR_LIST *perm));
static MASSTOR_LIST CommonPol2RecPolL ARGS((MASSTOR_LIST P, MASSTOR_LIST Uvlist, MASSTOR_LIST Xvlist, MASSTOR_LIST valis, MASSTOR_LIST *perm));
static MASSTOR_LIST CommonPol2ParamPol ARGS((MASSTOR_LIST p, MASSTOR_LIST Uvlist, MASSTOR_LIST Xvlist, MASSTOR_LIST valis, MASSTOR_LIST *perm));
static MASSTOR_LIST CommonPol2ParamPolL ARGS((MASSTOR_LIST P, MASSTOR_LIST Uvlist, MASSTOR_LIST Xvlist, MASSTOR_LIST valis, MASSTOR_LIST *perm));
static MASSTOR_LIST PqFC ARGS((MASSTOR_LIST C));
static MASSTOR_LIST PQFDIL ARGS((MASSTOR_LIST dil, MASSTOR_LIST pqop, MASSTOR_LIST op));
static MASSTOR_LIST forfdata ARGS((MASSTOR_LIST Cond, MASSTOR_LIST Plist, MASSTOR_LIST Gre, MASSTOR_LIST Neq));
static MASSTOR_LIST PqFCond ARGS((MASSTOR_LIST Cond));
static MASSTOR_LIST ExtractPolynomials ARGS((MASSTOR_LIST phi, MASSTOR_LIST bvlist, MASSTOR_LIST valis));
static MASSTOR_LIST RQERSNF ARGS((MASSTOR_LIST phi, MASSTOR_LIST bvlist, MASSTOR_LIST valis));
static MASSTOR_LIST RelSymNf ARGS((MASSTOR_LIST phi, MASSTOR_LIST bvv));
static MASSTOR_LIST exvlist ARGS((MASSTOR_LIST vlist1, MASSTOR_LIST vlist2));
static MASSTOR_LIST nontrivial ARGS((MASSTOR_LIST p, MASSTOR_LIST bvlist, MASSTOR_LIST allvars));
static void RqeOptInit ARGS(());
static void PolFmtInit ARGS(());
static void PolFmtPush ARGS((MASSTOR_LIST vars, MASSTOR_LIST bvlist, MASSTOR_LIST fvlist, MASSTOR_LIST perm));
static void PolFmtPop ARGS(());


MASSTOR_LIST RQEPRRC_RQEQE
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  MASSTOR_LIST psi;
  MASSTOR_LIST qf, vars, bvlist;
  MASSTOR_LIST quantifiers, bvariables;
  SYSINFO_SYSINFO s;

  SYSINFO_SysInfoStart(&s);
  if (phi == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  psi = PQBASE_PQSIMPLIFY(MASLOG_FORMKPRENEXI(PQBASE_PQMKPOS(PQBASE_PQELIMXOPS(PQBASE_PQSMPL(phi))), MLOGBASE_EXIST));
  if (RQEPRRC_RqeOpt.TraceLevel > 0) {
    if (RQEPRRC_RqeOpt.TraceLevel > 2) {
      MASBIOS_SWRITE("Input in prenex normal form", 27L);
      MASBIOS_BLINES(0);
      PQBASE_PQPPRT(psi);
    }
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("[", 1L);
  }
  qf = MLOGBASE_FORGOP(psi);
  quantifiers = MASSTOR_SIL;
  bvariables = MASSTOR_SIL;
  while (qf == MLOGBASE_EXIST || qf == MLOGBASE_FORALL) {
    MLOGBASE_FORPQUANT(psi, &qf, &vars, &psi);
    quantifiers = MASSTOR_COMP(qf, quantifiers);
    bvariables = MASSTOR_COMP(vars, bvariables);
    qf = MLOGBASE_FORGOP(psi);
  }
  if (RQEPRRC_RqeOpt.TraceLevel > 0) {
    if (RQEPRRC_RqeOpt.TraceLevel > 1) {
      MASBIOS_SWRITE("Number of quantifier blocks: ", 29L);
      MASSYM2_UWRITE(MASSTOR_LENGTH(quantifiers));
    } else {
      MASBIOS_SWRITE(" QB=", 4L);
      MASSYM2_UWRIT1(MASSTOR_LENGTH(quantifiers));
      MASBIOS_SWRITE(" ", 1L);
    }
  }
  RqeIterate = TRUE;
  while (quantifiers != MASSTOR_SIL && psi != MLOGBASE_VERUM && psi != MLOGBASE_FALSUM && RqeIterate) {
    MASSTOR_ADV(quantifiers, &qf, &quantifiers);
    MASSTOR_ADV(bvariables, &vars, &bvariables);
    bvlist = PQBASE_vlistflvar(vars);
    if (RQEPRRC_RqeOpt.TraceLevel > 0) {
      if (RQEPRRC_RqeOpt.TraceLevel > 1) {
        MASBIOS_SWRITE("Elimination of an ", 18L);
        MASSYM2_UWRIT1(qf);
        MASBIOS_SWRITE(" quantifier", 11L);
        MASBIOS_BLINES(0);
        MASBIOS_SWRITE("bound Variables", 15L);
        SACPOL_VLWRIT(bvlist);
        MASBIOS_BLINES(0);
      } else {
        MASBIOS_SWRITE(" QB ", 4L);
      }
    }
    if (qf == MLOGBASE_FORALL) {
      psi = PQBASE_PQMKPOS(MLOGBASE_FORMKUNOP(MLOGBASE_NON, psi));
    }
    psi = PQBASE_PQSIMPLIFY(RqeExists(psi, bvlist));
    if (qf == MLOGBASE_FORALL) {
      psi = PQBASE_PQMKPOS(MLOGBASE_FORMKUNOP(MLOGBASE_NON, psi));
    }
    if (RQEPRRC_RqeOpt.TraceLevel > 2) {
      MASBIOS_SWRITE("Result of the elimination:", 26L);
      MASBIOS_BLINES(0);
      PQBASE_PQPPRT(psi);
      MASBIOS_BLINES(0);
    }
  }
  if (!RqeIterate) {
    while (quantifiers != MASSTOR_SIL) {
      MASSTOR_ADV(quantifiers, &qf, &quantifiers);
      MASSTOR_ADV(bvariables, &vars, &bvariables);
      psi = MLOGBASE_FORMKQUANT(qf, vars, psi);
    }
  }
  SYSINFO_SysInfoStop(&s);
  if (RQEPRRC_RqeOpt.TraceLevel > 0) {
    if (RQEPRRC_RqeOpt.TraceLevel > 1) {
      SYSINFO_SysInfoWrite(s);
    }
    MASBIOS_SWRITE("]", 1L);
    MASBIOS_BLINES(0);
  }
  return psi;
}

static MASSTOR_LIST RqeExists
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST bvlist)
# else
(phi, bvlist)
MASSTOR_LIST phi, bvlist;
# endif
{
  MASSTOR_LIST psi, result, conj, InterRes;

  psi = PQBASE_PQMKDNF(RQERSNF(phi, bvlist, DIPC_VALIS));
  psi = MLOGBASE_FORGARGS(psi);
  if (RQEPRRC_RqeOpt.TraceLevel > 0) {
    if (RQEPRRC_RqeOpt.TraceLevel > 1) {
      MASBIOS_SWRITE("Number of arguments of the disjunction:", 39L);
      MASSYM2_UWRITE(MASSTOR_LENGTH(psi));
    } else {
      MASBIOS_SWRITE("CS=", 3L);
      MASSYM2_UWRIT1(MASSTOR_LENGTH(psi));
      MASBIOS_SWRITE(" ", 1L);
    }
  }
  result = MASSTOR_SIL;
  while (psi != MASSTOR_SIL) {
    MASSTOR_ADV(psi, &conj, &psi);
    if (RQEPRRC_RqeOpt.TraceLevel > 0) {
      if (RQEPRRC_RqeOpt.TraceLevel > 1) {
        MASBIOS_SWRITE("Eliminating one conjunction.", 28L);
        MASBIOS_BLINES(0);
        if (RQEPRRC_RqeOpt.TraceLevel > 2) {
          PQBASE_PQPPRT(conj);
          MASBIOS_BLINES(0);
        }
      } else {
        MASBIOS_SWRITE(" CS ", 4L);
      }
    }
    InterRes = RqeConjunction(conj, MLOGBASE_VERUM, bvlist);
    if (InterRes == MLOGBASE_VERUM) {
      return MLOGBASE_VERUM;
    }
    result = MASSTOR_COMP(InterRes, result);
  }
  return MLOGBASE_FORMKFOR(MLOGBASE_VEL, MASSTOR_INV(result));
}

static MASSTOR_LIST RqeConjunction
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST psi, MASSTOR_LIST bvlist)
# else
(phi, psi, bvlist)
MASSTOR_LIST phi, psi, bvlist;
# endif
{
  MASSTOR_LIST E, G, N, fvlist, perm, newdd, result, qff, p;
  MASSTOR_LIST gsys, S, VD, CD, Cond, Plist, CP;
  MASSTOR_LIST pols, pols2, NC;
  MASSTOR_LIST Initial;
  SYSINFO_SYSINFO s;

  if (psi == MLOGBASE_FALSUM) {
    return MLOGBASE_FALSUM;
  }
  pols = ExtractPolynomials(phi, bvlist, DIPC_VALIS);
  NC = MASSTOR_FIRST(pols);
  MASSTOR_ADV(NC, &E, &NC);
  MASSTOR_ADV(NC, &G, &NC);
  MASSTOR_ADV(NC, &N, &NC);
  if (E == MASSTOR_SIL && G == MASSTOR_SIL && N == MASSTOR_SIL) {
    return phi;
  } else if (E == MASSTOR_SIL && G == MASSTOR_SIL) {
    result = MASSTOR_SIL;
    while (N != MASSTOR_SIL) {
      MASSTOR_ADV(N, &p, &N);
      result = MASSTOR_COMP(nontrivial(p, bvlist, DIPC_VALIS), result);
    }
    result = MLOGBASE_FORMKFOR(MLOGBASE_ET, MASSTOR_INV(result));
    result = MLOGBASE_FORMKBINOP(MLOGBASE_ET, result, PqFC(SACLIST_SECOND(pols)));
    return result;
  } else if (E == MASSTOR_SIL) {
    if (RQEPRRC_RqeOpt.DimensionZeroOnly) {
      RqeIterate = FALSE;
      return MLOGBASE_FORMKQUANT(MLOGBASE_EXIST, PQBASE_lvarfvlist(bvlist), phi);
    } else {
      return RqeNoEq(phi, bvlist);
    }
  }
  fvlist = MASSET_SetComplementQ(bvlist, DIPC_VALIS);
  newdd = ADTOOLS_IPDDCMP(fvlist);
  E = CommonPol2RecPolL(E, fvlist, bvlist, DIPC_VALIS, &perm);
  PolFmtPush(DIPC_VALIS, bvlist, fvlist, perm);
  Initial = CondFC(SACLIST_SECOND(pols));
  if (psi != MLOGBASE_VERUM) {
    pols2 = ExtractPolynomials(psi, bvlist, DIPC_VALIS);
    Initial = CondUnion(Initial, CondFC(SACLIST_SECOND(pols2)));
  }
  if (RQEPRRC_RqeOpt.TraceLevel > 1) {
    MASBIOS_SWRITE("Computing a reduced Groebner system ...", 39L);
    SYSINFO_SysInfoStart(&s);
    MASBIOS_BLINES(0);
  }
  gsys = CGBMAIN_GSYSRED(CGBMAIN_GSYS(cgbinput1(E, bvlist, newdd, Initial)));
  if (RQEPRRC_RqeOpt.TraceLevel > 1) {
    SYSINFO_SysInfoStop(&s);
    MASBIOS_SWRITE(" finished.", 10L);
    MASBIOS_BLINES(0);
    SYSINFO_SysInfoWrite(s);
  }
  CGBDSTR_GsParts(gsys, &S, &VD, &CD);
  if (RQEPRRC_RqeOpt.TraceLevel > 0) {
    if (RQEPRRC_RqeOpt.TraceLevel > 1) {
      MASBIOS_SWRITE("Number of cases in the Groebner system: ", 40L);
      MASSYM2_UWRITE(MASSTOR_LENGTH(S));
    } else {
      MASBIOS_SWRITE(" B=", 3L);
      MASSYM2_UWRIT1(MASSTOR_LENGTH(S));
      MASBIOS_SWRITE(" ", 1L);
    }
  }
  result = MASSTOR_SIL;
  qff = MLOGBASE_FALSUM;
  while (S != MASSTOR_SIL && qff != MLOGBASE_VERUM) {
    MASSTOR_ADV(S, &CP, &S);
    SACLIST_FIRST2(CP, &Cond, &Plist);
    Plist = CGBFUNC_GREPOL(Plist);
    if (RQEPRRC_RqeOpt.TraceLevel > 0) {
      if (RQEPRRC_RqeOpt.TraceLevel > 1) {
        MASBIOS_SWRITE("Handle one case of the Groebner system.", 39L);
        MASBIOS_BLINES(0);
        if (RQEPRRC_RqeOpt.TraceLevel > 2) {
          CGBDSTR_CondWrite(Cond);
        }
      } else {
        MASBIOS_SWRITE(" B ", 3L);
      }
    }
    qff = PQBASE_PQSIMPLIFY(RqeBranch(Cond, Plist, G, N, SACLIST_SECOND(pols)));
    result = MASSTOR_COMP(PQBASE_PQSIMPLIFY(qff), result);
  }
  if (qff != MLOGBASE_VERUM) {
    result = MLOGBASE_FORMKFOR(MLOGBASE_VEL, MASSTOR_INV(result));
    result = MLOGBASE_FORMKBINOP(MLOGBASE_ET, PqFC(SACLIST_SECOND(pols)), result);
  } else {
    result = PqFC(SACLIST_SECOND(pols));
  }
  PolFmtPop();
  return PQBASE_PQSIMPLIFYP(result, 2);
}

static MASSTOR_LIST RqeBranch
# ifdef __STDC__
(MASSTOR_LIST Cond, MASSTOR_LIST Plist, MASSTOR_LIST Gre, MASSTOR_LIST Neq, MASSTOR_LIST CPols)
# else
(Cond, Plist, Gre, Neq, CPols)
MASSTOR_LIST Cond, Plist, Gre, Neq, CPols;
# endif
{
  MASSTOR_LIST d, n, Smaxvl, newdd, D, res, perm, dep, indep;

  DIPTOOLS_ValisPush(RQEPRRC_PolFmt.BoundVars);
  d = DIMISS(Plist, RQEPRRC_PolFmt.BoundVars, &Smaxvl);
  n = MASSTOR_LENGTH(DIPC_VALIS);
  if (RQEPRRC_RqeOpt.TraceLevel > 1) {
    MASBIOS_SWRITE("Dimension of the ideal = ", 25L);
    MASSYM2_UWRITE(d);
  }
  if (d == 0) {
    {
      register struct RQEPRRC_2 *W_1 = &RQEPRRC_PolFmt;

      DIPTOOLS_ValisPush(W_1->AllVars);
      Gre = CommonPol2RecPolL(Gre, W_1->FreeVars, W_1->BoundVars, DIPC_VALIS, &perm);
      Neq = CommonPol2RecPolL(Neq, W_1->FreeVars, W_1->BoundVars, DIPC_VALIS, &perm);
      DIPTOOLS_ValisPop();
    }
    D = DIPTOOLS_ADDDFDIL(Plist);
    if (RQEPRRC_RqeOpt.TraceLevel > 2) {
      MASBIOS_BLINES(0);
      MASBIOS_SWRITE("Groebner Basis:", 15L);
      DIPADOM_DILWR(Plist, RQEPRRC_PolFmt.BoundVars);
      MASBIOS_BLINES(0);
      MASBIOS_SWRITE("Side conditions '>':", 20L);
      DIPADOM_DILWR(Gre, RQEPRRC_PolFmt.BoundVars);
      MASBIOS_BLINES(0);
      MASBIOS_SWRITE("Side conditions '<>':", 21L);
      DIPADOM_DILWR(Neq, RQEPRRC_PolFmt.BoundVars);
    }
    Plist = DIPTOOLS_DILCONV(Plist, ADTOOLS_RFDDFIPDD(D));
    Gre = DIPTOOLS_DILCONV(Gre, ADTOOLS_RFDDFIPDD(D));
    Neq = DIPTOOLS_DILCONV(Neq, ADTOOLS_RFDDFIPDD(D));
    res = RQEPRRC(Plist, Gre, Neq);
    if (!CGBDSTR_CondIsEmpty(Cond)) {
      res = MLOGBASE_FORMKBINOP(MLOGBASE_ET, PqFCond(Cond), res);
    }
  } else if (d > 0 && d < n && RQEPRRC_RqeOpt.DimensionZeroOnly) {
    DIPTOOLS_ValisPush(RQEPRRC_PolFmt.AllVars);
    res = forfdata(Cond, Plist, Gre, Neq);
    res = MLOGBASE_FORMKBINOP(MLOGBASE_ET, res, PqFC(CPols));
    res = MLOGBASE_FORMKQUANT(MLOGBASE_EXIST, PQBASE_lvarfvlist(RQEPRRC_PolFmt.BoundVars), res);
    DIPTOOLS_ValisPop();
    RqeIterate = FALSE;
  } else if (d > 0 && d < n) {
    res = forfdata(Cond, Plist, Gre, Neq);
    res = MLOGBASE_FORMKBINOP(MLOGBASE_ET, res, PqFC(CPols));
    indep = MASSTOR_FIRST(Smaxvl);
    dep = MASSET_SetComplementQ(indep, RQEPRRC_PolFmt.BoundVars);
    res = MLOGBASE_FORMKQUANT(MLOGBASE_EXIST, PQBASE_lvarfvlist(dep), res);
    if (RQEPRRC_RqeOpt.TraceLevel >= 2) {
      MASBIOS_SWRITE("first recursive call of RQEQE in the case 0 < d < n", 51L);
      MASBIOS_BLINES(0);
      MASBIOS_SWRITE("eliminating the variables: ", 27L);
      MASBIOS_BLINES(0);
      SACPOL_VLWRIT(dep);
      MASBIOS_BLINES(0);
      MASBIOS_SWRITE("in the formula", 14L);
      MASBIOS_BLINES(0);
      DIPTOOLS_ValisPush(RQEPRRC_PolFmt.AllVars);
      PQBASE_PQPPRT(res);
      MASBIOS_BLINES(0);
      DIPTOOLS_ValisPop();
    }
    DIPTOOLS_ValisPush(RQEPRRC_PolFmt.AllVars);
    res = RQEPRRC_RQEQE(res);
    DIPTOOLS_ValisPop();
    res = MLOGBASE_FORMKQUANT(MLOGBASE_EXIST, PQBASE_lvarfvlist(indep), res);
    if (RQEPRRC_RqeOpt.TraceLevel >= 2) {
      MASBIOS_SWRITE("second recursive call of RQEQE in the case 0 < d < n", 52L);
      MASBIOS_BLINES(0);
      MASBIOS_SWRITE("eliminating the variables: ", 27L);
      MASBIOS_BLINES(0);
      SACPOL_VLWRIT(indep);
      MASBIOS_BLINES(0);
      MASBIOS_SWRITE("in the formula", 14L);
      MASBIOS_BLINES(0);
      DIPTOOLS_ValisPush(RQEPRRC_PolFmt.AllVars);
      PQBASE_PQPPRT(res);
      MASBIOS_BLINES(0);
      DIPTOOLS_ValisPop();
    }
    DIPTOOLS_ValisPush(RQEPRRC_PolFmt.AllVars);
    res = RQEPRRC_RQEQE(res);
    DIPTOOLS_ValisPop();
  } else if (d == n && RQEPRRC_RqeOpt.DimensionZeroOnly) {
    DIPTOOLS_ValisPush(RQEPRRC_PolFmt.AllVars);
    res = forfdata(Cond, Plist, Gre, Neq);
    res = MLOGBASE_FORMKBINOP(MLOGBASE_ET, res, PqFC(CPols));
    res = MLOGBASE_FORMKQUANT(MLOGBASE_EXIST, PQBASE_lvarfvlist(RQEPRRC_PolFmt.BoundVars), res);
    DIPTOOLS_ValisPop();
    RqeIterate = FALSE;
  } else if (d == n) {
    res = forfdata(Cond, MASSTOR_SIL, Gre, Neq);
    res = MLOGBASE_FORMKBINOP(MLOGBASE_ET, res, PqFC(CPols));
    res = MLOGBASE_FORMKQUANT(MLOGBASE_EXIST, PQBASE_lvarfvlist(RQEPRRC_PolFmt.BoundVars), res);
    DIPTOOLS_ValisPush(RQEPRRC_PolFmt.AllVars);
    res = RQEPRRC_RQEQE(res);
    DIPTOOLS_ValisPop();
  } else if (d == -1) {
    res = MLOGBASE_FALSUM;
  } else {
    MASERR_ERROR(MASERR_severe, "RqeBranch: incorrect dimension -1>d or d>n.", 43L);
    res = MLOGBASE_FALSUM;
  }
  DIPTOOLS_ValisPop();
  return res;
}

static MASSTOR_LIST RQEPRRC
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST F, MASSTOR_LIST NQ)
# else
(G, F, NQ)
MASSTOR_LIST G, F, NQ;
# endif
{
  MASSTOR_LIST R, E, U, Q, beta, s;
  MASSTOR_LIST D;
  MASSTOR_LIST prod;
  MASSTOR_LIST tf, ct, deg, i, ctp, c;
  MASSTOR_LIST result;
  SYSINFO_SYSINFO TotalS, sysinfo;

  SYSINFO_SysInfoStart(&TotalS);
  G = DIPC_DIPLPM(DIPTOOLS_DILMOC(G));
  D = DIPTOOLS_ADDDFDIL(G);
  R = RRADOM_RRREDTERMS(G);
  E = LINALG_ADUM(D, MASSTOR_LENGTH(R));
  RRADOM_RRADSTRCONST(D, G, R, &U, &beta);
  Q = RRADOM_RRADQUADFORM(D, R, U, beta, E);
  SYSINFO_SysInfoStart(&sysinfo);
  if (F != MASSTOR_SIL || NQ != MASSTOR_SIL) {
    prod = PiChi(F, NQ, G, R, U, beta);
  } else {
    prod = CharPolQ1(G, R, U, beta);
  }
  SYSINFO_SysInfoStop(&sysinfo);
  if (RQEPRRC_RqeOpt.TraceLevel >= 2) {
    MASBIOS_SWRITE("Time for computation of characteristic polynomial: ", 51L);
    MASBIOS_BLINES(0);
    SYSINFO_SysInfoWrite(sysinfo);
  }
  ct = DIPTOOLS_DIPCT(prod);
  deg = MASSTOR_LENGTH(ct) - 1;
  if (RQEPRRC_RqeOpt.TraceLevel > 2) {
    i = 0;
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("Type formula to compute: T", 26L);
    MASSYM2_UWRIT1(deg);
    MASBIOS_SWRITE("(c), where", 10L);
    MASBIOS_BLINES(0);
    ctp = ct;
    while (ctp != MASSTOR_SIL) {
      MASSTOR_ADV(ctp, &c, &ctp);
      MASBIOS_SWRITE("c", 1L);
      SACLIST_AWRITE(i);
      MASBIOS_SWRITE(" = ", 3L);
      MASBIOS_SWRITE("  ", 2L);
      MASADOM_ADWRIT(c);
      MASBIOS_BLINES(0);
      i = i + 1;
    }
  }
  SYSINFO_SysInfoStart(&sysinfo);
  tf = TFORM_TfTypeFormula(deg);
  SYSINFO_SysInfoStop(&sysinfo);
  if (RQEPRRC_RqeOpt.TraceLevel >= 2) {
    MASBIOS_SWRITE("Time for computing type formula: ", 33L);
    MASBIOS_BLINES(0);
    SYSINFO_SysInfoWrite(sysinfo);
  }
  result = MLOGBASE_FORMKUNOP(MLOGBASE_NON, TfEvalVars(tf, ct));
  SYSINFO_SysInfoStop(&TotalS);
  if (RQEPRRC_RqeOpt.TraceLevel >= 2) {
    MASBIOS_SWRITE("Time for real root count: ", 26L);
    MASBIOS_BLINES(0);
    SYSINFO_SysInfoWrite(TotalS);
  }
  return result;
}

static MASSTOR_LIST CharPolQ1
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST R, MASSTOR_LIST U, MASSTOR_LIST beta)
# else
(G, R, U, beta)
MASSTOR_LIST G, R, U, beta;
# endif
{
  MASSTOR_LIST D, L, CVL, chiq1;
  SYSINFO_SYSINFO s;

  CVL = MASSTOR_LIST1(MASBIOS_LISTS("Y", 1L));
  D = DIPTOOLS_ADDDFDIL(G);
  L = RRADOM_RRADVARMATRICES(G, R, U, beta);
  chiq1 = ChiQf(DIPTOOLS_DIPONE(D), D, R, U, beta, &L);
  return chiq1;
}

static MASSTOR_LIST PiChi
# ifdef __STDC__
(MASSTOR_LIST F, MASSTOR_LIST N, MASSTOR_LIST G, MASSTOR_LIST R, MASSTOR_LIST U, MASSTOR_LIST beta)
# else
(F, N, G, R, U, beta)
MASSTOR_LIST F, N, G, R, U, beta;
# endif
{
  MASSTOR_LIST D, FC, CVL, L, chiqf, f, ev, ChiProd, FProd, i;
  SYSINFO_SYSINFO s, TotalS;

  if (F == MASSTOR_SIL && N == MASSTOR_SIL) {
    return CharPolQ1(G, R, U, beta);
  }
  if (F != MASSTOR_SIL) {
    D = DIPTOOLS_ADDDFDIL(F);
  }
  if (F == MASSTOR_SIL || D == 0) {
    D = DIPTOOLS_ADDDFDIL(N);
  }
  if (D == 0) {
    MASERR_ERROR(MASERR_severe, "ChiQf: Cannot determine domain descriptor!", 42L);
    return MASSTOR_SIL;
  }
  CVL = MASSTOR_LIST1(MASBIOS_LISTS("Y", 1L));
  L = RRADOM_RRADVARMATRICES(G, R, U, beta);
  FProd = DIPTOOLS_DIPONE(D);
  DIPTOOLS_ValisPush(CVL);
  ChiProd = DIPTOOLS_DIPONE(D);
  DIPTOOLS_ValisPop();
  FC = F;
  while (FC != MASSTOR_SIL) {
    MASSTOR_ADV(FC, &f, &FC);
    FProd = DIPADOM_DIPROD(FProd, f);
  }
  FC = N;
  while (FC != MASSTOR_SIL) {
    MASSTOR_ADV(FC, &f, &FC);
    FProd = DIPADOM_DIPROD(FProd, DIPADOM_DIPROD(f, f));
  }
  if (F == MASSTOR_SIL) {
    chiqf = ChiQf(FProd, D, R, U, beta, &L);
    return chiqf;
  }
  ev = MASSTOR_SIL;
  {
    LONGINT B_1 = 1, B_2 = MASSTOR_LENGTH(F);

    if (B_1 <= B_2)
      for (i = B_1;; i += 1) {
        ev = MASSTOR_COMP(0, ev);
        if (i >= B_2) break;
      }
  }
  do {
    NextProduct(F, &ev, &f);
    f = DIPADOM_DIPROD(f, FProd);
    chiqf = ChiQf(f, D, R, U, beta, &L);
    DIPTOOLS_ValisPush(CVL);
    ChiProd = DIPADOM_DIPROD(ChiProd, chiqf);
    DIPTOOLS_ValisPop();
  } while (!(ev == MASSTOR_SIL));
  return ChiProd;
}

static MASSTOR_LIST ChiQf
# ifdef __STDC__
(MASSTOR_LIST f, MASSTOR_LIST D, MASSTOR_LIST R, MASSTOR_LIST U, MASSTOR_LIST beta, MASSTOR_LIST *L)
# else
(f, D, R, U, beta, L)
MASSTOR_LIST f, D, R, U, beta;
MASSTOR_LIST *L;
# endif
{
  MASSTOR_LIST Q, Mf;
  MASSTOR_LIST ChiCoeff, Chi, Coeff, zero;
  MASSTOR_LIST i;
  SYSINFO_SYSINFO s, t;

  RRADOM_RRADPOLMATRIX(D, R, f, &Mf, L);
  Q = RRADOM_RRADQUADFORM(D, R, U, beta, Mf);
  ChiCoeff = MASSTOR_INV(LINALG_ADCHARPOL(D, Q));
  Chi = MASSTOR_SIL;
  i = 0;
  zero = MASADOM_ADFI(D, 0);
  while (ChiCoeff != MASSTOR_SIL) {
    MASSTOR_ADV(ChiCoeff, &Coeff, &ChiCoeff);
    if (SACLIST_EQUAL(Coeff, zero) == 0) {
      Chi = DIPC_DIPMCP(Coeff, MASSTOR_LIST1(i), Chi);
    }
    i = i + 1;
  }
  return Chi;
}

static void NextProduct
# ifdef __STDC__
(MASSTOR_LIST F, MASSTOR_LIST *last, MASSTOR_LIST *PF)
# else
(F, last, PF)
MASSTOR_LIST F;
MASSTOR_LIST *last, *PF;
# endif
{
  MASSTOR_LIST lp, lpp, e, f;

  if (*last == MASSTOR_SIL) {
    *last = MASSTOR_SIL;
    return;
  }
  *PF = DIPTOOLS_DIPONE(DIPTOOLS_ADDDFDIL(F));
  lp = *last;
  do {
    MASSTOR_ADV(lp, &e, &lpp);
    MASSTOR_ADV(F, &f, &F);
    if (e == 0) {
      MASSTOR_SFIRST(lp, 1);
    } else if (e == 1) {
      MASSTOR_SFIRST(lp, 0);
      *PF = DIPADOM_DIPROD(*PF, f);
    } else {
      MASERR_ERROR(MASERR_severe, "NextProduct: incorrect exponent.", 32L);
    }
    lp = lpp;
  } while (!(lp == MASSTOR_SIL || e == 0));
  if (lp == MASSTOR_SIL && e == 1) {
    *last = MASSTOR_SIL;
    return;
  }
  while (lp != MASSTOR_SIL) {
    MASSTOR_ADV(lp, &e, &lp);
    MASSTOR_ADV(F, &f, &F);
    if (e == 1) {
      *PF = DIPADOM_DIPROD(*PF, f);
    }
  }
  return;
}

static MASSTOR_LIST TfEvalVars
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST C_188_A)
# else
(phi, C_188_A)
MASSTOR_LIST phi, C_188_A;
# endif
{
  SYSINFO_SYSINFO s;

  SYSINFO_SysInfoStart(&s);
  return MASLOG_FORAPPLYATF2(phi, C_188_A, tfevaf);
  SYSINFO_SysInfoStop(&s);
  if (RQEPRRC_RqeOpt.TraceLevel >= 3) {
    MASBIOS_SWRITE("Time for evaluating type formula: ", 34L);
    MASBIOS_BLINES(0);
    SYSINFO_SysInfoWrite(s);
  }
}

static MASSTOR_LIST tfevaf
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST C_187_A)
# else
(phi, C_187_A)
MASSTOR_LIST phi, C_187_A;
# endif
{
  MASSTOR_LIST rel, idl, id, result, rf;
  MASSTOR_LIST r, p, drf, vl, num, den;
  MASSTOR_LIST lf, lb;

  TFORM_tfpaf(phi, &rel, &idl);
  DIPTOOLS_ValisPush(RQEPRRC_PolFmt.FreeVars);
  result = DIPTOOLS_DIPONE(ADTOOLS_INTDDCMP());
  DIPTOOLS_ValisPop();
  while (idl != MASSTOR_SIL) {
    MASSTOR_ADV(idl, &id, &idl);
    drf = SACLIST_LELT(C_187_A, id + 1);
    ADTOOLS_RFDDADV(drf, &rf, &vl);
    r = DIPRF_RFNOV(rf);
    num = DIPRF_RFNUM(rf);
    den = DIPRF_RFDEN(rf);
    if (rel == PQBASE_EQU || rel == PQBASE_NEQ) {
      p = DIPTOOLS_DIPFIP(num, r);
    } else {
      p = SACIPOL_IPPROD(r, num, den);
      p = DIPTOOLS_DIPFIP(p, r);
    }
    result = DIPADOM_DIPROD(result, p);
  }
  lf = MASSTOR_LENGTH(RQEPRRC_PolFmt.FreeVars);
  lb = MASSTOR_LENGTH(RQEPRRC_PolFmt.BoundVars);
  result = DIPC_DIPINV(result, lf + 1, lb);
  return PQBASE_pqmkaf(rel, DIPC_DIPERM(result, MASCOMB_INVPERM(RQEPRRC_PolFmt.Permutation)));
}

static MASSTOR_LIST RqeNoEq
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST bvlist)
# else
(phi, bvlist)
MASSTOR_LIST phi, bvlist;
# endif
{
  MASSTOR_LIST NC, G, N, pols;
  MASSTOR_LIST result, psi, GreaterCond, NotZero, InterResult;
  MASSTOR_LIST univlist, redlist, op;

  if (AdjoinedEq) {
    return MLOGBASE_FALSUM;
  }
  univlist = MASSTOR_LIST1(MASSTOR_FIRST(bvlist));
  redlist = MASSTOR_RED(bvlist);
  pols = ExtractPolynomials(phi, univlist, DIPC_VALIS);
  NC = MASSTOR_FIRST(pols);
  G = SACLIST_SECOND(NC);
  N = SACLIST_THIRD(NC);
  psi = PQBASE_PQSIMPLIFY(PqFC(SACLIST_SECOND(pols)));
  op = MLOGBASE_FORGOP(psi);
  if (op != MLOGBASE_ET && op != MLOGBASE_VERUM && op != MLOGBASE_FALSUM) {
    psi = MLOGBASE_FORMKUNOP(MLOGBASE_ET, psi);
  }
  if (psi == MLOGBASE_FALSUM) {
    return MLOGBASE_FALSUM;
  }
  NotZero = RqeNonTriviality(N, univlist);
  if (NotZero == MLOGBASE_FALSUM) {
    return MLOGBASE_FALSUM;
  }
  InterResult = RqeLimitCondition(G, univlist);
  if (InterResult == MLOGBASE_VERUM) {
    return psi;
  }
  result = MASSTOR_LIST1(InterResult);
  GreaterCond = PQFDIL(G, PQBASE_GRE, MLOGBASE_ET);
  InterResult = RqeDerivationCondition(G, GreaterCond, univlist, psi);
  if (InterResult == MLOGBASE_VERUM) {
    return MLOGBASE_VERUM;
  }
  result = MASSTOR_COMP(InterResult, result);
  InterResult = RqeDifferenceCondition(G, GreaterCond, univlist, psi);
  if (InterResult == MLOGBASE_VERUM) {
    return MLOGBASE_VERUM;
  }
  result = MASSTOR_COMP(InterResult, result);
  result = MLOGBASE_FORMKFOR(MLOGBASE_VEL, MASSTOR_INV(result));
  result = MLOGBASE_FORMKFOR(MLOGBASE_ET, SACLIST_LIST3(result, psi, NotZero));
  if (redlist != MASSTOR_SIL) {
    result = MLOGBASE_FORMKQUANT(MLOGBASE_EXIST, PQBASE_lvarfvlist(redlist), result);
    result = RQEPRRC_RQEQE(result);
  }
  return result;
}

static MASSTOR_LIST RqeNonTriviality
# ifdef __STDC__
(MASSTOR_LIST N, MASSTOR_LIST var)
# else
(N, var)
MASSTOR_LIST N, var;
# endif
{
  MASSTOR_LIST n, result;

  if (N == MASSTOR_SIL) {
    return MLOGBASE_VERUM;
  }
  result = MASSTOR_SIL;
  do {
    MASSTOR_ADV(N, &n, &N);
    result = MASSTOR_COMP(nontrivial(n, var, DIPC_VALIS), result);
  } while (!(N == MASSTOR_SIL));
  return PQBASE_PQSIMPLIFY(MLOGBASE_FORMKFOR(MLOGBASE_ET, MASSTOR_INV(result)));
}

static MASSTOR_LIST RqeDerivationCondition
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST phi, MASSTOR_LIST var, MASSTOR_LIST psi)
# else
(G, phi, var, psi)
MASSTOR_LIST G, phi, var, psi;
# endif
{
  MASSTOR_LIST VarIndex, g, result, DeriveCond, InterResult;

  if (RQEPRRC_RqeOpt.TraceLevel > 0) {
    if (RQEPRRC_RqeOpt.TraceLevel > 1) {
      MASBIOS_SWRITE("RqeDerivationCondition: maximal ", 32L);
      MASSYM2_UWRIT1(MASSTOR_LENGTH(G));
      MASBIOS_SWRITE(" conjunctions to generate", 25L);
      MASBIOS_BLINES(0);
    } else {
      MASBIOS_SWRITE("(DC=", 4L);
      MASSYM2_UWRITE(MASSTOR_LENGTH(G));
    }
  }
  VarIndex = LISTTOOLS_LSRCHQ(MASSTOR_FIRST(var), DIPC_VALIS);
  result = MASSTOR_SIL;
  while (G != MASSTOR_SIL) {
    MASSTOR_ADV(G, &g, &G);
    if (DIPTOOLS_DIPDEGI(g, VarIndex) >= 2) {
      DeriveCond = PQBASE_pqmkaf(PQBASE_EQU, DIPTOOLS_DIPPAD(g, VarIndex));
      AdjoinedEq = TRUE;
      DeriveCond = MLOGBASE_FORMKFOR(MLOGBASE_ET, MASSTOR_COMP(DeriveCond, MLOGBASE_FORGARGS(phi)));
      InterResult = RqeConjunction(DeriveCond, psi, var);
      AdjoinedEq = FALSE;
      if (InterResult == MLOGBASE_VERUM) {
        return MLOGBASE_VERUM;
      }
      result = MASSTOR_COMP(InterResult, result);
    }
  }
  if (RQEPRRC_RqeOpt.TraceLevel > 0) {
    if (RQEPRRC_RqeOpt.TraceLevel > 1) {
      MASBIOS_SWRITE("RqeDerivationCondition: All conjunctions generated.", 51L);
      MASBIOS_BLINES(0);
    } else {
      MASBIOS_SWRITE(")", 1L);
    }
  }
  if (result == MASSTOR_SIL) {
    return MLOGBASE_FALSUM;
  } else {
    return MLOGBASE_FORMKFOR(MLOGBASE_VEL, MASSTOR_INV(result));
  }
}

static MASSTOR_LIST RqeDifferenceCondition
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST phi, MASSTOR_LIST var, MASSTOR_LIST psi)
# else
(G, phi, var, psi)
MASSTOR_LIST G, phi, var, psi;
# endif
{
  MASSTOR_LIST result, pairs, p, DiffCond, InterResult;

  result = MASSTOR_SIL;
  pairs = LISTTOOLS_LPAIRS(G);
  if (RQEPRRC_RqeOpt.TraceLevel > 1) {
    if (RQEPRRC_RqeOpt.TraceLevel > 1) {
      MASBIOS_SWRITE("RqeDifferenceCondition: ", 24L);
      MASSYM2_UWRIT1(MASSTOR_LENGTH(pairs));
      MASBIOS_SWRITE("  conjunctions to generate.", 27L);
      MASBIOS_BLINES(0);
    }
  }
  while (pairs != MASSTOR_SIL) {
    MASSTOR_ADV(pairs, &p, &pairs);
    DiffCond = PQBASE_pqmkaf(PQBASE_EQU, DIPADOM_DIPSUM(MASSTOR_FIRST(p), DIPADOM_DIPNEG(SACLIST_SECOND(p))));
    DiffCond = MLOGBASE_FORMKFOR(MLOGBASE_ET, MASSTOR_COMP(DiffCond, MLOGBASE_FORGARGS(phi)));
    AdjoinedEq = TRUE;
    InterResult = RqeConjunction(DiffCond, psi, var);
    AdjoinedEq = FALSE;
    if (InterResult == MLOGBASE_VERUM) {
      return MLOGBASE_VERUM;
    }
    result = MASSTOR_COMP(InterResult, result);
  }
  if (RQEPRRC_RqeOpt.TraceLevel > 0) {
    if (RQEPRRC_RqeOpt.TraceLevel > 1) {
      MASBIOS_SWRITE("RqeDifferenceCondition: All conjunctions generated.", 51L);
      MASBIOS_BLINES(0);
    } else {
      MASBIOS_SWRITE(")", 1L);
    }
  }
  if (result == MASSTOR_SIL) {
    return MLOGBASE_FALSUM;
  } else {
    return PQBASE_PQSIMPLIFY(MLOGBASE_FORMKFOR(MLOGBASE_VEL, MASSTOR_INV(result)));
  }
}

static MASSTOR_LIST RqeLimitCondition
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST var)
# else
(G, var)
MASSTOR_LIST G, var;
# endif
{
  MASSTOR_LIST GU, GP, g, LimCond, result, fvlist, newdd, perm;

  result = MASSTOR_SIL;
  LimCond = MASSTOR_SIL;
  fvlist = MASSET_SetComplementQ(var, DIPC_VALIS);
  GU = CommonPol2RecPolL(G, fvlist, var, DIPC_VALIS, &perm);
  PolFmtPush(DIPC_VALIS, var, fvlist, perm);
  GP = GU;
  while (GP != MASSTOR_SIL) {
    MASSTOR_ADV(GP, &g, &GP);
    LimCond = MASSTOR_COMP(RqeLimP(g), LimCond);
  }
  LimCond = MLOGBASE_FORMKFOR(MLOGBASE_ET, MASSTOR_INV(LimCond));
  result = MASSTOR_COMP(LimCond, result);
  GP = GU;
  LimCond = MASSTOR_SIL;
  while (GP != MASSTOR_SIL) {
    MASSTOR_ADV(GP, &g, &GP);
    LimCond = MASSTOR_COMP(RqeLimN(g), LimCond);
  }
  LimCond = MLOGBASE_FORMKFOR(MLOGBASE_ET, MASSTOR_INV(LimCond));
  result = MASSTOR_COMP(LimCond, result);
  PolFmtPop();
  return PQBASE_PQSIMPLIFY(MLOGBASE_FORMKFOR(MLOGBASE_VEL, result));
}

static MASSTOR_LIST RqeLimP
# ifdef __STDC__
(MASSTOR_LIST p)
# else
(p)
MASSTOR_LIST p;
# endif
{
  MASSTOR_LIST invperm, c, cp, e;

  if (p == 0) {
    return MLOGBASE_FALSUM;
  }
  invperm = MASCOMB_INVPERM(RQEPRRC_PolFmt.Permutation);
  DIPC_DIPMAD(p, &c, &e, &p);
  {
    register struct RQEPRRC_2 *W_2 = &RQEPRRC_PolFmt;

    cp = ParamPol2CommonPol(c, W_2->FreeVars, W_2->BoundVars, invperm);
  }
  if (DIPTOOLS_DIPCNST(cp)) {
    if (MASADOM_ADSIGN(c) == 1) {
      return MLOGBASE_VERUM;
    } else {
      return MLOGBASE_FALSUM;
    }
  } else if (p == MASSTOR_SIL) {
    return PQBASE_pqmkaf(PQBASE_GRE, cp);
  } else {
    return MLOGBASE_FORMKBINOP(MLOGBASE_VEL, PQBASE_pqmkaf(PQBASE_GRE, cp), MLOGBASE_FORMKBINOP(MLOGBASE_ET, PQBASE_pqmkaf(PQBASE_EQU, cp), RqeLimP(p)));
  }
}

static MASSTOR_LIST RqeLimN
# ifdef __STDC__
(MASSTOR_LIST p)
# else
(p)
MASSTOR_LIST p;
# endif
{
  MASSTOR_LIST invperm, c, cp, e;

  if (p == 0) {
    return MLOGBASE_FALSUM;
  }
  invperm = MASCOMB_INVPERM(RQEPRRC_PolFmt.Permutation);
  DIPC_DIPMAD(p, &c, &e, &p);
  {
    register struct RQEPRRC_2 *W_3 = &RQEPRRC_PolFmt;

    cp = ParamPol2CommonPol(c, W_3->FreeVars, W_3->BoundVars, invperm);
  }
  if (MASSTOR_FIRST(e) % 2 == 0) {
    if (DIPTOOLS_DIPCNST(cp)) {
      if (MASADOM_ADSIGN(c) == 1) {
        return MLOGBASE_VERUM;
      } else {
        return MLOGBASE_FALSUM;
      }
    } else if (p == MASSTOR_SIL) {
      return PQBASE_pqmkaf(PQBASE_GRE, cp);
    } else {
      return MLOGBASE_FORMKBINOP(MLOGBASE_VEL, PQBASE_pqmkaf(PQBASE_GRE, cp), MLOGBASE_FORMKBINOP(MLOGBASE_ET, PQBASE_pqmkaf(PQBASE_EQU, cp), RqeLimN(p)));
    }
  } else {
    if (DIPTOOLS_DIPCNST(cp)) {
      if (MASADOM_ADSIGN(c) == -1) {
        return MLOGBASE_VERUM;
      } else {
        return MLOGBASE_FALSUM;
      }
    } else if (p == MASSTOR_SIL) {
      return PQBASE_pqmkaf(PQBASE_LES, cp);
    } else {
      return MLOGBASE_FORMKBINOP(MLOGBASE_VEL, PQBASE_pqmkaf(PQBASE_LES, cp), MLOGBASE_FORMKBINOP(MLOGBASE_ET, PQBASE_pqmkaf(PQBASE_EQU, cp), RqeLimN(p)));
    }
  }
}

static MASSTOR_LIST cgbinput1
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST V, MASSTOR_LIST D, MASSTOR_LIST Cond)
# else
(P, V, D, Cond)
MASSTOR_LIST P, V, D, Cond;
# endif
{
  return CGBDSTR_CdpCons(MASSTOR_LIST1(Cond), SACLIST_LIST2(MASSTOR_INV(DIPC_DIPLPM(P)), 0), CGBDSTR_VdCons(V, D));
}

static MASSTOR_LIST CondFC
# ifdef __STDC__
(MASSTOR_LIST C)
# else
(C)
MASSTOR_LIST C;
# endif
{
  MASSTOR_LIST red, green, L, p, i;

  red = MASSTOR_SIL;
  green = MASSTOR_SIL;
  MASSTOR_ADV(C, &L, &C);
  while (L != MASSTOR_SIL) {
    MASSTOR_ADV(L, &p, &L);
    red = MASSTOR_COMP(p, red);
  }
  MASSTOR_ADV(C, &L, &C);
  MASSTOR_ADV(C, &L, &C);
  while (L != MASSTOR_SIL) {
    MASSTOR_ADV(L, &p, &L);
    green = MASSTOR_COMP(p, red);
  }
  MASSTOR_ADV(C, &L, &C);
  while (L != MASSTOR_SIL) {
    MASSTOR_ADV(L, &p, &L);
    red = MASSTOR_COMP(p, red);
  }
  MASSTOR_ADV(C, &L, &C);
  MASSTOR_ADV(C, &L, &C);
  while (L != MASSTOR_SIL) {
    MASSTOR_ADV(L, &p, &L);
    red = MASSTOR_COMP(p, red);
  }
  {
    register struct RQEPRRC_2 *W_4 = &RQEPRRC_PolFmt;

    red = CommonPol2ParamPolL(red, W_4->FreeVars, W_4->BoundVars, W_4->AllVars, &W_4->Permutation);
    green = CommonPol2ParamPolL(green, W_4->FreeVars, W_4->BoundVars, W_4->AllVars, &W_4->Permutation);
  }
  return CGBDSTR_CondCons(green, red);
}

static MASSTOR_LIST DIMISS
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST VL, MASSTOR_LIST *SMAXVL)
# else
(PL, VL, SMAXVL)
MASSTOR_LIST PL, VL;
MASSTOR_LIST *SMAXVL;
# endif
{
  MASSTOR_LIST M, m, S, DL;

  if (PL == MASSTOR_SIL) {
    *SMAXVL = MASSTOR_LIST1(VL);
    return MASSTOR_LENGTH(VL);
  }
  DIPDIM_DILDIM(PL, &DL, &S, &M);
  if (DL == -1) {
    *SMAXVL = MASSTOR_SIL;
    return -1;
  }
  *SMAXVL = MASSTOR_SIL;
  while (M != MASSTOR_SIL) {
    MASSTOR_ADV(M, &m, &M);
    *SMAXVL = MASSTOR_COMP(DIPDIM_IXSUBS(VL, m), *SMAXVL);
  }
  *SMAXVL = MASSTOR_INV(*SMAXVL);
  return DL;
}

static MASSTOR_LIST CondUnion
# ifdef __STDC__
(MASSTOR_LIST c1, MASSTOR_LIST c2)
# else
(c1, c2)
MASSTOR_LIST c1, c2;
# endif
{
  MASSTOR_LIST green1, red1, green2, red2;

  if (CGBDSTR_CondIsEmpty(c1)) {
    return c2;
  } else if (CGBDSTR_CondIsEmpty(c2)) {
    return c1;
  }
  CGBDSTR_CondParts(c1, &green1, &red1);
  CGBDSTR_CondParts(c2, &green2, &red2);
  return CGBDSTR_CondCons(SACLIST_CCONC(green1, green2), SACLIST_CCONC(red1, red2));
}

static MASSTOR_LIST ParamPol2CommonPol
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST Uvlist, MASSTOR_LIST Xvlist, MASSTOR_LIST iperm)
# else
(p, Uvlist, Xvlist, iperm)
MASSTOR_LIST p, Uvlist, Xvlist, iperm;
# endif
{
  p = DIPTOOLS_DIPFADIP(p);
  p = DIPC_DIPINV(p, MASSTOR_LENGTH(Uvlist) + 1, MASSTOR_LENGTH(Xvlist));
  return DIPC_DIPERM(p, iperm);
}

static MASSTOR_LIST ParamPol2CommonPolL
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST Uvlist, MASSTOR_LIST Xvlist, MASSTOR_LIST iperm)
# else
(P, Uvlist, Xvlist, iperm)
MASSTOR_LIST P, Uvlist, Xvlist, iperm;
# endif
{
  MASSTOR_LIST p, res, lfv, lbv, luv, lxv;

  res = MASSTOR_SIL;
  luv = MASSTOR_LENGTH(Uvlist);
  lxv = MASSTOR_LENGTH(Xvlist);
  while (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, &p, &P);
    p = DIPTOOLS_DIPFADIP(p);
    p = DIPC_DIPINV(p, luv + 1, lxv);
    res = MASSTOR_COMP(DIPC_DIPERM(p, iperm), res);
  }
  return MASSTOR_INV(res);
}

static MASSTOR_LIST RecPol2CommonPol
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST Uvlist, MASSTOR_LIST Xvlist, MASSTOR_LIST iperm)
# else
(p, Uvlist, Xvlist, iperm)
MASSTOR_LIST p, Uvlist, Xvlist, iperm;
# endif
{
  MASSTOR_LIST d, q, v;

  d = ADTOOLS_INTDDCMP();
  DIPTOOLS_ValisPush(Xvlist);
  DIPTOOLS_DIPFDIPP(p, d, &q, &v);
  DIPTOOLS_ValisPop();
  q = DIPC_DIPERM(q, iperm);
  return q;
}

static MASSTOR_LIST RecPol2CommonPolL
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST Uvlist, MASSTOR_LIST Xvlist, MASSTOR_LIST iperm)
# else
(P, Uvlist, Xvlist, iperm)
MASSTOR_LIST P, Uvlist, Xvlist, iperm;
# endif
{
  MASSTOR_LIST d, q, v, p, res;

  DIPTOOLS_ValisPush(Xvlist);
  res = MASSTOR_SIL;
  d = ADTOOLS_INTDDCMP();
  while (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, &p, &P);
    DIPTOOLS_DIPFDIPP(p, d, &q, &v);
    q = DIPC_DIPERM(q, iperm);
    res = MASSTOR_COMP(q, res);
  }
  DIPTOOLS_ValisPop();
  return MASSTOR_INV(res);
}

static MASSTOR_LIST CommonPol2RecPol
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST Uvlist, MASSTOR_LIST Xvlist, MASSTOR_LIST valis, MASSTOR_LIST *perm)
# else
(p, Uvlist, Xvlist, valis, perm)
MASSTOR_LIST p, Uvlist, Xvlist, valis;
MASSTOR_LIST *perm;
# endif
{
  MASSTOR_LIST q, v, r, newdd;

  *perm = MASCOMB_PVFLISTS(valis, SACLIST_CCONC(Uvlist, Xvlist));
  r = MASSTOR_LENGTH(Uvlist);
  newdd = ADTOOLS_IPDDCMP(Uvlist);
  DIPTOOLS_ValisPush(SACCOMB_LPERM(valis, *perm));
  DIPTOOLS_DIPPFDIP(DIPC_DIPERM(p, *perm), r, newdd, &q, &v);
  DIPTOOLS_ValisPop();
  return q;
}

static MASSTOR_LIST CommonPol2RecPolL
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST Uvlist, MASSTOR_LIST Xvlist, MASSTOR_LIST valis, MASSTOR_LIST *perm)
# else
(P, Uvlist, Xvlist, valis, perm)
MASSTOR_LIST P, Uvlist, Xvlist, valis;
MASSTOR_LIST *perm;
# endif
{
  MASSTOR_LIST q, v, p, res, r, newdd;

  res = MASSTOR_SIL;
  *perm = MASCOMB_PVFLISTS(valis, SACLIST_CCONC(Uvlist, Xvlist));
  r = MASSTOR_LENGTH(Uvlist);
  newdd = ADTOOLS_IPDDCMP(Uvlist);
  DIPTOOLS_ValisPush(SACCOMB_LPERM(valis, *perm));
  while (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, &p, &P);
    DIPTOOLS_DIPPFDIP(DIPC_DIPERM(p, *perm), r, newdd, &q, &v);
    res = MASSTOR_COMP(q, res);
  }
  DIPTOOLS_ValisPop();
  return MASSTOR_INV(res);
}

static MASSTOR_LIST CommonPol2ParamPol
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST Uvlist, MASSTOR_LIST Xvlist, MASSTOR_LIST valis, MASSTOR_LIST *perm)
# else
(p, Uvlist, Xvlist, valis, perm)
MASSTOR_LIST p, Uvlist, Xvlist, valis;
MASSTOR_LIST *perm;
# endif
{
  MASSTOR_LIST q, v, c, r, e, newdd;

  *perm = MASCOMB_PVFLISTS(valis, SACLIST_CCONC(Uvlist, Xvlist));
  r = MASSTOR_LENGTH(Uvlist);
  newdd = ADTOOLS_IPDDCMP(Uvlist);
  DIPTOOLS_ValisPush(SACCOMB_LPERM(valis, *perm));
  DIPTOOLS_DIPPFDIP(DIPC_DIPERM(p, *perm), r, newdd, &q, &v);
  DIPC_DIPMAD(q, &c, &e, &q);
  DIPTOOLS_ValisPop();
  return c;
}

static MASSTOR_LIST CommonPol2ParamPolL
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST Uvlist, MASSTOR_LIST Xvlist, MASSTOR_LIST valis, MASSTOR_LIST *perm)
# else
(P, Uvlist, Xvlist, valis, perm)
MASSTOR_LIST P, Uvlist, Xvlist, valis;
MASSTOR_LIST *perm;
# endif
{
  MASSTOR_LIST q, v, p, res, r, c, e, newdd;

  res = MASSTOR_SIL;
  *perm = MASCOMB_PVFLISTS(valis, SACLIST_CCONC(Uvlist, Xvlist));
  r = MASSTOR_LENGTH(Uvlist);
  newdd = ADTOOLS_IPDDCMP(Uvlist);
  DIPTOOLS_ValisPush(SACCOMB_LPERM(valis, *perm));
  while (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, &p, &P);
    DIPTOOLS_DIPPFDIP(DIPC_DIPERM(p, *perm), r, newdd, &q, &v);
    DIPC_DIPMAD(q, &c, &e, &q);
    res = MASSTOR_COMP(c, res);
  }
  DIPTOOLS_ValisPop();
  return MASSTOR_INV(res);
}

static MASSTOR_LIST PqFC
# ifdef __STDC__
(MASSTOR_LIST C)
# else
(C)
MASSTOR_LIST C;
# endif
{
  MASSTOR_LIST result, dil, p;

  result = MASSTOR_SIL;
  MASSTOR_ADV(C, &dil, &C);
  if (dil != MASSTOR_SIL) {
    result = MASSTOR_COMP(PQFDIL(dil, PQBASE_LES, MLOGBASE_ET), result);
  }
  MASSTOR_ADV(C, &dil, &C);
  if (dil != MASSTOR_SIL) {
    result = MASSTOR_COMP(PQFDIL(dil, PQBASE_LSQ, MLOGBASE_ET), result);
  }
  MASSTOR_ADV(C, &dil, &C);
  if (dil != MASSTOR_SIL) {
    result = MASSTOR_COMP(PQFDIL(dil, PQBASE_EQU, MLOGBASE_ET), result);
  }
  MASSTOR_ADV(C, &dil, &C);
  if (dil != MASSTOR_SIL) {
    result = MASSTOR_COMP(PQFDIL(dil, PQBASE_NEQ, MLOGBASE_ET), result);
  }
  MASSTOR_ADV(C, &dil, &C);
  if (dil != MASSTOR_SIL) {
    result = MASSTOR_COMP(PQFDIL(dil, PQBASE_GRQ, MLOGBASE_ET), result);
  }
  MASSTOR_ADV(C, &dil, &C);
  if (dil != MASSTOR_SIL) {
    result = MASSTOR_COMP(PQFDIL(dil, PQBASE_GRE, MLOGBASE_ET), result);
  }
  if (result != MASSTOR_SIL) {
    return MLOGBASE_FORMKFOR(MLOGBASE_ET, MASSTOR_INV(result));
  } else {
    return MLOGBASE_VERUM;
  }
}

static MASSTOR_LIST PQFDIL
# ifdef __STDC__
(MASSTOR_LIST dil, MASSTOR_LIST pqop, MASSTOR_LIST op)
# else
(dil, pqop, op)
MASSTOR_LIST dil, pqop, op;
# endif
{
  MASSTOR_LIST dip, result;

  if (dil == MASSTOR_SIL) {
    if (op == MLOGBASE_ET) {
      return MLOGBASE_VERUM;
    } else if (op == MLOGBASE_VEL) {
      return MLOGBASE_FALSUM;
    } else {
      MASERR_ERROR(MASERR_severe, "PQFDIL: cannot create formula from empty list.", 46L);
      return MLOGBASE_FALSUM;
    }
  }
  result = MASSTOR_SIL;
  while (dil != MASSTOR_SIL) {
    MASSTOR_ADV(dil, &dip, &dil);
    result = MASSTOR_COMP(PQBASE_pqmkaf(pqop, dip), result);
  }
  return MLOGBASE_FORMKFOR(op, MASSTOR_INV(result));
}

static MASSTOR_LIST forfdata
# ifdef __STDC__
(MASSTOR_LIST Cond, MASSTOR_LIST Plist, MASSTOR_LIST Gre, MASSTOR_LIST Neq)
# else
(Cond, Plist, Gre, Neq)
MASSTOR_LIST Cond, Plist, Gre, Neq;
# endif
{
  MASSTOR_LIST G, R, result, p;

  {
    register struct RQEPRRC_2 *W_5 = &RQEPRRC_PolFmt;

    Plist = RecPol2CommonPolL(Plist, W_5->FreeVars, W_5->BoundVars, MASCOMB_INVPERM(W_5->Permutation));
  }
  DIPTOOLS_ValisPush(RQEPRRC_PolFmt.BoundVars);
  result = MASSTOR_SIL;
  while (Neq != MASSTOR_SIL) {
    MASSTOR_ADV(Neq, &p, &Neq);
    result = MASSTOR_COMP(PQBASE_pqmkaf(PQBASE_NEQ, p), result);
  }
  while (Gre != MASSTOR_SIL) {
    MASSTOR_ADV(Gre, &p, &Gre);
    result = MASSTOR_COMP(PQBASE_pqmkaf(PQBASE_GRE, p), result);
  }
  while (Plist != MASSTOR_SIL) {
    MASSTOR_ADV(Plist, &p, &Plist);
    result = MASSTOR_COMP(PQBASE_pqmkaf(PQBASE_EQU, p), result);
  }
  if (result == MASSTOR_SIL) {
    result = MLOGBASE_VERUM;
  } else {
    result = MLOGBASE_FORMKFOR(MLOGBASE_ET, MASSTOR_INV(result));
  }
  if (!CGBDSTR_CondIsEmpty(Cond)) {
    result = MLOGBASE_FORMKBINOP(MLOGBASE_ET, PqFCond(Cond), result);
  }
  DIPTOOLS_ValisPop();
  return result;
}

static MASSTOR_LIST PqFCond
# ifdef __STDC__
(MASSTOR_LIST Cond)
# else
(Cond)
MASSTOR_LIST Cond;
# endif
{
  MASSTOR_LIST G, R, p, result;

  result = MASSTOR_SIL;
  if (!CGBDSTR_CondIsEmpty(Cond)) {
    CGBDSTR_CondParts(Cond, &G, &R);
    {
      register struct RQEPRRC_2 *W_6 = &RQEPRRC_PolFmt;

      G = ParamPol2CommonPolL(G, W_6->FreeVars, W_6->BoundVars, MASCOMB_INVPERM(W_6->Permutation));
      R = ParamPol2CommonPolL(R, W_6->FreeVars, W_6->BoundVars, MASCOMB_INVPERM(W_6->Permutation));
    }
    while (R != MASSTOR_SIL) {
      MASSTOR_ADV(R, &p, &R);
      result = MASSTOR_COMP(PQBASE_pqmkaf(PQBASE_NEQ, p), result);
    }
    while (G != MASSTOR_SIL) {
      MASSTOR_ADV(G, &p, &G);
      result = MASSTOR_COMP(PQBASE_pqmkaf(PQBASE_EQU, p), result);
    }
    result = MLOGBASE_FORMKFOR(MLOGBASE_ET, MASSTOR_INV(result));
  } else {
    result = MLOGBASE_VERUM;
  }
  return result;
}

static MASSTOR_LIST ExtractPolynomials
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST bvlist, MASSTOR_LIST valis)
# else
(phi, bvlist, valis)
MASSTOR_LIST phi, bvlist, valis;
# endif
{
  MASSTOR_LIST p, op, args, af, rel, bvv;
  MASSTOR_LIST eq, gr, nq, cle, clq, ceq, cnq, cgq, cgr;

  bvv = DIPTOOLS_VVECFVLIST(bvlist, valis);
  eq = MASSTOR_SIL;
  gr = MASSTOR_SIL;
  nq = MASSTOR_SIL;
  cle = MASSTOR_SIL;
  clq = MASSTOR_SIL;
  ceq = MASSTOR_SIL;
  cnq = MASSTOR_SIL;
  cgq = MASSTOR_SIL;
  cgr = MASSTOR_SIL;
  MLOGBASE_FORPFOR(phi, &op, &args);
  while (args != MASSTOR_SIL) {
    MASSTOR_ADV(args, &af, &args);
    PQBASE_pqpaf(af, &rel, &p);
    if (DIPTOOLS_DIPCNSTR(p, bvv)) {
      if (rel == PQBASE_LES) {
        cle = MASSTOR_COMP(p, cle);
      } else if (rel == PQBASE_LSQ) {
        clq = MASSTOR_COMP(p, clq);
      } else if (rel == PQBASE_EQU) {
        ceq = MASSTOR_COMP(p, ceq);
      } else if (rel == PQBASE_NEQ) {
        cnq = MASSTOR_COMP(p, cnq);
      } else if (rel == PQBASE_GRQ) {
        cgq = MASSTOR_COMP(p, cgq);
      } else if (rel == PQBASE_GRE) {
        cgr = MASSTOR_COMP(p, cgr);
      } else {
        MASERR_ERROR(MASERR_severe, "ExtractPolynomials: incorrect relation symbol", 45L);
      }
    } else {
      if (rel == PQBASE_EQU) {
        eq = MASSTOR_COMP(p, eq);
      } else if (rel == PQBASE_GRE) {
        gr = MASSTOR_COMP(p, gr);
      } else if (rel == PQBASE_NEQ) {
        nq = MASSTOR_COMP(p, nq);
      } else {
        MASERR_ERROR(MASERR_severe, "ExtractPolynomials: incorrect relation symbol", 45L);
      }
    }
  }
  return SACLIST_LIST2(SACLIST_LIST3(MASSTOR_INV(eq), MASSTOR_INV(gr), MASSTOR_INV(nq)), LISTTOOLS_LIST6(MASSTOR_INV(cle), MASSTOR_INV(clq), MASSTOR_INV(ceq), MASSTOR_INV(cnq), MASSTOR_INV(cgq), MASSTOR_INV(cgr)));
}

static MASSTOR_LIST RQERSNF
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST bvlist, MASSTOR_LIST valis)
# else
(phi, bvlist, valis)
MASSTOR_LIST phi, bvlist, valis;
# endif
{
  MASSTOR_LIST bvv;

  bvv = DIPTOOLS_VVECFVLIST(bvlist, valis);
  return MASLOG_FORAPPLYATF2(phi, bvv, RelSymNf);
}

static MASSTOR_LIST RelSymNf
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST bvv)
# else
(phi, bvv)
MASSTOR_LIST phi, bvv;
# endif
{
  MASSTOR_LIST rel, pol;

  PQBASE_pqpaf(phi, &rel, &pol);
  if (DIPTOOLS_DIPCNSTR(pol, bvv)) {
    return phi;
  }
  if (rel == PQBASE_EQU || rel == PQBASE_NEQ || rel == PQBASE_GRE) {
    return phi;
  } else if (rel == PQBASE_LSQ) {
    return MLOGBASE_FORMKFOR(MLOGBASE_VEL, SACLIST_LIST2(PQBASE_pqmkaf(PQBASE_GRE, DIPADOM_DIPNEG(pol)), PQBASE_pqmkaf(PQBASE_EQU, pol)));
  } else if (rel == PQBASE_GRQ) {
    return MLOGBASE_FORMKFOR(MLOGBASE_VEL, SACLIST_LIST2(PQBASE_pqmkaf(PQBASE_GRE, pol), PQBASE_pqmkaf(PQBASE_EQU, pol)));
  } else if (rel == PQBASE_LES) {
    return PQBASE_pqmkaf(PQBASE_GRE, DIPADOM_DIPNEG(pol));
  } else {
    MASSYM2_UWRITE(rel);
    MASERR_ERROR(MASERR_severe, "RelSymNf: unknown relation symbol", 33L);
  }
}

static MASSTOR_LIST exvlist
# ifdef __STDC__
(MASSTOR_LIST vlist1, MASSTOR_LIST vlist2)
# else
(vlist1, vlist2)
MASSTOR_LIST vlist1, vlist2;
# endif
{
  MASSTOR_LIST v, result;

  result = SACLIST_CINV(vlist1);
  while (vlist2 != MASSTOR_SIL) {
    MASSTOR_ADV(vlist2, &v, &vlist2);
    if (SACLIST_MEMBER(v, vlist1) == 0) {
      result = MASSTOR_COMP(v, result);
    }
  }
  return MASSTOR_INV(result);
}

static MASSTOR_LIST nontrivial
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST bvlist, MASSTOR_LIST allvars)
# else
(p, bvlist, allvars)
MASSTOR_LIST p, bvlist, allvars;
# endif
{
  MASSTOR_LIST c, e, result, perm, invperm, fvlist;

  if (p == 0) {
    return MLOGBASE_FALSUM;
  }
  fvlist = MASSET_SetComplementQ(bvlist, allvars);
  p = CommonPol2RecPol(p, fvlist, bvlist, DIPC_VALIS, &perm);
  result = MASSTOR_SIL;
  invperm = MASCOMB_INVPERM(perm);
  while (p != MASSTOR_SIL) {
    DIPC_DIPMAD(p, &c, &e, &p);
    c = ParamPol2CommonPol(c, fvlist, bvlist, invperm);
    result = MASSTOR_COMP(PQBASE_pqmkaf(PQBASE_NEQ, c), result);
  }
  return PQBASE_PQSIMPLIFY(MLOGBASE_FORMKFOR(MLOGBASE_VEL, MASSTOR_INV(result)));
}

MASSTOR_LIST RQEPRRC_RQEOPTSET
# ifdef __STDC__
(MASSTOR_LIST opt)
# else
(opt)
MASSTOR_LIST opt;
# endif
{
  MASSTOR_LIST old, flag;

  if (RQEPRRC_RqeOpt.DimensionZeroOnly) {
    old = MASSTOR_LIST1(1);
  } else {
    old = MASSTOR_LIST1(0);
  }
  old = MASSTOR_COMP(RQEPRRC_RqeOpt.TraceLevel, old);
  if (opt == MASSTOR_SIL) {
    return old;
  }
  if (opt != MASSTOR_SIL) {
    if (MASSTOR_FIRST(opt) != -1) {
      MASSTOR_ADV(opt, &RQEPRRC_RqeOpt.TraceLevel, &opt);
    } else {
      opt = MASSTOR_RED(opt);
    }
  }
  if (opt != MASSTOR_SIL) {
    if (MASSTOR_FIRST(opt) != -1) {
      MASSTOR_ADV(opt, &flag, &opt);
      if (flag == 1) {
        RQEPRRC_RqeOpt.DimensionZeroOnly = TRUE;
      } else {
        RQEPRRC_RqeOpt.DimensionZeroOnly = FALSE;
      }
    } else {
      opt = MASSTOR_RED(opt);
    }
  }
  return old;
}

void RQEPRRC_RQEOPTWR
# ifdef __STDC__
()
# else
()
# endif
{
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("Options for the RQE - System", 28L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("The trace level is: ", 20L);
  MASSYM2_UWRITE(RQEPRRC_RqeOpt.TraceLevel);
  if (RQEPRRC_RqeOpt.DimensionZeroOnly) {
    MASBIOS_SWRITE("Only partial quantifier elimination is done.", 44L);
  } else {
    MASBIOS_SWRITE("Full quantifier elimination is done.", 36L);
  }
  MASBIOS_BLINES(1);
}

static void RqeOptInit
# ifdef __STDC__
()
# else
()
# endif
{
  {
    register RQEPRRC_RQEOPTIONS *W_7 = &RQEPRRC_RqeOpt;

    W_7->TraceLevel = 3;
    W_7->DimensionZeroOnly = FALSE;
  }
}

static void PolFmtInit
# ifdef __STDC__
()
# else
()
# endif
{
  PolFmtStack = MASSTOR_SIL;
  MASSTOR_LISTVAR(&PolFmtStack);
  {
    register struct RQEPRRC_2 *W_8 = &RQEPRRC_PolFmt;

    W_8->AllVars = MASSTOR_SIL;
    W_8->BoundVars = MASSTOR_SIL;
    W_8->FreeVars = MASSTOR_SIL;
    W_8->Permutation = MASSTOR_SIL;
    MASSTOR_LISTVAR(&W_8->AllVars);
    MASSTOR_LISTVAR(&W_8->BoundVars);
    MASSTOR_LISTVAR(&W_8->FreeVars);
    MASSTOR_LISTVAR(&W_8->Permutation);
  }
}

static void PolFmtPush
# ifdef __STDC__
(MASSTOR_LIST vars, MASSTOR_LIST bvlist, MASSTOR_LIST fvlist, MASSTOR_LIST perm)
# else
(vars, bvlist, fvlist, perm)
MASSTOR_LIST vars, bvlist, fvlist, perm;
# endif
{
  {
    register struct RQEPRRC_2 *W_9 = &RQEPRRC_PolFmt;

    PolFmtStack = MASSTOR_COMP(SACLIST_LIST4(W_9->AllVars, W_9->BoundVars, W_9->FreeVars, W_9->Permutation), PolFmtStack);
    W_9->AllVars = vars;
    W_9->BoundVars = bvlist;
    W_9->FreeVars = fvlist;
    W_9->Permutation = perm;
  }
}

static void PolFmtPop
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST elem;

  if (PolFmtStack == MASSTOR_SIL) {
    MASERR_ERROR(MASERR_severe, "PolFmtPop: stack empty.", 23L);
    return;
  }
  MASSTOR_ADV(PolFmtStack, &elem, &PolFmtStack);
  {
    register struct RQEPRRC_2 *W_10 = &RQEPRRC_PolFmt;

    SACLIST_FIRST4(elem, &W_10->AllVars, &W_10->BoundVars, &W_10->FreeVars, &W_10->Permutation);
  }
}

void BEGIN_RQEPRRC()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASLISPU();
    BEGIN_MASSTOR();
    BEGIN_ADTOOLS();
    BEGIN_CGBDSTR();
    BEGIN_CGBFUNC();
    BEGIN_CGBMISC();
    BEGIN_CGBMAIN();
    BEGIN_DIPADOM();
    BEGIN_DIPC();
    BEGIN_DIPDIM();
    BEGIN_DIPRF();
    BEGIN_DIPTOOLS();
    BEGIN_LINALG();
    BEGIN_LISTTOOLS();
    BEGIN_MASADOM();
    BEGIN_MASBIOS();
    BEGIN_MASCOMB();
    BEGIN_MASELEM();
    BEGIN_MASERR();
    BEGIN_MASLOG();
    BEGIN_MASSET();
    BEGIN_MASSTOR();
    BEGIN_MASSYM2();
    BEGIN_MLOGBASE();
    BEGIN_PQBASE();
    BEGIN_RRADOM();
    BEGIN_SACCOMB();
    BEGIN_SACIPOL();
    BEGIN_SACLIST();
    BEGIN_SACPOL();
    BEGIN_SYSINFO();
    BEGIN_TFORM();

    RqeOptInit();
    PolFmtInit();
    AdjoinedEq = FALSE;
  }
}
