#include "SYSTEM_.h"

#ifndef DEFINITION_Portab
#include "Portab.h"
#endif

CHAR Portab_rcsid [] = "$Id: Portab.md,v 1.2 1992/02/12 17:31:59 pesch Exp $";
CHAR Portab_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
CHAR Portab_esc, Portab_cr, Portab_ff, Portab_ef, Portab_lf, Portab_del, Portab_bs, Portab_nul, Portab_sp;

static CHAR rcsidi [] = "$Id";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


void BEGIN_Portab()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;


    Portab_esc = (CHAR)27;
    Portab_cr = (CHAR)13;
    Portab_ff = (CHAR)12;
    Portab_ef = (CHAR)4;
    Portab_lf = (CHAR)11;
    Portab_del = (CHAR)127;
    Portab_bs = (CHAR)8;
    Portab_nul = (CHAR)0;
    Portab_sp = (CHAR)32;
  }
}
