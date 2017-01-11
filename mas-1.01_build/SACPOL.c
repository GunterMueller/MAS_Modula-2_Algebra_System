#include "SYSTEM_.h"

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_SACPRIM
#include "SACPRIM.h"
#endif

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

MASSTOR_LIST SACPOL_PRIME;
CHAR SACPOL_rcsid [] = "$Id: SACPOL.md,v 1.2 1992/02/12 17:34:02 pesch Exp $";
CHAR SACPOL_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SACPOL.mi,v 1.3 1992/10/15 16:28:43 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
static void BEGIN3 ARGS(());


static void BEGIN3
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LISTVAR(&SACPOL_PRIME);
  SACPOL_PRIME = SACPRIM_DPGEN(MASSTOR_BETA - 1000, 500);
  return;
}

MASSTOR_LIST SACPOL_PBIN
# ifdef __STDC__
(MASSTOR_LIST AL1, MASSTOR_LIST EL1, MASSTOR_LIST AL2, MASSTOR_LIST EL2)
# else
(AL1, EL1, AL2, EL2)
MASSTOR_LIST AL1, EL1, AL2, EL2;
# endif
{
  MASSTOR_LIST C_45_A;

  C_45_A = MASSTOR_BETA;
  if (AL2 != 0) {
    C_45_A = SACLIST_LIST2(EL2, AL2);
  }
  if (AL1 != 0) {
    C_45_A = SACLIST_COMP2(EL1, AL1, C_45_A);
  }
  if (C_45_A == MASSTOR_SIL) {
    C_45_A = 0;
  }
  return C_45_A;
}

MASSTOR_LIST SACPOL_PCL
# ifdef __STDC__
(MASSTOR_LIST C_44_A)
# else
(C_44_A)
MASSTOR_LIST C_44_A;
# endif
{
  MASSTOR_LIST AL, AP, EL, L, ML, NL;

  AP = C_44_A;
  NL = MASSTOR_FIRST(AP);
  L = MASSTOR_BETA;
  for (ML = NL; ML >= 0; ML += -1) {
    if (AP == MASSTOR_SIL) {
      EL = -1;
    } else {
      EL = MASSTOR_FIRST(AP);
    }
    if (EL == ML) {
      SACLIST_ADV2(AP, &EL, &AL, &AP);
    } else {
      AL = 0;
    }
    L = MASSTOR_COMP(AL, L);
  }
  L = MASSTOR_INV(L);
  return L;
}

MASSTOR_LIST SACPOL_PDBORD
# ifdef __STDC__
(MASSTOR_LIST C_43_A)
# else
(C_43_A)
MASSTOR_LIST C_43_A;
# endif
{
  MASSTOR_LIST AL, AP, B, EL, KL;

  KL = SACPOL_PORD(C_43_A);
  if (KL == 0) {
    B = C_43_A;
  } else {
    B = MASSTOR_BETA;
    AP = C_43_A;
    do {
      SACLIST_ADV2(AP, &EL, &AL, &AP);
      EL = EL - KL;
      B = SACLIST_COMP2(AL, EL, B);
    } while (!(AP == MASSTOR_SIL));
    B = MASSTOR_INV(B);
  }
  return B;
}

MASSTOR_LIST SACPOL_PDEG
# ifdef __STDC__
(MASSTOR_LIST C_42_A)
# else
(C_42_A)
MASSTOR_LIST C_42_A;
# endif
{
  MASSTOR_LIST NL;

  if (C_42_A == 0) {
    NL = 0;
  } else {
    NL = MASSTOR_FIRST(C_42_A);
  }
  return NL;
}

MASSTOR_LIST SACPOL_PDEGSV
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_41_A, MASSTOR_LIST IL)
# else
(RL, C_41_A, IL)
MASSTOR_LIST RL, C_41_A, IL;
# endif
{
  MASSTOR_LIST AL, AP, EL, NL, NL1, RLP;

  if (C_41_A == 0) {
    NL = 0;
    return NL;
  }
  if (IL == RL) {
    NL = SACPOL_PDEG(C_41_A);
    return NL;
  }
  NL = 0;
  AP = C_41_A;
  RLP = RL - 1;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    NL1 = SACPOL_PDEGSV(RLP, AL, IL);
    NL = MASELEM_MASMAX(NL, NL1);
  } while (!(AP == MASSTOR_SIL));
  return NL;
}

MASSTOR_LIST SACPOL_PDEGV
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_40_A)
# else
(RL, C_40_A)
MASSTOR_LIST RL, C_40_A;
# endif
{
  MASSTOR_LIST A1, AP, IL, NL, RLP, V, V1;

  if (C_40_A == 0) {
    V = MASSTOR_BETA;
    {
      LONGINT B_1 = 1, B_2 = RL;

      if (B_1 <= B_2)
        for (IL = B_1;; IL += 1) {
          V = MASSTOR_COMP(0, V);
          if (IL >= B_2) break;
        }
    }
    return V;
  }
  NL = SACPOL_PDEG(C_40_A);
  if (RL == 1) {
    V = MASSTOR_LIST1(NL);
    return V;
  }
  RLP = RL - 1;
  A1 = SACPOL_PLDCF(C_40_A);
  V = SACPOL_PDEGV(RLP, A1);
  AP = SACPOL_PRED(C_40_A);
  while (AP != 0) {
    A1 = SACPOL_PLDCF(AP);
    V1 = SACPOL_PDEGV(RLP, A1);
    V = SACPOL_VMAX(V, V1);
    AP = SACPOL_PRED(AP);
  }
  V = MASSTOR_COMP(NL, V);
  return V;
}

MASSTOR_LIST SACPOL_PDPV
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_39_A, MASSTOR_LIST IL, MASSTOR_LIST NL)
# else
(RL, C_39_A, IL, NL)
MASSTOR_LIST RL, C_39_A, IL, NL;
# endif
{
  MASSTOR_LIST AL, AP, B, BL, EL, FL, RLP;

  if (C_39_A == 0 || NL == 0) {
    B = C_39_A;
    return B;
  }
  AP = C_39_A;
  B = MASSTOR_BETA;
  RLP = RL - 1;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    if (IL == RL) {
      BL = AL;
      FL = EL - NL;
    } else {
      BL = SACPOL_PDPV(RLP, AL, IL, NL);
      FL = EL;
    }
    B = SACLIST_COMP2(BL, FL, B);
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST SACPOL_PFDP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_38_A)
# else
(RL, C_38_A)
MASSTOR_LIST RL, C_38_A;
# endif
{
  MASSTOR_LIST AP, B, BL, NL, RLP;

  if (C_38_A == 0 || RL == 0) {
    B = C_38_A;
    return B;
  }
  MASSTOR_ADV(C_38_A, &NL, &AP);
  B = MASSTOR_BETA;
  RLP = RL - 1;
  do {
    MASSTOR_ADV(AP, &BL, &AP);
    if (BL != 0) {
      if (RLP != 0) {
        BL = SACPOL_PFDP(RLP, BL);
      }
      B = SACLIST_COMP2(BL, NL, B);
    }
    NL = NL - 1;
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST SACPOL_PINV
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_37_A, MASSTOR_LIST KL)
# else
(RL, C_37_A, KL)
MASSTOR_LIST RL, C_37_A, KL;
# endif
{
  MASSTOR_LIST A1, AP, B, B1, EL1, IL, RLP;

  if (C_37_A == 0 || KL == 0) {
    B = C_37_A;
    return B;
  }
  if (RL == 0) {
    B = C_37_A;
    {
      LONGINT B_3 = 1, B_4 = KL;

      if (B_3 <= B_4)
        for (IL = B_3;; IL += 1) {
          B = SACLIST_LIST2(0, B);
          if (IL >= B_4) break;
        }
    }
    return B;
  }
  RLP = RL - 1;
  AP = C_37_A;
  B = MASSTOR_BETA;
  do {
    SACLIST_ADV2(AP, &EL1, &A1, &AP);
    B1 = SACPOL_PINV(RLP, A1, KL);
    B = SACLIST_COMP2(B1, EL1, B);
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST SACPOL_PLBCF
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_36_A)
# else
(RL, C_36_A)
MASSTOR_LIST RL, C_36_A;
# endif
{
  MASSTOR_LIST AL, IL;

  if (C_36_A == 0) {
    AL = 0;
  } else {
    AL = C_36_A;
    {
      LONGINT B_5 = 1, B_6 = RL;

      if (B_5 <= B_6)
        for (IL = B_5;; IL += 1) {
          AL = SACPOL_PLDCF(AL);
          if (IL >= B_6) break;
        }
    }
  }
  return AL;
}

MASSTOR_LIST SACPOL_PLDCF
# ifdef __STDC__
(MASSTOR_LIST C_35_A)
# else
(C_35_A)
MASSTOR_LIST C_35_A;
# endif
{
  MASSTOR_LIST AL;

  if (C_35_A == 0) {
    AL = 0;
  } else {
    AL = SACLIST_SECOND(C_35_A);
  }
  return AL;
}

MASSTOR_LIST SACPOL_PMDEG
# ifdef __STDC__
(MASSTOR_LIST C_34_A)
# else
(C_34_A)
MASSTOR_LIST C_34_A;
# endif
{
  MASSTOR_LIST NL;

  if (C_34_A == 0) {
    NL = -1;
  } else {
    NL = MASSTOR_FIRST(C_34_A);
  }
  return NL;
}

MASSTOR_LIST SACPOL_PMON
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST EL)
# else
(AL, EL)
MASSTOR_LIST AL, EL;
# endif
{
  MASSTOR_LIST C_33_A;

  if (AL == 0) {
    C_33_A = 0;
  } else {
    C_33_A = SACLIST_LIST2(EL, AL);
  }
  return C_33_A;
}

MASSTOR_LIST SACPOL_PMPMV
# ifdef __STDC__
(MASSTOR_LIST C_32_A, MASSTOR_LIST KL)
# else
(C_32_A, KL)
MASSTOR_LIST C_32_A, KL;
# endif
{
  MASSTOR_LIST AL, AP, B, EL, J1Y;

  if (C_32_A == 0 || KL == 0) {
    B = C_32_A;
    return B;
  }
  B = MASSTOR_BETA;
  AP = C_32_A;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    J1Y = EL + KL;
    B = SACLIST_COMP2(AL, J1Y, B);
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST SACPOL_PORD
# ifdef __STDC__
(MASSTOR_LIST C_31_A)
# else
(C_31_A)
MASSTOR_LIST C_31_A;
# endif
{
  MASSTOR_LIST AP, KL;

  AP = C_31_A;
  do {
    MASSTOR_ADV(AP, &KL, &AP);
    AP = MASSTOR_RED(AP);
  } while (!(AP == MASSTOR_SIL));
  return KL;
}

MASSTOR_LIST SACPOL_PRED
# ifdef __STDC__
(MASSTOR_LIST C_30_A)
# else
(C_30_A)
MASSTOR_LIST C_30_A;
# endif
{
  MASSTOR_LIST B;

  if (C_30_A == 0) {
    B = 0;
  } else {
    B = SACLIST_RED2(C_30_A);
    if (B == MASSTOR_SIL) {
      B = 0;
    }
  }
  return B;
}

MASSTOR_LIST SACPOL_PRT
# ifdef __STDC__
(MASSTOR_LIST C_29_A)
# else
(C_29_A)
MASSTOR_LIST C_29_A;
# endif
{
  MASSTOR_LIST AL, AP, B, EL, NL;

  NL = MASSTOR_FIRST(C_29_A);
  AP = C_29_A;
  B = MASSTOR_BETA;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    EL = NL - EL;
    B = SACLIST_COMP2(EL, AL, B);
  } while (!(AP == MASSTOR_SIL));
  return B;
}

MASSTOR_LIST SACPOL_PTBCF
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_28_A)
# else
(RL, C_28_A)
MASSTOR_LIST RL, C_28_A;
# endif
{
  MASSTOR_LIST AL, AS, BL, EL, RLP;

  if (RL == 0 || C_28_A == 0) {
    AL = C_28_A;
    return AL;
  }
  RLP = RL - 1;
  AS = SACLIST_CINV(C_28_A);
  SACLIST_ADV2(AS, &BL, &EL, &AS);
  if (EL == 0) {
    AL = SACPOL_PTBCF(RLP, BL);
  } else {
    AL = 0;
  }
  return AL;
}

MASSTOR_LIST SACPOL_PUFP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_27_A)
# else
(RL, C_27_A)
MASSTOR_LIST RL, C_27_A;
# endif
{
  MASSTOR_LIST AL, AP, B, BL, EL, RLP;

  if (RL == 0 || C_27_A == 0) {
    B = C_27_A;
    return B;
  }
  RLP = RL - 1;
  B = MASSTOR_BETA;
  AP = C_27_A;
  while (AP != MASSTOR_SIL) {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    BL = SACPOL_PTBCF(RLP, AL);
    if (BL != 0) {
      B = SACLIST_COMP2(BL, EL, B);
    }
  }
  if (B == MASSTOR_SIL) {
    B = 0;
  } else {
    B = MASSTOR_INV(B);
  }
  return B;
}

MASSTOR_LIST SACPOL_VCOMP
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V)
# else
(U, V)
MASSTOR_LIST U, V;
# endif
{
  MASSTOR_LIST TL, TL1, TL2, UL, US, VL, VS;

  TL1 = 0;
  TL2 = 0;
  US = U;
  VS = V;
  do {
    MASSTOR_ADV(US, &UL, &US);
    MASSTOR_ADV(VS, &VL, &VS);
    if (UL < VL) {
      TL1 = 1;
    } else {
      if (VL < UL) {
        TL2 = 2;
      }
    }
  } while (!(US == MASSTOR_SIL));
  TL = TL1 + TL2;
  return TL;
}

MASSTOR_LIST SACPOL_VLREAD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST C, V, VL;

  V = MASSTOR_SIL;
  C = MASBIOS_CREADB();
  if (C != MASBIOS_MASORD('(')) {
    MASBIOS_SWRITE("ERROR FOUND BY VLREAD.", 22L);
    MASBIOS_DIBUFF();
  }
  C = MASBIOS_CREADB();
  if (C == MASBIOS_MASORD(')')) {
    return V;
  } else {
    MASBIOS_BKSP();
  }
  for (;;) {
    VL = SACPOL_VREAD();
    V = MASSTOR_COMP(VL, V);
    C = MASBIOS_CREADB();
    if (C == MASBIOS_MASORD(')')) {
      V = MASSTOR_INV(V);
      return V;
    } else {
      if (C != MASBIOS_MASORD(',')) {
        MASBIOS_SWRITE("ERROR FOUND BY VLREAD.", 22L);
        MASBIOS_DIBUFF();
      }
    }
  } EXIT_1:;
}

MASSTOR_LIST SACPOL_VLSRCH
# ifdef __STDC__
(MASSTOR_LIST VL, MASSTOR_LIST V)
# else
(VL, V)
MASSTOR_LIST VL, V;
# endif
{
  MASSTOR_LIST IL, VL1, VP;

  VP = V;
  IL = 1;
  while (VP != MASSTOR_SIL) {
    MASSTOR_ADV(VP, &VL1, &VP);
    if (SACLIST_EQUAL(VL, VL1) == 1) {
      return IL;
    }
    IL = IL + 1;
  }
  IL = 0;
  return IL;
}

void SACPOL_VLWRIT
# ifdef __STDC__
(MASSTOR_LIST V)
# else
(V)
MASSTOR_LIST V;
# endif
{
  MASSTOR_LIST VL, VP;

  VP = V;
  MASBIOS_SWRITE("(", 1L);
  if (VP == MASSTOR_SIL) {
    MASBIOS_SWRITE(")", 1L);
    return;
  } else {
    MASSTOR_ADV(VP, &VL, &VP);
    SACLIST_CLOUT(VL);
  }
  while (VP != MASSTOR_SIL) {
    MASBIOS_SWRITE(",", 1L);
    MASSTOR_ADV(VP, &VL, &VP);
    SACLIST_CLOUT(VL);
  }
  MASBIOS_SWRITE(")", 1L);
  return;
}

MASSTOR_LIST SACPOL_VMAX
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V)
# else
(U, V)
MASSTOR_LIST U, V;
# endif
{
  MASSTOR_LIST UL, US, VL, VS, W, WL;

  W = MASSTOR_BETA;
  US = U;
  VS = V;
  do {
    MASSTOR_ADV(US, &UL, &US);
    MASSTOR_ADV(VS, &VL, &VS);
    WL = MASELEM_MASMAX(UL, VL);
    W = MASSTOR_COMP(WL, W);
  } while (!(US == MASSTOR_SIL));
  W = MASSTOR_INV(W);
  return W;
}

MASSTOR_LIST SACPOL_VMIN
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V)
# else
(U, V)
MASSTOR_LIST U, V;
# endif
{
  MASSTOR_LIST UL, US, VL, VS, W, WL;

  W = MASSTOR_BETA;
  US = U;
  VS = V;
  do {
    MASSTOR_ADV(US, &UL, &US);
    MASSTOR_ADV(VS, &VL, &VS);
    WL = MASELEM_MASMIN(UL, VL);
    W = MASSTOR_COMP(WL, W);
  } while (!(US == MASSTOR_SIL));
  W = MASSTOR_INV(W);
  return W;
}

MASSTOR_LIST SACPOL_VREAD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST C, IDUM, VL;

  C = MASBIOS_CREADB();
  if (!MASBIOS_LETTER(C)) {
    MASBIOS_SWRITE("ERROR found by VREAD.", 21L);
    MASBIOS_DIBUFF();
  }
  VL = MASSTOR_BETA;
  do {
    VL = MASSTOR_COMP(C, VL);
    C = MASBIOS_CREAD();
  } while (!!(MASBIOS_LETTER(C) || MASBIOS_DIGIT(C)));
  VL = MASSTOR_INV(VL);
  MASBIOS_BKSP();
  return VL;
}

void BEGIN_SACPOL()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_MASBIOS();
    BEGIN_SACPRIM();

    BEGIN3();
  }
}
