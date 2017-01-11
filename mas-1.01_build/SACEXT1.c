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

#ifndef DEFINITION_SACEXT1
#include "SACEXT1.h"
#endif

CHAR SACEXT1_rcsid [] = "$Id: SACEXT1.md,v 1.2 1992/02/12 17:34:45 pesch Exp $";
CHAR SACEXT1_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SACEXT1.mi,v 1.3 1992/10/15 16:28:54 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST SACEXT1_LCONC
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST L1, L2, LP, LP1, M;

  if (L == MASSTOR_SIL) {
    M = MASSTOR_BETA;
    return M;
  }
  LP = L;
  do {
    MASSTOR_ADV(LP, &M, &LP);
  } while (!(M != MASSTOR_SIL || LP == MASSTOR_SIL));
  L1 = M;
  while (LP != MASSTOR_SIL) {
    MASSTOR_ADV(LP, &L2, &LP);
    if (L2 != MASSTOR_SIL) {
      LP1 = SACLIST_LAST(L1);
      MASSTOR_SRED(LP1, L2);
      L1 = L2;
    }
  }
  return M;
}

MASSTOR_LIST SACEXT1_LEQUAL
# ifdef __STDC__
(MASSTOR_LIST C_45_A, MASSTOR_LIST B)
# else
(C_45_A, B)
MASSTOR_LIST C_45_A, B;
# endif
{
  MASSTOR_LIST A1, AP, B1, BL, BP;

  BL = 1;
  AP = C_45_A;
  while (AP != MASSTOR_SIL) {
    MASSTOR_ADV(AP, &A1, &AP);
    BL = SACLIST_MEMBER(A1, B);
    if (BL == 0) {
      return BL;
    }
  }
  BP = B;
  while (BP != MASSTOR_SIL) {
    MASSTOR_ADV(BP, &B1, &BP);
    BL = SACLIST_MEMBER(B1, C_45_A);
    if (BL == 0) {
      return BL;
    }
  }
  return BL;
}

MASSTOR_LIST SACEXT1_LMERGE
# ifdef __STDC__
(MASSTOR_LIST C_44_A, MASSTOR_LIST B)
# else
(C_44_A, B)
MASSTOR_LIST C_44_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, SL;

  C = C_44_A;
  BP = B;
  while (BP != MASSTOR_SIL) {
    MASSTOR_ADV(BP, &BL, &BP);
    AP = C_44_A;
    SL = 0;
    while (AP != MASSTOR_SIL && SL == 0) {
      MASSTOR_ADV(AP, &AL, &AP);
      SL = SACLIST_EQUAL(AL, BL);
    }
    if (SL == 0) {
      C = MASSTOR_COMP(BL, C);
    }
  }
  return C;
}

void BEGIN_SACEXT1()
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
