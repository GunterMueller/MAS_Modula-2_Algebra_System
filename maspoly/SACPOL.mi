(* ----------------------------------------------------------------------------
 * $Id: SACPOL.mi,v 1.3 1992/10/15 16:28:43 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACPOL.mi,v $
 * Revision 1.3  1992/10/15  16:28:43  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:34:03  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:14:18  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACPOL;

(*SAC Polynomial System Implementation Module. *)


(* Import lists and declarations. *)

FROM MASELEM IMPORT MASMIN, MASMAX;


FROM MASSTOR IMPORT LIST, SIL, BETA, LISTVAR, 
                    FIRST, RED, COMP, INV, ADV, LIST1;


FROM SACLIST IMPORT LIST2, COMP2, ADV2, 
                    CLOUT, CINV, RED2, SECOND, EQUAL;


FROM MASBIOS IMPORT CREAD, CREADB, CWRITE, 
                    DIBUFF, LETTER, DIGIT, 
                    MASORD, BKSP, BLINES, SWRITE;


FROM SACPRIM IMPORT DPGEN;

CONST rcsidi = "$Id: SACPOL.mi,v 1.3 1992/10/15 16:28:43 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE BEGIN3();
(*Begin 3.  Begin3 calls Begin2, then creates a list of primes
just less than beta which is assigned to the global variable PRIME.*)
BEGIN
(*1*) LISTVAR(PRIME); PRIME:=DPGEN(BETA-1000,500); RETURN;
(*4*) END BEGIN3;


PROCEDURE PBIN(AL1,EL1,AL2,EL2: LIST): LIST;
(*Polynomial binomial.  a1 and a2 are elements of a coefficient ring
R.  e1 and e2 are non-negative beta-integers e1 gt e2.  A is the
polynomial A(x)=a1*x**e1+a2*x**e2, a univariate polynomial
over R.*)
VAR  A: LIST;
BEGIN
(*1*) A:=BETA;
      IF AL2 <> 0 THEN A:=LIST2(EL2,AL2); END;
      IF AL1 <> 0 THEN A:=COMP2(EL1,AL1,A); END;
      IF A = SIL THEN A:=0; END;
      RETURN(A);
(*4*) END PBIN;


PROCEDURE PCL(A: LIST): LIST;
(*Polynomial coefficient list.  A is a non-zero polynomial.  L is the
list (a(n),a(n-1), ...,a(0)) where n=DEG(A) and A(x)=a(n)*x**n+
a(n-1)*x**(n-1)+ ...+a(0).*)
VAR  AL, AP, EL, L, ML, NL: LIST;
BEGIN
(*1*) AP:=A; NL:=FIRST(AP); L:=BETA;
      FOR ML:=NL TO 0 BY -1 DO
          IF AP = SIL THEN EL:=-1; ELSE EL:=FIRST(AP); END;
          IF EL = ML THEN ADV2(AP, EL,AL,AP); ELSE AL:=0; END;
          L:=COMP(AL,L); END;
      L:=INV(L); RETURN(L);
(*4*) END PCL;


PROCEDURE PDBORD(A: LIST): LIST;
(*Polynomial divided by order.  A is a non-zero polynomial.  B(x)=
A(x)/x**k where k is the order of A.*)
VAR  AL, AP, B, EL, KL: LIST;
BEGIN
(*1*) KL:=PORD(A);
      IF KL = 0 THEN B:=A; ELSE B:=BETA; AP:=A;
         REPEAT ADV2(AP, EL,AL,AP); EL:=EL-KL; B:=COMP2(AL,EL,B);
                UNTIL AP = SIL;
         B:=INV(B); END;
      RETURN(B);
(*4*) END PDBORD;


PROCEDURE PDEG(A: LIST): LIST;
(*Polynomial degree.  A is a polynomial.  n is the degree of A.*)
VAR  NL: LIST;
BEGIN
(*1*) IF A = 0 THEN NL:=0; ELSE NL:=FIRST(A); END;
      RETURN(NL);
(*4*) END PDEG;


PROCEDURE PDEGSV(RL,A,IL: LIST): LIST;
(*Polynomial degree, specified variable.  A is a polynomial in r
variables, r ge 1.  1 le i le r.  n is the degree of A in the i-th
variable.*)
VAR  AL, AP, EL, NL, NL1, RLP: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN NL:=0; RETURN(NL); END;
(*2*) (*il=rl.*)
      IF IL = RL THEN NL:=PDEG(A); RETURN(NL); END;
(*3*) (*general case.*) NL:=0; AP:=A; RLP:=RL-1;
      REPEAT ADV2(AP, EL,AL,AP); NL1:=PDEGSV(RLP,AL,IL);
             NL:=MASMAX(NL,NL1);
             UNTIL AP = SIL;
      RETURN(NL);
(*6*) END PDEGSV;


PROCEDURE PDEGV(RL,A: LIST): LIST;
(*Polynomial degree vector.  A is a polynomial A(x(1), ...,x(r)) in
r variables.  V is the list (v(r), ...,v(1)) where v(i) is the
degree of a in x(i).*)
VAR  A1, AP, IL, NL, RLP, V, V1: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN V:=BETA;
         FOR IL:=1 TO RL DO V:=COMP(0,V); END;
         RETURN(V); END;
(*2*) (*rl=1.*) NL:=PDEG(A);
      IF RL = 1 THEN V:=LIST1(NL); RETURN(V); END;
(*3*) (*rl gt 1.*) RLP:=RL-1; A1:=PLDCF(A); V:=PDEGV(RLP,A1);
      AP:=PRED(A);
      WHILE AP <> 0 DO A1:=PLDCF(AP); V1:=PDEGV(RLP,A1);
            V:=VMAX(V,V1); AP:=PRED(AP); END;
      V:=COMP(NL,V); RETURN(V);
(*6*) END PDEGV;


PROCEDURE PDPV(RL,A,IL,NL: LIST): LIST;
(*Polynomial division by power of variable.  A is a polynomial in
r variables.  1 le i le r and n is a beta-integer such that
x sub i sup n divides A.  B eq A/x sub i sup n.*)
VAR  AL, AP, B, BL, EL, FL, RLP: LIST;
BEGIN
(*1*) (*a eq 0 or n eq 0.*)
      IF (A = 0) OR (NL = 0) THEN B:=A; RETURN(B); END;
(*2*) (*general case.*) AP:=A; B:=BETA; RLP:=RL-1;
      REPEAT ADV2(AP, EL,AL,AP);
             IF IL = RL THEN BL:=AL; FL:=EL-NL; ELSE
                BL:=PDPV(RLP,AL,IL,NL); FL:=EL; END;
             B:=COMP2(BL,FL,B);
             UNTIL AP = SIL;
      B:=INV(B); RETURN(B);
(*5*) END PDPV;


PROCEDURE PFDP(RL,A: LIST): LIST;
(*Polynomial from dense polynomial.  A is a dense polynomial in
r variables, r ge 0.  B is the result of converting A to recursive
polynomial representation.*)
VAR  AP, B, BL, NL, RLP: LIST;
BEGIN
(*1*) IF (A = 0) OR (RL = 0) THEN B:=A; RETURN(B); END;
      ADV(A, NL,AP); B:=BETA; RLP:=RL-1;
      REPEAT ADV(AP, BL,AP);
             IF BL <> 0 THEN
                IF RLP <> 0 THEN BL:=PFDP(RLP,BL); END;
                B:=COMP2(BL,NL,B); END;
             NL:=NL-1;
             UNTIL AP = SIL;
      B:=INV(B); RETURN(B);
(*4*) END PFDP;


PROCEDURE PINV(RL,A,KL: LIST): LIST;
(*Polynomial introduction of new variables.  A is a polynomial in r
variables, r ge 0.  k ge 0.  B(y(1), ...,y(k),x(1), ...,x(r))
=A(x(1), ...,x(r)).*)
VAR  A1, AP, B, B1, EL1, IL, RLP: LIST;
BEGIN
(*1*) (*a=0 or kl=0.*)
      IF (A = 0) OR (KL = 0) THEN B:=A; RETURN(B); END;
(*2*) (*rl=0.*)
      IF RL = 0 THEN B:=A;
         FOR IL:=1 TO KL DO B:=LIST2(0,B); END;
         RETURN(B); END;
(*3*) (*rl gt 0.*) RLP:=RL-1; AP:=A; B:=BETA;
      REPEAT ADV2(AP, EL1,A1,AP); B1:=PINV(RLP,A1,KL);
             B:=COMP2(B1,EL1,B);
             UNTIL AP = SIL;
      B:=INV(B); RETURN(B);
(*6*) END PINV;


PROCEDURE PLBCF(RL,A: LIST): LIST;
(*Polynomial leading base coefficient.  A is a polynomial in r
variables.  a is the leading base coefficient of A.*)
VAR  AL, IL: LIST;
BEGIN
(*1*) IF A = 0 THEN AL:=0; ELSE AL:=A;
         FOR IL:=1 TO RL DO AL:=PLDCF(AL); END;
         END;
      RETURN(AL);
(*4*) END PLBCF;


PROCEDURE PLDCF(A: LIST): LIST;
(*Polynomial leading coefficient.  A is a polynomial.  a is the
leading coefficient of A.*)
VAR  AL: LIST;
BEGIN
(*1*) IF A = 0 THEN AL:=0; ELSE AL:=SECOND(A); END;
      RETURN(AL);
(*4*) END PLDCF;


PROCEDURE PMDEG(A: LIST): LIST;
(*Polynomial modified degree.  A is a polynomial.  If A=0 then n=-1
and otherwise n=DEG(A).*)
VAR  NL: LIST;
BEGIN
(*1*) IF A = 0 THEN NL:=-1; ELSE NL:=FIRST(A); END;
      RETURN(NL);
(*4*) END PMDEG;


PROCEDURE PMON(AL,EL: LIST): LIST;
(*Polynomial monomial.  a is an element of a coefficient ring R.
e is a non-negative beta-integer.  A is the polynomial
A(x)=a*x**e, a univariate polynomial over R.*)
VAR  A: LIST;
BEGIN
(*1*) IF AL = 0 THEN A:=0; ELSE A:=LIST2(EL,AL); END;
      RETURN(A);
(*4*) END PMON;


PROCEDURE PMPMV(A,KL: LIST): LIST;
(*Polynomial multiplication by power of main variable.  A is a
polynomial in r variables, r ge 1.  k is a non-negative integer.
B(x sub 1 , ..., x sub r ) eq A(x sub 1 , ..., x sub r ) *
x sub r sup k .*)
VAR  AL, AP, B, EL, J1Y: LIST;
BEGIN
(*1*) (*a eq 0 or k eq 0.*)
      IF (A = 0) OR (KL = 0) THEN B:=A; RETURN(B); END;
(*2*) (*general case.*) B:=BETA; AP:=A;
      REPEAT ADV2(AP, EL,AL,AP); J1Y:=EL+KL; B:=COMP2(AL,J1Y,B);
             UNTIL AP = SIL;
      B:=INV(B); RETURN(B);
(*5*) END PMPMV;


PROCEDURE PORD(A: LIST): LIST;
(*Polynomial order.  A is a non-zero polynomial.  k is the order of A.
that is, if A(x)=a(n)*x**n+ ...+a(0), then k is the smallest
integer such that a(k) ne 0.*)
VAR  AP, KL: LIST;
BEGIN
(*1*) AP:=A;
      REPEAT ADV(AP, KL,AP); AP:=RED(AP);
             UNTIL AP = SIL;
      RETURN(KL);
(*4*) END PORD;


PROCEDURE PRED(A: LIST): LIST;
(*Polynomial reductum.  A is a polynomial.  B is the reductum of A.*)
VAR  B: LIST;
BEGIN
(*1*) IF A = 0 THEN B:=0; ELSE B:=RED2(A);
         IF B = SIL THEN B:=0; END;
         END;
      RETURN(B);
(*4*) END PRED;


PROCEDURE PRT(A: LIST): LIST;
(*Polynomial reciprocal transformation.  A is a non-zero polynomial.
let n=DEG(A).  Then B(x)=x**n*A(1/x), where x is the main
variable of A.*)
VAR  AL, AP, B, EL, NL: LIST;
BEGIN
(*1*) NL:=FIRST(A); AP:=A; B:=BETA;
      REPEAT ADV2(AP, EL,AL,AP); EL:=NL-EL; B:=COMP2(EL,AL,B);
             UNTIL AP = SIL;
      RETURN(B);
(*4*) END PRT;


PROCEDURE PTBCF(RL,A: LIST): LIST;
(*Polynomial trailing base coefficient.  A is an r-variate polynomial,
r ge 0.  a=trailing base coefficient of A.*)
VAR  AL, AS, BL, EL, RLP: LIST;
BEGIN
(*1*) (*rl=0 or a=0.*)
      IF (RL = 0) OR (A = 0) THEN AL:=A; RETURN(AL); END;
(*2*) (*general case.*) RLP:=RL-1; AS:=CINV(A); ADV2(AS, BL,EL,AS);
      IF EL = 0 THEN AL:=PTBCF(RLP,BL); ELSE AL:=0; END;
      RETURN(AL);
(*5*) END PTBCF;


PROCEDURE PUFP(RL,A: LIST): LIST;
(*Polynomial, univariate, from polynomial.  A is an r-variate
polynomial, r ge 0.  B, a univariate polynomial, equals A(0, ...,0,x).*)
VAR  AL, AP, B, BL, EL, RLP: LIST;
BEGIN
(*1*) (*rl=0 or a=0.*)
      IF (RL = 0) OR (A = 0) THEN B:=A; RETURN(B); END;
(*2*) (*general case.*) RLP:=RL-1; B:=BETA; AP:=A;
      WHILE AP <> SIL DO ADV2(AP, EL,AL,AP); BL:=PTBCF(RLP,AL);
            IF BL <> 0 THEN B:=COMP2(BL,EL,B); END;
            END;
      IF B = SIL THEN B:=0; ELSE B:=INV(B); END;
      RETURN(B);
(*5*) END PUFP;


PROCEDURE VCOMP(U,V: LIST): LIST;
(*Vector comparison.  U=(u(1), ...,u(r)) and V=(v(1), ...,v(r))
are lists of beta-integers with common length r ge 1.  If U=V
then t=0.  If U is not equal to V then t=1 if u(i) le v(i) for
all i and t=2 if v(i) le u(i) for all i.  Otherwise t=3.*)
VAR  TL, TL1, TL2, UL, US, VL, VS: LIST;
BEGIN
(*1*) TL1:=0; TL2:=0; US:=U; VS:=V;
      REPEAT ADV(US, UL,US); ADV(VS, VL,VS);
             IF UL < VL THEN TL1:=1; ELSE
                IF VL < UL THEN TL2:=2; END;
                END;
             UNTIL US = SIL;
      TL:=TL1+TL2; RETURN(TL);
(*4*) END VCOMP;


PROCEDURE VLREAD(): LIST;
(*Variable list read.  V, a list of variables, is read from the input
stream.  Any preceding blanks are skipped.*)
VAR  C, V, VL: LIST;
BEGIN
(*1*) (*read variables.*) V:=SIL; C:=CREADB();
      IF C <> MASORD("(") THEN 
         SWRITE("ERROR FOUND BY VLREAD."); DIBUFF; END;
      C:=CREADB();
      IF C = MASORD(")") THEN RETURN(V); ELSE BKSP; END;
      LOOP VL:=VREAD(); V:=COMP(VL,V); C:=CREADB();
           IF C = MASORD(")") THEN V:=INV(V); RETURN(V); ELSE
              IF C <> MASORD(",") THEN 
                 SWRITE("ERROR FOUND BY VLREAD."); DIBUFF; END;
              END;
           END;
(*5*) END VLREAD;


PROCEDURE VLSRCH(VL,V: LIST): LIST;
(*Variable list search.  v is a variable.  V is a list of variables
(v(1), ...,v(n)), n non-negative.  If v=v(j) for some j then
i=j.  Otherwise i=0.*)
VAR   IL, VL1, VP: LIST;
BEGIN
(*1*) VP:=V; IL:=1;
      WHILE VP <> SIL DO ADV(VP, VL1,VP);
            IF EQUAL(VL,VL1) = 1 THEN RETURN(IL); END;
            IL:=IL+1; END;
      IL:=0; RETURN(IL);
(*4*) END VLSRCH;


PROCEDURE VLWRIT(V: LIST);
(*Variable list write.  V, a list of variables, is written in the
output stream.*)
VAR  VL, VP: LIST;
BEGIN
(*1*) VP:=V; SWRITE("(");
      IF VP = SIL THEN SWRITE(")"); RETURN; ELSE ADV(VP, VL,VP);
         CLOUT(VL); END;
      WHILE VP <> SIL DO SWRITE(","); ADV(VP, VL,VP); CLOUT(VL);
      END;
      SWRITE(")"); RETURN;
(*4*) END VLWRIT;



PROCEDURE VMAX(U,V: LIST): LIST;
(*Vector maximum.  U=(u(1), ...,u(r)) and V=(v(1), ...,v(r)) are
lists of beta-integers with common length r ge 1.  W=(w(1), ...,
w(r)) where w(i)=MAX(u(i),v(i)).*)
VAR  UL, US, VL, VS, W, WL: LIST;
BEGIN
(*1*) W:=BETA; US:=U; VS:=V;
      REPEAT ADV(US, UL,US); ADV(VS, VL,VS); WL:=MASMAX(UL,VL);
             W:=COMP(WL,W);
             UNTIL US = SIL;
      W:=INV(W); RETURN(W);
(*4*) END VMAX;


PROCEDURE VMIN(U,V: LIST): LIST;
(*Vector maximum.  U=(u(1), ...,u(r)) and V=(v(1), ...,v(r)) are
lists of beta-integers with common length r ge 1.  W=(w(1), ...,
w(r)) where w(i)=MIN(u(i),v(i)).*)
VAR  UL, US, VL, VS, W, WL: LIST;
BEGIN
(*1*) W:=BETA; US:=U; VS:=V;
      REPEAT ADV(US, UL,US); ADV(VS, VL,VS); WL:=MASMIN(UL,VL);
             W:=COMP(WL,W);
             UNTIL US = SIL;
      W:=INV(W); RETURN(W);
(*4*) END VMIN;


PROCEDURE VREAD(): LIST;
(*Variable read.  The variable v is read from the input stream.  Any
number of preceding blanks are skipped.*)
VAR  C, IDUM, VL: LIST;
BEGIN
(*1*) C:=CREADB();
      IF NOT LETTER(C) THEN SWRITE("ERROR found by VREAD."); DIBUFF;
         END;
      VL:=BETA;
      REPEAT VL:=COMP(C,VL); C:=CREAD();
             UNTIL NOT ( LETTER(C) OR DIGIT(C) );
      VL:=INV(VL); BKSP; RETURN(VL);
(*4*) END VREAD;


BEGIN 

BEGIN3;

END SACPOL.


(* -EOF- *)
