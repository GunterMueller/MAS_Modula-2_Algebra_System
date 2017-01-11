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

#ifndef DEFINITION_SACI
#include "SACI.h"
#endif

#ifndef DEFINITION_SACRN
#include "SACRN.h"
#endif

#ifndef DEFINITION_LINALGRN
#include "LINALGRN.h"
#endif

#ifndef DEFINITION_LINALGI
#include "LINALGI.h"
#endif

CHAR LINALGI_rcsid [] = "$Id: LINALGI.md,v 1.3 1995/11/05 09:21:55 kredel Exp $";
CHAR LINALGI_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: LINALGI.mi,v 1.6 1995/11/05 09:23:13 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
typedef MASSTOR_LIST (*F2) ARGS((MASSTOR_LIST, MASSTOR_LIST));
static MASSTOR_LIST ium ARGS((MASSTOR_LIST i, MASSTOR_LIST j));
static MASSTOR_LIST MAT ARGS((F2 f, MASSTOR_LIST m, MASSTOR_LIST n));


static MASSTOR_LIST ium
# ifdef __STDC__
(MASSTOR_LIST i, MASSTOR_LIST j)
# else
(i, j)
MASSTOR_LIST i, j;
# endif
{
  if (i == j) {
    return 1;
  } else {
    return 0;
  }
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

MASSTOR_LIST LINALGI_IUM
# ifdef __STDC__
(MASSTOR_LIST m, MASSTOR_LIST n)
# else
(m, n)
MASSTOR_LIST m, n;
# endif
{
  return MAT(ium, m, n);
}

void LINALGI_IVWRITE
# ifdef __STDC__
(MASSTOR_LIST C_105_A)
# else
(C_105_A)
MASSTOR_LIST C_105_A;
# endif
{
  MASSTOR_LIST a;

  MASBIOS_SWRITE("(", 1L);
  while (C_105_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_105_A, &a, &C_105_A);
    SACI_IWRITE(a);
    if (C_105_A != MASSTOR_SIL) {
      MASBIOS_SWRITE(", ", 2L);
    }
  }
  MASBIOS_SWRITE(")", 1L);
}

void LINALGI_IMWRITE
# ifdef __STDC__
(MASSTOR_LIST C_104_A)
# else
(C_104_A)
MASSTOR_LIST C_104_A;
# endif
{
  MASSTOR_LIST a;

  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("(", 1L);
  while (C_104_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_104_A, &a, &C_104_A);
    LINALGI_IVWRITE(a);
    if (C_104_A != MASSTOR_SIL) {
      MASBIOS_SWRITE(", ", 2L);
      MASBIOS_BLINES(0);
    }
  }
  MASBIOS_SWRITE(")", 1L);
  MASBIOS_BLINES(0);
}

MASSTOR_LIST LINALGI_IKM
# ifdef __STDC__
(MASSTOR_LIST C_103_A, MASSTOR_LIST B)
# else
(C_103_A, B)
MASSTOR_LIST C_103_A, B;
# endif
{
  MASSTOR_LIST a, b, c, d, C, D;

  C = MASSTOR_SIL;
  D = MASSTOR_SIL;
  a = MASSTOR_FIRST(C_103_A);
  b = MASSTOR_FIRST(B);
  if (a != (MASSTOR_LIST)0) {
    if (b != (MASSTOR_LIST)0) {
      while (C_103_A != MASSTOR_SIL) {
        MASSTOR_ADV(C_103_A, &c, &C_103_A);
        c = SACI_IPROD(c, b);
        C = MASSTOR_COMP(c, C);
        MASSTOR_ADV(B, &d, &B);
        d = SACI_IPROD(d, a);
        D = MASSTOR_COMP(d, D);
      }
      C_103_A = MASSTOR_INV(C);
      B = MASSTOR_INV(D);
      B = LINALGI_IVVDIF(B, C_103_A);
    }
  }
  return B;
}

MASSTOR_LIST LINALGI_IVVDIF
# ifdef __STDC__
(MASSTOR_LIST C_102_A, MASSTOR_LIST B)
# else
(C_102_A, B)
MASSTOR_LIST C_102_A, B;
# endif
{
  MASSTOR_LIST a, b, c, C, test;

  C = MASSTOR_SIL;
  while (C_102_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_102_A, &a, &C_102_A);
    MASSTOR_ADV(B, &b, &B);
    c = SACI_IDIF(a, b);
    C = MASSTOR_COMP(c, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST LINALGI_IVVSUM
# ifdef __STDC__
(MASSTOR_LIST C_101_A, MASSTOR_LIST B)
# else
(C_101_A, B)
MASSTOR_LIST C_101_A, B;
# endif
{
  MASSTOR_LIST a, b, c, C, test;

  C = MASSTOR_SIL;
  while (C_101_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_101_A, &a, &C_101_A);
    MASSTOR_ADV(B, &b, &B);
    c = SACI_ISUM(a, b);
    C = MASSTOR_COMP(c, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST LINALGI_IVSVSUM
# ifdef __STDC__
(MASSTOR_LIST C_100_A, MASSTOR_LIST B)
# else
(C_100_A, B)
MASSTOR_LIST C_100_A, B;
# endif
{
  MASSTOR_LIST a, b, c, C;

  C = MASSTOR_SIL;
  b = MASSTOR_FIRST(B);
  while (C_100_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_100_A, &a, &C_100_A);
    c = SACI_ISUM(a, b);
    C = MASSTOR_COMP(c, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST LINALGI_IVSSUM
# ifdef __STDC__
(MASSTOR_LIST C_99_A)
# else
(C_99_A)
MASSTOR_LIST C_99_A;
# endif
{
  MASSTOR_LIST a, c;

  c = 0;
  while (C_99_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_99_A, &a, &C_99_A);
    c = SACI_ISUM(a, c);
  }
  return c;
}

MASSTOR_LIST LINALGI_IVSVPROD
# ifdef __STDC__
(MASSTOR_LIST C_98_A, MASSTOR_LIST B)
# else
(C_98_A, B)
MASSTOR_LIST C_98_A, B;
# endif
{
  MASSTOR_LIST a, b, c, C;

  C = MASSTOR_SIL;
  b = MASSTOR_FIRST(B);
  while (C_98_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_98_A, &a, &C_98_A);
    c = SACI_IPROD(a, b);
    C = MASSTOR_COMP(c, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST LINALGI_IVVPROD
# ifdef __STDC__
(MASSTOR_LIST C_97_A, MASSTOR_LIST B)
# else
(C_97_A, B)
MASSTOR_LIST C_97_A, B;
# endif
{
  MASSTOR_LIST a, b, c, C;

  C = MASSTOR_SIL;
  while (C_97_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_97_A, &a, &C_97_A);
    MASSTOR_ADV(B, &b, &B);
    c = SACI_IPROD(a, b);
    C = MASSTOR_COMP(c, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST LINALGI_IVSPROD
# ifdef __STDC__
(MASSTOR_LIST C_96_A, MASSTOR_LIST B)
# else
(C_96_A, B)
MASSTOR_LIST C_96_A, B;
# endif
{
  MASSTOR_LIST a, b, c, C;

  C = 0;
  while (C_96_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_96_A, &a, &C_96_A);
    MASSTOR_ADV(B, &b, &B);
    c = SACI_IPROD(a, b);
    C = SACI_ISUM(c, C);
  }
  return C;
}

MASSTOR_LIST LINALGI_IVMAX
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
    element = SACI_IABSF(element);
    max = SACI_IMAX(max, element);
  }
  return max;
}

MASSTOR_LIST LINALGI_IMPROD
# ifdef __STDC__
(MASSTOR_LIST C_95_A, MASSTOR_LIST B)
# else
(C_95_A, B)
MASSTOR_LIST C_95_A, B;
# endif
{
  MASSTOR_LIST H1, H2, C, C1, a, c, BP, BT, b;

  C = MASSTOR_SIL;
  if (C_95_A == MASSTOR_SIL) {
    return C;
  }
  if (B == MASSTOR_SIL) {
    return C;
  }
  H1 = MASSTOR_LENGTH(MASSTOR_FIRST(C_95_A));
  H2 = MASSTOR_LENGTH(B);
  if (H1 != H2) {
    return C;
  }
  BT = LINALGRN_MTRANS(B);
  while (C_95_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_95_A, &a, &C_95_A);
    C1 = MASSTOR_SIL;
    BP = BT;
    while (BP != MASSTOR_SIL) {
      MASSTOR_ADV(BP, &b, &BP);
      c = LINALGI_IVSPROD(a, b);
      C1 = MASSTOR_COMP(c, C1);
    }
    C1 = MASSTOR_INV(C1);
    C = MASSTOR_COMP(C1, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST LINALGI_ISMPROD
# ifdef __STDC__
(MASSTOR_LIST C_94_A, MASSTOR_LIST B)
# else
(C_94_A, B)
MASSTOR_LIST C_94_A, B;
# endif
{
  MASSTOR_LIST a, b, c, C;

  if (C_94_A == MASSTOR_SIL) {
    return C_94_A;
  }
  C = MASSTOR_SIL;
  b = MASSTOR_LIST1(B);
  while (C_94_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_94_A, &a, &C_94_A);
    c = LINALGI_IVSVPROD(a, b);
    C = MASSTOR_COMP(c, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST LINALGI_IMDIF
# ifdef __STDC__
(MASSTOR_LIST C_93_A, MASSTOR_LIST B)
# else
(C_93_A, B)
MASSTOR_LIST C_93_A, B;
# endif
{
  MASSTOR_LIST a, b, c, C;

  if (C_93_A == MASSTOR_SIL) {
    B = LINALGI_ISMPROD(B, -1);
    return B;
  }
  if (B == MASSTOR_SIL) {
    return C_93_A;
  }
  C = MASSTOR_SIL;
  while (C_93_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_93_A, &a, &C_93_A);
    MASSTOR_ADV(B, &b, &B);
    c = LINALGI_IVVDIF(a, b);
    C = MASSTOR_COMP(c, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST LINALGI_IMSUM
# ifdef __STDC__
(MASSTOR_LIST C_92_A, MASSTOR_LIST B)
# else
(C_92_A, B)
MASSTOR_LIST C_92_A, B;
# endif
{
  MASSTOR_LIST a, b, c, C;

  if (C_92_A == MASSTOR_SIL) {
    return B;
  }
  if (B == MASSTOR_SIL) {
    return C_92_A;
  }
  C = MASSTOR_SIL;
  while (C_92_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_92_A, &a, &C_92_A);
    MASSTOR_ADV(B, &b, &B);
    c = LINALGI_IVVSUM(a, b);
    C = MASSTOR_COMP(c, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST LINALGI_IMMAX
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
    element = LINALGI_IVMAX(zeile);
    max = SACI_IMAX(max, element);
  }
  return max;
}

MASSTOR_LIST LINALGI_IVFRNV
# ifdef __STDC__
(MASSTOR_LIST C_91_A)
# else
(C_91_A)
MASSTOR_LIST C_91_A;
# endif
{
  MASSTOR_LIST AP, BP;

  LINALGI_IVFRNV1(C_91_A, MASSTOR_SIL, &AP, &BP);
  return AP;
}

void LINALGI_IVFRNV1
# ifdef __STDC__
(MASSTOR_LIST C_90_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *D)
# else
(C_90_A, B, C, D)
MASSTOR_LIST C_90_A, B;
MASSTOR_LIST *C, *D;
# endif
{
  MASSTOR_LIST ap, bp, d, a, c, b;

  *C = MASSTOR_SIL;
  *D = MASSTOR_SIL;
  ap = C_90_A;
  bp = B;
  d = 1;
  while (ap != MASSTOR_SIL) {
    MASSTOR_ADV(ap, &a, &ap);
    c = SACRN_RNDEN(a);
    d = SACI_ILCM(d, c);
  }
  while (bp != MASSTOR_SIL) {
    MASSTOR_ADV(bp, &a, &bp);
    c = SACRN_RNDEN(a);
    d = SACI_ILCM(d, c);
  }
  ap = C_90_A;
  bp = B;
  while (ap != MASSTOR_SIL) {
    MASSTOR_ADV(ap, &a, &ap);
    c = SACRN_RNDEN(a);
    b = SACI_IQ(d, c);
    c = SACRN_RNNUM(a);
    c = SACI_IPROD(c, b);
    *C = MASSTOR_COMP(c, *C);
  }
  while (bp != MASSTOR_SIL) {
    MASSTOR_ADV(bp, &a, &bp);
    c = SACRN_RNDEN(a);
    b = SACI_IQ(d, c);
    c = SACRN_RNNUM(a);
    c = SACI_IPROD(c, b);
    *D = MASSTOR_COMP(c, *D);
  }
  *C = MASSTOR_INV(*C);
  *D = MASSTOR_INV(*D);
}

MASSTOR_LIST LINALGI_IMFRNM
# ifdef __STDC__
(MASSTOR_LIST C_89_A)
# else
(C_89_A)
MASSTOR_LIST C_89_A;
# endif
{
  MASSTOR_LIST AP, BP;

  LINALGI_IMFRNM1(C_89_A, MASSTOR_SIL, &AP, &BP);
  return AP;
}

void LINALGI_IMFRNM1
# ifdef __STDC__
(MASSTOR_LIST C_88_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *D)
# else
(C_88_A, B, C, D)
MASSTOR_LIST C_88_A, B;
MASSTOR_LIST *C, *D;
# endif
{
  MASSTOR_LIST a, b, c, d;

  *C = MASSTOR_SIL;
  *D = MASSTOR_SIL;
  B = LINALGRN_MTRANS(B);
  while (C_88_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_88_A, &a, &C_88_A);
    if (B != MASSTOR_SIL) {
      MASSTOR_ADV(B, &b, &B);
    } else {
      b = MASSTOR_SIL;
    }
    LINALGI_IVFRNV1(a, b, &c, &d);
    *C = MASSTOR_COMP(c, *C);
    if (d != MASSTOR_SIL) {
      *D = MASSTOR_COMP(d, *D);
    }
  }
  *C = MASSTOR_INV(*C);
  *D = MASSTOR_INV(*D);
  *D = LINALGRN_MTRANS(*D);
}

MASSTOR_LIST LINALGI_IVLC
# ifdef __STDC__
(MASSTOR_LIST a, MASSTOR_LIST C_87_A, MASSTOR_LIST b, MASSTOR_LIST B)
# else
(a, C_87_A, b, B)
MASSTOR_LIST a, C_87_A, b, B;
# endif
{
  MASSTOR_LIST c, cp, C, ap, bp;

  C = MASSTOR_SIL;
  if (a == 0) {
    a = b;
    C_87_A = B;
    b = 0;
  }
  if (b == 0) {
    while (C_87_A != MASSTOR_SIL) {
      MASSTOR_ADV(C_87_A, &ap, &C_87_A);
      c = SACI_IPROD(a, ap);
      C = MASSTOR_COMP(c, C);
    }
    C = MASSTOR_INV(C);
    return C;
  }
  while (C_87_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_87_A, &ap, &C_87_A);
    MASSTOR_ADV(B, &bp, &B);
    c = SACI_IPROD(a, ap);
    cp = SACI_IPROD(b, bp);
    c = SACI_ISUM(c, cp);
    C = MASSTOR_COMP(c, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST LINALGI_IVSQ
# ifdef __STDC__
(MASSTOR_LIST a, MASSTOR_LIST C_86_A)
# else
(a, C_86_A)
MASSTOR_LIST a, C_86_A;
# endif
{
  MASSTOR_LIST c, C, ap, r;

  C = MASSTOR_SIL;
  while (C_86_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_86_A, &ap, &C_86_A);
    SACI_IQR(ap, a, &c, &r);
    if (r != 0) {
      MASERR_ERROR(MASERR_severe, "IVSQ: non zero remainder.", 25L);
    }
    C = MASSTOR_COMP(c, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

void LINALGI_IMGELUD
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST *L, MASSTOR_LIST *U)
# else
(M, L, U)
MASSTOR_LIST M;
MASSTOR_LIST *L, *U;
# endif
{
  MASSTOR_LIST F, C, CP, M1, MP, L1, a, b, c, MP1, MP2, V, n, Z;

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
  n = 0;
  F = 1;
  while (M1 != MASSTOR_SIL) {
    L1 = MASSTOR_SIL;
    MP1 = M1;
    M1 = MASSTOR_SIL;
    a = 0;
    while (MP1 != MASSTOR_SIL && a == 0) {
      MASSTOR_ADV(MP1, &C, &MP1);
      MASSTOR_ADV(C, &a, &CP);
      if (a == 0) {
        M1 = MASSTOR_COMP(CP, M1);
        L1 = MASSTOR_COMP(a, L1);
      }
    }
    if (a == 0) {
      F = 1;
    } else {
      L1 = MASSTOR_COMP(a, L1);
      L1 = MASSTOR_COMP(F, L1);
      MP2 = MASSTOR_INV(M1);
      M1 = MASSTOR_SIL;
      while (MP2 != MASSTOR_SIL) {
        MASSTOR_ADV(MP2, &V, &MP2);
        V = LINALGI_IVLC(a, V, 0, CP);
        if (F != 1) {
          V = LINALGI_IVSQ(F, V);
        }
        M1 = MASSTOR_COMP(V, M1);
      }
      while (MP1 != MASSTOR_SIL) {
        MASSTOR_ADV(MP1, &V, &MP1);
        MASSTOR_ADV(V, &b, &V);
        V = LINALGI_IVLC(a, V, SACI_INEG(b), CP);
        if (F != 1) {
          V = LINALGI_IVSQ(F, V);
        }
        M1 = MASSTOR_COMP(V, M1);
        L1 = MASSTOR_COMP(b, L1);
      }
      F = a;
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
  return;
}

MASSTOR_LIST LINALGI_IMLT
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST b)
# else
(L, b)
MASSTOR_LIST L, b;
# endif
{
  MASSTOR_LIST F, u, L1, b1, b2, c, l, d, a, e;

  u = MASSTOR_SIL;
  while (L != MASSTOR_SIL) {
    MASSTOR_ADV(L, &L1, &L);
    b1 = b;
    b = MASSTOR_SIL;
    b2 = MASSTOR_SIL;
    l = 0;
    while (L1 != MASSTOR_SIL && l == 0) {
      MASSTOR_ADV(L1, &l, &L1);
      MASSTOR_ADV(b1, &c, &b1);
      if (l == 0) {
        b2 = MASSTOR_COMP(c, b2);
      }
    }
    if (l == 0) {
      b = b2;
    } else {
      u = MASSTOR_COMP(c, u);
      e = l;
      MASSTOR_ADV(L1, &F, &L1);
      b2 = MASSTOR_INV(b2);
      while (b2 != MASSTOR_SIL) {
        MASSTOR_ADV(b2, &d, &b2);
        a = SACI_IPROD(e, d);
        if (F != 1) {
          a = SACI_IQ(a, F);
        }
        b = MASSTOR_COMP(a, b);
      }
      while (L1 != MASSTOR_SIL) {
        MASSTOR_ADV(L1, &l, &L1);
        MASSTOR_ADV(b1, &d, &b1);
        d = SACI_IPROD(e, d);
        a = SACI_IPROD(l, c);
        a = SACI_IDIF(d, a);
        if (F != 1) {
          a = SACI_IQ(a, F);
        }
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

MASSTOR_LIST LINALGI_IMUT
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST b)
# else
(U, b)
MASSTOR_LIST U, b;
# endif
{
  MASSTOR_LIST UP, x, bp;

  UP = LINALGRN_RNMFIM(U);
  bp = LINALGRN_RNVFIV(b);
  x = LINALGRN_RNMUT(UP, bp);
  return x;
}

MASSTOR_LIST LINALGI_IMGE
# ifdef __STDC__
(MASSTOR_LIST M)
# else
(M)
MASSTOR_LIST M;
# endif
{
  MASSTOR_LIST i, j, u, MP, l;

  i = MASSTOR_LENGTH(M);
  if (M != MASSTOR_SIL) {
    j = MASSTOR_LENGTH(MASSTOR_FIRST(M));
  } else {
    j = 0;
  }
  LINALGI_IMGELUD(M, &l, &u);
  MP = LINALGRN_MFILL(u, i, j);
  return MP;
}

MASSTOR_LIST LINALGI_IMSDS
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST U, MASSTOR_LIST b)
# else
(L, U, b)
MASSTOR_LIST L, U, b;
# endif
{
  MASSTOR_LIST u, x;

  u = LINALGI_IMLT(L, b);
  if (u != MASSTOR_SIL) {
    x = LINALGI_IMUT(U, u);
  } else {
    x = MASSTOR_SIL;
  }
  return x;
}

MASSTOR_LIST LINALGI_RNMINVI
# ifdef __STDC__
(MASSTOR_LIST C_85_A)
# else
(C_85_A)
MASSTOR_LIST C_85_A;
# endif
{
  MASSTOR_LIST B, C, n, E, e, x, AP, EP, u, UP, L, U;

  n = MASSTOR_LENGTH(C_85_A);
  B = MASSTOR_SIL;
  if (n <= 0) {
    return B;
  }
  if (n != MASSTOR_LENGTH(MASSTOR_FIRST(C_85_A))) {
    return B;
  }
  E = LINALGRN_RNUM(n, n);
  LINALGI_IMFRNM1(C_85_A, E, &AP, &EP);
  LINALGI_IMGELUD(AP, &L, &U);
  UP = LINALGRN_RNMFIM(U);
  while (EP != MASSTOR_SIL) {
    MASSTOR_ADV(EP, &e, &EP);
    u = LINALGI_IMLT(L, e);
    if (u == MASSTOR_SIL) {
      return MASSTOR_SIL;
    }
    u = LINALGRN_RNVFIV(u);
    x = LINALGRN_RNMUT(UP, u);
    if (x == MASSTOR_SIL) {
      return MASSTOR_SIL;
    }
    B = MASSTOR_COMP(x, B);
  }
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST LINALGI_IMUNS
# ifdef __STDC__
(MASSTOR_LIST U)
# else
(U)
MASSTOR_LIST U;
# endif
{
  MASSTOR_LIST UP, N;

  UP = LINALGRN_RNMFIM(U);
  N = LINALGRN_RNMUNS(UP);
  return N;
}

MASSTOR_LIST LINALGI_IMDETL
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
    if (V == MASSTOR_SIL) {
      return d;
    }
    MASSTOR_ADV(V, &d, &V);
    if (V != MASSTOR_SIL) {
      d = 0;
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
      dp = LINALGI_IMDETL(N);
      dp = SACI_IPROD(v, dp);
      if (s < 0) {
        dp = SACI_INEG(dp);
      }
      d = SACI_ISUM(d, dp);
    }
    s = -s;
  }
  return d;
}

MASSTOR_LIST LINALGI_IMDET
# ifdef __STDC__
(MASSTOR_LIST M)
# else
(M)
MASSTOR_LIST M;
# endif
{
  MASSTOR_LIST F, d, s, i, C, CP, M1, MP, a, b, c, MP1, MP2, V, e;

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
  e = 1;
  d = e;
  F = 1;
  while (M1 != MASSTOR_SIL) {
    MP1 = M1;
    M1 = MASSTOR_SIL;
    a = 0;
    i = 0;
    while (MP1 != MASSTOR_SIL && a == 0) {
      MASSTOR_ADV(MP1, &C, &MP1);
      i = i + 1;
      MASSTOR_ADV(C, &a, &CP);
      if (a == 0) {
        M1 = MASSTOR_COMP(CP, M1);
      }
    }
    if (a == 0) {
      d = 0;
      return d;
    }
    if (MASELEM_MASEVEN(i)) {
      s = -s;
    }
    d = a;
    MP2 = MASSTOR_INV(M1);
    M1 = MASSTOR_SIL;
    while (MP2 != MASSTOR_SIL) {
      MASSTOR_ADV(MP2, &V, &MP2);
      V = LINALGI_IVLC(a, V, 0, CP);
      if (F != 1) {
        V = LINALGI_IVSQ(F, V);
      }
      M1 = MASSTOR_COMP(V, M1);
    }
    while (MP1 != MASSTOR_SIL) {
      MASSTOR_ADV(MP1, &V, &MP1);
      MASSTOR_ADV(V, &b, &V);
      V = LINALGI_IVLC(a, V, SACI_INEG(b), CP);
      if (F != 1) {
        V = LINALGI_IVSQ(F, V);
      }
      M1 = MASSTOR_COMP(V, M1);
    }
    M1 = MASSTOR_INV(M1);
    F = a;
    if (M1 != MASSTOR_SIL) {
      if (MASSTOR_FIRST(M1) == MASSTOR_SIL) {
        d = 0;
        return d;
      }
    }
  }
  if (s < 0) {
    d = SACI_INEG(d);
  }
  return d;
}

void BEGIN_LINALGI()
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
    BEGIN_SACI();
    BEGIN_SACRN();
    BEGIN_LINALGRN();

  }
}
