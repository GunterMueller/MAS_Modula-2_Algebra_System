(* ----------------------------------------------------------------------------
 * $Id: CGBDSTR.md,v 1.9 1996/06/08 16:47:06 pesch Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1992-1996 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: CGBDSTR.md,v $
 * Revision 1.9  1996/06/08 16:47:06  pesch
 * Reformatted, removed obsolete procedures.
 *
 * Revision 1.8  1995/12/16 13:54:48  kredel
 * Comments slightly edited.
 *
 * Revision 1.7  1995/03/23  16:05:41  pesch
 * Added new data structure Colp for coloured polynomials.
 *
 * Revision 1.6  1994/04/09  18:05:53  pesch
 * Reformatted parts of the CGB sources. Updated comments in CGB*.md.
 *
 * Revision 1.5  1994/03/14  16:42:52  pesch
 * Minor changes requested by A. Dolzmann
 *
 * Revision 1.4  1994/03/11  15:58:08  pesch
 * Major changes to CGB.
 * C-Preprocessor now used for .mip files. The corresponding .mi files have
 * been removed.
 * Many new CGB-Functions and fixes of old ones.
 *
 * Revision 1.3  1993/05/11  10:34:30  kredel
 * Added comments
 *
 * Revision 1.2  1993/04/15  13:14:19  kredel
 * Further corrections by Pesch
 *
 * Revision 1.1  1993/03/17  11:43:18  kredel
 * Initial Revision, added by Pesch.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE CGBDSTR;

(* Comprehensive-Groebner-Bases Data-Structures Definition Module. *)

FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: CGBDSTR.md,v 1.9 1996/06/08 16:47:06 pesch Exp $";
CONST copyright = "Copyright (c) 1992-1996 Universitaet Passau";

(******************************************************************************
Data-Structure: Conditions (Cond)
=================================

A condition contains information (=0, <>0, unknown) on coefficients. 
A conditions is implemented as a list containing two lists of coefficients:
((P_1, ..., P_i), (Q_1, ..., Q_j)) where P_l=0 and Q_k<>0.
The empty condition is ((), ()).
******************************************************************************)

PROCEDURE CondZero(Cond: LIST): LIST;
(* Condition zero part.
Cond is a condition.
Returns the list of coefficients =0 in Cond.*)

PROCEDURE CondNzero(Cond: LIST): LIST;
(* Condition non-zero part.
Cond is a condition.
Returns the list of coefficients <>0 in Cond.*)

PROCEDURE CondParts(Cond: LIST; VAR C0, C1:LIST);
(* Condition parts.
Cond is a condition.
C0,C1 need not be initialized.
Returns the list of coefficients =0 from Cond in C0 and 
the list of coefficients <>0 from Cond in C1 *)

PROCEDURE CondCons(C0, C1:LIST):LIST;
(* Condition construct.
C0, C1 are lists of coefficients.
Returns a condition where the coefficients from C0 are =0 and
the coefficients from C1 are <>0. *)

PROCEDURE CondIsEmpty(Cond: LIST): BOOLEAN;
(* Condition is empty.
Cond is a condition.
Returns true iff Cond is the empty condition. *)

PROCEDURE CondEmpty():LIST;
(* Condition empty.
Returns the empty condition. *)

PROCEDURE CondRead(VD: LIST): LIST;
(* Condition read.
VD is a list containing a variable list and a domain descriptor.
Returns a condition read from the input stream. *)

PROCEDURE CondPRead(VD, B: LIST): LIST;
(* Condition part read.
VD is a list containing a variable list and a domain descriptor.
Returns a condition part read from the input stream. *)

PROCEDURE CondWrite(Cond: LIST); 
(* Condition write.
Cond is a condition, which is written to the output stream. *)

PROCEDURE FormFCond(Cond: LIST; VAR VD: LIST): LIST;
(* Formula from Condition.
Cond is a condition.
DOM and VARL need not be initialized.
Returns a formula "equivalent" to Cond and its variable list and
domain descriptor in VD. *)

(*****************************************************************************
Data-Structure: Colouring (Col).
================================

A colouring contains information (=0 (green), <>0 (red), unknown (white))
about monomials of a polynomial and the unknown factors of an unknown
coefficient.
A colouring is implemented as a list containing two lists: (CRED, CWHITE).
CRED is a sorted list of red terms.
CWHITE=((T_1, (F_1_1, ..., F_1_n)), ..., (T_m, (F_m_1, ..., F_m_n))) is
a list sorted by T_i, where T_i are white terms, and F_i_j are white
factors of the coefficient of T_i.
The empty colouring is ((), ()).
******************************************************************************)

PROCEDURE ColRed(Col: LIST): LIST;
(* Colouring red.
Col is a Colouring.
Returns a list of red terms in Col. *)

PROCEDURE ColWhite(Col: LIST): LIST;
(* Colouring white.
Col is a Colouring.
Returns a list of white terms with white factors in Col. *)

PROCEDURE ColParts(Col: LIST; VAR R, W:LIST);
(* Colouring parts.
Col is a Colouring.
R, W need not be initialized.
Returns a list of red terms from Col in R and
a list of white terms with white factors in W. *)

PROCEDURE ColCons(R, W: LIST): LIST;
(* Colouring construct.
R is a (possibly empty) list of red terms.
W is a (possibly empty) list of white terms.
Returns a colouring constructed from R an W. *)

PROCEDURE ColConsCond(POL,COND: LIST): LIST;
(* Colouring construct from condition.
POL is a polynomial.
COND is a condition.
Returns a colouring of POL according to COND. *)

PROCEDURE ColIsEmpty(Col: LIST): BOOLEAN;
(* Colouring is empty.
Col is a Colouring.
Returns true iff Col is the empty Colouring. *)

PROCEDURE ColEmpty(): LIST;
(* Colouring empty.
Returns the empty Colouring. *)

PROCEDURE ColHT (COL: LIST): LIST;
(* Colouring head term.
COL is a colouring.
If the highest non-zero (red) term is greater then the highest unknown (white)
term returns the highest non-zero term else returns SIL. *)

(*****************************************************************************
Data-Structure: Coloured polynomial (Colp)
==========================================

A coloured polynomial contains a a polynomial and information about the
colouring (=0,<>0,unknown) of its monomials.
A coloured polynomial is implemented as a list (POL,COL) containing
a distributive polynomial over the domain IP and a colouring (Col).
******************************************************************************)

PROCEDURE ColpCons (POL,COL: LIST): LIST;
(* Coloured polynomial construct.
POL is a polynomial.
COL is a colouring.
Returns a Colp built from POL and COL.*)

PROCEDURE ColpConsCond(POL,COND: LIST): LIST;
(* Coloured polynomial construct from condition.
POL is a polynomial.
COND is a condition.
Returns a Colp by colouring POL according to COND. *)

PROCEDURE ColpPol(COLP: LIST): LIST;
(* Coloured polynomial polynomial part.
COLP is a coloured polynomial.
Returns the polynomial in Colp. *)

PROCEDURE ColpCol(COLP: LIST): LIST;
(* Coloured polynomial colouring part.
COLP is a coloured polynomial.
Returns the colouring of COLP. *)

PROCEDURE ColpParts(COLP: LIST; VAR POL,COL: LIST);
(* Coloured polynomial parts.
COLP is a coloured polynomial.
POL, COL need not be initialized.
Returns the polynomial from COLP in POL and the colouring from COLP in COL.*)

PROCEDURE ColpIsCnst(COLP: LIST): BOOLEAN;
(* Coloured polynomial is (non zero) constant.
COLP is a coloured polynomial
Returns TRUE iff COLP is constant (i.e. its degree is 0) and non zero wrt.
to its colouring *)

PROCEDURE ColpHT (COLP: LIST): LIST;
(* Coloured polynomial head term.
COLP is a coloured polynomial.
If the head term of COLP is determined by its colouring (i.e. the
highest non-zero (red) term is greater then the highest unknown (white)
term) returns the head term else returns SIL. *)

PROCEDURE ColpIsZero (COLP: LIST): BOOLEAN;
(* Coloured polynomial is zero.
COLP is a coloured polynomial.
Returns TRUE iff all terms of COLP are zero (green) wrt. its colouring. *)

(*****************************************************************************
Data-Structure: Case distinction (Cd)
=====================================

A case distinction is implemented as a list containing conditions.
-to do-: complete
******************************************************************************)

PROCEDURE CdRead(VD: LIST): LIST;
(* Case distinction read.
VD is a variable list and a domain descriptor.
Returns a case distinction read from the input stream. *)

PROCEDURE CdWrite(CD: LIST); 
(*Case distinction write.
CD is a case distinction which is written to the output stream. *)

(*****************************************************************************
Data-Structure: Case distinction and polynomial set (Cdp)
=========================================================

A case distinction and polynomial set is implemented as a list containing
three elements: (CD,PL,VD) where CD is a case distinction, PL is a
list of polynomials and VD is a variable list and domain descriptor for PL.
******************************************************************************)

PROCEDURE CdpCons(CD,PL,VD: LIST): LIST;
(* Case distinction and polynomial set construct.
CD is a case distinction.
PL is a list of Polynomials.
VD is a varable list and domain descriptor for PL.
Returns a CDP built from CD,PL,VD.*)

PROCEDURE CdpParts(CDP: LIST; VAR CD,PL,VD: LIST);
(* Case distinction and polynomial set parts.
CDP is a case distinction and polynomial set.
Returns the case distinction from CDP in CD, the polynomial set from CDP
in PL and the variable list and domain descriptor from CDP in VD. *)

PROCEDURE CdpCd(CDP: LIST): LIST;
(* Case distinction and polynomial set case distinction part.
CDP is a case distinction and polynomial set.
Returns the case distinction from CDP. *)

PROCEDURE CdpPs(CDP: LIST): LIST;
(* Case distinction and polynomial set polynomial set part.
CDP is a case distinction and polynomial set.
Returns the polynomial set from CDP. *)

PROCEDURE CdpVd(CDP: LIST): LIST;
(* Case distinction and polynomial set variable list and domain descriptor 
part.
CDP is a case distinction and polynomial set.
Returns the variable list and domain descriptor from CDP. *)

PROCEDURE CdpRead():LIST; 
(*Case distinction and polynomial set read.
Returns a case distinction and polynomial set read from the input stream.*)

PROCEDURE CdpWrite(CDP: LIST);
(*Case distinction and polynomial set write.
CDP is a case distinction and polynomial set.
Writes CDP to the output-stream.*)

PROCEDURE RDSYS(VD: LIST): LIST; 
(*Read polynomial systems.
VD is a variable list and domain descriptor.
PPS is a list of two polynomial systems read from the input stream. *)
(* -to do-: get rid of this procedure! -- mp *)

(*****************************************************************************
Data-Structure: Groebner system (Gs)
====================================

A Groebner System  is implemented as a list containing three lists:
(S,VD,CD) where S is a list containing the Groebner system, VD is
a variable list and domain descriptor for S and CD is the initial
case distinction.
******************************************************************************)

PROCEDURE GsCons(S,VD,CD: LIST): LIST;
(* Groebner system construct.
S is a Groebner system,
VD its variables list and domain descriptor and
CD the initial case distinction
Returns the Groebner system constructed from S, VD and CD *)

PROCEDURE GsS(GS: LIST): LIST;
(* Groebner system system part.
GS is a Groebner system.
Returns the system part of GS *)

PROCEDURE GsVd(GS: LIST): LIST;
(* Groebner system variable list and domain descriptor.
GS is a Groebner system.
Returns the variable list and domain descriptor for GS. *)

PROCEDURE GsCd(GS: LIST): LIST;
(* Groebner system initial case distinction.
GS is a Groebner system.
Returns the initial case distinction for GS. *)

PROCEDURE GsParts(GS: LIST; VAR S,VD,CD: LIST);
(* Groebner system parts.
S and VD need not be initialized.
Returns the system part of GS in S, the variable list and domain
descriptor for GS in VD and the initial case distinction in CD. *)

PROCEDURE GsWrite(GS: LIST);
(* Groebner system write.
GS is a Groebner system which is written to the output stream. *)

(******************************************************************************
Data-Structure: Comprehensive Groebner basis (Cgb)
==================================================

A Comprehensive Groebner basis is implemented as a list containing four
elements: (CGB,I,VD,CD) where CD is the CGB (a list of polynomials),
I is the number of conditions, VD is the variable list and domain descriptor
and CD is the initial case distinction.
******************************************************************************)

PROCEDURE CgbCons(CGB,I,VD,CD: LIST): LIST;
(* Groebner system construct.
CGB is a list of polynomials,
I is an Integer, the number of conditions,
VD its variables list and domain descriptor and
CD the initial case distinction
Returns the comprehensive Groebner basis constructed from CGB, I, VD and CD *)

PROCEDURE CgbP(CGB: LIST): LIST;
(* Comprehensive Groebner basis polynomial list part.
CGB is a comprehensive Groebner basis
Returns the polynomial list part of CGB *)

PROCEDURE CgbI(CGB: LIST): LIST;
(* Comprehensive Groebner basis number of conditions part.
CGB is a comprehensive Groebner basis
Returns the number of conditions part of CGB *)

PROCEDURE CgbVd(CGB: LIST): LIST;
(* Comprehensive Groebner basis variable list and domain descriptor.
CGB is a Comprehensive Groebner basis.
Returns the variable list and domain descriptor for CGB. *)

PROCEDURE CgbCd(CGB: LIST): LIST;
(* Groebner system initial case distinction.
CGB is a Comprehensive Groebner basis.
Returns the initial case distinction for CGB. *)

PROCEDURE CgbParts(CGB: LIST; VAR P,I,VD,CD: LIST);
(* Comprehensive Groebner basis parts.
P, I, VD and CD need not be initialized.
Returns the polynomial list part of CGB in P, the number of conditions
in I,  the variable list and domain
descriptor for CGB in VD and the initial case distinction in CD. *)

PROCEDURE CgbWrite(CGB: LIST);
(* Comprehensive Groebner basis write.
CGB is a comprehensive Groebner basis which is written to the output stream
*)


(******************************************************************************
Data-Structure: Formula and dimension (Fd)
==========================================

A formula and dimension implemented as a list (D, F, V) containing
three elements: a formula F an integer D and a variable list V.
(D is first (instead of F) because of problems with the interpreter.)
******************************************************************************)

PROCEDURE FdCons(F,D,V: LIST): LIST;
(* Formula and dimension construct.
F is a formula.
D is an integer.
Returns the Fd constructed from F and D. *)

PROCEDURE FdParts(FD: LIST; VAR F,D,V: LIST);
(* Formula and dimension parts.
FD is a formula and dimension.
F, D and V need not be initialized.
Returns the formula from FD in F, the dimension in D and the variable
list in V. *)

PROCEDURE FdF(FD: LIST): LIST;
(* Formula and dimension formula part.
FD is a formula and dimension.
Returns the formula part from FD*)

PROCEDURE FdD(FD: LIST): LIST;
(* Formula and dimension formula part.
FD is a formula and dimension.
Returns the dimension part from FD*)

PROCEDURE FdV(FD: LIST): LIST;
(* Formula and dimension variable list part.
FD is a formula and dimension.
Returns the variable list part from FD*)

PROCEDURE FdWrite(FD: LIST);
(* Formula and dimension write.
FD is a formula and dimension, which is written to the output stream.
PQPRING must be called prior to calling FdWrite to set domain descriptor
and variable list. *)
(* --- to do ---: this must change!!! *)

(******************************************************************************
Data-Structure: Parametric dimension (Pd)
=========================================

A parametric dimension implemented as a list containing
two elements: a list of formulas and dimensions and the appropriate
variable list and domain descriptor.
******************************************************************************)

PROCEDURE PdCons(F,VD: LIST): LIST;
(* Parametric dimension construct.
F is a formula.
VD is the variable list and domain descriptor for F.
Returns the Pd constructed from F and V. *)

PROCEDURE PdParts(PD: LIST; VAR F,VD: LIST);
(* Parametric dimension parts.
Pd is a parametric dimension.
F and V need not be initialized.
Returns the formula from PD in F and the variable list and domain descriptor
in V. *)

PROCEDURE PdF(PD: LIST): LIST;
(* Parametric dimension formula and dimension list part.
PD is a parametric dimension.
Returns the formula and dimension list from PD. *)

PROCEDURE PdVd(PD: LIST): LIST;
(* Parametric dimension variable list and domain descriptor part.
PD is a Parametric dimension.
Returns the dimension from PD. *)

PROCEDURE PdWrite(PD: LIST);
(* Parametric dimension write.
PD is a Parametric dimension, which is written to the output stream.
 *)
     

(******************************************************************************
Data-Structure: Variable list and domain descriptor (Vd)
========================================================

A Variable list and domain descriptor is implemented as a list containing
two elements: the variable list and the domain descriptor.
******************************************************************************)

PROCEDURE VdCons(V,D: LIST): LIST;
(* Variable list and domain descriptor construct.
V is a variable list.
D is a domain descriptor.
Returns the VD constructed from V and D. *)

PROCEDURE VdV(Vd: LIST): LIST;
(* Variable list and domain descriptor variable list part.
Vd is a variable list and domain descriptor.
Returns the variable list from Vd. *)

PROCEDURE VdD(Vd: LIST): LIST;
(* Variable list and domain descriptor domain descriptor part.
Vd is a variable list and domain descriptor.
Returns the domain descriptor from Vd. *)

PROCEDURE VdParts(Vd: LIST; VAR V,D: LIST);
(* Variable list and domain descriptor parts.
Vd is a variable list and domain descriptor.
Returns the variable list from Vd in V and the domain descriptor in D. *)

PROCEDURE VdRead(): LIST; 
(*Variable list and domain descriptor read.
Returns a variable list and domain descriptor read from the input stream.*)

END CGBDSTR.
(* -EOF- *)
