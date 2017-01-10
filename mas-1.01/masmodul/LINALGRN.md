(* ----------------------------------------------------------------------------
 * $Id: LINALGRN.md,v 1.3 1995/11/05 09:21:58 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: LINALGRN.md,v $
 * Revision 1.3  1995/11/05 09:21:58  kredel
 * Fixed comments.
 *
 * Revision 1.2  1992/02/12  17:33:10  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:12:33  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE LINALGRN;

(* MAS Linear Algebra Rational Number Definition Module. *)


(*-------------------------------------------------------------------------

Definition Module: Linear Algebra Rational Number 

Programmierpraktikum SS 1990: JUERGEN MUELLER, Heinz Kredel 

Contents: Standartoperations for matrix and vector manipulations,  
          Gaussian elimination, LU-Decomposition, Solve,    
          Inversion, Nullspace, Determinant. 

Stand : 27.09.90, Juergen Mueller                         
        from then date of the file, Heinz Kredel             

Remarks: A vector is represented as a list of elements.
         The elements may be integers or rational numbers.
         A matix is represented as a list of vectors.
         In most circumstances these vectors are interpreted row 
         vectors, but they can also be interpreted as column vectors.

--------------------------------------------------------------------------*)

FROM MASSTOR IMPORT LIST;


(* --------------- arbitrary matrices ------------- *)
CONST rcsid = "$Id: LINALGRN.md,v 1.3 1995/11/05 09:21:58 kredel Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";

 

PROCEDURE MDIM(M : LIST): LIST;
(*Matrix dimension. M is a matrix. MDIM returns
max( row, column) of M. *)


PROCEDURE MGET(M, k, l : LIST): LIST;
(*Matrix get. M is a matrix. k, l are integers, 0 le k le  rows(M),
0 le l le  columns(M). MGET returns the element M(k,l) of matrix M. *)


PROCEDURE MSET(M, k, l, x : LIST): LIST;
(*Matrix set. M is a matrix. k, l are integers, 0 le k le  rows(M),
0 le l le  columns(M). MSET sets the element M(k,l) to x. 
The new matrix is returned. *) 


PROCEDURE VDELEL(V, i : LIST): LIST;
(*Vector delete element. V is a vector. The i-th element of V 
is deleted. 0 le i le length(V). *)


PROCEDURE MDELCOL(M, i : LIST): LIST;
(*Matrix delete column. M is a vector of row vectors. In each 
row the i-th element is deleted, 0 le i le  columns(M). The new 
matrix is returned. *)


PROCEDURE MMINOR(M, i, j : LIST): LIST;
(*Matrix minor. M is a vector of row vectors. The i-th column, 
0 le i le  rows(M), and in each remaining row the j-th element,
0 le j le  columns(M), is deleted. *)


PROCEDURE MTRANS(M : LIST): LIST;
(*Matrix transpose. M is a matrix. The transposed matrix is returned. *)


PROCEDURE VEL(a, n : LIST): LIST;
(*Vector elements. A vector of length n with elements a is returned. *)


PROCEDURE MFILL(M, m, n: LIST): LIST;
(*Matrix fill. M is an upper triangular matrix. A (m x n) matrix 
with zeros in the lower triangular part is returned. *)


PROCEDURE MRANG(U: LIST): LIST;
(*Matrix rang. U is an upper triangular matrix from a
LU-decomposition. The rang of U is returned. *)


(* --------------- rational number matrices ------------- *)

PROCEDURE RNMHILBERT(m, n : LIST): LIST;
(*Rational number matrix Hilbert. m, n integer. A (m x n) rational 
number Hilbert matrix is returned. *)


PROCEDURE RNUM(m, n : LIST): LIST;
(*Rational number unit matrix. m, n integer. A (m x n) rational 
number unit matrix is returned. *)


PROCEDURE RNVWRITE(A, s : LIST);
(*Rational number vector write. A is a rational number vector. 
A is written to the output stream. The rational numbers are written 
as rational numbers if s = -1, as decimal approximations, with s decimal 
digits if s >= 0 or in floating point format if s < -1. *)


PROCEDURE RNVREAD(): LIST;
(*Rational number vector read. A rational number vector is 
read from the input stream, and returned. *)


PROCEDURE RNMWRITE(A, s : LIST);
(*Rational number matrix write. A is a rational number matrix. 
A is written to the output stream. The rational numbers are written 
as rational numbers if s = -1, as decimal approximations, with s decimal 
digits if s >= 0 or in floating point format if s < -1. *)


PROCEDURE RNMREAD(): LIST;
(*Rational number matrix read. A rational number matrix is 
read from the input stream, and returned. *)


PROCEDURE RNVFIV(A : LIST): LIST;
(*Rational number vector from integer vector. A is an integer 
vector. A rational number vector with denominators 1 
and nominators equal to the elements of A is returned. *)


PROCEDURE RNMFIM(M : LIST): LIST;
(*Rational number matrix from integer matrix. A is an integer 
matrix. A rational number matrix with denominators 1 
and nominators equal to the elements of A is returned. *)


PROCEDURE RNVDIF(A, B : LIST): LIST;
(*Rational number vector difference. A and B are rational number 
vectors. The rational number vector C = A - B is returned. *)


PROCEDURE RNVQ(A, B : LIST): LIST;
(*Rational number vector quotient. A and B are rational number vectors.
The rational number vector C = A / FIRST(B) is returned. *)


PROCEDURE RNVQF(A : LIST): LIST;
(*Rational number vector quotient. A is a rational number vector.  
The rational number vector C = A / FIRST(A) is returned. *)


PROCEDURE RNVVSUM(A, B : LIST): LIST;
(*Rational number vector vector sum. A and B are rational number vectors. 
A rational number vector C = A + B is returned. *)


PROCEDURE RNVSVSUM(A, B : LIST): LIST;
(*Rational number vector scalar sum. A and B are rational number vectors.
A rational number vector C = A + FIRST(B) is returned. *)


PROCEDURE RNVSSUM(A : LIST): LIST;
(*Rational number vector scalar sum. A is a rational number vector.
A rational number C = a1 + a2 + ... + an is returned. *)


PROCEDURE RNVSVPROD(A, B : LIST): LIST;
(*Rational number vector scalar vector product. A and B are 
rational number vectors. A rational number vector 
C = (a1*FIRST(B), ..., an*FIRST(B)) is returned. *)


PROCEDURE RNVVPROD(A, B : LIST): LIST;
(*Rational number vector vector product. A and B are 
rational number vectors. A rational number vector 
C = (a1*b1, ..., an*bn) is returned. *)


PROCEDURE RNVSPROD(A, B : LIST): LIST;
(*Rational number vector scalar product. A and B are rational 
number vectors. A rational number C = a1*b1 + ... + an*bn is
returned. *)


PROCEDURE RNVMAX(M : LIST): LIST;
(*Rational number vector maximum norm. M is a rational number 
vector. A rational number a = maximum absolute value M(i) 
is returned. *)


PROCEDURE RNVLC(a, A, b, B : LIST): LIST;
(*Rational number vector linear combination. A and B are rational 
number vectors. a and b are rational numbers. A rational number vector 
C = a*A + b*B is returned. *)


PROCEDURE RNSVPROD(a, A : LIST): LIST;
(*Rational number vector product with scalar. A is a rational 
number vector. a is a rational number. A rational number vector
C = a*A is returned. *)


PROCEDURE RNMSUM(A, B : LIST): LIST;
(*Rational number matrix sum. A and B are rational number
matrices. A rational number matrix C = A + B is returned. *)


PROCEDURE RNMDIF(A, B : LIST): LIST;
(*Rational number matrix difference. A and B are rational number
matrices. A rational number matrix C = A - B is returned. *)


PROCEDURE RNMPROD(A, B : LIST): LIST;
(*Rational number matrix product. A and B are rational number
matrices. A rational number matrix C = A * B is returned, if 
the number of coloums of A is equal to the number of rows of B, 
otherwise the empty matrix is returned. *)


PROCEDURE RNSMPROD(A, B : LIST): LIST;
(*Rational number scalar and matrix product. A is a rational 
number matrix. B is a rational number. A rational number matrix 
C = A * B is returned. *)


PROCEDURE RNMMAX(M : LIST): LIST;
(*Rational number matrix maximum norm. M is a rational number 
matrix. A rational number a = maximum absolute value M(i,j) 
is returned. *)


PROCEDURE RNMGE(M : LIST): LIST;
(*Rational number matrix Gaussian elimination. M is a (n x m) 
rational number matrix. A (n x m) rational number matrix
resulting from Gaussian elimination is returned.  
RNMGELUD is called. *)


PROCEDURE RNMDET(M : LIST): LIST;
(*Rational number matrix determinant, using Gaussian elimination. 
M is a rational number matrix. The determinant of M is returned. *)


PROCEDURE RNMDETL(M : LIST): LIST;
(*Rational number matrix determinant, using Laplace expansion. 
M is a rational number matrix. The determinant of M is returned. *)


PROCEDURE RNMGELUD(M : LIST; VAR L, U: LIST);
(*Rational number matrix Gaussian elimination LU-decomposition. 
M is a rational number matrix represented rowwise. L is a lower 
triangular rational number matrix represented columnwise.
U is an upper triangular rational number matrix represented rowwise.
M = L * U for appropriate modifications of L and U. 
The pivot operations are also recorded in L. *)


PROCEDURE RNMLT(L, b : LIST): LIST;
(*Rational matrix lower triangular matrix transformation. 
L is a lower triangular rational number matrix represented 
columnwise as generated by RNMGELUD. b is a rational number 
vector. A rational number vector u = L * b is returned, 
such that if M * x = b and M = L * U, then U * x = u. *)


PROCEDURE RNMUT(U, b : LIST): LIST;
(*Rational matrix upper triangular matrix transformation. 
U is an upper triangular rational number matrix represented rowwise
as generated by RNMGELUD. b is a rational number vector 
b = L * b' as generated by RNMLT. A rational number vector x, 
such that U * x = b is returned. If no such x exists, then an 
empty vector is returned. If more than one such x exists, then 
for free x(i), x(i) = 0 is taken. *)


PROCEDURE RNMSDS(L, U, b : LIST): LIST;
(*Rational number matrix solve decomposed system. 
L is a lower triangular rational number matrix represented 
columnwise, U is an upper triangular rational number matrix 
represented rowwise. L and U as generated by RNMGELUD.
If M = L * U, then a rational number vector x, such that 
M * x = b is returned. If no such x exists, then an empty 
vector is returned. If more than one such x exists, then 
for free x(i), x(i) = 0 is taken. *)


PROCEDURE RNMINV(A : LIST): LIST;
(*Rational number matrix inversion. A is a rational number matrix 
represented rowwise. If it exists, the inverse matrix of A is 
returned, otherwise an empty matrix is returned. *)


PROCEDURE RNMUNS(U : LIST): LIST;
(*Rational number matrix upper triangular matrix solution null space. 
U is an upper triangular rational number matrix represented rowwise
as generated by RNMGELUD. A matrix X of linear independent rational 
number vectors x is returned, such that for each x in X, U * x = 0 holds. 
If only x = 0 satisfies the condition U * x = 0, then the 
matrix X is empty. *)


END LINALGRN.

(* -EOF- *)
