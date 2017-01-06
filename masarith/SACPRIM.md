(* ----------------------------------------------------------------------------
 * $Id: SACPRIM.md,v 1.2 1992/02/12 13:19:15 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACPRIM.md,v $
 * Revision 1.2  1992/02/12  13:19:15  pesch
 * Moved CONST Definition to the right place.
 *
 * Revision 1.1  1992/01/22  15:08:18  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SACPRIM;

(* SAC Factorization and Prime Number Definition Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST;


VAR UZ210, SMPRM: LIST;

CONST rcsid = "$Id: SACPRIM.md,v 1.2 1992/02/12 13:19:15 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";


    
PROCEDURE DPGEN(ML, K: LIST): LIST;
(*Digit prime generator. K and m are positive beta-integers.  
L is the list (p(1),...,p(r)) of all prime numbers p such that 
m le p lt m+2*K, with p(1) lt p(2) lt ... lt p(r).  
A local array is used.*)


PROCEDURE FRESL(NL: LIST; VAR ML,L: LIST);
(*Fermat residue list.  n is a positive integer with no prime divisors
less than 17.  m is a positive beta-integer and L is an ordered list
of the elements of Z(m) such that if x**2-n is a square then x is
congruent to a (modulo m) for some a in L.*)


PROCEDURE FRLSM(ML,AL: LIST): LIST;
(*Fermat residue list, single modulus.  m is a positive beta-integer.
a belongs to Z(m).  L is a list of the distinct b in Z(m) such
that b**2-a is a square in Z(m).*)


PROCEDURE GDPGEN(ML: LIST; KL: INTEGER): LIST;
(*Gaussian digit prime generator. m and k are positive beta-integers. 
L is the list (p(1),...,p(r)) of all prime numbers p such that m is 
less than or equal to p, p is less than m+4*k and p is congruent to 
3 mod 4, with p(1) lt p(2) lt ... lt p(r).  A local array is used.*)


PROCEDURE IFACT(NL: LIST): LIST;
(*Integer factorization.  n is a positive integer. F is a list 
(q(1), q(2),...,q(h)) of the prime factors of n, q(1) le q(2) le ...
le q(h), with n equal to the product of the q(i).*)


PROCEDURE ILPDS(NL,AL,BL: LIST; VAR PL,NLP: LIST);
(*Integer large prime divisor search.  n is a positive integer with
no prime divisors less than 17.  1 le a le b le n.  A search is made
for a divisor p of the integer n, with a le p le b.  If such a p
is found then np=n/p, otherwise p=1 and np=n.  A modular version
of fermats method is used, and the search goes from a to b.*)


PROCEDURE IMPDS(NL,AL,BL: LIST; VAR PL,QL: LIST);
(*Integer medium prime divisor search.  n, a and b are positive
integers such that a le b le n and n has no
positive divisors less than a.  If n has a prime
divisor in the closed interval from a to b then p is the least
such prime and q=n/p.  Otherwise p=1 and q=n.*)


PROCEDURE ISPD(NL: LIST; VAR F,ML: LIST);
(*Integer small prime divisors.  n is a positive integer.
F is a list of primes (q(1),q(2),...,q(h)), h non-negative,
q(1) le q(2) le ... lt q(h), such that n is equal to m times the
product of the q(i) and m is not divisible by any prime in SMPRM.
Either m=1 or m gt 1,000,000.*)


PROCEDURE ISPT(ML,MLP,F: LIST): LIST;
(*Integer selfridge primality test.  m is an integer greater than or
equal to 3.  mp=m-1.  F is a list (q(1),q(2),...,q(k)),
q(1) le q(2) le ... le q(k), of the prime factors of mp, with
mp equal to the product of the q(i). An attempt is made to find a 
root of unity modulo m of order m-1.  If the existence of such a root 
is discovered then m is prime and s=1.  If it is discovered that no such
root exists then m is not a prime and s=-1.  Otherwise the primality
of m remains uncertain and s=0.*)


END SACPRIM.


(* -EOF- *)
