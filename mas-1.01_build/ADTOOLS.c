#include "SYSTEM_.h"

#ifndef DEFINITION_DOMIP
#include "DOMIP.h"
#endif

#ifndef DEFINITION_DOMRF
#include "DOMRF.h"
#endif

#ifndef DEFINITION_DIPRF
#include "DIPRF.h"
#endif

#ifndef DEFINITION_DOMI
#include "DOMI.h"
#endif

#ifndef DEFINITION_MASADOM
#include "MASADOM.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_MASBIOSU
#include "MASBIOSU.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_ADTOOLS
#include "ADTOOLS.h"
#endif

CHAR ADTOOLS_rcsid [] = "$Id: ADTOOLS.md,v 1.2 1994/11/28 20:43:07 dolzmann Exp $";
CHAR ADTOOLS_copyright [] = "Copyright (c) 1989 - 1994 Universitaet Passau";



MASSTOR_LIST ADTOOLS_ADRFFADIP
# ifdef __STDC__
(MASSTOR_LIST adip)
# else
(adip)
MASSTOR_LIST adip;
# endif
{
  MASSTOR_LIST ip, r, vlist;

  SACLIST_FIRST3(adip, &ip, &r, &vlist);
  return SACLIST_LIST2(DIPRF_RFFIP(r, ip), vlist);
}

MASSTOR_LIST ADTOOLS_ADDDFSTR
# ifdef __STDC__
(CHAR s[], LONGCARD O_1)
# else
(s, O_1)
CHAR s[];
LONGCARD O_1;
# endif
{
  OPEN_ARRAY_LOCALS

  ALLOC_OPEN_ARRAYS(O_1 * sizeof(CHAR), 1)
  COPY_OPEN_ARRAY(s, O_1, CHAR)
  MASBIOSU_CLTIS(MASBIOS_LISTS(s, O_1));
  {
    LONGINT R_1 = MASADOM_ADDDREAD();

    FREE_OPEN_ARRAYS
    return R_1;
  }
}

MASSTOR_LIST ADTOOLS_ADCAST
# ifdef __STDC__
(MASSTOR_LIST e, MASSTOR_LIST dd)
# else
(e, dd)
MASSTOR_LIST e, dd;
# endif
{
  MASSTOR_LIST result, red, add;

  result = MASSTOR_LIST1(MASSTOR_FIRST(dd));
  result = MASSTOR_COMP(e, result);
  add = SACLIST_RED2(dd);
  while (add != MASSTOR_SIL) {
    MASSTOR_ADV(add, &red, &add);
    result = MASSTOR_COMP(red, result);
  }
  return MASSTOR_INV(result);
}

MASSTOR_LIST ADTOOLS_ADRMDD
# ifdef __STDC__
(MASSTOR_LIST e)
# else
(e)
MASSTOR_LIST e;
# endif
{
  return SACLIST_SECOND(e);
}

void ADTOOLS_AdLoadConvFunc
# ifdef __STDC__
()
# else
()
# endif
{
  MASADOM_SetConvFunc(DOMRF_DOMRFD, DOMIP_DOMIPD, ADTOOLS_ADRFFADIP);
}

MASSTOR_LIST ADTOOLS_RFDDFIPDD
# ifdef __STDC__
(MASSTOR_LIST ipdd)
# else
(ipdd)
MASSTOR_LIST ipdd;
# endif
{
  MASSTOR_LIST ipid, p, r, vlist;

  SACLIST_FIRST4(ipdd, &ipid, &p, &r, &vlist);
  return SACLIST_LIST3(DOMRF_DOMRFD, SACLIST_LIST2(r, 0), vlist);
}

MASSTOR_LIST ADTOOLS_IPDDCMP
# ifdef __STDC__
(MASSTOR_LIST vlist)
# else
(vlist)
MASSTOR_LIST vlist;
# endif
{
  return SACLIST_LIST4(DOMIP_DOMIPD, 0, MASSTOR_LENGTH(vlist), vlist);
}

MASSTOR_LIST ADTOOLS_IPDECMP
# ifdef __STDC__
(MASSTOR_LIST e, MASSTOR_LIST vlist)
# else
(e, vlist)
MASSTOR_LIST e, vlist;
# endif
{
  return SACLIST_LIST4(DOMIP_DOMIPD, e, MASSTOR_LENGTH(vlist), vlist);
}

MASSTOR_LIST ADTOOLS_INTDDCMP
# ifdef __STDC__
()
# else
()
# endif
{
  return SACLIST_LIST2(DOMI_DOMINT, 0);
}

void ADTOOLS_IPDDADV
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST *q, MASSTOR_LIST *r, MASSTOR_LIST *vl)
# else
(p, q, r, vl)
MASSTOR_LIST p;
MASSTOR_LIST *q, *r, *vl;
# endif
{
  MASSTOR_LIST dnr;

  SACLIST_FIRST4(p, &dnr, q, r, vl);
}

void ADTOOLS_RFDDADV
# ifdef __STDC__
(MASSTOR_LIST e, MASSTOR_LIST *rat, MASSTOR_LIST *vl)
# else
(e, rat, vl)
MASSTOR_LIST e;
MASSTOR_LIST *rat, *vl;
# endif
{
  MASSTOR_LIST dnr;

  SACLIST_FIRST3(e, &dnr, rat, vl);
  return;
}

void BEGIN_ADTOOLS()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_DOMIP();
    BEGIN_DOMRF();
    BEGIN_DIPRF();
    BEGIN_DOMI();
    BEGIN_MASADOM();
    BEGIN_MASBIOS();
    BEGIN_MASBIOSU();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();

  }
}
