(* ----------------------------------------------------------------------------
 * $Id: CGBMISC.md,v 1.6 1995/03/06 15:49:40 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: CGBMISC.md,v $
 * Revision 1.6  1995/03/06  15:49:40  pesch
 * Added new procedure GSYSF, Groebner system with factorization. This uses
 * the new procedures GBSYSF and CONSGBF (also added).
 *
 * Added new procedures DIP2AD, AD2DIP and DIPPFACTAV.
 *
 * Fixed error in CHECK.
 *
 * New option for factorization of conditions: factorize with optimization
 * of variable ordering.
 *
 * Revision 1.5  1994/04/14  16:46:10  dolzmann
 * Syntactical errors (found by Mocka) corrected.
 *
 * Revision 1.4  1994/04/10  17:58:38  pesch
 * Added option to compute generic case (coeficients are considered
 * rational functions, the necessary non-zero conditions are collected) only.
 *
 * Revision 1.3  1994/04/09  18:05:59  pesch
 * Reformatted parts of the CGB sources. Updated comments in CGB*.md.
 *
 * Revision 1.2  1994/03/14  16:42:58  pesch
 * Minor changes requested by A. Dolzmann
 *
 * Revision 1.1  1994/03/12  17:43:15  pesch
 * Part of CGB.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE CGBMISC;

(* Comprehensive-Groebner-Bases Miscellaneous Programs Definition Module.*)
(* Import lists and declarations. *)

FROM MASSTOR	IMPORT	LIST;

CONST rcsid = "$Id: CGBMISC.md,v 1.6 1995/03/06 15:49:40 pesch Exp $";
CONST copyright = "Copyright (c) 1993 Universitaet Passau";

TYPE COLOUR = (zero, nzero, unknown);

TYPE CGBPAR = RECORD
     	       	    outputlevel: INTEGER; (* 0: quiet, >0: chatty *)
     	       	    factorize: INTEGER; (* 0: don't, 1: do, 2: with voo *)
     	       	    normalform: INTEGER; (* 0: top reduction, 1: normal red. *)
     	       	    compcond: INTEGER; (* 0: simple, 1: reduced set, 2: GB *)
     	            char: INTEGER; (* 0: characteristic 0; <>0 arbitr. char *)
     	       	    genericOnly: BOOLEAN; (* consider generic case  only? *)
     	       	    Factors: PROCEDURE(LIST): LIST; (* Factors of polynomial*)
     	       	    Factorize: PROCEDURE(LIST): LIST; (* factorization *)
     	       	    NormalForm: PROCEDURE(LIST,LIST,LIST,
     	       	    	      	   	  VAR LIST, VAR LIST);(* NFORM/NFTOP *)
     	       	    CondEval: PROCEDURE(LIST,LIST): COLOUR;
     	       	    CondRamif: PROCEDURE(LIST,LIST,VAR LIST,VAR LIST);
     	       	    IsCnst: PROCEDURE(LIST): BOOLEAN;
     	       	    TermOrderPol: LIST; (* Term Order for Polynomials *)
     	       	    TermOrderCoef: LIST; (* Term Order for Coefficients *)
     	       END;

VAR PAR: CGBPAR;


PROCEDURE EvordSet(T: LIST);
(* EVORD set.
T is a termorder.
The global variable EVORD is set to T.
The old value of EVORD is put on top of a stack and can be restored
using EvordReset(). *)

PROCEDURE EvordReset();
(* Reset evord.
The global variable EVORD is set to the top element of EVORDSTACK.
(EVORDSTACK is set by EvordSet().) *)

PROCEDURE ValisSet(V: LIST);
(* Set valis.
V is a variables list. The global variable VALIS is set to T.
The old value of VALIS is put on top of a stack and can be restored
using ValisReset(). *)

PROCEDURE ValisReset();
(* Reset valis.
The global variable VALIS is set to the top element of VALISSTACK.
(VALISSTACK is set by ValisSet().) *)

(*****************************************************************************)
(* Sets                                                                      *)
(*****************************************************************************)

PROCEDURE SetInsert(e, A: LIST): LIST;
(* Set insert.
A is a set.
e is an element.
Returns the set A U {e}.*)

PROCEDURE SetUnion(A,B: LIST): LIST;
(* Set union.
A is a set.
B is a set.
Returns the set A U B. *)

(*****************************************************************************)
(* Miscellaneous CGB Functions                                               *)
(*****************************************************************************)

PROCEDURE CGBOPT(O: LIST);
(*Comprehensive Groebner Basis Options.
O is a list with an arbitrary number of elements.
The global variable PAR is set according to O.
The elements of O (if existent) are interpreted as follows:
1st element: if =0 no output during computation, if >0 chatty.
2nd element: if =1 factorize coefficients, if <> do not.
3rd element: if =0 use top reduction only, if =1 use "normal" reduction.
4th element: evaluate conditions using:
     	     if =0: simple methode, if =1: reduced sets, if =2: Groebner bases.
5th element: if =0: characteristic 0, if <>0 arbritrary characteristic.
6th element: term order for polynomials
7th element: term order for coefficients
*)

PROCEDURE CGBOPTWRITE();
(*Comprehensive Groebner Basis Options Write
Writes the options from the global Variable PAR on the output stream*)

PROCEDURE dummycnst(A: LIST): BOOLEAN;
(* Dummy constant.
Value for PAR.IsCnst. Returns false always (nothing is constant). *)

PROCEDURE dummyfactorize(A: LIST): LIST;
(* Dummy factorize.
Value for PAR.factorize. Does not factorize. Returns a list containing A.*)

(* Do not use any of the following outside from CGB! -- mp*)

(*****************************************************************************)
(* LIST output                                                               *)
(*****************************************************************************)

PROCEDURE FLWRITE(L: LIST);
(* Formatted list write.
The input list L is written to the output stream.*)

PROCEDURE FILWRITE(L: LIST; N:INTEGER);
(* Formatted indented list write.
The input list L is written to the output stream.*)

(*****************************************************************************)
(* Polynomial conversion                                                     *)
(*****************************************************************************)

PROCEDURE XPFDIP (DP, DOM, VARL: LIST): LIST;
(* Recursive polynomial (with domain-descriptor) from distributive polynomial.
DP is a polynomial in distributive representation.
DOM is a domain descriptor.
VARL is a list of variables.
Returns a Polynomial (DOM, P, R, VARL) where
P is the recursive representation of DP and R is the number of variables of DP.
*)

PROCEDURE PFLDIPL (DIPL, DOM, VARL: LIST): LIST;
(* Recursive polynomial list (with domain-descriptor) from distributive
polynomial list.
DIPL is a list of polynomials in distributive representation.
DOM is a domain descriptor.
VARL is a list of variables.
Returns a list containing an element
(DOM, P, R, VARL) for each distributive polynomial dp in DIPL where
P is the recursive representation of dp and R is the number of variables of dp
(all polynomials in DIPL are assumed to have the same number of variables).
*)

PROCEDURE XDIPFPF (P: LIST; VAR DOM, VARL: LIST): LIST;
(* Distributive polynomial from recursive polynomial (with domain-descriptor).
P is a polynomial in recursive representation. 
Returns this polynomial in distributive representation, sorted according
to the value of EVORD, the domain-descriptor in DOM and the list of
variables in VARL.
*)

PROCEDURE DIPLFPFL (PFL: LIST; VAR DOM, VARL: LIST): LIST;
(* Distributive polynomial list from recursive polynomial
(with domain-descriptor) list.
PFL is a list of polynomials in recursive representation. 
Returns a list of this polynomials in distributive representation
the domain-descriptor in DOM and the list of variables in VARL.
*)

PROCEDURE DIFPF(P, D: LIST; VAR DOM, VARL: LIST): LIST;
(* Distributive polynomial with arbitrary domain coefficients from
recursive polynomial (with domain-descriptor).
P is a polynomial with domain descriptor.
D is a domain descriptor.
Returns P in distributive representation over domain D,
sorted according to the value of EVORD, the domain-descriptor of P in DOM, and
the list of variables in VARL.
*)

PROCEDURE DILFPFL(PFL, D: LIST; VAR DOM, VARL: LIST): LIST;
(* Distributive polynomial list with arbitrary domain coefficients from
recursive polynomial list (with domain-descriptor).
P is a polynomial list with domain descriptor.
D is a domain descriptor.
Returns a list containing the polynomials from PFL
in distributive representation over domain D,
sorted according to the value of EVORD, the domain-descriptor of PFL
in DOM, and the list of variables in VARL.
*)

(*****************************************************************************)
(* Groebner bases and related procedures for recursive integral polynomials *)
(*****************************************************************************)

PROCEDURE PFIGB(PFL, TF: LIST; VAR ONE: BOOLEAN): LIST;
(* Integral Polynomial Groebner Basis.
PFL is a list of polynomials in recursive representation.
TF is the trace flag.
Returns the Groebner Basis of PFL wrt. to the total degree inverse 
lexicographical term order.
ONE=TRUE iff 1 is an element of the Groebner Basis.*)

PROCEDURE PFIGBA(PFL, P, TF: LIST; VAR ONE: BOOLEAN): LIST;
(* Integral Polynomial Groebner Basis augmentation.
PFL is a list of polynomials in recursive representation.
P is a polynomial.
TF is the trace flag.
Returns the Groebner Basis of PFL and P wrt. to the total degree inverse 
lexicographical term order.
ONE=TRUE iff 1 is an element of the Groebner Basis.*)

PROCEDURE PFILS(B: LIST; VAR ONE: BOOLEAN): LIST;
(* Integral polynomial list irreducible set.
B is a list of polynomials in recursive representation.
Returns the result of reducing B.
ONE=TRUE iff 1 is an element of the result. *)

PROCEDURE DIILIS(P: LIST): LIST; 
(*Distributive integral polynomial list irreducible set.
P is a list of distributive integral polynomials,
PP is the result of reducing each p element of P modulo P-(p)
until no further reductions are possible. *)


PROCEDURE PFINOR(B, P: LIST): LIST;
(* Integral Polynomial Normal Form.
B is a list of polynomials in recursive representation.
P is a polynomial in recursive representation.
Returns the normal form of P wrt. B, or SIL if this normal form is 0. *)


PROCEDURE PFILNOR(B, P: LIST; VAR ZERO: BOOLEAN): LIST;
(* Integral Polynomial List Normal Form.
B is a list of polynomials in recursive representation.
P is a list of polynomials in recursive representation.
Returns a list of (non-zero, not constant) normal forms of each p in P wrt. B.
ZERO=TRUE iff one of the normal forms is zero. *)


PROCEDURE PFILDS(B: LIST; VAR ONE: BOOLEAN): LIST;
(* Integral polynomial list d-irreducible set.
B is a list of polynomials in recursive representation.
Returns the result of d-reducing B.
ONE=FALSE.*)


PROCEDURE PFIDNOR(B, P: LIST): LIST;
(* Integral Polynomial D Normal Form.
B is a list of polynomials in recursive representation.
P is a polynomial in recursive representation.
Returns the d-normal form of P wrt. B, or SIL if this normal form is 0. *)

PROCEDURE PFILDNOR(B, P: LIST; VAR ZERO: BOOLEAN): LIST;
(* Integral Polynomial List D-Normal Form.
B is a list of polynomials in recursive representation.
P is a list of polynomials in recursive representation.
Returns a list of (non-zero) d-normal forms of each p in P wrt. B.
ZERO=TRUE iff one of the d-normal forms is zero. *)

PROCEDURE PFWRITE(P: LIST);
(* Integral polynomial write.
P is a polynomial in recursive representation with domain-descriptor.
P is written to the outputstream (wrt. the term order in EVORD).
*)

PROCEDURE DIIPNORM(P: LIST): LIST;
(* Distributive integral polynomial norm.
Returns a polynomial r, were  n*r=p for an Integer n, the content of r is 1
and the highest coefficient of r is not negative.*)

END CGBMISC.

(* -EOF- *)
