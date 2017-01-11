#include "SYSTEM_.h"

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

CHAR MASELEM_rcsid [] = "$Id: MASELEM.md,v 1.2 1992/02/12 17:31:54 pesch Exp $";
CHAR MASELEM_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASELEM.mi,v 1.3 1992/10/15 16:24:57 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASELEM_GAMMAINT MASELEM_MASABS
# ifdef __STDC__
(MASELEM_GAMMAINT a)
# else
(a)
MASELEM_GAMMAINT a;
# endif
{
  MASELEM_GAMMAINT b;

  if (a >= 0) {
    b = a;
  } else {
    b = -a;
  }
  return b;
}

BOOLEAN MASELEM_MASEVEN
# ifdef __STDC__
(MASELEM_GAMMAINT a)
# else
(a)
MASELEM_GAMMAINT a;
# endif
{
  BOOLEAN t;

  t = TRUE;
  if (a % 2 != 0) {
    t = FALSE;
  }
  return t;
}

MASELEM_GAMMAINT MASELEM_MASEXP
# ifdef __STDC__
(MASELEM_GAMMAINT a, MASELEM_GAMMAINT b)
# else
(a, b)
MASELEM_GAMMAINT a, b;
# endif
{
  MASELEM_GAMMAINT CL, IL;

  CL = 1;
  {
    LONGINT B_1 = 1, B_2 = b;

    if (B_1 <= B_2)
      for (IL = B_1;; IL += 1) {
        CL = a * CL;
        if (IL >= B_2) break;
      }
  }
  return CL;
}

MASELEM_GAMMAINT MASELEM_MASMAX
# ifdef __STDC__
(MASELEM_GAMMAINT a, MASELEM_GAMMAINT b)
# else
(a, b)
MASELEM_GAMMAINT a, b;
# endif
{
  MASELEM_GAMMAINT c;

  if (a >= b) {
    c = a;
  } else {
    c = b;
  }
  return c;
}

MASELEM_GAMMAINT MASELEM_MASMIN
# ifdef __STDC__
(MASELEM_GAMMAINT a, MASELEM_GAMMAINT b)
# else
(a, b)
MASELEM_GAMMAINT a, b;
# endif
{
  MASELEM_GAMMAINT c;

  if (a <= b) {
    c = a;
  } else {
    c = b;
  }
  return c;
}

BOOLEAN MASELEM_MASODD
# ifdef __STDC__
(MASELEM_GAMMAINT a)
# else
(a)
MASELEM_GAMMAINT a;
# endif
{
  BOOLEAN t;

  t = FALSE;
  if (a % 2 != 0) {
    t = TRUE;
  }
  return t;
}

void MASELEM_MASQREM
# ifdef __STDC__
(MASELEM_GAMMAINT a, MASELEM_GAMMAINT b, MASELEM_GAMMAINT *q, MASELEM_GAMMAINT *r)
# else
(a, b, q, r)
MASELEM_GAMMAINT a, b;
MASELEM_GAMMAINT *q, *r;
# endif
{
  *q = a / b;
  *r = a - b * *q;
  return;
}

MASELEM_GAMMAINT MASELEM_MASREM
# ifdef __STDC__
(MASELEM_GAMMAINT a, MASELEM_GAMMAINT b)
# else
(a, b)
MASELEM_GAMMAINT a, b;
# endif
{
  MASELEM_GAMMAINT q, r;

  q = a / b;
  r = a - b * q;
  return r;
}

MASELEM_GAMMAINT MASELEM_MASSIGN
# ifdef __STDC__
(MASELEM_GAMMAINT a)
# else
(a)
MASELEM_GAMMAINT a;
# endif
{
  MASELEM_GAMMAINT s;

  if (a > 0) {
    s = 1;
  } else {
    if (a < 0) {
      s = -1;
    } else {
      s = 0;
    }
  }
  return s;
}

void BEGIN_MASELEM()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;


  }
}
