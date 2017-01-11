#include "SYSTEM_.h"

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_LISTTOOLS
#include "LISTTOOLS.h"
#endif

CHAR LISTTOOLS_rcsid [] = "$Id: LISTTOOLS.md,v 1.1 1994/11/28 20:32:48 dolzmann Exp $";
CHAR LISTTOOLS_copyright [] = "Copyright (c) 1994 Universitaet Passau";

static CHAR rcsidi [] = "$Id: LISTTOOLS.mi,v 1.1 1994/11/28 20:32:51 dolzmann Exp $";
static CHAR copyrighti [] = "Copyright (c) 1994 Universitaet Passau";


MASSTOR_LIST LISTTOOLS_CLISTFA
# ifdef __STDC__
(MASSTOR_LIST atom)
# else
(atom)
MASSTOR_LIST atom;
# endif
{
  MASSTOR_LIST result;
  BOOLEAN minus;

  result = MASSTOR_SIL;
  if (atom < 0) {
    minus = TRUE;
    atom = -atom;
  } else {
    minus = FALSE;
  }
  do {
    result = MASSTOR_COMP(atom % 10, result);
    atom = atom / 10;
  } while (!(atom == 0));
  if (minus) {
    result = MASSTOR_COMP(MASBIOS_MASORD('-'), result);
  }
  return result;
}

MASSTOR_LIST LISTTOOLS_LIST6
# ifdef __STDC__
(MASSTOR_LIST a1, MASSTOR_LIST a2, MASSTOR_LIST a3, MASSTOR_LIST a4, MASSTOR_LIST a5, MASSTOR_LIST a6)
# else
(a1, a2, a3, a4, a5, a6)
MASSTOR_LIST a1, a2, a3, a4, a5, a6;
# endif
{
  return MASSTOR_COMP(a1, SACLIST_LIST5(a2, a3, a4, a5, a6));
}

MASSTOR_LIST LISTTOOLS_LPAIRS
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST result, pointer, first, second;

  result = MASSTOR_SIL;
  while (L != MASSTOR_SIL) {
    MASSTOR_ADV(L, &first, &L);
    pointer = L;
    while (pointer != MASSTOR_SIL) {
      MASSTOR_ADV(pointer, &second, &pointer);
      result = MASSTOR_COMP(SACLIST_LIST2(first, second), result);
    }
  }
  return result;
}

MASSTOR_LIST LISTTOOLS_LSRCHQ
# ifdef __STDC__
(MASSTOR_LIST a, MASSTOR_LIST L)
# else
(a, L)
MASSTOR_LIST a, L;
# endif
{
  MASSTOR_LIST b, i;

  i = 0;
  while (L != MASSTOR_SIL) {
    i = i + 1;
    MASSTOR_ADV(L, &b, &L);
    if (SACLIST_EQUAL(a, b) == 1) {
      return i;
    }
  }
  return 0;
}

MASSTOR_LIST LISTTOOLS_UPCASE
# ifdef __STDC__
(MASSTOR_LIST clist)
# else
(clist)
MASSTOR_LIST clist;
# endif
{
  MASELEM_GAMMAINT c;
  MASSTOR_LIST result;

  result = MASSTOR_SIL;
  while (clist != MASSTOR_SIL) {
    MASSTOR_ADV(clist, &c, &clist);
    if (MASBIOS_LETTER(c) && MASELEM_MASEVEN(c)) {
      result = MASSTOR_COMP(c + 1, result);
    } else {
      result = MASSTOR_COMP(c, result);
    }
  }
  return MASSTOR_INV(result);
}

void BEGIN_LISTTOOLS()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASBIOS();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();

  }
}
