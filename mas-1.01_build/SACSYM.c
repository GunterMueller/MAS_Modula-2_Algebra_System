#include "SYSTEM_.h"

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SACSYM
#include "SACSYM.h"
#endif

MASELEM_GAMMAINT SACSYM_COUNT, SACSYM_TRMAX;
MASSTOR_LIST SACSYM_SYMTB;
CHAR SACSYM_rcsid [] = "$Id: SACSYM.md,v 1.2 1992/02/12 17:32:35 pesch Exp $";
CHAR SACSYM_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

#define ICOUNT	1
static MASELEM_GAMMAINT NAM, SBASE;
static CHAR rcsidi [] = "$Id: SACSYM.mi,v 1.3 1992/10/15 16:27:55 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
static void BEGINU ARGS(());
static MASSTOR_LIST STNEW ARGS((MASSTOR_LIST L));
static MASSTOR_LIST SYNEW ARGS((MASSTOR_LIST L));
static void TRC ARGS((CHAR SP[], LONGCARD , MASSTOR_LIST AL1, MASSTOR_LIST AL2, MASSTOR_LIST AL3, MASSTOR_LIST AL4, MASSTOR_LIST AL5, MASSTOR_LIST AL6, MASSTOR_LIST AL7, MASSTOR_LIST AL8, MASSTOR_LIST AL9, MASSTOR_LIST AL10, MASSTOR_LIST AL11, MASSTOR_LIST AL12, MASSTOR_LIST AL13));
struct S_2 {
    MASSTOR_LIST A[13 - 1 + 1];
};


MASSTOR_LIST SACSYM_ACOMP
# ifdef __STDC__
(MASSTOR_LIST C_21_A, MASSTOR_LIST B)
# else
(C_21_A, B)
MASSTOR_LIST C_21_A, B;
# endif
{
  MASSTOR_LIST TL;

  TL = SACSYM_ACOMP1(SACSYM_NAME(C_21_A), SACSYM_NAME(B));
  return TL;
}

MASSTOR_LIST SACSYM_ACOMP1
# ifdef __STDC__
(MASSTOR_LIST C_20_A, MASSTOR_LIST B)
# else
(C_20_A, B)
MASSTOR_LIST C_20_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, SL;

  AP = C_20_A;
  BP = B;
  SL = 0;
  do {
    MASSTOR_ADV(AP, &AL, &AP);
    MASSTOR_ADV(BP, &BL, &BP);
    if (AL > BL) {
      SL = 1;
    } else {
      if (AL < BL) {
        SL = -1;
      }
    }
    if (SL != 0) {
      return SL;
    }
  } while (!(AP == MASSTOR_SIL || BP == MASSTOR_SIL));
  if (BP != MASSTOR_SIL) {
    SL = -1;
  } else {
    if (AP != MASSTOR_SIL) {
      SL = 1;
    }
  }
  return SL;
}

MASSTOR_LIST SACSYM_ASSOC
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST L)
# else
(AL, L)
MASSTOR_LIST AL, L;
# endif
{
  MASSTOR_LIST ALP, P;

  P = L;
  while (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, &ALP, &P);
    if (AL == ALP) {
      return P;
    }
    MASSTOR_ADV(P, &ALP, &P);
  }
  return P;
}

MASSTOR_LIST SACSYM_ASSOCQ
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST L)
# else
(AL, L)
MASSTOR_LIST AL, L;
# endif
{
  MASSTOR_LIST ALP, P;

  P = L;
  while (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, &ALP, &P);
    if (SACLIST_EQUAL(AL, ALP) == 1) {
      return P;
    }
    MASSTOR_ADV(P, &ALP, &P);
  }
  return P;
}

MASSTOR_LIST SACSYM_ATTRIB
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST LP;

  LP = MASSTOR_SIL;
  if (SACSYM_SYMBOL(L)) {
    LP = SACLIST_RED2(L);
  }
  return LP;
}

static void BEGINU
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST CL, NL, TL;

  SACSYM_SYMTB = MASSTOR_SIL;
  NL = 0;
  CL = MASBIOS_CHI + 1;
  TL = MASSTOR_BETA / CL;
  do {
    TL = TL / CL;
    NL = NL + 1;
  } while (!(TL == 0));
  SBASE = MASELEM_MASEXP(CL, NL);
  SACSYM_TRMAX = 10;
  SACSYM_COUNT = 0;
  NAM = 0;
  return;
}

MASSTOR_LIST SACSYM_EXPLOD
# ifdef __STDC__
(MASSTOR_LIST S)
# else
(S)
MASSTOR_LIST S;
# endif
{
  MASSTOR_LIST C_19_A, AP, CL, DL, J1Y, L, LP, Q;

  LP = SACSYM_NAME(S);
  L = MASSTOR_SIL;
  CL = MASBIOS_CHI + 1;
  do {
    DL = SBASE / CL;
    MASSTOR_ADV(LP, &C_19_A, &LP);
    do {
      MASELEM_MASQREM(C_19_A, DL, &Q, &AP);
      C_19_A = AP;
      J1Y = Q - 1;
      L = MASSTOR_COMP(J1Y, L);
      DL = DL / CL;
    } while (!(C_19_A == 0));
  } while (!(LP == MASSTOR_SIL));
  L = MASSTOR_INV(L);
  return L;
}

MASSTOR_LIST SACSYM_ENTER
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST J1Y, S;

  J1Y = SACSYM_PACK(L);
  S = SACSYM_STINS(J1Y);
  return S;
}

MASSTOR_LIST SACSYM_GENSYM
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST J1Y, Q, S;

  NAM = NAM + 1;
  S = MASSTOR_LIST1(MASBIOS_MASORD('Y'));
  Q = NAM;
  do {
    J1Y = MASELEM_MASREM(Q, 10);
    S = MASSTOR_COMP(J1Y, S);
    Q = Q / 10;
  } while (!(Q == 0));
  J1Y = MASSTOR_COMP(MASBIOS_MASORD('J'), S);
  S = SACSYM_ENTER(J1Y);
  return S;
}

MASSTOR_LIST SACSYM_GET
# ifdef __STDC__
(MASSTOR_LIST S, MASSTOR_LIST AL)
# else
(S, AL)
MASSTOR_LIST S, AL;
# endif
{
  MASSTOR_LIST C_18_A;

  C_18_A = SACSYM_ASSOC(AL, SACSYM_ATTRIB(S));
  if (C_18_A != MASSTOR_SIL) {
    C_18_A = MASSTOR_FIRST(C_18_A);
  }
  return C_18_A;
}

MASSTOR_LIST SACSYM_NAME
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST LP;

  LP = MASSTOR_SIL;
  if (SACSYM_SYMBOL(L)) {
    LP = SACLIST_SECOND(L);
  }
  return LP;
}

MASSTOR_LIST SACSYM_PACK
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST C_17_A, B, BL, CL, DL, J1Y, LP;

  LP = L;
  B = MASSTOR_SIL;
  BL = MASBIOS_CHI + 1;
  C_17_A = 0;
  DL = 1;
  do {
    MASSTOR_ADV(LP, &CL, &LP);
    if (DL == SBASE) {
      B = MASSTOR_COMP(C_17_A, B);
      C_17_A = 0;
      DL = 1;
    }
    DL = DL * BL;
    J1Y = C_17_A * BL;
    J1Y = J1Y + CL;
    C_17_A = J1Y + 1;
  } while (!(LP == MASSTOR_SIL));
  while (DL < SBASE) {
    DL = DL * BL;
    C_17_A = C_17_A * BL;
  }
  J1Y = MASSTOR_COMP(C_17_A, B);
  B = MASSTOR_INV(J1Y);
  return B;
}

void SACSYM_PUT
# ifdef __STDC__
(MASSTOR_LIST S, MASSTOR_LIST AL, MASSTOR_LIST C_16_A)
# else
(S, AL, C_16_A)
MASSTOR_LIST S, AL, C_16_A;
# endif
{
  MASSTOR_LIST L;

  L = SACSYM_ASSOC(AL, SACSYM_ATTRIB(S));
  if (L != MASSTOR_SIL) {
    MASSTOR_SFIRST(L, C_16_A);
    return;
  }
  MASSTOR_SRED(MASSTOR_RED(S), SACLIST_COMP2(AL, C_16_A, SACSYM_ATTRIB(S)));
  return;
}

void SACSYM_REMPRP
# ifdef __STDC__
(MASSTOR_LIST S, MASSTOR_LIST AL)
# else
(S, AL)
MASSTOR_LIST S, AL;
# endif
{
  MASSTOR_LIST BL, L, LP;

  L = MASSTOR_RED(S);
  LP = MASSTOR_RED(L);
  while (LP != MASSTOR_SIL) {
    MASSTOR_ADV(LP, &BL, &LP);
    if (AL == BL) {
      MASSTOR_SRED(L, MASSTOR_RED(LP));
      return;
    }
    L = LP;
    LP = MASSTOR_RED(LP);
  }
  return;
}

MASSTOR_LIST SACSYM_SMEMB
# ifdef __STDC__
(MASSTOR_LIST S, MASSTOR_LIST L)
# else
(S, L)
MASSTOR_LIST S, L;
# endif
{
  MASSTOR_LIST BL, LP, SP, SS;

  LP = L;
  BL = 1;
  SP = SACLIST_SECOND(S);
  while (LP != MASSTOR_SIL) {
    MASSTOR_ADV(LP, &SS, &LP);
    if (SACSYM_SYMBOL(SS) && SACSYM_ACOMP1(SACSYM_NAME(SS), SP) == 0) {
      return BL;
    }
  }
  BL = 0;
  return BL;
}

MASSTOR_LIST SACSYM_SREAD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST J1Y, S;

  J1Y = SACSYM_SREAD1();
  S = SACSYM_ENTER(J1Y);
  return S;
}

MASSTOR_LIST SACSYM_SREAD1
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST C, L;

  L = MASSTOR_SIL;
  C = MASBIOS_CREADB();
  if (!MASBIOS_LETTER(C)) {
    MASBIOS_SWRITE("NO SYMBOL FOUND BY SREAD1", 25L);
    MASBIOS_DIBUFF();
    L = MASBIOS_LISTS("???", 3L);
    return L;
  }
  do {
    L = MASSTOR_COMP(C, L);
    C = MASBIOS_CREAD();
  } while (!(!MASBIOS_DIGIT(C) && !MASBIOS_LETTER(C)));
  MASBIOS_BKSP();
  L = MASSTOR_INV(L);
  return L;
}

void SACSYM_STCNT
# ifdef __STDC__
(MASSTOR_LIST T, MASSTOR_LIST *S, MASSTOR_LIST *P)
# else
(T, S, P)
MASSTOR_LIST T;
MASSTOR_LIST *S, *P;
# endif
{
  MASSTOR_LIST J1Y, K, L, PP, R, SP;

  if (T == MASSTOR_SIL) {
    *S = 0;
    *P = 0;
    return;
  }
  SACLIST_ADV2(T, &L, &K, &R);
  SACSYM_STCNT(L, S, P);
  *S = *S + 1;
  J1Y = MASSTOR_LENGTH(K);
  J1Y = J1Y / 2;
  *P = *P + J1Y;
  if (SACSYM_COUNT >= 1 && SACSYM_GET(K, ICOUNT) != MASSTOR_SIL) {
    SACSYM_UWRIT1(K);
    MASBIOS_TAB(8);
    SACSYM_UWRITE(SACSYM_GET(K, ICOUNT));
  }
  SACSYM_STCNT(R, &SP, &PP);
  *S = *S + SP;
  *P = *P + PP;
  return;
}

MASSTOR_LIST SACSYM_STINS
# ifdef __STDC__
(MASSTOR_LIST B)
# else
(B)
MASSTOR_LIST B;
# endif
{
  MASSTOR_LIST L, N, R, S, SP, T, TP;
  INTEGER s;

  T = SACSYM_SYMTB;
  while (T != MASSTOR_SIL) {
    SACLIST_ADV2(T, &L, &SP, &R);
    s = (INTEGER)SACSYM_ACOMP1(SACSYM_NAME(SP), B);
    switch (s) {
    case -1:;
      TP = T;
      T = R;
      break;
    case 0:;
      S = SP;
      return S;
      break;
    case 1:;
      TP = T;
      T = L;
      break;
    }
  }
  S = SYNEW(B);
  N = STNEW(S);
  if (SACSYM_SYMTB == MASSTOR_SIL) {
    SACSYM_SYMTB = N;
  } else {
    if (s == -1) {
      MASSTOR_SRED(MASSTOR_RED(TP), N);
    } else {
      MASSTOR_SFIRST(TP, N);
    }
  }
  return S;
}

MASSTOR_LIST SACSYM_STLST
# ifdef __STDC__
(MASSTOR_LIST T)
# else
(T)
MASSTOR_LIST T;
# endif
{
  MASSTOR_LIST J1Y, L, LL, RL, SL;

  if (T == MASSTOR_SIL) {
    L = MASSTOR_SIL;
    return L;
  }
  SACLIST_ADV2(T, &LL, &SL, &RL);
  if (LL != MASSTOR_SIL) {
    LL = SACSYM_STLST(LL);
  }
  if (RL != MASSTOR_SIL) {
    RL = SACSYM_STLST(RL);
  }
  J1Y = MASSTOR_COMP(SL, RL);
  L = SACLIST_CONC(LL, J1Y);
  return L;
}

MASSTOR_LIST SACSYM_STLSTI
# ifdef __STDC__
(MASSTOR_LIST T)
# else
(T)
MASSTOR_LIST T;
# endif
{
  MASSTOR_LIST J1Y, L, LL, RL, SL;

  if (T == MASSTOR_SIL) {
    L = MASSTOR_SIL;
    return L;
  }
  SACLIST_ADV2(T, &LL, &SL, &RL);
  if (LL != MASSTOR_SIL) {
    LL = SACSYM_STLSTI(LL);
  }
  if (RL != MASSTOR_SIL) {
    RL = SACSYM_STLSTI(RL);
  }
  J1Y = SACLIST_CONC(LL, RL);
  L = MASSTOR_COMP(SL, J1Y);
  return L;
}

static MASSTOR_LIST STNEW
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST S;

  S = MASSTOR_COMP(MASSTOR_SIL, MASSTOR_COMP(L, MASSTOR_SIL));
  return S;
}

MASSTOR_LIST SACSYM_STSRCH
# ifdef __STDC__
(MASSTOR_LIST T, MASSTOR_LIST AP)
# else
(T, AP)
MASSTOR_LIST T, AP;
# endif
{
  MASSTOR_LIST K, L, R, S, TP, TPP;
  INTEGER s;

  S = MASSTOR_SIL;
  TPP = T;
  if (TPP != MASSTOR_SIL) {
    do {
      TP = TPP;
      SACLIST_ADV2(TP, &L, &K, &R);
      s = (INTEGER)SACSYM_ACOMP1(SACSYM_NAME(K), AP);
      switch (s) {
      case -1:;
        TPP = R;
        break;
      case 0:;
        S = K;
        return S;
        break;
      case 1:;
        TPP = L;
        break;
      }
    } while (!(TPP == MASSTOR_SIL));
  }
  return S;
}

void SACSYM_STWRT
# ifdef __STDC__
(MASSTOR_LIST T)
# else
(T)
MASSTOR_LIST T;
# endif
{
  MASSTOR_LIST K, L, M, ML, R, TP;

  TP = T;
  while (TP != MASSTOR_SIL) {
    SACLIST_ADV2(TP, &L, &K, &R);
    SACSYM_STWRT(L);
    SACSYM_UWRIT1(K);
    MASBIOS_SWRITE(": ", 2L);
    M = SACSYM_ATTRIB(K);
    while (M != MASSTOR_SIL) {
      MASSTOR_ADV(M, &ML, &M);
      SACSYM_UWRIT1(ML);
      MASBIOS_SWRITE(" ", 1L);
    }
    MASBIOS_BLINES(0);
    TP = R;
  }
  return;
}

BOOLEAN SACSYM_SYMBOL
# ifdef __STDC__
(MASSTOR_LIST AP)
# else
(AP)
MASSTOR_LIST AP;
# endif
{
  BOOLEAN BL;

  BL = FALSE;
  if (AP > MASSTOR_BETA) {
    if (MASSTOR_FIRST(AP) == -MASSTOR_BETA) {
      BL = TRUE;
    }
  }
  return BL;
}

static MASSTOR_LIST SYNEW
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST S;

  S = MASSTOR_COMP(-MASSTOR_BETA, MASSTOR_COMP(L, MASSTOR_SIL));
  return S;
}

void SACSYM_SymSummary
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST P, S;

  MASBIOS_BLINES(2);
  SACSYM_STCNT(SACSYM_SYMTB, &S, &P);
  SACLIST_AWRITE(S);
  MASBIOS_SWRITE(" SYMBOLS AND ", 13L);
  SACLIST_AWRITE(P);
  MASBIOS_SWRITE(" PROPERTIES.", 12L);
  MASBIOS_BLINES(1);
  SACSYM_STWRT(SACSYM_SYMTB);
}

void SACSYM_SYWRIT
# ifdef __STDC__
(MASSTOR_LIST S)
# else
(S)
MASSTOR_LIST S;
# endif
{
  MASSTOR_LIST N, L;

  N = SACSYM_EXPLOD(S);
  SACLIST_CLOUT(N);
}

MASSTOR_LIST SACSYM_SUBLIS
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST C_15_A)
# else
(L, C_15_A)
MASSTOR_LIST L, C_15_A;
# endif
{
  MASSTOR_LIST B, C1, C2, J1Y, J2Y;

  B = SACSYM_ASSOC(C_15_A, L);
  if (B != MASSTOR_SIL) {
    B = MASSTOR_FIRST(B);
    return B;
  }
  if (C_15_A <= MASSTOR_BETA || SACSYM_SYMBOL(C_15_A)) {
    B = C_15_A;
    return B;
  }
  MASSTOR_ADV(C_15_A, &C1, &C2);
  J1Y = SACSYM_SUBLIS(L, C1);
  J2Y = SACSYM_SUBLIS(L, C2);
  B = MASSTOR_COMP(J1Y, J2Y);
  return B;
}

MASSTOR_LIST SACSYM_UREAD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST C, J1Y, L;

  L = MASSTOR_SIL;
  C = MASBIOS_CREADB();
  if (MASBIOS_DIGIT(C) || C == MASBIOS_MASORD('-') || C == MASBIOS_MASORD('+')) {
    MASBIOS_BKSP();
    L = SACLIST_AREAD();
    return L;
  }
  if (MASBIOS_LETTER(C)) {
    MASBIOS_BKSP();
    L = SACSYM_SREAD();
    return L;
  }
  if (C != MASBIOS_MASORD('(')) {
    MASBIOS_SWRITE("ATOMS, SYMBOLS, OR LISTS EXPECTED BY UREAD, ", 44L);
    MASBIOS_CWRITE(C);
    MASBIOS_SWRITE(" FOUND", 6L);
    MASBIOS_DIBUFF();
    return 0;
  }
  C = MASBIOS_CREADB();
  if (C == MASBIOS_MASORD(')')) {
    return L;
  }
  MASBIOS_BKSP();
  for (;;) {
    J1Y = SACSYM_UREAD();
    L = MASSTOR_COMP(J1Y, L);
    C = MASBIOS_CREADB();
    if (C == MASBIOS_MASORD(')')) {
      L = MASSTOR_INV(L);
      return L;
    }
    if (C != MASBIOS_MASORD(',')) {
      MASBIOS_BKSP();
    }
  } EXIT_1:;
}

void SACSYM_UWRITE
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  SACSYM_UWRIT1(L);
  MASBIOS_BLINES(0);
  return;
}

void SACSYM_UWRIT1
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST AL, LP;

  if (L < MASSTOR_BETA) {
    SACLIST_AWRITE(L);
    return;
  }
  if (SACSYM_SYMBOL(L)) {
    SACSYM_SYWRIT(L);
    return;
  }
  MASBIOS_SWRITE("(", 1L);
  LP = L;
  while (LP != MASSTOR_SIL) {
    MASSTOR_ADV(LP, &AL, &LP);
    SACSYM_UWRIT1(AL);
    if (LP != MASSTOR_SIL) {
      MASBIOS_SWRITE(" ", 1L);
    }
  }
  MASBIOS_SWRITE(")", 1L);
}

static void TRC
# ifdef __STDC__
(CHAR SP[], LONGCARD O_1, MASSTOR_LIST AL1, MASSTOR_LIST AL2, MASSTOR_LIST AL3, MASSTOR_LIST AL4, MASSTOR_LIST AL5, MASSTOR_LIST AL6, MASSTOR_LIST AL7, MASSTOR_LIST AL8, MASSTOR_LIST AL9, MASSTOR_LIST AL10, MASSTOR_LIST AL11, MASSTOR_LIST AL12, MASSTOR_LIST AL13)
# else
(SP, O_1, AL1, AL2, AL3, AL4, AL5, AL6, AL7, AL8, AL9, AL10, AL11, AL12, AL13)
CHAR SP[];
LONGCARD O_1;
MASSTOR_LIST AL1, AL2, AL3, AL4, AL5, AL6, AL7, AL8, AL9, AL10, AL11, AL12, AL13;
# endif
{
  struct S_2 C_14_A;
  MASSTOR_LIST BL, CL, J1Y, JL, S;
  INTEGER IL;

  C_14_A.A[1 - 1] = AL1;
  C_14_A.A[2 - 1] = AL2;
  C_14_A.A[3 - 1] = AL3;
  C_14_A.A[4 - 1] = AL4;
  C_14_A.A[5 - 1] = AL5;
  C_14_A.A[6 - 1] = AL6;
  C_14_A.A[7 - 1] = AL7;
  C_14_A.A[8 - 1] = AL8;
  C_14_A.A[9 - 1] = AL9;
  C_14_A.A[10 - 1] = AL10;
  C_14_A.A[11 - 1] = AL11;
  C_14_A.A[12 - 1] = AL12;
  C_14_A.A[13 - 1] = AL13;
  S = SACSYM_ENTER(MASBIOS_LISTS(SP, O_1));
  CL = SACSYM_GET(S, ICOUNT);
  if (CL == MASSTOR_SIL) {
    CL = 0;
  }
  if (C_14_A.A[1 - 1] < 0) {
    CL = CL + 1;
    SACSYM_PUT(S, ICOUNT, CL);
  }
  if (CL > SACSYM_TRMAX || SACSYM_COUNT >= 1) {
    return;
  }
  if (C_14_A.A[1 - 1] < 0) {
    MASBIOS_SWRITE("+", 1L);
    SACSYM_UWRIT1(S);
    {
      LONGINT B_1 = 2, B_2 = (INTEGER)C_14_A.A[1 - 1];

      if (B_1 <= B_2)
        for (IL = B_1;; IL += 1) {
          MASBIOS_GWRITE((MASELEM_GAMMAINT)(IL - 1));
          MASBIOS_SWRITE(".", 1L);
          SACSYM_UWRIT1(C_14_A.A[IL - 1]);
          if (IL >= B_2) break;
        }
    }
    MASBIOS_BLINES(0);
    return;
  }
  MASBIOS_SWRITE("-", 1L);
  SACSYM_UWRIT1(S);
  {
    LONGINT B_3 = 2, B_4 = (INTEGER)(-C_14_A.A[1 - 1]);

    if (B_3 <= B_4)
      for (IL = B_3;; IL += 1) {
        MASBIOS_GWRITE((MASELEM_GAMMAINT)(IL - 1));
        MASBIOS_SWRITE(".", 1L);
        SACSYM_UWRIT1(C_14_A.A[IL - 1]);
        if (IL >= B_4) break;
      }
  }
  if (CL > 0) {
  }
  MASBIOS_BLINES(0);
  return;
}

void BEGIN_SACSYM()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_MASBIOS();
    BEGIN_SACLIST();

    MASSTOR_LISTVAR(&SACSYM_SYMTB);
    BEGINU();
  }
}
