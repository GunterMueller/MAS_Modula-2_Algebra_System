(* ----------------------------------------------------------------------------
 * $Id: SACRPOL.md,v 1.2 1992/02/12 17:34:04 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACRPOL.md,v $
 * Revision 1.2  1992/02/12  17:34:04  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:13:56  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SACRPOL;

(* SAC Rational Polynomial Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: SACRPOL.md,v 1.2 1992/02/12 17:34:04 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";

 

PROCEDURE RPDIF(RL,A,B: LIST): LIST;
(*Rational polynomial difference.  A and B are rational polynomials in
r variables, r ge 0.  C=A-B.*)


PROCEDURE RPEMV(RL,A,BL: LIST): LIST;
(*Rational polynomial evaluation, main variable.  A is a rational
polynomial in r variables, r gt 0.  b is a rational number.
C(x(1), ...,x(r-1))=A(x(1), ...,x(r-1),b).*)


PROCEDURE RPFIP(RL,A: LIST): LIST;
(*Rational polynomial from integral polynomial.  A is an integral
polynomial in r variables, r ge 0.*)


PROCEDURE RPIMV(RL,A: LIST): LIST;
(*Rational polynomial integration, main variable.  A is a rational
polynomial in r variables, r gt 0.  B is the integral of A with
respect to its main variable.  The constant of integration is 0.*)


PROCEDURE RPNEG(RL,A: LIST): LIST;
(*Rational polynomial negative.  A is an rational polynomial in r
variables, r ge 0.  B=-A.*)


PROCEDURE RPPROD(RL,A,B: LIST): LIST;
(*Rational polynomial product.  A and B are rational polynomials in r
variables, r ge 0.  C=A*B.*)


PROCEDURE RPQR(RL,A,B: LIST;    VAR Q,R: LIST);
(*Rational polynomial quotient and remainder.  A and B are rational
polynomials in r variables with B non-zero.  Q and R are the unique
rational polynomials such that either B divides A, Q=A/B and R=0 or
else B does not divide A and A=BQ+R with DEG(R) minimal.*)


PROCEDURE RPREAD( VAR RL,A,V: LIST);
(*Rational polynomial read.  The rational polynomial A is read from the
input stream.  r ge 0 is the number of variables of A and V is the
variable list of A.  Any number of preceding blanks are skipped.*)


PROCEDURE RPRNP(RL,AL,B: LIST): LIST;
(*Rational polynomial rational number product.  B is a rational
polynomial in r variables, r ge 0.  a is a rational number.  C=a*B.*)


PROCEDURE RPSUM(RL,A,B: LIST): LIST;
(*Rational polynomial sum.  A and B are rational polynomials in r
variables, r ge 0.  C=A+B.*)


PROCEDURE RPWRIT(RL,A,V: LIST);
(*Rational polynomial write.  A is a rational polynomial in r
variables, r ge 0.  V is a variable list for A.  A is written
in the output stream in external canonical form.*)


END SACRPOL.

(* -EOF- *)
