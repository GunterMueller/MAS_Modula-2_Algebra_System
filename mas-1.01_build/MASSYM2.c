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

#ifndef DEFINITION_MASSYM2
#include "MASSYM2.h"
#endif

MASELEM_GAMMAINT MASSYM2_COUNT, MASSYM2_TRMAX;
MASSTOR_LIST MASSYM2_SYMTB;
MASSTOR_LIST MASSYM2_NOSHOW;
CHAR MASSYM2_rcsid [] = "$Id: MASSYM2.md,v 1.2 1992/02/12 17:32:33 pesch Exp $";
CHAR MASSYM2_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASSYM2.mi,v 1.5 1993/05/11 10:48:59 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
#define ICOUNT	1
static MASELEM_GAMMAINT NAM, SBASE;
static BOOLEAN newIns;
static void BEGINU ARGS(());
static MASSTOR_LIST SYNEW ARGS((MASSTOR_LIST L));
#define maxtab	498
#define maxtab1	(maxtab + 1)
static struct S_1 {
    MASSTOR_LIST A[maxtab + 1];
} SYMTBarr;
static CARDINAL hash ARGS((MASSTOR_LIST name));
static MASSTOR_LIST SearchInsertAVL ARGS((MASSTOR_LIST B, MASSTOR_LIST t, MASSTOR_LIST *S, BOOLEAN *HeightChanged));
static void STCNTrec ARGS((MASSTOR_LIST T, MASSTOR_LIST *S, MASSTOR_LIST *P));
static MASSTOR_LIST STLST1tree ARGS((MASSTOR_LIST T));
static void WalkThroughTreeAndInsertIntoAuxtree ARGS((MASSTOR_LIST T));
static void insert ARGS((MASSTOR_LIST sym));
static MASSTOR_LIST STLSTIrec ARGS((MASSTOR_LIST T));
static CARDINAL i;

static MASSTOR_LIST *G_1_bal;
static MASSTOR_LIST *G_2_J1Y;
static MASSTOR_LIST *G_3_bal;
static MASSTOR_LIST *G_4_AuxTree;
static MASSTOR_LIST *G_5_J1Y;
static MASSTOR_LIST *G_6_bal;

MASSTOR_LIST MASSYM2_ACOMP
# ifdef __STDC__
(MASSTOR_LIST C_20_A, MASSTOR_LIST B)
# else
(C_20_A, B)
MASSTOR_LIST C_20_A, B;
# endif
{
  MASSTOR_LIST TL;

  TL = MASSYM2_ACOMP1(MASSYM2_NAME(C_20_A), MASSYM2_NAME(B));
  return TL;
}

MASSTOR_LIST MASSYM2_ACOMP1
# ifdef __STDC__
(MASSTOR_LIST C_19_A, MASSTOR_LIST B)
# else
(C_19_A, B)
MASSTOR_LIST C_19_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, SL;

  AP = C_19_A;
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

MASSTOR_LIST MASSYM2_ASSOC
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

MASSTOR_LIST MASSYM2_ASSOCQ
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

MASSTOR_LIST MASSYM2_ATTRIB
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST LP;

  LP = MASSTOR_SIL;
  if (MASSYM2_SYMBOL(L)) {
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

  MASSYM2_SYMTB = MASSTOR_SIL;
  NL = 0;
  CL = MASBIOS_CHI + 1;
  TL = MASSTOR_BETA / CL;
  do {
    TL = TL / CL;
    NL = NL + 1;
  } while (!(TL == 0));
  SBASE = MASELEM_MASEXP(CL, NL);
  MASSYM2_TRMAX = 10;
  MASSYM2_COUNT = 0;
  NAM = 0;
  MASSYM2_NOSHOW = MASSYM2_ENTER(MASBIOS_LISTS("NOSHOW", 6L));
  return;
}

MASSTOR_LIST MASSYM2_EXPLOD
# ifdef __STDC__
(MASSTOR_LIST S)
# else
(S)
MASSTOR_LIST S;
# endif
{
  MASSTOR_LIST C_18_A, AP, CL, DL, J1Y, L, LP, Q;

  LP = MASSYM2_NAME(S);
  L = MASSTOR_SIL;
  CL = MASBIOS_CHI + 1;
  do {
    DL = SBASE / CL;
    MASSTOR_ADV(LP, &C_18_A, &LP);
    do {
      MASELEM_MASQREM(C_18_A, DL, &Q, &AP);
      C_18_A = AP;
      J1Y = Q - 1;
      L = MASSTOR_COMP(J1Y, L);
      DL = DL / CL;
    } while (!(C_18_A == 0));
  } while (!(LP == MASSTOR_SIL));
  L = MASSTOR_INV(L);
  return L;
}

MASSTOR_LIST MASSYM2_ENTER
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST J1Y, S;

  J1Y = MASSYM2_PACK(L);
  S = MASSYM2_STINS(J1Y);
  return S;
}

MASSTOR_LIST MASSYM2_GENSYM
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
  S = MASSYM2_ENTER(J1Y);
  return S;
}

MASSTOR_LIST MASSYM2_GET
# ifdef __STDC__
(MASSTOR_LIST S, MASSTOR_LIST AL)
# else
(S, AL)
MASSTOR_LIST S, AL;
# endif
{
  MASSTOR_LIST C_17_A;

  C_17_A = MASSYM2_ASSOC(AL, MASSYM2_ATTRIB(S));
  if (C_17_A != MASSTOR_SIL) {
    C_17_A = MASSTOR_FIRST(C_17_A);
  }
  return C_17_A;
}

MASSTOR_LIST MASSYM2_NAME
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST LP;

  LP = MASSTOR_SIL;
  if (MASSYM2_SYMBOL(L)) {
    LP = SACLIST_SECOND(L);
  }
  return LP;
}

MASSTOR_LIST MASSYM2_PACK
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST C_16_A, B, BL, CL, DL, J1Y, LP;

  LP = L;
  B = MASSTOR_SIL;
  BL = MASBIOS_CHI + 1;
  C_16_A = 0;
  DL = 1;
  do {
    MASSTOR_ADV(LP, &CL, &LP);
    if (DL == SBASE) {
      B = MASSTOR_COMP(C_16_A, B);
      C_16_A = 0;
      DL = 1;
    }
    DL = DL * BL;
    J1Y = C_16_A * BL;
    J1Y = J1Y + CL;
    C_16_A = J1Y + 1;
  } while (!(LP == MASSTOR_SIL));
  while (DL < SBASE) {
    DL = DL * BL;
    C_16_A = C_16_A * BL;
  }
  J1Y = MASSTOR_COMP(C_16_A, B);
  B = MASSTOR_INV(J1Y);
  return B;
}

void MASSYM2_PUT
# ifdef __STDC__
(MASSTOR_LIST S, MASSTOR_LIST AL, MASSTOR_LIST C_15_A)
# else
(S, AL, C_15_A)
MASSTOR_LIST S, AL, C_15_A;
# endif
{
  MASSTOR_LIST L;

  L = MASSYM2_ASSOC(AL, MASSYM2_ATTRIB(S));
  if (L != MASSTOR_SIL) {
    MASSTOR_SFIRST(L, C_15_A);
    return;
  }
  MASSTOR_SRED(MASSTOR_RED(S), SACLIST_COMP2(AL, C_15_A, MASSYM2_ATTRIB(S)));
  return;
}

void MASSYM2_REMPRP
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

MASSTOR_LIST MASSYM2_SMEMB
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
    if (MASSYM2_SYMBOL(SS) && MASSYM2_ACOMP1(MASSYM2_NAME(SS), SP) == 0) {
      return BL;
    }
  }
  BL = 0;
  return BL;
}

MASSTOR_LIST MASSYM2_SREAD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST J1Y, S;

  J1Y = MASSYM2_SREAD1();
  S = MASSYM2_ENTER(J1Y);
  return S;
}

MASSTOR_LIST MASSYM2_SREAD1
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
    MASBIOS_SWRITE("No symbol found by SREAD1", 25L);
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

BOOLEAN MASSYM2_SYMBOL
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

void MASSYM2_SymSummary
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST P, S;
  CARDINAL i;

  MASBIOS_BLINES(2);
  MASSYM2_STCNT(MASSYM2_SYMTB, &S, &P);
  SACLIST_AWRITE(S);
  MASBIOS_SWRITE(" symbols and ", 13L);
  SACLIST_AWRITE(P);
  MASBIOS_SWRITE(" properties.", 12L);
  MASBIOS_BLINES(1);
  MASSYM2_STWRT(MASSYM2_SYMTB);
}

void MASSYM2_SYWRIT
# ifdef __STDC__
(MASSTOR_LIST S)
# else
(S)
MASSTOR_LIST S;
# endif
{
  MASSTOR_LIST N, L;

  N = MASSYM2_EXPLOD(S);
  SACLIST_CLOUT(N);
}

MASSTOR_LIST MASSYM2_SUBLIS
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST C_14_A)
# else
(L, C_14_A)
MASSTOR_LIST L, C_14_A;
# endif
{
  MASSTOR_LIST B, C1, C2, J1Y, J2Y;

  B = MASSYM2_ASSOC(C_14_A, L);
  if (B != MASSTOR_SIL) {
    B = MASSTOR_FIRST(B);
    return B;
  }
  if (C_14_A <= MASSTOR_BETA || MASSYM2_SYMBOL(C_14_A)) {
    B = C_14_A;
    return B;
  }
  MASSTOR_ADV(C_14_A, &C1, &C2);
  J1Y = MASSYM2_SUBLIS(L, C1);
  J2Y = MASSYM2_SUBLIS(L, C2);
  B = MASSTOR_COMP(J1Y, J2Y);
  return B;
}

MASSTOR_LIST MASSYM2_UREAD
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
    L = MASSYM2_SREAD();
    return L;
  }
  if (C == MASBIOS_MASORD('"')) {
    for (;;) {
      C = MASBIOS_CREAD();
      if (C == MASBIOS_MASORD('"')) {
        C = MASBIOS_CREAD();
        if (C != MASBIOS_MASORD('"')) {
          MASBIOS_BKSP();
          goto EXIT_1;
        }
      }
      L = MASSTOR_COMP(C, L);
    } EXIT_1:;
    L = MASSTOR_INV(L);
    return L;
  }
  if (C != MASBIOS_MASORD('(')) {
    MASBIOS_SWRITE("Atoms, strings, symbols, or lists expected by UREAD, ", 53L);
    MASBIOS_CWRITE(C);
    MASBIOS_SWRITE(" found.", 7L);
    MASBIOS_DIBUFF();
    return 0;
  }
  C = MASBIOS_CREADB();
  if (C == MASBIOS_MASORD(')')) {
    return L;
  }
  MASBIOS_BKSP();
  for (;;) {
    J1Y = MASSYM2_UREAD();
    L = MASSTOR_COMP(J1Y, L);
    C = MASBIOS_CREADB();
    if (C == MASBIOS_MASORD(')')) {
      L = MASSTOR_INV(L);
      return L;
    }
    if (C != MASBIOS_MASORD(',')) {
      MASBIOS_BKSP();
    }
  } EXIT_2:;
}

void MASSYM2_UWRITE
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSYM2_UWRIT1(L);
  MASBIOS_BLINES(0);
  return;
}

void MASSYM2_UWRIT1
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
  if (MASSYM2_SYMBOL(L)) {
    MASSYM2_SYWRIT(L);
    return;
  }
  MASBIOS_SWRITE("(", 1L);
  LP = L;
  while (LP != MASSTOR_SIL) {
    MASSTOR_ADV(LP, &AL, &LP);
    MASSYM2_UWRIT1(AL);
    if (AL == MASSYM2_NOSHOW) {
      MASBIOS_SWRITE(" ...", 4L);
      LP = MASSTOR_SIL;
    }
    if (LP != MASSTOR_SIL) {
      MASBIOS_SWRITE(" ", 1L);
    }
  }
  MASBIOS_SWRITE(")", 1L);
}

static CARDINAL hash
# ifdef __STDC__
(MASSTOR_LIST name)
# else
(name)
MASSTOR_LIST name;
# endif
{
  MASSTOR_LIST f;

  f = MASSTOR_FIRST(name);
  return (CARDINAL)(f % maxtab1);
}

static MASSTOR_LIST SearchInsertAVL
# ifdef __STDC__
(MASSTOR_LIST B, MASSTOR_LIST t, MASSTOR_LIST *S, BOOLEAN *HeightChanged)
# else
(B, t, S, HeightChanged)
MASSTOR_LIST B, t;
MASSTOR_LIST *S;
BOOLEAN *HeightChanged;
# endif
{
  MASSTOR_LIST lt, bal, elem, rt;
  MASSTOR_LIST tt, lth, balh, rth, lth1, rth1;

  tt = t;
  if (t == MASSTOR_SIL) {
    *S = SYNEW(B);
    tt = MASSTOR_COMP(MASSTOR_SIL, MASSTOR_COMP(0, MASSTOR_COMP(*S, MASSTOR_SIL)));
    *HeightChanged = TRUE;
    newIns = TRUE;
  } else {
    SACLIST_ADV3(t, &lt, &bal, &elem, &rt);
    switch ((INTEGER)MASSYM2_ACOMP1(B, MASSYM2_NAME(elem))) {
    case -1:;
      lt = SearchInsertAVL(B, lt, S, HeightChanged);
      if (newIns) {
        MASSTOR_SFIRST(t, lt);
        newIns = FALSE;
      }
      if (*HeightChanged) {
        switch ((INTEGER)bal) {
        case -1:;
          SACLIST_ADV3(lt, &lth, &balh, &elem, &rth);
          if (balh == -1) {
            MASSTOR_SFIRST(t, rth);
            MASSTOR_SRED(SACLIST_RED2(lt), t);
            SACLIST_SLELT(t, 2, 0);
            tt = lt;
            newIns = TRUE;
          } else {
            SACLIST_ADV3(rth, &lth1, &balh, &elem, &rth1);
            MASSTOR_SRED(SACLIST_RED2(lt), lth1);
            MASSTOR_SFIRST(rth, lt);
            MASSTOR_SFIRST(t, rth1);
            MASSTOR_SRED(SACLIST_RED2(rth), t);
            if (balh == -1) {
              SACLIST_SLELT(t, 2, 1);
            } else {
              SACLIST_SLELT(t, 2, 0);
            }
            if (balh == 1) {
              SACLIST_SLELT(lt, 2, -1);
            } else {
              SACLIST_SLELT(lt, 2, 0);
            }
            tt = rth;
            newIns = TRUE;
          }
          SACLIST_SLELT(t, 2, 0);
          *HeightChanged = FALSE;
          break;
        case 0:;
          SACLIST_SLELT(t, 2, -1);
          break;
        case 1:;
          SACLIST_SLELT(t, 2, 0);
          *HeightChanged = FALSE;
          break;
        }
      }
      break;
    case 0:;
      *S = elem;
      *HeightChanged = FALSE;
      break;
    case 1:;
      rt = SearchInsertAVL(B, rt, S, HeightChanged);
      if (newIns) {
        MASSTOR_SRED(SACLIST_RED2(t), rt);
        newIns = FALSE;
      }
      if (*HeightChanged) {
        switch ((INTEGER)bal) {
        case -1:;
          SACLIST_SLELT(t, 2, 0);
          *HeightChanged = FALSE;
          break;
        case 0:;
          SACLIST_SLELT(t, 2, 1);
          break;
        case 1:;
          SACLIST_ADV3(rt, &lth, &balh, &elem, &rth);
          if (balh == 1) {
            MASSTOR_SRED(SACLIST_RED2(t), lth);
            MASSTOR_SFIRST(rt, t);
            SACLIST_SLELT(t, 2, 0);
            tt = rt;
            newIns = TRUE;
          } else {
            SACLIST_ADV3(lth, &lth1, &balh, &elem, &rth1);
            MASSTOR_SFIRST(rt, rth1);
            MASSTOR_SRED(SACLIST_RED2(lth), rt);
            MASSTOR_SRED(SACLIST_RED2(t), lth1);
            MASSTOR_SFIRST(lth, t);
            if (balh == 1) {
              SACLIST_SLELT(t, 2, -1);
            } else {
              SACLIST_SLELT(t, 2, 0);
            }
            if (balh == -1) {
              SACLIST_SLELT(rt, 2, 1);
            } else {
              SACLIST_SLELT(rt, 2, 0);
            }
            tt = lth;
            newIns = TRUE;
          }
          SACLIST_SLELT(t, 2, 0);
          *HeightChanged = FALSE;
          break;
        }
      }
      break;
    }
  }
  return tt;
}

MASSTOR_LIST MASSYM2_STINS
# ifdef __STDC__
(MASSTOR_LIST B)
# else
(B)
MASSTOR_LIST B;
# endif
{
  BOOLEAN h;
  MASSTOR_LIST S;
  CARDINAL n;

  newIns = FALSE;
  h = FALSE;
  S = MASSTOR_SIL;
  n = hash(B);
  SYMTBarr.A[n] = SearchInsertAVL(B, SYMTBarr.A[n], &S, &h);
  return S;
}

static void STCNTrec
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
  } else {
    SACLIST_ADV3(T, &L, G_1_bal, &K, &R);
    STCNTrec(L, S, P);
    *S = *S + 1;
    J1Y = MASSTOR_LENGTH(K);
    J1Y = J1Y / 2;
    *P = *P + J1Y;
    if (MASSYM2_COUNT >= 1 && MASSYM2_GET(K, ICOUNT) != MASSTOR_SIL) {
      MASSYM2_UWRIT1(K);
      MASBIOS_TAB(8);
      MASSYM2_UWRITE(MASSYM2_GET(K, ICOUNT));
    }
    STCNTrec(R, &SP, &PP);
    *S = *S + SP;
    *P = *P + PP;
  }
}

void MASSYM2_STCNT
# ifdef __STDC__
(MASSTOR_LIST T, MASSTOR_LIST *S, MASSTOR_LIST *P)
# else
(T, S, P)
MASSTOR_LIST T;
MASSTOR_LIST *S, *P;
# endif
{
  MASSTOR_LIST bal;
  MASSTOR_LIST s1, p1;
  CARDINAL i;
  MASSTOR_LIST *L_1;

  L_1 = G_1_bal;
  G_1_bal = &bal;
  *S = 0;
  *P = 0;
  for (i = 0; i <= maxtab; i += 1) {
    STCNTrec(SYMTBarr.A[i], &s1, &p1);
    *S = *S + s1;
    *P = *P + p1;
  }
  G_1_bal = L_1;
}

static MASSTOR_LIST STLST1tree
# ifdef __STDC__
(MASSTOR_LIST T)
# else
(T)
MASSTOR_LIST T;
# endif
{
  MASSTOR_LIST LL, RL, SL;

  if (T == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  SACLIST_ADV2(T, &LL, &SL, &RL);
  if (LL != MASSTOR_SIL) {
    LL = STLST1tree(LL);
  }
  if (RL != MASSTOR_SIL) {
    RL = STLST1tree(RL);
  }
  *G_2_J1Y = MASSTOR_COMP(SL, RL);
  return SACLIST_CONC(LL, *G_2_J1Y);
}

static void insert
# ifdef __STDC__
(MASSTOR_LIST sym)
# else
(sym)
MASSTOR_LIST sym;
# endif
{
  MASSTOR_LIST h, l, m, r;

  if (*G_4_AuxTree == MASSTOR_SIL) {
    *G_4_AuxTree = MASSTOR_COMP(MASSTOR_SIL, MASSTOR_COMP(sym, MASSTOR_SIL));
  } else {
    h = *G_4_AuxTree;
    for (;;) {
      SACLIST_ADV2(h, &l, &m, &r);
      switch ((INTEGER)MASSYM2_ACOMP1(MASSYM2_NAME(m), MASSYM2_NAME(sym))) {
      case -1:;
        if (r == MASSTOR_SIL) {
          MASSTOR_SRED(MASSTOR_RED(h), MASSTOR_COMP(MASSTOR_SIL, MASSTOR_COMP(sym, MASSTOR_SIL)));
          goto EXIT_3;
        } else {
          h = r;
        }
        break;
      case 1:;
        if (l == MASSTOR_SIL) {
          MASSTOR_SFIRST(h, MASSTOR_COMP(MASSTOR_SIL, MASSTOR_COMP(sym, MASSTOR_SIL)));
          goto EXIT_3;
        } else {
          h = l;
        }
        break;
      }
    } EXIT_3:;
  }
}

static void WalkThroughTreeAndInsertIntoAuxtree
# ifdef __STDC__
(MASSTOR_LIST T)
# else
(T)
MASSTOR_LIST T;
# endif
{
  MASSTOR_LIST L, M, R;

  if (T != MASSTOR_SIL) {
    SACLIST_ADV3(T, &L, G_3_bal, &M, &R);
    insert(M);
    WalkThroughTreeAndInsertIntoAuxtree(L);
    WalkThroughTreeAndInsertIntoAuxtree(R);
  }
}

MASSTOR_LIST MASSYM2_STLST
# ifdef __STDC__
(MASSTOR_LIST T)
# else
(T)
MASSTOR_LIST T;
# endif
{
  MASSTOR_LIST bal, J1Y;
  MASSTOR_LIST AuxTree;
  CARDINAL i;
  MASSTOR_LIST *L_2;
  MASSTOR_LIST *L_3;
  MASSTOR_LIST *L_4;

  L_2 = G_2_J1Y;
  G_2_J1Y = &J1Y;
  L_3 = G_3_bal;
  G_3_bal = &bal;
  L_4 = G_4_AuxTree;
  G_4_AuxTree = &AuxTree;
  AuxTree = MASSTOR_SIL;
  for (i = 0; i <= maxtab; i += 1) {
    WalkThroughTreeAndInsertIntoAuxtree(SYMTBarr.A[i]);
  }
  {
    LONGINT R_1 = STLST1tree(AuxTree);

    G_2_J1Y = L_2;
    G_3_bal = L_3;
    G_4_AuxTree = L_4;
    return R_1;
  }
}

static MASSTOR_LIST STLSTIrec
# ifdef __STDC__
(MASSTOR_LIST T)
# else
(T)
MASSTOR_LIST T;
# endif
{
  MASSTOR_LIST LL, RL, SL;

  if (T == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  SACLIST_ADV3(T, &LL, G_6_bal, &SL, &RL);
  if (LL != MASSTOR_SIL) {
    LL = STLSTIrec(LL);
  }
  if (RL != MASSTOR_SIL) {
    RL = STLSTIrec(RL);
  }
  *G_5_J1Y = SACLIST_CONC(LL, RL);
  return MASSTOR_COMP(SL, *G_5_J1Y);
}

MASSTOR_LIST MASSYM2_STLSTI
# ifdef __STDC__
(MASSTOR_LIST T)
# else
(T)
MASSTOR_LIST T;
# endif
{
  MASSTOR_LIST bal, J1Y;
  MASSTOR_LIST L;
  CARDINAL i;
  MASSTOR_LIST *L_5;
  MASSTOR_LIST *L_6;

  L_5 = G_5_J1Y;
  G_5_J1Y = &J1Y;
  L_6 = G_6_bal;
  G_6_bal = &bal;
  L = MASSTOR_SIL;
  for (i = 0; i <= maxtab; i += 1) {
    L = SACLIST_CONC(L, STLSTIrec(SYMTBarr.A[i]));
  }
  G_5_J1Y = L_5;
  G_6_bal = L_6;
  return L;
}

MASSTOR_LIST MASSYM2_STSRCH
# ifdef __STDC__
(MASSTOR_LIST T, MASSTOR_LIST AP)
# else
(T, AP)
MASSTOR_LIST T, AP;
# endif
{
  MASSTOR_LIST l, b, m, r;

  T = SYMTBarr.A[hash(AP)];
  while (T != MASSTOR_SIL) {
    SACLIST_ADV3(T, &l, &b, &m, &r);
    switch ((INTEGER)MASSYM2_ACOMP1(MASSYM2_NAME(m), AP)) {
    case -1:;
      T = r;
      break;
    case 0:;
      return m;
      break;
    case 1:;
      T = l;
      break;
    }
  }
  return MASSTOR_SIL;
}

void MASSYM2_STWRT
# ifdef __STDC__
(MASSTOR_LIST T)
# else
(T)
MASSTOR_LIST T;
# endif
{
  MASSTOR_LIST a, M, ML;

  T = MASSYM2_STLST(T);
  while (T != MASSTOR_SIL) {
    MASSTOR_ADV(T, &a, &T);
    MASSYM2_UWRIT1(a);
    MASBIOS_SWRITE(": ", 2L);
    M = MASSYM2_ATTRIB(a);
    while (M != MASSTOR_SIL) {
      MASSTOR_ADV(M, &ML, &M);
      MASSYM2_UWRIT1(ML);
      MASBIOS_SWRITE(" ", 1L);
    }
    MASBIOS_BLINES(0);
  }
}

void BEGIN_MASSYM2()
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

    for (i = 0; i <= maxtab; i += 1) {
      MASSTOR_LISTVAR(&SYMTBarr.A[i]);
      SYMTBarr.A[i] = MASSTOR_SIL;
    }
    MASSTOR_LISTVAR(&MASSYM2_SYMTB);
    BEGINU();
  }
}
