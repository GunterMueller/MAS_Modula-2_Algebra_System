(* ----------------------------------------------------------------------------
 * $Id: DIPGB.md,v 1.2 1992/02/12 17:31:22 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPGB.md,v $
 * Revision 1.2  1992/02/12  17:31:22  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:09:03  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DIPGB;

(* DIP Groebner Bases Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: DIPGB.md,v 1.2 1992/02/12 17:31:22 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DIGMIN(P: LIST): LIST; 
(*Distributive minimal ordered groebner basis. P is a list of
non zero polynomials in distributive representation
in r variables. PP is the minimal normed and ordered
groebner basis. *)


PROCEDURE DILIS(P: LIST): LIST; 
(*Distributive polynomial list irreducible set.
P is a list of distributive polynomials,
PP is the result of reducing each p element of P modulo P-(p)
until no further reductions are possible. *)


PROCEDURE DIPGB(P,TF: LIST): LIST; 
(*Distributive polynomial groebner basis. P is a
list of polynomials in distributive representation
in r variables. PP is the groebner basis of P. tf is the
trace flag.*)


PROCEDURE DIPNOR(P,S: LIST): LIST; 
(*Distributive polynomial normal form. P is a list
of non zero polynomials in distributive
representation in r variables. S is a distributive
polynomial. R is a polynomial such that S is reducible to R
modulo P and R is in normalform with respect to P. *)


PROCEDURE DIPSP(A,B: LIST): LIST; 
(*Distributive polynomial S-polynomial. A and B are
polynomials in distributive representation. C is
the S-polynomial of A and B. *)



(* DIP Integral Function Groebner Bases Implementation Module. ----- *)

PROCEDURE DIIFGB(P,TF: LIST): LIST; 
(*Distributive integral function polynomial groebner basis.
P is a list of integral function polynomials in
distributive representation in r variables.
PP is the groebner basis of P. tf is the trace flag.*)


PROCEDURE DIIFLS(P: LIST): LIST; 
(*Distributive integral function polynomial list irreducible set.
P is a list of distributive integral function polynomials,
PP is the result of reducing each p element of P modulo P-(p)
until no further reductions are possible. *)


PROCEDURE DIIFMI(P: LIST): LIST; 
(*Distributive minimal ordered groebner basis. P is a list of
non zero integral function polynomials in distributive representation
in r variables. PP is the minimal normed and ordered
groebner basis. *)


PROCEDURE DIIFNF(P,RPP,S: LIST): LIST; 
(*Distributive integral function polynomial normal form.
P is a list of non zero polynomials in distributive
integral function representation in r variables.
S is a distributive integral function polynomial.
R is a polynomial such that S is reducible to R
modulo P and R is in normalform with respect to P. *)


PROCEDURE DIIFSP(A,B: LIST): LIST; 
(*Distributive integral function polynom S-polynomial.
A and B are integral function polynomials in distributive
representation. C is the S polynomial of A and B. *)


END DIPGB.


(* -EOF- *)
