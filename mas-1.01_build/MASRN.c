#include "SYSTEM_.h"

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
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

#ifndef DEFINITION_MASRN
#include "MASRN.h"
#endif

CHAR MASRN_rcsid [] = "$Id: MASRN.md,v 1.2 1992/02/12 13:19:04 pesch Exp $";
CHAR MASRN_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASRN.mi,v 1.3 1992/10/15 16:28:15 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST MASRN_RNDRD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST C_50_A, B, BL, BLP, C, IL, J1Y, JL, R, R1, R2, RP, s;

  C = MASBIOS_CREADB();
  MASBIOS_BKSP();
  if (C == MASBIOS_MASORD('-')) {
    s = -1;
  } else {
    s = 1;
  }
  R1 = SACI_IREAD();
  C = MASBIOS_CREADB();
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
    C = MASBIOS_CREADB();
    JL = JL + 1;
  } while (!(C != 0));
  if (!MASBIOS_DIGIT(C)) {
    MASBIOS_BKSP();
    R = SACRN_RNINT(R1);
    return R;
  }
  C_50_A = 0;
  B = MASSTOR_BETA;
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
    C_50_A = SACI_IDPR(C_50_A, SACD_THETA);
    MASSTOR_ADV(B, &BLP, &B);
    C_50_A = SACI_ISUM(C_50_A, BLP);
  }
  if (C_50_A != 0) {
    J1Y = MASELEM_MASEXP(10, IL);
    C_50_A = SACI_IDPR(C_50_A, J1Y);
  }
  C_50_A = SACI_ISUM(C_50_A, BL);
  R2 = SACI_IEXP(10, JL);
  R = SACRN_RNRED(C_50_A, R2);
  RP = SACRN_RNINT(R1);
  if (s < 0) {
    R = SACRN_RNDIF(RP, R);
  } else {
    R = SACRN_RNSUM(RP, R);
  }
  return R;
}

void MASRN_RNDWR
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST NL)
# else
(R, NL)
MASSTOR_LIST R, NL;
# endif
{
  MASSTOR_LIST C_49_A, B, D, DL, F, IL, M, SL, TL;

  if (R == 0) {
    C_49_A = 0;
    B = 1;
  } else {
    SACLIST_FIRST2(R, &C_49_A, &B);
  }
  SL = SACI_ISIGNF(C_49_A);
  if (SL < 0) {
    C_49_A = SACI_INEG(C_49_A);
  }
  M = SACI_IEXP(10, NL);
  C_49_A = SACI_IPROD(C_49_A, M);
  SACI_IQR(C_49_A, B, &D, &F);
  F = SACI_IDPR(F, 2);
  if (F == 0) {
    TL = 0;
  } else {
    TL = SACI_ICOMP(B, F);
    if (TL == 0) {
      TL = 1;
    } else {
      if (TL < 0) {
        D = SACI_ISUM(D, 1);
      }
    }
  }
  if (SL < 0) {
    MASBIOS_SWRITE("-", 1L);
  }
  SACI_IQR(D, M, &D, &F);
  SACI_IWRITE(D);
  MASBIOS_SWRITE(".", 1L);
  {
    LONGINT B_1 = 1, B_2 = NL;

    if (B_1 <= B_2)
      for (IL = B_1;; IL += 1) {
        F = SACI_IDPR(F, 10);
        SACI_IQR(F, M, &DL, &F);
        MASBIOS_CWRITE(DL);
        if (IL >= B_2) break;
      }
  }
  return;
}

void MASRN_RNDWRS
# ifdef __STDC__
(MASSTOR_LIST C_48_A, MASSTOR_LIST S)
# else
(C_48_A, S)
MASSTOR_LIST C_48_A, S;
# endif
{
  MASRN_RNDWR(C_48_A, S);
  return;
}

MASSTOR_LIST MASRN_RNEXP
# ifdef __STDC__
(MASSTOR_LIST C_47_A, MASSTOR_LIST NL)
# else
(C_47_A, NL)
MASSTOR_LIST C_47_A, NL;
# endif
{
  MASSTOR_LIST B, KL;

  if (NL == 0) {
    B = SACRN_RNINT(1);
    return B;
  }
  if (NL == 1) {
    B = C_47_A;
    return B;
  }
  KL = NL / 2;
  B = MASRN_RNEXP(C_47_A, KL);
  B = SACRN_RNPROD(B, B);
  if (NL > 2 * KL) {
    B = SACRN_RNPROD(B, C_47_A);
  }
  return B;
}

MASSTOR_LIST MASRN_RNMAX
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST BL)
# else
(AL, BL)
MASSTOR_LIST AL, BL;
# endif
{
  MASSTOR_LIST CL, SL;

  SL = SACRN_RNCOMP(AL, BL);
  if (SL >= 0) {
    CL = AL;
  } else {
    CL = BL;
  }
  return CL;
}

MASSTOR_LIST MASRN_RNONE
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST R1, R2, SL;

  SL = 0;
  if (R == 0) {
    return SL;
  }
  SACLIST_FIRST2(R, &R1, &R2);
  SL = SACLIST_EQUAL(R1, R2);
  return SL;
}

void BEGIN_MASRN()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_MASBIOS();
    BEGIN_SACLIST();
    BEGIN_SACD();
    BEGIN_SACI();
    BEGIN_SACRN();

  }
}
