#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASERR
#include "MASERR.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SACD
#include "SACD.h"
#endif

#ifndef DEFINITION_SACI
#include "SACI.h"
#endif

#ifndef DEFINITION_SACRN
#include "SACRN.h"
#endif

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_MASRN
#include "MASRN.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPRN
#include "DIPRN.h"
#endif

CHAR DIPRN_rcsid [] = "$Id: DIPRN.md,v 1.2 1992/02/12 17:33:51 pesch Exp $";
CHAR DIPRN_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: DIPRN.mi,v 1.4 1995/11/05 09:18:39 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST DIPRN_DIRFIP
# ifdef __STDC__
(MASSTOR_LIST C_166_A)
# else
(C_166_A)
MASSTOR_LIST C_166_A;
# endif
{
  MASSTOR_LIST AL, AL1, AP, B, BL, EL;

  if (C_166_A == 0) {
    B = 0;
    return B;
  }
  DIPC_DIPMAD(C_166_A, &AL1, &EL, &AP);
  BL = SACRN_RNINT(1);
  B = DIPC_DIPFMO(EL, BL);
  while (AP != MASSTOR_SIL) {
    DIPC_DIPMAD(AP, &AL, &EL, &AP);
    BL = SACRN_RNRED(AL, AL1);
    B = DIPC_DIPMCP(EL, BL, B);
  }
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST DIPRN_DIRLRD
# ifdef __STDC__
(MASSTOR_LIST V)
# else
(V)
MASSTOR_LIST V;
# endif
{
  MASSTOR_LIST C_165_A, AL, C;

  C_165_A = MASSTOR_BETA;
  C = MASBIOS_CREADB();
  if (C != MASBIOS_MASORD('(')) {
    MASERR_ERROR(MASERR_harmless, "DIRLRD, ( expected.", 19L);
    return C_165_A;
  }
  do {
    C = MASBIOS_CREADB();
    if (C == MASBIOS_MASORD(',')) {
      C = MASBIOS_CREADB();
    }
    if (C != MASBIOS_MASORD(')')) {
      MASBIOS_BKSP();
      AL = DIPRN_DIRPRD(V);
      C_165_A = MASSTOR_COMP(AL, C_165_A);
    }
  } while (!(C == MASBIOS_MASORD(')')));
  C_165_A = MASSTOR_INV(C_165_A);
  return C_165_A;
}

void DIPRN_DIRLWR
# ifdef __STDC__
(MASSTOR_LIST C_164_A, MASSTOR_LIST V, MASSTOR_LIST S)
# else
(C_164_A, V, S)
MASSTOR_LIST C_164_A, V, S;
# endif
{
  MASSTOR_LIST AL, AP, OS, LS, RS;

  MASBIOS_BLINES(0);
  OS = -1;
  LS = 10;
  RS = 60;
  MASBIOS_SOLINE(&OS, &LS, &RS);
  AP = C_164_A;
  while (AP != MASSTOR_SIL) {
    MASSTOR_ADV(AP, &AL, &AP);
    DIPRN_DIRPWR(AL, V, S);
    MASBIOS_BLINES(1);
  }
  MASBIOS_SOLINE(&OS, &LS, &RS);
  MASBIOS_BLINES(0);
  return;
}

MASSTOR_LIST DIPRN_DIRPAB
# ifdef __STDC__
(MASSTOR_LIST C_163_A)
# else
(C_163_A)
MASSTOR_LIST C_163_A;
# endif
{
  MASSTOR_LIST B, SL;

  SL = DIPRN_DIRPSG(C_163_A);
  if (SL >= 0) {
    B = C_163_A;
  } else {
    B = DIPRN_DIRPNG(C_163_A);
  }
  return B;
}

MASSTOR_LIST DIPRN_DIRPDF
# ifdef __STDC__
(MASSTOR_LIST C_162_A, MASSTOR_LIST B)
# else
(C_162_A, B)
MASSTOR_LIST C_162_A, B;
# endif
{
  MASSTOR_LIST AL, AP, APP, BL, BP, C, CL, CP, CPP, EL, FL, SL;

  if (C_162_A == 0) {
    C = DIPRN_DIRPNG(B);
    return C;
  }
  if (B == 0) {
    C = C_162_A;
    return C;
  }
  AP = C_162_A;
  BP = B;
  CP = MASSTOR_BETA;
  do {
    EL = DIPC_DIPEVL(AP);
    FL = DIPC_DIPEVL(BP);
    SL = DIPC_EVCOMP(EL, FL);
    if (SL == 1) {
      DIPC_DIPMAD(AP, &AL, &EL, &AP);
      CP = DIPC_DIPMCP(EL, AL, CP);
    } else {
      if (SL == -1) {
        DIPC_DIPMAD(BP, &BL, &FL, &BP);
        CL = SACRN_RNNEG(BL);
        CP = DIPC_DIPMCP(FL, CL, CP);
      } else {
        DIPC_DIPMAD(AP, &AL, &EL, &AP);
        DIPC_DIPMAD(BP, &BL, &FL, &BP);
        CL = SACRN_RNDIF(AL, BL);
        if (CL != 0) {
          CP = DIPC_DIPMCP(EL, CL, CP);
        }
      }
    }
  } while (!(AP == MASSTOR_SIL || BP == MASSTOR_SIL));
  APP = AP;
  if (AP == MASSTOR_SIL) {
    if (BP != MASSTOR_SIL) {
      APP = DIPRN_DIRPNG(BP);
    }
  }
  if (CP == MASSTOR_SIL) {
    C = APP;
  } else {
    CPP = CP;
    C = MASSTOR_INV(CP);
    MASSTOR_SRED(CPP, APP);
  }
  if (C == MASSTOR_SIL) {
    C = 0;
  }
  return C;
}

MASSTOR_LIST DIPRN_DIRPDM
# ifdef __STDC__
(MASSTOR_LIST C_161_A)
# else
(C_161_A)
MASSTOR_LIST C_161_A;
# endif
{
  MASSTOR_LIST AL, ALP, AS, B, EL, EL1, EL2, ELR, ELS, FL;

  if (C_161_A == 0) {
    B = 0;
    return B;
  }
  if (DIPC_DIPEVL(C_161_A) == MASSTOR_SIL) {
    B = 0;
    return B;
  }
  AS = C_161_A;
  B = MASSTOR_BETA;
  do {
    DIPC_DIPMAD(AS, &AL, &EL, &AS);
    MASSTOR_ADV(EL, &EL1, &ELS);
    if (EL1 > 0) {
      ELR = SACRN_RNINT(EL1);
      ALP = SACRN_RNPROD(AL, ELR);
      EL2 = EL1 - 1;
      FL = MASSTOR_COMP(EL2, ELS);
      B = DIPC_DIPMCP(FL, ALP, B);
    }
  } while (!(AS == MASSTOR_SIL || EL1 == 0));
  if (B == MASSTOR_SIL) {
    B = 0;
  } else {
    B = MASSTOR_INV(B);
  }
  return B;
}

MASSTOR_LIST DIPRN_DIRPDR
# ifdef __STDC__
(MASSTOR_LIST C_160_A, MASSTOR_LIST IL)
# else
(C_160_A, IL)
MASSTOR_LIST C_160_A, IL;
# endif
{
  MASSTOR_LIST AL, ALP, AS, B, EL, ELP, FL, FLR, J1Y, JL, KL, RL;

  if (C_160_A == 0) {
    B = 0;
    return B;
  }
  RL = DIPC_DIPNOV(C_160_A);
  KL = 1;
  J1Y = RL - IL;
  JL = J1Y + 1;
  AS = C_160_A;
  B = MASSTOR_BETA;
  do {
    DIPC_DIPMAD(AS, &AL, &EL, &AS);
    DIPC_EVDER(EL, JL, KL, &ELP, &FL);
    if (FL != 0) {
      FLR = SACRN_RNINT(FL);
      ALP = SACRN_RNPROD(AL, FLR);
      B = DIPC_DIPMCP(ELP, ALP, B);
    }
  } while (!(AS == MASSTOR_SIL));
  if (B == MASSTOR_SIL) {
    B = 0;
  } else {
    B = MASSTOR_INV(B);
  }
  return B;
}

MASSTOR_LIST DIPRN_DIRPEM
# ifdef __STDC__
(MASSTOR_LIST C_159_A, MASSTOR_LIST AL)
# else
(C_159_A, AL)
MASSTOR_LIST C_159_A, AL;
# endif
{
  MASSTOR_LIST ALP, AP, B, C, EL1, EL2, J1Y;

  if (C_159_A == 0) {
    B = 0;
    return B;
  }
  DIPC_DIPADM(C_159_A, &EL1, &EL2, &B, &AP);
  while (AP != 0) {
    J1Y = EL1 - EL2;
    ALP = MASRN_RNEXP(AL, J1Y);
    B = DIPRN_DIRPRP(B, ALP);
    DIPC_DIPADM(AP, &EL1, &EL2, &C, &AP);
    B = DIPRN_DIRPSM(B, C);
  }
  ALP = MASRN_RNEXP(AL, EL1);
  B = DIPRN_DIRPRP(B, ALP);
  return B;
}

MASSTOR_LIST DIPRN_DIRPEV
# ifdef __STDC__
(MASSTOR_LIST C_158_A, MASSTOR_LIST IL, MASSTOR_LIST AL)
# else
(C_158_A, IL, AL)
MASSTOR_LIST C_158_A, IL, AL;
# endif
{
  MASSTOR_LIST ALP, AP, B, BS, C, D, EL1, EL2, J1Y, RL;

  if (C_158_A == 0) {
    B = 0;
    return B;
  }
  B = MASSTOR_LIST1(0);
  BS = B;
  AP = C_158_A;
  do {
    DIPC_DIPADV(AP, IL, &EL1, &EL2, &D, &AP);
    while (AP != 0 && EL1 > EL2) {
      J1Y = EL1 - EL2;
      ALP = MASRN_RNEXP(AL, J1Y);
      D = DIPRN_DIRPRP(D, ALP);
      DIPC_DIPADV(AP, IL, &EL1, &EL2, &C, &AP);
      D = DIPRN_DIRPSM(D, C);
    }
    ALP = MASRN_RNEXP(AL, EL1);
    D = DIPRN_DIRPRP(D, ALP);
    B = MASSTOR_COMP(D, B);
  } while (!(AP == 0));
  MASSTOR_ADV(B, &D, &B);
  MASSTOR_SFIRST(BS, D);
  MASSTOR_SRED(BS, B);
  B = DIPRN_DIRPLS(B);
  return B;
}

MASSTOR_LIST DIPRN_DIRPEX
# ifdef __STDC__
(MASSTOR_LIST C_157_A, MASSTOR_LIST NL)
# else
(C_157_A, NL)
MASSTOR_LIST C_157_A, NL;
# endif
{
  MASSTOR_LIST B, BL, BLP, I, RL;

  if (NL == 0) {
    RL = DIPC_DIPNOV(C_157_A);
    BLP = SACRN_RNINT(1);
    BL = DIPC_DIPFMO(BLP, MASSTOR_BETA);
    B = DIPC_DIPINV(BL, 0, RL);
    return B;
  }
  if (C_157_A == 0) {
    B = 0;
    return B;
  }
  B = C_157_A;
  {
    LONGINT B_1 = 1, B_2 = NL - 1;

    if (B_1 <= B_2)
      for (I = B_1;; I += 1) {
        B = DIPRN_DIRPPR(B, C_157_A);
        if (I >= B_2) break;
      }
  }
  return B;
}

MASSTOR_LIST DIPRN_DIRPHD
# ifdef __STDC__
(MASSTOR_LIST C_156_A, MASSTOR_LIST IL, MASSTOR_LIST NL)
# else
(C_156_A, IL, NL)
MASSTOR_LIST C_156_A, IL, NL;
# endif
{
  MASSTOR_LIST AL, ALP, AS, B, EL, ELP, FL, FLR, J1Y, JL, RL;

  if (C_156_A == 0) {
    B = 0;
    return B;
  }
  RL = DIPC_DIPNOV(C_156_A);
  J1Y = RL - IL;
  JL = J1Y + 1;
  AS = C_156_A;
  B = MASSTOR_BETA;
  do {
    DIPC_DIPMAD(AS, &AL, &EL, &AS);
    DIPC_EVDER(EL, JL, NL, &ELP, &FL);
    if (FL != 0) {
      FLR = SACRN_RNINT(FL);
      ALP = SACRN_RNPROD(AL, FLR);
      B = DIPC_DIPMCP(ELP, ALP, B);
    }
  } while (!(AS == MASSTOR_SIL));
  if (B == MASSTOR_SIL) {
    B = 0;
  } else {
    B = MASSTOR_INV(B);
  }
  return B;
}

MASSTOR_LIST DIPRN_DIRPLS
# ifdef __STDC__
(MASSTOR_LIST C_155_A)
# else
(C_155_A)
MASSTOR_LIST C_155_A;
# endif
{
  MASSTOR_LIST B, BP, BPP, C, CP, CPP;

  if (C_155_A == MASSTOR_SIL) {
    B = 0;
    return B;
  }
  C = C_155_A;
  MASSTOR_ADV(C, &B, &CP);
  while (C != CP) {
    MASSTOR_ADV(CP, &BP, &CPP);
    BPP = DIPRN_DIRPSM(B, BP);
    MASSTOR_SFIRST(C, BPP);
    MASSTOR_SRED(C, CPP);
    C = CPP;
    MASSTOR_ADV(C, &B, &CP);
  }
  return B;
}

MASSTOR_LIST DIPRN_DIRPMC
# ifdef __STDC__
(MASSTOR_LIST C_154_A)
# else
(C_154_A)
MASSTOR_LIST C_154_A;
# endif
{
  MASSTOR_LIST BL, C, CL, SL;

  C = C_154_A;
  if (C_154_A == 0) {
    return C;
  }
  BL = DIPC_DIPLBC(C_154_A);
  SL = MASRN_RNONE(BL);
  if (SL != 1) {
    CL = SACRN_RNINV(BL);
    C = DIPRN_DIRPRP(C_154_A, CL);
  }
  return C;
}

MASSTOR_LIST DIPRN_DIRPMN
# ifdef __STDC__
(MASSTOR_LIST C_153_A)
# else
(C_153_A)
MASSTOR_LIST C_153_A;
# endif
{
  MASSTOR_LIST AL, AS, BL, CL, EL;

  BL = 0;
  if (C_153_A == 0) {
    return BL;
  }
  AS = C_153_A;
  do {
    DIPC_DIPMAD(AS, &AL, &EL, &AS);
    CL = SACRN_RNABS(AL);
    BL = MASRN_RNMAX(CL, BL);
  } while (!(AS == MASSTOR_SIL));
  return BL;
}

MASSTOR_LIST DIPRN_DIRPNG
# ifdef __STDC__
(MASSTOR_LIST C_152_A)
# else
(C_152_A)
MASSTOR_LIST C_152_A;
# endif
{
  MASSTOR_LIST AL, AS, B, BL, EL;

  if (C_152_A == 0) {
    B = 0;
    return B;
  }
  AS = C_152_A;
  B = MASSTOR_BETA;
  do {
    DIPC_DIPMAD(AS, &AL, &EL, &AS);
    BL = SACRN_RNNEG(AL);
    B = DIPC_DIPMCP(EL, BL, B);
  } while (!(AS == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST DIPRN_DIRPON
# ifdef __STDC__
(MASSTOR_LIST C_151_A)
# else
(C_151_A)
MASSTOR_LIST C_151_A;
# endif
{
  MASSTOR_LIST AL, AS, EL, FL, TL;

  TL = 0;
  if (C_151_A == 0) {
    return TL;
  }
  DIPC_DIPMAD(C_151_A, &AL, &EL, &AS);
  if (AS != MASSTOR_SIL) {
    return TL;
  }
  FL = DIPC_EVSIGN(EL);
  if (FL != 0) {
    return TL;
  }
  TL = MASRN_RNONE(AL);
  return TL;
}

MASSTOR_LIST DIPRN_DIRPPR
# ifdef __STDC__
(MASSTOR_LIST C_150_A, MASSTOR_LIST B)
# else
(C_150_A, B)
MASSTOR_LIST C_150_A, B;
# endif
{
  MASSTOR_LIST AL, AP, AS, BL, BS, C, C1, CL, CS, EL, FL, GL;

  if (C_150_A == 0 || B == 0) {
    C = 0;
    return C;
  }
  AS = SACLIST_CINV(C_150_A);
  BS = B;
  C = MASSTOR_LIST1(0);
  CS = C;
  do {
    DIPC_DIPMAD(BS, &BL, &FL, &BS);
    AP = AS;
    C1 = MASSTOR_BETA;
    do {
      DIPC_DIPMAD(AP, &EL, &AL, &AP);
      CL = SACRN_RNPROD(AL, BL);
      GL = DIPC_EVSUM(EL, FL);
      C1 = DIPC_DIPMCP(CL, GL, C1);
    } while (!(AP == MASSTOR_SIL));
    C = MASSTOR_COMP(C1, C);
  } while (!(BS == MASSTOR_SIL));
  MASSTOR_ADV(C, &C1, &C);
  MASSTOR_SFIRST(CS, C1);
  MASSTOR_SRED(CS, C);
  C = DIPRN_DIRPLS(C);
  return C;
}

MASSTOR_LIST DIPRN_DIRPQ
# ifdef __STDC__
(MASSTOR_LIST C_149_A, MASSTOR_LIST B)
# else
(C_149_A, B)
MASSTOR_LIST C_149_A, B;
# endif
{
  MASSTOR_LIST C, R;

  DIPRN_DIRPQR(C_149_A, B, &C, &R);
  return C;
}

void DIPRN_DIRPQR
# ifdef __STDC__
(MASSTOR_LIST C_148_A, MASSTOR_LIST B, MASSTOR_LIST *Q, MASSTOR_LIST *R)
# else
(C_148_A, B, Q, R)
MASSTOR_LIST C_148_A, B;
MASSTOR_LIST *Q, *R;
# endif
{
  MASSTOR_LIST AL, BL, BP, DL, ML, NL, Q1, QL, QP, RP, SL, TL;

  DIPC_DIPMAD(B, &BL, &NL, &BP);
  if (BP == MASSTOR_SIL) {
    BP = 0;
  }
  *Q = MASSTOR_BETA;
  *R = C_148_A;
  for (;;) {
    if (*R == 0) {
      goto EXIT_1;
    }
    ML = DIPC_DIPEVL(*R);
    DIPC_EVDFSI(ML, NL, &DL, &TL);
    if (TL < 0) {
      goto EXIT_1;
    }
    AL = DIPC_DIPLBC(*R);
    QL = SACRN_RNQ(AL, BL);
    *Q = DIPC_DIPMCP(DL, QL, *Q);
    Q1 = DIPC_DIPFMO(QL, DL);
    RP = DIPC_DIPMRD(*R);
    QP = DIPRN_DIRPPR(BP, Q1);
    *R = DIPRN_DIRPDF(RP, QP);
  } EXIT_1:;
  if (*Q == MASSTOR_SIL) {
    *Q = 0;
  } else {
    *Q = MASSTOR_INV(*Q);
  }
  return;
}

MASSTOR_LIST DIPRN_DIRPRA
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST KL, MASSTOR_LIST LL, MASSTOR_LIST EL)
# else
(RL, KL, LL, EL)
MASSTOR_LIST RL, KL, LL, EL;
# endif
{
  MASSTOR_LIST C_147_A, AL, AP, FL, IL;

  C_147_A = 0;
  if (RL == 0) {
    AL = SACRN_RNRAND(KL);
    C_147_A = DIPC_DIPFMO(AL, MASSTOR_BETA);
    return C_147_A;
  }
  {
    LONGINT B_3 = 1, B_4 = LL;

    if (B_3 <= B_4)
      for (IL = B_3;; IL += 1) {
        AL = SACRN_RNRAND(KL);
        if (AL != 0) {
          FL = DIPC_EVRAND(RL, EL);
          AP = DIPC_DIPFMO(AL, FL);
          C_147_A = DIPRN_DIRPSM(C_147_A, AP);
        }
        if (IL >= B_4) break;
      }
  }
  return C_147_A;
}

MASSTOR_LIST DIPRN_DIRPRD
# ifdef __STDC__
(MASSTOR_LIST V)
# else
(V)
MASSTOR_LIST V;
# endif
{
  MASSTOR_LIST C_146_A, A1, AL, AP, C, EL, ES, FL, IDUM, IL, J1Y, JL, RL, VL;

  C_146_A = 0;
  C = MASBIOS_CREADB();
  if (C == 0) {
    return C_146_A;
  }
  MASBIOS_BKSP();
  C = MASBIOS_CREADB();
  MASBIOS_BKSP();
  if (C == MASBIOS_MASORD(',')) {
    MASERR_ERROR(MASERR_harmless, "DIRPRD, no , expected.", 22L);
    return C_146_A;
  }
  FL = 0;
  if (C == MASBIOS_MASORD('(')) {
    C = MASBIOS_CREADB();
    FL = 1;
  }
  if (C == MASBIOS_MASORD(')')) {
    if (FL == 1) {
      return C_146_A;
    } else {
      MASERR_ERROR(MASERR_harmless, "DIRPRD, no ) expected.", 22L);
      return C_146_A;
    }
  }
  RL = MASSTOR_LENGTH(V);
  ES = MASSTOR_BETA;
  {
    LONGINT B_5 = 1, B_6 = RL;

    if (B_5 <= B_6)
      for (IL = B_5;; IL += 1) {
        ES = MASSTOR_COMP(0, ES);
        if (IL >= B_6) break;
      }
  }
  J1Y = SACRN_RNINT(1);
  A1 = DIPC_DIPFMO(J1Y, ES);
  AP = A1;
  for (;;) {
    C = MASBIOS_CREADB();
    if (C == MASBIOS_MASORD(')')) {
      if (FL == 0) {
        MASBIOS_BKSP();
      }
      return C_146_A;
    }
    if (C == MASBIOS_MASORD(',')) {
      MASBIOS_BKSP();
      return C_146_A;
    }
    if (C == MASBIOS_MASORD('-')) {
      AP = DIPRN_DIRPNG(AP);
    }
    if (C == MASBIOS_MASORD('+') || C == MASBIOS_MASORD('-')) {
      C = MASBIOS_CREADB();
    }
    if (C == MASBIOS_MASORD('*')) {
      C = MASBIOS_CREADB();
    }
    MASBIOS_BKSP();
    if (MASBIOS_DIGIT(C)) {
      AL = MASRN_RNDRD();
      EL = DIPC_EPREAD();
      AL = MASRN_RNEXP(AL, EL);
      AP = DIPRN_DIRPRP(AP, AL);
    } else if (C == MASBIOS_MASORD('(')) {
      AL = DIPRN_DIRPRD(V);
      EL = DIPC_EPREAD();
      AL = DIPRN_DIRPEX(AL, EL);
      AP = DIPRN_DIRPPR(AP, AL);
    } else if (MASBIOS_LETTER(C)) {
      VL = SACPOL_VREAD();
      JL = SACPOL_VLSRCH(VL, V);
      if (JL == 0) {
        MASERR_ERROR(MASERR_harmless, "DIRPRD, unknown variable.", 25L);
        return C_146_A;
      }
      EL = DIPC_EPREAD();
      AP = DIPC_DIPMPV(AP, JL, EL);
    }
    C = MASBIOS_CREADB();
    MASBIOS_BKSP();
    if (C == MASBIOS_MASORD('+') || C == MASBIOS_MASORD('-') || C == MASBIOS_MASORD(')') || C == MASBIOS_MASORD(',')) {
      C_146_A = DIPRN_DIRPSM(C_146_A, AP);
      AP = A1;
    }
  } EXIT_2:;
}

MASSTOR_LIST DIPRN_DIRPRP
# ifdef __STDC__
(MASSTOR_LIST C_145_A, MASSTOR_LIST BL)
# else
(C_145_A, BL)
MASSTOR_LIST C_145_A, BL;
# endif
{
  MASSTOR_LIST AL, AP, C, EL, PL;

  if (C_145_A == 0 || BL == 0) {
    C = 0;
    return C;
  }
  C = MASSTOR_BETA;
  AP = C_145_A;
  do {
    DIPC_DIPMAD(AP, &AL, &EL, &AP);
    PL = SACRN_RNPROD(AL, BL);
    C = DIPC_DIPMCP(EL, PL, C);
  } while (!(AP == MASSTOR_SIL));
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST DIPRN_DIRPRQ
# ifdef __STDC__
(MASSTOR_LIST C_144_A, MASSTOR_LIST BL)
# else
(C_144_A, BL)
MASSTOR_LIST C_144_A, BL;
# endif
{
  MASSTOR_LIST AL, AP, C, CL, EL, QL;

  if (C_144_A == 0) {
    C = 0;
    return C;
  }
  C = MASSTOR_BETA;
  AP = C_144_A;
  CL = SACRN_RNINV(BL);
  do {
    DIPC_DIPMAD(AP, &AL, &EL, &AP);
    QL = SACRN_RNPROD(AL, CL);
    C = DIPC_DIPMCP(EL, QL, C);
  } while (!(AP == MASSTOR_SIL));
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST DIPRN_DIRPSG
# ifdef __STDC__
(MASSTOR_LIST C_143_A)
# else
(C_143_A)
MASSTOR_LIST C_143_A;
# endif
{
  MASSTOR_LIST J1Y, SL;

  if (C_143_A == 0) {
    SL = 0;
  } else {
    J1Y = DIPC_DIPLBC(C_143_A);
    SL = SACRN_RNSIGN(J1Y);
  }
  return SL;
}

MASSTOR_LIST DIPRN_DIRPSM
# ifdef __STDC__
(MASSTOR_LIST C_142_A, MASSTOR_LIST B)
# else
(C_142_A, B)
MASSTOR_LIST C_142_A, B;
# endif
{
  MASSTOR_LIST AL, AP, APP, BL, BP, C, CL, CP, CPP, EL, FL, SL;

  if (C_142_A == 0) {
    C = B;
    return C;
  }
  if (B == 0) {
    C = C_142_A;
    return C;
  }
  AP = C_142_A;
  BP = B;
  CP = MASSTOR_BETA;
  do {
    EL = DIPC_DIPEVL(AP);
    FL = DIPC_DIPEVL(BP);
    SL = DIPC_EVCOMP(EL, FL);
    if (SL == 1) {
      DIPC_DIPMAD(AP, &AL, &EL, &AP);
      CP = DIPC_DIPMCP(EL, AL, CP);
    } else {
      if (SL == -1) {
        DIPC_DIPMAD(BP, &BL, &FL, &BP);
        CP = DIPC_DIPMCP(FL, BL, CP);
      } else {
        DIPC_DIPMAD(AP, &AL, &EL, &AP);
        DIPC_DIPMAD(BP, &BL, &FL, &BP);
        CL = SACRN_RNSUM(AL, BL);
        if (CL != 0) {
          CP = DIPC_DIPMCP(EL, CL, CP);
        }
      }
    }
  } while (!(AP == MASSTOR_SIL || BP == MASSTOR_SIL));
  if (AP == MASSTOR_SIL) {
    APP = BP;
  } else {
    APP = AP;
  }
  if (CP == MASSTOR_SIL) {
    C = APP;
  } else {
    CPP = CP;
    C = MASSTOR_INV(CP);
    MASSTOR_SRED(CPP, APP);
  }
  if (C == MASSTOR_SIL) {
    C = 0;
  }
  return C;
}

MASSTOR_LIST DIPRN_DIRPSN
# ifdef __STDC__
(MASSTOR_LIST C_141_A)
# else
(C_141_A)
MASSTOR_LIST C_141_A;
# endif
{
  MASSTOR_LIST AL, AS, BL, CL, EL;

  BL = 0;
  if (C_141_A == 0) {
    return BL;
  }
  AS = C_141_A;
  do {
    DIPC_DIPMAD(AS, &AL, &EL, &AS);
    CL = SACRN_RNABS(AL);
    BL = SACRN_RNSUM(CL, BL);
  } while (!(AS == MASSTOR_SIL));
  return BL;
}

MASSTOR_LIST DIPRN_DIRPSO
# ifdef __STDC__
(MASSTOR_LIST C_140_A)
# else
(C_140_A)
MASSTOR_LIST C_140_A;
# endif
{
  MASSTOR_LIST AL, AP, B, BP, BS, EL, TL;

  if (C_140_A == 0) {
    return C_140_A;
  }
  B = MASSTOR_LIST1(0);
  BS = B;
  AP = C_140_A;
  do {
    DIPC_DIPMAD(AP, &AL, &EL, &AP);
    BP = DIPC_DIPFMO(AL, EL);
    B = MASSTOR_COMP(BP, B);
  } while (!(AP == MASSTOR_SIL));
  MASSTOR_ADV(B, &BP, &B);
  MASSTOR_SFIRST(BS, BP);
  MASSTOR_SRED(BS, B);
  B = DIPRN_DIRPLS(B);
  return B;
}

MASSTOR_LIST DIPRN_DIRPSU
# ifdef __STDC__
(MASSTOR_LIST C_139_A, MASSTOR_LIST IL, MASSTOR_LIST B)
# else
(C_139_A, IL, B)
MASSTOR_LIST C_139_A, IL, B;
# endif
{
  MASSTOR_LIST AP, BP, BS, C, D, E, EL1, EL2, ES, J1Y, RL;

  if (C_139_A == 0) {
    E = 0;
    return E;
  }
  if (B == 0) {
    E = DIPC_DIPTCS(C_139_A, IL);
    return E;
  }
  BS = B;
  E = MASSTOR_LIST1(0);
  ES = E;
  AP = C_139_A;
  do {
    DIPC_DIPADV(AP, IL, &EL1, &EL2, &D, &AP);
    while (AP != 0 && EL1 > EL2) {
      J1Y = EL1 - EL2;
      BP = DIPRN_DIRPEX(BS, J1Y);
      D = DIPRN_DIRPPR(D, BP);
      DIPC_DIPADV(AP, IL, &EL1, &EL2, &C, &AP);
      D = DIPRN_DIRPSM(D, C);
    }
    BP = DIPRN_DIRPEX(BS, EL1);
    D = DIPRN_DIRPPR(D, BP);
    E = MASSTOR_COMP(D, E);
  } while (!(AP == 0));
  MASSTOR_ADV(E, &D, &E);
  MASSTOR_SFIRST(ES, D);
  MASSTOR_SRED(ES, E);
  E = DIPRN_DIRPLS(E);
  return E;
}

MASSTOR_LIST DIPRN_DIRPSV
# ifdef __STDC__
(MASSTOR_LIST C_138_A, MASSTOR_LIST B)
# else
(C_138_A, B)
MASSTOR_LIST C_138_A, B;
# endif
{
  MASSTOR_LIST AP, BP, C, D, EL1, EL2, J1Y;

  if (C_138_A == 0) {
    C = 0;
    return C;
  }
  if (B == 0) {
    C = DIPC_DIPTCF(C_138_A);
    return C;
  }
  DIPC_DIPADM(C_138_A, &EL1, &EL2, &C, &AP);
  while (AP != 0) {
    J1Y = EL1 - EL2;
    BP = DIPRN_DIRPEX(B, J1Y);
    C = DIPRN_DIRPPR(C, BP);
    DIPC_DIPADM(AP, &EL1, &EL2, &D, &AP);
    C = DIPRN_DIRPSM(C, D);
  }
  BP = DIPRN_DIRPEX(B, EL1);
  C = DIPRN_DIRPPR(C, BP);
  return C;
}

MASSTOR_LIST DIPRN_DIRPTM
# ifdef __STDC__
(MASSTOR_LIST C_137_A, MASSTOR_LIST HL)
# else
(C_137_A, HL)
MASSTOR_LIST C_137_A, HL;
# endif
{
  MASSTOR_LIST AL, ALQ, AS, B, B1, B2, EL, ELS, IL;

  if (C_137_A == 0 || HL == 0) {
    B = C_137_A;
    return B;
  }
  DIPC_DIPADM(C_137_A, &EL, &ELS, &AL, &AS);
  B = DIPC_DIPCMP(0, AL);
  for (;;) {
    {
      LONGINT B_7 = 1, B_8 = EL - ELS;

      if (B_7 <= B_8)
        for (IL = B_7;; IL += 1) {
          B1 = DIPC_DIPMPM(B, 1);
          B2 = DIPRN_DIRPRP(B, HL);
          B = DIPRN_DIRPSM(B1, B2);
          if (IL >= B_8) break;
        }
    }
    if (AS == 0) {
      return B;
    }
    DIPC_DIPADM(AS, &EL, &ELS, &AL, &AS);
    ALQ = DIPC_DIPCMP(0, AL);
    B = DIPRN_DIRPSM(B, ALQ);
  } EXIT_3:;
  return B;
}

MASSTOR_LIST DIPRN_DIRPTR
# ifdef __STDC__
(MASSTOR_LIST C_136_A, MASSTOR_LIST HL, MASSTOR_LIST IL)
# else
(C_136_A, HL, IL)
MASSTOR_LIST C_136_A, HL, IL;
# endif
{
  MASSTOR_LIST AL, AS, B, BS, C, C1, C2, EL1, EL2, KL, RL;

  if (C_136_A == 0 || HL == 0) {
    B = C_136_A;
    return B;
  }
  AS = C_136_A;
  B = MASSTOR_LIST1(0);
  BS = B;
  do {
    DIPC_DIPADS(AS, IL, 0, &EL1, &EL2, &C, &AS);
    while (AS != 0 && EL1 > EL2) {
      {
        LONGINT B_9 = 1, B_10 = EL1 - EL2;

        if (B_9 <= B_10)
          for (KL = B_9;; KL += 1) {
            C1 = DIPC_DIPMPV(C, IL, 1);
            C2 = DIPRN_DIRPRP(C, HL);
            C = DIPRN_DIRPSM(C1, C2);
            if (KL >= B_10) break;
          }
      }
      DIPC_DIPADS(AS, IL, 0, &EL1, &EL2, &AL, &AS);
      C = DIPRN_DIRPSM(C, AL);
    }
    {
      LONGINT B_11 = 1, B_12 = EL1;

      if (B_11 <= B_12)
        for (KL = B_11;; KL += 1) {
          C1 = DIPC_DIPMPV(C, IL, 1);
          C2 = DIPRN_DIRPRP(C, HL);
          C = DIPRN_DIRPSM(C1, C2);
          if (KL >= B_12) break;
        }
    }
    B = MASSTOR_COMP(C, B);
  } while (!(AS == 0));
  MASSTOR_ADV(B, &C, &B);
  MASSTOR_SFIRST(BS, C);
  MASSTOR_SRED(BS, B);
  B = DIPRN_DIRPLS(B);
  return B;
}

void DIPRN_DIRPWR
# ifdef __STDC__
(MASSTOR_LIST C_135_A, MASSTOR_LIST V, MASSTOR_LIST S)
# else
(C_135_A, V, S)
MASSTOR_LIST C_135_A, V, S;
# endif
{
  MASSTOR_LIST AL, AS, E, EL, ES, FL, J1Y, LL, R1, RL, SL, TL, VL, VS;

  if (C_135_A == 0) {
    if (S < 0) {
      SACRN_RNWRIT(C_135_A);
    } else {
      MASRN_RNDWR(C_135_A, S);
    }
    return;
  }
  RL = DIPC_DIPNOV(C_135_A);
  if (RL == 0) {
    AL = DIPC_DIPLBC(C_135_A);
    if (S < 0) {
      SACRN_RNWRIT(AL);
    } else {
      MASRN_RNDWR(AL, S);
    }
    return;
  }
  AS = C_135_A;
  FL = 0;
  J1Y = -1;
  R1 = SACRN_RNINT(J1Y);
  LL = DIPC_DIPNBC(C_135_A);
  if (LL > 1) {
    MASBIOS_SWRITE("(", 1L);
  }
  do {
    DIPC_DIPMAD(AS, &AL, &E, &AS);
    MASBIOS_SWRITE(" ", 1L);
    SL = SACRN_RNSIGN(AL);
    if (SL > 0 && FL != 0) {
      MASBIOS_SWRITE("+", 1L);
    }
    FL = 1;
    TL = DIPC_EVSIGN(E);
    if (TL == 0) {
      if (S >= 0) {
        MASRN_RNDWR(AL, S);
      } else {
        SACRN_RNWRIT(AL);
      }
    } else {
      TL = MASRN_RNONE(AL);
      if (SACRN_RNCOMP(R1, AL) == 0) {
        MASBIOS_SWRITE("-", 1L);
        TL = 1;
      }
      if (TL != 1) {
        if (S >= 0) {
          MASRN_RNDWR(AL, S);
        } else {
          SACRN_RNWRIT(AL);
        }
      }
      ES = SACLIST_CINV(E);
      VS = V;
      do {
        MASSTOR_ADV(ES, &EL, &ES);
        MASSTOR_ADV(VS, &VL, &VS);
        if (EL > 0) {
          MASBIOS_SWRITE(" ", 1L);
          SACLIST_CLOUT(VL);
          if (EL > 1) {
            MASBIOS_SWRITE("**", 2L);
            SACLIST_AWRITE(EL);
          }
        }
      } while (!(ES == MASSTOR_SIL));
    }
  } while (!(AS == MASSTOR_SIL));
  MASBIOS_SWRITE(" ", 1L);
  if (LL > 1) {
    MASBIOS_SWRITE(")", 1L);
  }
  return;
}

void DIPRN_DIRPWV
# ifdef __STDC__
(MASSTOR_LIST C_134_A)
# else
(C_134_A)
MASSTOR_LIST C_134_A;
# endif
{
  MASSTOR_LIST RL, VL;

  RL = DIPC_DIPNOV(C_134_A);
  VL = DIPC_STVL(RL);
  DIPRN_DIRPWR(C_134_A, VL, -1);
  return;
}

MASSTOR_LIST DIPRN_DIRRAS
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST KL, MASSTOR_LIST LL, MASSTOR_LIST EL, MASSTOR_LIST QL)
# else
(RL, KL, LL, EL, QL)
MASSTOR_LIST RL, KL, LL, EL, QL;
# endif
{
  MASSTOR_LIST C_133_A, AL, AP, FL, IL, QL1, QL2, QLP, TL;

  C_133_A = 0;
  if (RL == 0) {
    AL = SACI_IRAND(KL);
    C_133_A = DIPC_DIPFMO(AL, MASSTOR_BETA);
    return C_133_A;
  }
  SACLIST_FIRST2(QL, &QL1, &QL2);
  SACD_DQR(QL1, 0, QL2, &QLP, &TL);
  {
    LONGINT B_13 = 1, B_14 = LL;

    if (B_13 <= B_14)
      for (IL = B_13;; IL += 1) {
        AL = SACRN_RNRAND(KL);
        if (AL != 0) {
          FL = DIPC_EVRASP(RL, EL, QLP);
          AP = DIPC_DIPFMO(AL, FL);
          C_133_A = DIPRN_DIRPSM(C_133_A, AP);
        }
        if (IL >= B_14) break;
      }
  }
  return C_133_A;
}

void BEGIN_DIPRN()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_MASERR();
    BEGIN_MASBIOS();
    BEGIN_SACLIST();
    BEGIN_SACD();
    BEGIN_SACI();
    BEGIN_SACRN();
    BEGIN_SACPOL();
    BEGIN_MASRN();
    BEGIN_DIPC();

  }
}
