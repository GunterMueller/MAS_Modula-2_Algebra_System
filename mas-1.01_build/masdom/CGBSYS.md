(* ----------------------------------------------------------------------------
 * $Id: CGBSYS.md,v 1.9 1996/06/08 16:47:14 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1996 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: CGBSYS.md,v $
 * Revision 1.9  1996/06/08 16:47:14  pesch
 * Reformatted, removed obsolete procedures.
 *
 * Revision 1.8  1995/03/06  15:49:41  pesch
 * Added new procedure GSYSF, Groebner system with factorization. This uses
 * the new procedures GBSYSF and CONSGBF (also added).
 *
 * Added new procedures DIP2AD, AD2DIP and DIPPFACTAV.
 *
 * Fixed error in CHECK.
 *
 * New option for factorization of conditions: factorize with optimization
 * of variable ordering.
 *
 * Revision 1.7  1994/04/10  16:57:44  pesch
 * Modified CONSGB. Returns its result now. When a condition is ramified,
 * we continue with this new case distinction first. This is useful to
 * have the generic case computed first.
 *
 * Revision 1.6  1994/04/09  18:06:01  pesch
 * Reformatted parts of the CGB sources. Updated comments in CGB*.md.
 *
 * Revision 1.5  1994/03/11  15:58:17  pesch
 * Major changes to CGB.
 * C-Preprocessor now used for .mip files. The corresponding .mi files have
 * been removed.
 * Many new CGB-Functions and fixes of old ones.
 *
 * Revision 1.4  1993/04/15  13:14:23  kredel
 * Further corrections by Pesch
 *
 * Revision 1.3  1993/03/17  11:45:39  kredel
 * Changes and corrections by Pesch.
 *
 * Revision 1.2  1992/02/12  17:31:18  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:08:58  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE CGBSYS;

(* Comprehensive-Groebner-Bases System Definition Module. *)

FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: CGBSYS.md,v 1.9 1996/06/08 16:47:14 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1996 Universitaet Passau";


PROCEDURE GRED(COND,PCO,PCI,RE: LIST; VAR RCO,HA: LIST); 
(*Parametric reduction. COND is a condition, PCO and PCI are coloured
polynomials. PCI is determined by cond. RE is a term in PCO coloured
red or white by COND. RE is a multiple of the headterm (wrt cond) of PCI.
RCO is the result
of one step reduction of PCO ( by PCI ) to eliminate the term RE. HA
is the multiple factor of PCO. *)


PROCEDURE GBDIFF(COND,A,ACOLS,B,BCOLS: LIST; VAR C,CCOLS: LIST); 
(*Parametric difference. COND is a condition. A and B are polynomials.
ACOLS is the colouring of A wrt cond, BCOLS is the colouring of B wrt
COND. C=A-B. CCOLS is the colouring of C wrt COND. *)


PROCEDURE COLPRD(COL1,TTERM: LIST): LIST; 
(*Colour product. COL1 contains a list of red terms and a list of white
terms. TTERM is a term. Every term in COL1 is multiplied with TTERM.*)


PROCEDURE CMULT(ONECL,TTERM,B: LIST): LIST; 
(*Colour multiplication.
If B=1 then ONECL is a list of (red) terms.
If B=2 then ONECL is a list of pairs, each containing a (white) term
and the white part of its coefficient.
TTERM is a term. Every term in ONECL is multiplicated with TTERM.
CCOL is the result. *)


PROCEDURE WHSRT(COL,TTERM,ALIST: LIST): LIST; 
(*White sort. COL contains a list of red terms and a list of white terms.
The form of COL is
((r1,... ,rn),((w1,(wp11,; ,wp1s)),... ,(wm,(wpm1,; ,wpms)))).
TTERM is a term. ALIST is a list of coefficients.
The form of ALIST is (a1,... ,at).
Every term of COL is multiplied with TTERM. The resulting terms are
coloured white by adding ALIST to its white part. The list of red terms
is empty. The list of white terms z is as follows
( (r1*tterm,(a1,... ,at)),... ,(rn*tterm,(a1,... ,at)),
(w1*tterm,(a1,... ,at,wp11,... ,wp1s)),... ,
(wm*tterm,(a1,... ,at,wpm1,... ,wpms)) ).
CWHIT0  contains the same terms as z in a nondecreasing order.
COLS is pair containg an empty list of red terms and the list CWHIT0. *)


PROCEDURE WUPD(ALIST,BLIST: LIST): LIST; 
(*White part update. ALIST and BLIST are sets of coefficients.
Returns the union of ALIST and BLIST. *)


PROCEDURE COLDIF(T,ACOLS,COLR,COLW: LIST; VAR CRED,CWHITE: LIST); 
(*Colour difference. T is term. ACOLS contains a list of red terms
and a list of white terms. COLR is a list of red terms. COLW is
a list of white terms.
If T is member of the red terms in ACOLS, it is added to COLR. The
result is CRED.
If T is member of the white terms in ACOLS, it is added to COLW with
its white part. The result is CWHITE. *)


PROCEDURE KEYCOL(EL,ACOLS: LIST; VAR KEY,ALIST: LIST); 
(*Key colour. EL is a term.
ACOLS contains a list of red terms and a list of white terms.
If EL is member of the red terms in ACOLS then KEY=1 and ALIST is empty.
If EL is member of the white terms in ACOLS then KEY=2 and ALIST is
the white part of EL.
If EL is not in ACOLS (EL is coloured green) then KEY=0 and ALIST is empty. *)


PROCEDURE MKACOL(ALIST,EL,COLR,COLW: LIST; VAR CRED,CWHITE: LIST); 
(*Make colour. ALIST is a list of coefficients. EL is a term.
COLR is a list of red terms. COLW is a list of white terms.
If ALIST is empty, EL is added to COLR. The result is CRED.
If ALIST is not empty, the pair of EL and ALIST is added to COLW. the
result is CWHITE. *)


PROCEDURE MKCOL(COND,CA,CE,COLR,COLW: LIST; VAR CRED,CWHITE: LIST); 
(*Make new colour. COND is a condition. CA is a coefficient. CE is
a term. COLR is a list of red terms. COLW is a list of white terms.
If CA is coloured red by COND, CE is added to COLR. the result is CRED.
If CA is coloured white by COND, the pair with CE and the white factors
of CA are added to COLW. the result is CWHITE. *)


PROCEDURE FINCOL(APP,ACOLS,COLR,COLW: LIST; VAR CRED,CWHITE: LIST); 
(*Finish colouring. APP is a polynomial.
ACOLS contains a list of red terms and a list of white terms.
COLR is a list of red terms. COLW is a list of white terms.
The red terms of APP are added to COLR. the result is CRED.
The white terms of APP are added to COLW with their white part.
The result is CWHITE. *)


PROCEDURE NFORM(GA,FCO,P: LIST; VAR N0,N1: LIST); 
(*Parametric normalform.
GA is a condition. FCO is a polynomial coloured wrt GA.
P is a list of polynomials coloured wrt GA.
FCO is reduced modulo P wrt GA. N0 is the set of tripel of the form
(cond,pco,c), where cond is a condition, pco is a normalform of fco
coloured completely green by cond and c is a multiplicative factor.
N1 is the set of tripel of the form
(cond,pco,c), where cond is a condition, pco is a normalform of fco
not coloured completely green by cond and c is a multiplicative
factor. *)


PROCEDURE NFTOP(GA,FCO,P: LIST; VAR N0,N1: LIST); 
(*Normalform by topreduction.
GA is a condition. FCO is a polynomial coloured wrt GA.
P is a list of polynomials coloured wrt GA.
FCO is reduced modulo P wrt GA. N0 is the set of tripel of the form
(cond,pco,c), where cond is a condition, pco is a normalform of fco
coloured completely green by cond and c is a multiplicative factor.
N1 is the set of tripel of the form
(cond,pco,c), where cond is a condition, pco is a normalform of fco
not coloured completely green by cond and c is a multiplicative
factor. *)

PROCEDURE FINDPI(PCO,P: LIST; VAR PCI,RE: LIST); 
(*Find polynomial.
PCO is a coloured polynomial.
P is a list of coloured polynomials. 
A polynomial for the reduction over all terms of PCO modulo P
is searched.
PCI is emtpy if no polynomial is found, else PCI is the found
polynomial and RE is the term of PCO to be eliminated. *)

PROCEDURE FINDPITOP(PCO,P: LIST; VAR PCI,RE: LIST); 
(*Find polynomial.
PCO is a coloured polynomial.
P is a list of coloured polynomials.
A polynomial for the topreduction of PCO modulo P is searched.
PCI is emtpy if no polynomial is found, else PCI is the found
polynomial and RE is the term of PCO to be eliminated. *)


PROCEDURE SPOL(COND,HA,HB: LIST): LIST; 
(*Parametric spolynom. COND is a condition. HA and HB are coloured
polynomials.
Returns the spolynom of HA and HB with colouring. *)


PROCEDURE GBSYS(CNDS,P: LIST): LIST;
(*Groebner system.
CNDS is a case distinction.
P is a list of polynomials.
Returns a Groebner-system for P relative to CNDS. *)


PROCEDURE GBSYSF(CNDS,P: LIST): LIST;
(*Groebner system with factorization.
CNDS is a case distinction.
P is a list of polynomials.
Returns a Groebner-system for P relative to CNDS. *)


PROCEDURE VRNORM(COND,PP,N0,N1,PPAIRS: LIST;
                 VAR P,PAIRS,PAIRSL,GSYS: LIST);
(*Verify normalforms. COND is a condition. PP is a polynomials list
determined by COND. N0 is a set of tripel (ga,pco,c), where ga is
a condition, pco is a normalform determined and coloured completely
green by ga and c is a multiplicative factor. N1 is a set of tripel
(ga,pco,c), where ga is a condition, pco is a normalform determined and
not coloured completely green by ga and c is a multiplicative factor.
PPAIRS is the polynomials pairs list of PP.
The normalforms are checked. PP is updated to P.
PPAIRS is updated to PAIRS. PAIRSL is a list of the form
(cond1,p1,pairs1,... ,condn,pn,pairsn) constructed from the information
of the N0 and N1.
GSYS is a list of pairs, each containing a condition and a groebner
base wrt this condition. *)


PROCEDURE CHDEGL(PLIST: LIST): LIST; 
(*Check degree of polynomial list. PLIST is a list of coloured
polynomials. PCO is an element of PLIST, such that the degree wrt
the colouring of the polynomial is 0. PCO is emtpy if no such
polynomial exists. *)


PROCEDURE MKN1(NN1,P,PAIRS: LIST; VAR PPLIST,GSYS: LIST); 
(* Make n1.
NN1 is a set of tripel of the form
(ga,pco,c), where ga is a condition, pco is a normalform determined and
not coloured completely green by ga and c is a multiplicative
factor.
P is a list of coloured polynomials.
PAIRS is the polynomials pairs list of P.
PPLIST is a list of the form
(cond1,p1,pairs1,... ,condn,pn,pairsn) constructed from the information
of the NN1.
GSYS is a list of pairs, each containing a condition and a groebner
basis wrt this condition. *)


PROCEDURE MKN0(NN0,P,PAIRS: LIST; VAR PPLIST: LIST); 
(*Make n0.
NN0 is a set of tripel of the form
(ga,pco,c), where ga is a condition, pco is a normalform determined and
coloured completely green by ga and c is a multiplicative
factor.
P is a list of coloured polynomials.
PAIRS is the polynomials pairs list of P.
PPLIST is a list of the form
(cond1,p1,pairs1,... ,condn,pn,pairsn) constructed from the information
of the NN0. *)


PROCEDURE GSYSN0(NN0,P: LIST; VAR GSYS: LIST); 
(*Groebner-System n0 update.
NN0 is a set of tripel of the form
(ga,pco,c), where ga is a condition, pco is a normalform determined and
coloured completely green by ga and c is a multiplicative
factor.
P is a list of coloured polynomials.
for each GA in NN0, the pair of the form (ga,p) is added to GSYS. *)


PROCEDURE MINPP(PP,PCO: LIST): LIST; 
(*Minimize polynomials list. PP is a list of coloured polynomials.
PCO is a coloured polynomial.
P is a list of PCO and those polynomials in PP, such that their
headterms wrt the colouring can not be divided by the headterm of PCO
relative to its colouring. *)


PROCEDURE UPDPP(COND,P: LIST): LIST; 
(*Update polynomials. COND is a condition. P is a list of polynomials
determined and coloured wrt a predecessor of COND. The colouring of
each polynomial is updated. The result is the polynomial-list PP. *)


PROCEDURE GBUPD(COND,P,GBSYS: LIST): LIST; 
(*Groebner-system update. COND is a condition. P is a list of polynomials
determined and coloured wrt a predecessor of COND. GBSYS is the actual
Groebner-system. The colouring of each polynomial
in P is updated relative to COND. Extraneous polynomials are elminiated.
The condititon and the resulting polynomials list are added to GBSYS.
The result is GSYS. *)


PROCEDURE MKPAIR(PP: LIST): LIST; 
(*Make pairs. PP is a list of coloured polynomials. The polynomials
pairs list is constructed containing those polynomials whose headterm
relative to the colouring is defined. The list pairs is in a
nondecreasing order. *)


PROCEDURE PRSCOP(PAIRS: LIST): LIST; 
(*Pairs copy. PAIRS is a polynomials pairs list. PPAIRS is a copy of PAIRS. *)


PROCEDURE MKNEWP(P,POL,PRS: LIST): LIST; 
(*Make new pairs. P is a list of coloured polynomials. POL is a
coloured polynomial. PRS is the polynomials pairslist of P. The new
pairs between POL and P are constructed and added to PRS. The result
is PPAIRS. *)


PROCEDURE MKCGB(PL: LIST; VAR X,I: LIST); 
(*Make Comprehensive-Groebner-Basis. PL is a Groebner-System.
X is the Comprehensive-Groebner-Basis from PL. I is the number of
conditions in PL. *)


PROCEDURE ADDCGB(PLIST,P: LIST): LIST; 
(*Add polynomials to comprehensive-groebner-basis. PLIST is
list of coloured polynomials. P is a list of polynomials.
Those polynomials that are not in P, are added to P without their
colouring. the result is PP. *)


PROCEDURE GSRED(GS: LIST): LIST; 
(*Groebner-System reduction. GS is a groebner-system. 
Returns the reduced groebner-system. *)


PROCEDURE REDUCT(PELEM: LIST): LIST; 
(*Reduct. PELEM is a pair containing a condition and a polynomials
list determined and coloured wrt the condition.
The polynomials list is to be reduced.
The result together with the condition is R. *)


PROCEDURE REXTP(P: LIST): LIST; 
(*Remove extraneous polynomials. P is a list of coloured polynomials.
extraneous polynomials relative to their colouring are to be removed.
PP is the resulting list. *)


PROCEDURE RDNORM(COND,FCO,P: LIST; VAR NCO: LIST);
(*Reduction normalform. COND is a condition. FCO is a coloured
polynomial. P is a list of polynomials determined and coloured by COND.
NCO is the normalform of fco modulo P relative to COND. *)


PROCEDURE REFIND(PCO,P: LIST; VAR PLI,RE: LIST); 
(*Reduction find polynomial. PCO is a coloured polynomial.
P is a list of determined and coloured polynomials.
A polynomial for the reduction of PCO modulo P is searched.
PLI is emtpy if no polynomial is found. Else PLI is the found
polynomial and RE is the term of PCO to be eliminated. *)


PROCEDURE RMGRT(COND,PP: LIST): LIST; 
(*Remove green terms. COND is a condition. PP is a list of polynomials
determined and coloured relative to COND. If COND contains coefficients
to be zero, all green monomials of the polynomials in PP are removed.
P is the resulting polynomials list. *)


PROCEDURE GLOBRE(COND,P: LIST): LIST; 
(*Global reduction. COND is a condition. P is a list of polynomials.
CGB is the coloured polynomials list after global reduction. *)


PROCEDURE GLEXTP(P: LIST): LIST; 
(*Global extraneous polynomials remove. P is a list of
coloured polynomials. Determined polynomials that are extraneous, are
removed. The resulting polynomials list is PP. *)

END CGBSYS.
(* -EOF- *)
