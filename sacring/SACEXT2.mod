(* ----------------------------------------------------------------------------
 * $Id: SACEXT2.mi,v 1.3 1992/10/15 16:28:55 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACEXT2.mi,v $
 * Revision 1.3  1992/10/15  16:28:55  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:34:47  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:15:54  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACEXT2;

(* SAC Extensions 2 Implementation Module. *)



(* Import lists and declarations. *) 

FROM MASSTOR IMPORT LIST, SIL, BETA,
                    COMP, SRED, ADV, FIRST, RED;

FROM SACLIST IMPORT CONC, FIRST2, LAST;

FROM SACI IMPORT IDP2, IMP2, IORD2;

CONST rcsidi = "$Id: SACEXT2.mi,v 1.3 1992/10/15 16:28:55 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE RNBCR(A,B: LIST;  VAR M,N,KL: LIST); 
(*Rational number binary common representation.  A and B are binary
rational numbers.  If both A eq 0 and B eq 0, then M eq N eq K eq 0.
If A eq 0, B ne 0, then M eq 0 and N and K are the unique integers
such that B eq N cdot 2 sup k with N odd.  If B eq 0, A ne 0, then
N eq 0 and M and K are the unique integers such that A eq
M cdot 2 sup K with M odd.  If A ne 0 and B ne 0, then M,N, and K
are the unique integers such that A eq M cdot 2 sup K and
B eq N cdot 2 sup K with at least one of M and N odd.*)
VAR  A2, B2, EL1, EL2, J1Y: LIST; 
BEGIN
(*1*) (*express both A and B as odd integer times power of 2.*) 
      IF A = 0 THEN M:=0; ELSE FIRST2(A, M,A2); 
         IF A2 = 1 THEN EL1:=IORD2(M); M:=IDP2(M,EL1); ELSE
            J1Y:=IORD2(A2); EL1:=-J1Y; END; 
         END; 
      IF B = 0 THEN N:=0; EL2:=0; ELSE FIRST2(B, N,B2); 
         IF B2 = 1 THEN EL2:=IORD2(N); N:=IDP2(N,EL2); ELSE
            J1Y:=IORD2(B2); EL2:=-J1Y; END; 
         END; 
(*2*) (*obtain common power of 2.*) 
      IF A = 0 THEN KL:=EL2; RETURN; ELSE
         IF B = 0 THEN KL:=EL1; RETURN; END; 
         END; 
      IF EL1 <= EL2 THEN J1Y:=EL2-EL1; N:=IMP2(N,J1Y); KL:=EL1; 
         ELSE J1Y:=EL1-EL2; M:=IMP2(M,J1Y); KL:=EL2; END; 
      RETURN; 
(*5*) END RNBCR; 


END SACEXT2.
(* -EOF- *)
