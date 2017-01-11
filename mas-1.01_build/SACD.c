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

#ifndef DEFINITION_SACD
#include "SACD.h"
#endif

MASSTOR_LIST SACD_THETA, SACD_ZETA, SACD_DELTA, SACD_ETA, SACD_EPSIL;
struct SACD_1 SACD_TABP2;
CHAR SACD_rcsid [] = "$Id: SACD.md,v 1.2 1992/02/12 13:19:10 pesch Exp $";
CHAR SACD_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static MASSTOR_LIST RINC, RMULT, RTERM;
static CHAR rcsidi [] = "$Id: SACD.mi,v 1.3 1992/10/15 16:28:17 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
static void BEGIN2 ARGS(());


static void BEGIN2
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST IL, J1Y, J2Y, L, ML, TL;

  IL = 1;
  TL = 1;
  while (TL < MASSTOR_BETA) {
    SACD_TABP2.A[(INTEGER)IL - 1] = TL;
    IL = IL + 1;
    TL = TL + TL;
  }
  SACD_ZETA = IL - 1;
  SACD_ETA = 0;
  TL = MASSTOR_BETA;
  do {
    TL = TL / 10;
    SACD_ETA = SACD_ETA + 1;
  } while (!(TL < 10));
  SACD_THETA = 1;
  {
    LONGINT B_1 = 1, B_2 = SACD_ETA;

    if (B_1 <= B_2)
      for (IL = B_1;; IL += 1) {
        SACD_THETA = 10 * SACD_THETA;
        if (IL >= B_2) break;
      }
  }
  J1Y = SACD_ZETA / 2;
  J1Y = J1Y + 1;
  SACD_DELTA = SACD_TABP2.A[(INTEGER)J1Y - 1];
  SACD_EPSIL = MASSTOR_BETA / SACD_DELTA;
  J1Y = SACLIST_LIST10(3, 1, 4, 1, 5, 9, 2, 6, 5, 3);
  J2Y = SACLIST_LIST10(5, 8, 9, 7, 9, 3, 2, 3, 8, 4);
  L = SACLIST_CONC(J1Y, J2Y);
  ML = 0;
  while (ML < MASSTOR_BETA / 10) {
    MASSTOR_ADV(L, &TL, &L);
    J1Y = 10 * ML;
    ML = J1Y + TL;
  }
  ML = ML / 8;
  J1Y = 8 * ML;
  RMULT = J1Y + 5;
  J1Y = SACLIST_LIST10(2, 1, 1, 3, 2, 4, 8, 6, 5, 4);
  J2Y = SACLIST_LIST10(0, 5, 1, 8, 7, 1, 0, 0, 0, 0);
  L = SACLIST_CONC(J1Y, J2Y);
  ML = 0;
  {
    LONGINT B_3 = 1, B_4 = SACD_ETA;

    if (B_3 <= B_4)
      for (IL = B_3;; IL += 1) {
        MASSTOR_ADV(L, &TL, &L);
        J1Y = 10 * ML;
        ML = J1Y + TL;
        if (IL >= B_4) break;
      }
  }
  SACD_DQR(ML, 0, SACD_THETA, &RINC, &TL);
  if (MASELEM_MASEVEN(RINC)) {
    RINC = RINC + 1;
  }
  J1Y = SACLIST_LIST10(5, 7, 7, 2, 1, 5, 6, 6, 4, 9);
  J2Y = SACLIST_LIST10(0, 1, 5, 3, 2, 8, 6, 0, 6, 0);
  L = SACLIST_CONC(J1Y, J2Y);
  ML = 0;
  {
    LONGINT B_5 = 1, B_6 = SACD_ETA;

    if (B_5 <= B_6)
      for (IL = B_5;; IL += 1) {
        MASSTOR_ADV(L, &TL, &L);
        J1Y = 10 * ML;
        ML = J1Y + TL;
        if (IL >= B_6) break;
      }
  }
  RTERM = ML;
  return;
}

MASSTOR_LIST SACD_BITRAN
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST AL, BL, IDUM;

  AL = SACD_DRANN();
  AL = AL + AL;
  if (AL >= MASSTOR_BETA) {
    BL = 1;
  } else {
    BL = 0;
  }
  return BL;
}

void SACD_DEGCD
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST BL, MASSTOR_LIST *CL, MASSTOR_LIST *UL, MASSTOR_LIST *VL)
# else
(AL, BL, CL, UL, VL)
MASSTOR_LIST AL, BL;
MASSTOR_LIST *CL, *UL, *VL;
# endif
{
  MASSTOR_LIST AL1, AL2, AL3, J1Y, QL, UL1, UL2, UL3, VL1, VL2, VL3;

  AL1 = AL;
  AL2 = BL;
  UL1 = 1;
  UL2 = 0;
  VL1 = 0;
  VL2 = 1;
  while (AL2 != 0) {
    MASELEM_MASQREM(AL1, AL2, &QL, &AL3);
    AL1 = AL2;
    AL2 = AL3;
    J1Y = QL * UL2;
    UL3 = UL1 - J1Y;
    UL1 = UL2;
    UL2 = UL3;
    J1Y = QL * VL2;
    VL3 = VL1 - J1Y;
    VL1 = VL2;
    VL2 = VL3;
  }
  *CL = AL1;
  *UL = UL1;
  *VL = VL1;
  return;
}

MASSTOR_LIST SACD_DGCD
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST BL)
# else
(AL, BL)
MASSTOR_LIST AL, BL;
# endif
{
  MASSTOR_LIST AL1, AL2, AL3, CL;

  AL1 = AL;
  AL2 = BL;
  while (AL2 != 0) {
    AL3 = MASELEM_MASREM(AL1, AL2);
    AL1 = AL2;
    AL2 = AL3;
  }
  CL = AL1;
  return CL;
}

MASSTOR_LIST SACD_DLOG2
# ifdef __STDC__
(MASSTOR_LIST AL)
# else
(AL)
MASSTOR_LIST AL;
# endif
{
  MASSTOR_LIST ALB, IL, J1Y, JL, NL;

  if (AL == 0) {
    NL = 0;
    return NL;
  }
  ALB = MASELEM_MASABS(AL);
  IL = 1;
  JL = SACD_ZETA + 1;
  do {
    J1Y = IL + JL;
    NL = J1Y / 2;
    if (ALB >= SACD_TABP2.A[(INTEGER)NL - 1]) {
      IL = NL;
    } else {
      JL = NL;
    }
  } while (!(JL - IL == 1));
  NL = IL;
  return NL;
}

void SACD_DPCC
# ifdef __STDC__
(MASSTOR_LIST AL1, MASSTOR_LIST AL2, MASSTOR_LIST *UL, MASSTOR_LIST *ULP, MASSTOR_LIST *VL, MASSTOR_LIST *VLP)
# else
(AL1, AL2, UL, ULP, VL, VLP)
MASSTOR_LIST AL1, AL2;
MASSTOR_LIST *UL, *ULP, *VL, *VLP;
# endif
{
  MASSTOR_LIST AL, ALP, ALPP, J1Y, QL, ULPP, VLPP;

  AL = AL1;
  ALP = AL2;
  *UL = 1;
  *ULP = 0;
  *VL = 0;
  *VLP = 1;
  for (;;) {
    QL = AL / ALP;
    J1Y = QL * ALP;
    ALPP = AL - J1Y;
    J1Y = QL * *ULP;
    ULPP = *UL - J1Y;
    J1Y = QL * *VLP;
    VLPP = *VL - J1Y;
    if (ALPP < MASELEM_MASABS(VLPP) || ALP - ALPP < MASELEM_MASABS(*VLP - VLPP)) {
      return;
    }
    AL = ALP;
    ALP = ALPP;
    *UL = *ULP;
    *ULP = ULPP;
    *VL = *VLP;
    *VLP = VLPP;
  } EXIT_1:;
  return;
}

void SACD_DPR
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST BL, MASSTOR_LIST *CL, MASSTOR_LIST *DL)
# else
(AL, BL, CL, DL)
MASSTOR_LIST AL, BL;
MASSTOR_LIST *CL, *DL;
# endif
{
  MASSTOR_LIST AL0, AL1, BL0, BL1, CL0, CL00, CL01, CL1, CL10, CL11, CL2, CLP, DLP, J1Y, J2Y;

  AL1 = AL / SACD_EPSIL;
  J1Y = AL1 * SACD_EPSIL;
  AL0 = AL - J1Y;
  BL1 = BL / SACD_EPSIL;
  J1Y = BL1 * SACD_EPSIL;
  BL0 = BL - J1Y;
  CL0 = AL0 * BL0;
  J1Y = AL1 * BL0;
  J2Y = AL0 * BL1;
  CL1 = J1Y + J2Y;
  CL2 = AL1 * BL1;
  if (CL0 >= MASSTOR_BETA) {
    CL01 = 1;
    CL00 = CL0 - MASSTOR_BETA;
  } else {
    if (CL0 <= -MASSTOR_BETA) {
      CL01 = -1;
      CL00 = CL0 + MASSTOR_BETA;
    } else {
      CL01 = 0;
      CL00 = CL0;
    }
  }
  CL11 = CL1 / SACD_DELTA;
  J1Y = CL11 * SACD_DELTA;
  CL10 = CL1 - J1Y;
  J1Y = CL2 + CL01;
  CLP = J1Y + CL11;
  if (SACD_DELTA != SACD_EPSIL) {
    CLP = CLP + CL2;
  }
  J1Y = CL10 * SACD_EPSIL;
  DLP = J1Y + CL00;
  if (DLP >= MASSTOR_BETA) {
    *CL = CLP + 1;
    *DL = DLP - MASSTOR_BETA;
  } else {
    if (DLP <= -MASSTOR_BETA) {
      *CL = CLP - 1;
      *DL = DLP + MASSTOR_BETA;
    } else {
      *CL = CLP;
      *DL = DLP;
    }
  }
  return;
}

void SACD_DQR
# ifdef __STDC__
(MASSTOR_LIST AL1, MASSTOR_LIST AL0, MASSTOR_LIST BL, MASSTOR_LIST *QL, MASSTOR_LIST *RL)
# else
(AL1, AL0, BL, QL, RL)
MASSTOR_LIST AL1, AL0, BL;
MASSTOR_LIST *QL, *RL;
# endif
{
  MASSTOR_LIST ALP0, ALP1, BLP, QLP;
  INTEGER IL;

  if (AL1 == 0) {
    MASELEM_MASQREM(AL0, BL, QL, RL);
    return;
  }
  ALP1 = MASELEM_MASABS(AL1);
  ALP0 = MASELEM_MASABS(AL0);
  BLP = MASELEM_MASABS(BL);
  QLP = 0;
  {
    LONGINT B_7 = 1, B_8 = (INTEGER)SACD_ZETA;

    if (B_7 <= B_8)
      for (IL = B_7;; IL += 1) {
        ALP1 = ALP1 + ALP1;
        ALP0 = ALP0 + ALP0;
        if (ALP0 >= MASSTOR_BETA) {
          ALP0 = ALP0 - MASSTOR_BETA;
          ALP1 = ALP1 + 1;
        }
        QLP = QLP + QLP;
        if (ALP1 >= BLP) {
          ALP1 = ALP1 - BLP;
          QLP = QLP + 1;
        }
        if (IL >= B_8) break;
      }
  }
  if (AL1 < 0) {
    QLP = -QLP;
    ALP1 = -ALP1;
  }
  if (BL < 0) {
    QLP = -QLP;
  }
  *QL = QLP;
  *RL = ALP1;
  return;
}

MASSTOR_LIST SACD_DRAN
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST AL, AL1, AL2, IDUM, J1Y, SL;

  AL1 = SACD_DRANN();
  SL = 0;
  AL1 = AL1 + AL1;
  if (AL1 >= MASSTOR_BETA) {
    SL = 1;
    AL1 = AL1 - MASSTOR_BETA;
  }
  AL1 = AL1 / SACD_DELTA;
  AL2 = SACD_DRANN();
  AL2 = AL2 / SACD_EPSIL;
  J1Y = AL1 * SACD_DELTA;
  AL = J1Y + AL2;
  if (SL == 1) {
    AL = -AL;
  }
  return AL;
}

MASSTOR_LIST SACD_DRANN
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST AL, TL;

  SACD_DPR(RTERM, RMULT, &TL, &AL);
  AL = AL + RINC;
  if (AL >= MASSTOR_BETA) {
    AL = AL - MASSTOR_BETA;
  }
  RTERM = AL;
  return AL;
}

void SACD_DSQRTF
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST *BL, MASSTOR_LIST *TL)
# else
(AL, BL, TL)
MASSTOR_LIST AL;
MASSTOR_LIST *BL, *TL;
# endif
{
  MASSTOR_LIST CL, HL, J1Y, KL, RL;

  if (AL == 0) {
    *BL = 0;
    *TL = 0;
    return;
  }
  KL = SACD_DLOG2(AL);
  J1Y = KL + 1;
  HL = J1Y / 2;
  *BL = SACD_TABP2.A[(INTEGER)HL + 1 - 1];
  for (;;) {
    MASELEM_MASQREM(AL, *BL, &CL, &RL);
    if (*BL <= CL) {
      J1Y = *BL * *BL;
      J1Y = AL - J1Y;
      *TL = MASELEM_MASSIGN(J1Y);
      return;
    }
    J1Y = *BL + CL;
    *BL = J1Y / 2;
  } EXIT_2:;
  return;
}

void BEGIN_SACD()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();

    BEGIN2();
  }
}
