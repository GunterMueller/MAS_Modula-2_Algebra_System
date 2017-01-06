(* ----------------------------------------------------------------------------
 * $Id: DIPIGB.md,v 1.2 1992/02/12 17:34:20 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPIGB.md,v $
 * Revision 1.2  1992/02/12  17:34:20  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:14:37  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DIPIGB;

(* DIP Integral Groebner Bases Definition Module. *)


FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: DIPIGB.md,v 1.2 1992/02/12 17:34:20 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DIIGBA(PL,P,TF: LIST): LIST; 
(*Distributive integral polynomial groebner basis augmentation.
P is a groebner basis of polynomials in distributive
representation in r variables. p is a polynomial. PP is the
groebner basis of (P,p). tf is the trace flag.*)


PROCEDURE DIIGMI(P: LIST): LIST; 
(*Distributive minimal ordered groebner basis. P is a list of
non zero integral polynomials in distributive representation
in r variables. PP is the minimal normed and ordered
groebner basis. *)


PROCEDURE DIILIS(P: LIST): LIST; 
(*Distributive integral polynomial list irreducible set.
P is a list of distributive integral polynomials,
PP is the result of reducing each p element of P modulo P-(p)
until no further reductions are possible. *)


PROCEDURE DIIPGB(P,TF: LIST): LIST; 
(*Distributive integral polynomial groebner basis. P is a
list of integral polynomials in distributive representation
in r variables. PP is the groebner basis of P. tf is the
trace flag.*)


PROCEDURE DIIPNF(P,RPP,S: LIST): LIST; 
(*Distributive integral polynomial normal form. P is a list
of non zero polynomials in distributive integral
representation in r variables. S is a distributive integral
polynomial. R is a polynomial such that S is reducible to R
modulo P and R is in normalform with respect to p. *)


PROCEDURE DIIPSP(A,B: LIST): LIST; 
(*Distributive integral polynomial s polynomial. A and B are
integral polynomials in distributive representation. C is
the S-polynomial of A and B. *)


END DIPIGB.


(* -EOF- *)
