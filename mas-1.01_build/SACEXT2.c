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

#ifndef DEFINITION_SACEXT2
#include "SACEXT2.h"
#endif

CHAR SACEXT2_rcsid [] = "$Id: SACEXT2.md,v 1.2 1992/02/12 17:34:46 pesch Exp $";
CHAR SACEXT2_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SACEXT2.mi,v 1.3 1992/10/15 16:28:55 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


void SACEXT2_RNBCR
# ifdef __STDC__
(MASSTOR_LIST C_43_A, MASSTOR_LIST B, MASSTOR_LIST *M, MASSTOR_LIST *N, MASSTOR_LIST *KL)
# else
(C_43_A, B, M, N, KL)
MASSTOR_LIST C_43_A, B;
MASSTOR_LIST *M, *N, *KL;
# endif
{
  MASSTOR_LIST A2, B2, EL1, EL2, J1Y;

  if (C_43_A == 0) {
    *M = 0;
  } else {
    SACLIST_FIRST2(C_43_A, M, &A2);
    if (A2 == 1) {
      EL1 = SACI_IORD2(*M);
      *M = SACI_IDP2(*M, EL1);
    } else {
      J1Y = SACI_IORD2(A2);
      EL1 = -J1Y;
    }
  }
  if (B == 0) {
    *N = 0;
    EL2 = 0;
  } else {
    SACLIST_FIRST2(B, N, &B2);
    if (B2 == 1) {
      EL2 = SACI_IORD2(*N);
      *N = SACI_IDP2(*N, EL2);
    } else {
      J1Y = SACI_IORD2(B2);
      EL2 = -J1Y;
    }
  }
  if (C_43_A == 0) {
    *KL = EL2;
    return;
  } else {
    if (B == 0) {
      *KL = EL1;
      return;
    }
  }
  if (EL1 <= EL2) {
    J1Y = EL2 - EL1;
    *N = SACI_IMP2(*N, J1Y);
    *KL = EL1;
  } else {
    J1Y = EL1 - EL2;
    *M = SACI_IMP2(*M, J1Y);
    *KL = EL2;
  }
  return;
}

void BEGIN_SACEXT2()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_SACI();

  }
}
