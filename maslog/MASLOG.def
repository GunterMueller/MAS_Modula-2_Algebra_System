(* ----------------------------------------------------------------------------
 * $Id: MASLOG.md,v 1.4 1994/11/28 21:03:59 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: MASLOG.md,v $
 * Revision 1.4  1994/11/28  21:03:59  dolzmann
 * New revision of the MASLOG system: New functions and bug fixes of old one.
 *
 * Revision 1.3  1993/12/17  17:12:07  dolzmann
 * MASLOG is divided into three parts. (MLOGBASE, MLOGIO, MASLOG)
 * Additional input procedures are added.
 *
 * Revision 1.2  1993/10/03  18:28:01  dolzmann
 * New version of procedure FORMKVD
 *
 * Revision 1.1  1993/07/13  14:44:05  dolzmann
 * The maslog-system and a simple example.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASLOG;
(* Maslog Definition Module. *)

(******************************************************************************
*				 M A S L O G				      *
*-----------------------------------------------------------------------------*
* Author:   Andreas Dolzmann                                                  *
* Language: MODULA II (mocka or mtc are possible.)                            *
* System:   Program for the computer algebra system MAS by Heinz Kredel.      *
* Project:  MASLOG							      *
* Remark:   Libraries maskern, maslisp are used.                              *
* Abstract: A package for the MAS computer algebra system by Heinz Kredel.    *
*           This package implements basic routins on formulas of the first    *
*           order predicate calculus.                                         *
******************************************************************************)

FROM MASSTOR	IMPORT	LIST;
FROM MASLISPU	IMPORT	PROCF0, PROCF1, PROCF2, PROCF3, PROCP1;
FROM MLOGBASE	IMPORT	PROCFB1, PROCFB2;


CONST rcsid = "$Id: MASLOG.md,v 1.4 1994/11/28 21:03:59 dolzmann Exp $";
CONST copyright = "Copyright (c) 1993 Universitaet Passau";


(******************************************************************************
*			  M A K E   P O S I T I V E			      *
******************************************************************************)

PROCEDURE FORMKPOS(phi, pref: LIST;bbmkneg:PROCF1):LIST;
(* formula make positive. phi is a formula; pref is a symbol of the set \{ET,
VEL, NON\}; bbmkneg is a bb-procedure to negate a bb-formula; a formula
equivalent to phi, which is relative positive, is returned.  Relative positive
means that negations are only in front of atomic formulas. pref is a switch
that controls the substitution of the operators IMP, REP, EQUIV, XOR. If
pref=NON then subformulas with IMP and REP are substituted, only if they are
negated, EQUIV and XOR are not substituted.  If pref=ET or pref=VEL then IMP
and REP are substituted every time.  If pref=ET (pref=VEL) then the outermost
operator of the replacement for EQUIV and XOR is an ET (a VEL) operator. *)


(******************************************************************************
*	    M A K E   D I S J U N C T I V E   N O R M A L F O R M	      *
******************************************************************************)

PROCEDURE FORMKDNF(phi: LIST; bbmkneg: PROCF1): LIST;
(* formula make dnf. phi is a quantifier-free formula, bbmkneg is a
bb-pro\-ce\-dure to negate a bb-formula; a formula phi1 equivalent to phi is
returned.  phi1 is in strict dnf. *)


(******************************************************************************
*	    M A K E   C O N J U N C T I V E   N O R M A L   F O R M           *
******************************************************************************)

PROCEDURE FORMKCNF(phi: LIST; bbmkneg: PROCF1): LIST;
(* formula make cnf. phi is a quantifier-free formula, bbmkneg is a
bb-pro\-ce\-dure to negate a bb-formula; a formula phi1 equivalent to phi is
returned.  phi1 is in strict cnf. *)


(******************************************************************************
*			    M A K E   P R E N E X			      *
******************************************************************************)

PROCEDURE FORMKPRENEX(phi,pref:LIST): LIST;
(* formula make prenex. phi is a formula; pref is an element of \{EXIST,
FORALL\}; a formula psi in prenex normal form is returned.  phi must be a
relative positive formula without additional operation symbols like IMP, REP,
etc.  All bound variables in phi must have different specifications (i.e.
different names or different types).  The only transformation which is used to
calculate psi is the interchange of a junctor with a quantifier.  The formula
psi has the minimal number of blocks of quantifiers under all prenex formulas
which are built using only the interchange of a junctor with a quantifier.
The argument pref is only respected, if there are two equivalent formulas with
the same optimal number of blocks of quantifiers.  In this case the formula is
returned which has a "pref"-quantifier as the outermost operation symbol.*)

PROCEDURE FORMKPRENEXI(phi,pref:LIST): LIST;
(* formula make prenex. phi is a formula; pref is an element of \{EXIST,
FORALL\}; a formula psi in prenex normal form is returned.  phi must be a
relative positive formula without additional operation symbols like IMP, REP,
etc.  All bound variables in phi must have different specifications (i.e.
different names or different types).  The only transformation which is used to
calculate psi is the interchange of a junctor with a quantifier.  The formula
psi has the minimal number of blocks of quantifiers under all prenex formulas
which are built using only the interchange of a junctor with a quantifier.
The argument pref is only respected, if there are two equivalent formulas with
the same optimal number of blocks of quantifiers.  In this case the formula is
returned which has a "pref"-quantifier as the innermost operation symbol.*)

PROCEDURE FORMKPRENEX1(phi: LIST): LIST;
(* formula make prenex 1. phi is a relative positive formula; this procedure
returns a list of maximal two objects of the form (psi,qb(psi)). In
(psi,qb(psi)) psi is a formula in prenex normal form, and qb(psi) the number
of blocks of quantifiers.  If there are two objects in the returned list, then
the outermost quantifier of the first formula is an exist quantifier and the
outermost quantifier of the second formula is a forall quantifier.  In the
following comments such a list is called pnf-selection. *)

PROCEDURE FORIMQB(phi: LIST):LIST;
(* formula innermost quantifier block. phi is a formula in prenex normal form.
If the outermost operator of phi is no quantifier then SIL is returned. 
Otherwise the type of the innermost quantifier block (either FOREX or FORALL) 
is returned. *)

(******************************************************************************
*		S U B S T I T U T E   V A R I A B L E                         *
******************************************************************************)

PROCEDURE FORSUBSTVAR(phi, old, new: LIST; bbsubstvar: PROCF3): LIST;
(* formula substitute variable. phi is a formula; old and new are variables; a
formula in which the variable old is substituted by the variable new is
returned. *)


(******************************************************************************
*	    M A K E   V A R I A B L E S   D I S J O I N T                     *
******************************************************************************)

PROCEDURE FORMKVD(formula:LIST; bbsubstvar:PROCF3;bblsvars:PROCF1): LIST;
(* formula make variable names disjoint. formula is a formula, bbsubstvar is a
bb-procedure to substitute variables in bb-formulas, bblsvars is a
bb-procedure to list all variables in a bb-formula; FORMKVD returns a formula
in which all bound variables of the same sort have different names. Only the
minimal number of renamings are done to make the names different. *)


(******************************************************************************
*			 S I M P L I F Y				      *
******************************************************************************)

PROCEDURE FORSMPL(phi: LIST; bbsmpl, bbmkneg: PROCF1): LIST;
(* formula simplify. phi is a formula, simplifybb is a bb-procedure to
simplify a bb-formula; bbmkneg is a bb-procedure to negate a bb-formula; a
formula phi1 equivalent to phi is returned. The formula phi1 is simplified,
that means the constants VERUM and FALSUM are eliminated, and nested operators
are eliminated. (In this case the procedure takes advantage of associativity
of ET and VEL, and the idempotenz of NON. *)

PROCEDURE FORSIMPLIFY(phi: LIST; smart: PROCF1; bbsmpl, bbmkneg: PROCF1):LIST;
(* formula simplify. phi is a formula, smart is a function
to do smart simplification on a list of atomic formulas. 
simplifybb is a bb-procedure to
simplify a bb-formula; bbmkneg is a bb-procedure to negate a bb-formula.
A simplification of phi is returned. *)

PROCEDURE FORSIMPLIFYP(phi,maxlevel: LIST;
	smart: PROCF1; bbsmpl, bbmkneg: PROCF1):LIST;
(* formula simplify prune. phi is a formula, level, maxlevel are atoms, 
smart is a function to do smart simplification on a list of atomic formulas. 
simplifybb is a bb-procedure to
simplify a bb-formula; bbmkneg is a bb-procedure to negate a bb-formula.
maxlevel defines the number of levels that are simplified, 1 means only 
the top-level, zero means simplify the hole tree.
A simplification of phi is returned. *)

(******************************************************************************
*	 P R E P A R E Q U A N T I F I E R E L I M I N A T I O N	      *
******************************************************************************)

PROCEDURE FORPREPQE(phi: LIST; bbmkneg: PROCF1):LIST;
(* formula prepare quantifier elimination. phi is a prenex formula; bbmkneg is
a bb-procedure to negate a bb-formula; a formula psi equivalent to phi is
returned. psi is built according to the following rules: If the innermost
block of quantifiers is an exist-quantifier, then matrix(phi) is transformed
in CNF and the innermost block of quantifiers is moved inside the conjunction.
If the innermost quantifier is a forall-quantifier, then matrix(phi) is
transformed in DNF and the innermost block of quantifiers is moved inside the
disjunction.*)


(******************************************************************************
*  E L I M I N A T E   E X T E N D E D   O P E R A T I O N   S Y M B O L S    *
******************************************************************************)

PROCEDURE FORELIMXOPS(phi :LIST; pref: LIST): LIST;
(* formula eliminate extended operation symbols. phi is formula, pref is a
symbol of the set \{VEL, ET, NON\}; FORELIMXOPS returns a formula phi1
equivalent to phi. If pref is NON then this function does nothing. Otherwise
this function replaces all subterms of phi with the operators IMP, REP, EQUIV
or XOR with terms with the operators VEL, ET and NON. There are two different
substitutions for EQUIV and XOR. If pref=ET (pref=VEL) then the outermost
operator of the replacement terms for EQUIV, XOR is ET (VEL). *)

(******************************************************************************
*                              F O R R E P A F S                              *
******************************************************************************)

PROCEDURE FORREPAFS(phi,rep:LIST):LIST;
(* formula replace atomic formulas. phi is a formula. rep is a 
assoc list of the form (old1,new1,old2,new2,...), where old1,... and
new1,.. are atomic formulas. Each occurence of oldi in phi is 
replaced with newi. *)


(******************************************************************************
*			  A P P L Y   T O   A T O M			      *
******************************************************************************)

PROCEDURE FORAPPLYAT(phi:LIST; dosomething:PROCF1): LIST;
(* formula apply to atomic formular. phi is a formula; a formular in which all
atomic formulas psi are substituted with dosomething(psi) is returned.  *)

PROCEDURE FORAPPLYATF2(phi,param1:LIST; dosomething:PROCF2): LIST;
(* formula apply to atomic formula f2. 
phi is a formula; param1 is an arbitrary list object,
a formula in which all atomic formulas psi are substituted with 
dosomething(psi,param1) is returned.  *)

(******************************************************************************
*                  C O U N T   A T O M I C   F O R M U L A S                  *
******************************************************************************)

PROCEDURE FORCOUNTAF(phi:LIST): LIST;
(* formula count atomic formulas. phi is a formula; 
The number of the atomic formulas in the formula phi is returned. *)


(******************************************************************************
*	        C O N T A I N S   B O U N D   V A R I A B L E		      *
******************************************************************************)

PROCEDURE FORCONTBDVAR(phi:LIST; svar: LIST): BOOLEAN;
(* formula contain bound variable. phi is a formula; var is a variable;
FORCONTBDVAR returns true, if and only if phi contains var as a bound
variable. *)


(******************************************************************************
*		      C O N T A I N S   V A R I A B L E			      *
******************************************************************************)

PROCEDURE FORCONTVAR(phi:LIST; svar: LIST; bbcontvar: PROCFB2): BOOLEAN;
(* formula contain variable. phi is a formula; var is a variable; bbcontvar is
a procedure, which tests whether a bb-formula contains a variable or not;
FORCONTVAR returns true, if and only if phi contains var as a free variable.
*)


END MASLOG.

(* -EOF- *)
