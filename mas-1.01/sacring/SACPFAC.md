(* ----------------------------------------------------------------------------
 * $Id: SACPFAC.md,v 1.2 1992/02/12 17:34:59 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACPFAC.md,v $
 * Revision 1.2  1992/02/12  17:34:59  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:15:41  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SACPFAC;

(* SAC Polynomial Factorization Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: SACPFAC.md,v 1.2 1992/02/12 17:34:59 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE IPCEVP(RL,A: LIST;  VAR B,L: LIST); 
(*Integral polynomial, choice of evaluation points.  A is an r-variate
integral polynomial, square-free in its main variable x, r ge 1.  L is
a list (l sub 1, ...,l sub r-1) of beta-integers, with L as small as
possible in reverse lexicographic order with 0 lt 1 lt -1 lt 2 lt -2 lt
 ... such that deg sub x of A(x1, ...,x sub r-1,x)=deg sub x of A(l sub
1, ...,l sub r-1,x), and A(l sub 1, ...,l sub r-1,x) is the square-
free univariate integral polynomial B.*)


PROCEDURE IPFAC(RL,A: LIST;  VAR SL,CL,L: LIST); 
(*Integral polynomial factorization.  A is a non-zero integral
polynomial in r variables, r ge 1.  s=sign(A).  c is the integer
content of A.  L is a list ((e1,A1), ...,(ek,Ak)), k ge 0, where
each ei is a positive integer, the Aips are the distinct positive
irreducible integral factors of A, and A=s*c*(the product from i
equal 1 to k of Ai**ei).*)


PROCEDURE IPGFCB(RL,A: LIST): LIST; 
(*Integral polynomial Gelfond factor coefficient bound.  A is an
integral polynomial in r variables, r gt 0.  a=2**h*(the degree of
A in xr) where h=the least integer greater than the sum from i=1 to
r of the maximum of 0 and ((2*the i-th partial derivative of A)-1)/2.
a is an integer.*)


PROCEDURE IPIQH(RL,PL,D,AB,BB,SB,TB,M,C: LIST;  VAR A,B: LIST); 
(*Integral polynomial mod ideal quadratic Hensel lemma.  D is a list of
non-negative beta-integers (d sub 1, ...,d sub r-1), r ge 1.  AB, BB,
SB and TB belong to Z sub p (x sub 1, ...,x sub r-1,y)/(x sub 1 ** d
sub 1, ...,x sub r-1 ** d sub r-1), with AB monic, AB*SB+BB*TB=1,
deg sub y of AB gt 0 and p a prime beta-integer.  C is an r-variate
integral polynomial with AB*BB congruent to C.  M, a positive integer,
is equal to p**j for some positive integer j.  A, B belong to Z sub M
(x sub 1, ...,x sub r-1,y)/(x sub 1 ** d sub 1, ...,x sub r-1 ** d
sub r-1), with A monic, A congruent to AB, B congruent to BB, deg sub y
of A=deg sub y of AB, and A*B congruent to C.*)


PROCEDURE ISFPF(RL,A: LIST): LIST; 
(*Integral squarefree polynomial factorization.  A is a positive
integral polynomial in r variables, r ge 1, which with respect to its
main variable is of positive degree, primitive, and squarefree.  L is a
list (A1, ...,Ak) of the distinct positive irreducible factors of A.*)


PROCEDURE MIPISE(RL,M,D,A,B,S,T,C: LIST;  VAR U,V: LIST); 
(*Modular integral polynomial mod ideal, solution of equation.  D is a
list (d sub 1, ...,d sub r-1) of non-negative beta-integers, r ge 1.
A, B, S, T and C belong to Z sub M (x sub 1, ...,x sub r-1,y)/(x sub 1 **
d sub 1, ...,x sub r-1 ** d sub r-1), with A monic and of positive
degree in y, and A*S+B*T=1.  U and V belong to Z sub M(x sub 1, ...,x
sub r-1,y)/(x sub 1 ** d sub 1, ...,x sub r-1 ** d sub r-1) such
that A*U+B*V=C, and deg sub y of V lt deg sub y of A.*)


PROCEDURE MPIQH(RL,PL,D,AB,BB,SB,TB,M,DP,C: LIST;  VAR A,B: LIST); 
(*Modular polynomial mod ideal, quadratic Hensel lemma.  p is a beta-
prime.  D and DP are lists of positive beta-integers of length r-1, r
ge 1.  AB, BB, SB, TB belong to Z sub p (x sub 1, ...,x sub r-1,y)/(x sub
1 ** d(1), ...,x sub r-1 ** d(r-1)), with AB monic, AB*SB+BB*TB=1, and
deg sub y of AB gt 0.  C is an r-variate integral polynomial, with AB*
BB congruent to C.  M, a positive integer, is equal to p**j for some
positive integer j.  A, b belong to Z sub M(x sub 1, ...,x sub r-1,y)/
(x sub 1 ** DP(1), ...,x sub rl-1 ** DP(r-1)), with A monic, A
congruent to AB, B congruent to BB, deg sub y of A=deg sub y of AB, and
A*B congruent to C.*)


PROCEDURE MPIQHL(RL,PL,F,M,D,C: LIST): LIST; 
(*Modular polynomial mod ideal quadratic Hensel lemma, list.  C is an
r-variate integral polynomial.  F is a list (f sub 1, ...,f sub m)
of monic univariate polynomials of positive degree over Z sub p, with
the product of the f sub i (x) similar to C(0, ...,0,x), and gcd(f
sub i, f sub j)=1 for 1 le i lt j le m, p a beta-prime not
dividing ldcf(C).  M is a positive power of p.  D is a list (d
sub 1, ...,d sub r-1) of non-negative beta-integers.  FP is a list (fp
sub 1, ...,fp sub m) of monic polynomials in Z sub M (x sub 1, ...,x
sub r-1,x)/(x sub 1 ** d sub 1, ...,x sub r-1 ** d sub r-1), with
C similar to the product of the fp sub i, fp sub i congruent to f
sub i, and deg sub x of fp sub i=deg sub x of f sub i, for 1 le
i le m.*)


PROCEDURE MPIQHS(RL,M,D,AB,BB,SB,TB,SL,NL,C: LIST; VAR A,B,S,T,DP: LIST); 
(*Modular polynomial mod ideal, quadratic Hensel lemma on a single variable. 
M is a positive integer.  D is a list of positive beta-integers 
(d sub 1, ...,d sub r-1), r ge 2.  AB, BB, SB, TB belong to
Z sub M(x sub 1, ...,x sub r-1,y)/(x sub 1 ** d sub 1, ...,x sub r-1
**d sub r-1).  s is a positive integer lt r, and N is a
non-negative  beta-integer.  C is an element of Z sub M ( x sub 1, ...,
x sub r-1,yl).  AB is monic. AB*SB+BB*TB=1, AB*BB is congruent to C, 
and deg sub y of AB gt 0. 
A, B, S, T belong to Z sub M(x sub 1, ...,x sub r-1,y)/(x
sub 1 ** d sub 1, ...,S sub s-1 ** d sub s-1,x sub s ** n,x sub
s+1 ** d sub s+1, ...,x sub r-1 ** d sub r-1), with A*S+B*T=1, deg
sub y of A=deg sub y of AB, A monic, A*B congruent to C, and A congruent
to AB, B congruent to BB, S congruent to SB, T congruent to TB.  DP is
a list of non-negative beta-integers (d sub 1, ...,d sub
s-1,n,d sub s+1, ...,d  sub r-1).*)


END SACPFAC.
(* -EOF- *)
