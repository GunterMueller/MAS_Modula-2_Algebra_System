(* ----------------------------------------------------------------------------
 * $Id: DIPTOOLS.md,v 1.5 1995/11/04 17:59:56 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1994 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPTOOLS.md,v $
 * Revision 1.5  1995/11/04 17:59:56  pesch
 * Changed comments violating documentation rules. Should be rewritten.
 *
 * Revision 1.4  1994/11/28  20:49:04  dolzmann
 * New conversion procedures, partial derivation w.r.t. to a main variable,
 * computation of content and primitive part ...
 *
 * Revision 1.3  1994/06/02  10:37:25  dolzmann
 * New procedures DILMOC and ADPFDIP.
 *
 * Revision 1.2  1994/04/30  12:30:59  dolzmann
 * Procedures PushEvord, PopEvord, PushValis, PopValis have been renamed to
 * EvordPush, EvordPop, ValisPush, ValisPop.
 * New procedures ADDNFDIP, ADDNFDIPD, ADDNFDIL, ADDNFDILD.
 *
 * Revision 1.1  1994/04/14  18:01:58  dolzmann
 * Introduced new modules ADTOOLS and DIPTOOLS.
 *
 * ----------------------------------------------------------------------------
 *)
  
DEFINITION MODULE DIPTOOLS;

(* Distributive Polynomials Tools Definition Module *)

FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: DIPTOOLS.md,v 1.5 1995/11/04 17:59:56 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1994 Universitaet Passau";


(******************************************************************************
*                       V A R I A B L E   V E C T O R S                       *
******************************************************************************)

PROCEDURE VVECFVLIST(v1,v2:LIST):LIST;
(* variable vector from variable lists.
v1,v2 are variable lists, such that v1 is contained in v2.
A variable vector representing v1 w.r.t. v2 is returned. *)

PROCEDURE VVECC(v:LIST):LIST;
(* variable vector complement.
v is a variable vector.
The complement of v is returned. *)


(******************************************************************************
*                    S P E C I A L   P O L Y N O M I A L S                    *
******************************************************************************)

PROCEDURE DIPONE(d:LIST):LIST;
(* distributive polynomial arbitrary domain one.
The polynomial 1 in the actual polynomial ring is returned.
The polynomial ring is determined by the global variable VALIS and the
domain element d. *)


(******************************************************************************
*     D O M A I N   D E S C R I P T O R   F R O M   P O L Y N O M I A L S     *
******************************************************************************)

PROCEDURE ADDDFDIP(p:LIST):LIST;
(* arbitrary domain domain descriptor from distributive polynomial.
p is a polynomial over an arbitrary domain polynomial ring.
The domain descriptor of the arbitrary domain is returned.
If p=0, then 0 is returned. *)

PROCEDURE ADDDFDIPD(p,d:LIST):LIST;
(* arbitrary domain domain descriptor from distributive polynomial or default.
p is a polynomial over an arbitrary domain polynomial ring,
d is a domain descriptor.
The domain descriptor of the arbitrary domain is returned.
If p is the zero polynomial, then the default value d is returned. *)

PROCEDURE ADDDFDIL(l:LIST):LIST;
(* arbitrary domain domain descriptor from distributive polynomial list.
l is a list of polynomials over an arbitrary domain polynomial ring.
The domain descriptor of the arbitrary domain is returned.
If l is the empty list or all polynomials in l are equal to zero,
then 0 is returned. *)

PROCEDURE ADDDFDILD(l,d:LIST):LIST;
(* arbitrary domain domain descriptor from distributive polynomial list
or default.
l is a list of polynomials over an arbitrary domain polynomial ring,
d is a domain descriptor.
The domain descriptor of the arbitrary domain is returned.
If l is the empty list or all polynomials in l are equal to zero,
then 0 is returned. *)


(******************************************************************************
*        D O M A I N   N U M B E R S   F R O M   P O L Y N O M I A L S        *
******************************************************************************)

PROCEDURE ADDNFDIP(p:LIST):LIST;
(* arbitrary domain domain number from distributive polynomial.
p is a polynomial over an arbitrary domain polynomial ring.
The domain number of the arbitrary domain is returned.
If p is the zero polynomial, then 0 is returned. *)

PROCEDURE ADDNFDIPD(p,d:LIST):LIST;
(* arbitrary domain domain number from distributive polynomial or default.
p is a polynomial over an arbitrary domain polynomial ring,
d is a domain number.
The domain number of the arbitrary domain is returned.
If p is the zero polynomial, then the default value d is returned. *)

PROCEDURE ADDNFDIL(l:LIST):LIST;
(* arbitrary domain domain number from distributive polynomial list.
l is a list of polynomials over an arbitrary domain polynomial ring.
The domain number of the arbitrary domain is returned.
If l is the empty list or all polynomials in l are equal to zero,
then 0 is returned. *)

PROCEDURE ADDNFDILD(l,d:LIST):LIST;
(* arbitrary domain domain number from distributive polynomial list
or default.
l is a list of polynomials over an arbitrary domain polynomial ring,
d is a domain number.
The domain number of the arbitrary domain is returned.
If l is the empty list or all polynomials in l are equal to zero,
then 0 is returned. *)


(******************************************************************************
*                  P O L Y N O M I A L   A R I T H M E T I C                  *
******************************************************************************)

PROCEDURE DIPPOWER(p,n:LIST):LIST;
(* distributive polynomial power. p is a distributive polynomial over an
arbitrary domain, n is an integer. The polynomial p**n is returned. *)

PROCEDURE DILPROD(L:LIST;domain:LIST):LIST;
(* distributive polynomial list product.
L is a list of distributive polynomials over an arbitrary domain.
The product of all polynomials in L is returned.
The variable domain specifies the domain of the polynomial ring.
This is necessary to form the polynomial 1, if the list L is empty. *)

PROCEDURE DIPDEGI(p,i:LIST):LIST;
(* distributive polynomial degree of i-th main variable.
p is a distributive polynomial in r variables. 0<i<=r is an atom.
The degree of the i-th variable is returned. The variable are numbered
accordingly to their occurrence in VALIS. *)

PROCEDURE DILMOC(L:LIST):LIST;
(* distributive polynomial monic.
L is a list of distributive polynomials over an arbitrary domain.
Each polynomial is normalized in such a way, that its highest
coefficient is 1. Note, the inverses of the highest coefficients
must exist. Identical polynomials are deleted. *)

PROCEDURE DIPPAD(p,i: LIST):LIST;
(* distributive polynomial partial derivation.
p is a distributive polynomial in r variables.
0<i<=r is an atom.
$\frac{\partial p}{\partial X_i}$ is returned.
$X_i$ is the i-th element in the variable list VALIS *)

PROCEDURE DIMPAD(c,ev,i:LIST):LIST;
(* distributive monomial partial derivation.
c is a arbitrary domain element.
e is an exponent vector with r elements.
0<i<=r is an atom.
$\frac{\partial c X^{ev} }{\partial X_i}$ is returned.
$X_i$ is the i-th element in the variable list VALIS
The result is returned as an distributive polynomial. *)

PROCEDURE DIPCPP(P:LIST; VAR content,ppt: LIST);
(* distributive polynomial content and primitive part. 
P is a distributive polynomial over an arbitrary domain.
The following domain functions must be set:
ADSIGN, ADONE, ADNEG, ADQUOT, ADGCD. 
The content of p is stored in content and 
the primitive part of P is stored in ppt. *)

PROCEDURE DIPPCPP(P:LIST; VAR content,ppt: LIST);
(* distributive polynomial pseudo content and primitive part. 
P is a distributive polynomial over an arbitrary domain.
The following domain functions must be set:
ADONE, ADNEG, ADQUOT.  
ppt is a monic polynomial.
*)

(******************************************************************************
*                         T E S T   F U N C T I O N S                         *
******************************************************************************)

PROCEDURE DIPCNST(dip:LIST): BOOLEAN;
(* distributive polynomial is constant.
dip is a distributive polynomial.
True is returned iff the polynomial is constant, i.e.
there is only one monomial and the exponent vector of the monomial
is a tuple containing only zeroes.. *)

PROCEDURE DIPCNSTR(p,v: LIST):BOOLEAN;
(* distributive polynomial constant relative to variables.
p is a distributive polynomial in n variables.
v is a variable vector.
True is returned, iff p is constant w.r.t. to the variables in v. *)

PROCEDURE EVCNSTR(ev,mvars:LIST):BOOLEAN;
(*exponent vector constant relatively.
ev is a exponent vector of length r.
mvars is a variable vector of length r.
True is returned, iff ev is constant relatively to mvars. *)


(******************************************************************************
*                    E V O R D   /   V A L I S   S T A C K                    *
******************************************************************************)

PROCEDURE EvordPush(evord: LIST);
(* evord push.
evord is a value for the global variable EVORD of the module DIPC.
The variable EVORD is set to evord.
The old value of EVORD is stored on the to of the evord stack.
It can be restored with the command PopEvord. *)

PROCEDURE EvordPop();
(* evord pop.
The global variable EVORD is set to the top element of the evord stack.
The top element is deleted. *)

PROCEDURE ValisPush(valis: LIST);
(* valis push.
valis is a value for the global variable VALIS of the module DIPC.
The variable VALIS is set to valis.
The old value of VALIS is stored on the to of the valis stack.
It can be restored with the command PopValis. *)

PROCEDURE ValisPop();
(* valis pop.
The global variable VALIS is set to the top element of the valis stack.
The top element is deleted. *)

(******************************************************************************
*                    C O N V E R S I O N   R O U T I N E S                    *
******************************************************************************)

PROCEDURE DILINV(dil,j,k:LIST):LIST;
(* distributive polynomial list introduce new variable. dil is a list
of polynomials in a polynomial ring R(X1,...,Xr), 0<=j<r, k>0. The polynomials
are transfered into the polynomial ring R(X1,...,Xj,Y1,...,Yk,Xj+1,...,Xr).
Be carefully, the EV of the original polynomials is (Xr,...,X1) and
the EV of the new polynomials is (Xr,...,Xj+1,Yk,...,Y1,Xj,...,X1).
So j+1,... are the positions of the new variables in
VALIS but not in the exponent vectors of the polynomials. *)

PROCEDURE DIPFDIPP(p,NewDd:LIST;  VAR q, vlist: LIST);
(* distributive polynomial from distributive polynomial over polynomial ring.
p is a distributive polynomial over an arbitrary domain d, which is a
(represented recursively) polynomial ring R[U] (or more exactly R[U1][U2]...).
A distributive polynomial over the domain with the domain descriptor
NewDd is returned in the variable q, the varlist for q in vlist.
It is supposed that the coefficients of the polynomial p have the
form (id,pp,r,valis) where id is the domain identifier, pp is the
polynomial, r is the number of variables and valis is the variable
list for pp. No adaption to the domain elements are done.
The global variable VALIS must be set. *)

PROCEDURE EVEXT(p,evx:LIST):LIST;
(* exponent vector extension.
p is distributive polynomial not equal to zero.
exv is an exponent vector.
All exponent vectors of monomials of p are extended with evx, i.e. each
exponent vector ev is replaced with CONC(evx,ev). *)

PROCEDURE ADPFDIP(p, dd: LIST): LIST;
(* arbitrary domain polynomial from distributive polynomial.
p is a distributive polynomial.
dd is an arbitrary domain descriptor.
All coefficients of p are casted to the domain dd. The result is returned. *)

PROCEDURE DIPPFDIP(p,r,NewDd:LIST;VAR q,vlist: LIST);
(* distributive polynomial over polynomial ring from distributive polynomial.
p is distributive polynomial over an arbitrary domain R. 0<r<DIPNOV(p) is a
number of variables. NewDd is a domain descriptor. The representation of the
polynomial p is changed. Let p in R[U1,...,Ur,X1,...Xn]. The polynomial
p is represented as an element in the polynomial ring R[U1,...,Um][X1,...,Xn].
NewDd must be the domain descriptor of the Ring R[U1,...,Um].
Polynomials in the ring R[U1,...,Um] must be represented recursively.
The new representation of the polynomial p is returned in q. The new
list of main variables is returned in vlist. The global variable VALIS
must be set. *)

PROCEDURE MPPFMP(Coeff,Ev,r:LIST;VAR RCpol,NewEv: LIST);
(* monomial of polynomial ring over polynomial ring from monomial of
polynomial ring.
Coeff is the coefficient of the monomial,
Ev describes the term of the monomial.
r is the number of variables, which are shifted into the coefficient ring.
RCpol is set to the recursive represented coefficient polynomial.
NewEv is the term of the new monomial. *)

PROCEDURE DIPCONV(p,E: LIST):LIST;
(* distributive polynomial conversion.
p is a distributive polynomial over an arbitrary domain D.
All coefficients of p are converted to the domain E.
It is necessary, that the conversion function from the domain D to the
domain E is available. (Set this function with SetConvFunc(D,E,f1)) *)

PROCEDURE DILCONV(P,E: LIST):LIST;
(* distributive polynomial list conversion.
P is a list of distributive polynomials p.
Each p is a distributive polynomial over an arbitrary domain D.
All coefficients of p are converted to the domain E. It is necessary, that the
 conversion function from the domain D to the domain E is available.
(Set this function with SetConvFunc(D,E,f1)) *)

PROCEDURE DIPFADIP(p: LIST):LIST;
(* distributive polynomial from arbitrary domain integral polynomial.
p is an element of the arbitrary domain IP (u_1,...,u_r).
The polynomial p is returned represented as an distributive polynomial
over the arbitrary domain INT.*)

PROCEDURE DIPFIP(p,r: LIST):LIST;
(* distributive polynomial from integral polynomial.
p is an integral polynomial, r is the number of variables of p.
The polynomial p is returned represented as an distributive polynomial
over the arbitrary domain INT.*)

PROCEDURE DILPFDIL(L,r,newdd:LIST):LIST;
(* distributive polynomials over polynomial ring list from distributive
polynomial list.
L is a list of distributive polynomials,
r is the number of variables that are shifted in the coefficient ring,
newdd is the domain descriptor for the new coefficient.
For each polynomial in l the first r variables of the polynomial ring are
shifted in the coefficient ring. *)

PROCEDURE DILFDILP(L,NewDd:LIST):LIST;
(* distributive polynomial list from distributive polynomial list over
polynomial ring list.
L is a list of distributive polynomials over an polynomial ring.
NewDd is a domain descriptor.
All variables of the coefficient ring are shifted to the main variables.
NewDd is the domain descriptor for the new coefficient ring. *)

PROCEDURE DIPCT(p: LIST): LIST;
(* distributive polynomial coefficient tuple.
p is a univariate distributive polynomial over an arbitrary domain.
The coefficient tuple (a_0,...,a_d) of p is returned. *)


(******************************************************************************
*                                S O R T I N G                                *
******************************************************************************)


PROCEDURE DIPIMO(p:LIST):LIST;
(* distributive polynomial inverse monomial order.
p is a distributive polynomial.
The order of the monomials in the polynomials p is inverted.
The polynomial p is modified. The result is returned. *)

PROCEDURE DILIMO(P:LIST):LIST;
(* distributive polynomial list inverse monomial order.
P is a list of distributive polynomials p.
The order of the monomials in each p is inverted. Each p is modified to obtain
the result. *)

(******************************************************************************
*                            M I S C E L L A N E A                            *
******************************************************************************)

PROCEDURE DIPXCM(p,mvars: LIST):LIST;
(* distributive polynomial extract constant monomials.
p is a distributive polynomial in r variables.
mvars is a variable vector.
A polynomial is returned. This polynomial contains all
monomials of p which are constant w.r.t. mvars. *)

PROCEDURE DIPMVV(p: LIST):LIST;
(* distributive polynomial minimal variable vector.
p is a distributive polynomial.
A variable vector containing all variables occuring in p is returned. *)

END DIPTOOLS.

(* -EOF- *)
