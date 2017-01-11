#include "SYSTEM_.h"

#ifndef DEFINITION_System
#include "System.h"
#endif

#ifndef DEFINITION_Strings
#include "Strings.h"
#endif

#ifndef DEFINITION_MASmtc
#include "MASmtc.h"
#endif

struct MASmtc_1 MASmtc_EditPrg, MASmtc_EditPrm;
CHAR MASmtc_rcsid [] = "$Id: MASmtc.md,v 1.2 1992/02/12 17:31:58 pesch Exp $";
CHAR MASmtc_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASmtc.mip,v 1.1 1995/03/06 16:48:45 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
#define stackoff	0
static CARDINAL parmpos;
static INTEGER toc;
static CARDINAL ArgCount;
static void parameter ARGS(());
struct S_4 {
    CHAR A[250 + 1];
};


ADDRESS MASmtc_getstck
# ifdef __STDC__
()
# else
()
# endif
{
  INTEGER stck;
  ADDRESS a;

  stck = 0;
  a = (ADDRESS)(ADR(stck) + stackoff);
  stck = 1;
  return a;
}

ADDRESS MASmtc_gettoc
# ifdef __STDC__
()
# else
()
# endif
{
  ADDRESS a;

  toc = 0;
  a = ADR(toc);
  toc = 1;
  return a;
}

static void parameter
# ifdef __STDC__
()
# else
()
# endif
{
  ArgCount = GetArgCount();
  parmpos = 0;
}

BOOLEAN MASmtc_NextParm
# ifdef __STDC__
(CHAR s[], LONGCARD O_1)
# else
(s, O_1)
CHAR s[];
LONGCARD O_1;
# endif
{
  if (parmpos < ArgCount - 1) {
    parmpos = parmpos + 1;
    GetArgument(parmpos, s, O_1);
    return TRUE;
  }
  return FALSE;
}

INTEGER MASmtc_DOS
# ifdef __STDC__
(CHAR s[], LONGCARD O_2)
# else
(s, O_2)
CHAR s[];
LONGCARD O_2;
# endif
{
  INTEGER i;
  OPEN_ARRAY_LOCALS

  ALLOC_OPEN_ARRAYS(O_2 * sizeof(CHAR), 1)
  COPY_OPEN_ARRAY(s, O_2, CHAR)
  i = System(s, O_2);
  FREE_OPEN_ARRAYS
  return i;
}

INTEGER MASmtc_EDIT
# ifdef __STDC__
(CHAR s[], LONGCARD O_3)
# else
(s, O_3)
CHAR s[];
LONGCARD O_3;
# endif
{
  Strings_tString ep, sp;
  struct S_4 e;
  INTEGER i;
  OPEN_ARRAY_LOCALS

  ALLOC_OPEN_ARRAYS(O_3 * sizeof(CHAR), 1)
  COPY_OPEN_ARRAY(s, O_3, CHAR)
  Strings_ArrayToString(MASmtc_EditPrg.A, 81L, &ep);
  Strings_ArrayToString(MASmtc_EditPrm.A, 81L, &sp);
  Strings_Concatenate(&ep, &sp);
  Strings_ArrayToString(s, O_3, &sp);
  Strings_Concatenate(&ep, &sp);
  Strings_StringToArray(&ep, e.A, 251L);
  i = System(e.A, 251L);
  FREE_OPEN_ARRAYS
  return i;
}

void BEGIN_MASmtc()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_System();
    BEGIN_Strings();

    parameter();
    (void)strncpy(MASmtc_EditPrg.A, "/public/gnu/bin/emacs", sizeof(MASmtc_EditPrg.A));
    (void)strncpy(MASmtc_EditPrm.A, "  ", sizeof(MASmtc_EditPrm.A));
  }
}
