#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_MASSYM
#include "MASSYM.h"
#endif

#ifndef DEFINITION_MASSET
#include "MASSET.h"
#endif

CHAR MASSET_rcsid [] = "$Id: MASSET.md,v 1.2 1995/12/16 15:03:27 kredel Exp $";
CHAR MASSET_copyright [] = "Copyright (c) 1994 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASSET.mi,v 1.1 1994/11/28 20:39:36 dolzmann Exp $";
static CHAR copyrighti [] = "Copyright (c) 1994 Universitaet Passau";


MASSTOR_LIST MASSET_SetAdd
# ifdef __STDC__
(MASSTOR_LIST e, MASSTOR_LIST S)
# else
(e, S)
MASSTOR_LIST e, S;
# endif
{
  if (MASSYM_MEMQ(e, S)) {
    return S;
  } else {
    return MASSTOR_COMP(e, S);
  }
}

MASSTOR_LIST MASSET_SetAddQ
# ifdef __STDC__
(MASSTOR_LIST e, MASSTOR_LIST S)
# else
(e, S)
MASSTOR_LIST e, S;
# endif
{
  if (SACLIST_MEMBER(e, S) == 1) {
    return S;
  } else {
    return MASSTOR_COMP(e, S);
  }
}

MASSTOR_LIST MASSET_SetUnion
# ifdef __STDC__
(MASSTOR_LIST S1, MASSTOR_LIST S2)
# else
(S1, S2)
MASSTOR_LIST S1, S2;
# endif
{
  MASSTOR_LIST elem;

  while (S2 != MASSTOR_SIL) {
    MASSTOR_ADV(S2, &elem, &S2);
    S1 = MASSET_SetAdd(elem, S1);
  }
  return S1;
}

MASSTOR_LIST MASSET_SetUnionQ
# ifdef __STDC__
(MASSTOR_LIST S1, MASSTOR_LIST S2)
# else
(S1, S2)
MASSTOR_LIST S1, S2;
# endif
{
  MASSTOR_LIST elem;

  while (S2 != MASSTOR_SIL) {
    MASSTOR_ADV(S2, &elem, &S2);
    S1 = MASSET_SetAddQ(elem, S1);
  }
  return S1;
}

BOOLEAN MASSET_SetElementP
# ifdef __STDC__
(MASSTOR_LIST e, MASSTOR_LIST S)
# else
(e, S)
MASSTOR_LIST e, S;
# endif
{
  return MASSYM_MEMQ(e, S);
}

BOOLEAN MASSET_SetElementPQ
# ifdef __STDC__
(MASSTOR_LIST e, MASSTOR_LIST S)
# else
(e, S)
MASSTOR_LIST e, S;
# endif
{
  return SACLIST_MEMBER(e, S) == 1;
}

MASSTOR_LIST MASSET_SetMinus
# ifdef __STDC__
(MASSTOR_LIST e, MASSTOR_LIST S)
# else
(e, S)
MASSTOR_LIST e, S;
# endif
{
  MASSTOR_LIST last, elem, SP, SPP;

  if (MASSTOR_FIRST(S) == e) {
    return MASSTOR_RED(S);
  }
  last = S;
  SP = S;
  while (SP != MASSTOR_SIL) {
    MASSTOR_ADV(SP, &elem, &SPP);
    if (elem == e) {
      MASSTOR_SRED(last, SPP);
      return S;
    }
    last = SP;
    SP = SPP;
  }
  return S;
}

MASSTOR_LIST MASSET_SetMinusQ
# ifdef __STDC__
(MASSTOR_LIST e, MASSTOR_LIST S)
# else
(e, S)
MASSTOR_LIST e, S;
# endif
{
  MASSTOR_LIST last, elem, SP, SPP;

  if (SACLIST_EQUAL(MASSTOR_FIRST(S), e) == 1) {
    return MASSTOR_RED(S);
  }
  last = S;
  SP = S;
  while (SP != MASSTOR_SIL) {
    MASSTOR_ADV(SP, &elem, &SPP);
    if (SACLIST_EQUAL(elem, e) == 1) {
      MASSTOR_SRED(last, SPP);
      return S;
    }
    last = SP;
    SP = SPP;
  }
  return S;
}

MASSTOR_LIST MASSET_SetMinusC
# ifdef __STDC__
(MASSTOR_LIST e, MASSTOR_LIST S)
# else
(e, S)
MASSTOR_LIST e, S;
# endif
{
  MASSTOR_LIST result, elem;

  while (S != MASSTOR_SIL) {
    MASSTOR_ADV(S, &elem, &S);
    if (elem != e) {
      result = MASSTOR_COMP(elem, result);
    }
  }
  return MASSTOR_INV(result);
}

MASSTOR_LIST MASSET_SetMinusCQ
# ifdef __STDC__
(MASSTOR_LIST e, MASSTOR_LIST S)
# else
(e, S)
MASSTOR_LIST e, S;
# endif
{
  MASSTOR_LIST result, elem;

  while (S != MASSTOR_SIL) {
    MASSTOR_ADV(S, &elem, &S);
    if (SACLIST_MEMBER(elem, e) == 0) {
      result = MASSTOR_COMP(elem, result);
    }
  }
  return MASSTOR_INV(result);
}

MASSTOR_LIST MASSET_SetComplement
# ifdef __STDC__
(MASSTOR_LIST S1, MASSTOR_LIST S2)
# else
(S1, S2)
MASSTOR_LIST S1, S2;
# endif
{
  MASSTOR_LIST e, result;

  result = MASSTOR_SIL;
  while (S2 != MASSTOR_SIL) {
    MASSTOR_ADV(S2, &e, &S2);
    if (!MASSYM_MEMQ(e, S1)) {
      result = MASSTOR_COMP(e, result);
    }
  }
  return MASSTOR_INV(result);
}

MASSTOR_LIST MASSET_SetComplementQ
# ifdef __STDC__
(MASSTOR_LIST S1, MASSTOR_LIST S2)
# else
(S1, S2)
MASSTOR_LIST S1, S2;
# endif
{
  MASSTOR_LIST e, result;

  result = MASSTOR_SIL;
  while (S2 != MASSTOR_SIL) {
    MASSTOR_ADV(S2, &e, &S2);
    if (SACLIST_MEMBER(e, S1) == 0) {
      result = MASSTOR_COMP(e, result);
    }
  }
  return MASSTOR_INV(result);
}

void BEGIN_MASSET()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_MASBIOS();
    BEGIN_SACLIST();
    BEGIN_MASSYM();

  }
}
