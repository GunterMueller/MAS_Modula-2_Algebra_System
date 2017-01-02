(* ----------------------------------------------------------------------------
 * $Id: MASLOADQ.mi,v 1.2 1992/10/15 16:30:38 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASLOADQ.mi,v $
 * Revision 1.2  1992/10/15  16:30:38  kredel
 * Changed rcsid variable
 *
 * Revision 1.1  1992/09/28  17:56:21  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASLOADQ;

(* MAS Load Implementaion Module Q. *)


(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, LENGTH;

FROM MASLISPU IMPORT Declare,
                     Compiledp0, Compiledp1, Compiledp2, 
                     Compiledf0, Compiledf1, Compiledf2, Compiledf3, 
                     Compiledf4,
                     Compiledp1v2,
                     Compiledp2v2; 

FROM MASC IMPORT CNWRITE, CDWRITE, CDREAD, CNREAD, 
                 CINT, CRN, CRNP, CRE, CIM, CRAND, 
                 CCOMP, CONE, CNEG, CCON, CABS,  
                 CSUM, CDIF, CNINV, CPROD, CQ, CEXP;

FROM MASQ IMPORT QNWRITE, QDWRITE, QDREAD, QNREAD, 
                 QINT, QRN, QRN4, QRE, QIMi, QIMj, QIMk, QRAND, 
                 QCOMP, QONE, QNEG, QCON, QABS,  
                 QSUM, QDIF, QINV, QPROD, QQ, QEXP;

FROM MASO IMPORT ONWRITE, ODWRITE, ODREAD, ONREAD, 
                 OINT, ORN, ORNP, ORE, OIM, ORAND, 
                 OCOMP, OONE, ONEG, OCON, OABS,  
                 OSUM, ODIF, ONINV, OPROD, OQ, OEXP;

FROM MASFF IMPORT FFWRITE, FFREAD, FFFINT, FFHOM, FFRAND, 
                  FFCOMP, FFONE, FFNEG,   
                  FFSUM, FFDIF, FFINV, FFPROD, FFQ, FFEXP;
(*
FROM SACMUFAC IMPORT MUPFBL; 
*)

CONST rcsidi = "$Id: MASLOADQ.mi,v 1.2 1992/10/15 16:30:38 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";


PROCEDURE InitExternalsQ;
(*Initialize external compiled arithmetic Q procedures. *)
BEGIN 
(*1*) (*from MASC. *)
      Compiledp2(CDWRITE,"CDWRITE");
      Compiledf0(CDREAD,"CDREAD");
      Compiledp1(CNWRITE,"CNWRITE");
      Compiledf0(CNREAD,"CNREAD");
      Compiledf1(CINT,"CINT");
      Compiledf1(CRN,"CRN");
      Compiledf2(CRNP,"CRNP");
      Compiledf1(CRE,"CRE");
      Compiledf1(CIM,"CIM");
      Compiledf1(CRAND,"CRAND");
      Compiledf2(CCOMP,"CCOMP");
      Compiledf1(CONE,"CONE");
      Compiledf1(CNEG,"CNEG");
      Compiledf1(CCON,"CCON");
      Compiledf1(CABS,"CABS");
      Compiledf2(CSUM,"CSUM");
      Compiledf2(CDIF,"CDIF");
      Compiledf1(CNINV,"CNINV");
      Compiledf2(CPROD,"CPROD");
      Compiledf2(CQ,"CQ");
      Compiledf2(CEXP,"CEXP"); 
(*2*) (*from MASQ. *)
      Compiledp2(QDWRITE,"QDWRITE");
      Compiledf0(QDREAD,"QDREAD");
      Compiledp1(QNWRITE,"QNWRITE");
      Compiledf0(QNREAD,"QNREAD");
      Compiledf1(QINT,"QINT");
      Compiledf1(QRN,"QRN");
      Compiledf4(QRN4,"QRN4");
      Compiledf1(QRE,"QRE");
      Compiledf1(QIMi,"QIMi");
      Compiledf1(QIMj,"QIMj");
      Compiledf1(QIMk,"QIMk");
      Compiledf1(QRAND,"QRAND");
      Compiledf2(QCOMP,"QCOMP");
      Compiledf1(QONE,"QONE");
      Compiledf1(QNEG,"QNEG");
      Compiledf1(QCON,"QCON");
      Compiledf1(QABS,"QABS");
      Compiledf2(QSUM,"QSUM");
      Compiledf2(QDIF,"QDIF");
      Compiledf1(QINV,"QINV");
      Compiledf2(QPROD,"QPROD");
      Compiledf2(QQ,"QQ");
      Compiledf2(QEXP,"QEXP"); 
(*3*) (*from MASO. *)
      Compiledp2(ODWRITE,"ODWRITE");
      Compiledf0(ODREAD,"ODREAD");
      Compiledp1(ONWRITE,"ONWRITE");
      Compiledf0(ONREAD,"ONREAD");
      Compiledf1(OINT,"OINT");
      Compiledf1(ORN,"ORN");
      Compiledf2(ORNP,"ORNP");
      Compiledf1(ORE,"ORE");
      Compiledf1(OIM,"OIM");
      Compiledf1(ORAND,"ORAND");
      Compiledf2(OCOMP,"OCOMP");
      Compiledf1(OONE,"OONE");
      Compiledf1(ONEG,"ONEG");
      Compiledf1(OCON,"OCON");
      Compiledf1(OABS,"OABS");
      Compiledf2(OSUM,"OSUM");
      Compiledf2(ODIF,"ODIF");
      Compiledf1(ONINV,"ONINV");
      Compiledf2(OPROD,"OPROD");
      Compiledf2(OQ,"OQ");
      Compiledf2(OEXP,"OEXP"); 
(*4*) (*from MASFF. *)
      Compiledp2(FFWRITE,"FFWRITE");
      Compiledf1(FFREAD,"FFREAD");
      Compiledf3(FFFINT,"FFFINT");
      Compiledf3(FFHOM,"FFHOM");
      Compiledf3(FFRAND,"FFRAND");
      Compiledf2(FFCOMP,"FFCOMP");
      Compiledf1(FFONE,"FFONE");
      Compiledf3(FFNEG,"FFNEG");
      Compiledf4(FFSUM,"FFSUM");
      Compiledf4(FFDIF,"FFDIF");
      Compiledf3(FFINV,"FFINV");
      Compiledf4(FFPROD,"FFPROD");
      Compiledf4(FFQ,"FFQ");
      Compiledf4(FFEXP,"FFEXP"); 
      (* Compiledf2(MUPFBL,"MUPFBL");  --- test --- *)
(*9*) END InitExternalsQ;


END MASLOADQ.



(* -EOF- *)
