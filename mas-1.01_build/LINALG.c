#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_MASADOM
#include "MASADOM.h"
#endif

#ifndef DEFINITION_SACI
#include "SACI.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_LINALGI
#include "LINALGI.h"
#endif

#ifndef DEFINITION_LINALGRN
#include "LINALGRN.h"
#endif

#ifndef DEFINITION_MASI
#include "MASI.h"
#endif

#ifndef DEFINITION_LINALG
#include "LINALG.h"
#endif

CHAR LINALG_rcsid [] = "$Id: LINALG.md,v 1.1 1994/03/11 15:21:45 pesch Exp $";
CHAR LINALG_copyright [] = "Copyright (c) 1993 Universitaet Passau";

static CHAR rcsidi [] = "$Id: LINALG.mi,v 1.1 1994/03/11 15:21:46 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1993 Universitaet Passau";


MASSTOR_LIST LINALG_ADUM
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST n)
# else
(D, n)
MASSTOR_LIST D, n;
# endif
{
  MASSTOR_LIST C, c, i, j, e;

  C = MASSTOR_SIL;
  i = 0;
  while (i < n) {
    c = MASSTOR_SIL;
    i = i + 1;
    j = 0;
    while (j < n) {
      j = j + 1;
      if (i == j) {
        e = MASADOM_ADFI(D, 1);
      } else {
        e = MASADOM_ADFI(D, 0);
      }
      c = MASSTOR_COMP(e, c);
    }
    c = MASSTOR_INV(c);
    C = MASSTOR_COMP(c, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST LINALG_ADVSPROD
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST C_140_A, MASSTOR_LIST B)
# else
(D, C_140_A, B)
MASSTOR_LIST D, C_140_A, B;
# endif
{
  MASSTOR_LIST a, b, c, C;

  C = MASADOM_ADFI(D, 0);
  while (C_140_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_140_A, &a, &C_140_A);
    MASSTOR_ADV(B, &b, &B);
    c = MASADOM_ADPROD(a, b);
    C = MASADOM_ADSUM(c, C);
  }
  return C;
}

MASSTOR_LIST LINALG_ADVSVPROD
# ifdef __STDC__
(MASSTOR_LIST C_139_A, MASSTOR_LIST b)
# else
(C_139_A, b)
MASSTOR_LIST C_139_A, b;
# endif
{
  MASSTOR_LIST a, c, C;

  C = MASSTOR_SIL;
  while (C_139_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_139_A, &a, &C_139_A);
    c = MASADOM_ADPROD(a, b);
    C = MASSTOR_COMP(c, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST LINALG_ADVVSUM
# ifdef __STDC__
(MASSTOR_LIST C_138_A, MASSTOR_LIST B)
# else
(C_138_A, B)
MASSTOR_LIST C_138_A, B;
# endif
{
  MASSTOR_LIST a, b, c, C;

  C = MASSTOR_SIL;
  while (C_138_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_138_A, &a, &C_138_A);
    MASSTOR_ADV(B, &b, &B);
    c = MASADOM_ADSUM(a, b);
    C = MASSTOR_COMP(c, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST LINALG_ADSMPROD
# ifdef __STDC__
(MASSTOR_LIST C_137_A, MASSTOR_LIST b)
# else
(C_137_A, b)
MASSTOR_LIST C_137_A, b;
# endif
{
  MASSTOR_LIST a, c, C;

  if (C_137_A == MASSTOR_SIL) {
    return C_137_A;
  }
  C = MASSTOR_SIL;
  while (C_137_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_137_A, &a, &C_137_A);
    c = LINALG_ADVSVPROD(a, b);
    C = MASSTOR_COMP(c, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST LINALG_ADMSUM
# ifdef __STDC__
(MASSTOR_LIST C_136_A, MASSTOR_LIST B)
# else
(C_136_A, B)
MASSTOR_LIST C_136_A, B;
# endif
{
  MASSTOR_LIST a, b, c, C;

  if (C_136_A == MASSTOR_SIL) {
    return B;
  }
  if (B == MASSTOR_SIL) {
    return C_136_A;
  }
  C = MASSTOR_SIL;
  while (C_136_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_136_A, &a, &C_136_A);
    MASSTOR_ADV(B, &b, &B);
    c = LINALG_ADVVSUM(a, b);
    C = MASSTOR_COMP(c, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST LINALG_ADMPROD
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST C_135_A, MASSTOR_LIST B)
# else
(D, C_135_A, B)
MASSTOR_LIST D, C_135_A, B;
# endif
{
  MASSTOR_LIST H1, H2, C, C1, a, c, BP, BT, b;

  C = MASSTOR_SIL;
  if (C_135_A == MASSTOR_SIL) {
    return C;
  }
  if (B == MASSTOR_SIL) {
    return C;
  }
  H1 = MASSTOR_LENGTH(MASSTOR_FIRST(C_135_A));
  H2 = MASSTOR_LENGTH(B);
  if (H1 != H2) {
    return C;
  }
  BT = LINALGRN_MTRANS(B);
  while (C_135_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_135_A, &a, &C_135_A);
    C1 = MASSTOR_SIL;
    BP = BT;
    while (BP != MASSTOR_SIL) {
      MASSTOR_ADV(BP, &b, &BP);
      c = LINALG_ADVSPROD(D, a, b);
      C1 = MASSTOR_COMP(c, C1);
    }
    C1 = MASSTOR_INV(C1);
    C = MASSTOR_COMP(C1, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

void LINALG_ADVWRITE
# ifdef __STDC__
(MASSTOR_LIST C_134_A)
# else
(C_134_A)
MASSTOR_LIST C_134_A;
# endif
{
  MASSTOR_LIST a;

  MASBIOS_SWRITE("(", 1L);
  while (C_134_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_134_A, &a, &C_134_A);
    MASADOM_ADWRIT(a);
    if (C_134_A != MASSTOR_SIL) {
      MASBIOS_SWRITE(",", 1L);
    }
  }
  MASBIOS_SWRITE(")", 1L);
}

void LINALG_ADMWRITE
# ifdef __STDC__
(MASSTOR_LIST C_133_A)
# else
(C_133_A)
MASSTOR_LIST C_133_A;
# endif
{
  MASSTOR_LIST a;

  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("(", 1L);
  while (C_133_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_133_A, &a, &C_133_A);
    LINALG_ADVWRITE(a);
    if (C_133_A != MASSTOR_SIL) {
      MASBIOS_SWRITE(", ", 2L);
      MASBIOS_BLINES(0);
    }
  }
  MASBIOS_SWRITE(")", 1L);
  MASBIOS_BLINES(0);
}

MASSTOR_LIST LINALG_ADMTRACE
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST C_132_A)
# else
(D, C_132_A)
MASSTOR_LIST D, C_132_A;
# endif
{
  MASSTOR_LIST tr, i, a;

  tr = MASADOM_ADFI(D, 0);
  i = 0;
  while (C_132_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_132_A, &a, &C_132_A);
    i = i + 1;
    tr = MASADOM_ADSUM(tr, SACLIST_LELT(a, i));
  }
  return tr;
}

MASSTOR_LIST LINALG_ADMPTRACE
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST C_131_A, MASSTOR_LIST B)
# else
(D, C_131_A, B)
MASSTOR_LIST D, C_131_A, B;
# endif
{
  MASSTOR_LIST tr, a, b, H1, H2, BT;

  tr = MASADOM_ADFI(D, 0);
  if (C_131_A == MASSTOR_SIL || B == MASSTOR_SIL) {
    return tr;
  }
  H1 = MASSTOR_LENGTH(MASSTOR_FIRST(C_131_A));
  H2 = MASSTOR_LENGTH(B);
  if (H1 != H2) {
    return tr;
  }
  BT = LINALGRN_MTRANS(B);
  while (C_131_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_131_A, &a, &C_131_A);
    MASSTOR_ADV(BT, &b, &BT);
    tr = MASADOM_ADSUM(tr, LINALG_ADVSPROD(D, a, b));
  }
  return tr;
}

MASSTOR_LIST LINALG_ADCHARPOL
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST Q)
# else
(D, Q)
MASSTOR_LIST D, Q;
# endif
{
  MASSTOR_LIST L, l, C_130_A, B, sl, s, al, a, k, p;

  al = MASSTOR_LIST1(MASADOM_ADFI(D, 1));
  if (Q == MASSTOR_SIL) {
    return al;
  }
  p = MASSTOR_LENGTH(Q);
  L = MASSTOR_SIL;
  C_130_A = Q;
  k = 1;
  s = LINALG_ADMTRACE(D, C_130_A);
  sl = MASSTOR_LIST1(s);
  a = MASADOM_ADNEG(s);
  al = SACLIST_SUFFIX(al, a);
  while (k * k < p) {
    k = k + 1;
    L = MASSTOR_COMP(C_130_A, L);
    C_130_A = LINALG_ADMPROD(D, C_130_A, Q);
    s = LINALG_ADMTRACE(D, C_130_A);
    sl = MASSTOR_COMP(s, sl);
    a = MASADOM_ADQUOT(LINALG_ADVSPROD(D, sl, al), MASADOM_ADFI(D, -k));
    al = SACLIST_SUFFIX(al, a);
  }
  B = C_130_A;
  L = MASSTOR_INV(L);
  l = L;
  while (k < p) {
    k = k + 1;
    if (l == MASSTOR_SIL) {
      B = LINALG_ADMPROD(D, B, C_130_A);
      s = LINALG_ADMTRACE(D, B);
      l = L;
    } else {
      s = LINALG_ADMPTRACE(D, B, MASSTOR_FIRST(l));
      l = MASSTOR_RED(l);
    }
    sl = MASSTOR_COMP(s, sl);
    a = MASADOM_ADQUOT(LINALG_ADVSPROD(D, sl, al), MASADOM_ADFI(D, -k));
    al = SACLIST_SUFFIX(al, a);
  }
  return al;
}

MASSTOR_LIST LINALG_ADSIG
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST Q)
# else
(D, Q)
MASSTOR_LIST D, Q;
# endif
{
  MASSTOR_LIST al, p, n, a, s, sp, sn, t;

  p = 0;
  n = 0;
  al = LINALG_ADCHARPOL(D, Q);
  MASSTOR_ADV(al, &a, &al);
  sp = MASADOM_ADSIGN(a);
  sn = sp;
  t = 1;
  while (al != MASSTOR_SIL) {
    MASSTOR_ADV(al, &a, &al);
    t = -t;
    s = MASADOM_ADSIGN(a);
    if (s != 0) {
      if (sp != s) {
        p = p + 1;
        sp = s;
      }
      if (sn != s * t) {
        n = n + 1;
        sn = s * t;
      }
    }
  }
  return p - n;
}

MASSTOR_LIST LINALG_IMTRACE
# ifdef __STDC__
(MASSTOR_LIST C_129_A)
# else
(C_129_A)
MASSTOR_LIST C_129_A;
# endif
{
  MASSTOR_LIST tr, i, a;

  tr = 0;
  i = 0;
  while (C_129_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_129_A, &a, &C_129_A);
    i = i + 1;
    tr = SACI_ISUM(tr, SACLIST_LELT(a, i));
  }
  return tr;
}

MASSTOR_LIST LINALG_IMPTRACE
# ifdef __STDC__
(MASSTOR_LIST C_128_A, MASSTOR_LIST B)
# else
(C_128_A, B)
MASSTOR_LIST C_128_A, B;
# endif
{
  MASSTOR_LIST tr, a, b, H1, H2, BT;

  tr = 0;
  if (C_128_A == MASSTOR_SIL || B == MASSTOR_SIL) {
    return tr;
  }
  H1 = MASSTOR_LENGTH(MASSTOR_FIRST(C_128_A));
  H2 = MASSTOR_LENGTH(B);
  if (H1 != H2) {
    return tr;
  }
  BT = LINALGRN_MTRANS(B);
  while (C_128_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_128_A, &a, &C_128_A);
    MASSTOR_ADV(BT, &b, &BT);
    tr = SACI_ISUM(tr, LINALGI_IVSPROD(a, b));
  }
  return tr;
}

MASSTOR_LIST LINALG_ICHARPOL
# ifdef __STDC__
(MASSTOR_LIST Q)
# else
(Q)
MASSTOR_LIST Q;
# endif
{
  MASSTOR_LIST L, l, C_127_A, B, sl, s, al, a, k, p;

  al = MASSTOR_LIST1(1);
  if (Q == MASSTOR_SIL) {
    return al;
  }
  p = MASSTOR_LENGTH(Q);
  L = MASSTOR_SIL;
  C_127_A = Q;
  k = 1;
  s = LINALG_IMTRACE(C_127_A);
  sl = MASSTOR_LIST1(s);
  a = SACI_INEG(s);
  al = SACLIST_SUFFIX(al, a);
  while (k * k < p) {
    k = k + 1;
    L = MASSTOR_COMP(C_127_A, L);
    C_127_A = LINALGI_IMPROD(C_127_A, Q);
    s = LINALG_IMTRACE(C_127_A);
    sl = MASSTOR_COMP(s, sl);
    a = SACI_IQ(LINALGI_IVSPROD(sl, al), -k);
    al = SACLIST_SUFFIX(al, a);
  }
  B = C_127_A;
  L = MASSTOR_INV(L);
  l = L;
  while (k < p) {
    k = k + 1;
    if (l == MASSTOR_SIL) {
      B = LINALGI_IMPROD(B, C_127_A);
      s = LINALG_IMTRACE(B);
      l = L;
    } else {
      s = LINALG_IMPTRACE(B, MASSTOR_FIRST(l));
      l = MASSTOR_RED(l);
    }
    sl = MASSTOR_COMP(s, sl);
    a = SACI_IQ(LINALGI_IVSPROD(sl, al), -k);
    al = SACLIST_SUFFIX(al, a);
  }
  return al;
}

MASSTOR_LIST LINALG_ISIG
# ifdef __STDC__
(MASSTOR_LIST Q)
# else
(Q)
MASSTOR_LIST Q;
# endif
{
  MASSTOR_LIST al, p, n, a, s, sp, sn, t;

  p = 0;
  n = 0;
  al = LINALG_ICHARPOL(Q);
  MASSTOR_ADV(al, &a, &al);
  sp = SACI_ISIGNF(a);
  sn = sp;
  t = 1;
  while (al != MASSTOR_SIL) {
    MASSTOR_ADV(al, &a, &al);
    t = -t;
    s = SACI_ISIGNF(a);
    if (s != 0) {
      if (sp != s) {
        p = p + 1;
        sp = s;
      }
      if (sn != s * t) {
        n = n + 1;
        sn = s * t;
      }
    }
  }
  return p - n;
}

MASSTOR_LIST LINALG_IMRTPROD
# ifdef __STDC__
(MASSTOR_LIST C_126_A, MASSTOR_LIST B)
# else
(C_126_A, B)
MASSTOR_LIST C_126_A, B;
# endif
{
  MASSTOR_LIST C, c, a, ar, ars, Bs, b, br, brs;

  C = MASSTOR_SIL;
  if (C_126_A == MASSTOR_SIL || B == MASSTOR_SIL) {
    return C;
  }
  while (C_126_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_126_A, &ar, &C_126_A);
    Bs = B;
    while (Bs != MASSTOR_SIL) {
      MASSTOR_ADV(Bs, &br, &Bs);
      c = MASSTOR_SIL;
      ars = ar;
      while (ars != MASSTOR_SIL) {
        MASSTOR_ADV(ars, &a, &ars);
        brs = br;
        while (brs != MASSTOR_SIL) {
          MASSTOR_ADV(brs, &b, &brs);
          c = MASSTOR_COMP(MASI_IPROD(a, b), c);
        }
      }
      c = MASSTOR_INV(c);
      C = MASSTOR_COMP(c, C);
    }
  }
  C = MASSTOR_INV(C);
  return C;
}

void BEGIN_LINALG()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_MASADOM();
    BEGIN_SACI();
    BEGIN_MASBIOS();
    BEGIN_LINALGI();
    BEGIN_LINALGRN();
    BEGIN_MASI();

  }
}
