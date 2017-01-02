(* ----------------------------------------------------------------------------
 * $Id: RRUINT.md,v 1.1 1994/03/11 15:21:53 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: RRUINT.md,v $
 * Revision 1.1  1994/03/11  15:21:53  pesch
 * Counting real roots of multivariate polynomials, Diplomarbeit F. Lippold
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE RRUINT;
(* Real Root Univariate Integral Definition Module *)
	
(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: RRUINT.md,v 1.1 1994/03/11 15:21:53 pesch Exp $";
CONST copyright = "Copyright (c) 1993 Universitaet Passau";

PROCEDURE RRUIPOLTOVEC(g,d: LIST): LIST;
(* Real root univariate integral polynomial to vector. 
   g is an univariate integral polynomial with degree less than d. 
   If a(i) is the coefficient of X**i in g then the list (a(d-1),...,a(0)) 
   is returned. *)

PROCEDURE RRUISTRCONST(f,h: LIST): LIST;
(* Real root univariate integral structure constants. 
   f and h are univariate integral polynomials. f has degree p > 0. An integral
   matrix beta with entries beta[i,j] for 0 le i le p-1 and 0 le j le 3*p-3 is
   created, such that c*h*X**j = beta[0,j]+beta[1,j]*X+...+beta[p-1,j]X**(p-1)
   modulo f for some positive integer c. beta is represented columnwise. *)

PROCEDURE RRUIQUADFORM(beta: LIST): LIST;
(* Real root univariate integral quadratic form. 
   beta is the set of structure constants as computed by RRUISTRCONST. 
   Let s(k)=tr(M(c*h*X**k))=beta[0,k]+beta[1,k+1]+...+beta[p-1,k+p-1] 
   for some positive constant c. 
   The matrix Q = (q(i,j)) with q(i,j) = s(i+j-2) is computed. *)

PROCEDURE RRUICOUNT(f,H,V,tf: LIST): LIST;
(* Real root univariate integral count. 
   f is an univariate integral polynomial with degree p > 0. 
   H is a list of univariate integral polynomials of length s. v is a vector 
   of signs with length not greater than s. tr is the trace flag.
   ZNL is a list of pairs (z,n) with n is an element of {-1,0,+1}**s and z > 0
   is the number of real zeroes of f wrt the sign condition n for the elements
   of H. ZNL is sorted wrt the invers lexicographical order of the n. If there
   does not exist any real zero or a zero satisfiing the sign condition v,
   then the empty list is returned. *)

END RRUINT.

(* -EOF- *)
