(* ----------------------------------------------------------------------------
 * $Id: SACEXT8.md,v 1.3 1993/05/11 10:51:40 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACEXT8.md,v $
 * Revision 1.3  1993/05/11  10:51:40  kredel
 * Spelling errors corr.
 *
 * Revision 1.2  1992/02/12  17:34:55  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:15:37  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SACEXT8;

(* SAC Extensions 8 Definition Module. *)


(* Import lists and declarations. *) 

FROM MASSTOR IMPORT LIST; 

CONST rcsid = "$Id: SACEXT8.md,v 1.3 1993/05/11 10:51:40 kredel Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE AFCOMP(MB,I,AL,BL: LIST): LIST; 
(*Algebraic number field comparison.  MB is the integral minimal
polynomial of a real algebraic number alpha.  I is an acceptable
isolating interval for alpha.  a and b are elements of
Q( alpha ).  t eq SIGN(a-b).*)


PROCEDURE AFFINT(M: LIST): LIST; 
(*Algebraic number field element from integer.  M is an
integer.  A is M represented as an element of an algebraic
number field.*)


PROCEDURE AFFRN(R: LIST): LIST; 
(*Algebraic number field element from rational number.  R is a
rational number.  A is R represented as an element of an algebraic
number field.*)


PROCEDURE AFPAFP(RL,M,AL,B: LIST): LIST; 
(*Algebraic number field polynomial algebraic number field element product.  
M is the rational minimal polynomial of an algebraic number alpha.  
a is an element of Q( alpha ).  B is a polynomial
over Q( alpha ) in r variables, r ge 1.  C eq a cdot B.*)


PROCEDURE AFPAFQ(RL,M,A,BL: LIST): LIST; 
(*Algebraic number field polynomial algebraic number field element quotient.  
M is the rational minimal polynomial of an algebraic
number alpha.  A is a polynomial over Q( alpha ) in r variables,
r ge 1.  b is an element of Q( alpha ).  C eq A/b.*)


(* -- depends indirectly on AFPRII :-(
PROCEDURE AFPBRI(M,MB,I,L: LIST): LIST; 
(*Algebraic number field polynomial basis real root isolation.
M is the rational minimal polynomial of a real algebraic number
alpha.  MB is the integral minimal polynomial of alpha.
I is an acceptable isolating interval for alpha.  L is a
nonempty squarefree basis (A sub 1 ,... , A sub n ) of univariate
polynomials over Q( alpha ).  N is a list (i sub 1 ,b sub 1
,... , i sub m ,b sub m ), m ge 0, where i sub 1 lt i sub 2 lt  ...   lt
i sub m are strongly disjoint isolating intervals for all
the real roots of a eq prod from (j eq 1) to n (a sub j).
each i sub i has binary rational endpoints and is left open
and right closed.  b sub i is the unique a sub j which has
a root in i sub i.*)
*)


(* -- depends on AFPRII :-(
PROCEDURE AFPCLL(M,MB,I,A: LIST): LIST; 
(*Algebraic number field polynomial real root isolation, Collins-Loos
algorithm, list output version.  M is the rational minimal
polynomial of a real algebraic number alpha.
MB is the integral minimal polynomial of alpha.
I is an acceptable isolating interval for alpha.  A is a monic
univariate polynomial of degree n ge 0 over Q( alpha ).
If n eq 0 then L eq ().
If n gt 0, then L eq (L sub 0 ,... , L sub n-1 ),
where L sub i is a strong isolation list for the real roots
of der sup i (A).*)
*)

PROCEDURE AFPDIF(RL,A,B: LIST): LIST; 
(*Algebraic number field polynomial difference.  A and B are
polynomials in r variables, r ge 0, over Q( alpha ), for some
algebraic number alpha.  C=A-B.*)


PROCEDURE AFPDMV(RL,M,A: LIST): LIST; 
(*Algebraic number field polynomial derivative, main variable.
M is the rational minimal polynomial of an algebraic number alpha.
A is a polynomial over Q( alpha ) in r variables, r ge 1.  B is
the derivative of a with respect to its main variable.*)


PROCEDURE AFPEMV(RL,M,A,AL: LIST): LIST; 
(*Algebraic number field polynomial evaluation of main variable.
M is the rational minimal polynomial of an algebraic number alpha.
A is a polynomial over Q( alpha ) in r variables, r ge 1.  a is an
element of Q( alpha ).  B( x sub 1 ,... , x sub r-1 ) eq
A(x sub 1 ,... , x sub r-1 ,a).*)


PROCEDURE AFPEV(RL,M,A,IL,AL: LIST): LIST; 
(*Algebraic number field polynomial evaluation.  M is the rational
minimal polynomial of an algebraic number alpha.  A is a
polynomial in r ge 1 variables over Q( alpha ).  i satisfies
1 le i le r, and a is an element of Q( alpha ).
B(x sub 1 ,... , x sub i-1 , x sub i+1 ,... , x sub r) eq
A(x sub 1 ,... , x sub i-1 , a , x sub i+1 ,... , x sub r ).*)


PROCEDURE AFPFIP(RL,A: LIST): LIST; 
(*Algebraic number field polynomial from integral polynomial.  A is
an integral polynomial in r variables, r ge 1.  B is a represented as
a polynomial over an algebraic number field.*)


PROCEDURE AFPFRP(RL,A: LIST): LIST; 
(*Algebraic number field polynomial from rational polynomial.  A is
a rational polynomial in r variables, r ge 1.  B is a represented as
a polynomial over an algebraic number field.*)


PROCEDURE AFPINT(RL,M,A,BL: LIST): LIST; 
(*Algebraic number field polynomial integration.  M is the rational
minimal polynomial of an algebraic number alpha. A is a nonzero
polynomial over Q( alpha ) in r variables, r ge 1.  b is a polynomial
over Q( alpha ) in r-1 variables.  B eq B(x sub 1 ,... , x sub r )
is the integral of a with respect to its main variable, such that
B(x sub 1 ,... , x sub r-1 ,0) eq b.*)


PROCEDURE AFPME(RL,M,A,BL: LIST): LIST; 
(*Algebraic number field, polynomial multiple evaluation.
M is the rational minimal polynomial of an algebraic number
alpha.  A eq A(x sub 1 ,... , x sub r ) is a polynomial in
r ge 1 variables over Q( alpha ).  b eq (b sub 1 ,... , b sub k )
is a list of k elements of Q( alpha ) for some k, 1 le k le r.
B eq A(b sub 1 ,... , b sub k ,x sub k+1 ,... , x sub r ),
an element of Q( alpha )(x sub k+1 ,... , x sub r ).*)


PROCEDURE AFPMON(RL,M,A: LIST): LIST; 
(*Algebraic number field polynomial monic.  A is a polynomial in
r variables, r ge 1, over Q( alpha ) for some algebraic number
alpha.  M is the rational minimal polynomial of alpha.
If A is nonzero then AP is the monic polynomial over Q( alpha )
similar to A.  If A eq 0 then AP eq 0.*)


PROCEDURE AFPMPR(M,MB,I,B,J,L: LIST;  VAR JS,JL: LIST); 
(*Algebraic number field polynomial minimal polynomial of a real root.
M is the rational minimal polynomial of a real algebraic number
alpha.  MB is the integral minimal polynomial of alpha.  I
is an acceptable isolating interval for alpha.  J is an interval
with binary rational number endpoints which is either left-open and
right-closed, or a one-point interval.  B is a univariate polynomial
over Q( alpha ) having a unique root beta of odd multiplicity
in j.  L is a nonempty list of positive irreducible univariate
integral polynomials exactly one of which has beta as a root.
j is the index in L of the unique element n of L having beta
as a root, and js is a subinterval of j with binary rational
endpoints which is an isolating interval for beta as a root of n.
js is either left-open and right-closed or a one-point interval.*)


PROCEDURE AFPNEG(RL,A: LIST): LIST; 
(*Algebraic number field polynomial negative.  A is a polynomial in
r variables, r ge 0, over Q( alpha ) for some algebraic number
alpha.  B=-A.*)


PROCEDURE AFPNIP(MB,A: LIST): LIST; 
(*Algebraic number field polynomial normalize to integral polynomial.
MB is the integral minimal polynomial of an algebraic number alpha.
A is a univariate polynomial over Q( alpha ) of positive degree.
l is a list (l sub 1 ,... , l sub n ), n ge 1, of the positive
irreducible factors of positive degree of a univariate integral
polynomial which has among its roots the roots of A.*)


PROCEDURE AFPPR(RL,M,A,B: LIST): LIST; 
(*Algebraic number field polynomial product.  A and B are polynomials
in r variables, r ge 0, over Q( alpha ) for some algebraic number
alpha.  M is the rational minimal polynomial of alpha.  C=A*B.*)


PROCEDURE AFPQR(RL,M,A,B: LIST;  VAR Q,R: LIST); 
(*Algebraic number field polynomial quotient and remainder.  A and B,
B ne 0, are polynomials in r variables, r ge 1, over Q( alpha ), for
some algebraic number alpha.  M is the rational minimal polynomial
of alpha.  Q and R are the unique algebraic number field polynomials
such that either B divides A, Q eq B/A, and r eq 0 or else B does not
divide A and A eq BQ+R with degree(R) minimal.*)


(* -- depends on AFPRII :-(
PROCEDURE AFPRCL(M,MB,I,A: LIST): LIST; 
(*Algebraic number field polynomial real root isolation, Collins-Loos algorithm.  
M is the rational minimal polynomial of a real algebraic
number alpha.  MB is the integral minimal polynomial of alpha.
I is an acceptable isolating interval for alpha.  A is a monic
univariate polynomial of degree n ge 0 over Q( alpha ).  L is a
strong isolation list for the real roots of a.*)
*)


(* -- zuviele goto's :-(
PROCEDURE AFPRII(M,MB,J,A,AP,DL,LP: LIST): LIST; 
(*Algebraic number field polynomial real root isolation induction.
M is the rational minimal polynomial of a real algebraic number
alpha.  MB is the integral minimal polynomial of alpha.  J is
an acceptable isolating interval for alpha.  A is a positive
univariate polynomial over Q( alpha ) of positive degree.  AP is
the derivative of A.  d is a binary rational real root bound for A.
LP is a strong isolation list for AP.  L is a strong isolation list
for A.*)
*)

PROCEDURE AFPRLS(M,MB,I,A1,A2,L1,L2: LIST;  VAR LS1,LS2: LIST); 
(*Algebraic number field polynomial real root list separation.
M is the rational minimal polynomial of a real algebraic number
alpha.  MB is the integral minimal polynomial of alpha.
I is an acceptable isolating interval for alpha.  A1 and A2
are univariate polynomials over Q( alpha ) with no common roots
and real roots of only odd multiplicity.  L1 and L2 are strong
isolation lists for the real roots of A1 and A2 respectively.  Let
L1 eq (i sub 1,1 ,m sub 1,1 ,... , i sub (1,r sub 1),m sub (1,r sub 1)),
L2 eq (i sub 2,1 ,m sub 2,1 ,... , i sub (2,r sub 2),m sub (2,r sub 2)).
Then i sub 1,1  lt  i sub 1,2  lt  ...   lt  i sub (1,r sub 1)
and  i sub 2,1  lt  i sub 2,2  lt  ...   lt  i sub (2,r sub 2) .
l sub 1 sup *  eq (i sub 1,1 sup * ,m sub 1,1 ,... ,
i sub (1,r sub 1) sup * ,m sub (1,r sub 1))
and l sub 2 sup *  eq (i sub 2,1 sup * ,m sub 2,1 ,... ,
i sub (2,r sub 2) sup * ,m sub (2,r sub 2)),
where i sub i,j sup * is a binary rational subinterval of
i sub i,j containing the root of a sub i in i sub i,j.
each i sub 1,j sup * is strongly disjoint from each
i sub 2,j sup *.*)


PROCEDURE AFPRRI(M,MB,I,A,B,J,SL1,TL1: LIST): LIST; 
(*Algebraic number field polynomial relative real root isolation.
M is the rational minimal polynomial of a real algebraic number
alpha.  MB is the integral minimal polynomial of alpha.  I is an
acceptable isolating interval for alpha.  A and B are univariate
polynomials over Q( alpha ).  J is a left open, right closed
interval (a sub 1 ,a sub 2 ) where al sub 1 and al sub 2 are
binary rational numbers with al sub 1 lt al sub 2.  A and B have
unique roots, alpha and beta respectively, in J, each of odd
multiplicity and with alpha ne beta.  sl sub 1 eq
sign(a(al sub 1 +)) and tl sub 1 eq sign(b(al sub 1 +)).
js eq (al sub 1 sup * ,al sub 2 sup * ) is al left-open, right-closed
subinterval of j with al sub 1 sup * and al sub 2 sup *
binary rational numbers and al sub 1 sup * lt al sub 2 sup *,
such that js contains alpha but not beta.*)


PROCEDURE AFPRRS(M,MB,I,A1,A2,I1,I2: LIST; VAR IS1,IS2,SL: LIST); 
(*Algebraic number field polynomial real root separation.  M is
the rational minimal polynomial of a real algebraic number alpha.
MB is the integral minimal polynomial of alpha.  I is an
acceptable isolating interval for alpha.  A1 and A2 are
univariate integral polynomials of positive degrees over Q( alpha ).
I1 and I2 are intervals with binary rational number endpoints, each of
which is either left-open and right-closed, or a one-point interval.
I1 contains a unique root alpha sub 1 of A1 of odd multiplicity,
and I2 contains a unique root alpha sub 2 ne alpha sub 1
of A2 of odd multiplicity.  I sub 1 sup * and
I sub 2 sup * are binary rational subintervals of I1 and I2
containing alpha sub 1 and alpha sub 2 respectively, with
I sub 1 sup * and I sub 2 sup * strongly disjoint.  If I1 is
left-open and right-closed then so is I sub 1 sup *, and
similarly for I2 and I sub 2 sup *.  s eq -1
if I sub 1 sup *  lt  I sub 2 sup *, and s eq 1
if I sub 1 sup *  gt  I sub 2 sup *.*)


PROCEDURE AFPSUM(RL,A,B: LIST): LIST; 
(*Algebraic number field polynomial sum. A and B are polynomials over
Q( alpha ) in r variables, r ge 1, for some algebraic number
alpha.  C=A+B.*)


PROCEDURE AFSUPB(M,A: LIST): LIST; 
(*Algebraic number field squarefree univariate polynomial squarefree
basis.  M is the rational minimal polynomial of an algebraic number
alpha.  A eq (a sub 1 ,... , a sub n ), n ge 0, is a list of monic
squarefree univariate polynomials over Q( alpha ), each of which
is of positive degree.  B is a coarsest squarefree basis for A.*)


PROCEDURE AFUPBA(M,A,B: LIST): LIST; 
(*Algebraic number field univariate polynomial squarefree basis
augmentation.  M is the rational minimal polynomial of an algebraic
number alpha.  A is a monic squarefree univariate polynomial over
Q( alpha ), of positive degree.  B eq (b sub 1 ,... , b sub s ),
s ge 0, is a squarefree basis of univariate polynomials over
Q( alpha ).  BS is a coarsest squarefree basis for
(a,b sub 1 ,... , b sub s ).*)


PROCEDURE AFUPCB(M,A: LIST): LIST; 
(*Algebraic number field univariate polynomial coarsest squarefree basis. 
M is the rational minimal polynomial of an algebraic number alpha. 
A eq (a sub 1 ,... , a sub n ), n ge 0, is a
list of monic univariate polynomials over Q( alpha ), each of
which is of positive degree.  B is a coarsest squarefree basis for A.*)


PROCEDURE AFUPGC(M,A,B: LIST;  VAR C,AB,BB: LIST); 
(*Algebraic number field univariate polynomial greatest common divisor
and cofactors.  A and B are univariate polynomials over
Q( alpha ) for some algebraic number alpha.  M is the rational
minimal polynomial of alpha.  C eq gcd(A,B), a monic polynomial.
If C ne 0, then AB eq A/C and BB eq B/C, otherwise AB eq 0 and BB eq 0.
*)


PROCEDURE AFUPGS(M,A: LIST): LIST; 
(*Algebraic number field polynomial greatest squarefree divisor.
M is the rational minimal polynomial of an algebraic number alpha.
A is a univariate polynomial over Q( alpha ).  If A eq 0 then
B eq 0.  Otherwise B is the monic associate of the greatest
squarefree divisor of A.*)


PROCEDURE AFUPRB(MB,I,A: LIST): LIST; 
(*Algebraic number field univariate polynomial root bound.  MB is
the integral minimal polynomial of a real algebraic number alpha.
I is an acceptable isolating interval for alpha.  A is a monic
univariate polynomial over Q( alpha ) of positive degree.
B is a binary rational number which is a root bound for A.
If A(x) eq x sup n + sum from (i eq 0) to n-1 (a sub i x sup i),
then B is the smallest power of 2 such that 2 cdot (abs(a sub n-k ))
sup 1/k le B for 1 le k le n.  If a sub n-k eq 0 for 1 le k le n
then B eq 1.*)


PROCEDURE AFUPRL(M,A: LIST): LIST; 
(*Algebraic number field polynomial, root of a linear polynomial.  A
is an element of Q( alpha )(x) of degree one, for some algebraic
number alpha.  M is the rational minimal polynomial of alpha.
a is the unique element of Q( alpha ) such that A(a) eq 0.*)


PROCEDURE AFUPSF(M,A: LIST): LIST; 
(*Algebraic number field univariate polynomial squarefree factorization.
M is the rational minimal polynomial of an algebraic number alpha.
A is a monic univariate polynomial over Q( alpha ) of positive degree.
L is the list ((e sub 1 ,a sub 1 ) ,... , (e sub k ,a sub k )),
where A eq prod from (i eq 1) to k (a sub i sup (e sub i)) is the
squarefree factorization of A, with 1 le e sub 1 lt e sub 2
le ...   lt e sub k and each a sub i a monic squarefree polynomial
of positive degree.*)


PROCEDURE AFUPSR(M,MB,I,A,CL: LIST): LIST; 
(*Algebraic number field univariate polynomial, sign at a rational
point.  M is the rational minimal polynomial of a real algebraic
number alpha.  MB is the integral minimal polynomial of alpha.
I is an acceptable isolating interval for alpha.  A is a
univariate polynomial over Q( alpha ).  c is a rational number.
s eq sign(A(c)).*)


PROCEDURE ANDWR(M,I,NL: LIST); 
(*Algebraic number decimal write.  M is the integral minimal polynomial
of a real algebraic number alpha.  I is an acceptable isolating
interval for alpha.  n is a nonnegative integer.  alpha is
approximated by a rational number r with inaccuracy of approximation
at most 10 sup -(n+1).  Then r is approximated by a decimal
fraction d with n decimal digits following the decimal point and
d is written in the output stream.  The inaccuracy of the approximation
of d to r is at most (1/2) 10 sup -n.  If abs(d) gt abs(r) then
the last digit is followed by $=-. If abs(d) lt abs(r) then by $=+.*)


PROCEDURE ANFAF(M,I,AL: LIST;  VAR N,J: LIST); 
(*Algebraic number from algebraic number field element.  M is the
integral minimal polynomial of a real algebraic number alpha.
I is an acceptable isolating interval for alpha.  a is an
element of Q( alpha ).  N is the integral minimal polynomial of a,
and J is an acceptable isolating interval for a.*)


PROCEDURE ANIIPE(MB,I,NB,J,TL,L: LIST;  VAR S,KL,K: LIST); 
(*Algebraic number isolating interval for a primitive element.
MB is the integral minimal polynomial of a real algebraic number
alpha.  I is a binary rational isolating interval for alpha
which is either left-open and right-closed or a one-point interval.
NB is the integral minimal polynomial of a real algebraic number
beta.  J is a binary rational isolating interval for beta which
is either left-open and right-closed or a one-point interval.
t is an integer such that Q( alpha +t beta ) eq
Q( alpha , beta ).  If degree(MB) eq 1 and degree(NB) eq 1,
then L is a list containing a primitive positive integral polynomial
p of degree 1, s eq p, k eq 1, and k is a binary rational isolating
interval for the real root of p which is either left-open and
right-closed or a one-point interval.  If degree(mb) eq 1,
degree(NB) gt 1, then l eq (NB), S eq NB, k eq 1, and k eq j.
If degree(MB) gt 1, degree(NB) eq 1, then L eq (MB), S eq MB, k eq 1,
and k eq i.  If degree(MB) gt 1, degree(NB) gt 1, then L is a nonempty
list of positive irreducible univariate integral polynomials exactly
one of which has alpha +t beta as a root.  S is the element of L
having alpha +t beta as a root, k is the index of S in L, and
k is a left-open, right-closed binary rational isolating interval
for alpha +t beta as a root of S.*)


PROCEDURE ANPEDE(MB,NB: LIST;  VAR TL,S,T: LIST); 
(*Algebraic number primitive element for a double extension.
MB eq MB(x) is the integral minimal polynomial of a real algebraic
number alpha.  NB eq NB(x) is the integral minimal polynomial
of a real algebraic number beta.  t is an integer such that
Q( alpha +t beta ) eq Q( alpha , beta ).  If degree(MB) eq 1
and degree(NB) eq 1, then S eq (x), a list of length of length 1
containing the polynomial x.  If degree(MB) eq 1 and degree(NB) gt 1,
then S eq (NB).  If degree(MB) gt 1 and degree(NB) eq 1, then S eq (MB).
If degree(MB) gt 1 and degree(NB1) gt 1, then S is a list of the
integral minimal polynomials of all algebraic numbers of the
form alpha sub i + t beta sub j, where alpha sub i is some
conjugate of alpha and beta sub j is some conjugate of
beta.  Where n ge 1 is the length of S, t is a list
(m sub 1 sup * ,n sub 1 sup * ,... , m sub n sup * , n sub n sup * ).
For 1 le k le n, where gamma sub k is a root of s sub k,
m sub k sup * is the representation of alpha as an element
of Q( gamma sub k ) and n sub k sup * is the representation
of beta as an element of Q( gamma sub k ).*)


PROCEDURE ANREPE(M,MB,A,B: LIST): LIST; 
(*Algebraic number represent element of a primitive extension.
M is the rational minimal polynomial of an algebraic number
gamma.  MB is the integral minimal polynomial of gamma.
A and B are elements of Q( gamma ) (y) which can be and are
represented as bivariate integral polynomials, i.e. as elements
of Z(x,y).  A eq AP(x-ty) for a minimal polynomial AP of an
algebraic number alpha, and B eq B(y) is the minimal polynomial
of an algebraic number beta.  gamma is a primitive element
for alpha and beta.  B is a univariate rational polynomial
which is the representation for beta as an element of Q( gamma ).*)


PROCEDURE APDWR(M,I,BL,NL: LIST); 
(*Algebraic point, decimal write.  M,I, and b constitute the
representation of an algebraic point in r-dimensional euclidean
space for some r ge 1.  n is a nonnegative integer.  For each
coordinate b sub i of b, b sub i is represented by a rational
number r sub i with inaccuracy of approximation at most
10 sup -(n+1).  Then r sub i is approximated by a decimal
fraction d sub i with n decimal digits following the decimal
point, and d sub i is written in the output stream.  The
inaccuracy of the approximation of d sub i to r sub i is
at most (1/2) 10 sup -n.*)


PROCEDURE IPAFME(RL,M,A,BL: LIST): LIST; 
(*Integral polynomial, algebraic number field multiple evaluation.
A is an integral polynomial in r
variables, r ge 1.  M is the rational minimal polynomial of an
algebraic number alpha.   b eq (b sub 1 ,... , b sub k ) is
a list of k elements of Q( alpha ), for some k, 1 le k le r.
b eq a(b sub 1 ,... , b sub k , x sub k+1 ,... , x sub r ),
an element of Q( alpha )(x sub k+1 ,... , x sub r ).*)


PROCEDURE IUPMRN(R: LIST): LIST; 
(*Integral univariate polynomial minimal polynomial of a rational number. 
R is a rational number.  M is the integral minimal polynomial of R.*)


PROCEDURE RPAFME(RL,M,A,BL: LIST): LIST; 
(*Rational polynomial, algebraic number field multiple evaluation.
A is a rational polynomial in r
variables, r ge 1.  M is the rational minimal polynomial of an
algebraic number alpha.   b eq (b sub 1 ,... , b sub k ) is
a list of k elements of Q( alpha ), for some k, 1 le k le r.
B eq A(b sub 1 ,... , b sub k , x sub k+1 ,... , x sub r ),
an element of Q( alpha )(x sub k+1 ,... , x sub r ).*)


END SACEXT8.


(* -EOF- *)
