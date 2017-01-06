(* ----------------------------------------------------------------------------
 * $Id: DIPRNPOL.mi,v 1.4 1992/10/15 16:28:38 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPRNPOL.mi,v $
 * Revision 1.4  1992/10/15  16:28:38  kredel
 * Changed rcsid variable
 *
 * Revision 1.3  1992/06/12  13:38:06  kredel
 * Added GCD and LCM for rational univariate polynomials and some others.
 *
 * Revision 1.2  1992/02/12  17:33:54  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:14:07  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DIPRNPOL;

(* DIP Rational Number Polynomial Implementation Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, SIL, FIRST, RED, ADV, INV,
                    COMP, BETA, LENGTH;

FROM MASBIOS IMPORT CWRITE, DIGIT, BKSP, BLINES, 
                    SOLINE,
                    MASORD, CREAD, CREADB, SWRITE;

FROM SACLIST IMPORT CINV, ADV2, FIRST2, CLOUT;

FROM SACI IMPORT IWRITE;

FROM SACRN IMPORT RNSIGN, RNWRIT, RNINT, RNINV;

FROM MASRN IMPORT RNDWR, RNONE;

FROM SACPOL IMPORT PDEG, PLDCF, PINV, PLBCF;

FROM SACRPOL IMPORT RPNEG, RPPROD, RPQR, RPDIF, RPRNP;

CONST rcsidi = "$Id: DIPRNPOL.mi,v 1.4 1992/10/15 16:28:38 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE RPABS(RL,A: LIST): LIST;
(*Rational polynomial absolute value.  A is a rational polynomial in
r variables.  B is the absolute value of A.*)
VAR  B, SL: LIST;
BEGIN
(*1*) SL:=RPSIGN(RL,A);
      IF SL >= 0 THEN B:=A; ELSE B:=RPNEG(RL,A); END;
      RETURN(B);
(*4*) END RPABS;


PROCEDURE RPCONST(RL,A: LIST): LIST; 
(*Rational polynomial constant.  A is a rational polynomial in r
variables.  If A is a non-zero rational number then t=1, 
otherwise t=0. *) 
VAR   IL, AL, TL: LIST;
BEGIN
(*1*) (*a=0. *) TL:=0; 
      IF A = 0 THEN RETURN(TL); END; 
(*2*) (*get lbcf. *) AL:=A; 
      FOR IL:=1 TO RL DO
          IF PDEG(AL) <> 0 THEN RETURN(TL); END; 
          AL:=PLDCF(AL); END; 
      TL:=1; 
(*5*) RETURN(TL); END RPCONST; 


PROCEDURE RPEXP(RL,A,NL: LIST): LIST;
(*Rational polynomial exponentiation.  A is a rational polynomial in
r variables, r ge 0.  n is a non-negative integer.  B=A**n.*)
VAR  B, IL: LIST;
BEGIN
(*1*) (*nl=0.*)
      IF NL = 0 THEN B:=PINV(0,RNINT(1),RL); RETURN(B); END;
(*2*) (*a=0.*)
      IF A = 0 THEN B:=0; RETURN(B); END;
(*3*) (*general case.*) B:=A;
      FOR IL:=1 TO NL-1 DO B:=RPPROD(RL,B,A); END;
      RETURN(B);
(*6*) END RPEXP;
 

PROCEDURE RPMON(RL,A: LIST): LIST;
(*Rational polynomial monic.  A is a rational polynomial in r variables.
If A is non-zero then AP is the polynomial similar to A with LBCF(AP)=1.  
If A=0 then AP=0.*)
VAR   AL, ALP, AP: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN AP:=0; RETURN(AP); END;
(*2*) (*a non-zero.*) AL:=PLBCF(RL,A); ALP:=RNINV(AL);
      AP:=RPRNP(RL,ALP,A); RETURN(AP);
(*4*) END RPMON;


PROCEDURE RPONE(RL,A: LIST): LIST; 
(*Rational polynomial one.  A is a rational polynomial in r
variables.  If A=1 then t=1, otherwise t=0. *) 
VAR   IL, AL, TL: LIST;
BEGIN
(*1*) (*a=0. *) TL:=0; 
      IF A = 0 THEN RETURN(TL); END; 
(*2*) (*get lbcf. *) AL:=A; 
      FOR IL:=1 TO RL DO
          IF PDEG(AL) <> 0 THEN RETURN(TL); END; 
          AL:=PLDCF(AL); END; 
      TL:=RNONE(AL); 
(*5*) RETURN(TL); END RPONE; 
 

PROCEDURE RPSIGN(RL,A: LIST): LIST;
(*Rational polynomial sign.  A is a rational polynomial in r
variables.  s is the sign of A.*)
VAR  J1Y, SL: LIST;
BEGIN
(*1*) J1Y:=PLBCF(RL,A); SL:=RNSIGN(J1Y); RETURN(SL);
(*4*) END RPSIGN;


PROCEDURE RPLWRS(RL,A,V,S: LIST); 
(*Rational polynomial list write.  A is a list of rational
polynomial in r variables, r ge 0.  V is a variable list for
the polynomials in A. S is a decimal flag. A is written in the
output stream in external canonical form.*)
VAR  AL, AP, LS, RS, OS: LIST; 
BEGIN
(*1*) (*format. *) BLINES(1); LS:=10; RS:=60; OS:=-1; 
      SOLINE(OS,LS,RS); BLINES(1); 
(*2*) (*write polynomials. *) AP:=A; 
      WHILE AP <> SIL DO ADV(AP, AL,AP); RPWRTS(RL,AL,V,S); 
            BLINES(2); END; 
      SOLINE(OS,LS,RS); BLINES(1); 
(*5*) RETURN; END RPLWRS; 


PROCEDURE RPWRTS(RL,A,V,S: LIST); 
(*Rational polynomial write.  A is a rational polynomial in r
variables, r ge 0.  V is a variable list for A. S is a decimal
flag. A is written in the output stream in external canonical form.*)
VAR  AL, AP, EL, IL, LL, RLP, V1, VB, VP: LIST; 
BEGIN
(*1*) (*rl=0 or a=0.*) 
      IF (RL = 0) OR (A = 0) THEN IWRITE(A); RETURN; END; 
(*2*) (*a ne 0.*) AP:=A; RLP:=RL-1; VB:=CINV(V); LL:=LENGTH(AP); 
      IF LL > 2 THEN SWRITE("("); END; 
      ADV(VB, V1,VP); VP:=INV(VP); IL:=0; 
      REPEAT ADV2(AP, EL,AL,AP); 
             IF IL <> 0 THEN
                IF RL > 1 THEN SWRITE("+"); ELSE
                   IF RNSIGN(AL) > 0 THEN SWRITE("+"); END; 
                   END; 
                END; 
             IF RLP = 0 THEN
                IF S < 0 THEN RNWRIT(AL); ELSE RNDWR(AL,S); END; 
                ELSE RPWRTS(RLP,AL,VP,S); END; 
             IF EL > 0 THEN SWRITE("*"); CLOUT(V1); 
                IF EL > 1 THEN SWRITE("*"); SWRITE("*"); 
                   IWRITE(EL); END; 
                END; 
             IL:=1; 
             UNTIL AP = SIL; 
      IF LL > 2 THEN SWRITE(")"); END; 
      RETURN; 
(*5*) END RPWRTS; 


PROCEDURE RUPEGC(A,B: LIST;  VAR C,U,V: LIST); 
(*Rational univariate polynomial extended greatest common divisor.  
A and B are rational univariate polynomials. C=gcd(A,B).  
A*U+B*V=C, and, if deg(A/C) gt 0, then deg(V) lt
deg(A/C), else deg(V)=0.  Similarly, if deg(B/C) gt 0, then deg(U) lt
deg(B/C), else deg(U)=0.  If A=0, U=0.  If B=0, V=0.*)
VAR   D, RP: LIST; 
BEGIN
(*1*) RUPHEG(A,B, C,V); 
      IF A = 0 THEN U:=0; ELSE D:=RPPROD(1,B,V); 
         D:=RPDIF(1,C,D); RPQR(1,D,A,U,RP); END; 
      RETURN; 
(*4*) END RUPEGC; 


PROCEDURE RUPGCD(A,B: LIST): LIST; 
(*Rational univariate polynomial greatest common divisor.  A and B are
rational univariate polynomials. C=gcd(A,B).*)
VAR   Q, A1, A2, A3, C, ML, NL: LIST; 
BEGIN
(*1*) (*a or b zero.*) 
      IF A = 0 THEN C:=RPMON(1,B); RETURN(C); END; 
      IF B = 0 THEN C:=RPMON(1,A); RETURN(C); END; 
(*2*) (*general case.*) ML:=PDEG(A); NL:=PDEG(B); 
      IF ML >= NL THEN A1:=A; A2:=B; ELSE A1:=B; A2:=A; END; 
      REPEAT RPQR(1,A1,A2, Q,A3); A1:=A2; A2:=A3; 
             UNTIL A2 = 0; 
      C:=RPMON(1,A1); RETURN(C); 
(*5*) END RUPGCD; 


PROCEDURE RUPHEG(A,B: LIST;  VAR C,V: LIST); 
(*Rational univariate polynomial half-extended greatest common divisor.
A and B are rational univariate polynomials.  C=gcd(A,B).  
There exists a polynomial U such that A*U+B*V=C, and, if deg(A/C) gt 0, 
then deg(V) lt deg(A/C).  If deg(A/C)=0, deg(V) is also 0.  If B=0, V=0.*)
VAR   A1, A2, A3, AL, ALP, J1Y, Q, V1, V2, V3: LIST; 
BEGIN
(*1*) (*compute remainder sequence.*) 
      V1:=0; V2:=PINV(0,RNINT(1),1); A1:=A; A2:=B; 
      WHILE A2 <> 0 DO RPQR(1,A1,A2, Q,A3); 
            J1Y:=RPPROD(1,Q,V2); V3:=RPDIF(1,V1,J1Y); A1:=A2; 
            A2:=A3; V1:=V2; V2:=V3; END; 
(*2*) (*adjust ldcf.*) 
      IF A1 = 0 THEN C:=0; V:=0; RETURN; END; 
      AL:=PLDCF(A1); ALP:=RNINV(AL); C:=RPRNP(1,ALP,A1); 
      V:=RPRNP(1,ALP,V1); RETURN; 
(*5*) END RUPHEG; 


PROCEDURE RUPLCM(A,B: LIST): LIST; 
(*Rational univariate polynomial least common multiple. A and B are 
rational univariate polynomials. C=LCM(A,B), a nonnegative 
rational univariate polynomial.*)
VAR   AP, APP, BP, N, C, CP: LIST; 
BEGIN
(*1*) (*a or b eq 0.*) AP:=RPABS(1,A); BP:=RPABS(1,B); 
      IF AP = 0 THEN C:=BP; RETURN(C); END; 
      IF BP = 0 THEN C:=AP; RETURN(C); END; 
(*2*) (*a and b nonzero.*) CP:=RUPGCD(AP,BP); 
      RPQR(1,AP,CP, APP, N); C:=RPPROD(1,APP,BP); 
(*5*) RETURN(C); END RUPLCM; 



END DIPRNPOL.


(* -EOF- *)
