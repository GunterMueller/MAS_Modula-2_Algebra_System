#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_LISTTOOLS
#include "LISTTOOLS.h"
#endif

#ifndef DEFINITION_MASCOMB
#include "MASCOMB.h"
#endif

CHAR MASCOMB_rcsid [] = "$Id: MASCOMB.md,v 1.1 1994/11/28 20:39:33 dolzmann Exp $";
CHAR MASCOMB_copyright [] = "Copyright (c) 1994 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASCOMB.mi,v 1.1 1994/11/28 20:39:34 dolzmann Exp $";
static CHAR copyrighti [] = "Copyright (c) 1994 Universitaet Passau";


MASSTOR_LIST MASCOMB_INVPERM
# ifdef __STDC__
(MASSTOR_LIST perm)
# else
(perm)
MASSTOR_LIST perm;
# endif
{
  MASSTOR_LIST L, pos;
  INTEGER i, n;

  n = MASSTOR_LENGTH(perm);
  L = MASSTOR_SIL;
  {
    LONGINT B_1 = 1, B_2 = n;

    if (B_1 <= B_2)
      for (i = B_1;; i += 1) {
        L = MASSTOR_COMP(0, L);
        if (i >= B_2) break;
      }
  }
  {
    LONGINT B_3 = 1, B_4 = n;

    if (B_3 <= B_4)
      for (i = B_3;; i += 1) {
        MASSTOR_ADV(perm, &pos, &perm);
        SACLIST_SLELT(L, pos, i);
        if (i >= B_4) break;
      }
  }
  return L;
}

MASSTOR_LIST MASCOMB_PVFLISTS
# ifdef __STDC__
(MASSTOR_LIST list1, MASSTOR_LIST list2)
# else
(list1, list2)
MASSTOR_LIST list1, list2;
# endif
{
  MASSTOR_LIST a, P;

  P = MASSTOR_SIL;
  while (list2 != MASSTOR_SIL) {
    MASSTOR_ADV(list2, &a, &list2);
    P = MASSTOR_COMP(LISTTOOLS_LSRCHQ(a, list1), P);
  }
  return MASSTOR_INV(P);
}

void BEGIN_MASCOMB()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_LISTTOOLS();

  }
}
