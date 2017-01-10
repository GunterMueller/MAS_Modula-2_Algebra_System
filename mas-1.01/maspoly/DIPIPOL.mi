(* ----------------------------------------------------------------------------
 * $Id: DIPIPOL.mi,v 1.3 1992/10/15 16:28:36 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPIPOL.mi,v $
 * Revision 1.3  1992/10/15  16:28:36  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:33:51  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:14:03  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DIPIPOL;

(* DIP Integer Polynomial Implementation Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT INV, LIST, SIL, BETA, ADV, 
                    SFIRST, SRED, COMP, FIRST, RED, LENGTH;

FROM SACLIST IMPORT LIST2, FIRST2, COMP2, LIST3;

FROM SACD IMPORT DRANN, DQR;

FROM SACI IMPORT IRAND;

FROM SACIPOL IMPORT IPABS, IPPROD, IPIP, IPSUM;

CONST rcsidi = "$Id: DIPIPOL.mi,v 1.3 1992/10/15 16:28:36 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE VIPIIP(RL,A,B: LIST): LIST;
(*Vector of integral polynomials with vector of integers inner product. 
A is a vector of integral polynomials in r variables, r non-negative.
B is a vector of integers. C is the inner product of A and B.*)
VAR  AL, AP, BL, BP, CL, C: LIST;
BEGIN
(*1*) (*a=0 or b=0.*) C:=0;
      IF (A = SIL) OR (B = SIL) THEN RETURN(C); END;
(*2*) (*general case.*) AP:=A; BP:=B;
      REPEAT ADV(AP, AL,AP); ADV(BP, BL,BP);
             CL:=IPIP(RL,BL,AL); C:=IPSUM(RL,C,CL); 
             UNTIL AP = SIL;
      RETURN(C);
(*5*) END VIPIIP;


PROCEDURE HIPRAN(RL,KL,QL,NL: LIST): LIST; 
(*Homogeneous integral polynomial random.  k is a positive
beta-digit. q is a rational number q1/q2 with
0 lt q1 le q2 lt beta. n is a non-negative beta-digit
r ge 0.  A is a random homogeneous integral polynomial
in r variables with homogeneous degree n. max norm of
A lt 2**k and q is the probability that any
particular term of A has a non-zero coefficient.*)
VAR  A, AL, DL, EL, J1Y, QL1, QL2, QLS, RLP, TL: LIST; 
BEGIN
(*1*) (*rl gt 1.*) 
      IF RL > 1 THEN RLP:=RL-1; A:=BETA; EL:=0; 
         WHILE EL <= NL DO J1Y:=NL-EL; AL:=HIPRAN(RLP,KL,QL,J1Y); 
               IF AL <> 0 THEN A:=COMP2(EL,AL,A); END; 
               EL:=EL+1; END; 
         IF A = SIL THEN A:=0; END; 
         RETURN(A); END; 
(*2*) (*compute qls=int(ql*beta).*) FIRST2(QL, QL1,QL2); 
      DQR(QL1,0,QL2, QLS,TL); A:=0; AL:=0; DL:=DRANN(); 
      IF DL < QLS THEN AL:=IRAND(KL); END; 
      IF AL = 0 THEN RETURN(A); END; 
(*3*) (*rl=1 or 0.*) 
      IF RL = 0 THEN A:=AL; ELSE A:=LIST2(NL,AL); END; 
      RETURN(A); 
(*6*) END HIPRAN; 


PROCEDURE IPRAN(RL,KL,QL,N: LIST): LIST; 
(*Integral polynomial random.  k is a positive beta-digit.
q is a rational number q1/q2 with 0 lt q1 le q2 lt beta.
N is a list (n sub r, ...,n sub 1) of non-negative beta-digits
r ge 0.  A is a random integral polynomial in r variables
with deg sub i of a le n sub i + 1 for 1 le i le r.
Max norm of A lt 2**k and q is the probability that any
particular term of A has a non-zero coefficient. Modified
version, original version by G. E. Collins. *)
VAR  A, AL, DL, EL, NL, NP, QL1, QL2, QLS, RLP, TL: LIST; 
BEGIN
(*1*) (*compute qls=int(ql*beta).*) FIRST2(QL, QL1,QL2); 
      DQR(QL1,0,QL2, QLS,TL); 
(*2*) (*rl=0.*) 
      IF RL = 0 THEN DL:=DRANN(); 
         IF DL < QLS THEN A:=IRAND(KL); ELSE A:=0; END; 
         RETURN(A); END; 
(*3*) (*rl gt 0.*) RLP:=RL-1; ADV(N, NL,NP); A:=BETA; EL:=0; 
      WHILE EL <= NL DO
            IF RLP = 0 THEN DL:=DRANN(); 
               IF DL < QLS THEN AL:=IRAND(KL); ELSE AL:=0; END; 
               ELSE AL:=IPRAN(RLP,KL,QL,NP); END; 
            IF AL <> 0 THEN A:=COMP2(EL,AL,A); END; 
            EL:=EL+1; END; 
      IF A = SIL THEN A:=0; END; 
      RETURN(A); 
(*6*) END IPRAN; 


END DIPIPOL.


(* -EOF- *)
