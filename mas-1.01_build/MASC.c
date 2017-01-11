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

#ifndef DEFINITION_MASC
#include "MASC.h"
#endif

CHAR MASC_rcsid [] = "$Id: MASC.md,v 1.2 1992/09/28 18:34:51 kredel Exp $";
CHAR MASC_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASC.mi,v 1.3 1992/10/15 16:28:10 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST MASC_CABS
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
  S = SACRN_RNSUM(SACRN_RNPROD(r, r), SACRN_RNPROD(i, i));
  return S;
}

MASSTOR_LIST MASC_CCON
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
  S = SACLIST_COMP2(r, SACRN_RNNEG(i), MASSTOR_SIL);
  return S;
}

MASSTOR_LIST MASC_CCOMP
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

MASSTOR_LIST MASC_CDIF
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST S)
# else
(R, S)
MASSTOR_LIST R, S;
# endif
{
  MASSTOR_LIST T, r1, i1, r2, i2;

  if (R == 0) {
    T = MASC_CNEG(S);
    return T;
  }
  if (S == 0) {
    T = R;
    return T;
  }
  SACLIST_FIRST2(R, &r1, &i1);
  SACLIST_FIRST2(S, &r2, &i2);
  r1 = SACRN_RNDIF(r1, r2);
  i1 = SACRN_RNDIF(i1, i2);
  if (r1 == 0 && i1 == 0) {
    T = 0;
    return T;
  }
  T = SACLIST_COMP2(r1, i1, MASSTOR_SIL);
  return T;
}

MASSTOR_LIST MASC_CDREAD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST R, r, i, c;

  r = MASRN_RNDRD();
  i = 0;
  c = MASBIOS_CREADB();
  if (c == MASBIOS_MASORD('i')) {
    i = MASRN_RNDRD();
  } else {
    MASBIOS_BKSP();
  }
  if (r == 0 && i == 0) {
    return 0;
  }
  R = SACLIST_COMP2(r, i, MASSTOR_SIL);
  return R;
}

void MASC_CDWRITE
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
  MASRN_RNDWR(r, NL);
  if (i != 0) {
    MASBIOS_SWRITE(" i ", 3L);
    MASRN_RNDWR(i, NL);
  }
}

MASSTOR_LIST MASC_CEXP
# ifdef __STDC__
(MASSTOR_LIST C_21_A, MASSTOR_LIST NL)
# else
(C_21_A, NL)
MASSTOR_LIST C_21_A, NL;
# endif
{
  MASSTOR_LIST B, KL;

  if (NL == 0) {
    B = MASC_CINT(1);
    return B;
  }
  if (NL == 1) {
    B = C_21_A;
    return B;
  }
  KL = NL / 2;
  B = MASC_CEXP(C_21_A, KL);
  B = MASC_CPROD(B, B);
  if (NL > 2 * KL) {
    B = MASC_CPROD(B, C_21_A);
  }
  return B;
}

MASSTOR_LIST MASC_CIM
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

MASSTOR_LIST MASC_CINT
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
  R = SACLIST_COMP2(SACRN_RNINT(C_20_A), 0, MASSTOR_SIL);
  return R;
}

MASSTOR_LIST MASC_CRE
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

MASSTOR_LIST MASC_CRN
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
  R = SACLIST_COMP2(C_19_A, 0, MASSTOR_SIL);
  return R;
}

MASSTOR_LIST MASC_CRNP
# ifdef __STDC__
(MASSTOR_LIST C_18_A, MASSTOR_LIST B)
# else
(C_18_A, B)
MASSTOR_LIST C_18_A, B;
# endif
{
  MASSTOR_LIST R;

  if (C_18_A == 0 && B == 0) {
    return 0;
  }
  R = SACLIST_COMP2(C_18_A, B, MASSTOR_SIL);
  return R;
}

MASSTOR_LIST MASC_CNINV
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST S, r, i, a;

  if (R == 0) {
    MASERR_ERROR(MASERR_severe, "CINV: division by zero.", 23L);
  }
  SACLIST_FIRST2(R, &r, &i);
  a = SACRN_RNSUM(SACRN_RNPROD(r, r), SACRN_RNPROD(i, i));
  r = SACRN_RNQ(r, a);
  i = SACRN_RNQ(SACRN_RNNEG(i), a);
  S = SACLIST_COMP2(r, i, MASSTOR_SIL);
  return S;
}

MASSTOR_LIST MASC_CNEG
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
  S = SACLIST_COMP2(SACRN_RNNEG(r), SACRN_RNNEG(i), MASSTOR_SIL);
  return S;
}

MASSTOR_LIST MASC_CONE
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
  t = MASRN_RNONE(r);
  return t;
}

MASSTOR_LIST MASC_CPROD
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
  r = SACRN_RNDIF(SACRN_RNPROD(r1, r2), SACRN_RNPROD(i1, i2));
  i = SACRN_RNSUM(SACRN_RNPROD(r1, i2), SACRN_RNPROD(i1, r2));
  if (r == 0 && i == 0) {
    return 0;
  }
  T = SACLIST_COMP2(r, i, MASSTOR_SIL);
  return T;
}

MASSTOR_LIST MASC_CQ
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST S)
# else
(R, S)
MASSTOR_LIST R, S;
# endif
{
  MASSTOR_LIST T;

  T = MASC_CPROD(R, MASC_CNINV(S));
  return T;
}

MASSTOR_LIST MASC_CRAND
# ifdef __STDC__
(MASSTOR_LIST NL)
# else
(NL)
MASSTOR_LIST NL;
# endif
{
  MASSTOR_LIST T, r, i;

  r = SACRN_RNRAND(NL);
  i = SACRN_RNRAND(NL);
  if (r == 0 && i == 0) {
    return 0;
  }
  T = SACLIST_COMP2(r, i, MASSTOR_SIL);
  return T;
}

MASSTOR_LIST MASC_CNREAD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST R, r, i, c;

  r = SACRN_RNREAD();
  i = 0;
  c = MASBIOS_CREADB();
  if (c == MASBIOS_MASORD('i')) {
    i = SACRN_RNREAD();
  } else {
    MASBIOS_BKSP();
  }
  if (r == 0 && i == 0) {
    return 0;
  }
  R = SACLIST_COMP2(r, i, MASSTOR_SIL);
  return R;
}

MASSTOR_LIST MASC_CSUM
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
  r1 = SACRN_RNSUM(r1, r2);
  i1 = SACRN_RNSUM(i1, i2);
  if (r1 == 0 && i1 == 0) {
    T = 0;
    return T;
  }
  T = SACLIST_COMP2(r1, i1, MASSTOR_SIL);
  return T;
}

void MASC_CNWRITE
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
  SACRN_RNWRIT(r);
  if (i != 0) {
    MASBIOS_SWRITE(" i ", 3L);
    SACRN_RNWRIT(i);
  }
}

void BEGIN_MASC()
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
