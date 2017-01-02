(* ----------------------------------------------------------------------------
 * $Id: DIPGCD.mi,v 1.3 1992/10/15 16:29:34 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPGCD.mi,v $
 * Revision 1.3  1992/10/15  16:29:34  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:34:18  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:14:52  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DIPGCD;

(* DIP GCD Implementation Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, SIL, BETA, ADV, COMP, INV;

FROM SACLIST IMPORT FIRST2, LIST2;

FROM SACIPOL IMPORT IPABS, IPPROD;

FROM SACPGCD IMPORT IPGCDC;

FROM SACPFAC IMPORT IPFAC;

FROM DIPC IMPORT PFDIP, DIPFP;    

FROM DIPI IMPORT DIIFRP;

FROM DIPRN IMPORT DIRFIP;
     
CONST rcsidi = "$Id: DIPGCD.mi,v 1.3 1992/10/15 16:29:34 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DIRFAC(P: LIST): LIST; 
(*Distributive rational polynomial factorisation.
P is a distributive rational polynomial.
PP=((e1,P1), ...,(en,Pn)), where P=P1**e1+ ... +Pn**en. *)
VAR  CL, EL, PL, PLP, PP, Q, QL, QLP, QLS, RL, SL: LIST; 
BEGIN
(*1*) (*convert to recursive integral. *) PP:=BETA; 
      IF P = 0 THEN RETURN(PP); END; 
      PL:=DIIFRP(P); PFDIP(PL, RL,PL); 
(*2*) (*factorize. *) IPFAC(RL,PL, SL,CL,Q); 
(*3*) (*convert factors to distributive rational polynomial. *) 
      WHILE Q <> SIL DO ADV(Q, QLS,Q); FIRST2(QLS, EL,QLP); 
            PLP:=DIPFP(RL,QLP); PLP:=DIRFIP(PLP); QL:=LIST2(EL,PLP); 
            PP:=COMP(QL,PP); END; 
(*4*) (*finish. *) PP:=INV(PP); 
(*7*) RETURN(PP); END DIRFAC; 


PROCEDURE IPLCM(RL,A,B: LIST): LIST; 
(*Integral polynomial least common multiple. A and B are integal
polynomials. C=LCM(A,B), a nonnegative integral polynomial.*)
VAR  AP, APP, BP, BPP, C, CP: LIST; 
BEGIN
(*1*) (*a or b eq 0.*) AP:=IPABS(RL,A); BP:=IPABS(RL,B); 
      IF AP = 0 THEN C:=BP; RETURN(C); END; 
      IF BP = 0 THEN C:=AP; RETURN(C); END; 
(*2*) (*a and b nonzero.*) IPGCDC(RL,AP,BP, CP,APP,BPP); 
      C:=IPPROD(RL,APP,BP); 
(*5*) RETURN(C); END IPLCM; 


END DIPGCD.



(* -EOF- *)
