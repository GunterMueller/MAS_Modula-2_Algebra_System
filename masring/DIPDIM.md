(* ----------------------------------------------------------------------------
 * $Id: DIPDIM.md,v 1.2 1992/02/12 17:34:16 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPDIM.md,v $
 * Revision 1.2  1992/02/12  17:34:16  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:14:32  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DIPDIM;

(* DIP Dimension Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: DIPDIM.md,v 1.2 1992/02/12 17:34:16 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DIGBZT(S: LIST): LIST; 
(*Distributive polynomial groebner base common zero test.
S is a groebner basis. t = -1 or 0 if DIMENSION(S) eq -1 or 0, t = 1
if DIMENSION(S) ge 1. *)


PROCEDURE DILDIM(G: LIST;  VAR DL,S,M: LIST); 
(*Distributive polynomial list dimension.
G is a list of distributive polynomials, a groebner base.
d is the dimension of ideal(G). M is a maximal independend
set of variables. S is a set of maximal independent sets of
variables. *)


PROCEDURE DIDIMS(G,S,U,M: LIST): LIST; 
(*Distributive polynomial dimension maximal independent set.
G is a list of distributive rational polynomials, and a g-base.
S is a maximal independent set of variables.
U is a set of variables of unknown status.
M and MP are lists of maximal independent sets of variables.  *)


PROCEDURE EVGBIT(S,G: LIST): LIST; 
(*Exponent vector groebner base intersection test.
S is a set of variable indices. G is a groebner basis.
t = 0 if intersection = () else t = 1. *)


PROCEDURE USETCT(U,V: LIST): LIST; 
(*Unordered set containment test. U and V are unordered sets.
t = 1 if U is contained in V else t = 0. *)


PROCEDURE IXSUBS(V,I: LIST): LIST; 
(*Indexed subset. V is a list.
I is an index list. The elements of V with index from I
are put to VP. *)


PROCEDURE DIDIMWR(DL,S,M,V: LIST); 
(*Distributive polynomial dimension write.
d is the dimension of an ideal. M is a maximal independend
set of variables. S is a set of maximal independent sets of
variables. V is the variable list. *)


END DIPDIM.


(* -EOF- *)
