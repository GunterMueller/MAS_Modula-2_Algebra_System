(* ----------------------------------------------------------------------------
 * $Id: MASLOADS.mi,v 1.3 1992/10/15 16:30:40 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASLOADS.mi,v $
 * Revision 1.3  1992/10/15  16:30:40  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:32:54  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:12:18  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASLOADS;

(* MAS Load Syzygy Implementation Module. *)


FROM MASSTOR IMPORT LIST;

FROM MASLISPU IMPORT Compiledp2, Compiledp3, Compiledp4, Compiledp5,
                     Compiledf2, Compiledf3, Compiledf4,
                     Compiledf5, Compiledp2v2, Compiledp2v3, Compiledf1;

FROM SYZMAIN  IMPORT SYHC, HEQ, HSEQ, IEQ, ISEQ, SYHNL,  SIC,  SINL,
                     SYTHC, SYTHNL, STIC, STINL, 
                     NLHEQ, NLHSEQ, NLIEQ, NLISEQ, OREC;

FROM SYZGB    IMPORT MGB, NLMGB;

FROM SYZHLP   IMPORT MREAD, NMREAD, PLWR, PMWR;

CONST rcsidi = "$Id: MASLOADS.mi,v 1.3 1992/10/15 16:30:40 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE InitExternalsS;
(* Tell Modula about external compiled procedures. *)
BEGIN
(*1*) (* from SYZMAIN. *)
      Compiledf3(SYHC,"SYHC");
      Compiledf3(HEQ,"HEQ");
      Compiledf3(HSEQ,"HSEQ");
      Compiledp3(SYTHC,"SYTHC");
      Compiledf4(SIC,"SIC");
      Compiledf4(IEQ,"IEQ");
      Compiledf4(ISEQ,"ISEQ");
      Compiledp4(STIC,"STIC");

      Compiledf4(SYHNL,"SYHNL");
      Compiledf4(NLHEQ,"NLHEQ");
      Compiledf4(NLHSEQ,"NLHSEQ");
      Compiledp4(SYTHNL,"SYTHNL");
      Compiledf5(SINL,"SINL");
      Compiledf5(NLIEQ,"NLIEQ");
      Compiledf5(NLISEQ,"NLISEQ");
      Compiledp5(STINL,"STINL");
      Compiledp2v3(OREC,"OREC");
(*2*) (* from SYZGB. *)
      Compiledf2(MGB,"MGB");
      Compiledp2v2(nlmgb,"nlmgb");
(*3*) (* from SYZHLP. *)
      Compiledf1(MREAD,"MREAD");
      Compiledf2(NMREAD,"NMREAD");
      Compiledp2(PLWR,"PLWR");
      Compiledp2(PMWR,"PMWR");
END InitExternalsS;


PROCEDURE nlmgb(PM, SANZ : LIST; VAR T, pm: LIST);
(* Non-Commutative Modul Groebner Base. Berechnet wird die Modul 
Groebner Basis fuer die Polynommatrix PM. Das Bit SANZ steuert die 
Anzeigeart. *)
(*Interface to avoid functions with var parameters. *) 
BEGIN
(*1*) pm:=NLMGB(PM, SANZ, T);
(*9*) END nlmgb;


END MASLOADS.




(* -EOF- *)
