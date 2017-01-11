(* ----------------------------------------------------------------------------
 * $Id: MASLOADA.mi,v 1.4 1995/11/05 09:05:01 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASLOADA.mi,v $
 * Revision 1.4  1995/11/05 09:05:01  kredel
 * Interpreter IPROD now uses Karatsubas Method.
 *
 * Revision 1.3  1992/10/15  16:30:32  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:32:49  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:12:07  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASLOADA;

(* MAS Load Implementation Module A. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, LENGTH;

FROM MASLISPU IMPORT Declare,
                     Compiledp0, Compiledp1, Compiledp2, 
                     Compiledf0, Compiledf1, Compiledf2, Compiledf3,
                     Compiledp1v2,
                     Compiledp2v2; 

FROM SACI IMPORT IWRITE, IREAD, INEG, (* IPROD,*) ISUM, IDIF,  
                 IQ, IREM, IQR, ISIGNF, IABSF, IEXP, ICOMP, 
                 IGCD, ILCM, 
                 IRAND, ILWRIT;

FROM SACCOMB IMPORT IFACTL, IBCOEF;
  
FROM SACRN IMPORT RNWRIT, RNDWR, RNREAD, 
                  RNSIGN, RNCOMP, RNNEG, RNABS,
                  RNINT, RNRED, RNDEN, RNNUM, RNINV, 
                  RNSUM, RNDIF, RNPROD, RNQ;

FROM SACM IMPORT MIDIF, MIEXP, MIHOM, MIINV, MINEG, 
                 MIPROD, MIQ, MISUM;

FROM MASRN IMPORT RNEXP;

FROM MASI IMPORT IPROD;

FROM MASAPF IMPORT APSPRE, APFINT, APWRIT,
                   APSIGN, APCMPR, APNEG, APABS, 
                   APSUM, APDIFF, APPROD, APQ, APEXP,  
                   APFRN, RNFAP, RNDRD, 
                   APROOT, APPI;

FROM SACPRIM IMPORT IFACT, SMPRM, DPGEN;

FROM MASF IMPORT RNFF, FFRN,
                 SIN, COS, TAN, ARCTAN, 
                 EXPF, LN, LOG, SQRT;

CONST rcsidi = "$Id: MASLOADA.mi,v 1.4 1995/11/05 09:05:01 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE InitExternalsA;
(*Initialize external compiled arithmetic procedures. *)
BEGIN 
(*1*) (*from SACI+MASI. *)
      Compiledp1(IWRITE,"IWRITE");
      Compiledp1(ILWRIT,"ILWRIT");
      Compiledf0(IREAD,"IREAD");
      Compiledf1(ISIGNF,"ISIGN");
      Compiledf2(ICOMP,"ICOMP");
      Compiledf1(INEG,"INEG");
      Compiledf1(IABSF,"IABS");
      Compiledf2(ISUM,"ISUM");
      Compiledf2(IDIF,"IDIF");
      Compiledf2(IPROD,"IPROD");
      Compiledf2(IQ,"IQ");
      Compiledf2(IREM,"IREM");
      Compiledp2v2(IQR,"IQR");
      Compiledf2(IEXP,"IEXP");
      Compiledf2(IGCD,"IGCD");
      Compiledf2(ILCM,"ILCM");
      Compiledf1(IRAND,"IRAND");
(*2*) (*from SACRN+MASRN. *)
      Compiledp2(RNDWR,"RNDWR");
      Compiledp1(RNWRIT,"RNWRIT");
      Compiledf0(RNREAD,"RNREAD");
      Compiledf2(RNRED,"RNRED");
      Compiledf1(RNDEN,"RNDEN");
      Compiledf1(RNNUM,"RNNUM");
      Compiledf1(RNINV,"RNINV");
      Compiledf1(RNSIGN,"RNSIGN");
      Compiledf2(RNCOMP,"RNCOMP");
      Compiledf1(RNNEG,"RNNEG");
      Compiledf1(RNABS,"RNABS");
      Compiledf1(RNINT,"RNINT");
      Compiledf2(RNSUM,"RNSUM");
      Compiledf2(RNDIF,"RNDIF");
      Compiledf2(RNPROD,"RNPROD");
      Compiledf2(RNQ,"RNQ");
      Compiledf2(RNEXP,"RNEXP"); 
(*3*) (*from MASAPF. *)
      Compiledp1(APSPRE,"APSPRE");
      Compiledp1(APWRIT,"APWRIT");
      Compiledf0(APREAD,"APREAD");
      Compiledf0(RNDRD,"RNDRD");
      Compiledf1(APFRN,"APFRN");
      Compiledf1(RNFAP,"RNFAP");
      Compiledf1(APSIGN,"APSIGN");
      Compiledf2(APCMPR,"APCMPR");
      Compiledf1(APNEG,"APNEG");
      Compiledf1(APABS,"APABS");
      Compiledf1(APFINT,"APFINT");
      Compiledf2(APSUM,"APSUM");
      Compiledf2(APDIFF,"APDIFF");
      Compiledf2(APPROD,"APPROD");
      Compiledf2(APQ,"APQ");
      Compiledf2(APEXP,"APEXP");
      Compiledf2(APROOT,"APROOT");
      Compiledf0(APPI,"APPI");
(*4*) (*from SACPRIM. *)
      Compiledf1(IFACT,"IFACT");
      Compiledf2(DPGEN,"DPGEN");
      Compiledf0(GetSMPRM,"SMPRM");
(*5*) (*from SACCOMB. *)
      Compiledf1(IFACTL,"IFACTL");
      Compiledf2(IBCOEF,"IBCOEF");
(*6*) (*from MASF. *)
      Compiledf1(SIN,"SIN");
      Compiledf1(COS,"COS");
      Compiledf1(TAN,"TAN");
      Compiledf1(ARCTAN,"ARCTAN");
      Compiledf1(LN,"LN");
      Compiledf1(LOG,"LOG");
      Compiledf1(EXPF,"EXPF");
      Compiledf1(SQRT,"SQRT");
      Compiledf1(VIA,"VIA");
(*7*) (*from SACM. *)
      Compiledf3(MIDIF,"MIDIF");
      Compiledf3(MIEXP,"MIEXP");
      Compiledf2(MIHOM,"MIHOM");
      Compiledf2(MIINV,"MIINV");
      Compiledf2(MINEG,"MINEG");
      Compiledf3(MIPROD,"MIPROD");
      Compiledf3(MIQ,"MIQ");
      Compiledf3(MISUM,"MISUM");
(*9*) END InitExternalsA;


PROCEDURE GetSMPRM(): LIST;
(*access global variable via function. *)
BEGIN RETURN(SMPRM) END GetSMPRM;


PROCEDURE VIA(a: LIST): LIST;
(*convert to floating point and back. *)
BEGIN RETURN(RNFF(FFRN(a))) END VIA;


PROCEDURE APREAD(): LIST;
(*Read ap floating point using RNDRD. *)
BEGIN RETURN(APFRN(RNDRD())) END APREAD;


END MASLOADA.



(* -EOF- *)
