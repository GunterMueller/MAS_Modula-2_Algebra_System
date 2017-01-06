(* ----------------------------------------------------------------------------
 * $Id: RQEPRRC.mi,v 1.3 1996/05/19 07:54:56 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1994 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: RQEPRRC.mi,v $
 * Revision 1.3  1996/05/19 07:54:56  dolzmann
 * Fixed a bug in RqeNoEq.
 *
 * Revision 1.2  1995/11/04  18:00:30  pesch
 * Changed comments violating documentation rules. Should be rewritten.
 *
 * Revision 1.1  1994/11/28  21:10:06  dolzmann
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

IMPLEMENTATION MODULE RQEPRRC;
(* Real Quantifier Elimination with Parametric Real Root Count. *)

(******************************************************************************
*                                R Q E C G B                                  *
*-----------------------------------------------------------------------------*
* Author:   Andreas Dolzmann                                                  *
* Language: Modula II                                                         *
* System:   This program is written for the computer algebra system MAS by    *
*           Heinz Kredel.                                                     *
* Abstract: A program for quantifier elimination for the theory of the real   *
*           numbers.                                                          *
*           The quantifier elimination algorithm is described                 *
*           in Volker Weispfenning, A New Approach to Quantifier Elimination  *
*           for Real Algebra; Universitaet Passau; MIP 9305 July 1993.        *
******************************************************************************)

FROM ADTOOLS	IMPORT	INTDDCMP, IPDDADV, IPDDCMP, IPDECMP, RFDDADV,
			RFDDFIPDD;
FROM CGBDSTR	IMPORT	CdpCons, CondCons, CondEmpty, CondIsEmpty, CondParts,
			CondWrite, FormFCond, GsParts, GsS, GsWrite, VdCons,
			VdD, VdV;
FROM CGBFUNC	IMPORT	GREPOL;
FROM CGBMISC	IMPORT	EvordReset, EvordSet, PAR, ValisReset, ValisSet;
FROM CGBMAIN	IMPORT	GSYS, GSYSRED;
FROM DIPADOM	IMPORT	DILWR, DIPNEG, DIPROD, DIPSUM, DIWRIT;
FROM DIPC	IMPORT	DILPERM, DIPBSO, DIPERM, DIPFP, DIPINV, DIPLPM,
			DIPMAD, DIPMCP, EVORD, PFDIP, VALIS;
FROM DIPDIM	IMPORT	DILDIM, IXSUBS;
FROM DIPRF	IMPORT	RFDEN, RFNOV, RFNUM;
FROM DIPTOOLS	IMPORT	ADDDFDIL, ADDDFDIP, ADPFDIP, DILCONV, DILINV, DILMOC,
			DIMPAD, DIPCNST, DIPCNSTR, DIPCT, DIPDEGI, DIPFADIP,
			DIPFDIPP, DIPFIP, DIPIMO, DIPONE, DIPPAD, DIPPFDIP,
			DIPXCM, EVCNSTR, EvordPop, EvordPush, VVECC,
			VVECFVLIST, ValisPop, ValisPush;
FROM LINALG	IMPORT	ADCHARPOL, ADSIG, ADUM, ADVWRITE;
FROM LISTTOOLS	IMPORT	LIST6, LPAIRS, LSRCHQ;
FROM MASADOM	IMPORT	ADFI, ADPROD, ADSIGN, ADWRIT;
FROM MASBIOS	IMPORT	BKSP, BLINES, CREAD, CREADB, DIGIT, LETTER, LISTS,
			MASORD, SWRITE;
FROM MASCOMB	IMPORT	INVPERM, PVFLISTS;
FROM MASELEM	IMPORT	GAMMAINT;
FROM MASERR	IMPORT	ERROR, fatal, harmless, severe, spotless;
FROM MASLOG	IMPORT	FORAPPLYAT, FORAPPLYATF2, FORMKPRENEXI;
FROM MASSET	IMPORT	SetComplementQ;
FROM MASSTOR	IMPORT	ADV, COMP, FIRST, INV, LENGTH, LIST, LIST1, LISTVAR,
			RED, SFIRST, SIL, SRED, TIME;
FROM MASSYM2	IMPORT	UWRIT1, UWRITE;
FROM MLOGBASE	IMPORT	ANY, ET, EXIST, FALSUM, FORALL, FORGARGS, FORGLVAR,
			FORGOP, FORMKBINOP, FORMKFOR, FORMKLVAR, FORMKQUANT,
			FORMKUNOP, FORMKVAR, FORPFOR, FORPQUANT, FORPVAR,
			FORVTENTER, FORVTGET, NON, VEL, VERUM;
FROM PQBASE	IMPORT	EQU, GRE, GRQ, LES, LSQ, NEQ, PQELIMXOPS, PQMKCNF,
			PQMKDNF, PQMKPOS, PQPPRT, PQPRING, PQSIMPLIFY,
			PQSIMPLIFYP, PQSMPL, lvarfvlist, pqmkaf, pqpaf,
			vlistflvar;
FROM RRADOM	IMPORT	RRADPOLMATRIX, RRADQUADFORM, RRADSTRCONST,
			RRADVARMATRICES, RRREDTERMS;
FROM SACCOMB	IMPORT	LPERM;
FROM SACIPOL	IMPORT	IPPROD;
FROM SACLIST	IMPORT	ADV2, ADV3, AREAD, AWRITE, CCONC, CINV, CLOUT, COMP2,
			COMP3, CONC, EQUAL, FIRST2, FIRST3, FIRST4, FOURTH,
			LAST, LELT, LIST2, LIST3, LIST4, LIST5, LWRITE,
			MEMBER, OWRITE, RED2, SECOND, THIRD;
FROM SACPOL	IMPORT	VLREAD, VLWRIT;
FROM SYSINFO	IMPORT	SYSINFO, SysInfoStart, SysInfoStop, SysInfoWrite;
FROM TFORM	IMPORT	TFPPRT, TfTypeFormula, tfmkaf, tfpaf; 

CONST rcsidi = "$Id: RQEPRRC.mi,v 1.3 1996/05/19 07:54:56 dolzmann Exp $";
CONST copyrighti = "Copyright (c) 1994 Universitaet Passau";

(******************************************************************************
*                       G L O B A L   V A R I A B L E S                       *
******************************************************************************)

VAR PolFmtStack: LIST;
(* ***************************************************************************
For temporary changing of the contents of the variable PolFmt 
we define a stack to store and restore old contents of PolFmt.
*************************************************************************** *)

VAR RqeIterate: BOOLEAN;
(* ***************************************************************************
We use the global variable RqeIterate to control the iteration 
of the quantifier elimination of quantifier blocks. If only zero 
dimensional ideals are eliminated, then the result formula can contain
quantifiers. In this case we cannot iterate the elimination procedure.
If an ideal with a dimension greater than 0 occurs and 
RqeOpt.DimensionZeroOnly is true, then  the variable RqeIterate 
is set to true.
*************************************************************************** *)

VAR AdjoinedEq: BOOLEAN; (* TRUE, if RqeNoEq is active. *)
(* ***************************************************************************
We know from the theory, that the adjoined equation is not trivial. 
Instead of adjoining the non-trivial condition to the conjunction, 
we call the elimination procedure for the conjunction over the side 
conditions and the adjoined equation. During the elimination of this 
conjunction the n-dimensional case can be entered. In this case 
we do not make a recursion but we generate the elimination result FALSE.
We use the global variable AdjoinedEq to mark, that a equation was 
adjoined to the input. RqeNoEq terminates with the result FALSUM, 
if AdjoinedEq is TRUE. 
*************************************************************************** *)

(******************************************************************************
*                            T E R M I N O L O G Y                            *
******************************************************************************)

(* 
"formula":
==========
With the term formula we denotes a formula of the polynomial equation system
(short "PQ-SYSTEM") It is a formula in the language of ordered rings. 
The terms in these formulas are represented as distributive polynomials over
an arbitrary domain. 
For technical reasons, we can use only the domain INT in this package. 

"common polynomial format":
=========================== 
Distributive polynomials over the domain INT. Z[U_1,...,U_m,X_1,...,X_n]

"recursive polynomial format":
==============================
Distributive polynomials over the domain IP. Z[U_1,...,U_m][X_1,...,X_n]

"parameter polynomial format":
==============================
Elements of the arbitrary domain IP. Z[U_1,...,U_m].

"XPL" (extracted polynomial list)
=================================
A XPL (w.r.t. to a variable list V) represents a conjunction of atomic 
formulas. 
A XPL has the following form (NC,C), where 
NC=(E,G,N) and C=(CLES, CLEQ, CEQ, CNEQ, CGEQ, CGR).
Each element E, G, CLES, CLEQ, CEQ, CNEQ, CGEQ, and CGR is a list of 
distributive polynomials in the common polynomial format. 
The list NC of a XPL contains polynomials in which at least one 
variable of V occurs. The list C contains only polynomials in which no 
variable of V occurs.
Let A a list of polynomials. We define A rho 0 as the conjunction 
and a in A a rho 0. Then a XPL represents the formula 
AND E=0 and AND G>0 and AND N<>0 and 
AND CLES<0 and AND CLEQ<=0 and AND CEQ=0 and 
AND CNEQ<>0 and AND CGEQ>=0 and CGR>0.
*)

(******************************************************************************
*                            E L I M I N A T I O N                            *
******************************************************************************)

PROCEDURE RQEQE(phi:LIST):LIST;
(* real quantifier elimination quantifier elimination.  
phi is a formula. 
A formula psi equivalent to phi is returned. 
All quantifiers must bound different variables. No variable
is allowed to occur free and bound.  An automatic renaming of
variables is not done. Atomic formulas must be truth values or must
have the form "(rel term)", where rel is an relation and term is
distributive polynomial over the domain INT.  All atomic formulas of
the latter form of atomic formulas must contains polynomials in the
same polynomial ring, which is determined by the global variables
VALIS, EVORD , and DOMAIN. 
In the normal case psi contains no quantifier. 
See the documentation of the options of the RQE-SYSTEM for more informations.
The global variables VALIS, EVORD and DOMAIN must be set 
appropriately. The options for the CGB-SYSTEM must be set appropriately.
VALIS must contain the variable list of the polynomials used in the 
atomic formulas. 
EVORD must contain the term order of the polynomials used in the 
atomic formulas. 
DOMAIN must contain the domain descriptor for the PQ-SYSTEM.
Only the domain INT is valid.
The term orders of the CGB-SYSTEM and the variable EVORD must be set
compatible. All term orders should be equal.
Tracing of intermediate output, conditions to the output formula and other 
things are controlled by the RqeOpt variable.
This procedure calls the CGB-SYSTEM. Use the options of this system for 
controlling the computation of an Groebner system.
*)
	VAR psi: LIST;
	VAR qf, vars, bvlist: LIST;
	VAR quantifiers, bvariables: LIST;
	VAR s: SYSINFO;
BEGIN
	SysInfoStart(s);
	IF phi=SIL THEN RETURN SIL; END;
	psi:=PQSIMPLIFY(FORMKPRENEXI(PQMKPOS(PQELIMXOPS(PQSMPL(phi))),EXIST));
	IF RqeOpt.TraceLevel > 0 THEN 
		IF RqeOpt.TraceLevel > 2 THEN 
			SWRITE("Input in prenex normal form");BLINES(0);
			PQPPRT(psi);
		END;
		BLINES(0);SWRITE("[");
	END;
	qf:=FORGOP(psi);
	quantifiers:=SIL;
	bvariables:=SIL;
	WHILE (qf=EXIST) OR (qf=FORALL) DO
		FORPQUANT(psi,qf,vars,psi);
		quantifiers:=COMP(qf,quantifiers);
		bvariables:=COMP(vars,bvariables);
		qf:=FORGOP(psi);
	END;
	IF RqeOpt.TraceLevel > 0 THEN
		IF RqeOpt.TraceLevel > 1 THEN
			SWRITE("Number of quantifier blocks: ");
			UWRITE(LENGTH(quantifiers));
		ELSE 
			SWRITE(" QB=");UWRIT1(LENGTH(quantifiers));SWRITE(" ");
		END;
	END;
	RqeIterate:=TRUE;
	WHILE (quantifiers<>SIL) AND (psi <> VERUM) AND (psi<>FALSUM) 
		AND RqeIterate 
	DO
		ADV(quantifiers,  qf,quantifiers);
		ADV(bvariables,  vars,bvariables);
		bvlist:=vlistflvar(vars);	
		IF RqeOpt.TraceLevel > 0 THEN
			IF RqeOpt.TraceLevel > 1 THEN
				SWRITE("Elimination of an "); UWRIT1(qf);
				SWRITE(" quantifier"); BLINES(0);
				SWRITE("bound Variables"); VLWRIT(bvlist); 
				BLINES(0);
			ELSE
				SWRITE(" QB ");
			END;
		END;
		IF qf=FORALL THEN
			psi:=PQMKPOS(FORMKUNOP(NON,psi));
		END;
		(* Eliminate an existential quantifier. *)
		psi:=PQSIMPLIFY(RqeExists(psi,bvlist)); 
		IF qf=FORALL THEN
			psi:=PQMKPOS(FORMKUNOP(NON,psi));
		END;
		IF RqeOpt.TraceLevel > 2 THEN
			SWRITE("Result of the elimination:");BLINES(0);
			PQPPRT(psi);BLINES(0);
		END;
	END;
	IF NOT RqeIterate THEN
		WHILE quantifiers<>SIL DO
			ADV(quantifiers,  qf, quantifiers);
			ADV(bvariables,  vars,bvariables);
			psi:=FORMKQUANT(qf,vars,psi);
		END;
	END;
	SysInfoStop(s);
	IF RqeOpt.TraceLevel > 0 THEN 
		IF RqeOpt.TraceLevel > 1 THEN 
			SysInfoWrite(s);
		END;
		SWRITE("]");BLINES(0);
	END;
		RETURN psi;
END RQEQE;

PROCEDURE RqeExists(phi,bvlist: LIST):LIST;
(* real quantifier elimination exists. 
phi is a quantifier free formula. 
bvlist is a variable list. 
A quantifier free equivalent of the formula (EX bvlist: phi) is returned. 
The global variables VALIS, EVORD DOMAIN must be set 
appropriately. *)
	VAR psi, result,conj, InterRes: LIST;
BEGIN
	psi:=PQMKDNF(RQERSNF(phi,bvlist,VALIS));
	psi:=FORGARGS(psi);
	IF RqeOpt.TraceLevel > 0 THEN
		IF RqeOpt.TraceLevel > 1 THEN
			SWRITE("Number of arguments of the disjunction:");
			UWRITE(LENGTH(psi));
		ELSE
			SWRITE("CS=");UWRIT1(LENGTH(psi));SWRITE(" ");
		END
	END;
	result:=SIL;
	WHILE psi<>SIL DO
		ADV(psi,  conj,psi);
		IF RqeOpt.TraceLevel > 0 THEN
			IF RqeOpt.TraceLevel > 1 THEN
				SWRITE("Eliminating one conjunction.");
				BLINES(0);
				IF RqeOpt.TraceLevel > 2 THEN
					PQPPRT(conj);
					BLINES(0);
				END;
			ELSE
				SWRITE(" CS ");
			END;
		END;		
		InterRes:=RqeConjunction(conj,VERUM,bvlist);
		IF InterRes=VERUM THEN RETURN VERUM; END;
		result:=COMP(InterRes,result);
	END;
	RETURN FORMKFOR(VEL,INV(result));
END RqeExists;

PROCEDURE RqeConjunction(phi,psi,bvlist: LIST):LIST;
(* real quantifier elimination conjunction. 
phi is a conjunction of  atomic formulas of the form (f=0),(f<>0), or (f>0). 
psi is a conjunction of atomic formulas with polynomials constant w.r.t. 
bvlist or the truth values VERUM or FALSUM. 
A formula gamma is returned. 
(gamma and psi) is equivalent to ( (ex bvlist(phi)) and psi).
The result of the elimination of (EX bvlist: phi) is returned.
The global variables VALIS, EVORD DOMAIN must be set 
appropriately. *)
	VAR E, G, N, fvlist, perm, newdd, result,qff,p: LIST; 
	VAR gsys, S, VD, CD, Cond, Plist, CP: LIST;
	VAR pols,pols2,NC: LIST;
	VAR Initial: LIST;
	VAR s: SYSINFO;
BEGIN
	IF psi=FALSUM THEN RETURN FALSUM; END;
	pols:=ExtractPolynomials(phi,bvlist,VALIS);
	NC:=FIRST(pols);
	ADV(NC,  E,NC); ADV(NC,  G,NC); ADV(NC,  N,NC);
	(* phi is independent from bound variables. *)
	IF (E=SIL) AND (G=SIL) AND (N=SIL) THEN 
		RETURN phi;
	(* phi is a conjunction of formulas of the form h<>0. *)
	ELSIF (E=SIL) AND (G=SIL) THEN
		result:=SIL;
		WHILE N<>SIL DO
			ADV(N,  p,N);
			result:=COMP(nontrivial(p,bvlist,VALIS),result);
		END;
		result:=FORMKFOR(ET,INV(result));
		result:=FORMKBINOP(ET,result,PqFC(SECOND(pols)));
		RETURN result
	(* No non-trivial equation is present. *)
	ELSIF E=SIL THEN
		IF RqeOpt.DimensionZeroOnly THEN
			RqeIterate:=FALSE;
			RETURN FORMKQUANT(EXIST,lvarfvlist(bvlist),phi);
		ELSE
			RETURN RqeNoEq(phi,bvlist);
		END;
	END;
	fvlist:=SetComplementQ(bvlist,VALIS);
	newdd:=IPDDCMP(fvlist);
	E:=CommonPol2RecPolL(E,fvlist,bvlist,VALIS,  perm);
	PolFmtPush(VALIS,bvlist,fvlist,perm);
		Initial:=CondFC(SECOND(pols));
		IF psi<>VERUM THEN 
			pols2:=ExtractPolynomials(psi,bvlist,VALIS);
			Initial:=CondUnion(Initial,CondFC(SECOND(pols2)));
		END;
		IF RqeOpt.TraceLevel > 1 THEN
			SWRITE("Computing a reduced Groebner system ...");
			SysInfoStart(s);	
			BLINES(0);
		END;
		gsys:=GSYSRED(GSYS(cgbinput1(E,bvlist,newdd,Initial)));
		IF RqeOpt.TraceLevel > 1 THEN 	
			SysInfoStop(s);
			SWRITE(" finished.");BLINES(0);
			SysInfoWrite(s);
		END;
	GsParts(gsys,  S,VD,CD);
	IF RqeOpt.TraceLevel > 0 THEN 
		IF RqeOpt.TraceLevel >1 THEN 
			SWRITE("Number of cases in the Groebner system: ");
			UWRITE(LENGTH(S));
		ELSE
			SWRITE(" B=");UWRIT1(LENGTH(S));SWRITE(" ");
		END;
	END;
	result:=SIL;
	qff:=FALSUM;
	WHILE (S<>SIL) AND (qff<>VERUM) DO
		ADV(S,  CP,S);
		FIRST2(CP,  Cond,Plist);
		Plist:=GREPOL(Plist);
		IF RqeOpt.TraceLevel>0  THEN 
			IF RqeOpt.TraceLevel > 1 THEN 
				SWRITE("Handle one case of the Groebner system.");
				BLINES(0);
				IF RqeOpt.TraceLevel > 2 THEN
					CondWrite(Cond);
				END;	
			ELSE
				SWRITE(" B ");
			END;
		END;
		qff:=PQSIMPLIFY(RqeBranch(Cond,Plist,G,N,SECOND(pols)));
		result:=COMP(PQSIMPLIFY(qff),result);
	END;

	IF qff<>VERUM THEN
		result:=FORMKFOR(VEL,INV(result));
		result:=FORMKBINOP(ET,PqFC(SECOND(pols)),result);
	ELSE
		result:=PqFC(SECOND(pols));
	END;
	PolFmtPop();
	RETURN PQSIMPLIFYP(result,2);	
END RqeConjunction;

PROCEDURE RqeBranch(Cond, Plist, Gre, Neq, CPols:LIST):LIST;
(* real quantifier elimination eliminate branch.
Cond is a condition (terminology of the CGB-package)
Plist is a list of polynomials in Z[U_1,...,U_m][X_1,...,X_m]. 
Gre, Neq are lists of distributive polynomials in K[U_1,...,U_m,X_1,...,X_n].
A formula phi is returned. phi is true iff the ideal ID(PLIST) have 
at least one real zero which suffices the side conditions G > 0 and N # 0. 
Cpols is a C part of a XPL. *)
		VAR d,n,Smaxvl,newdd,D,res,perm,dep,indep: LIST;
BEGIN
	ValisPush(PolFmt.BoundVars);
	d:=DIMISS(Plist,PolFmt.BoundVars,  Smaxvl);
	n:=LENGTH(VALIS);
	IF RqeOpt.TraceLevel > 1 THEN
		SWRITE("Dimension of the ideal = ");UWRITE(d);
	END;
	IF d=0 THEN 
		WITH PolFmt DO
			ValisPush(AllVars);
			Gre:=CommonPol2RecPolL(Gre,FreeVars,BoundVars,VALIS,  perm);
			Neq:=CommonPol2RecPolL(Neq,FreeVars,BoundVars,VALIS,  perm);
			ValisPop();
		END;
		D:=ADDDFDIL(Plist);		(* d=0: PLIST not empty!: *)
		IF RqeOpt.TraceLevel > 2 THEN
			BLINES(0);
			SWRITE("Groebner Basis:");
			DILWR(Plist,PolFmt.BoundVars);
			BLINES(0);
			SWRITE("Side conditions '>':");
			DILWR(Gre,PolFmt.BoundVars);
			BLINES(0);
			SWRITE("Side conditions '<>':");
			DILWR(Neq,PolFmt.BoundVars);
		END;
		Plist:=DILCONV(Plist,RFDDFIPDD(D));
		Gre:=DILCONV(Gre,RFDDFIPDD(D));
		Neq:=DILCONV(Neq,RFDDFIPDD(D));
		res:=RQEPRRC(Plist,Gre,Neq);
		IF NOT CondIsEmpty(Cond) THEN 
			res:=FORMKBINOP(ET,PqFCond(Cond),res);
		END;
	ELSIF ((d>0) AND (d<n)) AND RqeOpt.DimensionZeroOnly THEN
		ValisPush(PolFmt.AllVars);
		res:=forfdata(Cond,Plist,Gre,Neq);
		res:=FORMKBINOP(ET,res,PqFC(CPols));
		res:=FORMKQUANT(EXIST,lvarfvlist(PolFmt.BoundVars),res);
		ValisPop();
		RqeIterate:=FALSE;
	ELSIF (d>0) AND (d<n) THEN
		res:=forfdata(Cond,Plist,Gre,Neq);
		res:=FORMKBINOP(ET,res,PqFC(CPols));
		indep:=FIRST(Smaxvl);
		dep:=SetComplementQ(indep,PolFmt.BoundVars);
		res:=FORMKQUANT(EXIST,lvarfvlist(dep),res);
		IF RqeOpt.TraceLevel>=2 THEN 
			SWRITE("first recursive call of RQEQE in the case 0 < d < n");
			BLINES(0);
			SWRITE("eliminating the variables: ");BLINES(0);
			VLWRIT(dep);BLINES(0);
			SWRITE("in the formula");BLINES(0);
			ValisPush(PolFmt.AllVars);
			PQPPRT(res);BLINES(0);
			ValisPop();
		END;
		ValisPush(PolFmt.AllVars);
		res:=RQEQE(res);
		ValisPop();
		res:=FORMKQUANT(EXIST,lvarfvlist(indep),res);
		IF RqeOpt.TraceLevel>=2 THEN 
			SWRITE("second recursive call of RQEQE in the case 0 < d < n");
			BLINES(0);
			SWRITE("eliminating the variables: ");BLINES(0);
			VLWRIT(indep);BLINES(0);
			SWRITE("in the formula");BLINES(0);
			ValisPush(PolFmt.AllVars);
			PQPPRT(res);BLINES(0);
			ValisPop();
		END;
		ValisPush(PolFmt.AllVars);
		res:=RQEQE(res);
		ValisPop();
	ELSIF (d=n) AND RqeOpt.DimensionZeroOnly THEN
		ValisPush(PolFmt.AllVars);
		res:=forfdata(Cond,Plist,Gre,Neq);
		res:=FORMKBINOP(ET,res,PqFC(CPols));
		res:=FORMKQUANT(EXIST,lvarfvlist(PolFmt.BoundVars),res);
		ValisPop();
		RqeIterate:=FALSE;
	ELSIF (d=n) THEN
		res:=forfdata(Cond,SIL,Gre,Neq);
		res:=FORMKBINOP(ET,res,PqFC(CPols));
		res:=FORMKQUANT(EXIST,lvarfvlist(PolFmt.BoundVars),res);
		ValisPush(PolFmt.AllVars);
		res:=RQEQE(res);
		ValisPop();
	ELSIF d=-1 THEN
		res:=FALSUM;
	ELSE
		ERROR(severe,"RqeBranch: incorrect dimension -1>d or d>n.");
		res:=FALSUM; (* dummy *)
	END;
	ValisPop();
	RETURN res;
END RqeBranch;

(******************************************************************************
*             P A R A M E T R I C   R E A L   R O O T   C O U N T             *
******************************************************************************)

PROCEDURE RQEPRRC(G,F,NQ: LIST):LIST;
(* real quantifier elimination parametric real root count.
G is a Groebner basis, 
F is a list of side conditions of the form f > 0,
NQ is a list of side conditions of the form f <> 0.
A formula phi is returned. phi is true iff the ideal ID(PLIST) have 
at least one real zero which suffices the side conditions G > 0 and N # 0. *) 
	VAR R,E,U,Q,beta,s:LIST;
	VAR D:LIST;
	VAR prod:LIST;
	VAR tf,ct,deg,i,ctp,c: LIST;
	VAR result: LIST;
	VAR TotalS,sysinfo: SYSINFO;
BEGIN
	SysInfoStart(TotalS);
	G:=DIPLPM(DILMOC(G));
	D:=ADDDFDIL(G);			(* Determine the domain descriptor. *)
	R:=RRREDTERMS(G);		(* Compute the reduced terms. 	    *)
	E:=ADUM(D,LENGTH(R));		(* Unit matrix.			    *)
	RRADSTRCONST(D,G,R,  U,beta);	(* Structure constants.		    *)
	Q:=RRADQUADFORM(D,R,U,beta,E);	(* The matrix Q.		    *)
	SysInfoStart(sysinfo);
	IF (F<>SIL) OR (NQ<>SIL) THEN
		prod:=PiChi(F,NQ,G,R,U,beta);
	ELSE
		prod:=CharPolQ1(G,R,U,beta);
	END;
	SysInfoStop(sysinfo);
	IF RqeOpt.TraceLevel >= 2 THEN 
		SWRITE("Time for computation of characteristic polynomial: ");
		BLINES(0);
		SysInfoWrite(sysinfo);
	END; 
	ct:=DIPCT(prod);	(* Coefficient tuple of prod. *)
	deg:=LENGTH(ct)-1;
	IF RqeOpt.TraceLevel>2 THEN 
		i:=0;
		BLINES(0);
		SWRITE("Type formula to compute: T");
		UWRIT1(deg);
		SWRITE("(c), where");
		BLINES(0);
		ctp:=ct;
		WHILE ctp<>SIL DO 
			ADV(ctp,c,ctp);
			SWRITE("c");AWRITE(i);SWRITE(" = ");
			SWRITE("  ");
			ADWRIT(c);
			BLINES(0);
			i:=i+1;
		END;
	END;
		SysInfoStart(sysinfo);
	tf:=TfTypeFormula(deg);
	SysInfoStop(sysinfo);
	IF RqeOpt.TraceLevel >=2 THEN 
		SWRITE("Time for computing type formula: ");BLINES(0);
		SysInfoWrite(sysinfo);
	END;
	result:=FORMKUNOP(NON,TfEvalVars(tf,ct));
	SysInfoStop(TotalS);
	IF RqeOpt.TraceLevel >= 2 THEN 
		SWRITE("Time for real root count: ");BLINES(0);
		SysInfoWrite(TotalS);
	END;
	RETURN result;
END RQEPRRC;

(******************************************************************************
*             C H A R A C T E R I S T I C   P O L Y N O M I A L S             *
******************************************************************************)

PROCEDURE CharPolQ1(G,R,U,beta:LIST):LIST;
(* characteristic polynomial of the matrix Q_1.
G is a reduced Groebner basis, (Polynomials in K(U)[X]), 
R is the set of reduced terms,
U = R x R,
beta is the matrix of structure constants w.r.t. R.
The characteristic polynomial of the matrix Q_1 is returned. 
The returned polynomial is a univariate distributive polynomial over 
the domain RF. *)
	VAR D, L, CVL, chiq1: LIST;
	VAR s: SYSINFO;
BEGIN
	CVL:=LIST1(LISTS("Y"));		(* The variable list for Char-Pol. *)
	D:=ADDDFDIL(G);
	L:=RRADVARMATRICES(G,R,U,beta);
	chiq1:=ChiQf(DIPONE(D),D,R,U,beta,  L);	(* Compute the X_Q_f. *)
	RETURN chiq1;
END CharPolQ1;

PROCEDURE PiChi(F,N,G,R,U,beta: LIST): LIST;
(* product of characteristic polynomials.
F is a list of side conditions of the form f > 0 ,
N is a list of side conditions of the form f <> 0,
G is Groebner basis,
R is the set od reduced terms,
U = R x R 
beta: matrix of structure constants.
Returns the product $PI_{e\in \{1,2\}^s} X_{Q_{f^e}}$.
This product is a univariate polynomial in Z(U)[Y].
F or N is not empty and contains at least a polynomial not equal to 0. *)
		VAR D, FC, CVL, L, chiqf, f, ev, ChiProd, FProd,i: LIST;
		VAR s, TotalS: SYSINFO;
BEGIN
	IF (F=SIL) AND (N=SIL) THEN 
		RETURN CharPolQ1(G,R,U,beta);
	END;
	IF F<>SIL THEN
		D:=ADDDFDIL(F);		(* The domain descriptor from f. *)
	END;
	IF (F=SIL) OR (D=0) THEN 
		D:=ADDDFDIL(N);
	END;	
	IF D=0 THEN 
		ERROR(severe,"ChiQf: Cannot determine domain descriptor!");
		RETURN SIL;
	END;
	CVL:=LIST1(LISTS("Y"));		(* The variable list for the Chi. *)
	L:=RRADVARMATRICES(G,R,U,beta);
	FProd:=DIPONE(D);	(* Initialize the product of f_i^{e_i}. *)
	ValisPush(CVL);
	ChiProd:=DIPONE(D);  	(* Initialize the product of all Chi.  *)
	ValisPop();
	FC:=F;
	WHILE FC<>SIL DO
		ADV(FC,  f,FC);
		FProd:=DIPROD(FProd,f);
	END;
	FC:=N;
	WHILE FC<>SIL DO
		ADV(FC,  f,FC);
		FProd:=DIPROD(FProd,DIPROD(f,f));
	END;
		IF F=SIL THEN 
			(* Only one characteristic polynomial have to be computed. *)
			chiqf:=ChiQf(FProd,D,R,U,beta,  L);
			RETURN chiqf;
		END;
	ev:=SIL;
	FOR i:=1 TO LENGTH(F) DO
		ev:=COMP(0,ev);
	END;
	REPEAT
		NextProduct(F,ev,f);		(* Next exponent tuple.	*)
		f:=DIPROD(f,FProd);		(* Compute the product.	*)
		chiqf:=ChiQf(f,D,R,U,beta,  L);	(* Compute the X_Q_f	*)
		ValisPush(CVL);
		ChiProd:=DIPROD(ChiProd,chiqf);
		ValisPop();
	UNTIL ev=SIL;
	RETURN ChiProd;
END PiChi;

PROCEDURE ChiQf(f,D,R,U,beta:LIST;  VAR L:LIST):LIST;
(* chi q f. 
f is a polynomial in Z(U)[X]
D is the domain descriptor of Z(U)
R is the set od reduced terms,
U = R x R,
beta is the matrix of structure constants.
Returns the characteristic polynomial of Q_f.
L contains nonempty lists L(i) of the form 
j(1),M(1),j(2),M(2),...,j(k),M(k) with 1=j(1)<j(2)<...<j(k) and M(l) ist 
the matrix of multiplication with X(i)**j(l) for the variable X(i).
L must be initialized, L is updated.  *)
	VAR Q,Mf: LIST;
	VAR ChiCoeff,Chi,Coeff,zero: LIST;
	VAR i: LIST;
	VAR s,t: SYSINFO;
BEGIN
	RRADPOLMATRIX(D,R,f,  Mf,L);
	Q:=RRADQUADFORM(D,R,U,beta,Mf);
	ChiCoeff:=INV(ADCHARPOL(D,Q));
	Chi:=SIL;
	i:=0;
	zero:=ADFI(D,0);
	WHILE ChiCoeff<>SIL DO;
		ADV(ChiCoeff,  Coeff,ChiCoeff);
		IF EQUAL(Coeff,zero)=0 THEN
			Chi:=DIPMCP(Coeff,LIST1(i),Chi);
		END;
		i:=i+1;
	END;
	RETURN Chi;
END ChiQf;

PROCEDURE NextProduct(F:LIST;  VAR last,PF: LIST);
(* next product. 
F is a not empty list of polynomials.
last is an exponent vector of length |F| with entries of {0,1}.
The lexicographic next exponent vector is computed non constructive.
The product $PF:=\Pi f_i^{e_i}$ is computed. 
If there is no next exponent vector, then last is set to SIL.
The global variable VALIS must be set. *)
	VAR lp,lpp,e,f: LIST;
BEGIN
(*0*)	(* Special case. *)
	IF last=SIL THEN last:=SIL; RETURN; END;
(*1*)	(* Initialization. *)
	PF:=DIPONE(ADDDFDIL(F));
	lp:=last;
(*2*)	(* Compute next vector and product. *)
	REPEAT
		ADV(lp,  e,lpp);
		ADV(F,  f,F);
		IF e=0 THEN
			SFIRST(lp,1);
		ELSIF e=1 THEN
			SFIRST(lp,0);
			PF:=DIPROD(PF,f);
		ELSE
			ERROR(severe,"NextProduct: incorrect exponent.");
		END;
		lp:=lpp;
	UNTIL (lp=SIL) OR (e=0);
(*3*)	(* New exponent vector computed? *)
	IF (lp=SIL) AND (e=1) THEN last:=SIL; RETURN; END;
(*4*)	(* Finish the computation of the product. *)
	WHILE lp<>SIL DO
		ADV(lp,  e,lp);
		ADV(F,  f,F);
		IF e=1 THEN
			PF:=DIPROD(PF,f);
		END;
	END;
	RETURN;
END NextProduct;

PROCEDURE TfEvalVars(phi,A:LIST):LIST;
(* type formula evaluate variables. 
phi is a type formula in variables a_0,...,a_{d-1}. 
A is a list of distributive polynomials over the arbitrary domain RF. 
A formula in PQ-format is returned. 
This formula is computed from phi using the following rules:
1) a_i is substituted by the (i-1)th element of A.
2) a) (f/g) <  0 is replaced with (f*g) <  0
   b) (f/g) <= 0 is replaced with (f*g) <= 0 
   c) (f/g) =  0 is replaced with (f)    = 0
   d) (f/g) <> 0 is replaced with (f)   <> 0
   e) (f/g) >= 0 is replaced with (f*g) >= 0
   f) (f/g) >  0 is replaced with (f*g) <  0  
The result is returned. *)
	VAR s: SYSINFO;
BEGIN
	SysInfoStart(s);
	RETURN FORAPPLYATF2(phi,A,tfevaf);
	SysInfoStop(s);
	IF RqeOpt.TraceLevel >= 3 THEN
		SWRITE("Time for evaluating type formula: ");
		BLINES(0);
		SysInfoWrite(s);
	END;
END TfEvalVars;

PROCEDURE tfevaf(phi,A:LIST):LIST;
(* type formula evaluate variables atomic formulas. 
phi is an atomic formula of a type formula. 
A is a list of distributive polynomials over the arbitrary domain RF. 
The global variable PolFmt is used.
*)
	VAR rel, idl, id,result,rf: LIST;
	VAR r, p, drf, vl, num, den : LIST;
	VAR lf, lb: LIST;
BEGIN
	tfpaf(phi,  rel,idl);
	ValisPush(PolFmt.FreeVars);
	result:=DIPONE(INTDDCMP());
	ValisPop();
	WHILE idl<>SIL DO
		ADV(idl,  id,idl);
		drf:=LELT(A,id+1);
		RFDDADV(drf,  rf,vl);
		r:=RFNOV(rf);
		num:=RFNUM(rf);
		den:=RFDEN(rf);
		IF (rel=EQU) OR (rel=NEQ) THEN
			p:=DIPFIP(num,r);
		ELSE
			(* p := num/den * den**2 = num * den *)
			p:=IPPROD(r,num,den);
			p:=DIPFIP(p,r);
		END;
		result:=DIPROD(result,p);
	END;
	lf:=LENGTH(PolFmt.FreeVars);
	lb:=LENGTH(PolFmt.BoundVars);
	result:=DIPINV(result,lf+1,lb);
	RETURN pqmkaf(rel,DIPERM(result,INVPERM(PolFmt.Permutation)));
END tfevaf;

(******************************************************************************
*                                R Q E N O E Q                                *
******************************************************************************)

PROCEDURE RqeNoEq(phi,bvlist: LIST):LIST;
(* real quantifier elimination no equation. 
The formula phi is a conjunction over atomic formulas. 
In all atomic formulas dependent of the variable occuring first in 
bvlist must occur the relation > or <>.  
The formula (exists bvlist(phi)) is eliminated and the result is returned.  
The global variable AdjoinedEq is used. 
The global variable VALIS must be set appropriately. *)
	VAR NC,G,N,pols: LIST;
	VAR result, psi, GreaterCond, NotZero, InterResult: LIST;
	VAR univlist, redlist,op: LIST;
BEGIN
(*0*)   (* Terminate the procedure, if a equation was already adjoined. *)
	IF AdjoinedEq THEN RETURN FALSUM; END;
(*1*)	(* Extract the polynomials from the formula. *)
	univlist:=LIST1(FIRST(bvlist));
	redlist:=RED(bvlist);
	pols:=ExtractPolynomials(phi,univlist,VALIS);
(*2*)	(* Extract the non-constant polynomials from the variable pols. *)
	NC:=FIRST(pols);
	G:=SECOND(NC);
	N:=THIRD(NC);
(*3*)	(* Generate formula from the extracted constant polynomials. *)
	psi:=PQSIMPLIFY(PqFC(SECOND(pols)));
	op:=FORGOP(psi);
	IF (op<>ET) AND (op<>VERUM) AND (op<>FALSUM) THEN	
		psi:=FORMKUNOP(ET,psi);
	END;
	IF psi=FALSUM THEN RETURN FALSUM; END;
(*4*)	(* Generate non triviality condition for side conditions f <> 0.*)
	NotZero:=RqeNonTriviality(N,univlist);
	IF NotZero=FALSUM THEN RETURN FALSUM; END;
(*5*)	(* Generate condition that quantified formula is valid at infinity. *)
	InterResult:=RqeLimitCondition(G,univlist);
	IF InterResult=VERUM THEN RETURN psi; END;
	result:=LIST1(InterResult);
(*6*)	(* Generate condition for greater side conditions. *)
	GreaterCond:=PQFDIL(G,GRE,ET);
(*7*)   (* Generate and eliminate the conjunction with equations from the 
           derivation condition. *)
	InterResult:=RqeDerivationCondition(G,GreaterCond,univlist,psi);
	IF InterResult=VERUM THEN RETURN VERUM; END;
	result:=COMP(InterResult,result);
(*7*)   (* Generate and eliminate the conjunction with equations from the 
           difference condition. *)
	InterResult:=RqeDifferenceCondition(G,GreaterCond,univlist,psi);
	IF InterResult=VERUM THEN RETURN VERUM; END;
	result:=COMP(InterResult,result);
(*8*)	(* Generate result of elimination of one variable. *)
	result:=FORMKFOR(VEL,INV(result));
	result:=FORMKFOR(ET,LIST3(result,psi,NotZero));
(*9*)	(* Eliminate the remaining variables. *)
	IF redlist<>SIL THEN
		result:=FORMKQUANT(EXIST,lvarfvlist(redlist),result);
		result:=RQEQE(result);
	END;
	RETURN result; 
END RqeNoEq;

PROCEDURE RqeNonTriviality(N,var: LIST): LIST;
(* real quantifier elimination non triviality. 
N is alist of polynomials.
The variable var contains the list of the main variables of the polynomials
in N. 
A formula psi is returned. psi is true iff no polynomial in N is trivial
w.r.t. the main variables, i.e. it is not the zero polynomial.
The global variable VALIS must be set. *)
	VAR n,result: LIST;
BEGIN
(*0*)	(* Special case. *)
	IF N=SIL THEN RETURN VERUM; END;
(*1*)	(* Initialization. *)
	result:=SIL;
(*2*)	(* Main loop. *)	
	REPEAT
		ADV(N,  n,N);
		result:=COMP(nontrivial(n,var,VALIS),result);
	UNTIL N=SIL; 
(*9*)	(* Return the result. *)
	RETURN PQSIMPLIFY(FORMKFOR(ET,INV(result)));
END RqeNonTriviality;

PROCEDURE RqeDerivationCondition(G,phi,var,psi: LIST):LIST;
(* real quantifier elimination derivation condition. 
G is a list of polynomials. 
phi and psi are a formulas.
var is a variable list with one element.
A disjunction of formulas gamma_i is returned. 
Each gamma_i is the result of the elimination of the formula 
(ex var: dg_i/dx(x)=0 AND phi) under the premise that psi is valid.
The global variable VALIS must be set. *)
	VAR VarIndex, g, result, DeriveCond, InterResult: LIST;
BEGIN
	IF RqeOpt.TraceLevel > 0 THEN
		IF RqeOpt.TraceLevel > 1 THEN
			SWRITE("RqeDerivationCondition: maximal ");
			UWRIT1(LENGTH(G));
			SWRITE(" conjunctions to generate");BLINES(0);
		ELSE
			SWRITE("(DC=");UWRITE(LENGTH(G));
		END;
	END;
	VarIndex:=LSRCHQ(FIRST(var),VALIS);
	result:=SIL;
	WHILE G<>SIL DO
		ADV(G,  g,G);
		IF DIPDEGI(g,VarIndex)>=2 THEN
			DeriveCond:=pqmkaf(EQU,DIPPAD(g,VarIndex));
			AdjoinedEq:=TRUE; 
			DeriveCond:=FORMKFOR(ET,
				COMP(DeriveCond,FORGARGS(phi)));
			InterResult:=RqeConjunction(DeriveCond,psi,var);
			AdjoinedEq:=FALSE;
			IF InterResult=VERUM THEN RETURN VERUM; END;
			result:=COMP(InterResult,result); 
		END;
	END;
	IF RqeOpt.TraceLevel>0 THEN
		IF RqeOpt.TraceLevel>1 THEN 
			SWRITE("RqeDerivationCondition: All conjunctions generated.");
			BLINES(0);
		ELSE
			SWRITE(")");
		END;
	END;
	IF result=SIL THEN
		RETURN FALSUM;
	ELSE
		RETURN FORMKFOR(VEL,INV(result));
	END;
END RqeDerivationCondition;

PROCEDURE RqeDifferenceCondition(G,phi,var,psi: LIST):LIST;
(* real quantifier elimination difference condition. 
G is a list of polynomials. 
phi and psi are a formulas.
var is a variable list with one element.
A disjunction of formulas gamma_i is returned. 
Each gamma_i is the result of the elimination of the formula 
(ex var: g_i-g_j(x)=0 AND phi) under the premise that psi is valid.
The global variable VALIS must be set. *)
	VAR result, pairs, p, DiffCond, InterResult: LIST;
BEGIN
	result:=SIL;
	pairs:=LPAIRS(G);
	IF RqeOpt.TraceLevel > 1 THEN
		IF RqeOpt.TraceLevel > 1 THEN
			SWRITE("RqeDifferenceCondition: ");
			UWRIT1(LENGTH(pairs));
			SWRITE("  conjunctions to generate.");
			BLINES(0);
		END;	
	END;	
	WHILE pairs<>SIL DO
		ADV(pairs,  p,pairs);
		DiffCond:=pqmkaf(EQU,DIPSUM(FIRST(p),DIPNEG(SECOND(p))));
		DiffCond:=FORMKFOR(ET,COMP(DiffCond,FORGARGS(phi)));
		AdjoinedEq:=TRUE;
		InterResult:=RqeConjunction(DiffCond,psi,var);
		AdjoinedEq:=FALSE;
		IF InterResult=VERUM THEN RETURN VERUM; END;		
		result:=COMP(InterResult,result);
	END;
	IF RqeOpt.TraceLevel>0 THEN
		IF RqeOpt.TraceLevel>1 THEN 
			SWRITE("RqeDifferenceCondition: All conjunctions generated.");
			BLINES(0);
		ELSE
			SWRITE(")");
		END;
	END;	
	IF result=SIL THEN
		RETURN FALSUM;
	ELSE
		RETURN PQSIMPLIFY(FORMKFOR(VEL,INV(result)));
	END;
END RqeDifferenceCondition;

PROCEDURE RqeLimitCondition(G,var: LIST):LIST;
(* real quantifier elimination limit condition. 
G is the list of polynomials.
var is a variable list with one element.
A formula is returned. 
This formula is true iff the limits of all polynomials 
at infinity or minus infinity is greater than zero.
The global variable VALIS must be set. *)
	VAR GU, GP, g, LimCond, result,fvlist,newdd,perm: LIST;
BEGIN
(*0*)	(* Initialization. *)
	result:=SIL;
	LimCond:=SIL;
(*1*)	(* Transform all polynomials in univariate polynomials in the main
	    variable var. *)
	fvlist:=SetComplementQ(var,VALIS);
	GU:=CommonPol2RecPolL(G,fvlist,var,VALIS,  perm);
	PolFmtPush(VALIS,var,fvlist,perm);
(*2*)	(* Condition for infinity. *)
	GP:=GU;
	WHILE GP<>SIL DO
		ADV(GP,  g,GP);
		LimCond:=COMP(RqeLimP(g),LimCond);
	END;
	LimCond:=FORMKFOR(ET,INV(LimCond));
	result:=COMP(LimCond,result);
(*3*)	(* Condition for minus infinity. *)
	GP:=GU;
	LimCond:=SIL;
	WHILE GP<>SIL DO
		ADV(GP,  g,GP);
		LimCond:=COMP(RqeLimN(g),LimCond);
	END;
	LimCond:=FORMKFOR(ET,INV(LimCond));
	result:=COMP(LimCond,result);
(*4*) 	(* Clear PolFmt and return result. *)
	PolFmtPop();
	RETURN PQSIMPLIFY(FORMKFOR(VEL,result));
END RqeLimitCondition;

PROCEDURE RqeLimP(p: LIST):LIST;
(* real quantifier elimination limes infinity positive. 
p is a univariate distributive polynomial. 
A formula is returned. The returned formula is true 
iff $\lim_{x\rightarrow\infty} p(x)>0$. 
We construct the formula recursively. 
The global variable PolFmt is used. *)
	VAR invperm,c,cp,e: LIST;
BEGIN
(*0*)	(* Special case. *)
	IF p=0 THEN RETURN FALSUM; END;
(*1*)	(* Initialization. *)
	invperm:=INVPERM(PolFmt.Permutation);
(*2*)	(* Generate condition for the highest coefficient. *)
	DIPMAD(p,  c,e,p);
	WITH PolFmt DO
		cp:=ParamPol2CommonPol(c,FreeVars,BoundVars,invperm);
	END;
(*3*)	(* If HC(p) contains no parameter, return the result. *)
	IF DIPCNST(cp) THEN 
		IF ADSIGN(c)=1 THEN
			RETURN VERUM;
		ELSE
			RETURN FALSUM;
		END;
(*4*)	(* If p-HC(p)=0, return restrictive condition. *)
	ELSIF p=SIL THEN
		RETURN pqmkaf(GRE,cp);
	ELSE 
(*5*)	(* Call RqeLimP recursively and return the result. *)
		RETURN FORMKBINOP(VEL,pqmkaf(GRE,cp),
			FORMKBINOP(ET,pqmkaf(EQU,cp),RqeLimP(p)));
	END;
END RqeLimP;

PROCEDURE RqeLimN(p: LIST):LIST;
(* real quantifier elimination limes infinity negative. 
p is a univariate distributive polynomial. 
A formula is returned.  The returned formula is true 
iff $\lim_{x\rightarrow-\infty} p(x)>0$. 
We construct the formula recursively. 
The global variable PolFmt is used. *)
	VAR invperm,c,cp,e: LIST;
BEGIN
(*0*)	(* Special case. *)
	IF p=0 THEN RETURN FALSUM; END;
(*1*)	(* Initialization. *)
	invperm:=INVPERM(PolFmt.Permutation);
(*2*)	(* Generate condition for the highest coefficient. *)
	DIPMAD(p,  c,e,p);
	WITH PolFmt DO
		cp:=ParamPol2CommonPol(c,FreeVars,BoundVars,invperm);
	END;
(*3*)	(* HM(p)=HC(p)*X^{2e} *)
	IF FIRST(e) MOD 2 = 0  THEN
(*4*)	(* If HC(p) contains no parameter, return the result. *)
		IF DIPCNST(cp) THEN 
			IF ADSIGN(c)=1 THEN
				RETURN VERUM;
			ELSE
				RETURN FALSUM;
			END;
		ELSIF p=SIL THEN
			RETURN pqmkaf(GRE,cp);
		ELSE 
			RETURN FORMKBINOP(VEL,pqmkaf(GRE,cp),
				FORMKBINOP(ET,pqmkaf(EQU,cp),RqeLimN(p)));
		END;
(*5*)	(* HM(p)=HC(p)*X^{2e+1} *)
	ELSE
(*6*)	(* If HC(p) contains no parameter, return the result. *)
		IF DIPCNST(cp) THEN 
			IF ADSIGN(c)=-1 THEN
				RETURN VERUM;
			ELSE
				RETURN FALSUM;
			END;
		ELSIF p=SIL THEN
(*7*)	(* If p-HC(p)=0, return restrictive condition. *)
			RETURN pqmkaf(LES,cp);
		ELSE 
(*8*)	(* Call RqeLimN recursively and return the result. *)
			RETURN FORMKBINOP(VEL,pqmkaf(LES,cp),
				FORMKBINOP(ET,pqmkaf(EQU,cp),RqeLimN(p)));
		END;
	END;
END RqeLimN;

(******************************************************************************
*                            C G B   -   S T U F F                            *
******************************************************************************)

PROCEDURE cgbinput1(P,V,D,Cond:LIST):LIST;
(* comprehensive Groebner basis input.
P is a list of polynomials, with domain descriptor D and variable list V.
Cond is a condition. It is used as the initial case distinction.
C0 and C1 builds the initial case distinction.
C0 are coefficient polynomials with the interpretation c in C0 = 0 
and C1 are coefficient polynomials with the interpretation c in C1 <> 0.
*)
BEGIN
	RETURN CdpCons(LIST1(Cond),LIST2(INV(DIPLPM(P)),0),
		VdCons(V,D));
END cgbinput1;

PROCEDURE CondFC(C:LIST):LIST;
(* condition from constant polynomials. 
C is a list of the form  (cle, clq, ceq, cnqm cgq, cgr). 
A condition (terminology of the CGB-module) is returned. 
The global variable PolFmt is used. *)
	VAR red, green, L, p, i: LIST; 
BEGIN
	red:=SIL; green:=SIL;
	ADV(C,  L,C);				(* side conditions < *)
	WHILE L<>SIL DO 
		ADV(L, p,L);
		red:=COMP(p,red);
	END;
	ADV(C,  L,C);				(* side conditions <= *)
	ADV(C,  L,C);				(* side conditions = *)
	WHILE L<>SIL DO 
		ADV(L, p,L);
		green:=COMP(p,red);
	END;	
	ADV(C,  L,C);				(* side conditions <> *)
	WHILE L<>SIL DO 
		ADV(L, p,L);
		red:=COMP(p,red);
	END;
	ADV(C,  L,C);				(* side conditions >= *)
	ADV(C,  L,C);				(* side conditions > *)
	WHILE L<>SIL DO 
		ADV(L, p,L);
		red:=COMP(p,red);
	END;
	WITH PolFmt DO
		red:=CommonPol2ParamPolL(red,FreeVars,BoundVars,AllVars,
			Permutation);
		green:=CommonPol2ParamPolL(green,FreeVars,BoundVars,AllVars,
			Permutation);
	END;
	RETURN CondCons(green,red);
END CondFC; 

PROCEDURE DIMISS(PL,VL: LIST; VAR SMAXVL: LIST): LIST; 
(* Dimension and set of maximal independent sets.
PL is a list of polynomials.
VL is the variable list.
SMAXVL need not be initialized.
Returns the dimension of PP and maximal independent sets in SMAXVL. *)
	VAR M, m, S,DL: LIST; 
BEGIN
(*0*)	(* Special case: empty set. *)
	IF PL = SIL THEN 
		SMAXVL:=LIST1(VL);
		RETURN LENGTH(VL);
	END;
(*1*)	(* Determine the dimension and the set of maximal independent sets. *)
	DILDIM(PL, DL,S,M);
	IF DL=-1 THEN SMAXVL:=SIL; RETURN -1; END;
(*2*)	(* Get the maximal independent sets from the returned indexed sets. *)
	SMAXVL:=SIL;
	WHILE M<>SIL DO
		ADV(M,m,M);
		SMAXVL:=COMP(IXSUBS(VL,m),SMAXVL);
	END;
(*9*)	(* Return the result. *)
	SMAXVL:=INV(SMAXVL);
	RETURN(DL);
END DIMISS; 

PROCEDURE CondUnion(c1,c2: LIST):LIST;
(* condition union. 
c1 and c2 are conditions. 
The union c of the two  conditions is returned. 
Let phi1, phi2 the formulas which are represented by the conditions c1, c2 
then c represents the formula (phi1 and phi2). *)
	VAR green1, red1, green2, red2: LIST;
BEGIN
	IF CondIsEmpty(c1) THEN 
		RETURN c2;
	ELSIF CondIsEmpty(c2) THEN 
		RETURN c1; 
	END;
	CondParts(c1,  green1,red1);
	CondParts(c2,  green2,red2);
	RETURN CondCons(CCONC(green1,green2),CCONC(red1,red2));
END CondUnion;

(******************************************************************************
*                     P O L Y N O M I A L   F O R M A T S                     *
******************************************************************************)

PROCEDURE ParamPol2CommonPol(p, Uvlist, Xvlist,iperm: LIST):LIST;
(* parameter polynomial to common polynomial format.
p is a polynomial in K[U] represented as a arbitrary domain element.
Uvlist is the variable list of the parameters U, 
Xvlist is the variable list of the main variables X. 
iperm is a permutation to reorder the variables in the result.
p is converted to the common polynomial format K[U,X]. 
EVORD must be set. *)
BEGIN
	p:=DIPFADIP(p);
	p:= DIPINV(p,LENGTH(Uvlist)+1,LENGTH(Xvlist));
	RETURN DIPERM(p,iperm);
END ParamPol2CommonPol;			   

PROCEDURE ParamPol2CommonPolL(P, Uvlist, Xvlist,iperm: LIST):LIST;
(* parameter polynomial list to common polynomial format.
Each p in P is a polynomial in K[U] represented as a arbitrary domain element.
Uvlist is the variable list of the parameters U, 
Xvlist is the variable list of the main variables X. 
iperm is a permutation to reorder the variables in the result.
Each p is converted to the common polynomial format K[U,X]. 
EVORD must be set. *)
	VAR p,res,lfv,lbv,luv,lxv: LIST;
BEGIN
	res:=SIL;
	luv:=LENGTH(Uvlist);
	lxv:=LENGTH(Xvlist);
	WHILE P<>SIL DO
		ADV(P,  p,P);
		p:=DIPFADIP(p);
		p:= DIPINV(p,luv+1,lxv);
		res:=COMP(DIPERM(p,iperm),res);
	END;
	RETURN INV(res);
END ParamPol2CommonPolL;

PROCEDURE RecPol2CommonPol(p,Uvlist,Xvlist,iperm: LIST):LIST;
(* recursive polynomial to common polynomial format.
p is a polynomial in K[U][X]. 
Uvlist is the variable list of the parameters U, 
Xvlist is the variable list of the main variables X. 
iperm is a permutation to reorder the variables in the result.
p is converted to the common polynomial format K[U,X].
EVORD must be set. *)
	VAR d,q,v: LIST;
BEGIN
	d:=INTDDCMP();
	ValisPush(Xvlist);
	DIPFDIPP(p,d,  q,v);
	ValisPop();
	q:=DIPERM(q,iperm);
	RETURN q;
END RecPol2CommonPol;

PROCEDURE RecPol2CommonPolL(P,Uvlist,Xvlist,iperm: LIST):LIST;
(* recursive polynomial list to common polynomial format.
Each p in P is a polynomial in K[U][X]. 
Uvlist is the variable list of the parameters U, 
Xvlist is the variable list of the main variables X. 
iperm is a permutation to reorder the variables in the result.
Each P is converted into a polynomial in K[U,X].
EVORD must be set. *)
	VAR d,q,v,p,res: LIST;
BEGIN
	ValisPush(Xvlist);
	res:=SIL;
	d:=INTDDCMP();
	WHILE P<>SIL DO
		ADV(P,  p,P);
		DIPFDIPP(p,d,  q,v);
		q:=DIPERM(q,iperm);
		res:=COMP(q,res);
	END;
	ValisPop();
	RETURN INV(res);
END RecPol2CommonPolL;

PROCEDURE CommonPol2RecPol(p,Uvlist,Xvlist,valis: LIST; VAR perm: LIST):LIST;
(* common polynomial to recursive polynomial format. 
valis is the list of all variables.
Uvlist is the variable list of the parameters U, 
Xvlist is the variable list of the main variables X. 
perm is a permutation to achieve (Uvlist,Xvlist) from (valis).
p is converted into a polynomial in K[U][X]. 
EVORD and must be set. *)
	VAR q,v,r,newdd: LIST;
BEGIN
	perm:=PVFLISTS(valis,CCONC(Uvlist,Xvlist));
	r:=LENGTH(Uvlist);
	newdd:=IPDDCMP(Uvlist);
	ValisPush(LPERM(valis,perm));
	DIPPFDIP(DIPERM(p,perm),r,newdd,q,v);
	ValisPop();
	RETURN q;
END CommonPol2RecPol;

PROCEDURE CommonPol2RecPolL(P,Uvlist,Xvlist,valis: LIST; VAR perm: LIST):LIST;
(* common polynomial list to recursive polynomial format. 
Each p in P is a polynomial in K[Y_1,...,Y_n] {Y_i}={X_i,U_i}. 
valis is the list of all variables.
Uvlist is the variable list of the parameters U, 
Xvlist is the variable list of the main variables X. 
perm is a permutation to achieve (Uvlist,Xvlist) from (valis).
Each p is converted into a polynomial in K[U][X]. 
EVORD must be set. *)
	VAR q,v,p,res,r,newdd: LIST;
BEGIN
	res:=SIL;
	perm:=PVFLISTS(valis,CCONC(Uvlist,Xvlist));
	r:=LENGTH(Uvlist);
	newdd:=IPDDCMP(Uvlist);
	ValisPush(LPERM(valis,perm));
	WHILE P<>SIL DO
		ADV(P,  p,P);
		DIPPFDIP(DIPERM(p,perm),r,newdd,q,v);
		res:=COMP(q,res);
	END;
	ValisPop();
	RETURN INV(res);
END CommonPol2RecPolL;

PROCEDURE CommonPol2ParamPol(p,Uvlist,Xvlist,valis:LIST; VAR perm : LIST):LIST;
(* common polynomial to parameter polynomial. 
p is a polynomial in K[U][X] which is constant with respect to the main 
variables.
valis is the list of all variables. 
Uvlist is the variable list of the parameters U, 
Xvlist is the variable list of the main variables X. 
perm is a permutation to achieve (Uvlist,Xvlist) from (valis).
The polynomial p represented as an element in K[U] as an arbitrary domain 
object. 
EVORD must be set.*)
	VAR q,v,c,r,e,newdd: LIST;
BEGIN
	perm:=PVFLISTS(valis,CCONC(Uvlist,Xvlist));
	r:=LENGTH(Uvlist);
	newdd:=IPDDCMP(Uvlist);
	ValisPush(LPERM(valis,perm));
	DIPPFDIP(DIPERM(p,perm),r,newdd,  q,v);
	DIPMAD(q,  c,e,q);
	ValisPop();
	RETURN c;
END CommonPol2ParamPol;

PROCEDURE CommonPol2ParamPolL(P,Uvlist,Xvlist,valis:LIST; VAR perm: LIST):LIST;
(* common polynomial list to parameter polynomial. 
Each p in P is a polynomial in K[U][X] which is constant with respect 
to the main variables.
valis is the list of all variables. 
Uvlist is the variable list of the parameters U, 
Xvlist is the variable list of the main variables X. 
perm is a permutation to achieve (Uvlist,Xvlist) from (valis).
Each p is converted to an parameter polynomial.
EVORD must be set.*)
	VAR q,v,p,res,r,c,e,newdd: LIST;
BEGIN
	res:=SIL;
	perm:=PVFLISTS(valis,CCONC(Uvlist,Xvlist));
	r:=LENGTH(Uvlist);
	newdd:=IPDDCMP(Uvlist);
	ValisPush(LPERM(valis,perm));
	WHILE P<>SIL DO
		ADV(P,  p,P);
		DIPPFDIP(DIPERM(p,perm),r,newdd,  q,v);
		DIPMAD(q,  c,e,q);
		res:=COMP(c,res);
	END;
	ValisPop();
	RETURN INV(res);	
END CommonPol2ParamPolL;

PROCEDURE PqFC(C: LIST):LIST;
(* polynomial equation from constant polynomials. C is a list of the form
(cle, clq, ceq, cnq cgq, cgr). A formula 
AND (cle < 0, clq <= 0, ceq = 0, cnq # 0, cgq >= 0, cgr > 0) 
is returned. *)
	VAR result, dil,p: LIST;
BEGIN
	result:=SIL;
	ADV(C,  dil,C);
	IF dil<>SIL THEN result:=COMP(PQFDIL(dil,LES,ET),result); END;
	ADV(C,  dil,C);
	IF dil<>SIL THEN result:=COMP(PQFDIL(dil,LSQ,ET),result); END;
	ADV(C,  dil,C);
	IF dil<>SIL THEN result:=COMP(PQFDIL(dil,EQU,ET),result); END;
	ADV(C,  dil,C);
	IF dil<>SIL THEN result:=COMP(PQFDIL(dil,NEQ,ET),result); END;
	ADV(C,  dil,C);
	IF dil<>SIL THEN result:=COMP(PQFDIL(dil,GRQ,ET),result); END;
	ADV(C,  dil,C);
	IF dil<>SIL THEN result:=COMP(PQFDIL(dil,GRE,ET),result); END;
	IF result<>SIL THEN 
		RETURN FORMKFOR(ET,INV(result));
	ELSE
		RETURN VERUM;
	END;
END PqFC;

PROCEDURE PQFDIL(dil,pqop,op:LIST):LIST;
(* polynomial equation from distributive polynomial list.
dil is a list of distributive polynomials. pqop is a relation symbol. 
op is maslog operator. The formula op_i( dil_i pqop 0) is returned. 
If dil is empty and the operator is ET (VEL), VERUM (FALSUM) is returned.
Otherwise an error is generated. *)
	VAR dip, result: LIST;
BEGIN
	IF dil=SIL THEN
		IF op=ET THEN
			RETURN VERUM;
		ELSIF op=VEL THEN
			RETURN FALSUM;
		ELSE
			ERROR(severe,"PQFDIL: cannot create formula from empty list.");
			RETURN FALSUM;
		END;
	END;
	result:=SIL;
	WHILE dil<>SIL DO
		ADV(dil,  dip,dil);
		result:=COMP(pqmkaf(pqop,dip),result);
	END;
	RETURN FORMKFOR(op,INV(result));
END PQFDIL;

PROCEDURE forfdata(Cond, Plist, Gre, Neq:LIST):LIST;
(* formula from data.
Cond is a condition, 
Plist is a list of polynomials in K[U][X],
Gre and Neq are list of polynomials in K[U,X]. 
Let cond=(R,G). A conjunction of the following atomic formulas is generated:
(r<>0), (g=0), (p=0), (gr>0) and (n<>), where  
r\in R, g\in G, p\in P, gr\in Gre and n\in Neq.
The global variable PolFmt is used. *)
	VAR G,R,result,p: LIST;
BEGIN
	WITH PolFmt DO
		Plist:=RecPol2CommonPolL(Plist,
			FreeVars,BoundVars,INVPERM(Permutation));
	END;
	ValisPush(PolFmt.BoundVars);
	result:=SIL;
	WHILE Neq<>SIL DO
		ADV(Neq,  p,Neq);
		result:=COMP(pqmkaf(NEQ,p),result);
	END;
	WHILE Gre<>SIL DO
		ADV(Gre,  p,Gre);
		result:=COMP(pqmkaf(GRE,p),result);
	END;
	WHILE Plist<>SIL DO
		ADV(Plist,  p,Plist);
		result:=COMP(pqmkaf(EQU,p),result);
	END;
	IF result=SIL THEN 
		result:=VERUM;
	ELSE
		result:=FORMKFOR(ET,INV(result));
	END;
	IF NOT CondIsEmpty(Cond) THEN
		result:=FORMKBINOP(ET,
			PqFCond(Cond),result);
	END;
	ValisPop();
	RETURN result;
END forfdata;

PROCEDURE PqFCond(Cond:LIST):LIST;
(* polynomial equation from condition. 
Cond is a condition (in the sense of the CGB module.) 
The condition is transformed into a formula. 
The global variable PolFmt is used. *)
	VAR G,R,p,result: LIST; 
BEGIN
	result:=SIL;
	IF NOT CondIsEmpty(Cond) THEN
		CondParts(Cond,  G,R);
		WITH PolFmt DO
			G:=ParamPol2CommonPolL(G, 
				FreeVars,BoundVars,INVPERM(Permutation));
			R:=ParamPol2CommonPolL(R,
				FreeVars,BoundVars,INVPERM(Permutation));
		END;
		WHILE R<>SIL DO
			ADV(R,  p,R);
			result:=COMP(pqmkaf(NEQ,p),result);
		END;
		WHILE G<>SIL DO
			ADV(G,  p,G);
			result:=COMP(pqmkaf(EQU,p),result);
		END;
		result:=FORMKFOR(ET,INV(result));
	ELSE 
		result:=VERUM;
	END;
	RETURN result;
END PqFCond;

PROCEDURE ExtractPolynomials(phi, bvlist, valis: LIST):LIST;
(* extract polynomials. 
phi is conjunction over atomic formulas.
valis is the variable list os all polynomials occuring in phi.
bvlist is a subset of valis.
A XPL w.r.t. bvlist is returned. *)
	VAR p,op,args,af,rel,bvv: LIST;
	VAR eq, gr, nq, cle, clq, ceq, cnq, cgq, cgr: LIST;
BEGIN
	bvv:=VVECFVLIST(bvlist,valis);
	eq:=SIL; gr:=SIL; nq:=SIL;
	cle:=SIL; clq:=SIL; ceq:=SIL; cnq:=SIL; cgq:=SIL; cgr:=SIL;
	FORPFOR(phi,  op,args);
	WHILE args<>SIL DO
		ADV(args,  af,args);
		pqpaf(af,  rel,p);
		IF DIPCNSTR(p,bvv) THEN
			IF rel=LES THEN
				cle:=COMP(p,cle);
			ELSIF rel=LSQ THEN 	
				clq:=COMP(p,clq);
			ELSIF rel=EQU THEN 	
				ceq:=COMP(p,ceq);
			ELSIF rel=NEQ THEN 	
				cnq:=COMP(p,cnq);
			ELSIF rel=GRQ THEN 	
				cgq:=COMP(p,cgq);
			ELSIF rel=GRE THEN 	
				cgr:=COMP(p,cgr);
			ELSE
				ERROR(severe,"ExtractPolynomials: incorrect relation symbol");
			END;
		ELSE
			IF rel=EQU THEN
				eq:=COMP(p,eq);
			ELSIF rel=GRE THEN
				gr:=COMP(p,gr);
			ELSIF rel=NEQ THEN
				nq:=COMP(p,nq);
			ELSE
				ERROR(severe,"ExtractPolynomials: incorrect relation symbol");
			END;
		END;
	END;
	RETURN LIST2(LIST3(INV(eq), INV(gr), INV(nq)),
		LIST6(INV(cle),INV(clq),INV(ceq),INV(cnq),INV(cgq),INV(cgr)));
END ExtractPolynomials;

PROCEDURE RQERSNF(phi,bvlist,valis:LIST):LIST;
(* relation symbol normal form. 
phi is conjunction of atomic formulas of the form "(rel pol)". 
valis is the variable list of all polynomials occuring in phi.
bvlist is a subset of valis.
A formula psi equivalent to phi is returned. Each atomic formula in psi 
has the form (nfrel pol), where nfrel is a relation of {>,=<>}. *)
	VAR bvv: LIST;
BEGIN
	bvv:=VVECFVLIST(bvlist,valis);
	RETURN FORAPPLYATF2(phi,bvv,RelSymNf);
END RQERSNF;

PROCEDURE RelSymNf(phi,bvv:LIST):LIST;
(* relation symbol normal form. 
phi is an atomic formula. 
bvv is a variable vector.
A formula psi equivalent to phi is returned. Each atomic formula in psi 
has the form (nfrel pol), where nfrel is a relation of {>,=<>}. *)
	VAR rel,pol: LIST;
BEGIN
	pqpaf(phi,  rel,pol);
	IF DIPCNSTR(pol,bvv) THEN RETURN phi; END;
	IF (rel=EQU) OR (rel=NEQ) OR (rel=GRE) THEN
		RETURN phi;
	ELSIF rel=LSQ THEN
		RETURN FORMKFOR(VEL,LIST2(
			pqmkaf(GRE,DIPNEG(pol)),
			pqmkaf(EQU,pol)));
	ELSIF rel=GRQ THEN
		RETURN FORMKFOR(VEL,LIST2(
			pqmkaf(GRE,pol),
			pqmkaf(EQU,pol)));
	ELSIF rel=LES THEN
		RETURN pqmkaf(GRE,DIPNEG(pol));
	ELSE
		UWRITE(rel);
		ERROR(severe,"RelSymNf: unknown relation symbol");
	END;
END RelSymNf;

PROCEDURE exvlist(vlist1,vlist2:LIST):LIST;
(* extend variable list.
vlist1 is a variable list.
vlist2 is a subset of vlist1.
All elements of vlist2 which are not in vlist1 are appended to vlist1. 
The result is returned. vlist1 are not modified. *)
	VAR v,result: LIST;
BEGIN
	result:=CINV(vlist1);
	WHILE vlist2<>SIL DO
		ADV(vlist2,  v,vlist2);
		IF MEMBER(v,vlist1)=0 THEN
			result:=COMP(v,result)
		END;
	END;
	RETURN INV(result);
END exvlist;

PROCEDURE nontrivial(p,bvlist,allvars:LIST):LIST;
(* non trivial. 
p is a distributive polynomial in Z[allvars]. 
allvars is the variable list of the polynomial p.
bvlist is a subset of allvars. 
p is transformed in a polynomial q in Z[allvars-bvars][bvars]. 
A formula psi is returned. psi is true, iff q is not the zero polynomial.
Only the domain INT is supported for p. *)
	VAR c,e,result,perm,invperm,fvlist: LIST;
BEGIN
	IF p=0 THEN RETURN FALSUM; END;
	fvlist:=SetComplementQ(bvlist,allvars);
	p:=CommonPol2RecPol(p,fvlist,bvlist,VALIS,  perm);
	result:=SIL;
	invperm:=INVPERM(perm);
	WHILE p<>SIL DO
		DIPMAD(p,  c,e,p);
		c:=ParamPol2CommonPol(c,fvlist,bvlist,invperm);
		result:=COMP(pqmkaf(NEQ,c),result);
	END;
	RETURN PQSIMPLIFY(FORMKFOR(VEL,INV(result)));
END nontrivial;

(******************************************************************************
*                                O P T I O N S                                *
******************************************************************************)

PROCEDURE RQEOPTSET(opt:LIST):LIST;
(* real quantifier elimination options set. 
opt is a list of options. 
The first element of opt is the trace level. 
The second element of opt is a flag. If this flag is true, then 
partial elimination of zero dimensional ideals are done. Otherwise full
quantifier elimination is done.
The old option list is returned. *)
	VAR old,flag: LIST;
BEGIN
	IF RqeOpt.DimensionZeroOnly THEN 
		old:=LIST1(1); 
	ELSE 
		old:=LIST1(0); 
	END;
	old:=COMP(RqeOpt.TraceLevel,old);		
	IF opt=SIL THEN RETURN old; END;
	IF opt<>SIL THEN
		IF FIRST(opt)<>-1 THEN
			ADV(opt,  RqeOpt.TraceLevel,opt);
		ELSE
			opt:=RED(opt);
		END;
	END;
	IF opt<>SIL THEN
		IF FIRST(opt)<>-1 THEN
			ADV(opt,  flag,opt);
			IF flag=1 THEN 
				RqeOpt.DimensionZeroOnly:=TRUE;
			ELSE
				RqeOpt.DimensionZeroOnly:=FALSE;
			END;
		ELSE
			opt:=RED(opt);
		END;
	END;
	RETURN old;
END RQEOPTSET;

PROCEDURE RQEOPTWR();
(* real quantifier elimination option write. 
The actual options are written to the output stream. *)
BEGIN
	BLINES(1);
	SWRITE("Options for the RQE - System");BLINES(0);
	SWRITE("The trace level is: ");UWRITE(RqeOpt.TraceLevel);
	IF RqeOpt.DimensionZeroOnly THEN
		SWRITE("Only partial quantifier elimination is done.");
	ELSE
		SWRITE("Full quantifier elimination is done.");
	END;
	BLINES(1);
END RQEOPTWR;

PROCEDURE RqeOptInit();
(* real quantifier elimination option initialization. 
The global variable RqeOption containing the options for the 
computation is initialized. *)
BEGIN
	WITH RqeOpt DO
		TraceLevel:=3;
		DimensionZeroOnly:=FALSE;
	END;
END RqeOptInit;

PROCEDURE PolFmtInit();
(* polynomial format initialize. 
The entries of the record PolFmt and the PolFmtStack is initialized.*)
BEGIN
	PolFmtStack:=SIL;
	LISTVAR(PolFmtStack);
	WITH PolFmt DO
		AllVars:=SIL;
		BoundVars:=SIL;
		FreeVars:=SIL;
		Permutation:=SIL;
		LISTVAR(AllVars);
		LISTVAR(BoundVars);
		LISTVAR(FreeVars);
		LISTVAR(Permutation);
	END;
END PolFmtInit;

PROCEDURE PolFmtPush(vars,bvlist,fvlist,perm:LIST);
(* polynomial format push. 
The old values of PolFmt are pushed onto the PolFmtStack. 
The new values are stored in PolFmt. *)
BEGIN
	WITH PolFmt DO
		PolFmtStack:=COMP(
			LIST4(AllVars,BoundVars,FreeVars,Permutation),
			PolFmtStack);
		AllVars:=vars;
		BoundVars:=bvlist;
		FreeVars:=fvlist;
		Permutation:=perm;
	END;
END PolFmtPush;

PROCEDURE PolFmtPop();
(* polynomial format push. 
The old values of PolFmt are restored from the PolFmtStack.
The top entry of the PolFmtStack is deleted. *)
	VAR elem:LIST;
BEGIN
	IF PolFmtStack=SIL THEN
		ERROR(severe,"PolFmtPop: stack empty.");
		RETURN;
	END;
	ADV(PolFmtStack,  elem,PolFmtStack);
	WITH PolFmt DO
		FIRST4(elem,  AllVars, BoundVars, FreeVars,Permutation);
	END;
END PolFmtPop;

BEGIN
	RqeOptInit();
	PolFmtInit();
	AdjoinedEq:=FALSE;

END RQEPRRC.
(* -EOF- *)
