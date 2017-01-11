#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
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

#ifndef DEFINITION_MASI
#include "MASI.h"
#endif

CHAR MASI_rcsid [] = "$Id: MASI.md,v 1.2 1992/02/12 13:19:03 pesch Exp $";
CHAR MASI_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASI.mi,v 1.3 1992/10/15 16:28:12 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST MASI_IPROD
# ifdef __STDC__
(MASSTOR_LIST C_43_A, MASSTOR_LIST B)
# else
(C_43_A, B)
MASSTOR_LIST C_43_A, B;
# endif
{
  MASSTOR_LIST A0, A1, AL, AP, AP0, APP, AS, B0, B1, BL, BP, BP0, BS, C, C0, C1, C2, CH, CL, CLP, CP, CPP, CS, CSP, EL, FL, I, KL, L, ML, NL, TL;

  if (C_43_A == 0 || B == 0) {
    C = 0;
    return C;
  }
  if (C_43_A < MASSTOR_BETA && B < MASSTOR_BETA) {
    SACD_DPR(C_43_A, B, &CLP, &CL);
    if (CLP == 0) {
      C = CL;
    } else {
      C = SACLIST_LIST2(CL, CLP);
    }
    return C;
  }
  if (C_43_A < MASSTOR_BETA) {
    C = SACI_IDPR(B, C_43_A);
    return C;
  }
  if (B < MASSTOR_BETA) {
    C = SACI_IDPR(C_43_A, B);
    return C;
  }
  ML = MASSTOR_LENGTH(C_43_A);
  NL = MASSTOR_LENGTH(B);
  if (ML >= NL) {
    AP0 = C_43_A;
    BP0 = B;
  } else {
    AP0 = B;
    BP0 = C_43_A;
    TL = ML;
    ML = NL;
    NL = TL;
  }
  if (NL <= 16) {
    AP = AP0;
    BP = BP0;
    C = SACLIST_LIST2(0, 0);
    CS = C;
    {
      LONGINT B_1 = 1, B_2 = ML + NL - 2;

      if (B_1 <= B_2)
        for (I = B_1;; I += 1) {
          C = MASSTOR_COMP(0, C);
          if (I >= B_2) break;
        }
    }
    CP = C;
    do {
      APP = AP;
      MASSTOR_ADV(BP, &BL, &BP);
      if (BL != 0) {
        CPP = CP;
        CLP = 0;
        do {
          MASSTOR_ADV(APP, &AL, &APP);
          SACD_DPR(AL, BL, &EL, &FL);
          CL = MASSTOR_FIRST(CPP);
          CL = CL + FL;
          CL = CL + CLP;
          CLP = CL / MASSTOR_BETA;
          TL = CLP * MASSTOR_BETA;
          CL = CL - TL;
          MASSTOR_SFIRST(CPP, CL);
          CLP = EL + CLP;
          CPP = MASSTOR_RED(CPP);
        } while (!(APP == MASSTOR_SIL));
        MASSTOR_SFIRST(CPP, CLP);
      }
      CP = MASSTOR_RED(CP);
    } while (!(BP == MASSTOR_SIL));
    if (CLP == 0) {
      MASSTOR_SRED(CS, MASSTOR_SIL);
    }
    return C;
  }
  if (ML >= 2 * NL) {
    L = MASSTOR_BETA;
    do {
      SACI_ISEG(AP0, NL, &AP0, &A0);
      C0 = MASI_IPROD(A0, BP0);
      L = MASSTOR_COMP(C0, L);
    } while (!(AP0 == 0));
    L = MASSTOR_INV(L);
    C = SACI_ISSUM(NL, L);
    return C;
  }
  KL = ML / 2;
  if (ML > KL + KL) {
    KL = KL + 1;
  }
  SACI_ISEG(AP0, KL, &A1, &A0);
  SACI_ISEG(BP0, KL, &B1, &B0);
  AS = SACI_ISUM(A1, A0);
  BS = SACI_ISUM(B1, B0);
  C2 = MASI_IPROD(A1, B1);
  C0 = MASI_IPROD(A0, B0);
  CSP = MASI_IPROD(AS, BS);
  CH = SACI_ISUM(C0, C2);
  C1 = SACI_IDIF(CSP, CH);
  L = SACLIST_LIST3(C0, C1, C2);
  C = SACI_ISSUM(KL, L);
  return C;
}

void BEGIN_MASI()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_SACD();
    BEGIN_SACI();

  }
}
