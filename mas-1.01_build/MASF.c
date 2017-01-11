#include "SYSTEM_.h"

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
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

#ifndef DEFINITION_MathLib
#include "MathLib.h"
#endif

#ifndef DEFINITION_MASF
#include "MASF.h"
#endif

MASF_MFLOAT MASF_FBETA;
MASF_MFLOAT MASF_FBETAH;
MASELEM_GAMMAINT MASF_BETAH;
MASSTOR_LIST MASF_IBETA;
CHAR MASF_rcsid [] = "$Id: MASF.md,v 1.3 1992/10/16 13:52:04 kredel Exp $";
CHAR MASF_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASF.mi,v 1.4 1992/10/16 13:52:05 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
static void InitFLOAT ARGS(());


MASF_MFLOAT MASF_FFGI
# ifdef __STDC__
(MASELEM_GAMMAINT N)
# else
(N)
MASELEM_GAMMAINT N;
# endif
{
  MASF_MFLOAT f;

  f = MathLib_real(N);
  return f;
}

MASSTOR_LIST MASF_IFF
# ifdef __STDC__
(MASF_MFLOAT F)
# else
(F)
MASF_MFLOAT F;
# endif
{
  MASELEM_GAMMAINT g, h;
  MASF_MFLOAT f;

  if (F >= 0.0) {
    f = F;
    h = 1;
  } else {
    f = -F;
    h = -1;
  }
  while (f >= MASF_FBETA) {
    f = f / MASF_FBETA;
    h = SACI_IPROD(h, MASF_IBETA);
  }
  g = MathLib_entier(f);
  h = SACI_IPROD(h, g);
  return h;
}

MASF_MFLOAT MASF_FEXP
# ifdef __STDC__
(MASF_MFLOAT F, MASELEM_GAMMAINT N)
# else
(F, N)
MASF_MFLOAT F;
MASELEM_GAMMAINT N;
# endif
{
  INTEGER i;
  MASF_MFLOAT f;

  if (F == 0.0) {
    return F;
  }
  f = 1.0;
  if (N == 0) {
    return f;
  }
  if (N < 0) {
    N = -N;
    f = 1.0 / f;
  }
  {
    LONGINT B_1 = 1, B_2 = N;

    if (B_1 <= B_2)
      for (i = B_1;; i += 1) {
        f = f * F;
        if (i >= B_2) break;
      }
  }
  return f;
}

MASF_MFLOAT MASF_FLOG10
# ifdef __STDC__
(MASF_MFLOAT F)
# else
(F)
MASF_MFLOAT F;
# endif
{
  return MathLib_ln(F) / MathLib_ln(10.0);
}

MASF_MFLOAT MASF_FFINT
# ifdef __STDC__
(MASSTOR_LIST N)
# else
(N)
MASSTOR_LIST N;
# endif
{
  MASSTOR_LIST C_62_A, a;
  MASF_MFLOAT f;

  f = 0.0;
  if (N == 0) {
    return f;
  }
  C_62_A = N;
  if (C_62_A < MASSTOR_BETA) {
    C_62_A = MASSTOR_LIST1(C_62_A);
  }
  C_62_A = SACLIST_CINV(C_62_A);
  while (C_62_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_62_A, &a, &C_62_A);
    f = f * MASF_FBETA + MASF_FFGI(a);
  }
  return f;
}

MASF_MFLOAT MASF_FFRN
# ifdef __STDC__
(MASSTOR_LIST C_61_A)
# else
(C_61_A)
MASSTOR_LIST C_61_A;
# endif
{
  MASSTOR_LIST d, n;
  MASF_MFLOAT f, fd, fn;

  f = 0.0;
  if (C_61_A == 0) {
    return f;
  }
  d = SACRN_RNDEN(C_61_A);
  n = SACRN_RNNUM(C_61_A);
  fd = MASF_FFINT(d);
  fn = MASF_FFINT(n);
  f = fn / fd;
  return f;
}

MASSTOR_LIST MASF_RNFF
# ifdef __STDC__
(MASF_MFLOAT F)
# else
(F)
MASF_MFLOAT F;
# endif
{
  MASSTOR_LIST R, I, E;
  MASF_MFLOAT f, i, l;

  f = F;
  l = MASF_FLOG10(f) + 1.0;
  I = MASF_IFF(l);
  i = MASF_FEXP(10.0, I);
  E = SACI_IEXP(10, I);
  if (I >= 0) {
    f = f / i;
    f = f * MASF_FBETA;
    R = MASF_IFF(f);
    R = SACI_IPROD(R, E);
    R = SACRN_RNRED(R, MASF_IBETA);
  } else {
    f = f * i;
    f = f * MASF_FBETA;
    R = MASF_IFF(f);
    E = SACI_IPROD(E, MASF_IBETA);
    R = SACRN_RNRED(R, E);
  }
  return R;
}

MASSTOR_LIST MASF_SIN
# ifdef __STDC__
(MASSTOR_LIST C_60_A)
# else
(C_60_A)
MASSTOR_LIST C_60_A;
# endif
{
  MASSTOR_LIST R;
  MASF_MFLOAT f;

  f = MASF_FFRN(C_60_A);
  f = MathLib_sin(f);
  R = MASF_RNFF(f);
  return R;
}

MASSTOR_LIST MASF_COS
# ifdef __STDC__
(MASSTOR_LIST C_59_A)
# else
(C_59_A)
MASSTOR_LIST C_59_A;
# endif
{
  MASSTOR_LIST R;
  MASF_MFLOAT f;

  f = MASF_FFRN(C_59_A);
  f = MathLib_cos(f);
  R = MASF_RNFF(f);
  return R;
}

MASSTOR_LIST MASF_TAN
# ifdef __STDC__
(MASSTOR_LIST C_58_A)
# else
(C_58_A)
MASSTOR_LIST C_58_A;
# endif
{
  MASSTOR_LIST R;
  MASF_MFLOAT f;

  f = MASF_FFRN(C_58_A);
  f = MathLib_cos(f);
  if (f != 0.0) {
    f = MathLib_sin(f) / f;
    R = MASF_RNFF(f);
  } else {
    f = MathLib_sin(f);
    if (f < 0.0) {
      R = SACLIST_LIST2(-1, 0);
    } else {
      R = SACLIST_LIST2(1, 0);
    }
  }
  return R;
}

MASSTOR_LIST MASF_ARCTAN
# ifdef __STDC__
(MASSTOR_LIST C_57_A)
# else
(C_57_A)
MASSTOR_LIST C_57_A;
# endif
{
  MASSTOR_LIST R;
  MASF_MFLOAT f;

  f = MASF_FFRN(C_57_A);
  f = MathLib_arctan(f);
  R = MASF_RNFF(f);
  return R;
}

MASSTOR_LIST MASF_EXPF
# ifdef __STDC__
(MASSTOR_LIST C_56_A)
# else
(C_56_A)
MASSTOR_LIST C_56_A;
# endif
{
  MASSTOR_LIST R;
  MASF_MFLOAT f;

  f = MASF_FFRN(C_56_A);
  f = MathLib_exp(f);
  R = MASF_RNFF(f);
  return R;
}

MASSTOR_LIST MASF_LN
# ifdef __STDC__
(MASSTOR_LIST C_55_A)
# else
(C_55_A)
MASSTOR_LIST C_55_A;
# endif
{
  MASSTOR_LIST R;
  MASF_MFLOAT f;

  f = MASF_FFRN(C_55_A);
  f = MathLib_ln(f);
  R = MASF_RNFF(f);
  return R;
}

MASSTOR_LIST MASF_LOG
# ifdef __STDC__
(MASSTOR_LIST C_54_A)
# else
(C_54_A)
MASSTOR_LIST C_54_A;
# endif
{
  MASSTOR_LIST R;
  MASF_MFLOAT f;

  f = MASF_FFRN(C_54_A);
  f = MathLib_ln(f) / MathLib_ln(10.0);
  R = MASF_RNFF(f);
  return R;
}

MASSTOR_LIST MASF_SQRT
# ifdef __STDC__
(MASSTOR_LIST C_53_A)
# else
(C_53_A)
MASSTOR_LIST C_53_A;
# endif
{
  MASSTOR_LIST R;
  MASF_MFLOAT f;

  f = MASF_FFRN(C_53_A);
  f = MathLib_sqrt(f);
  R = MASF_RNFF(f);
  return R;
}

static void InitFLOAT
# ifdef __STDC__
()
# else
()
# endif
{
  MASF_BETAH = MASELEM_MASEXP(2, 15);
  MASF_FBETA = MASF_FFGI(MASELEM_MASEXP(2, 29));
  MASF_FBETAH = MASF_FFGI(MASELEM_MASEXP(2, 15));
  MASF_IBETA = SACI_IEXP(2, 29);
}

void BEGIN_MASF()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_SACI();
    BEGIN_SACRN();
    BEGIN_MathLib();

    InitFLOAT();
  }
}
