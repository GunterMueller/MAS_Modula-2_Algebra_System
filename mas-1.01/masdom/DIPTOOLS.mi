(* ----------------------------------------------------------------------------
 * $Id: DIPTOOLS.mi,v 1.5 1995/11/04 17:59:58 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1994 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPTOOLS.mi,v $
 * Revision 1.5  1995/11/04 17:59:58  pesch
 * Changed comments violating documentation rules. Should be rewritten.
 *
 * Revision 1.4  1994/11/28  20:49:06  dolzmann
 * New conversion procedures, partial derivation w.r.t. to a main variable,
 * computation of content and primitive part ...
 *
 * Revision 1.3  1994/06/02  10:37:26  dolzmann
 * New procedures DILMOC and ADPFDIP.
 *
 * Revision 1.2  1994/04/30  12:31:01  dolzmann
 * Procedures PushEvord, PopEvord, PushValis, PopValis have been renamed to
 * EvordPush, EvordPop, ValisPush, ValisPop.
 * New procedures ADDNFDIP, ADDNFDIPD, ADDNFDIL, ADDNFDILD.
 *
 * Revision 1.1  1994/04/14  18:01:59  dolzmann
 * Introduced new modules ADTOOLS and DIPTOOLS.
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DIPTOOLS;

(* Distributive Polynomials Tools Implementation Module *)

FROM ADTOOLS	IMPORT	ADCAST, ADRMDD, INTDDCMP, IPDDADV;
FROM DIPADOM	IMPORT	DILWR, DIPMOC, DIPNEG, DIPROD, DIPSUM, DIREAD,
			DIWRIT;
FROM DIPC	IMPORT	DILBSO, DIPBSO, DIPFMO, DIPFP, DIPINV, DIPLPM,
			DIPMAD, DIPMCP, DIPNOV, EVORD, EVSIGN, GRLEX, IGRLEX,
			INVLEX, LEX, PFDIP, REVILEX, REVITDG, REVLEX,
			REVTDEG, VALIS;
FROM MASADOM	IMPORT	ADCONV, ADDDREAD, ADDDWRIT, ADFI, ADPROD,
			SetConvFunc, ADSIGN, ADQUOT, ADONE, ADGCD, ADNEG;
FROM MASBIOS	IMPORT	BLINES, LISTS, SWRITE;
FROM MASBIOSU	IMPORT	CLTIS;
FROM MASELEM	IMPORT	GAMMAINT;
FROM MASSTOR	IMPORT	ADV, COMP, FIRST, INV, LENGTH, LIST, LIST1, LISTVAR,
			RED, SFIRST, SIL, SRED;
FROM MASERR	IMPORT	ERROR, confusion, fatal, harmless, severe, spotless;
FROM MASSYM	IMPORT	ATOM, MEMQ;
FROM MASSYM2	IMPORT	UWRITE;
FROM SACLIST	IMPORT	ADV2, ADV3, ADV4, AWRITE, CCONC, CINV, CLOUT, COMP2,
			CONC, EQUAL, FIRST3, FOURTH, LELT, LIST10, LIST2,
			LIST3, LIST4, LIST5, MEMBER, RED2, SECOND, SLELT,
			THIRD;


CONST rcsidi = "$Id: DIPTOOLS.mi,v 1.5 1995/11/04 17:59:58 pesch Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1994 Universitaet Passau";

VAR EvordStack: LIST;	(* stack to store different values of the global
			   variable EVORD from module DIPC. *)
VAR ValisStack: LIST;	(* stack to store different values of the global
			   variable VALIS from module DIPC. *)

(******************************************************************************
*                        D A T A   S T R U C T U R E S                        *
******************************************************************************)

(* VARIABLE VECTOR.
   A variable vector determines a subset of the variables of a
   distributive polynomial.
   A variable vector (w.r.t. VALIS) is a list with length n:=LENGTH(VALIS)
   and elements in \{0,1\}. Iff the i-th element on an variable vector v is 1,
   then the variable of position n-i+1 of VALIS is contains in the set
   determined by v. Note that the i-th element of a variable vector
   corresponds to the i-th element of an exponent vector.
*)


(******************************************************************************
*                       V A R I A B L E   V E C T O R S                       *
******************************************************************************)

PROCEDURE VVECFVLIST(v1,v2:LIST):LIST;
(* variable vector from variable lists.
v1,v2 are variable lists, such that v1 is contained in v2.
A variable vector representing v1 w.r.t. v2 is returned. *)
	VAR v,r: LIST;
BEGIN
	r:=SIL;
	WHILE v2<>SIL DO
		ADV(v2,  v,v2);
		IF MEMBER(v,v1)=1 THEN
			r:=COMP(1,r);
		ELSE
			r:=COMP(0,r);
		END;
	END;
	RETURN r;
END VVECFVLIST;

PROCEDURE VVECC(v:LIST):LIST;
(* variable vector complement.
v is a variable vector.
The complement of v is returned. *)
	VAR u,r: LIST;
BEGIN
	r:=SIL;
	WHILE v<>SIL DO
		ADV(v,  u,v);
		IF u=1 THEN
			r:=COMP(0,r);
		ELSE
			r:=COMP(1,r);
		END;
	END;
	RETURN INV(r);
END VVECC;


(******************************************************************************
*                    S P E C I A L   P O L Y N O M I A L S                    *
******************************************************************************)

PROCEDURE DIPONE(d:LIST):LIST;
(* distributive polynomial arbitrary domain one.
The polynomial 1 in the actual polynomial ring is returned.
The polynomial ring is determined by the global variable VALIS and the
domain element d. *)
	VAR i: INTEGER;
	VAR zev: LIST;
BEGIN
	zev:=SIL;
	FOR i:=1 TO LENGTH(VALIS) DO zev:=COMP(0,zev); END;
	RETURN DIPFMO(ADFI(d,1),zev);
END DIPONE;


(******************************************************************************
*     D O M A I N   D E S C R I P T O R   F R O M   P O L Y N O M I A L S     *
******************************************************************************)

PROCEDURE ADDDFDIP(p:LIST):LIST;
(* arbitrary domain domain descriptor from distributive polynomial.
p is a polynomial over an arbitrary domain polynomial ring.
The domain descriptor of the arbitrary domain is returned.
If p=0, then 0 is returned. *)
	VAR coefficient, ev, dummy: LIST;
BEGIN
	IF p=0 THEN RETURN 0; END;
	DIPMAD(p,coefficient,ev,dummy);
	RETURN ADFI(coefficient,0);
END ADDDFDIP;

PROCEDURE ADDDFDIPD(p,d:LIST):LIST;
(* arbitrary domain domain descriptor from distributive polynomial or default.
p is a polynomial over an arbitrary domain polynomial ring,
d is a domain descriptor.
The domain descriptor of the arbitrary domain is returned.
If p is the zero polynomial, then the default value d is returned. *)
	VAR coefficient, ev, dummy: LIST;
BEGIN
	IF p=0 THEN RETURN d; END;
	DIPMAD(p,coefficient,ev,dummy);
	RETURN ADFI(coefficient,0);
END ADDDFDIPD;

PROCEDURE ADDDFDIL(l:LIST):LIST;
(* arbitrary domain domain descriptor from distributive polynomial list.
l is a list of polynomials over an arbitrary domain polynomial ring.
The domain descriptor of the arbitrary domain is returned.
If l is the empty list or all polynomials in l are equal to zero,
then 0 is returned. *)
	VAR p, coefficient, ev, dummy: LIST;
BEGIN
	IF l=SIL THEN RETURN 0; END;
	REPEAT
		ADV(l,p,l);
	UNTIL (l=SIL) OR (p<>0);
	IF p=SIL THEN RETURN 0; END;
	DIPMAD(p,coefficient,ev,dummy);
	RETURN ADFI(coefficient,0);
END ADDDFDIL;

PROCEDURE ADDDFDILD(l,d:LIST):LIST;
(* arbitrary domain domain descriptor from distributive polynomial list
or default.
l is a list of polynomials over an arbitrary domain polynomial ring,
d is a domain descriptor.
The domain descriptor of the arbitrary domain is returned.
If l is the empty list or all polynomials in l are equal to zero,
then 0 is returned. *)
	VAR p, coefficient, ev, dummy: LIST;
BEGIN
	IF l=SIL THEN RETURN d; END;
	REPEAT
		ADV(l,p,l);
	UNTIL (l=SIL) OR (p<>0);
	IF p=SIL THEN RETURN d; END;
	DIPMAD(p,coefficient,ev,dummy);
	RETURN ADFI(coefficient,0);
END ADDDFDILD;


(******************************************************************************
*        D O M A I N   N U M B E R S   F R O M   P O L Y N O M I A L S        *
******************************************************************************)

PROCEDURE ADDNFDIP(p:LIST):LIST;
(* arbitrary domain domain number from distributive polynomial.
p is a polynomial over an arbitrary domain polynomial ring.
The domain number of the arbitrary domain is returned.
If p is the zero polynomial, then 0 is returned. *)
	VAR coefficient, ev, dummy: LIST;
BEGIN
	IF p=0 THEN RETURN 0; END;
	DIPMAD(p,coefficient,ev,dummy);
	RETURN FIRST(coefficient);
END ADDNFDIP;

PROCEDURE ADDNFDIPD(p,d:LIST):LIST;
(* arbitrary domain domain number from distributive polynomial or default.
p is a polynomial over an arbitrary domain polynomial ring,
d is a domain number.
The domain number of the arbitrary domain is returned.
If p is the zero polynomial, then the default value d is returned. *)
	VAR coefficient, ev, dummy: LIST;
BEGIN
	IF p=0 THEN RETURN d; END;
	DIPMAD(p,coefficient,ev,dummy);
	RETURN FIRST(coefficient);
END ADDNFDIPD;

PROCEDURE ADDNFDIL(l:LIST):LIST;
(* arbitrary domain domain number from distributive polynomial list.
l is a list of polynomials over an arbitrary domain polynomial ring.
The domain number of the arbitrary domain is returned.
If l is the empty list or all polynomials in l are equal to zero,
then 0 is returned. *)
	VAR p, coefficient, ev, dummy: LIST;
BEGIN
	IF l=SIL THEN RETURN 0; END;
	REPEAT
		ADV(l,p,l);
	UNTIL (l=SIL) OR (p<>0);
	IF p=SIL THEN RETURN 0; END;
	DIPMAD(p,coefficient,ev,dummy);
	RETURN FIRST(coefficient);
END ADDNFDIL;

PROCEDURE ADDNFDILD(l,d:LIST):LIST;
(* arbitrary domain domain number from distributive polynomial list
or default.
l is a list of polynomials over an arbitrary domain polynomial ring,
d is a domain number.
The domain number of the arbitrary domain is returned.
If l is the empty list or all polynomials in l are equal to zero,
then 0 is returned. *)
	VAR p, coefficient, ev, dummy: LIST;
BEGIN
	IF l=SIL THEN RETURN d; END;
	REPEAT
		ADV(l,p,l);
	UNTIL (l=SIL) OR (p<>0);
	IF p=SIL THEN RETURN d; END;
	DIPMAD(p,coefficient,ev,dummy);
	RETURN FIRST(coefficient);
END ADDNFDILD;


(******************************************************************************
*                  P O L Y N O M I A L   A R I T H M E T I C                  *
******************************************************************************)

PROCEDURE DIPPOWER(p,n:LIST):LIST;
(* distributive polynomial power. p is a distributive polynomial over an
arbitrary domain, n is an integer. The polynomial p**n is returned. *)
	VAR result, d:LIST;
	VAR domain: LIST;
BEGIN
	IF p=0 THEN RETURN 0; END;
	domain:=ADDDFDIP(p);
	result:=DIPONE(domain);
	d:=p;
	WHILE n>0 DO
		WHILE (n MOD 2) = 0 DO
			d:=DIPROD(d,d);
			n:= n DIV 2;
		END;
		result:=DIPROD(result,d);
		n:=n-1;
	END;
	RETURN result;
END DIPPOWER;

PROCEDURE DILPROD(L:LIST;domain:LIST):LIST;
(* distributive polynomial list product.
L is a list of distributive polynomials over an arbitrary domain.
The product of all polynomials in L is returned.
The variable domain specifies the domain of the polynomial ring.
This is necessary to form the polynomial 1, if the list L is empty. *)
	VAR p,result:LIST;
BEGIN
	IF L=SIL THEN RETURN DIPONE(domain) END;
	ADV(L,result,L);
	WHILE L<>SIL DO
		ADV(L,p,L);
		IF p=0 THEN RETURN 0; END;
		result:=DIPROD(result,p);
	END;
	RETURN result;
END DILPROD;

PROCEDURE DIPDEGI(p,i:LIST):LIST;
(* distributive polynomial degree of i-th main variable.
p is a distributive polynomial in r variables. 0<i<=r is an atom.
The degree of the i-th variable is returned. The variable are numbered
accordingly to their occurrence in VALIS. *)
	VAR result, c,e,md,pos,dummy:LIST;
BEGIN
	IF (p=0) OR (p=SIL) THEN RETURN 0; END;
	DIPMAD(p,  c,e,p);
	pos:=LENGTH(e)-i+1;	(* position of the exponent *)
	result:=LELT(e,pos);
	WHILE p<>SIL DO
		DIPMAD(p,  c,e,p);
		md:=LELT(e,pos);
		IF md>result THEN result:=md; END;
	END;
	RETURN result;
END DIPDEGI;

PROCEDURE DILMOC(L:LIST):LIST;
(* distributive polynomial monic.
L is a list of distributive polynomials over an arbitrary domain.
Each polynomial is normalized in such a way, that its highest
coefficient is 1. Note, the inverses of the highest coefficients
must exist. Identical polynomials are deleted. *)
	VAR p,r: LIST;
BEGIN
	r:=SIL;
	WHILE L<>SIL DO
		ADV(L,p,L);
		p:=DIPMOC(p);
		IF MEMBER(p,r)=0 THEN
			r:=COMP(DIPMOC(p),r);
		END;
	END;
	RETURN INV(r);
END DILMOC;

PROCEDURE DIPPAD(p,i: LIST):LIST;
(* distributive polynomial partial derivation.
p is a distributive polynomial in r variables.
0<i<=r is an atom.
$\frac{\partial p}{\partial X_i}$ is returned.
$X_i$ is the i-th element in the variable list VALIS *)
	VAR c,ev,m,result: LIST;
BEGIN
	IF p=0 THEN RETURN 0; END;
	result:=SIL;
	WHILE p<>SIL DO
		DIPMAD(p,  c,ev,p);
		m:=DIMPAD(c,ev,i);
		IF m<>0 THEN
			result:=DIPMCP(SECOND(m),FIRST(m),result);
		END;
	END;
	RETURN DIPIMO(result);
END DIPPAD;

PROCEDURE DIMPAD(c,ev,i:LIST):LIST;
(* distributive monomial partial derivation.
c is a arbitrary domain element.
e is an exponent vector with r elements.
0<i<=r is an atom.
$\frac{\partial c X^{ev} }{\partial X_i}$ is returned.
$X_i$ is the i-th element in the variable list VALIS
The result is returned as an distributive polynomial. *)
	VAR e,ep,cp,j: LIST;
BEGIN
	ep:=SIL;
		(* The ordering of VALIS is inverted to the ordering in
		   the exponent vector *)
		ev:=CINV(ev);
		FOR j:=1 TO i-1 DO
			ADV(ev, e,ev);
			ep:=COMP(e,ep);
		END;
		ADV(ev, e,ev);
		IF e>0 THEN
			cp:=ADPROD(c,ADFI(c,e));
			ep:=COMP(e-1,ep);
		ELSE
			RETURN 0;
		END;
		WHILE ev<>SIL DO
			ADV(ev, e,ev);
			ep:=COMP(e,ep);
		END;
	RETURN LIST2(ep,cp);
END DIMPAD;

PROCEDURE DIPCPP(p:LIST; VAR content,ppt: LIST);
(* distributive polynomial content and primitive part. 
P is a distributive polynomial over an arbitrary domain.
The following domain functions must be set:
ADSIGN, ADONE, ADNEG, ADQUOT, ADGCD. 
The content of p is stored in content and 
the primitive part of P is stored in ppt. *)
	VAR pp, q, c, e, revert, hcsign: LIST;
BEGIN
(*0*)	(*special case *)
	IF p=0 THEN content:=0; ppt:=0; RETURN; END;
(*1*)	(* initialization *)
	pp:=p;	
	DIPMAD(pp,  content,e,pp);
	hcsign:=ADSIGN(content);	(* sign(HC(p)) *)
(*2*)	(* compute content *)
	WHILE (pp<>SIL) AND (ADONE(content)<>1) DO
		DIPMAD(pp,  c,e,pp);
		content:=ADGCD(content,c);
	END;
(*3*)	(* choose sign of content *)  
	IF ADSIGN(content)<>hcsign THEN content:=ADNEG(content); END;
(*4*)	(* compute primitive part. *)
	IF ADONE(content)=1 THEN ppt:=p; RETURN; END;
	pp:=p;
	q:=SIL;
	WHILE pp<>SIL DO
		DIPMAD(pp,  c,e,pp);
		c:=ADQUOT(c,content);
		q:=DIPMCP(c,e,q);
	END;
(*9*)	(* reorder the result and return it *)
	ppt:=DIPIMO(q);
	RETURN;
END DIPCPP;

PROCEDURE DIPPCPP(p:LIST; VAR content,ppt: LIST);
(* distributive polynomial pseudo content and primitive part. 
P is a distributive polynomial over an arbitrary domain.
The following domain functions must be set:
ADONE, ADNEG, ADQUOT.  
ppt is a monic polynomial, such that P=content * ppt.
*)
	VAR pp, q, c, e, revert, hcsign: LIST;
BEGIN
(*0*)	(*special case *)
	IF p=0 THEN content:=0; ppt:=0; RETURN; END;
(*1*)	(* initialization *)
	pp:=p;	
(*2*)	(* compute pseudo content. *)
	DIPMAD(pp,  content,e,pp);
(*4*)	(* compute primitive part. *)
	IF ADONE(content)=1 THEN ppt:=p; RETURN; END;
	pp:=p;
	q:=SIL;
	WHILE pp<>SIL DO
		DIPMAD(pp,  c,e,pp);
		c:=ADQUOT(c,content);
		q:=DIPMCP(c,e,q);
	END;
(*9*)	(* reorder the result and return it *)
	ppt:=DIPIMO(q);
	RETURN;
END DIPPCPP;

(******************************************************************************
*                         T E S T   F U N C T I O N S                         *
******************************************************************************)

PROCEDURE DIPCNST(dip:LIST): BOOLEAN;
(* distributive polynomial is constant.
dip is a distributive polynomial.
True is returned iff the polynomial is constant, i.e.
there is only one monomial and the exponent vector of the monomial
is a tuple containing only zeroes.. *)
	VAR e,c,r: LIST;
BEGIN
	IF dip=0 THEN RETURN TRUE; END;
	ADV2(dip,e,c,r);
	IF r<>SIL THEN RETURN FALSE; END;
	IF EVSIGN(e)=0 THEN RETURN TRUE; END;
	RETURN FALSE;
END DIPCNST;

PROCEDURE DIPCNSTR(p,v: LIST):BOOLEAN;
(* distributive polynomial constant relative to variables.
p is a distributive polynomial in n variables.
v is a variable vector.
True is returned, iff p is constant w.r.t. to the variables in v. *)
	VAR c,e,f,ei,vi,vp: LIST;
BEGIN
	IF p=0 THEN RETURN TRUE; END;
	WHILE p<>SIL DO
		DIPMAD(p,  c,e,p);
		vp:=v;
		WHILE e<>SIL DO
			ADV(e,  ei,e);
			ADV(vp,  vi,vp);
			IF (vi=1) AND (ei<>0) THEN RETURN FALSE; END;
		END;
	END;
	RETURN TRUE;
END DIPCNSTR;

PROCEDURE EVCNSTR(ev,mvars:LIST):BOOLEAN;
(*exponent vector constant relatively.
ev is a exponent vector of length r.
mvars is a variable vector of length r.
True is returned, iff ev is constant relatively to mvars. *)
	VAR e,m: LIST;
BEGIN
	WHILE ev<>SIL DO
		ADV(ev,  e,ev);
		ADV(mvars,  m,mvars);
		IF (mvars=1) AND (e<>0) THEN
			RETURN FALSE;
		END;
	END;
	RETURN TRUE;
END EVCNSTR;


(******************************************************************************
*                    E V O R D   /   V A L I S   S T A C K                    *
******************************************************************************)

PROCEDURE EvordPush(evord: LIST);
(* evord push.
evord is a value for the global variable EVORD of the module DIPC.
The variable EVORD is set to evord.
The old value of EVORD is stored on the to of the evord stack.
It can be restored with the command PopEvord. *)
BEGIN
	EvordStack:=COMP(EVORD,EvordStack);
	EVORD:=evord;
	RETURN;
END EvordPush;

PROCEDURE EvordPop();
(* evord pop.
The global variable EVORD is set to the top element of the evord stack.
The top element is deleted. *)
BEGIN
	IF EvordStack=SIL THEN
		ERROR(severe,"EvordPop: pop to empty stack");
	ELSE
		ADV(EvordStack,EVORD,EvordStack);
	END;
END EvordPop;

PROCEDURE ValisPush(valis: LIST);
(* valis push.
valis is a value for the global variable VALIS of the module DIPC.
The variable VALIS is set to valis.
The old value of VALIS is stored on the to of the valis stack.
It can be restored with the command PopValis. *)
BEGIN
	ValisStack:=COMP(VALIS,ValisStack);
	VALIS:=valis;
	RETURN;
END ValisPush;

PROCEDURE ValisPop();
(* valis pop.
The global variable VALIS is set to the top element of the valis stack.
The top element is deleted. *)
BEGIN
	IF ValisStack=SIL THEN
		ERROR(severe,"ValisPop: pop to empty stack");
	ELSE
		ADV(ValisStack,VALIS,ValisStack);
	END;
END ValisPop;

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
	VAR dip,result: LIST;
BEGIN
	result:=SIL;
	WHILE dil<>SIL DO
		ADV(dil,dip,dil);
		result:=COMP(DIPINV(dip,j,k),result);
	END;
	RETURN INV(result);
END DILINV;

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
	VAR coeff, exp, dummy, pp,r,result: LIST;
	VAR c,e: LIST;
BEGIN
(*0*)	(* special case *)
	IF p=0 THEN q:=0; vlist:=SIL; RETURN; END;
(*1*)	(* determine the variable list and the number of variables of the
	   coefficients. *)
	DIPMAD(p,coeff,exp,dummy);
	vlist:=FOURTH(coeff);
	vlist:=CCONC(vlist,INV(CINV(VALIS)));
	r:=THIRD(coeff);
(*2*)	(* transform each monomial into a polynomial and form the result *)
	result:=SIL;
	WHILE p<>SIL DO
		DIPMAD(p,coeff,exp,p);
		(* coeff is a recursive polynomial *)
		coeff:=DIPFP(r,ADRMDD(coeff));
		DIPBSO(coeff);
		(* now coeff is in distributive representation *)
		(* multiply the coefficient polynomial with the polynomial
		*  (term) which is given by the exponent vector exp *)
		pp:=EVEXT(coeff,exp);
		(* note: each created term is unique in all terms, because
		*  each monomial created from one recursive polynomial is
		*  unique and the monomials of the recursive polynomials
		*  are multiplied with a unique term, so you can use
		*  DIPMCP and DIPBSO to construct the result. *)
		WHILE pp<>SIL DO
			DIPMAD(pp,c,e,pp);
			result:=DIPMCP(c,e,result);
		END;
	END;
(*9*)	(* reorder the result and return it *)
	result:=ADPFDIP(result,NewDd);
	DIPBSO(result);
	q:=result;
	RETURN;
END DIPFDIPP;

PROCEDURE EVEXT(p,evx:LIST):LIST;
(* exponent vector extension.
p is distributive polynomial not equal to zero.
exv is an exponent vector.
All exponent vectors of monomials of p are extended with evx, i.e. each
exponent vector ev is replaced with CONC(evx,ev). *)
	VAR coeff, ev, result: LIST;
BEGIN
(*1*)	(* initialization *)
	result:=SIL;
(*2*)	(* process each monomial of p *)
	WHILE p<>SIL DO 	(* p <> 0 ! *)
		DIPMAD(p,coeff,ev,p);
		result:=DIPMCP(coeff,CCONC(evx,ev),result);
	END;
(*9*)	(* sort the result and return it *)
	DIPBSO(result);
	RETURN result;
END EVEXT;

PROCEDURE ADPFDIP(p, dd: LIST): LIST;
(* arbitrary domain polynomial from distributive polynomial.
p is a distributive polynomial.
dd is an arbitrary domain descriptor.
All coefficients of p are casted to the domain dd. The result is returned. *)
	VAR result, coeff, ev: LIST;
BEGIN
(*0*)	(* special case *)
	IF p=0 THEN RETURN 0; END;
(*1*)	(* initialization *)
	result:=SIL;
(*2*)	(* process each monomial of p *)
	WHILE p<>SIL DO
		DIPMAD(p,coeff,ev,p);
		result:=DIPMCP(ADCAST(coeff,dd),ev,result);
	END;
(*9*)	(* reorder the result. *)
	(* only the order of monomials must be inverted. But INV is not
	admissible *)
	RETURN DIPIMO(result);
END ADPFDIP;

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
	VAR result,cvlist,v,coeff,ev,RCpol,NewEv: LIST;
	VAR i:INTEGER;
BEGIN
(*0*)	(* special case *)
	IF p=0 THEN q:=0; vlist:=SIL; RETURN; END;
(*1*)	(* determine the variable lists. *)
	vlist:=INV(CINV(VALIS));
	cvlist:=SIL;
	FOR i:=1 TO r DO
		ADV(vlist,v,vlist);
		cvlist:=COMP(v,cvlist);
	END;
	cvlist:=INV(cvlist);
(*2*)	(* determine the number of variables of the coefficient polynomials *)
	r:=LENGTH(cvlist);
(*3*)	(* convert each monomial *)
	result:=SIL;
	q:=0;
	WHILE p<>SIL DO
		DIPMAD(p,coeff,ev,p);
		MPPFMP(ADRMDD(coeff),ev,r,RCpol,NewEv);
		RCpol:=ADCAST(RCpol,NewDd);
		result:=SIL;
		(* form the result. *)
		(* note: there are possibly equal terms, so DIPMCP is not
		*  sufficient to form the result. *)
		q:=DIPSUM(q,DIPMCP(RCpol,NewEv,SIL));

	END;
(*4*)	(* sort the result polynomial according to the actual term order *)
	DIPBSO(q);
	RETURN;
END DIPPFDIP;

PROCEDURE MPPFMP(Coeff,Ev,r:LIST;VAR RCpol,NewEv: LIST);
(* monomial of polynomial ring over polynomial ring from monomial of
polynomial ring.
Coeff is the coefficient of the monomial,
Ev describes the term of the monomial.
r is the number of variables, which are shifted into the coefficient ring.
RCpol is set to the recursive represented coefficient polynomial.
NewEv is the term of the new monomial. *)
	VAR CoeffEv,dummy,Cpol,e: LIST;
	VAR i: INTEGER;
BEGIN
(*1*)	(* determine the exponent vector of coefficient and monomial. *)
	NewEv:=CINV(Ev);
	CoeffEv:=SIL;
	FOR i:=1 TO r DO
		ADV(NewEv,e,NewEv);
		CoeffEv:=COMP(e,CoeffEv);
	END;
	NewEv:=INV(NewEv);
(*2*)	(* construct the coefficient polynomial *)
	Cpol:=SIL;
	Cpol:=DIPMCP(Coeff,CoeffEv,Cpol);
(*3*)	(* convert the coefficient polynomial into recursive representation. *)
	EvordPush(INVLEX);
	PFDIP(Cpol,dummy,RCpol);
	EvordPop();
(*9*)	RETURN;
END MPPFMP;

PROCEDURE DIPCONV(p,E: LIST):LIST;
(* distributive polynomial conversion.
p is a distributive polynomial over an arbitrary domain D.
All coefficients of p are converted to the domain E.
It is necessary, that the conversion function from the domain D to the
domain E is available. (Set this function with SetConvFunc(D,E,f1)) *)
	VAR coeff,exp,result:LIST;
BEGIN
	IF p=0 THEN RETURN 0; END;
	result:=SIL;
	WHILE p<>SIL DO
		DIPMAD(p,coeff,exp,p);
		coeff:=ADCONV(E,coeff);
		result:=DIPMCP(coeff,exp,result);
	END;
	RETURN DIPIMO(result);
END DIPCONV;

PROCEDURE DILCONV(P,E: LIST):LIST;
(* distributive polynomial list conversion.
P is a list of distributive polynomials p.
Each p is a distributive polynomial over an arbitrary domain D.
All coefficients of p are converted to the domain E. It is necessary, that the
 conversion function from the domain D to the domain E is available.
(Set this function with SetConvFunc(D,E,f1)) *)
	VAR p,r:LIST;
BEGIN
	r:=SIL;
	WHILE P<>SIL DO
		ADV(P,p,P);
		r:=COMP(DIPCONV(p,E),r);
	END;
	RETURN INV(r);
END DILCONV;

PROCEDURE DIPFADIP(p: LIST):LIST;
(* distributive polynomial from arbitrary domain integral polynomial.
p is an element of the arbitrary domain IP (u_1,...,u_r).
The polynomial p is returned represented as an distributive polynomial
over the arbitrary domain INT.*)
	VAR d, q, qp, r, m, e, vl: LIST;
BEGIN
	IPDDADV(p,  q,r,vl);
	RETURN DIPFIP(q,r);
END DIPFADIP;

PROCEDURE DIPFIP(p,r: LIST):LIST;
(* distributive polynomial from integral polynomial.
p is an integral polynomial, r is the number of variables of p.
The polynomial p is returned represented as an distributive polynomial
over the arbitrary domain INT.*)
	VAR d, qp, m, e, vl: LIST;
BEGIN
	p:=DIPFP(r,p);
	IF p=0 THEN RETURN 0; END;
	qp:=SIL;
	d:=INTDDCMP();
	WHILE p<>SIL DO
		DIPMAD(p,  m,e,p);
		qp:=DIPMCP(ADFI(d,m),e,qp);
	END;
	DIPBSO(qp);
	RETURN qp;
END DIPFIP;

PROCEDURE DILPFDIL(L,r,newdd:LIST):LIST;
(* distributive polynomials over polynomial ring list from distributive
polynomial list.
L is a list of distributive polynomials,
r is the number of variables that are shifted in the coefficient ring,
newdd is the domain descriptor for the new coefficient.
For each polynomial in l the first r variables of the polynomial ring are
shifted in the coefficient ring. *)
	VAR p, vl,res: LIST;
BEGIN
	res:=SIL;
	WHILE L<>SIL DO
		ADV(L,  p,L);
		DIPPFDIP(p,r,newdd,  p,vl);
		res:=COMP(p,res);
	END;
	RETURN INV(res);
END DILPFDIL;

PROCEDURE DILFDILP(L,NewDd:LIST):LIST;
(* distributive polynomial list from distributive polynomial list over
polynomial ring list.
L is a list of distributive polynomials over an polynomial ring.
NewDd is a domain descriptor.
All variables of the coefficient ring are shifted to the main variables.
NewDd is the domain descriptor for the new coefficient ring. *)
	VAR vl, q, p, result: LIST;
BEGIN
	result:=SIL;
	WHILE L<>SIL DO
		ADV(L,  p,L);
		DIPFDIPP(p,NewDd,  q,vl);
		result:=COMP(q,result);
	END;
	RETURN INV(result);
END DILFDILP;

PROCEDURE DIPCT(p: LIST): LIST;
(* distributive polynomial coefficient tuple.
p is a univariate distributive polynomial over an arbitrary domain.
The coefficient tuple (a_0,...,a_d) of p is returned. *)
	VAR A,i,j,coeff,exp,dummy,deg,perm,zero: LIST;
BEGIN
(*0*)	(* Special case. *)
	IF p=0 THEN RETURN SIL; END;
(*1*)	(* determine the degree of p *)
	DIPMAD(p,  coeff,exp,dummy);
	deg:=FIRST(exp);
(*2*)	(* Initialization. *)
	zero:=ADFI(coeff,0);
	A:=SIL;
	i:=deg;
(*3*)	(* Insert each coefficient of p in the coefficient tuple. *)
	WHILE p<>SIL DO
		DIPMAD(p,  coeff,exp,p);
		exp:=FIRST(exp);
(*4*)		(* Insert 0 if coefficient is omitted. *)
		WHILE exp<i DO
			i:=i-1;
			A:=COMP(zero,A);
		END;
		A:=COMP(coeff,A);
		i:=i-1;
	END;
(*5*)	(* Insert trailing zeroes. *)
	FOR j:=i TO 0 BY -1 DO
		A:=COMP(zero,A);
	END;
(*9*)	(* Return the result. *)
	RETURN A;
END DIPCT;


(******************************************************************************
*                                S O R T I N G                                *
******************************************************************************)


PROCEDURE DIPIMO(p:LIST):LIST;
(* distributive polynomial inverse monomial order.
p is a distributive polynomial.
The order of the monomials in the polynomials p is inverted.
The polynomial p is modified. The result is returned. *)
	VAR r,h:LIST;
BEGIN
	IF p=0 THEN RETURN 0; END;
	r:=SIL;
	WHILE p<>SIL DO
		h:=RED2(p);
		SRED(RED(p),r);
		r:=p;
		p:=h;
	END;
	RETURN r;
END DIPIMO;

PROCEDURE DILIMO(P:LIST):LIST;
(* distributive polynomial list inverse monomial order.
P is a list of distributive polynomials p.
The order of the monomials in each p is inverted. Each p is modified to obtain
the result. *)
	VAR p,r:LIST;
BEGIN
	r:=SIL;
	WHILE P<>SIL DO
		ADV(P,p,P);
		r:=COMP(p,r);
	END;
	RETURN INV(r);
END DILIMO;

(******************************************************************************
*                            M I S C E L L A N E A                            *
******************************************************************************)

PROCEDURE DIPXCM(p,mvars: LIST):LIST;
(* distributive polynomial extract constant monomials.
p is a distributive polynomial in r variables.
mvars is a variable vector.
A polynomial is returned. This polynomial contains all
monomials of p which are constant w.r.t. mvars. *)
	VAR result,c,e: LIST;
BEGIN
	IF p=0 THEN RETURN 0; END;
	result:=SIL;
	WHILE p<>SIL DO
		DIPMAD(p,  c,e,p);
		IF EVCNSTR(e,mvars) THEN
			result:=DIPMCP(result,c,e);
		END;
	END;
	RETURN DIPIMO(result);
END DIPXCM;

PROCEDURE DIPMVV(p: LIST):LIST;
(* distributive polynomial minimal variable vector.
p is a distributive polynomial.
A variable vector containing all variables occuring in p is returned. *)
	VAR c,e,ev,v,vv,i,result: LIST;
BEGIN
	IF p=0 THEN RETURN SIL; END;
	result:=SIL;
	FOR i:=1 TO DIPNOV(p) DO
		result:=COMP(0,result);
	END;
	WHILE p<>SIL DO
		DIPMAD(p,  c,ev,p);
		i:=0;
		vv:=result;
		WHILE ev<>SIL DO
			i:=i+1;
			ADV(vv,  v,vv);
			ADV(ev,  e,ev);
			IF (e<>0) AND (v<>1) THEN
				SLELT(result,i,1);
			END;
		END;
	END;
	RETURN result;
END DIPMVV;

(******************************************************************************
*                                   M A I N                                   *
******************************************************************************)

BEGIN
	LISTVAR(ValisStack);
	ValisStack:=SIL;
	LISTVAR(EvordStack);
	EvordStack:=SIL;
END DIPTOOLS.

(* -EOF- *)
