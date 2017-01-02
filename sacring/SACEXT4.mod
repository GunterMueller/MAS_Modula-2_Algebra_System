(* ----------------------------------------------------------------------------
 * $Id: SACEXT4.mi,v 1.3 1992/10/15 16:28:57 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACEXT4.mi,v $
 * Revision 1.3  1992/10/15  16:28:57  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:34:50  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:15:58  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACEXT4;

(* SAC Extensions 4 Implementation Module. *)



(* Import lists and declarations. *) 

FROM MASSTOR IMPORT LIST, SIL, BETA,
                    LIST1, INV, COMP, SRED, ADV, FIRST, RED;

FROM SACLIST IMPORT CINV, CONC, LIST2, ADV2, COMP2, 
                    COMP4, FIRST2, LAST;

FROM SACI IMPORT IQ;

FROM SACRN IMPORT RNINT, RNPROD, RNINV;

FROM SACCOMB IMPORT LPERM;

FROM SACPOL IMPORT PLBCF, PDPV, PDEG, PMON, PLDCF;

FROM SACIPOL IMPORT IPQ, IPIQ, IPGSUB; 

FROM SACRPOL IMPORT RPRNP, RPFIP;

FROM SACPGCD IMPORT IPSCPP;

CONST rcsidi = "$Id: SACEXT4.mi,v 1.3 1992/10/15 16:28:57 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE IPINT(RL,A,BL: LIST): LIST; 
(*Integral polynomial integration.  A is a non-zero integral
polynomial in r variables, r ge 1, such that the integral of a with
respect to its main variable is an integral polynomial.  b is an
integral polynomial in r-1 variables.  B eq B(x sub 1 , ..., x sub r )
is the integral of a with respect to its main variable, such that
B(x sub 1 , ..., x sub r-1 ,0) eq b.*)
VAR  AL, AP, B, CL, EL, RLP: LIST; 
BEGIN
(*1*) AP:=A; B:=BETA; RLP:=RL-1; 
      REPEAT ADV2(AP, EL,AL,AP); EL:=EL+1; 
             IF RL = 1 THEN CL:=IQ(AL,EL); ELSE
                CL:=IPIQ(RLP,AL,EL); END; 
             B:=COMP2(CL,EL,B); 
             UNTIL (AP = SIL); 
      IF BL <> 0 THEN B:=COMP2(BL,0,B); END; 
      B:=INV(B); RETURN(B); 
(*4*) END IPINT; 


PROCEDURE IUPIHT(A,NL: LIST): LIST; 
(*Integral univariate polynomial integer homothetic transformation.
A is a non-zero univariate integral polynomial.  n is a non-zero
integer.  B(x) is the primitive part of A(nx).*)
VAR  B, CL, J1Y, M, SL: LIST; 
BEGIN
(*1*) M:=PMON(NL,1); J1Y:=LIST1(M); B:=IPGSUB(1,A,1,J1Y); 
      IPSCPP(1,B,SL,CL,B); RETURN(B); 
(*4*) END IUPIHT; 


PROCEDURE PCONST(RL,A: LIST): LIST; 
(*Polynomial constant.  A(x sub 1 ,  ..., x sub r ) is a polynomial
in r variables, r ge 1.  b eq 1 if a is a constant polynomial,
otherwise b eq 0.*)
VAR  AP, BL, IL: LIST; 
BEGIN
(*1*) (*a eq 0.*) BL:=1; 
      IF A = 0 THEN RETURN(BL); END; 
(*2*) (*a ne 0.*) AP:=A; 
      FOR IL:=1 TO RL DO
          IF PDEG(AP) <> 0 THEN BL:=0; RETURN(BL); ELSE
             AP:=PLDCF(AP); END; 
          END; 
      RETURN(BL); 
(*5*) END PCONST; 


PROCEDURE PSDSV(RL,A,IL,NL: LIST): LIST; 
(*Polynomial special decomposition, specified variable.  A is a
polynomial in r variables.  1 le i le r and n is a beta-integer such
that each exponent of x sub i occurring in a is divisible by n.
B is A with each exponent e of x sub i replaced by e/n.*)
VAR  AL, AP, B, BL, EL, FL, RLP: LIST; 
BEGIN
(*1*) (*a eq 0 or n eq 0.*) 
      IF (A = 0) OR (NL = 0) THEN B:=A; RETURN(B); END; 
(*2*) (*general case.*) AP:=A; B:=BETA; RLP:=RL-1; 
      REPEAT ADV2(AP, EL,AL,AP); 
             IF IL = RL THEN BL:=AL; FL:=EL DIV NL; ELSE
                BL:=PDPV(RLP,AL,IL,NL); FL:=EL; END; 
             B:=COMP2(BL,FL,B); 
             UNTIL (AP = SIL); 
      B:=INV(B); RETURN(B); 
(*5*) END PSDSV; 


PROCEDURE PUNT(RL,A: LIST): LIST; 
(*Polynomial univariate test.  A eq A(x sub 1 , ..., x sub r ) is a
polynomial in r variables, r ge 1.  b eq 2 if A has degree zero in all
variables.  b eq 1 if A has degree zero in x sub 2 , ..., x sub r, but
positive degree in x sub 1.  otherwise b eq 0.*)
VAR  AP, BL, IL: LIST; 
BEGIN
(*1*) (*a eq 0.*) BL:=2; 
      IF A = 0 THEN RETURN(BL); END; 
(*2*) (*a ne 0.*) AP:=A; 
      FOR IL:=1 TO RL-1 DO
          IF PDEG(AP) <> 0 THEN BL:=0; RETURN(BL); ELSE
             AP:=PLDCF(AP); END; 
          END; 
      IF PDEG(AP) > 0 THEN BL:=1; END; 
      RETURN(BL); 
(*5*) END PUNT; 


PROCEDURE RPDMV(RL,A: LIST): LIST; 
(*Rational polynomial derivative, main variable.  A is a rational
polynomial in r variables.  B is the derivative of A with respect to
its main variable.*)
VAR  AL, AP, B, BL, EL, ELP, J1Y, RLP: LIST; 
BEGIN
(*1*) (*a=0.*) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
(*2*) (*general case.*) AP:=A; RLP:=RL-1; B:=BETA; 
      REPEAT ADV2(AP, EL,AL,AP); 
             IF RLP = 0 THEN J1Y:=RNINT(EL); BL:=RNPROD(J1Y,AL); 
                ELSE J1Y:=RNINT(EL); BL:=RPRNP(RLP,J1Y,AL); END; 
             ELP:=EL-1; 
             IF EL <> 0 THEN B:=COMP2(BL,ELP,B); END; 
             UNTIL (AP = SIL); 
      B:=INV(B); 
      IF B = SIL THEN B:=0; END; 
      RETURN(B); 
(*5*) END RPDMV; 


PROCEDURE RPMAIP(RL,A: LIST): LIST; 
(*Rational polynomial monic associate of integral polynomial.
A is an integral polynomial in r variables, r ge 1.  If A eq 0
then B eq 0.  if A ne 0, let the integer a be the leading base
coefficient of A.  Then B eq (1/a) A, a monic rational polynomial.*)
VAR  AL, B: LIST; 
BEGIN
(*1*) (*a eq 0.*) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
(*2*) (*a ne 0.*) B:=RPFIP(RL,A); AL:=PLBCF(RL,B); AL:=RNINV(AL); 
      B:=RPRNP(RL,AL,B); RETURN(B); 
(*5*) END RPMAIP; 


(* unused code, since the representation of distributive 
polynomials in DIP is different.

FROM SACPOL IMPORT DIPFP, PFDIP;

PROCEDURE DIPINS(AL,DL,A: LIST;  VAR TL,B: LIST); 
(*Distributed polynomial, insert term.  A is either a distributed
polynomial in r variables, r ge 0, or the null list.  a is the
coefficient and d the degree vector of a term in r variables
to be inserted.  If d does not already occur in A, then t eq 1 and
B is the distributive polynomial resulting from inserting the term.
If d does already occur in A, then t eq 0 and B eq A.*)
VAR  ALP, AP, BL, DLP: LIST; 
BEGIN
(*1*) (*a empty.*) TL:=1; 
      IF A = SIL THEN B:=LIST2(AL,DL); RETURN; END; 
      B:=A; 
(*2*) (*a nonempty.*) AP:=A; ADV2(AP, ALP,DLP,AP); BL:=DVCMP(DL,DLP); 
      IF BL = 0 THEN TL:=0; RETURN; END; 
      IF BL > 0 THEN B:=COMP2(AL,DL,A); RETURN; END; 
      B:=LIST2(DLP,ALP); 
      WHILE AP <> SIL DO ADV2(AP, ALP,DLP,AP); BL:=DVCMP(DL,DLP); 
            IF BL = 0 THEN B:=A; TL:=0; RETURN; END; 
            IF BL > 0 THEN B:=COMP4(DLP,ALP,DL,AL,B); B:=INV(B); 
               B:=CONC(B,AP); RETURN; END; 
            B:=COMP2(DLP,ALP,B); END; 
      B:=COMP2(DL,AL,B); B:=INV(B); RETURN; 
(*5*) END DIPINS; 


PROCEDURE DVCMP(DL1,DL2: LIST): LIST; 
(*Degree vector comparison.  d1 and d2 are degree vectors of
distributive polynomials in r variables, r ge 0.  With respect to
the inverse lexicographical ordering of degree vectors, b eq -1
if d1 lt d2, b eq 0 if d1 eq d2, and b eq 1 if d1 gt d2.*)
VAR  BL, DLP1, DLP2, EL1, EL2: LIST; 
BEGIN
(*1*) DLP1:=DL1; DLP2:=DL2; BL:=0; 
      WHILE DLP1 <> SIL DO ADV(DLP1, EL1,DLP1); ADV(DLP2, EL2,DLP2); 
            IF EL1 < EL2 THEN BL:=-1; RETURN(BL); END; 
            IF EL1 > EL2 THEN BL:=1; RETURN(BL); END; 
            END; 
      RETURN(BL); 
(*4*) END DVCMP; 


PROCEDURE PPERMV(RL,A,P: LIST): LIST; 
(*Polynomial permutation of variables.  A is a polynomial in r
variables, r ge 0.  P is a list (P sub 1 , ..., P sub r ) whose
elements are the beta-digits 1 through r.  B(x sub (P sub 1)
, ..., x sub (P sub r) ) eq A(x sub 1 , ..., x sub r ).*)
VAR  AL, AP, B, BP, DL, DLP, TL: LIST; 
BEGIN
(*1*) (*a eq 0.*) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
(*2*) (*convert a to distributive representation and reorder.*) 
      AP:=DIPFP(RL,A); BP:=BETA; 
      REPEAT ADV2(AP, AL,DL,AP); DLP:=CINV(DL); DLP:=LPERM(DLP,P); 
             DLP:=INV(DLP); DIPINS(AL,DLP,BP, TL,BP); 
             UNTIL (AP = SIL); 
(*3*) (*convert back to recursive representation.*) B:=PFDIP(RL,BP); 
      RETURN(B); 
(*6*) END PPERMV; 

end of unused code. *)


END SACEXT4.
(* -EOF- *)
