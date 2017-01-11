#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASERR
#include "MASERR.h"
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

#ifndef DEFINITION_MASNC
#include "MASNC.h"
#endif

#ifndef DEFINITION_MASNCGB
#include "MASNCGB.h"
#endif

CHAR MASNCGB_rcsid [] = "$Id: MASNCGB.md,v 1.2 1992/02/12 17:33:32 pesch Exp $";
CHAR MASNCGB_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASNCGB.mi,v 1.3 1992/10/15 16:29:48 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST MASNCGB_DINLNF
# ifdef __STDC__
(MASSTOR_LIST T, MASSTOR_LIST P, MASSTOR_LIST S)
# else
(T, P, S)
MASSTOR_LIST T, P, S;
# endif
{
  MASSTOR_LIST AP, APP, BL, FL, OL, PP, Q, QA, QE, QP, R, SL, SP, SPP, TA, TE;

  if (S == 0 || P == MASSTOR_SIL) {
    R = S;
    return R;
  }
  R = MASSTOR_BETA;
  SP = S;
  OL = SACRN_RNINT(1);
  do {
    DIPC_DIPMAD(SP, &TA, &TE, &SPP);
    PP = P;
    do {
      MASSTOR_ADV(PP, &Q, &PP);
      DIPC_DIPMAD(Q, &QA, &QE, &QP);
      SL = DIPC_EVMT(TE, QE);
    } while (!(PP == MASSTOR_SIL || SL == 1));
    if (SL == 0) {
      R = DIPC_DIPMCP(TE, TA, R);
      if (SPP == MASSTOR_SIL) {
        SP = 0;
      } else {
        SP = SPP;
      }
    } else {
      FL = DIPC_EVDIF(TE, QE);
      AP = DIPC_DIPFMO(OL, FL);
      APP = MASNC_DINPPR(T, AP, Q);
      BL = DIPC_DIPLBC(APP);
      BL = SACRN_RNQ(TA, BL);
      APP = DIPRN_DIRPRP(APP, BL);
      SP = DIPRN_DIRPDF(SP, APP);
    }
  } while (!(SP == 0));
  if (R == MASSTOR_SIL) {
    R = 0;
  } else {
    R = MASSTOR_INV(R);
  }
  return R;
}

MASSTOR_LIST MASNCGB_DINLIS
# ifdef __STDC__
(MASSTOR_LIST T, MASSTOR_LIST P)
# else
(T, P)
MASSTOR_LIST T, P;
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
    PL = MASNCGB_DINLNF(T, PP, PL);
    SACLIST_AWRITE(IRR);
    MASBIOS_SWRITE(", ", 2L);
    if (PL == 0) {
      LL = LL - 1;
      if (LL <= 1) {
        goto EXIT_1;
      }
    } else {
      FL = DIPC_DIPEVL(PL);
      SL = DIPC_EVSIGN(FL);
      if (SL == 0) {
        PP = MASSTOR_LIST1(PL);
        goto EXIT_1;
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
      goto EXIT_1;
    }
  } EXIT_1:;
  MASBIOS_BLINES(0);
  return PP;
}

MASSTOR_LIST MASNCGB_DINLSP
# ifdef __STDC__
(MASSTOR_LIST T, MASSTOR_LIST C_86_A, MASSTOR_LIST B)
# else
(T, C_86_A, B)
MASSTOR_LIST T, C_86_A, B;
# endif
{
  MASSTOR_LIST AL, AP, APP, BL, BP, BPP, C, EL, EL1, FL, FL1, GL, OL;

  C = 0;
  if (C_86_A == 0 || B == 0) {
    return C;
  }
  EL = DIPC_DIPEVL(C_86_A);
  FL = DIPC_DIPEVL(B);
  OL = SACRN_RNINT(1);
  GL = DIPC_EVLCM(EL, FL);
  EL1 = DIPC_EVDIF(GL, EL);
  FL1 = DIPC_EVDIF(GL, FL);
  APP = DIPC_DIPFMO(OL, EL1);
  BPP = DIPC_DIPFMO(OL, FL1);
  APP = MASNC_DINPPR(T, APP, C_86_A);
  BPP = MASNC_DINPPR(T, BPP, B);
  AL = DIPC_DIPLBC(APP);
  BL = DIPC_DIPLBC(BPP);
  APP = DIPRN_DIRPRP(APP, BL);
  BPP = DIPRN_DIRPRP(BPP, AL);
  C = DIPRN_DIRPDF(APP, BPP);
  return C;
}

MASSTOR_LIST MASNCGB_DINLGB
# ifdef __STDC__
(MASSTOR_LIST T, MASSTOR_LIST P, MASSTOR_LIST TF)
# else
(T, P, TF)
MASSTOR_LIST T, P, TF;
# endif
{
  MASSTOR_LIST B, C, CPI, CPJ, CPP, D, DL, EL, ELI, ELJ, H, IL, J1Y, K, PLI, PLIP, PLJ, PP, PPP, PPR, PS, Q, QP, RL, S, SL, SL3, TL, TR, X3, X4, XC, XD, XH, XS, XT, YD, ZD;

  TL = MASSTOR_TIME();
  XH = 0;
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
  if (TF < 0) {
    TF = -TF;
    TR = MASSTOR_TIME();
    PP = MASNCGB_DINLIS(T, PP);
    MASBIOS_SWRITE("***IRR TIME=", 12L);
    SACLIST_AWRITE(MASSTOR_TIME() - TR);
    MASBIOS_BLINES(0);
  }
  PPR = DIPC_DIPLPM(PP);
  PP = MASSTOR_INV(PPR);
  DIPRNGB_DILCPL(PP, &D, &B);
  for (;;) {
    if (D == MASSTOR_SIL) {
      goto EXIT_2;
    }
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
      MASBIOS_SWRITE("EL=", 3L);
      SACLIST_OWRITE(EL);
      MASBIOS_BLINES(0);
    }
    for (;;) {
      SL3 = DIPRNGB_DIGBC3(B, PLI, PLJ, EL);
      if (SL3 == 0) {
        goto EXIT_3;
      }
      S = MASNCGB_DINLSP(T, PLI, PLJ);
      if (S == 0) {
        goto EXIT_3;
      }
      XH = XH + 1;
      if (TF >= 2) {
        SACLIST_AWRITE(MASSTOR_TIME() - TL);
        MASBIOS_SWRITE(" S, ", 4L);
        MASBIOS_SWRITE("S=", 2L);
        DIPRN_DIRPWR(S, DIPC_VALIS, -1);
        MASBIOS_BLINES(1);
      }
      H = MASNCGB_DINLNF(T, PP, S);
      if (H == 0) {
        goto EXIT_3;
      }
      H = DIPRN_DIRPMC(H);
      SL = DIPRN_DIRPON(H);
      if (SL == 1) {
        PP = MASSTOR_LIST1(H);
        return PP;
      }
      if (TF >= 1) {
        SACLIST_AWRITE(MASSTOR_TIME() - TL);
        MASBIOS_SWRITE(" S, ", 4L);
        SACLIST_AWRITE(XH);
        MASBIOS_SWRITE(" H-POLYNOMIALS, ", 16L);
        SACLIST_AWRITE(MASSTOR_LENGTH(D));
        MASBIOS_SWRITE(" PAIRS LEFT.", 12L);
        MASBIOS_BLINES(0);
        MASBIOS_SWRITE("H=", 2L);
        DIPRN_DIRPWR(H, DIPC_VALIS, -1);
        MASBIOS_BLINES(1);
      }
      D = DIPRNGB_DILUPL(H, PP, D, B);
      goto EXIT_3;
    } EXIT_3:;
  } EXIT_2:;
  if (TF >= 1) {
    SACLIST_AWRITE(MASSTOR_TIME() - TL);
    MASBIOS_SWRITE(" S, ", 4L);
    SACLIST_AWRITE(XH);
    MASBIOS_SWRITE(" H-POLYNOMIALS.", 15L);
    MASBIOS_BLINES(0);
  }
  PP = MASNCGB_DINLGM(T, PP);
  return PP;
}

MASSTOR_LIST MASNCGB_DINLGM
# ifdef __STDC__
(MASSTOR_LIST T, MASSTOR_LIST P)
# else
(T, P)
MASSTOR_LIST T, P;
# endif
{
  MASSTOR_LIST AL, EI, EJ, EL, PB, PI, PJ, PP, PS, QP, TL;

  PP = P;
  if (P == MASSTOR_SIL || MASSTOR_RED(P) == MASSTOR_SIL) {
    return PP;
  }
  MASBIOS_SWRITE("LEN=", 4L);
  SACLIST_OWRITE(MASSTOR_LENGTH(PP));
  MASBIOS_BLINES(0);
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
  PP = MASNCGB_DINLIS(T, PP);
  PP = DIPC_DIPLPM(PP);
  return PP;
}

MASSTOR_LIST MASNCGB_DIN1GB
# ifdef __STDC__
(MASSTOR_LIST T, MASSTOR_LIST P, MASSTOR_LIST TF)
# else
(T, P, TF)
MASSTOR_LIST T, P, TF;
# endif
{
  MASSTOR_LIST EL, F, G, IL, J1Y, N, O, PL, PP, QL, RL, TL, V, X, XL, XP, XS;

  PP = P;
  if (P == MASSTOR_SIL) {
    return PP;
  }
  J1Y = MASSTOR_FIRST(P);
  RL = DIPC_DIPNOV(J1Y);
  if (RL == 0) {
    return PP;
  }
  N = MASNC_EVZERO(RL);
  O = SACRN_RNINT(1);
  X = MASSTOR_BETA;
  {
    LONGINT B_1 = 1, B_2 = RL;

    if (B_1 <= B_2)
      for (IL = B_1;; IL += 1) {
        DIPC_EVSU(N, IL, 1, &EL, &XL);
        XP = DIPC_DIPFMO(O, EL);
        X = MASSTOR_COMP(XP, X);
        if (IL >= B_2) break;
      }
  }
  V = DIPC_VALIS;
  do {
    G = MASNCGB_DINLGB(T, PP, TF);
    MASBIOS_SWRITE("Left Groebner base ", 19L);
    DIPRN_DIRLWR(G, V, -1);
    MASBIOS_BLINES(1);
    PP = G;
    F = G;
    do {
      MASSTOR_ADV(F, &PL, &F);
      XS = X;
      do {
        MASSTOR_ADV(XS, &XP, &XS);
        QL = MASNC_DINPPR(T, PL, XP);
        QL = MASNCGB_DINLNF(T, PP, QL);
        if (QL != 0) {
          MASBIOS_SWRITE("QL=", 3L);
          DIPRN_DIRPWR(QL, V, -1);
          MASBIOS_BLINES(1);
          PP = MASSTOR_COMP(QL, PP);
        }
      } while (!(XS == MASSTOR_SIL));
    } while (!(F == MASSTOR_SIL));
  } while (!(G == PP));
  return PP;
}

MASSTOR_LIST MASNCGB_DINCGB
# ifdef __STDC__
(MASSTOR_LIST T, MASSTOR_LIST P, MASSTOR_LIST TF)
# else
(T, P, TF)
MASSTOR_LIST T, P, TF;
# endif
{
  MASSTOR_LIST B, C, CPI, CPJ, CPP, CR, D, DL, EL, ELI, ELJ, F, H, IL, J1Y, K, N, O, PL, PLI, PLIP, PLJ, PP, PPP, PPR, PS, Q, QL, QP, RL, S, SL, TL, TR, V, X, X3, X4, XC, XD, XH, XL, XP, XS, XT, YD, ZD;

  TL = MASSTOR_TIME();
  XH = 0;
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
  if (PP == MASSTOR_SIL) {
    return PP;
  }
  J1Y = MASSTOR_FIRST(PP);
  RL = DIPC_DIPNOV(J1Y);
  if (RL == 0) {
    return PP;
  }
  N = MASNC_EVZERO(RL);
  O = SACRN_RNINT(1);
  X = MASSTOR_BETA;
  {
    LONGINT B_3 = 1, B_4 = RL;

    if (B_3 <= B_4)
      for (IL = B_3;; IL += 1) {
        DIPC_EVSU(N, IL, 1, &EL, &XL);
        XP = DIPC_DIPFMO(O, EL);
        X = MASSTOR_COMP(XP, X);
        if (IL >= B_4) break;
      }
  }
  V = DIPC_VALIS;
  F = PP;
  do {
    MASSTOR_ADV(F, &PL, &F);
    XS = X;
    do {
      MASSTOR_ADV(XS, &XP, &XS);
      QL = MASNC_DINPPR(T, PL, XP);
      QL = MASNCGB_DINLNF(T, PP, QL);
      QL = DIPRN_DIRPMC(QL);
      SL = DIPRN_DIRPON(QL);
      if (SL == 1) {
        PP = MASSTOR_LIST1(QL);
        return PP;
      }
      if (QL != 0) {
        MASBIOS_SWRITE("QL=", 3L);
        DIPRN_DIRPWR(QL, V, -1);
        MASBIOS_BLINES(1);
        PP = MASSTOR_COMP(QL, PP);
      }
    } while (!(XS == MASSTOR_SIL));
  } while (!(F == MASSTOR_SIL));
  if (TF < 0) {
    TF = -TF;
    TR = MASSTOR_TIME();
    PP = MASNCGB_DINLIS(T, PP);
    MASBIOS_SWRITE("***IRR TIME=", 12L);
    SACLIST_AWRITE(MASSTOR_TIME() - TR);
    MASBIOS_BLINES(0);
  }
  PPR = DIPC_DIPLPM(PP);
  PP = MASSTOR_INV(PPR);
  DIPRNGB_DILCPL(PP, &D, &B);
  for (;;) {
    if (D == MASSTOR_SIL) {
      goto EXIT_4;
    }
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
      MASBIOS_SWRITE("EL=", 3L);
      SACLIST_OWRITE(EL);
      MASBIOS_BLINES(0);
    }
    for (;;) {
      SL = DIPRNGB_DIGBC3(B, PLI, PLJ, EL);
      if (SL == 0) {
        goto EXIT_5;
      }
      S = MASNCGB_DINLSP(T, PLI, PLJ);
      if (S == 0) {
        goto EXIT_5;
      }
      XH = XH + 1;
      if (TF >= 2) {
        SACLIST_AWRITE(MASSTOR_TIME() - TL);
        MASBIOS_SWRITE(" S, ", 4L);
        MASBIOS_BLINES(0);
        MASBIOS_SWRITE("S=", 2L);
        DIPRN_DIRPWR(S, V, -1);
        MASBIOS_BLINES(1);
      }
      H = MASNCGB_DINLNF(T, PP, S);
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
        SACLIST_AWRITE(MASSTOR_TIME() - TL);
        MASBIOS_SWRITE(" S, ", 4L);
        SACLIST_AWRITE(XH);
        MASBIOS_SWRITE(" H-POLYNOMIALS, ", 16L);
        SACLIST_AWRITE(MASSTOR_LENGTH(D));
        MASBIOS_SWRITE(" PAIRS LEFT.", 12L);
        MASBIOS_BLINES(0);
        MASBIOS_SWRITE("H=", 2L);
        DIPRN_DIRPWR(H, V, -1);
        MASBIOS_BLINES(1);
      }
      D = DIPRNGB_DILUPL(H, PP, D, B);
      XS = X;
      do {
        MASSTOR_ADV(XS, &XP, &XS);
        QL = MASNC_DINPPR(T, H, XP);
        QL = MASNCGB_DINLNF(T, PP, QL);
        QL = DIPRN_DIRPMC(QL);
        SL = DIPRN_DIRPON(QL);
        if (SL == 1) {
          PP = MASSTOR_LIST1(QL);
          return PP;
        }
        if (QL != 0) {
          MASBIOS_SWRITE("QL=", 3L);
          DIPRN_DIRPWR(QL, V, -1);
          MASBIOS_BLINES(1);
          D = DIPRNGB_DILUPL(QL, PP, D, B);
        }
      } while (!(XS == MASSTOR_SIL));
      goto EXIT_5;
    } EXIT_5:;
  } EXIT_4:;
  if (TF >= 1) {
    SACLIST_AWRITE(MASSTOR_TIME() - TL);
    MASBIOS_SWRITE(" S, ", 4L);
    SACLIST_AWRITE(XH);
    MASBIOS_SWRITE(" H-POLYNOMIALS.", 15L);
    MASBIOS_BLINES(0);
  }
  PP = MASNCGB_DINLGM(T, PP);
  return PP;
}

void BEGIN_MASNCGB()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_MASERR();
    BEGIN_SACLIST();
    BEGIN_MASBIOS();
    BEGIN_SACRN();
    BEGIN_DIPC();
    BEGIN_DIPRN();
    BEGIN_DIPRNGB();
    BEGIN_MASNC();

  }
}
