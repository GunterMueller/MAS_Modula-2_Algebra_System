#include "SYSTEM_.h"

#ifndef DEFINITION_DIPADOM
#include "DIPADOM.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPGB
#include "DIPGB.h"
#endif

#ifndef DEFINITION_DIPTOOLS
#include "DIPTOOLS.h"
#endif

#ifndef DEFINITION_MASADOM
#include "MASADOM.h"
#endif

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

#ifndef DEFINITION_MASNCC
#include "MASNCC.h"
#endif

#ifndef DEFINITION_MASRN
#include "MASRN.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_massig
#include "massig.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_SACRN
#include "SACRN.h"
#endif

#ifndef DEFINITION_DIPAGB
#include "DIPAGB.h"
#endif

CHAR DIPAGB_rcsid [] = "$Id: DIPAGB.md,v 1.3 1994/10/13 15:58:20 rose Exp $";
CHAR DIPAGB_copyright [] = "Copyright (c) 1989 - 1994 Universitaet Passau";

static struct S_1 {
    CARDINAL TraceFlag;
    CARDINAL Strategy;
    MASSTOR_LIST VariableWeight;
    MASLISPU_PROCP0 UpdateVariableWeight;
    MASLISPU_PROCP1V2 Update;
    MASLISPU_PROCP1V2 InitUpdate;
    MASLISPU_PROCF2 CPExtend;
    MASLISPU_PROCF1 DIPExtend;
    MASLISPU_PROCF2 ECPInsert;
    MASLISPU_PROCP1V2 ECPSelect;
    MASLISPU_PROCP1 ECPWrite;
    MASLISPU_PROCF2 EDIPNormalform;
    MASLISPU_PROCF2 EDIPSPolynomial;
    MASLISPU_PROCF1 EDIPUnExtend;
    MASLISPU_PROCP1 EDIPWrite;
} DIPAGBOpt;
static MASSTOR_LIST *pG, *pB, *pcell, *ptime, *predsum, *prednum;
static CHAR rcsidi [] = "$Id: DIPAGB.mi,v 1.5 1995/11/04 20:39:35 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1994 Universitaet Passau";
static MASSTOR_LIST CPCON ARGS((MASSTOR_LIST f, MASSTOR_LIST g));
static MASSTOR_LIST IDF1 ARGS((MASSTOR_LIST L));
static void NOP ARGS(());
static void SigUsr1HandleDIPAGB ARGS((INTEGER signo));
static void EDIPNORWRITE ARGS((MASSTOR_LIST f));
static MASSTOR_LIST ECPNORCON ARGS((MASSTOR_LIST f, MASSTOR_LIST g));
static MASSTOR_LIST ECPNORINS ARGS((MASSTOR_LIST CP, MASSTOR_LIST P));
static void ECPNORWRITE ARGS((MASSTOR_LIST CP));
static MASSTOR_LIST DIPSUGEXT ARGS((MASSTOR_LIST f));
static void EDIPSUGWRITE ARGS((MASSTOR_LIST f));
static MASSTOR_LIST ECPSUGCON ARGS((MASSTOR_LIST f, MASSTOR_LIST g));
static MASSTOR_LIST ECPSUGINS ARGS((MASSTOR_LIST CP, MASSTOR_LIST P));
static void ECPSUGWRITE ARGS((MASSTOR_LIST CP));
static void SugarUpdateVariableWeight ARGS(());
static void InitDIPAGB ARGS(());


MASSTOR_LIST DIPAGB_DIPAGB
# ifdef __STDC__
(MASSTOR_LIST F)
# else
(F)
MASSTOR_LIST F;
# endif
{
  MASSTOR_LIST G, B, g1g2, f, g1, g2, h, g, W, V, v, cell, time, redtime, redsum, rednum;
  BOOLEAN ProperId;
  massig_Action sighandleold;

  cell = MASSTOR_CELLS();
  pcell = (LONGINT *)ADR(cell);
  time = MASSTOR_TIME();
  ptime = (LONGINT *)ADR(time);
  redtime = 0;
  redsum = 0;
  predsum = (LONGINT *)ADR(redsum);
  rednum = 0;
  prednum = (LONGINT *)ADR(rednum);
  ProperId = TRUE;
  DIPAGB_UpdateVariableWeight();
  G = MASSTOR_SIL;
  B = MASSTOR_SIL;
  while (F != MASSTOR_SIL) {
    MASSTOR_ADV(F, &f, &F);
    DIPAGB_INITUPDATE(DIPAGB_DIPEXTEND(f), &G, &B);
  }
  pG = (LONGINT *)ADR(G);
  pB = (LONGINT *)ADR(B);
  sighandleold = signal(massig_SIGUSR1, SigUsr1HandleDIPAGB);
  while (B != MASSTOR_SIL) {
    DIPAGB_ECPSELECT(B, &g1g2, &B);
    g1 = DIPAGB_ECPPOLY1(g1g2);
    g2 = DIPAGB_ECPPOLY2(g1g2);
    f = DIPAGB_EDIPSP(g1, g2);
    rednum = rednum + 1;
    if (DIPAGBOpt.TraceFlag >= 4) {
      SACLIST_AWRITE(rednum);
      switch (rednum) {
      case 1:;
        MASBIOS_SWRITE("st polynomial to reduce to normalform: ", 39L);
        break;
      case 2:;
        MASBIOS_SWRITE("nd polynomial to reduce to normalform: ", 39L);
        break;
      case 3:;
        MASBIOS_SWRITE("rd polynomial to reduce to normalform: ", 39L);
        break;
      default :
        MASBIOS_SWRITE("th polynomial to reduce to normalform: ", 39L);
        break;
      }
      MASBIOS_BLINES(0);
      MASBIOS_SWRITE("  ", 2L);
      DIPADOM_DIWRIT(DIPAGB_EDIPUNEXTEND(f), DIPC_VALIS);
      MASBIOS_BLINES(1);
    }
    redtime = MASSTOR_TIME();
    h = DIPAGB_EDIPNOR(G, f);
    redsum = redsum + MASSTOR_TIME() - redtime;
    g = DIPAGB_EDIPUNEXTEND(h);
    if (g != 0) {
      if (!DIPTOOLS_DIPCNST(g)) {
        (*DIPAGBOpt.Update)(h, &G, &B);
      } else {
        ProperId = FALSE;
        G = MASSTOR_LIST1(DIPTOOLS_DIPONE(DIPTOOLS_ADDDFDIP(g)));
        B = MASSTOR_SIL;
      }
    }
  }
  if (DIPAGBOpt.TraceFlag >= 2) {
    SACLIST_AWRITE(rednum);
    MASBIOS_SWRITE(" normalform computations in ", 28L);
    SACLIST_AWRITE(redsum);
    MASBIOS_SWRITE(" milliseconds. ", 15L);
    MASBIOS_BLINES(1);
  }
  if (ProperId) {
    G = DIPAGB_LEDIPUNEXTEND(G);
  }
  if (DIPAGBOpt.TraceFlag >= 1) {
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("Total time: ", 12L);
    SACLIST_AWRITE(MASSTOR_TIME() - time);
    MASBIOS_SWRITE(" milliseconds.", 14L);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("     Cells: ", 12L);
    SACLIST_AWRITE(MASSTOR_CELLS() - cell);
    MASBIOS_SWRITE(".", 1L);
    MASBIOS_BLINES(1);
  }
  sighandleold = signal(massig_SIGUSR1, sighandleold);
  return G;
}

void DIPAGB_UPDATE
# ifdef __STDC__
(MASSTOR_LIST h, MASSTOR_LIST *G, MASSTOR_LIST *B)
# else
(h, G, B)
MASSTOR_LIST h;
MASSTOR_LIST *G, *B;
# endif
{
  MASSTOR_LIST Bnew, Gnew, C, D, E, CC, DD, CP, hg, hg1, hg2, g1g2, g, g1, g2, HTg, HTg1, HTg2, HTh, FL;

  C = MASSTOR_SIL;
  D = *G;
  while (D != MASSTOR_SIL) {
    MASSTOR_ADV(D, &g1, &D);
    C = DIPAGB_ECPINSERT(DIPAGB_CPEXTEND(h, g1), C);
  }
  HTh = DIPAGB_EDIPEVL(h);
  while (C != MASSTOR_SIL) {
    MASSTOR_ADV(C, &hg1, &C);
    g1 = DIPAGB_ECPPOLY2(hg1);
    HTg1 = DIPAGB_EDIPEVL(g1);
    if (DIPC_EVNNZE(MASNCC_EVGCD(HTh, HTg1)) == 0) {
      D = MASSTOR_COMP(hg1, D);
    } else {
      CC = C;
      FL = 0;
      while (CC != MASSTOR_SIL && FL == 0) {
        MASSTOR_ADV(CC, &hg2, &CC);
        FL = DIPC_EVMT(DIPAGB_ECPLCMHT(hg1), DIPAGB_ECPLCMHT(hg2));
      }
      if (FL == 0) {
        DD = D;
        while (DD != MASSTOR_SIL && FL == 0) {
          MASSTOR_ADV(DD, &hg2, &DD);
          FL = DIPC_EVMT(DIPAGB_ECPLCMHT(hg1), DIPAGB_ECPLCMHT(hg2));
        }
      }
      if (FL == 0) {
        D = MASSTOR_COMP(hg1, D);
      }
    }
  }
  E = MASSTOR_SIL;
  while (D != MASSTOR_SIL) {
    MASSTOR_ADV(D, &hg, &D);
    g = DIPAGB_ECPPOLY2(hg);
    HTg = DIPAGB_EDIPEVL(g);
    if (DIPC_EVNNZE(MASNCC_EVGCD(HTh, HTg)) > 0) {
      E = MASSTOR_COMP(hg, E);
    }
  }
  while (*B != MASSTOR_SIL) {
    MASSTOR_ADV(*B, &g1g2, B);
    g1 = DIPAGB_ECPPOLY1(g1g2);
    g2 = DIPAGB_ECPPOLY2(g1g2);
    HTg1 = DIPAGB_EDIPEVL(g1);
    HTg2 = DIPAGB_EDIPEVL(g2);
    if (DIPC_EVMT(DIPAGB_ECPLCMHT(g1g2), HTh) == 0 || DIPC_EVCOMP(DIPC_EVLCM(HTg1, HTh), DIPAGB_ECPLCMHT(g1g2)) == 0 || DIPC_EVCOMP(DIPC_EVLCM(HTh, HTg2), DIPAGB_ECPLCMHT(g1g2)) == 0) {
      E = DIPAGB_ECPINSERT(g1g2, E);
    }
  }
  Bnew = E;
  Gnew = MASSTOR_SIL;
  while (*G != MASSTOR_SIL) {
    MASSTOR_ADV(*G, &g, G);
    HTg = DIPAGB_EDIPEVL(g);
    if (DIPC_EVMT(HTg, HTh) == 0) {
      Gnew = MASSTOR_COMP(g, Gnew);
    }
  }
  Gnew = MASSTOR_COMP(h, Gnew);
  *G = Gnew;
  *B = Bnew;
}

MASSTOR_LIST DIPAGB_DIPEXTEND
# ifdef __STDC__
(MASSTOR_LIST f)
# else
(f)
MASSTOR_LIST f;
# endif
{
  MASSTOR_LIST Ef;
  CARDINAL i;

  Ef = (*DIPAGBOpt.DIPExtend)(f);
  if (DIPAGBOpt.TraceFlag >= 8) {
    MASBIOS_SWRITE("Extending the polynomial", 24L);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("    ", 4L);
    DIPAGB_EDIPWRITE(Ef);
    for (i = 1; i <= 79; i += 1) {
      MASBIOS_SWRITE("-", 1L);
    }
    MASBIOS_BLINES(1);
  }
  return Ef;
}

MASSTOR_LIST DIPAGB_LDIPEXTEND
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST p, Q;

  Q = MASSTOR_SIL;
  while (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, &p, &P);
    Q = MASSTOR_COMP(DIPAGB_DIPEXTEND(p), Q);
  }
  return Q;
}

MASSTOR_LIST DIPAGB_EDIPEVL
# ifdef __STDC__
(MASSTOR_LIST f)
# else
(f)
MASSTOR_LIST f;
# endif
{
  return DIPC_DIPEVL(DIPAGB_EDIPUNEXTEND(f));
}

MASSTOR_LIST DIPAGB_EDIPNOR
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST f)
# else
(P, f)
MASSTOR_LIST P, f;
# endif
{
  MASSTOR_LIST g;
  CARDINAL i;

  g = (*DIPAGBOpt.EDIPNormalform)(P, f);
  if (DIPAGBOpt.TraceFlag >= 5) {
    MASBIOS_SWRITE("The normalform is", 17L);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("  ", 2L);
    DIPAGB_EDIPWRITE(g);
    for (i = 1; i <= 79; i += 1) {
      MASBIOS_SWRITE("-", 1L);
    }
    MASBIOS_BLINES(1);
  }
  return g;
}

MASSTOR_LIST DIPAGB_EDIPSP
# ifdef __STDC__
(MASSTOR_LIST f, MASSTOR_LIST g)
# else
(f, g)
MASSTOR_LIST f, g;
# endif
{
  MASSTOR_LIST SP;
  CARDINAL i;

  SP = (*DIPAGBOpt.EDIPSPolynomial)(f, g);
  if (DIPAGBOpt.TraceFlag >= 9) {
    MASBIOS_SWRITE("Computing the S-polynomial of the following two ", 48L);
    MASBIOS_SWRITE("distributive polynomials:", 25L);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("f = ", 4L);
    DIPAGB_EDIPWRITE(f);
    MASBIOS_SWRITE("g = ", 4L);
    DIPAGB_EDIPWRITE(g);
    MASBIOS_SWRITE("==> Spol(f,g) = ", 16L);
    DIPAGB_EDIPWRITE(SP);
    for (i = 1; i <= 79; i += 1) {
      MASBIOS_SWRITE("-", 1L);
    }
    MASBIOS_BLINES(1);
  }
  return SP;
}

MASSTOR_LIST DIPAGB_EDIPUNEXTEND
# ifdef __STDC__
(MASSTOR_LIST f)
# else
(f)
MASSTOR_LIST f;
# endif
{
  return (*DIPAGBOpt.EDIPUnExtend)(f);
}

MASSTOR_LIST DIPAGB_LEDIPUNEXTEND
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST p, Q;

  Q = MASSTOR_SIL;
  while (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, &p, &P);
    Q = MASSTOR_COMP(DIPAGB_EDIPUNEXTEND(p), Q);
  }
  return Q;
}

void DIPAGB_EDIPWRITE
# ifdef __STDC__
(MASSTOR_LIST f)
# else
(f)
MASSTOR_LIST f;
# endif
{
  (*DIPAGBOpt.EDIPWrite)(f);
}

void DIPAGB_LEDIPWRITE
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST p, i;

  i = 0;
  while (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, &p, &P);
    i = i + 1;
    SACLIST_AWRITE(i);
    switch (i) {
    case 1:;
      MASBIOS_SWRITE("st polynomial: ", 15L);
      break;
    case 2:;
      MASBIOS_SWRITE("nd polynomial: ", 15L);
      break;
    case 3:;
      MASBIOS_SWRITE("rd polynomial: ", 15L);
      break;
    default :
      MASBIOS_SWRITE("th polynomial: ", 15L);
      break;
    }
    DIPAGB_EDIPWRITE(p);
  }
}

MASSTOR_LIST DIPAGB_CPEXTEND
# ifdef __STDC__
(MASSTOR_LIST f, MASSTOR_LIST g)
# else
(f, g)
MASSTOR_LIST f, g;
# endif
{
  MASSTOR_LIST ECP;
  CARDINAL i;

  ECP = (*DIPAGBOpt.CPExtend)(f, g);
  if (DIPAGBOpt.TraceFlag >= 8) {
    MASBIOS_SWRITE("Extending the following critical pair:", 38L);
    MASBIOS_BLINES(0);
    DIPAGB_ECPWRITE(ECP);
    MASBIOS_BLINES(1);
    for (i = 1; i <= 79; i += 1) {
      MASBIOS_SWRITE("-", 1L);
    }
    MASBIOS_BLINES(1);
  }
  return ECP;
}

MASSTOR_LIST DIPAGB_ECPINSERT
# ifdef __STDC__
(MASSTOR_LIST CP, MASSTOR_LIST P)
# else
(CP, P)
MASSTOR_LIST CP, P;
# endif
{
  CARDINAL i;

  P = (*DIPAGBOpt.ECPInsert)(CP, P);
  if (DIPAGBOpt.TraceFlag >= 7) {
    MASBIOS_SWRITE("Inserting the following extended critical pair:", 47L);
    MASBIOS_BLINES(0);
    DIPAGB_ECPWRITE(CP);
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("==> New extended critical pair list:", 36L);
    MASBIOS_BLINES(0);
    DIPAGB_LECPWRITE(P);
    for (i = 1; i <= 79; i += 1) {
      MASBIOS_SWRITE("-", 1L);
    }
    MASBIOS_BLINES(1);
  }
  return P;
}

MASSTOR_LIST DIPAGB_ECPLCMHT
# ifdef __STDC__
(MASSTOR_LIST CP)
# else
(CP)
MASSTOR_LIST CP;
# endif
{
  return SACLIST_THIRD(CP);
}

MASSTOR_LIST DIPAGB_ECPPOLY1
# ifdef __STDC__
(MASSTOR_LIST CP)
# else
(CP)
MASSTOR_LIST CP;
# endif
{
  return MASSTOR_FIRST(CP);
}

MASSTOR_LIST DIPAGB_ECPPOLY2
# ifdef __STDC__
(MASSTOR_LIST CP)
# else
(CP)
MASSTOR_LIST CP;
# endif
{
  return SACLIST_SECOND(CP);
}

void DIPAGB_ECPSELECT
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST *CP, MASSTOR_LIST *Q)
# else
(P, CP, Q)
MASSTOR_LIST P;
MASSTOR_LIST *CP, *Q;
# endif
{
  (*DIPAGBOpt.ECPSelect)(P, CP, Q);
}

MASSTOR_LIST DIPAGB_ECPUNEXTEND
# ifdef __STDC__
(MASSTOR_LIST CP)
# else
(CP)
MASSTOR_LIST CP;
# endif
{
  MASSTOR_LIST f, g;

  f = DIPAGB_ECPPOLY1(CP);
  g = DIPAGB_ECPPOLY2(CP);
  return CPCON(DIPAGB_EDIPUNEXTEND(f), DIPAGB_EDIPUNEXTEND(g));
}

MASSTOR_LIST DIPAGB_LECPUNEXTEND
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST CP, Q;

  Q = MASSTOR_SIL;
  while (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, &CP, &P);
    Q = MASSTOR_COMP(DIPAGB_ECPUNEXTEND(CP), Q);
  }
  return Q;
}

void DIPAGB_ECPWRITE
# ifdef __STDC__
(MASSTOR_LIST CP)
# else
(CP)
MASSTOR_LIST CP;
# endif
{
  (*DIPAGBOpt.ECPWrite)(CP);
}

void DIPAGB_LECPWRITE
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST CP, i;

  i = 0;
  while (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, &CP, &P);
    i = i + 1;
    SACLIST_AWRITE(i);
    switch (i) {
    case 1:;
      MASBIOS_SWRITE("st critical pair: ", 18L);
      break;
    case 2:;
      MASBIOS_SWRITE("nd critical pair: ", 18L);
      break;
    case 3:;
      MASBIOS_SWRITE("rd critical pair: ", 18L);
      break;
    default :
      MASBIOS_SWRITE("th critical pair: ", 18L);
      break;
    }
    MASBIOS_BLINES(0);
    DIPAGB_ECPWRITE(CP);
    MASBIOS_BLINES(1);
  }
}

MASSTOR_LIST DIPAGB_ADDNFEDIP
# ifdef __STDC__
(MASSTOR_LIST f)
# else
(f)
MASSTOR_LIST f;
# endif
{
  return DIPTOOLS_ADDNFDIP(DIPAGB_EDIPUNEXTEND(f));
}

static MASSTOR_LIST CPCON
# ifdef __STDC__
(MASSTOR_LIST f, MASSTOR_LIST g)
# else
(f, g)
MASSTOR_LIST f, g;
# endif
{
  return SACLIST_LIST2(f, g);
}

MASSTOR_LIST DIPAGB_DIPRWTDG
# ifdef __STDC__
(MASSTOR_LIST f, MASSTOR_LIST W)
# else
(f, W)
MASSTOR_LIST f, W;
# endif
{
  MASSTOR_LIST TD, g, C_119_A, EV;

  if (f == 0) {
    return 0;
  }
  g = f;
  TD = 0;
  while (g != MASSTOR_SIL) {
    DIPC_DIPMAD(g, &C_119_A, &EV, &g);
    TD = MASRN_RNMAX(TD, DIPAGB_EVRWTDEG(EV, W));
  }
  if (DIPAGBOpt.TraceFlag >= 6) {
    MASBIOS_SWRITE("The rational-weighted total degree of the polynomial", 52L);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("  ", 2L);
    DIPADOM_DIWRIT(f, DIPC_VALIS);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("w.r.t. the variable list", 24L);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("  ", 2L);
    SACPOL_VLWRIT(DIPC_VALIS);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("and the variable weight list", 28L);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("  ", 2L);
    DIPAGB_LRNWRIT(SACLIST_CINV(W));
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("is ", 3L);
    SACRN_RNWRIT(TD);
    MASBIOS_SWRITE(".", 1L);
    MASBIOS_BLINES(1);
  }
  return TD;
}

MASSTOR_LIST DIPAGB_EVRWTDEG
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST W)
# else
(U, W)
MASSTOR_LIST U, W;
# endif
{
  MASSTOR_LIST TD, Ui, Wi;

  TD = 0;
  while (U != MASSTOR_SIL) {
    MASSTOR_ADV(U, &Ui, &U);
    MASSTOR_ADV(W, &Wi, &W);
    if (Ui >= MASSTOR_BETA) {
      MASERR_ERROR(MASERR_severe, "EVRWTDEG: exponent out of range", 31L);
      return MASSTOR_SIL;
    }
    TD = SACRN_RNSUM(TD, SACRN_RNPROD(Wi, SACRN_RNINT(Ui)));
  }
  return TD;
}

static MASSTOR_LIST IDF1
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  return L;
}

void DIPAGB_INITUPDATE
# ifdef __STDC__
(MASSTOR_LIST f, MASSTOR_LIST *G, MASSTOR_LIST *B)
# else
(f, G, B)
MASSTOR_LIST f;
MASSTOR_LIST *G, *B;
# endif
{
  (*DIPAGBOpt.InitUpdate)(f, G, B);
}

void DIPAGB_LRNWRIT
# ifdef __STDC__
(MASSTOR_LIST LRN)
# else
(LRN)
MASSTOR_LIST LRN;
# endif
{
  MASSTOR_LIST RN;

  MASBIOS_SWRITE("(", 1L);
  if (LRN != MASSTOR_SIL) {
    MASSTOR_ADV(LRN, &RN, &LRN);
    SACRN_RNWRIT(RN);
  }
  while (LRN != MASSTOR_SIL) {
    MASSTOR_ADV(LRN, &RN, &LRN);
    MASBIOS_SWRITE(",", 1L);
    SACRN_RNWRIT(RN);
  }
  MASBIOS_SWRITE(")", 1L);
}

static void NOP
# ifdef __STDC__
()
# else
()
# endif
{
}

void DIPAGB_UpdateVariableWeight
# ifdef __STDC__
()
# else
()
# endif
{
  (*DIPAGBOpt.UpdateVariableWeight)();
}

static void SigUsr1HandleDIPAGB
# ifdef __STDC__
(INTEGER signo)
# else
(signo)
INTEGER signo;
# endif
{
  massig_Action C_118_dummy;
  MASSTOR_LIST Dummy;
  CARDINAL i;

  C_118_dummy = signal(massig_SIGUSR1, massig_SIG_IGN);
  Dummy = MASBIOS_SOUNIT("CON:x", 5L);
  MASBIOS_BLINES(0);
  for (i = 1; i <= 79; i += 1) {
    MASBIOS_SWRITE("-", 1L);
  }
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("SIGUSR1 received in DIPAGB:", 27L);
  MASBIOS_BLINES(1);
  SACLIST_AWRITE(*prednum);
  MASBIOS_SWRITE(" normalform computations in ", 28L);
  SACLIST_AWRITE(*predsum);
  MASBIOS_SWRITE(" milliseconds up to now. ", 25L);
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("Total time up to now:      ", 27L);
  SACLIST_AWRITE(MASSTOR_TIME() - *ptime);
  MASBIOS_SWRITE(" milliseconds.", 14L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("Number of cells up to now: ", 27L);
  SACLIST_AWRITE(MASSTOR_CELLS() - *pcell);
  MASBIOS_SWRITE(".", 1L);
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("Already computed polynomials of the Groebner Basis:", 51L);
  MASBIOS_BLINES(1);
  DIPAGB_LEDIPWRITE(*pG);
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("Actual extended critical pair list:", 35L);
  MASBIOS_BLINES(1);
  DIPAGB_LECPWRITE(*pB);
  MASBIOS_BLINES(1);
  for (i = 1; i <= 79; i += 1) {
    MASBIOS_SWRITE("-", 1L);
  }
  MASBIOS_BLINES(1);
  Dummy = MASBIOS_CUNIT("CON:x", 5L);
  C_118_dummy = signal(massig_SIGUSR1, SigUsr1HandleDIPAGB);
}

static void EDIPNORWRITE
# ifdef __STDC__
(MASSTOR_LIST f)
# else
(f)
MASSTOR_LIST f;
# endif
{
  DIPADOM_DIWRIT(DIPAGB_EDIPUNEXTEND(f), DIPC_VALIS);
  MASBIOS_BLINES(1);
}

static MASSTOR_LIST ECPNORCON
# ifdef __STDC__
(MASSTOR_LIST f, MASSTOR_LIST g)
# else
(f, g)
MASSTOR_LIST f, g;
# endif
{
  MASSTOR_LIST HTf, HTg;

  HTf = DIPAGB_EDIPEVL(f);
  HTg = DIPAGB_EDIPEVL(g);
  return SACLIST_LIST3(f, g, DIPC_EVLCM(HTf, HTg));
}

static MASSTOR_LIST ECPNORINS
# ifdef __STDC__
(MASSTOR_LIST CP, MASSTOR_LIST P)
# else
(CP, P)
MASSTOR_LIST CP, P;
# endif
{
  MASSTOR_LIST PP, PPR, LCMCP;

  if (P == MASSTOR_SIL) {
    return MASSTOR_LIST1(CP);
  }
  LCMCP = DIPAGB_ECPLCMHT(CP);
  if (DIPC_EVCOMP(DIPAGB_ECPLCMHT(MASSTOR_FIRST(P)), LCMCP) >= 0) {
    return MASSTOR_COMP(CP, P);
  }
  PP = P;
  PPR = MASSTOR_RED(PP);
  while (PPR != MASSTOR_SIL && DIPC_EVCOMP(DIPAGB_ECPLCMHT(MASSTOR_FIRST(PPR)), LCMCP) == -1) {
    PP = PPR;
    PPR = MASSTOR_RED(PP);
  }
  MASSTOR_SRED(PP, MASSTOR_COMP(CP, PPR));
  return P;
}

static void ECPNORWRITE
# ifdef __STDC__
(MASSTOR_LIST CP)
# else
(CP)
MASSTOR_LIST CP;
# endif
{
  MASSTOR_LIST f, g, Cf, Ef, Rf;

  f = DIPAGB_EDIPUNEXTEND(DIPAGB_ECPPOLY1(CP));
  g = DIPAGB_EDIPUNEXTEND(DIPAGB_ECPPOLY2(CP));
  MASBIOS_SWRITE("1st polynomial: ", 16L);
  DIPADOM_DIWRIT(f, DIPC_VALIS);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("2nd polynomial: ", 16L);
  DIPADOM_DIWRIT(g, DIPC_VALIS);
  MASBIOS_BLINES(0);
  DIPC_DIPMAD(f, &Cf, &Ef, &Rf);
  MASBIOS_SWRITE("LCM of their leading terms:", 27L);
  DIPADOM_DIWRIT(DIPC_DIPFMO(MASADOM_ADFI(Cf, 1), DIPAGB_ECPLCMHT(CP)), DIPC_VALIS);
  MASBIOS_BLINES(0);
}

static MASSTOR_LIST DIPSUGEXT
# ifdef __STDC__
(MASSTOR_LIST f)
# else
(f)
MASSTOR_LIST f;
# endif
{
  MASSTOR_LIST W;

  W = DIPAGBOpt.VariableWeight;
  return DIPAGB_EDIPSUGCON(f, DIPAGB_DIPRWTDG(f, W));
}

MASSTOR_LIST DIPAGB_EDIIFSUGNF
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST f)
# else
(P, f)
MASSTOR_LIST P, f;
# endif
{
  MASSTOR_LIST PP, g, h, p, q, Ag, Eg, Ap, Ep, gcd, CoAg, CoAp, Sh, Sp, W, Mult;

  g = DIPAGB_EDIPUNEXTEND(f);
  if (g == 0 || P == MASSTOR_SIL) {
    return f;
  }
  h = 0;
  Sh = DIPAGB_EDIPSUGAR(f);
  W = DIPAGBOpt.VariableWeight;
  do {
    DIPC_DIPMAD(g, &Ag, &Eg, &g);
    if (g == MASSTOR_SIL) {
      g = 0;
    }
    PP = P;
    do {
      MASSTOR_ADV(PP, &p, &PP);
      Sp = DIPAGB_EDIPSUGAR(p);
      p = DIPAGB_EDIPUNEXTEND(p);
      DIPC_DIPMAD(p, &Ap, &Ep, &q);
      Mult = DIPC_EVMT(Eg, Ep);
    } while (!(PP == MASSTOR_SIL || Mult == 1));
    if (Mult == 0) {
      if (h == 0) {
        h = DIPC_DIPFMO(Ag, Eg);
      } else {
        h = DIPC_DIPMCP(Ag, Eg, h);
      }
    } else {
      if (q != MASSTOR_SIL) {
        MASADOM_ADGCDC(Ag, Ap, &gcd, &CoAg, &CoAp);
        g = DIPADOM_DIPDIF(DIPADOM_DIPBCP(g, CoAp), DIPADOM_DIPROD(q, DIPC_DIPFMO(CoAg, DIPC_EVDIF(Eg, Ep))));
        h = DIPADOM_DIPBCP(h, CoAp);
      }
      Sh = MASRN_RNMAX(Sh, SACRN_RNSUM(Sp, DIPAGB_EVRWTDEG(DIPC_EVDIF(Eg, Ep), W)));
    }
  } while (!(g == 0));
  return DIPAGB_EDIPSUGCON(DIPTOOLS_DIPIMO(h), Sh);
}

MASSTOR_LIST DIPAGB_EDIIFSUGSP
# ifdef __STDC__
(MASSTOR_LIST f, MASSTOR_LIST g)
# else
(f, g)
MASSTOR_LIST f, g;
# endif
{
  MASSTOR_LIST SP, SUG, W, HTf, HTg;

  SP = DIPGB_DIIFSP(DIPAGB_EDIPUNEXTEND(f), DIPAGB_EDIPUNEXTEND(g));
  W = DIPAGBOpt.VariableWeight;
  HTf = DIPAGB_EDIPEVL(f);
  HTg = DIPAGB_EDIPEVL(g);
  SUG = SACRN_RNSUM(MASRN_RNMAX(SACRN_RNDIF(DIPAGB_EDIPSUGAR(f), DIPAGB_EVRWTDEG(HTf, W)), SACRN_RNDIF(DIPAGB_EDIPSUGAR(g), DIPAGB_EVRWTDEG(HTg, W))), DIPAGB_EVRWTDEG(DIPC_EVLCM(HTf, HTg), W));
  return DIPAGB_EDIPSUGCON(SP, SUG);
}

MASSTOR_LIST DIPAGB_EDIPSUGAR
# ifdef __STDC__
(MASSTOR_LIST f)
# else
(f)
MASSTOR_LIST f;
# endif
{
  return SACLIST_SECOND(f);
}

MASSTOR_LIST DIPAGB_EDIPSUGCON
# ifdef __STDC__
(MASSTOR_LIST f, MASSTOR_LIST S)
# else
(f, S)
MASSTOR_LIST f, S;
# endif
{
  return SACLIST_LIST2(f, S);
}

MASSTOR_LIST DIPAGB_EDIPSUGNOR
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST f)
# else
(P, f)
MASSTOR_LIST P, f;
# endif
{
  MASSTOR_LIST PP, g, h, p, q, Ag, Eg, Ap, Ep, Sh, Sp, W, Mult;

  g = DIPAGB_EDIPUNEXTEND(f);
  if (g == 0 || P == MASSTOR_SIL) {
    return f;
  }
  h = 0;
  Sh = DIPAGB_EDIPSUGAR(f);
  W = DIPAGBOpt.VariableWeight;
  do {
    DIPC_DIPMAD(g, &Ag, &Eg, &g);
    if (g == MASSTOR_SIL) {
      g = 0;
    }
    PP = P;
    do {
      MASSTOR_ADV(PP, &p, &PP);
      Sp = DIPAGB_EDIPSUGAR(p);
      p = DIPAGB_EDIPUNEXTEND(p);
      DIPC_DIPMAD(p, &Ap, &Ep, &q);
      Mult = DIPC_EVMT(Eg, Ep);
    } while (!(PP == MASSTOR_SIL || Mult == 1));
    if (Mult == 0) {
      if (h == 0) {
        h = DIPC_DIPFMO(Ag, Eg);
      } else {
        h = DIPC_DIPMCP(Ag, Eg, h);
      }
    } else {
      if (q != MASSTOR_SIL) {
        g = DIPADOM_DIPDIF(g, DIPADOM_DIPROD(q, DIPC_DIPFMO(MASADOM_ADQUOT(Ag, Ap), DIPC_EVDIF(Eg, Ep))));
      }
      Sh = MASRN_RNMAX(Sh, SACRN_RNSUM(Sp, DIPAGB_EVRWTDEG(DIPC_EVDIF(Eg, Ep), W)));
    }
  } while (!(g == 0));
  return DIPAGB_EDIPSUGCON(DIPTOOLS_DIPIMO(h), Sh);
}

MASSTOR_LIST DIPAGB_EDIPSUGSP
# ifdef __STDC__
(MASSTOR_LIST f, MASSTOR_LIST g)
# else
(f, g)
MASSTOR_LIST f, g;
# endif
{
  MASSTOR_LIST SP, SUG, W, HTf, HTg;

  SP = DIPGB_DIPSP(DIPAGB_EDIPUNEXTEND(f), DIPAGB_EDIPUNEXTEND(g));
  W = DIPAGBOpt.VariableWeight;
  HTf = DIPAGB_EDIPEVL(f);
  HTg = DIPAGB_EDIPEVL(g);
  SUG = SACRN_RNSUM(MASRN_RNMAX(SACRN_RNDIF(DIPAGB_EDIPSUGAR(f), DIPAGB_EVRWTDEG(HTf, W)), SACRN_RNDIF(DIPAGB_EDIPSUGAR(g), DIPAGB_EVRWTDEG(HTg, W))), DIPAGB_EVRWTDEG(DIPC_EVLCM(HTf, HTg), W));
  return DIPAGB_EDIPSUGCON(SP, SUG);
}

static void EDIPSUGWRITE
# ifdef __STDC__
(MASSTOR_LIST f)
# else
(f)
MASSTOR_LIST f;
# endif
{
  DIPADOM_DIWRIT(DIPAGB_EDIPUNEXTEND(f), DIPC_VALIS);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("with sugar ", 11L);
  SACRN_RNWRIT(DIPAGB_EDIPSUGAR(f));
  MASBIOS_SWRITE(".", 1L);
  MASBIOS_BLINES(1);
}

static MASSTOR_LIST ECPSUGCON
# ifdef __STDC__
(MASSTOR_LIST f, MASSTOR_LIST g)
# else
(f, g)
MASSTOR_LIST f, g;
# endif
{
  MASSTOR_LIST W, HTf, HTg, LCM, SUG;

  HTf = DIPAGB_EDIPEVL(f);
  HTg = DIPAGB_EDIPEVL(g);
  LCM = DIPC_EVLCM(HTf, HTg);
  W = DIPAGBOpt.VariableWeight;
  SUG = SACRN_RNSUM(MASRN_RNMAX(SACRN_RNDIF(DIPAGB_EDIPSUGAR(f), DIPAGB_EVRWTDEG(HTf, W)), SACRN_RNDIF(DIPAGB_EDIPSUGAR(g), DIPAGB_EVRWTDEG(HTg, W))), DIPAGB_EVRWTDEG(LCM, W));
  return SACLIST_LIST4(f, g, LCM, SUG);
}

MASSTOR_LIST DIPAGB_ECPSUGAR
# ifdef __STDC__
(MASSTOR_LIST CP)
# else
(CP)
MASSTOR_LIST CP;
# endif
{
  return SACLIST_FOURTH(CP);
}

static MASSTOR_LIST ECPSUGINS
# ifdef __STDC__
(MASSTOR_LIST CP, MASSTOR_LIST P)
# else
(CP, P)
MASSTOR_LIST CP, P;
# endif
{
  MASSTOR_LIST PP, PPR, LCMCP, SUGCP, SUGCompare;

  if (P == MASSTOR_SIL) {
    return MASSTOR_LIST1(CP);
  }
  SUGCP = DIPAGB_ECPSUGAR(CP);
  LCMCP = DIPAGB_ECPLCMHT(CP);
  SUGCompare = SACRN_RNCOMP(DIPAGB_ECPSUGAR(MASSTOR_FIRST(P)), SUGCP);
  if (SUGCompare == 1) {
    return MASSTOR_COMP(CP, P);
  }
  if (SUGCompare == 0 && DIPC_EVCOMP(DIPAGB_ECPLCMHT(MASSTOR_FIRST(P)), LCMCP) >= 0) {
    return MASSTOR_COMP(CP, P);
  }
  PP = P;
  PPR = MASSTOR_RED(PP);
  while (PPR != MASSTOR_SIL && SACRN_RNCOMP(DIPAGB_ECPSUGAR(MASSTOR_FIRST(PPR)), SUGCP) == -1) {
    PP = PPR;
    PPR = MASSTOR_RED(PP);
  }
  if (PPR == MASSTOR_SIL || SACRN_RNCOMP(DIPAGB_ECPSUGAR(MASSTOR_FIRST(PPR)), SUGCP) == 1) {
    MASSTOR_SRED(PP, MASSTOR_COMP(CP, PPR));
    return P;
  }
  while (PPR != MASSTOR_SIL && SACRN_RNCOMP(DIPAGB_ECPSUGAR(MASSTOR_FIRST(PPR)), SUGCP) == 0 && DIPC_EVCOMP(DIPAGB_ECPLCMHT(MASSTOR_FIRST(PPR)), LCMCP) == -1) {
    PP = PPR;
    PPR = MASSTOR_RED(PP);
  }
  MASSTOR_SRED(PP, MASSTOR_COMP(CP, PPR));
  return P;
}

static void ECPSUGWRITE
# ifdef __STDC__
(MASSTOR_LIST CP)
# else
(CP)
MASSTOR_LIST CP;
# endif
{
  MASSTOR_LIST f, g, Cf, Ef, Rf, F, G;

  F = DIPAGB_ECPPOLY1(CP);
  G = DIPAGB_ECPPOLY2(CP);
  f = DIPAGB_EDIPUNEXTEND(F);
  g = DIPAGB_EDIPUNEXTEND(G);
  MASBIOS_SWRITE("1st polynomial: ", 16L);
  DIPADOM_DIWRIT(f, DIPC_VALIS);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("    with sugar ", 15L);
  SACRN_RNWRIT(DIPAGB_EDIPSUGAR(F));
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("2nd polynomial: ", 16L);
  DIPADOM_DIWRIT(g, DIPC_VALIS);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("    with sugar ", 15L);
  SACRN_RNWRIT(DIPAGB_EDIPSUGAR(G));
  MASBIOS_BLINES(0);
  DIPC_DIPMAD(f, &Cf, &Ef, &Rf);
  MASBIOS_SWRITE("LCM of their leading terms:", 27L);
  DIPADOM_DIWRIT(DIPC_DIPFMO(MASADOM_ADFI(Cf, 1), DIPAGB_ECPLCMHT(CP)), DIPC_VALIS);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("Sugar of their S-polynomial: ", 29L);
  SACRN_RNWRIT(DIPAGB_ECPSUGAR(CP));
  MASBIOS_BLINES(0);
}

static void SugarUpdateVariableWeight
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST V, W, v, w;
  BOOLEAN OnlyOneSeen;

  V = DIPC_VALIS;
  W = DIPAGBOpt.VariableWeight;
  OnlyOneSeen = TRUE;
  while (V != MASSTOR_SIL && W != MASSTOR_SIL) {
    MASSTOR_ADV(V, &v, &V);
    MASSTOR_ADV(W, &w, &W);
    if (SACRN_RNCOMP(SACRN_RNINT(1), w) != 0) {
      OnlyOneSeen = FALSE;
    }
  }
  if (OnlyOneSeen) {
    if (V != MASSTOR_SIL && W == MASSTOR_SIL) {
      W = DIPAGBOpt.VariableWeight;
      while (V != MASSTOR_SIL) {
        MASSTOR_ADV(V, &v, &V);
        W = MASSTOR_COMP(SACRN_RNINT(1), W);
      }
      DIPAGB_SetDIPAGBVariableWeight(W);
      MASBIOS_BLINES(1);
    } else {
      if (W != MASSTOR_SIL) {
        while (OnlyOneSeen && W != MASSTOR_SIL) {
          MASSTOR_ADV(W, &w, &W);
          if (SACRN_RNCOMP(SACRN_RNINT(1), w) != 0) {
            OnlyOneSeen = FALSE;
          }
        }
        if (OnlyOneSeen) {
          V = DIPC_VALIS;
          W = MASSTOR_SIL;
          while (V != MASSTOR_SIL) {
            MASSTOR_ADV(V, &v, &V);
            W = MASSTOR_COMP(SACRN_RNINT(1), W);
          }
          DIPAGB_SetDIPAGBVariableWeight(W);
          MASBIOS_BLINES(1);
        } else {
          DIPAGB_WriteDIPAGBVariableWeight();
          MASERR_ERROR(MASERR_fatal, "DIPAGB: no valid variable weight list", 37L);
        }
      }
    }
  } else {
    if (V == MASSTOR_SIL && W != MASSTOR_SIL || V != MASSTOR_SIL && W == MASSTOR_SIL) {
      DIPAGB_WriteDIPAGBVariableWeight();
      MASERR_ERROR(MASERR_fatal, "DIPAGB: no valid variable weight list", 37L);
    }
  }
}

static void InitDIPAGB
# ifdef __STDC__
()
# else
()
# endif
{
  DIPAGBOpt.TraceFlag = 0;
  DIPAGBOpt.Strategy = DIPAGB_Normal;
  DIPAGBOpt.VariableWeight = MASSTOR_SIL;
  DIPAGBOpt.UpdateVariableWeight = NOP;
  DIPAGBOpt.Update = DIPAGB_UPDATE;
  DIPAGBOpt.InitUpdate = DIPAGB_UPDATE;
  DIPAGBOpt.CPExtend = ECPNORCON;
  DIPAGBOpt.DIPExtend = IDF1;
  DIPAGBOpt.ECPInsert = ECPNORINS;
  DIPAGBOpt.ECPSelect = MASSTOR_ADV;
  DIPAGBOpt.ECPWrite = ECPNORWRITE;
  DIPAGBOpt.EDIPNormalform = MASADOM_ADPNF;
  DIPAGBOpt.EDIPSPolynomial = MASADOM_ADPSP;
  DIPAGBOpt.EDIPUnExtend = IDF1;
  DIPAGBOpt.EDIPWrite = EDIPNORWRITE;
}

void DIPAGB_SetCPExtend
# ifdef __STDC__
(MASLISPU_PROCF2 EXT)
# else
(EXT)
MASLISPU_PROCF2 EXT;
# endif
{
  DIPAGBOpt.CPExtend = EXT;
}

void DIPAGB_SetDIPAGBOptions
# ifdef __STDC__
(MASSTOR_LIST OPT)
# else
(OPT)
MASSTOR_LIST OPT;
# endif
{
  MASELEM_GAMMAINT L;

  L = MASSTOR_LENGTH(OPT);
  if (L >= 1) {
    DIPAGB_SetDIPAGBTraceFlag(MASSTOR_FIRST(OPT));
    MASBIOS_BLINES(1);
  }
  if (L >= 2) {
    DIPAGB_SetDIPAGBStrategy(SACLIST_SECOND(OPT));
    MASBIOS_BLINES(1);
  }
  if (L >= 3) {
    DIPAGB_SetDIPAGBVariableWeight(SACLIST_THIRD(OPT));
    MASBIOS_BLINES(1);
  }
}

void DIPAGB_SetDIPAGBStrategy
# ifdef __STDC__
(MASSTOR_LIST st)
# else
(st)
MASSTOR_LIST st;
# endif
{
  DIPAGBOpt.Strategy = st;
  if (DIPAGBOpt.TraceFlag >= 3) {
    MASBIOS_SWRITE("New strategy: ", 14L);
    SACLIST_AWRITE(st);
    switch (st) {
    case 0:;
      MASBIOS_SWRITE("  (= normal)           ", 23L);
      break;
    case 1:;
      MASBIOS_SWRITE("  (= normal with sugar)", 23L);
      break;
    default :
      MASERR_ERROR(MASERR_fatal, "SetDIPAGBStrategy: No valid strategy.", 37L);
      break;
    }
  }
  switch (st) {
  case 0:;
    DIPAGB_SetUpdateVariableWeight(NOP);
    DIPAGB_SetCPExtend(ECPNORCON);
    DIPAGB_SetDIPExtend(IDF1);
    DIPAGB_SetECPInsert(ECPNORINS);
    DIPAGB_SetECPWrite(ECPNORWRITE);
    DIPAGB_SetEDIPNormalform(MASADOM_ADPNF);
    DIPAGB_SetEDIPSPolynomial(MASADOM_ADPSP);
    DIPAGB_SetEDIPUnExtend(IDF1);
    DIPAGB_SetEDIPWrite(EDIPNORWRITE);
    break;
  case 1:;
    DIPAGB_SetUpdateVariableWeight(SugarUpdateVariableWeight);
    DIPAGB_SetCPExtend(ECPSUGCON);
    DIPAGB_SetDIPExtend(DIPSUGEXT);
    DIPAGB_SetECPInsert(ECPSUGINS);
    DIPAGB_SetECPWrite(ECPSUGWRITE);
    DIPAGB_SetEDIPNormalform(MASADOM_ADPSUGNF);
    DIPAGB_SetEDIPSPolynomial(MASADOM_ADPSUGSP);
    DIPAGB_SetEDIPUnExtend(MASSTOR_FIRST);
    DIPAGB_SetEDIPWrite(EDIPSUGWRITE);
    break;
  }
}

void DIPAGB_SetDIPAGBTraceFlag
# ifdef __STDC__
(MASSTOR_LIST tf)
# else
(tf)
MASSTOR_LIST tf;
# endif
{
  DIPAGBOpt.TraceFlag = tf;
  if (DIPAGBOpt.TraceFlag >= 3) {
    MASBIOS_SWRITE("New documentation level: ", 25L);
    SACLIST_AWRITE(tf);
  }
}

void DIPAGB_SetDIPAGBVariableWeight
# ifdef __STDC__
(MASSTOR_LIST VW)
# else
(VW)
MASSTOR_LIST VW;
# endif
{
  if (DIPAGBOpt.TraceFlag >= 3) {
    MASBIOS_SWRITE("New variable weight list: ", 26L);
    DIPAGB_LRNWRIT(VW);
  }
  DIPAGBOpt.VariableWeight = MASSTOR_INV(VW);
}

void DIPAGB_SetDIPExtend
# ifdef __STDC__
(MASLISPU_PROCF1 EXT)
# else
(EXT)
MASLISPU_PROCF1 EXT;
# endif
{
  DIPAGBOpt.DIPExtend = EXT;
}

void DIPAGB_SetECPInsert
# ifdef __STDC__
(MASLISPU_PROCF2 INS)
# else
(INS)
MASLISPU_PROCF2 INS;
# endif
{
  DIPAGBOpt.ECPInsert = INS;
}

void DIPAGB_SetECPSelect
# ifdef __STDC__
(MASLISPU_PROCP1V2 SEL)
# else
(SEL)
MASLISPU_PROCP1V2 SEL;
# endif
{
  DIPAGBOpt.ECPSelect = SEL;
}

void DIPAGB_SetECPWrite
# ifdef __STDC__
(MASLISPU_PROCP1 WR)
# else
(WR)
MASLISPU_PROCP1 WR;
# endif
{
  DIPAGBOpt.ECPWrite = WR;
}

void DIPAGB_SetEDIPNormalform
# ifdef __STDC__
(MASLISPU_PROCF2 NF)
# else
(NF)
MASLISPU_PROCF2 NF;
# endif
{
  DIPAGBOpt.EDIPNormalform = NF;
}

void DIPAGB_SetEDIPSPolynomial
# ifdef __STDC__
(MASLISPU_PROCF2 SP)
# else
(SP)
MASLISPU_PROCF2 SP;
# endif
{
  DIPAGBOpt.EDIPSPolynomial = SP;
}

void DIPAGB_SetEDIPUnExtend
# ifdef __STDC__
(MASLISPU_PROCF1 UEXT)
# else
(UEXT)
MASLISPU_PROCF1 UEXT;
# endif
{
  DIPAGBOpt.EDIPUnExtend = UEXT;
}

void DIPAGB_SetEDIPWrite
# ifdef __STDC__
(MASLISPU_PROCP1 WR)
# else
(WR)
MASLISPU_PROCP1 WR;
# endif
{
  DIPAGBOpt.EDIPWrite = WR;
}

void DIPAGB_SetInit
# ifdef __STDC__
(MASLISPU_PROCP1V2 INIT)
# else
(INIT)
MASLISPU_PROCP1V2 INIT;
# endif
{
  DIPAGBOpt.InitUpdate = INIT;
}

void DIPAGB_SetUpdate
# ifdef __STDC__
(MASLISPU_PROCP1V2 UPD)
# else
(UPD)
MASLISPU_PROCP1V2 UPD;
# endif
{
  DIPAGBOpt.Update = UPD;
}

void DIPAGB_SetUpdateVariableWeight
# ifdef __STDC__
(MASLISPU_PROCP0 UPD)
# else
(UPD)
MASLISPU_PROCP0 UPD;
# endif
{
  DIPAGBOpt.UpdateVariableWeight = UPD;
}

void DIPAGB_WriteDIPAGBOptions
# ifdef __STDC__
()
# else
()
# endif
{
  DIPAGB_WriteDIPAGBTraceFlag();
  MASBIOS_BLINES(0);
  DIPAGB_WriteDIPAGBStrategy();
  MASBIOS_BLINES(0);
  DIPAGB_WriteDIPAGBVariableWeight();
  MASBIOS_BLINES(0);
}

void DIPAGB_WriteDIPAGBStrategy
# ifdef __STDC__
()
# else
()
# endif
{
  MASBIOS_SWRITE("Actual strategy: ", 17L);
  SACLIST_AWRITE(DIPAGBOpt.Strategy);
  switch (DIPAGBOpt.Strategy) {
  case 0:;
    MASBIOS_SWRITE("  (= normal)           ", 23L);
    break;
  case 1:;
    MASBIOS_SWRITE("  (= normal with sugar)", 23L);
    break;
  }
  MASBIOS_BLINES(0);
}

void DIPAGB_WriteDIPAGBTraceFlag
# ifdef __STDC__
()
# else
()
# endif
{
  MASBIOS_SWRITE("Actual documentation level: ", 28L);
  SACLIST_AWRITE(DIPAGBOpt.TraceFlag);
  MASBIOS_BLINES(0);
}

void DIPAGB_WriteDIPAGBVariableWeight
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST WL, RN;

  MASBIOS_SWRITE("Actual variable weight list: ", 29L);
  DIPAGB_LRNWRIT(SACLIST_CINV(DIPAGBOpt.VariableWeight));
  MASBIOS_BLINES(0);
}

void BEGIN_DIPAGB()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASLISPU();
    BEGIN_DIPADOM();
    BEGIN_DIPC();
    BEGIN_DIPGB();
    BEGIN_DIPTOOLS();
    BEGIN_MASADOM();
    BEGIN_MASBIOS();
    BEGIN_MASELEM();
    BEGIN_MASERR();
    BEGIN_MASLISPU();
    BEGIN_MASNCC();
    BEGIN_MASRN();
    BEGIN_MASSTOR();
    BEGIN_massig();
    BEGIN_SACLIST();
    BEGIN_SACPOL();
    BEGIN_SACRN();

    MASSTOR_LISTVAR(&DIPAGBOpt.VariableWeight);
    InitDIPAGB();
  }
}
