(* ----------------------------------------------------------------------------
 * $Id: SACEXT4.md,v 1.2 1992/02/12 17:34:49 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACEXT4.md,v $
 * Revision 1.2  1992/02/12  17:34:49  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:15:30  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SACEXT4;

(* SAC Extensions 4 Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: SACEXT4.md,v 1.2 1992/02/12 17:34:49 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE IPINT(RL,A,BL: LIST): LIST; 
(*Integral polynomial integration.  A is a non-zero integral
polynomial in r variables, r ge 1, such that the integral of a with
respect to its main variable is an integral polynomial.  b is an
integral polynomial in r-1 variables.  B eq B(x sub 1 , ..., x sub r )
is the integral of a with respect to its main variable, such that
B(x sub 1 , ..., x sub r-1 ,0) eq b.*)


PROCEDURE IUPIHT(A,NL: LIST): LIST; 
(*Integral univariate polynomial integer homothetic transformation.
A is a non-zero univariate integral polynomial.  n is a non-zero
integer.  B(x) is the primitive part of A(nx).*)


PROCEDURE PCONST(RL,A: LIST): LIST; 
(*Polynomial constant.  A(x sub 1 ,  ..., x sub r ) is a polynomial
in r variables, r ge 1.  b eq 1 if a is a constant polynomial,
otherwise b eq 0.*)


PROCEDURE PSDSV(RL,A,IL,NL: LIST): LIST; 
(*Polynomial special decomposition, specified variable.  A is a
polynomial in r variables.  1 le i le r and n is a beta-integer such
that each exponent of x sub i occurring in a is divisible by n.
B is A with each exponent e of x sub i replaced by e/n.*)


PROCEDURE PUNT(RL,A: LIST): LIST; 
(*Polynomial univariate test.  A eq A(x sub 1 , ..., x sub r ) is a
polynomial in r variables, r ge 1.  b eq 2 if A has degree zero in all
variables.  b eq 1 if A has degree zero in x sub 2 , ..., x sub r, but
positive degree in x sub 1.  otherwise b eq 0.*)


PROCEDURE RPDMV(RL,A: LIST): LIST; 
(*Rational polynomial derivative, main variable.  A is a rational
polynomial in r variables.  B is the derivative of A with respect to
its main variable.*)


PROCEDURE RPMAIP(RL,A: LIST): LIST; 
(*Rational polynomial monic associate of integral polynomial.
A is an integral polynomial in r variables, r ge 1.  If A eq 0
then B eq 0.  if A ne 0, let the integer a be the leading base
coefficient of A.  Then B eq (1/a) A, a monic rational polynomial.*)


END SACEXT4.

(* -EOF- *)
