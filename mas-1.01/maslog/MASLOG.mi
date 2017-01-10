(* ----------------------------------------------------------------------------
 * $Id: MASLOG.mi,v 1.4 1994/11/28 21:04:08 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: MASLOG.mi,v $
 * Revision 1.4  1994/11/28  21:04:08  dolzmann
 * New revision of the MASLOG system: New functions and bug fixes of old one.
 *
 * Revision 1.3  1993/12/17  17:12:10  dolzmann
 * MASLOG is divided into three parts. (MLOGBASE, MLOGIO, MASLOG)
 * Additional input procedures are added.
 *
 * Revision 1.2  1993/10/03  18:28:02  dolzmann
 * New version of procedure FORMKVD
 *
 * Revision 1.1  1993/07/13  14:44:06  dolzmann
 * The maslog-system and a simple example.
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASLOG;
(* Maslog Implementation Module. *)

(******************************************************************************
*				 M A S L O G				      *
*-----------------------------------------------------------------------------*
* Author:   Andreas Dolzmann                                                  *
* Language: MODULA II (mocka or mtc are possible.)                            *
* System:   Program for the computer algebra system MAS by Heinz Kredel.      *
* Project:  MASLOG                                                            *
* Remark:   Libraries maskern, maslisp are used.                              *
* Abstract: A package for the MAS computer algebra system by Heinz Kredel.    *
*           This package implements basic routins on formulas of the first    *
*           order predicate calculus.                                         *
******************************************************************************)

FROM MASBIOS	IMPORT	BLINES, MASORD, SWRITE;
FROM MASELEM	IMPORT	MASREM;
FROM MASERR	IMPORT	ERROR, confusion, fatal, harmless, severe, spotless;
FROM MASLISPU	IMPORT	Declare, PROCF0, PROCF1, PROCF2, PROCF3, PROCP1;
FROM MASSET	IMPORT	SetAddQ, SetComplementQ;
FROM MASSTOR	IMPORT	ADV, COMP, FIRST, INV, LENGTH, LIST, LIST1, RED, SIL;
FROM MASSYM2	IMPORT	ASSOCQ, ENTER, EXPLOD, GENSYM, SREAD, UWRITE; 
FROM MLOGBASE	IMPORT	ANY, BOOL, EQUIV, ET, EXIST, FALSUM, FORALL,
			FORGARGS, FORGLVAR, FORGOP, FORISATOM, FORISBBFOR,
			FORISBOOLVAR, FORISLVAR, FORISVAR, FORMKBINOP,
			FORMKCNST, FORMKFOR, FORMKLVAR, FORMKQUANT,
			FORMKUNOP, FORMKVAR, FORPARGS, FORPBINOP, FORPBINOPA,
			FORPFOR, FORPLVAR, FORPQUANT, FORPQUANTA, FORPUNOP,
			FORPUNOPA, FORPVAR, FORPVARA, FORTST, FORVTENTER,
			FORVTGET, IMP, NON, PROCFB1, PROCFB2, REP, TVAR, VEL,
			VERUM, XOR; 
FROM SACLIST	IMPORT	ADV2, ADV3, AREAD, CCONC, CINV, COMP2, CONC, EQUAL,
			LIST10, LIST2, LIST3, LIST4, LIST5, MEMBER, SECOND,
			THIRD;
			
CONST rcsidi = "$Id: MASLOG.mi,v 1.4 1994/11/28 21:04:08 dolzmann Exp $";
CONST copyrighti = "Copyright (c) 1993 Universitaet Passau";


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
	VAR op, args, vars, formula, posformula, result, key: LIST;
	VAR arg1, arg2, posarg1, posarg2, nposarg1, nposarg2: LIST;
BEGIN
	IF phi = SIL THEN RETURN SIL; END;

	IF (pref<>VEL) AND (pref<>ET) AND (pref<>NON) THEN
		ERROR(severe,"FORMKPOS: wrong preference given (assume NON)");
		pref:=NON;
	END;
	FORPFOR(phi,op,args);
	IF (op=VERUM) OR (op=FALSUM) THEN
		RETURN phi;
	ELSIF op=NON THEN
		FORPUNOPA(args,formula);
		RETURN complement(formula,pref,bbmkneg);
	ELSIF (op=VEL) OR (op=ET) THEN
		result:=SIL;
		WHILE args <> SIL DO
			FORPARGS(args,formula,args);
			posformula:=FORMKPOS(formula,pref,bbmkneg);
			result:=COMP(posformula,result);
		END;
		RETURN FORMKFOR(op,INV(result));
	ELSIF (op=EXIST) OR (op=FORALL) THEN
		FORPQUANTA(args,vars,formula);
		posformula:=FORMKPOS(formula,pref,bbmkneg);
		RETURN FORMKQUANT(op,vars,posformula);
	ELSIF (op=IMP) AND (pref<>NON) THEN
		FORPBINOPA(args,arg1,arg2);
		RETURN FORMKBINOP(VEL,complement(arg1,pref,bbmkneg),
			FORMKPOS(arg2,pref,bbmkneg));
	ELSIF (op=IMP) AND (pref=NON) THEN
		FORPBINOPA(args,arg1,arg2);
		RETURN FORMKBINOP(IMP,FORMKPOS(arg1,pref,bbmkneg),
					FORMKPOS(arg2,pref,bbmkneg));
	ELSIF (op=REP) AND (pref<>NON) THEN
		FORPBINOPA(args,arg1,arg2);
		RETURN FORMKBINOP(VEL,FORMKPOS(arg1,pref,bbmkneg),
			complement(arg2,pref,bbmkneg));
	ELSIF (op=REP) AND (pref=NON) THEN
		FORPBINOPA(args,arg1,arg2);
		RETURN FORMKBINOP(REP,FORMKPOS(arg1,pref,bbmkneg),
					FORMKPOS(arg2,pref,bbmkneg));
	ELSIF (op=EQUIV) AND (pref<>NON) THEN
		FORPBINOPA(args,arg1,arg2);
		posarg1:=FORMKPOS(arg1,pref,bbmkneg);
		posarg2:=FORMKPOS(arg2,pref,bbmkneg);
		nposarg1:=complement(arg1,pref,bbmkneg);
		nposarg2:=complement(arg2,pref,bbmkneg);
		IF pref=ET THEN
			RETURN FORMKBINOP(ET,FORMKBINOP(VEL,nposarg1,posarg2),
				 FORMKBINOP(VEL,posarg1,nposarg2));
		ELSIF pref=VEL THEN
			RETURN FORMKBINOP(VEL,FORMKBINOP(ET,posarg1,posarg2),
				 FORMKBINOP(ET,nposarg1,nposarg2));
		END;
	ELSIF (op=EQUIV) AND (pref=NON) THEN
		FORPBINOPA(args,arg1,arg2);
		RETURN FORMKBINOP(EQUIV,
			FORMKPOS(arg1,pref,bbmkneg),
			FORMKPOS(arg2,pref,bbmkneg));
	ELSIF (op=XOR) AND (pref<>NON) THEN
		FORPBINOPA(args,arg1,arg2);
		posarg1:=FORMKPOS(arg1,pref,bbmkneg);
		posarg2:=FORMKPOS(arg2,pref,bbmkneg);
		nposarg1:=complement(arg1,pref,bbmkneg);
		nposarg2:=complement(arg2,pref,bbmkneg);
		IF pref=VEL THEN
			RETURN FORMKBINOP(VEL,FORMKBINOP(ET,posarg1,nposarg2),
				FORMKBINOP(ET,nposarg1,posarg2));
		ELSIF pref=ET THEN
			RETURN FORMKBINOP(ET,FORMKBINOP(VEL,posarg1,posarg2),
				 FORMKBINOP(VEL,nposarg1,nposarg2));
		END;
	ELSIF (op=XOR) AND (pref=NON) THEN
		FORPBINOPA(args,arg1,arg2);
		RETURN FORMKBINOP(XOR,
			FORMKPOS(arg1,pref,bbmkneg),
			FORMKPOS(arg2,pref,bbmkneg));
	ELSIF op=TVAR THEN
		RETURN phi;
	ELSE
		RETURN phi;
	END;
END FORMKPOS;

PROCEDURE complement(phi, pref: LIST; bbmkneg:PROCF1): LIST;
(* complement. like FORMKPOS, but supposes that phi is negated. *)
	VAR op,args,vars,formula,posformula,result: LIST;
	VAR arg1,arg2, posarg1, posarg2, nposarg1, nposarg2: LIST;
BEGIN
	IF phi = SIL THEN RETURN SIL; END;
	FORPFOR(phi,op,args);
	IF op=VERUM THEN
		RETURN FORMKCNST(FALSUM);
	ELSIF op=FALSUM THEN
		RETURN FORMKCNST(VERUM);
	ELSIF op=NON THEN
		FORPARGS(args,formula,args);
		RETURN FORMKPOS(formula,pref,bbmkneg);
	ELSIF (op=VEL) OR (op=ET) THEN
		result:=SIL;
		WHILE args <> SIL DO
			FORPARGS(args,formula,args);
			posformula:=complement(formula,pref,bbmkneg);
			result:=COMP(posformula,result);
		END;
		RETURN FORMKFOR(notsymbol(op),INV(result));
	ELSIF (op=EXIST) OR (op=FORALL) THEN
		FORPQUANTA(args,vars,formula);
		posformula:=complement(formula,pref,bbmkneg);
		RETURN FORMKQUANT(notsymbol(op),vars,posformula);
	ELSIF op=REP THEN
		FORPBINOPA(args,arg1,arg2);
		posarg1:=complement(arg1,pref,bbmkneg);
		posarg2:=FORMKPOS(arg2,pref,bbmkneg);
		RETURN FORMKBINOP(ET,posarg1,posarg2);
	ELSIF op=IMP THEN
		FORPBINOPA(args,arg1,arg2);
		posarg1:=FORMKPOS(arg1,pref,bbmkneg);
		posarg2:=complement(arg2,pref,bbmkneg);
		RETURN FORMKBINOP(ET,posarg1,posarg2);
	ELSIF (op=XOR) AND (pref<>NON) THEN
		FORPBINOPA(args,arg1,arg2);
		posarg1:=FORMKPOS(arg1,pref,bbmkneg);
		posarg2:=FORMKPOS(arg2,pref,bbmkneg);
		nposarg1:=complement(arg1,pref,bbmkneg);
		nposarg2:=complement(arg2,pref,bbmkneg);
		IF pref=ET THEN
			RETURN FORMKBINOP(ET,FORMKBINOP(VEL,posarg1,nposarg2),
				 FORMKBINOP(VEL,nposarg1,posarg2));
		ELSIF pref=VEL THEN
			RETURN FORMKBINOP(VEL,FORMKBINOP(ET,posarg1,posarg2),
				 FORMKBINOP(ET,nposarg1,nposarg2));
		END;
	ELSIF (op=XOR) AND (pref=NON) THEN
		FORPBINOPA(args,arg1,arg2);
		RETURN FORMKBINOP(EQUIV,
			FORMKPOS(arg1,pref,bbmkneg),
			FORMKPOS(arg2,pref,bbmkneg));
	ELSIF (op=EQUIV) AND (pref<>NON) THEN
		FORPBINOPA(args,arg1,arg2);
		posarg1:=FORMKPOS(arg1,pref,bbmkneg);
		posarg2:=FORMKPOS(arg2,pref,bbmkneg);
		nposarg1:=complement(arg1,pref,bbmkneg);
		nposarg2:=complement(arg2,pref,bbmkneg);
		IF pref=VEL THEN
			RETURN FORMKBINOP(VEL,FORMKBINOP(ET,posarg1,nposarg2),
				 FORMKBINOP(ET,nposarg1,posarg2));
		ELSIF pref=ET THEN
			RETURN FORMKBINOP(ET,FORMKBINOP(VEL,posarg1,posarg2),
				 FORMKBINOP(VEL,nposarg1,nposarg2));
		END;
	ELSIF (op=EQUIV) AND (pref=NON) THEN
		FORPBINOPA(args,arg1,arg2);
		RETURN FORMKBINOP(XOR,
			FORMKPOS(arg1,pref,bbmkneg),
			FORMKPOS(arg2,pref,bbmkneg));
	ELSIF op=TVAR THEN
		RETURN FORMKUNOP(NON,phi);
	ELSE
		RETURN bbmkneg(phi);
	END;
END complement;


(******************************************************************************
*	    M A K E   D I S J U N C T I V E   N O R M A L F O R M	      *
******************************************************************************)

PROCEDURE FORMKDNF(phi: LIST; bbmkneg: PROCF1): LIST;
(* formula make dnf. phi is a quantifier-free formula, bbmkneg is a
bb-pro\-ce\-dure to negate a bb-formula; a formula phi1 equivalent to phi is
returned.  phi1 is in strict dnf. *)
BEGIN
	RETURN FORMKDNF1(phi, bbmkneg, FALSE);
END FORMKDNF;

PROCEDURE FORMKDNF1(phi: LIST; bbmkneg: PROCF1; neg: BOOLEAN): LIST;
(* formula make postiv 1. phi is a quantifier-free formula; bbmkneg is a
bb-procedure to negate a bb-formula, neg is a flag that shows whether a
negation was read or not; FORMKDNF1 returns an equivalent formula in strict
dnf. *)
	VAR op, red, arg, arg1, arg2, dnfarg, result, opvel, psi, prednf: LIST;
BEGIN
	IF phi=SIL THEN RETURN SIL; END;

	FORPFOR(phi,op,red);
	IF (op=VERUM) OR (op=FALSUM) THEN
		IF neg 	THEN
			RETURN FORMKUNOP(VEL,
				FORMKUNOP(ET,notsymbol(phi)));
		ELSE
			RETURN FORMKUNOP(VEL,FORMKUNOP(ET,phi));
		END;
	ELSIF op=NON THEN
		FORPUNOPA(red,arg);
		RETURN FORMKDNF1(arg,bbmkneg,NOT neg);
	ELSIF ((op=VEL) AND (NOT neg)) OR ((op=ET) AND neg) (* VEL *) 	THEN
		(* transform all arguments in dnf and join all disjunctions *)
		result:=SIL;
		WHILE red <> SIL DO
			FORPARGS(red,arg,red);
			dnfarg:=FORMKDNF1(arg,bbmkneg,neg);
			FORPARGS(dnfarg,opvel,psi);
			result:=CCONC(result,psi);
		END;
		RETURN FORMKFOR(VEL,result);
	ELSIF ((op=ET) AND (NOT neg)) OR ((op=VEL) AND neg) (* ET *) THEN
		(* transform all arguments in dnf ... *)
		prednf:=SIL;
		WHILE red <> SIL DO
			FORPARGS(red,arg,red);
			prednf:=COMP(FORMKDNF1(arg,bbmkneg,neg),prednf);
		END;
		RETURN distribetovel(INV(prednf));
	ELSIF op=IMP THEN
		FORPBINOPA(red,arg1,arg2);
		RETURN FORMKDNF1(FORMKBINOP(VEL,FORMKUNOP(NON,arg1),arg2),
			bbmkneg,neg);
	ELSIF op=REP THEN
		FORPBINOPA(red,arg1,arg2);
		RETURN FORMKDNF1(FORMKBINOP(VEL,arg1,FORMKUNOP(NON,arg2)),
			bbmkneg,neg);
	ELSIF ((op=EQUIV) AND (NOT neg)) OR ((op=XOR) AND neg) THEN
		FORPBINOPA(red,arg1,arg2);
		RETURN FORMKDNF1(FORMKBINOP(VEL,
			FORMKBINOP(ET,
				FORMKUNOP(NON,arg1),FORMKUNOP(NON,arg2)),
			FORMKBINOP(ET,arg1,arg2)),bbmkneg,FALSE);
	ELSIF ((op=XOR) AND (NOT neg)) OR ((op=EQUIV) AND neg) THEN
		FORPBINOPA(red,arg1,arg2);
		RETURN FORMKDNF1(FORMKBINOP(VEL,
			FORMKBINOP(ET,arg1,FORMKUNOP(NON,arg2)),
			FORMKBINOP(ET,FORMKUNOP(NON,arg1),arg2)),
			bbmkneg,FALSE);
	ELSIF op=TVAR THEN
		IF neg THEN
			RETURN FORMKUNOP(VEL,FORMKUNOP(ET,FORMKUNOP(NON,phi)));
		ELSE
			RETURN FORMKUNOP(VEL,FORMKUNOP(ET,phi));
		END;
	ELSE
		IF neg THEN
			RETURN FORMKUNOP(VEL,
				FORMKUNOP(ET,bbmkneg(phi)));
		ELSE
			RETURN FORMKUNOP(VEL,FORMKUNOP(ET,phi));
		END;
	END;
END FORMKDNF1;

PROCEDURE distribetovel(L: LIST): LIST;
(* distributive et over vel. L is a list of boolean terms in strict dnf; a
boolean term t equivalent to ET(L) is returned. t is in strict dnf. *)
	VAR first, firstpt, tail, elem, redelem, obj, result, prefix: LIST;
	VAR dummy: LIST;
BEGIN
	IF L = SIL THEN RETURN SIL; END;

	FORPFOR(L,first,tail);
	IF tail = SIL THEN
		RETURN first;
	END;
	FORPARGS(first,dummy,first);
	WHILE tail <> SIL DO
		FORPARGS(tail,obj,tail);
		FORPARGS(obj,dummy,obj);
		result:=SIL;
		WHILE obj <> SIL DO
			FORPARGS(obj,elem,obj);
			redelem:=RED(elem);
			firstpt:=first;
			WHILE firstpt <> SIL DO
				FORPARGS(firstpt,prefix,firstpt);
				result:=COMP(CCONC(prefix,redelem),result);
			END;
		END;
		first:=result;
	END;
	result:=FORMKFOR(VEL,result);
	RETURN result;
END distribetovel;


(******************************************************************************
*	    M A K E   C O N J U N C T I V E   N O R M A L   F O R M           *
******************************************************************************)

PROCEDURE FORMKCNF(phi: LIST; bbmkneg: PROCF1): LIST;
(* formula make cnf. phi is a quantifier-free formula, bbmkneg is a
bb-pro\-ce\-dure to negate a bb-formula; a formula phi1 equivalent to phi is
returned.  phi1 is in strict cnf. *)
BEGIN
	RETURN FORMKCNF1(phi, bbmkneg, FALSE);
END FORMKCNF;

PROCEDURE FORMKCNF1(phi: LIST; bbmkneg: PROCF1; neg: BOOLEAN): LIST;
(* formula make cnf 1. phi is a quantifier-free formula, bbmkneg is a
bb-procedure to negate a bb-formula positive, neg is a flag, that shows
whether a negation was read or not; FORMKCNF1 returns an equivalent formula in
strict cnf. *)
	VAR op, red, arg, arg1, arg2, cnfarg, result, opet, psi, precnf: LIST;
BEGIN
	IF phi=SIL THEN RETURN SIL; END;

	FORPFOR(phi,op,red);
	IF (op=VERUM) OR (op=FALSUM) THEN
		IF neg 	THEN
			RETURN FORMKUNOP(ET,
				FORMKUNOP(VEL,notsymbol(op)));
		ELSE
			RETURN FORMKUNOP(ET,FORMKUNOP(VEL,phi));
		END;
	ELSIF op=NON THEN
		FORPUNOPA(red,arg);
		RETURN FORMKCNF1(arg,bbmkneg,NOT neg);
	ELSIF ((op=ET) AND (NOT neg)) OR ((op=VEL) AND neg)  (* op=ET *) THEN
		(* transform all arguments in cnf and join all disjunctions *)
		result:=SIL;
		WHILE red <> SIL DO
			FORPARGS(red,arg,red);
			cnfarg:=FORMKCNF1(arg,bbmkneg,neg);
			FORPARGS(cnfarg,opet,psi);
			result:=CCONC(result,psi);
		END;
		RETURN FORMKFOR(ET,result);
	ELSIF ((op=VEL) AND (NOT neg)) OR ((op=ET) AND neg)  (* op=VEL *) THEN
		(* transform all arguments in cnf ... *)
		precnf:=SIL;
		WHILE red <> SIL DO
			FORPARGS(red,arg,red);
			precnf:=COMP(FORMKCNF1(arg,bbmkneg,neg),precnf);
		END;
		RETURN distribveloet(INV(precnf));
	ELSIF op=IMP THEN
		FORPBINOPA(red,arg1,arg2);
		RETURN FORMKCNF1(FORMKBINOP(VEL,FORMKUNOP(NON,arg1),arg2),
			bbmkneg,neg);
	ELSIF op=REP THEN
		FORPBINOPA(red,arg1,arg2);
		RETURN FORMKCNF1(FORMKBINOP(VEL,arg1,FORMKUNOP(NON,arg2)),
			bbmkneg,neg);
	ELSIF ((op=XOR) AND (NOT neg)) OR ((op=EQUIV) AND neg) THEN
		FORPBINOPA(red,arg1,arg2);
		RETURN FORMKCNF1(FORMKBINOP(ET,
			FORMKBINOP(VEL,
				FORMKUNOP(NON,arg1),FORMKUNOP(NON,arg2)),
			FORMKBINOP(VEL,arg1,arg2)),bbmkneg,FALSE);
	ELSIF ((op=EQUIV) AND (NOT neg)) OR ((op=XOR) AND neg) THEN
		FORPBINOPA(red,arg1,arg2);
		RETURN FORMKCNF1(FORMKBINOP(ET,
			FORMKBINOP(VEL,arg1,FORMKUNOP(NON,arg2)),
			FORMKBINOP(VEL,FORMKUNOP(NON,arg1),arg2)),
			bbmkneg,FALSE);
	ELSIF op=TVAR THEN
		IF neg 	THEN
			RETURN FORMKUNOP(ET,FORMKUNOP(VEL,FORMKUNOP(NON,phi)));
		ELSE
			RETURN FORMKUNOP(ET,FORMKUNOP(VEL,phi));
		END;
	ELSE
		IF neg 	THEN
			RETURN FORMKUNOP(ET,
				FORMKUNOP(VEL,bbmkneg(phi)));
		ELSE
			RETURN FORMKUNOP(ET,FORMKUNOP(VEL,phi));
		END;
	END;
END FORMKCNF1;

PROCEDURE distribveloet(L: LIST): LIST;
(* distributive vel over et. L is a list of quantifier-free formulas in strict
cnf; a quantifier-free formula equivalent to VEL(L), which is in strict cnf,
is returned. *)
	VAR first, firstpt, tail, elem, redelem, obj, result, prefix: LIST;
	VAR dummy: LIST;
BEGIN
	IF L = SIL THEN RETURN SIL; END;

	FORPFOR(L,first,tail);
	IF tail = SIL THEN
		RETURN first;
	END;
	FORPARGS(first,dummy,first);
	WHILE tail <> SIL DO
		FORPARGS(tail,obj,tail);
		FORPARGS(obj,dummy,obj);
		result:=SIL;
		WHILE obj <> SIL DO
			FORPARGS(obj,elem,obj);
			redelem:=RED(elem);
			firstpt:=first;
			WHILE firstpt <> SIL DO
				FORPARGS(firstpt,prefix,firstpt);
				result:=COMP(CCONC(prefix,redelem),result);
			END;
		END;
		first:=result;
	END;
	result:=FORMKFOR(ET,result);
	RETURN result;
END distribveloet;


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
	VAR pnfs, phi1, phi2, qbphi1, qbphi2: LIST;
BEGIN
	IF (pref<>EXIST) AND (pref<>FORALL) THEN
		ERROR(severe,
			"FORMKPRENEX: wrong preference given (assume EXIST)");
		pref:=EXIST;
	END;
	pnfs:=FORMKPRENEX1(phi);
	IF RED(pnfs)=SIL THEN
		(* Only one element: No choice is possible. *)
		RETURN FIRST(FIRST(pnfs));
	END;
	phi1:=FIRST(FIRST(pnfs));
	phi2:=FIRST(SECOND(pnfs));
	qbphi1:=SECOND(FIRST(pnfs));
	qbphi2:=SECOND(SECOND(pnfs));
	(* Choice resp. number of blocks of quantifiers. *)
	IF qbphi1<qbphi2 THEN
		RETURN phi1;
	ELSIF qbphi1>qbphi2 THEN
		RETURN phi2;
	(* Choice resp. the preferd type of quantifier. *)
	ELSIF FORGOP(phi1)=pref THEN
		RETURN phi1;
	ELSE
		RETURN phi2;
	END;
END FORMKPRENEX;

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
	VAR pnfs, phi1, phi2, qbphi1, qbphi2: LIST;
BEGIN
	IF (pref<>EXIST) AND (pref<>FORALL) THEN
		ERROR(severe,
			"FORMKPRENEX: wrong preference given (assume EXIST)");
		pref:=EXIST;
	END;
	pnfs:=FORMKPRENEX1(phi);
	IF RED(pnfs)=SIL THEN
		(* Only one element: No choice is possible. *)
		RETURN FIRST(FIRST(pnfs));
	END;
	phi1:=FIRST(FIRST(pnfs));
	phi2:=FIRST(SECOND(pnfs));
	qbphi1:=SECOND(FIRST(pnfs));
	qbphi2:=SECOND(SECOND(pnfs));
	(* Choice resp. number of blocks of quantifiers. *)
	IF qbphi1<qbphi2 THEN
		RETURN phi1;
	ELSIF qbphi1>qbphi2 THEN
		RETURN phi2;
	(* Choice resp. the preferd type of quantifier. *)
	ELSIF FORIMQB(phi1)=pref THEN
		RETURN phi1;
	ELSE
		RETURN phi2;
	END;
END FORMKPRENEXI;

PROCEDURE FORMKPRENEX1(phi: LIST): LIST;
(* formula make prenex 1. phi is a relative positive formula; this procedure
returns a list of maximal two objects of the form (psi,qb(psi)). In
(psi,qb(psi)) psi is a formula in prenex normal form, and qb(psi) the number
of blocks of quantifiers.  If there are two objects in the returned list, then
the outermost quantifier of the first formula is an exist quantifier and the
outermost quantifier of the second formula is a forall quantifier.  In the
following comments such a list is called pnf-selection. *)
	VAR op, res: LIST;
BEGIN
	FORPFOR(phi,op,res);
	IF (op=EXIST) OR (op=FORALL) THEN
		RETURN pnfquantifier(phi)
	ELSIF (op=VEL) OR (op=ET) THEN
		RETURN pnfjunctor(phi);
	ELSE  	(* i.e. phi is an atomic formula,
		   but not necessary a bb-formula.
		   VERUM, FALSUM, or a bb-formula, (which are
		   eventually negated) are possible. *)
		RETURN LIST1(LIST2(phi,0))
	END;
END FORMKPRENEX1;

PROCEDURE pnfquantifier(phi:LIST): LIST;
(* prenex normal form quantifier. phi is a relative positive formula with an
quantifier as the outermost operator symbol; pnfquantifier returns a
pnf-selection with only one formula equivalent to phi. *)
	VAR pnfs, qf, vars, nvars, qform, psi1, psi2, qbpsi1, qbpsi2: LIST;
BEGIN
	FORPQUANT(phi,qf,vars,qform);
	nvars:=FORGLVAR(vars);
	pnfs:=FORMKPRENEX1(qform);
	psi1:=FIRST(FIRST(pnfs));
	qbpsi1:=SECOND(FIRST(pnfs));
	IF RED(pnfs)=SIL THEN (* #pnfs=1 *)
		RETURN LIST1(mkquant(qf,nvars,psi1,qbpsi1));
	ELSIF FORGOP(psi1)=qf THEN
		RETURN LIST1(mkquant(qf,nvars,psi1,qbpsi1));
	ELSE
		psi2:=FIRST(SECOND(pnfs));
		qbpsi2:=SECOND(SECOND(pnfs));
		RETURN LIST1(mkquant(qf,nvars,psi2,qbpsi2));
	END;
END pnfquantifier;

PROCEDURE mkquant(qf,vars,phi,qbqform: LIST): LIST;
(* make quantifier. qf is a quantifier; vars is a list of the bound
variables of qf; phi is a formula; qbqform is the number of blocks of
quantifiers of qform, mkquantifier returns a pnf-selection with formulas
equivalent to the formula 'qf vars: phi'. If phi is a quantified formula and
the outermost quantifier of phi is a qf quantifier then mkquant generates no
new quantifier, but bounds the variables var to the outermost quantifier of
phi. *)
	VAR op,res,form,newvarlist, varlist:LIST;
BEGIN
	FORPFOR(phi,op,res);
	IF op<>qf THEN
		RETURN LIST2(FORMKQUANT(qf,FORMKLVAR(vars),phi),qbqform+1);
	ELSE
		FORPQUANTA(res,varlist,form);
		newvarlist:=CCONC(vars,FORGLVAR(varlist));
		RETURN LIST2(FORMKQUANT(qf,FORMKLVAR(newvarlist),form),
			qbqform);
	END;
END mkquant;

PROCEDURE pnfjunctor(phi: LIST):LIST;
(* prenex normal form junctor. phi is a relative positive formula with an ET
or VEL operator as the outermost function symbol; pnfjunctor returns a
pnf-selection with formulas equivalent to phi. If there are two objects in the
pnf-selection, then the outermost quantifier of the formula in the first
(second) object is an EXIST (FORALL) quantifier *)
	VAR op, res, arglist, pnfargs, arg, l1, l2, M, qf1, qf2:LIST;
	VAR phi1, qbphi1, phi2, qbphi2: LIST;
	VAR onlyex, onlyfa: BOOLEAN;
BEGIN
	M:=0;
	onlyex:=TRUE;
	onlyfa:=TRUE;

	FORPFOR(phi,op,res);
	arglist:=SIL;
	l1:=SIL;
	l2:=SIL;
	WHILE res<>SIL DO
		FORPARGS(res,arg,res);
		pnfargs:=FORMKPRENEX1(arg);
		phi1:=FIRST(FIRST(pnfargs));
		qbphi1:=SECOND(FIRST(pnfargs));
		(* calculate the characteristic selections *)
		IF RED(pnfargs)=SIL THEN
			l1:=COMP(phi1,l1);
			l2:=COMP(phi1,l2);
			phi2:=phi1;
			qbphi2:=qbphi1;
		ELSE
			phi2:=FIRST(SECOND(pnfargs));
			qbphi2:=SECOND(SECOND(pnfargs));
			(* In resp. to the definition of pnf is the outermost
			* quantifier of phi1 (phi2) is an EXIST (FORALL)
			* quantifier *)
			l1:=COMP(phi1,l1);
			l2:=COMP(phi2,l2);
		END;
		(* compute the maximum of blocks of quantifiers,
		* simultaneous
		* ascertaian criterions which characteristic selection is
		* optimal resp. the number of blocks of quantifiers. *)
		qf1:=FORGOP(phi1);
		qf2:=FORGOP(phi2);
		IF M<qbphi1 THEN
			M:=qbphi1;
			onlyex:=TRUE;
			onlyfa:=TRUE;
		END;
		IF (M=qbphi1) AND (qf1<>EXIST)  (* for M=0  meaningless *)
		THEN 				(* but M=0 is a special *)
			onlyex:=FALSE;		(* case.		*)
		END;
		IF (M=qbphi2) AND (qf2<>FORALL)	(*        dito       *)
		THEN
			onlyfa:=FALSE
		END;
	END;
	IF M=0 THEN
		RETURN LIST1(LIST2(phi,0));
	END;
	(* Calculate the result with respect to onlyex and onlyfa. *)
	(* refere to the proof in the documentation. *)
	IF onlyex AND (NOT onlyfa) THEN
		RETURN LIST1(interchange(l1,op,EXIST));
	ELSIF onlyfa AND (NOT onlyex) THEN
		RETURN LIST1(interchange(l2,op,FORALL));
	ELSE
		RETURN LIST2(interchange(l1,op,EXIST),
			interchange(l2,op,FORALL));
	END;
END pnfjunctor;

PROCEDURE interchange(L,op,pref:LIST):LIST;
(* interchange. L is a list of relative positive formulas; op is an operation
symbol (VEL or ET); pref is a quantifier symbol; interchange returns an element
of a pnf-selection with a formula equivalent to the formula 'op(L)'. pref is
the type of the outermost quantifier after the interchange, if a choice is
possible. *)
	VAR l1, l2, qf, q, form, qblock, vblock, qform, vars: LIST;
 	VAR varlist, result, numqfb, nextop:LIST;
	VAR noqf: BOOLEAN;
BEGIN
	IF L=SIL THEN RETURN SIL; END;

	l1:=L;
	qf:=pref;
	qblock:=SIL;	(* List of all quantifiers in the blocks *)
	vblock:=SIL;	(* List of all bound variables in the blocks *)
	REPEAT
		l2:=SIL;
		varlist:=SIL;
		noqf:=TRUE;
		WHILE l1<>SIL DO
			ADV(l1,form,l1);
			getqfb(form,qf,vars,qform);
			nextop:=FORGOP(qform);
			noqf:=noqf AND ((nextop<>EXIST) AND (nextop<>FORALL));
			l2:=COMP(qform,l2);
			varlist:=CCONC(varlist,vars);
		END;
		IF varlist <> SIL THEN
			qblock:=COMP(qf,qblock);
			vblock:=COMP(FORMKLVAR(varlist),vblock);
		END;
		l1:=l2;
		qf:=notsymbol(qf);
	UNTIL noqf; (* i.e there are no quantifiers in the formulas of L *)
	(* generate the result *)
	numqfb:=LENGTH(vblock);
	result:=FORMKFOR(op,l1);
	WHILE qblock <> SIL DO
		ADV(qblock,q,qblock);
		ADV(vblock,varlist,vblock);
		result:=FORMKQUANT(q,varlist,result);
	END;
	RETURN LIST2(result,numqfb);
END interchange;

PROCEDURE getqfb(phi,qf: LIST; VAR qfb, qform: LIST);
(* get quantifier block. phi is a relative positive formula; qf is a
quantifier symbol.  qfb is assigned to a list of variables which are bound
to the outermost quantifier of type qf, qform is the formula bound by the
quantifier qf. *)
	VAR op, res, varlist, bound: LIST;
BEGIN
	qfb:=SIL;
	FORPFOR(phi,op,res);
	IF op<>qf THEN
		qform:=phi;
		RETURN;
	END;
	WHILE (op=qf) DO
 		FORPQUANTA(res,varlist,qform);
		FORPLVAR(varlist,bound);
		qfb:=CCONC(qfb,bound);
		FORPFOR(qform,op,res);
	END;
	RETURN;
END getqfb;

PROCEDURE FORIMQB(phi: LIST):LIST;
(* formula innermost quantifier block. phi is a formula in prenex normal form.
If the outermost operator of phi is no quantifier then SIL is returned. 
Otherwise the type of the innermost quantifier block (either FOREX or FORALL) 
is returned. *)
	VAR sym, vars, imq : LIST;
BEGIN
	sym:=FORGOP(phi);
	IF (sym<>EXIST) AND (sym<>FORALL) THEN RETURN SIL; END;
	REPEAT 
		imq:=sym;
		FORPQUANT(phi,sym,vars,phi);
	UNTIL (sym<>EXIST) AND (sym<>FORALL);
	RETURN imq;
END FORIMQB;

(******************************************************************************
*		S U B S T I T U T E   V A R I A B L E                         *
******************************************************************************)

PROCEDURE FORSUBSTVAR(phi, old, new: LIST; bbsubstvar: PROCF3): LIST;
(* formula substitute variable. phi is a formula; old and new are variables; a
formula in which the variable old is substituted by the variable new is
returned. *)
	VAR op, res, arg, arg1, arg2: LIST;
	VAR parlist, lvar, varlist, var, qform: LIST;
BEGIN
	FORPFOR(phi,op,res);

	IF (op=VERUM) OR (op=FALSUM) THEN
		RETURN phi;
	ELSIF op=NON THEN
		FORPUNOPA(res,arg);
		RETURN FORMKUNOP(op,FORSUBSTVAR(arg,old,new,bbsubstvar));
	ELSIF (op=VEL) OR (op=ET) THEN
		parlist:=SIL;
		WHILE res<>SIL DO
			FORPARGS(res,arg,res);
			parlist:=COMP(FORSUBSTVAR(arg,old,new,bbsubstvar),
				parlist);
		END;
		RETURN FORMKFOR(op,INV(parlist));
	ELSIF (op=REP) OR (op=IMP) OR (op=EQUIV) OR (op=XOR) THEN
		FORPBINOPA(res,arg1,arg2);
		RETURN FORMKBINOP(op,
			FORSUBSTVAR(arg1,old,new,bbsubstvar),
			FORSUBSTVAR(arg2,old,new,bbsubstvar));
	ELSIF op=TVAR THEN
		IF EQUAL(phi,old)=1 THEN
			RETURN new;
		ELSE    
			RETURN phi;
		END;       
	ELSIF (op=EXIST) OR (op=FORALL) THEN
		FORPQUANTA(res,lvar,qform);
		FORPLVAR(lvar,varlist);
		parlist:=SIL;
		WHILE varlist<>SIL DO
			FORPARGS(varlist,var,varlist);
			IF EQUAL(var,old)=1 THEN
				parlist:=COMP(new,varlist);
			ELSE
				parlist:=COMP(var,parlist);
			END;
		END;
		RETURN FORMKQUANT(op,FORMKLVAR(INV(parlist)),
			FORSUBSTVAR(qform,old,new,bbsubstvar));
	ELSE
		RETURN bbsubstvar(phi,old,new);
	END;
END FORSUBSTVAR;


(******************************************************************************
*		 M A K E   V A R I A B L E S   D I S J O I N T                *
******************************************************************************)

PROCEDURE FORMKVD(phi:LIST; bbsubstvar:PROCF3;bblsvars:PROCF1): LIST;
(* formula make variable names disjoint. phi is a formula, bbsubstvar is a
bb-procedure to substitute variables in bb-formulas, bblsvars is a
bb-procedure to list all variables in a bb-formula; FORMKVD returns a formula
in which all bound variables of the same sort have different names. Only the
minimal number of renamings are done to make the names different. *)
	VAR all,used,var,xall,name,sort,free,bound,env: LIST;
BEGIN
	free:=SIL;
	bound:=SIL;
	env:=SIL;
	collectnames(phi,env,bblsvars,free,bound);
	used:=free;
	all:=CCONC(free,bound);
	xall:=SIL;
	WHILE all<>SIL DO
		ADV(all,var,all);
		FORPVAR(var,name,sort);
		xall:=COMP(LIST2(FORVTGET(name),FORVTGET(sort)),xall);
	END;
	RETURN repvar(phi,SIL,SIL,used,xall,bbsubstvar);
END FORMKVD;

PROCEDURE collectnames(phi,env:LIST; bblsvars:PROCF1; VAR free, bound:LIST);
(* collect names. phi is a formula, env is the list of all bound variables
in phi; bblsvars is a bb-procedure to list all variables in a bb-formula; 
the list of all free (bound) varaiables of phi are built in the list free 
(bound). 
It should be taken into account that one variable can occure in the list free
and in the list bound! *)
	VAR op, red, arg, arg1, arg2, lvar, psi, name, sort: LIST;
	VAR varlist, var: LIST;
BEGIN
	IF phi=SIL THEN RETURN;  END;

	FORPFOR(phi,op,red);
	IF (op=VERUM) OR (op=FALSUM) THEN
		RETURN ;
   	ELSIF op=NON THEN
		FORPUNOPA(red,arg);
		collectnames(arg,env,bblsvars,free,bound);
		RETURN;
   	ELSIF (op=VEL) OR (op=ET) THEN
		WHILE red<>SIL DO
			FORPARGS(red,arg,red);
			collectnames(arg,env,bblsvars,free,bound);
   		END;
		RETURN ;
	ELSIF (op=IMP) OR (op=REP) OR (op=EQUIV) OR (op=XOR) THEN
		FORPBINOPA(red,arg1,arg2);
		collectnames(arg1,env,bblsvars,free,bound);
		collectnames(arg2,env,bblsvars,free,bound);
		RETURN;
	ELSIF (op=EXIST) OR (op=FORALL) THEN
		FORPQUANTA(red,lvar,psi);
		varlist:=FORGLVAR(lvar);
		env:=CCONC(varlist,env);
		bound:=CCONC(varlist,bound);
		collectnames(psi,env,bblsvars,free,bound);
		RETURN;
	ELSIF (op=TVAR) (* sort = BOOL *) THEN
		free:=COMP(phi,free);	(* regard boolean vars as free vars *)
		RETURN;
	ELSE  (* phi is an atomic formula *)
		varlist:=SetComplementQ(env,bblsvars(phi));
		free:=CCONC(varlist,free);
		RETURN;
	END;
END collectnames;

PROCEDURE repvar(phi,old,new:LIST; VAR used, denied: LIST;
	bbsubstvar: PROCF3):LIST;
(* replace variables. phi is a formula; old is a list of variables which are
substituted with the corresponding variables in new; used is list of variables
of phi which are already used (and contains also the names of all free 
varaiables; denied is a list of lists of the form (name,sort). 
The list denied describes a list of variables which are not
allowed to be generated. 
The procedure bbsubstvar is a bb-procedure to substitute variables in 
bb-formulas. repvar returns a formula in which the variables are replaced; 
used and denied are updated. *)
	VAR op, red, arg, arg1, arg2, lvar, psi, name, newvars, newv,
		sort, result, vars, v, p, t: LIST;
BEGIN
	IF phi=SIL THEN RETURN SIL; END;

	FORPFOR(phi,op,red);
	IF (op=VERUM) OR (op=FALSUM) THEN
		RETURN phi;
   	ELSIF op=NON THEN
		FORPUNOPA(red,arg);
		RETURN FORMKUNOP(NON,
			repvar(arg,old,new,used,denied,bbsubstvar));
   	ELSIF (op=VEL) OR (op=ET) THEN
		result:=SIL;
		WHILE red<>SIL DO
			FORPARGS(red,arg,red);
			result:=COMP(repvar(arg,old,new,used,denied,
					 bbsubstvar),result);
   		END;
		RETURN FORMKFOR(op,INV(result));
	ELSIF (op=IMP) OR (op=REP) OR (op=EQUIV) OR (op=XOR) THEN
		FORPBINOPA(red,arg1,arg2);
		RETURN FORMKBINOP(op,
			repvar(arg1,old,new,used,denied,bbsubstvar),
			repvar(arg2,old,new,used,denied,bbsubstvar))
	ELSIF (op=EXIST) OR (op=FORALL) THEN
		FORPQUANTA(red,lvar,psi);
		FORPLVAR(lvar,vars);
		newvars:=SIL;
		WHILE vars<>SIL DO
			ADV(vars,v,vars);
			IF MEMBER(v,used)=1
			THEN
				newv:=GENVAR(v,denied);
				FORPVAR(newv,name,sort);
				denied:=COMP(LIST2(FORVTGET(name),
					FORVTGET(sort)),denied); 
				old:=COMP(v,old);
				new:=COMP(newv,new);
				newvars:=COMP(newv,newvars);
			ELSE
				used:=COMP(v,used);
				newvars:=COMP(v,newvars);
			END;
		END;
		RETURN FORMKQUANT(op,FORMKLVAR(INV(newvars)),
			repvar(psi,old,new,used,denied,bbsubstvar));
	ELSIF op=TVAR THEN
		WHILE old<>SIL DO
			ADV(old,p,old);
			ADV(new,t,new);
			IF EQUAL(phi,p)=1 THEN RETURN t; END;
		END;
		RETURN phi;
	ELSE
		(* apply all substitution to the bb-formula phi *)
		result:=phi;
		WHILE old<>SIL DO
			ADV(old,p,old);
			ADV(new,t,new);
			result:=bbsubstvar(result,p,t);
		END;
		RETURN result;
	END;
END repvar;

PROCEDURE GENVAR(var,xdenied:LIST): LIST;
(* generate variable. var is a variable; xdenied is a list of variables (all
symbols in this list must been exploded!).  The returned variable has a name
which is disjoint to the names of the variables in the list xdenied. (refere
the procedure GENSYM from the module MASSYM2.) *)
	VAR name, sort, xname, xsort, sname,(* x for explode, s for symbol *)
		num, q, new: LIST;
BEGIN
	FORPVAR(var,name,sort);
	xname:=FORVTGET(name);
	xsort:=FORVTGET(sort);
	(* check whether var is in denied or not *)
	IF MEMBER(LIST2(xname,xsort),xdenied)=0 THEN RETURN var; END;
	num:=0;
	(* generate new varaibles until no name conflicts occurs *)
	REPEAT
		new:=SIL;      (* FORMAT von XDENIED hat sich geaendert!!!! *)
		num:=num+1;
		q:=num;
		REPEAT
			new:=COMP(MASREM(q,10),new);
			q:=q DIV 10;
		UNTIL q = 0;
		new:=COMP(MASORD("N"),new);
		new:=CCONC(xname,new);
	UNTIL MEMBER(LIST2(new,xsort),xdenied)=0;
	sname:=FORVTENTER(new);
	RETURN FORMKVAR(sname,sort)
END GENVAR;


(******************************************************************************
*				 S I M P L I F Y			      *
******************************************************************************)

PROCEDURE FORSMPL(phi: LIST; bbsmpl, bbmkneg: PROCF1): LIST;
(* formula simplify. phi is a formula, simplifybb is a bb-procedure to
simplify a bb-formula; bbmkneg is a bb-procedure to negate a bb-formula; a
formula phi1 equivalent to phi is returned. The formula phi1 is simplified,
that means the constants VERUM and FALSUM are eliminated, and nested operators
are eliminated. (In this case the procedure takes advantage of associativity
of ET and VEL, and the idempotenz of NON.) *)
	VAR op, red, arg, arg1, arg2, simparg1, simparg2, newop, newarg: LIST;
	VAR newred, vars, qform, simpqform, elem, result: LIST;
BEGIN
	IF phi = SIL THEN RETURN SIL; END;

	FORPFOR(phi,op,red);
	IF (op=VERUM) OR (op=FALSUM) THEN
		RETURN phi;
	ELSIF op=NON THEN
		FORPUNOPA(red,arg);
		newarg:=FORSMPL(arg,bbsmpl,bbmkneg);
		RETURN formkneg(newarg,bbmkneg);
	ELSIF op=ET THEN
		result:=SIL;
		WHILE red <> SIL DO
			FORPARGS(red,arg,red);
			newarg:=FORSMPL(arg,bbsmpl,bbmkneg);
			IF newarg=FALSUM
			THEN
				RETURN FORMKCNST(FALSUM);
			ELSIF newarg<>VERUM (* VERUM is neutral w.r.t. ET *)
			THEN
			(* Try to simplify the formula with the law of
			* associativity *)
				FORPARGS(newarg,newop,newred);
				IF newop=ET THEN
					WHILE newred <> SIL DO
						FORPARGS(newred,elem,newred);
						result:=COMP(elem,result);
					END;

				ELSE
					result:=COMP(newarg,result);
				END;
			END;
		END;
		IF result<>SIL 	THEN
			RETURN FORMKFOR(ET,INV(result));
		ELSE
			RETURN FORMKCNST(VERUM);
		END
	ELSIF op=VEL THEN
		result:=SIL;
		WHILE red <> SIL DO
			FORPARGS(red,arg,red);
			newarg:=FORSMPL(arg,bbsmpl,bbmkneg);
			IF newarg=VERUM THEN
				RETURN VERUM;
			ELSIF newarg<>FALSUM THEN
			(* Try to simplify the formula with the law of
			* associativity *)
				FORPARGS(newarg,newop,newred);
				IF newop=VEL THEN
					WHILE newred <> SIL DO
						FORPARGS(newred,elem,newred);
						result:=COMP(elem,result);
					END;
				ELSE
					result:=COMP(newarg,result);
				END;
			END;
		END;
		IF result<>SIL 	THEN
			RETURN FORMKFOR(VEL,INV(result));
		ELSE
			RETURN FORMKCNST(FALSUM);
		END;
 	ELSIF (op=IMP) OR (op=REP) THEN
		RETURN smplimpl(phi,bbsmpl,bbmkneg);
 	ELSIF op=EQUIV THEN
		FORPBINOPA(red,arg1,arg2);
		simparg1:=FORSMPL(arg1,bbsmpl,bbmkneg);
		simparg2:=FORSMPL(arg2,bbsmpl,bbmkneg);
		IF simparg1=VERUM THEN
			RETURN simparg2
		ELSIF simparg2=VERUM THEN
			RETURN simparg1
		ELSIF simparg1=FALSUM THEN
			RETURN formkneg(simparg2,bbmkneg);
		ELSIF simparg2=FALSUM THEN
			RETURN formkneg(simparg1,bbmkneg);
		ELSE
			RETURN FORMKBINOP(EQUIV,simparg1,simparg2);
		END;
	ELSIF op=XOR THEN
		FORPBINOPA(red,arg1,arg2);
		simparg1:=FORSMPL(arg1,bbsmpl,bbmkneg);
		simparg2:=FORSMPL(arg2,bbsmpl,bbmkneg);
		IF simparg1=FALSUM THEN
			RETURN simparg2
		ELSIF simparg2=FALSUM THEN
			RETURN simparg1
		ELSIF simparg1=VERUM THEN
			RETURN formkneg(simparg2,bbmkneg);
		ELSIF simparg2=VERUM THEN
			RETURN formkneg(simparg1,bbmkneg);
		ELSE
			RETURN FORMKBINOP(XOR,simparg1,simparg2);
		END;
	ELSIF (op=EXIST) OR (op=FORALL) THEN
		FORPQUANTA(red,vars,qform);
		simpqform:=FORSMPL(qform,bbsmpl,bbmkneg);
		IF (simpqform=VERUM) OR (simpqform=FALSUM) THEN
			RETURN simpqform
		ELSE
			RETURN FORMKQUANT(op,vars,simpqform);
		END;
	ELSIF op=TVAR THEN
		RETURN phi;
	ELSE
		RETURN bbsmpl(phi);
	END;
END FORSMPL;

PROCEDURE smplimpl(phi:LIST;bbsmpl,bbmkneg:PROCF1):LIST;
(* simplify implication. phi is either an implication or a replication; bbsmpl
is bb-procedure to simplify a bb-formula; bbmkneg is a bb-procedure to negate
a bb-formula; a simplification of phi is returned. (see the description of
FORSMPL). *)
	VAR sprem, sconcl,prem,concl,op,newarg,newop,arg1,arg2: LIST;
BEGIN
	FORPBINOP(phi,op,arg1,arg2);
	IF op=IMP THEN
		prem:=arg1;
		concl:=arg2;
	ELSE
		prem:=arg2;
		concl:=arg1;
	END;
	IF prem=FALSUM THEN
		RETURN FORMKCNST(VERUM);
	ELSIF prem=VERUM THEN
		RETURN FORSMPL(concl,bbsmpl,bbmkneg);
	ELSIF concl=FALSUM THEN
		RETURN FORSMPL(FORMKUNOP(NON,prem),bbsmpl,bbmkneg);
	ELSIF concl=VERUM THEN
		RETURN concl;
	ELSE
		sprem:=FORSMPL(prem,bbsmpl,bbmkneg);
		sconcl:=FORSMPL(concl,bbsmpl,bbmkneg);
		IF sprem=FALSUM THEN
			RETURN FORMKCNST(VERUM);
		ELSIF sprem=VERUM THEN
			RETURN sconcl;
		ELSIF sconcl=FALSUM THEN
			FORPFOR(sprem,newop,newarg);
			IF newop=NON THEN
				RETURN newarg;
			ELSE
				RETURN FORMKUNOP(NON,sprem)
			END;
		ELSIF sconcl=VERUM THEN
			RETURN sconcl;
		ELSE
			IF EQUAL(sprem,sconcl)=1 THEN RETURN VERUM; END;
			IF op=IMP THEN
				RETURN FORMKBINOP(IMP,sprem,sconcl);
			ELSE
				RETURN FORMKBINOP(REP,sconcl,sprem);
			END;
		END;
	END;
END smplimpl;


PROCEDURE FORSIMPLIFY(phi: LIST; smart: PROCF1; bbsmpl, bbmkneg: PROCF1):LIST;
(* formula simplify. phi is a formula, smart is a function
to do smart simplification on a list of atomic formulas. 
simplifybb is a bb-procedure to
simplify a bb-formula; bbmkneg is a bb-procedure to negate a bb-formula.
A simplification of phi is returned. *)
	VAR op, red, arg, arg1, arg2, simparg1, simparg2, newop, newarg: LIST;
	VAR newred, vars, qform, simpqform, elem, result: LIST;
	VAR aflist, cflist,psi: LIST;
BEGIN
	IF phi = SIL THEN RETURN SIL; END;

	FORPFOR(phi,op,red);
	IF (op=VERUM) OR (op=FALSUM) THEN
		RETURN phi;
	ELSIF op=NON THEN
		FORPUNOPA(red,arg);
		newarg:=FORSIMPLIFY(arg,smart,bbsmpl,bbmkneg);
		RETURN formkneg(newarg,bbmkneg);
	ELSIF (op=ET) OR (op=VEL) THEN
		result:=SIL;
		WHILE red<>SIL DO
			FORPARGS(red,arg,red);
			arg:=FORSIMPLIFY(arg,smart,bbsmpl,bbmkneg);
			result:=SimplifyComp(arg,op,result);
			IF (result=VERUM) OR (result=FALSUM) THEN
				RETURN result;
			END; 
		END;
		result:=DoSmartSimplify(result,op,smart);
		IF (result=VERUM) OR (result=FALSUM) THEN
			RETURN result;
		END;
		IF (result=VERUM) OR (result=FALSUM) THEN
			RETURN FORMKCNST(result);
		ELSIF result=SIL THEN
			IF op=ET THEN 
				RETURN FORMKCNST(VERUM); 
			ELSE (* IF op=VEL *)
				RETURN FORMKCNST(FALSUM); 
			END;
		ELSIF RED(result)=SIL THEN 	(* only one argument *)
			RETURN FIRST(result)
		ELSE
			RETURN FORMKFOR(op,result);
		END;
 	ELSIF (op=IMP) OR (op=REP) THEN
		RETURN smplimpl(phi,bbsmpl,bbmkneg);
 	ELSIF op=EQUIV THEN
		FORPBINOPA(red,arg1,arg2);
		simparg1:=FORSIMPLIFY(arg1,smart,bbsmpl,bbmkneg);
		simparg2:=FORSIMPLIFY(arg2,smart,bbsmpl,bbmkneg);
		IF simparg1=VERUM THEN
			RETURN simparg2
		ELSIF simparg2=VERUM THEN
			RETURN simparg1
		ELSIF simparg1=FALSUM THEN
			RETURN formkneg(simparg2,bbmkneg);
		ELSIF simparg2=FALSUM THEN
			RETURN formkneg(simparg1,bbmkneg);
		ELSE
			IF EQUAL(simparg1,simparg2)=1 THEN RETURN VERUM; END; 
			RETURN FORMKBINOP(EQUIV,simparg1,simparg2);
		END;
	ELSIF op=XOR THEN
		FORPBINOPA(red,arg1,arg2);
		simparg1:=FORSIMPLIFY(arg1,smart,bbsmpl,bbmkneg);
		simparg2:=FORSIMPLIFY(arg2,smart,bbsmpl,bbmkneg);
		IF simparg1=FALSUM THEN
			RETURN simparg2
		ELSIF simparg2=FALSUM THEN
			RETURN simparg1
		ELSIF simparg1=VERUM THEN
			RETURN formkneg(simparg2,bbmkneg);
		ELSIF simparg2=VERUM THEN
			RETURN formkneg(simparg1,bbmkneg);
		ELSE
			IF EQUAL(simparg1,simparg2)=1 THEN RETURN FALSUM; END; 
			RETURN FORMKBINOP(XOR,simparg1,simparg2);
		END;
	ELSIF (op=EXIST) OR (op=FORALL) THEN
		FORPQUANTA(red,vars,qform);
		simpqform:=FORSIMPLIFY(qform,smart,bbsmpl,bbmkneg);
		IF (simpqform=VERUM) OR (simpqform=FALSUM) THEN
			RETURN simpqform
		ELSE
			RETURN FORMKQUANT(op,vars,simpqform);
		END;
	ELSIF op=TVAR THEN
		RETURN phi;
	ELSE
		RETURN bbsmpl(phi);
	END;
END FORSIMPLIFY;

PROCEDURE SimplifyComp(phi,op,L:LIST):LIST;
(* simplify composition. phi is a formula. 
op is either ET or VEL. L is a list of formulas. 
A list of formulas is returned. If phi is already a element of L then L is 
returned. If the operator symbol of phi is equal to op then all arguments 
of this operator of phi are inserted in L, otherwise phi is inserted in L.
L is modified, the result is returned. If the result of SimplifyComp
is VERUM or FALUSM then VERUM or FALSUM are returned, not the LIST of 
one of these symbols. 
*)
	VAR args,psi: LIST;
BEGIN
	IF ((op=ET) AND (phi=FALSUM) ) OR 
	   ((op=VEL) AND (phi=VERUM) ) 
	THEN
		RETURN phi;
	ELSIF (phi=VERUM) OR (phi=FALSUM) THEN
		RETURN L;
	END; 
	IF FORGOP(phi)=op THEN
		args:=FORGARGS(phi);
		WHILE args<>SIL DO
			ADV(args,psi,args);
			L:=SetAddQ(psi,L);
		END;
		RETURN L;
	ELSE
		RETURN SetAddQ(phi,L);
	END;
END SimplifyComp;

PROCEDURE DoSmartSimplify(L,op:LIST;smart:PROCF1):LIST;
(* do smart simplification. L is a list of formulas. op is a the operator
ET or VEL. smart is a procedure for smart simplification. The
simplified formula op(L) is returned. *)
	VAR aflist, cflist, psi, result,smartresult: LIST;
BEGIN
	aflist:=SIL; 
	result:=SIL;
	WHILE L<>SIL DO
		ADV(L,psi,L);
		IF FORISBBFOR(psi)
		THEN
			aflist:=COMP(psi,aflist);
		ELSE
			result:=COMP(psi,result);
		END;
	END;
	IF aflist<>SIL THEN
		smartresult:=smart(FORMKFOR(op,aflist));
		IF NOT FORISATOM(smartresult) THEN 
			smartresult:=FORMKFOR(FORGOP(smartresult),
				INV(FORGARGS(smartresult)));
		END;
		RETURN SimplifyComp(smartresult,op,result);
	ELSE
		RETURN result;
	END; 
END DoSmartSimplify;

PROCEDURE FORSIMPLIFYP(phi,maxlevel: LIST;
	smart: PROCF1; bbsmpl, bbmkneg: PROCF1):LIST;
(* formula simplify prune. phi is a formula, level, maxlevel are atoms, 
smart is a function to do smart simplification on a list of atomic formulas. 
simplifybb is a bb-procedure to
simplify a bb-formula; bbmkneg is a bb-procedure to negate a bb-formula.
maxlevel defines the number of levels that are simplified, 1 means only 
the top-level, zero means simplify the hole tree.
A simplification of phi is returned. *)
BEGIN
	RETURN simplifyp(phi,1,maxlevel,smart,bbsmpl,bbmkneg);
END FORSIMPLIFYP;

PROCEDURE simplifyp(phi,level,maxlevel: LIST;
	smart: PROCF1; bbsmpl, bbmkneg: PROCF1):LIST;
(* formula simplify prune. phi is a formula, level, maxlevel are atoms, 
smart is a function to do smart simplification on a list of atomic formulas. 
simplifybb is a bb-procedure to
simplify a bb-formula; bbmkneg is a bb-procedure to negate a bb-formula.
maxlevel defines the number of levels that are simplified, 1 means only 
the top-level, zero means simplify the hole tree. level is the current level.
A simplification of phi is returned. *)
	VAR op, red, arg, arg1, arg2, simparg1, simparg2, newop, newarg: LIST;
	VAR newred, vars, qform, simpqform, elem, result: LIST;
	VAR aflist, cflist,psi: LIST;
BEGIN
	IF phi = SIL THEN RETURN SIL; END;
	IF level=maxlevel+1 THEN RETURN phi; END; 

	FORPFOR(phi,op,red);
	IF (op=VERUM) OR (op=FALSUM) THEN
		RETURN phi;
	ELSIF op=NON THEN
		FORPUNOPA(red,arg);
		newarg:=simplifyp(arg,level+1,maxlevel,smart,bbsmpl,bbmkneg);
		RETURN formkneg(newarg,bbmkneg);
	ELSIF (op=ET) OR (op=VEL) THEN
		result:=SIL;
		WHILE red<>SIL DO
			FORPARGS(red,arg,red);
			arg:=simplifyp(arg,level+1,maxlevel,smart,bbsmpl,bbmkneg);
			result:=SimplifyComp(arg,op,result);
			IF (result=VERUM) OR (result=FALSUM) THEN
				RETURN result;
			END; 
		END;
		result:=DoSmartSimplify(result,op,smart);
		IF (result=VERUM) OR (result=FALSUM) THEN
			RETURN result;
		END;
		IF (result=VERUM) OR (result=FALSUM) THEN
			RETURN FORMKCNST(result);
		ELSIF result=SIL THEN
			IF op=ET THEN 
				RETURN FORMKCNST(VERUM); 
			ELSE (* IF op=VEL *)
				RETURN FORMKCNST(FALSUM); 
			END;
		ELSIF RED(result)=SIL THEN 	(* only one argument *)
			RETURN FIRST(result)
		ELSE
			RETURN FORMKFOR(op,result);
		END;
 	ELSIF (op=IMP) OR (op=REP) THEN
		RETURN smplimpl(phi,bbsmpl,bbmkneg);
 	ELSIF op=EQUIV THEN
		FORPBINOPA(red,arg1,arg2);
		simparg1:=simplifyp(arg1,level+1,maxlevel,smart,bbsmpl,bbmkneg);
		simparg2:=simplifyp(arg2,level+1,maxlevel,smart,bbsmpl,bbmkneg);
		IF simparg1=VERUM THEN
			RETURN simparg2
		ELSIF simparg2=VERUM THEN
			RETURN simparg1
		ELSIF simparg1=FALSUM THEN
			RETURN formkneg(simparg2,bbmkneg);
		ELSIF simparg2=FALSUM THEN
			RETURN formkneg(simparg1,bbmkneg);
		ELSE
			IF EQUAL(simparg1,simparg2)=1 THEN RETURN VERUM; END; 
			RETURN FORMKBINOP(EQUIV,simparg1,simparg2);
		END;
	ELSIF op=XOR THEN
		FORPBINOPA(red,arg1,arg2);
		simparg1:=simplifyp(arg1,level+1,maxlevel,smart,bbsmpl,bbmkneg);
		simparg2:=simplifyp(arg2,level+1,maxlevel,smart,bbsmpl,bbmkneg);
		IF simparg1=FALSUM THEN
			RETURN simparg2
		ELSIF simparg2=FALSUM THEN
			RETURN simparg1
		ELSIF simparg1=VERUM THEN
			RETURN formkneg(simparg2,bbmkneg);
		ELSIF simparg2=VERUM THEN
			RETURN formkneg(simparg1,bbmkneg);
		ELSE
			IF EQUAL(simparg1,simparg2)=1 THEN RETURN FALSUM; END; 
			RETURN FORMKBINOP(XOR,simparg1,simparg2);
		END;
	ELSIF (op=EXIST) OR (op=FORALL) THEN
		FORPQUANTA(red,vars,qform);
		simpqform:=simplifyp(qform,level+1,maxlevel,smart,bbsmpl,bbmkneg);
		IF (simpqform=VERUM) OR (simpqform=FALSUM) THEN
			RETURN simpqform
		ELSE
			RETURN FORMKQUANT(op,vars,simpqform);
		END;
	ELSIF op=TVAR THEN
		RETURN phi;
	ELSE
		RETURN bbsmpl(phi);
	END;
END simplifyp;

(******************************************************************************
*	 P R E P A R E   Q U A N T I F I E R   E L I M I N A T I O N	      *
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
	VAR op, quant, red, parg, phi1, lastop, qblocks, vblocks, psi,
		arg, psi1, lvar: LIST;
BEGIN
	IF phi=SIL THEN RETURN SIL; END;

	FORPFOR(phi,op,red);
	IF (op<>EXIST) AND (op<>FORALL) THEN
		RETURN phi;
	END;
	qblocks:=SIL;
	vblocks:=SIL;
	WHILE (op=EXIST) OR (op=FORALL) DO
		FORPQUANTA(red,lvar,phi1);
		qblocks:=COMP(op,qblocks);
		vblocks:=COMP(lvar,vblocks);
		FORPFOR(phi1,op,red);
	END;
	(* now: qblocks is a list of all blocks of quantifiers of phi, but
	the sequence is reveresed. *)
	ADV(qblocks,quant,qblocks);
	ADV(vblocks,lvar,vblocks);
	(* now: quant is the innermost quantifier *)
	IF quant=EXIST THEN
		psi1:=FORMKDNF(phi1,bbmkneg);
	ELSE 		(* op=FORALL *)
		psi1:=FORMKCNF(phi1,bbmkneg);
	END;
	FORPFOR(psi1,op,red);
	psi:=SIL;
	WHILE red<>SIL DO
		FORPARGS(red,arg,red);
		parg:=FORMKQUANT(quant,lvar,arg);	(* simplification? *)
		psi:=COMP(parg,psi);
	END;
	psi:=FORMKFOR(op,psi);
	WHILE qblocks<>SIL DO
		ADV(qblocks,quant,qblocks);
		ADV(vblocks,lvar,vblocks);
		psi:=FORMKQUANT(quant,lvar,psi);
	END;
	RETURN psi;
END FORPREPQE;


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
	VAR op, arglist, arg, arg1, arg2, prem, concl, lvar, qform: LIST;
	VAR elimarg1, elimarg2, res: LIST;
BEGIN
	IF phi = SIL THEN RETURN SIL; END;
	IF pref = NON THEN RETURN phi; END;

	IF (pref <> VEL) AND (pref <> ET) THEN
		ERROR(severe,"FORMELIMXOPS: wrong preferenz given (assume NON)");
		RETURN phi;
	END;

	FORPFOR(phi,op,arglist);
	IF (op=VERUM) OR (op=FALSUM) THEN
		RETURN phi;
	ELSIF op=NON THEN
		FORPUNOPA(arglist,arg);
		RETURN FORMKUNOP(NON,FORELIMXOPS(arg,pref));
	ELSIF (op=VEL) OR (op=ET) THEN
		res:=SIL;
		WHILE arglist <> SIL DO
			FORPARGS(arglist,arg,arglist);
			res:=COMP(FORELIMXOPS(arg,pref),res);
		END;
		RETURN FORMKFOR(op,INV(res));
	ELSIF (op=EXIST) OR (op=FORALL) THEN
		FORPQUANTA(arglist,lvar,qform);
		RETURN FORMKQUANT(op,lvar,FORELIMXOPS(qform,pref));
	ELSIF op=IMP THEN
		FORPBINOPA(arglist,prem,concl);
		RETURN FORMKBINOP(VEL,FORMKUNOP(NON,FORELIMXOPS(prem,pref)),
			FORELIMXOPS(concl,pref));
	ELSIF op=REP THEN
		FORPBINOPA(arglist,concl,prem);
		RETURN FORMKBINOP(VEL,FORELIMXOPS(concl,pref),
			FORMKUNOP(NON,FORELIMXOPS(prem,pref)));
	ELSIF (op=EQUIV) AND (pref=VEL) THEN
		FORPBINOPA(arglist,arg1,arg2);
		elimarg1:=FORELIMXOPS(arg1,pref);
		elimarg2:=FORELIMXOPS(arg2,pref);
		RETURN FORMKBINOP(VEL,
				FORMKBINOP(ET,elimarg1,elimarg2),
				FORMKBINOP(ET,
					FORMKUNOP(NON,elimarg1),
					FORMKUNOP(NON,elimarg2)));
	ELSIF (op=EQUIV) AND (pref=ET) THEN
		FORPBINOPA(arglist,arg1,arg2);
		elimarg1:=FORELIMXOPS(arg1,pref);
		elimarg2:=FORELIMXOPS(arg2,pref);
		RETURN FORMKBINOP(ET,
			FORMKBINOP(VEL,FORMKUNOP(NON,elimarg1),elimarg2),
			FORMKBINOP(VEL,elimarg1,FORMKUNOP(NON,elimarg2)));
	ELSIF (op=XOR) AND (pref=VEL) THEN
		FORPBINOPA(arglist,arg1,arg2);
		elimarg1:=FORELIMXOPS(arg1,pref);
		elimarg2:=FORELIMXOPS(arg2,pref);
		RETURN FORMKBINOP(VEL,
			FORMKBINOP(ET,FORMKUNOP(NON,elimarg1),elimarg2),
			FORMKBINOP(ET,elimarg1,FORMKUNOP(NON,elimarg2)));
	ELSIF (op=XOR) AND (pref=ET) THEN
		FORPBINOPA(arglist,arg1,arg2);
		elimarg1:=FORELIMXOPS(arg1,pref);
		elimarg2:=FORELIMXOPS(arg2,pref);
		RETURN FORMKBINOP(ET,
			FORMKBINOP(VEL,elimarg1,elimarg2),
			FORMKBINOP(VEL,
				FORMKUNOP(NON,elimarg1),
				FORMKUNOP(NON,elimarg2)));
	ELSE
		RETURN phi;
	END;
END FORELIMXOPS;


(******************************************************************************
*                              F O R R E P A F S                              *
******************************************************************************)

PROCEDURE FORREPAFS(phi,rep:LIST):LIST;
(* formula replace atomic formulas. phi is a formula. rep is a 
assoc list of the form (old1,new1,old2,new2,...), where old1,... and
new1,.. are atomic formulas. Each occurence of oldi in phi is 
replaced with newi. *)
	VAR op,arg1,arg2,args,argi,found,result: LIST;
	VAR quantifier, bvars: LIST;
BEGIN
	op:=FORGOP(phi);
	IF (op=NON) THEN 
		RETURN FORMKUNOP(NON,FORREPAFS(FIRST(FORGARGS(phi)),rep));
	ELSIF (op=ET) OR (op=VEL) THEN
		args:=FORGARGS(phi);
		result:=SIL;
		WHILE args<>SIL DO 
			ADV(args,argi,args);
			result:=COMP(FORREPAFS(argi,rep),result);
		END;
		RETURN FORMKFOR(op,INV(result));
	ELSIF (op=EXIST) OR (op=FORALL) THEN
		FORPQUANT(phi,quantifier,bvars,arg1);
		RETURN FORMKQUANT(quantifier,bvars,FORREPAFS(arg1,rep));
	ELSIF (op=IMP) OR (op=REP) OR (op=EQUIV) OR (op=XOR) THEN
		FORPBINOP(phi,op,arg1,arg2);
		RETURN FORMKBINOP(op,FORREPAFS(arg1,rep),FORREPAFS(arg2,rep));
	ELSE (* phi is a atomic formula *)
		found:=ASSOCQ(phi,rep);
		IF found=SIL THEN 
			RETURN phi;
		ELSE
			RETURN FIRST(found);
		END;
	END;
END FORREPAFS;

(******************************************************************************
*			  A P P L Y   T O   A T O M			      *
******************************************************************************)

PROCEDURE FORAPPLYAT(phi:LIST; dosomething:PROCF1): LIST;
(* formula apply to atomic formular. phi is a formula; a formular in which all
atomic formulas psi are substituted with dosomething(psi) is returned.  *)
	VAR op, red, arg, arg1, arg2, lvar, psi, name, sort, result: LIST;
BEGIN
	IF phi=SIL THEN RETURN SIL; END;

	FORPFOR(phi,op,red);
	IF (op=VERUM) OR (op=FALSUM) THEN
  		RETURN dosomething(phi)
   	ELSIF op=NON THEN
		FORPUNOPA(red,arg);
		RETURN FORMKUNOP(NON,FORAPPLYAT(arg,dosomething));
   	ELSIF (op=VEL) OR (op=ET) THEN
		result:=SIL;
		WHILE red<>SIL DO
			FORPARGS(red,arg,red);
			result:=COMP(FORAPPLYAT(arg,dosomething),result);
   		END;
		RETURN FORMKFOR(op,INV(result));
	ELSIF (op=IMP) OR (op=REP) OR (op=EQUIV) OR (op=XOR) THEN
		FORPBINOPA(red,arg1,arg2);
		RETURN FORMKBINOP(op,FORAPPLYAT(arg1,dosomething),
			FORAPPLYAT(arg2,dosomething))
	ELSIF (op=EXIST) OR (op=FORALL) THEN
		FORPQUANTA(red,lvar,psi);
		RETURN FORMKQUANT(op,lvar,FORAPPLYAT(psi,dosomething));
	ELSIF op=TVAR THEN
		RETURN dosomething(phi);
	ELSE
		RETURN dosomething(phi);
	END;
END FORAPPLYAT;

PROCEDURE FORAPPLYATF2(phi,param1:LIST; dosomething:PROCF2): LIST;
(* formula apply to atomic formula f2. 
phi is a formula; param1 is an arbitrary list object,
a formula in which all atomic formulas psi are substituted with 
dosomething(psi,param1) is returned.  *)
	VAR op, red, arg, arg1, arg2, lvar, psi, name, sort, result: LIST;
BEGIN
	IF phi=SIL THEN RETURN SIL; END;
	FORPFOR(phi,op,red);
	IF (op=VERUM) OR (op=FALSUM) THEN
  		RETURN dosomething(phi,param1)
   	ELSIF op=NON THEN
		FORPUNOPA(red,arg);
		RETURN FORMKUNOP(NON,FORAPPLYATF2(arg,param1,dosomething));
   	ELSIF (op=VEL) OR (op=ET) THEN
		result:=SIL;
		WHILE red<>SIL DO
			FORPARGS(red,arg,red);
			result:=COMP(FORAPPLYATF2(arg,param1,dosomething),
				result);
   		END;
		RETURN FORMKFOR(op,INV(result));
	ELSIF (op=IMP) OR (op=REP) OR (op=EQUIV) OR (op=XOR) THEN
		FORPBINOPA(red,arg1,arg2);
		RETURN FORMKBINOP(op,FORAPPLYATF2(arg1,param1,dosomething),
			FORAPPLYATF2(arg2,param1,dosomething))
	ELSIF (op=EXIST) OR (op=FORALL) THEN
		FORPQUANTA(red,lvar,psi);
		RETURN FORMKQUANT(op,lvar,
			FORAPPLYATF2(psi,param1,dosomething));
	ELSIF op=TVAR THEN
		RETURN dosomething(phi,param1);
	ELSE
		RETURN dosomething(phi,param1);
	END;
END FORAPPLYATF2;

(******************************************************************************
*                  C O U N T   A T O M I C   F O R M U L A S                  *
******************************************************************************)

PROCEDURE FORCOUNTAF(phi:LIST): LIST;
(* formula count atomic formulas. phi is a formula; 
The number of the atomic formulas in the formula phi is returned. *)
	VAR op, red, arg, arg1, arg2, lvar, psi, number: LIST;
BEGIN
	IF phi=SIL THEN RETURN SIL; END;

	FORPFOR(phi,op,red);
	IF (op=VERUM) OR (op=FALSUM) THEN
  		RETURN 1;
   	ELSIF op=NON THEN
		FORPUNOPA(red,arg);
		RETURN FORCOUNTAF(arg);
   	ELSIF (op=VEL) OR (op=ET) THEN
		number:=0;
		WHILE red<>SIL DO
			FORPARGS(red,arg,red);
			number:=number+FORCOUNTAF(arg);
   		END;
		RETURN number;
	ELSIF (op=IMP) OR (op=REP) OR (op=EQUIV) OR (op=XOR) THEN
		FORPBINOPA(red,arg1,arg2);
		RETURN FORCOUNTAF(arg1)+FORCOUNTAF(arg2)
	ELSIF (op=EXIST) OR (op=FORALL) THEN
		FORPQUANTA(red,lvar,psi);
		RETURN FORCOUNTAF(psi);
	ELSIF op=TVAR THEN
		RETURN 1;
	ELSE
		RETURN 1;
	END;
END FORCOUNTAF;


(******************************************************************************
*	      C O N T A I N S   B O U N D E D   V A R I A B L E		      *
******************************************************************************)

PROCEDURE FORCONTBDVAR(phi:LIST; svar: LIST): BOOLEAN;
(* formula contain bound variable. phi is a formula; svar is a variable;
FORCONTBDVAR returns true, if and only if phi contains svar as a bound
variable. *)
	VAR op, red, arg, arg1, arg2, lvar, psi, varlist, var: LIST;
BEGIN
	IF phi=SIL THEN RETURN FALSE; END;

	FORPFOR(phi,op,red);
	IF (op=VERUM) OR (op=FALSUM) THEN
  		RETURN FALSE;
   	ELSIF op=NON THEN
		FORPUNOPA(phi,arg);
		RETURN FORCONTBDVAR(arg,svar);
   	ELSIF (op=VEL) OR (op=ET) THEN
		WHILE red<>SIL  DO
			FORPARGS(red,arg,red);
			IF FORCONTBDVAR(arg,svar) THEN RETURN TRUE; END;
   		END;
		RETURN FALSE; 
	ELSIF (op=IMP) OR (op=REP) OR (op=EQUIV) OR (op=XOR) THEN
		FORPBINOPA(red,arg1,arg2);
		RETURN FORCONTBDVAR(arg1,svar) OR FORCONTBDVAR(arg2,svar)
	ELSIF (op=EXIST) OR (op=FORALL) THEN
		FORPQUANTA(red,lvar,psi);
		FORPLVAR(lvar,varlist);
		WHILE varlist<>SIL DO
			FORPARGS(varlist,var,varlist);
			IF  EQUAL(svar,var)=1 THEN RETURN TRUE; END; 
		END;
		RETURN FORCONTBDVAR(psi,svar);
	ELSIF op=TVAR THEN
		RETURN FALSE;
	ELSE
		RETURN FALSE;
	END;
END FORCONTBDVAR;


(******************************************************************************
*		      C O N T A I N S   V A R I A B L E			      *
******************************************************************************)

PROCEDURE FORCONTVAR(phi:LIST; svar: LIST; bbcontvar: PROCFB2): BOOLEAN;
(* formula contain variable. phi is a formula; var is a variable; bbcontvar is
a procedure, which tests whether a bb-formula contains a variable or not;
FORCONTVAR returns true, if and only if phi contains var as a free variable.
*)
	VAR op, red, arg, arg1, arg2, lvar, psi, varlist, var: LIST;
BEGIN
	IF phi=SIL THEN RETURN FALSE; END;

	FORPFOR(phi,op,red);
	IF (op=VERUM) OR (op=FALSUM) THEN
  		RETURN FALSE;
   	ELSIF op=NON THEN
		FORPUNOPA(phi,arg);
		RETURN FORCONTVAR(arg,svar,bbcontvar);
   	ELSIF (op=VEL) OR (op=ET) THEN
		WHILE red<>SIL DO
			FORPARGS(red,arg,red);
			IF FORCONTVAR(arg,svar,bbcontvar) THEN RETURN TRUE END;
   		END;
		RETURN FALSE;
	ELSIF (op=IMP) OR (op=REP) OR (op=EQUIV) OR (op=XOR) THEN
		FORPBINOPA(red,arg1,arg2);
		RETURN FORCONTVAR(arg1,svar,bbcontvar) OR
			FORCONTVAR(arg2,svar,bbcontvar)
	ELSIF (op=EXIST) OR (op=FORALL)	THEN
		FORPQUANTA(red,lvar,psi);
		FORPLVAR(lvar,varlist);
		WHILE varlist<>SIL  DO
			FORPARGS(varlist,var,varlist);
			IF EQUAL(svar,var)=1 THEN RETURN FALSE; END; 
		END;
		RETURN FORCONTVAR(psi,svar,bbcontvar);
	ELSIF op=TVAR THEN
		RETURN EQUAL(svar,var)=1;
	ELSE
		RETURN bbcontvar(phi,var);
	END;
END FORCONTVAR;


(******************************************************************************
*	    G E N E R A L   A U X I L I A R Y   P R O C E D U R E S           *
******************************************************************************)

PROCEDURE notsymbol(sym :LIST): LIST;
(* not symbol. sym is a symbol of the set {VERUM, FALSUM, VEL, ET, IMP, REP,
EQUIV, XOR, FORALL, EXIST}; returns the (defined) negation of this symbol. *)
BEGIN
	IF sym=VERUM	THEN RETURN FALSUM;	END;
	IF sym=FALSUM	THEN RETURN VERUM;	END;
	IF sym=VEL	THEN RETURN ET;		END;
	IF sym=ET	THEN RETURN VEL;	END;
	IF sym=EXIST	THEN RETURN FORALL;	END;
	IF sym=FORALL	THEN RETURN EXIST;	END;
	IF sym=IMP	THEN RETURN REP;	END;
	IF sym=REP	THEN RETURN IMP;	END;
	IF sym=EQUIV	THEN RETURN XOR;	END;
	IF sym=XOR	THEN RETURN EQUIV;	END;
END notsymbol;


PROCEDURE formkneg(phi:LIST; bbmkneg: PROCF1): LIST;
(* formula make negation. phi is a formula, bbmkneg a procedure to negate a
bb-formula, a simplification of a negation of phi is returned. *)
	VAR op, arg, left, right: LIST;
BEGIN
	FORPFOR(phi,op,arg);
	IF op=VERUM THEN
		RETURN FORMKCNST(FALSUM)
	ELSIF op=FALSUM THEN
		RETURN FORMKCNST(VERUM)
	ELSIF op=NON THEN
		RETURN arg;
	ELSIF (op=VEL) OR (op=ET) OR (op=IMP) OR (op=REP) OR
		(op=TVAR) OR (op=EXIST) OR (op=FORALL) THEN
		RETURN FORMKUNOP(NON,phi);
	ELSIF op=EQUIV THEN
		FORPBINOPA(arg,left,right);
		RETURN FORMKBINOP(XOR,left,right);
	ELSIF op=XOR THEN
		FORPBINOPA(arg,left,right);
		RETURN FORMKBINOP(EQUIV,left,right);
	ELSIF op=TVAR THEN 
		RETURN FORMKUNOP(NON,phi);
	ELSE
		RETURN bbmkneg(phi);
	END;
END formkneg;


(******************************************************************************
*				   M A I N				      *
******************************************************************************)

(* BEGIN *) (* OF INITIALIZATION *)

END MASLOG.

(* -EOF- *)
