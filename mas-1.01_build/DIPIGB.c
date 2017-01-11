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

#ifndef DEFINITION_DIPI
#include "DIPI.h"
#endif

#ifndef DEFINITION_DIPRNGB
#include "DIPRNGB.h"
#endif

#ifndef DEFINITION_DIPIGB
#include "DIPIGB.h"
#endif

CHAR DIPIGB_rcsid [] = "$Id: DIPIGB.md,v 1.2 1992/02/12 17:34:20 pesch Exp $";
CHAR DIPIGB_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: DIPIGB.mi,v 1.3 1992/10/15 16:29:37 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST DIPIGB_DIIGBA
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST P, MASSTOR_LIST TF)
# else
(PL, P, TF)
MASSTOR_LIST PL, P, TF;
# endif
{
  MASSTOR_LIST B, C, CL, CPI, CPJ, CPP, D, DL, EL, ELI, ELJ, H, J1Y, K, PLI, PLJ, PLS, PP, PSS, Q, QL, QLS, QP, RL, S, SL, T, X3, X4, XC, XD, XH, XS, XT, YD;

  T = MASSTOR_TIME();
  XH = 0;
  DIPI_DIIPCP(PL, &CL, &PLS);
  if (P == MASSTOR_SIL) {
    PP = MASSTOR_LIST1(PLS);
    return PP;
  }
  PLS = DIPIGB_DIIPNF(P, 0, PLS);
  J1Y = SACLIST_CINV(P);
  PP = MASSTOR_INV(J1Y);
  if (PLS == 0) {
    return PP;
  }
  DIPI_DIIPCP(PLS, &CL, &PLS);
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
      S = DIPIGB_DIIPSP(PLI, PLJ);
      if (S == 0) {
        goto EXIT_2;
      }
      XH = XH + 1;
      H = DIPIGB_DIIPNF(PP, 0, S);
      if (H == 0) {
        goto EXIT_2;
      }
      DIPI_DIIPCP(H, &CL, &H);
      if (TF >= 1) {
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
        SACLIST_OWRITE(H);
        MASBIOS_BLINES(1);
      }
      D = DIPRNGB_DILUPL(H, PP, D, B);
      YD = MASSTOR_LENGTH(D);
      XD = YD;
      X4 = 0;
      X3 = 0;
      XS = 0;
      XH = 0;
      XT = MASSTOR_TIME();
      XC = MASSTOR_CELLS();
      goto EXIT_2;
    } EXIT_2:;
  } EXIT_1:;
  if (TF >= 1) {
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
  }
  PP = DIPIGB_DIIGMI(PP);
  return PP;
}

MASSTOR_LIST DIPIGB_DIIGMI
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST AL, CL, EI, EJ, EL, PB, PI, PIP, PJ, PL, PP, PS, QP, TL;

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
      PI = DIPIGB_DIIPNF(QP, PL, PIP);
      DIPI_DIIPCP(PI, &CL, &PI);
    }
    PP = MASSTOR_COMP(PI, PP);
  } while (!(PS == MASSTOR_SIL));
  PP = MASSTOR_INV(PP);
  PP = DIPC_DIPLPM(PP);
  return PP;
}

MASSTOR_LIST DIPIGB_DIILIS
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST CL, EL, FL, IRR, LL, PL, PP, PS, RP, SL;

  PP = P;
  PS = MASSTOR_BETA;
  while (PP != MASSTOR_SIL) {
    MASSTOR_ADV(PP, &PL, &PP);
    DIPI_DIIPCP(PL, &CL, &PL);
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
  for (;;) {
    MASSTOR_ADV(PP, &PL, &PP);
    EL = DIPC_DIPEVL(PL);
    PL = DIPIGB_DIIPNF(PP, 0, PL);
    SACLIST_OWRITE(IRR);
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
        DIPI_DIIPCP(PL, &CL, &PL);
      }
      PS = MASSTOR_LIST1(PL);
      MASSTOR_SRED(RP, PS);
      RP = PS;
    }
    if (IRR == LL) {
      goto EXIT_3;
    }
  } EXIT_3:;
  MASBIOS_BLINES(1);
  SACLIST_AWRITE(LL);
  MASBIOS_SWRITE("  irreducible polynomials.", 26L);
  MASBIOS_BLINES(1);
  return PP;
}

MASSTOR_LIST DIPIGB_DIIPGB
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST TF)
# else
(P, TF)
MASSTOR_LIST P, TF;
# endif
{
  MASSTOR_LIST B, C, CL, CPI, CPJ, CPP, CR, D, DL, EL, ELI, ELJ, H, IL, J1Y, PL, PLI, PLJ, PP, PPR, PS, Q, QP, RL, S, SL, T, TR, X3, X4, XC, XD, XH, XS, XT, YD, ZD;

  if (P == MASSTOR_SIL) {
    PP = P;
    return PP;
  }
  PS = P;
  PPR = MASSTOR_BETA;
  while (PS != MASSTOR_SIL) {
    MASSTOR_ADV(PS, &PLI, &PS);
    if (PLI != 0) {
      DIPI_DIIPCP(PLI, &CL, &PL);
      PPR = MASSTOR_COMP(PL, PPR);
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
  X3 = 0;
  X4 = 0;
  XS = 0;
  XH = 0;
  if (XH > 0) {
    TR = MASSTOR_TIME();
    CR = MASSTOR_CELLS();
    PP = DIPIGB_DIILIS(PP);
    MASBIOS_SWRITE("***irr time=", 12L);
    SACLIST_AWRITE(MASSTOR_TIME() - TR);
    MASBIOS_SWRITE(", cells=", 8L);
    SACLIST_AWRITE(MASSTOR_CELLS() - CR);
    MASBIOS_BLINES(1);
  }
  PPR = DIPC_DIPLPM(PP);
  PP = MASSTOR_INV(PPR);
  DIPRNGB_DILCPL(PP, &D, &B);
  XD = MASSTOR_LENGTH(D);
  YD = XD;
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
        goto EXIT_5;
      }
      X4 = X4 + 1;
      SL = DIPRNGB_DIGBC4(PLI, PLJ, EL);
      if (SL == 0) {
        goto EXIT_5;
      }
      XS = XS + 1;
      S = DIPIGB_DIIPSP(PLI, PLJ);
      if (S == 0) {
        goto EXIT_5;
      }
      DIPI_DIIPCP(S, &CL, &S);
      XH = XH + 1;
      H = DIPIGB_DIIPNF(PP, 0, S);
      if (H == 0) {
        goto EXIT_5;
      }
      DIPI_DIIPCP(H, &CL, &H);
      SL = DIPI_DIIPON(H);
      if (SL == 1) {
        PP = MASSTOR_LIST1(H);
        return PP;
      }
      if (TF >= 1) {
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
        DIPI_DIIPWR(H, DIPC_VALIS);
        MASBIOS_BLINES(1);
      }
      D = DIPRNGB_DILUPL(H, PP, D, B);
      XD = MASSTOR_LENGTH(D);
      YD = XD;
      X3 = 0;
      X4 = 0;
      XS = 0;
      XH = 0;
      goto EXIT_5;
    } EXIT_5:;
  } EXIT_4:;
  if (TF >= 1) {
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
  }
  PP = DIPIGB_DIIGMI(PP);
  return PP;
}

MASSTOR_LIST DIPIGB_DIIPNF
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
        SACI_IGCDCF(TA, QA, &CL, &AL, &BL);
        AP = DIPC_DIPFMO(AL, FL);
        APP = DIPI_DIIPPR(QP, AP);
        SP = DIPI_DIIPIP(SP, BL);
        R = DIPI_DIIPIP(R, BL);
        SP = DIPI_DIIPDF(SP, APP);
      }
    }
  } while (!(SP == 0));
  return R;
}

MASSTOR_LIST DIPIGB_DIIPSP
# ifdef __STDC__
(MASSTOR_LIST C_120_A, MASSTOR_LIST B)
# else
(C_120_A, B)
MASSTOR_LIST C_120_A, B;
# endif
{
  MASSTOR_LIST AL, AP, APP, BL, BP, BPP, C, CL, EL, EL1, FL, FL1, GL;

  C = 0;
  if (C_120_A == 0 || B == 0) {
    return C;
  }
  DIPC_DIPMAD(C_120_A, &AL, &EL, &AP);
  DIPC_DIPMAD(B, &BL, &FL, &BP);
  if (AP == MASSTOR_SIL && BP == MASSTOR_SIL) {
    return C;
  }
  GL = DIPC_EVLCM(EL, FL);
  SACI_IGCDCF(AL, BL, &CL, &AL, &BL);
  if (AP == MASSTOR_SIL) {
    FL1 = DIPC_EVDIF(GL, FL);
    AL = SACI_INEG(AL);
    BPP = DIPC_DIPFMO(AL, FL1);
    C = DIPI_DIIPPR(BP, BPP);
    return C;
  }
  if (BP == MASSTOR_SIL) {
    EL1 = DIPC_EVDIF(GL, EL);
    APP = DIPC_DIPFMO(BL, EL1);
    C = DIPI_DIIPPR(AP, APP);
    return C;
  }
  EL1 = DIPC_EVDIF(GL, EL);
  FL1 = DIPC_EVDIF(GL, FL);
  APP = DIPC_DIPFMO(BL, EL1);
  BPP = DIPC_DIPFMO(AL, FL1);
  APP = DIPI_DIIPPR(AP, APP);
  BPP = DIPI_DIIPPR(BP, BPP);
  C = DIPI_DIIPDF(APP, BPP);
  return C;
}

void BEGIN_DIPIGB()
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
    BEGIN_DIPI();
    BEGIN_DIPRNGB();

  }
}
