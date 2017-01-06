(* ----------------------------------------------------------------------------
 * $Id: DIPRNGB.md,v 1.2 1992/02/12 17:34:23 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPRNGB.md,v $
 * Revision 1.2  1992/02/12  17:34:23  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:14:41  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DIPRNGB;

(* DIP Rational Groebner Bases Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: DIPRNGB.md,v 1.2 1992/02/12 17:34:23 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DIGBC3(B,PLI,PLJ,EL: LIST): LIST; 
(*Distributive polynomial groebner basis criterion 3.
B is a non empty list of reduction sets. pi and pj are
distributive polynomials. e is the least common multiple
of the leading exponent vectors of pi and pj. s=1 if the
reduction of pi and pj is necessary s=0 else. *)


PROCEDURE DIGBC4(PLI,PLJ,EL: LIST): LIST; 
(*Distributive polynomial groebner basis criterion 4.
pi and pj are polynomials in distributive representation.
e is the least common multiple of the leading exponent vectors
of pi and pj. s=1 if the reduction of pi and pj is necessary
s=0 else. *)


PROCEDURE DIGBMI(P: LIST): LIST; 
(*Distributive minimal ordered groebner basis. P is a list of
non zero rational polynomials in distributive representation
in r variables. PP is the minimal normed and ordered
groebner basis. *)


PROCEDURE DILCPL(P: LIST;  VAR D,B: LIST); 
(*Distributive polynomial list construct pair list.
P is list of polynomials in distributive representation
in r variables. B is the polynomials pairs list and
D is the pairs list. *)


PROCEDURE DILUPL(PL,P,D,B: LIST): LIST; 
(*Distributive polynomial list update pair list.
P is list of polynomials in distributive representation
in r variables. B is the polynomials pairs list and
D is the pairs list. p is a non zero polynomial in
distributive representation. D, P and B are modified.
DP is the updated pairs list. *)


PROCEDURE DIRGBA(PL,P,TF: LIST): LIST; 
(*Distributive rational polynomial groebner basis augmentation.
P is a groebner basis of polynomials in distributive
representation in r variables. p is a polynomial. PP is the
groebner basis of (P,p). t is the trace flag.*)


PROCEDURE DIRGBR(P,TF: LIST): LIST; 
(*Distributive rational polynomial groebner basis recursion.
P is a list of rational polynomials in distributive representation
in r variables. PP is the groebner basis of P. t is the
trace flag.*)


PROCEDURE DIRLIS(P: LIST): LIST; 
(*Distributive rational polynomial list irreducible set.
P is a list of distributive rational polynomials,
PP is the result of reducing each p element of P modulo P-(p)
until no further reductions are possible. *)


PROCEDURE DIRPGB(P,TF: LIST): LIST; 
(*Distributive rational polynomials groebner basis.
P is a list of rational polynomials in distributive representation
in r variables. PP is the groebner basis of P. t is the
trace flag.*)


PROCEDURE DIRPNF(P,S: LIST): LIST; 
(*Distributive rational polynomial normal form. P is a list
of non zero polynomials in distributive rational
representation in r variables. S is a distributive rational
polynomial. R is a polynomial such that S is reducible to R
modulo P and R is in normalform with respect to P. *)


PROCEDURE DIRPSP(A,B: LIST): LIST; 
(*Distributive rational polynomial S polynomial. A and B are
rational polynomials in distributive representation. C is
the S polynomial of A and B. *)


PROCEDURE EVPLM(L1,L2: LIST): LIST; 
(*Exponent vector pair-list merge.  L1 and L2 are pair-lists
of exponent vectors in non decreasing order.  L is the merge 
of L1 and L2. L1 and L2 are modified to produce L. *)


PROCEDURE EVPLSO(A: LIST): LIST; 
(*Exponent vector pair-list sort. A is a list of pair-lists. B is 
the result of sorting A into non-decreasing order. Pairs of
elements of A are merged. The list A is modified to produce B. *)


END DIPRNGB.


(* -EOF- *)
