#include "SYSTEM_.h"

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#ifndef DEFINITION_MASERR
#include "MASERR.h"
#endif

#ifndef DEFINITION_MASLISP
#include "MASLISP.h"
#endif

#ifndef DEFINITION_MASLISPU
#include "MASLISPU.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASSYM2
#include "MASSYM2.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_MODVAR
#include "MODVAR.h"
#endif

CHAR MODVAR_rcsid [] = "$Id: MODVAR.md,v 1.2 1995/12/16 14:46:01 kredel Exp $";
CHAR MODVAR_copyright [] = "Copyright (c) 1993 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MODVAR.mi,v 1.1 1994/11/28 21:01:28 dolzmann Exp $";
static CHAR copyrighti [] = "Copyright (c) 1994 Universitaet Passau";
static MASSTOR_LIST MGV, CMT, SORT, BOOL, LST, ACCESS, RO, RW;


void MODVAR_MVDeclareL
# ifdef __STDC__
(MASSTOR_LIST *var, CHAR name[], LONGCARD O_2, CHAR comment[], LONGCARD O_1, BOOLEAN access)
# else
(var, name, O_2, comment, O_1, access)
MASSTOR_LIST *var;
CHAR name[];
LONGCARD O_2;
CHAR comment[];
LONGCARD O_1;
BOOLEAN access;
# endif
{
  MASSTOR_LIST sym;
  OPEN_ARRAY_LOCALS

  ALLOC_OPEN_ARRAYS(O_1 * sizeof(CHAR) + O_2 * sizeof(CHAR), 2)
  COPY_OPEN_ARRAY(comment, O_1, CHAR)
  COPY_OPEN_ARRAY(name, O_2, CHAR)
  MASLISPU_Declare(&sym, name, O_2);
  MASSYM2_PUT(sym, MGV, SACLIST_LIST2(MASSYM2_NOSHOW, (MASELEM_GAMMAINT)ADR(*var)));
  MASSYM2_PUT(sym, CMT, SACLIST_LIST2(MASSYM2_NOSHOW, MASBIOS_LISTS(comment, O_1)));
  if (access) {
    MASSYM2_PUT(sym, ACCESS, RW);
  } else {
    MASSYM2_PUT(sym, ACCESS, RO);
  }
  MASSYM2_PUT(sym, SORT, LST);
  FREE_OPEN_ARRAYS
}

void MODVAR_MVDeclareB
# ifdef __STDC__
(BOOLEAN *var, CHAR name[], LONGCARD O_4, CHAR comment[], LONGCARD O_3, BOOLEAN access)
# else
(var, name, O_4, comment, O_3, access)
BOOLEAN *var;
CHAR name[];
LONGCARD O_4;
CHAR comment[];
LONGCARD O_3;
BOOLEAN access;
# endif
{
  MASSTOR_LIST sym;
  OPEN_ARRAY_LOCALS

  ALLOC_OPEN_ARRAYS(O_3 * sizeof(CHAR) + O_4 * sizeof(CHAR), 2)
  COPY_OPEN_ARRAY(comment, O_3, CHAR)
  COPY_OPEN_ARRAY(name, O_4, CHAR)
  MASLISPU_Declare(&sym, name, O_4);
  MASSYM2_PUT(sym, MGV, SACLIST_LIST2(MASSYM2_NOSHOW, (MASELEM_GAMMAINT)ADR(*var)));
  MASSYM2_PUT(sym, CMT, SACLIST_LIST2(MASSYM2_NOSHOW, MASBIOS_LISTS(comment, O_3)));
  if (access) {
    MASSYM2_PUT(sym, ACCESS, RW);
  } else {
    MASSYM2_PUT(sym, ACCESS, RO);
  }
  MASSYM2_PUT(sym, SORT, BOOL);
  FREE_OPEN_ARRAYS
}

void MODVAR_MVSET
# ifdef __STDC__
(MASSTOR_LIST sym, MASSTOR_LIST value)
# else
(sym, value)
MASSTOR_LIST sym, value;
# endif
{
  MASSTOR_LIST *varp;
  MASSTOR_LIST varl;
  MASSTOR_LIST acc, srt;

  varl = MASSYM2_GET(sym, MGV);
  if (varl == MASSTOR_SIL) {
    MASERR_ERROR(MASERR_harmless, "MVSET: unbound modula variable", 30L);
    return;
  }
  acc = MASSYM2_GET(sym, ACCESS);
  if (acc == RO) {
    MASERR_ERROR(MASERR_harmless, "MVSET: variable is read only", 28L);
    return;
  }
  srt = MASSYM2_GET(sym, SORT);
  if (srt != LST) {
    MASERR_ERROR(MASERR_harmless, "MVSET: MVSET is possible only for list variables.", 49L);
    return;
  }
  varp = (LONGINT *)(ADDRESS)SACLIST_SECOND(varl);
  *varp = value;
}

MASSTOR_LIST MODVAR_MVGET
# ifdef __STDC__
(MASSTOR_LIST sym)
# else
(sym)
MASSTOR_LIST sym;
# endif
{
  MASSTOR_LIST *varp;
  MASSTOR_LIST varl;
  MASSTOR_LIST srt;

  varl = MASSYM2_GET(sym, MGV);
  if (varl == MASSTOR_SIL) {
    MASERR_ERROR(MASERR_harmless, "MVGET: unbound modula variable", 30L);
    return MASSTOR_SIL;
  }
  srt = MASSYM2_GET(sym, SORT);
  if (srt != LST) {
    MASERR_ERROR(MASERR_harmless, "MVGET: MVGET is possible only for list variables.", 49L);
    return MASSTOR_SIL;
  }
  varp = (LONGINT *)(ADDRESS)SACLIST_SECOND(varl);
  return *varp;
}

MASSTOR_LIST MODVAR_MVFLAG
# ifdef __STDC__
(MASSTOR_LIST sym)
# else
(sym)
MASSTOR_LIST sym;
# endif
{
  BOOLEAN *varp;
  MASSTOR_LIST varl;
  MASSTOR_LIST srt;

  varl = MASSYM2_GET(sym, MGV);
  if (varl == MASSTOR_SIL) {
    MASERR_ERROR(MASERR_harmless, "MVGET: unbound modula variable", 30L);
    return 0;
  }
  srt = MASSYM2_GET(sym, SORT);
  if (srt != BOOL) {
    MASERR_ERROR(MASERR_harmless, "MVFLAG: MVFLAG is possible only for boolean variables.", 54L);
    return 0;
  }
  varp = (BOOLEAN *)(ADDRESS)SACLIST_SECOND(varl);
  if (*varp) {
    return 1;
  } else {
    return 0;
  }
}

void MODVAR_MVON
# ifdef __STDC__
(MASSTOR_LIST sym)
# else
(sym)
MASSTOR_LIST sym;
# endif
{
  BOOLEAN *varp;
  MASSTOR_LIST varl;
  MASSTOR_LIST acc, srt;

  varl = MASSYM2_GET(sym, MGV);
  if (varl == MASSTOR_SIL) {
    MASERR_ERROR(MASERR_harmless, "MVON: unbound modula variable", 29L);
    return;
  }
  acc = MASSYM2_GET(sym, ACCESS);
  if (acc == RO) {
    MASERR_ERROR(MASERR_harmless, "MVON: variable is read only", 27L);
    return;
  }
  srt = MASSYM2_GET(sym, SORT);
  if (srt != BOOL) {
    MASERR_ERROR(MASERR_harmless, "MVON: MVON is only for boolean variables possible.", 50L);
    return;
  }
  varp = (BOOLEAN *)(ADDRESS)SACLIST_SECOND(varl);
  *varp = TRUE;
}

void MODVAR_MVOFF
# ifdef __STDC__
(MASSTOR_LIST sym)
# else
(sym)
MASSTOR_LIST sym;
# endif
{
  BOOLEAN *varp;
  MASSTOR_LIST varl;
  MASSTOR_LIST acc, srt;

  varl = MASSYM2_GET(sym, MGV);
  if (varl == MASSTOR_SIL) {
    MASERR_ERROR(MASERR_harmless, "MVOFF: unbound modula variable", 30L);
    return;
  }
  acc = MASSYM2_GET(sym, ACCESS);
  if (acc == RO) {
    MASERR_ERROR(MASERR_harmless, "MVOFF: variable is read only", 28L);
    return;
  }
  srt = MASSYM2_GET(sym, SORT);
  if (srt != BOOL) {
    MASERR_ERROR(MASERR_harmless, "MVOFF: MVOFF is possible only for boolean variables.", 52L);
    return;
  }
  varp = (BOOLEAN *)(ADDRESS)SACLIST_SECOND(varl);
  *varp = FALSE;
}

void MODVAR_MVHLP
# ifdef __STDC__
(MASSTOR_LIST sym)
# else
(sym)
MASSTOR_LIST sym;
# endif
{
  MASSTOR_LIST *varpl;
  BOOLEAN *varpb;
  MASSTOR_LIST varl;
  MASSTOR_LIST acc, srt, cmt;

  MASBIOS_BLINES(0);
  varl = MASSYM2_GET(sym, MGV);
  if (varl == MASSTOR_SIL) {
    MASSYM2_UWRIT1(sym);
    MASBIOS_SWRITE(" is not a modula variable. ", 27L);
    MASBIOS_BLINES(0);
    return;
  }
  MASBIOS_SWRITE("Modula variable: ", 17L);
  MASSYM2_UWRITE(sym);
  acc = MASSYM2_GET(sym, ACCESS);
  if (acc == RO) {
    MASBIOS_SWRITE("  is a read-only variable", 25L);
  } else {
    MASBIOS_SWRITE("  is a read-write variable", 26L);
  }
  srt = MASSYM2_GET(sym, SORT);
  if (srt == BOOL) {
    MASBIOS_SWRITE(" of the type BOOLEAN.", 21L);
  } else {
    MASBIOS_SWRITE(" of the type LIST.", 18L);
  }
  MASBIOS_BLINES(0);
  cmt = SACLIST_SECOND(MASSYM2_GET(sym, CMT));
  MASBIOS_SWRITE("  Documentation:", 16L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("    ", 4L);
  SACLIST_CLOUT(cmt);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("  Current value: ", 17L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("    ", 4L);
  if (srt == BOOL) {
    varpb = (BOOLEAN *)(ADDRESS)SACLIST_SECOND(varl);
    if (*varpb) {
      MASBIOS_SWRITE("TRUE", 4L);
    } else {
      MASBIOS_SWRITE("FALSE", 5L);
    }
  } else {
    varpl = (LONGINT *)(ADDRESS)SACLIST_SECOND(varl);
    MASSYM2_UWRIT1(*varpl);
  }
  MASBIOS_BLINES(0);
}

void BEGIN_MODVAR()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASBIOS();
    BEGIN_MASELEM();
    BEGIN_MASERR();
    BEGIN_MASLISP();
    BEGIN_MASLISPU();
    BEGIN_MASSTOR();
    BEGIN_MASSYM2();
    BEGIN_SACLIST();

    MASLISPU_Declare(&MGV, "MGV", 3L);
    MASLISPU_Declare(&CMT, "Comment", 7L);
    MASLISPU_Declare(&SORT, "TYPE", 4L);
    MASLISPU_Declare(&BOOL, "BOOLEAN", 7L);
    MASLISPU_Declare(&LST, "LIST", 4L);
    MASLISPU_Declare(&RW, "ReadWrite", 9L);
    MASLISPU_Declare(&RO, "ReadOnly", 8L);
    MASLISPU_Declare(&ACCESS, "Access", 6L);
  }
}
