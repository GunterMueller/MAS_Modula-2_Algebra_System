(* ----------------------------------------------------------------------------
 * $Id: RRINT.md,v 1.1 1994/03/11 15:21:50 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: RRINT.md,v $
 * Revision 1.1  1994/03/11  15:21:50  pesch
 * Counting real roots of multivariate polynomials, Diplomarbeit F. Lippold
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE RRINT;
(* Real Root Integral Definition Module *)

(* Import lists and declarations *)
	
FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: RRINT.md,v 1.1 1994/03/11 15:21:50 pesch Exp $";
CONST copyright = "Copyright (c) 1993 Universitaet Passau";

PROCEDURE RRIPIQ(c: LIST; VAR A,a: LIST);
(* Real root integral polynomial integral quotient.
   A is an integral polynomial. a and c are nonzero integers. New values for 
   A and a are computed such that the equation A/a := (1/c)*(A/a) holds. If a 
   and the content of A have gcd 1 then this is also true for the result. *)

PROCEDURE RRIPQSUM(B,b,c: LIST; VAR A,a: LIST);
(* Real root integral polynomial quotient sum. 
   A and B are integral polynomials. a,b and c are non zero integers. 
   New values for A and a are computed such that the equation 
   A/a := A/a + c*(B/b) holds. If b and the content of B have gcd 1 
   and a and the content of A have gcd 1 then the new integral polynomial 
   A has gcd 1 with the new value of a. *)

PROCEDURE RRINFORM(G,R: LIST; VAR a,NF: LIST);
(* Real root integral normal form. 
   G reduced integral groebner basis of a nontrivial zerodimensional ideal, 
   R is the set of reduced terms. NF is a list of entries (u,ut,ua,up) with: 
   u is an element of R * R, RRREDTEST(G,u,_,ut), up is an integral polynomial
   and ua is an integer such that up/ua is the normal form of u wrt G. 
   a is the lcm of all integers ua in NF. The elements of NF are sorted with 
   respect to the actual termorder in decreasing order of the first entry. *)

PROCEDURE RRISTRCONST(G,R: LIST; VAR U,a,beta: LIST);
(* Real root integral structure constants. 
   G reduced integral groebner basis of a nontrivial zerodimensional ideal, 
   R the set of reduced terms. beta is the integral matrix of combined 
   structure constants beta[u,v] wrt the basis a*R with u from U = R * R and
   v from R. U and the rows of the matrix beta are sorted with respect to the
   actual termorder in increasing order. *)

PROCEDURE RRIVARMATRICES(G,R,U,beta: LIST; VAR al,L: LIST);
(* Real root integral multiplication matrices of variables.
   G reduced integral groebner basis  of a nontrivial zerodimensional ideal. 
   R is the set of reduced terms in increasing order, U= R * R and beta is the
   set of combined structure constants wrt c*R for some nonzero integer c.
   al=(a(1),...,a(n)) is a list of integers and L is a list of entries of the 
   form (1,M(i)) and M(i) is the matrix of multiplication with a(i)*X(i) wrt 
   c*R. *)

PROCEDURE RRIPOLMATRIX(R,h,f,fl: LIST; VAR Mh,L: LIST);
(* Real root integral polynomial matrix. 
   R is the set of reduced terms in increasing order, 
   h is a polynomial of domain D, f is a positive integer, fl=(f(1),...,f(n))
   is a list of positive integers, L contains nonempty lists L(i) of the form
   j(1),M(1),j(2),M(2),...,j(k),M(k) with 1=j(1)<j(2)<...<j(k) and M(l) is the
   integral matrix of multiplikation with (f*f(i)*X(i))**j(l) for the variable
   X(i). L is extended with new calculated matrices. 
   If d(i) is the maximal degree in the variable X(i) and d is the maximal 
   total degree of the terms of the polynomial h, then Mh is the integral 
   matrix of multiplication with (f**d)*(f(1)**d(1))*...*(f(1)**d(1)) * h. *)

PROCEDURE RRIQUADFORM(R,U,beta,Mh: LIST): LIST;
(* Real root integral quadratic form. 
   R is the set of reduced terms in increasing order, U = R * R and beta is 
   the set of integral combined structure constants wrt a*R for some nonzero
   integer a. Mh is the integral matrix of multiplication with c*h for some
   positive constant c represented columnwise. The matrix Q = (q(i,j)) with 
   q(i,j) = tr(M(h)*M(v(i))*M(v(j)) and v(i),v(j) from a*R is computed. *)

PROCEDURE RRICOUNT(G,H,v,tf: LIST): LIST;
(* Real root integral count. 
   G is an integral reduced groebner basis of a zerodimensional ideal I, 
   H is a list of polynomials of length s. v is a vector of signs with length 
   not greater than s. tf is the trace-flag.
   ZNL is a list of pairs (z,n) with n is an element of {-1,0,+1}**s and z > 0
   is the number of real zeroes of I wrt the sign condition n for the elements
   of H. ZNL is sorted wrt the invers lexicographical order of the n. If there
   does not exist any real zero or a zero satisfiing the sign condition v,
   then the empty list is returned. *)

END RRINT.

(* -EOF- *)