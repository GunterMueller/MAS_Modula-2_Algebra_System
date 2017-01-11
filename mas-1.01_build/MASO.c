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

#ifndef DEFINITION_MASQ
#include "MASQ.h"
#endif

#ifndef DEFINITION_MASO
#include "MASO.h"
#endif

CHAR MASO_rcsid [] = "$Id: MASO.md,v 1.2 1992/09/28 18:34:52 kredel Exp $";
CHAR MASO_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASO.mi,v 1.3 1992/10/15 16:28:13 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST MASO_OABS
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST S, r, i;

  if (R == 0) {
    S = R;
    return S;
  }
  SACLIST_FIRST2(R, &r, &i);
  S = SACRN_RNSUM(MASQ_QABS(r), MASQ_QABS(i));
  return S;
}

MASSTOR_LIST MASO_OCON
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST S, r, i;

  if (R == 0) {
    return 0;
  }
  SACLIST_FIRST2(R, &r, &i);
  S = SACLIST_COMP2(MASQ_QCON(r), MASQ_QNEG(i), MASSTOR_SIL);
  return S;
}

MASSTOR_LIST MASO_OCOMP
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

MASSTOR_LIST MASO_ODIF
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST S)
# else
(R, S)
MASSTOR_LIST R, S;
# endif
{
  MASSTOR_LIST T, r1, i1, r2, i2;

  if (R == 0) {
    T = MASO_ONEG(S);
    return T;
  }
  if (S == 0) {
    T = R;
    return T;
  }
  SACLIST_FIRST2(R, &r1, &i1);
  SACLIST_FIRST2(S, &r2, &i2);
  r1 = MASQ_QDIF(r1, r2);
  i1 = MASQ_QDIF(i1, i2);
  if (r1 == 0 && i1 == 0) {
    T = 0;
    return T;
  }
  T = SACLIST_COMP2(r1, i1, MASSTOR_SIL);
  return T;
}

MASSTOR_LIST MASO_ODREAD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST R, r, i, c;

  r = MASQ_QDREAD();
  i = 0;
  c = MASBIOS_CREADB();
  if (c == MASBIOS_MASORD('p')) {
    i = MASQ_QDREAD();
  } else {
    MASBIOS_BKSP();
  }
  if (r == 0 && i == 0) {
    return 0;
  }
  R = SACLIST_COMP2(r, i, MASSTOR_SIL);
  return R;
}

void MASO_ODWRITE
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST NL)
# else
(R, NL)
MASSTOR_LIST R, NL;
# endif
{
  MASSTOR_LIST r, i;

  if (R == 0) {
    SACLIST_AWRITE(R);
    return;
  }
  SACLIST_FIRST2(R, &r, &i);
  MASQ_QDWRITE(r, NL);
  if (i != 0) {
    MASBIOS_SWRITE(" p ", 3L);
    MASQ_QDWRITE(i, NL);
  }
}

MASSTOR_LIST MASO_OEXP
# ifdef __STDC__
(MASSTOR_LIST C_23_A, MASSTOR_LIST NL)
# else
(C_23_A, NL)
MASSTOR_LIST C_23_A, NL;
# endif
{
  MASSTOR_LIST B, KL;

  if (NL == 0) {
    B = MASO_OINT(1);
    return B;
  }
  if (NL == 1) {
    B = C_23_A;
    return B;
  }
  KL = NL / 2;
  B = MASO_OEXP(C_23_A, KL);
  B = MASO_OPROD(B, B);
  if (NL > 2 * KL) {
    B = MASO_OPROD(B, C_23_A);
  }
  return B;
}

MASSTOR_LIST MASO_OIM
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

MASSTOR_LIST MASO_OINT
# ifdef __STDC__
(MASSTOR_LIST C_22_A)
# else
(C_22_A)
MASSTOR_LIST C_22_A;
# endif
{
  MASSTOR_LIST R;

  if (C_22_A == 0) {
    R = C_22_A;
    return R;
  }
  R = SACLIST_COMP2(MASQ_QINT(C_22_A), 0, MASSTOR_SIL);
  return R;
}

MASSTOR_LIST MASO_ORE
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

MASSTOR_LIST MASO_ORN
# ifdef __STDC__
(MASSTOR_LIST C_21_A)
# else
(C_21_A)
MASSTOR_LIST C_21_A;
# endif
{
  MASSTOR_LIST R;

  if (C_21_A == 0) {
    return 0;
  }
  R = SACLIST_COMP2(MASQ_QRN(C_21_A), 0, MASSTOR_SIL);
  return R;
}

MASSTOR_LIST MASO_ORNP
# ifdef __STDC__
(MASSTOR_LIST C_20_A, MASSTOR_LIST B)
# else
(C_20_A, B)
MASSTOR_LIST C_20_A, B;
# endif
{
  MASSTOR_LIST R;

  if (C_20_A == 0 && B == 0) {
    return 0;
  }
  R = SACLIST_COMP2(C_20_A, B, MASSTOR_SIL);
  return R;
}

MASSTOR_LIST MASO_ONINV
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST S, t, r, i, r1, i1, a;

  if (R == 0) {
    MASERR_ERROR(MASERR_severe, "OINV: division by zero.", 23L);
  }
  a = MASO_OABS(R);
  S = MASO_OCON(R);
  SACLIST_FIRST2(S, &r, &i);
  r1 = 0;
  i1 = 0;
  if (r != 0) {
    r1 = MASSTOR_SIL;
    while (r != MASSTOR_SIL) {
      MASSTOR_ADV(r, &t, &r);
      t = SACRN_RNQ(t, a);
      r1 = MASSTOR_COMP(t, r1);
    }
    r1 = MASSTOR_INV(r1);
  }
  if (i != 0) {
    i1 = MASSTOR_SIL;
    while (i != MASSTOR_SIL) {
      MASSTOR_ADV(i, &t, &i);
      t = SACRN_RNQ(t, a);
      i1 = MASSTOR_COMP(t, i1);
    }
    i1 = MASSTOR_INV(i1);
  }
  S = SACLIST_COMP2(r1, i1, MASSTOR_SIL);
  return S;
}

MASSTOR_LIST MASO_ONEG
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST S, r, i;

  if (R == 0) {
    return 0;
  }
  SACLIST_FIRST2(R, &r, &i);
  S = SACLIST_COMP2(MASQ_QNEG(r), MASQ_QNEG(i), MASSTOR_SIL);
  return S;
}

MASSTOR_LIST MASO_OONE
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST r, i, t;

  if (R == 0) {
    return 0;
  }
  SACLIST_FIRST2(R, &r, &i);
  if (i != 0) {
    return 0;
  }
  t = MASQ_QONE(r);
  return t;
}

MASSTOR_LIST MASO_OPROD
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST S)
# else
(R, S)
MASSTOR_LIST R, S;
# endif
{
  MASSTOR_LIST T, r1, i1, r2, i2, r, i;

  if (R == 0 || S == 0) {
    return 0;
  }
  SACLIST_FIRST2(R, &r1, &i1);
  SACLIST_FIRST2(S, &r2, &i2);
  r = MASQ_QDIF(MASQ_QPROD(r1, r2), MASQ_QPROD(MASQ_QCON(i2), i1));
  i = MASQ_QSUM(MASQ_QPROD(i1, MASQ_QCON(r2)), MASQ_QPROD(i2, r1));
  if (r == 0 && i == 0) {
    return 0;
  }
  T = SACLIST_COMP2(r, i, MASSTOR_SIL);
  return T;
}

MASSTOR_LIST MASO_OQ
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST S)
# else
(R, S)
MASSTOR_LIST R, S;
# endif
{
  MASSTOR_LIST T;

  T = MASO_OPROD(R, MASO_ONINV(S));
  return T;
}

MASSTOR_LIST MASO_ORAND
# ifdef __STDC__
(MASSTOR_LIST NL)
# else
(NL)
MASSTOR_LIST NL;
# endif
{
  MASSTOR_LIST T, r, i;

  r = MASQ_QRAND(NL);
  i = MASQ_QRAND(NL);
  if (r == 0 && i == 0) {
    return 0;
  }
  T = SACLIST_COMP2(r, i, MASSTOR_SIL);
  return T;
}

MASSTOR_LIST MASO_ONREAD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST R, r, i, c;

  r = MASQ_QNREAD();
  i = 0;
  c = MASBIOS_CREADB();
  if (c == MASBIOS_MASORD('p')) {
    i = MASQ_QNREAD();
  } else {
    MASBIOS_BKSP();
  }
  if (r == 0 && i == 0) {
    return 0;
  }
  R = SACLIST_COMP2(r, i, MASSTOR_SIL);
  return R;
}

MASSTOR_LIST MASO_OSUM
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST S)
# else
(R, S)
MASSTOR_LIST R, S;
# endif
{
  MASSTOR_LIST T, r1, i1, r2, i2;

  if (R == 0) {
    T = S;
    return T;
  }
  if (S == 0) {
    T = R;
    return T;
  }
  SACLIST_FIRST2(R, &r1, &i1);
  SACLIST_FIRST2(S, &r2, &i2);
  r1 = MASQ_QSUM(r1, r2);
  i1 = MASQ_QSUM(i1, i2);
  if (r1 == 0 && i1 == 0) {
    T = 0;
    return T;
  }
  T = SACLIST_COMP2(r1, i1, MASSTOR_SIL);
  return T;
}

void MASO_ONWRITE
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST r, i;

  if (R == 0) {
    SACLIST_AWRITE(R);
    return;
  }
  SACLIST_FIRST2(R, &r, &i);
  MASQ_QNWRITE(r);
  if (i != 0) {
    MASBIOS_SWRITE(" p ", 3L);
    MASQ_QNWRITE(i);
  }
}

void BEGIN_MASO()
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
    BEGIN_MASQ();

  }
}
