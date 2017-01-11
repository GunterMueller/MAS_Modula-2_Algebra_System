#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_SACRN
#include "SACRN.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPRN
#include "DIPRN.h"
#endif

#ifndef DEFINITION_DIPRNGB
#include "DIPRNGB.h"
#endif

#ifndef DEFINITION_TIPRNGB
#include "TIPRNGB.h"
#endif

CHAR TIPRNGB_rcsid [] = "$Id: TIPRNGB.md,v 1.1 1995/11/05 15:57:37 pesch Exp $";
CHAR TIPRNGB_copyright [] = "Copyright (c) 1995 Universitaet Passau";

static CHAR rcsidi [] = "$Id: TIPRNGB.mi,v 1.1 1995/11/05 15:57:39 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1995 Universitaet Passau";
static MASSTOR_LIST EGBPMC ARGS((MASSTOR_LIST AM));
static MASSTOR_LIST EGBPON ARGS((MASSTOR_LIST AM));
static MASSTOR_LIST EGBC3 ARGS((MASSTOR_LIST B, MASSTOR_LIST PMI, MASSTOR_LIST PMJ, MASSTOR_LIST EL));
static MASSTOR_LIST EGBC4 ARGS((MASSTOR_LIST PMI, MASSTOR_LIST PMJ, MASSTOR_LIST EL));
static MASSTOR_LIST EGBPSP ARGS((MASSTOR_LIST AM, MASSTOR_LIST BM));
static MASSTOR_LIST EGBPNF ARGS((MASSTOR_LIST P, MASSTOR_LIST SM));
static MASSTOR_LIST LISTMERGE ARGS((MASSTOR_LIST L1, MASSTOR_LIST L2));
static MASSTOR_LIST EGBLPM ARGS((MASSTOR_LIST C_83_A));
static MASSTOR_LIST EGBMI ARGS((MASSTOR_LIST GB));
static void EGBLCPL ARGS((MASSTOR_LIST P, MASSTOR_LIST *D, MASSTOR_LIST *B));
static MASSTOR_LIST EGBLUPL ARGS((MASSTOR_LIST PM, MASSTOR_LIST P, MASSTOR_LIST D, MASSTOR_LIST B));


static MASSTOR_LIST EGBPMC
# ifdef __STDC__
(MASSTOR_LIST AM)
# else
(AM)
MASSTOR_LIST AM;
# endif
{
  MASSTOR_LIST C_86_A, AX, BL, CM, C, CX, Y;

  CM = MASSTOR_SIL;
  if (AM == MASSTOR_SIL) {
    return CM;
  }
  SACLIST_FIRST2(AM, &C_86_A, &AX);
  if (C_86_A == 0) {
    return CM;
  }
  BL = SACRN_RNINV(DIPC_DIPLBC(C_86_A));
  C = DIPRN_DIRPRP(C_86_A, BL);
  CX = MASSTOR_SIL;
  while (AX != MASSTOR_SIL) {
    MASSTOR_ADV(AX, &Y, &AX);
    Y = DIPRN_DIRPRP(Y, BL);
    CX = MASSTOR_COMP(Y, CX);
  }
  CM = MASSTOR_COMP(C, MASSTOR_COMP(MASSTOR_INV(CX), CM));
  return CM;
}

static MASSTOR_LIST EGBPON
# ifdef __STDC__
(MASSTOR_LIST AM)
# else
(AM)
MASSTOR_LIST AM;
# endif
{
  MASSTOR_LIST C_85_A, AX;

  if (AM == MASSTOR_SIL) {
    return 0;
  }
  SACLIST_FIRST2(AM, &C_85_A, &AX);
  return DIPRN_DIRPON(C_85_A);
}

static MASSTOR_LIST EGBC3
# ifdef __STDC__
(MASSTOR_LIST B, MASSTOR_LIST PMI, MASSTOR_LIST PMJ, MASSTOR_LIST EL)
# else
(B, PMI, PMJ, EL)
MASSTOR_LIST B, PMI, PMJ, EL;
# endif
{
  MASSTOR_LIST BP, EP, PM, PL, PX, PP, PLI, PLJ, PXI, PXJ, PPI, PPJ, PS, Q, QM, SL, TL;

  BP = B;
  do {
    SACLIST_ADV2(BP, &PS, &Q, &BP);
    MASSTOR_ADV(PS, &PM, &PS);
    SACLIST_FIRST2(PM, &PL, &PX);
    if (PM != PMI) {
      EP = DIPC_DIPEVL(PL);
      TL = DIPC_EVMT(EL, EP);
      if (TL == 1) {
        SL = 0;
        PP = PS;
        while (PP != MASSTOR_SIL && SL == 0) {
          MASSTOR_ADV(PP, &QM, &PP);
          if (QM == PMI || QM == PMJ) {
            SL = 1;
          }
        }
        if (SL == 0) {
          return SL;
        }
      }
    }
  } while (!(PM == PMI));
  PPI = PS;
  do {
    SACLIST_ADV2(BP, &PS, &Q, &BP);
    MASSTOR_ADV(PS, &PM, &PS);
    SACLIST_FIRST2(PM, &PL, &PX);
    if (PM != PMJ) {
      EP = DIPC_DIPEVL(PL);
      TL = DIPC_EVMT(EL, EP);
      if (TL == 1) {
        SL = 0;
        PP = PPI;
        while (PP != MASSTOR_SIL && SL == 0) {
          MASSTOR_ADV(PP, &QM, &PP);
          if (QM == PM) {
            SL = 1;
          }
        }
        PP = PS;
        while (PP != MASSTOR_SIL && SL == 0) {
          MASSTOR_ADV(PP, &QM, &PP);
          if (QM == PMJ) {
            SL = 1;
          }
        }
        if (SL == 0) {
          return SL;
        }
      }
    }
  } while (!(PM == PMJ));
  PPJ = PS;
  while (BP != MASSTOR_SIL) {
    SACLIST_ADV2(BP, &PS, &Q, &BP);
    MASSTOR_ADV(PS, &PM, &PS);
    SACLIST_FIRST2(PM, &PL, &PX);
    EP = DIPC_DIPEVL(PL);
    TL = DIPC_EVMT(EL, EP);
    if (TL == 1) {
      SL = 0;
      PP = PPI;
      while (PP != MASSTOR_SIL && SL == 0) {
        MASSTOR_ADV(PP, &QM, &PP);
        if (QM == PM) {
          SL = 1;
        }
      }
      PP = PPJ;
      while (PP != MASSTOR_SIL && SL == 0) {
        MASSTOR_ADV(PP, &QM, &PP);
        if (QM == PM) {
          SL = 1;
        }
      }
      if (SL == 0) {
        return SL;
      }
    }
  }
  SL = 1;
  return SL;
}

static MASSTOR_LIST EGBC4
# ifdef __STDC__
(MASSTOR_LIST PMI, MASSTOR_LIST PMJ, MASSTOR_LIST EL)
# else
(PMI, PMJ, EL)
MASSTOR_LIST PMI, PMJ, EL;
# endif
{
  MASSTOR_LIST PI, PJ, EI, EJ, EP, SL, DUMMY;

  SACLIST_FIRST2(PMI, &PI, &DUMMY);
  SACLIST_FIRST2(PMJ, &PJ, &DUMMY);
  EI = DIPC_DIPEVL(PI);
  EJ = DIPC_DIPEVL(PJ);
  EP = DIPC_EVSUM(EI, EJ);
  SL = SACLIST_EQUAL(EL, EP);
  return 1 - SL;
}

static MASSTOR_LIST EGBPSP
# ifdef __STDC__
(MASSTOR_LIST AM, MASSTOR_LIST BM)
# else
(AM, BM)
MASSTOR_LIST AM, BM;
# endif
{
  MASSTOR_LIST C_84_A, AL, AP, AX, B, BL, BP, BX, C, CL, CX, CM, EL, FL, GL, Y1, Y2, DUMMY;

  CM = MASSTOR_SIL;
  if (AM == MASSTOR_SIL || BM == MASSTOR_SIL) {
    return CM;
  }
  SACLIST_FIRST2(AM, &C_84_A, &AX);
  SACLIST_FIRST2(BM, &B, &BX);
  if (C_84_A == 0 || B == 0) {
    return CM;
  }
  DIPC_DIPMAD(C_84_A, &AL, &EL, &DUMMY);
  DIPC_DIPMAD(B, &BL, &FL, &DUMMY);
  GL = DIPC_EVLCM(EL, FL);
  AP = DIPC_DIPFMO(BL, DIPC_EVDIF(GL, EL));
  BP = DIPC_DIPFMO(AL, DIPC_EVDIF(GL, FL));
  C = DIPRN_DIRPDF(DIPRN_DIRPPR(C_84_A, AP), DIPRN_DIRPPR(B, BP));
  if (C == 0) {
    return CM;
  }
  CX = MASSTOR_SIL;
  while (AX != MASSTOR_SIL) {
    MASSTOR_ADV(AX, &Y1, &AX);
    Y1 = DIPRN_DIRPPR(Y1, AP);
    MASSTOR_ADV(BX, &Y2, &BX);
    Y2 = DIPRN_DIRPPR(Y2, BP);
    CX = MASSTOR_COMP(DIPRN_DIRPDF(Y1, Y2), CX);
  }
  CM = MASSTOR_COMP(C, MASSTOR_COMP(MASSTOR_INV(CX), CM));
  return CM;
}

static MASSTOR_LIST EGBPNF
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST SM)
# else
(P, SM)
MASSTOR_LIST P, SM;
# endif
{
  MASSTOR_LIST AP, APP, PP, QM, Q, QX, QA, QE, R, RX, RM, SL, S, SX, TA, TE, XX, Y1, Y2, DUMMY;

  RM = MASSTOR_SIL;
  if (SM == MASSTOR_SIL || P == MASSTOR_SIL) {
    RM = SM;
    return RM;
  }
  R = 0;
  SACLIST_FIRST2(SM, &S, &SX);
  do {
    DIPC_DIPMAD(S, &TA, &TE, &DUMMY);
    PP = P;
    do {
      MASSTOR_ADV(PP, &QM, &PP);
      SACLIST_FIRST2(QM, &Q, &QX);
      DIPC_DIPMAD(Q, &QA, &QE, &DUMMY);
      SL = DIPC_EVMT(TE, QE);
    } while (!(PP == MASSTOR_SIL || SL == 1));
    if (SL == 0) {
      XX = DIPC_DIPFMO(TA, TE);
      S = DIPRN_DIRPDF(S, XX);
      R = DIPRN_DIRPSM(R, XX);
    } else {
      XX = DIPC_DIPFMO(SACRN_RNQ(TA, QA), DIPC_EVDIF(TE, QE));
      AP = DIPRN_DIRPPR(Q, XX);
      S = DIPRN_DIRPDF(S, AP);
      RX = MASSTOR_SIL;
      while (SX != MASSTOR_SIL) {
        MASSTOR_ADV(SX, &Y1, &SX);
        MASSTOR_ADV(QX, &Y2, &QX);
        RX = MASSTOR_COMP(DIPRN_DIRPDF(Y1, DIPRN_DIRPPR(Y2, XX)), RX);
      }
      SX = MASSTOR_INV(RX);
    }
  } while (!(S == 0));
  RX = SX;
  if (R == 0) {
    return RM;
  } else {
    RM = MASSTOR_COMP(R, MASSTOR_COMP(RX, RM));
  }
  return RM;
}

static MASSTOR_LIST LISTMERGE
# ifdef __STDC__
(MASSTOR_LIST L1, MASSTOR_LIST L2)
# else
(L1, L2)
MASSTOR_LIST L1, L2;
# endif
{
  MASSTOR_LIST AM1, AM2, AL1, AL2, AX1, AX2, EL1, EL2, L, LP, LP1, LP2, TL;
  BOOLEAN eoz;

  if (L1 == MASSTOR_SIL) {
    L = L2;
    return L;
  }
  if (L2 == MASSTOR_SIL) {
    L = L1;
    return L;
  }
  LP1 = L1;
  LP2 = L2;
  AM1 = MASSTOR_FIRST(L1);
  AM2 = MASSTOR_FIRST(L2);
  SACLIST_FIRST2(AM1, &AL1, &AX1);
  SACLIST_FIRST2(AM2, &AL2, &AX2);
  EL1 = DIPC_DIPEVL(AL1);
  EL2 = DIPC_DIPEVL(AL2);
  TL = DIPC_EVCOMP(EL1, EL2);
  if (TL > 0) {
    L = L2;
    LP = L2;
    LP2 = MASSTOR_RED(L2);
    eoz = FALSE;
  } else {
    L = L1;
    LP = L1;
    LP1 = MASSTOR_RED(L1);
    eoz = TRUE;
  }
  for (;;) {
    if (eoz) {
      if (LP1 == MASSTOR_SIL) {
        goto EXIT_1;
      }
      AM1 = MASSTOR_FIRST(LP1);
      SACLIST_FIRST2(AM1, &AL1, &AX1);
      EL1 = DIPC_DIPEVL(AL1);
      TL = DIPC_EVCOMP(EL1, EL2);
      if (TL <= 0) {
        LP = LP1;
        LP1 = MASSTOR_RED(LP1);
        eoz = TRUE;
      } else {
        MASSTOR_SRED(LP, LP2);
        LP = LP2;
        LP2 = MASSTOR_RED(LP2);
        eoz = FALSE;
      }
    } else {
      if (LP2 == MASSTOR_SIL) {
        goto EXIT_1;
      }
      AM2 = MASSTOR_FIRST(LP2);
      SACLIST_FIRST2(AM2, &AL2, &AX2);
      EL2 = DIPC_DIPEVL(AL2);
      TL = DIPC_EVCOMP(EL1, EL2);
      if (TL <= 0) {
        MASSTOR_SRED(LP, LP1);
        LP = LP1;
        LP1 = MASSTOR_RED(LP1);
        eoz = TRUE;
      } else {
        LP = LP2;
        LP2 = MASSTOR_RED(LP2);
        eoz = FALSE;
      }
    }
  } EXIT_1:;
  if (LP1 == MASSTOR_SIL) {
    MASSTOR_SRED(LP, LP2);
  } else {
    MASSTOR_SRED(LP, LP1);
  }
  return L;
}

static MASSTOR_LIST EGBLPM
# ifdef __STDC__
(MASSTOR_LIST C_83_A)
# else
(C_83_A)
MASSTOR_LIST C_83_A;
# endif
{
  MASSTOR_LIST AM1, AM2, AL1, AL2, AX1, AX2, AP, APP, APPP, B, BP, BPP, C, CP, CPP, CS, EL1, EL2, TL;

  if (C_83_A == MASSTOR_SIL || MASSTOR_RED(C_83_A) == MASSTOR_SIL) {
    B = C_83_A;
    return B;
  }
  C = MASSTOR_LIST1(0);
  CS = C;
  AP = C_83_A;
  do {
    MASSTOR_ADV(AP, &AM1, &APP);
    SACLIST_FIRST2(AM1, &AL1, &AX1);
    if (APP == MASSTOR_SIL) {
      BP = AP;
    } else {
      MASSTOR_ADV(APP, &AM2, &APPP);
      SACLIST_FIRST2(AM2, &AL2, &AX2);
      EL1 = DIPC_DIPEVL(AL1);
      EL2 = DIPC_DIPEVL(AL2);
      TL = DIPC_EVCOMP(EL1, EL2);
      if (TL <= 0) {
        BP = AP;
        MASSTOR_SRED(APP, MASSTOR_SIL);
      } else {
        BP = APP;
        MASSTOR_SRED(APP, AP);
        MASSTOR_SRED(AP, MASSTOR_SIL);
      }
    }
    C = MASSTOR_COMP(BP, C);
    AP = APPP;
  } while (!(APP == MASSTOR_SIL || AP == MASSTOR_SIL));
  MASSTOR_ADV(C, &BP, &C);
  MASSTOR_SFIRST(CS, BP);
  MASSTOR_SRED(CS, C);
  MASSTOR_ADV(C, &B, &CP);
  while (C != CP) {
    MASSTOR_ADV(CP, &BP, &CPP);
    BPP = LISTMERGE(B, BP);
    MASSTOR_SFIRST(C, BPP);
    MASSTOR_SRED(C, CPP);
    C = CPP;
    MASSTOR_ADV(C, &B, &CP);
  }
  return B;
}

static MASSTOR_LIST EGBMI
# ifdef __STDC__
(MASSTOR_LIST GB)
# else
(GB)
MASSTOR_LIST GB;
# endif
{
  MASSTOR_LIST AL, EI, EJ, EL, PB, PI, PIP, PJ, PP, PS, QP, TL, PM1, PM2, PX1, PX2;

  PP = GB;
  if (GB == MASSTOR_SIL || MASSTOR_RED(GB) == MASSTOR_SIL) {
    return PP;
  }
  PS = PP;
  QP = MASSTOR_SIL;
  do {
    MASSTOR_ADV(PS, &PM1, &PS);
    SACLIST_FIRST2(PM1, &PI, &PX1);
    PB = PS;
    EI = DIPC_DIPEVL(PI);
    TL = 0;
    while (PB != MASSTOR_SIL && TL == 0) {
      MASSTOR_ADV(PB, &PM2, &PB);
      SACLIST_FIRST2(PM2, &PJ, &PX2);
      EJ = DIPC_DIPEVL(PJ);
      TL = DIPC_EVMT(EI, EJ);
    }
    PB = QP;
    while (PB != MASSTOR_SIL && TL == 0) {
      MASSTOR_ADV(PB, &PM2, &PB);
      SACLIST_FIRST2(PM2, &PJ, &PX2);
      EJ = DIPC_DIPEVL(PJ);
      TL = DIPC_EVMT(EI, EJ);
    }
    if (TL == 0) {
      QP = MASSTOR_COMP(PM1, QP);
    }
  } while (!(PS == MASSTOR_SIL));
  PP = MASSTOR_INV(QP);
  if (PP == MASSTOR_SIL || MASSTOR_RED(PP) == MASSTOR_SIL) {
    return PP;
  }
  PS = PP;
  QP = PP;
  PP = MASSTOR_SIL;
  do {
    MASSTOR_ADV(PS, &PM1, &PS);
    SACLIST_FIRST2(PM1, &PI, &PX1);
    DIPC_DIPMAD(PI, &AL, &EL, &PIP);
    if (PIP != MASSTOR_SIL) {
      PM1 = MASSTOR_SIL;
      PM1 = MASSTOR_COMP(PIP, MASSTOR_COMP(PX1, PM1));
      PM1 = EGBPNF(QP, PM1);
      if (PM1 != MASSTOR_SIL) {
        SACLIST_FIRST2(PM1, &PIP, &PX1);
        PI = DIPC_DIPMCP(AL, EL, PIP);
      } else {
        PI = DIPC_DIPFMO(AL, EL);
      }
      PM1 = MASSTOR_SIL;
      PM1 = MASSTOR_COMP(PI, MASSTOR_COMP(PX1, PM1));
    }
    PP = MASSTOR_COMP(PM1, PP);
  } while (!(PS == MASSTOR_SIL));
  PP = MASSTOR_INV(PP);
  if (PP == MASSTOR_SIL || MASSTOR_RED(PP) == MASSTOR_SIL) {
    return PP;
  }
  return EGBLPM(PP);
}

static void EGBLCPL
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST *D, MASSTOR_LIST *B)
# else
(P, D, B)
MASSTOR_LIST P;
MASSTOR_LIST *D, *B;
# endif
{
  MASSTOR_LIST BP, BR, EL, ELI, ELJ, PI, PJ, PP, PM1, PM2, PX1, PX2, PSS, Q, QP, V;

  *D = MASSTOR_SIL;
  *B = MASSTOR_SIL;
  if (P == MASSTOR_SIL) {
    return;
  }
  PP = P;
  PSS = PP;
  BR = MASSTOR_SIL;
  do {
    MASSTOR_ADV(PSS, &PM1, &QP);
    SACLIST_FIRST2(PM1, &PI, &PX1);
    Q = MASSTOR_LIST1(PM1);
    BP = MASSTOR_COMP(0, BR);
    ELI = DIPC_DIPEVL(PI);
    while (QP != MASSTOR_SIL) {
      MASSTOR_ADV(QP, &PM2, &QP);
      SACLIST_FIRST2(PM2, &PJ, &PX2);
      ELJ = DIPC_DIPEVL(PJ);
      EL = DIPC_EVLCM(ELI, ELJ);
      *D = MASSTOR_COMP(SACLIST_LIST3(EL, BP, Q), *D);
      Q = MASSTOR_COMP(PM2, Q);
    }
    QP = MASSTOR_INV(Q);
    MASSTOR_SFIRST(BP, QP);
    BR = MASSTOR_COMP(Q, BP);
    PSS = MASSTOR_RED(PSS);
  } while (!(PSS == MASSTOR_SIL));
  *D = DIPRNGB_EVPLSO(*D);
  *B = MASSTOR_INV(BR);
}

static MASSTOR_LIST EGBLUPL
# ifdef __STDC__
(MASSTOR_LIST PM, MASSTOR_LIST P, MASSTOR_LIST D, MASSTOR_LIST B)
# else
(PM, P, D, B)
MASSTOR_LIST PM, P, D, B;
# endif
{
  MASSTOR_LIST BP, BPP, BPPP, BR, DL, DP, EL, ELI, ELJ, PB, PMI, PLI, PXI, PP, PPP, PPR, PS, Q, QS, SL, T, TF, V, HM, HI, HX;

  BP = B;
  DP = MASSTOR_SIL;
  PP = P;
  HM = PM;
  PS = MASSTOR_LIST1(HM);
  PPR = SACLIST_LAST(PP);
  MASSTOR_SRED(PPR, PS);
  SACLIST_FIRST2(HM, &HI, &HX);
  ELJ = DIPC_DIPEVL(HI);
  while (BP != MASSTOR_SIL) {
    MASSTOR_ADV(BP, &QS, &BPP);
    MASSTOR_ADV(BPP, &Q, &BPPP);
    PMI = MASSTOR_FIRST(QS);
    SACLIST_FIRST2(PMI, &PLI, &PXI);
    ELI = DIPC_DIPEVL(PLI);
    EL = DIPC_EVLCM(ELI, ELJ);
    DL = SACLIST_LIST3(EL, BP, Q);
    DP = MASSTOR_COMP(DL, DP);
    PS = MASSTOR_LIST1(HM);
    MASSTOR_SRED(Q, PS);
    MASSTOR_SFIRST(BPP, PS);
    BP = BPPP;
  }
  DP = DIPRNGB_EVPLSO(DP);
  DP = DIPRNGB_EVPLM(D, DP);
  PS = MASSTOR_LIST1(HM);
  PB = SACLIST_LIST2(PS, PS);
  BR = SACLIST_LAST(B);
  MASSTOR_SRED(BR, PB);
  return DP;
}

void TIPRNGB_DIREGB
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST TF, MASSTOR_LIST *GB, MASSTOR_LIST *GBM)
# else
(P, TF, GB, GBM)
MASSTOR_LIST P, TF;
MASSTOR_LIST *GB, *GBM;
# endif
{
  MASSTOR_LIST B, C, CPI, CPJ, CPP, D, DL, EL, ELI, ELJ, J1Y, K, PMI, PMIP, PMJ, PM, PL, PX, PP, PPP, PPR, PS, Q, QP, SM, HM, H, HX, SL, T, X3, X4, XC, XH, XS, YD, I, XX;

  *GB = MASSTOR_SIL;
  *GBM = MASSTOR_SIL;
  PP = MASSTOR_SIL;
  if (P == MASSTOR_SIL) {
    return;
  }
  PS = P;
  K = 0;
  YD = MASSTOR_LENGTH(P);
  while (PS != MASSTOR_SIL) {
    MASSTOR_ADV(PS, &PMI, &PS);
    if (PMI != 0) {
      K = K + 1;
      XX = MASSTOR_SIL;
      {
        LONGINT B_1 = K + 1, B_2 = YD;

        if (B_1 <= B_2)
          for (I = B_1;; I += 1) {
            XX = MASSTOR_COMP(0, XX);
            if (I >= B_2) break;
          }
      }
      XX = MASSTOR_COMP(DIPRN_DIRPEX(PMI, 0), XX);
      {
        LONGINT B_3 = 1, B_4 = K - 1;

        if (B_3 <= B_4)
          for (I = B_3;; I += 1) {
            XX = MASSTOR_COMP(0, XX);
            if (I >= B_4) break;
          }
      }
      PP = MASSTOR_COMP(SACLIST_LIST2(PMI, XX), PP);
    }
  }
  if (PP == MASSTOR_SIL) {
    return;
  }
  PS = PP;
  PPR = MASSTOR_SIL;
  while (PS != MASSTOR_SIL) {
    MASSTOR_ADV(PS, &PMI, &PS);
    if (PMI != MASSTOR_SIL) {
      PMIP = EGBPMC(PMI);
      SL = EGBPON(PMIP);
      if (SL == 1) {
        SACLIST_FIRST2(PMIP, GB, GBM);
        *GB = MASSTOR_LIST1(*GB);
        *GBM = MASSTOR_LIST1(*GBM);
        return;
      }
      PPR = MASSTOR_COMP(PMIP, PPR);
    }
  }
  PP = MASSTOR_INV(PPR);
  if (PP == MASSTOR_SIL || MASSTOR_RED(PP) == MASSTOR_SIL) {
    while (PP != MASSTOR_SIL) {
      MASSTOR_ADV(PP, &PM, &PP);
      SACLIST_FIRST2(PM, &PL, &PX);
      *GB = MASSTOR_COMP(PL, *GB);
      *GBM = MASSTOR_COMP(PX, *GBM);
    }
    *GB = MASSTOR_INV(*GB);
    *GBM = MASSTOR_INV(*GBM);
    return;
  }
  if (DIPC_VALIS == MASSTOR_SIL) {
    TF = 0;
  }
  T = MASSTOR_TIME();
  XH = 0;
  XS = 0;
  X3 = 0;
  X4 = 0;
  PPR = EGBLPM(PP);
  PP = MASSTOR_INV(PPR);
  EGBLCPL(PP, &D, &B);
  YD = MASSTOR_LENGTH(D);
  for (;;) {
    if (D == MASSTOR_SIL) {
      goto EXIT_2;
    }
    YD = YD - 1;
    MASSTOR_ADV(D, &DL, &D);
    SACLIST_FIRST3(DL, &EL, &CPI, &CPJ);
    MASSTOR_ADV(CPI, &QP, &C);
    PMI = MASSTOR_FIRST(QP);
    J1Y = MASSTOR_RED(CPJ);
    PMJ = MASSTOR_FIRST(J1Y);
    J1Y = MASSTOR_RED(CPJ);
    CPP = MASSTOR_RED(J1Y);
    MASSTOR_SRED(CPJ, CPP);
    if (CPP == MASSTOR_SIL) {
      Q = SACLIST_LAST(QP);
      MASSTOR_SFIRST(C, Q);
    }
    for (;;) {
      X3 = X3 + 1;
      if (EGBC3(B, PMI, PMJ, EL) == 0) {
        goto EXIT_3;
      }
      X4 = X4 + 1;
      if (EGBC4(PMI, PMJ, EL) == 0) {
        goto EXIT_3;
      }
      XS = XS + 1;
      SM = EGBPSP(PMI, PMJ);
      if (SM == MASSTOR_SIL) {
        goto EXIT_3;
      }
      XH = XH + 1;
      HM = EGBPNF(PP, SM);
      if (HM == MASSTOR_SIL) {
        goto EXIT_3;
      }
      HM = EGBPMC(HM);
      SACLIST_FIRST2(HM, &H, &HX);
      SL = EGBPON(HM);
      if (SL == 1) {
        SACLIST_FIRST2(PMIP, GB, GBM);
        *GB = MASSTOR_LIST1(*GB);
        *GBM = MASSTOR_LIST1(*GBM);
        return;
      }
      if (TF >= 1) {
        SACLIST_OWRITE(MASSTOR_TIME() - T);
        MASBIOS_SWRITE(" S, ", 4L);
        SACLIST_OWRITE(XH);
        MASBIOS_SWRITE(" H-POLYNOMIALS, ", 16L);
        SACLIST_OWRITE(YD);
        MASBIOS_SWRITE(" PAIRS LEFT.", 12L);
        MASBIOS_BLINES(0);
        MASBIOS_SWRITE("H=", 2L);
        DIPRN_DIRPWR(H, DIPC_VALIS, -1);
        MASBIOS_BLINES(0);
      }
      if (TF >= 2) {
        SACLIST_OWRITE(X3);
        MASBIOS_SWRITE(" CRIT3,  ", 9L);
        SACLIST_OWRITE(X4);
        MASBIOS_SWRITE(" CRIT4,  ", 9L);
        SACLIST_OWRITE(XS);
        MASBIOS_SWRITE(" SPOLY,  ", 9L);
        MASBIOS_BLINES(1);
      }
      D = EGBLUPL(HM, PP, D, B);
      YD = MASSTOR_LENGTH(D);
      goto EXIT_3;
    } EXIT_3:;
  } EXIT_2:;
  if (TF >= 1) {
    SACLIST_OWRITE(MASSTOR_TIME() - T);
    MASBIOS_SWRITE(" S, ", 4L);
    SACLIST_OWRITE(XH);
    MASBIOS_SWRITE(" H-POLYNOMIALS, ", 16L);
    SACLIST_OWRITE(YD);
    MASBIOS_SWRITE(" PAIRS LEFT.", 12L);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("H=", 2L);
    DIPRN_DIRPWR(H, DIPC_VALIS, -1);
    MASBIOS_BLINES(0);
  }
  if (TF >= 2) {
    SACLIST_OWRITE(X3);
    MASBIOS_SWRITE(" CRIT3,  ", 9L);
    SACLIST_OWRITE(X4);
    MASBIOS_SWRITE(" CRIT4,  ", 9L);
    SACLIST_OWRITE(XS);
    MASBIOS_SWRITE(" SPOLY,  ", 9L);
    MASBIOS_BLINES(1);
  }
  PP = EGBMI(PP);
  while (PP != MASSTOR_SIL) {
    MASSTOR_ADV(PP, &PM, &PP);
    SACLIST_FIRST2(PM, &PL, &PX);
    *GB = MASSTOR_COMP(PL, *GB);
    *GBM = MASSTOR_COMP(PX, *GBM);
  }
  *GB = MASSTOR_INV(*GB);
  *GBM = MASSTOR_INV(*GBM);
}

void BEGIN_TIPRNGB()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_MASBIOS();
    BEGIN_SACRN();
    BEGIN_DIPC();
    BEGIN_DIPRN();
    BEGIN_DIPRNGB();

  }
}
