(* ----------------------------------------------------------------------------
 * $Id: DIPE.md,v 1.2 1992/02/12 17:33:26 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPE.md,v $
 * Revision 1.2  1992/02/12  17:33:26  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:13:11  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DIPE;

(* DIP Exterior Algebra Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: DIPE.md,v 1.2 1992/02/12 17:33:26 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE COPYOB(A: LIST): LIST; 
(*Copy object. A is an object. B is the copy of A.*)


PROCEDURE EIMWRT(A: LIST); 
(*Exterior integral matrix write. A is an exterior
integral matrix. A is written in the output stream.*)


PROCEDURE EIVABS(U: LIST): LIST; 
(*Exterior integral vector absolute value. U is an
exterior integral vector. V is the absolute value of U. *)


PROCEDURE EIVAPP(U: LIST): LIST; 
(*Exterior integral vector absolute primitive part. U is an
exterior integral vector. V is the absolute primitive part of U. *)


PROCEDURE EIVCPP(U: LIST;  VAR V,VL: LIST); 
(*Exterior integral vector content and primitive part.
U is an exterior integral vector. v is the content and
V is the primitive part of U. *)


PROCEDURE EIVEPR(U,V: LIST): LIST; 
(*Exterior integral vector exterior product. U and V are exterior
integral vectors. W is the exterior product of U and V.*)


PROCEDURE EIVFUP(A,PL: LIST): LIST; 
(*Exterior integral vector from univariate integral polynomial
with multiplication by power of main variable. A is an
univariate integral polynomial. p is a beta-integer. B is the
exterior integral vector from A(x)*(x**p). *)


PROCEDURE EIVILP(U,V: LIST): LIST; 
(*Exterior integral vector inner left product. U and V are
exterior integral vectors. W is the inner left
product of U and V.*)


PROCEDURE EIVIP(A,BL: LIST): LIST; 
(*Exterior integral vector integer product. A is an
exterior integral vector, b is an integer, C=A*b. *)


PROCEDURE EIVIQ(A,BL: LIST): LIST; 
(*Exterior integral vector integer quotient. A is an
exterior integral vector, b is a nonzero integer,
and b divides any coefficient of A. C=A/b.*)


PROCEDURE EIVIRP(U,V: LIST): LIST; 
(*Exterior integral vector inner right product. U and V are
exterior integral vectors. W is the inner right
product of U and V.*)


PROCEDURE EIVNEG(U: LIST): LIST; 
(*Exterior integral vector negative. U is an exterior
integral vector. V is the negative of U. *)


PROCEDURE EIVPP(U: LIST): LIST; 
(*Exterior integral vector primitive part. U is an
exterior integral vector. V is the primitive part of U. *)


PROCEDURE EIVSIG(U: LIST): LIST; 
(*Exterior integral vector sign. U is an exterior
integral vector. s is the sign of U. *)


PROCEDURE EIVSUM(U,V: LIST): LIST; 
(*Exterior integral vector sum. U and V are exterior
integral vectors. W is the sum of U and V.*)


PROCEDURE EIVWRT(A: LIST); 
(*Exterior integral vector write. A is an exterior
integral vector. A is written in the output stream.*)


PROCEDURE EXIDET(M: LIST): LIST; 
(*Exterior integral matrix determinant. M is an exterior integral
matrix. d is the determinant of A.*)


PROCEDURE EXIDT2(M: LIST): LIST; 
(*Exterior integral matrix determinant 2. M is an exterior integral
matrix. d is the determinant of A.*)


PROCEDURE EXMHOM(M: LIST): LIST; 
(*Exterior matrix homomorphism. M=(m1,... ,mn) is a
vector of integral vectors mi, 0 le i le n. MS is a
vector of exterior integral vectors, MS=(ms1,... ,msn).
were msi=EXVHOM(mi). *)


PROCEDURE EXVHOM(U,SL: LIST): LIST; 
(*Exterior vector homomorphism. U=(u1,... ,un) is an
integral vector of n components, 0 le n. s is the
starting index for the exterior index list.
V=(u1,(s),... ,un,(s+n)).  *)


PROCEDURE ITD(A: LIST): LIST; 
(*Integer trailing digit. A is an integer,
A = b mod beta.*)


PROCEDURE IJACS(X,Y: LIST): LIST; 
(*Integer Jacobi symbol algorithm. Y is an odd
positive integer, X is an integer relatively prime
to Y. s=(X/Y). *)


PROCEDURE ILADDC(U,CL: LIST): LIST; 
(*Index list addition of constant. U is an index list, c is
a beta-integer. V=(u1+c, ...,un+c) where U=(u1, ...,un). 
n ge 0. *)


PROCEDURE ILEXPR(U,V: LIST;  VAR W,SL: LIST); 
(*Index list exterior product. U, V and W are index lists.
W is the exterior product of U and V. s is the sign
of the exterior product. If s = 0 then W = ().  *)


PROCEDURE ILILPR(U,V: LIST;  VAR W,SL: LIST); 
(*Index list inner left product. U, V and W are index lists.
W is the inner left product of U and V. s is the sign
of the inner left product. If s = 0 then W = ().  *)


PROCEDURE ILINPR(U,V: LIST;  VAR W,SL: LIST); 
(*Index list inner product. U, V and W are index lists. W
is the inner product of U and V, i.e. if U is contained
in V then W is the complement of U in V, otherwise the sign
of the inner product is set to zero. s is the sign of
the inner product. *)


PROCEDURE ILIRPR(U,V: LIST;  VAR W,SL: LIST); 
(*Index list inner right product. U, V and W are index lists.
W is the inner right product of U and V. s is the sign
of the inner right product. if s = 0 then W = ().  *)


PROCEDURE ILSCMP(U,V: LIST): LIST; 
(*Index list strong compare. U=(u1,... ,un), V=(v1,... vm)
are index lists with length n and m. t=1 if n gt m,
t=-1 if n lt m. If n=m then t=0 if U=V,
t=1 if U gt V, t=-1 if U lt V.*)


PROCEDURE ILWCMP(U,V: LIST): LIST; 
(*Index list week compare. U=(u1,... ,un), V=(v1,... vm) are
index lists. t=0 if U=V, t=1 if U gt V, t=-1 if U lt V.*)


PROCEDURE INDLST(RL,SL: LIST): LIST; 
(*Index list. Starting with r and ending with s.*)


PROCEDURE INLWRT(U: LIST); 
(*Index list write. U is an exterior index list.
U is written in the output stream.*)


PROCEDURE IPSR(R: LIST): LIST; 
(*Integral polynomial specified roots. R is a list of integers.
A is an integral univariate polynomial with roots from R. *)


PROCEDURE IVHOM(U,IL,JL: LIST): LIST; 
(*Integer vector homomorphism. U=(u1,(s),... ,un,(r))
is an exterior integral vector. i is the starting index
for the integral vector and j is its ending index.
V=(vi,... ,vj). *)


PROCEDURE IVRAND(KL,QL,NL: LIST): LIST; 
(*Integer vector random. U is an random integer vector with
n components, 0 le n, and the absolut value of each
component is lt 2**k. q is a rational number qd/qn,
with 0 lt qd le qn lt beta. So q is the propability
that any particular component of V is not zero.*)


PROCEDURE KREISP(NL: LIST): LIST; 
(*Kreisteilungs polynom. n is a beta-integer gt 1.
A is an univariate integral polynomial. *)


PROCEDURE MDVHOM(ML,U: LIST): LIST; 
(*Modular vector homomorphism. U is an integral vector.
V is a modular vector. m is a beta-integer.*)


PROCEDURE MIRAND(KL,QL,NL,ML: LIST): LIST; 
(*Matrix random. M is an integral matrix with n rows generated 
by IVRAND(k,q,m). *)


PROCEDURE POWSEV(PL,A: LIST): LIST; 
(*Power of variable symmetric product with exterior vector.
p is a beta-integer. A is an exterior vector. B is the
symmetric product of x**p and A.*)


PROCEDURE UIPRES(A,B: LIST;  VAR CL,KL: LIST); 
(*Univariate integral polynomials resultant. A and B are
univariate integral polynomials. c is the resultant of
A and B. k is the degree of the common factor. *)


PROCEDURE UIPRS1(A,B: LIST): LIST; 
(*Univariate integral polynomials resultant 1. A and B are
univariate integral polynomials. c is the resultant of
A and B. *)


PROCEDURE UIPSIL(A,EL: LIST): LIST; 
(*Univariate integral polynomial symmetric product with exterior index list. 
A is an univariate integral polynomial. e is an exterior index 
list. B is the symmetric product of A and e.*)


PROCEDURE UIPSIV(A,B: LIST): LIST; 
(*Univariate integral polynomial symmetric product with exterior integral vector. 
A is an univariate integral polynomial. B is an exterior integral 
vector. C is the symmetric product of A and B.*)


END DIPE.
(* -EOF- *)
