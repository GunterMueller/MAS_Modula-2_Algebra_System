#include "SYSTEM_.h"

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

#ifndef DEFINITION_MASSYM
#include "MASSYM.h"
#endif

MASSTOR_LIST MASSYM_NOSHOW;
CHAR MASSYM_rcsid [] = "$Id: MASSYM.md,v 1.2 1992/02/12 17:32:31 pesch Exp $";
CHAR MASSYM_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASSYM.mi,v 1.4 1996/06/19 20:59:57 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


BOOLEAN MASSYM_ATOM
# ifdef __STDC__
(MASSTOR_LIST X)
# else
(X)
MASSTOR_LIST X;
# endif
{
  if (-MASSTOR_BETA < X && X < MASSTOR_BETA) {
    return TRUE;
  }
  return FALSE;
}

BOOLEAN MASSYM_ELEMP
# ifdef __STDC__
(MASSTOR_LIST X)
# else
(X)
MASSTOR_LIST X;
# endif
{
  MASSTOR_LIST Y;

  Y = X;
  while (Y > MASSTOR_BETA) {
    Y = MASSTOR_FIRST(Y);
  }
  if (-MASSTOR_BETA < Y && Y <= MASSTOR_BETA) {
    return TRUE;
  }
  return FALSE;
}

BOOLEAN MASSYM_MEMQ
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST L)
# else
(AL, L)
MASSTOR_LIST AL, L;
# endif
{
  MASSTOR_LIST AL1, LP;

  LP = L;
  while (LP != MASSTOR_SIL) {
    MASSTOR_ADV(LP, &AL1, &LP);
    if (AL == AL1) {
      return TRUE;
    }
  }
  return FALSE;
}

BOOLEAN MASSYM_OCCURQ
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST L)
# else
(AL, L)
MASSTOR_LIST AL, L;
# endif
{
  MASSTOR_LIST C1, C2;

  if (AL == L) {
    return TRUE;
  }
  if (MASSYM_ATOM(L) || MASSYM2_SYMBOL(L) || L == MASSTOR_SIL) {
    return FALSE;
  }
  MASSTOR_ADV(L, &C1, &C2);
  if (MASSYM_OCCURQ(AL, C1)) {
    return TRUE;
  }
  if (MASSYM_OCCURQ(AL, C2)) {
    return TRUE;
  }
  return FALSE;
}

MASSTOR_LIST MASSYM_UREAD
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
    J1Y = MASSYM_UREAD();
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

void MASSYM_UWRITE
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSYM_UWRIT1(L);
  MASBIOS_BLINES(0);
}

void MASSYM_UWRIT1
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
    MASSYM_UWRIT1(AL);
    if (AL == MASSYM_NOSHOW) {
      MASBIOS_SWRITE(" ...", 4L);
      LP = MASSTOR_SIL;
    }
    if (LP != MASSTOR_SIL) {
      MASBIOS_SWRITE(" ", 1L);
    }
  }
  MASBIOS_SWRITE(")", 1L);
}

BOOLEAN MASSYM_UNIFY
# ifdef __STDC__
(MASSTOR_LIST C_21_A, MASSTOR_LIST B, MASSTOR_LIST *S)
# else
(C_21_A, B, S)
MASSTOR_LIST C_21_A, B;
MASSTOR_LIST *S;
# endif
{
  MASSTOR_LIST C1, C2, D1, D2;

  if (C_21_A == B) {
    return TRUE;
  }
  if (MASSYM2_SYMBOL(C_21_A)) {
    if (MASSYM_OCCURQ(C_21_A, B)) {
      return FALSE;
    }
    *S = SACLIST_COMP2(C_21_A, B, *S);
    return TRUE;
  }
  if (MASSYM2_SYMBOL(B)) {
    if (MASSYM_OCCURQ(B, C_21_A)) {
      return FALSE;
    }
    *S = SACLIST_COMP2(B, C_21_A, *S);
    return TRUE;
  }
  if (MASSYM_ATOM(C_21_A) || MASSYM_ATOM(B)) {
    return FALSE;
  }
  if (C_21_A == MASSTOR_SIL || B == MASSTOR_SIL) {
    return FALSE;
  }
  MASSTOR_ADV(C_21_A, &C1, &C2);
  MASSTOR_ADV(B, &D1, &D2);
  if (C1 != D1) {
    return FALSE;
  }
  while (C2 != MASSTOR_SIL && D2 != MASSTOR_SIL) {
    MASSTOR_ADV(C2, &C1, &C2);
    MASSTOR_ADV(D2, &D1, &D2);
    C1 = MASSYM2_SUBLIS(*S, C1);
    D1 = MASSYM2_SUBLIS(*S, D1);
    if (!MASSYM_UNIFY(C1, D1, S)) {
      return FALSE;
    }
  }
  if (C2 != MASSTOR_SIL || D2 != MASSTOR_SIL) {
    return FALSE;
  }
  return TRUE;
}

MASSTOR_LIST MASSYM_GENARRAY
# ifdef __STDC__
(MASSTOR_LIST C_20_A)
# else
(C_20_A)
MASSTOR_LIST C_20_A;
# endif
{
  MASSTOR_LIST J, Q, S, SP, n, I, i;

  S = MASSTOR_SIL;
  SACLIST_FIRST2(C_20_A, &n, &I);
  I = SACLIST_CINV(I);
  while (I != MASSTOR_SIL) {
    MASSTOR_ADV(I, &i, &I);
    if (i >= 0) {
      Q = i;
    } else {
      Q = -i;
    }
    do {
      J = Q % 10;
      S = MASSTOR_COMP(J, S);
      Q = Q / 10;
    } while (!(Q == 0));
    if (i < 0) {
      S = MASSTOR_COMP(MASBIOS_MASORD('m'), S);
    }
    if (I != MASSTOR_SIL) {
      S = MASSTOR_COMP(MASBIOS_MASORD('d'), S);
    }
  }
  SP = MASSYM2_EXPLOD(n);
  S = SACLIST_CONC(SP, S);
  S = MASSYM2_ENTER(S);
  return S;
}

MASSTOR_LIST MASSYM_GENINDEX
# ifdef __STDC__
(MASSTOR_LIST C_19_A)
# else
(C_19_A)
MASSTOR_LIST C_19_A;
# endif
{
  MASSTOR_LIST S, SP, i, j, I, s;

  S = MASSTOR_SIL;
  if (C_19_A == MASSTOR_SIL) {
    return MASSTOR_LIST1(MASSTOR_SIL);
  }
  MASSTOR_ADV(C_19_A, &i, &C_19_A);
  j = -1;
  SP = MASSYM_GENINDEX(C_19_A);
  while (j < i) {
    j = j + 1;
    I = SP;
    while (I != MASSTOR_SIL) {
      MASSTOR_ADV(I, &s, &I);
      s = MASSTOR_COMP(j, s);
      S = MASSTOR_COMP(s, S);
    }
  }
  S = MASSTOR_INV(S);
  return S;
}

MASSTOR_LIST MASSYM_ARRAYDEC
# ifdef __STDC__
(MASSTOR_LIST C_18_A)
# else
(C_18_A)
MASSTOR_LIST C_18_A;
# endif
{
  MASSTOR_LIST S, SP, s, n, I;

  SACLIST_FIRST2(C_18_A, &n, &I);
  S = MASSTOR_SIL;
  SP = MASSYM_GENINDEX(I);
  while (SP != MASSTOR_SIL) {
    MASSTOR_ADV(SP, &s, &SP);
    s = SACLIST_LIST2(n, s);
    s = MASSYM_GENARRAY(s);
    S = MASSTOR_COMP(s, S);
  }
  S = MASSTOR_INV(S);
  return S;
}

void BEGIN_MASSYM()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_MASBIOS();
    BEGIN_SACLIST();
    BEGIN_MASSYM2();

    MASSYM_NOSHOW = MASSYM2_ENTER(MASBIOS_LISTS("NOSHOW", 6L));
  }
}
