(* ----------------------------------------------------------------------------
 * $Id: RRADOM.md,v 1.1 1994/03/11 15:21:49 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: RRADOM.md,v $
 * Revision 1.1  1994/03/11  15:21:49  pesch
 * Counting real roots of multivariate polynomials, Diplomarbeit F. Lippold
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE RRADOM;
(* Real Root Arbitrary Domain Definition Module *)
	
(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: RRADOM.md,v 1.1 1994/03/11 15:21:49 pesch Exp $";
CONST copyright = "Copyright (c) 1993 Universitaet Passau";

PROCEDURE EVUMSORT(L: LIST): LIST;
(* Exponent vector unique merge sort. 
   The list of exponent vectors L ist sorted with respect to the actual 
   termorder. Multiple entries are deleted. *)

PROCEDURE EVSSPROD(T: LIST): LIST;
(* Exponent vektor set sorted product. 
   T is a list of terms. U = {a*b: a,b from T} is sorted with respect to 
   the actual termorder. *)

PROCEDURE RRVTEXT(A,L: LIST): LIST;
(* Real root vector of tupels extension. 
   A is a set of s-tupels, L is a set of objects. B is a set of (s+1)-tupels 
   constructed by appending each object of L to the tupels of A. The ordering
   of B is increasing lexicographical wrt the ordering of L and A. *)

PROCEDURE RRZDIM(G: LIST): LIST;
(* Real root zero-dimensional test.
   G non-trivial reduced groebner basis. 
   s = 1 iff Id(G) is zero-dimensional, s = 0 otherwise. *)

PROCEDURE RRREDTEST(G,t: LIST; VAR g,s: LIST);
(* Real root reducibility test. 
   G reduced groebner basis, t term.
   s =  0, if t is reducible with an Element g of G with HT(g) = t,
   s = -1, if t is not reducible and s = 1 otherwise *)

PROCEDURE RRREDTERMS(G: LIST): LIST;      
(* Real root reduced terms. 
   G reduced groebner basis of a nontrival zerodimensional ideal. R ist the 
   set of reduced terms sorted with respect to the actual termorder. *)

PROCEDURE RRADNFORM(D,G,R: LIST): LIST;
(* Real root arbitrary domain normal form. 
   G monic reduced groebner basis of a nontrivial zerodimensional ideal of 
   domain D, R is the set of reduced terms. NF is a list of entries (u,ut,up)
   with: u is an element of R * R, RRREDTEST(G,u,_,ut) and up is the normal 
   form of u wrt G. The elements of NF are sorted with respect to the actual 
   termorder in decreasing order of the first entry. *)

PROCEDURE RRADSTRCONST(D,G,R: LIST; VAR U, beta: LIST);
(* Real root arbitrary domain structure constants. 
   G monic reduced groebner basis of a nontrivial zerodimensional ideal of 
   domain D, R is the set of reduced terms. beta is a matrix of structure-
   constants beta[u,v] wrt the basis R with u from U = R * R and v from R. 
   U and the rows of the matrix beta are sorted with respect to the actual 
   termorder in increasing order. *)

PROCEDURE RRMMULT(w,R,U,beta: LIST): LIST;
(* Real root matrix of multiplication. 
   R is the set of reduced terms in increasing order, w from R, U = R * R 
   and beta is the set of combined structure constants wrt R. The columnwise 
   represented matrix of multiplication with w is returned. *)

PROCEDURE RRADVARMATRICES(G,R,U,beta: LIST): LIST;
(* Real root arbitrary domain multiplication matrices of variables. 
   G monic reduced groebner basis of a nontrivial zerodimensional ideal. R is
   the set of reduced terms in increasing order, U = R * R and beta is the
   set of combined structure constants wrt R. L is a list of entries of the 
   form (1,M(i)) and M(i) is the matrix of multiplication with X(i) wrt R. *)

PROCEDURE RRADPOLMATRIX(D,R,h: LIST; VAR Mh,L: LIST);
(* Real root arbitrary domain polynomial matrix. 
   R is the set of reduced terms in increasing order, 
   h is a polynomial of domain D, L contains nonempty lists L(i) of the form 
   j(1),M(1),j(2),M(2),...,j(k),M(k) with 1=j(1)<j(2)<...<j(k) and M(l) ist 
   the matrix of multiplikation with X(i)**j(l) for the variable X(i). L is 
   extended with new calculated matrices. Mh is the matrix of multiplication 
   with h. *)

PROCEDURE RRADQUADFORM(D,R,U,beta,Mh: LIST): LIST;
(* Real root arbitrary domain quadratic form. 
   D is a domain, R is the set of reduced terms in increasing order, U = R * R
   and beta is the set of combined structure constants wrt R. Mh is the matrix
   of multiplication with h represented columnwise. The matrix Q=(q(i,j)) with
   q(i,j) = tr(M(h)*M(v(i))*M(v(j)) and v(i),v(j) from R is computed. *)

PROCEDURE RRCSR(i,v,tf: LIST; VAR A,N,S,L: LIST): LIST;
(* Real root count solve and reduce. Subroutine of the RR*COUNT procedures.
   i is an integer, v is a sign vector, tf is the trace-flag. 
   A is an integral k x k- matrix, N is a subset of {-1,0,+1}**i of length k 
   sorted in increasing lexicographical order, S is an integral vector of 
   length k and L is a list of length k.
   The system A*Z=S is solved and reduced by deleting the zero entries of Z
   and the corresponding columns of A. Then the system is reduced to a regular
   one by deleting linear dependend rows of A and the corresponding elements
   of S and L. ZNL is a list of pairs (z,n) with z > 0 is an element of Z and 
   n is the corresponding element of N. If there does not exist an element n
   in N satisfiing the sign condition v then the empty list is returned. *)

PROCEDURE RRADCOUNT(D,G,H,v,tf: LIST): LIST;
(* Real root arbirary domain count. 
   G is a monic reduced groebner basis of a zerodimensional ideal of domain D,
   H is a list of polynomials of length s. v is a vektor of signs with length 
   not greater than s. tf is the trace-flag.
   ZNL is a list of pairs (z,n) with n is an element of {-1,0,+1}**s and z > 0
   is the number of real zeroes of G wrt the sign condition n for the elements
   of H. ZNL is sorted wrt the invers lexicographical order of the n. If there
   does not exist any real zero or a zero satisfiing the sign condition v, 
   then the empty list is returned. *)

END RRADOM.

(* -EOF- *)
