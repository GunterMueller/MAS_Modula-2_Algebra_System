#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACEXT4
#include "SACEXT4.h"
#endif

#ifndef DEFINITION_SACIPOL
#include "SACIPOL.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SACPGCD
#include "SACPGCD.h"
#endif

#ifndef DEFINITION_MASPGCD
#include "MASPGCD.h"
#endif

CHAR MASPGCD_rcsid [] = "$Id: MASPGCD.md,v 1.2 1994/06/16 13:00:58 pfeil Exp $";
CHAR MASPGCD_copyright [] = "Copyright (c) 1989 - 1994 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASPGCD.mi,v 1.2 1994/06/16 13:01:00 pfeil Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1994 Universitaet Passau";


MASSTOR_LIST MASPGCD_IPSFF
# ifdef __STDC__
(MASSTOR_LIST r, MASSTOR_LIST f)
# else
(r, f)
MASSTOR_LIST r, f;
# endif
{
  MASSTOR_LIST cf, f0, CF, CF1, F0, F, EP, e, p;

  if (r == 1) {
    return SACPGCD_IPSF(1, f);
  } else {
    SACPGCD_IPCPP(r, f, &cf, &f0);
    if (SACEXT4_PCONST(r - 1, cf) == 1) {
      CF = MASSTOR_SIL;
    } else {
      CF = MASPGCD_IPSFF(r - 1, cf);
    }
    CF1 = MASSTOR_SIL;
    while (CF != MASSTOR_SIL) {
      MASSTOR_ADV(CF, &EP, &CF);
      SACLIST_FIRST2(EP, &e, &p);
      EP = SACLIST_LIST2(e, SACLIST_LIST2(0, p));
      CF1 = MASSTOR_COMP(EP, CF1);
    }
    CF = MASSTOR_INV(CF1);
    if (SACEXT4_PCONST(r, f0) == 1) {
      F0 = MASSTOR_SIL;
    } else {
      F0 = SACPGCD_IPSF(r, f0);
    }
    F = MASPGCD_IPFLMER(r, F0, CF);
    return F;
  }
}

MASSTOR_LIST MASPGCD_IPFLMER
# ifdef __STDC__
(MASSTOR_LIST r, MASSTOR_LIST F1, MASSTOR_LIST F2)
# else
(r, F1, F2)
MASSTOR_LIST r, F1, F2;
# endif
{
  MASSTOR_LIST F, EP1, EP2, e1, e2, f1, f2, f;

  F = MASSTOR_SIL;
  for (;;) {
    if (F1 == MASSTOR_SIL) {
      while (F2 != MASSTOR_SIL) {
        MASSTOR_ADV(F2, &EP2, &F2);
        F = MASSTOR_COMP(EP2, F);
      }
      return MASSTOR_INV(F);
    }
    MASSTOR_ADV(F1, &EP1, &F1);
    SACLIST_FIRST2(EP1, &e1, &f1);
    if (F2 == MASSTOR_SIL) {
      F = MASSTOR_COMP(EP1, F);
      while (F1 != MASSTOR_SIL) {
        MASSTOR_ADV(F1, &EP1, &F1);
        F = MASSTOR_COMP(EP1, F);
      }
      return MASSTOR_INV(F);
    }
    MASSTOR_ADV(F2, &EP2, &F2);
    SACLIST_FIRST2(EP2, &e2, &f2);
    for (;;) {
      if (e1 == e2) {
        f = SACIPOL_IPPROD(r, f1, f2);
        F = MASSTOR_COMP(SACLIST_LIST2(e1, f), F);
        goto EXIT_2;
      }
      if (e1 < e2) {
        F = MASSTOR_COMP(EP1, F);
        if (F1 == MASSTOR_SIL) {
          F = MASSTOR_COMP(EP2, F);
          while (F2 != MASSTOR_SIL) {
            MASSTOR_ADV(F2, &EP2, &F2);
            F = MASSTOR_COMP(EP2, F);
          }
          return MASSTOR_INV(F);
        }
        MASSTOR_ADV(F1, &EP1, &F1);
        SACLIST_FIRST2(EP1, &e1, &f1);
      } else {
        F = MASSTOR_COMP(EP2, F);
        if (F2 == MASSTOR_SIL) {
          F = MASSTOR_COMP(EP1, F);
          while (F1 != MASSTOR_SIL) {
            MASSTOR_ADV(F1, &EP1, &F1);
            F = MASSTOR_COMP(EP1, F);
          }
          return MASSTOR_INV(F);
        }
        MASSTOR_ADV(F2, &EP2, &F2);
        SACLIST_FIRST2(EP2, &e2, &f2);
      }
    } EXIT_2:;
  } EXIT_1:;
}

void BEGIN_MASPGCD()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_SACEXT4();
    BEGIN_SACIPOL();
    BEGIN_SACLIST();
    BEGIN_SACPGCD();

  }
}
