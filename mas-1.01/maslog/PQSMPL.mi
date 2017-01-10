(* ----------------------------------------------------------------------------
 * $Id: PQSMPL.mi,v 1.3 1995/11/04 18:00:28 pesch Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: PQSMPL.mi,v $
 * Revision 1.3  1995/11/04 18:00:28  pesch
 * Changed comments violating documentation rules. Should be rewritten.
 *
 * Revision 1.2  1994/11/28  21:12:09  dolzmann
 * Moved procedures from PQSMPL into PQBASE.
 *
 * Revision 1.1  1993/12/18  20:12:20  dolzmann
 * System for the simplification of boolean combinations of polynomial 
 * equations.
 * 
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE PQSMPL;
(* Polynomial Equation Simplification Implementation Module. *)

(******************************************************************************
*    P O L Y N O M I A L   E Q U A T I O N   S I M P L I F I C A T I O N      *
*-----------------------------------------------------------------------------*
* Author:   Andreas Dolzmann                                                  *
* Language: Modula II                                                         *
* System:   This program is written for the computer algebra system MAS by    *
*           Heinz Kredel.                                                     *
* Remark:   Libraries maskern, maslisp and maslog, masdom, maspoly, ...       *
*           are used.                                                         *
* Abstract: A program for simplification of polynomial equations and          *
*           inequations in the field of the complex numbers.                  *
******************************************************************************)

FROM MASELEM	IMPORT	GAMMAINT;
FROM MASSTOR	IMPORT	ADV, COMP, FIRST, INV, LENGTH, LIST, LIST1, LISTVAR,
			RED, SFIRST, SIL, SRED;
FROM MASBIOS	IMPORT	BKSP, BLINES, CREAD, CREADB, CWRITE, DIBUFF, DIGIT,
			LETTER, LISTS, MASORD, SWRITE;
FROM SACLIST	IMPORT	ADV2, ADV3, ADV4, AWRITE, CCONC, CINV, CLOUT, COMP2,
			CONC, EQUAL, LIST10, LIST2, LIST3, LIST4, LIST5,
			MEMBER, SECOND, THIRD; 
FROM MASERR	IMPORT	ERROR, confusion, fatal, harmless, severe, spotless;
FROM MASSYM	IMPORT	ATOM, MEMQ;
FROM MASSYM2	IMPORT	ASSOC, ASSOCQ, EXPLOD, SREAD1, SYMBOL, UREAD, UWRIT1,
			UWRITE;
FROM MASLISPU	IMPORT	Declare;
FROM MLOGBASE	IMPORT	ET, FALSUM, FORGARGS, FORGOP, FORMKBINOP, FORMKFOR,
			FORMKUNOP, FORPARGS, FORPBINOP, FORPFOR, FORPUNOP,
			FORPUNOPA, IMP, NON, TVAR, VEL, VERUM;
FROM MASLOG	IMPORT	FORAPPLYAT, FORELIMXOPS, FORMKCNF, FORMKDNF,
			FORMKPOS, FORSMPL, FORMKPRENEX, FORMKPRENEX1; 
FROM MLOGIO	IMPORT	FORIREAD, FORPPRT, FORPREAD, FORTEXW, KEYREAD;
FROM DIPADOM	IMPORT	DILWR, DIPNEG, DIPROD, DIPSUM, DIREAD, DIWRIT;
FROM DIPC	IMPORT	DILBSO, DIPBSO, DIPFMO, DIPINV, DIPLPM, DIPMAD,
			DIPNOV, EVORD, EVSIGN, GRLEX, IGRLEX, INVLEX, LEX,
			REVILEX, REVITDG, REVLEX, REVTDEG, VALIS;
FROM DIPGB	IMPORT	DIIFGB, DIIFNF, DILIS, DIPGB, DIPNOR;
FROM MASADOM	IMPORT	ADDDWRIT, ADFI, ADDDREAD;
FROM SACSET	IMPORT	LBIBMS;
FROM SACPOL	IMPORT	VLREAD, VLWRIT; 
FROM PQBASE	IMPORT	DOMAIN, PQMKCNF, PQMKDNF, PQSMPL, PQMKPRENEX,
			PQELIMXOPS, pqmkaf, pqpaf, PQIREAD, PQPPRT, EQU, NEQ;
FROM DIPTOOLS	IMPORT	ADDDFDIP, DILINV, DILPROD, DIPONE, DIPPOWER,
			EvordPop, EvordPush, ValisPop, ValisPush; 


TYPE SetRel=(subset,superset,setequal,setnorel); 

CONST rcsidi = "$Id: PQSMPL.mi,v 1.3 1995/11/04 18:00:28 pesch Exp $";
CONST copyrighti = "Copyright (c) 1993 Universitaet Passau";

(******************************************************************************
*                       G L O B A L   V A R I A B L E S                       *
******************************************************************************)

VAR PQTRACE: LIST;	(* This variable determines, how many tracing 
			   output is printed. *) 
VAR PQRMSTest: LIST; 	(* This variable determines the method for the radical
			   mebership test. (Radical Membership Test)*)
VAR PQPOWERS: LIST;     (* A list of powers for a pseudo radical membership
			   test. *)
VAR PQIBREP: LIST;	(* This variable determines whether a ideal basis is 
			   replaced by another or not. (Ideal Basis REPlace) *)
VAR PQREDCON: LIST;	(* This variable determines wheter the conclusions
			   are reduced. *)

(******************************************************************************
*                         S I M P L I F I C A T I O N                         *
******************************************************************************)

PROCEDURE PQSCNF(phi: LIST):LIST;
(* polynomial equation simplification normal form. phi is an arbitrary 
quantifier-free formula. A equivalent formula in SCNF is returned. *)
	VAR nf: LIST;
BEGIN
	nf:=SimplifyNf(PQMKCNF(PQSMPL(phi)));
	IF (nf=VERUM) OR (nf=FALSUM) THEN
		RETURN nf;
	END;
	RETURN PQscnf(PQGetDataCnf(nf));
END PQSCNF;

PROCEDURE PQSDNF(phi: LIST):LIST;
(* polynomial equation simplification normal form. phi is an arbitrary 
quantifier-free formula. A equivalent formula in SDNF is returned. *)
	VAR nf: LIST;
BEGIN
	nf:=SimplifyNf(PQMKCNF(PQSMPL(phi)));
	IF (nf=VERUM) OR (nf=FALSUM) THEN
		RETURN nf;
	END;
	RETURN PQsdnf(PQGetDataDnf(nf));
END PQSDNF;

PROCEDURE PQCnfSimplify(nu:LIST):LIST;
(* polynomial equation cnf based simplification. nu is an quantifier free
formula. The formula nu is simplified. Consult the documentation for a 
description of the rules which are applied *)
BEGIN
	DLSWRITE("starting cnf based simplification",1);
(*	DLPQPRT("Input formula",nu,2); *)
	RETURN PQSimplify1(SimplifyNf(PQMKCNF(PQSMPL(nu))),1); 
END PQCnfSimplify;

PROCEDURE PQDnfSimplify(nu:LIST):LIST;
(* polynomial equation dnf based simplification. nu is an quantifier free
formula. The formula nu is simplified. Consult the documentation for a 
description of the rules which are applied *)
BEGIN
	DLSWRITE("starting cnf based simplification",1);
(*	DLPQPRT("Input formula",nu,2); *)
	RETURN PQSimplify1(SimplifyNf(PQMKDNF(PQSMPL(nu))),2);
END PQDnfSimplify;


PROCEDURE PQSimplify1(nf,type: LIST):LIST;
(* polynomial equation simplification. nf is a quantifier free formula
in cnf (type=1) or dnf (type=2). Consult the documentation for a description
of the rules which are applied. The formula is divided in two parts:
Implications of the form "(AND PHI=0) => gamma=0" and a conjunction of
the form "AND PSI=0". PHI=0 denotes a set of polynomial equations phi=0 and
PSI=0 denotes a set of polynomial equations psi=0. *)
	VAR POLS, PSI, GB1, GBi2, PHI, GAMMA, gamma, phi: LIST;
	VAR gamma1: LIST;
	VAR GAMMA1, PHI1, phi1, B: LIST;
	VAR domain: LIST;
BEGIN
	IF (nf=VERUM) OR (nf=FALSUM) THEN
		DLPQPRT("Input formula in SNF",nf,2);
		RETURN nf;
	END;
	IF type=1 THEN
		POLS:=PQGetData1(nf,1);	
		DLPQPRT("Input formula in SCNF",PQscnf(POLS),2);
	ELSE 
		POLS:=PQGetData1(nf,2);	
		DLPQPRT("Input formula in SDNF",PQsdnf(POLS),2);
	END;
	PSI:=THIRD(POLS);
	DLSWRITE("1.) consistency test over psi",1);
	GB1:=SIL;
	IF PSI<>SIL THEN
		domain:=ADDDFDIP(FIRST(PSI));
		GB1:=DIPADGB(PSI); (* This computation is not necceary
					in the case of PQRMSTest<=3 *)
		IF IdealMember(GB1,DIPONE(domain)) THEN
			IF type=1 THEN
				RETURN FALSUM;
			ELSE
				RETURN VERUM;
			END
		END;
		CASE INTEGER(PQIBREP) OF
		0:				|
		1: 	PSI:=DIPADIRSET(PSI);	|
		2:	PSI:=DIPADIRSET(GB1);
		ELSE ERROR(severe,"PQIBREP unknown code!");
		END;
	END;
	PHI:=FIRST(POLS);
	GAMMA:=SECOND(POLS);
	GAMMA1:=SIL;
	PHI1:=SIL;
	DLSWRITE("2.) simplification of the implications",1);
	WHILE PHI<>SIL DO
		ADV(GAMMA,gamma,GAMMA);
		ADV(PHI,phi,PHI);
		IF NOT TestRMember(phi,GB1,gamma,B,gamma1) THEN 
			GAMMA1:=COMP(gamma1,GAMMA1);
			PHI1:=COMP(B,PHI1);
		END;
	END;
	IF type=1 THEN
		RETURN PQSMPL(PQscnf(LIST3(INV(PHI1),INV(GAMMA1),PSI)));
	ELSE
		RETURN PQSMPL(PQsdnf(LIST3(INV(PHI1),INV(GAMMA1),PSI)));
	END
END PQSimplify1;

PROCEDURE SimplifyNf(nf: LIST):LIST;
(* simplify normal form. nf is a formula in disjunctive normal form or
conjunctive normal form. A simplification of nf is returned.
Following rules are applied: Equal literals in clauses are contracted,
atomic formulas with identical polynomials are contracted to TRUE or FALSE. *)
(* Note: identical clauses are not contracted. This happens in the
GetDataXXX Procedures. In this procedure equal implications are contracted. *)
	VAR literal, clause, lhs, rel, op1, op2, Literals, Clauses: LIST;
	VAR  PolRel, ResLits, ResClaus, assoc, s: LIST;
	VAR exit: BOOLEAN;
BEGIN
	s:=PQSMPL(nf);    (* To strong ! *)
	IF (s=VERUM) OR (s=FALSUM) THEN RETURN s; END;
	FORPFOR(nf,op1,Clauses);
	ResClaus:=SIL;
	WHILE Clauses<>SIL DO
		ResLits:=SIL;
		PolRel:=SIL;
		FORPARGS(Clauses, clause, Clauses);
		FORPFOR(clause,op2,Literals);
		exit:=FALSE;
		WHILE (Literals<>SIL) AND NOT exit DO
			FORPFOR(Literals,literal,Literals);
			pqpaf(literal,rel,lhs);
			assoc:=ASSOCQ(lhs,PolRel);
			IF assoc=SIL THEN
				PolRel:=COMP2(lhs,rel,PolRel);
				ResLits:=COMP(literal,ResLits);
			ELSIF FIRST(assoc)<>rel THEN
				DLSWRITE("smart simplify successful",3);
				ResLits:=SIL;
				exit:=TRUE;
			ELSE
				DLSWRITE("identical atomic formulas deleted",
					3);
			END;
		END;
		IF ResLits<>SIL THEN
			ResClaus:=COMP(FORMKFOR(op2,INV(ResLits)),ResClaus);
		END;
	END;
	IF (ResClaus=SIL) AND (op1=ET) THEN
		RETURN VERUM;
	ELSIF (ResClaus=SIL) AND (op1=VEL) THEN
		RETURN FALSUM;
	ELSE (* ResClaus<>SIL *)
		RETURN FORMKFOR(op1,INV(ResClaus));
	END;
END SimplifyNf;


(******************************************************************************
*                          P R E P R O Z E S S I N G                          *
******************************************************************************)

(******************************************************************************
* data structure SNFC ("Simplification Normal Form Content")                  *
*                                                                             *
* This datastructure represents the important datas from a formula in SCNF    *
* or SDNF. A variable of the type SNFC is a list with three elements.         *
* The first and second elemts represents the first part of the S?NF and the   *
* third element the second part of the S?NF.                                  *
* The first and the second element are lists with one element for each        *
* implikation in the S?NF. Each element in the first list is a list of all    *
* polynomials in the premise of the implication. Each element in the second   *
* list is the polynomial in the conclusion. The third element is a list of    *
* all polynomials in the second part of the S?NF.                             *
******************************************************************************)
 
PROCEDURE PQGetDataCnf(cnf: LIST): LIST;
(* polynomial equation get data from cnf. *)
BEGIN
	RETURN PQGetData1(cnf,1);
END PQGetDataCnf;

PROCEDURE PQGetDataDnf(dnf: LIST): LIST;
(* polynomial equation get data from dnf. *)
BEGIN
	RETURN PQGetData1(dnf,2);
END PQGetDataDnf;

PROCEDURE PQGetData1(nf,type: LIST):LIST;
(* polynomial equation get data. nf is a cnf (type=1) or a dnf (type=2).
The polynomials which occurs in the formula nf are extracted. 
The formula is  transformed in a formula with a structure 
similar to (OP (AND PHI_j=0) => gamma_i=0) OP (AND PSI=0). 
PHI_j=0 denotes a set of polynomial equations phi_ij=0 and PSI=0
denotes a set of polynomial equations psi=0. A list with the following 
format is returned. (PHI,GAMMA,PSI), where PHI is a list of a list of 
the polynomials in PHI_j, GAMMA is a list of the polynomials gamma_j, and 
PSI is a list of the polynomials on PSI=0. *)
	VAR clause,atomic:LIST;
	VAR POS,NEG:LIST;
	VAR PHI,GAMMA,PSI: LIST;
	VAR dummy,HLP: LIST;
	VAR rel,pol,domain,af: LIST;
BEGIN
	PHI:=SIL; PSI:=SIL; GAMMA:=SIL;
	FORPFOR(nf,dummy,nf);
	(* extract the domain descriptor *)
	af:=FIRST(FORGARGS(FIRST(nf)));	(* The first atomic formula of the 
					   first clause. *)
	pqpaf(af,dummy,pol);
	domain:=ADDDFDIP(pol);
	(* *** *)
	WHILE nf<>SIL DO
		FORPARGS(nf,clause,nf);
		FORPFOR(clause,dummy,clause);
		POS:=SIL; NEG:=SIL;
		WHILE clause<>SIL DO
			FORPARGS(clause,atomic,clause);
			pqpaf(atomic,rel,pol);
			IF rel=NEQ THEN
				NEG:=COMP(pol,NEG);
			ELSIF rel=EQU THEN
				POS:=COMP(pol,POS);
			ELSE
				ERROR(severe,"unknown relation symbol");
			END;
		END;
		IF type<>1 THEN		(* a logical negation is necessary *)
			HLP:=NEG;
			NEG:=POS;
			POS:=HLP;
		END;
		IF NEG=SIL THEN		
			PSI:=SETADD(DILPROD(POS,domain),PSI);
		ELSE
			NEG:=INV(NEG);
			POS:=DILPROD(POS,domain);
			IF NOT SeqPair(NEG,PHI,POS,GAMMA) THEN
				PHI:=COMP(NEG,PHI);
				GAMMA:=COMP(POS,GAMMA);
			ELSE
				DLSWRITE("identical implications deleted", 3);
			END;
		END;
	END;
	RETURN LIST3(INV(PHI),INV(GAMMA),INV(PSI));
END PQGetData1;

(******************************************************************************
*                         P O S T P R O C E S S I N G                         *
******************************************************************************)

PROCEDURE PQscnf(POLS: LIST):LIST;
(* polynomial equation simplification conjunctive normal form. 
POLS is a list in the format, that PQGetDataCnf returns.
The SCNF associated with the list POLS is returned. *)
	VAR fst,snd: LIST;
BEGIN
	PQsnf1(POLS,1,fst,snd);
	IF (fst=SIL) AND (snd=SIL) THEN
		RETURN VERUM;
	ELSIF fst=SIL THEN
		RETURN FORMKFOR(ET,INV(snd));
	ELSIF snd=SIL THEN
		RETURN FORMKFOR(ET,INV(fst));
	ELSE
		RETURN FORMKBINOP(ET,FORMKFOR(ET,INV(fst)),
				     FORMKFOR(ET,INV(snd)));
	END;
END PQscnf;

PROCEDURE PQsdnf(POLS: LIST):LIST;
(* polynomial equation simplification disjunctive normal form. 
POLS is a list in the format, that PQGetDataCnf returns.
The SDNF associated with the list POLS is returned. *)
	VAR fst, snd: LIST;
BEGIN
	PQsnf1(POLS,2,fst,snd);
	IF (fst=SIL) AND (snd=SIL) THEN
		RETURN FALSUM;
	ELSIF fst=SIL THEN
		RETURN FORMKUNOP(NON,FORMKFOR(ET,INV(snd)));
	ELSIF snd=SIL THEN
		RETURN FORMKFOR(VEL,INV(fst));
	ELSE
		RETURN FORMKBINOP(VEL,FORMKFOR(VEL,INV(fst)),
				     FORMKUNOP(NON,FORMKFOR(ET,INV(snd))));
	END;
END PQsdnf;

PROCEDURE PQsnf1(POLS,type:LIST;VAR fst,snd: LIST);
(* polynomial equation simplification normal form. 
POLS is a list in the format, that PQGetDataCnf returns.
The first and the second part of the SCNF (type=1) or SDNF (type=2) 
is returned. fst=SIL or snd=sil indicates, that this part can be omitted. *) 
	VAR PHIij, PHIj, phi, GAMMAi, gamma, PHIj1, PSIi, psi: LIST;
BEGIN
	ADV3(POLS,PHIij,GAMMAi,PSIi,POLS);
	fst:=SIL;
	WHILE PHIij<>SIL DO
		ADV(PHIij,PHIj,PHIij);
		ADV(GAMMAi,gamma,GAMMAi);
		PHIj1:=SIL;
		WHILE PHIj<>SIL DO
			ADV(PHIj,phi,PHIj);
			PHIj1:=COMP(pqmkaf(EQU,phi),PHIj1)
		END;
		IF type=1 THEN
			fst:=COMP(FORMKBINOP(IMP,FORMKFOR(ET,INV(PHIj1)),
				pqmkaf(EQU,gamma)),fst);
		ELSE
			fst:=COMP(FORMKUNOP(NON,FORMKBINOP(IMP,FORMKFOR(ET,
				INV(PHIj1)),pqmkaf(EQU,gamma))),fst);
		END;
	END;
	snd:=SIL;
	WHILE PSIi<>SIL DO
		ADV(PSIi,psi,PSIi);
		snd:=COMP(pqmkaf(EQU,psi),snd);
	END;
	RETURN;
END PQsnf1;


(******************************************************************************
*                       I D E A L   P R O C E D U R E S                       *
******************************************************************************)

PROCEDURE TestRMember(F,G,p:LIST; VAR B,p1: LIST):BOOLEAN;
(* test radical membership. F is a final radical basis, 
G is a Groebner basis. p is a polynomial. If true is 
returned then p in RAD(F join G). Note: If p is in the radical
then true is not necessary returned! 
A new ideal basis of Id(F) is assigned to B. *)
	VAR result:BOOLEAN;
BEGIN
	CASE INTEGER(PQIBREP) OF
	0:	result:=TestRMember1(F,G,p,p1);
		B:=F;						|	
	1:	B:=DIPADIRSET(F);	
		result:=TestRMember1(F,G,p,p1);			|
	2:	B:=DIPADGB(F);
		result:=TestRMember1(SIL,DIPADGBunion(B,G),p,p1);
	ELSE 	ERROR(severe,"PQIBREP unknown code!");
	END;		
	RETURN result;
END TestRMember;

PROCEDURE TestRMember1(F,G,p:LIST;VAR p1: LIST):BOOLEAN;
(* test radical membership 1. F is a final radical basis, 
G is a Groebner basis. p is a polynomial. If true is 
returned then p in RAD(F join G). Note: If p is in the radical
then true is not necessary returned! *)
	VAR GB, F1, F0, RGB, power, POWERS: LIST;
	VAR result: BOOLEAN;
	VAR domain:LIST;
BEGIN
	IF p=0 THEN RETURN TRUE; END;
	domain:=ADDDFDIP(p);
	result:=FALSE;
	CASE INTEGER(PQRMSTest) OF
	1:	result:=MEMBER(p,CCONC(G,F))=1; 		|
	2: 	F1:=CCONC(G,F);
		result:=(MEMBER(p,F1)=1) OR (DIPADNF(F1,p)=0);	|
	3:	F0:=CCONC(G,F);
		F1:=DIPADIRSET(F0);	
		result:=(MEMBER(p,F0)=1) OR (MEMBER(p,F1)=1)
			OR (DIPADNF(F1,p)=0);	|
	4: 	GB:=DIPADGBext(G,F);
		result:=IdealMember(GB,p) 			|
	5:	POWERS:=PQPOWERS;
		IF EQUAL(DIPONE(domain),p)=1 THEN
			POWERS:=LIST1(1);
		END;
		GB:=DIPADGBext(G,F);	
		WHILE (POWERS<>SIL) AND NOT result DO
			ADV(POWERS,power,POWERS);
			IF IdealMember(GB,DIPPOWER(p,power)) THEN
				result:=TRUE;
			END;
		END; 						|
	6: 	GB:=DIPADGBext(G,F);
		result:= (IdealMember(GB,p) OR
			RadicalMember(GB,p)) 			|
	7: 	(* GB:=DIPADGBext(G,F); 
		result:=RadicalMember(GB,p); *)
		result:=RadicalMember(CCONC(G,F),p); 
	ELSE
		ERROR(severe,"TestRMember: unknown code");
		RETURN FALSE;
	END;
	IF (PQRMSTest>3) AND (PQREDCON=1) THEN
		DLSWRITE("computing the normal form of the conclusion",2);
		p1:=DIPADNF(GB,p);
		DLSWRITE("... finished.",2);
	ELSE
		p1:=p;
	END;
	IF PQTRACE>=1 THEN
		IF result THEN
			SWRITE("Radical membership test ");
			AWRITE(PQRMSTest);
			SWRITE(" succeed.");
			BLINES(0); 
		ELSE
			SWRITE("Radical membership test ");
			AWRITE(PQRMSTest);
			SWRITE(" failed.");
			BLINES(0); 
		END;
	END;
	RETURN result;
END TestRMember1;

PROCEDURE IdealMember(G,p:LIST):BOOLEAN;
(* ideal membership test. G is groebner basis. Iff p in ID(g) then 1 
is returned otherwise 0. *)
BEGIN
	RETURN DIPADNF(G,p)=0;
END IdealMember;

PROCEDURE RadicalMember(G,p:LIST):BOOLEAN;
(* radical membership test. G is an ideal basis. Iff p in RAD(G) then 1 is
returned otherwise 0. The new variable Rw is introduced. *)
	VAR G1, G2: LIST;
	VAR result: BOOLEAN;
	VAR p1: LIST;
	VAR domain: LIST;
BEGIN
	IF p=0 THEN RETURN TRUE; END;
	domain:=ADDDFDIP(p);
	G1:=DILINV(G,0,1);
	p1:=DIPINV(p,0,1);
	ValisPush(COMP(LIST2(45,54),VALIS));
(*	G2:=DIPADGBext(G1,LIST1(rabinowitsch(p1)));*)
	G2:=DIPADGB(COMP(rabinowitsch(p1),G1));
	result:=DIPADNF(G2,DIPONE(domain))=0;
	ValisPop();
	RETURN result;
END RadicalMember;

PROCEDURE rabinowitsch(p:LIST):LIST;
(* rabinowitsch. p is a non zero polynomial.
The polynomial 1-Zp is returned. Z denotes the variable with the exponent
vector (0,...,0,1). *)
	VAR z,zexp,nov,dipone: LIST;
	VAR domain: LIST;
BEGIN
	domain:=ADDDFDIP(p);
	nov:=DIPNOV(p);
	dipone:=DIPFMO(ADFI(domain,1),GenEV(0,nov));
	zexp:=GenEV(0,nov-1);
	zexp:=INV(COMP(1,zexp));
	z:=DIPFMO(ADFI(domain,1),zexp);
	RETURN DIPSUM(dipone,DIPNEG(DIPROD(z,p)));
END rabinowitsch;


(******************************************************************************
*                       D I P A D - P R O C E D U R E S                       *
******************************************************************************)

PROCEDURE DIPADGB(P:LIST):LIST;
(* distributive polynomial arbitrary domain groebner basis. P is a list of
polynomials (over the ring of integers). A groebner basis of P is returned.
This procedure is at moment only a dummy procedure. It should
calculate a groebner basis in respect to the coefficient ring of the
polynomials. *)
	VAR g:LIST;
BEGIN
	DLSWRITE("Computing a Groebner Base ...",2);
	g:=DIPGB(P,0);
	DLSWRITE("... finished!",2);
	RETURN g;
END DIPADGB;

PROCEDURE DIPADNF(P,S:LIST):LIST;
(* distributive polynomial arbitrary domain normal form. P is a list of
polynomials. The normal form of the polynomial
S w.r.t. P is returned. This procedure is at moment only a dummy. Is should
work on Polynomials over arbitrary fields and rings. *)
BEGIN
	RETURN DIPNOR(P,S);
END DIPADNF;

PROCEDURE DILADNF(P,S:LIST):LIST;
(* distributive polynomial list arbitrary domain normal form. P is a list of
polynomials. S is a list of polynomials.
The list of normal forms of the polynomials of 
S w.r.t. P is returned. This procedure is at moment only a dummy. Is should
work on Polynomials over arbitrary fields and rings. *)
	VAR s,result: LIST;
BEGIN
	result:=SIL;
	WHILE S<>SIL DO
		ADV(S,s,S);
		result:=COMP(DIPADNF(P,s),result);
	END;
	RETURN INV(result);
END DILADNF;

PROCEDURE DIPADGBext(gb,pols:LIST):LIST;
(* distributive polynomial arbitrary domain groebner basis extension.
gb is a groebner basis, pols is a list of polynomials.
A groebner basis of the ideal basis gb join pols is calculated and
returned. This procedure is at moment only a dummy. *)
BEGIN
	IF pols=SIL THEN RETURN gb; END;
	RETURN DIPADGB(CCONC(gb,pols));
END DIPADGBext;

PROCEDURE DIPADGBunion(gb1,gb2:LIST):LIST;
(* distributive polynomial arbitrary domain groebner basis union. gb1 and
gb2 are groebner basis. A groebner basis of the ideal basis gb1 join gb2
is calculated and returned. This procedure is at moment only a dummy. *)
BEGIN
	IF gb2=SIL THEN RETURN gb1; END;
	IF gb1=SIL THEN RETURN gb2; END;
	RETURN DIPADGB(CCONC(gb1,gb2));
END DIPADGBunion;

PROCEDURE DIPADIRSET(P:LIST):LIST;
(* distributive polynomial arbitrary domain irreducible set. P is a list
of polynomials. A set PP of polynomials is returned. PP is the result of 
reducing each element p modulo P - {p} until no further reductions are 
possible. *)
BEGIN
	RETURN DILIS(P);
END DIPADIRSET;

PROCEDURE DIPADGBRED(gb: LIST):LIST;
(* distributive polynomial groebner basis reduction. gb is a groebner basis
of distributive polynomials over an arbitrary domain. 
The unique reduced and ordered groebner basis to gp is returned. *)
BEGIN
	IF (gb=SIL) OR (RED(gb)=SIL) THEN RETURN gb; END;
	RETURN DIPLPM(DILIS(gb));
END DIPADGBRED;


(******************************************************************************
*                   A U X I L I A R Y   P R O C E D U R E S                   *
******************************************************************************)

PROCEDURE SETADD(elem,set: LIST):LIST;
(* set add element. If the element elem is not in the set set, then
{elem} join set is returned else set is returned. *)
BEGIN
	IF MEMBER(elem,set)=1 THEN
DLSWRITE("SETADD: element already in the set!",3);
		RETURN set;
	ELSE
		RETURN COMP(elem,set);
	END;
END SETADD;

PROCEDURE GenEV(value,length:LIST):LIST;
(* generate exponent vector. A exponent vector of the length length with
entries value is generated. *)
	VAR i: INTEGER;
	VAR result:LIST;
BEGIN
	result:=SIL;
	FOR i:=1 TO length DO
		result:=COMP(value,result);
	END;
	RETURN result;
END GenEV;

PROCEDURE SeqPair(elem1,SEQ1,elem2,SEQ2:LIST): BOOLEAN;
(* sequence pair. elem1 and elem2 are elements, SEQ1, SEQ2 are final sequences
with the same length.
1 is returned iff there is a n in Nat such that elem1=SEQ1_n and elem2=SEQ2_n.
*)
	VAR seq1,seq2: LIST;
BEGIN
	WHILE SEQ1<>SIL DO
		ADV(SEQ1,seq1,SEQ1);
		ADV(SEQ2,seq2,SEQ2);
		IF (EQUAL(seq1,elem1)=1) AND (EQUAL(seq2,elem2)=1) THEN
			RETURN TRUE;
		END;
	END;
	RETURN FALSE;
END SeqPair;

(******************************************************************************
*                                O P T I O N S                                *
******************************************************************************)
			
PROCEDURE PQOPT(O:LIST):LIST;
(* polynomial equation options. The options of the PQ-System are set.
The list O is of the following format: The first entry
is the trace level of the system, the second entry determines the method for 
the radical membership test, the third entry is a list of powers for the 
pseudo radical membership test, the fourth entry controls the replacement
of the premises of the implications, and the fifth entry controls the 
You can omit an entry of O 
by writing a -1 on the place of the entry. You need not specify all entries.
The old parameters are returned. *)
	VAR old: LIST;
BEGIN
	old:=LIST5(PQTRACE,PQRMSTest,PQPOWERS,PQIBREP,PQREDCON);
	IF O<>SIL THEN 
		IF FIRST(O)<>-1 THEN ADV(O,PQTRACE,O);	ELSE O:=RED(O); END;
	END;
	IF O<>SIL THEN 
		IF FIRST(O)<>-1 THEN ADV(O,PQRMSTest,O);ELSE O:=RED(O); END;
	END;
	IF O<>SIL THEN 
		IF FIRST(O)<>-1 THEN ADV(O,PQPOWERS,O);	ELSE O:=RED(O); END;
	END;
	IF O<>SIL THEN 
		IF FIRST(O)<>-1 THEN ADV(O,PQIBREP,O);	ELSE O:=RED(O); END;
	END;
	IF O<>SIL THEN 
		IF FIRST(O)<>-1 THEN ADV(O,PQREDCON,O);	ELSE O:=RED(O); END;
	END;
	RETURN old;
END PQOPT;

PROCEDURE PQOPTWR();
(* polynomial options write. The options of the PQ-System are printed in the
output stream. *)
BEGIN
	SWRITE("The setting of the options of the PQ-System:");
	BLINES(0);
	SWRITE("  The trace level is "); AWRITE(PQTRACE);
	SWRITE(".");BLINES(0);
	SWRITE("  Radical memebership test using ");
	BLINES(0);
	CASE INTEGER(PQRMSTest) OF
	1:	SWRITE("    element test.");				|
	2:	SWRITE("    reduction with the ideal basis."); 		|
	3: 	SWRITE("    reduction with the interreduced ideal basis.");|
	4:	SWRITE("    ideal membership test.");			|
	5:	SWRITE("    ideal membership test with the ");
		IF RED(PQPOWERS)=SIL THEN
			SWRITE("power "); AWRITE(FIRST(PQPOWERS));
		ELSE
			SWRITE("powers "); UWRIT1(PQPOWERS);
		END;
		SWRITE(".");						|
	6:	SWRITE("    radical membership test after ideal membership test."); |
	7:	SWRITE("    radical membership test."); 		|
	ELSE	SWRITE("    unknown test method specified!");
	END;
	BLINES(0);
	CASE INTEGER(PQIBREP) OF
	0: 	SWRITE("  Conjunctions over polynomial equations are not replaced."); |
	1:	SWRITE("  Reducing conjunctions over polynomial equations with the"); 
		BLINES(0);
		SWRITE("    interreduction-method.");	|
	2:	SWRITE("  Reducing conjunctions over polynomial equations with the");
		BLINES(0);
		SWRITE("    Groebner-Basis-method.");
	ELSE 	SWRITE("WARNING: unknown code for PQIBREP");
	END;
	BLINES(0);
	IF PQREDCON=0 THEN
		SWRITE("  The conclusions in the implications are not reduced.");
	ELSE
		SWRITE("  The conclusions in the implications are reduced.");
	END;
	BLINES(0);
END PQOPTWR;

(******************************************************************************
*                             D E B U G L E V E L                             *
******************************************************************************)

PROCEDURE PQSetTrace(level:LIST):LIST;
(* polynomial equation set debug level. The debug level is set to level.
The old value is returned. *)
	VAR old:LIST;
BEGIN
	old:=PQTRACE;
	PQTRACE:=level;
	RETURN old;
END PQSetTrace;

PROCEDURE PQGetTrace():LIST;
(* polynomial equation get debug level. The actual debug level is returned. *)
BEGIN
	RETURN PQTRACE;
END PQGetTrace;

PROCEDURE DLSWRITE(S: ARRAY OF CHAR;level:LIST);
(* debug level SWRITE. The string S is in dependency of the debug level
written to the output stream. In contrast to MAS a blank line is added.
(analogous to UWRITE and UWRIT1) *)
BEGIN
	IF PQTRACE >= level THEN
		SWRITE(S);
		BLINES(0);
	END;
END DLSWRITE;

PROCEDURE DLSWRIT1(S: ARRAY OF CHAR;level:LIST);
(* debug level SWRITE. The string S is in dependency of the debug level
written to the output stream. *)
BEGIN
	IF PQTRACE >= level THEN
		SWRITE(S);
	END;
END DLSWRIT1;

PROCEDURE DLUWRITE(L,level:LIST);
(* debug level UWRITE. The list L is in dependency of the debug level
written to the output stream. *)
BEGIN
	IF PQTRACE >= level THEN
		UWRITE(L);
	END;
END DLUWRITE;

PROCEDURE DLUWRIT1(L,level:LIST);
(* debug level UWRIT1. The list L is in dependency of the debug level
written to the output stream. *)
BEGIN
	IF PQTRACE >= level THEN
		UWRIT1(L);
	END;
END DLUWRIT1;

PROCEDURE DLBLINES(n:LIST;level:LIST);
(* debug level BLINES. n blank lines are in dependency of the debug level
written to the output stream. *)
BEGIN
	IF PQTRACE >= level THEN
		BLINES(n);
	END;
END DLBLINES;

PROCEDURE DLPQPRT(S:ARRAY OF CHAR; phi: LIST; level:LIST);
(* debug level polynomial equation print. The string S is written to the
output stream, the the formula phi is written to the output stream. As the
final step a blank lines is written to the output stream. *)
BEGIN
	IF PQTRACE>= level THEN
		SWRITE(S);
		BLINES(0);
		PQPPRT(phi);
		BLINES(0);
	END;
END DLPQPRT;

PROCEDURE PQDEMO();
(* Demonstration for this package. *)
	VAR V, phi: LIST;
BEGIN
	SWRITE("           ");
	SWRITE("D E M O N S T R A T I O N   O F   T H E   P Q - S Y S T E M");
	BLINES(2);
	SWRITE("Enter the list of variables, please!");
	BLINES(1);
	V:=UREAD();
	VALIS:=V;
	BLINES(0);
	SWRITE("Enter the formula, please!");
	BLINES(1);
	phi:=PQIREAD();
	phi:=PQCnfSimplify(phi);
	BLINES(1);
	SWRITE("The result is:");
	PQPPRT(phi);
	BLINES(2);
END PQDEMO;

(******************************************************************************
*                                   M A I N                                   *
******************************************************************************)

BEGIN
	(* *** listvar declarations for global variables. *** *)
	LISTVAR(PQRMSTest);
	LISTVAR(PQPOWERS);
	LISTVAR(PQTRACE);
	LISTVAR(PQIBREP);
	LISTVAR(PQREDCON);
	(* *** initialize the global variables. ***  *)
	PQTRACE:=0;
	PQPOWERS:=LIST1(1);;
	PQRMSTest:=6;
	PQIBREP:=1;
	PQREDCON:=0;
END PQSMPL.

(* -EOF- *)
