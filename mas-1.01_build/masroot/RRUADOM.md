(* ----------------------------------------------------------------------------
 * $Id: RRUADOM.md,v 1.1 1994/03/11 15:21:51 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: RRUADOM.md,v $
 * Revision 1.1  1994/03/11  15:21:51  pesch
 * Counting real roots of multivariate polynomials, Diplomarbeit F. Lippold
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE RRUADOM;
(* Real Root Univariate Arbitrary Domain Definition Module *)
	
(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: RRUADOM.md,v 1.1 1994/03/11 15:21:51 pesch Exp $";
CONST copyright = "Copyright (c) 1993 Universitaet Passau";

PROCEDURE RRUADPOLTOVEC(D,g,d: LIST): LIST;
(* Real root univariate arbitrary domain polynomial to vector. 
   g is an univariate polynomial of domain D with degree less than d. 
   If a(i) is the coefficient of X**i in g then the list (a(d-1),...,a(0)) 
   is returned. *)

PROCEDURE RRUADSTRCONST(D,f,h: LIST): LIST;
(* Real root univariate arbitrary domain structure constants. 
   f and h are univariate polynomials of domain D. 
   f is monic with degree p > 0. A matrix beta with entries beta[i,j] 
   from D for 0 le i le p-1 and 0 le j le 3*p-3 is created, such that 
   h * X**j = beta[0,j]+beta[1,j]*X+...+beta[p-1,j]X**(p-1) modulo f. 
   beta is represented columnwise. *)

PROCEDURE RRUADQUADFORM(beta: LIST): LIST;
(* Real root univariate arbitrary domain quadratic form. 
   beta is the set of structure constants as computed by RRUADSTRCONST.
   Let s(k) = tr(M(h)*M(X**k))=beta[0,k]+beta[1,k+1]+...+beta[p-1,k+p-1].
   The matrix Q=(q(i,j)) with q(i,j) = s(i+j-2) is computed. *)

PROCEDURE RRUADCOUNT(D,f,H,v,tf: LIST): LIST;
(* Real root univariate arbirary domain count. 
   f is a monic univariate polynomial of domain D with degree p > 0. 
   H is a list of univariate polynomials of length s. v is a vector of signs 
   with length not greater than s. tf is the trace flag.
   ZNL is a list of pairs (z,n) with n is an element of {-1,0,+1}**s and z > 0
   is the number of real zeroes of f wrt the sign condition n for the elements
   of H. ZNL is sorted wrt the invers lexicographical order of the n. If there
   does not exist any real zero or a zero satisfiing the sign condition v,
   then the empty list is returned. *)

END RRUADOM.

(* -EOF- *)
