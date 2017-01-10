(* ----------------------------------------------------------------------------
 * $Id: MLDEMO.mi,v 1.5 1995/11/04 18:00:25 pesch Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: MLDEMO.mi,v $
 * Revision 1.5  1995/11/04 18:00:25  pesch
 * Changed comments violating documentation rules. Should be rewritten.
 *
 * Revision 1.4  1994/11/28  21:04:11  dolzmann
 * New revision of the MASLOG system: New functions and bug fixes of old one.
 *
 * Revision 1.3  1993/12/17  17:15:37  dolzmann
 * Additional input procedures are added.
 *
 * Revision 1.2  1993/10/03  18:28:04  dolzmann
 * New version of procedure FORMKVD
 *
 * Revision 1.1  1993/07/13  14:44:08  dolzmann
 * The maslog-system and a simple example.
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MLDEMO;
(* Maslog Demonstration Implementation Module. *)

(******************************************************************************
*		   M A S L O G   D E M O N S T R A T I O N		      *
*-----------------------------------------------------------------------------*
* Author:   Andreas Dolzmann                                                  *
* Language: Modula II (mtc or mocka are possible)                             *
* System:   Program for the computer algebra system MAS by Heinz Kredel.      *
* Project:  MASLOG
* Remark:   This module requires the MASLOG-System.                           *
* Abstract: This module implements a primitive application for the MASLOG-    *
*           System.                                                           *
******************************************************************************)

FROM MASELEM	IMPORT	GAMMAINT;
FROM MASSTOR	IMPORT	ADV, COMP, FIRST, INV, LIST, LIST1, LISTVAR, RED,
			SIL;
FROM MASERR	IMPORT	ERROR, confusion, fatal, harmless, severe, spotless;
FROM MASLISPU	IMPORT	Declare, PROCF1, PROCP1;
FROM MASBIOS	IMPORT	BKSP, BLINES, CREAD, CREADB, DIBUFF, DIGIT, LETTER,
			LISTS, SWRITE;
FROM MASSYM	IMPORT	ATOM, UWRIT1, UWRITE;
FROM MASSYM2	IMPORT	ACOMP, ASSOCQ, ENTER, SYMBOL, SYWRIT;
FROM SACLIST	IMPORT	ADV2, AREAD, AWRITE, CCONC, CINV, CLOUT, CONC,
			LIST10, LIST2, LIST3, LIST4, LIST5;
			
FROM MLOGBASE	IMPORT	ANY, BOOL, EQUIV, ET, EXIST, FALSUM, FORALL,
			FORGARGS, FORGLVAR, FORGOP, FORISBOOLVAR, FORISLVAR,
			FORISVAR, FORMKBINOP, FORMKCNST, FORMKFOR, FORMKLVAR,
			FORMKQUANT, FORMKUNOP, FORMKVAR, FORPARGS, FORPBINOP,
			FORPBINOPA, FORPFOR, FORPLVAR, FORPQUANT, FORPQUANTA,
			FORPUNOP, FORPUNOPA, FORPVAR, FORPVARA, FORTST, IMP,
			NON, REP, TVAR, VEL, VERUM, XOR;
FROM MASLOG	IMPORT	FORAPPLYAT, FORCONTBDVAR, FORCONTVAR, FORMKCNF,
			FORMKDNF, FORMKPOS, FORMKPRENEX, FORMKVD, FORPREPQE,
			FORSMPL, FORSUBSTVAR;
FROM MLOGIO	IMPORT	FORIREAD, FORPPRT, FORPPVAR, FORPREAD, FORRDVAR,
			FORTEXW, KEYREAD;

CONST rcsidi = "$Id: MLDEMO.mi,v 1.5 1995/11/04 18:00:25 pesch Exp $";
CONST copyrighti = "Copyright (c) 1993 Universitaet Passau";

VAR BbfParserSyms: LIST;

(******************************************************************************
*  I M P L E M E N T A T I O N   O F   T H E   A T O M I C   F O R M U L A S  *
******************************************************************************)

PROCEDURE MLDMKATOM(rel,left,right:LIST):LIST;
(* maslog demonstration make atomic formula. rel is the relation symbol
(either EQU or NEQ), left and right are beta integers or variables. The
formula (left rel right) is returned. *)
BEGIN
	RETURN LIST3(rel,left,right);
END MLDMKATOM;


(******************************************************************************
*		   L O W   L E V E L   P R O C E D U R E S		      *
******************************************************************************)

PROCEDURE mldbbtst(l: LIST): BOOLEAN;
(* maslog demonstration black-box test. l is a list; mldbbtst returns true if
and only if l represents a bb-objekt. bb-objekts are lists of the form
(REL,a,b), where REL is an element of the set {EQU,NEQ} and a, b are either a
variable (represented as in MASLOG) or an atom. For program tests mldbbtst
accepts additionally all lists of the form (KEY,...), where KEY is an
arbitrary keyword but is not of the EQU or NEQ.  These lists have not any
interpretation. *)
	VAR op, arg1, arg2, red: LIST;
BEGIN
	IF l = SIL THEN RETURN FALSE; END;
	IF SYMBOL(l) OR ATOM(l) THEN RETURN FALSE; END;
	ADV(l,op,red);
	IF NOT SYMBOL(op) THEN RETURN FALSE; END;
	IF (ACOMP(op,EQU)=0) OR (ACOMP(op,NEQ)=0)
	THEN
		IF (red = SIL) OR (RED(red) = SIL) THEN RETURN FALSE; END;
		ADV2(red,arg1,arg2,red);
		IF red <> SIL THEN RETURN FALSE; END;
		IF (NOT ATOM(arg1) AND NOT FORISVAR(arg1)) OR
			NOT ATOM(arg2) AND NOT FORISVAR(arg2)
		THEN
			RETURN FALSE;
		ELSE
			RETURN TRUE;
		END;
	ELSE
		RETURN TRUE; (* change to FALSE, if you will avoid the
				acception of (KEY,...) as a bb-formula. *)
	END;
END mldbbtst;

PROCEDURE mldbbpprt(phi: LIST);
(* maslog demonstration black-box pretty print. phi is a bb-formula; writes
phi formated in the output stream. *)
	VAR op, red, arg1, arg2, dummy: LIST;
BEGIN
	ADV(phi,op,red);
	IF (op=EQU) OR (op=NEQ)
	THEN
		ADV2(red,arg1,arg2,dummy);
		SWRITE("[");
		IF FORISVAR(arg1) THEN 
			FORPPVAR(arg1);
		ELSE 
			 UWRIT1(arg1);
		END;
		bbpprtop(op);
		IF FORISVAR(arg2) THEN 
			FORPPVAR(arg2);
		ELSE
			UWRIT1(arg2);
		END;
		SWRITE("]");
	ELSE
		SWRITE("[");
		UWRIT1(phi);
		SWRITE("]");
	END;
END mldbbpprt;

PROCEDURE bbpprtop(op: LIST);
(* black box pretty print operator. op is a symbol of the set {EQU, NEQ};
writes op in the output stream. *)
BEGIN
	IF (op=EQU)	THEN SWRITE("=");	RETURN; END;
	IF (op=NEQ)	THEN SWRITE("<>");	RETURN; END;
END bbpprtop;

PROCEDURE mldbbtexw(phi: LIST);
(* maslog demonstration black-box tex write. phi is bb-formula; writes phi in
tex style in the output stream. *)
	VAR op, red, arg1, arg2, dummy: LIST;
BEGIN
	ADV(phi,op,red);
	IF (op=EQU) OR (op=NEQ)
	THEN
	BLINES(0);
		ADV2(red,arg1,arg2,dummy);
		SWRITE("(");
		SWRITE("\mbox{\tt ");
		UWRIT1(arg1);
		SWRITE("}");
		bbtexwop(op);
		SWRITE("\mbox{\tt ");
		UWRIT1(arg2);
		SWRITE("}");
		SWRITE(")");
	ELSE
	BLINES(0);
		SWRITE("\mbox{\tt ");
		UWRIT1(phi);
		SWRITE("}");
	END;
END mldbbtexw;

PROCEDURE bbtexwop(op: LIST);
(* black-box tex write operator. op is a element of the set {EQU,NEQ}; writes
op in tex stye in the output stream. *)
BEGIN
	IF (op=EQU)	THEN SWRITE("=");	RETURN; END;
	IF (op=NEQ)	THEN SWRITE("\neq");	RETURN; END;
END bbtexwop;

PROCEDURE mldbbmkneg(phi: LIST): LIST;
(* maslog demonstration black-box make negation. phi is a bb-formula; the
negation of phi is returned. Remark: You can always move the negation inside
an atomic formular. *)
	VAR op, res:LIST;
BEGIN
	ADV(phi,op,res);
	IF op=EQU THEN RETURN CCONC(LIST1(NEQ),res);
	ELSIF op=NEQ THEN RETURN CCONC(LIST1(EQU),res);
	ELSE RETURN FORMKUNOP(NON,phi);
	END;
END mldbbmkneg;

PROCEDURE mldbbsmpl(phi: LIST): LIST;
(* maslog demonstration black-box simplify. phi is a bb-formula; returns a
simplification of phi. *)
	VAR op,res, a, b, dummy: LIST;
BEGIN
	IF phi=SIL THEN RETURN SIL; END;
	ADV(phi,op,res);
	IF (op=NEQ) OR (op=EQU)
	THEN
		ADV2(res,a,b,dummy);
		IF ATOM(a) AND ATOM(b)
		THEN
			IF (op=EQU) AND (a=b)
			THEN
				RETURN FORMKCNST(VERUM);
			ELSIF (op=EQU) AND (a<>b)
			THEN
				RETURN FORMKCNST(FALSUM);
			ELSIF (op=NEQ) AND (a<>b)
			THEN
				RETURN FORMKCNST(VERUM);
			ELSE (* (op=NEQ) AND (a=b) *)
				RETURN FORMKCNST(FALSUM)
			END;
		ELSE
			RETURN phi;
		END;
	ELSE
		RETURN phi;
	END;
END mldbbsmpl;

PROCEDURE mldbbsubstvar(phi, old, new:LIST):LIST;
(* maslog demonstration black-box substitute variable. phi is a bb-formula,
old and new are variables.  mldsubstvar returns a formula in which all
occurences of old are substituted with new. *)
	VAR op, res, a, b, dummy, aname, asort, bname, bsort,
		oname, osort: LIST;
BEGIN
	ADV(phi,op,res);
	IF (op=EQU) OR (op=NEQ)
	THEN
		ADV2(res,a,b,dummy);
		FORPVAR(old,oname,osort);
		IF NOT ATOM(a)
		THEN
			FORPVAR(a,aname,asort);
			IF (aname=oname) AND (asort=osort)
			THEN
				a:=new;
			END;
		END;
		IF NOT ATOM(b)
		THEN
			FORPVAR(b,bname,bsort);
			IF (bname=oname) AND (bsort=osort)
			THEN
				b:=new;
			END;
		END;
		RETURN LIST3(op,a,b);
	ELSE
		RETURN phi;
	END;
END mldbbsubstvar;

PROCEDURE mldbbcontvar(phi,var:LIST):BOOLEAN;
(* maslog demonstration black-box contains variable. phi is a bb-formula, var
is a variable; mldbbcontvar returns true if and only if phi contains var. *)
	VAR op, res, a, b, dummy: LIST;
BEGIN
	ADV(phi,op,res);
	IF (op=EQU) OR (op=NEQ)
	THEN
		ADV2(res,a,b,dummy);
		IF (a=var) OR (b=var) THEN RETURN TRUE; ELSE RETURN FALSE; END;
	ELSE
		RETURN FALSE;
	END;
END mldbbcontvar;

PROCEDURE mldbblsvars(phi:LIST):LIST;
(* maslog demonstration black-box list variables. phi is a bb-formula;
a list of all variables in phi is returned. *)
	VAR op, lhs, rhs, red, dummy,result: LIST;
BEGIN
	result:=SIL;
	ADV(phi,op,red);
	IF (op=EQU) OR (op=NEQ) THEN
		ADV2(red,lhs,rhs,dummy);
		IF FORISVAR(lhs) THEN 
			result:=COMP(lhs,result);
		END;
		IF FORISVAR(rhs) THEN
			result:=COMP(rhs,result);
		END;
		RETURN result;
	ELSE
		RETURN SIL;
	END;
END mldbblsvars;

PROCEDURE mldbbread():LIST;
(* maslog demonstration black-box read. a bb-formula is read from the 
inputstream. *)
	VAR c:GAMMAINT;
	VAR result:LIST;
	VAR lhs,rhs,rel,sym:LIST;
BEGIN
	lhs:=readarg();
(* SWRITE("lhs");UWRIT1(lhs);BLINES(0); *)
	rel:=KEYREAD();
(* SWRITE("rel");CLOUT(rel);BLINES(0); *)
	sym:=ASSOCQ(rel,BbfParserSyms);
	IF sym=SIL THEN
		DIBUFF();
		ERROR(severe,"unknown relation");
		RETURN SIL;
	ELSE
		sym:=FIRST(sym);
	END;
	rhs:=readarg();
(* SWRITE("rhs");UWRIT1(rhs);BLINES(0); *)
	RETURN MLDMKATOM(sym,lhs,rhs);
END mldbbread;

PROCEDURE readarg():LIST;
(* read argument. A argument of a relation is read from the inputstream. *)
	VAR c: GAMMAINT;
	VAR result:LIST;
BEGIN
	c:=CREADB();
	IF LETTER(c) THEN
		BKSP();
		result:=FORRDVAR();
		RETURN result;
	ELSIF DIGIT(c) THEN
		BKSP;
		result:=AREAD();
		RETURN result;
	ELSE
		DIBUFF();
		ERROR(severe,"ATOM or SYMBOL expected");
		RETURN SIL;
	END;
END readarg;

PROCEDURE InitBbfParser();
(* Initialize black-box formula parser. *)
BEGIN
	BbfParserSyms:=SIL;
	LISTVAR(BbfParserSyms);
	BbfParserSyms:=LIST4(LISTS("<>"),NEQ,LISTS("="),EQU);
	RETURN;
END InitBbfParser;

PROCEDURE apply(phi:LIST):LIST;
(* apply. phi is a list; phi is returned and written in the outputstream. *)
BEGIN
	UWRITE(phi);
	RETURN phi;
END apply;


(******************************************************************************
*		  H I G H   L E V E L   P R O C E D U R E S		      *
******************************************************************************)

PROCEDURE MLDTST(l: LIST):LIST;
(* maslog demonstration test 1. l is a list; MLDTST returns 1 if l represents
a formula otherwise 0. *)
BEGIN
	IF FORTST(l,mldbbtst)
	THEN
		RETURN LIST(1);
	ELSE
		RETURN LIST(0);
	END;
END MLDTST;

PROCEDURE MLDMKPOS(phi: LIST): LIST;
(* maslog demonstration make positive.  phi is a formula; a formula equivalent
to phi, which is relative positive, is returned. Relative positive means that
negations are only in front of atomic formulas. *)
BEGIN
	RETURN FORMKPOS(phi,NON,mldbbmkneg);
END MLDMKPOS;

PROCEDURE MLDMKPOS1(phi, pref: LIST): LIST;
(* maslog demonstration make positive 1.  phi is a formula; pref is a symbol
of the set \{ET, VEL, NON\}; a formula equivalent to phi, which is relative
positive, is returned. Relative positive means that negations are only in
front of atomic formulas. pref is a switch that controls the substitution of
the operators IMP, REP, EQUIV, XOR.*)
BEGIN
	RETURN FORMKPOS(phi,pref,mldbbmkneg);
END MLDMKPOS1;

PROCEDURE MLDMKDNF(phi: LIST): LIST;
(* maslog demonstration make disjunctive normal form. phi is a formula;
MLMKDNF returns a formula in strict disjunctive normal form which is
equivalent to phi.  *)
BEGIN
	RETURN FORMKDNF(phi,mldbbmkneg);
END MLDMKDNF;

PROCEDURE MLDMKCNF(phi: LIST): LIST;
(* maslog demonstration make disjunctive normal form. phi is a formula;
MLDMKCNF returns a formula in strict conjunctive normal form which is
equivalent to phi. *)
BEGIN
	RETURN FORMKCNF(phi,mldbbmkneg);
END MLDMKCNF;

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
BEGIN
	RETURN FORMKPRENEX(phi,pref);
END MLDMKPRENEX;

PROCEDURE MLDSUBSTVAR(phi,old,new:LIST):LIST;
(* maslog demonstration substitute variables.  phi is a formula; old and new
are variables; a formula in which the variable old is substituted by the
variable new is returned. *)
BEGIN
	RETURN FORSUBSTVAR(phi,old,new,mldbbsubstvar);
END MLDSUBSTVAR;

PROCEDURE MLDMKVD(phi: LIST):LIST;
(* maslog demonstration make variables disjoint.  formula is a formula, this
procedure returns a formula in which all bound variables of the same sort
have different names.  Only the minimal number of renamings are done to make
the names different.*)
BEGIN
	RETURN FORMKVD(phi,mldbbsubstvar,mldbblsvars);
END MLDMKVD;

PROCEDURE MLDSMPL(phi: LIST): LIST;
(* maslog demonstration simplify.  phi is a formula; a formula phi1 equivalent
to phi is returned. The formula phi1 is simplified, that means the constants
VERUM and FALSUM are eliminated, and nested operators are eliminated. (In this
case the procedure takes advantage of associativity of ET and VEL, and the
idempotenz of NON. *)
BEGIN
	RETURN FORSMPL(phi,mldbbsmpl,mldbbmkneg);
END MLDSMPL;

PROCEDURE MLDPREPQE(phi: LIST):LIST;
(* maslog demonstration prepare quantifier elimination.  phi is a prenex
formu\-la; a formula psi equivalent to phi is returned. psi is built according
to the following rules: If the innermost block of quantifiers is an
exist-quantifier, then matrix(phi) is transformed in CNF and the innermost
block of quantifiers is moved inside the conjunction. If the innermost
quantifier is a forall-quantifier, then matrix(phi) is transformed in DNF and
the innermost block of quantifiers is moved inside the disjunction.*)
BEGIN
	RETURN FORPREPQE(phi,mldbbmkneg);
END MLDPREPQE;

PROCEDURE MLDAPPLYAT(phi:LIST):LIST;
(* maslog demonstration apply to atomic formulas. phi is a formula; the
formula phi is returned and all atomic formulas are written in the outout
stream. *)
BEGIN
	RETURN FORAPPLYAT(phi,apply);
END MLDAPPLYAT;

PROCEDURE MLDPPRT(phi: LIST);
(* maslog demonstration pretty print. phi is a formula; this procedure writes
the formula phi formated in the output stream. *)
BEGIN
	FORPPRT(phi, mldbbpprt);
	RETURN;
END MLDPPRT;

PROCEDURE MLDTEXW(phi: LIST);
(* maslog demonstration tex write. phi is a formula; this procedure writes phi
in tex style in the output stream. *)
BEGIN
	FORTEXW(phi, mldbbtexw);
	RETURN
END MLDTEXW;

PROCEDURE MLDCONTVAR(phi,var:LIST):LIST;
(* maslog demonstration contain variable. phi is a formula, var is a variable;
1 is returned, if phi contains var as an unbound variable, otherwise 0 is
returned. *)
BEGIN
	IF FORCONTVAR(phi,var,mldbbcontvar)
	THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END;
END MLDCONTVAR;

PROCEDURE MLDCONTBDVAR(phi,var:LIST):LIST;
(* maslog demonstration contains bound variable. phi is a formula, var is a
variable; 1 is returned, if phi contains var as bound variable, otherwise 0
is returned. *)
BEGIN
	IF FORCONTBDVAR(phi,var)
	THEN
		RETURN LIST(1);
	ELSE
		RETURN LIST(0);
	END;
END MLDCONTBDVAR;

PROCEDURE MLDPREAD():LIST;
BEGIN
	RETURN FORPREAD(mldbbread);
END MLDPREAD;

PROCEDURE MLDIREAD():LIST;
BEGIN
	RETURN FORIREAD(mldbbread);
END MLDIREAD;

BEGIN (* OF INITIALIZATION *)
	Declare(EQU,"EQU");
	Declare(NEQ,"NEQ");
	InitBbfParser();
END MLDEMO.

(* -EOF- *)
