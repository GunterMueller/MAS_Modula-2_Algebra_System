#include "SYSTEM_.h"

#ifndef DEFINITION_MLDEMO
#include "MLDEMO.h"
#endif

#ifndef DEFINITION_MASLISPU
#include "MASLISPU.h"
#endif

#ifndef DEFINITION_MLMLDEMO
#include "MLMLDEMO.h"
#endif

CHAR MLMLDEMO_rcsid [] = "$Id: MLMLDEMO.md,v 1.3 1995/11/05 14:04:46 kredel Exp $";
CHAR MLMLDEMO_copyright [] = "Copyright (c) 1993 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MLMLDEMO.mi,v 1.2 1993/12/17 17:38:55 dolzmann Exp $";
static CHAR copyrighti [] = "Copyright (c) 1993 Universitaet Passau";


void MLMLDEMO_InitExternalsMLDEMO
# ifdef __STDC__
()
# else
()
# endif
{
  MASLISPU_Compiledf1(MLDEMO_MLDMKPOS, "MLDMKPOS", 8L);
  MASLISPU_Compiledf2(MLDEMO_MLDMKPOS1, "MLDMKPOS1", 9L);
  MASLISPU_Compiledf1(MLDEMO_MLDSMPL, "MLDSMPL", 7L);
  MASLISPU_Compiledf1(MLDEMO_MLDTST, "MLDTST", 6L);
  MASLISPU_Compiledp1(MLDEMO_MLDPPRT, "MLDPPRT", 7L);
  MASLISPU_Compiledp1(MLDEMO_MLDTEXW, "MLDTEXW", 7L);
  MASLISPU_Compiledf1(MLDEMO_MLDMKDNF, "MLDMKDNF", 8L);
  MASLISPU_Compiledf1(MLDEMO_MLDMKCNF, "MLDMKCNF", 8L);
  MASLISPU_Compiledf3(MLDEMO_MLDSUBSTVAR, "MLDSUBSTVAR", 11L);
  MASLISPU_Compiledf2(MLDEMO_MLDMKPRENEX, "MLDMKPRENEX", 11L);
  MASLISPU_Compiledf1(MLDEMO_MLDPREPQE, "MLDPREPQE", 9L);
  MASLISPU_Compiledf2(MLDEMO_MLDCONTVAR, "MLDCONTVAR", 10L);
  MASLISPU_Compiledf2(MLDEMO_MLDCONTBDVAR, "MLDCONTBDVAR", 12L);
  MASLISPU_Compiledf1(MLDEMO_MLDAPPLYAT, "MLDAPPLYAT", 10L);
  MASLISPU_Compiledf1(MLDEMO_MLDMKVD, "MLDMKVD", 7L);
  MASLISPU_Compiledf0(MLDEMO_MLDPREAD, "MLDPREAD", 8L);
  MASLISPU_Compiledf0(MLDEMO_MLDIREAD, "MLDIREAD", 8L);
}

void BEGIN_MLMLDEMO()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MLDEMO();
    BEGIN_MASLISPU();

  }
}
