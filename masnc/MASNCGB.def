(* ----------------------------------------------------------------------------
 * $Id: MASNCGB.md,v 1.2 1992/02/12 17:33:32 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASNCGB.md,v $
 * Revision 1.2  1992/02/12  17:33:32  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:13:17  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASNCGB;

(* MAS Non-commutative Groebner Bases Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: MASNCGB.md,v 1.2 1992/02/12 17:33:32 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DINLNF(T,P,S: LIST): LIST; 
(*Distributive non-commutative polynomial left normal form.
P is a list of non zero polynomials in distributive rational
representation in r variables. S is a distributive rational
polynomial. R is a polynomial such that S is left reducible to R
modulo P and R is in normalform with respect to P.
T is a table of distributive polynomials specifying the
non-commutative relations. *)


PROCEDURE DINLIS(T,P: LIST): LIST; 
(*Distributive non-commutative polynomial list left irreducible set.
P is a list of distributive rational polynomials, PP is the
result of left reducing each p element of P modulo P-(p)
until no further reductions are possible.
T is a table of distributive polynomials specifying the
non-commutative relations. *)


PROCEDURE DINLSP(T,A,B: LIST): LIST; 
(*Distributive non-commutative polynomial left S-polynomial.
A and B are rational polynomials in distributive representation.
C is the left S-polynomial of A and B.
T is a table of distributive polynomials specifying the
non-commutative relations. *)


PROCEDURE DINLGB(T,P,TF: LIST): LIST; 
(*Distributive non-commutative polynomials left Groebner base.
P is a list of rational polynomials in distributive representation
in r variables. PP is the left Groebner base of P. t is the
trace flag.
T is a table of distributive polynomials specifying the
non-commutative relations. *)


PROCEDURE DINLGM(T,P: LIST): LIST; 
(*Distributive non-commutative minimal ordered left Groebner base.
P is a list of non zero rational polynomials in distributive
representation in r variables, P is a left Groebner base.
PP is the minimal normed and ordered left Groebner base.
T is a table of distributive polynomials specifying the
non-commutative relations. *)


PROCEDURE DIN1GB(T,P,TF: LIST): LIST; 
(*Distributive non-commutative polynomials Groebner base.
P is a list of rational polynomials in distributive representation
in r variables. PP is the Groebner base of P. t is the
trace flag.
T is a table of distributive polynomials specifying the
non-commutative relations. *)


PROCEDURE DINCGB(T,P,TF: LIST): LIST; 
(*Distributive non-commutative polynomials Groebner base.
P is a list of rational polynomials in distributive representation
in r variables. PP is the Groebner base of P. t is the
trace flag.
T is a table of distributive polynomials specifying the
non-commutative relations. *)


END MASNCGB.


(* -EOF- *)
