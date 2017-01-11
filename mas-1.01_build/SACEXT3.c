#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SACEXT3
#include "SACEXT3.h"
#endif

CHAR SACEXT3_rcsid [] = "$Id: SACEXT3.md,v 1.2 1992/02/12 17:34:48 pesch Exp $";
CHAR SACEXT3_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SACEXT3.mi,v 1.3 1992/10/15 16:28:56 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


void SACEXT3_CPLEXN
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST *I, MASSTOR_LIST *M)
# else
(L, I, M)
MASSTOR_LIST L;
MASSTOR_LIST *I, *M;
# endif
{
  MASSTOR_LIST C_9_A, L1, L2, LP, TL;

  TL = 1;
  *I = MASSTOR_BETA;
  LP = L;
  do {
    SACLIST_FIRST2(LP, &L1, &L2);
    if (TL == 1) {
      MASSTOR_ADV(L1, &C_9_A, &L1);
      if (L1 != MASSTOR_SIL) {
        MASSTOR_SFIRST(LP, L1);
        TL = 0;
      } else {
        MASSTOR_SFIRST(LP, L2);
      }
    } else {
      C_9_A = MASSTOR_FIRST(L1);
    }
    *I = MASSTOR_COMP(C_9_A, *I);
    LP = SACLIST_RED2(LP);
  } while (!(LP == MASSTOR_SIL));
  *I = MASSTOR_INV(*I);
  if (TL == 0) {
    *M = L;
  } else {
    *M = MASSTOR_BETA;
  }
  return;
}

MASSTOR_LIST SACEXT3_PERMCY
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST PL, PL1, PP, PS;

  PP = MASSTOR_BETA;
  if (P == MASSTOR_SIL) {
    return PP;
  }
  MASSTOR_ADV(P, &PL1, &PS);
  while (PS != MASSTOR_SIL) {
    MASSTOR_ADV(PS, &PL, &PS);
    PP = MASSTOR_COMP(PL, PP);
  }
  PP = MASSTOR_COMP(PL1, PP);
  PP = MASSTOR_INV(PP);
  return PP;
}

void BEGIN_SACEXT3()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();

  }
}
