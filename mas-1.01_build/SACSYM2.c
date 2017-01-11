#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASERR
#include "MASERR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SACSYM
#include "SACSYM.h"
#endif

#ifndef DEFINITION_SACSYM2
#include "SACSYM2.h"
#endif

CHAR SACSYM2_rcsid [] = "$Id: SACSYM2.md,v 1.2 1992/02/12 17:32:36 pesch Exp $";
CHAR SACSYM2_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SACSYM2.mi,v 1.3 1992/10/15 16:27:57 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
struct S_2 {
    MASSTOR_LIST A[500 + 1];
};


MASSTOR_LIST SACSYM2_STBAL
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST n)
# else
(L, n)
MASSTOR_LIST L, n;
# endif
{
  MASSTOR_LIST LP;
  INTEGER i, m;
  struct S_2 C_15_A;

  if (n > 500) {
    MASERR_ERROR(MASERR_severe, "STBAL: array to small.", 22L);
    return MASSTOR_SIL;
  }
  LP = L;
  i = -1;
  while (LP != MASSTOR_SIL) {
    i = i + 1;
    C_15_A.A[i] = MASSTOR_FIRST(LP);
    LP = MASSTOR_RED(LP);
  }
  m = SACSYM2_STBALS(C_15_A.A, 501L, 0, (INTEGER)(n - 1));
  return C_15_A.A[m];
}

INTEGER SACSYM2_STBALS
# ifdef __STDC__
(MASSTOR_LIST C_14_A[], LONGCARD O_1, INTEGER l, INTEGER r)
# else
(C_14_A, O_1, l, r)
MASSTOR_LIST C_14_A[];
LONGCARD O_1;
INTEGER l, r;
# endif
{
  INTEGER m, m1, m2;
  MASSTOR_LIST L;

  if (l == r) {
    m = l;
    MASSTOR_SFIRST(C_14_A[m], MASSTOR_SIL);
    MASSTOR_SRED(MASSTOR_RED(C_14_A[m]), MASSTOR_SIL);
    return m;
  }
  m = (l + r) / 2;
  if (l == m) {
    MASSTOR_SFIRST(C_14_A[m], MASSTOR_SIL);
  } else {
    m1 = SACSYM2_STBALS(C_14_A, O_1, l, m - 1);
    MASSTOR_SFIRST(C_14_A[m], C_14_A[m1]);
  }
  m2 = SACSYM2_STBALS(C_14_A, O_1, m + 1, r);
  MASSTOR_SRED(MASSTOR_RED(C_14_A[m]), C_14_A[m2]);
  return m;
}

void SACSYM2_STNLST
# ifdef __STDC__
(MASSTOR_LIST T, MASSTOR_LIST *L, MASSTOR_LIST *n)
# else
(T, L, n)
MASSTOR_LIST T;
MASSTOR_LIST *L, *n;
# endif
{
  MASSTOR_LIST l, r, lp, rp, S, n1, n2;

  SACLIST_ADV2(T, &l, &S, &r);
  n1 = 0;
  n2 = 0;
  lp = MASSTOR_SIL;
  rp = MASSTOR_SIL;
  if (l != MASSTOR_SIL) {
    SACSYM2_STNLST(l, &lp, &n1);
  }
  if (r != MASSTOR_SIL) {
    SACSYM2_STNLST(r, &rp, &n2);
  }
  *L = SACLIST_CONC(lp, MASSTOR_COMP(T, rp));
  *n = n1 + 1 + n2;
  return;
}

void SACSYM2_SSYTBAL
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST L, n;

  if (SACSYM_SYMTB == MASSTOR_SIL) {
    return;
  }
  SACSYM2_STNLST(SACSYM_SYMTB, &L, &n);
  L = SACSYM2_STBAL(L, n);
  if (L != MASSTOR_SIL) {
    SACSYM_SYMTB = L;
  }
  return;
}

void BEGIN_SACSYM2()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_MASERR();
    BEGIN_SACLIST();
    BEGIN_SACSYM();

  }
}
