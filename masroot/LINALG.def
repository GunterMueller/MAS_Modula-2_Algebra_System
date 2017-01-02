(* ----------------------------------------------------------------------------
 * $Id: LINALG.md,v 1.1 1994/03/11 15:21:45 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: LINALG.md,v $
 * Revision 1.1  1994/03/11  15:21:45  pesch
 * Counting real roots of multivariate polynomials, Diplomarbeit F. Lippold
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE LINALG;
(* Linear algebra definition module *)

FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: LINALG.md,v 1.1 1994/03/11 15:21:45 pesch Exp $";
CONST copyright = "Copyright (c) 1993 Universitaet Passau";
	
(* Arbitrary domain linear algebra ---------------------------------------- *)

PROCEDURE ADUM(D,n: LIST): LIST;
(* Arbitrary domain unit matrix. 
   n is an integer. The (n x n) unit matrix of domain D is returned. *)

PROCEDURE ADVSPROD(D,A,B: LIST): LIST;
(* Arbitrary domain vector scalar product. 
   A and B are vectors of the domain D. The arbitrary domain value 
   C = a1*b1 + ... + an*bn is returned. *)

PROCEDURE ADVSVPROD(A,b: LIST): LIST;
(* Arbitrary domain vector scalar vector product. 
   A is an arbitrary domain vector and b is a number of the same domain. 
   The arbitrary domain vector C = (a1*b, ..., an*b) is returned. *)

PROCEDURE ADVVSUM(A,B: LIST): LIST;
(* Arbitrary domain vector vector sum. 
   A and B are arbitrary domain vectors. The arbitrary domain vector 
   C = (a1+b1, ..., an+bn) is returned. *)

PROCEDURE ADSMPROD(A,b: LIST): LIST;
(* Arbitrary domain scalar and matrix product.
   A is a arbitrary domain matrix. b is a arbitrary domain number. 
   The arbitrary domain matrix C = A * b is returned. *)

PROCEDURE ADMSUM(A,B: LIST): LIST;
(* Arbitrary domain matrix sum. 
   A and B are arbitrary domain matrices. The arbitrary domain matrix 
   C = A + B is returned. *)

PROCEDURE ADMPROD(D,A,B: LIST): LIST;
(* Arbitrary domain matrix product. 
   A and B are matrices of domain D. The matrix C = A * B of domain D is 
   returned, if the number of columns of A is equal to the number of rows 
   of B, otherwise the empty matrix is returned. *)

PROCEDURE ADVWRITE(A: LIST);
(* Arbitrary domain vector write. 
   A is an arbitrary domain vector. A is written to the output stream. *)

PROCEDURE ADMWRITE(A: LIST);
(*Arbitrary domain matrix write. 
  A is an arbitrary domain  matrix. A is written to the output stream. *)

PROCEDURE ADMTRACE(D,A: LIST): LIST;
(* Arbitrary domain matrix trace. 
   A is a matrix of domain D. The trace of A is returned. *)

PROCEDURE ADMPTRACE(D,A,B: LIST): LIST;
(* Arbitrary domain matrix product trace. 
   A and B are matrices of domain D. The trace of A*B is returned. *)

PROCEDURE ADCHARPOL(D,Q: LIST): LIST;
(* Arbitrary domain characteristic polynomial. 
   Q is a p x p Matrix of domain D. The list al=(a(0),...,a(p)) is created 
   such that a(i) from D is the coefficient of X^(p-i) in det(XE-Q). *)

PROCEDURE ADSIG(D,Q: LIST): LIST;
(* Arbitrary domain signature. 
   Q is a symmetric p x p Matrix of domain D. The signature of Q ist returned.
   ADCHARPOL is used. *)

(* Integer linear algebra ------------------------------------------------- *)

PROCEDURE IMTRACE(A: LIST): LIST;
(* Integral matrix trace. 
   A is an integral matrix. The trace of A is returned. *)

PROCEDURE IMPTRACE(A,B: LIST): LIST;
(* Integral matrix product trace. 
   A and B are integral matrices. The trace of the matrix A*B is returned. *)

PROCEDURE ICHARPOL(Q: LIST): LIST;
(* Integral matrix characteristic polynomial. 
   Q is an integral p x p Matrix. The list al = (a(0),...,a(p)) of integers 
   is created with a(i) is the coefficient of X^(p-i) in det(XE-Q). *)

PROCEDURE ISIG(Q: LIST): LIST;
(* Integral matrix signature. 
   Q is a symmetric integral p x p Matrix. The signature of Q ist returned.
   ICHARPOL is used *)

PROCEDURE IMRTPROD(A,B: LIST): LIST;
(* Integral matrix right tensor product. 
   A and B are integral matrices. The matrix C is constructed by 
   replacing every entry a(i,j) of A by the matrix a(i,j)*B. *) 

END LINALG.

(* -EOF- *)
