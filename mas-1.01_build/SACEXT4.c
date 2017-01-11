#include "SYSTEM_.h"

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

#ifndef DEFINITION_SACCOMB
#include "SACCOMB.h"
#endif

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_SACIPOL
#include "SACIPOL.h"
#endif

#ifndef DEFINITION_SACRPOL
#include "SACRPOL.h"
#endif

#ifndef DEFINITION_SACPGCD
#include "SACPGCD.h"
#endif

#ifndef DEFINITION_SACEXT4
#include "SACEXT4.h"
#endif

CHAR SACEXT4_rcsid [] = "$Id: SACEXT4.md,v 1.2 1992/02/12 17:34:49 pesch Exp $";
CHAR SACEXT4_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SACEXT4.mi,v 1.3 1992/10/15 16:28:57 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST SACEXT4_IPINT
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_161_A, MASSTOR_LIST BL)
# else
(RL, C_161_A, BL)
MASSTOR_LIST RL, C_161_A, BL;
# endif
{
  MASSTOR_LIST AL, AP, B, CL, EL, RLP;

  AP = C_161_A;
  B = MASSTOR_BETA;
  RLP = RL - 1;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    EL = EL + 1;
    if (RL == 1) {
      CL = SACI_IQ(AL, EL);
    } else {
      CL = SACIPOL_IPIQ(RLP, AL, EL);
    }
    B = SACLIST_COMP2(CL, EL, B);
  } while (!(AP == MASSTOR_SIL));
  if (BL != 0) {
    B = SACLIST_COMP2(BL, 0, B);
  }
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST SACEXT4_IUPIHT
# ifdef __STDC__
(MASSTOR_LIST C_160_A, MASSTOR_LIST NL)
# else
(C_160_A, NL)
MASSTOR_LIST C_160_A, NL;
# endif
{
  MASSTOR_LIST B, CL, J1Y, M, SL;

  M = SACPOL_PMON(NL, 1);
  J1Y = MASSTOR_LIST1(M);
  B = SACIPOL_IPGSUB(1, C_160_A, 1, J1Y);
  SACPGCD_IPSCPP(1, B, &SL, &CL, &B);
  return B;
}

MASSTOR_LIST SACEXT4_PCONST
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_159_A)
# else
(RL, C_159_A)
MASSTOR_LIST RL, C_159_A;
# endif
{
  MASSTOR_LIST AP, BL, IL;

  BL = 1;
  if (C_159_A == 0) {
    return BL;
  }
  AP = C_159_A;
  {
    LONGINT B_1 = 1, B_2 = RL;

    if (B_1 <= B_2)
      for (IL = B_1;; IL += 1) {
        if (SACPOL_PDEG(AP) != 0) {
          BL = 0;
          return BL;
        } else {
          AP = SACPOL_PLDCF(AP);
        }
        if (IL >= B_2) break;
      }
  }
  return BL;
}

MASSTOR_LIST SACEXT4_PSDSV
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_158_A, MASSTOR_LIST IL, MASSTOR_LIST NL)
# else
(RL, C_158_A, IL, NL)
MASSTOR_LIST RL, C_158_A, IL, NL;
# endif
{
  MASSTOR_LIST AL, AP, B, BL, EL, FL, RLP;

  if (C_158_A == 0 || NL == 0) {
    B = C_158_A;
    return B;
  }
  AP = C_158_A;
  B = MASSTOR_BETA;
  RLP = RL - 1;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    if (IL == RL) {
      BL = AL;
      FL = EL / NL;
    } else {
      BL = SACPOL_PDPV(RLP, AL, IL, NL);
      FL = EL;
    }
    B = SACLIST_COMP2(BL, FL, B);
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST SACEXT4_PUNT
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_157_A)
# else
(RL, C_157_A)
MASSTOR_LIST RL, C_157_A;
# endif
{
  MASSTOR_LIST AP, BL, IL;

  BL = 2;
  if (C_157_A == 0) {
    return BL;
  }
  AP = C_157_A;
  {
    LONGINT B_3 = 1, B_4 = RL - 1;

    if (B_3 <= B_4)
      for (IL = B_3;; IL += 1) {
        if (SACPOL_PDEG(AP) != 0) {
          BL = 0;
          return BL;
        } else {
          AP = SACPOL_PLDCF(AP);
        }
        if (IL >= B_4) break;
      }
  }
  if (SACPOL_PDEG(AP) > 0) {
    BL = 1;
  }
  return BL;
}

MASSTOR_LIST SACEXT4_RPDMV
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_156_A)
# else
(RL, C_156_A)
MASSTOR_LIST RL, C_156_A;
# endif
{
  MASSTOR_LIST AL, AP, B, BL, EL, ELP, J1Y, RLP;

  if (C_156_A == 0) {
    B = 0;
    return B;
  }
  AP = C_156_A;
  RLP = RL - 1;
  B = MASSTOR_BETA;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    if (RLP == 0) {
      J1Y = SACRN_RNINT(EL);
      BL = SACRN_RNPROD(J1Y, AL);
    } else {
      J1Y = SACRN_RNINT(EL);
      BL = SACRPOL_RPRNP(RLP, J1Y, AL);
    }
    ELP = EL - 1;
    if (EL != 0) {
      B = SACLIST_COMP2(BL, ELP, B);
    }
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  if (B == MASSTOR_SIL) {
    B = 0;
  }
  return B;
}

MASSTOR_LIST SACEXT4_RPMAIP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_155_A)
# else
(RL, C_155_A)
MASSTOR_LIST RL, C_155_A;
# endif
{
  MASSTOR_LIST AL, B;

  if (C_155_A == 0) {
    B = 0;
    return B;
  }
  B = SACRPOL_RPFIP(RL, C_155_A);
  AL = SACPOL_PLBCF(RL, B);
  AL = SACRN_RNINV(AL);
  B = SACRPOL_RPRNP(RL, AL, B);
  return B;
}

void BEGIN_SACEXT4()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_SACI();
    BEGIN_SACRN();
    BEGIN_SACCOMB();
    BEGIN_SACPOL();
    BEGIN_SACIPOL();
    BEGIN_SACRPOL();
    BEGIN_SACPGCD();

  }
}
