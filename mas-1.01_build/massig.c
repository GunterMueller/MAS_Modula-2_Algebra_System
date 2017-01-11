#include "SYSTEM_.h"

#ifndef DEFINITION_massig
#include "massig.h"
#endif

CHAR massig_rcsid [] = "$Id: massig.md,v 1.3 1995/12/16 13:37:38 kredel Exp $";
CHAR massig_copyright [] = "Copyright (c) 1995 Universitaet Passau";
massig_Action massig_SIG_DFL, massig_SIG_IGN, massig_SIG_ACK, massig_SIG_ERR;

static CHAR rcsidi [] = "$Id: massig.mi,v 1.1 1995/11/04 20:40:06 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1995 Universitaet Passau";


void BEGIN_massig()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;


    massig_SIG_DFL = (massig_Action)0;
    massig_SIG_IGN = (massig_Action)1;
    massig_SIG_ACK = (massig_Action)4;
    massig_SIG_ERR = (massig_Action)-1;
  }
}
