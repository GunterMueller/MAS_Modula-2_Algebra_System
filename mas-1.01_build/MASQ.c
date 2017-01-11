#include "SYSTEM_.h"

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

#ifndef DEFINITION_MASQ
#include "MASQ.h"
#endif

CHAR MASQ_rcsid [] = "$Id: MASQ.md,v 1.2 1992/09/28 18:34:54 kredel Exp $";
CHAR MASQ_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASQ.mi,v 1.3 1992/10/15 16:28:14 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST MASQ_QABS
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST S, r, i, j, k;

  if (R == 0) {
    S = R;
    return S;
  }
  SACLIST_FIRST4(R, &r, &i, &j, &k);
  S = SACRN_RNSUM(SACRN_RNPROD(r, r), SACRN_RNPROD(i, i));
  S = SACRN_RNSUM(S, SACRN_RNPROD(j, j));
  S = SACRN_RNSUM(S, SACRN_RNPROD(k, k));
  return S;
}

MASSTOR_LIST MASQ_QCON
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST S, r, i, j, k;

  if (R == 0) {
    return 0;
  }
  SACLIST_FIRST4(R, &r, &i, &j, &k);
  S = SACLIST_COMP4(r, SACRN_RNNEG(i), SACRN_RNNEG(j), SACRN_RNNEG(k), MASSTOR_SIL);
  return S;
}

MASSTOR_LIST MASQ_QCOMP
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST S)
# else
(R, S)
MASSTOR_LIST R, S;
# endif
{
  MASSTOR_LIST t;

  t = SACLIST_EQUAL(R, S);
  if (t == 1) {
    t = 0;
  } else {
    t = 1;
  }
  return t;
}

MASSTOR_LIST MASQ_QDIF
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST S)
# else
(R, S)
MASSTOR_LIST R, S;
# endif
{
  MASSTOR_LIST T, r1, i1, j1, k1, r2, i2, j2, k2;

  if (R == 0) {
    T = MASQ_QNEG(S);
    return T;
  }
  if (S == 0) {
    T = R;
    return T;
  }
  SACLIST_FIRST4(R, &r1, &i1, &j1, &k1);
  SACLIST_FIRST4(S, &r2, &i2, &j2, &k2);
  r1 = SACRN_RNDIF(r1, r2);
  i1 = SACRN_RNDIF(i1, i2);
  j1 = SACRN_RNDIF(j1, j2);
  k1 = SACRN_RNDIF(k1, k2);
  if (r1 == 0 && i1 == 0 && j1 == 0 && k1 == 0) {
    return 0;
  }
  T = SACLIST_COMP4(r1, i1, j1, k1, MASSTOR_SIL);
  return T;
}

MASSTOR_LIST MASQ_QDREAD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST R, r, i, j, k, c;

  r = MASRN_RNDRD();
  i = 0;
  c = MASBIOS_CREADB();
  if (c == MASBIOS_MASORD('i')) {
    i = MASRN_RNDRD();
  } else {
    MASBIOS_BKSP();
  }
  c = MASBIOS_CREADB();
  if (c == MASBIOS_MASORD('j')) {
    j = MASRN_RNDRD();
  } else {
    MASBIOS_BKSP();
  }
  c = MASBIOS_CREADB();
  if (c == MASBIOS_MASORD('k')) {
    k = MASRN_RNDRD();
  } else {
    MASBIOS_BKSP();
  }
  if (r == 0 && i == 0 && j == 0 && k == 0) {
    return 0;
  }
  R = SACLIST_COMP4(r, i, j, k, MASSTOR_SIL);
  return R;
}

void MASQ_QDWRITE
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST NL)
# else
(R, NL)
MASSTOR_LIST R, NL;
# endif
{
  MASSTOR_LIST r, i, j, k;

  if (R == 0) {
    SACLIST_AWRITE(R);
    return;
  }
  SACLIST_FIRST4(R, &r, &i, &j, &k);
  MASRN_RNDWR(r, NL);
  if (i != 0) {
    MASBIOS_SWRITE(" i ", 3L);
    MASRN_RNDWR(i, NL);
  }
  if (j != 0) {
    MASBIOS_SWRITE(" j ", 3L);
    MASRN_RNDWR(j, NL);
  }
  if (k != 0) {
    MASBIOS_SWRITE(" k ", 3L);
    MASRN_RNDWR(k, NL);
  }
}

MASSTOR_LIST MASQ_QEXP
# ifdef __STDC__
(MASSTOR_LIST C_21_A, MASSTOR_LIST NL)
# else
(C_21_A, NL)
MASSTOR_LIST C_21_A, NL;
# endif
{
  MASSTOR_LIST B, KL;

  if (NL == 0) {
    B = MASQ_QINT(1);
    return B;
  }
  if (NL == 1) {
    B = C_21_A;
    return B;
  }
  KL = NL / 2;
  B = MASQ_QEXP(C_21_A, KL);
  B = MASQ_QPROD(B, B);
  if (NL > 2 * KL) {
    B = MASQ_QPROD(B, C_21_A);
  }
  return B;
}

MASSTOR_LIST MASQ_QIMi
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  if (R == 0) {
    return 0;
  }
  return SACLIST_SECOND(R);
}

MASSTOR_LIST MASQ_QIMj
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  if (R == 0) {
    return 0;
  }
  return SACLIST_THIRD(R);
}

MASSTOR_LIST MASQ_QIMk
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  if (R == 0) {
    return 0;
  }
  return SACLIST_FOURTH(R);
}

MASSTOR_LIST MASQ_QINT
# ifdef __STDC__
(MASSTOR_LIST C_20_A)
# else
(C_20_A)
MASSTOR_LIST C_20_A;
# endif
{
  MASSTOR_LIST R;

  if (C_20_A == 0) {
    R = C_20_A;
    return R;
  }
  R = SACLIST_COMP4(SACRN_RNINT(C_20_A), 0, 0, 0, MASSTOR_SIL);
  return R;
}

MASSTOR_LIST MASQ_QRE
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  if (R == 0) {
    return 0;
  }
  return MASSTOR_FIRST(R);
}

MASSTOR_LIST MASQ_QRN
# ifdef __STDC__
(MASSTOR_LIST C_19_A)
# else
(C_19_A)
MASSTOR_LIST C_19_A;
# endif
{
  MASSTOR_LIST R;

  if (C_19_A == 0) {
    return 0;
  }
  R = SACLIST_COMP4(C_19_A, 0, 0, 0, MASSTOR_SIL);
  return R;
}

MASSTOR_LIST MASQ_QRN4
# ifdef __STDC__
(MASSTOR_LIST C_18_A, MASSTOR_LIST B, MASSTOR_LIST C, MASSTOR_LIST D)
# else
(C_18_A, B, C, D)
MASSTOR_LIST C_18_A, B, C, D;
# endif
{
  MASSTOR_LIST R;

  if (C_18_A == 0 && B == 0) {
    return 0;
  }
  R = SACLIST_COMP4(C_18_A, B, C, D, MASSTOR_SIL);
  return R;
}

MASSTOR_LIST MASQ_QINV
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST S, r, i, j, k, a;

  if (R == 0) {
    MASERR_ERROR(MASERR_severe, "QINV: division by zero.", 23L);
  }
  SACLIST_FIRST4(R, &r, &i, &j, &k);
  a = SACRN_RNSUM(SACRN_RNPROD(r, r), SACRN_RNPROD(i, i));
  a = SACRN_RNSUM(a, SACRN_RNPROD(j, j));
  a = SACRN_RNSUM(a, SACRN_RNPROD(k, k));
  r = SACRN_RNQ(r, a);
  i = SACRN_RNQ(SACRN_RNNEG(i), a);
  j = SACRN_RNQ(SACRN_RNNEG(j), a);
  k = SACRN_RNQ(SACRN_RNNEG(k), a);
  S = SACLIST_COMP4(r, i, j, k, MASSTOR_SIL);
  return S;
}

MASSTOR_LIST MASQ_QNEG
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST S, r, i, j, k;

  if (R == 0) {
    return 0;
  }
  SACLIST_FIRST4(R, &r, &i, &j, &k);
  S = SACLIST_COMP4(SACRN_RNNEG(r), SACRN_RNNEG(i), SACRN_RNNEG(j), SACRN_RNNEG(k), MASSTOR_SIL);
  return S;
}

MASSTOR_LIST MASQ_QONE
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST r, i, j, k, t;

  if (R == 0) {
    return 0;
  }
  SACLIST_FIRST4(R, &r, &i, &j, &k);
  if (i != 0 || j != 0 || k != 0) {
    return 0;
  }
  t = MASRN_RNONE(r);
  return t;
}

MASSTOR_LIST MASQ_QPROD
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST S)
# else
(R, S)
MASSTOR_LIST R, S;
# endif
{
  MASSTOR_LIST T, r1, i1, j1, k1, r2, i2, j2, k2, r, i, j, k;

  if (R == 0 || S == 0) {
    return 0;
  }
  SACLIST_FIRST4(R, &r1, &i1, &j1, &k1);
  SACLIST_FIRST4(S, &r2, &i2, &j2, &k2);
  r = SACRN_RNDIF(SACRN_RNPROD(r1, r2), SACRN_RNPROD(i1, i2));
  r = SACRN_RNDIF(r, SACRN_RNPROD(j1, j2));
  r = SACRN_RNDIF(r, SACRN_RNPROD(k1, k2));
  i = SACRN_RNSUM(SACRN_RNPROD(r1, i2), SACRN_RNPROD(i1, r2));
  i = SACRN_RNSUM(i, SACRN_RNPROD(j1, k2));
  i = SACRN_RNDIF(i, SACRN_RNPROD(k1, j2));
  j = SACRN_RNDIF(SACRN_RNPROD(r1, j2), SACRN_RNPROD(i1, k2));
  j = SACRN_RNSUM(j, SACRN_RNPROD(j1, r2));
  j = SACRN_RNSUM(j, SACRN_RNPROD(k1, i2));
  k = SACRN_RNSUM(SACRN_RNPROD(r1, k2), SACRN_RNPROD(i1, j2));
  k = SACRN_RNDIF(k, SACRN_RNPROD(j1, i2));
  k = SACRN_RNSUM(k, SACRN_RNPROD(k1, r2));
  if (r == 0 && i == 0 && j == 0 && k == 0) {
    return 0;
  }
  T = SACLIST_COMP4(r, i, j, k, MASSTOR_SIL);
  return T;
}

MASSTOR_LIST MASQ_QQ
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST S)
# else
(R, S)
MASSTOR_LIST R, S;
# endif
{
  MASSTOR_LIST T;

  T = MASQ_QPROD(R, MASQ_QINV(S));
  return T;
}

MASSTOR_LIST MASQ_QRAND
# ifdef __STDC__
(MASSTOR_LIST NL)
# else
(NL)
MASSTOR_LIST NL;
# endif
{
  MASSTOR_LIST T, r, i, j, k;

  r = SACRN_RNRAND(NL);
  i = SACRN_RNRAND(NL);
  j = SACRN_RNRAND(NL);
  k = SACRN_RNRAND(NL);
  if (r == 0 && i == 0 && j == 0 && k == 0) {
    return 0;
  }
  T = SACLIST_COMP4(r, i, j, k, MASSTOR_SIL);
  return T;
}

MASSTOR_LIST MASQ_QNREAD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST R, r, i, j, k, c;

  r = SACRN_RNREAD();
  i = 0;
  j = 0;
  k = 0;
  c = MASBIOS_CREADB();
  if (c == MASBIOS_MASORD('i')) {
    i = SACRN_RNREAD();
  } else {
    MASBIOS_BKSP();
  }
  c = MASBIOS_CREADB();
  if (c == MASBIOS_MASORD('j')) {
    j = SACRN_RNREAD();
  } else {
    MASBIOS_BKSP();
  }
  c = MASBIOS_CREADB();
  if (c == MASBIOS_MASORD('k')) {
    k = SACRN_RNREAD();
  } else {
    MASBIOS_BKSP();
  }
  if (r == 0 && i == 0 && j == 0 && k == 0) {
    return 0;
  }
  R = SACLIST_COMP4(r, i, j, k, MASSTOR_SIL);
  return R;
}

MASSTOR_LIST MASQ_QSUM
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST S)
# else
(R, S)
MASSTOR_LIST R, S;
# endif
{
  MASSTOR_LIST T, r1, i1, j1, k1, r2, i2, j2, k2;

  if (R == 0) {
    T = S;
    return T;
  }
  if (S == 0) {
    T = R;
    return T;
  }
  SACLIST_FIRST4(R, &r1, &i1, &j1, &k1);
  SACLIST_FIRST4(S, &r2, &i2, &j2, &k2);
  r1 = SACRN_RNSUM(r1, r2);
  i1 = SACRN_RNSUM(i1, i2);
  j1 = SACRN_RNSUM(j1, j2);
  k1 = SACRN_RNSUM(k1, k2);
  if (r1 == 0 && i1 == 0 && j1 == 0 && k1 == 0) {
    return 0;
  }
  T = SACLIST_COMP4(r1, i1, j1, k1, MASSTOR_SIL);
  return T;
}

void MASQ_QNWRITE
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST r, i, j, k;

  if (R == 0) {
    SACLIST_AWRITE(R);
    return;
  }
  SACLIST_FIRST4(R, &r, &i, &j, &k);
  SACRN_RNWRIT(r);
  if (i != 0) {
    MASBIOS_SWRITE(" i ", 3L);
    SACRN_RNWRIT(i);
  }
  if (j != 0) {
    MASBIOS_SWRITE(" j ", 3L);
    SACRN_RNWRIT(j);
  }
  if (k != 0) {
    MASBIOS_SWRITE(" k ", 3L);
    SACRN_RNWRIT(k);
  }
}

void BEGIN_MASQ()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASBIOS();
    BEGIN_MASSTOR();
    BEGIN_MASERR();
    BEGIN_SACLIST();
    BEGIN_SACRN();
    BEGIN_MASRN();

  }
}
