(* ----------------------------------------------------------------------------
 * $Id: MASNC.md,v 1.3 1992/10/16 14:07:55 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASNC.md,v $
 * Revision 1.3  1992/10/16  14:07:55  kredel
 * Cosmetic
 *
 * Revision 1.2  1992/02/12  17:33:29  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:13:13  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASNC;

(* MAS Non-commutative Product Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: MASNC.md,v 1.3 1992/10/16 14:07:55 kredel Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DINPPR(T,A,B: LIST): LIST; 
(*Distributive polynomial non-commutative product.
A and B are distributive polynomials. T is a table
of distributive polynomials specifying the non-commutative
relations. C=A*B, the non-commutative product of A and B.
The table T may be modified. *)


PROCEDURE DINPTL(T,EL,FL: LIST;  VAR C,EP,FP: LIST); 
(*Distributive polynomial non-commutative product table lookup.
e and f are exponent vectors. T is a table
of distributive polynomials specifying the non-commutative
relations. C is the non-commutative product of x**es and x**fs.
ep and fp are exponent vectors with es+ep=e and fs+fp=f.
If e=es or f=fs then ep=() or fp=(). *)


PROCEDURE DINPTU(T,EL,FL,C: LIST); 
(*Distributive polynomial non-commutative product table update.
e and f are exponent vectors. T is a table
of distributive polynomials specifying the non-commutative
relations. C is a distributive rational polynomial. The relation
e * f = C is added to T. T is modified. *)


PROCEDURE DINPEX(T,A,NL: LIST): LIST; 
(*Distributive non-commutative polynomial exponentiation. A is a
distributive rational polynomial, n is a non-negative beta-
integer. T is a table of non-commutative relations.
B=A**n. 0**0 is by definition a polynomial in zero variables. *)


PROCEDURE DINLRD(V,T: LIST): LIST; 
(*Distributive non-commutative polynomial list read. V is a
variable list. T is a table of non-commutative relations.
A list of distributive non-commutative polynomials
in r variables, where r=length(V), r ge 0, is read from
the input stream. Any blanks preceding A are skipped. *)


PROCEDURE DINPRD(V,T: LIST): LIST; 
(*Distributive non-commutative polynomial read. V is a variable list.
T is a table on non-commutative relations.
A distributive rational polynomial A in r variables, where
r=length(V), r ge 0, is read from the input stream. Any
blanks preceding A are skipped. *)


PROCEDURE EVZERO(RL: LIST): LIST; 
(*Exponent vector zero. U is an exponent vector of length r,
r ge 0 with all components zero. *)


END MASNC.


(* -EOF- *)
