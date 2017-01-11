#include "SYSTEM_.h"

#ifndef DEFINITION_MASLISPU
#include "MASLISPU.h"
#endif

#ifndef DEFINITION_PQSMPL
#include "PQSMPL.h"
#endif

#ifndef DEFINITION_MLPQSMPL
#include "MLPQSMPL.h"
#endif

CHAR MLPQSMPL_rcsid [] = "$Id: MLPQSMPL.md,v 1.2 1995/11/05 14:04:49 kredel Exp $";
CHAR MLPQSMPL_copyright [] = "Copyright (c) 1993 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MLPQSMPL.mi,v 1.4 1994/11/28 21:14:33 dolzmann Exp $";
static CHAR copyrighti [] = "Copyright (c) 1993 Universitaet Passau";


void MLPQSMPL_InitExternalsPQSMPL
# ifdef __STDC__
()
# else
()
# endif
{
  MASLISPU_Compiledf1(PQSMPL_PQSCNF, "PQSCNF", 6L);
  MASLISPU_Compiledf1(PQSMPL_PQSDNF, "PQSDNF", 6L);
  MASLISPU_Compiledf1(PQSMPL_PQCnfSimplify, "PQCnfSimplify", 13L);
  MASLISPU_Compiledf1(PQSMPL_PQDnfSimplify, "PQDnfSimplify", 13L);
  MASLISPU_Compiledf1(PQSMPL_PQOPT, "PQOPT", 5L);
  MASLISPU_Compiledp0(PQSMPL_PQOPTWR, "PQOPTWR", 7L);
  MASLISPU_Compiledp0(PQSMPL_PQDEMO, "PQDEMO", 6L);
}

void BEGIN_MLPQSMPL()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASLISPU();
    BEGIN_PQSMPL();

  }
}
