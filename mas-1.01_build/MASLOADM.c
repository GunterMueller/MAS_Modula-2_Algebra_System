#include "SYSTEM_.h"

#ifndef DEFINITION_MASLISPU
#include "MASLISPU.h"
#endif

#ifndef DEFINITION_LINALG
#include "LINALG.h"
#endif

#ifndef DEFINITION_RRADOM
#include "RRADOM.h"
#endif

#ifndef DEFINITION_RRINT
#include "RRINT.h"
#endif

#ifndef DEFINITION_RRUADOM
#include "RRUADOM.h"
#endif

#ifndef DEFINITION_RRUINT
#include "RRUINT.h"
#endif

#ifndef DEFINITION_MASLOADM
#include "MASLOADM.h"
#endif

CHAR MASLOADM_rcsid [] = "$Id: MASLOADM.md,v 1.2 1995/12/16 14:57:49 kredel Exp $";
CHAR MASLOADM_copyright [] = "Copyright (c) 1993 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASLOADM.mi,v 1.1 1994/03/11 15:37:30 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1993 Universitaet Passau";


void MASLOADM_InitExternalsM
# ifdef __STDC__
()
# else
()
# endif
{
  MASLISPU_Compiledf2(LINALG_ADUM, "ADUM", 4L);
  MASLISPU_Compiledf3(LINALG_ADVSPROD, "ADVSPROD", 8L);
  MASLISPU_Compiledf2(LINALG_ADVSVPROD, "ADVSVPROD", 9L);
  MASLISPU_Compiledf2(LINALG_ADVVSUM, "ADVVSUM", 7L);
  MASLISPU_Compiledf2(LINALG_ADSMPROD, "ADSMPROD", 8L);
  MASLISPU_Compiledf2(LINALG_ADMSUM, "ADMSUM", 6L);
  MASLISPU_Compiledf3(LINALG_ADMPROD, "ADMPROD", 7L);
  MASLISPU_Compiledf2(LINALG_ADMTRACE, "ADMTRACE", 8L);
  MASLISPU_Compiledf3(LINALG_ADMPTRACE, "ADMPTRACE", 9L);
  MASLISPU_Compiledf2(LINALG_ADCHARPOL, "ADCHARPOL", 9L);
  MASLISPU_Compiledf2(LINALG_ADSIG, "ADSIG", 5L);
  MASLISPU_Compiledp1(LINALG_ADVWRITE, "ADVWRITE", 8L);
  MASLISPU_Compiledp1(LINALG_ADMWRITE, "ADMWRITE", 8L);
  MASLISPU_Compiledf2(LINALG_IMRTPROD, "IMRTPROD", 8L);
  MASLISPU_Compiledf1(LINALG_ICHARPOL, "ICHARPOL", 8L);
  MASLISPU_Compiledf1(LINALG_ISIG, "ISIG", 4L);
  MASLISPU_Compiledf1(RRADOM_EVUMSORT, "EVUMSORT", 8L);
  MASLISPU_Compiledf1(RRADOM_EVSSPROD, "EVSSPROD", 8L);
  MASLISPU_Compiledf2(RRADOM_RRVTEXT, "RRVTEXT", 7L);
  MASLISPU_Compiledf1(RRADOM_RRZDIM, "RRZDIM", 6L);
  MASLISPU_Compiledf1(RRADOM_RRREDTERMS, "RRREDTERMS", 10L);
  MASLISPU_Compiledp3v2(RRADOM_RRADSTRCONST, "RRADSTRCONST", 12L);
  MASLISPU_Compiledf4(RRADOM_RRADVARMATRICES, "RRADVARMATRICES", 15L);
  MASLISPU_Compiledp3v2(RRADOM_RRADPOLMATRIX, "RRADPOLMATRIX", 13L);
  MASLISPU_Compiledf5(RRADOM_RRADQUADFORM, "RRADQUADFORM", 12L);
  MASLISPU_Compiledf5(RRADOM_RRADCOUNT, "RRADCOUNT", 9L);
  MASLISPU_Compiledp1v2(RRINT_RRIPIQ, "RRIPIQ", 6L);
  MASLISPU_Compiledp3v2(RRINT_RRIPQSUM, "RRIPQSUM", 8L);
  MASLISPU_Compiledp2v3(RRINT_RRISTRCONST, "RRISTRCONST", 11L);
  MASLISPU_Compiledf4(RRINT_RRIQUADFORM, "RRIQUADFORM", 11L);
  MASLISPU_Compiledf4(RRINT_RRICOUNT, "RRICOUNT", 8L);
  MASLISPU_Compiledf3(RRUADOM_RRUADPOLTOVEC, "RRUADPOLTOVEC", 13L);
  MASLISPU_Compiledf3(RRUADOM_RRUADSTRCONST, "RRUADSTRCONST", 13L);
  MASLISPU_Compiledf1(RRUADOM_RRUADQUADFORM, "RRUADQUADFORM", 13L);
  MASLISPU_Compiledf5(RRUADOM_RRUADCOUNT, "RRUADCOUNT", 10L);
  MASLISPU_Compiledf2(RRUINT_RRUIPOLTOVEC, "RRUIPOLTOVEC", 12L);
  MASLISPU_Compiledf2(RRUINT_RRUISTRCONST, "RRUISTRCONST", 12L);
  MASLISPU_Compiledf1(RRUINT_RRUIQUADFORM, "RRUIQUADFORM", 12L);
  MASLISPU_Compiledf4(RRUINT_RRUICOUNT, "RRUICOUNT", 9L);
}

void BEGIN_MASLOADM()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASLISPU();
    BEGIN_LINALG();
    BEGIN_RRADOM();
    BEGIN_RRINT();
    BEGIN_RRUADOM();
    BEGIN_RRUINT();

  }
}
