#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_DIPRN
#include "DIPRN.h"
#endif

#ifndef DEFINITION_SACRN
#include "SACRN.h"
#endif

#ifndef DEFINITION_DIPRNGB
#include "DIPRNGB.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_SACI
#include "SACI.h"
#endif

#ifndef DEFINITION_MASNC
#include "MASNC.h"
#endif

#ifndef DEFINITION_DINNGB
#include "DINNGB.h"
#endif

CHAR DINNGB_rcsid [] = "$Id: DINNGB.md,v 1.1 1995/12/16 13:23:13 kredel Exp $";
CHAR DINNGB_copyright [] = "Copyright (c) 1993 Universitaet Passau";

static CHAR rcsidi [] = "$Id: DINNGB.mi,v 1.1 1995/12/16 13:23:14 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1993 Universitaet Passau";


MASSTOR_LIST DINNGB_DINNCP
# ifdef __STDC__
(MASSTOR_LIST EL, MASSTOR_LIST C_140_A, MASSTOR_LIST B)
# else
(EL, C_140_A, B)
MASSTOR_LIST EL, C_140_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, CP, CS, OL, UL, VL;

  C = 0;
  if (C_140_A == 0) {
    return C;
  }
  if (B == 0) {
    return C;
  }
  if (DIPRN_DIRPON(C_140_A) == 1) {
    C = B;
    return C;
  }
  if (DIPRN_DIRPON(B) == 1) {
    C = C_140_A;
    return C;
  }
  OL = SACRN_RNINT(1);
  AP = C_140_A;
  do {
    DIPC_DIPMAD(AP, &AL, &UL, &AP);
    BP = B;
    do {
      DIPC_DIPMAD(BP, &BL, &VL, &BP);
      CP = DINNGB_EVNNCP(EL, UL, VL);
      CS = DIPC_DIPFMO(OL, CP);
      CL = SACRN_RNPROD(AL, BL);
      CS = DIPRN_DIRPRP(CS, CL);
      C = DIPRN_DIRPSM(C, CS);
    } while (!(BP == MASSTOR_SIL));
  } while (!(AP == MASSTOR_SIL));
  return C;
}

MASSTOR_LIST DINNGB_EVNNCP
# ifdef __STDC__
(MASSTOR_LIST EL, MASSTOR_LIST S, MASSTOR_LIST T)
# else
(EL, S, T)
MASSTOR_LIST EL, S, T;
# endif
{
  MASSTOR_LIST C, M1, ML, MP, N, NL, NP, QL, QP, S1, S2, VL, T1, TP, TS, TT;

  N = MASSTOR_LENGTH(S);
  VL = MASNC_EVZERO(N);
  TS = DIPC_EVILCP(S, VL);
  TT = DIPC_EVILCP(T, VL);
  DIPC_EVSU(S, 1, 0, &S1, &NL);
  DIPC_EVSU(S, 2, 0, &S2, &ML);
  DIPC_EVSU(T, 2, 0, &T1, &MP);
  C = MASSTOR_SIL;
  if (TS == 0) {
    C = T;
    return C;
  }
  if (TT == 0) {
    C = S;
    return C;
  }
  if (NL == 0) {
    C = DIPC_EVSUM(S, T);
    return C;
  }
  if (NL >= 1 && MP == 0) {
    C = DIPC_EVSUM(S, T);
    return C;
  }
  if (NL >= 1 && MP > 0) {
    QL = DINNGB_IPOWER(EL, NL);
    QP = MP * QL;
    DIPC_EVSU(T1, 2, QP, &TP, &M1);
    C = DIPC_EVSUM(S, TP);
  }
  return C;
}

MASSTOR_LIST DINNGB_EVNRDT
# ifdef __STDC__
(MASSTOR_LIST EL, MASSTOR_LIST S, MASSTOR_LIST T)
# else
(EL, S, T)
MASSTOR_LIST EL, S, T;
# endif
{
  MASSTOR_LIST C, CL, KL, ML, NL, QL, RL;

  DIPC_EVSU(S, 1, 0, &S, &NL);
  DIPC_EVSU(S, 2, 0, &S, &ML);
  DIPC_EVSU(T, 1, 0, &T, &RL);
  DIPC_EVSU(T, 2, 0, &T, &QL);
  if (NL <= RL) {
    CL = RL - NL;
    KL = DINNGB_IPOWER(EL, CL);
    KL = ML * KL;
    if (KL <= QL) {
      C = 1;
    }
  } else {
    C = 0;
  }
  return C;
}

MASSTOR_LIST DINNGB_EVNCRD
# ifdef __STDC__
(MASSTOR_LIST EL, MASSTOR_LIST S, MASSTOR_LIST T)
# else
(EL, S, T)
MASSTOR_LIST EL, S, T;
# endif
{
  MASSTOR_LIST C, CL, HL, KL, ML, NL, QL, RL, S1, S2, SP, T1, T2;

  DIPC_EVSU(S, 1, 0, &S1, &NL);
  DIPC_EVSU(S, 2, 0, &S2, &ML);
  DIPC_EVSU(T, 1, 0, &T1, &RL);
  DIPC_EVSU(T, 2, 0, &T2, &QL);
  if (NL <= RL) {
    CL = RL - NL;
    KL = DINNGB_IPOWER(EL, CL);
    KL = ML * KL;
    if (KL <= QL) {
      DIPC_EVSU(S2, 2, KL, &SP, &RL);
      C = DIPC_EVDIF(T, SP);
    }
  }
  return C;
}

MASSTOR_LIST DINNGB_EVNLDT
# ifdef __STDC__
(MASSTOR_LIST EL, MASSTOR_LIST S, MASSTOR_LIST T)
# else
(EL, S, T)
MASSTOR_LIST EL, S, T;
# endif
{
  MASSTOR_LIST C, FL, KL, ML, NL, QL, RL;

  DIPC_EVSU(S, 1, 0, &S, &NL);
  DIPC_EVSU(S, 2, 0, &S, &ML);
  DIPC_EVSU(T, 1, 0, &T, &RL);
  DIPC_EVSU(T, 2, 0, &T, &QL);
  if (NL <= RL && ML <= QL) {
    FL = QL - ML;
    KL = DINNGB_IPOWER(EL, NL);
    if (SACI_IREM(FL, KL) == 0) {
      C = 1;
    }
  } else {
    C = 0;
  }
  return C;
}

MASSTOR_LIST DINNGB_EVNCLD
# ifdef __STDC__
(MASSTOR_LIST EL, MASSTOR_LIST S, MASSTOR_LIST T)
# else
(EL, S, T)
MASSTOR_LIST EL, S, T;
# endif
{
  MASSTOR_LIST C, CL, CS, FL, KL, ML, NL, QL, RL, S1, S2, T1, T2;

  DIPC_EVSU(S, 1, 0, &S1, &NL);
  DIPC_EVSU(S, 2, 0, &S2, &ML);
  DIPC_EVSU(T, 1, 0, &T1, &RL);
  DIPC_EVSU(T, 2, 0, &T2, &QL);
  if (NL <= RL && ML <= QL) {
    FL = QL - ML;
    KL = DINNGB_IPOWER(EL, NL);
    if (SACI_IREM(FL, KL) == 0) {
      C = MASSTOR_SIL;
      CL = RL - NL;
      CS = SACI_IQ(FL, KL);
      C = MASSTOR_COMP(CS, C);
      C = MASSTOR_COMP(CL, C);
    }
  }
  return C;
}

MASSTOR_LIST DINNGB_EVLLCM
# ifdef __STDC__
(MASSTOR_LIST EL, MASSTOR_LIST S, MASSTOR_LIST T)
# else
(EL, S, T)
MASSTOR_LIST EL, S, T;
# endif
{
  MASSTOR_LIST C, FL, GL, GP, HL, M1, M2, ML, MP, N1, N2, NL, NP, S1, S2, SP, T1, T2;

  DIPC_EVSU(S, 1, 0, &S1, &N1);
  DIPC_EVSU(S, 2, 0, &S2, &M1);
  DIPC_EVSU(T, 1, 0, &T1, &N2);
  DIPC_EVSU(T, 2, 0, &T2, &M2);
  if (N1 >= N2) {
    NL = N1;
    ML = M1;
    NP = N2;
    MP = M2;
    SP = S2;
  } else {
    NL = N2;
    ML = M2;
    NP = N1;
    MP = M1;
    SP = T2;
  }
  FL = NL - NP;
  HL = DINNGB_IPOWER(EL, FL);
  GL = MP * HL;
  GP = SACI_IMAX(ML, GL);
  DIPC_EVSU(SP, 2, GP, &C, &N1);
  return C;
}

MASSTOR_LIST DINNGB_EVLRCM
# ifdef __STDC__
(MASSTOR_LIST EL, MASSTOR_LIST S, MASSTOR_LIST T)
# else
(EL, S, T)
MASSTOR_LIST EL, S, T;
# endif
{
  MASSTOR_LIST C, FL, FS, GL, GP, HL, HP, KL, M1, M2, MP, ML, MS, N1, N2, NP, NL, NN, RL, S1, S2, SP, T1, T2;

  DIPC_EVSU(S, 1, 0, &S1, &N1);
  DIPC_EVSU(S, 2, 0, &S2, &M1);
  DIPC_EVSU(T, 1, 0, &T1, &N2);
  DIPC_EVSU(T, 2, 0, &T2, &M2);
  if (N1 >= N2) {
    NL = N1;
    ML = M1;
    NP = N2;
    MP = M2;
    SP = S2;
  } else {
    NL = N2;
    ML = M2;
    NP = N1;
    MP = M1;
    SP = T2;
  }
  FL = MP - ML;
  GP = DINNGB_IPOWER(EL, NP);
  if (SACI_IREM(FL, GP) == 0) {
    if (ML >= MP) {
      MS = ML;
    } else {
      FS = SACRN_RNINT(FL);
      GP = DINNGB_IPOWER(EL, NL);
      RL = SACRN_RNINT(GP);
      HL = SACRN_RNQ(FS, RL);
      HL = SACRN_RNCEIL(HL);
      MS = HL * GP + ML;
    }
    DIPC_EVSU(SP, 2, MS, &C, &N1);
  }
  return C;
}

MASSTOR_LIST DINNGB_EVRCMT
# ifdef __STDC__
(MASSTOR_LIST EL, MASSTOR_LIST S, MASSTOR_LIST T)
# else
(EL, S, T)
MASSTOR_LIST EL, S, T;
# endif
{
  MASSTOR_LIST C, FS, GP, M1, M2, MP, ML, N1, N2, NP, NL;

  DIPC_EVSU(S, 1, 0, &S, &N1);
  DIPC_EVSU(S, 2, 0, &S, &M1);
  DIPC_EVSU(T, 1, 0, &T, &N2);
  DIPC_EVSU(T, 2, 0, &T, &M2);
  if (N1 >= N2) {
    NL = N1;
    ML = M1;
    NP = N2;
    MP = M2;
  } else {
    NL = N2;
    ML = M2;
    NP = N1;
    MP = M1;
  }
  FS = MP - ML;
  NP = DINNGB_IPOWER(EL, NP);
  if (SACI_IREM(FS, NP) == 0) {
    C = 1;
  } else {
    C = 0;
  }
  return C;
}

MASSTOR_LIST DINNGB_DNNLNF
# ifdef __STDC__
(MASSTOR_LIST EL, MASSTOR_LIST P, MASSTOR_LIST S)
# else
(EL, P, S)
MASSTOR_LIST EL, P, S;
# endif
{
  MASSTOR_LIST AP, APP, BL, FL, OL, PP, Q, QA, QE, QP, R, SL, SP, SPP, TA, TE;

  if (S == 0 || P == MASSTOR_SIL) {
    R = S;
    return R;
  }
  R = MASSTOR_SIL;
  SP = S;
  OL = SACRN_RNINT(1);
  do {
    DIPC_DIPMAD(SP, &TA, &TE, &SPP);
    PP = P;
    do {
      MASSTOR_ADV(PP, &Q, &PP);
      DIPC_DIPMAD(Q, &QA, &QE, &QP);
      SL = DINNGB_EVNRDT(EL, QE, TE);
    } while (!(PP == MASSTOR_SIL || SL == 1));
    if (SL == 0) {
      R = DIPC_DIPMCP(TE, TA, R);
      if (SPP == MASSTOR_SIL) {
        SP = 0;
      } else {
        SP = SPP;
      }
    } else {
      FL = DINNGB_EVNCRD(EL, QE, TE);
      AP = DIPC_DIPFMO(OL, FL);
      APP = DINNGB_DINNCP(EL, AP, Q);
      BL = SACRN_RNQ(TA, QA);
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

MASSTOR_LIST DINNGB_DNNLIS
# ifdef __STDC__
(MASSTOR_LIST EL, MASSTOR_LIST P)
# else
(EL, P)
MASSTOR_LIST EL, P;
# endif
{
  MASSTOR_LIST IRR, LL, PL, PP, PS, RP, SL, UL, VL;

  PP = P;
  PS = MASSTOR_SIL;
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
    UL = DIPC_DIPEVL(PL);
    PL = DINNGB_DNNLNF(EL, PP, PL);
    SACLIST_AWRITE(IRR);
    MASBIOS_SWRITE(", ", 2L);
    if (PL == 0) {
      LL = LL - 1;
      if (LL <= 1) {
        goto EXIT_1;
      }
    } else {
      VL = DIPC_DIPEVL(PL);
      SL = DIPC_EVSIGN(VL);
      if (SL == 0) {
        PP = MASSTOR_LIST1(PL);
        goto EXIT_1;
      }
      SL = SACLIST_EQUAL(UL, VL);
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

MASSTOR_LIST DINNGB_DNNLSP
# ifdef __STDC__
(MASSTOR_LIST EL, MASSTOR_LIST C_139_A, MASSTOR_LIST B)
# else
(EL, C_139_A, B)
MASSTOR_LIST EL, C_139_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, SL, FL, O, UL;

  O = SACRN_RNINT(1);
  C = 0;
  if (C_139_A == 0 || B == 0) {
    return C;
  }
  SL = DIPC_DIPEVL(C_139_A);
  FL = DIPC_DIPEVL(B);
  UL = DINNGB_EVLLCM(EL, SL, FL);
  AP = DINNGB_EVNCRD(EL, SL, UL);
  BP = DINNGB_EVNCRD(EL, FL, UL);
  AP = DIPC_DIPFMO(O, AP);
  BP = DIPC_DIPFMO(O, BP);
  AP = DINNGB_DINNCP(EL, AP, C_139_A);
  BP = DINNGB_DINNCP(EL, BP, B);
  AL = DIPC_DIPLBC(AP);
  BL = DIPC_DIPLBC(BP);
  AP = DIPRN_DIRPRP(AP, BL);
  BP = DIPRN_DIRPRP(BP, AL);
  C = DIPRN_DIRPDF(AP, BP);
  return C;
}

MASSTOR_LIST DINNGB_DNNLGB
# ifdef __STDC__
(MASSTOR_LIST EL, MASSTOR_LIST P, MASSTOR_LIST TF)
# else
(EL, P, TF)
MASSTOR_LIST EL, P, TF;
# endif
{
  MASSTOR_LIST B, C, CPI, CPJ, CPP, D, DL, H, IL, J1Y, PLI, PLIP, PLJ, PP, PPP, PPR, PS, Q, QP, S, SL, TL, TR, UL, V, XH;

  TL = MASSTOR_TIME();
  XH = 0;
  if (P == MASSTOR_SIL) {
    PP = P;
    return PP;
  }
  PS = P;
  PPR = MASSTOR_SIL;
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
  V = DIPC_VALIS;
  if (PP == MASSTOR_SIL || MASSTOR_RED(PP) == MASSTOR_SIL) {
    return PP;
  }
  if (TF < 0) {
    TF = -TF;
    TR = MASSTOR_TIME();
    PP = DINNGB_DNNLIS(EL, PP);
    MASBIOS_SWRITE("***IRR TIME=", 12L);
    SACLIST_AWRITE(MASSTOR_TIME() - TR);
    MASBIOS_BLINES(0);
  }
  PPR = DIPC_DIPLPM(PP);
  PP = MASSTOR_INV(PPR);
  DINNGB_DNLCPL(EL, PP, &D, &B);
  for (;;) {
    if (D == MASSTOR_SIL) {
      goto EXIT_2;
    }
    MASSTOR_ADV(D, &DL, &D);
    SACLIST_FIRST3(DL, &UL, &CPI, &CPJ);
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
      MASBIOS_SWRITE("UL=", 3L);
      SACLIST_OWRITE(UL);
      MASBIOS_BLINES(0);
    }
    for (;;) {
      S = DINNGB_DNNLSP(EL, PLI, PLJ);
      if (S == 0) {
        goto EXIT_3;
      }
      XH = XH + 1;
      if (TF >= 2) {
        SACLIST_AWRITE(MASSTOR_TIME() - TL);
        MASBIOS_SWRITE(" S, ", 4L);
        MASBIOS_SWRITE("S=", 2L);
        DIPRN_DIRPWR(S, V, -1);
        MASBIOS_BLINES(1);
      }
      H = DINNGB_DNNLNF(EL, PP, S);
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
        DIPRN_DIRPWR(H, V, -1);
        MASBIOS_BLINES(1);
      }
      D = DINNGB_DNLUPL(EL, H, PP, D, B);
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
  PP = DINNGB_DNNLIS(EL, PP);
  return PP;
}

MASSTOR_LIST DINNGB_DNNRNF
# ifdef __STDC__
(MASSTOR_LIST EL, MASSTOR_LIST P, MASSTOR_LIST S)
# else
(EL, P, S)
MASSTOR_LIST EL, P, S;
# endif
{
  MASSTOR_LIST AP, APP, BL, OL, PP, Q, QA, QE, QP, R, SL, SP, SPP, TA, TE;

  if (S == 0 || P == MASSTOR_SIL) {
    R = S;
    return R;
  }
  R = MASSTOR_SIL;
  SP = S;
  OL = SACRN_RNINT(1);
  do {
    PP = P;
    DIPC_DIPMAD(SP, &TA, &TE, &SPP);
    do {
      MASSTOR_ADV(PP, &Q, &PP);
      DIPC_DIPMAD(Q, &QA, &QE, &QP);
      SL = DINNGB_EVNLDT(EL, QE, TE);
    } while (!(SL == 1 || PP == MASSTOR_SIL));
    if (SL == 0) {
      R = DIPC_DIPMCP(TE, TA, R);
      if (SPP == MASSTOR_SIL) {
        SP = 0;
      } else {
        SP = SPP;
      }
    } else {
      AP = DINNGB_EVNCLD(EL, QE, TE);
      AP = DIPC_DIPFMO(OL, AP);
      APP = DINNGB_DINNCP(EL, Q, AP);
      BL = SACRN_RNQ(TA, QA);
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

MASSTOR_LIST DINNGB_DNNRIS
# ifdef __STDC__
(MASSTOR_LIST EL, MASSTOR_LIST P)
# else
(EL, P)
MASSTOR_LIST EL, P;
# endif
{
  MASSTOR_LIST FL, IRR, LL, PL, PP, PS, RP, SL, UL;

  PP = P;
  PS = MASSTOR_SIL;
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
    UL = DIPC_DIPEVL(PL);
    PL = DINNGB_DNNRNF(EL, PP, PL);
    SACLIST_AWRITE(IRR);
    MASBIOS_SWRITE(", ", 2L);
    if (PL == 0) {
      LL = LL - 1;
      if (LL <= 1) {
        goto EXIT_4;
      }
    } else {
      FL = DIPC_DIPEVL(PL);
      SL = DIPC_EVSIGN(FL);
      if (SL == 0) {
        PP = MASSTOR_LIST1(PL);
        goto EXIT_4;
      }
      SL = SACLIST_EQUAL(UL, FL);
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
      goto EXIT_4;
    }
  } EXIT_4:;
  return PP;
}

MASSTOR_LIST DINNGB_DNNRSP
# ifdef __STDC__
(MASSTOR_LIST EL, MASSTOR_LIST C_138_A, MASSTOR_LIST B)
# else
(EL, C_138_A, B)
MASSTOR_LIST EL, C_138_A, B;
# endif
{
  MASSTOR_LIST AL, AP, APP, BL, BP, BPP, C, NL, FL, OL, SL, UL, V;

  OL = SACRN_RNINT(1);
  C = 0;
  if (C_138_A == 0 || B == 0) {
    return C;
  }
  NL = DIPC_DIPEVL(C_138_A);
  FL = DIPC_DIPEVL(B);
  SL = DINNGB_EVRCMT(EL, NL, FL);
  if (SL == 1) {
    UL = DINNGB_EVLRCM(EL, NL, FL);
    APP = DINNGB_EVNCLD(EL, NL, UL);
    BPP = DINNGB_EVNCLD(EL, FL, UL);
    BP = DIPC_DIPFMO(OL, BPP);
    AP = DIPC_DIPFMO(OL, APP);
    AP = DINNGB_DINNCP(EL, C_138_A, AP);
    BP = DINNGB_DINNCP(EL, B, BP);
    AL = DIPC_DIPLBC(AP);
    BL = DIPC_DIPLBC(BP);
    AP = DIPRN_DIRPRP(AP, BL);
    BP = DIPRN_DIRPRP(BP, AL);
    C = DIPRN_DIRPDF(AP, BP);
  }
  return C;
}

MASSTOR_LIST DINNGB_DNNRGB
# ifdef __STDC__
(MASSTOR_LIST EL, MASSTOR_LIST P, MASSTOR_LIST TF)
# else
(EL, P, TF)
MASSTOR_LIST EL, P, TF;
# endif
{
  MASSTOR_LIST B, C, CPI, CPJ, CPP, D, DL, ELI, ELJ, H, IL, J1Y, PLI, PLIP, PLJ, PP, PPR, PS, Q, QP, S, SL, T, TL, TR, UL, XH;

  TL = MASSTOR_TIME();
  XH = 0;
  if (P == MASSTOR_SIL) {
    PP = P;
    return PP;
  }
  PS = P;
  PPR = MASSTOR_SIL;
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
    PP = DINNGB_DNNRIS(EL, PP);
    MASBIOS_SWRITE("***IRR TIME=", 12L);
    SACLIST_AWRITE(MASSTOR_TIME() - TR);
    MASBIOS_BLINES(0);
  }
  PPR = DIPC_DIPLPM(PP);
  PP = MASSTOR_INV(PPR);
  DINNGB_DNRCPL(EL, PP, &D, &B);
  for (;;) {
    if (D == MASSTOR_SIL) {
      goto EXIT_5;
    }
    MASSTOR_ADV(D, &DL, &D);
    SACLIST_FIRST3(DL, &UL, &CPI, &CPJ);
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
      MASBIOS_SWRITE("UL=", 3L);
      SACLIST_OWRITE(UL);
      MASBIOS_BLINES(0);
    }
    for (;;) {
      ELI = DIPC_DIPEVL(PLI);
      ELJ = DIPC_DIPEVL(PLJ);
      T = DINNGB_EVRCMT(EL, ELI, ELJ);
      if (T == 0) {
        goto EXIT_6;
      }
      S = DINNGB_DNNRSP(EL, PLI, PLJ);
      if (S == 0) {
        goto EXIT_6;
      }
      XH = XH + 1;
      if (TF >= 2) {
        SACLIST_AWRITE(MASSTOR_TIME() - TL);
        MASBIOS_SWRITE(" S, ", 4L);
        MASBIOS_SWRITE("S=", 2L);
        DIPRN_DIRPWR(S, DIPC_VALIS, -1);
        MASBIOS_BLINES(1);
      }
      H = DINNGB_DNNRNF(EL, PP, S);
      if (H == 0) {
        goto EXIT_6;
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
      D = DINNGB_DNRUPL(EL, H, PP, D, B);
      goto EXIT_6;
    } EXIT_6:;
  } EXIT_5:;
  if (TF >= 1) {
    SACLIST_AWRITE(MASSTOR_TIME() - TL);
    MASBIOS_SWRITE(" S, ", 4L);
    SACLIST_AWRITE(XH);
    MASBIOS_SWRITE(" H-POLYNOMIALS.", 15L);
    MASBIOS_BLINES(0);
  }
  PP = DINNGB_DNNRIS(2, PP);
  return PP;
}

void DINNGB_DNLCPL
# ifdef __STDC__
(MASSTOR_LIST EL, MASSTOR_LIST P, MASSTOR_LIST *D, MASSTOR_LIST *B)
# else
(EL, P, D, B)
MASSTOR_LIST EL, P;
MASSTOR_LIST *D, *B;
# endif
{
  MASSTOR_LIST BP, BR, DL, ELI, ELJ, PI, PJ, PP, PSS, Q, QP, UL, V;

  *D = MASSTOR_SIL;
  *B = MASSTOR_SIL;
  if (P == MASSTOR_SIL) {
    return;
  }
  PP = P;
  BR = MASSTOR_SIL;
  PSS = PP;
  do {
    MASSTOR_ADV(PSS, &PI, &QP);
    Q = MASSTOR_LIST1(PI);
    BP = MASSTOR_COMP(0, BR);
    ELI = DIPC_DIPEVL(PI);
    while (QP != MASSTOR_SIL) {
      MASSTOR_ADV(QP, &PJ, &QP);
      ELJ = DIPC_DIPEVL(PJ);
      UL = DINNGB_EVLLCM(EL, ELI, ELJ);
      DL = SACLIST_LIST3(UL, BP, Q);
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

void DINNGB_DNRCPL
# ifdef __STDC__
(MASSTOR_LIST EL, MASSTOR_LIST P, MASSTOR_LIST *D, MASSTOR_LIST *B)
# else
(EL, P, D, B)
MASSTOR_LIST EL, P;
MASSTOR_LIST *D, *B;
# endif
{
  MASSTOR_LIST BP, BR, DL, ELI, ELJ, PI, PJ, PP, PSS, Q, QP, SL, UL, V;

  *D = MASSTOR_SIL;
  *B = MASSTOR_SIL;
  if (P == MASSTOR_SIL) {
    return;
  }
  PP = P;
  BR = MASSTOR_SIL;
  PSS = PP;
  do {
    MASSTOR_ADV(PSS, &PI, &QP);
    Q = MASSTOR_LIST1(PI);
    BP = MASSTOR_COMP(0, BR);
    ELI = DIPC_DIPEVL(PI);
    while (QP != MASSTOR_SIL) {
      MASSTOR_ADV(QP, &PJ, &QP);
      ELJ = DIPC_DIPEVL(PJ);
      SL = DINNGB_EVRCMT(EL, ELI, ELJ);
      if (SL == 1) {
        UL = DINNGB_EVLRCM(EL, ELI, ELJ);
        DL = SACLIST_LIST3(UL, BP, Q);
        *D = MASSTOR_COMP(DL, *D);
      }
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

MASSTOR_LIST DINNGB_DNLUPL
# ifdef __STDC__
(MASSTOR_LIST EL, MASSTOR_LIST PL, MASSTOR_LIST P, MASSTOR_LIST D, MASSTOR_LIST B)
# else
(EL, PL, P, D, B)
MASSTOR_LIST EL, PL, P, D, B;
# endif
{
  MASSTOR_LIST BP, BPP, BPPP, BR, DL, DP, ELI, ELJ, H, PB, PLI, PLJ, PP, PPP, PPR, PS, Q, QS, SL, TL, TF, UL, V;

  BP = B;
  DP = MASSTOR_SIL;
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
    UL = DINNGB_EVLLCM(EL, ELI, ELJ);
    DL = SACLIST_LIST3(UL, BP, Q);
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

MASSTOR_LIST DINNGB_DNRUPL
# ifdef __STDC__
(MASSTOR_LIST EL, MASSTOR_LIST PL, MASSTOR_LIST P, MASSTOR_LIST D, MASSTOR_LIST B)
# else
(EL, PL, P, D, B)
MASSTOR_LIST EL, PL, P, D, B;
# endif
{
  MASSTOR_LIST BP, BPP, BPPP, BR, DL, DP, ELI, ELJ, H, PB, PLI, PLJ, PP, PPP, PPR, PS, Q, QS, SL, TL, TF, UL, V;

  BP = B;
  DP = MASSTOR_SIL;
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
    TL = DINNGB_EVRCMT(EL, ELI, ELJ);
    if (TL == 1) {
      UL = DINNGB_EVLRCM(EL, ELI, ELJ);
      DL = SACLIST_LIST3(UL, BP, Q);
      DP = MASSTOR_COMP(DL, DP);
    }
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

MASSTOR_LIST DINNGB_DNN2GB
# ifdef __STDC__
(MASSTOR_LIST EL, MASSTOR_LIST P, MASSTOR_LIST TF)
# else
(EL, P, TF)
MASSTOR_LIST EL, P, TF;
# endif
{
  MASSTOR_LIST DL, F, FL, G, GL, GS, H, HL, HS, IL, J1Y, N, NL, O, PL, PLI, PLIP, PP, PPR, PS, Q, QL, RL, S, SL, TL, V, XH, XI, XL, XS, Y, YL;

  TL = MASSTOR_TIME();
  XH = 0;
  if (P == MASSTOR_SIL) {
    PP = P;
    return PP;
  }
  PS = P;
  PPR = MASSTOR_SIL;
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
  N = MASNC_EVZERO(2);
  O = SACRN_RNINT(1);
  DIPC_EVSU(N, 1, 1, &FL, &YL);
  Y = DIPC_DIPFMO(O, FL);
  V = DIPC_VALIS;
  G = DIPRNGB_DIRPGB(PP, TF);
  F = G;
  do {
    MASSTOR_ADV(F, &PL, &F);
    QL = DINNGB_DINNCP(EL, Y, PL);
    QL = DIPRNGB_DIRPNF(G, QL);
    QL = DIPRN_DIRPMC(QL);
    SL = DIPRN_DIRPON(QL);
    if (SL == 1) {
      G = MASSTOR_LIST1(QL);
      return G;
    }
    if (QL != 0) {
      G = DIPRNGB_DIRGBA(QL, G, TF);
    }
    DL = DINNGB_DIPLMD(G);
    IL = 0;
    while (IL <= DL) {
      XS = DINNGB_IPOWER(EL, IL);
      DIPC_EVSU(N, 2, XS, &GL, &XL);
      IL = IL + 1;
      XI = DIPC_DIPFMO(O, GL);
      HL = DINNGB_DINNCP(EL, PL, XI);
      HS = DIPRNGB_DIRPNF(G, HL);
      HS = DIPRN_DIRPMC(HS);
      SL = DIPRN_DIRPON(HS);
      if (SL == 1) {
        G = MASSTOR_LIST1(HS);
        return G;
      }
      if (HS != 0) {
        G = DIPRNGB_DIRGBA(HS, G, TF);
      }
    }
  } while (!(F == MASSTOR_SIL));
  if (TF < 0) {
    G = DIPRNGB_DIRLIS(G);
  }
  return G;
}

MASSTOR_LIST DINNGB_DNNTGB
# ifdef __STDC__
(MASSTOR_LIST EL, MASSTOR_LIST P, MASSTOR_LIST TF)
# else
(EL, P, TF)
MASSTOR_LIST EL, P, TF;
# endif
{
  MASSTOR_LIST B, B1, C, D, D1, DL, DP, FS, G, GL, GP, GR, GLE, GRE, GRS, QL, QLS, H, HG, HL, HS, IL, N, O, PL, PLI, PLIP, PP, PPR, PS, PSS, Q, S, SL, TL, V, FS1;

  TL = MASSTOR_TIME();
  if (P == MASSTOR_SIL) {
    PP = P;
    return PP;
  }
  PS = P;
  PPR = MASSTOR_SIL;
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
  V = DIPC_VALIS;
  G = PP;
  DL = DINNGB_DIPLMD(G);
  if (TF >= 2) {
    MASBIOS_SWRITE("The maximum Y-degree is:", 24L);
    SACLIST_OWRITE(DL);
    MASBIOS_BLINES(0);
  }
  PPR = DIPC_DIPLPM(G);
  G = MASSTOR_INV(PPR);
  MASBIOS_SWRITE("G:", 2L);
  DIPRN_DIRLWR(PP, V, -1);
  MASBIOS_BLINES(0);
  DIPRNGB_DILCPL(G, &D, &B);
  FS = DINNGB_DIPSPS(D, B);
  if (TF >= 2) {
    MASBIOS_SWRITE("The set of S-polynomials added is:", 34L);
    DIPRN_DIRLWR(FS, V, -1);
    MASBIOS_BLINES(0);
  }
  GP = SACLIST_CCONC(FS, G);
  GRE = DINNGB_DNNRES(EL, G, 0, DL);
  if (TF >= 2) {
    MASBIOS_SWRITE("The set of right multiples added is:", 36L);
    DIPRN_DIRLWR(GRE, V, -1);
    MASBIOS_BLINES(0);
  }
  GP = SACLIST_CCONC(GRE, GP);
  GLE = DINNGB_DNNLES(EL, PP);
  if (TF >= 2) {
    MASBIOS_SWRITE("The set left multiples added is:", 32L);
    DIPRN_DIRLWR(GLE, V, -1);
    MASBIOS_BLINES(0);
  }
  GP = SACLIST_CCONC(GLE, GP);
  do {
    MASSTOR_ADV(GP, &GL, &GP);
    G = DIPC_DIPLPM(G);
    G = MASSTOR_INV(G);
    GP = DIPC_DIPLPM(GP);
    GP = DIPRNGB_DIRLIS(GP);
    HL = DIPRNGB_DIRPNF(G, GL);
    if (HL != 0) {
      PSS = G;
      G = DIPC_DIPLPM(G);
      HL = DIPRNGB_DIRPNF(G, HL);
      HL = DIPRN_DIRPMC(HL);
      SL = DIPRN_DIRPON(HL);
      if (SL == 1) {
        G = MASSTOR_LIST1(HL);
        return G;
      }
      if (TF >= 2) {
        MASBIOS_SWRITE("HL=", 3L);
        DIPRN_DIRPWR(HL, V, -1);
        MASBIOS_BLINES(0);
      }
      D1 = MASSTOR_SIL;
      B1 = MASSTOR_SIL;
      PSS = G;
      while (PSS != MASSTOR_SIL) {
        MASSTOR_ADV(PSS, &QL, &PSS);
        QLS = MASSTOR_LIST1(QL);
        B1 = SACLIST_COMP2(QLS, QLS, B1);
      }
      B1 = MASSTOR_INV(B1);
      MASBIOS_SWRITE("update pairs:", 13L);
      MASBIOS_BLINES(0);
      D1 = DIPRNGB_DILUPL(HL, G, D1, B1);
      FS1 = DINNGB_DIPSPS(D1, B1);
      if (TF >= 2) {
        MASBIOS_SWRITE("The set of new S-polynomials added is:", 38L);
        DIPRN_DIRLWR(FS1, V, -1);
        MASBIOS_BLINES(0);
      }
      GP = SACLIST_CCONC(FS1, GP);
      HS = MASSTOR_LIST1(HL);
      GR = DINNGB_DNNRES(EL, HS, 0, DL);
      if (TF >= 2) {
        MASBIOS_SWRITE("The set of new right multiples added is:", 40L);
        DIPRN_DIRLWR(GR, V, -1);
        MASBIOS_BLINES(0);
      }
      GP = SACLIST_CCONC(GR, GP);
      HG = DINNGB_DNNLES(EL, HS);
      if (TF >= 2) {
        MASBIOS_SWRITE("The set of new left multiples added is:", 39L);
        DIPRN_DIRLWR(HG, V, -1);
        MASBIOS_BLINES(0);
      }
      GP = SACLIST_CCONC(HG, GP);
      DP = DINNGB_DIPLMD(G);
      if (DP > DL) {
        if (TF >= 2) {
          MASBIOS_SWRITE("The Y-dergree increased from ", 29L);
          SACLIST_OWRITE(DL);
          MASBIOS_SWRITE(" to ", 4L);
          SACLIST_OWRITE(DP);
          MASBIOS_BLINES(0);
        }
        DL = DL + 1;
        GRS = DINNGB_DNNRES(EL, G, DL, DP);
        if (TF >= 2) {
          MASBIOS_SWRITE("The set of right multiples added due to change of Y-degree:", 59L);
          DIPRN_DIRLWR(GRS, V, -1);
          MASBIOS_BLINES(0);
        }
        GP = SACLIST_CCONC(GRS, GP);
        DL = DP;
      }
    }
  } while (!(GP == MASSTOR_SIL));
  G = DIPRNGB_DIRLIS(G);
  return G;
}

MASSTOR_LIST DINNGB_DNNLES
# ifdef __STDC__
(MASSTOR_LIST EL, MASSTOR_LIST P)
# else
(EL, P)
MASSTOR_LIST EL, P;
# endif
{
  MASSTOR_LIST F, FL, GL, QL, N, O, PL, PP, RL, UL, Y, YL;

  FL = MASSTOR_FIRST(P);
  RL = DIPC_DIPNOV(FL);
  if (RL == 0) {
    return P;
  }
  N = MASNC_EVZERO(2);
  O = SACRN_RNINT(1);
  DIPC_EVSU(N, 1, 1, &UL, &YL);
  Y = DIPC_DIPFMO(O, UL);
  F = P;
  PP = MASSTOR_SIL;
  do {
    MASSTOR_ADV(F, &PL, &F);
    QL = DINNGB_DINNCP(EL, Y, PL);
    if (QL != 0) {
      PP = MASSTOR_COMP(QL, PP);
    }
  } while (!(F == MASSTOR_SIL));
  PP = MASSTOR_INV(PP);
  return PP;
}

MASSTOR_LIST DINNGB_DNNRES
# ifdef __STDC__
(MASSTOR_LIST EL, MASSTOR_LIST P, MASSTOR_LIST DL, MASSTOR_LIST DP)
# else
(EL, P, DL, DP)
MASSTOR_LIST EL, P, DL, DP;
# endif
{
  MASSTOR_LIST F, FL, GL, HS, QL, IL, N, O, PL, PP, RL, UL, X, XI, XL, XS;

  FL = MASSTOR_FIRST(P);
  RL = DIPC_DIPNOV(FL);
  if (RL == 0) {
    return P;
  }
  N = MASNC_EVZERO(2);
  O = SACRN_RNINT(1);
  F = P;
  PP = MASSTOR_SIL;
  do {
    MASSTOR_ADV(F, &PL, &F);
    IL = DL;
    while (IL <= DP) {
      XS = DINNGB_IPOWER(EL, IL);
      DIPC_EVSU(N, 2, XS, &GL, &XL);
      XI = DIPC_DIPFMO(O, GL);
      HS = DINNGB_DINNCP(EL, PL, XI);
      if (HS != 0) {
        PP = MASSTOR_COMP(HS, PP);
      }
      IL = IL + 1;
    }
  } while (!(F == MASSTOR_SIL));
  return PP;
}

MASSTOR_LIST DINNGB_DIPSPS
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST B)
# else
(D, B)
MASSTOR_LIST D, B;
# endif
{
  MASSTOR_LIST C, CPI, CPJ, CPP, DL, H, S, SL, J1Y, N, NL, O, PL, PLI, PLJ, Q, QP, SL3, SL4, SP, UL;

  H = MASSTOR_SIL;
  if (D == MASSTOR_SIL) {
    return H;
  }
  do {
    MASSTOR_ADV(D, &DL, &D);
    SACLIST_FIRST3(DL, &UL, &CPI, &CPJ);
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
    SL3 = DIPRNGB_DIGBC3(B, PLI, PLJ, UL);
    SL4 = DIPRNGB_DIGBC4(PLI, PLJ, UL);
    if (SL3 != 0 && SL3 != 0) {
      S = DIPRNGB_DIRPSP(PLI, PLJ);
      if (S != 0) {
        S = DIPRN_DIRPMC(S);
        SL = DIPRN_DIRPON(S);
        if (SL == 1) {
          H = MASSTOR_LIST1(S);
          return H;
        }
        H = MASSTOR_COMP(S, H);
      }
    }
  } while (!(D == MASSTOR_SIL));
  return H;
}

MASSTOR_LIST DINNGB_DIPLMD
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST DL, NL, PL;

  DL = 0;
  do {
    MASSTOR_ADV(P, &PL, &P);
    NL = DIPC_DIPDEG(PL);
    if (NL >= DL) {
      DL = NL;
    }
  } while (!(P == MASSTOR_SIL));
  return DL;
}

MASSTOR_LIST DINNGB_IPOWER
# ifdef __STDC__
(MASSTOR_LIST EL, MASSTOR_LIST AL)
# else
(EL, AL)
MASSTOR_LIST EL, AL;
# endif
{
  MASSTOR_LIST C;

  C = 1;
  if (AL == 0) {
    return C;
  }
  while (AL >= 1) {
    C = EL * C;
    AL = AL - 1;
  }
  return C;
}

void BEGIN_DINNGB()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_SACPOL();
    BEGIN_MASBIOS();
    BEGIN_DIPRN();
    BEGIN_SACRN();
    BEGIN_DIPRNGB();
    BEGIN_DIPC();
    BEGIN_SACI();
    BEGIN_MASNC();

  }
}
