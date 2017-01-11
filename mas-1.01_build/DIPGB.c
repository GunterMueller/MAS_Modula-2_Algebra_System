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

#ifndef DEFINITION_SACI
#include "SACI.h"
#endif

#ifndef DEFINITION_SACRN
#include "SACRN.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPRNGB
#include "DIPRNGB.h"
#endif

#ifndef DEFINITION_DIPADOM
#include "DIPADOM.h"
#endif

#ifndef DEFINITION_MASADOM
#include "MASADOM.h"
#endif

#ifndef DEFINITION_DIPGB
#include "DIPGB.h"
#endif

CHAR DIPGB_rcsid [] = "$Id: DIPGB.md,v 1.2 1992/02/12 17:31:22 pesch Exp $";
CHAR DIPGB_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: DIPGB.mi,v 1.5 1994/07/29 12:01:22 rose Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST DIPGB_DIGMIN
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
      PIP = DIPGB_DIPNOR(QP, PIP);
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

MASSTOR_LIST DIPGB_DILIS
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST EL, FL, IRR, LL, PL, PP, PS, RP, SL;

  PP = P;
  PS = MASSTOR_BETA;
  while (PP != MASSTOR_SIL) {
    MASSTOR_ADV(PP, &PL, &PP);
    PL = DIPADOM_DIPMOC(PL);
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
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("***nf irr= ", 11L);
  do {
    MASSTOR_ADV(PP, &PL, &PP);
    EL = DIPC_DIPEVL(PL);
    PL = DIPGB_DIPNOR(PP, PL);
    SACLIST_AWRITE(IRR);
    MASBIOS_SWRITE(", ", 2L);
    if (PL == 0) {
      LL = LL - 1;
      if (LL <= 1) {
        return PP;
      }
    } else {
      FL = DIPC_DIPEVL(PL);
      SL = SACLIST_EQUAL(EL, FL);
      if (SL == 1) {
        IRR = IRR + 1;
      } else {
        IRR = 0;
        PL = DIPADOM_DIPMOC(PL);
      }
      PS = MASSTOR_LIST1(PL);
      MASSTOR_SRED(RP, PS);
      RP = PS;
    }
  } while (!(IRR == LL));
  MASBIOS_BLINES(1);
  SACLIST_AWRITE(LL);
  MASBIOS_SWRITE(" irreducible polynomials", 24L);
  MASBIOS_BLINES(1);
  return PP;
}

MASSTOR_LIST DIPGB_DIPGB
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST TF)
# else
(P, TF)
MASSTOR_LIST P, TF;
# endif
{
  MASSTOR_LIST B, C, CPI, CPJ, CPP, CR, D, DL, EL, ELI, ELJ, H, IL, J1Y, K, PL, PLI, PLJ, PP, PPR, PS, PSS, Q, QP, RL, S, SL, T, TR, X3, X4, XC, XD, XH, XS, XT, YD;

  if (P == MASSTOR_SIL) {
    PP = P;
    return PP;
  }
  PS = P;
  PPR = MASSTOR_BETA;
  while (PS != MASSTOR_SIL) {
    MASSTOR_ADV(PS, &PLI, &PS);
    PL = DIPADOM_DIPMOC(PLI);
    if (PLI != 0) {
      PPR = MASSTOR_COMP(PL, PPR);
    }
  }
  PP = MASSTOR_INV(PPR);
  if (PP == MASSTOR_SIL || MASSTOR_RED(PP) == MASSTOR_SIL) {
    return PP;
  }
  X3 = 0;
  X4 = 0;
  XS = 0;
  XH = 0;
  XT = MASSTOR_TIME();
  XC = MASSTOR_CELLS();
  PPR = DIPC_DIPLPM(PP);
  PP = MASSTOR_INV(PPR);
  PSS = PP;
  DIPRNGB_DILCPL(PP, &D, &B);
  XD = MASSTOR_LENGTH(D);
  YD = XD;
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
      S = DIPGB_DIPSP(PLI, PLJ);
      if (S == 0) {
        goto EXIT_2;
      }
      XH = XH + 1;
      H = DIPGB_DIPNOR(PP, S);
      if (H == 0) {
        goto EXIT_2;
      }
      H = DIPADOM_DIPMOC(H);
      if (TF >= 3) {
        SACLIST_AWRITE(MASSTOR_TIME() - XT);
        MASBIOS_SWRITE(" ms,  ", 6L);
        SACLIST_AWRITE(MASSTOR_CELLS() - XC);
        MASBIOS_SWRITE(" cells,  ", 9L);
        MASBIOS_BLINES(0);
        SACLIST_AWRITE(X3);
        MASBIOS_SWRITE(" crit3,  ", 9L);
        SACLIST_AWRITE(X4);
        MASBIOS_SWRITE(" crit4,  ", 9L);
        SACLIST_AWRITE(XS);
        MASBIOS_SWRITE(" spoly,  ", 9L);
        SACLIST_AWRITE(XH);
        MASBIOS_SWRITE(" hpoly,  ", 9L);
        MASBIOS_BLINES(0);
        SACLIST_AWRITE(XD);
        MASBIOS_SWRITE(" pairs,  ", 9L);
        SACLIST_AWRITE(YD);
        MASBIOS_SWRITE(" restp,  ", 9L);
        SACRN_RNDWR(SACRN_RNRED(YD, XD), 3);
        MASBIOS_SWRITE(" quot.", 6L);
        MASBIOS_BLINES(1);
        MASBIOS_SWRITE("H=", 2L);
        DIPADOM_DIWRIT(H, DIPC_VALIS);
        MASBIOS_BLINES(1);
      }
      D = DIPRNGB_DILUPL(H, PP, D, B);
      XD = MASSTOR_LENGTH(D);
      YD = XD;
      X3 = 0;
      X4 = 0;
      XH = 0;
      XS = 0;
      goto EXIT_2;
    } EXIT_2:;
  } EXIT_1:;
  if (TF >= 1) {
    SACLIST_AWRITE(MASSTOR_TIME() - XT);
    MASBIOS_SWRITE(" ms,  ", 6L);
    SACLIST_AWRITE(MASSTOR_CELLS() - XC);
    MASBIOS_SWRITE(" cells;  ", 9L);
  }
  if (TF >= 2) {
    MASBIOS_BLINES(0);
    SACLIST_AWRITE(X3);
    MASBIOS_SWRITE(" crit3,  ", 9L);
    SACLIST_AWRITE(X4);
    MASBIOS_SWRITE(" crit4,  ", 9L);
    SACLIST_AWRITE(XS);
    MASBIOS_SWRITE(" spoly,  ", 9L);
    SACLIST_AWRITE(XH);
    MASBIOS_SWRITE(" hpoly,  ", 9L);
    MASBIOS_BLINES(0);
    SACLIST_AWRITE(XD);
    MASBIOS_SWRITE(" pairs,  ", 9L);
    SACLIST_AWRITE(YD);
    MASBIOS_SWRITE(" restp,  ", 9L);
    SACRN_RNDWR(SACRN_RNRED(YD, XD), 3);
    MASBIOS_SWRITE(" quot.", 6L);
  }
  MASBIOS_BLINES(1);
  PP = DIPGB_DIGMIN(PP);
  return PP;
}

MASSTOR_LIST DIPGB_DIPNOR
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
  R = MASSTOR_BETA;
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
        BL = MASADOM_ADQUOT(TA, QA);
        AP = DIPC_DIPFMO(BL, FL);
        APP = DIPADOM_DIPROD(QP, AP);
        SP = DIPADOM_DIPDIF(SP, APP);
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

MASSTOR_LIST DIPGB_DIPSP
# ifdef __STDC__
(MASSTOR_LIST C_134_A, MASSTOR_LIST B)
# else
(C_134_A, B)
MASSTOR_LIST C_134_A, B;
# endif
{
  MASSTOR_LIST AL, AP, APP, BL, BP, BPP, C, CL, EL, EL1, FL, FL1, GL;

  C = 0;
  if (C_134_A == 0 || B == 0) {
    return C;
  }
  DIPC_DIPMAD(C_134_A, &AL, &EL, &AP);
  DIPC_DIPMAD(B, &BL, &FL, &BP);
  if (AP == MASSTOR_SIL && BP == MASSTOR_SIL) {
    return C;
  }
  GL = DIPC_EVLCM(EL, FL);
  if (AP == MASSTOR_SIL) {
    FL1 = DIPC_EVDIF(GL, FL);
    CL = MASADOM_ADNEG(AL);
    BPP = DIPC_DIPFMO(CL, FL1);
    C = DIPADOM_DIPROD(BP, BPP);
    return C;
  }
  if (BP == MASSTOR_SIL) {
    EL1 = DIPC_EVDIF(GL, EL);
    APP = DIPC_DIPFMO(BL, EL1);
    C = DIPADOM_DIPROD(AP, APP);
    return C;
  }
  EL1 = DIPC_EVDIF(GL, EL);
  FL1 = DIPC_EVDIF(GL, FL);
  APP = DIPC_DIPFMO(BL, EL1);
  BPP = DIPC_DIPFMO(AL, FL1);
  APP = DIPADOM_DIPROD(AP, APP);
  BPP = DIPADOM_DIPROD(BP, BPP);
  C = DIPADOM_DIPDIF(APP, BPP);
  return C;
}

MASSTOR_LIST DIPGB_DIIFGB
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST TF)
# else
(P, TF)
MASSTOR_LIST P, TF;
# endif
{
  MASSTOR_LIST B, C, CL, CPI, CPJ, CPP, CR, D, DL, EL, ELI, ELJ, H, IL, J1Y, PLI, PLJ, PP, PPP, PPR, PS, Q, QP, RL, S, SL, T, TR, X3, X4, XC, XD, XDP, XH, XS, XT, YD, ZD;

  if (P == MASSTOR_SIL) {
    PP = P;
    return PP;
  }
  PS = P;
  PPR = MASSTOR_BETA;
  while (PS != MASSTOR_SIL) {
    MASSTOR_ADV(PS, &PLI, &PS);
    if (PLI != 0) {
      PPR = MASSTOR_COMP(PLI, PPR);
    }
  }
  PP = MASSTOR_INV(PPR);
  if (PP == MASSTOR_SIL || MASSTOR_RED(PP) == MASSTOR_SIL) {
    return PP;
  }
  PPR = DIPC_DIPLPM(PP);
  PP = MASSTOR_INV(PPR);
  XT = MASSTOR_TIME();
  XC = MASSTOR_CELLS();
  if (XH > 0) {
    TR = MASSTOR_TIME();
    CR = MASSTOR_CELLS();
    PPP = PP;
    PP = MASSTOR_BETA;
    PP = DIPGB_DIIFLS(PPP);
    if (TF >= 3) {
      MASBIOS_SWRITE("***irr time=", 12L);
      SACLIST_AWRITE(MASSTOR_TIME() - TR);
      MASBIOS_SWRITE(", cells=", 8L);
      SACLIST_AWRITE(MASSTOR_CELLS() - CR);
      MASBIOS_BLINES(1);
    }
  }
  PPR = DIPC_DIPLPM(PP);
  PP = MASSTOR_INV(PPR);
  DIPRNGB_DILCPL(PP, &D, &B);
  XD = MASSTOR_LENGTH(D);
  YD = XD;
  X3 = 0;
  X4 = 0;
  XS = 0;
  XH = 0;
  for (;;) {
    if (D == MASSTOR_SIL) {
      goto EXIT_3;
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
    if (TF >= 3) {
      SACLIST_OWRITE(EL);
      MASBIOS_BLINES(0);
      MASBIOS_SWRITE("pli=", 4L);
      SACLIST_OWRITE(PLI);
      MASBIOS_BLINES(1);
      MASBIOS_SWRITE("plj=", 4L);
      SACLIST_OWRITE(PLJ);
      MASBIOS_BLINES(1);
    }
    for (;;) {
      X3 = X3 + 1;
      SL = DIPRNGB_DIGBC3(B, PLI, PLJ, EL);
      if (SL == 0) {
        goto EXIT_4;
      }
      X4 = X4 + 1;
      SL = DIPRNGB_DIGBC4(PLI, PLJ, EL);
      if (SL == 0) {
        goto EXIT_4;
      }
      XS = XS + 1;
      S = DIPGB_DIIFSP(PLI, PLJ);
      if (S == 0) {
        goto EXIT_4;
      }
      if (TF >= 3) {
        MASBIOS_SWRITE("S=", 2L);
        SACLIST_OWRITE(S);
        MASBIOS_BLINES(1);
      }
      XH = XH + 1;
      H = DIPGB_DIIFNF(PP, 0, S);
      if (H == 0) {
        goto EXIT_4;
      }
      SL = DIPC_DIPTDG(H);
      if (SL == 0) {
        MASBIOS_SWRITE("total degree = 0", 16L);
        MASBIOS_BLINES(1);
      }
      if (TF >= 2) {
        SACLIST_AWRITE(MASSTOR_TIME() - XT);
        MASBIOS_SWRITE(" ms,  ", 6L);
        SACLIST_AWRITE(MASSTOR_CELLS() - XC);
        MASBIOS_SWRITE(" cells,  ", 9L);
        MASBIOS_BLINES(0);
        SACLIST_AWRITE(X3);
        MASBIOS_SWRITE(" crit3,  ", 9L);
        SACLIST_AWRITE(X4);
        MASBIOS_SWRITE(" crit4,  ", 9L);
        SACLIST_AWRITE(XS);
        MASBIOS_SWRITE(" spoly,  ", 9L);
        SACLIST_AWRITE(XH);
        MASBIOS_SWRITE(" hpoly,  ", 9L);
        MASBIOS_BLINES(0);
        SACLIST_AWRITE(XD);
        MASBIOS_SWRITE(" pairs,  ", 9L);
        SACLIST_AWRITE(YD);
        MASBIOS_SWRITE(" restp,  ", 9L);
        SACRN_RNDWR(SACRN_RNRED(YD, XD), 3);
        MASBIOS_SWRITE(" quot.", 6L);
        MASBIOS_BLINES(1);
        MASBIOS_SWRITE("H=", 2L);
        DIPADOM_DIWRIT(H, DIPC_VALIS);
        MASBIOS_BLINES(1);
      }
      SL = DIPC_DIPTDG(H);
      if (SL == 0) {
        goto EXIT_4;
      }
      D = DIPRNGB_DILUPL(H, PP, D, B);
      J1Y = MASSTOR_LENGTH(PP);
      XDP = J1Y - 1;
      XD = XD + XDP;
      YD = YD + XDP;
      X3 = 0;
      X4 = 0;
      XS = 0;
      XH = 0;
      goto EXIT_4;
    } EXIT_4:;
  } EXIT_3:;
  if (TF >= 1) {
    SACLIST_AWRITE(MASSTOR_TIME() - XT);
    MASBIOS_SWRITE(" ms,  ", 6L);
    SACLIST_AWRITE(MASSTOR_CELLS() - XC);
    MASBIOS_SWRITE(" cells;  ", 9L);
  }
  if (TF >= 2) {
    MASBIOS_BLINES(0);
    SACLIST_AWRITE(X3);
    MASBIOS_SWRITE(" crit3,  ", 9L);
    SACLIST_AWRITE(X4);
    MASBIOS_SWRITE(" crit4,  ", 9L);
    SACLIST_AWRITE(XS);
    MASBIOS_SWRITE(" spoly,  ", 9L);
    SACLIST_AWRITE(XH);
    MASBIOS_SWRITE(" hpoly,  ", 9L);
    MASBIOS_BLINES(0);
    SACLIST_AWRITE(XD);
    MASBIOS_SWRITE(" pairs,  ", 9L);
    SACLIST_AWRITE(YD);
    MASBIOS_SWRITE(" restp,  ", 9L);
    SACRN_RNDWR(SACRN_RNRED(YD, XD), 3);
    MASBIOS_SWRITE(" quot.", 6L);
  }
  MASBIOS_BLINES(1);
  PP = DIPGB_DIIFMI(PP);
  return PP;
}

MASSTOR_LIST DIPGB_DIIFLS
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST CL, EL, FL, IRR, LL, PL, PP, PS, RP, SL;

  RP = SACLIST_CINV(P);
  PP = MASSTOR_INV(RP);
  LL = MASSTOR_LENGTH(P);
  IRR = 0;
  if (LL <= 1) {
    return PP;
  }
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("***nf irr= ", 11L);
  do {
    MASSTOR_ADV(PP, &PL, &PP);
    EL = DIPC_DIPEVL(PL);
    PL = DIPGB_DIIFNF(PP, 0, PL);
    SACLIST_OWRITE(IRR);
    MASBIOS_SWRITE(" ", 1L);
    if (PL == 0) {
      LL = LL - 1;
      if (LL <= 1) {
        return PP;
      }
    } else {
      FL = DIPC_DIPEVL(PL);
      SL = SACLIST_EQUAL(EL, FL);
      if (SL == 1) {
        IRR = IRR + 1;
      } else {
        IRR = 0;
      }
      PS = MASSTOR_LIST1(PL);
      MASSTOR_SRED(RP, PS);
      RP = PS;
    }
  } while (!(IRR == LL));
  MASBIOS_BLINES(1);
  SACLIST_AWRITE(LL);
  MASBIOS_SWRITE(" irreducible polynomials", 24L);
  MASBIOS_BLINES(1);
  return PP;
}

MASSTOR_LIST DIPGB_DIIFMI
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST AL, EI, EJ, EL, PB, PI, PIP, PJ, PL, PP, PS, QP, TL;

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
      PL = DIPC_DIPFMO(AL, EL);
      PI = DIPGB_DIIFNF(QP, PL, PIP);
    }
    PP = MASSTOR_COMP(PI, PP);
  } while (!(PS == MASSTOR_SIL));
  PP = MASSTOR_INV(PP);
  PP = DIPC_DIPLPM(PP);
  return PP;
}

MASSTOR_LIST DIPGB_DIIFNF
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST RPP, MASSTOR_LIST S)
# else
(P, RPP, S)
MASSTOR_LIST P, RPP, S;
# endif
{
  MASSTOR_LIST AL, AP, APP, BL, CL, FL, PP, Q, QA, QE, QP, R, RP, RS, SL, SP, TA, TE;

  if (S == 0) {
    R = RPP;
    return R;
  }
  if (P == MASSTOR_SIL) {
    if (RPP == 0) {
      R = S;
    } else {
      R = SACLIST_CCONC(RPP, S);
    }
    return R;
  }
  SP = S;
  R = RPP;
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
      RP = DIPC_DIPFMO(TA, TE);
      if (R == 0) {
        R = RP;
      } else {
        RS = SACLIST_LAST(R);
        MASSTOR_SRED(RS, RP);
      }
    } else {
      if (QP != MASSTOR_SIL) {
        FL = DIPC_EVDIF(TE, QE);
        MASADOM_ADGCDC(TA, QA, &CL, &AL, &BL);
        AP = DIPC_DIPFMO(AL, FL);
        APP = DIPADOM_DIPROD(QP, AP);
        SP = DIPADOM_DIPBCP(SP, BL);
        R = DIPADOM_DIPBCP(R, BL);
        SP = DIPADOM_DIPDIF(SP, APP);
      }
    }
  } while (!(SP == 0));
  return R;
}

MASSTOR_LIST DIPGB_DIIFSP
# ifdef __STDC__
(MASSTOR_LIST C_133_A, MASSTOR_LIST B)
# else
(C_133_A, B)
MASSTOR_LIST C_133_A, B;
# endif
{
  MASSTOR_LIST AL, AP, APP, BL, BP, BPP, C, CL, EL, EL1, FL, FL1, GL;

  C = 0;
  if (C_133_A == 0 || B == 0) {
    return C;
  }
  DIPC_DIPMAD(C_133_A, &AL, &EL, &AP);
  DIPC_DIPMAD(B, &BL, &FL, &BP);
  if (AP == MASSTOR_SIL && BP == MASSTOR_SIL) {
    return C;
  }
  GL = DIPC_EVLCM(EL, FL);
  MASADOM_ADGCDC(AL, BL, &CL, &AL, &BL);
  if (AP == MASSTOR_SIL) {
    FL1 = DIPC_EVDIF(GL, FL);
    AL = MASADOM_ADNEG(AL);
    BPP = DIPC_DIPFMO(AL, FL1);
    C = DIPADOM_DIPROD(BP, BPP);
    return C;
  }
  if (BP == MASSTOR_SIL) {
    EL1 = DIPC_EVDIF(GL, EL);
    APP = DIPC_DIPFMO(BL, EL1);
    C = DIPADOM_DIPROD(AP, APP);
    return C;
  }
  EL1 = DIPC_EVDIF(GL, EL);
  FL1 = DIPC_EVDIF(GL, FL);
  APP = DIPC_DIPFMO(BL, EL1);
  BPP = DIPC_DIPFMO(AL, FL1);
  APP = DIPADOM_DIPROD(AP, APP);
  BPP = DIPADOM_DIPROD(BP, BPP);
  C = DIPADOM_DIPDIF(APP, BPP);
  return C;
}

void BEGIN_DIPGB()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_MASBIOS();
    BEGIN_SACI();
    BEGIN_SACRN();
    BEGIN_DIPC();
    BEGIN_DIPRNGB();
    BEGIN_DIPADOM();
    BEGIN_MASADOM();

  }
}
