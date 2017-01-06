(* ----------------------------------------------------------------------------
 * $Id: PQBASE.md,v 1.1 1994/11/28 21:10:01 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1994 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: PQBASE.md,v $
 * Revision 1.1  1994/11/28  21:10:01  dolzmann
 * New modules PQBASE.md and PQBASE.mi:
 *   Procedures for the manipulating first oder formulas over the language of
 *   ordered rings.
 * New modules RQEPRRC.md and RQEPRRC.mi:
 *   Procedures for the real quantifier elimination.
 * New modules TFORM.md and TFORM.mi:
 *   Procedures for the computation of type formulas.
 * Makefile adapted.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE PQBASE;
(* Polynomial Equation Base Definition Module. *)

(******************************************************************************
*			     P Q B A S E				      *
*-----------------------------------------------------------------------------*
* Author:   Andreas Dolzmann                                                  *
* Language: Modula II                                                         *
* System:   This program is written for the computer algebra system MAS by    *
*           Heinz Kredel.                                                     *
* Abstract: Implementation of the language of ordered fields. The             *
*           implementation use distributive polynomials over an arbitrary     *
*           domain for the representation of terms.                           *
******************************************************************************)

FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: PQBASE.md,v 1.1 1994/11/28 21:10:01 dolzmann Exp $";
CONST copyright = "Copyright (c) 1994 Universitaet Passau";

(******************************************************************************
*                       G L O B A L   V A R I A B L E S                       *
******************************************************************************)

VAR  EQU, NEQ, GRE, LES, GRQ, LSQ: LIST; (* Relations =, #, >, <, >=, <= *)
VAR PQSAF: LIST ;
	(* symbol to mark a polynomial equation special atomic formula *)
VAR DOMAIN: LIST;


PROCEDURE vlistflvar(lvar:LIST):LIST;
(* variable list from lvar. lvar is a LVAR object. A variable list in the 
format of the module DIPC representing the same list of 
variables is returned. *)

PROCEDURE lvarfvlist(vlist:LIST):LIST;
(* lvar from variable list. vlist is a variable list in the format of the 
DIPC-module. A LVAR object representing the same variable list is returned. *)

PROCEDURE pqmkaf(rel:LIST;pol:LIST):LIST;
(* polynomial equation simplification make atomic formula.
rel is a relation, pol is a
polynomial, the atomic formula (rel,id) is returned. *)

PROCEDURE pqpaf(af:LIST; VAR rel,pol:LIST);
(* polynomial equation simplification parse atomic formula. af is an atomic
formula; the relation symbol of af is in rel returned; the polynomial of af
is in id returned. *)

PROCEDURE pqgrel(af:LIST):LIST;
(* polynomial equation get relation symbol. af is an atomic formula. The 
relation symbol of af is returned. *)

PROCEDURE pqgpol(af:LIST):LIST;
(* polynomial equation get polynomial. af is an atomic formula. The 
polynomial of af is returned. *)

PROCEDURE pqatom(phi:LIST):BOOLEAN;
(* polynomial equation atomic formula. pqatom returns true
iff phi has the structure of an atomic formula, i.e. phi is a list 
with two elements, and the first element of the list is an valid
relation symbol. *)

PROCEDURE pqprtaf(af: LIST);
(* polynomial equation simplification print atomic formula. The atomic formula
af is printed.
*)

PROCEDURE pqtexwaf(af: LIST);
(* polynomia equation tex write atomic formula. The atomic formula af 
is written to the output stream. *)

PROCEDURE pqnegaf(af: LIST):LIST;
(* negate atomic formula. af is a atomic formula. The negation of af is
returned. *)

PROCEDURE pqsimplifyaf(af:LIST):LIST;
(* polynomial equation simplify atomic formula. af is an atomic formula. 
af is simplified and af the result is returned. Only the relations between 
a constant polynomial (and zero) are evaluated. Be careful: Use only
polynomials over an domain with a proper ADSIGN function. 
(For example: RN, but not RF.) *)

PROCEDURE pqreadaf():LIST;
(* polynomial equation read atomic formula. An atomic formula is read from
the input stream. The global variable DOMAIN must be set.
Atomic fomulas have the following syntax: "<dilp> <rel> <dip>",
where dip are distributive polynomials over an arbitrary domain 
with the variable list VALIS and rel is one of the sympols 
<,=,>,>=,<>,<=,#,LES,EQU,GRE,LSQ,NEQ,GRQ,LEQ,GEQ. *)

PROCEDURE InitBbfParser();
(* Initialize black-box formula parser. *)

PROCEDURE pqsmart(phi:LIST):LIST;
(* polynomial equation atomic formula smart simplification. 
phi is a conjunction or a disjunction over atomic formulas. 
All atomic formulas with identical left hand sides are contracted to 
one atomic formula. A conjunction or a disjunction over these contraced
formulas is returned. *)

PROCEDURE ContractVel(l:LIST):LIST;
(* contract vel. l is a list of atomic formulas. These atomic formulas are 
interpreted as arguments of a disjunction. The relations of atomic formulas 
with equal left hand sides are contracted. *)

PROCEDURE PQCRELOR(left,right:LIST):LIST;
(* contract relations or. left and right are relations, the contraction of
left an right are returned. (this procedure works correct, even if left=SIL.)
*)

PROCEDURE ContractEt(l:LIST):LIST;
(* contract vel. l is a list of atomic formulas. These atomic formulas are 
interpreted
as arguments of a disjunction. The relations of atomic formulas with equal
identifiers are contracted. *)

PROCEDURE PQCRELAND(left,right:LIST):LIST;
(* contract relations or. left and right are relations, the contraction of
left an right are returned. (this procedure works correct, even if left=SIL.)
*)

(******************************************************************************
*                       M A S L O G   I N T E R F A C E                       *
******************************************************************************)

PROCEDURE PQMKDNF(phi:LIST):LIST;
(* polynomial equation make disjunctive normal form. phi is a formula;
MLMKDNF returns a formula in strict disjunctive normal form which is
equivalent to phi.  *)

PROCEDURE PQMKCNF(phi:LIST):LIST;
(* polynomial equation make disjunctive normal form. phi is a formula;
a formula in strict conjunctive normal form which is
equivalent to phi is returned. *)

PROCEDURE PQSMPL(phi:LIST):LIST;
(* polynomial equation simplify. phi is a formula; a simplification on
phi is returned. *)

PROCEDURE PQSIMPLIFY(phi:LIST):LIST;
(* polynomial equation simplify. phi is a formula. A simplification of 
phi is returned. Following simplification steps are done:
1. VERUM and FALSUM are eliminated 
2. assoziative simplification
3. idempotenz
*)

PROCEDURE PQSIMPLIFYP(phi,maxlevel:LIST):LIST;
(* polynomial equation simplify. phi is a formula. A simplification of 
phi is returned. Following simplification steps are done:
1. VERUM and FALSUM are eliminated 
2. assoziative simplification
3. idempotenz
maxlevel is the number of levels that are simplified. 
*)

PROCEDURE PQMKPOS(phi: LIST): LIST;
(* polynomial equation make positive. phi is a formula; a equivalent positive 
formula is returned. *)

PROCEDURE PQPPRT(phi:LIST);
(* polynomial equation pretty print. phi is a formula; this procedure writes
the formula phi formatted in the output stream. *)

PROCEDURE PQTEXW(phi: LIST);
(* polynomial equation tex write. The formula phi is printed in tex format in
the output stream. *)

PROCEDURE PQPREAD():LIST;
(* polynomial equation read. *)

PROCEDURE PQIREAD():LIST;
(* polynomial equation infix read. *)

PROCEDURE PQELIMXOPS(phi: LIST):LIST;
(* polynomial equation  eliminate extended operation symbols. phi is 
formula, pref is a
symbol of the set \{VEL, ET, NON\}; FORELIMXOPS returns a formula phi1
equivalent to phi. If pref is NON then this function does nothing. Otherwise
this function replaces all subterms of phi with the operators IMP, REP, EQUIV
or XOR with terms with the operators VEL, ET and NON. There are two different
substitutions for EQUIV and XOR. If pref=ET (pref=VEL) then the outermost
operator of the replacement terms for EQUIV, XOR is ET (VEL). *)

PROCEDURE PQELIMXOPS1(phi,pref: LIST):LIST;
(* polynomial equation  eliminate extended operation symbols. phi is 
formula, pref is a
symbol of the set \{VEL, ET, NON\}; FORELIMXOPS returns a formula phi1
equivalent to phi. If pref is NON then this function does nothing. Otherwise
this function replaces all subterms of phi with the operators IMP, REP, EQUIV
or XOR with terms with the operators VEL, ET and NON. There are two different
substitutions for EQUIV and XOR. If pref=ET (pref=VEL) then the outermost
operator of the replacement terms for EQUIV, XOR is ET (VEL). *)

PROCEDURE PQMKPRENEX(phi,pref:LIST): LIST;
(* polynomial equation make prenex. 
phi is a formula; pref is an element of \{EXIST,
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

(******************************************************************************
*                                  P R I N G                                  *
******************************************************************************)

PROCEDURE PQPRING(R: LIST): LIST;
(* polynomial equation polynomial ring. The global variables that describe the
polynomial ring are set. The list R is of the following format: The first entry
is the domain descriptor of the field, the second entry is the list of the 
variables, and the third entry is the term order. You can omit an entry of R 
by writing a -1 on the place of the entry. Not all entries must specified. 
The old parameters are returned. *)

PROCEDURE PQPRINGWR();
(* polynomial equation polynomial ring write. The description of the polynomial
ring is written in the output stream. *)

PROCEDURE PQMKVD(phi:LIST): LIST;
(* polynomial equation make variable names disjoint. *)

END PQBASE.
(* -EOF- *)
