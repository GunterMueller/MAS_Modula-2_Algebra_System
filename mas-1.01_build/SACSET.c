#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SACSET
#include "SACSET.h"
#endif

CHAR SACSET_rcsid [] = "$Id: SACSET.md,v 1.2 1992/02/12 13:19:19 pesch Exp $";
CHAR SACSET_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SACSET.mi,v 1.3 1992/10/15 16:28:22 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST SACSET_LBIBMS
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST B, BP, C, IL, J1Y, JL, KL, L1, L2, LP, LPP, LPPP, M, ML, NL, QL, QLP, RL, TL;

  TL = 10;
  NL = MASSTOR_LENGTH(L);
  if (NL < TL) {
    SACSET_LBIBS(L);
    M = L;
    return M;
  }
  KL = 0;
  ML = 1;
  QL = NL;
  do {
    KL = KL + 1;
    ML = ML + ML;
    QL = QL / 2;
  } while (!(QL < TL));
  J1Y = ML * QL;
  RL = NL - J1Y;
  B = MASSTOR_BETA;
  LP = L;
  {
    LONGINT B_1 = 1, B_2 = ML;

    if (B_1 <= B_2)
      for (IL = B_1;; IL += 1) {
        if (IL <= RL) {
          QLP = QL;
        } else {
          QLP = QL - 1;
        }
        LPP = LP;
        {
          LONGINT B_3 = 1, B_4 = QLP;

          if (B_3 <= B_4)
            for (JL = B_3;; JL += 1) {
              LPP = MASSTOR_RED(LPP);
              if (JL >= B_4) break;
            }
        }
        LPPP = MASSTOR_RED(LPP);
        MASSTOR_SRED(LPP, MASSTOR_SIL);
        SACSET_LBIBS(LP);
        B = MASSTOR_COMP(LP, B);
        LP = LPPP;
        if (IL >= B_2) break;
      }
  }
  {
    LONGINT B_5 = 1, B_6 = KL;

    if (B_5 <= B_6)
      for (IL = B_5;; IL += 1) {
        C = MASSTOR_BETA;
        BP = B;
        do {
          SACLIST_ADV2(BP, &L1, &L2, &BP);
          L1 = SACSET_LBIM(L1, L2);
          C = MASSTOR_COMP(L1, C);
        } while (!(BP == MASSTOR_SIL));
        B = C;
        if (IL >= B_6) break;
      }
  }
  M = MASSTOR_FIRST(B);
  return M;
}

void SACSET_LBIBS
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST ALP, ALPP, LP, LPP, M, MP;

  if (L == MASSTOR_SIL) {
    return;
  }
  M = MASSTOR_BETA;
  do {
    LP = L;
    LPP = MASSTOR_RED(LP);
    ALP = MASSTOR_FIRST(LP);
    MP = MASSTOR_BETA;
    while (LPP != M) {
      ALPP = MASSTOR_FIRST(LPP);
      if (ALP > ALPP) {
        MASSTOR_SFIRST(LP, ALPP);
        MASSTOR_SFIRST(LPP, ALP);
        MP = LPP;
      } else {
        ALP = ALPP;
      }
      LP = LPP;
      LPP = MASSTOR_RED(LP);
    }
    M = MP;
  } while (!(M == MASSTOR_SIL));
  return;
}

MASSTOR_LIST SACSET_LBIM
# ifdef __STDC__
(MASSTOR_LIST L1, MASSTOR_LIST L2)
# else
(L1, L2)
MASSTOR_LIST L1, L2;
# endif
{
  MASSTOR_LIST AL1, AL2, L, LP, LS, LP1, LP2, LPP1, LPP2;

  LP1 = L1;
  LP2 = L2;
  L = MASSTOR_SIL;
  LS = MASSTOR_SIL;
  while (LP1 != MASSTOR_SIL && LP2 != MASSTOR_SIL) {
    MASSTOR_ADV(LP1, &AL1, &LPP1);
    MASSTOR_ADV(LP2, &AL2, &LPP2);
    if (AL1 < AL2) {
      LP = LP1;
      LP1 = LPP1;
    } else {
      LP = LP2;
      LP2 = LPP2;
    }
    if (LS == MASSTOR_SIL) {
      LS = LP;
      L = LP;
    } else {
      MASSTOR_SRED(LS, LP);
      LS = LP;
    }
  }
  if (LP2 != MASSTOR_SIL) {
    LP1 = LP2;
  }
  if (LS == MASSTOR_SIL) {
    L = LP;
  } else {
    MASSTOR_SRED(LS, LP1);
  }
  return L;
}

MASSTOR_LIST SACSET_SCOMP
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST L)
# else
(AL, L)
MASSTOR_LIST AL, L;
# endif
{
  MASSTOR_LIST LP, LS, LPP, BL;

  LS = L;
  LP = MASSTOR_SIL;
  while (LS != MASSTOR_SIL) {
    MASSTOR_ADV(LS, &BL, &LS);
    if (AL == BL) {
      LP = L;
      return LP;
    }
    if (AL > BL) {
      LP = MASSTOR_COMP(BL, LP);
    } else {
      LPP = SACLIST_COMP2(BL, AL, LP);
      LP = MASSTOR_INV(LP);
      MASSTOR_SRED(LPP, LS);
      return LP;
    }
  }
  LP = MASSTOR_COMP(AL, LP);
  LP = MASSTOR_INV(LP);
  return LP;
}

MASSTOR_LIST SACSET_SDIFF
# ifdef __STDC__
(MASSTOR_LIST C_20_A, MASSTOR_LIST B)
# else
(C_20_A, B)
MASSTOR_LIST C_20_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CP;

  CP = MASSTOR_BETA;
  AP = C_20_A;
  BP = B;
  while (AP != MASSTOR_SIL && BP != MASSTOR_SIL) {
    AL = MASSTOR_FIRST(AP);
    BL = MASSTOR_FIRST(BP);
    if (AL == BL) {
      AP = MASSTOR_RED(AP);
      BP = MASSTOR_RED(BP);
    } else {
      if (AL < BL) {
        CP = MASSTOR_COMP(AL, CP);
        AP = MASSTOR_RED(AP);
      } else {
        BP = MASSTOR_RED(BP);
      }
    }
  }
  if (CP == MASSTOR_SIL) {
    C = AP;
  } else {
    C = MASSTOR_INV(CP);
    MASSTOR_SRED(CP, AP);
  }
  return C;
}

MASSTOR_LIST SACSET_SINTER
# ifdef __STDC__
(MASSTOR_LIST C_19_A, MASSTOR_LIST B)
# else
(C_19_A, B)
MASSTOR_LIST C_19_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CP;

  CP = MASSTOR_BETA;
  AP = C_19_A;
  BP = B;
  while (AP != MASSTOR_SIL && BP != MASSTOR_SIL) {
    AL = MASSTOR_FIRST(AP);
    BL = MASSTOR_FIRST(BP);
    if (AL == BL) {
      CP = MASSTOR_COMP(AL, CP);
      AP = MASSTOR_RED(AP);
      BP = MASSTOR_RED(BP);
    } else {
      if (AL < BL) {
        AP = MASSTOR_RED(AP);
      } else {
        BP = MASSTOR_RED(BP);
      }
    }
  }
  C = MASSTOR_INV(CP);
  return C;
}

MASSTOR_LIST SACSET_SUNION
# ifdef __STDC__
(MASSTOR_LIST C_18_A, MASSTOR_LIST B)
# else
(C_18_A, B)
MASSTOR_LIST C_18_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CP;

  CP = MASSTOR_BETA;
  AP = C_18_A;
  BP = B;
  while (AP != MASSTOR_SIL && BP != MASSTOR_SIL) {
    AL = MASSTOR_FIRST(AP);
    BL = MASSTOR_FIRST(BP);
    if (AL == BL) {
      CP = MASSTOR_COMP(AL, CP);
      AP = MASSTOR_RED(AP);
      BP = MASSTOR_RED(BP);
    } else {
      if (AL < BL) {
        CP = MASSTOR_COMP(AL, CP);
        AP = MASSTOR_RED(AP);
      } else {
        CP = MASSTOR_COMP(BL, CP);
        BP = MASSTOR_RED(BP);
      }
    }
  }
  if (AP == MASSTOR_SIL) {
    AP = BP;
  }
  if (CP == MASSTOR_SIL) {
    C = AP;
  } else {
    C = MASSTOR_INV(CP);
    MASSTOR_SRED(CP, AP);
  }
  return C;
}

MASSTOR_LIST SACSET_USCOMP
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST L)
# else
(AL, L)
MASSTOR_LIST AL, L;
# endif
{
  MASSTOR_LIST LP;

  if (SACLIST_MEMBER(AL, L) == 1) {
    LP = L;
  } else {
    LP = MASSTOR_COMP(AL, L);
  }
  return LP;
}

MASSTOR_LIST SACSET_USDIFF
# ifdef __STDC__
(MASSTOR_LIST C_17_A, MASSTOR_LIST B)
# else
(C_17_A, B)
MASSTOR_LIST C_17_A, B;
# endif
{
  MASSTOR_LIST AL, AP, C;

  AP = C_17_A;
  C = MASSTOR_BETA;
  while (AP != MASSTOR_SIL) {
    MASSTOR_ADV(AP, &AL, &AP);
    if (SACLIST_MEMBER(AL, B) == 0) {
      C = MASSTOR_COMP(AL, C);
    }
  }
  return C;
}

MASSTOR_LIST SACSET_USINT
# ifdef __STDC__
(MASSTOR_LIST C_16_A, MASSTOR_LIST B)
# else
(C_16_A, B)
MASSTOR_LIST C_16_A, B;
# endif
{
  MASSTOR_LIST AL, AP, C;

  AP = C_16_A;
  C = MASSTOR_BETA;
  while (AP != MASSTOR_SIL) {
    MASSTOR_ADV(AP, &AL, &AP);
    if (SACLIST_MEMBER(AL, B) == 1) {
      C = MASSTOR_COMP(AL, C);
    }
  }
  return C;
}

MASSTOR_LIST SACSET_USUN
# ifdef __STDC__
(MASSTOR_LIST C_15_A, MASSTOR_LIST B)
# else
(C_15_A, B)
MASSTOR_LIST C_15_A, B;
# endif
{
  MASSTOR_LIST C, J1Y;

  J1Y = SACSET_USDIFF(C_15_A, B);
  C = SACLIST_CONC(J1Y, B);
  return C;
}

void BEGIN_SACSET()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();

  }
}
