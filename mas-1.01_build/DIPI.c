#include "SYSTEM_.h"

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

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

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_MASI
#include "MASI.h"
#endif

#ifndef DEFINITION_DIPI
#include "DIPI.h"
#endif

CHAR DIPI_rcsid [] = "$Id: DIPI.md,v 1.3 1993/03/23 12:58:55 kredel Exp $";
CHAR DIPI_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: DIPI.mi,v 1.5 1995/11/05 09:17:21 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST DIPI_DIIFRP
# ifdef __STDC__
(MASSTOR_LIST C_171_A)
# else
(C_171_A)
MASSTOR_LIST C_171_A;
# endif
{
  MASSTOR_LIST AL, AL1, ALP, AP, B, BL, CL, EL, SL;

  if (C_171_A == 0) {
    B = 0;
    return B;
  }
  DIPC_DIPMAD(C_171_A, &AL1, &EL, &AP);
  SL = SACRN_RNSIGN(AL1);
  BL = SACRN_RNDEN(AL1);
  while (AP != MASSTOR_SIL) {
    DIPC_DIPMAD(AP, &AL1, &EL, &AP);
    AL = SACRN_RNDEN(AL1);
    BL = SACI_ILCM(BL, AL);
  }
  if (SL < 0) {
    BL = SACI_INEG(BL);
  }
  B = MASSTOR_BETA;
  AP = C_171_A;
  while (AP != MASSTOR_SIL) {
    DIPC_DIPMAD(AP, &AL1, &EL, &AP);
    SACLIST_FIRST2(AL1, &CL, &AL);
    ALP = SACI_IQ(BL, AL);
    CL = MASI_IPROD(CL, ALP);
    B = DIPC_DIPMCP(EL, CL, B);
  }
  B = MASSTOR_INV(B);
  DIPI_DIIPCP(B, &CL, &B);
  return B;
}

MASSTOR_LIST DIPI_DIILFR
# ifdef __STDC__
(MASSTOR_LIST C_170_A)
# else
(C_170_A)
MASSTOR_LIST C_170_A;
# endif
{
  MASSTOR_LIST AP, AL, B, BL;

  AP = C_170_A;
  B = MASSTOR_SIL;
  while (AP != MASSTOR_SIL) {
    MASSTOR_ADV(AP, &AL, &AP);
    BL = DIPI_DIIFRP(AL);
    B = MASSTOR_COMP(BL, B);
  }
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST DIPI_DIILFRCD
# ifdef __STDC__
(MASSTOR_LIST C_169_A)
# else
(C_169_A)
MASSTOR_LIST C_169_A;
# endif
{
  MASSTOR_LIST AL, AL1, ALP, AP, B, BP, BL, CL, EL, SL, C, CP;

  C = C_169_A;
  CP = C;
  BL = 1;
  while (CP != MASSTOR_SIL) {
    MASSTOR_ADV(CP, &AP, &CP);
    if (AP == 0) {
      AP = MASSTOR_SIL;
    }
    while (AP != MASSTOR_SIL) {
      DIPC_DIPMAD(AP, &AL1, &EL, &AP);
      AL = SACRN_RNDEN(AL1);
      BL = SACI_ILCM(BL, AL);
    }
  }
  CP = C;
  BP = MASSTOR_SIL;
  while (CP != MASSTOR_SIL) {
    MASSTOR_ADV(CP, &AP, &CP);
    if (AP == 0) {
      AP = MASSTOR_SIL;
    }
    B = MASSTOR_SIL;
    while (AP != MASSTOR_SIL) {
      DIPC_DIPMAD(AP, &AL1, &EL, &AP);
      SACLIST_FIRST2(AL1, &CL, &AL);
      ALP = SACI_IQ(BL, AL);
      CL = MASI_IPROD(CL, ALP);
      B = DIPC_DIPMCP(EL, CL, B);
    }
    B = MASSTOR_INV(B);
    if (B == MASSTOR_SIL) {
      B = 0;
    }
    BP = MASSTOR_COMP(B, BP);
  }
  BP = MASSTOR_INV(BP);
  return BP;
}

MASSTOR_LIST DIPI_DIILRD
# ifdef __STDC__
(MASSTOR_LIST V)
# else
(V)
MASSTOR_LIST V;
# endif
{
  MASSTOR_LIST C_168_A, AL, C;

  C_168_A = MASSTOR_BETA;
  C = MASBIOS_CREADB();
  if (C != MASBIOS_MASORD('(')) {
    MASERR_ERROR(MASERR_severe, "DIILRD ( expected.", 18L);
    return C_168_A;
  }
  do {
    C = MASBIOS_CREADB();
    if (C == MASBIOS_MASORD(',')) {
      C = MASBIOS_CREADB();
    }
    if (C != MASBIOS_MASORD(')')) {
      MASBIOS_BKSP();
      AL = DIPI_DIIPRD(V);
      C_168_A = MASSTOR_COMP(AL, C_168_A);
    }
  } while (!(C == MASBIOS_MASORD(')')));
  C_168_A = MASSTOR_INV(C_168_A);
  return C_168_A;
}

void DIPI_DIILWR
# ifdef __STDC__
(MASSTOR_LIST C_167_A, MASSTOR_LIST V)
# else
(C_167_A, V)
MASSTOR_LIST C_167_A, V;
# endif
{
  MASSTOR_LIST AL, AP, OS, LS, RS;

  MASBIOS_BLINES(0);
  OS = -1;
  LS = 10;
  RS = 60;
  MASBIOS_SOLINE(&OS, &LS, &RS);
  AP = C_167_A;
  while (AP != MASSTOR_SIL) {
    MASSTOR_ADV(AP, &AL, &AP);
    DIPI_DIIPWR(AL, V);
    MASBIOS_BLINES(0);
  }
  MASBIOS_SOLINE(&OS, &LS, &RS);
  return;
}

MASSTOR_LIST DIPI_DIIPAB
# ifdef __STDC__
(MASSTOR_LIST C_166_A)
# else
(C_166_A)
MASSTOR_LIST C_166_A;
# endif
{
  MASSTOR_LIST B, SL;

  SL = DIPI_DIIPSG(C_166_A);
  if (SL >= 0) {
    B = C_166_A;
  } else {
    B = DIPI_DIIPNG(C_166_A);
  }
  return B;
}

void DIPI_DIIPCP
# ifdef __STDC__
(MASSTOR_LIST C_165_A, MASSTOR_LIST *CL, MASSTOR_LIST *AP)
# else
(C_165_A, CL, AP)
MASSTOR_LIST C_165_A;
MASSTOR_LIST *CL, *AP;
# endif
{
  MASSTOR_LIST AL, DL, EL, SL;

  if (C_165_A == 0) {
    *CL = 0;
    *AP = C_165_A;
    return;
  }
  DIPC_DIPMAD(C_165_A, &DL, &EL, AP);
  SL = SACI_ISIGNF(DL);
  if (SL < 0) {
    DL = SACI_INEG(DL);
  }
  while (*AP != MASSTOR_SIL && DL != 1) {
    DIPC_DIPMAD(*AP, &AL, &EL, AP);
    DL = SACI_IGCD(DL, AL);
  }
  *CL = DL;
  *AP = C_165_A;
  if (DL == 1) {
    if (SL < 0) {
      *CL = -DL;
      *AP = DIPI_DIIPNG(C_165_A);
    }
  } else {
    if (SL < 0) {
      *CL = SACI_INEG(DL);
    }
    *AP = DIPI_DIIPIQ(C_165_A, *CL);
  }
  return;
}

MASSTOR_LIST DIPI_DIIPDF
# ifdef __STDC__
(MASSTOR_LIST C_164_A, MASSTOR_LIST B)
# else
(C_164_A, B)
MASSTOR_LIST C_164_A, B;
# endif
{
  MASSTOR_LIST AL, AP, APP, BL, BP, C, CL, CP, CPP, EL, FL, SL;

  if (C_164_A == 0) {
    C = DIPI_DIIPNG(B);
    return C;
  }
  if (B == 0) {
    C = C_164_A;
    return C;
  }
  AP = C_164_A;
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
        CL = SACI_INEG(BL);
        CP = DIPC_DIPMCP(FL, CL, CP);
      } else {
        DIPC_DIPMAD(AP, &AL, &EL, &AP);
        DIPC_DIPMAD(BP, &BL, &FL, &BP);
        CL = SACI_IDIF(AL, BL);
        if (CL != 0) {
          CP = DIPC_DIPMCP(EL, CL, CP);
        }
      }
    }
  } while (!(AP == MASSTOR_SIL || BP == MASSTOR_SIL));
  APP = AP;
  if (AP == MASSTOR_SIL) {
    if (BP != MASSTOR_SIL) {
      APP = DIPI_DIIPNG(BP);
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

MASSTOR_LIST DIPI_DIIPDM
# ifdef __STDC__
(MASSTOR_LIST C_163_A)
# else
(C_163_A)
MASSTOR_LIST C_163_A;
# endif
{
  MASSTOR_LIST AL, ALP, AS, B, EL, EL1, EL2, ELS, FL;

  if (C_163_A == 0) {
    B = 0;
    return B;
  }
  if (DIPC_DIPEVL(C_163_A) == MASSTOR_SIL) {
    B = 0;
    return B;
  }
  AS = C_163_A;
  B = MASSTOR_BETA;
  do {
    DIPC_DIPMAD(AS, &AL, &EL, &AS);
    MASSTOR_ADV(EL, &EL1, &ELS);
    if (EL1 > 0) {
      ALP = MASI_IPROD(AL, EL1);
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

MASSTOR_LIST DIPI_DIIPDR
# ifdef __STDC__
(MASSTOR_LIST C_162_A, MASSTOR_LIST IL)
# else
(C_162_A, IL)
MASSTOR_LIST C_162_A, IL;
# endif
{
  MASSTOR_LIST AL, ALP, AS, B, EL, ELP, FL, J1Y, JL, KL, RL;

  if (C_162_A == 0) {
    B = 0;
    return B;
  }
  RL = DIPC_DIPNOV(C_162_A);
  KL = 1;
  J1Y = RL - IL;
  JL = J1Y + 1;
  AS = C_162_A;
  B = MASSTOR_BETA;
  do {
    DIPC_DIPMAD(AS, &AL, &EL, &AS);
    DIPC_EVDER(EL, JL, KL, &ELP, &FL);
    if (FL != 0) {
      ALP = MASI_IPROD(AL, FL);
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

MASSTOR_LIST DIPI_DIIPEM
# ifdef __STDC__
(MASSTOR_LIST C_161_A, MASSTOR_LIST AL)
# else
(C_161_A, AL)
MASSTOR_LIST C_161_A, AL;
# endif
{
  MASSTOR_LIST B, EL1, EL2, C, AP, J1Y, ALP;

  if (C_161_A == 0) {
    B = 0;
    return B;
  }
  DIPC_DIPADM(C_161_A, &EL1, &EL2, &B, &AP);
  while (AP != 0) {
    J1Y = EL1 - EL2;
    ALP = SACI_IEXP(AL, J1Y);
    B = DIPI_DIIPIP(B, ALP);
    DIPC_DIPADM(AP, &EL1, &EL2, &C, &AP);
    B = DIPI_DIIPSM(B, C);
  }
  ALP = SACI_IEXP(AL, EL1);
  B = DIPI_DIIPIP(B, ALP);
  return B;
}

MASSTOR_LIST DIPI_DIIPEV
# ifdef __STDC__
(MASSTOR_LIST C_160_A, MASSTOR_LIST IL, MASSTOR_LIST AL)
# else
(C_160_A, IL, AL)
MASSTOR_LIST C_160_A, IL, AL;
# endif
{
  MASSTOR_LIST ALP, AP, B, BS, C, D, EL1, EL2, J1Y, RL;

  if (C_160_A == 0) {
    B = 0;
    return B;
  }
  B = MASSTOR_LIST1(0);
  BS = B;
  B = 0;
  AP = C_160_A;
  do {
    DIPC_DIPADV(AP, IL, &EL1, &EL2, &D, &AP);
    while (AP != 0 && EL1 > EL2) {
      J1Y = EL1 - EL2;
      ALP = SACI_IEXP(AL, J1Y);
      D = DIPI_DIIPIP(D, ALP);
      DIPC_DIPADV(AP, IL, &EL1, &EL2, &C, &AP);
      D = DIPI_DIIPSM(D, C);
    }
    ALP = SACI_IEXP(AL, EL1);
    D = DIPI_DIIPIP(D, ALP);
    B = MASSTOR_COMP(D, B);
  } while (!(AP == 0));
  MASSTOR_ADV(B, &D, &B);
  MASSTOR_SFIRST(BS, D);
  MASSTOR_SRED(BS, B);
  B = DIPI_DIIPLS(B);
  return B;
}

MASSTOR_LIST DIPI_DIIPEX
# ifdef __STDC__
(MASSTOR_LIST C_159_A, MASSTOR_LIST NL)
# else
(C_159_A, NL)
MASSTOR_LIST C_159_A, NL;
# endif
{
  MASSTOR_LIST B, BL, I, RL;

  if (NL == 0) {
    RL = DIPC_DIPNOV(C_159_A);
    BL = DIPC_DIPFMO(1, MASSTOR_BETA);
    B = DIPC_DIPINV(BL, 0, RL);
    return B;
  }
  if (C_159_A == 0) {
    B = 0;
    return B;
  }
  B = C_159_A;
  {
    LONGINT B_1 = 1, B_2 = NL - 1;

    if (B_1 <= B_2)
      for (I = B_1;; I += 1) {
        B = DIPI_DIIPPR(B, C_159_A);
        if (I >= B_2) break;
      }
  }
  return B;
}

MASSTOR_LIST DIPI_DIIPHD
# ifdef __STDC__
(MASSTOR_LIST C_158_A, MASSTOR_LIST IL, MASSTOR_LIST NL)
# else
(C_158_A, IL, NL)
MASSTOR_LIST C_158_A, IL, NL;
# endif
{
  MASSTOR_LIST AL, ALP, AS, B, EL, ELP, FL, J1Y, JL, RL;

  if (C_158_A == 0) {
    B = 0;
    return B;
  }
  RL = DIPC_DIPNOV(C_158_A);
  J1Y = RL - IL;
  JL = J1Y + 1;
  AS = C_158_A;
  B = MASSTOR_BETA;
  do {
    DIPC_DIPMAD(AS, &AL, &EL, &AS);
    DIPC_EVDER(EL, JL, NL, &ELP, &FL);
    if (FL != 0) {
      ALP = MASI_IPROD(AL, FL);
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

MASSTOR_LIST DIPI_DIIPIP
# ifdef __STDC__
(MASSTOR_LIST C_157_A, MASSTOR_LIST BL)
# else
(C_157_A, BL)
MASSTOR_LIST C_157_A, BL;
# endif
{
  MASSTOR_LIST AL, AP, C, EL, PL;

  if (C_157_A == 0 || BL == 0) {
    C = 0;
    return C;
  }
  C = MASSTOR_BETA;
  AP = C_157_A;
  do {
    DIPC_DIPMAD(AP, &AL, &EL, &AP);
    PL = MASI_IPROD(AL, BL);
    C = DIPC_DIPMCP(EL, PL, C);
  } while (!(AP == MASSTOR_SIL));
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST DIPI_DIIPIQ
# ifdef __STDC__
(MASSTOR_LIST C_156_A, MASSTOR_LIST BL)
# else
(C_156_A, BL)
MASSTOR_LIST C_156_A, BL;
# endif
{
  MASSTOR_LIST AL, AP, C, EL, QL, RL;

  if (C_156_A == 0) {
    C = 0;
    return C;
  }
  C = MASSTOR_BETA;
  AP = C_156_A;
  do {
    DIPC_DIPMAD(AP, &AL, &EL, &AP);
    SACI_IQR(AL, BL, &QL, &RL);
    C = DIPC_DIPMCP(EL, QL, C);
  } while (!(AP == MASSTOR_SIL));
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST DIPI_DIIPLS
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
    BPP = DIPI_DIIPSM(B, BP);
    MASSTOR_SFIRST(C, BPP);
    MASSTOR_SRED(C, CPP);
    C = CPP;
    MASSTOR_ADV(C, &B, &CP);
  }
  return B;
}

MASSTOR_LIST DIPI_DIIPMN
# ifdef __STDC__
(MASSTOR_LIST C_154_A)
# else
(C_154_A)
MASSTOR_LIST C_154_A;
# endif
{
  MASSTOR_LIST AL, AS, BL, CL, EL;

  BL = 0;
  if (C_154_A == 0) {
    return BL;
  }
  AS = C_154_A;
  do {
    DIPC_DIPMAD(AS, &AL, &EL, &AS);
    CL = SACI_IABSF(AL);
    BL = SACI_IMAX(CL, BL);
  } while (!(AS == MASSTOR_SIL));
  return BL;
}

MASSTOR_LIST DIPI_DIIPNG
# ifdef __STDC__
(MASSTOR_LIST C_153_A)
# else
(C_153_A)
MASSTOR_LIST C_153_A;
# endif
{
  MASSTOR_LIST AL, AS, B, BL, EL;

  if (C_153_A == 0) {
    B = 0;
    return B;
  }
  AS = C_153_A;
  B = MASSTOR_BETA;
  do {
    DIPC_DIPMAD(AS, &AL, &EL, &AS);
    BL = SACI_INEG(AL);
    B = DIPC_DIPMCP(EL, BL, B);
  } while (!(AS == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST DIPI_DIIPON
# ifdef __STDC__
(MASSTOR_LIST C_152_A)
# else
(C_152_A)
MASSTOR_LIST C_152_A;
# endif
{
  MASSTOR_LIST AL, AS, EL, FL, TL;

  TL = 0;
  if (C_152_A == 0) {
    return TL;
  }
  DIPC_DIPMAD(C_152_A, &AL, &EL, &AS);
  if (AL != 1 || AS != MASSTOR_SIL) {
    return TL;
  }
  FL = DIPC_EVSIGN(EL);
  if (FL == 0) {
    TL = 1;
  }
  return TL;
}

MASSTOR_LIST DIPI_DIIPPR
# ifdef __STDC__
(MASSTOR_LIST C_151_A, MASSTOR_LIST B)
# else
(C_151_A, B)
MASSTOR_LIST C_151_A, B;
# endif
{
  MASSTOR_LIST AL, AP, AS, BL, BS, C, C1, CL, CS, EL, FL, GL;

  if (C_151_A == 0 || B == 0) {
    C = 0;
    return C;
  }
  AS = SACLIST_CINV(C_151_A);
  BS = B;
  C = MASSTOR_LIST1(0);
  CS = C;
  do {
    DIPC_DIPMAD(BS, &BL, &FL, &BS);
    AP = AS;
    C1 = MASSTOR_BETA;
    do {
      DIPC_DIPMAD(AP, &EL, &AL, &AP);
      CL = MASI_IPROD(AL, BL);
      GL = DIPC_EVSUM(EL, FL);
      C1 = DIPC_DIPMCP(CL, GL, C1);
    } while (!(AP == MASSTOR_SIL));
    C = MASSTOR_COMP(C1, C);
  } while (!(BS == MASSTOR_SIL));
  MASSTOR_ADV(C, &C1, &C);
  MASSTOR_SFIRST(CS, C1);
  MASSTOR_SRED(CS, C);
  C = DIPI_DIIPLS(C);
  return C;
}

MASSTOR_LIST DIPI_DIIPPS
# ifdef __STDC__
(MASSTOR_LIST C_150_A, MASSTOR_LIST B)
# else
(C_150_A, B)
MASSTOR_LIST C_150_A, B;
# endif
{
  MASSTOR_LIST B1, BP, BS, C, C1, CL, FL, IL, J1Y, LL, LLP, ML, NL;

  NL = DIPC_DIPDEG(B);
  if (NL == 0) {
    C = 0;
    return C;
  }
  ML = DIPC_DIPDEG(C_150_A);
  C = C_150_A;
  DIPC_DIPADM(B, &NL, &FL, &BS, &BP);
  B1 = DIPC_DIPCMP(0, BS);
  {
    LONGINT B_3 = ML, B_4 = NL;

    if (B_3 >= B_4)
      for (IL = B_3;; IL += -1) {
        if (C == 0) {
          return C;
        }
        LL = DIPC_DIPDEG(C);
        if (LL == IL) {
          DIPC_DIPADM(C, &LLP, &FL, &CL, &C);
          C = DIPI_DIIPPR(C, B1);
          J1Y = LL - NL;
          C1 = DIPC_DIPCMP(J1Y, CL);
          BS = DIPI_DIIPPR(BP, C1);
          C = DIPI_DIIPDF(C, BS);
        } else {
          C = DIPI_DIIPPR(C, B1);
        }
        if (IL <= B_4) break;
      }
  }
  return C;
}

MASSTOR_LIST DIPI_DIIPQ
# ifdef __STDC__
(MASSTOR_LIST C_149_A, MASSTOR_LIST B)
# else
(C_149_A, B)
MASSTOR_LIST C_149_A, B;
# endif
{
  MASSTOR_LIST C, R;

  DIPI_DIIPQR(C_149_A, B, &C, &R);
  return C;
}

void DIPI_DIIPQR
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
    SACI_IQR(AL, BL, &QL, &SL);
    if (SL != 0) {
      goto EXIT_1;
    }
    *Q = DIPC_DIPMCP(DL, QL, *Q);
    Q1 = DIPC_DIPFMO(QL, DL);
    RP = DIPC_DIPMRD(*R);
    QP = DIPI_DIIPPR(BP, Q1);
    *R = DIPI_DIIPDF(RP, QP);
  } EXIT_1:;
  if (*Q == MASSTOR_SIL) {
    *Q = 0;
  } else {
    *Q = MASSTOR_INV(*Q);
  }
  return;
}

MASSTOR_LIST DIPI_DIIPRA
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
    AL = SACI_IRAND(KL);
    C_147_A = DIPC_DIPFMO(AL, MASSTOR_BETA);
    return C_147_A;
  }
  {
    LONGINT B_5 = 1, B_6 = LL;

    if (B_5 <= B_6)
      for (IL = B_5;; IL += 1) {
        AL = SACI_IRAND(KL);
        if (AL != 0) {
          FL = DIPC_EVRAND(RL, EL);
          AP = DIPC_DIPFMO(AL, FL);
          C_147_A = DIPI_DIIPSM(C_147_A, AP);
        }
        if (IL >= B_6) break;
      }
  }
  return C_147_A;
}

MASSTOR_LIST DIPI_DIIPRD
# ifdef __STDC__
(MASSTOR_LIST V)
# else
(V)
MASSTOR_LIST V;
# endif
{
  MASSTOR_LIST C_146_A, A1, AL, AP, C, EL, ES, FL, IL, JL, RL, VL;

  C_146_A = 0;
  C = MASBIOS_CREADB();
  if (C == 0) {
    return C_146_A;
  }
  MASBIOS_BKSP();
  C = MASBIOS_CREADB();
  MASBIOS_BKSP();
  if (C == MASBIOS_MASORD(',')) {
    MASERR_ERROR(MASERR_severe, "DIIPRD no , expected.", 21L);
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
      MASERR_ERROR(MASERR_severe, "DIIPRD no ) expected.", 21L);
      return C_146_A;
    }
  }
  RL = MASSTOR_LENGTH(V);
  ES = MASSTOR_BETA;
  {
    LONGINT B_7 = 1, B_8 = RL;

    if (B_7 <= B_8)
      for (IL = B_7;; IL += 1) {
        ES = MASSTOR_COMP(0, ES);
        if (IL >= B_8) break;
      }
  }
  A1 = DIPC_DIPFMO(1, ES);
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
      AP = DIPI_DIIPNG(AP);
    }
    if (C == MASBIOS_MASORD('+') || C == MASBIOS_MASORD('-')) {
      C = MASBIOS_CREADB();
    }
    if (C == MASBIOS_MASORD('*')) {
      C = MASBIOS_CREADB();
    }
    MASBIOS_BKSP();
    if (MASBIOS_DIGIT(C)) {
      AL = SACI_IREAD();
      EL = DIPC_EPREAD();
      AL = SACI_IEXP(AL, EL);
      AP = DIPI_DIIPIP(AP, AL);
    } else if (C == MASBIOS_MASORD('(')) {
      AL = DIPI_DIIPRD(V);
      EL = DIPC_EPREAD();
      AL = DIPI_DIIPEX(AL, EL);
      AP = DIPI_DIIPPR(AP, AL);
    } else if (MASBIOS_LETTER(C)) {
      VL = SACPOL_VREAD();
      JL = SACPOL_VLSRCH(VL, V);
      if (JL == 0) {
        DIPC_BACKUB();
        C_146_A = DIPI_DIIPSM(C_146_A, AP);
        return C_146_A;
      }
      EL = DIPC_EPREAD();
      AP = DIPC_DIPMPV(AP, JL, EL);
    }
    C = MASBIOS_CREADB();
    MASBIOS_BKSP();
    if (C == MASBIOS_MASORD('+') || C == MASBIOS_MASORD('-') || C == MASBIOS_MASORD(')') || C == MASBIOS_MASORD(',')) {
      C_146_A = DIPI_DIIPSM(C_146_A, AP);
      AP = A1;
    }
  } EXIT_2:;
}

MASSTOR_LIST DIPI_DIIPSG
# ifdef __STDC__
(MASSTOR_LIST C_145_A)
# else
(C_145_A)
MASSTOR_LIST C_145_A;
# endif
{
  MASSTOR_LIST J1Y, SL;

  if (C_145_A == 0) {
    SL = 0;
  } else {
    J1Y = DIPC_DIPLBC(C_145_A);
    SL = SACI_ISIGNF(J1Y);
  }
  return SL;
}

MASSTOR_LIST DIPI_DIIPSM
# ifdef __STDC__
(MASSTOR_LIST C_144_A, MASSTOR_LIST B)
# else
(C_144_A, B)
MASSTOR_LIST C_144_A, B;
# endif
{
  MASSTOR_LIST AL, AP, APP, BL, BP, C, CL, CP, CPP, EL, FL, SL;

  if (C_144_A == 0) {
    C = B;
    return C;
  }
  if (B == 0) {
    C = C_144_A;
    return C;
  }
  AP = C_144_A;
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
        CL = SACI_ISUM(AL, BL);
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

MASSTOR_LIST DIPI_DIIPSN
# ifdef __STDC__
(MASSTOR_LIST C_143_A)
# else
(C_143_A)
MASSTOR_LIST C_143_A;
# endif
{
  MASSTOR_LIST AL, AS, BL, CL, EL;

  BL = 0;
  if (C_143_A == 0) {
    return BL;
  }
  AS = C_143_A;
  do {
    DIPC_DIPMAD(AS, &AL, &EL, &AS);
    CL = SACI_IABSF(AL);
    BL = SACI_ISUM(CL, BL);
  } while (!(AS == MASSTOR_SIL));
  return BL;
}

MASSTOR_LIST DIPI_DIIPSO
# ifdef __STDC__
(MASSTOR_LIST C_142_A)
# else
(C_142_A)
MASSTOR_LIST C_142_A;
# endif
{
  MASSTOR_LIST AL, AP, B, BP, BS, EL, TL;

  if (C_142_A == 0) {
    return B;
  }
  B = MASSTOR_LIST1(0);
  BS = B;
  AP = C_142_A;
  do {
    DIPC_DIPMAD(AP, &AL, &EL, &AP);
    BP = DIPC_DIPFMO(AL, EL);
    B = MASSTOR_COMP(BP, B);
  } while (!(AP == MASSTOR_SIL));
  MASSTOR_ADV(B, &BP, &B);
  MASSTOR_SFIRST(BS, BP);
  MASSTOR_SRED(BS, B);
  B = DIPI_DIIPLS(B);
  return B;
}

MASSTOR_LIST DIPI_DIIPSU
# ifdef __STDC__
(MASSTOR_LIST C_141_A, MASSTOR_LIST IL, MASSTOR_LIST B)
# else
(C_141_A, IL, B)
MASSTOR_LIST C_141_A, IL, B;
# endif
{
  MASSTOR_LIST AP, BP, BS, C, D, E, EL1, EL2, ES, J1Y, RL;

  if (C_141_A == 0) {
    E = 0;
    return E;
  }
  if (B == 0) {
    E = DIPC_DIPTCS(C_141_A, IL);
    return E;
  }
  BS = B;
  E = MASSTOR_LIST1(0);
  ES = E;
  AP = C_141_A;
  do {
    DIPC_DIPADV(AP, IL, &EL1, &EL2, &D, &AP);
    while (AP != 0 && EL1 > EL2) {
      J1Y = EL1 - EL2;
      BP = DIPI_DIIPEX(BS, J1Y);
      D = DIPI_DIIPPR(D, BP);
      DIPC_DIPADV(AP, IL, &EL1, &EL2, &C, &AP);
      D = DIPI_DIIPSM(D, C);
    }
    BP = DIPI_DIIPEX(BS, EL1);
    D = DIPI_DIIPPR(D, BP);
    E = MASSTOR_COMP(D, E);
  } while (!(AP == 0));
  MASSTOR_ADV(E, &D, &E);
  MASSTOR_SFIRST(ES, D);
  MASSTOR_SRED(ES, E);
  E = DIPI_DIIPLS(E);
  return E;
}

MASSTOR_LIST DIPI_DIIPSV
# ifdef __STDC__
(MASSTOR_LIST C_140_A, MASSTOR_LIST B)
# else
(C_140_A, B)
MASSTOR_LIST C_140_A, B;
# endif
{
  MASSTOR_LIST AP, BP, C, D, EL1, EL2, J1Y;

  if (C_140_A == 0) {
    C = 0;
    return C;
  }
  if (B == 0) {
    C = DIPC_DIPTCF(C_140_A);
    return C;
  }
  DIPC_DIPADM(C_140_A, &EL1, &EL2, &C, &AP);
  while (AP != 0) {
    J1Y = EL1 - EL2;
    BP = DIPI_DIIPEX(B, J1Y);
    C = DIPI_DIIPPR(C, BP);
    DIPC_DIPADM(AP, &EL1, &EL2, &D, &AP);
    C = DIPI_DIIPSM(C, D);
  }
  BP = DIPI_DIIPEX(B, EL1);
  C = DIPI_DIIPPR(C, BP);
  return C;
}

MASSTOR_LIST DIPI_DIIPTM
# ifdef __STDC__
(MASSTOR_LIST C_139_A, MASSTOR_LIST HL)
# else
(C_139_A, HL)
MASSTOR_LIST C_139_A, HL;
# endif
{
  MASSTOR_LIST AL, ALQ, AS, B, B1, B2, EL, ELS, IL;

  if (C_139_A == 0 || HL == 0) {
    B = C_139_A;
    return B;
  }
  DIPC_DIPADM(C_139_A, &EL, &ELS, &AL, &AS);
  B = DIPC_DIPCMP(0, AL);
  for (;;) {
    {
      LONGINT B_9 = 1, B_10 = EL - ELS;

      if (B_9 <= B_10)
        for (IL = B_9;; IL += 1) {
          B1 = DIPC_DIPMPM(B, 1);
          B2 = DIPI_DIIPIP(B, HL);
          B = DIPI_DIIPSM(B1, B2);
          if (IL >= B_10) break;
        }
    }
    if (AS == 0) {
      return B;
    }
    DIPC_DIPADM(AS, &EL, &ELS, &AL, &AS);
    ALQ = DIPC_DIPCMP(0, AL);
    B = DIPI_DIIPSM(B, ALQ);
  } EXIT_3:;
  return B;
}

MASSTOR_LIST DIPI_DIIPTR
# ifdef __STDC__
(MASSTOR_LIST C_138_A, MASSTOR_LIST HL, MASSTOR_LIST IL)
# else
(C_138_A, HL, IL)
MASSTOR_LIST C_138_A, HL, IL;
# endif
{
  MASSTOR_LIST AL, AS, B, BS, C, C1, C2, EL1, EL2, KL, RL;

  if (C_138_A == 0 || HL == 0) {
    B = C_138_A;
    return B;
  }
  AS = C_138_A;
  B = MASSTOR_LIST1(0);
  BS = B;
  do {
    DIPC_DIPADS(AS, IL, 0, &EL1, &EL2, &C, &AS);
    while (AS != 0 && EL1 > EL2) {
      {
        LONGINT B_11 = 1, B_12 = EL1 - EL2;

        if (B_11 <= B_12)
          for (KL = B_11;; KL += 1) {
            C1 = DIPC_DIPMPV(C, IL, 1);
            C2 = DIPI_DIIPIP(C, HL);
            C = DIPI_DIIPSM(C1, C2);
            if (KL >= B_12) break;
          }
      }
      DIPC_DIPADS(AS, IL, 0, &EL1, &EL2, &AL, &AS);
      C = DIPI_DIIPSM(C, AL);
    }
    {
      LONGINT B_13 = 1, B_14 = EL1;

      if (B_13 <= B_14)
        for (KL = B_13;; KL += 1) {
          C1 = DIPC_DIPMPV(C, IL, 1);
          C2 = DIPI_DIIPIP(C, HL);
          C = DIPI_DIIPSM(C1, C2);
          if (KL >= B_14) break;
        }
    }
    B = MASSTOR_COMP(C, B);
  } while (!(AS == 0));
  MASSTOR_ADV(B, &C, &B);
  MASSTOR_SFIRST(BS, C);
  MASSTOR_SRED(BS, B);
  B = DIPI_DIIPLS(B);
  return B;
}

void DIPI_DIIPWR
# ifdef __STDC__
(MASSTOR_LIST C_137_A, MASSTOR_LIST V)
# else
(C_137_A, V)
MASSTOR_LIST C_137_A, V;
# endif
{
  MASSTOR_LIST AL, AS, E, EL, ES, FL, LL, RL, SL, VL, VS;

  if (C_137_A == 0) {
    SACLIST_AWRITE(C_137_A);
    return;
  }
  RL = DIPC_DIPNOV(C_137_A);
  if (RL == 0) {
    SACI_IWRITE(DIPC_DIPLBC(C_137_A));
    return;
  }
  AS = C_137_A;
  FL = 0;
  LL = DIPC_DIPNBC(C_137_A);
  if (LL > 1) {
    MASBIOS_SWRITE("(", 1L);
  }
  do {
    DIPC_DIPMAD(AS, &AL, &E, &AS);
    MASBIOS_SWRITE(" ", 1L);
    SL = SACI_ISIGNF(AL);
    if (SL > 0 && FL != 0) {
      MASBIOS_SWRITE("+", 1L);
    }
    FL = 1;
    SL = DIPC_EVSIGN(E);
    if (SL == 0) {
      SACI_IWRITE(AL);
    } else {
      if (AL == -1) {
        MASBIOS_SWRITE("-", 1L);
        AL = 1;
      }
      if (AL != 1) {
        SACI_IWRITE(AL);
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

void DIPI_DIIPWV
# ifdef __STDC__
(MASSTOR_LIST C_136_A)
# else
(C_136_A)
MASSTOR_LIST C_136_A;
# endif
{
  MASSTOR_LIST RL, VL;

  RL = DIPC_DIPNOV(C_136_A);
  VL = DIPC_STVL(RL);
  DIPI_DIIPWR(C_136_A, VL);
  return;
}

MASSTOR_LIST DIPI_DIIRAS
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST KL, MASSTOR_LIST LL, MASSTOR_LIST EL, MASSTOR_LIST QL)
# else
(RL, KL, LL, EL, QL)
MASSTOR_LIST RL, KL, LL, EL, QL;
# endif
{
  MASSTOR_LIST C_135_A, AL, AP, FL, IL, QL1, QL2, QLP, TL;

  C_135_A = 0;
  if (RL == 0) {
    AL = SACI_IRAND(KL);
    C_135_A = DIPC_DIPFMO(AL, MASSTOR_BETA);
    return C_135_A;
  }
  SACLIST_FIRST2(QL, &QL1, &QL2);
  SACD_DQR(QL1, 0, QL2, &QLP, &TL);
  {
    LONGINT B_15 = 1, B_16 = LL;

    if (B_15 <= B_16)
      for (IL = B_15;; IL += 1) {
        AL = SACI_IRAND(KL);
        if (AL != 0) {
          FL = DIPC_EVRASP(RL, EL, QLP);
          AP = DIPC_DIPFMO(AL, FL);
          C_135_A = DIPI_DIIPSM(C_135_A, AP);
        }
        if (IL >= B_16) break;
      }
  }
  return C_135_A;
}

void BEGIN_DIPI()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_MASERR();
    BEGIN_SACLIST();
    BEGIN_MASBIOS();
    BEGIN_SACD();
    BEGIN_SACI();
    BEGIN_SACRN();
    BEGIN_SACPOL();
    BEGIN_DIPC();
    BEGIN_MASI();

  }
}
