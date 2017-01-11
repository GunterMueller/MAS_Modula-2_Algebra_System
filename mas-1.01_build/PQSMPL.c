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

#ifndef DEFINITION_MASERR
#include "MASERR.h"
#endif

#ifndef DEFINITION_MASSYM
#include "MASSYM.h"
#endif

#ifndef DEFINITION_MASSYM2
#include "MASSYM2.h"
#endif

#ifndef DEFINITION_MASLISPU
#include "MASLISPU.h"
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

#ifndef DEFINITION_DIPADOM
#include "DIPADOM.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPGB
#include "DIPGB.h"
#endif

#ifndef DEFINITION_MASADOM
#include "MASADOM.h"
#endif

#ifndef DEFINITION_SACSET
#include "SACSET.h"
#endif

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_PQBASE
#include "PQBASE.h"
#endif

#ifndef DEFINITION_DIPTOOLS
#include "DIPTOOLS.h"
#endif

#ifndef DEFINITION_PQSMPL
#include "PQSMPL.h"
#endif

CHAR PQSMPL_rcsid [] = "$Id: PQSMPL.md,v 1.4 1995/12/16 11:34:34 kredel Exp $";
CHAR PQSMPL_copyright [] = "Copyright (c) 1993 Universitaet Passau";

#define subset	0
#define superset	1
#define setequal	2
#define setnorel	3
typedef unsigned char SetRel;
static CHAR rcsidi [] = "$Id: PQSMPL.mi,v 1.3 1995/11/04 18:00:28 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1993 Universitaet Passau";
static MASSTOR_LIST PQTRACE;
static MASSTOR_LIST PQRMSTest;
static MASSTOR_LIST PQPOWERS;
static MASSTOR_LIST PQIBREP;
static MASSTOR_LIST PQREDCON;
static MASSTOR_LIST PQSimplify1 ARGS((MASSTOR_LIST nf, MASSTOR_LIST type));
static MASSTOR_LIST PQGetDataCnf ARGS((MASSTOR_LIST cnf));
static MASSTOR_LIST PQGetDataDnf ARGS((MASSTOR_LIST dnf));
static MASSTOR_LIST PQGetData1 ARGS((MASSTOR_LIST nf, MASSTOR_LIST type));
static MASSTOR_LIST PQscnf ARGS((MASSTOR_LIST POLS));
static MASSTOR_LIST PQsdnf ARGS((MASSTOR_LIST POLS));
static void PQsnf1 ARGS((MASSTOR_LIST POLS, MASSTOR_LIST type, MASSTOR_LIST *fst, MASSTOR_LIST *snd));
static BOOLEAN TestRMember ARGS((MASSTOR_LIST F, MASSTOR_LIST G, MASSTOR_LIST p, MASSTOR_LIST *B, MASSTOR_LIST *p1));
static BOOLEAN TestRMember1 ARGS((MASSTOR_LIST F, MASSTOR_LIST G, MASSTOR_LIST p, MASSTOR_LIST *p1));
static MASSTOR_LIST GenEV ARGS((MASSTOR_LIST value, MASSTOR_LIST length));
static BOOLEAN SeqPair ARGS((MASSTOR_LIST elem1, MASSTOR_LIST SEQ1, MASSTOR_LIST elem2, MASSTOR_LIST SEQ2));
static MASSTOR_LIST PQSetTrace ARGS((MASSTOR_LIST level));
static MASSTOR_LIST PQGetTrace ARGS(());
static void DLSWRIT1 ARGS((CHAR S[], LONGCARD , MASSTOR_LIST level));
static void DLUWRITE ARGS((MASSTOR_LIST L, MASSTOR_LIST level));
static void DLUWRIT1 ARGS((MASSTOR_LIST L, MASSTOR_LIST level));
static void DLBLINES ARGS((MASSTOR_LIST n, MASSTOR_LIST level));
static void DLPQPRT ARGS((CHAR S[], LONGCARD , MASSTOR_LIST phi, MASSTOR_LIST level));


MASSTOR_LIST PQSMPL_PQSCNF
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  MASSTOR_LIST nf;

  nf = PQSMPL_SimplifyNf(PQBASE_PQMKCNF(PQBASE_PQSMPL(phi)));
  if (nf == MLOGBASE_VERUM || nf == MLOGBASE_FALSUM) {
    return nf;
  }
  return PQscnf(PQGetDataCnf(nf));
}

MASSTOR_LIST PQSMPL_PQSDNF
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  MASSTOR_LIST nf;

  nf = PQSMPL_SimplifyNf(PQBASE_PQMKCNF(PQBASE_PQSMPL(phi)));
  if (nf == MLOGBASE_VERUM || nf == MLOGBASE_FALSUM) {
    return nf;
  }
  return PQsdnf(PQGetDataDnf(nf));
}

MASSTOR_LIST PQSMPL_PQCnfSimplify
# ifdef __STDC__
(MASSTOR_LIST nu)
# else
(nu)
MASSTOR_LIST nu;
# endif
{
  PQSMPL_DLSWRITE("starting cnf based simplification", 33L, 1);
  return PQSimplify1(PQSMPL_SimplifyNf(PQBASE_PQMKCNF(PQBASE_PQSMPL(nu))), 1);
}

MASSTOR_LIST PQSMPL_PQDnfSimplify
# ifdef __STDC__
(MASSTOR_LIST nu)
# else
(nu)
MASSTOR_LIST nu;
# endif
{
  PQSMPL_DLSWRITE("starting cnf based simplification", 33L, 1);
  return PQSimplify1(PQSMPL_SimplifyNf(PQBASE_PQMKDNF(PQBASE_PQSMPL(nu))), 2);
}

static MASSTOR_LIST PQSimplify1
# ifdef __STDC__
(MASSTOR_LIST nf, MASSTOR_LIST type)
# else
(nf, type)
MASSTOR_LIST nf, type;
# endif
{
  MASSTOR_LIST POLS, PSI, GB1, GBi2, PHI, GAMMA, gamma, phi;
  MASSTOR_LIST gamma1;
  MASSTOR_LIST GAMMA1, PHI1, phi1, B;
  MASSTOR_LIST domain;

  if (nf == MLOGBASE_VERUM || nf == MLOGBASE_FALSUM) {
    DLPQPRT("Input formula in SNF", 20L, nf, 2);
    return nf;
  }
  if (type == 1) {
    POLS = PQGetData1(nf, 1);
    DLPQPRT("Input formula in SCNF", 21L, PQscnf(POLS), 2);
  } else {
    POLS = PQGetData1(nf, 2);
    DLPQPRT("Input formula in SDNF", 21L, PQsdnf(POLS), 2);
  }
  PSI = SACLIST_THIRD(POLS);
  PQSMPL_DLSWRITE("1.) consistency test over psi", 29L, 1);
  GB1 = MASSTOR_SIL;
  if (PSI != MASSTOR_SIL) {
    domain = DIPTOOLS_ADDDFDIP(MASSTOR_FIRST(PSI));
    GB1 = PQSMPL_DIPADGB(PSI);
    if (PQSMPL_IdealMember(GB1, DIPTOOLS_DIPONE(domain))) {
      if (type == 1) {
        return MLOGBASE_FALSUM;
      } else {
        return MLOGBASE_VERUM;
      }
    }
    switch ((INTEGER)PQIBREP) {
    case 0:;
      break;
    case 1:;
      PSI = PQSMPL_DIPADIRSET(PSI);
      break;
    case 2:;
      PSI = PQSMPL_DIPADIRSET(GB1);
      break;
    default :
      MASERR_ERROR(MASERR_severe, "PQIBREP unknown code!", 21L);
      break;
    }
  }
  PHI = MASSTOR_FIRST(POLS);
  GAMMA = SACLIST_SECOND(POLS);
  GAMMA1 = MASSTOR_SIL;
  PHI1 = MASSTOR_SIL;
  PQSMPL_DLSWRITE("2.) simplification of the implications", 38L, 1);
  while (PHI != MASSTOR_SIL) {
    MASSTOR_ADV(GAMMA, &gamma, &GAMMA);
    MASSTOR_ADV(PHI, &phi, &PHI);
    if (!TestRMember(phi, GB1, gamma, &B, &gamma1)) {
      GAMMA1 = MASSTOR_COMP(gamma1, GAMMA1);
      PHI1 = MASSTOR_COMP(B, PHI1);
    }
  }
  if (type == 1) {
    return PQBASE_PQSMPL(PQscnf(SACLIST_LIST3(MASSTOR_INV(PHI1), MASSTOR_INV(GAMMA1), PSI)));
  } else {
    return PQBASE_PQSMPL(PQsdnf(SACLIST_LIST3(MASSTOR_INV(PHI1), MASSTOR_INV(GAMMA1), PSI)));
  }
}

MASSTOR_LIST PQSMPL_SimplifyNf
# ifdef __STDC__
(MASSTOR_LIST nf)
# else
(nf)
MASSTOR_LIST nf;
# endif
{
  MASSTOR_LIST literal, clause, lhs, rel, op1, op2, Literals, Clauses;
  MASSTOR_LIST PolRel, ResLits, ResClaus, assoc, s;
  BOOLEAN exit;

  s = PQBASE_PQSMPL(nf);
  if (s == MLOGBASE_VERUM || s == MLOGBASE_FALSUM) {
    return s;
  }
  MLOGBASE_FORPFOR(nf, &op1, &Clauses);
  ResClaus = MASSTOR_SIL;
  while (Clauses != MASSTOR_SIL) {
    ResLits = MASSTOR_SIL;
    PolRel = MASSTOR_SIL;
    MLOGBASE_FORPARGS(Clauses, &clause, &Clauses);
    MLOGBASE_FORPFOR(clause, &op2, &Literals);
    exit = FALSE;
    while (Literals != MASSTOR_SIL && !exit) {
      MLOGBASE_FORPFOR(Literals, &literal, &Literals);
      PQBASE_pqpaf(literal, &rel, &lhs);
      assoc = MASSYM2_ASSOCQ(lhs, PolRel);
      if (assoc == MASSTOR_SIL) {
        PolRel = SACLIST_COMP2(lhs, rel, PolRel);
        ResLits = MASSTOR_COMP(literal, ResLits);
      } else if (MASSTOR_FIRST(assoc) != rel) {
        PQSMPL_DLSWRITE("smart simplify successful", 25L, 3);
        ResLits = MASSTOR_SIL;
        exit = TRUE;
      } else {
        PQSMPL_DLSWRITE("identical atomic formulas deleted", 33L, 3);
      }
    }
    if (ResLits != MASSTOR_SIL) {
      ResClaus = MASSTOR_COMP(MLOGBASE_FORMKFOR(op2, MASSTOR_INV(ResLits)), ResClaus);
    }
  }
  if (ResClaus == MASSTOR_SIL && op1 == MLOGBASE_ET) {
    return MLOGBASE_VERUM;
  } else if (ResClaus == MASSTOR_SIL && op1 == MLOGBASE_VEL) {
    return MLOGBASE_FALSUM;
  } else {
    return MLOGBASE_FORMKFOR(op1, MASSTOR_INV(ResClaus));
  }
}

static MASSTOR_LIST PQGetDataCnf
# ifdef __STDC__
(MASSTOR_LIST cnf)
# else
(cnf)
MASSTOR_LIST cnf;
# endif
{
  return PQGetData1(cnf, 1);
}

static MASSTOR_LIST PQGetDataDnf
# ifdef __STDC__
(MASSTOR_LIST dnf)
# else
(dnf)
MASSTOR_LIST dnf;
# endif
{
  return PQGetData1(dnf, 2);
}

static MASSTOR_LIST PQGetData1
# ifdef __STDC__
(MASSTOR_LIST nf, MASSTOR_LIST type)
# else
(nf, type)
MASSTOR_LIST nf, type;
# endif
{
  MASSTOR_LIST clause, atomic;
  MASSTOR_LIST POS, NEG;
  MASSTOR_LIST PHI, GAMMA, PSI;
  MASSTOR_LIST C_127_dummy, HLP;
  MASSTOR_LIST rel, pol, domain, af;

  PHI = MASSTOR_SIL;
  PSI = MASSTOR_SIL;
  GAMMA = MASSTOR_SIL;
  MLOGBASE_FORPFOR(nf, &C_127_dummy, &nf);
  af = MASSTOR_FIRST(MLOGBASE_FORGARGS(MASSTOR_FIRST(nf)));
  PQBASE_pqpaf(af, &C_127_dummy, &pol);
  domain = DIPTOOLS_ADDDFDIP(pol);
  while (nf != MASSTOR_SIL) {
    MLOGBASE_FORPARGS(nf, &clause, &nf);
    MLOGBASE_FORPFOR(clause, &C_127_dummy, &clause);
    POS = MASSTOR_SIL;
    NEG = MASSTOR_SIL;
    while (clause != MASSTOR_SIL) {
      MLOGBASE_FORPARGS(clause, &atomic, &clause);
      PQBASE_pqpaf(atomic, &rel, &pol);
      if (rel == PQBASE_NEQ) {
        NEG = MASSTOR_COMP(pol, NEG);
      } else if (rel == PQBASE_EQU) {
        POS = MASSTOR_COMP(pol, POS);
      } else {
        MASERR_ERROR(MASERR_severe, "unknown relation symbol", 23L);
      }
    }
    if (type != 1) {
      HLP = NEG;
      NEG = POS;
      POS = HLP;
    }
    if (NEG == MASSTOR_SIL) {
      PSI = PQSMPL_SETADD(DIPTOOLS_DILPROD(POS, domain), PSI);
    } else {
      NEG = MASSTOR_INV(NEG);
      POS = DIPTOOLS_DILPROD(POS, domain);
      if (!SeqPair(NEG, PHI, POS, GAMMA)) {
        PHI = MASSTOR_COMP(NEG, PHI);
        GAMMA = MASSTOR_COMP(POS, GAMMA);
      } else {
        PQSMPL_DLSWRITE("identical implications deleted", 30L, 3);
      }
    }
  }
  return SACLIST_LIST3(MASSTOR_INV(PHI), MASSTOR_INV(GAMMA), MASSTOR_INV(PSI));
}

static MASSTOR_LIST PQscnf
# ifdef __STDC__
(MASSTOR_LIST POLS)
# else
(POLS)
MASSTOR_LIST POLS;
# endif
{
  MASSTOR_LIST fst, snd;

  PQsnf1(POLS, 1, &fst, &snd);
  if (fst == MASSTOR_SIL && snd == MASSTOR_SIL) {
    return MLOGBASE_VERUM;
  } else if (fst == MASSTOR_SIL) {
    return MLOGBASE_FORMKFOR(MLOGBASE_ET, MASSTOR_INV(snd));
  } else if (snd == MASSTOR_SIL) {
    return MLOGBASE_FORMKFOR(MLOGBASE_ET, MASSTOR_INV(fst));
  } else {
    return MLOGBASE_FORMKBINOP(MLOGBASE_ET, MLOGBASE_FORMKFOR(MLOGBASE_ET, MASSTOR_INV(fst)), MLOGBASE_FORMKFOR(MLOGBASE_ET, MASSTOR_INV(snd)));
  }
}

static MASSTOR_LIST PQsdnf
# ifdef __STDC__
(MASSTOR_LIST POLS)
# else
(POLS)
MASSTOR_LIST POLS;
# endif
{
  MASSTOR_LIST fst, snd;

  PQsnf1(POLS, 2, &fst, &snd);
  if (fst == MASSTOR_SIL && snd == MASSTOR_SIL) {
    return MLOGBASE_FALSUM;
  } else if (fst == MASSTOR_SIL) {
    return MLOGBASE_FORMKUNOP(MLOGBASE_NON, MLOGBASE_FORMKFOR(MLOGBASE_ET, MASSTOR_INV(snd)));
  } else if (snd == MASSTOR_SIL) {
    return MLOGBASE_FORMKFOR(MLOGBASE_VEL, MASSTOR_INV(fst));
  } else {
    return MLOGBASE_FORMKBINOP(MLOGBASE_VEL, MLOGBASE_FORMKFOR(MLOGBASE_VEL, MASSTOR_INV(fst)), MLOGBASE_FORMKUNOP(MLOGBASE_NON, MLOGBASE_FORMKFOR(MLOGBASE_ET, MASSTOR_INV(snd))));
  }
}

static void PQsnf1
# ifdef __STDC__
(MASSTOR_LIST POLS, MASSTOR_LIST type, MASSTOR_LIST *fst, MASSTOR_LIST *snd)
# else
(POLS, type, fst, snd)
MASSTOR_LIST POLS, type;
MASSTOR_LIST *fst, *snd;
# endif
{
  MASSTOR_LIST PHIij, PHIj, phi, GAMMAi, gamma, PHIj1, PSIi, psi;

  SACLIST_ADV3(POLS, &PHIij, &GAMMAi, &PSIi, &POLS);
  *fst = MASSTOR_SIL;
  while (PHIij != MASSTOR_SIL) {
    MASSTOR_ADV(PHIij, &PHIj, &PHIij);
    MASSTOR_ADV(GAMMAi, &gamma, &GAMMAi);
    PHIj1 = MASSTOR_SIL;
    while (PHIj != MASSTOR_SIL) {
      MASSTOR_ADV(PHIj, &phi, &PHIj);
      PHIj1 = MASSTOR_COMP(PQBASE_pqmkaf(PQBASE_EQU, phi), PHIj1);
    }
    if (type == 1) {
      *fst = MASSTOR_COMP(MLOGBASE_FORMKBINOP(MLOGBASE_IMP, MLOGBASE_FORMKFOR(MLOGBASE_ET, MASSTOR_INV(PHIj1)), PQBASE_pqmkaf(PQBASE_EQU, gamma)), *fst);
    } else {
      *fst = MASSTOR_COMP(MLOGBASE_FORMKUNOP(MLOGBASE_NON, MLOGBASE_FORMKBINOP(MLOGBASE_IMP, MLOGBASE_FORMKFOR(MLOGBASE_ET, MASSTOR_INV(PHIj1)), PQBASE_pqmkaf(PQBASE_EQU, gamma))), *fst);
    }
  }
  *snd = MASSTOR_SIL;
  while (PSIi != MASSTOR_SIL) {
    MASSTOR_ADV(PSIi, &psi, &PSIi);
    *snd = MASSTOR_COMP(PQBASE_pqmkaf(PQBASE_EQU, psi), *snd);
  }
  return;
}

static BOOLEAN TestRMember
# ifdef __STDC__
(MASSTOR_LIST F, MASSTOR_LIST G, MASSTOR_LIST p, MASSTOR_LIST *B, MASSTOR_LIST *p1)
# else
(F, G, p, B, p1)
MASSTOR_LIST F, G, p;
MASSTOR_LIST *B, *p1;
# endif
{
  BOOLEAN result;

  switch ((INTEGER)PQIBREP) {
  case 0:;
    result = TestRMember1(F, G, p, p1);
    *B = F;
    break;
  case 1:;
    *B = PQSMPL_DIPADIRSET(F);
    result = TestRMember1(F, G, p, p1);
    break;
  case 2:;
    *B = PQSMPL_DIPADGB(F);
    result = TestRMember1(MASSTOR_SIL, PQSMPL_DIPADGBunion(*B, G), p, p1);
    break;
  default :
    MASERR_ERROR(MASERR_severe, "PQIBREP unknown code!", 21L);
    break;
  }
  return result;
}

static BOOLEAN TestRMember1
# ifdef __STDC__
(MASSTOR_LIST F, MASSTOR_LIST G, MASSTOR_LIST p, MASSTOR_LIST *p1)
# else
(F, G, p, p1)
MASSTOR_LIST F, G, p;
MASSTOR_LIST *p1;
# endif
{
  MASSTOR_LIST GB, F1, F0, RGB, power, POWERS;
  BOOLEAN result;
  MASSTOR_LIST domain;

  if (p == 0) {
    return TRUE;
  }
  domain = DIPTOOLS_ADDDFDIP(p);
  result = FALSE;
  switch ((INTEGER)PQRMSTest) {
  case 1:;
    result = SACLIST_MEMBER(p, SACLIST_CCONC(G, F)) == 1;
    break;
  case 2:;
    F1 = SACLIST_CCONC(G, F);
    result = SACLIST_MEMBER(p, F1) == 1 || PQSMPL_DIPADNF(F1, p) == 0;
    break;
  case 3:;
    F0 = SACLIST_CCONC(G, F);
    F1 = PQSMPL_DIPADIRSET(F0);
    result = SACLIST_MEMBER(p, F0) == 1 || SACLIST_MEMBER(p, F1) == 1 || PQSMPL_DIPADNF(F1, p) == 0;
    break;
  case 4:;
    GB = PQSMPL_DIPADGBext(G, F);
    result = PQSMPL_IdealMember(GB, p);
    break;
  case 5:;
    POWERS = PQPOWERS;
    if (SACLIST_EQUAL(DIPTOOLS_DIPONE(domain), p) == 1) {
      POWERS = MASSTOR_LIST1(1);
    }
    GB = PQSMPL_DIPADGBext(G, F);
    while (POWERS != MASSTOR_SIL && !result) {
      MASSTOR_ADV(POWERS, &power, &POWERS);
      if (PQSMPL_IdealMember(GB, DIPTOOLS_DIPPOWER(p, power))) {
        result = TRUE;
      }
    }
    break;
  case 6:;
    GB = PQSMPL_DIPADGBext(G, F);
    result = PQSMPL_IdealMember(GB, p) || PQSMPL_RadicalMember(GB, p);
    break;
  case 7:;
    result = PQSMPL_RadicalMember(SACLIST_CCONC(G, F), p);
    break;
  default :
    MASERR_ERROR(MASERR_severe, "TestRMember: unknown code", 25L);
    return FALSE;
    break;
  }
  if (PQRMSTest > 3 && PQREDCON == 1) {
    PQSMPL_DLSWRITE("computing the normal form of the conclusion", 43L, 2);
    *p1 = PQSMPL_DIPADNF(GB, p);
    PQSMPL_DLSWRITE("... finished.", 13L, 2);
  } else {
    *p1 = p;
  }
  if (PQTRACE >= 1) {
    if (result) {
      MASBIOS_SWRITE("Radical membership test ", 24L);
      SACLIST_AWRITE(PQRMSTest);
      MASBIOS_SWRITE(" succeed.", 9L);
      MASBIOS_BLINES(0);
    } else {
      MASBIOS_SWRITE("Radical membership test ", 24L);
      SACLIST_AWRITE(PQRMSTest);
      MASBIOS_SWRITE(" failed.", 8L);
      MASBIOS_BLINES(0);
    }
  }
  return result;
}

BOOLEAN PQSMPL_IdealMember
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST p)
# else
(G, p)
MASSTOR_LIST G, p;
# endif
{
  return PQSMPL_DIPADNF(G, p) == 0;
}

BOOLEAN PQSMPL_RadicalMember
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST p)
# else
(G, p)
MASSTOR_LIST G, p;
# endif
{
  MASSTOR_LIST G1, G2;
  BOOLEAN result;
  MASSTOR_LIST p1;
  MASSTOR_LIST domain;

  if (p == 0) {
    return TRUE;
  }
  domain = DIPTOOLS_ADDDFDIP(p);
  G1 = DIPTOOLS_DILINV(G, 0, 1);
  p1 = DIPC_DIPINV(p, 0, 1);
  DIPTOOLS_ValisPush(MASSTOR_COMP(SACLIST_LIST2(45, 54), DIPC_VALIS));
  G2 = PQSMPL_DIPADGB(MASSTOR_COMP(PQSMPL_rabinowitsch(p1), G1));
  result = PQSMPL_DIPADNF(G2, DIPTOOLS_DIPONE(domain)) == 0;
  DIPTOOLS_ValisPop();
  return result;
}

MASSTOR_LIST PQSMPL_rabinowitsch
# ifdef __STDC__
(MASSTOR_LIST p)
# else
(p)
MASSTOR_LIST p;
# endif
{
  MASSTOR_LIST z, zexp, nov, dipone;
  MASSTOR_LIST domain;

  domain = DIPTOOLS_ADDDFDIP(p);
  nov = DIPC_DIPNOV(p);
  dipone = DIPC_DIPFMO(MASADOM_ADFI(domain, 1), GenEV(0, nov));
  zexp = GenEV(0, nov - 1);
  zexp = MASSTOR_INV(MASSTOR_COMP(1, zexp));
  z = DIPC_DIPFMO(MASADOM_ADFI(domain, 1), zexp);
  return DIPADOM_DIPSUM(dipone, DIPADOM_DIPNEG(DIPADOM_DIPROD(z, p)));
}

MASSTOR_LIST PQSMPL_DIPADGB
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST g;

  PQSMPL_DLSWRITE("Computing a Groebner Base ...", 29L, 2);
  g = DIPGB_DIPGB(P, 0);
  PQSMPL_DLSWRITE("... finished!", 13L, 2);
  return g;
}

MASSTOR_LIST PQSMPL_DIPADNF
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST S)
# else
(P, S)
MASSTOR_LIST P, S;
# endif
{
  return DIPGB_DIPNOR(P, S);
}

MASSTOR_LIST PQSMPL_DILADNF
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST S)
# else
(P, S)
MASSTOR_LIST P, S;
# endif
{
  MASSTOR_LIST s, result;

  result = MASSTOR_SIL;
  while (S != MASSTOR_SIL) {
    MASSTOR_ADV(S, &s, &S);
    result = MASSTOR_COMP(PQSMPL_DIPADNF(P, s), result);
  }
  return MASSTOR_INV(result);
}

MASSTOR_LIST PQSMPL_DIPADGBext
# ifdef __STDC__
(MASSTOR_LIST gb, MASSTOR_LIST pols)
# else
(gb, pols)
MASSTOR_LIST gb, pols;
# endif
{
  if (pols == MASSTOR_SIL) {
    return gb;
  }
  return PQSMPL_DIPADGB(SACLIST_CCONC(gb, pols));
}

MASSTOR_LIST PQSMPL_DIPADGBunion
# ifdef __STDC__
(MASSTOR_LIST gb1, MASSTOR_LIST gb2)
# else
(gb1, gb2)
MASSTOR_LIST gb1, gb2;
# endif
{
  if (gb2 == MASSTOR_SIL) {
    return gb1;
  }
  if (gb1 == MASSTOR_SIL) {
    return gb2;
  }
  return PQSMPL_DIPADGB(SACLIST_CCONC(gb1, gb2));
}

MASSTOR_LIST PQSMPL_DIPADIRSET
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  return DIPGB_DILIS(P);
}

MASSTOR_LIST PQSMPL_DIPADGBRED
# ifdef __STDC__
(MASSTOR_LIST gb)
# else
(gb)
MASSTOR_LIST gb;
# endif
{
  if (gb == MASSTOR_SIL || MASSTOR_RED(gb) == MASSTOR_SIL) {
    return gb;
  }
  return DIPC_DIPLPM(DIPGB_DILIS(gb));
}

MASSTOR_LIST PQSMPL_SETADD
# ifdef __STDC__
(MASSTOR_LIST elem, MASSTOR_LIST set)
# else
(elem, set)
MASSTOR_LIST elem, set;
# endif
{
  if (SACLIST_MEMBER(elem, set) == 1) {
    PQSMPL_DLSWRITE("SETADD: element already in the set!", 35L, 3);
    return set;
  } else {
    return MASSTOR_COMP(elem, set);
  }
}

static MASSTOR_LIST GenEV
# ifdef __STDC__
(MASSTOR_LIST value, MASSTOR_LIST length)
# else
(value, length)
MASSTOR_LIST value, length;
# endif
{
  INTEGER i;
  MASSTOR_LIST result;

  result = MASSTOR_SIL;
  {
    LONGINT B_1 = 1, B_2 = length;

    if (B_1 <= B_2)
      for (i = B_1;; i += 1) {
        result = MASSTOR_COMP(value, result);
        if (i >= B_2) break;
      }
  }
  return result;
}

static BOOLEAN SeqPair
# ifdef __STDC__
(MASSTOR_LIST elem1, MASSTOR_LIST SEQ1, MASSTOR_LIST elem2, MASSTOR_LIST SEQ2)
# else
(elem1, SEQ1, elem2, SEQ2)
MASSTOR_LIST elem1, SEQ1, elem2, SEQ2;
# endif
{
  MASSTOR_LIST seq1, seq2;

  while (SEQ1 != MASSTOR_SIL) {
    MASSTOR_ADV(SEQ1, &seq1, &SEQ1);
    MASSTOR_ADV(SEQ2, &seq2, &SEQ2);
    if (SACLIST_EQUAL(seq1, elem1) == 1 && SACLIST_EQUAL(seq2, elem2) == 1) {
      return TRUE;
    }
  }
  return FALSE;
}

MASSTOR_LIST PQSMPL_PQOPT
# ifdef __STDC__
(MASSTOR_LIST O)
# else
(O)
MASSTOR_LIST O;
# endif
{
  MASSTOR_LIST old;

  old = SACLIST_LIST5(PQTRACE, PQRMSTest, PQPOWERS, PQIBREP, PQREDCON);
  if (O != MASSTOR_SIL) {
    if (MASSTOR_FIRST(O) != -1) {
      MASSTOR_ADV(O, &PQTRACE, &O);
    } else {
      O = MASSTOR_RED(O);
    }
  }
  if (O != MASSTOR_SIL) {
    if (MASSTOR_FIRST(O) != -1) {
      MASSTOR_ADV(O, &PQRMSTest, &O);
    } else {
      O = MASSTOR_RED(O);
    }
  }
  if (O != MASSTOR_SIL) {
    if (MASSTOR_FIRST(O) != -1) {
      MASSTOR_ADV(O, &PQPOWERS, &O);
    } else {
      O = MASSTOR_RED(O);
    }
  }
  if (O != MASSTOR_SIL) {
    if (MASSTOR_FIRST(O) != -1) {
      MASSTOR_ADV(O, &PQIBREP, &O);
    } else {
      O = MASSTOR_RED(O);
    }
  }
  if (O != MASSTOR_SIL) {
    if (MASSTOR_FIRST(O) != -1) {
      MASSTOR_ADV(O, &PQREDCON, &O);
    } else {
      O = MASSTOR_RED(O);
    }
  }
  return old;
}

void PQSMPL_PQOPTWR
# ifdef __STDC__
()
# else
()
# endif
{
  MASBIOS_SWRITE("The setting of the options of the PQ-System:", 44L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("  The trace level is ", 21L);
  SACLIST_AWRITE(PQTRACE);
  MASBIOS_SWRITE(".", 1L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("  Radical memebership test using ", 33L);
  MASBIOS_BLINES(0);
  switch ((INTEGER)PQRMSTest) {
  case 1:;
    MASBIOS_SWRITE("    element test.", 17L);
    break;
  case 2:;
    MASBIOS_SWRITE("    reduction with the ideal basis.", 35L);
    break;
  case 3:;
    MASBIOS_SWRITE("    reduction with the interreduced ideal basis.", 48L);
    break;
  case 4:;
    MASBIOS_SWRITE("    ideal membership test.", 26L);
    break;
  case 5:;
    MASBIOS_SWRITE("    ideal membership test with the ", 35L);
    if (MASSTOR_RED(PQPOWERS) == MASSTOR_SIL) {
      MASBIOS_SWRITE("power ", 6L);
      SACLIST_AWRITE(MASSTOR_FIRST(PQPOWERS));
    } else {
      MASBIOS_SWRITE("powers ", 7L);
      MASSYM2_UWRIT1(PQPOWERS);
    }
    MASBIOS_SWRITE(".", 1L);
    break;
  case 6:;
    MASBIOS_SWRITE("    radical membership test after ideal membership test.", 56L);
    break;
  case 7:;
    MASBIOS_SWRITE("    radical membership test.", 28L);
    break;
  default :
    MASBIOS_SWRITE("    unknown test method specified!", 34L);
    break;
  }
  MASBIOS_BLINES(0);
  switch ((INTEGER)PQIBREP) {
  case 0:;
    MASBIOS_SWRITE("  Conjunctions over polynomial equations are not replaced.", 58L);
    break;
  case 1:;
    MASBIOS_SWRITE("  Reducing conjunctions over polynomial equations with the", 58L);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("    interreduction-method.", 26L);
    break;
  case 2:;
    MASBIOS_SWRITE("  Reducing conjunctions over polynomial equations with the", 58L);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("    Groebner-Basis-method.", 26L);
    break;
  default :
    MASBIOS_SWRITE("WARNING: unknown code for PQIBREP", 33L);
    break;
  }
  MASBIOS_BLINES(0);
  if (PQREDCON == 0) {
    MASBIOS_SWRITE("  The conclusions in the implications are not reduced.", 54L);
  } else {
    MASBIOS_SWRITE("  The conclusions in the implications are reduced.", 50L);
  }
  MASBIOS_BLINES(0);
}

static MASSTOR_LIST PQSetTrace
# ifdef __STDC__
(MASSTOR_LIST level)
# else
(level)
MASSTOR_LIST level;
# endif
{
  MASSTOR_LIST old;

  old = PQTRACE;
  PQTRACE = level;
  return old;
}

static MASSTOR_LIST PQGetTrace
# ifdef __STDC__
()
# else
()
# endif
{
  return PQTRACE;
}

void PQSMPL_DLSWRITE
# ifdef __STDC__
(CHAR S[], LONGCARD O_1, MASSTOR_LIST level)
# else
(S, O_1, level)
CHAR S[];
LONGCARD O_1;
MASSTOR_LIST level;
# endif
{
  OPEN_ARRAY_LOCALS

  ALLOC_OPEN_ARRAYS(O_1 * sizeof(CHAR), 1)
  COPY_OPEN_ARRAY(S, O_1, CHAR)
  if (PQTRACE >= level) {
    MASBIOS_SWRITE(S, O_1);
    MASBIOS_BLINES(0);
  }
  FREE_OPEN_ARRAYS
}

static void DLSWRIT1
# ifdef __STDC__
(CHAR S[], LONGCARD O_2, MASSTOR_LIST level)
# else
(S, O_2, level)
CHAR S[];
LONGCARD O_2;
MASSTOR_LIST level;
# endif
{
  OPEN_ARRAY_LOCALS

  ALLOC_OPEN_ARRAYS(O_2 * sizeof(CHAR), 1)
  COPY_OPEN_ARRAY(S, O_2, CHAR)
  if (PQTRACE >= level) {
    MASBIOS_SWRITE(S, O_2);
  }
  FREE_OPEN_ARRAYS
}

static void DLUWRITE
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST level)
# else
(L, level)
MASSTOR_LIST L, level;
# endif
{
  if (PQTRACE >= level) {
    MASSYM2_UWRITE(L);
  }
}

static void DLUWRIT1
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST level)
# else
(L, level)
MASSTOR_LIST L, level;
# endif
{
  if (PQTRACE >= level) {
    MASSYM2_UWRIT1(L);
  }
}

static void DLBLINES
# ifdef __STDC__
(MASSTOR_LIST n, MASSTOR_LIST level)
# else
(n, level)
MASSTOR_LIST n;
MASSTOR_LIST level;
# endif
{
  if (PQTRACE >= level) {
    MASBIOS_BLINES(n);
  }
}

static void DLPQPRT
# ifdef __STDC__
(CHAR S[], LONGCARD O_3, MASSTOR_LIST phi, MASSTOR_LIST level)
# else
(S, O_3, phi, level)
CHAR S[];
LONGCARD O_3;
MASSTOR_LIST phi;
MASSTOR_LIST level;
# endif
{
  OPEN_ARRAY_LOCALS

  ALLOC_OPEN_ARRAYS(O_3 * sizeof(CHAR), 1)
  COPY_OPEN_ARRAY(S, O_3, CHAR)
  if (PQTRACE >= level) {
    MASBIOS_SWRITE(S, O_3);
    MASBIOS_BLINES(0);
    PQBASE_PQPPRT(phi);
    MASBIOS_BLINES(0);
  }
  FREE_OPEN_ARRAYS
}

void PQSMPL_PQDEMO
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST V, phi;

  MASBIOS_SWRITE("           ", 11L);
  MASBIOS_SWRITE("D E M O N S T R A T I O N   O F   T H E   P Q - S Y S T E M", 59L);
  MASBIOS_BLINES(2);
  MASBIOS_SWRITE("Enter the list of variables, please!", 36L);
  MASBIOS_BLINES(1);
  V = MASSYM2_UREAD();
  DIPC_VALIS = V;
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("Enter the formula, please!", 26L);
  MASBIOS_BLINES(1);
  phi = PQBASE_PQIREAD();
  phi = PQSMPL_PQCnfSimplify(phi);
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("The result is:", 14L);
  PQBASE_PQPPRT(phi);
  MASBIOS_BLINES(2);
}

void BEGIN_PQSMPL()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASLISPU();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_MASBIOS();
    BEGIN_SACLIST();
    BEGIN_MASERR();
    BEGIN_MASSYM();
    BEGIN_MASSYM2();
    BEGIN_MASLISPU();
    BEGIN_MLOGBASE();
    BEGIN_MASLOG();
    BEGIN_MLOGIO();
    BEGIN_DIPADOM();
    BEGIN_DIPC();
    BEGIN_DIPGB();
    BEGIN_MASADOM();
    BEGIN_SACSET();
    BEGIN_SACPOL();
    BEGIN_PQBASE();
    BEGIN_DIPTOOLS();

    MASSTOR_LISTVAR(&PQRMSTest);
    MASSTOR_LISTVAR(&PQPOWERS);
    MASSTOR_LISTVAR(&PQTRACE);
    MASSTOR_LISTVAR(&PQIBREP);
    MASSTOR_LISTVAR(&PQREDCON);
    PQTRACE = 0;
    PQPOWERS = MASSTOR_LIST1(1);
    PQRMSTest = 6;
    PQIBREP = 1;
    PQREDCON = 0;
  }
}
