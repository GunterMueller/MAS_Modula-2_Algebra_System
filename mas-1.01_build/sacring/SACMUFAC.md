(* ----------------------------------------------------------------------------
 * $Id: SACMUFAC.md,v 1.2 1992/02/12 17:34:58 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACMUFAC.md,v $
 * Revision 1.2  1992/02/12  17:34:58  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:15:39  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SACMUFAC;

(* SAC Modular Univariate Polynomial Factorization Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: SACMUFAC.md,v 1.2 1992/02/12 17:34:58 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE MCPMV(NL,L: LIST): LIST; 
(*Matrix of coefficients of polynomials, with respect to main variable.
L is a list (L(1), ...,L(k)) of k, ge 1, non-zero polynomials with
degrees less than n.  n is a positive beta-integer.  M is the matrix
with m(1,il)+m(2,i)*x+ ...+m(n,i)*x**(n-1)=L(i) for 1 le i le
k.*)


PROCEDURE MIUPSE(M,A,B,S,T,C: LIST;  VAR U,V: LIST); 
(*Modular integral univariate polynomial, solution of equation.  M is a
positive integer.  A,B,S,T and C belong to Z sub M (x) with ldcf(A) a
unit, deg(T) lt deg(A) and A*S+B*T=1.  U and V are the unique elements
of Z sub M (x) such that A*U+B*V=C, with deg(V) lt deg(A).*)


PROCEDURE MUPBQP(PL,A: LIST): LIST; 
(*Modular univariate polynomial Berlekamp q polynomials construction.
p is a prime beta-integer.  A is a univariate polynomial over Z sub p
with deg(A) ge 2.  Q is the list (Q(0), ...,Q(n-1)), where Q(i)(x)=
rem(x**(p*i),A(x)) and n=deg(A).*)


PROCEDURE MUPDDF(PL,A: LIST): LIST; 
(*Modular univariate polynomial distinct degree factorization.  p is
a prime beta-integer.  A is a monic squarefree univariate polynomial
over Z sub p, with deg(A) ge 2.  L is a list ((n(1),A(1)), ...
,(n(k),A(k))) where each n(i) is a positive integer, n(1) lt
n(2) lt ...lt n(k), and A(i) is the product of all irreducible monic
factors of A  of degree n(i).*)


PROCEDURE MUPFBL(PL,A: LIST): LIST; 
(*Modular univariate polynomial factorization-Berlekamp algorithm.
p is a prime beta-integer.  A is a monic squarefree univariate poly-
nomial, with deg(A) ge 2.  L is a list of all the monic irreducible
factors of A of positive degree.*)


PROCEDURE MUPFS(PL,A,B,DL: LIST): LIST; 
(*Modular univariate polynomial factorization, special.  p is a prime
beta-integer. A is a monic squarefree polynomial in Z sub p(x),deg(A)
ge 2.  B is a list (B(1), ...,B(r)) of monic univariate polynomials
over Z sub p, which constitute a basis for the space of all polynomials
C of degree less than deg(A) such that A is a divisor of C**p-C.
Further-more, B(1)=1.  d is a positive beta-integer such that A has
no irreducible factor of degree less than d.  L is a list
consisting of all the monic irreducible factors of A of positive
degree.*)


END SACMUFAC.

(* -EOF- *)
