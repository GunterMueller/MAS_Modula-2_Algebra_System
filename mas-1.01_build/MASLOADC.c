#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASLISPU
#include "MASLISPU.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPI
#include "DIPI.h"
#endif

#ifndef DEFINITION_DIPRN
#include "DIPRN.h"
#endif

#ifndef DEFINITION_MASNC
#include "MASNC.h"
#endif

#ifndef DEFINITION_MASNCGB
#include "MASNCGB.h"
#endif

#ifndef DEFINITION_MASNCC
#include "MASNCC.h"
#endif

#ifndef DEFINITION_MASLOADC
#include "MASLOADC.h"
#endif

CHAR MASLOADC_rcsid [] = "$Id: MASLOADC.md,v 1.1 1992/01/22 15:11:49 kredel Exp $";
CHAR MASLOADC_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASLOADC.mi,v 1.3 1992/10/15 16:30:34 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
static MASSTOR_LIST ndread ARGS(());
static MASSTOR_LIST npread ARGS((MASSTOR_LIST T));
static MASSTOR_LIST npreadd ARGS((MASSTOR_LIST X));
static MASSTOR_LIST pdread ARGS(());


void MASLOADC_InitExternalsC
# ifdef __STDC__
()
# else
()
# endif
{
  MASLISPU_Compiledf1(npread, "NPREAD", 6L);
  MASLISPU_Compiledf0(ndread, "NDREAD", 6L);
  MASLISPU_Compiledf1(npreadd, "NPREADD", 7L);
  MASLISPU_Compiledf2(MASNC_DINLRD, "DINLRD", 6L);
  MASLISPU_Compiledf3(MASNC_DINPPR, "NPPROD", 6L);
  MASLISPU_Compiledf3(MASNCGB_DINLSP, "LSPOL", 5L);
  MASLISPU_Compiledf3(MASNCGB_DINLNF, "LNFORM", 6L);
  MASLISPU_Compiledf2(MASNCGB_DINLIS, "LIRRSET", 7L);
  MASLISPU_Compiledf3(MASNCGB_DINLGB, "LGBASE", 6L);
  MASLISPU_Compiledf3(MASNCGB_DINCGB, "TSGBASE", 7L);
  MASLISPU_Compiledf3(MASNCC_EVLGTD, "EVLGTD", 6L);
  MASLISPU_Compiledf1(MASNCC_EVLGIL, "EVLGIL", 6L);
  MASLISPU_Compiledf3(MASNCC_DINCCO, "DINCCO", 6L);
  MASLISPU_Compiledf2(MASNCC_DINCCP, "DINCCP", 6L);
  MASLISPU_Compiledf2(MASNCC_DILFEL, "DILFEL", 6L);
  MASLISPU_Compiledf2(MASNCC_DINCCPpre, "CenterPol", 9L);
  MASLISPU_Compiledf3(MASNCC_DINLMPG, "DINLMPG", 7L);
  MASLISPU_Compiledf2(MASNCC_DINLMPL, "DINLMPL", 7L);
}

static MASSTOR_LIST ndread
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST P, V, X;

  P = MASSTOR_SIL;
  X = pdread();
  V = MASSTOR_FIRST(X);
  do {
    P = DIPRN_DIRLRD(V);
    MASBIOS_BLINES(0);
  } while (!(P != MASSTOR_SIL));
  P = MASSTOR_LIST1(P);
  P = SACLIST_CCONC(X, P);
  return P;
}

static MASSTOR_LIST npread
# ifdef __STDC__
(MASSTOR_LIST T)
# else
(T)
MASSTOR_LIST T;
# endif
{
  MASSTOR_LIST P, V, E;

  P = MASSTOR_SIL;
  V = DIPC_VALIS;
  do {
    MASBIOS_SWRITE("Enter noncom polynomial list: ", 30L);
    MASBIOS_BLINES(0);
    P = MASNC_DINLRD(V, T);
    MASBIOS_BLINES(1);
  } while (!(P != MASSTOR_SIL));
  return P;
}

static MASSTOR_LIST npreadd
# ifdef __STDC__
(MASSTOR_LIST X)
# else
(X)
MASSTOR_LIST X;
# endif
{
  MASSTOR_LIST T, P, V, E;

  P = MASSTOR_SIL;
  V = MASSTOR_FIRST(X);
  T = SACLIST_THIRD(X);
  do {
    MASBIOS_BLINES(0);
    P = MASNC_DINLRD(V, T);
    MASBIOS_BLINES(1);
  } while (!(P != MASSTOR_SIL));
  return P;
}

static MASSTOR_LIST pdread
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST P, T, V, E, Q, r, X;

  P = MASSTOR_SIL;
  do {
    V = SACPOL_VLREAD();
    MASBIOS_BLINES(1);
  } while (!(V != MASSTOR_SIL));
  DIPC_VALIS = V;
  do {
    E = MASBIOS_CREADB();
    MASBIOS_BLINES(1);
  } while (!(E == MASBIOS_MASORD('(') || E == MASBIOS_MASORD('L') || E == MASBIOS_MASORD('G')));
  if (E == MASBIOS_MASORD('L')) {
    DIPC_EVORD = DIPC_INVLEX;
  }
  if (E == MASBIOS_MASORD('G')) {
    DIPC_EVORD = DIPC_IGRLEX;
  }
  if (E == MASBIOS_MASORD('(')) {
    MASBIOS_BKSP();
    T = MASSTOR_LIST1(MASSTOR_LIST1(MASBIOS_MASORD('T')));
    X = DIPC_EVORD;
    DIPC_EVORD = DIPC_INVLEX;
    P = DIPRN_DIRLRD(T);
    P = DIPI_DIILFR(P);
    DIPC_PLFDIL(P, &r, &Q);
    DIPC_EVORD = X;
    if (MASSTOR_LENGTH(Q) == MASSTOR_LENGTH(V)) {
      DIPC_EVORD = MASSTOR_INV(Q);
    } else {
      MASBIOS_SWRITE("Wrong number of polynomials.", 28L);
      MASBIOS_BLINES(0);
    }
  }
  return MASSTOR_COMP(V, MASSTOR_LIST1(DIPC_EVORD));
}

void BEGIN_MASLOADC()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASLISPU();
    BEGIN_MASBIOS();
    BEGIN_SACLIST();
    BEGIN_SACPOL();
    BEGIN_DIPC();
    BEGIN_DIPI();
    BEGIN_DIPRN();
    BEGIN_MASNC();
    BEGIN_MASNCGB();
    BEGIN_MASNCC();

  }
}
