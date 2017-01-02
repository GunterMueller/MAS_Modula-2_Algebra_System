(* ----------------------------------------------------------------------------
 * $Id: CGBFUNC.md,v 1.7 1996/06/08 16:47:09 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1996 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: CGBFUNC.md,v $
 * Revision 1.7  1996/06/08 16:47:09  pesch
 * Reformatted, removed obsolete procedures.
 *
 * Revision 1.6  1994/04/09  18:05:55  pesch
 * Reformatted parts of the CGB sources. Updated comments in CGB*.md.
 *
 * Revision 1.5  1994/03/14  16:42:54  pesch
 * Minor changes requested by A. Dolzmann
 *
 * Revision 1.4  1994/03/11  15:58:10  pesch
 * Major changes to CGB.
 * C-Preprocessor now used for .mip files. The corresponding .mi files have
 * been removed.
 * Many new CGB-Functions and fixes of old ones.
 *
 * Revision 1.3  1993/03/17  11:45:36  kredel
 * Changes and corrections by Pesch.
 *
 * Revision 1.2  1992/02/12  17:31:14  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:08:54  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE CGBFUNC;

(* Comprehensive-Groebner-Bases Utility Functions Definition Module. *)

FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: CGBFUNC.md,v 1.7 1996/06/08 16:47:09 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1996 Universitaet Passau";


PROCEDURE WRCOL(COL,POL: LIST); 
(*Write colour.
POL is a polynomial.
COL contains the red and the white coloured terms of POL.
The red and white monomials of POL are written on the output stream. *)


PROCEDURE WRTERM(TERM,V: LIST); 
(*Write term.
TERM is a term.
V is the variable list.
Term is written on the output stream. *)


PROCEDURE DWRIT(DE: LIST); 
(*Distinction write.
DE is a case distinction. DE is written on the output stream. *)


PROCEDURE CGBCOL(COND,PL: LIST): LIST; 
(*Write coloured polynomials without green monomials. COND is a
condition. PL is a list of polynomials coloured wrt the condition.
If the condition contains coefficients to be 0,
each polynomial is written on the output stream without the green
coloured monomials. *)


PROCEDURE DCLWR(PL,B: LIST); 
(*Coloured polynomials list write. PL is a list of coloured polynomials.
If B = 0 the polynomial list is written on the output stream.
If B = 1 the polynomials and the red and white monomials are
written on the output stream. *)


PROCEDURE FINDCP(TTERM,WHITE: LIST): LIST; 
(*Find white factors. TTERM is a term, WHITE is a list of pairs,
containing a white coloured term and his list of white coloured
factors of the coefficient. If white contains tterm, CP is the list of
TTERM and the white factors. else CP is empty. *)


PROCEDURE FINDBC(RE,POL: LIST): LIST; 
(*Find base coefficient. RE is a term. POL is a polynomial, where
RE is one of the terms of POL. PA is the base coefficient of RE in
POL. *)


PROCEDURE FINDRM(RE,POL: LIST): LIST; 
(*Find monomial. RE is a term. POL is a polynomial, where
RE is one of the terms of POL. RPOL is the polynonomial, containing
only the monomial with RE in POL. *)


PROCEDURE CGBFRM(CGBL: LIST): LIST; 
(*Comprehensive-Groebner-Basis from coloured basis. CGBL is a list of
coloured polynomials. CGB is a list of the polynomials in CGBL
(without colours). *)


PROCEDURE MKPOL(PCO: LIST): LIST; 
(*Make polynomial without green monomials. PCO is a coloured polynomial.
PPOL is the polynomial without green monomials. If the polynomial is
completely coloured green, PPOL is empty. *)


PROCEDURE GREPOL(PL: LIST): LIST; 
(*Get polynomials without green monomials. PL is a list of coloured
polynomials. X is a list of the polynomials in PL without green
monomials. *)


PROCEDURE WMEMB(TTERM,WHITE: LIST): LIST; 
(*White term member. TTERM is a term, white is a list of pairs,
containing a white coloured term and his list of white coloured
factors of the coefficient. SL=1 if white contains TTERM,
else SL=0. *)


PROCEDURE EQPLCL(ALIST,BLIST: LIST): LIST; 
(*Equal lists of coloured polynomials. ALIST and BLIST are lists
of coloured polynomials. SL = 1 if the polynomials in ALIST and BLIST
are the same. Else SL = 0. *)


PROCEDURE CGBLM(L1,L2: LIST): LIST; 
(*CGB coloured distributive polynomial list merge.
L1 and L2 are lists of coloured distributive polynomials in non decreasing
order.  The merger of L1 and L2 is returned. 
(This procedure is a modified version of DIPLM from DIPC.MOD which does
the same for - not coloured - distributive polynomials.)*)

PROCEDURE CGBLPM(A: LIST): LIST; 
(*CGB list merge. A is a list of couloured polynomials. B contains
the coloured polynomials in a in nondecreasing order wrt to their
colour. See DIPLPM. *)

PROCEDURE ADDCON(COEFL,COND: LIST): LIST;
(*Add to condition.
COEFL is a list of coefficients.
COND is a condition.
Returns a case distinction covering COND containing all possible cases
for COEFL *)


PROCEDURE INICOL(COND,PI: LIST): LIST; 
(*Initialize colour. COND is a condition. PI is a polynomial.
COL is the list of red terms and white terms ( with white part ) of PI wrt to
the condition. *)


PROCEDURE SETCOL(COND,COL: LIST): LIST; 
(*Set colour. COND is a condition. COL is a list of red terms and
white terms ( with white part) wrt another condition, such that COND is
a successor of this condition. COL is updated to COLS wrt COND. *)


PROCEDURE REDSRT(RALT,RNEU: LIST): LIST; 
(*Red terms sort. RNEU and RALT  are lists of terms in nondecreasing
order. CRED0 contains the terms of RALT and RNEU in nondecreasing
order. *)


PROCEDURE TESTHT(COL: LIST):LIST;
(*Test highest term. COL contains a list of red terms and a list of
white terms. CP contains the highest white term and its white part
if it is gt the highest red term. Else CP is empty. *)


PROCEDURE DETPOL(GA,PI,COL: LIST; VAR DLIST,CLIST: LIST); 
(*Determine polynomial. GA is a condition. PI is a polynomial. COL
contains the list of the red terms of PI and the list of the white
terms of PI wrt the condition. DLIST is a case distinction that covers
GA and determines PI. CLIST is a list of pairs each containing a
condition of DLIST and PI coloured wrt this condition. *)


PROCEDURE DET(CONDS,P: LIST; VAR DLIST,PPL: LIST); 
(*Determine list of polynomials. CONDS is a case distinction. P is a
list of polynomials. DLIST is a case distinction that covers CONDS and
determines P. PPL is a list of pairs each containing a condiotion of
DLIST and P coloured wrt this condition. *)


PROCEDURE VERIFY(D,CLIST: LIST): LIST; 
(*Verify conditions and polynomials. D is a case distinction with
the conditions c1,... ,cn. CLIST is a list of pairs each containg a
condition and a coloured polynomial. The structure of clist is
((c11,p1),... ,(cn1,p1), (c12,p2),... ,(cn2,p2), (c1m,pm),... (cnm,pm)).
p1,... ,pm are coloured polynomials wrt cij. ci is a successor of cij
and cim=ci for i=1; n, j=1; m. The structure of the result is
q((c1,(p11,... ,p1m)),... , (c2,(p21,... ,p2m)),... , (cn,(pn1,... ,pnm))),
where (pi1,... ,pim) is a permutation of (p1,... ,pm), so that the polynomials
are in nondecreasing order wrt the condition pi for i=1; n. *)


PROCEDURE AINB(ALIST,BLIST: LIST): LIST; 
(*A in B. ALIST and BLIST  are  lists of coefficients.
SL eq 1 if all elements of ALIST are in BLIST. Else SL eq 0. *)

END CGBFUNC.

(* -EOF- *)
