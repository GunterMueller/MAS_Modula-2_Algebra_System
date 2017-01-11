#include "SYSTEM_.h"

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_MASmtc
#include "MASmtc.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_MASBIOSU
#include "MASBIOSU.h"
#endif

CHAR MASBIOSU_rcsid [] = "$Id: MASBIOSU.md,v 1.2 1992/02/12 17:31:51 pesch Exp $";
CHAR MASBIOSU_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASBIOSU.mi,v 1.3 1992/10/15 16:24:56 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
struct S_1 {
    CHAR A[80 + 1];
};
struct S_2 {
    CHAR A[80 + 1];
};
struct S_3 {
    CHAR A[80 + 1];
};
struct S_4 {
    CHAR A[80 + 1];
};
struct S_5 {
    CHAR A[80 + 1];
};


MASSTOR_LIST MASBIOSU_INP
# ifdef __STDC__
(MASSTOR_LIST C_21_A)
# else
(C_21_A)
MASSTOR_LIST C_21_A;
# endif
{
  struct S_1 S;

  MASBIOS_SLIST(C_21_A, S.A, 81L);
  return MASBIOS_SIUNIT(S.A, 81L);
}

MASSTOR_LIST MASBIOSU_OUT
# ifdef __STDC__
(MASSTOR_LIST C_20_A)
# else
(C_20_A)
MASSTOR_LIST C_20_A;
# endif
{
  struct S_2 S;

  MASBIOS_SLIST(C_20_A, S.A, 81L);
  return MASBIOS_SOUNIT(S.A, 81L);
}

MASSTOR_LIST MASBIOSU_SHUT
# ifdef __STDC__
(MASSTOR_LIST C_19_A)
# else
(C_19_A)
MASSTOR_LIST C_19_A;
# endif
{
  struct S_3 S;

  MASBIOS_SLIST(C_19_A, S.A, 81L);
  return MASBIOS_CUNIT(S.A, 81L);
}

MASSTOR_LIST MASBIOSU_EDIT
# ifdef __STDC__
(MASSTOR_LIST C_18_A)
# else
(C_18_A)
MASSTOR_LIST C_18_A;
# endif
{
  struct S_4 S;
  MASELEM_GAMMAINT i;

  MASBIOS_SLIST(C_18_A, S.A, 81L);
  i = (MASELEM_GAMMAINT)MASmtc_EDIT(S.A, 81L);
  return i;
}

MASSTOR_LIST MASBIOSU_DOS
# ifdef __STDC__
(MASSTOR_LIST C_17_A)
# else
(C_17_A)
MASSTOR_LIST C_17_A;
# endif
{
  struct S_5 S;
  MASELEM_GAMMAINT i;
  MASSTOR_LIST B;

  B = MASBIOS_LISTS(" ", 1L);
  B = SACLIST_CCONC(C_17_A, B);
  MASBIOS_SLIST(B, S.A, 81L);
  i = (MASELEM_GAMMAINT)MASmtc_DOS(S.A, 81L);
  return i;
}

void MASBIOSU_CLTIS
# ifdef __STDC__
(MASSTOR_LIST C_16_A)
# else
(C_16_A)
MASSTOR_LIST C_16_A;
# endif
{
  MASSTOR_LIST AP, k, b;

  k = MASBIOS_CUNIT("RAM:internal", 12L);
  k = MASBIOS_SOUNIT("RAM:internal", 12L);
  AP = C_16_A;
  while (AP != MASSTOR_SIL) {
    MASSTOR_ADV(AP, &b, &AP);
    MASBIOS_CWRITE(b);
  }
  k = MASBIOS_CUNIT("RAM:internal", 12L);
  k = MASBIOS_SIUNIT("RAM:internal", 12L);
}

void BEGIN_MASBIOSU()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_MASBIOS();
    BEGIN_MASmtc();
    BEGIN_SACLIST();

  }
}
