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

#ifndef DEFINITION_SACD
#include "SACD.h"
#endif

#ifndef DEFINITION_SACI
#include "SACI.h"
#endif

#ifndef DEFINITION_SACRN
#include "SACRN.h"
#endif

#ifndef DEFINITION_MASAPF
#include "MASAPF.h"
#endif

CHAR MASAPF_rcsid [] = "$Id: MASAPF.md,v 1.2 1992/02/12 13:18:58 pesch Exp $";
CHAR MASAPF_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static MASSTOR_LIST APPR2, APP10;
static BOOLEAN msg;
static CHAR rcsidi [] = "$Id: MASAPF.mi,v 1.4 1998/01/05 13:03:59 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST MASAPF_APCOMP
# ifdef __STDC__
(MASSTOR_LIST ML, MASSTOR_LIST EL)
# else
(ML, EL)
MASSTOR_LIST ML, EL;
# endif
{
  return MASSTOR_COMP(EL, MASSTOR_COMP(ML, MASSTOR_SIL));
}

MASSTOR_LIST MASAPF_APMANT
# ifdef __STDC__
(MASSTOR_LIST C_82_A)
# else
(C_82_A)
MASSTOR_LIST C_82_A;
# endif
{
  return MASSTOR_FIRST(MASSTOR_RED(C_82_A));
}

MASSTOR_LIST MASAPF_APEXPT
# ifdef __STDC__
(MASSTOR_LIST C_81_A)
# else
(C_81_A)
MASSTOR_LIST C_81_A;
# endif
{
  return MASSTOR_FIRST(C_81_A);
}

MASSTOR_LIST MASAPF_ILOG10
# ifdef __STDC__
(MASSTOR_LIST N)
# else
(N)
MASSTOR_LIST N;
# endif
{
  MASSTOR_LIST L, R, S;

  L = 0;
  if (N == 0) {
    return L;
  }
  S = SACI_IABSF(N);
  if (S == 1) {
    return L;
  }
  do {
    SACI_IDQR(S, SACD_THETA, &S, &R);
    L = L + SACD_ETA;
  } while (!(S == 0));
  L = L - SACD_ETA;
  S = R;
  do {
    MASELEM_MASQREM(S, 10, &S, &R);
    L = L + 1;
  } while (!(S == 0));
  L = L - 1;
  if (R != 0) {
    L = L + 1;
  }
  return L;
}

void MASAPF_APSPRE
# ifdef __STDC__
(MASSTOR_LIST N)
# else
(N)
MASSTOR_LIST N;
# endif
{
  MASSTOR_LIST J1Y, L, M, QL, RL;

  M = SACI_IEXP(10, N);
  L = SACI_ILOG2(M) + 1;
  MASELEM_MASQREM(L, SACD_ZETA, &QL, &RL);
  if (RL != 0) {
    L = L + SACD_ZETA - RL;
  }
  L = L - 1;
  APPR2 = L;
  APP10 = N;
  if (msg) {
    MASBIOS_SWRITE("Floating point precision set to ", 32L);
    SACI_IWRITE(N);
    MASBIOS_SWRITE(" digits = ", 10L);
    SACI_IWRITE(L);
    MASBIOS_SWRITE(" bits. ", 7L);
    MASBIOS_BLINES(0);
  }
  return;
}

MASSTOR_LIST MASAPF_APFINT
# ifdef __STDC__
(MASSTOR_LIST N)
# else
(N)
MASSTOR_LIST N;
# endif
{
  MASSTOR_LIST C_80_A, EL, FL, ML;

  if (N == 0) {
    C_80_A = MASAPF_APCOMP(0, 0);
    return C_80_A;
  }
  EL = SACI_ILOG2(N);
  FL = EL - 1 - APPR2;
  if (FL >= 0) {
    ML = SACI_IDP2(N, FL);
  } else {
    ML = SACI_IMP2(N, -FL);
  }
  ML = SACI_ISUM(ML, 1);
  ML = SACI_IDP2(ML, 1);
  C_80_A = MASAPF_APCOMP(ML, EL);
  return C_80_A;
}

MASSTOR_LIST MASAPF_APSHFT
# ifdef __STDC__
(MASSTOR_LIST B, MASSTOR_LIST EL)
# else
(B, EL)
MASSTOR_LIST B, EL;
# endif
{
  MASSTOR_LIST C_79_A, FL, J1Y, J2Y, ML;

  ML = MASAPF_APMANT(B);
  if (ML == 0) {
    C_79_A = MASAPF_APCOMP(0, 0);
    return C_79_A;
  }
  FL = MASAPF_APEXPT(B) + EL;
  if (FL >= MASSTOR_BETA) {
    MASERR_ERROR(MASERR_severe, "arbitrary precision floating point OVERFLOW", 43L);
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("Mantissa=", 9L);
    SACI_IWRITE(ML);
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("Exponent=", 9L);
    MASBIOS_GWRITE(MASAPF_APEXPT(B));
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("EL       =", 10L);
    MASBIOS_GWRITE(EL);
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("FL       =", 10L);
    MASBIOS_GWRITE(FL);
    MASBIOS_BLINES(2);
    J1Y = APPR2 + 1;
    J1Y = SACI_IMP2(1, J1Y);
    J2Y = -1;
    ML = SACI_ISUM(J1Y, J2Y);
    FL = MASSTOR_BETA - 1;
  }
  if (FL <= -MASSTOR_BETA) {
    MASERR_ERROR(MASERR_severe, "arbitrary precision floating point UNDERFLOW", 44L);
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("Mantissa=", 9L);
    SACI_IWRITE(ML);
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("Exponent=", 9L);
    MASBIOS_GWRITE(MASAPF_APEXPT(B));
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("EL       =", 10L);
    MASBIOS_GWRITE(EL);
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("FL       =", 10L);
    MASBIOS_GWRITE(FL);
    MASBIOS_BLINES(2);
    ML = 0;
    FL = 0;
  }
  C_79_A = MASAPF_APCOMP(ML, FL);
  return C_79_A;
}

MASSTOR_LIST MASAPF_APSIGN
# ifdef __STDC__
(MASSTOR_LIST C_78_A)
# else
(C_78_A)
MASSTOR_LIST C_78_A;
# endif
{
  MASSTOR_LIST ML, SL;

  ML = MASAPF_APMANT(C_78_A);
  SL = SACI_ISIGNF(ML);
  return SL;
}

void MASAPF_APWRIT
# ifdef __STDC__
(MASSTOR_LIST C_77_A)
# else
(C_77_A)
MASSTOR_LIST C_77_A;
# endif
{
  MASSTOR_LIST AP, SL, B, EL, GL, J1Y, ML, Z;

  ML = MASAPF_APMANT(C_77_A);
  if (ML == 0) {
    MASBIOS_SWRITE("0.0", 3L);
    return;
  }
  SL = MASAPF_APSIGN(C_77_A);
  AP = MASAPF_APABS(C_77_A);
  ML = MASAPF_APMANT(AP);
  Z = MASAPF_APFINT(10);
  EL = MASAPF_APLG10(AP);
  if (EL > 0) {
    J1Y = MASAPF_APEXP(Z, EL);
    B = MASAPF_APQ(AP, J1Y);
  } else {
    J1Y = MASAPF_APEXP(Z, -EL);
    B = MASAPF_APPROD(AP, J1Y);
  }
  ML = MASAPF_APMANT(B);
  GL = MASAPF_APEXPT(B);
  if (GL > 0) {
    ML = SACI_IMP2(ML, GL);
    ML = SACI_ISUM(ML, 1);
    EL = EL + 1;
  }
  J1Y = SACI_IEXP(10, APP10);
  ML = SACI_IPROD(ML, J1Y);
  ML = SACI_IDP2(ML, APPR2);
  if (SL < 0) {
    MASBIOS_SWRITE("-", 1L);
  }
  MASBIOS_SWRITE("0.", 2L);
  SACI_IWRITE(ML);
  MASBIOS_SWRITE("E", 1L);
  SACI_IWRITE(EL);
  return;
}

MASSTOR_LIST MASAPF_APNEG
# ifdef __STDC__
(MASSTOR_LIST C_76_A)
# else
(C_76_A)
MASSTOR_LIST C_76_A;
# endif
{
  MASSTOR_LIST B, EL, ML;

  ML = MASAPF_APMANT(C_76_A);
  ML = SACI_INEG(ML);
  EL = MASAPF_APEXPT(C_76_A);
  B = MASAPF_APCOMP(ML, EL);
  return B;
}

MASSTOR_LIST MASAPF_APABS
# ifdef __STDC__
(MASSTOR_LIST C_75_A)
# else
(C_75_A)
MASSTOR_LIST C_75_A;
# endif
{
  MASSTOR_LIST B, EL, ML;

  ML = MASAPF_APMANT(C_75_A);
  ML = SACI_IABSF(ML);
  EL = MASAPF_APEXPT(C_75_A);
  B = MASAPF_APCOMP(ML, EL);
  return B;
}

MASSTOR_LIST MASAPF_APCMPR
# ifdef __STDC__
(MASSTOR_LIST C_74_A, MASSTOR_LIST B)
# else
(C_74_A, B)
MASSTOR_LIST C_74_A, B;
# endif
{
  MASSTOR_LIST EL1, EL2, ML1, ML2, SL, SL1, SL2;

  ML1 = MASAPF_APMANT(C_74_A);
  ML2 = MASAPF_APMANT(B);
  SL1 = SACI_ISIGNF(ML1);
  SL2 = SACI_ISIGNF(ML2);
  SL = SACI_ICOMP(SL1, SL2);
  if (SL != 0) {
    return SL;
  }
  EL1 = MASAPF_APEXPT(C_74_A);
  EL2 = MASAPF_APEXPT(B);
  SL = SACI_ICOMP(EL1, EL2);
  if (SL == 0) {
    SL = SACI_ICOMP(ML1, ML2);
  }
  SL = SL * SL1;
  return SL;
}

MASSTOR_LIST MASAPF_APNELD
# ifdef __STDC__
(MASSTOR_LIST C_73_A, MASSTOR_LIST B)
# else
(C_73_A, B)
MASSTOR_LIST C_73_A, B;
# endif
{
  MASSTOR_LIST EL1, EL2, J1Y, LL, ML1, ML2, NL1, NL2, PL, PL1, PL2, SL, SL1, SL2;

  LL = 0;
  ML1 = MASAPF_APMANT(C_73_A);
  ML2 = MASAPF_APMANT(B);
  SL1 = SACI_ISIGNF(ML1);
  SL2 = SACI_ISIGNF(ML2);
  SL = SACI_ICOMP(SL1, SL2);
  if (SL != 0) {
    return LL;
  }
  EL1 = MASAPF_APEXPT(C_73_A);
  EL2 = MASAPF_APEXPT(B);
  SL = SACI_ICOMP(EL1, EL2);
  if (SL != 0) {
    return LL;
  }
  if (ML1 < MASSTOR_BETA) {
    ML1 = MASSTOR_LIST1(ML1);
  }
  if (ML2 < MASSTOR_BETA) {
    ML2 = MASSTOR_LIST1(ML2);
  }
  NL1 = SACLIST_CINV(ML1);
  NL2 = SACLIST_CINV(ML2);
  do {
    MASSTOR_ADV(NL1, &PL1, &NL1);
    MASSTOR_ADV(NL2, &PL2, &NL2);
    if (PL1 == PL2) {
      LL = LL + SACD_ZETA;
    } else {
      PL = PL1 - PL2;
      J1Y = SACI_ILOG2(PL);
      J1Y = SACD_ZETA - J1Y;
      LL = LL + J1Y;
      return LL;
    }
  } while (!(NL1 == MASSTOR_SIL));
  return LL;
}

MASSTOR_LIST MASAPF_APPROD
# ifdef __STDC__
(MASSTOR_LIST C_72_A, MASSTOR_LIST B)
# else
(C_72_A, B)
MASSTOR_LIST C_72_A, B;
# endif
{
  MASSTOR_LIST C, EL, EL1, EL2, J1Y, ML, ML1, ML2;

  ML1 = MASAPF_APMANT(C_72_A);
  ML2 = MASAPF_APMANT(B);
  ML = SACI_IPRODK(ML1, ML2);
  C = MASAPF_APFINT(ML);
  EL1 = MASAPF_APEXPT(C_72_A);
  EL2 = MASAPF_APEXPT(B);
  J1Y = EL1 + EL2;
  J1Y = J1Y - APPR2;
  EL = J1Y - APPR2;
  C = MASAPF_APSHFT(C, EL);
  return C;
}

MASSTOR_LIST MASAPF_APQ
# ifdef __STDC__
(MASSTOR_LIST C_71_A, MASSTOR_LIST B)
# else
(C_71_A, B)
MASSTOR_LIST C_71_A, B;
# endif
{
  MASSTOR_LIST C, EL, EL1, EL2, ML, ML1, ML2, MR, MQ;

  ML1 = MASAPF_APMANT(C_71_A);
  ML2 = MASAPF_APMANT(B);
  ML = SACI_IMP2(ML1, APPR2 + 1);
  ML = SACI_IQ(ML, ML2);
  C = MASAPF_APFINT(ML);
  EL1 = MASAPF_APEXPT(C_71_A);
  EL2 = MASAPF_APEXPT(B);
  EL = EL1 - APPR2 - 1 - EL2;
  C = MASAPF_APSHFT(C, EL);
  return C;
}

MASSTOR_LIST MASAPF_APSUM
# ifdef __STDC__
(MASSTOR_LIST C_70_A, MASSTOR_LIST B)
# else
(C_70_A, B)
MASSTOR_LIST C_70_A, B;
# endif
{
  MASSTOR_LIST C, EL, EL1, EL2, J1Y, ML, ML1, ML2;

  EL1 = MASAPF_APEXPT(C_70_A);
  EL2 = MASAPF_APEXPT(B);
  EL = SACI_IMIN(EL1, EL2);
  ML1 = MASAPF_APMANT(C_70_A);
  ML2 = MASAPF_APMANT(B);
  J1Y = EL1 - EL;
  ML1 = SACI_IMP2(ML1, J1Y);
  J1Y = EL2 - EL;
  ML2 = SACI_IMP2(ML2, J1Y);
  ML = SACI_ISUM(ML1, ML2);
  C = MASAPF_APFINT(ML);
  EL = EL - APPR2;
  C = MASAPF_APSHFT(C, EL);
  return C;
}

MASSTOR_LIST MASAPF_APDIFF
# ifdef __STDC__
(MASSTOR_LIST C_69_A, MASSTOR_LIST B)
# else
(C_69_A, B)
MASSTOR_LIST C_69_A, B;
# endif
{
  MASSTOR_LIST C, XL;

  C = MASAPF_APNEG(B);
  C = MASAPF_APSUM(C_69_A, C);
  return C;
}

MASSTOR_LIST MASAPF_APLG10
# ifdef __STDC__
(MASSTOR_LIST C_68_A)
# else
(C_68_A)
MASSTOR_LIST C_68_A;
# endif
{
  MASSTOR_LIST EL, FL, J1Y, L, S, XL, Z;

  L = 0;
  if (MASAPF_APMANT(C_68_A) == 0) {
    MASERR_ERROR(MASERR_fatal, "APLG10, logarithm of 0 undefined", 32L);
    return L;
  }
  S = MASAPF_APABS(C_68_A);
  J1Y = MASAPF_APEXPT(S);
  FL = SACI_IABSF(J1Y);
  XL = SACI_ILOG2(SACD_THETA);
  if (FL > XL) {
    if (FL > 50 * XL) {
      MASERR_ERROR(MASERR_severe, "APLG10 is not efficient", 23L);
    }
    Z = MASAPF_APFINT(SACD_THETA);
    EL = MASAPF_APEXPT(Z);
    while (MASAPF_APEXPT(S) >= EL) {
      S = MASAPF_APQ(S, Z);
      L = L + SACD_ETA;
    }
    while (MASAPF_APEXPT(S) < 0) {
      S = MASAPF_APPROD(S, Z);
      L = L - SACD_ETA;
    }
  }
  Z = MASAPF_APFINT(10);
  EL = MASAPF_APEXPT(Z);
  while (MASAPF_APEXPT(S) >= EL) {
    S = MASAPF_APQ(S, Z);
    L = L + 1;
  }
  while (MASAPF_APEXPT(S) < 0) {
    S = MASAPF_APPROD(S, Z);
    L = L - 1;
  }
  return L;
}

MASSTOR_LIST MASAPF_APEXP
# ifdef __STDC__
(MASSTOR_LIST C_67_A, MASSTOR_LIST NL)
# else
(C_67_A, NL)
MASSTOR_LIST C_67_A, NL;
# endif
{
  MASSTOR_LIST B, J1Y, KL, XL;

  if (NL == 0) {
    B = MASAPF_APFINT(1);
    return B;
  }
  if (NL == 1) {
    B = C_67_A;
    return B;
  }
  if (NL < 0) {
    J1Y = -NL;
    B = MASAPF_APEXP(C_67_A, J1Y);
    J1Y = MASAPF_APFINT(1);
    B = MASAPF_APQ(J1Y, B);
    return B;
  }
  KL = NL / 2;
  B = MASAPF_APEXP(C_67_A, KL);
  B = MASAPF_APPROD(B, B);
  if (NL > KL * 2) {
    B = MASAPF_APPROD(B, C_67_A);
  }
  return B;
}

MASSTOR_LIST MASAPF_APFRN
# ifdef __STDC__
(MASSTOR_LIST C_66_A)
# else
(C_66_A)
MASSTOR_LIST C_66_A;
# endif
{
  MASSTOR_LIST A1, A2, B, B1, B2, XL;

  if (C_66_A == 0) {
    B = MASAPF_APFINT(0);
    return B;
  }
  A1 = SACRN_RNNUM(C_66_A);
  A2 = SACRN_RNDEN(C_66_A);
  B1 = MASAPF_APFINT(A1);
  B2 = MASAPF_APFINT(A2);
  B = MASAPF_APQ(B1, B2);
  return B;
}

MASSTOR_LIST MASAPF_RNFAP
# ifdef __STDC__
(MASSTOR_LIST C_65_A)
# else
(C_65_A)
MASSTOR_LIST C_65_A;
# endif
{
  MASSTOR_LIST B, B1, B2, EL, J1Y, ML, XL;

  ML = MASAPF_APMANT(C_65_A);
  if (ML == 0) {
    B = 0;
    return B;
  }
  EL = MASAPF_APEXPT(C_65_A);
  B1 = ML;
  B2 = SACI_IMP2(1, APPR2);
  if (EL >= 0) {
    B1 = SACI_IMP2(B1, EL);
  } else {
    J1Y = -EL;
    B2 = SACI_IMP2(B2, J1Y);
  }
  B = SACRN_RNRED(B1, B2);
  return B;
}

MASSTOR_LIST MASAPF_RNDRD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST C_64_A, B, BL, BLP, C, EL, IL, J1Y, JL, R, R1, R2, RP, s;

  C = MASBIOS_CREADB();
  MASBIOS_BKSP();
  if (C == MASBIOS_MASORD('-')) {
    s = -1;
  } else {
    s = 1;
  }
  R1 = SACI_IREAD();
  C = MASBIOS_CREAD();
  if (C != MASBIOS_MASORD('.')) {
    if (C == MASBIOS_MASORD('/')) {
      R2 = SACI_IREAD();
    } else {
      R2 = 1;
      MASBIOS_BKSP();
    }
    R = SACRN_RNRED(R1, R2);
    return R;
  }
  JL = -1;
  do {
    C = MASBIOS_CREAD();
    JL = JL + 1;
  } while (!(C != 0));
  if (!MASBIOS_DIGIT(C)) {
    MASBIOS_BKSP();
    if (C != MASBIOS_MASORD('E')) {
      R = SACRN_RNINT(R1);
      return R;
    } else {
      C = 0;
    }
  }
  C_64_A = 0;
  B = MASSTOR_SIL;
  BL = 0;
  IL = 0;
  do {
    J1Y = 10 * BL;
    BL = J1Y + C;
    IL = IL + 1;
    if (IL == SACD_ETA) {
      B = MASSTOR_COMP(BL, B);
      BL = 0;
      IL = 0;
    }
    JL = JL + 1;
    C = MASBIOS_CREAD();
  } while (!!MASBIOS_DIGIT(C));
  MASBIOS_BKSP();
  B = MASSTOR_INV(B);
  while (B != MASSTOR_SIL) {
    C_64_A = SACI_IDPR(C_64_A, SACD_THETA);
    MASSTOR_ADV(B, &BLP, &B);
    C_64_A = SACI_ISUM(C_64_A, BLP);
  }
  if (C_64_A != 0) {
    J1Y = SACI_IEXP(10, IL);
    C_64_A = SACI_IDPR(C_64_A, J1Y);
  }
  C_64_A = SACI_ISUM(C_64_A, BL);
  R2 = SACI_IEXP(10, JL);
  R = SACRN_RNRED(C_64_A, R2);
  RP = SACRN_RNINT(R1);
  if (s < 0) {
    R = SACRN_RNDIF(RP, R);
  } else {
    R = SACRN_RNSUM(RP, R);
  }
  C = MASBIOS_CREAD();
  if (C != MASBIOS_MASORD('E')) {
    MASBIOS_BKSP();
    return R;
  }
  EL = SACI_IREAD();
  if (EL >= 0) {
    J1Y = SACI_IEXP(10, EL);
    RP = SACRN_RNRED(J1Y, 1);
  } else {
    J1Y = SACI_IEXP(10, -EL);
    RP = SACRN_RNRED(1, J1Y);
  }
  R = SACRN_RNPROD(R, RP);
  return R;
}

MASSTOR_LIST MASAPF_APROOT
# ifdef __STDC__
(MASSTOR_LIST C_63_A, MASSTOR_LIST NL)
# else
(C_63_A, NL)
MASSTOR_LIST C_63_A, NL;
# endif
{
  MASSTOR_LIST B, KL, KL1, NL1, PR, SL, W, WH, WP, WS;

  PR = APPR2 / 2 + 4;
  WP = MASAPF_APFINT(1);
  if (NL == 0) {
    B = WP;
    return B;
  }
  if (NL == 2) {
    do {
      WS = WP;
      W = MASAPF_APQ(C_63_A, WS);
      W = MASAPF_APSUM(WS, W);
      WP = MASAPF_APSHFT(W, -1);
      SL = MASAPF_APNELD(WP, WS);
    } while (!(SL >= PR));
    B = WP;
    return B;
  }
  KL = MASAPF_APFINT(NL);
  NL1 = NL - 1;
  KL1 = MASAPF_APFINT(NL1);
  do {
    WS = WP;
    W = MASAPF_APEXP(WS, NL1);
    W = MASAPF_APQ(C_63_A, W);
    WH = MASAPF_APPROD(WS, KL1);
    W = MASAPF_APSUM(WH, W);
    WP = MASAPF_APQ(W, KL);
    SL = MASAPF_APNELD(WP, WS);
  } while (!(SL >= PR));
  B = WP;
  return B;
}

MASSTOR_LIST MASAPF_APPI
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST C_62_A, B, C, D, EINS, F, J, P, PI, PR, S, SL, XL, ZWEI;

  PR = APPR2 / 2 + 4;
  EINS = MASAPF_APFINT(1);
  ZWEI = MASAPF_APFINT(2);
  C_62_A = EINS;
  J = MASAPF_APROOT(ZWEI, 2);
  B = MASAPF_APQ(EINS, J);
  C = B;
  S = MASAPF_APFINT(0);
  P = 1;
  do {
    F = C_62_A;
    J = MASAPF_APSUM(F, B);
    C_62_A = MASAPF_APSHFT(J, -1);
    J = MASAPF_APDIFF(F, B);
    C = MASAPF_APSHFT(J, -1);
    J = MASAPF_APPROD(F, B);
    B = MASAPF_APROOT(J, 2);
    P = P + 1;
    J = MASAPF_APSHFT(C, P);
    J = MASAPF_APPROD(C, J);
    S = MASAPF_APSUM(J, S);
    SL = MASAPF_APNELD(C_62_A, B);
  } while (!(SL >= PR));
  D = MASAPF_APDIFF(EINS, S);
  J = MASAPF_APSHFT(B, 2);
  J = MASAPF_APPROD(C_62_A, J);
  PI = MASAPF_APQ(J, D);
  return PI;
}

void BEGIN_MASAPF()
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
    BEGIN_SACD();
    BEGIN_SACI();
    BEGIN_SACRN();

    msg = FALSE;
    MASAPF_APSPRE(20);
    msg = TRUE;
  }
}
