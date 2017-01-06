(* ----------------------------------------------------------------------------
 * $Id: CGBAPPL.md,v 1.5 1996/06/08 16:47:03 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1996 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: CGBAPPL.md,v $
 * Revision 1.5  1996/06/08 16:47:03  pesch
 * Reformatted, removed obsolete procedures.
 *
 * Revision 1.4  1994/04/09  18:05:50  pesch
 * Reformatted parts of the CGB sources. Updated comments in CGB*.md.
 *
 * Revision 1.3  1994/03/11  15:58:05  pesch
 * Major changes to CGB.
 * C-Preprocessor now used for .mip files. The corresponding .mi files have
 * been removed.
 * Many new CGB-Functions and fixes of old ones.
 *
 * Revision 1.2  1992/02/12  17:31:12  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:08:52  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE CGBAPPL;

(* Comprehensive-Groebner-Bases Applications Definition Module. *)


FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: CGBAPPL.md,v 1.5 1996/06/08 16:47:03 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1996 Universitaet Passau";


PROCEDURE GTEST(C,P: LIST; VAR C0,C1: LIST); 
(*Groebner-Test. C is a condition and P is a list of polynomials.
PAR is a parameter for the factorization of coefficients.
GTEST verifies, whether P is a comprehensive-groebner-basis wrt C.
C0 contains the conditions so that P is no groebner basis.
C1 contains the conditions so that P is a groebner basis. *)


PROCEDURE GBHELP(COND,PPAIRS,P: LIST; VAR C0,C1: LIST); 
(*Groebner test help. COND is a condition. PPAIRS is the polynomial
pairs list of P. P is a list of determined and coloured polynomials
relative to COND. PAR is a parameter for the factorization of
coefficients. 
C0 contains the successors of COND so that p is no groebner basis.
C1 contains the successors of COND so that p is a groebner basis. *)


PROCEDURE NSET(NN0,NN1,CC0,CC1: LIST; VAR C0,C1: LIST); 
(*Normalform set.
NN0 is a set of tripels (ga,pco,c), where ga is a condition,
pco is a normalform determined and coloured completely green by ga
and c is a multiplicative factor.
NN1 is a set of tripels (ga,pco,c), where ga is a condition,
pco is a normalform determined and not coloured completely green by ga
and c is a multiplicative factor.
CC0 and CC1 are lists of conditions.
The conditions in NN0, that are not in CC1, are added to CC0.
The conditions in NN1 are added to CC1. *)


PROCEDURE WRTEST(C,PP,CGB0,CGB1: LIST); 
(*Write groebner test. C is a condition. PP is a list of polynomials.
CGB0 contains the successors of C so that p is no groebner basis.
CGB1 contains the successors of C so that p is a groebner basis.
The conditions are written on the output stream. *)


PROCEDURE CPART(COND,CONDS: LIST): LIST; 
(*Condition part. COND is a condition. CONDS is a list of conditions.
SL=1 if COND is a member of CNDS or a successor of a condition in
CONDS. SL=0 else. *)


(* obsolete *) PROCEDURE CGBQUA(PP: LIST); 
(*Comprehensive-Groebner-Basis quantifier free formula. PP is a list
of coloured polynomials. The quantifier free formular epsilon is
written on the output stream. *)


PROCEDURE MCOEF(PCO: LIST; VAR COEFLI,COEF,TL: LIST); 
(*Make coefficient list. PCO is a coloured polynomial.
COEFLI is the list of red and white coefficients in PCO, so that the
degree of the terms in PCO is not zero.
COEF=() if exists no monomial in PCO  whose coefficient is coloured
white and whose term is of deg zero or exists a monomial in PCO whose
coefficient is coloured green and whose term has degree zero.
COEF=0 if exists a monomial in PCO  whose coefficient is coloured
red and whose term is of deg zero.
Else coef is the white coefficient in PCO whose term is of deg zero.
TL = 1 if exists a red coloured coefficient whose term has
degree > 0. Else TL = 0 *)


PROCEDURE NFEXEC(C,PPS,PP: LIST; VAR NOUT: LIST); 
(*Parametric ideal membership exec. C is a condition. PPS is a list
of polynomials to be tested. PP is a list of polynomials forming a
comprehensive-groebner-basis. PAR is a parameter for the factorization
of coefficients.
NOUT is a list containing each polynomial of PPS and the conditions
and normalforms so that it is a member of the ideal and those so that
it is no member of the ideal. *)


PROCEDURE WRQFN0(N0: LIST); 
(*Write quantifier free formula for parametric ideal membership.
N0 is a list of tripel (cond,pco,c), where cond is a condition,
pco is a normalform coloured completely green by cond
and c is a multiplicative factor.
The formula is written on the output stream. *)


PROCEDURE DIMEXE(GS,V: LIST): LIST; 
(*Parametric dimension exec. GS is a groebner-system. V is the
variables list. For each element of the groebner-system the dimension
is computed. DIML is a list of conditions and dimensions. *)


PROCEDURE INTDIM(V,PP: LIST): LIST; 
(*See intdim of dip. V is the variables list. PP is a list of
polynomials. DL is the dimension of PP. *)


PROCEDURE WRDIMS(DIML: LIST); 
(*Write dimension. DIML is a list of conditions and dimensions.
The quantifier free formula for parametric dimension is written on
the output stream. *)


PROCEDURE WRCONJ(CONDS: LIST); 
(*Write conjunction. CONDS is a list of conditions. The conjunction
over all conditions is written on the output stream. *)


END CGBAPPL.
(* -EOF- *)
