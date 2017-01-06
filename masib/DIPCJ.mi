(* ----------------------------------------------------------------------------
 * $Id: DIPCJ.mi,v 1.1 1995/10/12 14:44:47 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPCJ.mi,v $
 * Revision 1.1  1995/10/12 14:44:47  pesch
 * Diplomarbeit Rainer Grosse-Gehling.
 * Involutive Bases.
 * Slightly edited.
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DIPCJ;
(* DIP Common Polynomial System Implementation Module. Functions for 
   Janet-Reduction. *)

(* Import lists and declarations. *)

FROM DIPADOM 	IMPORT 	DIPMOC;

FROM DIPC 	IMPORT 	DIPEVL, DIPEVP, DIPMAD, EVCOMP, EVSUM, EVTDEG;

FROM DIPI 	IMPORT 	DIIPCP;

FROM MASLISPU 	IMPORT 	PROCF1; 

FROM MASSTOR 	IMPORT 	ADV, COMP, FIRST, INV, LENGTH, LIST, LIST1, RED,
			SFIRST, SIL;

FROM SACLIST 	IMPORT 	CINV, CONC;

CONST rcsidi = "$Id: DIPCJ.mi,v 1.1 1995/10/12 14:44:47 pesch Exp $";
CONST copyrighti = "Copyright (c) 1995 Universitaet Passau";      


PROCEDURE ADDTDG(deg, P: LIST): LIST;
(* Add total degree.
   Input: polynomial degree deg & polynomial P in distributive 
          list representation.
   Output: polynom P with first list entry now total degree of the
           leading exponent vector. *)
BEGIN
     P:=COMP(deg,P);
     RETURN(P);
END ADDTDG;


PROCEDURE ADVTDG(P: LIST; VAR p, PP: LIST);
(* Advance total degree.
   Input: polynom P in distributive list representation. The first entry of the
          list is the total degree of the leading exponent vector.
   Output: p - the first entry of the list; PP - the polynom without the
           first entry *)
BEGIN
     ADV(P,p,PP); 
END ADVTDG;


PROCEDURE DILEBBS(A: LIST);
(* Distributive List Extended Bubble Sort.
   Sort a list of polynoms in decreasing order of the total degree of the
   leading exponent. The total degree must be the first entry of each polynom. 
   Input: A is a list of polynoms.
   A is changed *)
VAR B,AP,ap,APP,BP,ev1,app,DUMMY,ev2: LIST;
BEGIN
    IF (A=0) OR (LENGTH(A)=1) THEN RETURN END;
    B:=SIL;
    REPEAT AP:=A; ADV(AP,ap,APP); BP:=SIL; ev1:=FIRST(ap); 
           WHILE APP<>B DO ADV(APP,app,DUMMY); ev2:=FIRST(app); 
                 IF (ev2>0) AND ((ev1>ev2) OR (ev1=0)) 
                    THEN SFIRST(AP,app); SFIRST(APP,ap); BP:=APP; 
                    ELSE ap:=app; ev1:=ev2;
                 END;
                 AP:=APP; APP:=RED(AP);
           END;
           B:=BP;
    UNTIL B=SIL;
    RETURN;
END DILEBBS;


PROCEDURE DILBBS(A: LIST);
(* Distributive List Bubble Sort.
   Sort a list of polynoms in decreasing order of the total degree of the
   leading exponent.
   Input: A is a list of polynoms.
   A is changed *)
VAR B,AP,ap,APP,BP,ev1,app,DUMMY,ev2: LIST;
BEGIN
    IF (A=0) OR (LENGTH(A)=1) THEN RETURN END;
    B:=SIL;
    REPEAT AP:=A; ADV(AP,ap,APP); BP:=SIL; ev1:=EVTDEG(FIRST(ap)); 
           WHILE APP<>B DO ADV(APP,app,DUMMY); ev2:=EVTDEG(FIRST(app)); 
                 IF ev1>ev2 THEN SFIRST(AP,app); SFIRST(APP,ap); BP:=APP; 
                            ELSE ap:=app; ev1:=ev2;
                 END;
                 AP:=APP; APP:=RED(AP);
           END;
           B:=BP;
    UNTIL B=SIL;
    RETURN;
END DILEBBS;


PROCEDURE DILEP2P(P: LIST): LIST;
(* Distributive polynom list extended polynom to polynom.
   Input: P - a list of extended polynoms.
   Output: a list of polynoms whithout the first entry. *)
VAR PS, p, tdg: LIST;
BEGIN
  PS:=SIL;
  WHILE P<>SIL DO ADV(P,p,P); 
                  ADVTDG(p,tdg,p); 
                  PS:=COMP(p,PS); 
  END;
  RETURN(PS);
END DILEP2P; 


PROCEDURE DILATDG(P: LIST): LIST;
(* Distributive polynom list add total degree. 
   P is a list of distributive polynomials. 
   The result is a list of distributive polynoms with total
   degree of the leading term as first entry of each polynomial. *)
VAR PP,PL,PS: LIST;
BEGIN
  PP:=P; PS:=SIL;
  WHILE PP<>SIL DO ADV(PP,PL,PP); PL:=ADDTDG(EVTDEG(FIRST(PL)),PL); 
                  PS:=COMP(PL,PS);  
  END;
  RETURN(PS);
END DILATDG;


PROCEDURE DILTDG(A: LIST): LIST;
(* Distributive polynomial list total degree
   Input: A is a list of distributive polynomials, 
   Output tdg: the total degree of A *)
VAR tdg, TDG, PA, AL, EL: LIST;
BEGIN
  tdg:=0;
  WHILE A <> SIL DO ADV(A,PA,A); 
                    DIPMAD(PA, AL, EL, PA); TDG:=EVTDEG(EL);
                    IF tdg < TDG THEN tdg:=TDG END;
  END;
  RETURN(tdg); 
END DILTDG;


PROCEDURE DIPCLP(P: LIST): LIST;
(* Distributiv Polynomial Class of Polynomial.
   Input: P is a polynomial, 
   Output: t is the index of the lowest variable of the leading
           term of P, t=0 if P is Empty *)
VAR i, TA, TE, PP: LIST;
BEGIN
  i:=0;
  IF P=SIL THEN RETURN(i); END;
  DIPMAD(P, TA, TE, PP);
  i:=DIPCLT(TE); RETURN(i);
END DIPCLP;


PROCEDURE DIPCLT(P: LIST): LIST;
(* Distributiv Polynomial Class of Term.
   Input: P is a term, 
   Output: t is the index of the lowest variable in P,
           t=0 if P is empty *)
VAR i, PL, Q: LIST;
BEGIN
  i:=0; PL:=CINV(P);
  IF PL=SIL THEN RETURN(i); END;
  REPEAT ADV(PL,Q,PL); INC(i); UNTIL (Q<>0) OR (PL=SIL);
  RETURN(i);
END DIPCLT;


PROCEDURE DIPFIRST(P: LIST; extended: BOOLEAN; VAR pp, PP: LIST);
(* Distributive polynomial first polynomial,
   P is a list of polynomials,
   pp is the first polynomial and PP is the reductum of P.
*)
BEGIN
  ADV(P,pp,PP);
END DIPFIRST;


PROCEDURE DIPSSM(P: LIST; extended: BOOLEAN; VAR pp, PP: LIST);
(* Distributive polynomial sort and select minimal.
   Input: P - a list of polynoms,
          extended is TRUE iff the first entry of each polynomial in P is the
          total degree of the leading exponent vector.
   Output: pp - the minimal polynom w.r.t. the admissible term order.
           PP - sorted list of P without pp.
   P is changed *)
BEGIN
  IF extended THEN DILEBBS(P); ELSE DILBBS(P); END;
  ADV(P,pp,PP);
END DIPSSM;


PROCEDURE DILCAN(P: LIST; F: PROCF1): LIST;
(* Distributive Polynomial Cancel. 
   P is a list of distributive polynomials. F is the cancel-function.
   Output is a list of distributive polynomials or an empty list if all 
   polynomials in A equal 0. The coefficients of each polynomial are canceld
   down by F. *)
VAR PP, PL, PS: LIST;
BEGIN
  PP:=P; PS:=SIL;
  WHILE PP<>SIL DO ADV(PP,PL,PP); PL:=F(PL);
                   IF PL<>0 THEN PS:=COMP(PL,PS); END;
  END;
  RETURN(PS);
END DIPLMO;


PROCEDURE DIILPP(P: LIST): LIST;
(* Distributive integral polynomial list primitive part. 
   P is a list of distributive integral polynoms. The result is the positive
   primitive part of each polynomial in P. The list-order is reversed. *)
VAR PP,PL,PS,PC: LIST;
BEGIN
  PP:=P; PS:=SIL;  
  WHILE PP<>SIL DO ADV(PP,PL,PP); DIIPCP(PL,PC,PL);
                   IF PL<>0 THEN PS:=COMP(PL,PS); END;
  END;
  RETURN(PS);
END DIILPP;


PROCEDURE DIRPMV(A,B: LIST): LIST;
(* Distributiv Polynomial multiplication with a variable.
   Input: A is the polynomial, B is an exponent vector.
   Output:  A*B  *)
VAR S, A1, AA, AE, R: LIST;
BEGIN
  IF (A=0) OR (B=0) THEN RETURN(0); END;
  S:=SIL; A1:=CINV(A);
  REPEAT DIPMAD(A1,AE,AA,A1);
         R:=EVSUM(AE,B); S:=COMP(R, COMP(AA,S));
  UNTIL A1=SIL;
  RETURN(S);
END DIRPMV; 


PROCEDURE EVDIF2(U,V: LIST): LIST;
(* Exponent vector difference. 
   Input: U=(u1, ...,ur), V=(v1, ...,vr)
          are exponent vectors of length r. 
   Output: W=(w1, ...,wr) is the componentwise difference of U and V.
   Unlike procedure EVDIV this procedure returns 0 and not (0...0) if U=V *)
VAR W, WL, US, VS, c, UL, VL: LIST;
BEGIN
      W:=SIL;
      IF U = SIL THEN RETURN(W); END;
      US:=U; VS:=V; c:=0;
      REPEAT ADV(US, UL,US); ADV(VS, VL,VS); 
             WL:=UL-VL; W:=COMP(WL,W); c:=c+WL;
      UNTIL US = SIL;
      IF c>0 THEN W:=INV(W); ELSE W:=0 END; RETURN(W);
END EVDIF2;


PROCEDURE EVMTJ(U,V: LIST): LIST;
(* Exponent vector multiple test in the sense of Janet. 
   Input: U=(u1, ...,ur), V=(v1, ...,vr) are exponent vectors of length r.
   Output: t=1 if U is a multiple in the sense of Janet of V, t=0 else. *)
VAR US,VS,UL,VL: LIST;
BEGIN
   IF U=SIL THEN RETURN(1) END;
   IF V=SIL THEN RETURN(0) END;
   US:=U; VS:=V;
   REPEAT ADV(US, UL, US); ADV(VS, VL, VS) UNTIL (UL<>VL) OR (US=SIL);
   IF VL>UL THEN RETURN(0); ELSE
                 IF US=SIL THEN RETURN(1); END;
   END;
   REPEAT ADV(VS,VL,VS) UNTIL (VL>0) OR (VS=SIL);
   IF VL>0 THEN RETURN(0); ELSE RETURN(1) END;
END EVMTJ;


PROCEDURE DIPNML(G: LIST): LIST;
(* Distributive polynomial nonmultiple variable list.
   Compute for a polynom G the List of nonmultiplicative variables.
   Input: G is a polynomial.
   Output: a list of non-multiplicative variables for the leading term of G. *)
VAR F, E, e, le, A, f, B: LIST;
BEGIN
  IF G=SIL THEN RETURN(SIL); END;
  e:=CINV(DIPEVL(G)); 
  le :=LENGTH(e); A:=SIL; F:=SIL;
  REPEAT
      ADV(e,f,e); A:=COMP(0,A);    
  UNTIL (f<>0) OR (e = SIL); 
  WHILE LENGTH(A) < le DO
        B:=COMP(1,A); A:=COMP(0,A);
        WHILE LENGTH(B) < le DO B:=COMP(0,B) END;
        F:=COMP(LIST(B), F);
  END;
  RETURN(F);
END DIPNML;


PROCEDURE DIPPGL2(F, V, LL: LIST): LIST;
(* Distributive polynomial prolongation list.
   Input: F - polynomial which first entry is the total degree of the leading
              term; V - list of variables; LL - number of different variables 
	      in F.
   Output: PP - List of prolongations of F with non-multiplicative variables 
                for F from V. *) 
VAR PP,VV,clp,vv,P,gf: LIST;
BEGIN
  IF (F=SIL) OR (V=SIL) OR (LL=0) THEN RETURN(F) END;
  ADV(F,gf,F); gf:=gf+1;
  PP:=SIL; VV:=V; clp:=LL-DIPCLP(F); 
  IF clp = 0 THEN RETURN(PP) END; 
  WHILE clp > 0 DO
        ADV(VV,vv,VV); P:=DIPEVP(F,vv); 
        PP:=COMP(LIST(COMP(gf,P)),PP); clp:=clp-1;
  END;
  RETURN(PP);
END DIPPGL2;


PROCEDURE DIPPGL3(F, V, LL: LIST): LIST;
(* Distributive polynom prolongation list.
   Input: F - polynomial; V - list of variables; LL - number of variables in F.
   Output: PP - List of prolongations of F with non-multiplicative variables 
                for F from V. *) 
VAR PP,VV,clp,vv,P: LIST;
BEGIN
  IF (F=SIL) OR (V=SIL) OR (LL=0) THEN RETURN(F) END; 
  PP:=SIL; VV:=V; clp:=LL-DIPCLP(F); 
  IF clp = 0 THEN RETURN(PP) END; 
  WHILE clp > 0 DO
        ADV(VV,vv,VV); P:=DIPEVP(F,vv); 
        PP:=COMP(LIST(P),PP); clp:=clp-1;
  END;
  RETURN(PP);
END DIPPGL3;


PROCEDURE DIPPGL(V: LIST): LIST;
(* Distributive polynomial prolongation list. 
   Input: V - arbitrary domain polynomial.
   Output: List of prolongations of V with nonmultiplicative variables for V.*)
VAR F, e, LL, LLA, LLB, A, f, B, P: LIST;
BEGIN
  IF V=SIL THEN RETURN(SIL); END;
  e:=CINV(DIPEVL(V));
  LL:=LENGTH(e); LLA:=0; A:=SIL; F:=SIL;
  REPEAT
      ADV(e,f,e); A:=COMP(0,A); LLA:=LLA+1;   
  UNTIL (f<>0) OR (e = NIL); 
  WHILE LLA < LL DO
        B:=COMP(1,A); A:=COMP(0,A); LLA:=LLA+1; LLB:=LLA;
        WHILE LLB < LL DO B:=COMP(0,B); LLB:=LLB+1 END;
        P:=DIPEVP(V,B); F:=COMP(LIST(P), F);
  END;
  RETURN(F);
END DIPPGL;


PROCEDURE DIPVL(V: LIST): LIST;
(* Distributive Polynomial List of Variables.
   Input: a polynomial V.
   Output: list of variables with class > 1. *)
VAR A, F, LL, B, i: LIST;
BEGIN
  IF (V=SIL) OR (LENGTH(V)=0) THEN RETURN(SIL); END;
  A:=LIST1(0); F:=SIL; LL:=LENGTH(DIPEVL(V))-1;
  WHILE LL > 0 DO
        LL:=LL-1;
        B:=COMP(1,A); FOR i:=1 TO LL DO B:=COMP(0,B); END;
        F:=COMP(LIST(B),F);
        A:=COMP(0,A);
  END;
  RETURN(F);
END DIPVL;


END DIPCJ.

(* -EOF- *)
