(* ----------------------------------------------------------------------------
 * $Id: DIPCJ.md,v 1.2 1995/12/16 12:21:52 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPCJ.md,v $
 * Revision 1.2  1995/12/16 12:21:52  kredel
 * Comments slightly changed.
 *
 * Revision 1.1  1995/10/12  14:44:45  pesch
 * Diplomarbeit Rainer Grosse-Gehling.
 * Involutive Bases.
 * Slightly edited.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DIPCJ;

(* DIP Common Polynomial System Definition Module in the sense of Janet. *)

(* Import lists and declarations. *)

FROM MASSTOR 	IMPORT 	LIST;

FROM MASLISPU 	IMPORT 	PROCF1;

CONST rcsid = "$Id: DIPCJ.md,v 1.2 1995/12/16 12:21:52 kredel Exp $";
CONST copyright = "Copyright (c) 1995 Universitaet Passau";

PROCEDURE ADDTDG(deg, P: LIST): LIST;
(* Add total degree.
   Input: polynomial degree deg and polynomial P in distributive list
          representation.
   Output: polynom P with first list entry now total degree of the
           leading exponent vector. *)

PROCEDURE ADVTDG(P: LIST; VAR p, PP: LIST);
(* Advance total degree.
   Input: polynom P in distributive list representation. The first entry of the
          list is the total degree of the leading exponent vector.
   Output: p - the first entry of the list; PP - the polynom without the
           first entry *)

PROCEDURE DILEBBS(A: LIST);
(* Distributive List Extended Bubble Sort.
   Sort a list of polynoms in decreasing order of the total degree of the
   leading exponent. The total degree must be the first entry of each polynom. 
   Input: A is a list of polynoms.
   A is changed *)

PROCEDURE DILBBS(A: LIST);
(* Distributive List Bubble Sort.
   Sort a list of polynoms in decreasing order of the total degree of the
   leading exponent.
   Input: A is a list of polynoms.
   A is changed *)

PROCEDURE DILEP2P(P: LIST): LIST;
(* Distributive polynom list extended polynom to polynom.
   Input: P - a list of extended polynoms.
   Output: a list of polynoms whithout the first entry. *)

PROCEDURE DILATDG(P: LIST): LIST;
(* Distributive polynom list add total degree. 
   P is a list of distributive polynomials. 
   The result is a list of distributive polynoms with total
   degree of the leading term as first entry of each polynomial. *)

PROCEDURE DILTDG(A: LIST): LIST;
(* Distributive polynomial list total degree
   Input: A is a list of distributive polynomials, 
   Output tdg: the total degree of A *)

PROCEDURE DIPCLP(P: LIST): LIST;
(* Distributiv Polynomial Class of Polynomial.
   Input: P is a polynomial, 
   Output: t is the index of the lowest variable of the leading
           term of P, t=0 if P is Empty *)

PROCEDURE DIPCLT(P: LIST): LIST;
(* Distributiv Polynomial Class of Term.
   Input: P is a term, 
   Output: t is the index of the lowest variable in P,
           t=0 if P is empty *)

PROCEDURE DIPFIRST(P: LIST; extended: BOOLEAN; VAR pp, PP: LIST);
(* Distributive polynomial first polynomial,
   P is a list of polynomials,
   pp is the first polynomial and PP is the reductum of P.*)

PROCEDURE DIPSSM(P: LIST; extended: BOOLEAN; VAR pp, PP: LIST);
(* Distributive polynomial sort and select minimal.
   Input: P - a list of polynoms,
          extended is TRUE iff the first entry of each polynimial in P is the
          total degree of the leading exponent vector.
   Output: pp - the minimal polynom w.r.t. the admissible term order.
           PP - sorted list of P without pp.
   P is changed *)

PROCEDURE DILCAN(P: LIST; F: PROCF1): LIST;
(* Distributive Polynomial Cancel. 
   P is a list of distributive polynomials. F is the cancel-function.
   Output is a list of distributive polynomials or an empty list if all 
   polynomials in A equal 0. The coefficients of each polynomial are canceld
   down by F. *)

PROCEDURE DIILPP(P: LIST): LIST;
(* Distributive integral polynomial list primitive part. 
   P is a list of distributive integral polynoms. The result is the positive
   primitive part of each polynomial in P. The list-order is reversed. *)

PROCEDURE DIRPMV(A,B: LIST): LIST;
(* Distributiv Polynomial multiplication with a variable.
   Input: A is the polynomial, B is an exponent vector.
   Output:  A*B  *)

PROCEDURE EVDIF2(U,V: LIST): LIST;
(* Exponent vector difference. 
   Input: U=(u1, ...,ur), V=(v1, ...,vr)
          are exponent vectors of length r. 
   Output: W=(w1, ...,wr) is the componentwise difference of U and V.
   Unlike procedure EVDIV this procedure returns 0 and not (0...0) if U=V *)

PROCEDURE EVMTJ(U,V: LIST): LIST;
(* Exponent vector multiple test in the sense of Janet. 
   Input: U=(u1, ...,ur), V=(v1, ...,vr) are exponent vectors of length r.
   Output: t=1 if U is a multiple in the sense of Janet of V, t=0 else. *)

PROCEDURE DIPNML(G: LIST): LIST;
(* Distributive polynomial nonmultiple variable list.
   Compute for a polynom G the List of nonmultiplicative variables.
   Input: G is a polynomial.
   Output: a list of non-multiplicative variables for the leading term of G. *)

PROCEDURE DIPPGL2(F, V, LL: LIST): LIST;
(* Distributive polynomial prolongation list.
   Input: F - polynomial which first entry is the total degree of the leading
              term; V - list of variables; LL - number of different variables 
	      in F.
   Output: PP - List of prolongations of F with non-multiplicative variables 
                for F from V. *) 

PROCEDURE DIPPGL3(F, V, LL: LIST): LIST;
(* Distributive polynom prolongation list.
   Input: F - polynomial; V - list of variables; LL - number of variables in F.
   Output: PP - List of prolongations of F with non-multiplicative variables 
                for F from V. *) 

PROCEDURE DIPPGL(V: LIST): LIST;
(* Distributive polynomial prolongation list. 
   Input: V is an arbitrary domain polynomial.  
   Output: List of prolongations of V with nonmultiplicative variables for V.*)

PROCEDURE DIPVL(V: LIST): LIST;
(* Distributive Polynomial List of Variables.
   Input: a polynomial V.
   Output: list of variables with class > 1. *)


END DIPCJ.

(* -EOF- *)

