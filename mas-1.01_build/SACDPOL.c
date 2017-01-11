#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SACM
#include "SACM.h"
#endif

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_SACDPOL
#include "SACDPOL.h"
#endif

CHAR SACDPOL_rcsid [] = "$Id: SACDPOL.md,v 1.2 1992/02/12 17:33:56 pesch Exp $";
CHAR SACDPOL_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SACDPOL.mi,v 1.3 1992/10/15 16:28:39 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST SACDPOL_DMPPRD
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST ML, MASSTOR_LIST C_44_A, MASSTOR_LIST B)
# else
(RL, ML, C_44_A, B)
MASSTOR_LIST RL, ML, C_44_A, B;
# endif
{
  MASSTOR_LIST AL, AP, AS, BL, BP, BS, C, C1, CL, EL, FL, IL, JL, NL, RLP;

  if (C_44_A == 0 || B == 0) {
    C = 0;
    return C;
  }
  if (RL == 0) {
    C = SACM_MDPROD(ML, C_44_A, B);
    return C;
  }
  MASSTOR_ADV(C_44_A, &EL, &AP);
  MASSTOR_ADV(B, &FL, &BP);
  AS = SACLIST_CINV(AP);
  BS = SACLIST_CINV(BP);
  C = 0;
  RLP = RL - 1;
  {
    LONGINT B_1 = 0, B_2 = FL;

    if (B_1 <= B_2)
      for (IL = B_1;; IL += 1) {
        C1 = MASSTOR_BETA;
        {
          LONGINT B_3 = 1, B_4 = IL;

          if (B_3 <= B_4)
            for (JL = B_3;; JL += 1) {
              C1 = MASSTOR_COMP(0, C1);
              if (JL >= B_4) break;
            }
        }
        AP = AS;
        MASSTOR_ADV(BS, &BL, &BS);
        {
          LONGINT B_5 = 0, B_6 = EL;

          if (B_5 <= B_6)
            for (JL = B_5;; JL += 1) {
              MASSTOR_ADV(AP, &AL, &AP);
              if (RLP == 0) {
                CL = SACM_MDPROD(ML, AL, BL);
              } else {
                CL = SACDPOL_DMPPRD(RLP, ML, AL, BL);
              }
              C1 = MASSTOR_COMP(CL, C1);
              if (JL >= B_6) break;
            }
        }
        NL = EL + IL;
        while (C1 != MASSTOR_SIL && MASSTOR_FIRST(C1) == 0) {
          NL = NL - 1;
          C1 = MASSTOR_RED(C1);
        }
        if (C1 != MASSTOR_SIL) {
          C1 = MASSTOR_COMP(NL, C1);
          C = SACDPOL_DMPSUM(RL, ML, C1, C);
        }
        if (IL >= B_2) break;
      }
  }
  return C;
}

MASSTOR_LIST SACDPOL_DMPSUM
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST ML, MASSTOR_LIST C_43_A, MASSTOR_LIST B)
# else
(RL, ML, C_43_A, B)
MASSTOR_LIST RL, ML, C_43_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, EL, FL, IL, RLP;

  if (C_43_A == 0) {
    C = B;
    return C;
  }
  if (B == 0) {
    C = C_43_A;
    return C;
  }
  RLP = RL - 1;
  if (MASSTOR_FIRST(C_43_A) >= MASSTOR_FIRST(B)) {
    MASSTOR_ADV(C_43_A, &EL, &AP);
    MASSTOR_ADV(B, &FL, &BP);
  } else {
    MASSTOR_ADV(B, &EL, &AP);
    MASSTOR_ADV(C_43_A, &FL, &BP);
  }
  C = MASSTOR_BETA;
  {
    LONGINT B_7 = 1, B_8 = EL - FL;

    if (B_7 <= B_8)
      for (IL = B_7;; IL += 1) {
        MASSTOR_ADV(AP, &AL, &AP);
        C = MASSTOR_COMP(AL, C);
        if (IL >= B_8) break;
      }
  }
  do {
    MASSTOR_ADV(AP, &AL, &AP);
    MASSTOR_ADV(BP, &BL, &BP);
    if (RLP == 0) {
      CL = SACM_MDSUM(ML, AL, BL);
    } else {
      CL = SACDPOL_DMPSUM(RLP, ML, AL, BL);
    }
    C = MASSTOR_COMP(CL, C);
  } while (!(AP == MASSTOR_SIL));
  C = MASSTOR_INV(C);
  while (C != MASSTOR_SIL && MASSTOR_FIRST(C) == 0) {
    C = MASSTOR_RED(C);
    EL = EL - 1;
  }
  if (C == MASSTOR_SIL) {
    C = 0;
  } else {
    C = MASSTOR_COMP(EL, C);
  }
  return C;
}

MASSTOR_LIST SACDPOL_DMUPNR
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST C_42_A, MASSTOR_LIST B)
# else
(PL, C_42_A, B)
MASSTOR_LIST PL, C_42_A, B;
# endif
{
  MASSTOR_LIST AL, AP, APP, AS, BL, BLP, BP, BPP, BS, C, CL, KL, ML, NL;

  NL = MASSTOR_FIRST(B);
  if (NL == 0) {
    C = 0;
    return C;
  }
  BP = MASSTOR_RED(B);
  MASSTOR_ADV(BP, &BL, &BS);
  BLP = SACM_MDINV(PL, BL);
  AS = C_42_A;
  do {
    MASSTOR_ADV(AS, &KL, &AP);
    ML = -1;
    MASSTOR_ADV(AP, &AL, &APP);
    CL = SACM_MDPROD(PL, AL, BLP);
    BPP = BS;
    do {
      MASSTOR_ADV(BPP, &BL, &BPP);
      BL = SACM_MDPROD(PL, BL, CL);
      AL = MASSTOR_FIRST(APP);
      AL = SACM_MDDIF(PL, AL, BL);
      KL = KL - 1;
      if (ML < 0 && AL != 0) {
        ML = KL;
        AS = AP;
      }
      MASSTOR_SFIRST(APP, AL);
      AP = APP;
      APP = MASSTOR_RED(AP);
    } while (!(BPP == MASSTOR_SIL));
    while (ML < 0 && APP != MASSTOR_SIL) {
      KL = KL - 1;
      if (MASSTOR_FIRST(APP) != 0) {
        ML = KL;
        AS = AP;
      }
      AP = APP;
      APP = MASSTOR_RED(AP);
    }
    if (ML >= 0) {
      MASSTOR_SFIRST(AS, ML);
    }
  } while (!(ML < NL));
  if (ML >= 0) {
    C = AS;
  } else {
    C = 0;
  }
  return C;
}

MASSTOR_LIST SACDPOL_DPFP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_41_A)
# else
(RL, C_41_A)
MASSTOR_LIST RL, C_41_A;
# endif
{
  MASSTOR_LIST AP, B, BL, J1Y, KL, NL, RLP;

  if (C_41_A == 0 || RL == 0) {
    B = C_41_A;
    return B;
  }
  NL = SACPOL_PDEG(C_41_A);
  RLP = RL - 1;
  B = MASSTOR_BETA;
  AP = C_41_A;
  for (KL = NL; KL >= 0; KL += -1) {
    if (AP == MASSTOR_SIL || MASSTOR_FIRST(AP) < KL) {
      BL = 0;
    } else {
      AP = MASSTOR_RED(AP);
      MASSTOR_ADV(AP, &BL, &AP);
      if (RLP > 0) {
        BL = SACDPOL_DPFP(RLP, BL);
      }
    }
    B = MASSTOR_COMP(BL, B);
  }
  J1Y = MASSTOR_INV(B);
  B = MASSTOR_COMP(NL, J1Y);
  return B;
}

void BEGIN_SACDPOL()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_SACM();
    BEGIN_SACPOL();

  }
}
