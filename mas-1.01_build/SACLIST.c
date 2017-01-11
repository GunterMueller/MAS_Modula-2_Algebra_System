#include "SYSTEM_.h"

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

CHAR SACLIST_rcsid [] = "$Id: SACLIST.md,v 1.2 1992/02/12 17:32:02 pesch Exp $";
CHAR SACLIST_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SACLIST.mi,v 1.4 1992/10/16 13:47:57 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
struct S_1 {
    MASSTOR_LIST A[20 - 1 + 1];
};


void SACLIST_ADV2
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST *AL, MASSTOR_LIST *BL, MASSTOR_LIST *LP)
# else
(L, AL, BL, LP)
MASSTOR_LIST L;
MASSTOR_LIST *AL, *BL, *LP;
# endif
{
  MASSTOR_ADV(L, AL, LP);
  MASSTOR_ADV(*LP, BL, LP);
  return;
}

void SACLIST_ADV3
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST *AL1, MASSTOR_LIST *AL2, MASSTOR_LIST *AL3, MASSTOR_LIST *LP)
# else
(L, AL1, AL2, AL3, LP)
MASSTOR_LIST L;
MASSTOR_LIST *AL1, *AL2, *AL3, *LP;
# endif
{
  SACLIST_ADV2(L, AL1, AL2, LP);
  MASSTOR_ADV(*LP, AL3, LP);
  return;
}

void SACLIST_ADV4
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST *AL1, MASSTOR_LIST *AL2, MASSTOR_LIST *AL3, MASSTOR_LIST *AL4, MASSTOR_LIST *LP)
# else
(L, AL1, AL2, AL3, AL4, LP)
MASSTOR_LIST L;
MASSTOR_LIST *AL1, *AL2, *AL3, *AL4, *LP;
# endif
{
  MASSTOR_ADV(L, AL1, LP);
  MASSTOR_ADV(*LP, AL2, LP);
  MASSTOR_ADV(*LP, AL3, LP);
  MASSTOR_ADV(*LP, AL4, LP);
  return;
}

MASSTOR_LIST SACLIST_AREAD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST C_19_A, C, I, J1Y, S;

  S = 1;
  C = MASBIOS_CREADB();
  if (C == MASBIOS_MASORD('+')) {
    C = MASBIOS_CREAD();
  } else {
    if (C == MASBIOS_MASORD('-')) {
      C = MASBIOS_CREAD();
      S = -1;
    } else {
      if (!MASBIOS_DIGIT(C)) {
        MASBIOS_SWRITE("ERROR FOUND BY AREAD.", 21L);
        MASBIOS_DIBUFF();
        return 0;
      }
    }
  }
  C_19_A = 0;
  I = MASSTOR_BETA / 10;
  do {
    if (C_19_A > I) {
      MASBIOS_SWRITE("ERROR FOUND BY AREAD.", 21L);
      MASBIOS_DIBUFF();
      return 0;
    }
    J1Y = 10 * C_19_A;
    C_19_A = J1Y + C;
    if (C_19_A >= MASSTOR_BETA) {
      MASBIOS_SWRITE("ERROR FOUND BY AREAD.", 21L);
      MASBIOS_DIBUFF();
      return 0;
    }
    C = MASBIOS_CREAD();
  } while (!!MASBIOS_DIGIT(C));
  C_19_A = S * C_19_A;
  MASBIOS_BKSP();
  return C_19_A;
}

void SACLIST_AWRITE
# ifdef __STDC__
(MASSTOR_LIST C_18_A)
# else
(C_18_A)
MASSTOR_LIST C_18_A;
# endif
{
  struct S_1 D;
  MASSTOR_LIST AP, Q, J1Y;
  INTEGER N;

  if (C_18_A < 0) {
    AP = -C_18_A;
    MASBIOS_SWRITE("-", 1L);
  } else {
    AP = C_18_A;
  }
  N = 0;
  do {
    Q = AP / 10;
    N = N + 1;
    J1Y = 10 * Q;
    D.A[N - 1] = AP - J1Y;
    AP = Q;
  } while (!(AP == 0));
  do {
    MASBIOS_CWRITE(D.A[N - 1]);
    N = N - 1;
  } while (!(N == 0));
  return;
}

MASSTOR_LIST SACLIST_CCONC
# ifdef __STDC__
(MASSTOR_LIST L1, MASSTOR_LIST L2)
# else
(L1, L2)
MASSTOR_LIST L1, L2;
# endif
{
  MASSTOR_LIST L, LP1;

  L = L2;
  if (L1 == MASSTOR_SIL) {
    return L;
  }
  L = L1;
  if (L2 == MASSTOR_SIL) {
    return L;
  }
  LP1 = SACLIST_CINV(L1);
  L = MASSTOR_INV(LP1);
  MASSTOR_SRED(LP1, L2);
  return L;
}

MASSTOR_LIST SACLIST_CINV
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST AL, LP, M;

  M = MASSTOR_BETA;
  LP = L;
  while (LP != MASSTOR_SIL) {
    MASSTOR_ADV(LP, &AL, &LP);
    M = MASSTOR_COMP(AL, M);
  }
  return M;
}

void SACLIST_CLOUT
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST C, LP;

  LP = L;
  while (LP != MASSTOR_SIL) {
    MASSTOR_ADV(LP, &C, &LP);
    if (C < MASSTOR_SIL) {
      MASBIOS_CWRITE(C);
    }
  }
  return;
}

MASSTOR_LIST SACLIST_COMP2
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST BL, MASSTOR_LIST L)
# else
(AL, BL, L)
MASSTOR_LIST AL, BL, L;
# endif
{
  MASSTOR_LIST J1Y, M;

  J1Y = MASSTOR_COMP(BL, L);
  M = MASSTOR_COMP(AL, J1Y);
  return M;
}

MASSTOR_LIST SACLIST_COMP3
# ifdef __STDC__
(MASSTOR_LIST AL1, MASSTOR_LIST AL2, MASSTOR_LIST AL3, MASSTOR_LIST L)
# else
(AL1, AL2, AL3, L)
MASSTOR_LIST AL1, AL2, AL3, L;
# endif
{
  MASSTOR_LIST J1Y, M;

  J1Y = MASSTOR_COMP(AL3, L);
  J1Y = MASSTOR_COMP(AL2, J1Y);
  M = MASSTOR_COMP(AL1, J1Y);
  return M;
}

MASSTOR_LIST SACLIST_COMP4
# ifdef __STDC__
(MASSTOR_LIST AL1, MASSTOR_LIST AL2, MASSTOR_LIST AL3, MASSTOR_LIST AL4, MASSTOR_LIST L)
# else
(AL1, AL2, AL3, AL4, L)
MASSTOR_LIST AL1, AL2, AL3, AL4, L;
# endif
{
  MASSTOR_LIST J1Y, M;

  J1Y = MASSTOR_COMP(AL4, L);
  J1Y = MASSTOR_COMP(AL3, J1Y);
  J1Y = MASSTOR_COMP(AL2, J1Y);
  M = MASSTOR_COMP(AL1, J1Y);
  return M;
}

MASSTOR_LIST SACLIST_CONC
# ifdef __STDC__
(MASSTOR_LIST L1, MASSTOR_LIST L2)
# else
(L1, L2)
MASSTOR_LIST L1, L2;
# endif
{
  MASSTOR_LIST L, LP;

  L = L2;
  if (L1 == MASSTOR_SIL) {
    return L;
  }
  L = L1;
  if (L2 == MASSTOR_SIL) {
    return L;
  }
  LP = SACLIST_LAST(L1);
  MASSTOR_SRED(LP, L2);
  return L;
}

MASSTOR_LIST SACLIST_EQUAL
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST BL)
# else
(AL, BL)
MASSTOR_LIST AL, BL;
# endif
{
  MASSTOR_LIST AL1, ALP, BL1, BLP, TL;

  TL = 0;
  if (AL == BL) {
    TL = 1;
    return TL;
  }
  if (AL < MASSTOR_BETA || BL < MASSTOR_BETA) {
    return TL;
  }
  ALP = AL;
  BLP = BL;
  while (ALP != MASSTOR_SIL && BLP != MASSTOR_SIL) {
    MASSTOR_ADV(ALP, &AL1, &ALP);
    MASSTOR_ADV(BLP, &BL1, &BLP);
    if (SACLIST_EQUAL(AL1, BL1) == 0) {
      return TL;
    }
    if (ALP == BLP) {
      TL = 1;
      return TL;
    }
  }
  return TL;
}

MASSTOR_LIST SACLIST_EXTENT
# ifdef __STDC__
(MASSTOR_LIST AL)
# else
(AL)
MASSTOR_LIST AL;
# endif
{
  MASSTOR_LIST AL1, ALP, J1Y, NL;

  NL = 0;
  if (AL < MASSTOR_BETA) {
    return NL;
  }
  ALP = AL;
  while (ALP != MASSTOR_SIL) {
    MASSTOR_ADV(ALP, &AL1, &ALP);
    J1Y = SACLIST_EXTENT(AL1);
    J1Y = NL + J1Y;
    NL = J1Y + 1;
  }
  return NL;
}

void SACLIST_FIRST2
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST *AL, MASSTOR_LIST *BL)
# else
(L, AL, BL)
MASSTOR_LIST L;
MASSTOR_LIST *AL, *BL;
# endif
{
  MASSTOR_LIST LP;

  MASSTOR_ADV(L, AL, &LP);
  *BL = MASSTOR_FIRST(LP);
  return;
}

void SACLIST_FIRST3
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST *AL1, MASSTOR_LIST *AL2, MASSTOR_LIST *AL3)
# else
(L, AL1, AL2, AL3)
MASSTOR_LIST L;
MASSTOR_LIST *AL1, *AL2, *AL3;
# endif
{
  MASSTOR_LIST LP;

  SACLIST_ADV2(L, AL1, AL2, &LP);
  *AL3 = MASSTOR_FIRST(LP);
  return;
}

void SACLIST_FIRST4
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST *AL1, MASSTOR_LIST *AL2, MASSTOR_LIST *AL3, MASSTOR_LIST *AL4)
# else
(L, AL1, AL2, AL3, AL4)
MASSTOR_LIST L;
MASSTOR_LIST *AL1, *AL2, *AL3, *AL4;
# endif
{
  MASSTOR_LIST LP;

  MASSTOR_ADV(L, AL1, &LP);
  MASSTOR_ADV(LP, AL2, &LP);
  MASSTOR_ADV(LP, AL3, &LP);
  *AL4 = MASSTOR_FIRST(LP);
  return;
}

MASSTOR_LIST SACLIST_FOURTH
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST AL, J1Y;

  J1Y = SACLIST_RED3(L);
  AL = MASSTOR_FIRST(J1Y);
  return AL;
}

MASSTOR_LIST SACLIST_LAST
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST LP, LPP;

  LP = L;
  LPP = MASSTOR_RED(LP);
  while (LPP != MASSTOR_SIL) {
    LP = LPP;
    LPP = MASSTOR_RED(LP);
  }
  return LP;
}

MASSTOR_LIST SACLIST_LEINST
# ifdef __STDC__
(MASSTOR_LIST C_17_A, MASSTOR_LIST IL, MASSTOR_LIST AL)
# else
(C_17_A, IL, AL)
MASSTOR_LIST C_17_A, IL, AL;
# endif
{
  MASSTOR_LIST AP, APP, JL, L;

  if (IL == 0) {
    L = MASSTOR_COMP(AL, C_17_A);
    return L;
  }
  L = C_17_A;
  AP = C_17_A;
  {
    LONGINT B_1 = 2, B_2 = IL;

    if (B_1 <= B_2)
      for (JL = B_1;; JL += 1) {
        AP = MASSTOR_RED(AP);
        if (JL >= B_2) break;
      }
  }
  APP = MASSTOR_RED(AP);
  APP = MASSTOR_COMP(AL, APP);
  MASSTOR_SRED(AP, APP);
  return L;
}

MASSTOR_LIST SACLIST_LELT
# ifdef __STDC__
(MASSTOR_LIST C_16_A, MASSTOR_LIST IL)
# else
(C_16_A, IL)
MASSTOR_LIST C_16_A, IL;
# endif
{
  MASSTOR_LIST AL, AP, JL;

  AP = C_16_A;
  {
    LONGINT B_3 = 1, B_4 = IL - 1;

    if (B_3 <= B_4)
      for (JL = B_3;; JL += 1) {
        AP = MASSTOR_RED(AP);
        if (JL >= B_4) break;
      }
  }
  AL = MASSTOR_FIRST(AP);
  return AL;
}

MASSTOR_LIST SACLIST_LEROT
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST IL, MASSTOR_LIST JL)
# else
(L, IL, JL)
MASSTOR_LIST L, IL, JL;
# endif
{
  MASSTOR_LIST AL, BL, KL, LP, LPP, M;

  M = L;
  if (IL == JL) {
    return M;
  }
  LP = L;
  {
    LONGINT B_5 = 1, B_6 = IL - 1;

    if (B_5 <= B_6)
      for (KL = B_5;; KL += 1) {
        LP = MASSTOR_RED(LP);
        if (KL >= B_6) break;
      }
  }
  MASSTOR_ADV(LP, &AL, &LPP);
  {
    LONGINT B_7 = IL, B_8 = JL - 1;

    if (B_7 <= B_8)
      for (KL = B_7;; KL += 1) {
        BL = MASSTOR_FIRST(LPP);
        MASSTOR_SFIRST(LPP, AL);
        AL = BL;
        LPP = MASSTOR_RED(LPP);
        if (KL >= B_8) break;
      }
  }
  MASSTOR_SFIRST(LP, AL);
  return M;
}

void SACLIST_LINS
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST L)
# else
(AL, L)
MASSTOR_LIST AL, L;
# endif
{
  MASSTOR_LIST C_15_A, J1Y;

  J1Y = MASSTOR_RED(L);
  C_15_A = MASSTOR_COMP(AL, J1Y);
  MASSTOR_SRED(L, C_15_A);
  return;
}

MASSTOR_LIST SACLIST_LINSRT
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST C_14_A)
# else
(AL, C_14_A)
MASSTOR_LIST AL, C_14_A;
# endif
{
  MASSTOR_LIST AP, APP, AS, B;

  if (C_14_A == MASSTOR_SIL) {
    B = MASSTOR_LIST1(AL);
    return B;
  }
  if (AL < MASSTOR_FIRST(C_14_A)) {
    B = MASSTOR_COMP(AL, C_14_A);
    return B;
  }
  AP = C_14_A;
  APP = MASSTOR_RED(AP);
  while (APP != MASSTOR_SIL && AL >= MASSTOR_FIRST(APP)) {
    AP = APP;
    APP = MASSTOR_RED(AP);
  }
  AS = MASSTOR_COMP(AL, APP);
  MASSTOR_SRED(AP, AS);
  B = C_14_A;
  return B;
}

MASSTOR_LIST SACLIST_LIST10
# ifdef __STDC__
(MASSTOR_LIST AL1, MASSTOR_LIST AL2, MASSTOR_LIST AL3, MASSTOR_LIST AL4, MASSTOR_LIST AL5, MASSTOR_LIST AL6, MASSTOR_LIST AL7, MASSTOR_LIST AL8, MASSTOR_LIST AL9, MASSTOR_LIST AL10)
# else
(AL1, AL2, AL3, AL4, AL5, AL6, AL7, AL8, AL9, AL10)
MASSTOR_LIST AL1, AL2, AL3, AL4, AL5, AL6, AL7, AL8, AL9, AL10;
# endif
{
  MASSTOR_LIST J1Y, L;

  J1Y = MASSTOR_COMP(AL10, MASSTOR_BETA);
  J1Y = MASSTOR_COMP(AL9, J1Y);
  J1Y = MASSTOR_COMP(AL8, J1Y);
  J1Y = MASSTOR_COMP(AL7, J1Y);
  J1Y = MASSTOR_COMP(AL6, J1Y);
  J1Y = MASSTOR_COMP(AL5, J1Y);
  J1Y = MASSTOR_COMP(AL4, J1Y);
  J1Y = MASSTOR_COMP(AL3, J1Y);
  J1Y = MASSTOR_COMP(AL2, J1Y);
  L = MASSTOR_COMP(AL1, J1Y);
  return L;
}

MASSTOR_LIST SACLIST_LIST2
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST BL)
# else
(AL, BL)
MASSTOR_LIST AL, BL;
# endif
{
  MASSTOR_LIST J1Y, L;

  J1Y = MASSTOR_COMP(BL, MASSTOR_BETA);
  L = MASSTOR_COMP(AL, J1Y);
  return L;
}

MASSTOR_LIST SACLIST_LIST3
# ifdef __STDC__
(MASSTOR_LIST AL1, MASSTOR_LIST AL2, MASSTOR_LIST AL3)
# else
(AL1, AL2, AL3)
MASSTOR_LIST AL1, AL2, AL3;
# endif
{
  MASSTOR_LIST J1Y, L;

  J1Y = MASSTOR_COMP(AL3, MASSTOR_BETA);
  J1Y = MASSTOR_COMP(AL2, J1Y);
  L = MASSTOR_COMP(AL1, J1Y);
  return L;
}

MASSTOR_LIST SACLIST_LIST4
# ifdef __STDC__
(MASSTOR_LIST AL1, MASSTOR_LIST AL2, MASSTOR_LIST AL3, MASSTOR_LIST AL4)
# else
(AL1, AL2, AL3, AL4)
MASSTOR_LIST AL1, AL2, AL3, AL4;
# endif
{
  MASSTOR_LIST J1Y, L;

  J1Y = MASSTOR_COMP(AL4, MASSTOR_BETA);
  J1Y = MASSTOR_COMP(AL3, J1Y);
  J1Y = MASSTOR_COMP(AL2, J1Y);
  L = MASSTOR_COMP(AL1, J1Y);
  return L;
}

MASSTOR_LIST SACLIST_LIST5
# ifdef __STDC__
(MASSTOR_LIST AL1, MASSTOR_LIST AL2, MASSTOR_LIST AL3, MASSTOR_LIST AL4, MASSTOR_LIST AL5)
# else
(AL1, AL2, AL3, AL4, AL5)
MASSTOR_LIST AL1, AL2, AL3, AL4, AL5;
# endif
{
  MASSTOR_LIST J1Y, L;

  J1Y = MASSTOR_COMP(AL5, MASSTOR_BETA);
  J1Y = MASSTOR_COMP(AL4, J1Y);
  J1Y = MASSTOR_COMP(AL3, J1Y);
  J1Y = MASSTOR_COMP(AL2, J1Y);
  L = MASSTOR_COMP(AL1, J1Y);
  return L;
}

MASSTOR_LIST SACLIST_LREAD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST C, IDUM, L, L1;

  L = MASSTOR_BETA;
  C = MASBIOS_CREADB();
  if (C != MASBIOS_MASORD('(')) {
    MASBIOS_SWRITE("ERROR FOUND BY LREAD.", 21L);
    MASBIOS_DIBUFF();
    return L;
  }
  for (;;) {
    C = MASBIOS_CREADB();
    if (C == MASBIOS_MASORD(')')) {
      L = MASSTOR_INV(L);
      return L;
    } else {
      if (C == MASBIOS_MASORD('(')) {
        MASBIOS_BKSP();
        L1 = SACLIST_LREAD();
      } else {
        if (C == MASBIOS_MASORD('+') || C == MASBIOS_MASORD('-') || MASBIOS_DIGIT(C)) {
          MASBIOS_BKSP();
          L1 = SACLIST_AREAD();
        } else {
          MASBIOS_SWRITE("ERROR FOUND BY LREAD.", 21L);
          MASBIOS_DIBUFF();
          L = MASSTOR_INV(L);
          return L;
        }
      }
    }
    L = MASSTOR_COMP(L1, L);
    C = MASBIOS_CREADB();
    if (C == MASBIOS_MASORD(')')) {
      MASBIOS_BKSP();
    } else {
      if (C != MASBIOS_MASORD(',')) {
        MASBIOS_SWRITE("ERROR FOUND BY LREAD.", 21L);
        MASBIOS_DIBUFF();
        L = MASSTOR_INV(L);
        return L;
      }
    }
  } EXIT_1:;
}

MASSTOR_LIST SACLIST_LSRCH
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST C_13_A)
# else
(AL, C_13_A)
MASSTOR_LIST AL, C_13_A;
# endif
{
  MASSTOR_LIST AL1, AP, IL;

  AP = C_13_A;
  IL = 1;
  while (AP != MASSTOR_SIL) {
    MASSTOR_ADV(AP, &AL1, &AP);
    if (AL == AL1) {
      return IL;
    }
    IL = IL + 1;
  }
  IL = 0;
  return IL;
}

void SACLIST_LWRITE
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST L1, LP;

  MASBIOS_SWRITE("(", 1L);
  LP = L;
  while (LP != MASSTOR_SIL) {
    MASSTOR_ADV(LP, &L1, &LP);
    if (L1 < MASSTOR_BETA) {
      SACLIST_AWRITE(L1);
    } else {
      SACLIST_LWRITE(L1);
    }
    if (LP != MASSTOR_BETA) {
      MASBIOS_SWRITE(",", 1L);
    }
  }
  MASBIOS_SWRITE(")", 1L);
  return;
}

MASSTOR_LIST SACLIST_MEMBER
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST L)
# else
(AL, L)
MASSTOR_LIST AL, L;
# endif
{
  MASSTOR_LIST AL1, LP, TL;

  TL = 0;
  LP = L;
  while (LP != MASSTOR_SIL) {
    MASSTOR_ADV(LP, &AL1, &LP);
    TL = SACLIST_EQUAL(AL, AL1);
    if (TL == 1) {
      return TL;
    }
  }
  return TL;
}

MASSTOR_LIST SACLIST_ORDER
# ifdef __STDC__
(MASSTOR_LIST AL)
# else
(AL)
MASSTOR_LIST AL;
# endif
{
  MASSTOR_LIST AL1, ALP, J1Y, NL;

  NL = 0;
  if (AL < MASSTOR_BETA) {
    return NL;
  }
  ALP = AL;
  while (ALP != MASSTOR_SIL) {
    MASSTOR_ADV(ALP, &AL1, &ALP);
    J1Y = SACLIST_ORDER(AL1);
    NL = MASELEM_MASMAX(NL, J1Y);
  }
  NL = NL + 1;
  return NL;
}

MASSTOR_LIST SACLIST_OREAD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST B, C, IDUM;

  C = MASBIOS_CREADB();
  MASBIOS_BKSP();
  if (C == MASBIOS_MASORD('(')) {
    B = SACLIST_LREAD();
  } else {
    B = SACLIST_AREAD();
  }
  return B;
}

void SACLIST_OWRITE
# ifdef __STDC__
(MASSTOR_LIST B)
# else
(B)
MASSTOR_LIST B;
# endif
{
  if (B < MASSTOR_BETA) {
    SACLIST_AWRITE(B);
  } else {
    SACLIST_LWRITE(B);
  }
  return;
}

MASSTOR_LIST SACLIST_PAIR
# ifdef __STDC__
(MASSTOR_LIST C_12_A, MASSTOR_LIST B)
# else
(C_12_A, B)
MASSTOR_LIST C_12_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C;

  AP = C_12_A;
  BP = B;
  C = MASSTOR_BETA;
  while (AP != MASSTOR_SIL && BP != MASSTOR_SIL) {
    MASSTOR_ADV(AP, &AL, &AP);
    MASSTOR_ADV(BP, &BL, &BP);
    C = SACLIST_COMP2(BL, AL, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST SACLIST_REDUCT
# ifdef __STDC__
(MASSTOR_LIST C_11_A, MASSTOR_LIST IL)
# else
(C_11_A, IL)
MASSTOR_LIST C_11_A, IL;
# endif
{
  MASSTOR_LIST B, JL;

  B = C_11_A;
  {
    LONGINT B_9 = 1, B_10 = IL;

    if (B_9 <= B_10)
      for (JL = B_9;; JL += 1) {
        B = MASSTOR_RED(B);
        if (JL >= B_10) break;
      }
  }
  return B;
}

MASSTOR_LIST SACLIST_RED2
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST J1Y, LP;

  J1Y = MASSTOR_RED(L);
  LP = MASSTOR_RED(J1Y);
  return LP;
}

MASSTOR_LIST SACLIST_RED3
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST J1Y, M;

  J1Y = SACLIST_RED2(L);
  M = MASSTOR_RED(J1Y);
  return M;
}

MASSTOR_LIST SACLIST_RED4
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST J1Y, M;

  J1Y = MASSTOR_RED(L);
  J1Y = MASSTOR_RED(J1Y);
  J1Y = MASSTOR_RED(J1Y);
  M = MASSTOR_RED(J1Y);
  return M;
}

MASSTOR_LIST SACLIST_SECOND
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST AL, J1Y;

  J1Y = MASSTOR_RED(L);
  AL = MASSTOR_FIRST(J1Y);
  return AL;
}

void SACLIST_SLELT
# ifdef __STDC__
(MASSTOR_LIST C_10_A, MASSTOR_LIST IL, MASSTOR_LIST AL)
# else
(C_10_A, IL, AL)
MASSTOR_LIST C_10_A, IL, AL;
# endif
{
  MASSTOR_LIST AP, JL;

  AP = C_10_A;
  {
    LONGINT B_11 = 1, B_12 = IL - 1;

    if (B_11 <= B_12)
      for (JL = B_11;; JL += 1) {
        AP = MASSTOR_RED(AP);
        if (JL >= B_12) break;
      }
  }
  MASSTOR_SFIRST(AP, AL);
  return;
}

MASSTOR_LIST SACLIST_SUFFIX
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST BL)
# else
(L, BL)
MASSTOR_LIST L, BL;
# endif
{
  MASSTOR_LIST J1Y, LP;

  J1Y = MASSTOR_LIST1(BL);
  LP = SACLIST_CONC(L, J1Y);
  return LP;
}

MASSTOR_LIST SACLIST_THIRD
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST AL, J1Y;

  J1Y = SACLIST_RED2(L);
  AL = MASSTOR_FIRST(J1Y);
  return AL;
}

void BEGIN_SACLIST()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASELEM();
    BEGIN_MASBIOS();
    BEGIN_MASSTOR();

  }
}
