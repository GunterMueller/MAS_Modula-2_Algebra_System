#include "SYSTEM_.h"

#ifndef DEFINITION_MASLOADA
#include "MASLOADA.h"
#endif

#ifndef DEFINITION_MASLOADB
#include "MASLOADB.h"
#endif

#ifndef DEFINITION_MASLOADC
#include "MASLOADC.h"
#endif

#ifndef DEFINITION_MASLOADD
#include "MASLOADD.h"
#endif

#ifndef DEFINITION_MASLOADE
#include "MASLOADE.h"
#endif

#ifndef DEFINITION_MASLOADG
#include "MASLOADG.h"
#endif

#ifndef DEFINITION_MASLOADJ
#include "MASLOADJ.h"
#endif

#ifndef DEFINITION_MASLOADL
#include "MASLOADL.h"
#endif

#ifndef DEFINITION_MASLOADM
#include "MASLOADM.h"
#endif

#ifndef DEFINITION_MASLOADS
#include "MASLOADS.h"
#endif

#ifndef DEFINITION_MASLOADQ
#include "MASLOADQ.h"
#endif

#ifndef DEFINITION_MLMASLOG
#include "MLMASLOG.h"
#endif

#ifndef DEFINITION_MLMLDEMO
#include "MLMLDEMO.h"
#endif

#ifndef DEFINITION_MLPQSMPL
#include "MLPQSMPL.h"
#endif

#ifndef DEFINITION_MASLOAD
#include "MASLOAD.h"
#endif

CHAR MASLOAD_rcsid [] = "$Id: MASLOAD.md,v 1.2 1992/02/12 17:32:47 pesch Exp $";
CHAR MASLOAD_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASLOAD.mi,v 1.8 1995/11/05 15:29:35 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1995 Universitaet Passau";


void MASLOAD_InitExternals
# ifdef __STDC__
()
# else
()
# endif
{
  MASLOADA_InitExternalsA();
  MASLOADB_InitExternalsB();
  MASLOADC_InitExternalsC();
  MASLOADD_InitExternalsD();
  MASLOADG_InitExternalsG();
  MASLOADE_InitExternalsE();
  MASLOADJ_InitExternalsJ();
  MASLOADQ_InitExternalsQ();
  MASLOADL_InitExternalsL();
  MASLOADM_InitExternalsM();
  MASLOADS_InitExternalsS();
  MLMASLOG_InitExternalsML();
  MLMLDEMO_InitExternalsMLDEMO();
  MLPQSMPL_InitExternalsPQSMPL();
}

void BEGIN_MASLOAD()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASLOADA();
    BEGIN_MASLOADB();
    BEGIN_MASLOADC();
    BEGIN_MASLOADD();
    BEGIN_MASLOADE();
    BEGIN_MASLOADG();
    BEGIN_MASLOADJ();
    BEGIN_MASLOADL();
    BEGIN_MASLOADM();
    BEGIN_MASLOADS();
    BEGIN_MASLOADQ();
    BEGIN_MLMASLOG();
    BEGIN_MLMLDEMO();
    BEGIN_MLPQSMPL();

  }
}
