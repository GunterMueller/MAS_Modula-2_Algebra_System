(* ----------------------------------------------------------------------------
 * $Id: DIPC.mi,v 1.10 1995/11/05 09:16:35 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPC.mi,v $
 * Revision 1.10  1995/11/05 09:16:35  kredel
 * Improved exponent parsing.
 *
 * Revision 1.9  1995/11/04  22:14:56  pesch
 * New procedures EVOWRITE and EvordWrite.
 *
 * Revision 1.8  1994/09/01  13:30:59  pfeil
 * minor changes
 *
 * Revision 1.7  1994/06/09  15:13:30  pfeil
 * Added AD2DIP, DIP2AD.
 *
 * Revision 1.6  1994/03/30  13:02:33  dolzmann
 * New procedure DILPERM.
 *
 * Revision 1.5  1993/03/23  12:50:00  kredel
 * Improved linear form processing
 *
 * Revision 1.4  1993/03/16  09:32:28  kredel
 * Removed obsolete LPERM function.
 *
 * Revision 1.3  1992/10/15  16:28:33  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:33:46  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:13:58  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DIPC;

(* DIP Common Polynomial System Implementation Module. *)



(* Import lists and declarations. *)

FROM DIPI	IMPORT	DIILWR;

FROM DIPIPOL	IMPORT	VIPIIP;

FROM DIPTOOLS	IMPORT	EvordPop, EvordPush;

FROM MASELEM	IMPORT	GAMMAINT, MASMAX;

FROM MASSTOR	IMPORT	ADV, BETA, COMP, FIRST, INV, LENGTH, LIST, LIST1,
			LISTVAR, RED, SFIRST, SIL, SRED;

FROM MASERR	IMPORT	ERROR, harmless, severe; 

FROM SACLIST	IMPORT	ADV2, AREAD, CINV, COMP2, EQUAL, LAST, LELT, LIST2,
			OWRITE, RED2, SECOND;

FROM MASBIOS	IMPORT	BKSP, BLINES, CREAD, CREADB, DIBUFF, MASORD, SWRITE;

FROM SACCOMB	IMPORT	LPERM;

FROM SACD	IMPORT	DQR, DRANN;

FROM SACI	IMPORT	ICOMP, IPROD;

CONST rcsidi = "$Id: DIPC.mi,v 1.10 1995/11/05 09:16:35 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1995 Universitaet Passau";



PROCEDURE BACKUB();
(*Backspace until blank. *)
VAR  C: LIST;
BEGIN
(*1*) (*decrement of ipos. *)
      REPEAT BKSP; BKSP;
             C:=CREAD();
             UNTIL C = MASORD(" ");
(*4*) END BACKUB;


PROCEDURE BEGIND();
(*Begin distributive. set global variables for distributive
polynomial system. *)
BEGIN
(*2*) (*set valis. *) LISTVAR(VALIS); VALIS:=SIL;
(*3*) (*set evord. *) EVORD:=INVLEX; LISTVAR(EVORD); 
(*6*) RETURN; END BEGIND;


PROCEDURE CLIN(): LIST;
(*Character list in. If a character list is next in the input
stream then it is read, else L is empty. *)
VAR  C, IDUM, L, LL: LIST;
BEGIN
(*1*) (*is character list next. *) L:=BETA; C:=CREADB();
      IF C <> MASORD("$") THEN BKSP; RETURN(L); END;
      C:=CREAD();
      IF C <> MASORD("(") THEN BKSP; BKSP; RETURN(L); END;
      LL:=1;
(*2*) (*read character list. *)
      REPEAT C:=CREAD(); L:=COMP(C,L);
             IF C = MASORD("(") THEN LL:=LL+1; ELSE
                IF C = MASORD(")") THEN LL:=LL-1; END;
                END;
             UNTIL LL = 0;
      L:=RED(L); L:=INV(L);
(*5*) RETURN(L); END CLIN;


PROCEDURE DILBSO(A: LIST);
(*Distributive polynomial list bubble sort. A is a list of
lists of base coefficients and exponent vectors.
Each element of A is sorted with respect to the termordering
defined in EVORD by the bubble-sort method,
two monomials with equal exponents will lead to an error.
The lists in A but not there location, are modified.*)
VAR  AL, AP: LIST;
BEGIN
(*1*) (*sort polynomials. *) AP:=A;
      WHILE AP <> SIL DO ADV(AP, AL,AP); DIPBSO(AL); END;
(*4*) RETURN; END DILBSO;


PROCEDURE DILFPL(RL,A: LIST): LIST;
(*Distributive polynomial list from polynom list. A is a list
of polynomials in r variables, r ge 0. Every polynomial in A
is converted to distributive representation and returned in B. *)
VAR  AL, AP, B, BL: LIST;
BEGIN
(*1*) (*convert polynomials. *) AP:=A; B:=BETA;
      WHILE AP <> SIL DO ADV(AP, AL,AP); BL:=DIPFP(RL,AL);
            B:=COMP(BL,B); END;
      B:=INV(B);
(*4*) RETURN(B); END DILFPL;


PROCEDURE DILPERM(dil,perm: LIST):LIST;
(* distributive polynomial list permutation of variables.
The variable dil is a list of distributive polynomials in r variables, 
perm is a permutation. In each distributive polynomial of the list dil 
the variables are permuted with respect to perm. *)
	VAR dip,result: LIST;
BEGIN
(*1*)	(* initialization *)
	result:=SIL;
(*2*)	(* process each polynomial in the list dil. *)
	WHILE dil<>SIL DO
		ADV(dil,dip,dil);
		result:=COMP(DIPERM(dip,perm),result);
	END;
(*3*)	(* reorder the result and return it. *)
	RETURN INV(result);
END DILPERM; 


PROCEDURE DIPADM(A: LIST;    VAR EL,FL,BL,B: LIST);
(*Distributive polynomial advance main variable. A is a
distributive polynomial in one or more variables. e is the
degree of A, b is the leading coefficient of A,
B is the reductum of A, f is the degree of B.*)
VAR  CL, DL, J1Y: LIST;
BEGIN
(*1*) (*trivial case.*)
      IF A = 0 THEN EL:=0; FL:=0; BL:=A; B:=0; RETURN; END;
(*2*) (*general case.*) B:=A; BL:=BETA; J1Y:=DIPEVL(B); EL:=FIRST(J1Y);
      LOOP IF B = SIL THEN EXIT END; 
           CL:=DIPLBC(B); DL:=DIPEVL(B); ADV(DL, FL,DL);
           IF EL = FL THEN B:=RED2(B); BL:=DIPMCP(DL,CL,BL); 
              ELSE EXIT END;
           END;
(*3*) (*finish.*) BL:=INV(BL);
      IF B = SIL THEN B:=0; FL:=0; END;
      RETURN;
(*6*) END DIPADM;


PROCEDURE DIPADS(A,IL,SL: LIST;    VAR EL,FL,BL,B: LIST);
(*Distributive polynomial advance and substitute. A is a
distributive polynomial, i is the specified variable,
1 le i le r=DIPNOV(A), s is the new exponent of b
in the i-th variable. e is the exponent of the leading
monomial of A in the i-th variable, let bs be part of the
coefficient of xi**e then b = bs * xi**s,
B = A - bs*xi**e, f is the exponent of the leading monomial
of B in the i-th variable.*)
VAR  CL, DL, DUMMY, E1, GL, J1Y, JL, RL: LIST;
BEGIN
(*1*) (*trivial case.*)
      IF A = 0 THEN EL:=0; FL:=0; BL:=A; B:=0; RETURN; END;
(*2*) (*general case.*) RL:=DIPNOV(A); J1Y:=RL-IL; JL:=J1Y+1;
      DIPMAD(A, CL,E1,B); EVSU(E1,JL,SL, GL,EL); BL:=DIPFMO(GL,CL);
      LOOP IF B = SIL THEN EXIT END;
           DIPMAD(B, CL,DL,DUMMY); EVSU(DL,JL,SL, GL,FL);
           IF EL = FL THEN B:=RED2(B); BL:=DIPMCP(GL,CL,BL); 
              ELSE EXIT END;
           END;
(*3*) (*finish.*) BL:=INV(BL);
      IF B = SIL THEN B:=0; FL:=0; END;
      RETURN;
(*6*) END DIPADS;


PROCEDURE DIPADV(A,IL: LIST;    VAR EL,FL,BL,B: LIST);
(*Distributive polynomial advance. A is a distributive polynomial,
i is the specified variable, 1 le i le r=DIPNOV(A). e is
the exponent of the leading monomial of A in the i-th variable,
b is part of the coefficient of xi**e of A,
B = A - b*xi**e, f is the exponent of the leading monomial
of B in the i-th variable.*)
VAR  CL, DL, DUMMY, E1, GL, J1Y, JL, RL: LIST;
BEGIN
(*1*) (*trivial case.*)
      IF A = 0 THEN EL:=0; FL:=0; BL:=A; B:=0; RETURN; END;
      RL:=DIPNOV(A);
      IF IL = RL THEN DIPADM(A, EL,FL,BL,B); RETURN; END;
(*2*) (*general case.*) J1Y:=RL-IL; JL:=J1Y+1; DIPMAD(A, CL,E1,B);
      EVDEL(E1,JL, GL,EL); BL:=DIPFMO(GL,CL);
      LOOP IF B = SIL THEN EXIT END;
           DIPMAD(B, CL,DL,DUMMY); EVDEL(DL,JL, GL,FL);
           IF EL = FL THEN B:=RED2(B); BL:=DIPMCP(GL,CL,BL); 
              ELSE EXIT END;
           END;
(*3*) (*finish.*) BL:=INV(BL);
      IF B = SIL THEN B:=0; FL:=0; END;
      RETURN;
(*6*) END DIPADV;


PROCEDURE DIPBSO(A: LIST);
(*Distributive polynomial bubble sort. A is a list of
base coefficients and exponent vectors, A is sorted
with respect to the termordering defined in EVORD
by the bubble-sort method, two monomials with equal
exponents will lead to an error. The
list A but not its location, is modified.*)
VAR  ALP, ALPP, AP, APP, B, BP, DUMMY, ELP, ELPP, TL: LIST;
BEGIN
(*1*) (*trivial case.*)
      IF A = 0 THEN RETURN; END;
(*2*) (*general case.*) B:=BETA;
      REPEAT AP:=A; DIPMAD(AP, ALP,ELP,APP); BP:=BETA;
             WHILE APP <> B DO DIPMAD(APP, ALPP,ELPP,DUMMY);
                   TL:=EVCOMP(ELP,ELPP);
                   IF TL = 0 THEN ERROR(harmless,"DIPBSO, equal exponents.");
                      RETURN END;
                   IF TL < 0 THEN DIPMST(AP,ALPP,ELPP);
                      DIPMST(APP,ALP,ELP); BP:=APP; ELSE ALP:=ALPP;
                      ELP:=ELPP; END;
                   AP:=APP; APP:=RED2(AP); END;
             B:=BP;
             UNTIL B = SIL;
      RETURN;
(*6*) END DIPBSO;


PROCEDURE DIPCMP(EL,A: LIST): LIST;
(*Distributive polynomial composition. A is a distributive
polynomial in r variables. e is an exponent. Let t=r+1, then
B(x1, ...,xr,xt)=A(x1, ...,xr)*xt**e.*)
VAR  AS, B, CL, DL, DLP: LIST;
BEGIN
(*1*) (*a eq 0.*)
      IF A = 0 THEN B:=A; RETURN(B); END;
(*2*) (*general case.*) AS:=A; B:=BETA;
      REPEAT DIPMAD(AS, CL,DL,AS); DLP:=COMP(EL,DL);
             B:=DIPMCP(DLP,CL,B);
             UNTIL AS = SIL;
      B:=INV(B); RETURN(B);
(*5*) END DIPCMP;


PROCEDURE DIPDEG(A: LIST): LIST;
(*Distributive polynomial degree. A is a distributive polynomial.
n is the degree of A in its main variable.*)
VAR  EL, NL: LIST;
BEGIN
(*1*) (*a=0.*) NL:=0;
      IF A = 0 THEN RETURN(NL); END;
(*2*) (*a=integer.*) EL:=DIPEVL(A);
      IF EL = SIL THEN RETURN(NL); END;
      NL:=FIRST(EL); RETURN(NL);
(*5*) END DIPDEG;



PROCEDURE DIPDPV(A,SL,QL: LIST): LIST;
(*Distributive polynomial division by power of variable. A is
a distributive polynomial in r variables. s is the desired
variable to be divided, s le r. q is a beta-integer.
Q = A / ( xs**q). *)
VAR  AL, AS, EL, EL1, FL, J1Y, JL, Q, RL: LIST;
BEGIN
(*1*) (*a=0 or ql=0. *)
      IF (A = 0) OR (QL = 0) THEN Q:=A; RETURN(Q); END;
(*2*) (*divide terms.*) RL:=DIPNOV(A); J1Y:=RL-SL; JL:=J1Y+1; AS:=A;
      Q:=BETA;
      REPEAT DIPMAD(AS, AL,EL,AS); EVCSUB(EL,JL,QL, FL,EL1);
             Q:=DIPMCP(FL,AL,Q);
             UNTIL AS = SIL;
(*3*) (*finish.*) Q:=INV(Q); RETURN(Q);
(*6*) END DIPDPV;


PROCEDURE DIPERM(A,P: LIST): LIST;
(*Distributive polynomial permutation of variables. A is a
distributive polynomial, in r variables, r ge 0. P is a
list (p sub 1, ...,p sub r) whose elements are the
beta-digits 1 through r.  B(x sub (p sub 1), ...,x sub (p sub r))
=A(x sub 1, ...,x sub r). *)
VAR  AL, AP, B, DL, EL: LIST;
BEGIN
(*1*) (*a=0. *)
      IF A = 0 THEN B:=0; RETURN(B); END;
(*2*) (*permute variables. *) AP:=A; B:=BETA;
      REPEAT DIPMAD(AP, AL,EL,AP); DL:=CINV(EL); DL:=LPERM(DL,P);
             DL:=INV(DL); B:=DIPMCP(DL,AL,B);
             UNTIL AP = SIL;
(*3*) (*sort. *) B:=INV(B); DIPBSO(B);
(*6*) RETURN(B); END DIPERM;

PROCEDURE DIPEVL(A: LIST): LIST;
(*Distributive polynomial exponent vector leading monomial.
A is a distributive polynomial. u is the exponent vector of
the leading monomial of A. *)
VAR  UL: LIST;
BEGIN
(*1*) (*a=0.*) UL:=BETA;
      IF A <> 0 THEN UL:=FIRST(A); END;
      RETURN(UL)
(*4*) END DIPEVL;


PROCEDURE DIPEVP(A,EL: LIST): LIST;
(*Distributive polynomial exponent vector product. A is a
distributive polynomial, e is an exponent vector  C=A*(x**e). *)
VAR  AL, AP, C, FL, GL: LIST;
BEGIN
(*1*) (*a=0 or el=0.*)
      IF (A = 0) OR (EVSIGN(EL) = 0) THEN C:=A; RETURN(C); END;
(*2*) (*multiply.*) C:=BETA; AP:=A;
      REPEAT DIPMAD(AP, AL,FL,AP); GL:=EVSUM(EL,FL); C:=DIPMCP(GL,AL,C);
             UNTIL AP = SIL;
      C:=INV(C); RETURN(C);
(*5*) END DIPEVP;


PROCEDURE DIPEXC(A,ILP,JLP: LIST): LIST;
(*Distributive polynomial exchange variables. A is a
distributive polynomial, the variables ip and jp are exchanged,
B=(x1, ...,xip, ...,xjp, ...,xr)=A(x1, ...,xjp, ...,xip, ...,xr), 
0 le ip, jp le DIPNOV(A).*)
VAR  AL, AP, B, EL, FL, IL, J1Y, JL, RL, TL: LIST;
BEGIN
(*1*) (*a=0 or ilp=jlp.*)
      IF (A = 0) OR (ILP = JLP) THEN B:=A; RETURN(B); END;
(*2*) (*exchange.*) B:=BETA; AP:=A; RL:=DIPNOV(A); J1Y:=RL+1;
      JL:=J1Y-JLP; J1Y:=RL+1; IL:=J1Y-ILP;
      IF IL > JL THEN TL:=JL; JL:=IL; IL:=TL; END;
      REPEAT DIPMAD(AP, AL,EL,AP); FL:=EVEXC(EL,IL,JL);
             B:=DIPMCP(FL,AL,B);
             UNTIL AP = SIL;
      B:=INV(B);
(*3*) (*sort.*) DIPBSO(B); RETURN(B);
(*6*) END DIPEXC;


PROCEDURE DIPFMO(AL,EL: LIST): LIST;
(*Distributive polynomial from monomial. A is a non zero
distributive polynomial with a as its leading base coefficient
and e as is its exponent vector of the leading monomial. *)
VAR  A: LIST;
BEGIN
(*1*) (*list composition. *) A:=COMP2(EL,AL,BETA);
      RETURN(A)
(*4*) END DIPFMO;


PROCEDURE DIPFP(RL,A: LIST): LIST;
(*Distributive polynomial from polynomial. A is a polynomial
in r variables, r ge 0. B is the result of converting A from
recursive to distributive representation. Modified version
original version by G. E. Collins. *)
VAR  A1, AL1, AS, B, B1, BL1, E1, EL1, ELP, ELS, RLS: LIST;
BEGIN
(*1*) (*rl=0 or a=0.*)
      IF A = 0 THEN B:=A; RETURN(B); END;
      IF RL = 0 THEN B:=DIPFMO(A,BETA); RETURN(B); END;
(*2*) (*rl=1.*) B:=BETA; AS:=A; RLS:=RL-1;
      IF RLS = 0 THEN 
         REPEAT ADV2(AS, EL1,AL1,AS); E1:=LIST1(EL1); B:=DIPMCP(E1,AL1,B);
                UNTIL AS = SIL;
         B:=INV(B); RETURN(B) END;
(*3*) (*recursion.*)
      REPEAT ADV2(AS, ELP,A1,AS); B1:=DIPFP(RLS,A1);
             REPEAT DIPMAD(B1, BL1,ELS,B1); E1:=COMP(ELP,ELS);
                    B:=DIPMCP(E1,BL1,B);
                    UNTIL B1 = SIL;
             UNTIL AS = SIL;
      B:=INV(B); RETURN(B);
(*6*) END DIPFP;


PROCEDURE DIPINV(A,JL,KL: LIST): LIST;
(*Distributive polynomial introduction of new variables.
A is a distributive polynomial in r variables. k ge 0,
0 le j le r. B(x1, ...,xj,y1, ...,yk,xj+1, ...,xr)=A(x1, ...,xr).*)
VAR  AS, B, CL, DL, EL, ELS, FL, GL, I, IL, J1Y: LIST;
BEGIN
(*1*) (*a=0 or kl=0.*)
      IF (A = 0) OR (KL = 0) THEN B:=A; RETURN(B); END;
(*2*) (*general case.*) AS:=A; B:=BETA; J1Y:=DIPNOV(A); IL:=J1Y-JL;
      REPEAT DIPMAD(AS, CL,DL,AS); EL:=BETA;
             FOR I:=1 TO IL DO ADV(DL, FL,DL); EL:=COMP(FL,EL); END;
             GL:=DL;
             FOR I:=1 TO KL DO GL:=COMP(0,GL); END;
             IF EL = SIL THEN EL:=GL; ELSE ELS:=INV(EL); SRED(EL,GL);
                EL:=ELS; END;
             B:=DIPMCP(EL,CL,B);
             UNTIL AS = SIL;
      B:=INV(B);
(*5*) RETURN(B); END DIPINV;


PROCEDURE DIPLBC(A: LIST): LIST;
(*Distributive polynomial leading base coefficient. A is a
distributive polynomial. a is the leading base coefficient of A.*)
VAR  AL: LIST;
BEGIN
(*1*) (*a=0.*) AL:=0;
      IF A <> 0 THEN AL:=SECOND(A); END;
      RETURN(AL)
(*4*) END DIPLBC;


PROCEDURE DIPLDC(A: LIST): LIST;
(*Distributive polynomial leading coefficient. A is a distributive
polynomial in one or more variables. a is the leading
coefficient of A.*)
VAR  AL, AS, EL, FL: LIST;
BEGIN
(*1*) (*call dipadm.*) DIPADM(A, EL,FL,AL,AS); RETURN(AL);
(*4*) END DIPLDC;


PROCEDURE DIPLM(L1,L2: LIST): LIST;
(*Distributive polynomial list merge.  L1 and L2 are lists
of non zero distributive polynomials in non decreasing
order.  L is the merge of L1 and L2. L1 and L2 are
modified to produce L. *)
VAR  AL1, AL2, EL1, EL2, L, LP, LP1, LP2, TL: LIST;
     eoz: BOOLEAN;
BEGIN
(*1*) (*l1 or l2 null.*)
      IF L1 = SIL THEN L:=L2; RETURN(L); END;
      IF L2 = SIL THEN L:=L1; RETURN(L); END;
(*2*) (*initialize.*) LP1:=L1; LP2:=L2; AL1:=FIRST(L1); AL2:=FIRST(L2);
      EL1:=DIPEVL(AL1); EL2:=DIPEVL(AL2); TL:=EVCOMP(EL1,EL2);
      IF TL > 0 THEN L:=L2; LP:=L2; LP2:=RED(L2); eoz:=FALSE 
         ELSE L:=L1; LP:=L1; LP1:=RED(L1); eoz:=TRUE END;
LOOP
(*3*) (*last element from l1.*)
IF eoz THEN 
      IF LP1 = SIL THEN EXIT END;
      AL1:=FIRST(LP1); EL1:=DIPEVL(AL1); TL:=EVCOMP(EL1,EL2);
      IF TL <= 0 THEN LP:=LP1; LP1:=RED(LP1); eoz:=TRUE 
         ELSE SRED(LP,LP2); LP:=LP2; LP2:=RED(LP2); eoz:=FALSE END;
   ELSE
(*4*) (*last element from l2.*)
      IF LP2 = SIL THEN EXIT END;
      AL2:=FIRST(LP2); EL2:=DIPEVL(AL2); TL:=EVCOMP(EL1,EL2);
      IF TL <= 0 THEN SRED(LP,LP1); LP:=LP1; LP1:=RED(LP1); eoz:=TRUE 
         ELSE LP:=LP2; LP2:=RED(LP2); eoz:=FALSE END;
   END;
END;
(*5*) (*left over.*)
      IF LP1 = SIL THEN SRED(LP,LP2); ELSE SRED(LP,LP1); END;
      RETURN(L);
(*8*) END DIPLM;


PROCEDURE DIPLPM(A: LIST): LIST;
(*Distributive polynomial list pair-merge sort. A is
a list of non zero distributive polynomials. B is the
result of sorting A into non-decreasing order. Pairs of
polynomials are merged. The list A is modified to produce B. *)
VAR  AL1, AL2, AP, APP, APPP, B, BP, BPP, C, CP, CPP, CS, EL1, EL2,
     TL: LIST;
BEGIN
(*1*) (*nothing to do. *)
      IF (A = SIL) OR (RED(A) = SIL) THEN B:=A; RETURN(B); END;
(*2*) (*construct pairs. *) C:=LIST1(0); CS:=C; AP:=A;
      REPEAT ADV(AP, AL1,APP);
             IF APP = SIL THEN BP:=AP; ELSE ADV(APP, AL2,APPP);
                EL1:=DIPEVL(AL1); EL2:=DIPEVL(AL2); TL:=EVCOMP(EL1,EL2);
                IF TL <= 0 THEN BP:=AP; SRED(APP,SIL); ELSE BP:=APP;
                   SRED(APP,AP); SRED(AP,SIL); END;
                END;
             C:=COMP(BP,C); AP:=APPP;
             UNTIL (APP = SIL) OR (AP = SIL);
(*3*) (*circle and merge. *) ADV(C, BP,C); SFIRST(CS,BP); SRED(CS,C);
      ADV(C, B,CP);
      WHILE C <> CP DO ADV(CP, BP,CPP); BPP:=DIPLM(B,BP);
            SFIRST(C,BPP); SRED(C,CPP); C:=CPP; ADV(C, B,CP); END;
(*6*) RETURN(B); END DIPLPM;


PROCEDURE DIPLRS(A: LIST);
(*Distributive polynomial list re-sort. A is a list of
distributive  polynomials in r variables, r ge 0.
The polynomials in A are re-sorted. *)
VAR  AL, AP: LIST;
BEGIN
(*1*) (*a empty. *)
      IF A = SIL THEN RETURN; END;
(*2*) (*sort polynomials. *) AP:=A;
      REPEAT ADV(AP, AL,AP); DIPBSO(AL);
             UNTIL AP = SIL;
(*5*) RETURN; END DIPLRS;


PROCEDURE DIPMAD(A: LIST;    VAR AL,EL,AP: LIST);
(*Distributive polynomial monomial advance. A is a non zero
distributive polynomial. a is its leading base coefficient,
e is the exponent vector of the leading monomial of A.
AP is the distributive polynomial a without its leading
monomial, or the empty list. *)
BEGIN
(*1*) (*list advance. *) ADV(A, EL,AP); ADV(AP, AL,AP);
(*4*) END DIPMAD;


PROCEDURE DIPMCP(AL,EL,A: LIST): LIST;
(*Distributive polynomial monomial composition. A is an emty
list or a non zero distributive polynomial. AP is a non zero
distributive polynomial with a as its leading base coefficient,
e as is its exponent vector of the leading monomial and A as
its monomial reductum. *)
VAR  AP: LIST;
BEGIN
(*1*) (*list composition. *) AP:=COMP2(EL,AL,A);
      RETURN(AP)
(*4*) END DIPMCP;


PROCEDURE DIPMPM(A,PL: LIST): LIST;
(*Distributive polynomial multiplication by power of main variable.
A is a distributive polynomial in r variables. p is a beta-
integer.  B = A * ( xr**p ). *)
VAR  AL, AS, B, EL, FL, GL: LIST;
BEGIN
(*1*) (*a=0 or pl=0. *)
      IF (A = 0) OR (PL = 0) THEN B:=A; RETURN(B); END;
(*2*) (*multiply terms.*) AS:=A; B:=BETA;
      REPEAT DIPMAD(AS, AL,EL,AS); ADV(EL, FL,GL); FL:=FL+PL;
             GL:=COMP(FL,GL); B:=DIPMCP(GL,AL,B);
             UNTIL AS = SIL;
(*3*) (*finish.*) B:=INV(B); RETURN(B);
(*6*) END DIPMPM;


PROCEDURE DIPMPV(A,SL,PL: LIST): LIST;
(*Distributive polynomial multiplication by power of variable.
A is a distributive polynomial in r variables. s is the specified
variable to be multiplicated, 1 le s le r. p is a beta-integer.
B = A * ( xs**p ). *)
VAR  AL, AS, B, EL, EL1, FL, J1Y, JL, RL: LIST;
BEGIN
(*1*) (*a=0 or pl=0. *)
      IF (A = 0) OR (PL = 0) THEN B:=A; RETURN(B); END;
(*2*) (*multiply terms.*) RL:=DIPNOV(A); J1Y:=RL-SL; JL:=J1Y+1; AS:=A;
      B:=BETA;
      WHILE AS <> SIL DO DIPMAD(AS, AL,EL,AS); EVCADD(EL,JL,PL,
            FL,EL1); B:=DIPMCP(FL,AL,B); END;
      B:=INV(B); RETURN(B);
(*5*) END DIPMPV;


PROCEDURE DIPMRD(A: LIST): LIST;
(*Distributive polynomial monomial reductum. A is a distributive
polynomial. B is the distributive polynomial a without the
leading monomial of A. *)
VAR  B: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN B:=0; ELSE B:=RED2(A);
         IF B = SIL THEN B:=0; END;
         END;
      RETURN(B)
(*4*) END DIPMRD;


PROCEDURE DIPMST(A,AL,EL: LIST);
(*Distributive polynomial monomial set. A is a non zero
distributive polynomial. Its leading base coefficient is set
to a and its exponent vector of the leading monomial is
set to e. *)
VAR  AP: LIST;
BEGIN
(*1*) (*list set. *) SFIRST(A,EL); AP:=RED(A); SFIRST(AP,AL);
(*4*) END DIPMST;


PROCEDURE DIPNBC(A: LIST): LIST;
(*Distributive polynomial number of base coefficients. A is a
distributive polynomial. l is the number of base coefficients.*)
VAR  LL: LIST;
BEGIN
(*1*) (*a=0.*) LL:=0;
      IF A = 0 THEN RETURN(LL); END;
(*2*) (*a not 0.*) LL:=LENGTH(A); LL:=LL DIV 2; RETURN(LL);
(*5*) END DIPNBC;


PROCEDURE DIPNOV(A: LIST): GAMMAINT;
(*Distributive polynomial number of variables. A is a distributive
polynomial. r is the number of variables, r ge 0. If A=0 then
r is set to zero. *)
VAR  J1Y, RL: LIST;
BEGIN
(*1*) (*length of the exponent vector.*)
      IF A = 0 THEN RL:=0; ELSE J1Y:=DIPEVL(A); RL:=LENGTH(J1Y); END;
      RETURN(RL);
(*4*) END DIPNOV;


PROCEDURE DIPRED(A: LIST): LIST;
(*Distributive polynomial reductum. A is a distributive polynomial,
in one or more variables. B is the reductum of A.*)
VAR  AL, B, EL, FL: LIST;
BEGIN
(*1*) (*call dipadm.*) DIPADM(A, EL,FL,AL,B); RETURN(B);
(*4*) END DIPRED;


PROCEDURE DIPTBC(A: LIST): LIST;
(*Distributive polynomial trailing base coefficient. A is a
distributive polynomial. a is the trailing base coefficient.*)
VAR  AL, AP, AS, J1Y, SL: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN AL:=0; RETURN(AL); END;
(*2*) (*general case.*) AS:=A;
      REPEAT AP:=AS; AS:=RED2(AS);
             UNTIL AS = SIL;
      J1Y:=DIPEVL(AP); SL:=EVSIGN(J1Y);
      IF SL = 0 THEN AL:=DIPLBC(AP); ELSE AL:=0; END;
      RETURN(AL);
(*5*) END DIPTBC;


PROCEDURE DIPTCF(A: LIST): LIST;
(*Distributive polynomial trailing coefficient. A is a
distributive polynomial. a is the trailing coefficient of A.*)
VAR  A1, AL, AS, EL, J1Y: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN AL:=0; RETURN(AL); END;
(*2*) (*general case.*) AS:=A; AL:=BETA;
      REPEAT DIPMAD(AS, A1,EL,AS);
             IF FIRST(EL) = 0 THEN J1Y:=RED(EL);
                AL:=DIPMCP(J1Y,A1,AL); END;
             UNTIL AS = SIL;
(*3*) (*finish.*)
      IF AL = SIL THEN AL:=0; ELSE AL:=INV(AL); END;
      RETURN(AL);
(*6*) END DIPTCF;


PROCEDURE DIPTCS(A,IL: LIST): LIST;
(*Distributive polynomial trailing coefficient specified variable.
A is a distributive polynomial in r variables. a is the
trailing coefficient of A with respect to the i-th variable,
1 le i le r. *)
VAR  A1, AL, AS, EL, EL1, FL, J1Y, JL, RL: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN AL:=0; RETURN(AL); END;
(*2*) (*il=rl.*) RL:=DIPNOV(A);
      IF RL = IL THEN AL:=DIPTCF(A); RETURN(AL); END;
      J1Y:=RL-IL; JL:=J1Y+1;
(*3*) (*general case.*) AS:=A; AL:=BETA;
      REPEAT DIPMAD(AS, A1,EL,AS); EVDEL(EL,JL, FL,EL1);
             IF EL1 = 0 THEN AL:=DIPMCP(FL,A1,AL); END;
             UNTIL AS = SIL;
(*4*) (*finish.*)
      IF AL = SIL THEN AL:=0; ELSE AL:=INV(AL); END;
      RETURN(AL);
(*7*) END DIPTCS;


PROCEDURE DIPTDG(A: LIST): LIST;
(*Distributive polynomial total degree. A is a distributive
polynomial. n is the total degree of A.*)
VAR  AL, AS, EL, ML, NL: LIST;
BEGIN
(*1*) (*a=0.*) NL:=0;
      IF A = 0 THEN RETURN(NL); END;
(*2*) (*rl=0 or rl=1.*)
      IF DIPNOV(A) <= 1 THEN NL:=DIPDEG(A); RETURN(NL); END;
(*3*) (*find maximal total degree of exponent vectors.*) AS:=A;
      WHILE AS <> SIL DO DIPMAD(AS, AL,EL,AS); ML:=EVTDEG(EL);
            NL:=MASMAX(ML,NL); END;
      RETURN(NL);
(*6*) END DIPTDG;


PROCEDURE DIPUNT(A: LIST): LIST;
(*Distributive polynomial univariate test. A is a distributive
polynomial. If a is univariate then t=1, otherwise t=0.*)
VAR  AL, AP, EL, RL, TL, V, V1: LIST;
BEGIN
(*1*) (*rl=1 or 0.*) RL:=DIPNOV(A);
      IF RL <= 1 THEN TL:=1; RETURN(TL); END;
(*2*) (*check exponent vectors.*) TL:=0; DIPMAD(A, AL,EL,AP);
      V:=EVDOV(EL);
      IF V = SIL THEN TL:=1; RETURN(TL); END;
      IF RED(V) <> SIL THEN RETURN(TL); END;
      WHILE AP <> SIL DO DIPMAD(AP, AL,EL,AP); V1:=EVDOV(EL);
            IF V1 <> SIL THEN
               IF EQUAL(V,V1) = 0 THEN RETURN(TL); END;
               END;
            END;
      TL:=1;
(*5*) RETURN(TL); END DIPUNT;


PROCEDURE DIPUV(A: LIST): LIST;
(*Distributive polynomial univariate variable output.
A is a distributive polynomial. If A is univariate then t=i, 
otherwise t=0. were i is the index of the variable in which A 
is univariate. If A is constant then t= -1. *)
VAR  AL, AP, EL, J1Y, J2Y, RL, TL, V, V1: LIST;
BEGIN
(*1*) (*rl=1 or 0.*) RL:=DIPNOV(A);
      IF RL = 1 THEN TL:=1; RETURN(TL); END;
      IF RL = 0 THEN TL:=-1; RETURN(TL); END;
(*2*) (*check exponent vectors.*) TL:=0; DIPMAD(A, AL,EL,AP);
      V:=EVDOV(EL);
      IF V = SIL THEN TL:=-1; RETURN(TL); END;
      IF RED(V) <> SIL THEN RETURN(TL); END;
      WHILE AP <> SIL DO DIPMAD(AP, AL,EL,AP); V1:=EVDOV(EL);
            IF V1 <> SIL THEN
               IF EQUAL(V,V1) = 0 THEN RETURN(TL); END;
               END;
            END;
      J1Y:=RL+1; J2Y:=FIRST(V); TL:=J1Y-J2Y;
(*5*) RETURN(TL); END DIPUV;
 

PROCEDURE EPREAD(): LIST; 
(*Exponent read.  If ** is found in the input stream
then e=AREAD, else e=1. *)
VAR  C, EL, IDUM: LIST; 
BEGIN
(*1*) (*read **. *) EL:=1; C:=CREADB(); 
      IF C = MASORD("^") THEN EL:=AREAD(); RETURN(EL); END; 
      IF C <> MASORD("*") THEN BKSP; ELSE C:=CREAD(); 
         IF C <> MASORD("*") THEN BKSP; BKSP; ELSE EL:=AREAD(); END; 
         END; 
(*4*) RETURN(EL); END EPREAD; 


PROCEDURE EVCADD(U,IL,EL: LIST;    VAR V,FL: LIST);
(*Exponent vector component add. U=(u1, ...,ur) is an
exponent vector of length r, e is added to the i-th component,
1 le i le r, f=ui+e, V=(u1, ...,ui+e, ...,ur). *)
VAR  GL, J, UP, UPS, VP: LIST;
BEGIN
(*1*) (*u=() or il=0.*)
      IF (IL = 0) OR (U = SIL) THEN V:=U; FL:=0; RETURN; END;
(*2*) (*general case.*) UP:=U; VP:=BETA;
      FOR J:=1 TO IL-1 DO ADV(UP, GL,UP); VP:=COMP(GL,VP); END;
      ADV(UP, GL,UP); FL:=GL+EL; UPS:=COMP(FL,UP);
(*3*) (*finish.*)
      IF VP = SIL THEN V:=UPS; ELSE V:=INV(VP); SRED(VP,UPS); END;
      RETURN;
(*6*) END EVCADD;


PROCEDURE EVCOMP(U,V: LIST): LIST;
(*Exponent vector compare. U=(u1, ...,ur), V=(v1, ...vr)
are exponent vectors. r is the length of U and V.
t=0 if U eq V. t=1 if U gt V. t=-1 if U lt V. eq, gt, lt
with respect to the ordering of the exponent vectors specified
in the global variable EVORD. Lexicographical, inverse
lexicographical, graded lexicograhpical, inverse graded
lexicographical orderings are possible. *)
VAR  TL: LIST;
BEGIN
(*1*) (*compare with linear form. *)
      IF EVORD > SIL THEN TL:=EVLFCP(EVORD,U,V); 
         IF TL = 0 THEN 
            IF EQUAL(U,V) = 0 THEN
               SWRITE("LF ="); OWRITE(EVORD); BLINES(0);
               SWRITE("U  ="); OWRITE(U); BLINES(0);
               SWRITE("V  ="); OWRITE(V); BLINES(0);
               ERROR(severe,"EVCOMP: Linear form not linear independent.");
               END; 
            END;
         RETURN(TL) END;
(*2*) (*compare with evord.*)
      CASE INTEGER(EVORD) OF
           LEX             : TL:=-EVILCP(U,V) |
           INVLEX          : TL:= EVILCP(U,V) |
           GRLEX           : TL:=-EVIGLC(U,V) |
           IGRLEX          : TL:= EVIGLC(U,V) |
           REVLEX          : TL:=-EVILCI(U,V) |
           REVILEX         : TL:= EVILCI(U,V) |
           REVTDEG         : TL:=-EVITDC(U,V) |
           REVITDG         : TL:= EVITDC(U,V) 
               ELSE ERROR(severe,"EVCOMP, undefined term order.") END;
(*4*) RETURN(TL); END EVCOMP;


PROCEDURE EVCSUB(U,IL,EL: LIST;    VAR V,FL: LIST);
(*Exponent vector component subtract. U=(u1, ...,ur) is an
exponent vector of length r, e is subtracted from the i-th
component, 1 le i le r, V=(u1, ...,ui-e, ...,ur), f=ui. *)
VAR  GL, J, UP, UPS, VP: LIST;
BEGIN
(*1*) (*il=0 or u=().*)
      IF (IL = 0) OR (U = SIL) THEN V:=U; FL:=0; RETURN; END;
(*2*) (*general case.*) UP:=U; VP:=BETA;
      FOR J:=1 TO IL-1 DO ADV(UP, FL,UP); VP:=COMP(FL,VP); END;
      ADV(UP, FL,UP); GL:=FL-EL; UPS:=COMP(GL,UP);
(*3*) (*finish.*)
      IF VP = SIL THEN V:=UPS; ELSE V:=INV(VP); SRED(VP,UPS); END;
      RETURN;
(*6*) END EVCSUB;


PROCEDURE EVDEL(U,IL: LIST;    VAR V,EL: LIST);
(*Exponent vector delete. U=(u1, ...,ur) is an exponent vector
of length r. i is the component to be deleted, 1 le i le r.
V=(u1, ...,ui-1,ui+1, ...,ur),  e=ui.*)
VAR  J, UP, VP: LIST;
BEGIN
(*1*) (*u=() or il=0.*)
      IF (U = SIL) OR (IL = 0) THEN V:=U; EL:=0; RETURN; END;
(*2*) (*gerneral case.*) UP:=U; VP:=BETA;
      FOR J:=1 TO IL-1 DO ADV(UP, EL,UP); VP:=COMP(EL,VP); END;
      ADV(UP, EL,UP);
      IF VP = SIL THEN V:=UP; ELSE V:=INV(VP); SRED(VP,UP); END;
      RETURN;
(*5*) END EVDEL;


PROCEDURE EVDER(U,IL,EL: LIST;    VAR V,FL: LIST);
(*Exponent vector derivation. U=(u1, ...,ur) is an exponent
vector of length r, from the i-th component e-times one is
subtracted and f is multiplied with the result.
V=(u1, ...,ui-e, ...,ur). If f=0 then V is undefined. *)
VAR  DL, J, KL, UP, UPS, VP: LIST;
BEGIN
(*1*) (*u=().*) FL:=0;
      IF U = SIL THEN RETURN; END;
(*2*) (*bulidt derivation.*) UP:=U; VP:=BETA;
      FOR J:=1 TO IL-1 DO ADV(UP, DL,UP); VP:=COMP(DL,VP); END;
      ADV(UP, DL,UP);
      IF EL > DL THEN RETURN; END;
      FL:=DL;
      FOR KL:=DL-1 TO DL-EL+1 BY -1 DO FL:=IPROD(FL,KL); END;
(*3*) (*finish.*) UPS:=COMP(KL,UP);
      IF VP = SIL THEN V:=UPS; ELSE V:=INV(VP); SRED(VP,UPS); END;
      RETURN;
(*6*) END EVDER;


PROCEDURE EVDFSI(U,V: LIST;    VAR W,SL: LIST);
(*Exponent vector difference and sign. U=(u1, ...,ur),
V=(v1, ...,vr) are exponent vectors of length r.
W=(w1, ...,wr) is the componentwise difference of U and V.
s is the EVSIGN of W. If s=-1 then W is undefined.*)
VAR  UL, US, VL, VS, WL: LIST;
BEGIN
(*1*) (*u=() and v=().*) W:=BETA; SL:=0;
      IF U = SIL THEN RETURN; END;
(*2*) (*subtract.*) US:=U; VS:=V;
      REPEAT ADV(US, UL,US); ADV(VS, VL,VS); WL:=UL-VL;
             IF WL < 0 THEN SL:=-1; RETURN; END;
             IF WL > 0 THEN SL:=1; END;
             W:=COMP(WL,W);
             UNTIL US = SIL;
(*3*) (*finish.*) W:=INV(W); RETURN;
(*6*) END EVDFSI;


PROCEDURE EVDIF(U,V: LIST): LIST;
(*Exponent vector difference. U=(u1, ...,ur), V=(v1, ...,vr)
are exponent vectors of length r. W=(w1, ...,wr) is the
componentwise difference of U and V.*)
VAR  UL, US, VL, VS, W, WL: LIST;
BEGIN
(*1*) (*u=() and v=().*) W:=BETA;
      IF U = SIL THEN RETURN(W); END;
      US:=U; VS:=V;
(*2*) (*subtract components.*)
      REPEAT ADV(US, UL,US); ADV(VS, VL,VS); WL:=UL-VL; W:=COMP(WL,W);
             UNTIL US = SIL;
(*3*) (*finish.*) W:=INV(W); RETURN(W);
(*6*) END EVDIF;


PROCEDURE EVDOV(U: LIST): LIST;
(*Exponent vector dependency on variables. U is an exponent
vector. V is the list (j1, ...,jn) where each
j is the index of a variable with non zero exponent in U. *)
VAR  JL, UL, US, V: LIST;
BEGIN
(*1*) (*initialise.*) V:=BETA; US:=U; JL:=0;
(*2*) (*test exponents.*)
      WHILE US <> SIL DO JL:=JL+1; ADV(US, UL,US);
            IF UL <> 0 THEN V:=COMP(JL,V); END;
            END;
      V:=INV(V);
(*5*) RETURN(V); END EVDOV;


PROCEDURE EVEXC(U,IL,JL: LIST): LIST;
(*Exponent vector exchange. U=(u1, ...,ui, ...,uj, ...,ur)
is an exponent vector of length r. The components ui and uj are 
exchanged, 1 le i lt j le r. V=(u1, ...,uj, ...,ui, ...,ur).*)
VAR  J, V, V1, VL, VL1, VL2, VP, VPS, VS1, VS2: LIST;
BEGIN
(*1*) (*initialise.*) VS1:=BETA; VS2:=BETA; VP:=U;
(*2*) (*step to il and jl.*)
      FOR J:=1 TO IL-1 DO ADV(VP, VL,VP); VS1:=COMP(VL,VS1); END;
      ADV(VP, VL1,VP);
      FOR J:=1 TO JL-IL-1 DO ADV(VP, VL,VP); VS2:=COMP(VL,VS2); END;
      ADV(VP, VL2,VP);
(*3*) (*exchange.*) VPS:=COMP(VL1,VP);
      IF VS2 = SIL THEN V1:=VPS; ELSE V1:=INV(VS2); SRED(VS2,VPS);
         END;
      V1:=COMP(VL2,V1);
      IF VS1 = SIL THEN V:=V1; ELSE V:=INV(VS1); SRED(VS1,V1); END;
      RETURN(V);
(*6*) END EVEXC;


PROCEDURE EVIGLC(U,V: LIST): LIST;
(*Exponent vector inverse graded lexicographical compare.
U=(u1, ...,ur), V=(v1, ...vr) are exponent vectors.
t=0 if U eq V. t=1 if U gt V. t=-1 if U lt V. eq, gt, lt
with respect to the inverse graded lexicographical ordering
of the exponent vectors. r is the length of U and V.*)
VAR  TL, UL, ULP, US, VL, VLP, VS: LIST;
BEGIN
(*1*) (*lexicographical compare.*) TL:=0; US:=U; VS:=V;
      LOOP IF US = SIL THEN EXIT END; 
           ADV(US, UL,US); ADV(VS, VL,VS);
           IF UL > VL THEN TL:=1; EXIT; ELSE
              IF UL < VL THEN TL:=-1; EXIT; END;
              END;
           END;
      IF TL = 0 THEN RETURN(TL) END;
(*2*) (*graduaded compare.*)
      WHILE US <> SIL DO ADV(US, ULP,US); ADV(VS, VLP,VS); UL:=UL+ULP;
            VL:=VL+VLP; END;
      IF UL > VL THEN TL:=1; ELSE
         IF UL < VL THEN TL:=-1; END;
         END;
      RETURN(TL);
(*5*) END EVIGLC;


PROCEDURE EVILCI(U,V: LIST): LIST;
(*Exponent vector inverse lexicographical compare inverse exponent vector. 
U=(u1, ...,ur), V=(v1, ...vr) are exponent vectors.
t=0 if U eq V. t=1 if U gt V. t=-1 if U lt V. eq, gt,
lt with respect to the inverse lexicographical ordering
of the exponent vectors. r is the length of U and V.*)
VAR  TL, UP, VP: LIST;
BEGIN
(*1*) (*reverse exponent vectors. *) UP:=CINV(U); VP:=CINV(V);
      TL:=EVILCP(UP,VP);
(*4*) RETURN(TL); END EVILCI;


PROCEDURE EVILCP(U,V: LIST): LIST;
(*Exponent vector inverse lexicographical compare.
U=(u1, ...,ur), V=(v1, ...vr) are exponent vectors.
t=0 if U eq V. t=1 if U gt V. t=-1 if U lt V. eq, gt,
lt with respect to the inverse lexicographical ordering
of the exponent vectors. r is the length of U and V.*)
VAR  TL, UL, US, VL, VS: LIST;
BEGIN
(*1*) (*initialise and compare.*) TL:=0; US:=U; VS:=V;
      WHILE US <> SIL DO ADV(US, UL,US); ADV(VS, VL,VS);
            IF UL > VL THEN TL:=1; RETURN(TL); END;
            IF UL < VL THEN TL:=-1; RETURN(TL); END;
            END;
      RETURN(TL);
(*4*) END EVILCP;


PROCEDURE EVITDC(U,V: LIST): LIST;
(*Exponent vector inverse total degree compare.
U=(u1, ...,ur), V=(v1, ...vr) are exponent vectors.
t=0 if U eq V. t=1 if U gt V. t=-1 if U lt V. eq, gt, lt
with respect to buchbergers total degree ordering
of the exponent vectors. r is the length of U and V.*)
VAR  TL, UL, ULP, US, VL, VLP, VS: LIST;
BEGIN
(*1*) (*lexicographical compare.*) TL:=0; US:=CINV(U); VS:=CINV(V);
      LOOP IF US =SIL THEN EXIT END; 
            ADV(US, UL,US); ADV(VS, VL,VS);
            IF UL < VL THEN TL:=1; EXIT; ELSE
               IF UL > VL THEN TL:=-1; EXIT; END;
               END;
            END;
      IF TL = 0 THEN RETURN(TL) END;
(*2*) (*graduated compare.*)
      WHILE US <> SIL DO ADV(US, ULP,US); ADV(VS, VLP,VS); UL:=UL+ULP;
            VL:=VL+VLP; END;
      IF UL > VL THEN TL:=1; ELSE
         IF UL < VL THEN TL:=-1; END;
         END;
      RETURN(TL);
(*5*) END EVITDC;


PROCEDURE EVLFCP(L,U,V: LIST): LIST;
(*Exponent vector linear form compare. U=(u1, ...,ur),
V=(v1, ...,vr) are exponent vectors of length r.
L is an univariate integral polynomial vector.
t=0 if U eq V. t=1 if U gt V. t=-1 if U lt V. eq, gt, lt
with respect to the ordering of the exponent vectors 
determined by the linear form.*)
VAR  SL, TL, EL, FL, UL, US, VL, VS: LIST;
BEGIN
(*1*) (*compute inner products. *)
      US:=VIPIIP(1,L,U);  VS:=VIPIIP(1,L,V);
(*1*) (*compare polynomials.*) TL:=0; 
      WHILE (US <> 0) AND (VS <> 0) DO 
            ADV(US, EL,US); ADV(VS, FL,VS);
            IF EL > FL THEN TL:=1; RETURN(TL); END;
            IF EL < FL THEN TL:=-1; RETURN(TL); END;
            ADV(US, UL,US); ADV(VS, VL,VS);
            IF US = SIL THEN US:=0 END;
            IF VS = SIL THEN VS:=0 END;
            SL:=ICOMP(UL,VL);
            IF SL > 0 THEN TL:=1; RETURN(TL); END;
            IF SL < 0 THEN TL:=-1; RETURN(TL); END;
            END;
      IF US <> 0 THEN TL:=1; RETURN(TL); END;
      IF VS <> 0 THEN TL:=-1; RETURN(TL); END;
      RETURN(TL);
(*4*) END EVLFCP;


PROCEDURE EVLCM(U,V: LIST): LIST;
(*Exponent vector least common multiple. U=(u1, ...,ur),
V=(v1, ...,vr) are exponent vectors of length r.
W=(w1, ...,wr) is the least common multiple of U and V. *)
VAR  UL, US, VL, VS, W, WL: LIST;
BEGIN
(*1*) (*u=() and v=().*) W:=BETA;
      IF U = SIL THEN RETURN(W); END;
      US:=U; VS:=V;
(*2*) (*maximum of components.*)
      REPEAT ADV(US, UL,US); ADV(VS, VL,VS);
             IF UL > VL THEN WL:=UL; ELSE WL:=VL; END;
             W:=COMP(WL,W);
             UNTIL US = SIL;
(*3*) (*finish.*) W:=INV(W); RETURN(W);
(*6*) END EVLCM;


PROCEDURE EVMT(U,V: LIST): LIST;
(*Exponent vector multiple test. U=(u1, ...,ur),
V=(v1, ...,vr) are exponent vectors of length r.
t=1 if U is a multiple of V, t=0 else. *)
VAR  TL, UL, US, VL, VS: LIST;
BEGIN
(*1*) (*u=() and v=().*) TL:=1;
      IF U = SIL THEN RETURN(TL); END;
      US:=U; VS:=V;
(*2*) (*maximum of components.*)
      REPEAT ADV(US, UL,US); ADV(VS, VL,VS);
             IF UL < VL THEN TL:=0; RETURN(TL); END;
             UNTIL US = SIL;
(*5*) RETURN(TL); END EVMT;


PROCEDURE EVNNZE(U: LIST): LIST;
(*Exponent vector number of non zero exponents. U is an
exponent vector. n is the number of non zero exponents of U. *)
VAR  NL, UL, US: LIST;
BEGIN
(*1*) (*initialise.*) NL:=0; US:=U;
(*2*) (*test exponents.*)
      WHILE US <> SIL DO ADV(US, UL,US);
            IF UL <> 0 THEN NL:=NL+1; END;
            END;
(*5*) RETURN(NL); END EVNNZE;

PROCEDURE EVOWRITE(EVO: LIST);
(*Exponent vector order write.
EVO is an exponent vector order. A description of EVO is written to the
output stream.
inverse refers to the order of variables (in VALIS).
ascending means the inverted order (if x<y then x>y wrt. the inverted order).
*)

VAR O: LIST;

BEGIN
     CASE EVO OF
     	  LEX     : SWRITE("ascending inverse lexicographical order"); |
     	  INVLEX  : SWRITE("inverse lexicographical term order"); |
     	  GRLEX   : SWRITE("ascending graded (total degree) invers lexicographical order"); |
     	  IGRLEX  : SWRITE("graded (total degree) invers lexicographical termorder"); |
	  REVLEX  : SWRITE("ascending lexicographical order"); |
	  REVILEX : SWRITE("lexicographical term order"); |
	  REVTDEG : SWRITE("ascending total degree Buchberger lexicographical order"); |
	  REVITDG : SWRITE("total degree Buchberger lexicographical term order"); |
	  ELSE IF EVO <= SIL
	         THEN SWRITE("garbage passed to EVOWRITE");
     	       	 ELSE 
     	       	     EvordPush(INVLEX);
	             DIILWR(INV(DILFPL(1,EVO)),LIST1(LIST1(MASORD("T")))); 
     	       	     EvordPop();
     	         END;
         END;
END EVOWRITE;

PROCEDURE EvordWrite();
(* Evord Write.
Writes a description of EVORD to the output stream. *)
BEGIN
     EVOWRITE(EVORD);
END EvordWrite;

PROCEDURE EVRAND(RL,KL: LIST): LIST;
(*Exponent vector random. r is the length of U. k is a
positive beta-digit such that every component of U will be
less than k and k lt beta. U is a random exponent vector.*)
VAR  DL, EL, FL, I, IDUM, U: LIST;
BEGIN
(*1*) (*prepare for high order bits of drann.*)
      IF KL <= 0 THEN FL:=BETA; ELSE FL:=BETA DIV KL; END;
(*2*) (*get random components.*) U:=BETA;
      FOR I:=1 TO RL DO DL:=DRANN(); EL:=DL DIV FL; U:=COMP(EL,U); END;
      RETURN(U);
(*5*) END EVRAND;


PROCEDURE EVRASP(RL,KL,QL: LIST): LIST;
(*Exponent vector random. r is the length of U. k is a
positive beta-digit such that every component of U will be
less than k and k lt beta. U is a random exponent vector.*)
VAR  DL, EL, FL, GL, I, IDUM, U: LIST;
BEGIN
(*1*) (*prepare for high order bits of drann.*)
      IF KL <= 0 THEN FL:=BETA; ELSE FL:=BETA DIV KL; END;
(*2*) (*get random components.*) U:=BETA;
      FOR I:=1 TO RL DO GL:=DRANN();
          IF GL < QL THEN DL:=DRANN(); EL:=DL DIV FL; ELSE EL:=0;
          END;
          U:=COMP(EL,U); END;
      RETURN(U);
(*5*) END EVRASP;


PROCEDURE EVSIGN(U: LIST): LIST;
(*Exponent vector signum. U=(u1, ...,ur) is an exponent vector
of length r. t=0 if all components are eq 0, t=1 if all
components are ge 0, else t=-1.*)
VAR  TL, UL, US: LIST;
BEGIN
(*1*) (*check components.*) TL:=0; US:=U;
      WHILE US <> SIL DO ADV(US, UL,US);
            IF UL < 0 THEN TL:=-1; RETURN(TL); END;
            IF UL > 0 THEN TL:=1; END;
            END;
      RETURN(TL);
(*4*) END EVSIGN;


PROCEDURE EVSU(U,IL,FL: LIST;    VAR V,EL: LIST);
(*Exponent vector substitution. U=(u1, ...,ui, ...,ur)
is an exponent vector of length r. The i-th component is
changed into f. 1 le i le r. e=ui. 
V=(u1, ...,ui-1,f,ui+1, ...,ur). *)
VAR  J, UP, VP: LIST;
BEGIN
(*1*) (*u=() or il=0.*)
      IF (U = SIL) OR (IL = 0) THEN V:=U; EL:=0; RETURN; END;
(*2*) (*gerneral case.*) UP:=U; VP:=BETA;
      FOR J:=1 TO IL-1 DO ADV(UP, EL,UP); VP:=COMP(EL,VP); END;
      ADV(UP, EL,UP); VP:=COMP(FL,VP); V:=INV(VP); SRED(VP,UP); RETURN;
(*5*) END EVSU;


PROCEDURE EVSUM(U,V: LIST): LIST;
(*Exponent vector sum. U=(u1, ...,ur), V=(v1, ...,vr) are
exponent vectors of length r. W=(u1+v1, ...,ur+vr) is the
componentwise sum of U and V. *)
VAR  UL, US, VL, VS, W, WL: LIST;
BEGIN
(*1*) (*u=() and v=().*) W:=BETA;
      IF U = SIL THEN RETURN(W); END;
(*2*) (*add components.*) US:=U; VS:=V;
      REPEAT ADV(US, UL,US); ADV(VS, VL,VS); WL:=UL+VL; W:=COMP(WL,W);
             UNTIL US = SIL;
(*3*) (*finish.*) W:=INV(W); RETURN(W);
(*6*) END EVSUM;


PROCEDURE EVTDEG(U: LIST): LIST;
(*Exponent vector total degree. U is an exponent vector.
n is the sum of the components of U.*)
VAR  NL, UL, US: LIST;
BEGIN
(*1*) (*initialise.*) NL:=0; US:=U;
(*2*) (*sum.*)
      WHILE US <> SIL DO ADV(US, UL,US); NL:=NL+UL; END;
      RETURN(NL);
(*5*) END EVTDEG;


PROCEDURE PBCLI(RL,A: LIST): LIST;
(*Polynomial base coefficients list. A is a polynomial in
r variables. B is the list of the base coefficients of A. *)
VAR  AL, ALS, AP, AS, B, BL, BP, BS, EL, ELS, RLP: LIST;
BEGIN
(*1*) (*a=0 or rl=0.*)
      IF (A = 0) OR (RL = 0) THEN B:=LIST1(A); RETURN(B); END;
(*2*) (*rl=1.*)
      IF RL = 1 THEN AS:=A; B:=BETA;
         REPEAT ADV2(AS, ELS,ALS,AS); B:=COMP(ALS,B);
                UNTIL AS = SIL;
         B:=INV(B); RETURN(B); END;
(*3*) (*general case. *) AP:=A; B:=LIST1(0); BP:=B; RLP:=RL-1;
      REPEAT ADV2(AP, EL,AL,AP); BL:=PBCLI(RLP,AL); BS:=LAST(BL);
             SRED(BP,BL); BP:=BS;
             UNTIL AP = SIL;
      B:=RED(B);
(*6*) RETURN(B); END PBCLI;


PROCEDURE PFDIP(A: LIST;    VAR RL,B: LIST);
(*Polynomial from distributive polynomial. A is a distributive
polynomial. B is the result of converting A to recursive
representation, r is the number of variables of B, r ge 0.
Modified version, original version by G. E. Collins. *)
VAR  A1, AL1, AS, B1, E1, EL, EL1, FL, RLS, SL: LIST;
BEGIN
(*1*) (*rl=0 or a=0.*)
      IF A = 0 THEN RL:=0; B:=0; RETURN; END;
      RL:=DIPNOV(A);
      IF RL = 0 THEN B:=DIPLBC(A); RETURN; END;
(*2*) (*rl=1.*) B:=BETA; AS:=A; RLS:=RL-1;
      IF RLS = 0 THEN 
         REPEAT DIPMAD(AS, AL1,E1,AS); EL1:=FIRST(E1); B:=COMP2(AL1,EL1,B);
                UNTIL AS = SIL;
         B:=INV(B); RETURN END;
(*3*) (*recursion.*)
      REPEAT DIPADM(AS, EL,FL,A1,AS); PFDIP(A1, SL,B1);
             B:=COMP2(B1,EL,B);
             UNTIL AS = 0;
      B:=INV(B); RETURN;
(*6*) END PFDIP;


PROCEDURE PLFDIL(A: LIST;    VAR RL,B: LIST);
(*Polynomial list from distributive polynom list. A is a list
of distributive polynomials in r variables, r ge 0. Every
polynomial in A is converted to recursive representation and
stored in B. *)
VAR  AL, AP, BL: LIST;
BEGIN
(*1*) (*convert polynomials. *) AP:=A; B:=BETA;
      WHILE AP <> SIL DO ADV(AP, AL,AP); PFDIP(AL, RL,BL);
            B:=COMP(BL,B); END;
      B:=INV(B);
(*4*) RETURN; END PLFDIL;


PROCEDURE PMPV(RL,A,IL,NL: LIST): LIST;
(*Polynomial multiplication by power of variable.  A is
a polynomial in r variables. 1 le i le r
and n is a beta-integer. B=A*(x sub i)**n. *)
VAR  AL, AP, B, BL, EL, FL, RLP: LIST;
BEGIN
(*1*) (*a=0 or n=0.*)
      IF (A = 0) OR (NL = 0) THEN B:=A; RETURN(B); END;
(*2*) (*general case.*) AP:=A; B:=BETA; RLP:=RL-1;
      REPEAT ADV2(AP, EL,AL,AP);
             IF IL = RL THEN BL:=AL; FL:=EL+NL; ELSE
                BL:=PMPV(RLP,AL,IL,NL); FL:=EL; END;
             B:=COMP2(BL,FL,B);
             UNTIL AP = SIL;
      B:=INV(B);
(*5*) RETURN(B); END PMPV;


PROCEDURE PPERMV(RL,A,P: LIST): LIST;
(*Polynomial permutation of variables.  A is a polynomial in
r variables, r ge 0. P is a list (p sub 1, ...,p sub r)
whose elements are the beta-digits 1 through r.
B(x sub (p sub 1), ...,x sub (p sub r))=A(x sub 1, ...,
x sub r).*)
VAR  AP, B, BP, RLS: LIST;
BEGIN
(*1*) (*a=0. *)
      IF A = 0 THEN B:=0; RETURN(B); END;
(*2*) (*use distributive representation for permutation.*)
      AP:=DIPFP(RL,A); BP:=DIPERM(AP,P); PFDIP(BP, RLS,B);
(*5*) RETURN(B); END PPERMV;


PROCEDURE STVL(RL: LIST): LIST; 
(*Standard variable list. r is the number of variables.
V is the variable list for the variables x1, ...,xr. *)
VAR  K, KL, R, V, VL, X: LIST; 
BEGIN
(*1*) (*construct list.*) V:=BETA; X:=MASORD("X"); 
      FOR K:=RL TO 1 BY -1 DO KL:=K; VL:=BETA; 
          WHILE KL > 9 DO DQR(0,KL,10, KL,R); VL:=COMP(R,VL); END; 
          VL:=COMP2(X,KL,VL); V:=COMP(VL,V); END; 
      RETURN(V); 
(*4*) END STVL; 


PROCEDURE DIP2AD(P,d,rest: LIST): LIST;
(* distributive polynomial to arbitrary domain.
   P is a polynomial in distributive representation,
   d is a domain number, rest is a domain descriptor,
   returns P with added domain numbers and descriptors *)
VAR P1,exp,coe: LIST;
BEGIN
   P1:=SIL;
   WHILE P<>SIL DO
      ADV(P,exp,P);
      P1:=COMP(exp,P1);
      ADV(P,coe,P);
      P1:=COMP(COMP(d,COMP(coe,rest)),P1);
   END; (* while... *)
   P1:=INV(P1);
   RETURN(P1);
END DIP2AD;


PROCEDURE AD2DIP(P: LIST): LIST;
(* arbitrary domain to distributive polynomial.
   P is a polynomial in distributive representation
   with domain numbers and descriptors,
   returns P without domain numbers and descriptors *)
VAR P1,exp,coe,val: LIST;
BEGIN
   P1:=SIL;
   WHILE P<>SIL DO
      ADV(P,exp,P);
      P1:=COMP(exp,P1);
      ADV(P,coe,P);
      P1:=COMP(SECOND(coe),P1);
   END; (* while... *)
   P1:=INV(P1);
   RETURN(P1);
END AD2DIP;


BEGIN

BEGIND;

END DIPC.


(* -EOF- *)
