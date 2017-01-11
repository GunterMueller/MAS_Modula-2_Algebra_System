#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_MASSYM2
#include "MASSYM2.h"
#endif

#ifndef DEFINITION_MASLISPU
#include "MASLISPU.h"
#endif

#ifndef DEFINITION_MASLISP
#include "MASLISP.h"
#endif

#ifndef DEFINITION_MASSPEC
#include "MASSPEC.h"
#endif

#ifndef DEFINITION_MASREP
#include "MASREP.h"
#endif

CHAR MASREP_rcsid [] = "$Id: MASREP.md,v 1.2 1992/02/12 17:32:28 pesch Exp $";
CHAR MASREP_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static MASSTOR_LIST WT, RP;
static CHAR rcsidi [] = "$Id: MASREP.mi,v 1.3 1992/10/15 16:27:51 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST MASREP_NewRep
# ifdef __STDC__
()
# else
()
# endif
{
  return SACLIST_LIST3(RP, MASSTOR_SIL, MASSTOR_SIL);
}

void MASREP_SetRep
# ifdef __STDC__
(MASSTOR_LIST n, MASSTOR_LIST e, MASSTOR_LIST r)
# else
(n, e, r)
MASSTOR_LIST n, e, r;
# endif
{
  MASSTOR_LIST x, y, z;

  if (MASSTOR_FIRST(r) != RP) {
    return;
  }
  z = MASSTOR_RED(r);
  x = MASSYM2_ASSOCQ(n, MASSTOR_FIRST(z));
  if (x != MASSTOR_SIL) {
    MASSTOR_SFIRST(x, e);
  } else {
    x = MASSTOR_LIST1(e);
    y = MASSTOR_COMP(n, x);
    MASSTOR_SRED(x, MASSTOR_FIRST(z));
    MASSTOR_SFIRST(z, y);
  }
}

MASSTOR_LIST MASREP_GetRep
# ifdef __STDC__
(MASSTOR_LIST n, MASSTOR_LIST r)
# else
(n, r)
MASSTOR_LIST n, r;
# endif
{
  MASSTOR_LIST e;

  if (MASSTOR_FIRST(r) != RP) {
    return MASSTOR_SIL;
  }
  e = MASSYM2_ASSOCQ(n, SACLIST_SECOND(r));
  if (e != MASSTOR_SIL) {
    e = MASSTOR_FIRST(e);
  }
  return e;
}

MASSTOR_LIST MASREP_CopyRep
# ifdef __STDC__
(MASSTOR_LIST r)
# else
(r)
MASSTOR_LIST r;
# endif
{
  MASSTOR_LIST x;

  if (MASSTOR_FIRST(r) != RP) {
    return MASREP_NewRep();
  }
  x = SACLIST_SECOND(r);
  x = MASSTOR_INV(SACLIST_CINV(x));
  x = SACLIST_LIST3(RP, x, MASSTOR_SIL);
  return x;
}

MASSTOR_LIST MASREP_StepRep
# ifdef __STDC__
(MASSTOR_LIST r)
# else
(r)
MASSTOR_LIST r;
# endif
{
  MASSTOR_LIST x, y, n, e, p;

  if (MASSTOR_FIRST(r) != RP) {
    return MASSTOR_SIL;
  }
  x = SACLIST_RED2(r);
  if (MASSTOR_FIRST(x) != MASSTOR_SIL) {
    y = MASSTOR_FIRST(x);
    y = SACLIST_RED2(y);
    MASSTOR_SFIRST(x, y);
    if (y != MASSTOR_SIL) {
      SACLIST_FIRST2(y, &n, &e);
      y = SACLIST_LIST2(n, e);
      return y;
    }
    return MASSTOR_SIL;
  }
  y = SACLIST_SECOND(r);
  if (y != MASSTOR_SIL) {
    MASSTOR_SFIRST(x, y);
    SACLIST_FIRST2(y, &n, &e);
    y = SACLIST_LIST2(n, e);
    return y;
  }
  return MASSTOR_SIL;
}

MASSTOR_LIST MASREP_ForEachinRep
# ifdef __STDC__
(MASSTOR_LIST r, MASSTOR_LIST f, MASSTOR_LIST E)
# else
(r, f, E)
MASSTOR_LIST r, f, E;
# endif
{
  MASSTOR_LIST x, y, n, e, p;

  if (MASSTOR_FIRST(r) != RP) {
    return MASSTOR_SIL;
  }
  if (E == MASSTOR_SIL) {
    E = MASLISP_ENV;
  }
  x = SACLIST_SECOND(r);
  y = MASSTOR_SIL;
  while (x != MASSTOR_SIL) {
    SACLIST_ADV2(x, &n, &e, &x);
    p = SACLIST_LIST3(f, n, e);
    p = MASSPEC_EVALUATE(p, &E);
    if (p != MASSTOR_SIL) {
      SACLIST_FIRST2(p, &n, &e);
      y = SACLIST_COMP2(e, n, y);
    }
  }
  y = MASSTOR_INV(y);
  r = SACLIST_LIST3(RP, y, MASSTOR_SIL);
  return r;
}

MASSTOR_LIST MASREP_FullRep
# ifdef __STDC__
(MASSTOR_LIST r)
# else
(r)
MASSTOR_LIST r;
# endif
{
  if (MASSTOR_FIRST(r) != RP) {
    return MASSTOR_SIL;
  }
  if (r != MASSTOR_SIL) {
    if (SACLIST_SECOND(r) != MASSTOR_SIL) {
      return WT;
    }
  }
  return MASSTOR_SIL;
}

MASSTOR_LIST MASREP_ForEachinList
# ifdef __STDC__
(MASSTOR_LIST r, MASSTOR_LIST f, MASSTOR_LIST E)
# else
(r, f, E)
MASSTOR_LIST r, f, E;
# endif
{
  MASSTOR_LIST x, y, e, p;

  if (r == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  if (E == MASSTOR_SIL) {
    E = MASLISP_ENV;
  }
  x = r;
  y = MASSTOR_SIL;
  while (x != MASSTOR_SIL) {
    MASSTOR_ADV(x, &e, &x);
    p = SACLIST_LIST2(f, e);
    p = MASSPEC_EVALUATE(p, &E);
    y = MASSTOR_COMP(p, y);
  }
  y = MASSTOR_INV(y);
  return y;
}

void BEGIN_MASREP()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_MASSYM2();
    BEGIN_MASLISPU();
    BEGIN_MASLISP();
    BEGIN_MASSPEC();

    MASLISPU_Declare(&WT, "T", 1L);
    MASLISPU_Declare(&RP, "REP", 3L);
    MASSYM2_PUT(RP, MASLISPU_EXTYP, MASLISP_FEXPR);
  }
}
