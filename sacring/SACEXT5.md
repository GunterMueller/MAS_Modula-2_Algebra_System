(* ----------------------------------------------------------------------------
 * $Id: SACEXT5.md,v 1.2 1992/02/12 17:34:50 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACEXT5.md,v $
 * Revision 1.2  1992/02/12  17:34:50  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:15:31  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SACEXT5;

(* SAC Extensions 5 Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: SACEXT5.md,v 1.2 1992/02/12 17:34:50 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE IPCSFB(RL,A: LIST): LIST; 
(*Integral polynomial coarsest squarefree basis.  A eq (A sub 1
, ..., A sub n ), n ge 0, is a list of positive primitive integral
polynomials in r variables, r ge 1, each of which is of positive
degree in its main variable.  B is a coarsest squarefree basis
for A.*)


PROCEDURE IPDSCR(RL,A: LIST): LIST; 
(*Integral polynomial discriminant.  A is an integral polynomial
in r variables, r ge 1, of degree greater than or equal to two in
its main variable.  B is the discriminant of A.*)


PROCEDURE IPLCPP(RL,A: LIST;  VAR C,P: LIST); 
(*Integral polynomial list of contents and primitive parts.
A eq (A sub 1 , ..., A sub n ), n ge 0, is a list of integral
polynomials in r variables, r ge 1.  C eq (C sub 1 , ..., C sub s ),
0 le s le n, is a list such that for 1 le i le n, content(a sub i ) eq
c sub j for some j, 1 le j le s, if and only if content(a sub i )
has positive degree in some variable.
P eq (P sub 1 , ..., P sub m ), 0 le m le n, is a list such that
for 1 le i le n, PP(A sub i ) eq P sub j for some j, 1 le j le m,
if and only if PP(a sub i ) has positive degree in its main
variable.*)


PROCEDURE IPPSC(RL,A,B: LIST): LIST; 
(*Integral polynomial principal subresultant coefficients.  A and B
are integral polynomials in r variables, r ge 1, of positive degree
in the main variable.  P is a list of the principal subresultant
coefficients of the second kind of A and B.*)


PROCEDURE IPSFBA(RL,A,B: LIST): LIST; 
(*Integral polynomial squarefree basis augmentation.  A is a
primitive positive squarefree integral polynomial in r variables,
r ge 1, of positive degree in its main variable.
B eq (B sub 1 , ..., B sub s ), s ge 0, is a squarefree integral
polynomial basis in r variables.  BS is a coarsest squarefree
basis for (A,B sub 1 , ..., B sub s ).*)


PROCEDURE ISPSFB(RL,A: LIST): LIST; 
(*Integral squarefree polynomial squarefree basis.  A eq (A sub 1
, ..., A sub n ), n ge 0, is a list of positive primitive squarefree
integral polynomials in r variables,r ge 1, each of which is of
positive degree in its main variable.  B is a coarsest squarefree
basis for A.*)


PROCEDURE IUPRC(A,B: LIST;  VAR C,R: LIST); 
(*Integral univariate polynomial resultant and cofactor.  A and B are
univariate integral polynomials of positive degree.  R is the
resultant of A and B.  C is a univariate integral polynomial such
that for some univariate integral polynomial D, AD+BC eq R.*)


PROCEDURE MUPRC(PL,A,B: LIST;  VAR C,RL: LIST); 
(*Modular univariate polynomial resultant and cofactor.  p is a
prime beta-digit.  A and B are univariate polynomials over
Z sub p of positive degree.  R is the resultant of A and B,
an element of Z sub p.  C is a univariate polynomial over
Z sub p such that for some univariate polynomial D over
Z sub p, AD+BC eq R.*)


END SACEXT5.
(* -EOF- *)
