#include "SYSTEM_.h"

#ifndef DEFINITION_setjmp
#include "setjmp.h"
#endif

CHAR setjmp_rcsid [] = "$Id: setjmp.md,v 1.4 1993/05/11 10:46:24 kredel Exp $";
CHAR setjmp_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";



void BEGIN_setjmp()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;


  }
}
