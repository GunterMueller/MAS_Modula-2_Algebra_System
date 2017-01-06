(* ----------------------------------------------------------------------------
 * $Id: SACM.md,v 1.2 1992/02/12 13:19:14 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACM.md,v $
 * Revision 1.2  1992/02/12  13:19:14  pesch
 * Moved CONST Definition to the right place.
 *
 * Revision 1.1  1992/01/22  15:08:16  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)
 
DEFINITION MODULE SACM;

(* SAC Modular Digit and Integer Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: SACM.md,v 1.2 1992/02/12 13:19:14 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";


    
PROCEDURE MDCRA(ML1,ML2,MLP1,AL1,AL2: LIST): LIST;
(*Modular digit chinese remainder algorithm.  m1 and m2 are positive
beta-integers, with GCD(m1,m2)=1 and m=m1*m2 less than beta.
mp1 is the inverse of m1 in Z(m2).  a1 and a2 are elements of
Z(m1) and Z(m2) respectively.  a is the unique element of Z(m) such
that a is congruent to a1 modulo m1 and a is congruent to a2
modulo m2.*)


PROCEDURE MDDIF(ML,AL,BL: LIST): LIST;
(*Modular digit difference.  m is a positive beta-integer.  a and b
belong to Z sub m.  c=a-b.*)


PROCEDURE MDEXP(ML,AL,NL: LIST): LIST;
(*Modular digit exponentiation.  m is a positive beta-integer.
a belongs to Z sub m.  n is a non-negative beta-integer.  b=a**n.*)


PROCEDURE MDHOM(ML,A: LIST): LIST;
(*Modular digit homomorphism.  m is a positive beta-integer.  A is an
integer.  b is the image of A under the homomorphism H sub m.*)


PROCEDURE MDINV(ML,AL: LIST): LIST;
(*Modular digit inverse.  m is a positive beta-integer.  a is a unit
of Z sub m.  b=a**-1.*)


PROCEDURE MDLCRA(ML1,ML2,L1,L2: LIST): LIST;
(*Modular digit list chinese remainder algorithm.  m1 and m2 are
positive beta-integers, with GCD(m1,m2)=1 and m=m1*m2 less than
beta.  L1 and L2 are lists of elements of Z(m1) and Z(m2)
respectively.  L is a list of all a in Z(m) such that a is congruent
to a1 modulo m1 and a is congruent to a2 modulo m2 with a1 in L1
and a2 in L2.*)


PROCEDURE MDNEG(ML,AL: LIST): LIST;
(*Modular digit negative.  m is a positive beta-integer.  a belongs
to Z sub m.  b=-a.*)


PROCEDURE MDPROD(ML,AL,BL: LIST): LIST;
(*Modular digit product.  m is a positive beta-integer.  a and b
belong to Z sub m.  c=a*b.*)


PROCEDURE MDQ(ML,AL,BL: LIST): LIST;
(*Modular digit quotient.  m is a positive beta-integer.  a and b
belong to Z sub m.  b is a unit.  c=a/b.*)


PROCEDURE MDRAN(ML: LIST): LIST;
(*Modular digit, random.  m is a positive beta-digit.  a is a random
element of Z(m).*)


PROCEDURE MDSUM(ML,AL,BL: LIST): LIST;
(*Modular digit sum.  m is a positive beta-integer.  a and b belong
to Z sub m.  c=a+b.*)


PROCEDURE MIDCRA(M,ML,MLP,A,AL: LIST): LIST;
(*Modular integer digit chinese remainder algorithm.  M is a positive
integer.  m is an odd positive beta-integer.  GCD(M,m)=1.  mp is the
inverse of the image of M under the homomorphism H sub m.  A and a
are elements of Z prime sub M and Z sub m respectively.  AS is the
unique element of Z prime sub MS which is congruent to A modulo M and
congruent to a modulo m, where MS=M*m.*)


PROCEDURE MIDIF(M,A,B: LIST): LIST;
(*Modular integer difference.  M is a positive integer.  A and B
belong to Z sub M.  C=A-B.*)


PROCEDURE MIEXP(M,A,N: LIST): LIST;
(*Modular integer exponentiation.  M is a positive integer.  A is an
element of Z(M).  N is a non-negative integer.  B=A**N in Z(M).*)


PROCEDURE MIHOM(M,A: LIST): LIST;
(*Modular integer homomorphism.  M is a positive integer.  A is an
integer.  AS=H sub M(A).*)


PROCEDURE MIINV(M,A: LIST): LIST;
(*Modular integer inverse.  M is a positive integer.  A is a unit of
Z sub M.  B=A**-1.*)


PROCEDURE MINEG(M,A: LIST): LIST;
(*Modular integer negation.  M is a positive integer.  A belongs to
Z sub M.  B=-A.*)


PROCEDURE MIPROD(M,A,B: LIST): LIST;
(*Modular integer product.  M is a positive integer.  A and B belong to
Z(M).  C=A*B in Z(M).*)


PROCEDURE MIQ(M,A,B: LIST): LIST;
(*Modular integer quotient.  M is a positive integer.  A and B belong
to Z sub M.  B is a unit.  C=A/B.*)


PROCEDURE MIRAN(M: LIST): LIST;
(*Modular integer, random.  M is a positive integer.  R is a uniformly
distributed random element of Z sub M.*)


PROCEDURE MISUM(M,A,B: LIST): LIST;
(*Modular integer sum.  M is a positive integer.  A and B belong to
Z sub M.  C=A+B.*)


PROCEDURE SMFMI(M,A: LIST): LIST;
(*Symmetric modular from modular integer.  M is a positive integer.
A belongs to Z sub M.  B belongs to Z prime sub M with B=A(modulo M).*)


END SACM.


(* -EOF- *)
