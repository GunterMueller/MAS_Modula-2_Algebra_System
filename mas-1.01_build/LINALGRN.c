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

#ifndef DEFINITION_MASERR
#include "MASERR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SACRN
#include "SACRN.h"
#endif

#ifndef DEFINITION_MASRN
#include "MASRN.h"
#endif

#ifndef DEFINITION_MASAPF
#include "MASAPF.h"
#endif

#ifndef DEFINITION_LINALGRN
#include "LINALGRN.h"
#endif

CHAR LINALGRN_rcsid [] = "$Id: LINALGRN.md,v 1.3 1995/11/05 09:21:58 kredel Exp $";
CHAR LINALGRN_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: LINALGRN.mi,v 1.5 1995/11/05 09:24:14 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
typedef MASSTOR_LIST (*F2) ARGS((MASSTOR_LIST, MASSTOR_LIST));
static MASSTOR_LIST rnhi ARGS((MASSTOR_LIST i, MASSTOR_LIST j));
static MASSTOR_LIST rnum ARGS((MASSTOR_LIST i, MASSTOR_LIST j));
static MASSTOR_LIST MAT ARGS((F2 f, MASSTOR_LIST m, MASSTOR_LIST n));


static MASSTOR_LIST rnhi
# ifdef __STDC__
(MASSTOR_LIST i, MASSTOR_LIST j)
# else
(i, j)
MASSTOR_LIST i, j;
# endif
{
  return SACRN_RNRED(1, i + j - 1);
}

static MASSTOR_LIST rnum
# ifdef __STDC__
(MASSTOR_LIST i, MASSTOR_LIST j)
# else
(i, j)
MASSTOR_LIST i, j;
# endif
{
  if (i == j) {
    return SACRN_RNINT(1);
  } else {
    return 0;
  }
}

MASSTOR_LIST LINALGRN_MDIM
# ifdef __STDC__
(MASSTOR_LIST M)
# else
(M)
MASSTOR_LIST M;
# endif
{
  MASSTOR_LIST zeile, spalte;

  zeile = MASSTOR_LENGTH(MASSTOR_FIRST(M));
  spalte = MASSTOR_LENGTH(M);
  if (spalte < zeile) {
    return zeile;
  } else {
    return spalte;
  }
}

MASSTOR_LIST LINALGRN_MGET
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST k, MASSTOR_LIST l)
# else
(M, k, l)
MASSTOR_LIST M, k, l;
# endif
{
  MASSTOR_LIST i, j, h1, rest;

  rest = M;
  h1 = MASSTOR_SIL;
  i = 0;
  j = 0;
  while (i < k) {
    i = i + 1;
    MASSTOR_ADV(rest, &h1, &rest);
  }
  rest = h1;
  while (j < l) {
    j = j + 1;
    MASSTOR_ADV(rest, &h1, &rest);
  }
  return h1;
}

MASSTOR_LIST LINALGRN_MSET
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST k, MASSTOR_LIST l, MASSTOR_LIST x)
# else
(M, k, l, x)
MASSTOR_LIST M, k, l, x;
# endif
{
  MASSTOR_LIST i, j, h1, rest1, rest2, neuk, neul, neuhilf, egal, neu;

  rest1 = M;
  neuk = MASSTOR_SIL;
  i = 0;
  j = 0;
  while (i < k) {
    i = i + 1;
    MASSTOR_ADV(rest1, &h1, &rest1);
    neuk = MASSTOR_COMP(h1, neuk);
  }
  rest2 = h1;
  neul = MASSTOR_SIL;
  while (j < l) {
    j = j + 1;
    MASSTOR_ADV(rest2, &h1, &rest2);
    neul = MASSTOR_COMP(h1, neul);
  }
  neu = MASSTOR_COMP(x, rest2);
  MASSTOR_ADV(neul, &egal, &neul);
  while (neul != MASSTOR_SIL) {
    MASSTOR_ADV(neul, &neuhilf, &neul);
    neu = MASSTOR_COMP(neuhilf, neu);
  }
  neu = MASSTOR_LIST1(neu);
  MASSTOR_ADV(neuk, &egal, &neuk);
  while (neuk != MASSTOR_SIL) {
    MASSTOR_ADV(neuk, &neuhilf, &neuk);
    neu = MASSTOR_COMP(neuhilf, neu);
  }
  neu = MASSTOR_INV(neu);
  while (rest1 != MASSTOR_SIL) {
    MASSTOR_ADV(rest1, &neuhilf, &rest1);
    neu = MASSTOR_COMP(neuhilf, neu);
  }
  neu = MASSTOR_INV(neu);
  return neu;
}

MASSTOR_LIST LINALGRN_VDELEL
# ifdef __STDC__
(MASSTOR_LIST V, MASSTOR_LIST i)
# else
(V, i)
MASSTOR_LIST V, i;
# endif
{
  MASSTOR_LIST U, VP, v, j;

  if (i <= 0) {
    return V;
  }
  if (V == MASSTOR_SIL) {
    return V;
  }
  VP = V;
  j = 0;
  U = MASSTOR_SIL;
  do {
    j = j + 1;
    if (VP == MASSTOR_SIL) {
      return V;
    }
    MASSTOR_ADV(VP, &v, &VP);
    U = MASSTOR_COMP(v, U);
  } while (!(j == i));
  U = MASSTOR_RED(U);
  U = MASSTOR_INV(U);
  U = SACLIST_CONC(U, VP);
  return U;
}

MASSTOR_LIST LINALGRN_MDELCOL
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST i)
# else
(M, i)
MASSTOR_LIST M, i;
# endif
{
  MASSTOR_LIST N, MP, V;

  if (i <= 0) {
    return M;
  }
  if (M == MASSTOR_SIL) {
    return M;
  }
  MP = M;
  N = MASSTOR_SIL;
  while (MP != MASSTOR_SIL) {
    MASSTOR_ADV(MP, &V, &MP);
    V = LINALGRN_VDELEL(V, i);
    N = MASSTOR_COMP(V, N);
  }
  N = MASSTOR_INV(N);
  return N;
}

MASSTOR_LIST LINALGRN_MMINOR
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST i, MASSTOR_LIST j)
# else
(M, i, j)
MASSTOR_LIST M, i, j;
# endif
{
  MASSTOR_LIST MP;

  MP = LINALGRN_VDELEL(M, j);
  MP = LINALGRN_MDELCOL(MP, i);
  return MP;
}

MASSTOR_LIST LINALGRN_MTRANS
# ifdef __STDC__
(MASSTOR_LIST M)
# else
(M)
MASSTOR_LIST M;
# endif
{
  MASSTOR_LIST C_72_A, B, C, MT, a, b;

  B = M;
  MT = MASSTOR_SIL;
  while (B != MASSTOR_SIL) {
    C_72_A = B;
    B = MASSTOR_SIL;
    C = MASSTOR_SIL;
    while (C_72_A != MASSTOR_SIL) {
      MASSTOR_ADV(C_72_A, &a, &C_72_A);
      if (a != MASSTOR_SIL) {
        MASSTOR_ADV(a, &b, &a);
        B = MASSTOR_COMP(a, B);
        C = MASSTOR_COMP(b, C);
      }
    }
    C = MASSTOR_INV(C);
    if (C != MASSTOR_SIL) {
      MT = MASSTOR_COMP(C, MT);
    }
    B = MASSTOR_INV(B);
  }
  MT = MASSTOR_INV(MT);
  return MT;
}

MASSTOR_LIST LINALGRN_VEL
# ifdef __STDC__
(MASSTOR_LIST a, MASSTOR_LIST n)
# else
(a, n)
MASSTOR_LIST a, n;
# endif
{
  MASSTOR_LIST C_71_A, k;

  C_71_A = MASSTOR_SIL;
  k = 1;
  while (k <= n) {
    k = k + 1;
    C_71_A = MASSTOR_COMP(a, C_71_A);
  }
  return C_71_A;
}

MASSTOR_LIST LINALGRN_MFILL
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST m, MASSTOR_LIST n)
# else
(M, m, n)
MASSTOR_LIST M, m, n;
# endif
{
  MASSTOR_LIST i, j, V, MP, np;

  MP = MASSTOR_SIL;
  i = 0;
  while (i < m) {
    i = i + 1;
    j = 0;
    if (M != MASSTOR_SIL) {
      MASSTOR_ADV(M, &V, &M);
      np = n - MASSTOR_LENGTH(V);
    } else {
      V = MASSTOR_SIL;
      np = n;
    }
    while (j < np) {
      j = j + 1;
      V = MASSTOR_COMP(0, V);
    }
    MP = MASSTOR_COMP(V, MP);
  }
  MP = MASSTOR_INV(MP);
  return MP;
}

MASSTOR_LIST LINALGRN_MRANG
# ifdef __STDC__
(MASSTOR_LIST U)
# else
(U)
MASSTOR_LIST U;
# endif
{
  MASSTOR_LIST r;

  r = MASSTOR_LENGTH(U);
  return r;
}

static MASSTOR_LIST MAT
# ifdef __STDC__
(F2 f, MASSTOR_LIST m, MASSTOR_LIST n)
# else
(f, m, n)
F2 f;
MASSTOR_LIST m, n;
# endif
{
  MASSTOR_LIST i, j, V, M, v;

  M = MASSTOR_SIL;
  if (m <= 0 || n <= 0) {
    return M;
  }
  i = 0;
  while (i < m) {
    i = i + 1;
    j = 0;
    V = MASSTOR_SIL;
    while (j < n) {
      j = j + 1;
      v = (*f)(i, j);
      V = MASSTOR_COMP(v, V);
    }
    V = MASSTOR_INV(V);
    M = MASSTOR_COMP(V, M);
  }
  M = MASSTOR_INV(M);
  return M;
}

MASSTOR_LIST LINALGRN_RNMHILBERT
# ifdef __STDC__
(MASSTOR_LIST m, MASSTOR_LIST n)
# else
(m, n)
MASSTOR_LIST m, n;
# endif
{
  return MAT(rnhi, m, n);
}

MASSTOR_LIST LINALGRN_RNUM
# ifdef __STDC__
(MASSTOR_LIST m, MASSTOR_LIST n)
# else
(m, n)
MASSTOR_LIST m, n;
# endif
{
  return MAT(rnum, m, n);
}

void LINALGRN_RNVWRITE
# ifdef __STDC__
(MASSTOR_LIST C_70_A, MASSTOR_LIST s)
# else
(C_70_A, s)
MASSTOR_LIST C_70_A, s;
# endif
{
  MASSTOR_LIST a;

  MASBIOS_SWRITE("(", 1L);
  while (C_70_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_70_A, &a, &C_70_A);
    if (s < 0) {
      if (s == -1) {
        SACRN_RNWRIT(a);
      } else {
        a = MASAPF_APFRN(a);
        MASAPF_APWRIT(a);
      }
    } else {
      MASRN_RNDWR(a, s);
    }
    if (C_70_A != MASSTOR_SIL) {
      MASBIOS_SWRITE(", ", 2L);
    }
  }
  MASBIOS_SWRITE(")", 1L);
}

MASSTOR_LIST LINALGRN_RNVREAD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST c, a, C_69_A;

  c = MASBIOS_CREADB();
  C_69_A = MASSTOR_SIL;
  if (c != MASBIOS_MASORD('(')) {
    MASERR_ERROR(MASERR_severe, "RNVREAD ( expected.", 19L);
    MASBIOS_BKSP();
    return C_69_A;
  }
  for (;;) {
    c = MASBIOS_CREADB();
    if (c == MASBIOS_MASORD(')')) {
      goto EXIT_1;
    }
    MASBIOS_BKSP();
    a = MASAPF_RNDRD();
    C_69_A = MASSTOR_COMP(a, C_69_A);
    c = MASBIOS_CREADB();
    if (c != MASBIOS_MASORD(',')) {
      MASBIOS_BKSP();
    }
  } EXIT_1:;
  C_69_A = MASSTOR_INV(C_69_A);
  return C_69_A;
}

void LINALGRN_RNMWRITE
# ifdef __STDC__
(MASSTOR_LIST C_68_A, MASSTOR_LIST s)
# else
(C_68_A, s)
MASSTOR_LIST C_68_A, s;
# endif
{
  MASSTOR_LIST a;

  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("(", 1L);
  while (C_68_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_68_A, &a, &C_68_A);
    LINALGRN_RNVWRITE(a, s);
    if (C_68_A != MASSTOR_SIL) {
      MASBIOS_SWRITE(", ", 2L);
      MASBIOS_BLINES(0);
    }
  }
  MASBIOS_SWRITE(")", 1L);
  MASBIOS_BLINES(0);
}

MASSTOR_LIST LINALGRN_RNMREAD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST c, a, C_67_A;

  c = MASBIOS_CREADB();
  C_67_A = MASSTOR_SIL;
  if (c != MASBIOS_MASORD('(')) {
    MASERR_ERROR(MASERR_severe, "RNMREAD ( expected.", 19L);
    MASBIOS_BKSP();
    return C_67_A;
  }
  for (;;) {
    c = MASBIOS_CREADB();
    if (c == MASBIOS_MASORD(')')) {
      goto EXIT_2;
    }
    if (c == MASBIOS_MASORD('(')) {
      MASBIOS_BKSP();
      a = LINALGRN_RNVREAD();
      C_67_A = MASSTOR_COMP(a, C_67_A);
      c = MASBIOS_CREADB();
      if (c != MASBIOS_MASORD(',')) {
        MASBIOS_BKSP();
      }
    }
  } EXIT_2:;
  C_67_A = MASSTOR_INV(C_67_A);
  return C_67_A;
}

MASSTOR_LIST LINALGRN_RNVFIV
# ifdef __STDC__
(MASSTOR_LIST C_66_A)
# else
(C_66_A)
MASSTOR_LIST C_66_A;
# endif
{
  MASSTOR_LIST a, c, C;

  C = MASSTOR_SIL;
  a = MASSTOR_SIL;
  c = MASSTOR_SIL;
  while (C_66_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_66_A, &a, &C_66_A);
    c = SACRN_RNINT(a);
    C = MASSTOR_COMP(c, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST LINALGRN_RNMFIM
# ifdef __STDC__
(MASSTOR_LIST M)
# else
(M)
MASSTOR_LIST M;
# endif
{
  MASSTOR_LIST hilf, neu;

  hilf = MASSTOR_SIL;
  while (M != MASSTOR_SIL) {
    MASSTOR_ADV(M, &neu, &M);
    neu = LINALGRN_RNVFIV(neu);
    hilf = MASSTOR_COMP(neu, hilf);
  }
  hilf = MASSTOR_INV(hilf);
  return hilf;
}

MASSTOR_LIST LINALGRN_RNVDIF
# ifdef __STDC__
(MASSTOR_LIST C_65_A, MASSTOR_LIST B)
# else
(C_65_A, B)
MASSTOR_LIST C_65_A, B;
# endif
{
  MASSTOR_LIST a, b, c, C, test;

  C = MASSTOR_SIL;
  while (C_65_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_65_A, &a, &C_65_A);
    MASSTOR_ADV(B, &b, &B);
    c = SACRN_RNDIF(a, b);
    C = MASSTOR_COMP(c, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST LINALGRN_RNVQ
# ifdef __STDC__
(MASSTOR_LIST C_64_A, MASSTOR_LIST B)
# else
(C_64_A, B)
MASSTOR_LIST C_64_A, B;
# endif
{
  MASSTOR_LIST a, b, c, C;

  C = MASSTOR_SIL;
  if (B != MASSTOR_SIL) {
    while (C_64_A != MASSTOR_SIL) {
      MASSTOR_ADV(C_64_A, &a, &C_64_A);
      c = SACRN_RNQ(a, MASSTOR_FIRST(B));
      C = MASSTOR_COMP(c, C);
    }
    C = MASSTOR_INV(C);
    return C;
  } else {
    return C_64_A;
  }
}

MASSTOR_LIST LINALGRN_RNVQF
# ifdef __STDC__
(MASSTOR_LIST C_63_A)
# else
(C_63_A)
MASSTOR_LIST C_63_A;
# endif
{
  MASSTOR_LIST b;

  if (b != (MASSTOR_LIST)0) {
    C_63_A = LINALGRN_RNVQ(C_63_A, C_63_A);
  }
  return C_63_A;
}

MASSTOR_LIST LINALGRN_RNVVSUM
# ifdef __STDC__
(MASSTOR_LIST C_62_A, MASSTOR_LIST B)
# else
(C_62_A, B)
MASSTOR_LIST C_62_A, B;
# endif
{
  MASSTOR_LIST a, b, c, C, test;

  C = MASSTOR_SIL;
  while (C_62_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_62_A, &a, &C_62_A);
    MASSTOR_ADV(B, &b, &B);
    c = SACRN_RNSUM(a, b);
    C = MASSTOR_COMP(c, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST LINALGRN_RNVSVSUM
# ifdef __STDC__
(MASSTOR_LIST C_61_A, MASSTOR_LIST B)
# else
(C_61_A, B)
MASSTOR_LIST C_61_A, B;
# endif
{
  MASSTOR_LIST a, b, c, C;

  C = MASSTOR_SIL;
  b = MASSTOR_FIRST(B);
  while (C_61_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_61_A, &a, &C_61_A);
    c = SACRN_RNSUM(a, b);
    C = MASSTOR_COMP(c, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST LINALGRN_RNVSSUM
# ifdef __STDC__
(MASSTOR_LIST C_60_A)
# else
(C_60_A)
MASSTOR_LIST C_60_A;
# endif
{
  MASSTOR_LIST a, c;

  a = MASSTOR_SIL;
  c = 0;
  while (C_60_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_60_A, &a, &C_60_A);
    c = SACRN_RNSUM(a, c);
  }
  return c;
}

MASSTOR_LIST LINALGRN_RNVSVPROD
# ifdef __STDC__
(MASSTOR_LIST C_59_A, MASSTOR_LIST B)
# else
(C_59_A, B)
MASSTOR_LIST C_59_A, B;
# endif
{
  MASSTOR_LIST a, b, c, C;

  C = MASSTOR_SIL;
  b = MASSTOR_FIRST(B);
  while (C_59_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_59_A, &a, &C_59_A);
    c = SACRN_RNPROD(a, b);
    C = MASSTOR_COMP(c, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST LINALGRN_RNVVPROD
# ifdef __STDC__
(MASSTOR_LIST C_58_A, MASSTOR_LIST B)
# else
(C_58_A, B)
MASSTOR_LIST C_58_A, B;
# endif
{
  MASSTOR_LIST a, b, c, C;

  C = MASSTOR_SIL;
  while (C_58_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_58_A, &a, &C_58_A);
    MASSTOR_ADV(B, &b, &B);
    c = SACRN_RNPROD(a, b);
    C = MASSTOR_COMP(c, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST LINALGRN_RNVSPROD
# ifdef __STDC__
(MASSTOR_LIST C_57_A, MASSTOR_LIST B)
# else
(C_57_A, B)
MASSTOR_LIST C_57_A, B;
# endif
{
  MASSTOR_LIST a, b, c, C;

  C = 0;
  while (C_57_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_57_A, &a, &C_57_A);
    MASSTOR_ADV(B, &b, &B);
    c = SACRN_RNPROD(a, b);
    C = SACRN_RNSUM(c, C);
  }
  return C;
}

MASSTOR_LIST LINALGRN_RNVMAX
# ifdef __STDC__
(MASSTOR_LIST M)
# else
(M)
MASSTOR_LIST M;
# endif
{
  MASSTOR_LIST g, zeile, element, max;

  max = 0;
  while (M != MASSTOR_SIL) {
    MASSTOR_ADV(M, &element, &M);
    element = SACRN_RNABS(element);
    max = MASRN_RNMAX(max, element);
  }
  return max;
}

MASSTOR_LIST LINALGRN_RNMSUM
# ifdef __STDC__
(MASSTOR_LIST C_56_A, MASSTOR_LIST B)
# else
(C_56_A, B)
MASSTOR_LIST C_56_A, B;
# endif
{
  MASSTOR_LIST a, b, c, C;

  if (C_56_A == MASSTOR_SIL) {
    return B;
  }
  if (B == MASSTOR_SIL) {
    return C_56_A;
  }
  C = MASSTOR_SIL;
  while (C_56_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_56_A, &a, &C_56_A);
    MASSTOR_ADV(B, &b, &B);
    c = LINALGRN_RNVVSUM(a, b);
    C = MASSTOR_COMP(c, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST LINALGRN_RNMDIF
# ifdef __STDC__
(MASSTOR_LIST C_55_A, MASSTOR_LIST B)
# else
(C_55_A, B)
MASSTOR_LIST C_55_A, B;
# endif
{
  MASSTOR_LIST a, b, c, C;

  if (C_55_A == MASSTOR_SIL) {
    B = LINALGRN_RNSMPROD(B, SACRN_RNINT(-1));
    return B;
  }
  if (B == MASSTOR_SIL) {
    return C_55_A;
  }
  C = MASSTOR_SIL;
  while (C_55_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_55_A, &a, &C_55_A);
    MASSTOR_ADV(B, &b, &B);
    c = LINALGRN_RNVDIF(a, b);
    C = MASSTOR_COMP(c, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST LINALGRN_RNSMPROD
# ifdef __STDC__
(MASSTOR_LIST C_54_A, MASSTOR_LIST B)
# else
(C_54_A, B)
MASSTOR_LIST C_54_A, B;
# endif
{
  MASSTOR_LIST a, b, c, C;

  if (C_54_A == MASSTOR_SIL) {
    return C_54_A;
  }
  C = MASSTOR_SIL;
  b = MASSTOR_LIST1(B);
  while (C_54_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_54_A, &a, &C_54_A);
    c = LINALGRN_RNVSVPROD(a, b);
    C = MASSTOR_COMP(c, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST LINALGRN_RNMMAX
# ifdef __STDC__
(MASSTOR_LIST M)
# else
(M)
MASSTOR_LIST M;
# endif
{
  MASSTOR_LIST g, zeile, element, max;

  max = 0;
  while (M != MASSTOR_SIL) {
    MASSTOR_ADV(M, &zeile, &M);
    element = LINALGRN_RNVMAX(zeile);
    max = MASRN_RNMAX(max, element);
  }
  return max;
}

MASSTOR_LIST LINALGRN_RNMGE
# ifdef __STDC__
(MASSTOR_LIST M)
# else
(M)
MASSTOR_LIST M;
# endif
{
  MASSTOR_LIST l, u, i, j, MP;

  i = MASSTOR_LENGTH(M);
  if (M != MASSTOR_SIL) {
    j = MASSTOR_LENGTH(MASSTOR_FIRST(M));
  } else {
    j = 0;
  }
  LINALGRN_RNMGELUD(M, &l, &u);
  MP = LINALGRN_MFILL(u, i, j);
  return MP;
}

MASSTOR_LIST LINALGRN_RNMDETL
# ifdef __STDC__
(MASSTOR_LIST M)
# else
(M)
MASSTOR_LIST M;
# endif
{
  MASSTOR_LIST i, d, dp, s, N, MP, V, VP, v;

  d = 0;
  if (M == MASSTOR_SIL) {
    return d;
  }
  MASSTOR_ADV(M, &V, &MP);
  if (MP == MASSTOR_SIL) {
    if (MASSTOR_RED(V) != MASSTOR_SIL) {
      d = 0;
    } else {
      d = MASSTOR_FIRST(V);
    }
    return d;
  }
  s = 1;
  i = 0;
  while (V != MASSTOR_SIL) {
    MASSTOR_ADV(V, &v, &V);
    i = i + 1;
    if (v != 0) {
      N = LINALGRN_MDELCOL(MP, i);
      dp = LINALGRN_RNMDETL(N);
      dp = SACRN_RNPROD(v, dp);
      if (s < 0) {
        dp = SACRN_RNNEG(dp);
      }
      d = SACRN_RNSUM(d, dp);
    }
    s = -s;
  }
  return d;
}

MASSTOR_LIST LINALGRN_RNVLC
# ifdef __STDC__
(MASSTOR_LIST a, MASSTOR_LIST C_53_A, MASSTOR_LIST b, MASSTOR_LIST B)
# else
(a, C_53_A, b, B)
MASSTOR_LIST a, C_53_A, b, B;
# endif
{
  MASSTOR_LIST c, cp, C, ap, bp;

  C = MASSTOR_SIL;
  while (C_53_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_53_A, &ap, &C_53_A);
    MASSTOR_ADV(B, &bp, &B);
    c = SACRN_RNPROD(a, ap);
    cp = SACRN_RNPROD(b, bp);
    c = SACRN_RNSUM(c, cp);
    C = MASSTOR_COMP(c, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST LINALGRN_RNSVPROD
# ifdef __STDC__
(MASSTOR_LIST a, MASSTOR_LIST C_52_A)
# else
(a, C_52_A)
MASSTOR_LIST a, C_52_A;
# endif
{
  MASSTOR_LIST c, cp, C, ap;

  C = MASSTOR_SIL;
  while (C_52_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_52_A, &ap, &C_52_A);
    c = SACRN_RNPROD(a, ap);
    C = MASSTOR_COMP(c, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST LINALGRN_RNMPROD
# ifdef __STDC__
(MASSTOR_LIST C_51_A, MASSTOR_LIST B)
# else
(C_51_A, B)
MASSTOR_LIST C_51_A, B;
# endif
{
  MASSTOR_LIST H1, H2, C, C1, a, c, BP, BT, b;

  C = MASSTOR_SIL;
  if (C_51_A == MASSTOR_SIL) {
    return C;
  }
  if (B == MASSTOR_SIL) {
    return C;
  }
  H1 = MASSTOR_LENGTH(MASSTOR_FIRST(C_51_A));
  H2 = MASSTOR_LENGTH(B);
  if (H1 != H2) {
    return C;
  }
  BT = LINALGRN_MTRANS(B);
  while (C_51_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_51_A, &a, &C_51_A);
    C1 = MASSTOR_SIL;
    BP = BT;
    while (BP != MASSTOR_SIL) {
      MASSTOR_ADV(BP, &b, &BP);
      c = LINALGRN_RNVSPROD(a, b);
      C1 = MASSTOR_COMP(c, C1);
    }
    C1 = MASSTOR_INV(C1);
    C = MASSTOR_COMP(C1, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST LINALGRN_RNMDET
# ifdef __STDC__
(MASSTOR_LIST M)
# else
(M)
MASSTOR_LIST M;
# endif
{
  MASSTOR_LIST d, s, i, C, M1, MP, a, b, c, MP1, V, e;

  M1 = M;
  d = 0;
  s = 1;
  if (M1 == MASSTOR_SIL) {
    return d;
  }
  V = MASSTOR_FIRST(M1);
  if (V == MASSTOR_SIL) {
    return d;
  }
  if (MASSTOR_LENGTH(M1) != MASSTOR_LENGTH(V)) {
    return d;
  }
  e = SACRN_RNINT(1);
  d = e;
  while (M1 != MASSTOR_SIL) {
    MP1 = M1;
    M1 = MASSTOR_SIL;
    a = 0;
    i = 0;
    while (MP1 != MASSTOR_SIL && a == 0) {
      MASSTOR_ADV(MP1, &C, &MP1);
      i = i + 1;
      MASSTOR_ADV(C, &a, &C);
      if (a == 0) {
        M1 = MASSTOR_COMP(C, M1);
      }
    }
    if (MASELEM_MASEVEN(i)) {
      s = -s;
    }
    if (a == 0) {
      d = 0;
      return d;
    }
    d = SACRN_RNPROD(d, a);
    while (MP1 != MASSTOR_SIL) {
      MASSTOR_ADV(MP1, &V, &MP1);
      MASSTOR_ADV(V, &b, &V);
      if (b != 0) {
        b = SACRN_RNNEG(SACRN_RNQ(b, a));
        V = LINALGRN_RNVLC(e, V, b, C);
      }
      M1 = MASSTOR_COMP(V, M1);
    }
    M1 = MASSTOR_INV(M1);
    if (M1 != MASSTOR_SIL) {
      if (MASSTOR_FIRST(M1) == MASSTOR_SIL) {
        d = 0;
        return d;
      }
    }
  }
  if (s < 0) {
    d = SACRN_RNNEG(d);
  }
  return d;
}

void LINALGRN_RNMGELUD
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST *L, MASSTOR_LIST *U)
# else
(M, L, U)
MASSTOR_LIST M;
MASSTOR_LIST *L, *U;
# endif
{
  MASSTOR_LIST C, M1, MP, L1, a, b, c, MP1, V, e, n, Z;

  M1 = M;
  MP = MASSTOR_SIL;
  *L = MASSTOR_SIL;
  *U = MASSTOR_SIL;
  if (M1 == MASSTOR_SIL) {
    return;
  }
  if (MASSTOR_FIRST(M1) == MASSTOR_SIL) {
    return;
  }
  e = SACRN_RNINT(1);
  n = SACRN_RNINT(0);
  while (M1 != MASSTOR_SIL) {
    L1 = MASSTOR_SIL;
    MP1 = M1;
    M1 = MASSTOR_SIL;
    a = 0;
    while (MP1 != MASSTOR_SIL && a == 0) {
      MASSTOR_ADV(MP1, &C, &MP1);
      MASSTOR_ADV(C, &a, &C);
      if (a == 0) {
        M1 = MASSTOR_COMP(C, M1);
        L1 = MASSTOR_COMP(a, L1);
      }
    }
    if (a == 0) {
    } else {
      a = SACRN_RNQ(e, a);
      L1 = MASSTOR_COMP(a, L1);
      C = LINALGRN_RNSVPROD(a, C);
      while (MP1 != MASSTOR_SIL) {
        MASSTOR_ADV(MP1, &V, &MP1);
        MASSTOR_ADV(V, &b, &V);
        if (b != 0) {
          V = LINALGRN_RNVLC(e, V, SACRN_RNNEG(b), C);
        }
        M1 = MASSTOR_COMP(V, M1);
        L1 = MASSTOR_COMP(b, L1);
      }
      C = MASSTOR_COMP(e, C);
      MP = MASSTOR_COMP(C, MP);
    }
    M1 = MASSTOR_INV(M1);
    L1 = MASSTOR_INV(L1);
    *L = MASSTOR_COMP(L1, *L);
    if (M1 != MASSTOR_SIL) {
      if (MASSTOR_FIRST(M1) == MASSTOR_SIL) {
        M1 = MASSTOR_SIL;
      }
    }
  }
  *U = MASSTOR_INV(MP);
  *L = MASSTOR_INV(*L);
}

MASSTOR_LIST LINALGRN_RNMLT
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST b)
# else
(L, b)
MASSTOR_LIST L, b;
# endif
{
  MASSTOR_LIST u, L1, b1, c, l, d, a;

  u = MASSTOR_SIL;
  while (L != MASSTOR_SIL) {
    MASSTOR_ADV(L, &L1, &L);
    b1 = b;
    b = MASSTOR_SIL;
    l = 0;
    while (L1 != MASSTOR_SIL && l == 0) {
      MASSTOR_ADV(L1, &l, &L1);
      MASSTOR_ADV(b1, &c, &b1);
      if (l == 0) {
        b = MASSTOR_COMP(c, b);
      }
    }
    if (l == 0) {
    } else {
      c = SACRN_RNPROD(c, l);
      u = MASSTOR_COMP(c, u);
      while (L1 != MASSTOR_SIL) {
        MASSTOR_ADV(L1, &l, &L1);
        MASSTOR_ADV(b1, &d, &b1);
        a = SACRN_RNPROD(l, c);
        a = SACRN_RNDIF(d, a);
        b = MASSTOR_COMP(a, b);
      }
    }
    b = MASSTOR_INV(b);
  }
  while (b != MASSTOR_SIL) {
    MASSTOR_ADV(b, &c, &b);
    if (c != 0) {
      return MASSTOR_SIL;
    }
  }
  u = MASSTOR_INV(u);
  return u;
}

MASSTOR_LIST LINALGRN_RNMUT
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST b)
# else
(U, b)
MASSTOR_LIST U, b;
# endif
{
  MASSTOR_LIST UP, x, U1, a, c, y, u, xp, b1;

  x = MASSTOR_SIL;
  if (U == MASSTOR_SIL) {
    return x;
  }
  UP = SACLIST_CINV(U);
  b1 = SACLIST_CINV(b);
  while (UP != MASSTOR_SIL) {
    MASSTOR_ADV(UP, &U1, &UP);
    U1 = SACLIST_CINV(U1);
    y = 0;
    xp = x;
    while (xp != MASSTOR_SIL) {
      MASSTOR_ADV(xp, &c, &xp);
      MASSTOR_ADV(U1, &u, &U1);
      u = SACRN_RNPROD(u, c);
      y = SACRN_RNSUM(y, u);
    }
    xp = MASSTOR_SIL;
    while (MASSTOR_RED(U1) != MASSTOR_SIL) {
      U1 = MASSTOR_RED(U1);
      xp = MASSTOR_COMP(0, xp);
    }
    MASSTOR_ADV(U1, &u, &U1);
    MASSTOR_ADV(b1, &c, &b1);
    c = SACRN_RNDIF(c, y);
    a = SACRN_RNQ(c, u);
    xp = MASSTOR_COMP(a, xp);
    xp = MASSTOR_INV(xp);
    x = SACLIST_CONC(x, xp);
  }
  x = MASSTOR_INV(x);
  return x;
}

MASSTOR_LIST LINALGRN_RNMSDS
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST U, MASSTOR_LIST b)
# else
(L, U, b)
MASSTOR_LIST L, U, b;
# endif
{
  MASSTOR_LIST u, x;

  u = LINALGRN_RNMLT(L, b);
  if (u != MASSTOR_SIL) {
    x = LINALGRN_RNMUT(U, u);
  } else {
    x = MASSTOR_SIL;
  }
  return x;
}

MASSTOR_LIST LINALGRN_RNMINV
# ifdef __STDC__
(MASSTOR_LIST C_50_A)
# else
(C_50_A)
MASSTOR_LIST C_50_A;
# endif
{
  MASSTOR_LIST B, l, u, n, E, e, x;

  n = MASSTOR_LENGTH(C_50_A);
  B = MASSTOR_SIL;
  if (n <= 0) {
    return B;
  }
  if (n != MASSTOR_LENGTH(MASSTOR_FIRST(C_50_A))) {
    return B;
  }
  LINALGRN_RNMGELUD(C_50_A, &l, &u);
  E = LINALGRN_RNUM(n, n);
  while (E != MASSTOR_SIL) {
    MASSTOR_ADV(E, &e, &E);
    x = LINALGRN_RNMSDS(l, u, e);
    if (x == MASSTOR_SIL) {
      return MASSTOR_SIL;
    }
    B = MASSTOR_COMP(x, B);
  }
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST LINALGRN_RNMUNS
# ifdef __STDC__
(MASSTOR_LIST U)
# else
(U)
MASSTOR_LIST U;
# endif
{
  MASSTOR_LIST UP, V, N, Z, ZP, e, a, c, u, up, b, i, n, m, j;

  UP = SACLIST_CINV(U);
  N = MASSTOR_SIL;
  Z = MASSTOR_SIL;
  i = 0;
  e = SACRN_RNINT(1);
  while (UP != MASSTOR_SIL) {
    MASSTOR_ADV(UP, &u, &UP);
    n = MASSTOR_LENGTH(u) - 1;
    if (i < n) {
      MASSTOR_ADV(u, &b, &u);
      while (i < n) {
        i = i + 1;
        j = i;
        ZP = MASSTOR_COMP(e, Z);
        Z = MASSTOR_COMP(0, Z);
        while (j < n) {
          j = j + 1;
          ZP = MASSTOR_COMP(0, ZP);
        }
        a = LINALGRN_RNVSPROD(u, ZP);
        c = SACRN_RNNEG(a);
        a = SACRN_RNQ(c, b);
        j = j + 1;
        ZP = MASSTOR_COMP(a, ZP);
        V = UP;
        while (V != MASSTOR_SIL) {
          MASSTOR_ADV(V, &up, &V);
          m = MASSTOR_LENGTH(up) - 1;
          while (j < m) {
            j = j + 1;
            ZP = MASSTOR_COMP(0, ZP);
          }
          MASSTOR_ADV(up, &c, &up);
          a = LINALGRN_RNVSPROD(up, ZP);
          a = SACRN_RNNEG(a);
          a = SACRN_RNQ(a, c);
          j = j + 1;
          ZP = MASSTOR_COMP(a, ZP);
        }
        N = MASSTOR_COMP(ZP, N);
      }
    }
    i = n + 1;
  }
  N = MASSTOR_INV(N);
  return N;
}

void BEGIN_LINALGRN()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASELEM();
    BEGIN_MASBIOS();
    BEGIN_MASSTOR();
    BEGIN_MASERR();
    BEGIN_SACLIST();
    BEGIN_SACRN();
    BEGIN_MASRN();
    BEGIN_MASAPF();

  }
}
