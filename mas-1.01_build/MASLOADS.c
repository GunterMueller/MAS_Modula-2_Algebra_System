#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASLISPU
#include "MASLISPU.h"
#endif

#ifndef DEFINITION_SYZMAIN
#include "SYZMAIN.h"
#endif

#ifndef DEFINITION_SYZGB
#include "SYZGB.h"
#endif

#ifndef DEFINITION_SYZHLP
#include "SYZHLP.h"
#endif

#ifndef DEFINITION_MASLOADS
#include "MASLOADS.h"
#endif

CHAR MASLOADS_rcsid [] = "$Id: MASLOADS.md,v 1.2 1992/02/12 17:32:53 pesch Exp $";
CHAR MASLOADS_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASLOADS.mi,v 1.3 1992/10/15 16:30:40 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
static void nlmgb ARGS((MASSTOR_LIST PM, MASSTOR_LIST SANZ, MASSTOR_LIST *T, MASSTOR_LIST *pm));


void MASLOADS_InitExternalsS
# ifdef __STDC__
()
# else
()
# endif
{
  MASLISPU_Compiledf3(SYZMAIN_SYHC, "SYHC", 4L);
  MASLISPU_Compiledf3(SYZMAIN_HEQ, "HEQ", 3L);
  MASLISPU_Compiledf3(SYZMAIN_HSEQ, "HSEQ", 4L);
  MASLISPU_Compiledp3(SYZMAIN_SYTHC, "SYTHC", 5L);
  MASLISPU_Compiledf4(SYZMAIN_SIC, "SIC", 3L);
  MASLISPU_Compiledf4(SYZMAIN_IEQ, "IEQ", 3L);
  MASLISPU_Compiledf4(SYZMAIN_ISEQ, "ISEQ", 4L);
  MASLISPU_Compiledp4(SYZMAIN_STIC, "STIC", 4L);
  MASLISPU_Compiledf4(SYZMAIN_SYHNL, "SYHNL", 5L);
  MASLISPU_Compiledf4(SYZMAIN_NLHEQ, "NLHEQ", 5L);
  MASLISPU_Compiledf4(SYZMAIN_NLHSEQ, "NLHSEQ", 6L);
  MASLISPU_Compiledp4(SYZMAIN_SYTHNL, "SYTHNL", 6L);
  MASLISPU_Compiledf5(SYZMAIN_SINL, "SINL", 4L);
  MASLISPU_Compiledf5(SYZMAIN_NLIEQ, "NLIEQ", 5L);
  MASLISPU_Compiledf5(SYZMAIN_NLISEQ, "NLISEQ", 6L);
  MASLISPU_Compiledp5(SYZMAIN_STINL, "STINL", 5L);
  MASLISPU_Compiledp2v3(SYZMAIN_OREC, "OREC", 4L);
  MASLISPU_Compiledf2(SYZGB_MGB, "MGB", 3L);
  MASLISPU_Compiledp2v2(nlmgb, "nlmgb", 5L);
  MASLISPU_Compiledf1(SYZHLP_MREAD, "MREAD", 5L);
  MASLISPU_Compiledf2(SYZHLP_NMREAD, "NMREAD", 6L);
  MASLISPU_Compiledp2(SYZHLP_PLWR, "PLWR", 4L);
  MASLISPU_Compiledp2(SYZHLP_PMWR, "PMWR", 4L);
}

static void nlmgb
# ifdef __STDC__
(MASSTOR_LIST PM, MASSTOR_LIST SANZ, MASSTOR_LIST *T, MASSTOR_LIST *pm)
# else
(PM, SANZ, T, pm)
MASSTOR_LIST PM, SANZ;
MASSTOR_LIST *T, *pm;
# endif
{
  *pm = SYZGB_NLMGB(PM, SANZ, T);
}

void BEGIN_MASLOADS()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASLISPU();
    BEGIN_SYZMAIN();
    BEGIN_SYZGB();
    BEGIN_SYZHLP();

  }
}
