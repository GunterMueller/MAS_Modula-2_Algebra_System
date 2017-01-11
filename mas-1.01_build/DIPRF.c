#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASERR
#include "MASERR.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SACI
#include "SACI.h"
#endif

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_SACIPOL
#include "SACIPOL.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPI
#include "DIPI.h"
#endif

#ifndef DEFINITION_SACPGCD
#include "SACPGCD.h"
#endif

#ifndef DEFINITION_DIPRF
#include "DIPRF.h"
#endif

CHAR DIPRF_rcsid [] = "$Id: DIPRF.md,v 1.2 1992/02/12 17:34:21 pesch Exp $";
CHAR DIPRF_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: DIPRF.mi,v 1.4 1994/11/28 21:19:07 dolzmann Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


void DIPRF_IFWRIT
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST V)
# else
(R, V)
MASSTOR_LIST R, V;
# endif
{
  MASSTOR_LIST AL, RL, RP;

  SACLIST_FIRST2(R, &RL, &AL);
  if (AL == 0) {
    SACLIST_AWRITE(AL);
    return;
  }
  AL = DIPC_DIPFP(RL, AL);
  if (DIPI_DIIPSG(AL) < 0) {
    MASBIOS_SWRITE("-", 1L);
    AL = DIPI_DIIPNG(AL);
  }
  DIPI_DIIPWR(AL, V);
  return;
}

MASSTOR_LIST DIPRF_RFDEN
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST AL, BL, I, RL, RP;

  SACLIST_ADV2(R, &RL, &AL, &RP);
  if (AL != 0) {
    BL = MASSTOR_FIRST(RP);
    return BL;
  }
  BL = 1;
  {
    LONGINT B_1 = 1, B_2 = RL;

    if (B_1 <= B_2)
      for (I = B_1;; I += 1) {
        BL = SACLIST_LIST2(0, BL);
        if (I >= B_2) break;
      }
  }
  return BL;
}

MASSTOR_LIST DIPRF_RFDIF
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST S)
# else
(R, S)
MASSTOR_LIST R, S;
# endif
{
  MASSTOR_LIST SP, T;

  SP = DIPRF_RFNEG(S);
  T = DIPRF_RFSUM(R, SP);
  return T;
}

MASSTOR_LIST DIPRF_RFEXP
# ifdef __STDC__
(MASSTOR_LIST C_208_A, MASSTOR_LIST NL)
# else
(C_208_A, NL)
MASSTOR_LIST C_208_A, NL;
# endif
{
  MASSTOR_LIST B, I, KL, RL;

  if (NL == 0) {
    RL = DIPRF_RFNOV(C_208_A);
    B = 1;
    {
      LONGINT B_3 = 1, B_4 = RL;

      if (B_3 <= B_4)
        for (I = B_3;; I += 1) {
          B = SACLIST_LIST2(0, B);
          if (I >= B_4) break;
        }
    }
    B = DIPRF_RFFIP(RL, B);
    return B;
  }
  if (NL == 1) {
    B = C_208_A;
    return B;
  }
  KL = NL / 2;
  B = DIPRF_RFEXP(C_208_A, KL);
  B = DIPRF_RFPROD(B, B);
  if (NL > 2 * KL) {
    B = DIPRF_RFPROD(B, C_208_A);
  }
  return B;
}

MASSTOR_LIST DIPRF_RFFIP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_207_A)
# else
(RL, C_207_A)
MASSTOR_LIST RL, C_207_A;
# endif
{
  MASSTOR_LIST B, R;

  if (C_207_A == 0) {
    R = SACLIST_LIST2(RL, C_207_A);
    return R;
  }
  B = SACPOL_PINV(0, 1, RL);
  R = SACLIST_LIST3(RL, C_207_A, B);
  return R;
}

MASSTOR_LIST DIPRF_RFINV
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST R1, R2, RL, RP, S, S1, S2;

  SACLIST_FIRST3(R, &RL, &R1, &R2);
  if (SACIPOL_IPSIGN(RL, R1) > 0) {
    S1 = R2;
    S2 = R1;
  } else {
    S1 = SACIPOL_IPNEG(RL, R2);
    S2 = SACIPOL_IPNEG(RL, R1);
  }
  S = SACLIST_LIST3(RL, S1, S2);
  return S;
}

MASSTOR_LIST DIPRF_RFNEG
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST R1, RL, RP, RP1, S;

  SACLIST_ADV2(R, &RL, &R1, &RP);
  if (R1 == 0) {
    S = R;
  } else {
    RP1 = SACIPOL_IPNEG(RL, R1);
    S = SACLIST_COMP2(RL, RP1, RP);
  }
  return S;
}

MASSTOR_LIST DIPRF_RFNOV
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST RL;

  RL = MASSTOR_FIRST(R);
  return RL;
}

MASSTOR_LIST DIPRF_RFNUM
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST AL;

  AL = SACLIST_SECOND(R);
  return AL;
}

MASSTOR_LIST DIPRF_RFONE
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST C_206_A, B, RL, RP, SL;

  SACLIST_ADV2(R, &RL, &C_206_A, &RP);
  SL = 0;
  if (C_206_A == 0) {
    return SL;
  }
  B = MASSTOR_FIRST(RP);
  SL = SACLIST_EQUAL(C_206_A, B);
  return SL;
}

MASSTOR_LIST DIPRF_RFPROD
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST S)
# else
(R, S)
MASSTOR_LIST R, S;
# endif
{
  MASSTOR_LIST AL, BL, D1, D2, R1, R2, RB1, RB2, RL, RP, S1, S2, SB1, SB2, SP, T, T1, T2;

  SACLIST_ADV2(R, &RL, &R1, &RP);
  SACLIST_ADV2(S, &RL, &S1, &SP);
  if (R1 == 0 || S1 == 0) {
    T = SACLIST_LIST2(RL, 0);
    return T;
  }
  R2 = MASSTOR_FIRST(RP);
  S2 = MASSTOR_FIRST(SP);
  AL = SACIPOL_IPONE(RL, R2);
  BL = SACIPOL_IPONE(RL, S2);
  if (AL == 1 && BL == 1) {
    T1 = SACIPOL_IPPROD(RL, R1, S1);
    T = SACLIST_LIST3(RL, T1, R2);
    return T;
  }
  if (AL == 1) {
    SACPGCD_IPGCDC(RL, R1, S2, &D1, &RB1, &SB2);
    T1 = SACIPOL_IPPROD(RL, RB1, S1);
    T = SACLIST_LIST3(RL, T1, SB2);
    return T;
  }
  if (BL == 1) {
    SACPGCD_IPGCDC(RL, S1, R2, &D2, &SB1, &RB2);
    T1 = SACIPOL_IPPROD(RL, SB1, R1);
    T = SACLIST_LIST3(RL, T1, RB2);
    return T;
  }
  SACPGCD_IPGCDC(RL, R1, S2, &D1, &RB1, &SB2);
  SACPGCD_IPGCDC(RL, S1, R2, &D2, &SB1, &RB2);
  T1 = SACIPOL_IPPROD(RL, RB1, SB1);
  T2 = SACIPOL_IPPROD(RL, RB2, SB2);
  T = SACLIST_LIST3(RL, T1, T2);
  return T;
}

MASSTOR_LIST DIPRF_RFQ
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST S)
# else
(R, S)
MASSTOR_LIST R, S;
# endif
{
  MASSTOR_LIST AL, SP, T;

  AL = DIPRF_RFNUM(R);
  if (AL == 0) {
    T = R;
  } else {
    SP = DIPRF_RFINV(S);
    T = DIPRF_RFPROD(R, SP);
  }
  return T;
}

MASSTOR_LIST DIPRF_RFREAD
# ifdef __STDC__
(MASSTOR_LIST V)
# else
(V)
MASSTOR_LIST V;
# endif
{
  MASSTOR_LIST C, EL, JL, R, R1, R2, RL, RLS, VL;

  for (;;) {
    R = SACLIST_LIST2(0, 0);
    RL = MASSTOR_LENGTH(V);
    C = MASBIOS_CREADB();
    if (C == MASBIOS_MASORD('/')) {
      R1 = SACPOL_PINV(0, 1, RL);
      goto EXIT_1;
    }
    MASBIOS_BKSP();
    if (C == MASBIOS_MASORD('(')) {
      R1 = DIPI_DIIPRD(V);
      DIPC_PFDIP(R1, &RLS, &R1);
      goto EXIT_1;
    }
    if (MASBIOS_DIGIT(C)) {
      R1 = SACI_IREAD();
      R1 = SACPOL_PINV(0, R1, RL);
      goto EXIT_1;
    }
    if (MASBIOS_LETTER(C)) {
      VL = SACPOL_VREAD();
      JL = SACPOL_VLSRCH(VL, V);
      R1 = SACPOL_PINV(0, 1, RL);
      if (JL == 0) {
        R = DIPRF_RFFIP(RL, R1);
        return R;
      }
      EL = DIPC_EPREAD();
      R1 = DIPC_PMPV(RL, R1, JL, EL);
      goto EXIT_1;
    }
    MASERR_ERROR(MASERR_severe, "error found in RFREAD. ", 23L);
    return R;
  } EXIT_1:;
  for (;;) {
    C = MASBIOS_CREADB();
    if (C != MASBIOS_MASORD('/')) {
      MASBIOS_BKSP();
      R2 = SACPOL_PINV(0, 1, RL);
      goto EXIT_2;
    }
    C = MASBIOS_CREADB();
    MASBIOS_BKSP();
    if (C == MASBIOS_MASORD('(')) {
      R2 = DIPI_DIIPRD(V);
      DIPC_PFDIP(R2, &RLS, &R2);
      goto EXIT_2;
    }
    if (MASBIOS_DIGIT(C)) {
      R2 = SACI_IREAD();
      R2 = SACPOL_PINV(0, R2, RL);
      goto EXIT_2;
    }
    if (MASBIOS_LETTER(C)) {
      VL = SACPOL_VREAD();
      JL = SACPOL_VLSRCH(VL, V);
      if (JL != 0) {
        R2 = SACPOL_PINV(0, 1, RL);
        EL = DIPC_EPREAD();
        R2 = DIPC_PMPV(RL, R2, JL, EL);
        goto EXIT_2;
      }
    }
    MASERR_ERROR(MASERR_severe, "error found in RFREAD. ", 23L);
    return R;
  } EXIT_2:;
  R = DIPRF_RFRED(RL, R1, R2);
  return R;
  MASERR_ERROR(MASERR_severe, "error found in RFREAD. ", 23L);
}

MASSTOR_LIST DIPRF_RFRED
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_205_A, MASSTOR_LIST B)
# else
(RL, C_205_A, B)
MASSTOR_LIST RL, C_205_A, B;
# endif
{
  MASSTOR_LIST AP, BP, C, R, SL;

  if (C_205_A == 0) {
    R = SACLIST_LIST2(RL, 0);
    return R;
  }
  SACPGCD_IPGCDC(RL, C_205_A, B, &C, &AP, &BP);
  SL = SACIPOL_IPSIGN(RL, BP);
  if (SL < 0) {
    AP = SACIPOL_IPNEG(RL, AP);
    BP = SACIPOL_IPNEG(RL, BP);
  }
  R = SACLIST_LIST3(RL, AP, BP);
  return R;
}

MASSTOR_LIST DIPRF_RFSIGN
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST C_204_A, RL, SL;

  SACLIST_FIRST2(R, &RL, &C_204_A);
  SL = SACIPOL_IPSIGN(RL, C_204_A);
  return SL;
}

MASSTOR_LIST DIPRF_RFSUM
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST S)
# else
(R, S)
MASSTOR_LIST R, S;
# endif
{
  MASSTOR_LIST AL, BL, D, DP, E, R1, R2, RB2, RL, RP, S1, S2, SB2, SP, T, T1, T2;

  SACLIST_ADV2(R, &RL, &R1, &RP);
  SACLIST_ADV2(S, &RL, &S1, &SP);
  if (R1 == 0) {
    T = S;
    return T;
  }
  if (S1 == 0) {
    T = R;
    return T;
  }
  R2 = MASSTOR_FIRST(RP);
  S2 = MASSTOR_FIRST(SP);
  AL = SACIPOL_IPONE(RL, R2);
  BL = SACIPOL_IPONE(RL, S2);
  if (AL == 1 && BL == 1) {
    T1 = SACIPOL_IPSUM(RL, R1, S1);
    if (T1 == 0) {
      return SACLIST_LIST2(RL, T1);
    }
    T = SACLIST_LIST3(RL, T1, R2);
    return T;
  }
  if (AL == 1) {
    T1 = SACIPOL_IPPROD(RL, R1, S2);
    T1 = SACIPOL_IPSUM(RL, T1, S1);
    T = SACLIST_LIST3(RL, T1, S2);
    return T;
  }
  if (BL == 1) {
    T1 = SACIPOL_IPPROD(RL, R2, S1);
    T1 = SACIPOL_IPSUM(RL, T1, R1);
    T = SACLIST_LIST3(RL, T1, R2);
    return T;
  }
  SACPGCD_IPGCDC(RL, R2, S2, &D, &RB2, &SB2);
  T1 = SACIPOL_IPPROD(RL, R1, SB2);
  T2 = SACIPOL_IPPROD(RL, RB2, S1);
  T1 = SACIPOL_IPSUM(RL, T1, T2);
  if (T1 == 0) {
    T = SACLIST_LIST2(RL, 0);
    return T;
  }
  if (SACIPOL_IPONE(RL, D) != 1) {
    SACPGCD_IPGCDC(RL, T1, D, &E, &T1, &DP);
    if (SACIPOL_IPONE(RL, E) != 1) {
      R2 = SACIPOL_IPQ(RL, R2, E);
    }
  }
  T2 = SACIPOL_IPPROD(RL, R2, SB2);
  T = SACLIST_LIST3(RL, T1, T2);
  return T;
}

void DIPRF_RFWRIT
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST V)
# else
(R, V)
MASSTOR_LIST R, V;
# endif
{
  MASSTOR_LIST AL, BL, RL, RP;

  SACLIST_ADV2(R, &RL, &AL, &RP);
  if (AL == 0) {
    SACLIST_AWRITE(AL);
    return;
  }
  AL = DIPC_DIPFP(RL, AL);
  if (DIPI_DIIPSG(AL) < 0) {
    MASBIOS_SWRITE("-", 1L);
    AL = DIPI_DIIPNG(AL);
  }
  DIPI_DIIPWR(AL, V);
  BL = MASSTOR_FIRST(RP);
  if (SACIPOL_IPONE(RL, BL) != 1) {
    MASBIOS_SWRITE("/", 1L);
    BL = DIPC_DIPFP(RL, BL);
    DIPI_DIIPWR(BL, V);
  }
  return;
}

void BEGIN_DIPRF()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_MASERR();
    BEGIN_MASBIOS();
    BEGIN_SACLIST();
    BEGIN_SACI();
    BEGIN_SACPOL();
    BEGIN_SACIPOL();
    BEGIN_DIPC();
    BEGIN_DIPI();
    BEGIN_SACPGCD();

  }
}
