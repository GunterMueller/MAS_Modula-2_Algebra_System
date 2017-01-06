(* ----------------------------------------------------------------------------
 * $Id: SACLDIO.md,v 1.2 1992/02/12 17:33:12 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACLDIO.md,v $
 * Revision 1.2  1992/02/12  17:33:12  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:12:35  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SACLDIO;

(* SAC Linear Diophantine Equation System Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: SACLDIO.md,v 1.2 1992/02/12 17:33:12 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE LDSMKB(A,BL: LIST;  VAR XLS,N: LIST); 
(*Linear diophantine system solution, modified Kannan and Bachem algorithm.  
A is an m by n integral matrix.  A is represented
column-wise.  b is an integral m-vector.  If the diophantine
system A*x=b is consistent, then xs is a particular
solution and N is a list of basis vectors of the solution
module of A*x=0.  Otherwise, xs and N are null lists.  A and b are
modified.*)


PROCEDURE LDSSBR(A,BL: LIST;  VAR XLS,N: LIST); 
(*Linear diophantine system solution, based on Rosser ideas.  A is an
m by n integral matrix.  A is represented column-wise.  b is
an integral m-vector.  If the diophantine system A*x=b
is consistent, then xs is a particular solution and N is
a list of basis vectors of the solution module of A*x=0.  Otherwise,
xs and N are null lists.  A and b are modified.*)


PROCEDURE MAIPDE(RL,M: LIST): LIST; 
(*Matrix of integral polynomials determinant, exact division algorithm.
M is a square matrix of integral polynomials in r variables, r ge 0,
represented as a list.  D is the determinant of M.*)


PROCEDURE MAIPDM(RL,M: LIST): LIST; 
(*Matrix of integral polynomials determinant, modular algorithm.  M is
a square matrix of integral polynomials in r variables, r non-negative.
D is the determinant of M.*)


PROCEDURE MAIPHM(RL,ML,A: LIST): LIST; 
(*Matrix of integral polynomials homomorphism.  A is a matrix of
integral polynomials in r variables, r non-negative.  m is a
positive beta-integer.  B is the matrix B(i,j) of polynomials in r
variables  over Z sub m such that B(i,j)=H(m)(A(i,j)).*)


PROCEDURE MAIPP(RL,A,B: LIST): LIST; 
(*Matrix of integral polynomials product.  A and B are matrices of
integral polynomials in r variables, r ge 0, for which the matrix
product A*B is defined.  C=A*B.*)


PROCEDURE MIAIM(A: LIST): LIST; 
(*Matrix of integers, adjoin identity matrix,  A is an m by n matrix
of integers.  A is represented column-wise.  B is the matrix obtained
by adjoining an n by n identity matrix to the bottom of A.  A is
modified.*)


PROCEDURE MICINS(A,V: LIST): LIST; 
(*Matrix of integers column insertion.  A is an m by n integral
matrix represented by the list (a(1),a(2), ...,a(n)), where a(i) is the
list (a(1,i), ...,a(m,i)) representing column i of A and a(1,1)
ge a(1,2) ge  ... ge a(1,m).  V=(v(1), ...,v(m)) is an integral
vector with v(1) lt a(1,1). Let i be the largest integer such that
a(1,i) ge v(1).  Then B is the matrix represented by the list (a(1), ...,
a(i),V,a(i+1), ...,a(n)).  A is modified.*)


PROCEDURE MICS(A: LIST): LIST; 
(*Matrix of integers column sort.  A is an integral matrix with non-
negative elements in first row.  A is represented column-wise.  B is an
integral matrix obtained by sorting columns of A such that elements
of the first row are in descending order.  A is modified.*)


PROCEDURE MINNCT(A: LIST): LIST; 
(*Matrix of integers, non-negative column transformation.
A=(a(i,j)) is an m by n integral matrix.  A is represented
column-wise. B=(b(i,j)) is the m by n integral matrix
with b(i,j)=a(i,j) if a(1,j) ge 0 and b(i,j)=-a(i,j) if
a(1,j) lt 0.  A is modified.*)


PROCEDURE MMDDET(PL,M: LIST): LIST; 
(*Matrix of modular digits determinant.  p is a prime beta-integer.
M is a square matrix over GF(p), represented as a list.  d is the
determinant of M.*)


PROCEDURE MMDNSB(PL,M: LIST): LIST; 
(*Matrix of modular digits null space basis.  p is a prime beta-
integer.  M is an m by n matrix over Z sub p.  B is a list (b(1), ...,
b(r)) representing a basis for the null space of M, consisting of all
x such that M*x=0.  r is the dimension of the null space.  B=() if
the null space of M is 0.  Each b(i) is a list representing an
m-vector.  M is modified.  Alternatively, if M represents a matrix by
columns, then B is a basis for the null space consisting of all x such
that x*M=0.*)


PROCEDURE MMPDMA(RL,PL,M: LIST): LIST; 
(*Matrix of modular polynomials determinant, modular algorithm.  M is a
square matrix of modular polynomials in r variables over Z sub p,
r non-negative, p a prime beta-integer.  D is the determinant of M.*)


PROCEDURE MMPEV(RL,ML,A,KL,AL: LIST): LIST; 
(*Matrix of modular polynomials evaluation.  A is a matrix of
polynomials in r variables over Z sub m, m a positive beta-integer.
1 le k le r and a is an element of Z sub m.  B is the matrix of
polynomials b(i,j) where b(i,j)(x(1), ...,x(k-1),x(k+1), ...,x(r))=
a(i,j)(x(1), ...,x(k-1),a,x(k+1), ...,x(r)).*)


PROCEDURE VIAZ(A,NL: LIST): LIST; 
(*Vector of integers, adjoin zeros.  A is the vector (a(1), ...,a(m)).
n is a non-negative beta-integer.  B is the vector (a(1), ...,a(m),
0, ...,0) of m+n components.  A is modified.*)


PROCEDURE VIDIF(A,B: LIST): LIST; 
(*Vector of integers difference.  A and B are vectors in Z sup n.
C=A-B.*)


PROCEDURE VIERED(U,V,IL: LIST): LIST; 
(*Vector of integers, element reduction.  U=(u(1), ...,u(n)) and
V=(v(1), ...,v(n)) are integral n-vectors.  1 le i le n.  v(i)
ne 0.  W=U-q*V, where q=INTEGER(u(i)/v(i)).*)


PROCEDURE VILCOM(AL,BL,A,B: LIST): LIST; 
(*Vector of integers linear combination.  a and b are integers.  A
and B are integral vectors in Z sup n.  C=a*A+b*B.*)


PROCEDURE VINEG(A: LIST): LIST; 
(*Vector of integers negation.  A is an integral vector.  B=-A.*)


PROCEDURE VISPR(AL,A: LIST): LIST; 
(*Vector of integers scalar product.  a is an integer.  A is an
integral vector.  C=a*A.*)


PROCEDURE VISUM(A,B: LIST): LIST; 
(*Vector of integers sum.  A and B are vectors in Z sup n.  C=A+B.*)


PROCEDURE VIUT(U,V,IL: LIST;  VAR UP,VP: LIST); 
(*Vector of integers, unimodular transformation.  U=(u(1), ...,u(n))
and V=(v(1), ...,v(n)) are vectors in Z sup n with u(i) ne 0.
(UP,VP)=(U,V)*K where K is a unimodular matrix, depending on u(i)
and v(i), whose elements are obtained from IDEGCD.*)


END SACLDIO.
(* -EOF- *)
