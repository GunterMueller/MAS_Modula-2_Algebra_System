#include "SYSTEM_.h"

#ifndef DEFINITION_ADEXTRA
#include "ADEXTRA.h"
#endif

#ifndef DEFINITION_DIPDCIB
#include "DIPDCIB.h"
#endif

#ifndef DEFINITION_DIPIB
#include "DIPIB.h"
#endif

#ifndef DEFINITION_DIPIIB
#include "DIPIIB.h"
#endif

#ifndef DEFINITION_DIPRNIB
#include "DIPRNIB.h"
#endif

#ifndef DEFINITION_MASLISPU
#include "MASLISPU.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASLOADJ
#include "MASLOADJ.h"
#endif

CHAR MASLOADJ_rcsid [] = "$Id: MASLOADJ.md,v 1.1 1995/10/12 14:43:41 pesch Exp $";
CHAR MASLOADJ_copyright [] = "Copyright (c) 1995 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASLOADJ.mi,v 1.1 1995/10/12 14:43:43 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1995 Universitaet Passau";


void MASLOADJ_InitExternalsJ
# ifdef __STDC__
()
# else
()
# endif
{
  DIPIB_SetDomainNFJ();
  MASLISPU_Compiledf2(ADEXTRA_IBeqGB, "IBeqGB", 6L);
  MASLISPU_Compiledp2v2(DIPIB_ADPNFJ, "ADPNFJ", 6L);
  MASLISPU_Compiledp1v2(DIPIB_DILISJ, "DILISJ", 6L);
  MASLISPU_Compiledf1(DIPIB_DIPIB, "DIPIB", 5L);
  MASLISPU_Compiledf1(DIPIB_DIPIB2, "DIPIB2", 6L);
  MASLISPU_Compiledf1(DIPIB_DIPIB3, "DIPIB3", 6L);
  MASLISPU_Compiledf1(DIPIB_DIPIB4, "DIPIB4", 6L);
  MASLISPU_Compiledp1(DIPIB_SetDIPIBopt, "SetDIPIBopt", 11L);
  MASLISPU_Compiledp1(DIPIB_SetDIPIBTraceLevel, "SetDIPIBTraceLevel", 18L);
  MASLISPU_Compiledp1(DIPIB_SetDIPIBCancel, "SetDIPIBCancel", 14L);
  MASLISPU_Compiledp1(DIPIB_SetDIPIBSelect, "SetDIPIBSelect", 14L);
  MASLISPU_Compiledp1(DIPIB_SetDIPIBISJ, "SetDIPIBISJ", 11L);
  MASLISPU_Compiledp1(DIPIB_SetDIPIBCrit, "SetDIPIBCrit", 12L);
  MASLISPU_Compiledf1(DIPIB_ADCAN, "ADCAN", 5L);
  MASLISPU_Compiledf3(DIPIIB_DIIPNFJ, "DIIPNFJ", 7L);
  MASLISPU_Compiledf1(DIPIIB_DIILISJ, "DIILISJ", 7L);
  MASLISPU_Compiledf1(DIPIIB_DIIPIB, "DIIPIB", 6L);
  MASLISPU_Compiledf1(DIPIIB_DIIPIB2, "DIIPIB2", 7L);
  MASLISPU_Compiledf1(DIPIIB_DIIPIB3, "DIIPIB3", 7L);
  MASLISPU_Compiledf3(DIPRNIB_DIRPNFJ, "DIRPNFJ", 7L);
  MASLISPU_Compiledf1(DIPRNIB_DIRLISJ, "DIRLISJ", 7L);
  MASLISPU_Compiledf1(DIPRNIB_DIRPIB, "DIRPIB", 6L);
  MASLISPU_Compiledf1(DIPRNIB_DIRPIB2, "DIRPIB2", 7L);
  MASLISPU_Compiledf2(DIPDCIB_InvolutiveBases, "IB", 2L);
  MASLISPU_Compiledp2(DIPDCIB_IBLWR, "IBLWR", 5L);
  MASLISPU_Compiledp1(DIPDCIB_SetDCIBopt, "SetDCIBopt", 10L);
  MASLISPU_Compiledp1(DIPDCIB_SetDCIBTraceLevel, "SetDCIBTraceLevel", 17L);
  MASLISPU_Compiledp1(DIPDCIB_SetDCIBDecomp, "SetDCIBDecomp", 13L);
  MASLISPU_Compiledp1(DIPDCIB_SetDCIBVarOrdOpt, "SetDCIBVarOrdOpt", 16L);
  MASLISPU_Compiledp1(DIPDCIB_SetDCIBdepth, "SetDCIBdepth", 12L);
}

void BEGIN_MASLOADJ()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_ADEXTRA();
    BEGIN_DIPDCIB();
    BEGIN_DIPIB();
    BEGIN_DIPIIB();
    BEGIN_DIPRNIB();
    BEGIN_MASLISPU();
    BEGIN_MASSTOR();

  }
}
