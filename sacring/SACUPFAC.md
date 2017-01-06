(* ----------------------------------------------------------------------------
 * $Id: SACUPFAC.md,v 1.2 1992/02/12 17:35:06 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACUPFAC.md,v $
 * Revision 1.2  1992/02/12  17:35:06  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:15:48  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SACUPFAC;

(* SAC Univariate Polynomial Factorization Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: SACUPFAC.md,v 1.2 1992/02/12 17:35:06 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE IPFLC(RL,M,I,A,L,D: LIST): LIST; 
(*Integral polynomial factor list combine.  A is a non-constant
primitive r-variate integral polynomial.  M is a positive integer.
I is a list (d sub 1, ...,d sub r - 1) of non-negative beta-digits.
L is a list of monic factors of A modulo M, ((x sub 1)**(d sub 1), ...
,(x sub rl- 1)**(d sub r - 1)) such that if B is an integral factor
of A, then H sub M,I (B) is an associate of some product of elements
of L.  D is either 0, or a characteristic set for the possible degrees
of integral factors of A.  LP is a list of the primitive irreducible
integral factors of A. *)


PROCEDURE IUPFAC(A: LIST;  VAR SL,CL,L: LIST); 
(*Integral univariate polynomial factorization.  A is a non-zero
integral univariate polynomial.  s=sign(A), c=cont(A).  L is
a list ((e1,A1), ...,(ek,Ak)), k ge 0, where each ei is a
positive integer, e1 le e2 le  ... le ek, each A i is an ir-
reducible positive integral univariate polynomial, and A = s * c *
the product of A i ** ei, 1 le i le k.*)


PROCEDURE IUPFDS(A: LIST;  VAR PL,F,C: LIST); 
(*Integral univariate polynomial factor degree set.  A is a non-zero
square-free integral polynomial.  C is the intersection of
the degree sets of factorizations over Z sub p for as many as NPFDS
primes p (fewer only if SMPRM is exhausted or A is proved irredu-
cible). C is represented as a characteristic set.  p is
the least examined prime in P which gave the smallest number of
factors, and F is the distinct degree factorization of A over Z sub p,
unless A is shown to be irreducible, in which case p=0, F=().*)


PROCEDURE IUPQH(PL,AB,BB,SB,TB,M,C: LIST;  VAR A,B: LIST); 
(*Integral univariate polynomial quadratic Hensel lemma.  AB, BB, SB, TB
are univariate polynomials over Z sub p, p a prime beta-integer, with
AB*SB+BB*TB=1, and deg(TB) lt deg(AB).  C is a univariate integral
polynomial with H sub p of C=AB*BB.  M, a positive integer, is equal
to p**j for some positive integer j.  A and B are univariate
polynomials over Z sub M, with H sub p of A=AB, H sub p of B=BB,
ldcf(A)=ldcf(AB),deg(A)=deg(AB), and H sub M of C=A*B.*)


PROCEDURE IUPQHL(PL,F,M,C: LIST): LIST; 
(*Integral univariate polynomial quadratic Hensel lemma, list.  C is an
integral univariate polynomial.  F is a list (f sub 1, ...,f sub r)
of monic polynomials in Z sub p (x) with H sub p of C similar to the
product of the f sub i, and gcd(f sub i,f sub j)=1 for 1 le i
lt j le r, p a beta-prime not dividing ldcf(C).  M is a positive
power of p.  FP is a list (fp sub 1, ...,fp sub r) of monic
polynomials in Z sub M (x) with H sub M of C similar to the product of
the fp sub i, H sub p of fp sub i=f sub i and deg(fp sub
i)=deg(f sub i), for 1 le i le r.*)


PROCEDURE IUSFPF(A: LIST): LIST; 
(*Integral univariate squarefree polynomial factorization.  A is
an integral univariate squarefree polynomial which is positive,
primitive and of positive degree.  L is a list (A1, ...,Ak) of the
positive irreducible factors of A.*)


END SACUPFAC.

(* -EOF- *)
