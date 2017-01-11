#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASLISPU
#include "MASLISPU.h"
#endif

#ifndef DEFINITION_MASC
#include "MASC.h"
#endif

#ifndef DEFINITION_MASQ
#include "MASQ.h"
#endif

#ifndef DEFINITION_MASO
#include "MASO.h"
#endif

#ifndef DEFINITION_MASFF
#include "MASFF.h"
#endif

#ifndef DEFINITION_MASLOADQ
#include "MASLOADQ.h"
#endif

CHAR MASLOADQ_rcsid [] = "$Id: MASLOADQ.md,v 1.1 1992/09/28 17:56:18 kredel Exp $";
CHAR MASLOADQ_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASLOADQ.mi,v 1.2 1992/10/15 16:30:38 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


void MASLOADQ_InitExternalsQ
# ifdef __STDC__
()
# else
()
# endif
{
  MASLISPU_Compiledp2(MASC_CDWRITE, "CDWRITE", 7L);
  MASLISPU_Compiledf0(MASC_CDREAD, "CDREAD", 6L);
  MASLISPU_Compiledp1(MASC_CNWRITE, "CNWRITE", 7L);
  MASLISPU_Compiledf0(MASC_CNREAD, "CNREAD", 6L);
  MASLISPU_Compiledf1(MASC_CINT, "CINT", 4L);
  MASLISPU_Compiledf1(MASC_CRN, "CRN", 3L);
  MASLISPU_Compiledf2(MASC_CRNP, "CRNP", 4L);
  MASLISPU_Compiledf1(MASC_CRE, "CRE", 3L);
  MASLISPU_Compiledf1(MASC_CIM, "CIM", 3L);
  MASLISPU_Compiledf1(MASC_CRAND, "CRAND", 5L);
  MASLISPU_Compiledf2(MASC_CCOMP, "CCOMP", 5L);
  MASLISPU_Compiledf1(MASC_CONE, "CONE", 4L);
  MASLISPU_Compiledf1(MASC_CNEG, "CNEG", 4L);
  MASLISPU_Compiledf1(MASC_CCON, "CCON", 4L);
  MASLISPU_Compiledf1(MASC_CABS, "CABS", 4L);
  MASLISPU_Compiledf2(MASC_CSUM, "CSUM", 4L);
  MASLISPU_Compiledf2(MASC_CDIF, "CDIF", 4L);
  MASLISPU_Compiledf1(MASC_CNINV, "CNINV", 5L);
  MASLISPU_Compiledf2(MASC_CPROD, "CPROD", 5L);
  MASLISPU_Compiledf2(MASC_CQ, "CQ", 2L);
  MASLISPU_Compiledf2(MASC_CEXP, "CEXP", 4L);
  MASLISPU_Compiledp2(MASQ_QDWRITE, "QDWRITE", 7L);
  MASLISPU_Compiledf0(MASQ_QDREAD, "QDREAD", 6L);
  MASLISPU_Compiledp1(MASQ_QNWRITE, "QNWRITE", 7L);
  MASLISPU_Compiledf0(MASQ_QNREAD, "QNREAD", 6L);
  MASLISPU_Compiledf1(MASQ_QINT, "QINT", 4L);
  MASLISPU_Compiledf1(MASQ_QRN, "QRN", 3L);
  MASLISPU_Compiledf4(MASQ_QRN4, "QRN4", 4L);
  MASLISPU_Compiledf1(MASQ_QRE, "QRE", 3L);
  MASLISPU_Compiledf1(MASQ_QIMi, "QIMi", 4L);
  MASLISPU_Compiledf1(MASQ_QIMj, "QIMj", 4L);
  MASLISPU_Compiledf1(MASQ_QIMk, "QIMk", 4L);
  MASLISPU_Compiledf1(MASQ_QRAND, "QRAND", 5L);
  MASLISPU_Compiledf2(MASQ_QCOMP, "QCOMP", 5L);
  MASLISPU_Compiledf1(MASQ_QONE, "QONE", 4L);
  MASLISPU_Compiledf1(MASQ_QNEG, "QNEG", 4L);
  MASLISPU_Compiledf1(MASQ_QCON, "QCON", 4L);
  MASLISPU_Compiledf1(MASQ_QABS, "QABS", 4L);
  MASLISPU_Compiledf2(MASQ_QSUM, "QSUM", 4L);
  MASLISPU_Compiledf2(MASQ_QDIF, "QDIF", 4L);
  MASLISPU_Compiledf1(MASQ_QINV, "QINV", 4L);
  MASLISPU_Compiledf2(MASQ_QPROD, "QPROD", 5L);
  MASLISPU_Compiledf2(MASQ_QQ, "QQ", 2L);
  MASLISPU_Compiledf2(MASQ_QEXP, "QEXP", 4L);
  MASLISPU_Compiledp2(MASO_ODWRITE, "ODWRITE", 7L);
  MASLISPU_Compiledf0(MASO_ODREAD, "ODREAD", 6L);
  MASLISPU_Compiledp1(MASO_ONWRITE, "ONWRITE", 7L);
  MASLISPU_Compiledf0(MASO_ONREAD, "ONREAD", 6L);
  MASLISPU_Compiledf1(MASO_OINT, "OINT", 4L);
  MASLISPU_Compiledf1(MASO_ORN, "ORN", 3L);
  MASLISPU_Compiledf2(MASO_ORNP, "ORNP", 4L);
  MASLISPU_Compiledf1(MASO_ORE, "ORE", 3L);
  MASLISPU_Compiledf1(MASO_OIM, "OIM", 3L);
  MASLISPU_Compiledf1(MASO_ORAND, "ORAND", 5L);
  MASLISPU_Compiledf2(MASO_OCOMP, "OCOMP", 5L);
  MASLISPU_Compiledf1(MASO_OONE, "OONE", 4L);
  MASLISPU_Compiledf1(MASO_ONEG, "ONEG", 4L);
  MASLISPU_Compiledf1(MASO_OCON, "OCON", 4L);
  MASLISPU_Compiledf1(MASO_OABS, "OABS", 4L);
  MASLISPU_Compiledf2(MASO_OSUM, "OSUM", 4L);
  MASLISPU_Compiledf2(MASO_ODIF, "ODIF", 4L);
  MASLISPU_Compiledf1(MASO_ONINV, "ONINV", 5L);
  MASLISPU_Compiledf2(MASO_OPROD, "OPROD", 5L);
  MASLISPU_Compiledf2(MASO_OQ, "OQ", 2L);
  MASLISPU_Compiledf2(MASO_OEXP, "OEXP", 4L);
  MASLISPU_Compiledp2(MASFF_FFWRITE, "FFWRITE", 7L);
  MASLISPU_Compiledf1(MASFF_FFREAD, "FFREAD", 6L);
  MASLISPU_Compiledf3(MASFF_FFFINT, "FFFINT", 6L);
  MASLISPU_Compiledf3(MASFF_FFHOM, "FFHOM", 5L);
  MASLISPU_Compiledf3(MASFF_FFRAND, "FFRAND", 6L);
  MASLISPU_Compiledf2(MASFF_FFCOMP, "FFCOMP", 6L);
  MASLISPU_Compiledf1(MASFF_FFONE, "FFONE", 5L);
  MASLISPU_Compiledf3(MASFF_FFNEG, "FFNEG", 5L);
  MASLISPU_Compiledf4(MASFF_FFSUM, "FFSUM", 5L);
  MASLISPU_Compiledf4(MASFF_FFDIF, "FFDIF", 5L);
  MASLISPU_Compiledf3(MASFF_FFINV, "FFINV", 5L);
  MASLISPU_Compiledf4(MASFF_FFPROD, "FFPROD", 6L);
  MASLISPU_Compiledf4(MASFF_FFQ, "FFQ", 3L);
  MASLISPU_Compiledf4(MASFF_FFEXP, "FFEXP", 5L);
}

void BEGIN_MASLOADQ()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASLISPU();
    BEGIN_MASC();
    BEGIN_MASQ();
    BEGIN_MASO();
    BEGIN_MASFF();

  }
}
