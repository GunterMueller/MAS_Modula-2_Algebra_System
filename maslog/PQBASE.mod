(* ----------------------------------------------------------------------------
 * $Id: PQBASE.mi,v 1.2 1996/05/19 07:53:50 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: PQBASE.mi,v $
 * Revision 1.2  1996/05/19 07:53:50  dolzmann
 * Bug fixed in pqsimplifyaf.
 *
 * Revision 1.1  1994/11/28  21:10:04  dolzmann
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

IMPLEMENTATION MODULE PQBASE;
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

FROM DIPADOM	IMPORT	DILWR, DIPNEG, DIPROD, DIPSUM, DIREAD, DIWRIT;
FROM DIPC	IMPORT	DILBSO, DIPBSO, DIPERM, DIPFMO, DIPINV, DIPLPM,
			DIPMAD, DIPMCP, DIPNOV, EVORD, EVSIGN, GRLEX,
			IGRLEX, INVLEX, LEX, REVILEX, REVITDG, REVLEX,
			REVTDEG, VALIS, DIPLBC;
FROM DIPTOOLS	IMPORT	DIPCNST, DIPIMO, DIPMVV;
FROM DOMRN	IMPORT	DOMRND; 
FROM LISTTOOLS	IMPORT	LSRCHQ; 
FROM MASADOM	IMPORT	ADDDREAD, ADDDWRIT, ADFI, ADGCD, ADNEG, ADONE,
			ADQUOT, ADSIGN, ADWRIT,ADPCPP;
FROM MASBIOS	IMPORT	BKSP, BLINES, CREAD, CREADB, CWRITE, DIBUFF, DIGIT,
			LETTER, LISTS, MASORD, SWRITE;
FROM MASELEM	IMPORT	GAMMAINT;
FROM MASERR	IMPORT	ERROR, confusion, fatal, harmless, severe, spotless;
FROM MASLISPU	IMPORT	Declare, PROCF1, PROCF2; 
FROM MASLOG	IMPORT	FORAPPLYAT, FORELIMXOPS, FORMKCNF, FORMKDNF,
			FORMKPOS, FORMKPRENEX, FORMKPRENEX1, FORMKVD,
			FORREPAFS, FORSIMPLIFY, FORSIMPLIFYP, FORSMPL;
FROM MASSET	IMPORT	SetUnion; 
FROM MASSTOR	IMPORT	ADV, COMP, FIRST, INV, LENGTH, LIST, LIST1, LISTVAR,
			RED, SFIRST, SIL, SRED;
FROM MASSYM	IMPORT	ATOM, MEMQ;
FROM MASSYM2	IMPORT	ASSOC, ASSOCQ, EXPLOD, SREAD1, SYMBOL, UREAD, UWRIT1,
			UWRITE;			
FROM MLOGBASE	IMPORT	ANY, EQUIV, ET, EXIST, FALSUM, FORALL, FORGARGS,
			FORGLVAR, FORGOP, FORMKBINOP, FORMKFOR, FORMKLVAR,
			FORMKUNOP, FORMKVAR, FORPARGS, FORPBINOP, FORPFOR,
			FORPQUANT, FORPUNOP, FORPUNOPA, FORPVAR, FORVTENTER,
			FORVTGET, IMP, NON, REP, TVAR, VEL, VERUM, XOR; 
FROM MLOGIO	IMPORT	FORIREAD, FORPPRT, FORPREAD, FORTEXW, KEYREAD;
FROM SACLIST	IMPORT	ADV2, ADV3, ADV4, AWRITE, CCONC, CINV, CLOUT, COMP2,
			CONC, EQUAL, FIRST2, LIST10, LIST2, LIST3, LIST4,
			LIST5, MEMBER, SECOND, SLELT, SUFFIX, THIRD;
FROM SACPOL	IMPORT	VLREAD, VLWRIT; 
FROM SACSET	IMPORT	LBIBMS;

CONST rcsidi = "$Id: PQBASE.mi,v 1.2 1996/05/19 07:53:50 dolzmann Exp $";
CONST copyrighti = "Copyright (c) 1993 Universitaet Passau";

(******************************************************************************
*                       G L O B A L   V A R I A B L E S                       *
******************************************************************************)

VAR BbfParserSyms: LIST;(* The symbol table for the symbols of atomic
				   formulas. *)

VAR NewVariables: INTEGER;
(******************************************************************************
*                        A T O M I C   F O R M U L A S                        *
******************************************************************************)

PROCEDURE pqmkaf(rel:LIST;pol:LIST):LIST;
(* polynomial equation make atomic formula.
rel is a relation, pol is a
polynomial, the atomic formula (rel,id) is returned. *)
BEGIN
	RETURN LIST2(rel,pol);
END pqmkaf;

PROCEDURE pqpaf(af:LIST; VAR rel,pol:LIST);
(* polynomial equation parse atomic formula. af is an atomic
formula; the relation symbol of af is in rel returned; the polynomial of af
is in id returned. *)
BEGIN
	FIRST2(af,rel,pol);
END pqpaf;

PROCEDURE pqgrel(af:LIST):LIST;
(* polynomial equation get relation symbol. af is an atomic formula. The 
relation symbol of af is returned. *)
BEGIN
	RETURN FIRST(af);
END pqgrel;

PROCEDURE pqgpol(af:LIST):LIST;
(* polynomial equation get relation symbol. af is an atomic formula. The 
polynomial of af is returned. *)
BEGIN
	RETURN SECOND(af);
END pqgpol;

PROCEDURE pqatom(phi:LIST):BOOLEAN;
(* polynomial equation atomic formula. pqatom returns true
iff phi has the structure of an atomic formula, i.e. phi is a list 
with two elements, and the first element of the list is an valid
relation symbol. *)
	VAR rel,id: LIST;
BEGIN
	IF (phi=SIL) OR ATOM(phi) OR SYMBOL(phi) THEN RETURN FALSE; END;
	ADV(phi,rel,phi);
	IF (phi=SIL) OR (RED(phi)<>SIL) THEN RETURN FALSE; END;	
	RETURN 	(rel=EQU) OR (rel=NEQ) OR (rel=LES) OR (rel=GRE) OR 
		(rel=GRQ) OR (rel=LSQ);
END pqatom;

PROCEDURE pqprtaf(af: LIST);
(* polynomial equation print atomic formula. The atomic formula
af is printed.
*)
	VAR rel,pol:LIST;
BEGIN
	ADV2(af,rel,pol,af);
	SWRITE("[");
	DIWRIT(pol,VALIS);
	IF	rel=EQU THEN SWRITE(" = 0]");
	ELSIF	rel=NEQ THEN SWRITE(" <> 0]");
	ELSIF	rel=LES THEN SWRITE(" < 0]");
	ELSIF	rel=GRE THEN SWRITE(" > 0]");
	ELSIF	rel=LSQ	THEN SWRITE(" <= 0]");
	ELSIF	rel=GRQ	THEN SWRITE(" >= 0]");
	ELSE 	ERROR(severe,"pqprtaf: unknown relation symbol");
	END;
END pqprtaf ;

PROCEDURE pqtexwaf(af: LIST);
(* polynomia equation tex write atomic formula. The atomic formula af 
is written to the output stream. *)
	VAR rel,pol:LIST;
BEGIN
	ADV2(af,rel,pol,af);
	BLINES(0);
	DITEX(pol,VALIS);
	IF	rel=EQU THEN SWRITE("=0");
	ELSIF	rel=NEQ THEN SWRITE("\neq 0");
	ELSIF	rel=LES THEN SWRITE("<0");
	ELSIF	rel=GRE	THEN SWRITE(">0");
	ELSIF	rel=LSQ THEN SWRITE("\leq 0");
	ELSIF	rel=GRQ THEN SWRITE("\geq 0");
	ELSE	ERROR(severe,"pqtexwaf: unknown relation symbol");
	END;
END pqtexwaf ;

PROCEDURE DITEX(A,V: LIST); 
(*Distributive polynomial write. A is a distributive
polynomial in r variables, r ge 0. V is a variable list
for A. A is written in the output stream. *)
VAR   AL, AS, E, EL, FL, ES, LL, RL, SL, TL, VL, VS: LIST; 
BEGIN
(*1*) (*rl=0 or a=0.*) 
      IF A = 0 THEN AWRITE(A); RETURN; END; 
      RL:=DIPNOV(A); 
      IF RL = 0 THEN ADWRIT(DIPLBC(A)); RETURN; END; 
(*2*) (*general case.*) AS:=A; FL:=0; (* LL:=DIPNBC(A); 
      IF LL > 1 THEN SWRITE("("); END;  *)
      REPEAT DIPMAD(AS, AL,E,AS); SWRITE(" "); SL:=ADSIGN(AL); 
             IF FL <> 0 THEN 
                IF SL > 0 THEN SWRITE("+"); END; 
                IF SL < 0 THEN SWRITE("-"); AL:=ADNEG(AL); END; 
                END;
             FL:=1; TL:=EVSIGN(E); 
             IF TL = 0 THEN ADWRIT(AL); 
                ELSE SL:=ADONE(AL); 
                IF SL <> 1 THEN ADWRIT(AL); END; 
                ES:=CINV(E); VS:=V; 
                REPEAT ADV(ES, EL,ES); ADV(VS, VL,VS); 
                       IF EL > 0 THEN SWRITE(" "); CLOUT(VL); 
                          IF EL > 1 THEN SWRITE("^{"); 
                             AWRITE(EL); SWRITE("}"); END; 
                          END; 
                       UNTIL ES = SIL; 
                END; 
             UNTIL AS = SIL; 
      SWRITE(" "); 
(*      IF LL > 1 THEN SWRITE(")"); END;  *)
(*5*) RETURN; END DITEX; 

PROCEDURE pqnegaf(af: LIST):LIST;
(* negate atomic formula. af is a atomic formula. The negation of af is
returned. *)
	VAR rel, pol: LIST;
BEGIN
	pqpaf(af,rel,pol);
	IF    rel=EQU THEN RETURN pqmkaf(NEQ,pol);
	ELSIF rel=NEQ THEN RETURN pqmkaf(EQU,pol);
	ELSIF rel=GRE THEN RETURN pqmkaf(LSQ,pol);
	ELSIF rel=LES THEN RETURN pqmkaf(GRQ,pol);
	ELSIF rel=GRQ THEN RETURN pqmkaf(LES,pol);
	ELSIF rel=LSQ THEN RETURN pqmkaf(GRE,pol);
	ELSE ERROR(severe,"pqneqaf: unknown relation symbol in atomic formula.");
	END;
END pqnegaf;

PROCEDURE pqsimplifyaf(af:LIST):LIST;
(* polynomial equation simplify atomic formula. af is an atomic formula. 
af is simplified and af the result is returned. Only the relations between 
a constant polynomial (and zero) are evaluated. Be careful: Use only
polynomials over an domain with a proper ADSIGN function. 
(For example: RN, but not RF.) *)
	VAR rel, lhs, cnst,z,sgn,dummy: LIST;
BEGIN
	pqpaf(af,rel,lhs);
	IF (lhs=0) AND ( (rel=EQU) OR (rel=LSQ) OR (rel=GRQ) ) THEN
		RETURN VERUM;
	ELSIF (lhs=0) AND ( (rel=NEQ) OR (rel=LES) OR (rel=GRE) ) THEN
		RETURN FALSUM;
	ELSIF DIPCNST(lhs) THEN 
		DIPMAD(lhs,cnst,z,dummy);
		sgn:=ADSIGN(cnst);
		IF sgn=-1 THEN 
			IF (rel=LES) OR (rel=LSQ) OR (rel=NEQ) THEN
				RETURN VERUM;
			ELSE
				RETURN FALSUM;
			END;
		ELSIF sgn=0 THEN 
			IF (rel=EQU) OR (rel=LSQ) OR (rel=GRQ) THEN
				RETURN VERUM;
			ELSE
				RETURN FALSUM;
			END;
		ELSIF sgn=1 THEN
			IF (rel=GRE) OR (rel=GRQ) OR (rel=NEQ) THEN
				RETURN VERUM;
			ELSE
				RETURN FALSUM;
			END;
		ELSE
			ERROR(severe,"pqsimplifyaf: unknown ADSIGN value");
		END;
	ELSE
		lhs:=DIPINORM(lhs,rel);
		RETURN pqmkaf(rel,lhs);
	END;
END pqsimplifyaf;

PROCEDURE DIPINORM(p: LIST; VAR rel:LIST):LIST;
(* distributive polynomial over integers normalize.
p is a distributive polynomial over domain DOMI.
The coefficients of the polynomial
are divided by the content of the polyomial p. The highest coefficient 
is normalized to an positive number. The relation rel is adapted.*)
	VAR content,ppt: LIST;
BEGIN
	ADPCPP(p,content,ppt);
	IF ADSIGN(content)=-1 THEN rel:=negrel(rel); END;
	RETURN ppt; 
END DIPINORM;

PROCEDURE negrel(rel: LIST):LIST;
BEGIN
	IF    rel=EQU THEN RETURN EQU;
	ELSIF rel=NEQ THEN RETURN NEQ;
	ELSIF rel=GRE THEN RETURN LES;
	ELSIF rel=LES THEN RETURN GRE;
	ELSIF rel=GRQ THEN RETURN LSQ;
	ELSIF rel=LSQ THEN RETURN GRQ;
	ELSE ERROR(severe,"negrel: unknown relation symbol in atomic formula.");
	END;
END negrel;

PROCEDURE pqreadaf():LIST;
(* polynomial equation read atomic formula. An atomic formula is read from
the input stream. The global variable DOMAIN must be set.
Atomic fomulas have the following syntax: "<dip> <rel> <dip>",
where dip are distributive polynomials over an arbitrary domain 
with the variable list VALIS and rel is one of the sympols 
<,=,>,>=,<>,<=,#,LES,EQU,GRE,LSQ,NEQ,GRQ,LEQ,GEQ. *)
	VAR c: GAMMAINT;
	VAR lhs,rhs,rel,sym:LIST;
BEGIN
	lhs:=DIREAD(VALIS,DOMAIN);
	rel:=KEYREAD();
	sym:=ASSOCQ(rel,BbfParserSyms);
	IF sym=SIL THEN
		DIBUFF();
		ERROR(severe,"pqreadaf: unknown relation symbol.");
		RETURN pqmkaf(EQU,lhs); (* dummy *)
	ELSE
		rel:=FIRST(sym);
	END;
	c:=CREADB();
	IF c=MASORD("]") THEN (* for abbreviation only; not clean, but it is 
					correct. *)
		BKSP();
		rhs:=0;
	ELSE
		BKSP();
		rhs:=DIREAD(VALIS,DOMAIN);
		lhs:=DIPSUM(lhs,DIPNEG(rhs));
	END; 	
	RETURN pqmkaf(rel,lhs);
END pqreadaf;

PROCEDURE InitBbfParser();
(* Initialize black-box formula parser. *)
BEGIN
	BbfParserSyms:=SIL;
	LISTVAR(BbfParserSyms);
	BbfParserSyms:=COMP2(LISTS("<>"),NEQ,BbfParserSyms);
	BbfParserSyms:=COMP2(LISTS("#"),NEQ,BbfParserSyms);
	BbfParserSyms:=COMP2(LISTS("NEQ"),NEQ,BbfParserSyms);
	BbfParserSyms:=COMP2(LISTS("="),EQU,BbfParserSyms);
	BbfParserSyms:=COMP2(LISTS("!="),EQU,BbfParserSyms);
	BbfParserSyms:=COMP2(LISTS("EQU"),EQU,BbfParserSyms);
	BbfParserSyms:=COMP2(LISTS(">"),GRE,BbfParserSyms);
	BbfParserSyms:=COMP2(LISTS("GRE"),GRE,BbfParserSyms);
	BbfParserSyms:=COMP2(LISTS("<"),LES,BbfParserSyms);
	BbfParserSyms:=COMP2(LISTS("LES"),LES,BbfParserSyms);
	BbfParserSyms:=COMP2(LISTS("<="),LSQ,BbfParserSyms);
	BbfParserSyms:=COMP2(LISTS("LSQ"),LSQ,BbfParserSyms);
	BbfParserSyms:=COMP2(LISTS("LEQ"),LSQ,BbfParserSyms);
	BbfParserSyms:=COMP2(LISTS(">="),GRQ,BbfParserSyms);
	BbfParserSyms:=COMP2(LISTS("GRQ"),GRQ,BbfParserSyms);
	BbfParserSyms:=COMP2(LISTS("GEQ"),GRQ,BbfParserSyms);
	RETURN;
END InitBbfParser;

PROCEDURE pqsmart(phi:LIST):LIST;
(* polynomial equation atomic formula smart simplification. 
phi is a conjunction or a disjunction over atomic formulas. 
All atomic formulas with identical left hand sides are contracted to 
one atomic formula. A conjunction or a disjunction over these contracted
formulas is returned. *)
	VAR op,L,result: LIST;
BEGIN
	FORPFOR(phi,op,L);
	IF op=ET THEN
		result:=ContractEt(L);
	ELSIF op=VEL THEN
		result:=ContractVel(L); 
	ELSE 
		BLINES(0);
		UWRIT1(op);
		ERROR(spotless,"pqsmart: operator symbol not valid.");
		RETURN phi;
	END;
	IF (result=VERUM) OR (result=FALSUM) THEN
		RETURN result;
	ELSE
		RETURN FORMKFOR(op,result);
	END;
END pqsmart;

PROCEDURE ContractVel(l:LIST):LIST;
(* contract vel. l is a list of atomic formulas. These atomic formulas are 
interpreted as arguments of a disjunction. The relations of atomic formulas 
with equal left hand sides are contracted. A new list of atomic formulas
is returned. Every two atomic formulas in the returned list have differenet
left hand sides. For the returned list r the following 
equivalent holds VEL(l) <=> VEL(r) *)
	VAR mem, atom, rel, term, rels, fpoint, result: LIST;
BEGIN
	mem:=SIL;
	WHILE l<>SIL DO
		ADV(l,atom,l);
		pqpaf(atom,rel,term);
		fpoint:=ASSOCQ(term,mem);
		IF fpoint=SIL THEN
			mem:=COMP2(term,rel,mem);
		ELSE
			rels:=FIRST(fpoint);
			rels:=PQCRELOR(rels,rel);
		 	SFIRST(fpoint,rels);		
			IF rels=VERUM THEN RETURN VERUM; END;
		END;
	END;
	result:=SIL;
	WHILE mem<>SIL DO
		ADV2(mem,term,rel,mem);
		result:=COMP(pqmkaf(rel,term),result)
	END;
	RETURN result;
END ContractVel;

PROCEDURE PQCRELOR(left,right:LIST):LIST;
(* contract relations or. left and right are relations or the 
constants VERUM, FALSUM, the contraction of
left an right are returned. (this procedure works correct, even if left=SIL.)
*)
BEGIN
	IF 	left=SIL	THEN RETURN right;
	ELSIF	right=SIL	THEN RETURN left;
	ELSIF	left=FALSUM	THEN RETURN right;
	ELSIF	right=FALSUM	THEN RETURN left;
	ELSIF	(left=VERUM) OR (right=VERUM) THEN RETURN VERUM;
	ELSIF	left=right	THEN RETURN right;
	END;
	
	IF   left=LES THEN
		IF    right=LSQ THEN RETURN LSQ;
		ELSIF right=EQU THEN RETURN LSQ;
		ELSIF right=NEQ THEN RETURN NEQ;
		ELSIF right=GRQ THEN RETURN VERUM;
		ELSIF right=GRE THEN RETURN NEQ;
		ELSE ERROR(severe,"PQCRELOR: unknown relation symbol.");
		END;
	ELSIF left=LSQ THEN
		IF    right=LES THEN RETURN LSQ;
		ELSIF right=EQU THEN RETURN LSQ;
		ELSIF right=NEQ THEN RETURN VERUM;
		ELSIF right=GRQ THEN RETURN VERUM;
		ELSIF right=GRE THEN RETURN VERUM;
		ELSE ERROR(severe,"PQCRELOR: unknown relation symbol.");
		END;
	ELSIF left=EQU THEN
		IF    right=LES THEN RETURN LSQ;
		ELSIF right=LSQ THEN RETURN LSQ;
		ELSIF right=NEQ THEN RETURN VERUM;
		ELSIF right=GRQ THEN RETURN GRQ;
		ELSIF right=GRE THEN RETURN GRQ;
		ELSE ERROR(severe,"PQCRELOR: unknown relation symbol.");
		END;	
	ELSIF left=NEQ THEN
		IF    right=LES THEN RETURN NEQ;
		ELSIF right=LSQ THEN RETURN VERUM;
		ELSIF right=EQU THEN RETURN VERUM;
		ELSIF right=GRQ THEN RETURN VERUM;
		ELSIF right=GRE THEN RETURN NEQ;
		ELSE ERROR(severe,"PQCRELOR: unknown relation symbol.");
		END;
	ELSIF left=GRQ THEN
		IF    right=LES THEN RETURN VERUM;
		ELSIF right=LSQ THEN RETURN VERUM;
		ELSIF right=EQU THEN RETURN GRQ;
		ELSIF right=NEQ THEN RETURN VERUM;
		ELSIF right=GRE THEN RETURN GRQ;
		ELSE ERROR(severe,"PQCRELOR: unknown relation symbol.");
		END;
	ELSIF left=GRE THEN
		IF    right=LES THEN RETURN NEQ;
		ELSIF right=LSQ THEN RETURN VERUM;
		ELSIF right=EQU THEN RETURN GRQ;
		ELSIF right=NEQ THEN RETURN NEQ;
		ELSIF  right=GRQ THEN RETURN GRQ;
		ELSE ERROR(severe,"PQCRELOR: unknown relation symbol.");
		END;
	ELSE 
		ERROR(severe,"PQCRELOR: unknown relation symbol.");
	END;
END PQCRELOR;

PROCEDURE ContractEt(l:LIST):LIST;
(* contract vel. l is a list of atomic formulas. These atomic formulas are 
interpreted
as arguments of a disjunction. The relations of atomic formulas with equal
identifiers are contracted. *)
	VAR mem,atom,rel,term,rels,fpoint,result: LIST;
BEGIN
	mem:=SIL;
	WHILE l<>SIL DO
		ADV(l,atom,l);
		pqpaf(atom,rel,term);
		fpoint:=ASSOCQ(term,mem);
		IF fpoint=SIL THEN
			mem:=COMP2(term,rel,mem);
		ELSE
			rels:=FIRST(fpoint);
			rels:=PQCRELAND(rels,rel);
		 	SFIRST(fpoint,rels);		
			IF rels=FALSUM THEN RETURN FALSUM; END;
		END;
	END;
	result:=SIL;
	WHILE mem<>SIL DO
		ADV2(mem,term,rel,mem);
		result:=COMP(pqmkaf(rel,term),result)
	END;
	RETURN result;
END ContractEt;

PROCEDURE PQCRELAND(left,right:LIST):LIST;
(* contract relations or. left and right are relations, the contraction of
left an right are returned. (this procedure works correct, even if left=SIL.)
*)
BEGIN
	IF left=SIL THEN RETURN right; END;
	IF left=right THEN RETURN right; END;
	IF left=FALSUM THEN RETURN right; END;
	
	IF   left=LES THEN
		IF    right=LSQ THEN RETURN LES;
		ELSIF right=EQU THEN RETURN FALSUM;
		ELSIF right=NEQ THEN RETURN LES;
		ELSIF right=GRQ THEN RETURN FALSUM;
		ELSE (* right=GRE *) RETURN FALSUM;
		END;
	ELSIF left=LSQ THEN
		IF    right=LES THEN RETURN LES;
		ELSIF right=EQU THEN RETURN EQU;
		ELSIF right=NEQ THEN RETURN LES;
		ELSIF right=GRQ THEN RETURN EQU;
		ELSE (* right=GRE *) RETURN FALSUM;
		END;
	ELSIF left=EQU THEN
		IF    right=LES THEN RETURN FALSUM;
		ELSIF right=LSQ THEN RETURN EQU;
		ELSIF right=NEQ THEN RETURN FALSUM;
		ELSIF right=GRQ THEN RETURN EQU;
		ELSE (* right=GRE *) RETURN FALSUM;
		END;	
	ELSIF left=NEQ THEN
		IF    right=LES THEN RETURN LES;
		ELSIF right=LSQ THEN RETURN LES;
		ELSIF right=EQU THEN RETURN FALSUM;
		ELSIF right=GRQ THEN RETURN GRE;
		ELSE (* right=GRE *) RETURN GRE;
		END;
	ELSIF left=GRQ THEN
		IF    right=LES THEN RETURN FALSUM;
		ELSIF right=LSQ THEN RETURN EQU;
		ELSIF right=EQU THEN RETURN EQU;
		ELSIF right=NEQ THEN RETURN GRE;
		ELSE (* right=GRE *) RETURN GRE;
		END;
	ELSE (* left=GRE *)
		IF    right=LES THEN RETURN FALSUM;
		ELSIF right=LSQ THEN RETURN FALSUM;
		ELSIF right=EQU THEN RETURN FALSUM;
		ELSIF right=NEQ THEN RETURN GRE;
		ELSE (* right=GRQ *) RETURN GRE;
		END;
	END;
END PQCRELAND;

(******************************************************************************
*                  U N I Q U E   V A R I A B L E   N A M E S                  *
******************************************************************************)

(******************************************************************************
In the following section we implement a procedure to generate unique names
of variables. This procedure is necessary to transform arbitrary 
formulas in prenex normal form. The basic procedure is implemented
in the MASLOG module. But there is a serious problem to apply this
procedure for the PQ-system. We use distributive polynomials of the
DIP polynomiall system to represent
terms. But duriong the generation of unique names, we must introduce
new variables. The DIP sytsem uses exponent vectors with a positional 
correspondence to the variables. Each exponent vector in each polynomial  
of the formula must have the same length. So you cannot introduce trivially
a new variable. For a solving of this problem we introduce temporary a new
representation of atomic formulas. These representation has the following
form:

	(PQSAF Substitutions AtomicFormula)

PQSAF is a MAS symbol to mark the special form of atomic formulas. 
Substitutions is a list of lists with two atoms. 
Atomic formula is a normal atomic formula of the PQ-system.
Each pair (o,n) of the list Substitutions has the meaning 
move a exponent form position l-o+1 to position l-n+1, where l=LENGTH(VALIS).
The list of substitution must be applied in inverse order of their 
occurence in the list Substitutions.

As variable names, we uses the names from VALIS. 

The procedure works as follows:

1. Declare all variables from VALIS as maslog variables.
2. Call FORMKVD
3. Transform the special representation of the returned formula in standard 
	representation.

We use a global variable NewVariables to count the number of new introduced
variables.
******************************************************************************)

PROCEDURE EnterVariableNames(valis: LIST);
(* enter variable names. valis is a variable list. All names from valis
are entered in the MASLOG symbol table. *)
	VAR var,dummy: LIST;
BEGIN
	WHILE valis<>SIL DO
		ADV(valis,  var,valis);
		dummy:=FORVTENTER(var);
	END;
END EnterVariableNames;
	
PROCEDURE pqlsvars(af: LIST):LIST;
(* polynomial equation list variables. af is a atomic formula. 
All variables used in af is returned as a list of MASLOG variables. *)
	VAR rel, pol, var, result, valis, vv, v: LIST;
BEGIN
	pol:=pqgpol(af);
	IF pol=0 THEN RETURN SIL; END;
	result:=SIL;
	vv:=INV(DIPMVV(pol));	(* valis has the inverted order of ev *)
	valis:=VALIS;
	WHILE vv<>SIL DO
		ADV(vv,  v,vv);
		ADV(valis,  var,valis);
		IF v=1 THEN
			result:=COMP(FORMKVAR(FORVTENTER(var),ANY),result);
		END;
	END;
	RETURN result;
END pqlsvars;

PROCEDURE PqsafSubstvar(af,old,new:LIST):LIST;
(* polynomial equation special atomic formula substitute variable. 
phi is an atomic formula. 
old and new are variables. The variable old is substituted with new in af. 
VALIS is modified!!!! *)
	VAR oIndex, nIndex,name,type,n: LIST;
BEGIN
	FORPVAR(old,  name,type);
	oIndex:=LSRCHQ(FORVTGET(name),VALIS);
	FORPVAR(new,  name,type);
	nIndex:=LSRCHQ(FORVTGET(name),VALIS);
	IF nIndex=0 THEN 
		NewVariables:=NewVariables+1;
		VALIS:=SUFFIX(VALIS,FORVTGET(name));
		nIndex:=LENGTH(VALIS);
	END;
	IF FORGOP(af)<>PQSAF THEN
		RETURN LIST3(PQSAF,LIST1(LIST2(oIndex,nIndex)),af);
	ELSE
		RETURN LIST3(PQSAF,COMP(LIST2(oIndex,nIndex),SECOND(af)),
			THIRD(af));
	END;
END PqsafSubstvar;

PROCEDURE PqsafNormalizeAf(af:LIST):LIST;
(* polynomial equation special atomic formula normalize atomic formula. 
af is atomic formula is special representation. The normalized representation
is returned. *)
	VAR op, pol, rel, subst,s, o,n,i,length,perm :LIST;
BEGIN
(* *)	(* Initialization *)
	op:=FORGOP(af);
	IF (op=VERUM) OR (op=FALSUM) THEN RETURN af; END;
	IF (op<>PQSAF) AND (NewVariables=0) THEN RETURN af; END;
	IF op=PQSAF THEN
		pqpaf(THIRD(af),  rel,pol);
		subst:=SECOND(af);
	ELSE
		pqpaf(af,  rel,pol);
		subst:=SIL;
	END;
(* *)	(* introduce new variables *)
	length:=LENGTH(VALIS);
	IF NewVariables>0 THEN
		pol:=DIPINV(pol,length-NewVariables+1,NewVariables);
	END;
(* *)	(* generate permutation vector from substitution list *)	
	perm:=SIL;
	FOR i:=length TO 1 BY -1 DO
		perm:=COMP(i,perm);
	END;
	WHILE subst<>SIL DO
		ADV(subst,  s,subst);
		FIRST2(s,  o,n);
		SLELT(perm,n,o);
		SLELT(perm,o,n);
	END;
(* *)	(* permute polynomial *)
	pol:=DIPERM(pol,perm);
	RETURN pqmkaf(rel,pol);
END PqsafNormalizeAf;

	
PROCEDURE PQMKVD(phi:LIST): LIST;
(* polynomial equation make variable names disjoint. *)
	VAR psi: LIST;
BEGIN
	NewVariables:=0;
	EnterVariableNames(VALIS);
	psi:=FORMKVD(phi,PqsafSubstvar,pqlsvars);
	psi:=FORAPPLYAT(psi,PqsafNormalizeAf);
	RETURN psi;
END PQMKVD;


PROCEDURE vlistflvar(lvar:LIST):LIST;
(* variable list from lvar. lvar is a LVAR object. A variable list in the 
format of the module DIPC representing the same list of 
variables is returned. *)
	VAR result, var, name,sort: LIST;
BEGIN
	lvar:=FORGLVAR(lvar);
	result:=SIL;
	WHILE lvar<>SIL DO
		ADV(lvar,  var,lvar);
		FORPVAR(var,name,sort);
		result:=COMP(FORVTGET(name),result);
	END;
	RETURN INV(result);
END vlistflvar;

PROCEDURE lvarfvlist(vlist:LIST):LIST;
(* lvar from variable list. vlist is a variable list in the format of the 
DIPC-module. A LVAR object representing the same variable list is returned. *)
	VAR result,v: LIST;
BEGIN
	result:=SIL;
	WHILE vlist<>SIL DO
		ADV(vlist,  v,vlist);
		result:=COMP(FORMKVAR(FORVTENTER(v),ANY),result);
	END;
	RETURN FORMKLVAR(INV(result));
END lvarfvlist;

(******************************************************************************
*                       M A S L O G   I N T E R F A C E                       *
******************************************************************************)

PROCEDURE PQMKDNF(phi:LIST):LIST;
(* polynomial equation make disjunctive normal form. phi is a formula;
MLMKDNF returns a formula in strict disjunctive normal form which is
equivalent to phi.  *)
BEGIN
	RETURN FORMKDNF(phi,pqnegaf);
END PQMKDNF;

PROCEDURE PQMKCNF(phi:LIST):LIST;
(* polynomial equation make disjunctive normal form. phi is a formula;
a formula in strict conjunctive normal form which is
equivalent to phi is returned. *)
BEGIN
	RETURN FORMKCNF(phi,pqnegaf);
END PQMKCNF;

PROCEDURE PQSMPL(phi:LIST):LIST;
(* polynomial equation simplify. phi is a formula; a simplification on
phi is returned. *)
BEGIN
	RETURN FORSMPL(phi,pqsimplifyaf,pqnegaf);
END PQSMPL;

PROCEDURE PQSIMPLIFY(phi:LIST):LIST;
(* polynomial equation simplify. phi is a formula. A simplification of 
phi is returned. Following simplification steps are done:
1. VERUM and FALSUM are eliminated 
2. assoziative simplification
3. idempotenz
*)
BEGIN
	RETURN FORSIMPLIFY(phi,pqsmart,pqsimplifyaf,pqnegaf);
END PQSIMPLIFY;

PROCEDURE PQSIMPLIFYP(phi,maxlevel:LIST):LIST;
(* polynomial equation simplify. phi is a formula. A simplification of 
phi is returned. Following simplification steps are done:
1. VERUM and FALSUM are eliminated 
2. assoziative simplification
3. idempotenz
maxlevel is the number of levels that are simplified. 
*)
BEGIN
	RETURN FORSIMPLIFYP(phi,maxlevel,pqsmart,pqsimplifyaf,pqnegaf);
END PQSIMPLIFYP;

PROCEDURE PQMKPOS(phi: LIST): LIST;
(* polynomial equation make positive. phi is a formula; a equivalent positive 
formula is returned. *)
BEGIN
	RETURN FORMKPOS(phi,ET,pqnegaf);
END PQMKPOS;

PROCEDURE PQPPRT(phi:LIST);
(* polynomial equation pretty print. phi is a formula; this procedure writes
the formula phi formatted in the output stream. *)
BEGIN
	FORPPRT(phi,pqprtaf);
END PQPPRT;

PROCEDURE PQTEXW(phi: LIST);
(* polynomial equation tex write. The formula phi is printed in tex format in
the output stream. *)
BEGIN
	FORTEXW(phi,pqtexwaf);
END PQTEXW;

PROCEDURE PQPREAD():LIST;
(* polynomial equation read. *)
BEGIN
	RETURN FORPREAD(pqreadaf);
END PQPREAD;

PROCEDURE PQIREAD():LIST;
(* polynomial equation infix read. *)
	VAR c: GAMMAINT;
	VAR keyword, value: LIST;
BEGIN
	c:=CREADB();
	IF c <> MASORD("{") THEN
		BKSP();
	ELSE
		REPEAT
			keyword:=SREAD1();
			c:=CREADB();
			IF c<>MASORD("=") THEN
				DIBUFF();
				ERROR(severe,"PQIREAD: = expected");
			END;
			IF EQUAL(keyword,LISTS("DOMAIN"))=1 THEN
				DOMAIN:=ADDDREAD();
			ELSIF EQUAL(keyword,LISTS("VALIS"))=1 THEN
				VALIS:=VLREAD();
			ELSIF EQUAL(keyword,LISTS("EVORD"))=1 THEN
				EVORD:=UREAD();
			END;
			c:=CREADB();
			IF (c<>MASORD(",")) AND (c<>MASORD("}")) THEN
				DIBUFF();
				ERROR(severe,"PQIREAD: , or = expected");
			END;
		UNTIL c=MASORD("}"); 
BLINES(1);
SWRITE("DOMAIN: ");ADDDWRIT(DOMAIN);BLINES(0);
SWRITE("VALIS:  ");VLWRIT(VALIS);BLINES(0);
SWRITE("EVORD:  ");UWRITE(EVORD);BLINES(1);
	END;
	RETURN FORIREAD(pqreadaf);
END PQIREAD;

PROCEDURE PQELIMXOPS(phi: LIST):LIST;
(* polynomial equation  eliminate extended operation symbols. phi is 
formula, pref is a
symbol of the set \{VEL, ET, NON\}; FORELIMXOPS returns a formula phi1
equivalent to phi. If pref is NON then this function does nothing. Otherwise
this function replaces all subterms of phi with the operators IMP, REP, EQUIV
or XOR with terms with the operators VEL, ET and NON. There are two different
substitutions for EQUIV and XOR. If pref=ET (pref=VEL) then the outermost
operator of the replacement terms for EQUIV, XOR is ET (VEL). *)
BEGIN
	RETURN FORELIMXOPS(phi,ET); (* -- to do -- set preference *)
END PQELIMXOPS;

PROCEDURE PQELIMXOPS1(phi,pref: LIST):LIST;
(* polynomial equation  eliminate extended operation symbols. phi is 
formula, pref is a
symbol of the set \{VEL, ET, NON\}; FORELIMXOPS returns a formula phi1
equivalent to phi. If pref is NON then this function does nothing. Otherwise
this function replaces all subterms of phi with the operators IMP, REP, EQUIV
or XOR with terms with the operators VEL, ET and NON. There are two different
substitutions for EQUIV and XOR. If pref=ET (pref=VEL) then the outermost
operator of the replacement terms for EQUIV, XOR is ET (VEL). *)
BEGIN
	RETURN FORELIMXOPS(phi,pref); (* -- to do -- set preference *)
END PQELIMXOPS1;

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
BEGIN
	RETURN FORMKPRENEX(phi,pref);
END PQMKPRENEX;

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
	VAR old: LIST;
BEGIN
	old:=LIST3(DOMAIN,VALIS,EVORD);
	IF R<>SIL THEN 
		IF FIRST(R)<>-1 THEN ADV(R,DOMAIN,R); ELSE R:=RED(R); END;
	END;
	IF R<>SIL THEN 
		IF FIRST(R)<>-1 THEN ADV(R,VALIS,R); ELSE R:=RED(R); END;
	END;
	IF R<>SIL THEN 
		IF FIRST(R)<>-1 THEN ADV(R,EVORD,R); ELSE R:=RED(R); END;
	END;
	RETURN old;
END PQPRING;

PROCEDURE PQPRINGWR();
(* polynomial equation polynomial ring write. The description of the polynomial
ring is written in the output stream. *)
	VAR variable,varlist: LIST;
BEGIN
	BLINES(1);
	SWRITE("Specification of the polynomial ring:");
	BLINES(0);
	SWRITE("  The domain: "); ADDDWRIT(DOMAIN);BLINES(0);
	IF VALIS=SIL THEN 
		SWRITE("No list of variables specified!"); 
	ELSE
		SWRITE("  The list of variables: "); 
		VLWRIT(VALIS);
	END;
	BLINES(0);
	SWRITE("  The term order of the polynomial ring: ");
	IF EVORD>SIL THEN
		SWRITE("user defined term order:");
		UWRIT1(EVORD);
	ELSE
		CASE INTEGER(EVORD) OF
		LEX:		SWRITE("LEX");		|
		INVLEX:		SWRITE("INVLEX");	|
		GRLEX:		SWRITE("GRLEX");	|
		IGRLEX:		SWRITE("IGRLEX");	|
		REVLEX:		SWRITE("REVLEX");	|
		REVILEX:	SWRITE("REVILEX");	|
		REVTDEG:	SWRITE("REVTDEG");	|
		REVITDG:	SWRITE("REVITDG");
		ELSE 		SWRITE("WARNING: unknown term order indicator.");
		END;
	END;
	BLINES(1);
END PQPRINGWR;
	
(******************************************************************************
*                                   M A I N                                   *
******************************************************************************)

BEGIN
	(* *** symbols for bb-formulas *** *)
	Declare(EQU,"EQU");
	Declare(NEQ,"NEQ");
	Declare(LES,"LES");
	Declare(LSQ,"LSQ");
	Declare(GRQ,"GRQ");
	Declare(GRE,"GRE");
	Declare(PQSAF,"PQSAF");
	(* *** listvar declarations for global variables. *** *)
	LISTVAR(DOMAIN);
	(* *** initialize the bb-formula parser. *** *)
	InitBbfParser();
	(* *** initialize the global variables. ***  *)
	(* DOMAIN:=LIST3(DOMRND,0,-1);	(* RN -1 *) *)
	(* last line does not work. It is executed before domain RN loaded *)
	DOMAIN:=LIST3(8,0,-1);	(* RN -1 *) 
END PQBASE.

(* -EOF- *)
