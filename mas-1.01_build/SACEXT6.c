#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SACEXT5
#include "SACEXT5.h"
#endif

#ifndef DEFINITION_SACPFAC
#include "SACPFAC.h"
#endif

#ifndef DEFINITION_SACEXT6
#include "SACEXT6.h"
#endif

CHAR SACEXT6_rcsid [] = "$Id: SACEXT6.md,v 1.2 1992/02/12 17:34:52 pesch Exp $";
CHAR SACEXT6_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SACEXT6.mi,v 1.3 1992/10/15 16:28:58 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST SACEXT6_IPFSFB
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_26_A)
# else
(RL, C_26_A)
MASSTOR_LIST RL, C_26_A;
# endif
{
  MASSTOR_LIST B, B1, BP, BS, L;

  BS = SACEXT5_IPCSFB(RL, C_26_A);
  B = MASSTOR_BETA;
  while (BS != MASSTOR_SIL) {
    MASSTOR_ADV(BS, &B1, &BS);
    L = SACPFAC_ISFPF(RL, B1);
    BP = SACLIST_CONC(L, B);
    B = BP;
  }
  return B;
}

void BEGIN_SACEXT6()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_SACEXT5();
    BEGIN_SACPFAC();

  }
}
