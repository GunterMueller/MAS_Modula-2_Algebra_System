(* ----------------------------------------------------------------------------
 * $Id: MLDEMO.md,v 1.5 1995/11/04 18:00:23 pesch Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: MLDEMO.md,v $
 * Revision 1.5  1995/11/04 18:00:23  pesch
 * Changed comments violating documentation rules. Should be rewritten.
 *
 * Revision 1.4  1994/11/28  21:04:10  dolzmann
 * New revision of the MASLOG system: New functions and bug fixes of old one.
 *
 * Revision 1.3  1993/12/17  17:15:35  dolzmann
 * Additional input procedures are added.
 *
 * Revision 1.2  1993/10/03  18:28:04  dolzmann
 * New version of procedure FORMKVD
 *
 * Revision 1.1  1993/07/13  14:44:07  dolzmann
 * The maslog-system and a simple example.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MLDEMO;
(* Maslog Demonstration Definition Module. *)

(******************************************************************************
*		   M A S L O G    D E M O N S T R A T I O N		      *
*-----------------------------------------------------------------------------*
* Author:   Andreas Dolzmann                                                  *
* Language: Modula II (mtc or mocka are possible)                             *
* System:   Program for the computer algebra system MAS by Heinz Kredel.      *
* Project:  MASLOG                                                            *
* Remark:   Library maslog is used.                                           *
* Abstract: This is a example for MASLOG.                                     *
******************************************************************************)

FROM MASSTOR	IMPORT	LIST;
FROM MASLISPU	IMPORT	PROCF1, PROCP1;

CONST rcsid = "$Id: MLDEMO.md,v 1.5 1995/11/04 18:00:23 pesch Exp $";
CONST copyright = "Copyright (c) 1993 Universitaet Passau";

VAR EQU, NEQ: LIST;


(******************************************************************************
*  I M P L E M E N T A T I O N   O F   T H E   A T O M I C   F O R M U L A S  *
******************************************************************************)

PROCEDURE MLDMKATOM(rel,left,right:LIST):LIST;
(* maslog demonstration make atomic formula. rel is the relation symbol
(either EQU or NEQ), left and right are beta integers or variables. The
formula (left rel right) is returned. *)


(******************************************************************************
*		  H I G H   L E V E L   P R O C E D U R E S		      *
******************************************************************************)

PROCEDURE MLDTST(l: LIST):LIST;
(* maslog demonstration test 1. l is a list; MLDTST returns 1 if l represents
a formula otherwise 0. *)

PROCEDURE MLDMKPOS(phi: LIST): LIST;
(* maslog demonstration make positive.  phi is a formula; a formula equivalent
to phi, which is relative positive, is returned. Relative positive means that
negations are only in front of atomic formulas. *)

PROCEDURE MLDMKPOS1(phi, pref: LIST): LIST;
(* maslog demonstration make positive 1.  phi is a formula; pref is a symbol
of the set \{ET, VEL, NON\}; a formula equivalent to phi, which is relative
positive, is returned. Relative positive means that negations are only in
front of atomic formulas. pref is a switch that controls the substitution of
the operators IMP, REP, EQUIV, XOR.*)

PROCEDURE MLDMKDNF(phi: LIST): LIST;
(* maslog demonstration make disjunctive normal form. phi is a formula;
MLMKDNF returns a formula in strict disjunctive normal form which is
equivalent to phi.  *)

PROCEDURE MLDMKCNF(phi: LIST): LIST;
(* maslog demonstration make disjunctive normal form. phi is a formula;
MLDMKCNF returns a formula in strict conjunctive normal form which is
equivalent to phi. *)

PROCEDURE MLDMKPRENEX(phi, pref: LIST): LIST;
(* maslog demonstration make prenex.  phi is a formula; pref is an element of
\{EXIST, FORALL\}; a formula psi in prenex normal form is returned.  phi must
be a relative positive formula without additional operation symbols like IMP,
REP, etc. All bound variables in phi must have different specifications
(i.e. different names or different types).  The only transformation which is
used to calculate psi is the interchange of a junctor with a quantifier.  The
formula psi has the minimal number of blocks of quantifiers under all prenex
formulas which are built using only the interchange of a junctor with an
quantifier.  The argument pref is only respected, if there are two equivalent
formulas with the same optimal number of blocks of quantifiers.  In this case
the formula is returned which has a "`pref"'-quantifier as the outermost
operation symbol.*)

PROCEDURE MLDSUBSTVAR(phi,old,new:LIST):LIST;
(* maslog demonstration substitute variables.  phi is a formula; old and new
are variables; a formula in which the variable old is substituted by the
variable new is returned. *)

PROCEDURE MLDMKVD(phi: LIST):LIST;
(* maslog demonstration make variables disjoint.  formula is a formula, this
procedure returns a formula in which all bound variables of the same sort
have different names.  Only the minimal number of renamings are done to make
the names different.*)

PROCEDURE MLDSMPL(phi: LIST): LIST;
(* maslog demonstration simplify.  phi is a formula; a formula phi1 equivalent
to phi is returned. The formula phi1 is simplified, that means the constants
VERUM and FALSUM are eliminated, and nested operators are eliminated. (In this
case the procedure takes advantage of associativity of ET and VEL, and the
idempotenz of NON. *)

PROCEDURE MLDPREPQE(phi: LIST):LIST;
(* maslog demonstration prepare quantifier elimination.  phi is a prenex
formu\-la; a formula psi equivalent to phi is returned. psi is built according
to the following rules: If the innermost block of quantifiers is an
exist-quantifier, then matrix(phi) is transformed in CNF and the innermost
block of quantifiers is moved inside the conjunction. If the innermost
quantifier is a forall-quantifier, then matrix(phi) is transformed in DNF and
the innermost block of quantifiers is moved inside the disjunction.*)

PROCEDURE MLDAPPLYAT(phi:LIST):LIST;
(* maslog demonstration apply to atomic formulas. phi is a formula; the
formula phi is returned and all atomic formulas are written in the outout
stream. *)

PROCEDURE MLDPPRT(phi: LIST);
(* maslog demonstration pretty print. phi is a formula; this procedure writes
the formula phi formated in the output stream. *)

PROCEDURE MLDTEXW(phi: LIST);
(* maslog demonstration tex write. phi is a formula; this procedure writes phi
in tex style in the output stream. *)

PROCEDURE MLDCONTVAR(phi,var:LIST):LIST;
(* maslog demonstration contain variable. phi is a formula, var is a variable;
1 is returned, if phi contains var as an unbound variable, otherwise 0 is
returned. *)

PROCEDURE MLDCONTBDVAR(phi,var:LIST):LIST;
(* maslog demonstration contains bound variable. phi is a formula, var is a
variable; 1 is returned, if phi contains var as bound variable, otherwise 0
is returned. *)

PROCEDURE MLDPREAD():LIST;
(* maslog demonstration prefix read. A formula is read from the input 
stream. *)

PROCEDURE MLDIREAD():LIST;
(* maslog demonstration infix read. A formula is read from the input 
stream. *)

END MLDEMO.

(* -EOF- *)
