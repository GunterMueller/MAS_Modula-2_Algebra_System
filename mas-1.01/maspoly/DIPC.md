(* ----------------------------------------------------------------------------
 * $Id: DIPC.md,v 1.7 1995/11/04 22:14:54 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPC.md,v $
 * Revision 1.7  1995/11/04 22:14:54  pesch
 * New procedures EVOWRITE and EvordWrite.
 *
 * Revision 1.6  1994/09/01  13:30:57  pfeil
 * minor changes
 *
 * Revision 1.5  1994/06/09  15:13:25  pfeil
 * Added AD2DIP, DIP2AD.
 *
 * Revision 1.4  1994/03/30  13:02:30  dolzmann
 * New procedure DILPERM.
 *
 * Revision 1.3  1993/03/16  09:32:22  kredel
 * Removed obsolete LPERM function.
 *
 * Revision 1.2  1992/02/12  17:33:45  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:13:36  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DIPC;

(* DIP Common Polynomial System Definition Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST;


CONST LEX = 1;
      INVLEX = 2;
      GRLEX = 3;
      IGRLEX = 4;      
      REVLEX  = 5;
      REVILEX = 6;
      REVTDEG = 7;
      REVITDG = 8; 

VAR  EVORD: LIST; 
     VALIS: LIST;    


CONST rcsid = "$Id: DIPC.md,v 1.7 1995/11/04 22:14:54 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1995 Universitaet Passau";



PROCEDURE BACKUB();
(*Backspace until blank. *)


PROCEDURE CLIN(): LIST;
(*Character list in. If a character list is next in the input
stream then it is read, else L is empty. *)


PROCEDURE DILBSO(A: LIST);
(*Distributive polynomial list bubble sort. A is a list of
lists of base coefficients and exponent vectors.
Each element of A is sorted with respect to the termordering
defined in EVORD by the bubble-sort method,
two monomials with equal exponents will lead to an error.
The lists in A but not there location, are modified.*)


PROCEDURE DILFPL(RL,A: LIST): LIST;
(*Distributive polynomial list from polynom list. A is a list
of polynomials in r variables, r ge 0. Every polynomial in A
is converted to distributive representation and returned in B. *)


PROCEDURE DILPERM(dil,perm: LIST):LIST;
(* distributive polynomial list permutation of variables.
The variable dil is a list of distributive polynomials in r variables, 
perm is a permutation. In each distributive polynomial of the list dil 
the variables are permuted with respect to perm. *)


PROCEDURE DIPADM(A: LIST;    VAR EL,FL,BL,B: LIST);
(*Distributive polynomial advance main variable. A is a
distributive polynomial in one or more variables. e is the
degree of A, b is the leading coefficient of A,
B is the reductum of A, f is the degree of B.*)


PROCEDURE DIPADS(A,IL,SL: LIST;    VAR EL,FL,BL,B: LIST);
(*Distributive polynomial advance and substitute. A is a
distributive polynomial, i is the specified variable,
1 le i le r=DIPNOV(A), s is the new exponent of b
in the i-th variable. e is the exponent of the leading
monomial of A in the i-th variable, let bs be part of the
coefficient of xi**e then b = bs * xi**s,
B = A - bs*xi**e, f is the exponent of the leading monomial
of B in the i-th variable.*)


PROCEDURE DIPADV(A,IL: LIST;    VAR EL,FL,BL,B: LIST);
(*Distributive polynomial advance. A is a distributive polynomial,
i is the specified variable, 1 le i le r=DIPNOV(A). e is
the exponent of the leading monomial of A in the i-th variable,
b is part of the coefficient of xi**e of A,
B = A - b*xi**e, f is the exponent of the leading monomial
of B in the i-th variable.*)


PROCEDURE DIPBSO(A: LIST);
(*Distributive polynomial bubble sort. A is a list of
base coefficients and exponent vectors, A is sorted
with respect to the termordering defined in EVORD
by the bubble-sort method, two monomials with equal
exponents will lead to an error. The
list A but not its location, is modified.*)


PROCEDURE DIPCMP(EL,A: LIST): LIST;
(*Distributive polynomial composition. A is a distributive
polynomial in r variables. e is an exponent. Let t=r+1, then
B(x1, ...,xr,xt)=A(x1, ...,xr)*xt**e.*)


PROCEDURE DIPDEG(A: LIST): LIST;
(*Distributive polynomial degree. A is a distributive polynomial.
n is the degree of A in its main variable.*)


PROCEDURE DIPDPV(A,SL,QL: LIST): LIST;
(*Distributive polynomial division by power of variable. A is
a distributive polynomial in r variables. s is the desired
variable to be divided, s le r. q is a beta-integer.
Q = A / ( xs**q). *)


PROCEDURE DIPERM(A,P: LIST): LIST;
(*Distributive polynomial permutation of variables. A is a
distributive polynomial, in r variables, r ge 0. P is a
list (p sub 1, ...,p sub r) whose elements are the
beta-digits 1 through r.  B(x sub (p sub 1), ...,x sub (p sub r))
=A(x sub 1, ...,x sub r). *)


PROCEDURE DIPEVL(A: LIST): LIST;
(*Distributive polynomial exponent vector leading monomial.
A is a distributive polynomial. u is the exponent vector of
the leading monomial of A. *)


PROCEDURE DIPEVP(A,EL: LIST): LIST;
(*Distributive polynomial exponent vector product. A is a
distributive polynomial, e is an exponent vector  C=A*(x**e). *)


PROCEDURE DIPEXC(A,ILP,JLP: LIST): LIST;
(*Distributive polynomial exchange variables. A is a
distributive polynomial, the variables ip and jp are exchanged,
B=(x1, ...,xip, ...,xjp, ...,xr)=A(x1, ...,xjp, ...,xip, ...,xr), 
0 le ip, jp le DIPNOV(A).*)


PROCEDURE DIPFMO(AL,EL: LIST): LIST;
(*Distributive polynomial from monomial. A is a non zero
distributive polynomial with a as its leading base coefficient
and e as is its exponent vector of the leading monomial. *)


PROCEDURE DIPFP(RL,A: LIST): LIST;
(*Distributive polynomial from polynomial. A is a polynomial
in r variables, r ge 0. B is the result of converting A from
recursive to distributive representation. Modified version
original version by G. E. Collins. *)


PROCEDURE DIPINV(A,JL,KL: LIST): LIST;
(*Distributive polynomial introduction of new variables.
A is a distributive polynomial in r variables. k ge 0,
0 le j le r. B(x1, ...,xj,y1, ...,yk,xj+1, ...,xr)=A(x1, ...,xr).*)


PROCEDURE DIPLBC(A: LIST): LIST;
(*Distributive polynomial leading base coefficient. A is a
distributive polynomial. a is the leading base coefficient of A.*)


PROCEDURE DIPLDC(A: LIST): LIST;
(*Distributive polynomial leading coefficient. A is a distributive
polynomial in one or more variables. a is the leading
coefficient of A.*)


PROCEDURE DIPLM(L1,L2: LIST): LIST;
(*Distributive polynomial list merge.  L1 and L2 are lists
of non zero distributive polynomials in non decreasing
order.  L is the merge of L1 and L2. L1 and L2 are
modified to produce L. *)


PROCEDURE DIPLPM(A: LIST): LIST;
(*Distributive polynomial list pair-merge sort. A is
a list of non zero distributive polynomials. B is the
result of sorting A into non-decreasing order. Pairs of
polynomials are merged. The list A is modified to produce B. *)


PROCEDURE DIPLRS(A: LIST);
(*Distributive polynomial list re-sort. A is a list of
distributive  polynomials in r variables, r ge 0.
The polynomials in A are re-sorted. *)


PROCEDURE DIPMAD(A: LIST;    VAR AL,EL,AP: LIST);
(*Distributive polynomial monomial advance. A is a non zero
distributive polynomial. a is its leading base coefficient,
e is the exponent vector of the leading monomial of A.
AP is the distributive polynomial a without its leading
monomial, or the empty list. *)


PROCEDURE DIPMCP(AL,EL,A: LIST): LIST;
(*Distributive polynomial monomial composition. A is an emty
list or a non zero distributive polynomial. AP is a non zero
distributive polynomial with a as its leading base coefficient,
e as is its exponent vector of the leading monomial and A as
its monomial reductum. *)


PROCEDURE DIPMPM(A,PL: LIST): LIST;
(*Distributive polynomial multiplication by power of main variable.
A is a distributive polynomial in r variables. p is a beta-
integer.  B = A * ( xr**p ). *)


PROCEDURE DIPMPV(A,SL,PL: LIST): LIST;
(*Distributive polynomial multiplication by power of variable.
A is a distributive polynomial in r variables. s is the specified
variable to be multiplicated, 1 le s le r. p is a beta-integer.
B = A * ( xs**p ). *)


PROCEDURE DIPMRD(A: LIST): LIST;
(*Distributive polynomial monomial reductum. A is a distributive
polynomial. B is the distributive polynomial a without the
leading monomial of A. *)


PROCEDURE DIPMST(A,AL,EL: LIST);
(*Distributive polynomial monomial set. A is a non zero
distributive polynomial. Its leading base coefficient is set
to a and its exponent vector of the leading monomial is
set to e. *)


PROCEDURE DIPNBC(A: LIST): LIST;
(*Distributive polynomial number of base coefficients. A is a
distributive polynomial. l is the number of base coefficients.*)


PROCEDURE DIPNOV(A: LIST): LIST;
(*Distributive polynomial number of variables. A is a distributive
polynomial. r is the number of variables, r ge 0. If A=0 then
r is set to zero. *)


PROCEDURE DIPRED(A: LIST): LIST;
(*Distributive polynomial reductum. A is a distributive polynomial,
in one or more variables. B is the reductum of A.*)


PROCEDURE DIPTBC(A: LIST): LIST;
(*Distributive polynomial trailing base coefficient. A is a
distributive polynomial. a is the trailing base coefficient.*)


PROCEDURE DIPTCF(A: LIST): LIST;
(*Distributive polynomial trailing coefficient. A is a
distributive polynomial. a is the trailing coefficient of A.*)


PROCEDURE DIPTCS(A,IL: LIST): LIST;
(*Distributive polynomial trailing coefficient specified variable.
A is a distributive polynomial in r variables. a is the
trailing coefficient of A with respect to the i-th variable,
1 le i le r. *)


PROCEDURE DIPTDG(A: LIST): LIST;
(*Distributive polynomial total degree. A is a distributive
polynomial. n is the total degree of A.*)


PROCEDURE DIPUNT(A: LIST): LIST;
(*Distributive polynomial univariate test. A is a distributive
polynomial. If a is univariate then t=1, otherwise t=0.*)


PROCEDURE DIPUV(A: LIST): LIST;
(*Distributive polynomial univariate variable output.
A is a distributive polynomial. If A is univariate then t=i, 
otherwise t=0. were i is the index of the variable in which A 
is univariate. If A is constant then t= -1. *)


PROCEDURE EPREAD(): LIST; 
(*Exponent read.  If ** is found in the input stream
then e=AREAD, else e=1. *)


PROCEDURE EVCADD(U,IL,EL: LIST;    VAR V,FL: LIST);
(*Exponent vector component add. U=(u1, ...,ur) is an
exponent vector of length r, e is added to the i-th component,
1 le i le r, f=ui+e, V=(u1, ...,ui+e, ...,ur). *)


PROCEDURE EVCOMP(U,V: LIST): LIST;
(*Exponent vector compare. U=(u1, ...,ur), V=(v1, ...vr)
are exponent vectors. r is the length of U and V.
t=0 if U eq V. t=1 if U gt V. t=-1 if U lt V. eq, gt, lt
with respect to the ordering of the exponent vectors specified
in the global variable EVORD. Lexicographical, inverse
lexicographical, graded lexicograhpical, inverse graded
lexicographical orderings are possible. *)


PROCEDURE EVCSUB(U,IL,EL: LIST;    VAR V,FL: LIST);
(*Exponent vector component subtract. U=(u1, ...,ur) is an
exponent vector of length r, e is subtracted from the i-th
component, 1 le i le r, V=(u1, ...,ui-e, ...,ur), f=ui. *)


PROCEDURE EVDEL(U,IL: LIST;    VAR V,EL: LIST);
(*Exponent vector delete. U=(u1, ...,ur) is an exponent vector
of length r. i is the component to be deleted, 1 le i le r.
V=(u1, ...,ui-1,ui+1, ...,ur),  e=ui.*)


PROCEDURE EVDER(U,IL,EL: LIST;    VAR V,FL: LIST);
(*Exponent vector derivation. U=(u1, ...,ur) is an exponent
vector of length r, from the i-th component e-times one is
subtracted and f is multiplied with the result.
V=(u1, ...,ui-e, ...,ur). If f=0 then V is undefined. *)


PROCEDURE EVDFSI(U,V: LIST;    VAR W,SL: LIST);
(*Exponent vector difference and sign. U=(u1, ...,ur),
V=(v1, ...,vr) are exponent vectors of length r.
W=(w1, ...,wr) is the componentwise difference of U and V.
s is the EVSIGN of W. If s=-1 then W is undefined.*)


PROCEDURE EVDIF(U,V: LIST): LIST;
(*Exponent vector difference. U=(u1, ...,ur), V=(v1, ...,vr)
are exponent vectors of length r. W=(w1, ...,wr) is the
componentwise difference of U and V.*)


PROCEDURE EVDOV(U: LIST): LIST;
(*Exponent vector dependency on variables. U is an exponent
vector. V is the list (j1, ...,jn) where each
j is the index of a variable with non zero exponent in U. *)


PROCEDURE EVEXC(U,IL,JL: LIST): LIST;
(*Exponent vector exchange. U=(u1, ...,ui, ...,uj, ...,ur)
is an exponent vector of length r. The components ui and uj are 
exchanged, 1 le i lt j le r. V=(u1, ...,uj, ...,ui, ...,ur).*)


PROCEDURE EVIGLC(U,V: LIST): LIST;
(*Exponent vector inverse graded lexicographical compare.
U=(u1, ...,ur), V=(v1, ...vr) are exponent vectors.
t=0 if U eq V. t=1 if U gt V. t=-1 if U lt V. eq, gt, lt
with respect to the inverse graded lexicographical ordering
of the exponent vectors. r is the length of U and V.*)


PROCEDURE EVILCI(U,V: LIST): LIST;
(*Exponent vector inverse lexicographical compare inverse exponent vector. 
U=(u1, ...,ur), V=(v1, ...vr) are exponent vectors.
t=0 if U eq V. t=1 if U gt V. t=-1 if U lt V. eq, gt,
lt with respect to the inverse lexicographical ordering
of the exponent vectors. r is the length of U and V.*)


PROCEDURE EVILCP(U,V: LIST): LIST;
(*Exponent vector inverse lexicographical compare.
U=(u1, ...,ur), V=(v1, ...vr) are exponent vectors.
t=0 if U eq V. t=1 if U gt V. t=-1 if U lt V. eq, gt,
lt with respect to the inverse lexicographical ordering
of the exponent vectors. r is the length of U and V.*)


PROCEDURE EVITDC(U,V: LIST): LIST;
(*Exponent vector inverse total degree compare.
U=(u1, ...,ur), V=(v1, ...vr) are exponent vectors.
t=0 if U eq V. t=1 if U gt V. t=-1 if U lt V. eq, gt, lt
with respect to buchbergers total degree ordering
of the exponent vectors. r is the length of U and V.*)


PROCEDURE EVLFCP(L,U,V: LIST): LIST;
(*Exponent vector linear form compare. U=(u1, ...,ur),
V=(v1, ...,vr) are exponent vectors of length r.
L is an univariate integral polynomial vector.
t=0 if U eq V. t=1 if U gt V. t=-1 if U lt V. eq, gt, lt
with respect to the ordering of the exponent vectors 
determined by the linear form.*)


PROCEDURE EVLCM(U,V: LIST): LIST;
(*Exponent vector least common multiple. U=(u1, ...,ur),
V=(v1, ...,vr) are exponent vectors of length r.
W=(w1, ...,wr) is the least common multiple of U and V. *)


PROCEDURE EVMT(U,V: LIST): LIST;
(*Exponent vector multiple test. U=(u1, ...,ur),
V=(v1, ...,vr) are exponent vectors of length r.
t=1 if U is a multiple of V, t=0 else. *)


PROCEDURE EVNNZE(U: LIST): LIST;
(*Exponent vector number of non zero exponents. U is an
exponent vector. n is the number of non zero exponents of U. *)

PROCEDURE EVOWRITE(EVO: LIST);
(*Exponent vector order write.
EVO is an exponent vector order. A description of EVO is written to the
output stream.
inverse refers to the order of variables (in VALIS).
ascending means the inverted order (if x<y then x>y wrt. the inverted order).
*)

PROCEDURE EvordWrite();
(* Evord Write.
Writes a description of EVORD to the output stream. *)

PROCEDURE EVRAND(RL,KL: LIST): LIST;
(*Exponent vector random. r is the length of U. k is a
positive beta-digit such that every component of U will be
less than k and k lt beta. U is a random exponent vector.*)


PROCEDURE EVRASP(RL,KL,QL: LIST): LIST;
(*Exponent vector random. r is the length of U. k is a
positive beta-digit such that every component of U will be
less than k and k lt beta. U is a random exponent vector.*)


PROCEDURE EVSIGN(U: LIST): LIST;
(*Exponent vector signum. U=(u1, ...,ur) is an exponent vector
of length r. t=0 if all components are eq 0, t=1 if all
components are ge 0, else t=-1.*)


PROCEDURE EVSU(U,IL,FL: LIST;    VAR V,EL: LIST);
(*Exponent vector substitution. U=(u1, ...,ui, ...,ur)
is an exponent vector of length r. The i-th component is
changed into f. 1 le i le r. e=ui. 
V=(u1, ...,ui-1,f,ui+1, ...,ur). *)


PROCEDURE EVSUM(U,V: LIST): LIST;
(*Exponent vector sum. U=(u1, ...,ur), V=(v1, ...,vr) are
exponent vectors of length r. W=(u1+v1, ...,ur+vr) is the
componentwise sum of U and V. *)


PROCEDURE EVTDEG(U: LIST): LIST;
(*Exponent vector total degree. U is an exponent vector.
n is the sum of the components of U.*)


PROCEDURE PBCLI(RL,A: LIST): LIST;
(*Polynomial base coefficients list. A is a polynomial in
r variables. B is the list of the base coefficients of A. *)


PROCEDURE PFDIP(A: LIST;    VAR RL,B: LIST);
(*Polynomial from distributive polynomial. A is a distributive
polynomial. B is the result of converting A to recursive
representation, r is the number of variables of B, r ge 0.
Modified version, original version by G. E. Collins. *)


PROCEDURE PLFDIL(A: LIST;    VAR RL,B: LIST);
(*Polynomial list from distributive polynom list. A is a list
of distributive polynomials in r variables, r ge 0. Every
polynomial in A is converted to recursive representation and
stored in B. *)


PROCEDURE PMPV(RL,A,IL,NL: LIST): LIST;
(*Polynomial multiplication by power of variable.  A is
a polynomial in r variables. 1 le i le r
and n is a beta-integer. B=A*(x sub i)**n. *)


PROCEDURE PPERMV(RL,A,P: LIST): LIST;
(*Polynomial permutation of variables.  A is a polynomial in
r variables, r ge 0. P is a list (p sub 1, ...,p sub r)
whose elements are the beta-digits 1 through r.
B(x sub (p sub 1), ...,x sub (p sub r))=A(x sub 1, ...,
x sub r).*)


PROCEDURE STVL(RL: LIST): LIST; 
(*Standard variable list. r is the number of variables.
V is the variable list for the variables x1, ...,xr. *)


PROCEDURE DIP2AD(P,d,rest: LIST): LIST;
(* distributive polynomial to arbitrary domain.
   P is a polynomial in distributive representation,
   d is a domain number, rest is a domain descriptor,
   returns P with added domain numbers and descriptors *)


PROCEDURE AD2DIP(P: LIST): LIST;
(* arbitrary domain to distributive polynomial.
   P is a polynomial in distributive representation
   with domain numbers and descriptors,
   returns P without domain numbers and descriptors *)


END DIPC.


(* -EOF- *)
