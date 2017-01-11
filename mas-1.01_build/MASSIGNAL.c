#include "SYSTEM_.h"

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_massig
#include "massig.h"
#endif

#ifndef DEFINITION_MASSIGNAL
#include "MASSIGNAL.h"
#endif

CHAR MASSIGNAL_rcsid [] = "$Id: MASSIGNAL.md,v 1.4 1995/12/16 15:11:42 kredel Exp $";
CHAR MASSIGNAL_copyright [] = "Copyright (c) 1994 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASSIGNAL.mi,v 1.6 1995/11/04 20:40:01 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1994, 1995 Universitaet Passau";
static massig_Action s;


void MASSIGNAL_SigUsr1HandleDefault
# ifdef __STDC__
(INTEGER signo)
# else
(signo)
INTEGER signo;
# endif
{
  massig_Action C_2_dummy;
  MASSTOR_LIST Dummy;

  C_2_dummy = signal(massig_SIGUSR1, massig_SIG_IGN);
  Dummy = MASBIOS_SOUNIT("CON:x", 5L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("______________________________________________________________________________", 78L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("SIGUSR1 received. This is the default signal handler.", 53L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("Sorry, whatever is executing at the moment has", 46L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("no special signal-handler installed.", 36L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("______________________________________________________________________________", 78L);
  MASBIOS_BLINES(1);
  Dummy = MASBIOS_CUNIT("CON:x", 5L);
  C_2_dummy = signal(massig_SIGUSR1, MASSIGNAL_SigUsr1HandleDefault);
}

void BEGIN_MASSIGNAL()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASBIOS();
    BEGIN_MASSTOR();
    BEGIN_massig();

    s = signal(massig_SIGUSR1, MASSIGNAL_SigUsr1HandleDefault);
  }
}
