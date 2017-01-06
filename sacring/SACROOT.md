(* ----------------------------------------------------------------------------
 * $Id: SACROOT.md,v 1.3 1993/05/11 10:51:44 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACROOT.md,v $
 * Revision 1.3  1993/05/11  10:51:44  kredel
 * Spelling errors corr.
 *
 * Revision 1.2  1992/02/12  17:35:04  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:15:46  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SACROOT;

(* SAC Polynomial Real Root Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: SACROOT.md,v 1.3 1993/05/11 10:51:44 kredel Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE IIC(A,AP,I,L: LIST): LIST; 
(*Isolating interval conversion.  A is a squarefree univariate integral
polynomial.  AP is the derivative of A.  I is an left open right closed
interval (a,b) with binary rational endpoints represented by the list
(a,b).  L is a list of isolating intervals with binary rational end-
points for the real roots of A in I.  L=((a(1),b(1)), ...,(a(k),b(k))) 
with a(1) le b(1) le  ... le a(k) le b(k) and (a(i), b(i)) 
represents the open interval (a(i),b(i)) if a(i) lt
b(i), the closed interval (a(i),b(i)) if a(i)=b(i).  LS is a
list ((as(1),bs(1)), ...,(as(k),bs(k))) of isolating intervals for
the same roots and satisfying the same conditions except that each pair
(as(i),bs(i)) represents the left open right closed interval
(as(i),bs(i)).*)


PROCEDURE IPFSD(RL,A: LIST): LIST; 
(*Integral polynomial factorization, second derivative.  A is a
positive primitive integral polynomial in r variables of positive
degree.  L is a list (a(1), ...,a(k)) where k ge 1, A equal to sum of
a(i) for i=1, ...,k and, for each i, a(i) is a positive primitive
integral polynomial of positive degree with deg(a(i)) le 2 or
gcd(a(i),app(i))=1  where app(i) is the second derivative of a(i).*)


PROCEDURE IPLRRI(L: LIST): LIST; 
(*Integral polynomial list real root isolation.  L is a non-empty list
(A sub 1 ,  ..., A sub n ) of distinct univariate integral polynomials
which are positive, of positive degree, squarefree, and pairwise
relatively prime.  M is a list (I sub 1 , B sub 1 , ..., I sub m ,
B sub m ), where I sub 1  lt  I sub 2  lt   ...  lt  I sub m are
strongly disjoint isolating intervals for all of the real roots of A eq
prod from (j eq 1) to n (A sub j).  Each I sub i has binary
rational number endpoints, and is either left-open and
right-closed or is a one-point interval.  B sub i is the unique A
sub j which has a root in I sub i.*)


PROCEDURE IPRCH(A,I,KL: LIST): LIST; 
(*Integral polynomial real root calculation, high precision.  A is a
univariate integral polynomial of positive degree.  I is either the
nulllist () or a standard interval or an interval whose positive and
non-positive parts are standard.  k is a gamma-integer.  L is a
list ((e(1),I(1)), ...,(e(r),I(r))) where the e(j) are
beta-integers,  1 le e(1) le  ... le e(r), and the I(j) are binary
rational isolating intervals, I(j)=(a(j),b(j)), for the r distinct
real roots of A if I=(), or for the r distinct real roots of A in I if
I ne ().  e(j) is the multiplicity of the root alpha(j) in I(j) and
abs(b(j)-a(j))  le 2**k.  I(j) is a left-open and right-closed
interval if a(j) lt b(j), a one-point interval if a(j)=b(j).*)


PROCEDURE IPRCHS(A,I,KL: LIST): LIST; 
(*Integral polynomial real root calculation, high-precision special.
A is a positive, primitive, squarefree, univariate, integral polynomial
of positive degrre with GCD(A,APP)=1.  I is either the null list () or
a standard interval or an interval whose positive and non-positive parts
are standard.  k is a gamma-integer.  L is a list (I(1), ...,I(r)) of
binary rational isolating intervals I(j)=(a(j),b(j)) for the r
distinct real roots of A if I=(), for the r distinct real roots of A
of I if I ne (), with b(j)-a(j) le 2**kl.  I(j) is a left-open and
right-closed interval if a(j) ne b(j), a one-point interval if
a(j)=b(j).*)


PROCEDURE IPRCNP(A,I: LIST;  VAR SLP,SLPP,J: LIST); 
(*Integral polynomial real root calculation, newton method preparation.
A is a positive, primitive, squarefree, univariate integral polynomial
of positive degree.  I is an open interval (a1,a2) with binary
rational endpoints containing no roots of AP and APP.  sp and spp,
beta-integers, are the signs of AP and APP on I.  J is a subinterval
(b1,b2) of I with binary rational endpoints, containing alpha and
such that spp*SIGN(AP(b1)+f*AP(b2)) ge 0, where
f=(-3/4)**(sp*spp).  J is a left-open and right-closed interval if
b1 lt b2, the one-point interval if b1=b2.*)


PROCEDURE IPRCN1(A,I,SL,KL: LIST): LIST; 
(*Integral polynomial real root calculation, 1 root.  A is a positive
primitive univariate integral polynomial of positive degree. I is an
open interval (a1,a2) with binary rational endpoints containing a
unique root alpha of A and containing no roots of AP or APP.  s, a
beta-integer, is the sign of AP*APP on I.
min(abs(AP(a1)),abs(AP(a2))) le (3/4)*max(abs(AP(a1)),abs(AP(a2))).
k is a beta-integer.  J is a subinterval of I of length 2**k or less
containing alpha and with binary rational endpoints.*)


PROCEDURE IPRIM(A: LIST): LIST; 
(*Integral polynomial real root isolation, modified Uspensky method.
A is a non-zero squarefree univariate integral polynomial.  L is
a list (I sub 1 , ..., I sub r ) of strongly disjoint isolating
intervals for all of the real roots of A with I sub 1  lt  I
sub 2  lt   ...  lt  I sub r.  Each I sub j has binary rational
endpoints and is either left-open and right-closed or a one-point
interval.*)


PROCEDURE IPRIMO(A,AP,I: LIST): LIST; 
(*Integral polynomial real root isolation, modified Uspensky method, open interval.  
A is a univariate integral polynomial without multiple roots.  
AP is the derivative of A.  I is an open interval (a,b) with
binary rational endpoints, represented by the list (a,b), such that
there are integers h and k for which a=h*2**k and b=(h+1)*2**k.
L is a list (I(1), ...,I(r)) of isolating intervals for the real roots
of A in I.  Each I(j) is a left open right closed interval with binary
rational endpoints and I(1) lt I(2) lt  ... lt I(r).*)


PROCEDURE IPRIMS(A,AP,I: LIST): LIST; 
(*Integral polynomial real root isolation, modified Uspensky method, standard interval.  
A is a univariate integral polynomial without multiple roots.  
AP is the derivative of A.  I is a standard interval.
L is a list (I(1), ...,I(r)) of isolating intervals for the real roots
of A in I.  Each interval I(j) is a left open right closed interval
(a(j),b(j)) with binary rational endpoints and I(1) lt I(2) lt  ...
lt I(r).*)


PROCEDURE IPRIMU(A: LIST): LIST; 
(*Integral polynomial real root isolation, modified Uspensky method, unit interval.  
A is a squarefree univariate integral polynomial.  L is
a list (I(1), ...,I(r)) of isolating intervals for all the roots of A
in the left closed right open interval (0,1).  Each I(j) is a pair
(a(j),b(j)) of binary rational numbers, with 0 le a(1) le b(1) le
 ... le a(r) le b(r).  If a(j)=b(j) then (a(j),b(j))
represents the one-point interval (a(j),b(j)).  If a(j) lt b(j)
then the pair  (a(j),b(j)) represents the open interval
(a(j),b(j)).*)


PROCEDURE IPRIU(A: LIST): LIST; 
(*Integral polynomial real root isolation, Uspensky method.  A is a
non-zero squarefree univariate integral polynomial.  L is a list of
pairs  ((a(1),b(1)), ...,(a(k),b(k))) representing isolating
intervals forall of the real roots of A, with a(1) le b(1) le  ... le
a(k) le b(k).  If a(i) lt b(i) then the pair
(a(i),b(i)) represents the open interval (a(i),b(i)), while
if a(i)=b(i) then it represents the closed one-point interval
(a(i),b(i)).  The a(i) and b(i) are rational numbers except
that one may have a(1) equal to negative infinity, represented by
-1/0, that is the pair (-1,0), and one may have b(k) equal to
infinity, represented by 1/0.*)


PROCEDURE IPRIUP(A: LIST): LIST; 
(*Integral polynomial real root isolation, Uspensky method, positive roots.  
A is a non-zero squarefree univariate integral polynomial.  L
is a list of pairs ((a(1),b(1)), ...,(a(k),b(k))) representing iso-
lating intervals for the positive real roots of A, with a(1) le
b(1) le  ... le a(k) le b(k).  If a(i) lt e(i) then the pair
(a(i), b(i)) represents the open interval (a(i),b(i)) while if
a(i)=b(i) then (a(i),b(i)) represents the closed one-point
interval (a(i),b(i)).  The a(i) and b(i) are rational
numbers except thatone may have b(k) equal to infinity, represented
by 1/0, that is, the pair (1,0).*)


PROCEDURE IPRRLS(A1,A2,L1,L2: LIST;  VAR LS1,LS2: LIST); 
(*Integral polynomial real root list separation.  A1 and A2 are
univariate integral polynomials with no multiple real roots and with
no common real roots.  L1 and L2 are lists of isolating intervals for
some or all of the real roots of A1 and A2, respectively.  The
intervals in L1 and L2 have binary rational endpoints, and are either
left-open and right-closed or one-point intervals. Let
L1 eq (I sub 1,1 , ..., I sub (1,r sub 1) ),
L2 eq (I sub 2,1 , ..., I sub (2,r sub 2) ).
Then I sub 1,1  lt  I sub 1,2  lt   ...  lt  I sub (1,r sub 1)
and  I sub 2,1  lt  I sub 2,2  lt   ...  lt  I sub (2,r sub 2) .
L sub 1 sup *  eq (I sub 1,1 sup * , ..., I sub (1,r sub 1) sup * )
and L sub 2 sup *  eq (I sub 2,1 sup * , ..., I sub (2,r sub 2) sup * ),
where I sub i,j sup * is a binary rational subinterval of
I sub i,j containing the root of A sub i in I sub i,j.
Each I sub 1,j sup * is strongly disjoint from each
I sub 2,j sup *.*)


PROCEDURE IPRRS(A1,A2,I1,I2: LIST;  VAR IS1,IS2,SL: LIST); 
(*Integral polynomial real root separation.  A1 and A2 are squarefree
univariate integral polynomials of positive degrees.  I1 and I2
are intervals with binary rational number endpoints, each of
which is either left-open and right-closed, or a one-point interval.
I1 contains a unique root alpha sub 1 of A1, and I2 contains a
unique root alpha sub 2 ne alpha sub 1 of A2.  I sub 1 sup *
and I sub 2 sup * are binary rational subintervals of I1 and I2
containing alpha sub 1 and alpha sub 2 respectively, with
I sub 1 sup * and I sub 2 sup * strongly disjoint.  If I1 is
left-open and right-closed then so is I sub 1 sup *, and
similarly for I2 and I sub 2 sup *.  s eq -1
if I sub 1 sup *  lt  I sub 2 sup *, and s eq 1
if I sub 1 sup *  gt  I sub 2 sup *.*)


PROCEDURE IPSFSD(RL,A: LIST): LIST; 
(*Integral squarefree factorization, second derivative.  A is a
positive integral polynomial in r variables of positive degree L is a
list ((e(1),A(1)), ...,(e(k),A(k))) where primitive part of A
is equal to the sum of A(i)**e(i) for i=1, ...,k.  The a(i) are
pairwise relatively prime squarefree positive polynomials of
positive degrees, with deg(A(i))=1 or GCD(A(i),APP(i))=1 for all
i where APP(i) is the second derivative of A(i) and the e(i) are
positive beta-integers e(1) le e(2) le  ... le e(k).*)


PROCEDURE IPSRM(A,I: LIST): LIST; 
(*Integral polynomial strong real root isolation, modified Uspensky method. 
A is a univariate integral polynomial with multiple roots and
with no real roots in common with APP.  I is either the null list () or
a standard interval or an interval whose positive and non-negative
parts are standard.  L is a list (I(1), ...,I(r)) of isolating intervals
for  all the real roots of A if I=(), or for all the real roots of A in
I if I ne ().  The intervals I(j) contain no roots of AP or APP, are
left-open and right-closed, have binary rational endpoints, and
satisfy I(1) lt I(2) lt  ... lt I(r).*)


PROCEDURE IPSRMS(A,I: LIST): LIST; 
(*Integral polynomial strong real root isolation, modified Uspensky method, standard interval.  
A is a univariate integral polynomial with no multiple real roots 
and with no real roots in common with APP.  I is
a standard interval.  L is a list (I(1), ...,I(r)) of isolating
intervals for the roots of A in I.  The intervals I(j) contain no
roots of AP or APP, are left-open and right-closed, have binary rational
endpoints, are subintervals of I, and satisfy I(1) lt I(2) lt  ...
lt I(r).*)


PROCEDURE IPVCHT(A: LIST): LIST; 
(*Integral polynomial variations after circle to half-plane transformation. 
A is a non-zero univariate integral polynomial.  Let
n=deg(A), AP(x)=(x**n)*A(1/x), B(x)=AP(x+1).  k is the number of
sign variations in the coefficients of B.*)


PROCEDURE IUPRB(A: LIST): LIST; 
(*Integral univariate polynomial root bound.  A is an integral poly-
nomial of positive degree.  b is a binary rational number which is a
root bound for A.  If A(x) is equal to the sum of a(i)*x(i)**i for
i=0, ...,n, a(n) ne 0, then b is the smallest power of 2 such that
2*abs(a(n-k)/a(n))**(1/k) le b for 1 le k le n.  If
a(n-k)=0 for 1 le k le n then b=1.*)


PROCEDURE IUPRLP(A: LIST): LIST; 
(*Integral univariate polynomial, root of a linear polynomial.
A is an integral univariate polynomial of degree one.  r is
the unique rational number such that A(r)=0.*)


PROCEDURE IUPVAR(A: LIST): LIST; 
(*Integral univariate polynomial variations.  A is a non-zero uni-
variate integral polynomial.  n is the number of sign variations in
the coefficients of A.*)


PROCEDURE IUPVSI(A,I: LIST): LIST; 
(*Integral univariate polynomial, variations for standard interval.  
A is a non-zero integral univariate polynomial.  I is
a standard open interval.  Let T(z) be the transformation mapping the
right half-plane onto the circle having I as a diameter.
Let B(x)=A(T(x)).  Then v is the number of sign variations in the
coefficients of B.*)


PROCEDURE RIB(RL,SL: LIST): LIST; 
(*Rational interval bisection.  r and s are binary rational numbers,
r lt s.  t is a binary rational number with r lt t lt s, defined
as follows.  Let h=floor(log2(s-r)) and let c be the least integer
such that c*2**h gt r.  Then t=c*2**h if c*2**h lt s and
t=(2*c-1)*2**(h-1) otherwise.*)


PROCEDURE RILC(I,KL: LIST): LIST; 
(*Rational interval length comparison.  I is an interval (a,b) with
rational endpoints, a le b.  k is a gamma-integer.  t=1 if b-a le
2**k and t=0 otherwise.*)


PROCEDURE RINT(I: LIST): LIST; 
(*Rational interval normalizing transformation.  I is a list (r,s)
with rational endpoints and r lt s.  IS is the list (rs,ss)=
psi(r,s).*)


END SACROOT.
(* -EOF- *)
