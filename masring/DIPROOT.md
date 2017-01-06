(* ----------------------------------------------------------------------------
 * $Id: DIPROOT.md,v 1.3 1996/06/08 14:13:51 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPROOT.md,v $
 * Revision 1.3  1996/06/08 14:13:51  kredel
 * Correction to interval.
 *
 * Revision 1.2  1992/02/12  17:34:24  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:14:43  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DIPROOT;

(* DIP Ideal Real Root System Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: DIPROOT.md,v 1.3 1996/06/08 14:13:51 kredel Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DIGBSI(P,T,A: LIST): LIST; 
(*Distributive polynomial system algebraic number G basis sign.
P is a goebner basis in inverse lexicographical term order
in r variables (non empty), with all neccessary refinements.
T=(t1,... ,ti) i le r, where tj=(vj,ij,pj) j=1, ...,i and v is 
the character list for the j-th variable, ij is an isolating 
interval for a real root of the univariate polynomial pjl.
A is a distributive rational polynomial depending maximal on one 
variable. s is the sign of A as element of an algebraic extension
of Q determined by P. *)


PROCEDURE DIITNT(T: LIST): LIST; 
(*Distributive polynomial system interval tupel from norm tupel.
T is a refined normalized tupel of a zero set with a final Goebner 
base of dimension 0. TP is a list of interval tupels for T. *)


PROCEDURE DIITWR(TP,EPS: LIST); 
(*Distributive polynomial system interval tupels write. TP is a list 
of interval tupels of a zero set. EPS is LOG10 of the desired 
precision. *)


PROCEDURE DINTWR(TP,EPS: LIST); 
(*Distributive polynomial system normalized tupels write.
TP is a list of normalized tupels of a zero set. EPS is log10 of 
the desired precision. *)



PROCEDURE DIROWR(V,P,EPS: LIST); 
(*Distributive polynomial system real root write. V is a variable 
list. P is a list (e,p). EPS is the desired precision. e is the 
multiplicity of the root, and p is an irreducible polynomial. *)


PROCEDURE GBZSET(V,PP,EPS: LIST); 
(*Groebner base real zero set of zero dimensional ideal. 
V is a variable list. PP is a list of distributive rational polynomials,
PP is a Groebner base. EPS is is LOG10 of the desired precision. *)


PROCEDURE RIRWRT(R,EPS: LIST); 
(*Rational interval refinement write. R=(v,i,p) where v is the 
variable character string, i is a rational interval containing only
one real root of the polynomial p. EPS is the presicion epsilon. *)


END DIPROOT.

(* -EOF- *)
