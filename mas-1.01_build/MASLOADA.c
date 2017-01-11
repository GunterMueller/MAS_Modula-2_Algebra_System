#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASLISPU
#include "MASLISPU.h"
#endif

#ifndef DEFINITION_SACI
#include "SACI.h"
#endif

#ifndef DEFINITION_SACCOMB
#include "SACCOMB.h"
#endif

#ifndef DEFINITION_SACRN
#include "SACRN.h"
#endif

#ifndef DEFINITION_SACM
#include "SACM.h"
#endif

#ifndef DEFINITION_MASRN
#include "MASRN.h"
#endif

#ifndef DEFINITION_MASI
#include "MASI.h"
#endif

#ifndef DEFINITION_MASAPF
#include "MASAPF.h"
#endif

#ifndef DEFINITION_SACPRIM
#include "SACPRIM.h"
#endif

#ifndef DEFINITION_MASF
#include "MASF.h"
#endif

#ifndef DEFINITION_MASLOADA
#include "MASLOADA.h"
#endif

CHAR MASLOADA_rcsid [] = "$Id: MASLOADA.md,v 1.2 1992/02/12 17:32:49 pesch Exp $";
CHAR MASLOADA_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASLOADA.mi,v 1.4 1995/11/05 09:05:01 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
static MASSTOR_LIST GetSMPRM ARGS(());
static MASSTOR_LIST VIA ARGS((MASSTOR_LIST a));
static MASSTOR_LIST APREAD ARGS(());


void MASLOADA_InitExternalsA
# ifdef __STDC__
()
# else
()
# endif
{
  MASLISPU_Compiledp1(SACI_IWRITE, "IWRITE", 6L);
  MASLISPU_Compiledp1(SACI_ILWRIT, "ILWRIT", 6L);
  MASLISPU_Compiledf0(SACI_IREAD, "IREAD", 5L);
  MASLISPU_Compiledf1(SACI_ISIGNF, "ISIGN", 5L);
  MASLISPU_Compiledf2(SACI_ICOMP, "ICOMP", 5L);
  MASLISPU_Compiledf1(SACI_INEG, "INEG", 4L);
  MASLISPU_Compiledf1(SACI_IABSF, "IABS", 4L);
  MASLISPU_Compiledf2(SACI_ISUM, "ISUM", 4L);
  MASLISPU_Compiledf2(SACI_IDIF, "IDIF", 4L);
  MASLISPU_Compiledf2(MASI_IPROD, "IPROD", 5L);
  MASLISPU_Compiledf2(SACI_IQ, "IQ", 2L);
  MASLISPU_Compiledf2(SACI_IREM, "IREM", 4L);
  MASLISPU_Compiledp2v2(SACI_IQR, "IQR", 3L);
  MASLISPU_Compiledf2(SACI_IEXP, "IEXP", 4L);
  MASLISPU_Compiledf2(SACI_IGCD, "IGCD", 4L);
  MASLISPU_Compiledf2(SACI_ILCM, "ILCM", 4L);
  MASLISPU_Compiledf1(SACI_IRAND, "IRAND", 5L);
  MASLISPU_Compiledp2(SACRN_RNDWR, "RNDWR", 5L);
  MASLISPU_Compiledp1(SACRN_RNWRIT, "RNWRIT", 6L);
  MASLISPU_Compiledf0(SACRN_RNREAD, "RNREAD", 6L);
  MASLISPU_Compiledf2(SACRN_RNRED, "RNRED", 5L);
  MASLISPU_Compiledf1(SACRN_RNDEN, "RNDEN", 5L);
  MASLISPU_Compiledf1(SACRN_RNNUM, "RNNUM", 5L);
  MASLISPU_Compiledf1(SACRN_RNINV, "RNINV", 5L);
  MASLISPU_Compiledf1(SACRN_RNSIGN, "RNSIGN", 6L);
  MASLISPU_Compiledf2(SACRN_RNCOMP, "RNCOMP", 6L);
  MASLISPU_Compiledf1(SACRN_RNNEG, "RNNEG", 5L);
  MASLISPU_Compiledf1(SACRN_RNABS, "RNABS", 5L);
  MASLISPU_Compiledf1(SACRN_RNINT, "RNINT", 5L);
  MASLISPU_Compiledf2(SACRN_RNSUM, "RNSUM", 5L);
  MASLISPU_Compiledf2(SACRN_RNDIF, "RNDIF", 5L);
  MASLISPU_Compiledf2(SACRN_RNPROD, "RNPROD", 6L);
  MASLISPU_Compiledf2(SACRN_RNQ, "RNQ", 3L);
  MASLISPU_Compiledf2(MASRN_RNEXP, "RNEXP", 5L);
  MASLISPU_Compiledp1(MASAPF_APSPRE, "APSPRE", 6L);
  MASLISPU_Compiledp1(MASAPF_APWRIT, "APWRIT", 6L);
  MASLISPU_Compiledf0(APREAD, "APREAD", 6L);
  MASLISPU_Compiledf0(MASAPF_RNDRD, "RNDRD", 5L);
  MASLISPU_Compiledf1(MASAPF_APFRN, "APFRN", 5L);
  MASLISPU_Compiledf1(MASAPF_RNFAP, "RNFAP", 5L);
  MASLISPU_Compiledf1(MASAPF_APSIGN, "APSIGN", 6L);
  MASLISPU_Compiledf2(MASAPF_APCMPR, "APCMPR", 6L);
  MASLISPU_Compiledf1(MASAPF_APNEG, "APNEG", 5L);
  MASLISPU_Compiledf1(MASAPF_APABS, "APABS", 5L);
  MASLISPU_Compiledf1(MASAPF_APFINT, "APFINT", 6L);
  MASLISPU_Compiledf2(MASAPF_APSUM, "APSUM", 5L);
  MASLISPU_Compiledf2(MASAPF_APDIFF, "APDIFF", 6L);
  MASLISPU_Compiledf2(MASAPF_APPROD, "APPROD", 6L);
  MASLISPU_Compiledf2(MASAPF_APQ, "APQ", 3L);
  MASLISPU_Compiledf2(MASAPF_APEXP, "APEXP", 5L);
  MASLISPU_Compiledf2(MASAPF_APROOT, "APROOT", 6L);
  MASLISPU_Compiledf0(MASAPF_APPI, "APPI", 4L);
  MASLISPU_Compiledf1(SACPRIM_IFACT, "IFACT", 5L);
  MASLISPU_Compiledf2(SACPRIM_DPGEN, "DPGEN", 5L);
  MASLISPU_Compiledf0(GetSMPRM, "SMPRM", 5L);
  MASLISPU_Compiledf1(SACCOMB_IFACTL, "IFACTL", 6L);
  MASLISPU_Compiledf2(SACCOMB_IBCOEF, "IBCOEF", 6L);
  MASLISPU_Compiledf1(MASF_SIN, "SIN", 3L);
  MASLISPU_Compiledf1(MASF_COS, "COS", 3L);
  MASLISPU_Compiledf1(MASF_TAN, "TAN", 3L);
  MASLISPU_Compiledf1(MASF_ARCTAN, "ARCTAN", 6L);
  MASLISPU_Compiledf1(MASF_LN, "LN", 2L);
  MASLISPU_Compiledf1(MASF_LOG, "LOG", 3L);
  MASLISPU_Compiledf1(MASF_EXPF, "EXPF", 4L);
  MASLISPU_Compiledf1(MASF_SQRT, "SQRT", 4L);
  MASLISPU_Compiledf1(VIA, "VIA", 3L);
  MASLISPU_Compiledf3(SACM_MIDIF, "MIDIF", 5L);
  MASLISPU_Compiledf3(SACM_MIEXP, "MIEXP", 5L);
  MASLISPU_Compiledf2(SACM_MIHOM, "MIHOM", 5L);
  MASLISPU_Compiledf2(SACM_MIINV, "MIINV", 5L);
  MASLISPU_Compiledf2(SACM_MINEG, "MINEG", 5L);
  MASLISPU_Compiledf3(SACM_MIPROD, "MIPROD", 6L);
  MASLISPU_Compiledf3(SACM_MIQ, "MIQ", 3L);
  MASLISPU_Compiledf3(SACM_MISUM, "MISUM", 5L);
}

static MASSTOR_LIST GetSMPRM
# ifdef __STDC__
()
# else
()
# endif
{
  return SACPRIM_SMPRM;
}

static MASSTOR_LIST VIA
# ifdef __STDC__
(MASSTOR_LIST a)
# else
(a)
MASSTOR_LIST a;
# endif
{
  return MASF_RNFF(MASF_FFRN(a));
}

static MASSTOR_LIST APREAD
# ifdef __STDC__
()
# else
()
# endif
{
  return MASAPF_APFRN(MASAPF_RNDRD());
}

void BEGIN_MASLOADA()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASLISPU();
    BEGIN_SACI();
    BEGIN_SACCOMB();
    BEGIN_SACRN();
    BEGIN_SACM();
    BEGIN_MASRN();
    BEGIN_MASI();
    BEGIN_MASAPF();
    BEGIN_SACPRIM();
    BEGIN_MASF();

  }
}
