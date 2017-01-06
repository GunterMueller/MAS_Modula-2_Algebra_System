(* ----------------------------------------------------------------------------
 * $Id: MASBIOSU.mi,v 1.3 1992/10/15 16:24:56 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASBIOSU.mi,v $
 * Revision 1.3  1992/10/15  16:24:56  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:31:52  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:10:30  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASBIOSU;

(* MAS BIOS Utility Implementation Module. *)



(* Import lists and declarations. *)

FROM MASELEM IMPORT GAMMAINT;

FROM MASSTOR IMPORT SIL, ADV, LIST;

FROM MASBIOS IMPORT LISTS, CWRITE, SWRITE,
                    SIUNIT, SOUNIT, CUNIT, SLIST;

(*FROM MASmtc*) IMPORT MASmtc; (*EDIT, DOS*)

FROM SACLIST IMPORT CCONC;

(*FROM Strings IMPORT tString;*)

CONST rcsidi = "$Id: MASBIOSU.mi,v 1.3 1992/10/15 16:24:56 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



(* Procedure declarations. *)

PROCEDURE INP(A: LIST): LIST;
(*Input. Set input unit to stream A, A is an SAC-2 character list. *)
VAR   S: ARRAY [0..80] OF CHAR;
BEGIN
(*1*) (*convert to string and set *) 
      SLIST(A,S); RETURN(SIUNIT(S)); 
(*3*) END INP;


PROCEDURE OUT(A: LIST): LIST;
(*Output. Set output unit to stream A, A is an SAC-2 character list. *)
VAR   S: ARRAY [0..80] OF CHAR;
BEGIN
(*1*) (*convert to string and set *) 
      SLIST(A,S); RETURN(SOUNIT(S)); 
(*3*) END OUT;


PROCEDURE SHUT(A: LIST): LIST;
(*Shut. Close stream A, A is an SAC-2 character list. *)
VAR   S: ARRAY [0..80] OF CHAR;
BEGIN
(*1*) (*convert to string and close *) 
      SLIST(A,S); RETURN(CUNIT(S)); 
(*3*) END SHUT;


PROCEDURE EDIT(A: LIST): LIST;
(*Edit. Call editor for file A, A is an SAC-2 character list. *)
VAR S: ARRAY [0..80] OF CHAR;
    i: GAMMAINT;
BEGIN
(*1*) (*convert to string and set *) 
      SLIST(A,S); i:=GAMMAINT(MASmtc.EDIT(S));
      RETURN(i); 
(*3*) END EDIT;


PROCEDURE DOS(A: LIST): LIST;
(*DOS. Call DOS program with parameters. A is an SAC-2 character list. *)
VAR   S: ARRAY [0..80] OF CHAR;
      i: GAMMAINT;
      B: LIST;
BEGIN
(*0*) (*add blank *) B:=LISTS(" "); 
      B:=CCONC(A,B); 
(*1*) (*convert to string and call *) 
      SLIST(B,S); i:=GAMMAINT(MASmtc.DOS(S));
      RETURN(i); 
(*3*) END DOS;


PROCEDURE CLTIS(A: LIST);
(*Character list to input stream. A is an SAC-2 character list. *)
VAR   AP, k, b: LIST;
BEGIN
(*1*) k:=CUNIT("RAM:internal");  
      k:=SOUNIT("RAM:internal");
(*2*) (*write out characters. *) AP:=A;
      WHILE AP <> SIL DO ADV(AP,b,AP); CWRITE(b) END;
(*3*) k:=CUNIT("RAM:internal");  
      k:=SIUNIT("RAM:internal"); 
(*3*) END CLTIS;
                       

END MASBIOSU.








(* -EOF- *)
