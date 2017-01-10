(* ----------------------------------------------------------------------------
 * $Id: MASLOADC.mi,v 1.3 1992/10/15 16:30:34 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASLOADC.mi,v $
 * Revision 1.3  1992/10/15  16:30:34  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:32:51  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:12:11  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASLOADC;

(* MAS Load Implementation Module C. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT ADV, COMP, FIRST, RED, LIST, SIL, LIST1, INV, LENGTH;

FROM MASLISPU IMPORT Declare,
                     Compiledp0, Compiledp1, Compiledp2, 
                     Compiledf0, Compiledf1, Compiledf2, Compiledf3,
                     Compiledp1v2,
                     Compiledp2v2; 

FROM MASBIOS IMPORT BKSP, SWRITE, BLINES, MASORD, CREADB;

FROM SACLIST IMPORT CCONC, THIRD;

FROM SACPOL IMPORT VLREAD, VLWRIT;

FROM DIPC IMPORT VALIS, EVORD, INVLEX, IGRLEX,
                    PLFDIL, DILFPL;

FROM DIPI IMPORT DIILFR, DIILWR;

FROM DIPRN IMPORT DIRLRD, DIRLWR, DIRPPR, DIRPSM, DIRPNG;

FROM MASNC IMPORT DINPPR, DINLRD;

FROM MASNCGB IMPORT DINLNF, DINLIS, DINLSP, 
                    DINLGB, DINCGB;

FROM MASNCC IMPORT EVLGTD, EVLGIL, DILFEL, 
                   DINCCO, DINCCPpre, DINCCP,
                   DINLMPG, DINLMPL;

CONST rcsidi = "$Id: MASLOADC.mi,v 1.3 1992/10/15 16:30:34 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE InitExternalsC;
(*Initialize external compiled non-commutative polynomial procedures. *)
BEGIN 
(*6*) (*from noncom polynomial system. *)
      Compiledf1(npread,"NPREAD");
      Compiledf0(ndread,"NDREAD");
      Compiledf1(npreadd,"NPREADD");
      Compiledf2(DINLRD,"DINLRD");
      Compiledf3(DINPPR,"NPPROD");
      Compiledf3(DINLSP,"LSPOL");
      Compiledf3(DINLNF,"LNFORM");
      Compiledf2(DINLIS,"LIRRSET");
      Compiledf3(DINLGB,"LGBASE");
      Compiledf3(DINCGB,"TSGBASE");
(*7*) (*from noncom commutator system. *)
      Compiledf3(EVLGTD,"EVLGTD");
      Compiledf1(EVLGIL,"EVLGIL");
      Compiledf3(DINCCO,"DINCCO");
      Compiledf2(DINCCP,"DINCCP");
      Compiledf2(DILFEL,"DILFEL");
      Compiledf2(DINCCPpre,"CenterPol");
      Compiledf3(DINLMPG,"DINLMPG");
      Compiledf2(DINLMPL,"DINLMPL");
(*9*) END InitExternalsC;



PROCEDURE ndread(): LIST;
(*read noncom polynom descriptor. *)
VAR   P, V, X: LIST;
BEGIN P:=SIL;
(*1*) X:=pdread(); V:=FIRST(X);
(*3*) REPEAT P:=DIRLRD(V); BLINES(0);
             UNTIL P <> SIL;
(*4*) P:=LIST1(P); P:=CCONC(X,P);
      RETURN(P)
(*9*) END ndread;


PROCEDURE npread(T: LIST): LIST;
(*read noncom polynomial list, not including variable list and term order. *)
VAR P, V, E: LIST;
BEGIN P:=SIL; V:=VALIS;
(*1*) REPEAT SWRITE("Enter noncom polynomial list: "); BLINES(0); 
             P:=DINLRD(V,T); BLINES(1);
             UNTIL P <> SIL;
      RETURN(P)
(*3*) END npread;


PROCEDURE npreadd(X: LIST): LIST;
(*read noncom polynomial list, not including variable list and term order. *)
VAR   T, P, V, E: LIST;
BEGIN P:=SIL; V:=FIRST(X); T:=THIRD(X);
(*1*) REPEAT BLINES(0); 
             P:=DINLRD(V,T); BLINES(1);
             UNTIL P <> SIL;
      RETURN(P)
(*3*) END npreadd;


PROCEDURE pdread(): LIST;
(*read polynomial descriptor, i.e. variable list and term order. *)
VAR   P, T, V, E, Q, r, X: LIST;
BEGIN P:=SIL;
(*1*) REPEAT V:=VLREAD(); BLINES(1);
             UNTIL V <> SIL;
      VALIS:=V;
(*2*) REPEAT E:=CREADB(); BLINES(1);
             UNTIL    (E = MASORD("(")) 
                   OR (E = MASORD("L")) 
                   OR (E = MASORD("G"));
      IF E = MASORD("L") THEN EVORD:=INVLEX END;
      IF E = MASORD("G") THEN EVORD:=IGRLEX END;
      IF E = MASORD("(") THEN BKSP; T:=LIST1(LIST1(MASORD("T"))); 
         X:=EVORD; EVORD:=INVLEX;
         P:=DIRLRD(T); 
         P:=DIILFR(P); (* falsch muss erst auf hauptnenner *)
         PLFDIL(P, r,Q); 
         EVORD:=X;
         IF LENGTH(Q) = LENGTH(V) THEN EVORD:=INV(Q)
            ELSE SWRITE("Wrong number of polynomials."); BLINES(0) END
         END;
       RETURN(COMP(V,LIST1(EVORD)))
(*3*) END pdread;


END MASLOADC.



(* -EOF- *)
