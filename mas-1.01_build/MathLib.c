#include "SYSTEM_.h"

#ifndef DEFINITION_MathLib
#include "MathLib.h"
#endif

CHAR MathLib_rcsid [] = "$Id: MathLib.md,v 1.2 1993/03/22 10:17:06 kredel Exp $";
CHAR MathLib_copyright [] = "Copyright (c) GMD";

#define log2	0.693147180559945309E0
#define pi	3.1415926535897932384626434
#define twoopi	(2.0 / pi)
#define pio2	(pi / 2.0)
#define pio4	(pi / 4.0)
#define sqrt2	1.4142135623730950488016887
#define MaxCardI	65535
#define MaxCardR	65535.0
static CHAR rcsidi [] = "$Id: MathLib.mi,v 1.4 1993/03/22 10:17:07 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) GMD";
static INTEGER Trunc ARGS((LONGREAL x));
static LONGREAL Float ARGS((INTEGER x));
static LONGREAL frexp ARGS((LONGREAL x, INTEGER *exp));
static LONGREAL ldexp ARGS((LONGREAL value, INTEGER exp));
static LONGREAL modf ARGS((LONGREAL value, INTEGER *C_24_int));
static LONGREAL sarctan ARGS((LONGREAL arg));
static LONGREAL xatan ARGS((LONGREAL arg));
#define C_15_p4	0.161536412982230228262E2
#define C_16_p3	0.26842548195503973794141E3
#define C_17_p2	0.11530293515404850115428136E4
#define C_18_p1	0.178040631643319697105464587E4
#define C_19_p0	0.89678597403663861959987488E3
#define q4	0.5895697050844462222791E2
#define C_20_q3	0.536265374031215315104235E3
#define C_21_q2	0.16667838148816337184521798E4
#define C_22_q1	0.207933497444540981287275926E4
#define C_23_q0	0.89678597403663861962481162E3
#define sq2m1	(sqrt2 - 1.0)
#define sq2p1	(sqrt2 + 1.0)
static LONGREAL sinus ARGS((LONGREAL x, INTEGER quad));
#define C_8_p0	0.1357884097877375669092680E8
#define C_9_p1	(-0.4942908100902844161158627E7)
#define C_10_p2	0.4401030535375266501944918E6
#define C_11_p3	(-0.1384727249982452873054457E5)
#define p4	0.1459688406665768722226959E3
#define C_12_q0	0.8644558652922534429915149E7
#define C_13_q1	0.4081792252343299749395779E6
#define C_14_q2	0.9463096101538208180571257E4
#define q3	0.1326534908786136358911494E3
#define L30	1.073741824E9
static LONGREAL TwoPower ARGS((CARDINAL b));
#define maxf	10000.0
#define C_1_p0	0.2080384346694663001443843411E7
#define C_2_p1	0.3028697169744036299076048876E5
#define C_3_p2	0.6061485330061080841615584556E2
#define C_4_q0	0.6002720360238832528230907598E7
#define C_5_q1	0.3277251518082914423057964422E6
#define C_6_q2	0.1749287689093076403844945335E4
#define log2e	(1.0 / log2)
#define sqrto2	(1.0 / sqrt2)
#define p0	(-0.240139179559210510E2)
#define p1	0.309572928215376501E2
#define p2	(-0.963769093368686593E1)
#define p3	0.421087371217979714E0
#define q0	(-0.120069589779605255E2)
#define q1	0.194809660700889731E2
#define q2	(-0.891110902798312337E1)


static INTEGER Trunc
# ifdef __STDC__
(LONGREAL x)
# else
(x)
LONGREAL x;
# endif
{
  INTEGER res, exp, i, j;
  REAL xS;
  LONGREAL xL;
  CARDINAL c;

  exp = 0;
  while (x >= MaxCardR) {
    x = x / MaxCardR;
    INC(exp);
  }
  xS = x;
  res = TRUNC(xS);
  {
    LONGINT B_1 = 1, B_2 = exp;

    if (B_1 <= B_2)
      for (i = B_1;; i += 1) {
        xS = x;
        xL = FLOAT(TRUNC(xS));
        x = (x - xL) * MaxCardR;
        xS = x;
        j = TRUNC(xS);
        res = MaxCardI * res + j;
        if (i >= B_2) break;
      }
  }
  return res;
}

static LONGREAL Float
# ifdef __STDC__
(INTEGER x)
# else
(x)
INTEGER x;
# endif
{
  CARDINAL divC, modC;
  LONGREAL divR, modR;

  divC = x / MaxCardI;
  divR = FLOAT(divC);
  modC = x % MaxCardI;
  modR = FLOAT(modC);
  return divR * MaxCardR + modR;
}

static LONGREAL frexp
# ifdef __STDC__
(LONGREAL x, INTEGER *exp)
# else
(x, exp)
LONGREAL x;
INTEGER *exp;
# endif
{
  BOOLEAN neg;

  *exp = 0;
  neg = x < 0.0;
  if (neg) {
    x = -x;
  }
  if (x >= 1.0) {
    do {
      INC(*exp);
      x = x / 2.0;
    } while (!(x < 1.0));
  } else if (x < 0.1 && x != 0.0) {
    do {
      DEC(*exp);
      x = x * 2.0;
    } while (!(x >= 0.1));
  }
  if (neg) {
    x = -x;
  }
  return x;
}

static LONGREAL ldexp
# ifdef __STDC__
(LONGREAL value, INTEGER exp)
# else
(value, exp)
LONGREAL value;
INTEGER exp;
# endif
{
  INTEGER i;

  if (exp > 0) {
    {
      LONGINT B_3 = 1, B_4 = exp;

      if (B_3 <= B_4)
        for (i = B_3;; i += 1) {
          value = value * 2.0;
          if (i >= B_4) break;
        }
    }
  } else if (exp < 0) {
    {
      LONGINT B_5 = 1, B_6 = -exp;

      if (B_5 <= B_6)
        for (i = B_5;; i += 1) {
          value = value / 2.0;
          if (i >= B_6) break;
        }
    }
  }
  return value;
}

static LONGREAL modf
# ifdef __STDC__
(LONGREAL value, INTEGER *C_24_int)
# else
(value, C_24_int)
LONGREAL value;
INTEGER *C_24_int;
# endif
{
  BOOLEAN neg;

  neg = value < 0.0;
  if (neg) {
    value = -value;
  }
  *C_24_int = Trunc(value);
  value = value - Float(*C_24_int);
  if (neg) {
    *C_24_int = -*C_24_int;
  }
  return value;
}

static LONGREAL xatan
# ifdef __STDC__
(LONGREAL arg)
# else
(arg)
LONGREAL arg;
# endif
{
  LONGREAL argsq;

  argsq = arg * arg;
  return ((((C_15_p4 * argsq + C_16_p3) * argsq + C_17_p2) * argsq + C_18_p1) * argsq + C_19_p0) / (((((argsq + q4) * argsq + C_20_q3) * argsq + C_21_q2) * argsq + C_22_q1) * argsq + C_23_q0) * arg;
}

static LONGREAL sarctan
# ifdef __STDC__
(LONGREAL arg)
# else
(arg)
LONGREAL arg;
# endif
{
  if (arg < sq2m1) {
    return xatan(arg);
  } else if (arg > sq2p1) {
    return pio2 - xatan(1.0 / arg);
  } else {
    return pio4 + xatan((arg - 1.0) / (arg + 1.0));
  }
}

static LONGREAL sinus
# ifdef __STDC__
(LONGREAL x, INTEGER quad)
# else
(x, quad)
LONGREAL x;
INTEGER quad;
# endif
{
  LONGREAL y, C_7_dummy, ysq;
  INTEGER e, f, k;

  if (x < 0.0) {
    x = -x;
    INC1(quad, 2);
  }
  x = x * twoopi;
  if (x > 32764.0) {
    y = modf(x, &e);
    INC1(e, quad);
    C_7_dummy = modf(0.25 * MathLib_real(e), &f);
    quad = e - 4 * f;
  } else {
    k = MathLib_entier(x);
    y = x - MathLib_realL(k);
    quad = (quad + k) % 4;
  }
  if (ODD(quad)) {
    y = 1.0 - y;
  }
  if (quad > 1) {
    y = -y;
  }
  ysq = y * y;
  return ((((p4 * ysq + C_11_p3) * ysq + C_10_p2) * ysq + C_9_p1) * ysq + C_8_p0) * y / ((((ysq + q3) * ysq + C_14_q2) * ysq + C_13_q1) * ysq + C_12_q0);
}

REAL MathLib_sqrt
# ifdef __STDC__
(REAL arg)
# else
(arg)
REAL arg;
# endif
{
  return MathLib_sqrtL(arg);
}

static LONGREAL TwoPower
# ifdef __STDC__
(CARDINAL b)
# else
(b)
CARDINAL b;
# endif
{
  CARDINAL i;
  LONGREAL result;

  result = 1.0;
  {
    LONGCARD B_7 = 1, B_8 = b;

    if (B_7 <= B_8)
      for (i = B_7;; i += 1) {
        result = result * 2.0;
        if (i >= B_8) break;
      }
  }
  return result;
}

LONGREAL MathLib_sqrtL
# ifdef __STDC__
(LONGREAL arg)
# else
(arg)
LONGREAL arg;
# endif
{
  LONGREAL x, temp;
  INTEGER exp;
  LONGCARD i;

  if (arg < 0.0) {
    return 0.0;
  }
  if (arg == 0.0) {
    return 0.0;
  }
  x = frexp(arg, &exp);
  while (x < 0.5) {
    x = x * 2.0;
    DEC(exp);
  }
  if (ODD(exp)) {
    x = x * 2.0;
    DEC(exp);
  }
  temp = 0.5 * (1.0 + x);
  while (exp > 60) {
    temp = temp * L30;
    DEC1(exp, 60);
  }
  while (exp < -60) {
    temp = temp / L30;
    INC1(exp, 60);
  }
  if (exp >= 0) {
    temp = temp * TwoPower(exp / 2);
  } else {
    temp = temp / TwoPower(-exp / 2);
  }
  for (i = 0; i <= 4; i += 1) {
    temp = 0.5 * (temp + arg / temp);
  }
  return temp;
}

REAL MathLib_exp
# ifdef __STDC__
(REAL arg)
# else
(arg)
REAL arg;
# endif
{
  return MathLib_expL(arg);
}

LONGREAL MathLib_expL
# ifdef __STDC__
(LONGREAL arg)
# else
(arg)
LONGREAL arg;
# endif
{
  INTEGER ent;
  LONGREAL fract, xsq, temp1, temp2;

  if (arg == 0.0) {
    return 1.0;
  }
  if (arg < -maxf) {
    return 0.0;
  }
  if (arg > maxf) {
    return 0.0;
  }
  arg = arg * log2e;
  ent = MathLib_entier(arg);
  fract = arg - MathLib_realL(ent) - 0.5;
  xsq = fract * fract;
  temp1 = ((C_3_p2 * xsq + C_2_p1) * xsq + C_1_p0) * fract;
  temp2 = ((xsq + C_6_q2) * xsq + C_5_q1) * xsq + C_4_q0;
  return ldexp(sqrt2 * (temp2 + temp1) / (temp2 - temp1), ent);
}

REAL MathLib_ln
# ifdef __STDC__
(REAL arg)
# else
(arg)
REAL arg;
# endif
{
  return MathLib_lnL(arg);
}

LONGREAL MathLib_lnL
# ifdef __STDC__
(LONGREAL arg)
# else
(arg)
LONGREAL arg;
# endif
{
  LONGREAL asq;
  INTEGER exp;

  if (arg <= 0.0) {
    return 0.0;
  }
  arg = frexp(arg, &exp);
  while (arg < sqrto2) {
    arg = arg * 2.0;
    DEC(exp);
  }
  arg = (arg - 1.0) / (arg + 1.0);
  asq = arg * arg;
  return (((p3 * asq + p2) * asq + p1) * asq + p0) / (((asq + q2) * asq + q1) * asq + q0) * arg + MathLib_realL(exp) * log2;
}

REAL MathLib_sin
# ifdef __STDC__
(REAL arg)
# else
(arg)
REAL arg;
# endif
{
  return MathLib_sinL(arg);
}

LONGREAL MathLib_sinL
# ifdef __STDC__
(LONGREAL arg)
# else
(arg)
LONGREAL arg;
# endif
{
  return sinus(arg, 0);
}

REAL MathLib_cos
# ifdef __STDC__
(REAL arg)
# else
(arg)
REAL arg;
# endif
{
  return MathLib_cosL(arg);
}

LONGREAL MathLib_cosL
# ifdef __STDC__
(LONGREAL arg)
# else
(arg)
LONGREAL arg;
# endif
{
  if (arg < 0.0) {
    arg = -arg;
  }
  return sinus(arg, 1);
}

REAL MathLib_arctan
# ifdef __STDC__
(REAL arg)
# else
(arg)
REAL arg;
# endif
{
  return MathLib_arctanL(arg);
}

LONGREAL MathLib_arctanL
# ifdef __STDC__
(LONGREAL arg)
# else
(arg)
LONGREAL arg;
# endif
{
  if (arg > 0.0) {
    return sarctan(arg);
  } else {
    return -sarctan(-arg);
  }
}

REAL MathLib_real
# ifdef __STDC__
(INTEGER arg)
# else
(arg)
INTEGER arg;
# endif
{
  return MathLib_realL(arg);
}

LONGREAL MathLib_realL
# ifdef __STDC__
(INTEGER arg)
# else
(arg)
INTEGER arg;
# endif
{
  if (arg < 0) {
    return -Float(-arg);
  } else {
    return Float(arg);
  }
}

INTEGER MathLib_entier
# ifdef __STDC__
(REAL arg)
# else
(arg)
REAL arg;
# endif
{
  return MathLib_entierL(arg);
}

INTEGER MathLib_entierL
# ifdef __STDC__
(LONGREAL arg)
# else
(arg)
LONGREAL arg;
# endif
{
  if (arg >= 0.0) {
    return Trunc(arg);
  } else if (-Float(Trunc(-arg)) == arg) {
    return -Trunc(-arg);
  } else {
    return -Trunc(-arg) - 1;
  }
}

void BEGIN_MathLib()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;


  }
}
