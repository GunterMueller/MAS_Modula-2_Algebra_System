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

CHAR DIPRNGB_rcsid [] = "$Id: DIPRNGB.md,v 1.2 1992/02/12 17:34:23 pesch Exp $";
CHAR DIPRNGB_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: DIPRNGB.mi,v 1.3 1992/10/15 16:29:39 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST DIPRNGB_DIGBC3
# ifdef __STDC__
(MASSTOR_LIST B, MASSTOR_LIST PLI, MASSTOR_LIST PLJ, MASSTOR_LIST EL)
# else
(B, PLI, PLJ, EL)
MASSTOR_LIST B, PLI, PLJ, EL;
# endif
{
  MASSTOR_LIST BP, EP, PL, PP, PPI, PPJ, PS, Q, QL, SL, TL;

  BP = B;
  do {
    SACLIST_ADV2(BP, &PS, &Q, &BP);
    MASSTOR_ADV(PS, &PL, &PS);
    if (PL != PLI) {
      EP = DIPC_DIPEVL(PL);
      TL = DIPC_EVMT(EL, EP);
      if (TL == 1) {
        SL = 0;
        PP = PS;
        while (PP != MASSTOR_SIL && SL == 0) {
          MASSTOR_ADV(PP, &QL, &PP);
          if (QL == PLI || QL == PLJ) {
            SL = 1;
          }
        }
        if (SL == 0) {
          return SL;
        }
      }
    }
  } while (!(PL == PLI));
  PPI = PS;
  do {
    SACLIST_ADV2(BP, &PS, &Q, &BP);
    MASSTOR_ADV(PS, &PL, &PS);
    if (PL != PLJ) {
      EP = DIPC_DIPEVL(PL);
      TL = DIPC_EVMT(EL, EP);
      if (TL == 1) {
        SL = 0;
        PP = PPI;
        while (PP != MASSTOR_SIL && SL == 0) {
          MASSTOR_ADV(PP, &QL, &PP);
          if (QL == PL) {
            SL = 1;
          }
        }
        PP = PS;
        while (PP != MASSTOR_SIL && SL == 0) {
          MASSTOR_ADV(PP, &QL, &PP);
          if (QL == PLJ) {
            SL = 1;
          }
        }
        if (SL == 0) {
          return SL;
        }
      }
    }
  } while (!(PL == PLJ));
  PPJ = PS;
  while (BP != MASSTOR_SIL) {
    SACLIST_ADV2(BP, &PS, &Q, &BP);
    MASSTOR_ADV(PS, &PL, &PS);
    EP = DIPC_DIPEVL(PL);
    TL = DIPC_EVMT(EL, EP);
    if (TL == 1) {
      SL = 0;
      PP = PPI;
      while (PP != MASSTOR_SIL && SL == 0) {
        MASSTOR_ADV(PP, &QL, &PP);
        if (QL == PL) {
          SL = 1;
        }
      }
      PP = PPJ;
      while (PP != MASSTOR_SIL && SL == 0) {
        MASSTOR_ADV(PP, &QL, &PP);
        if (QL == PL) {
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

MASSTOR_LIST DIPRNGB_DIGBC4
# ifdef __STDC__
(MASSTOR_LIST PLI, MASSTOR_LIST PLJ, MASSTOR_LIST EL)
# else
(PLI, PLJ, EL)
MASSTOR_LIST PLI, PLJ, EL;
# endif
{
  MASSTOR_LIST EI, EJ, EP, SL;

  EI = DIPC_DIPEVL(PLI);
  EJ = DIPC_DIPEVL(PLJ);
  EP = DIPC_EVSUM(EI, EJ);
  SL = SACLIST_EQUAL(EL, EP);
  SL = 1 - SL;
  return SL;
}

MASSTOR_LIST DIPRNGB_DIGBMI
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST AL, EI, EJ, EL, PB, PI, PIP, PJ, PP, PS, QP, TL;

  PP = P;
  if (P == MASSTOR_SIL || MASSTOR_RED(P) == MASSTOR_SIL) {
    return PP;
  }
  PS = PP;
  QP = MASSTOR_BETA;
  do {
    MASSTOR_ADV(PS, &PI, &PS);
    PB = PS;
    EI = DIPC_DIPEVL(PI);
    TL = 0;
    while (PB != MASSTOR_SIL && TL == 0) {
      MASSTOR_ADV(PB, &PJ, &PB);
      EJ = DIPC_DIPEVL(PJ);
      TL = DIPC_EVMT(EI, EJ);
    }
    PB = QP;
    while (PB != MASSTOR_SIL && TL == 0) {
      MASSTOR_ADV(PB, &PJ, &PB);
      EJ = DIPC_DIPEVL(PJ);
      TL = DIPC_EVMT(EI, EJ);
    }
    if (TL == 0) {
      QP = MASSTOR_COMP(PI, QP);
    }
  } while (!(PS == MASSTOR_SIL));
  PP = MASSTOR_INV(QP);
  if (PP == MASSTOR_SIL || MASSTOR_RED(PP) == MASSTOR_SIL) {
    return PP;
  }
  PS = PP;
  QP = PP;
  PP = MASSTOR_BETA;
  do {
    MASSTOR_ADV(PS, &PI, &PS);
    DIPC_DIPMAD(PI, &AL, &EL, &PIP);
    if (PIP != MASSTOR_SIL) {
      PIP = DIPRNGB_DIRPNF(QP, PIP);
      if (PIP != 0) {
        PI = DIPC_DIPMCP(AL, EL, PIP);
      } else {
        PI = DIPC_DIPFMO(AL, EL);
      }
    }
    PP = MASSTOR_COMP(PI, PP);
  } while (!(PS == MASSTOR_SIL));
  PP = MASSTOR_INV(PP);
  if (PP == MASSTOR_SIL || MASSTOR_RED(PP) == MASSTOR_SIL) {
    return PP;
  }
  PP = DIPC_DIPLPM(PP);
  return PP;
}

void DIPRNGB_DILCPL
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST *D, MASSTOR_LIST *B)
# else
(P, D, B)
MASSTOR_LIST P;
MASSTOR_LIST *D, *B;
# endif
{
  MASSTOR_LIST BP, BR, DL, EL, ELI, ELJ, PI, PJ, PP, PSS, Q, QP, V;

  *D = MASSTOR_BETA;
  *B = MASSTOR_BETA;
  if (P == MASSTOR_SIL) {
    return;
  }
  PP = P;
  BR = MASSTOR_BETA;
  PSS = PP;
  do {
    MASSTOR_ADV(PSS, &PI, &QP);
    Q = MASSTOR_LIST1(PI);
    BP = MASSTOR_COMP(0, BR);
    ELI = DIPC_DIPEVL(PI);
    while (QP != MASSTOR_SIL) {
      MASSTOR_ADV(QP, &PJ, &QP);
      ELJ = DIPC_DIPEVL(PJ);
      EL = DIPC_EVLCM(ELI, ELJ);
      DL = SACLIST_LIST3(EL, BP, Q);
      *D = MASSTOR_COMP(DL, *D);
      Q = MASSTOR_COMP(PJ, Q);
    }
    QP = MASSTOR_INV(Q);
    MASSTOR_SFIRST(BP, QP);
    BR = MASSTOR_COMP(Q, BP);
    PSS = MASSTOR_RED(PSS);
  } while (!(PSS == MASSTOR_SIL));
  *D = DIPRNGB_EVPLSO(*D);
  *B = MASSTOR_INV(BR);
}

MASSTOR_LIST DIPRNGB_DILUPL
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST P, MASSTOR_LIST D, MASSTOR_LIST B)
# else
(PL, P, D, B)
MASSTOR_LIST PL, P, D, B;
# endif
{
  MASSTOR_LIST BP, BPP, BPPP, BR, DL, DP, EL, ELI, ELJ, H, PB, PLI, PLJ, PP, PPP, PPR, PS, Q, QS, SL, T, TF, V;

  BP = B;
  DP = MASSTOR_BETA;
  PP = P;
  H = PL;
  PS = MASSTOR_LIST1(H);
  PPR = SACLIST_LAST(PP);
  MASSTOR_SRED(PPR, PS);
  ELJ = DIPC_DIPEVL(H);
  while (BP != MASSTOR_SIL) {
    MASSTOR_ADV(BP, &QS, &BPP);
    MASSTOR_ADV(BPP, &Q, &BPPP);
    PLI = MASSTOR_FIRST(QS);
    ELI = DIPC_DIPEVL(PLI);
    EL = DIPC_EVLCM(ELI, ELJ);
    DL = SACLIST_LIST3(EL, BP, Q);
    DP = MASSTOR_COMP(DL, DP);
    PS = MASSTOR_LIST1(H);
    MASSTOR_SRED(Q, PS);
    MASSTOR_SFIRST(BPP, PS);
    BP = BPPP;
  }
  DP = DIPRNGB_EVPLSO(DP);
  DP = DIPRNGB_EVPLM(D, DP);
  PS = MASSTOR_LIST1(H);
  PB = SACLIST_LIST2(PS, PS);
  BR = SACLIST_LAST(B);
  MASSTOR_SRED(BR, PB);
  return DP;
}

MASSTOR_LIST DIPRNGB_DIRGBA
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST P, MASSTOR_LIST TF)
# else
(PL, P, TF)
MASSTOR_LIST PL, P, TF;
# endif
{
  MASSTOR_LIST B, C, CPI, CPJ, CPP, D, DL, EL, ELI, ELJ, H, J1Y, K, PLI, PLJ, PLS, PP, PSS, Q, QL, QLS, QP, RL, S, SL, T, X3, X4, XC, XD, XH, XS, XT, YD;

  T = MASSTOR_TIME();
  XH = 0;
  PLS = DIPRN_DIRPMC(PL);
  if (P == MASSTOR_SIL) {
    PP = MASSTOR_LIST1(PLS);
    return PP;
  }
  PLS = DIPRNGB_DIRPNF(P, PLS);
  J1Y = SACLIST_CINV(P);
  PP = MASSTOR_INV(J1Y);
  if (PLS == 0) {
    return PP;
  }
  PLS = DIPRN_DIRPMC(PLS);
  if (DIPC_VALIS == MASSTOR_SIL) {
    TF = 0;
  }
  D = MASSTOR_BETA;
  B = MASSTOR_BETA;
  PSS = PP;
  while (PSS != MASSTOR_SIL) {
    MASSTOR_ADV(PSS, &QL, &PSS);
    QLS = MASSTOR_LIST1(QL);
    B = SACLIST_COMP2(QLS, QLS, B);
  }
  B = MASSTOR_INV(B);
  D = DIPRNGB_DILUPL(PLS, PP, D, B);
  XD = MASSTOR_LENGTH(D);
  YD = XD;
  X3 = 0;
  X4 = 0;
  XS = 0;
  XH = 0;
  XT = MASSTOR_TIME();
  XC = MASSTOR_CELLS();
  for (;;) {
    if (D == MASSTOR_SIL) {
      goto EXIT_1;
    }
    YD = YD - 1;
    MASSTOR_ADV(D, &DL, &D);
    SACLIST_FIRST3(DL, &EL, &CPI, &CPJ);
    MASSTOR_ADV(CPI, &QP, &C);
    PLI = MASSTOR_FIRST(QP);
    J1Y = MASSTOR_RED(CPJ);
    PLJ = MASSTOR_FIRST(J1Y);
    J1Y = MASSTOR_RED(CPJ);
    CPP = MASSTOR_RED(J1Y);
    MASSTOR_SRED(CPJ, CPP);
    if (CPP == MASSTOR_SIL) {
      Q = SACLIST_LAST(QP);
      MASSTOR_SFIRST(C, Q);
    }
    for (;;) {
      X3 = X3 + 1;
      SL = DIPRNGB_DIGBC3(B, PLI, PLJ, EL);
      if (SL == 0) {
        goto EXIT_2;
      }
      X4 = X4 + 1;
      SL = DIPRNGB_DIGBC4(PLI, PLJ, EL);
      if (SL == 0) {
        goto EXIT_2;
      }
      XS = XS + 1;
      S = DIPRNGB_DIRPSP(PLI, PLJ);
      if (S == 0) {
        goto EXIT_2;
      }
      XH = XH + 1;
      H = DIPRNGB_DIRPNF(PP, S);
      if (H == 0) {
        goto EXIT_2;
      }
      H = DIPRN_DIRPMC(H);
      if (TF >= 1) {
        SACLIST_AWRITE(MASSTOR_TIME() - T);
        MASBIOS_SWRITE(" S, ", 4L);
        SACLIST_AWRITE(XH);
        MASBIOS_SWRITE(" H-POLYNOMIALS, ", 16L);
        SACLIST_AWRITE(MASSTOR_LENGTH(D));
        MASBIOS_SWRITE(" PAIRS LEFT.", 12L);
        MASBIOS_BLINES(0);
        MASBIOS_SWRITE("H=", 2L);
        DIPRN_DIRPWR(H, DIPC_VALIS, -1);
        MASBIOS_BLINES(0);
      }
      if (TF >= 2) {
        SACLIST_AWRITE(X3);
        MASBIOS_SWRITE(" CRIT3,  ", 9L);
        SACLIST_AWRITE(X4);
        MASBIOS_SWRITE(" CRIT4,  ", 9L);
        SACLIST_AWRITE(XS);
        MASBIOS_SWRITE(" SPOLY,  ", 9L);
        MASBIOS_BLINES(1);
      }
      D = DIPRNGB_DILUPL(H, PP, D, B);
      XD = MASSTOR_LENGTH(D);
      goto EXIT_2;
    } EXIT_2:;
  } EXIT_1:;
  if (TF >= 1) {
    SACLIST_AWRITE(MASSTOR_TIME() - T);
    MASBIOS_SWRITE(" S, ", 4L);
    SACLIST_AWRITE(XH);
    MASBIOS_SWRITE(" H-POLYNOMIALS, ", 16L);
    SACLIST_AWRITE(MASSTOR_LENGTH(D));
    MASBIOS_SWRITE(" PAIRS LEFT.", 12L);
    MASBIOS_BLINES(0);
  }
  if (TF >= 2) {
    SACLIST_AWRITE(X3);
    MASBIOS_SWRITE(" CRIT3,  ", 9L);
    SACLIST_AWRITE(X4);
    MASBIOS_SWRITE(" CRIT4,  ", 9L);
    SACLIST_AWRITE(XS);
    MASBIOS_SWRITE(" SPOLY,  ", 9L);
    MASBIOS_BLINES(1);
  }
  PP = DIPRNGB_DIGBMI(PP);
  return PP;
}

MASSTOR_LIST DIPRNGB_DIRGBR
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST TF)
# else
(P, TF)
MASSTOR_LIST P, TF;
# endif
{
  MASSTOR_LIST PL, PP, PS;

  PP = MASSTOR_BETA;
  PS = P;
  while (PS != MASSTOR_SIL) {
    MASSTOR_ADV(PS, &PL, &PS);
    PP = DIPRNGB_DIRGBA(PL, PP, TF);
  }
  return PP;
}

MASSTOR_LIST DIPRNGB_DIRLIS
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST EL, FL, IRR, LL, PL, PP, PS, RL, RP, SL;

  PP = P;
  PS = MASSTOR_BETA;
  while (PP != MASSTOR_SIL) {
    MASSTOR_ADV(PP, &PL, &PP);
    PL = DIPRN_DIRPMC(PL);
    if (PL != 0) {
      PS = MASSTOR_COMP(PL, PS);
    }
  }
  RP = PS;
  PP = MASSTOR_INV(PS);
  LL = MASSTOR_LENGTH(PP);
  IRR = 0;
  if (LL <= 1) {
    return PP;
  }
  MASBIOS_SWRITE("***NF IRR= ", 11L);
  for (;;) {
    MASSTOR_ADV(PP, &PL, &PP);
    EL = DIPC_DIPEVL(PL);
    PL = DIPRNGB_DIRPNF(PP, PL);
    SACLIST_AWRITE(IRR);
    MASBIOS_SWRITE(", ", 2L);
    if (PL == 0) {
      LL = LL - 1;
      if (LL <= 1) {
        goto EXIT_3;
      }
    } else {
      FL = DIPC_DIPEVL(PL);
      SL = DIPC_EVSIGN(FL);
      if (SL == 0) {
        PP = MASSTOR_LIST1(PL);
        goto EXIT_3;
      }
      SL = SACLIST_EQUAL(EL, FL);
      if (SL == 1) {
        IRR = IRR + 1;
      } else {
        IRR = 0;
        PL = DIPRN_DIRPMC(PL);
      }
      PS = MASSTOR_LIST1(PL);
      MASSTOR_SRED(RP, PS);
      RP = PS;
    }
    if (IRR == LL) {
      goto EXIT_3;
    }
  } EXIT_3:;
  MASBIOS_BLINES(0);
  return PP;
}

MASSTOR_LIST DIPRNGB_DIRPGB
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST TF)
# else
(P, TF)
MASSTOR_LIST P, TF;
# endif
{
  MASSTOR_LIST B, C, CPI, CPJ, CPP, CR, D, DL, EL, ELI, ELJ, H, IL, J1Y, K, PLI, PLIP, PLJ, PP, PPP, PPR, PS, Q, QP, RL, S, SL, T, TR, X3, X4, XC, XH, XS, XT, YD, ZD;

  if (P == MASSTOR_SIL) {
    PP = P;
    return PP;
  }
  PS = P;
  PPR = MASSTOR_BETA;
  while (PS != MASSTOR_SIL) {
    MASSTOR_ADV(PS, &PLI, &PS);
    if (PLI != 0) {
      PLIP = DIPRN_DIRPMC(PLI);
      SL = DIPRN_DIRPON(PLIP);
      if (SL == 1) {
        PP = MASSTOR_LIST1(PLIP);
        return PP;
      }
      PPR = MASSTOR_COMP(PLIP, PPR);
    }
  }
  PP = MASSTOR_INV(PPR);
  if (PP == MASSTOR_SIL || MASSTOR_RED(PP) == MASSTOR_SIL) {
    return PP;
  }
  if (DIPC_VALIS == MASSTOR_SIL) {
    TF = 0;
  }
  T = MASSTOR_TIME();
  XH = 0;
  XS = 0;
  X3 = 0;
  X4 = 0;
  if (TF < 0) {
    TF = -TF;
    TR = MASSTOR_TIME();
    CR = MASSTOR_CELLS();
    PP = DIPRNGB_DIRLIS(PP);
    MASBIOS_SWRITE("***IRR TIME=", 12L);
    SACLIST_AWRITE(MASSTOR_TIME() - TR);
    MASBIOS_SWRITE(", CELLS=", 8L);
    SACLIST_AWRITE(MASSTOR_CELLS() - CR);
    MASBIOS_BLINES(1);
  }
  PPR = DIPC_DIPLPM(PP);
  PP = MASSTOR_INV(PPR);
  DIPRNGB_DILCPL(PP, &D, &B);
  YD = MASSTOR_LENGTH(D);
  for (;;) {
    if (D == MASSTOR_SIL) {
      goto EXIT_4;
    }
    YD = YD - 1;
    MASSTOR_ADV(D, &DL, &D);
    SACLIST_FIRST3(DL, &EL, &CPI, &CPJ);
    MASSTOR_ADV(CPI, &QP, &C);
    PLI = MASSTOR_FIRST(QP);
    J1Y = MASSTOR_RED(CPJ);
    PLJ = MASSTOR_FIRST(J1Y);
    J1Y = MASSTOR_RED(CPJ);
    CPP = MASSTOR_RED(J1Y);
    MASSTOR_SRED(CPJ, CPP);
    if (CPP == MASSTOR_SIL) {
      Q = SACLIST_LAST(QP);
      MASSTOR_SFIRST(C, Q);
    }
    for (;;) {
      X3 = X3 + 1;
      SL = DIPRNGB_DIGBC3(B, PLI, PLJ, EL);
      if (SL == 0) {
        goto EXIT_5;
      }
      X4 = X4 + 1;
      SL = DIPRNGB_DIGBC4(PLI, PLJ, EL);
      if (SL == 0) {
        goto EXIT_5;
      }
      XS = XS + 1;
      S = DIPRNGB_DIRPSP(PLI, PLJ);
      if (S == 0) {
        goto EXIT_5;
      }
      XH = XH + 1;
      H = DIPRNGB_DIRPNF(PP, S);
      if (H == 0) {
        goto EXIT_5;
      }
      H = DIPRN_DIRPMC(H);
      SL = DIPRN_DIRPON(H);
      if (SL == 1) {
        PP = MASSTOR_LIST1(H);
        return PP;
      }
      if (TF >= 1) {
        SACLIST_AWRITE(MASSTOR_TIME() - T);
        MASBIOS_SWRITE(" S, ", 4L);
        SACLIST_AWRITE(XH);
        MASBIOS_SWRITE(" H-POLYNOMIALS, ", 16L);
        SACLIST_AWRITE(YD);
        MASBIOS_SWRITE(" PAIRS LEFT.", 12L);
        MASBIOS_BLINES(0);
        MASBIOS_SWRITE("H=", 2L);
        DIPRN_DIRPWR(H, DIPC_VALIS, -1);
        MASBIOS_BLINES(0);
      }
      if (TF >= 2) {
        SACLIST_AWRITE(X3);
        MASBIOS_SWRITE(" CRIT3,  ", 9L);
        SACLIST_AWRITE(X4);
        MASBIOS_SWRITE(" CRIT4,  ", 9L);
        SACLIST_AWRITE(XS);
        MASBIOS_SWRITE(" SPOLY,  ", 9L);
        MASBIOS_BLINES(1);
      }
      D = DIPRNGB_DILUPL(H, PP, D, B);
      YD = MASSTOR_LENGTH(D);
      goto EXIT_5;
    } EXIT_5:;
  } EXIT_4:;
  if (TF >= 1) {
    SACLIST_AWRITE(MASSTOR_TIME() - T);
    MASBIOS_SWRITE(" S, ", 4L);
    SACLIST_AWRITE(XH);
    MASBIOS_SWRITE(" H-POLYNOMIALS, ", 16L);
    SACLIST_AWRITE(YD);
    MASBIOS_SWRITE(" PAIRS LEFT.", 12L);
    MASBIOS_BLINES(0);
  }
  if (TF >= 2) {
    SACLIST_AWRITE(X3);
    MASBIOS_SWRITE(" CRIT3,  ", 9L);
    SACLIST_AWRITE(X4);
    MASBIOS_SWRITE(" CRIT4,  ", 9L);
    SACLIST_AWRITE(XS);
    MASBIOS_SWRITE(" SPOLY,  ", 9L);
    MASBIOS_BLINES(1);
  }
  PP = DIPRNGB_DIGBMI(PP);
  return PP;
}

MASSTOR_LIST DIPRNGB_DIRPNF
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST S)
# else
(P, S)
MASSTOR_LIST P, S;
# endif
{
  MASSTOR_LIST AP, APP, BL, FL, PP, Q, QA, QE, QP, R, SL, SP, TA, TE;

  if (S == 0 || P == MASSTOR_SIL) {
    R = S;
    return R;
  }
  R = MASSTOR_SIL;
  SP = S;
  do {
    DIPC_DIPMAD(SP, &TA, &TE, &SP);
    if (SP == MASSTOR_SIL) {
      SP = 0;
    }
    PP = P;
    do {
      MASSTOR_ADV(PP, &Q, &PP);
      DIPC_DIPMAD(Q, &QA, &QE, &QP);
      SL = DIPC_EVMT(TE, QE);
    } while (!(PP == MASSTOR_SIL || SL == 1));
    if (SL == 0) {
      R = DIPC_DIPMCP(TE, TA, R);
    } else {
      if (QP != MASSTOR_SIL) {
        FL = DIPC_EVDIF(TE, QE);
        BL = SACRN_RNQ(TA, QA);
        AP = DIPC_DIPFMO(BL, FL);
        APP = DIPRN_DIRPPR(QP, AP);
        SP = DIPRN_DIRPDF(SP, APP);
      }
    }
  } while (!(SP == 0));
  if (R == MASSTOR_SIL) {
    R = 0;
  } else {
    R = MASSTOR_INV(R);
  }
  return R;
}

MASSTOR_LIST DIPRNGB_DIRPSP
# ifdef __STDC__
(MASSTOR_LIST C_84_A, MASSTOR_LIST B)
# else
(C_84_A, B)
MASSTOR_LIST C_84_A, B;
# endif
{
  MASSTOR_LIST AL, AP, APP, BL, BP, BPP, C, CL, EL, EL1, FL, FL1, GL;

  C = 0;
  if (C_84_A == 0 || B == 0) {
    return C;
  }
  DIPC_DIPMAD(C_84_A, &AL, &EL, &AP);
  DIPC_DIPMAD(B, &BL, &FL, &BP);
  if (AP == MASSTOR_SIL && BP == MASSTOR_SIL) {
    return C;
  }
  GL = DIPC_EVLCM(EL, FL);
  if (AP == MASSTOR_SIL) {
    FL1 = DIPC_EVDIF(GL, FL);
    CL = SACRN_RNNEG(AL);
    BPP = DIPC_DIPFMO(CL, FL1);
    C = DIPRN_DIRPPR(BP, BPP);
    return C;
  }
  if (BP == MASSTOR_SIL) {
    EL1 = DIPC_EVDIF(GL, EL);
    APP = DIPC_DIPFMO(BL, EL1);
    C = DIPRN_DIRPPR(AP, APP);
    return C;
  }
  EL1 = DIPC_EVDIF(GL, EL);
  FL1 = DIPC_EVDIF(GL, FL);
  APP = DIPC_DIPFMO(BL, EL1);
  BPP = DIPC_DIPFMO(AL, FL1);
  APP = DIPRN_DIRPPR(AP, APP);
  BPP = DIPRN_DIRPPR(BP, BPP);
  C = DIPRN_DIRPDF(APP, BPP);
  return C;
}

MASSTOR_LIST DIPRNGB_EVPLM
# ifdef __STDC__
(MASSTOR_LIST L1, MASSTOR_LIST L2)
# else
(L1, L2)
MASSTOR_LIST L1, L2;
# endif
{
  MASSTOR_LIST AL1, AL2, EL1, EL2, L, LP, LP1, LP2, TL;
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
  AL1 = MASSTOR_FIRST(L1);
  AL2 = MASSTOR_FIRST(L2);
  EL1 = MASSTOR_FIRST(AL1);
  EL2 = MASSTOR_FIRST(AL2);
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
        goto EXIT_6;
      }
      AL1 = MASSTOR_FIRST(LP1);
      EL1 = MASSTOR_FIRST(AL1);
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
        goto EXIT_6;
      }
      AL2 = MASSTOR_FIRST(LP2);
      EL2 = MASSTOR_FIRST(AL2);
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
  } EXIT_6:;
  if (LP1 == MASSTOR_SIL) {
    MASSTOR_SRED(LP, LP2);
  } else {
    MASSTOR_SRED(LP, LP1);
  }
  return L;
}

MASSTOR_LIST DIPRNGB_EVPLSO
# ifdef __STDC__
(MASSTOR_LIST C_83_A)
# else
(C_83_A)
MASSTOR_LIST C_83_A;
# endif
{
  MASSTOR_LIST AL1, AL2, AP, APP, APPP, B, BP, BPP, C, CP, CPP, CS, EL1, EL2, TL;

  if (C_83_A == MASSTOR_SIL || MASSTOR_RED(C_83_A) == MASSTOR_SIL) {
    B = C_83_A;
    return B;
  }
  C = MASSTOR_LIST1(0);
  CS = C;
  AP = C_83_A;
  do {
    MASSTOR_ADV(AP, &AL1, &APP);
    if (APP == MASSTOR_SIL) {
      BP = AP;
    } else {
      MASSTOR_ADV(APP, &AL2, &APPP);
      EL1 = MASSTOR_FIRST(AL1);
      EL2 = MASSTOR_FIRST(AL2);
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
    BPP = DIPRNGB_EVPLM(B, BP);
    MASSTOR_SFIRST(C, BPP);
    MASSTOR_SRED(C, CPP);
    C = CPP;
    MASSTOR_ADV(C, &B, &CP);
  }
  return B;
}

void BEGIN_DIPRNGB()
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

  }
}
