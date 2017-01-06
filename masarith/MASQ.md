(* ----------------------------------------------------------------------------
 * $Id: MASQ.md,v 1.2 1992/09/28 18:34:54 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASQ.md,v $
 * Revision 1.2  1992/09/28  18:34:54  kredel
 * Updated revision string.
 *
 * Revision 1.1  1992/09/28  17:29:10  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASQ;

(* MAS Quaternion Number Definition Module. *)


FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: MASQ.md,v 1.2 1992/09/28 18:34:54 kredel Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";


PROCEDURE QABS(R: LIST): LIST;
(*Quaternion number absolute value.  R is a quaternion number.  S is the
absolute value of R, a rational number. *)


PROCEDURE QCON(R: LIST): LIST;
(*Quaternion number conjugate.  R is a quaternion number. S is the
quaternion conjugate of R. *)


PROCEDURE QCOMP(R,S: LIST): LIST;
(*Quaternion number comparison.  R and S are quaternion numbers.
t=0 if R=S, t=1 else. *)


PROCEDURE QDIF(R,S: LIST): LIST;
(*Quaternion number difference.  R and S are quaternion numbers.  T=R-S. *)


PROCEDURE QDREAD(): LIST; 
(*Quaternion number decimal read.  The quaternion number R is read
from the input stream.  Any preceding blanks are skipped. *)


PROCEDURE QDWRITE(R,NL: LIST); 
(*Quaternion number decimal write.  R is a quaternion number.  n is a
non-negative integer.  R is approximated by a decimal fraction D with
n decimal digits following the decimal point and D is written in the
output stream.  The inaccuracy of the approximation is at most
(1/2)*10**-n. *)


PROCEDURE QEXP(A,NL: LIST): LIST; 
(*Quaternion number exponentiation.  A is a quaternion number,
n is a non-negative beta-integer.  B=A**n. *)


PROCEDURE QIMi(R: LIST): LIST;
(*Quaternion number imaginary part i.  R is a quaternion number.  b is the
imaginary part i of R, a rational number. *)


PROCEDURE QIMj(R: LIST): LIST;
(*Quaternion number imaginary part j.  R is a quaternion number.  b is the
imaginary part j of R, a rational number. *)


PROCEDURE QIMk(R: LIST): LIST;
(*Quaternion number imaginary part k.  R is a quaternion number.  b is the
imaginary part k of R, a rational number. *)


PROCEDURE QINT(A: LIST): LIST;
(*Quaternion number from integer.  A is an integer.  R is the quaternion
number with real part A/1 and imaginary part 0. *)


PROCEDURE QRE(R: LIST): LIST;
(*Quaternion number real part.  R is a quaternion number.  b is the
real part of R, a rational number. *)


PROCEDURE QRN(A: LIST): LIST;
(*Quaternion number from rational number.  A is a rational number.  
R is the quaternion number with real part A and imaginary part 0. *)


PROCEDURE QRN4(A, B, C, D: LIST): LIST;
(*Quaternion number from 4-tuple of rational numbers.  A, B, C and D 
are rational numbers.  R is the quaternion number with real part A 
and imaginary part i B, imaginary part j C, imaginary part k D. *)


PROCEDURE QINV(R: LIST): LIST;
(*Quaternion number inverse.  R is a non-zero quaternion number.  S R=1. *)


PROCEDURE QNEG(R: LIST): LIST;
(*Quaternion number negative.  R is a quaternion number.  S=-R. *)


PROCEDURE QONE(R: LIST): LIST; 
(*Quaternion number one.  R is a quaternion number.  s=1 if R=1,
s=0 else. *)


PROCEDURE QPROD(R,S: LIST): LIST;
(*Quaternion number product.  R and S are quaternion numbers.  T=R*S. *)


PROCEDURE QQ(R,S: LIST): LIST;
(*Quaternion number quotient.  R and S are quaternion numbers, S non-zero.
T=R/S. *)


PROCEDURE QRAND(NL: LIST): LIST;
(*Quaternion number, random.  n is a positive beta-integer.  Random 
rational numbers A and B are generated using RNRAND(n). Then 
R is the quaternion number with real part A and imaginary part B. *)


PROCEDURE QNREAD(): LIST;
(*Quaternion number read.  The quaternion number R is read from the input
stream.  Any preceding blanks are skipped. *)


PROCEDURE QSUM(R,S: LIST): LIST;
(*Quaternion number sum.  R and S are quaternion numbers.  T=R+S. *)


PROCEDURE QNWRITE(R: LIST);
(*Quaternion number write. R is a quaternion number.  R is converted 
to decimal and written in the output stream. *)


END MASQ. 


(* -EOF- *)
