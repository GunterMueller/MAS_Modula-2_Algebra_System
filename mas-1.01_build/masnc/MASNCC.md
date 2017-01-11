(* ----------------------------------------------------------------------------
 * $Id: MASNCC.md,v 1.2 1992/02/12 17:33:31 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASNCC.md,v $
 * Revision 1.2  1992/02/12  17:33:31  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:13:15  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASNCC;

(* MAS Non-commutative Center Definition Module. *)



FROM MASSTOR IMPORT LIST; 

CONST rcsid = "$Id: MASNCC.md,v 1.2 1992/02/12 17:33:31 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DINCCO(T, A, B: LIST): LIST;
(*Distributive rational non-commutative polynomial commutator. 
A and B are distributive rational non-commutative polynomials.
The commutator of A and B is returned. T is the relation table. *)


PROCEDURE DINCCP(T, E: LIST): LIST; 
(*Distributive rational non-commutative polynomial center polynomial. 
E is a list of exponent vectors. T is the relation table. 
A polynomial in the center of the ideal 
is returned. *)


PROCEDURE DINCCPpre(T, E: LIST): LIST; 
(*Distributive rational non-commutative polynomial center polynomial preparation. 
E is a list of exponent vectors. T is the relation table. 
A polynomial in the center of the polynomial ring is returned. *)


PROCEDURE DILFEL(a, E: LIST): LIST;
(*Distributive polynomial list from exponent vector list. 
E is a list of exponent vectors. A list distributive polynomials with 
exponent vectors from E and coefficients equal to a is returned. *)


PROCEDURE DINPTslT(T: LIST): BOOLEAN; 
(*Distributive polynomial non-commutative product table strict lex test.
T is a table of distributive polynomials specifying the non-commutative
relations. It is tested if T is strict lexicographical, i.e. if 
Xj*Xi = cij Xi Xj + pij is a strict lexicographical commutator relation,
then cij = 1 and pij <(inv lex) Xi Xj. *)


PROCEDURE DINLMPG(T,i,F: LIST): LIST; 
(*Distributive non-commutative left rational minimal polynomial for a G basis. 
F is a non-commutative left groebner basis. 
PP is the left minimal polynomial for the i-th variable for F. *)


PROCEDURE DINLMPL(T,F: LIST): LIST; 
(*Distributive non-commutative left rational minimal polynomial list for a G basis. 
F is a non-commutative left groebner basis. 
P is the list of left minimal polynomial for each variable for F. *)


PROCEDURE EVGCD(U,V: LIST): LIST;
(*Exponent vector greatest common divisor. U=(UL1, ...,ULRL),
V=(VL1, ...,VLRL) are exponent vectors of length r.
W=(WL1, ...,WLRL) is the greatest common divisor of U and V. *)


PROCEDURE EVLGTD(r,d,L: LIST): LIST;
(*Exponent vector list generate for total degree. 
r is the number of variables. L is a list of already generated 
exponent vectors. A list of exponent vectors up to total degree 
d (>= 0) is returned. *)


PROCEDURE EVLGIL(D: LIST): LIST;
(*Exponent vector list generate for inverse lexicographical sequence. 
D is a list of maximal degrees in the respective variable. 
A list of exponent vectors up to the maximal degrees is returned. *)


PROCEDURE EVLINV(L,i,k: LIST): LIST;
(*Exponent vector list introduction of new variables. 
L is a list of exponent vectors. In each element of L k new variables
are introduced after position i. The new list is returned. *) 


PROCEDURE EVTSZ(i,U: LIST): BOOLEAN;
(*Exponent vector test if starting with i zero exponents. *) 


PROCEDURE EVINV(U,i,k: LIST): LIST;
(*Exponent vector introduction of new variables. At position
i in U k new variables are introduced. *) 


END MASNCC.


(* -EOF- *)
