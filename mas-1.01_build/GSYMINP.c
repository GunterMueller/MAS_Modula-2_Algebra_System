#include "SYSTEM_.h"

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPI
#include "DIPI.h"
#endif

#ifndef DEFINITION_DIPRN
#include "DIPRN.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_GSYMINP
#include "GSYMINP.h"
#endif

CHAR GSYMINP_rcsid [] = "$Id: GSYMINP.md,v 1.2 1996/06/09 10:20:20 pesch Exp $";
CHAR GSYMINP_copyright [] = "Copyright (c) 1996 Universitaet Passau";

static CHAR rcsidi [] = "$Id: GSYMINP.mi,v 1.1 1996/06/08 18:52:49 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1996 Universitaet Passau";


MASSTOR_LIST GSYMINP_GSDREAD
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
  } while (!(E == MASBIOS_MASORD('(') || E == MASBIOS_MASORD('S') || E == MASBIOS_MASORD('L') || E == MASBIOS_MASORD('P') || E == MASBIOS_MASORD('G')));
  if (E == MASBIOS_MASORD('S')) {
    DIPC_EVORD = DIPC_REVILEX;
  }
  if (E == MASBIOS_MASORD('L')) {
    DIPC_EVORD = DIPC_INVLEX;
  }
  if (E == MASBIOS_MASORD('P')) {
    DIPC_EVORD = DIPC_REVITDG;
  }
  if (E == MASBIOS_MASORD('G')) {
    DIPC_EVORD = DIPC_IGRLEX;
  }
  if (E == MASBIOS_MASORD('(')) {
    MASBIOS_BKSP();
    T = MASSTOR_LIST1(MASSTOR_LIST1(MASBIOS_MASORD('T')));
    X = DIPC_EVORD;
    DIPC_EVORD = DIPC_INVLEX;
    P = DIPI_DIILRD(T);
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

MASSTOR_LIST GSYMINP_GSPREAD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST P, V, X;

  P = MASSTOR_SIL;
  X = GSYMINP_GSDREAD();
  V = MASSTOR_FIRST(X);
  do {
    MASBIOS_SWRITE("Enter polynomial list: ", 23L);
    P = DIPI_DIILRD(V);
    MASBIOS_BLINES(0);
  } while (!(P != MASSTOR_SIL));
  return P;
}

MASSTOR_LIST GSYMINP_GSRDREAD
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
  } while (!(E == MASBIOS_MASORD('(') || E == MASBIOS_MASORD('S') || E == MASBIOS_MASORD('L') || E == MASBIOS_MASORD('P') || E == MASBIOS_MASORD('G')));
  if (E == MASBIOS_MASORD('S')) {
    DIPC_EVORD = DIPC_REVILEX;
  }
  if (E == MASBIOS_MASORD('L')) {
    DIPC_EVORD = DIPC_INVLEX;
  }
  if (E == MASBIOS_MASORD('P')) {
    DIPC_EVORD = DIPC_REVITDG;
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

MASSTOR_LIST GSYMINP_GSRREAD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST P, V, X;

  P = MASSTOR_SIL;
  X = GSYMINP_GSRDREAD();
  V = MASSTOR_FIRST(X);
  do {
    MASBIOS_SWRITE("Enter polynomial list: ", 23L);
    P = DIPRN_DIRLRD(V);
    MASBIOS_BLINES(0);
  } while (!(P != MASSTOR_SIL));
  return P;
}

void BEGIN_GSYMINP()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_DIPC();
    BEGIN_DIPI();
    BEGIN_DIPRN();
    BEGIN_MASBIOS();
    BEGIN_MASSTOR();
    BEGIN_SACPOL();

  }
}
