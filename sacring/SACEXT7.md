(* ----------------------------------------------------------------------------
 * $Id: SACEXT7.md,v 1.2 1992/02/12 17:34:53 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACEXT7.md,v $
 * Revision 1.2  1992/02/12  17:34:53  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:15:35  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SACEXT7;

(* SAC Extensions 7 Definition Module. *)



FROM MASSTOR IMPORT LIST;


CONST rcsid = "$Id: SACEXT7.md,v 1.2 1992/02/12 17:34:53 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";


(* -- depends on IPRRII :-(
PROCEDURE IPRICL(A: LIST): LIST; 
(*Integral polynomial real root isolation, Collins-Loos algorithm.
A is an integral polynomial.  L is a strong isolation list for A.*)
*)


(* -- zuviele gotos :-(
PROCEDURE IPRRII(A,AP,DL,LP: LIST): LIST; 
(*Integral polynomial real root isolation induction.  A is a primitive
positive univariate integral polynomial of positive degree.  AP is
the derivative of A.  D is a binary rational real root bound for A.
LP is a strong isolation list for AP.  L is a strong isolation list
for A.*)
*)


PROCEDURE IPRRRI(A,B,I,SL1,TL1: LIST): LIST; 
(*Integral polynomial relative real root isolation.  A and B are
univariate integral polynomials.  I is a left-open, right-closed
interval (a sub 1 ,a sub 2 ) where al sub 1 and al sub 2 are
binary rational numbers with al sub 1 lt al sub 2.  A and B have
unique roots, alpha and beta respectively, in I, each of odd
multiplicity and with alpha ne beta.  sl sub 1 eq
sign(A(al sub 1 +)) and tl sub 1 eq sign(B(al sub 1 +)).
is eq (al sub 1 sup * ,al sub 2 sup * ) is al left-open, right-closed
subinterval of I with al sub 1 sup * and al sub 2 sup *
binary rational numbers and al sub 1 sup * lt al sub 2 sup *,
such that is contains alpha but not beta.*)


PROCEDURE IPSIFI(A,I: LIST): LIST; 
(*Integral polynomial standard isolating interval from isolating interval.
I is an interval with binary rational endpoints, which is either 
left-open and right-closed or a one-point interval.  A is a univariate
integral polynomial which has a unique root alpha
of odd multiplicity in I.  If I is a one-point interval, then
J=I.  If I is left-open and right-closed, then J is either a
standard left-open and right-closed subinterval of I containing
alpha, or if alpha is a binary rational number, J may
possibly instead be the one-point interval ( alpha , alpha ).*)


PROCEDURE ISFPIR(A,I,KL: LIST): LIST; 
(*Integral squarefree polynomial isolating interval refinement.
A is a squarefree univariate integral polynomial.  I is an
isolating interval for a real root alpha of A.  k is a
nonnegative beta -integer.  J is a subinterval of I isolating alpha
with length less than 10 sup -k.*)


PROCEDURE IUPVOI(A,I: LIST): LIST; 
(*Integral univariate polynomial, variations for open interval.
A is a non-zero integral univariate polynomial.  I is an open
interval (a,b) with a and b binary rational numbers such that
a lt b.  Let t(z) be the transformation mapping the right half-plane
onto the circle having I as diameter.  Let B(X) eq A(t(X)).
then v is the number of sign variations in the coefficients of B.*)


END SACEXT7.

(* -EOF- *)
