(* ----------------------------------------------------------------------------
 * $Id: TFORM.mi,v 1.1 1994/11/28 21:10:08 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1994 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: TFORM.mi,v $
 * Revision 1.1  1994/11/28  21:10:08  dolzmann
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

IMPLEMENTATION MODULE TFORM;
(* Type Formula Implementation Module. *)

(******************************************************************************
*                   S E P E R A T I O N   F O R M U L A E                     *
*-----------------------------------------------------------------------------*
* Author:   Andreas Dolzmann                                                  *
* Language: Modula II                                                         *
* System:   This program is written for the computer algebra system MAS by    *
*           Heinz Kredel.                                                     *
* Abstract: A program for the determination of type formulas.                 *
******************************************************************************)

FROM MASBIOS	IMPORT	BKSP, BLINES, CREAD, CREADB, CWRITE, DIBUFF, DIGIT,
			LETTER, LISTS, MASORD, SWRITE;
FROM MASBIOSU	IMPORT	CLTIS, INP, OUT, SHUT;
FROM MASELEM	IMPORT	GAMMAINT, MASEVEN;
FROM MASERR	IMPORT	ERROR, confusion, fatal, harmless, severe, spotless;
FROM MASLISPU	IMPORT	Declare, PROCF1, PROCF2;
FROM MASLOG	IMPORT	FORAPPLYAT, FORAPPLYATF2, FORCOUNTAF, FORELIMXOPS,
			FORMKCNF, FORMKDNF, FORMKPOS, FORMKPRENEX,
			FORMKPRENEX1, FORREPAFS, FORSIMPLIFY, FORSMPL;
FROM MASSET	IMPORT	SetUnion;
FROM MASSTOR	IMPORT	ADV, COMP, FIRST, INV, LENGTH, LIST, LIST1, LISTVAR,
			RED, SFIRST, SIL, SRED;
FROM MASSYM	IMPORT	ATOM, MEMQ;
FROM MASSYM2	IMPORT	ASSOC, ASSOCQ, EXPLOD, SREAD1, SYMBOL, UREAD, UWRIT1,
			UWRITE;
FROM MLOGBASE	IMPORT	EQUIV, ET, EXIST, FALSUM, FORALL, FORGARGS, FORGOP,
			FORMKBINOP, FORMKFOR, FORMKQUANT, FORMKUNOP,
			FORPARGS, FORPBINOP, FORPBINOPA, FORPFOR, FORPQUANT,
			FORPQUANTA, FORPUNOP, FORPUNOPA, IMP, NON, REP, TVAR,
			VEL, VERUM, XOR;
FROM MLOGIO	IMPORT	FORIREAD, FORPPRT, FORPREAD, FORTEXW, KEYREAD;
FROM LISTTOOLS	IMPORT	CLISTFA, LSRCHQ, UPCASE; 
FROM PQBASE	IMPORT	EQU, GRE, GRQ, LES, LSQ, NEQ, PQCRELAND, PQCRELOR,
			PQSIMPLIFY, PQSIMPLIFYP, pqgpol, pqgrel, pqmkaf,
			pqpaf;
FROM SACLIST	IMPORT	ADV2, ADV3, ADV4, AREAD, AWRITE, CCONC, CINV, CLOUT,
			COMP2, CONC, EQUAL, FIRST2, LELT, LIST10, LIST2,
			LIST3, LIST4, LIST5, MEMBER, RED2, SECOND, THIRD; 
FROM SACSET	IMPORT	LBIBMS;


CONST rcsidi = "$Id: TFORM.mi,v 1.1 1994/11/28 21:10:08 dolzmann Exp $";
CONST copyrighti = "Copyright (c) 1994 Universitaet Passau";

(******************************************************************************
* Coefficient tuples:                                                         *
* List of a length n representing a univariate polynomial of degree n-1.      *
* The i-th entry in the list is the coefficient of X^(i-1). We consider       *
* coefficients -1,0,1 representing arbitrary coefficients less than, equal    *
* to or greater than 0.                                                       *
* The characteristic coefficient J is represented by 2.                       *
******************************************************************************)

(* ***************************************************************************
Classification.
Let t the coefficient tuple (t_0,...,t_d) and -t:=(t_0,-t_1,...,(-1)^d t_d).
A classification of a characteristic coefficient tuple t without joker entries
is determined by the following rules. 
If tau(t)-tau(-t)=0,  then the classification of t is Good.
If tau(t)-tau(-t)>0,  then the classification of t is Bad.
If tau(t)-tau(-t)<0,  then the classification of t is DontCare.
If tau(t)-tau(-t)<>0, then the classification of t is Impossible.
We represents the classification of tuple with an enumerate type or
with a MAS symbol.
*************************************************************************** *)

(****************************************************************************
Type formulas.

Type formulas are MASLOG objects with the following representation of 
atomic formulas.

Atomic formulas are represented as lists
	(REL,(id_0,id_1,...,id_n)),
where REL is a relation symbol of \{NEQ, EQU, GRE, GRQ, LES LSQ\}, and
id_i is an atom.
Such an object has the following interpretation: 
	id_0*id_1* ... *id_n REL 0.
We think this representation suffices to store optimal type formulas:

Powers of identifiers are not necessary, because you can transform a 
formula id^n REL1 0 into id REL2 0.

Sums are not necessary, because the sign of a sum of two or more
parameters is not defined independently of the specialization of the 
parameters. 

Products are necessary: See the examples of type formulas in the 
documentation!
****************************************************************************)


(******************************************************************************
*                       G L O B A L   V A R I A B L E S                       *
******************************************************************************)

VAR TfGood, TfBad, TfImpossible, TfDontCare: LIST;

VAR BbfParserSyms: LIST;	(* The symbol table for the symbols of atomic
				   formulas. *)

VAR TypeFormulaProc: PROCF1;	(* Holds the procedure used for type formula 
					computation. *) 
					

(******************************************************************************
*                        A T O M I C _ F O R M U L A S                        *
******************************************************************************)

PROCEDURE tfmkaf(rel:LIST;idl:LIST):LIST;
(* type formula make atomic formula.
rel is a relation, idl is a list of atoms, 
the atomic formula (rel,idl) is returned. *)
BEGIN
	RETURN LIST2(rel,idl);
END tfmkaf;

PROCEDURE tfpaf(af:LIST; VAR rel,idl:LIST);
(* type formula parse atomic formula. 
af is an atomic formula; 
the relation symbol of af is in rel returned; 
the list of identifiers is in id returned. *)
BEGIN
	FIRST2(af,rel,idl);
END tfpaf;

PROCEDURE tfgrel(af:LIST):LIST;
(* type formula get relation symbol. af 
is an atomic formula. 
The relation symbol of af is returned. *)
BEGIN
	RETURN FIRST(af);
END tfgrel;

PROCEDURE tfprtaf(af: LIST);
(* type formula print atomic formula. The atomic formula
af is printed.
*)
	VAR rel,idl,id:LIST;
BEGIN
	ADV2(af,rel,idl,af);
	SWRITE("[ (");
	ADV(idl,  id,idl);
	SWRITE("a");
	AWRITE(id);
	WHILE idl<>SIL DO
		SWRITE(" * ");
		ADV(idl,  id,idl);
		SWRITE("a");
		AWRITE(id);
	END;
	SWRITE(")");
	IF	rel=EQU THEN SWRITE(" = 0]");
	ELSIF	rel=NEQ THEN SWRITE(" <> 0]");
	ELSIF	rel=LES THEN SWRITE(" < 0]");
	ELSIF	rel=GRE THEN SWRITE(" > 0]");
	ELSIF	rel=LSQ	THEN SWRITE(" <= 0]");
	ELSIF	rel=GRQ	THEN SWRITE(" >= 0]");
	ELSE 	ERROR(severe,"tfprtaf: unknown relation symbol");
	END;
END tfprtaf ;

PROCEDURE tfraf():LIST;
(* type formula read atomic formula. An atomic formula is read from the 
input stream. The syntax is [(] id { [*] [a]n } [)]. *)
	VAR c: GAMMAINT;
	VAR ExpectOp: BOOLEAN;
	VAR code,cl,ucl,rel,idl,sym,clp: LIST;
BEGIN
	idl:=SIL;
	ExpectOp:=FALSE;
	c:=CREADB();
	IF c<>MASORD("(") THEN BKSP(); END;
	LOOP
		c:=CREADB();
		IF DIGIT(c) THEN
			BKSP(); 
			code:=AREAD();	
			ExpectOp:=TRUE;
			idl:=COMP(code,idl);
		ELSIF c=MASORD("*") THEN
			IF NOT ExpectOp THEN
				DIBUFF();
				ERROR(severe,"tfraf: operator expected.");
			ELSE
				ExpectOp:=FALSE;
			END;
		ELSIF c=MASORD(")") THEN 
			ucl:=KEYREAD();
			sym:=ASSOCQ(ucl,BbfParserSyms);
			IF sym=SIL THEN 
				DIBUFF();
				ERROR(severe,"tfraf: unknown relation symbol.");
			END;
			EXIT;
		ELSE
			BKSP();
			IF LETTER(c) THEN
				cl:=SREAD1();
			ELSE
				cl:=KEYREAD();
			END;
			ucl:=UPCASE(cl);
			sym:=ASSOCQ(ucl,BbfParserSyms);
			IF sym<>SIL THEN EXIT; END; 
			IF FIRST(cl)>9 THEN cl:=RED(cl); END; 
			code:=0;
			WHILE cl<>SIL DO
				ADV(cl,clp,cl);
				code:=code*10+clp;
			END;
			ExpectOp:=TRUE;
			idl:=COMP(code,idl);		
		END;			
	END;
	rel:=FIRST(sym);
	c:=CREADB();	
	IF c<>0 THEN 
		DIBUFF();
		ERROR(severe,"tfraf: 0 expected.");
		IF c=MASORD("]") THEN BKSP(); END; 
	END;
	c:=CREADB(); IF c<>MASORD(")") THEN BKSP(); END;
	RETURN tfmkaf(rel,LBIBMS(idl)); (* to do: delete repeated entries *)
END tfraf;

PROCEDURE InitBbfParser();
(* Initialize black-box formula parser. *)
BEGIN
	BbfParserSyms:=SIL;
	LISTVAR(BbfParserSyms);
	BbfParserSyms:=COMP2( LISTS("<>"),  NEQ, BbfParserSyms);
	BbfParserSyms:=COMP2( LISTS("#"),   NEQ, BbfParserSyms);
	BbfParserSyms:=COMP2( LISTS("!="),  NEQ, BbfParserSyms);
	BbfParserSyms:=COMP2( LISTS("NEQ"), NEQ, BbfParserSyms);
	BbfParserSyms:=COMP2( LISTS("="),   EQU, BbfParserSyms);
	BbfParserSyms:=COMP2( LISTS("EQU"), EQU, BbfParserSyms);
	BbfParserSyms:=COMP2( LISTS(">"),   GRE, BbfParserSyms);
	BbfParserSyms:=COMP2( LISTS("GRE"), GRE, BbfParserSyms);
	BbfParserSyms:=COMP2( LISTS("<"),   LES, BbfParserSyms);
	BbfParserSyms:=COMP2( LISTS("LES"), LES, BbfParserSyms);
	BbfParserSyms:=COMP2( LISTS("<="),  LSQ, BbfParserSyms);
	BbfParserSyms:=COMP2( LISTS("LSQ"), LSQ, BbfParserSyms);
	BbfParserSyms:=COMP2( LISTS("LEQ"), LSQ, BbfParserSyms);
	BbfParserSyms:=COMP2( LISTS(">="),  GRQ, BbfParserSyms);
	BbfParserSyms:=COMP2( LISTS("GRQ"), GRQ, BbfParserSyms);
	BbfParserSyms:=COMP2( LISTS("GEQ"), GRQ, BbfParserSyms);
	RETURN;
END InitBbfParser;


(******************************************************************************
*                       M A S L O G   I N T E R F A C E                       *
******************************************************************************)

PROCEDURE TFPPRT(phi:LIST);
(* type formula pretty print. 
phi is a tf-formula; 
this procedure writes the formula phi formatted in the output stream. *)
BEGIN
	FORPPRT(phi,tfprtaf);
END TFPPRT;

PROCEDURE TFIREAD():LIST;
(* type formula infix read. 
A type formula is read from the input stream. *)
BEGIN
	RETURN FORIREAD(tfraf);
END TFIREAD;


(******************************************************************************
*                     E X T E R N A L   I N T E R F A C E                     *
******************************************************************************)

PROCEDURE TfUseDb();
(* type formula use data base. 
The global variable TypeFormulaProc is set.
Type formulas are computed only if they are not stored in the data base. *)
BEGIN
	TypeFormulaProc:=UseDb;
END TfUseDb;

PROCEDURE TfComputeTf();
(* type formula compute type formulas. 
The global variable TypeFormulaProc is set.
The data base of type formulas is not used. *)
BEGIN
	TypeFormulaProc:=ComputeTypeFormula;
END TfComputeTf;

PROCEDURE TfTypeFormula(deg: LIST):LIST;
(* type formula type formula.
A type formula for polynomials of degree deg > 0 is returned. 
This is the interface for other modules. *)
BEGIN
	RETURN TypeFormulaProc(deg);
END TfTypeFormula;


(******************************************************************************
* E F F I C I E N T   C O M P U T A T I O N   O F   T Y P E   F O R M U L A S *
******************************************************************************)

PROCEDURE ComputeTypeFormula(deg: LIST):LIST;
(* compute type formula. 
deg is an atom > 0.
A type formula for polynomials of degree deg is returned. *)
	VAR result: LIST;
BEGIN
	IF deg <=2 THEN
		result:=TfRecBasis(deg);
	ELSIF (deg <= 6) AND (deg MOD 2 = 0) THEN
		result:=TfTypeFormula(deg-2);
		result:=TfShiftVars(result,2);
		result:=FORMKFOR(ET,LIST3(tfmkaf(EQU,LIST1(0)),
					tfmkaf(EQU,LIST1(1)),
					result));
		result:=FORMKBINOP(VEL,result,TfRecBasis(deg));
	ELSIF deg MOD 2 = 1 THEN
		result:=TfTypeFormula(deg-1);
		result:=TfShiftVars(result,1);
		result:=FORMKBINOP(ET,tfmkaf(EQU,LIST1(0)),result);
	ELSIF deg MOD 2 = 0 THEN
		result:=TfTypeFormula(deg-2);
		result:=TfShiftVars(result,2);
		result:=FORMKFOR(ET,LIST3(tfmkaf(EQU,LIST1(0)),
					tfmkaf(EQU,LIST1(1)),
					result));
		result:=FORMKBINOP(VEL,result,TFGENJ(deg));
	END;
	RETURN result;
END ComputeTypeFormula;

PROCEDURE UseDb(deg: LIST): LIST;
(* Use data base. 
A type formula for polynomials of degree deg > 0 is returned. 
If the type formula is already stored in the data base, this formula
is returned. Otherwise the type formula is computed, stored in the 
data base and returned. 
Type formulas are stored in files with the name TF.d.db, where 
d is the degree of the type formula.  *)
	VAR name, ret,phi: LIST;
BEGIN
	name:=LISTS("TF.");	
	name:=CONC(name,CLISTFA(deg));
	name:=CONC(name,LISTS(".db"));
	ret:=INP(name);
	IF ret<>0 THEN 
		phi:=ComputeTypeFormula(deg);
		ret:=OUT(name);
		TFPPRT(phi);
		SWRITE(".");
		ret:=SHUT(name);
	ELSE
		phi:=TFIREAD();
		ret:=SHUT(name);
	END;
	RETURN phi;
END UseDb;

PROCEDURE TFGENJ(deg: LIST):LIST;
(* type formula generate with joker argument. 
deg is an even atom greater than 1.
computed. The computed formula is returned. 
A strict type formula for polynomials of degree deg is computed.
The joker argument is used in order to reduce the size of the type formula. *)
	VAR R,r,result: LIST;
	VAR last: LIST;
BEGIN
	IF deg MOD 4 = 0 THEN
		last:=tfmkaf(GRE,LIST1(0));
	ELSIF deg MOD 4 = 2 THEN 
		last:=tfmkaf(LES,LIST1(0));
	ELSE
		ERROR(severe,"TFGENJ: degree must be even.");
		RETURN FALSUM;
	END;
	result:=SIL;
	R:=TfCtj(deg);
	WHILE R<>SIL DO 
		ADV(R,r,R);
		result:=COMP(TFFTUPLE(r),result);
	END;
	RETURN FORMKBINOP(ET,last,FORMKFOR(VEL,INV(result)));
END TFGENJ;

PROCEDURE TfRecBasis(deg:LIST):LIST;
(* type formula recursion basis. 
deg is an atom < 6. 
A type formula for polynomials with degree deg is returned. *)
	VAR sp: LIST;
BEGIN
	CASE INTEGER(deg) OF 
	1: CLTIS(LISTS("( [a0 = 0] ) . "));
	   RETURN TFIREAD();						|
	2: CLTIS(LISTS("( [a1 = 0] \/ [a0 < 0] ) . "));
	   RETURN TFIREAD();						|
	4: CLTIS(LISTS("( [ a0 > 0 ] /\ ( [a2 < 0] \/ [a1 a3 < 0] )) . "));
	   RETURN TFIREAD();						|
	6: CLTIS(LISTS("([a0<0]/\((([a2>0]\/[a3 a1<0])/\([a4<0]\/[a5 a3<0]))\/([a5 a1>0]/\[a4 a2<0]))) . "));
	   RETURN TFIREAD(); 
	ELSE
		ERROR(severe,"TfRecBasis: possible values for deg: 1,2,4,6.");
		RETURN FALSUM; (* only a dummy *)
	END;
END TfRecBasis;
	
PROCEDURE TfCtj(deg: LIST):LIST;
(* type formula coefficient tuples with joker argument.
deg is an even atom.
All good coefficients tuples with of polynomials of degree deg are computed.
*)
BEGIN
	IF deg MOD 2 = 1 THEN 
		ERROR(severe,"TfCtj: deg must be even.");
		RETURN SIL;
	END;
	IF deg MOD 4 = 2 THEN 
		RETURN TfCtj1(deg,LIST1(1),-1,LIST2(-1,1),1,0,0);
	ELSE
		RETURN TfCtj1(deg,LIST1(1),1,LIST2(-1,1),1,0,0);
	END;
END TfCtj;
		
PROCEDURE TfCtj1(deg, end, c0, ci,length, zp, zm: LIST):LIST;
(* type formula coefficient tuples with joker argument one.
Auxiliary procedure for TfCtj1.
deg is the degree of the characteristic polynomial.
end is the end of a coefficient tuple.
c0 is the first element of all coefficient tuples.
ci is a list of possible elements for the next position. 
length is the length of end.
zp is the number of sign changes of end.
zm is the number of sign chances of -(end). 
A list of coefficient tuples is returned. *)
	VAR result,first,c,l: LIST;
BEGIN
	l:= deg DIV 2;
	IF (zm > l) OR (zp > l) THEN
		RETURN SIL;
	END;
	first:=FIRST(end);
	IF length=deg+1 THEN 
		(* end is the hole tuple. return if classification=good. *)
		IF (zp+zm=deg) AND (zp=zm) THEN 
			RETURN LIST1(end);
		ELSE
			RETURN SIL;
		END;
	ELSIF length=deg THEN
		(* only one position is left. fix this position with c0 *)
		IF c0*first=-1 THEN zp:=zp+1; ELSE zm:=zm+1 END;
		RETURN TfCtj1(deg,COMP(c0,end),c0,SIL,length+1,zp,zm);
		(* to do. this recursive call is not necessary. *)
	ELSIF length=deg-1 THEN
		(* two position are unspecified, but the last position is 
		fixed by c0. *)
		IF c0*first=-1 THEN 
			(* The preultimate position is a joker, so 
			fix the last two positions. *)
			RETURN TfCtj1(deg,COMP2(c0,2,end),c0,SIL,length+2,
					zp+1,zm+1);
			(* to do. this recursive call is not necessary. *)
		ELSE
			(* the preultimate position is not a joker, 
			so generate all possibilities. *)
			result:=SIL;
			WHILE ci<>SIL DO 
				ADV(ci,c,ci);
				IF first*c=-1 THEN
					result:=CONC(result,TfCtj1(deg,
					COMP(c,end),c0,SIL,length+1,zp+1,zm));
				ELSE	
					result:=CONC(result,TfCtj1(deg,
					COMP(c,end),c0,SIL,length+1,zp,zm+1));
				END;
			END;
			RETURN result;
		END;
	ELSE (* general case *)
		(* generate a joker on the actual position *)
		result:=TfCtj1(deg,COMP2(-first,2,end),c0,LIST2(-1,1),
			length+2,zp+1,zm+1);
		(* generate all possibilities without joker *)
		WHILE ci<>SIL DO 
			ADV(ci,c,ci);
			IF first*c=-1 THEN
				result:=CONC(result,TfCtj1(deg,
				COMP(c,end),c0,LIST1(first),length+1,zp+1,zm));
			ELSE	
				result:=CONC(result,TfCtj1(deg,
				COMP(c,end),c0,LIST1(first),length+1,zp,zm+1));
			END;
		END;
		RETURN result;
	END;
END TfCtj1;


(******************************************************************************
*                            M I S C E L L A N E A                            *
******************************************************************************)

PROCEDURE TFFTUPLE(tup:LIST):LIST;
(* type formula from coefficient tuple with joker entries.
tup is a coefficient tuple.
A formula in tf-format is returned. The formula is true, iff
the instantiation of the variables suffice the relation conditions of
the characteristic coefficients of tup. *)
	VAR c,i,result: LIST;	
BEGIN
	IF tup=SIL THEN RETURN FALSUM; END;	(* dummy *)
	i:=1;
	result:=SIL;
	ADV(tup,  c,tup); (* ignore the lowest coefficient *)
	WHILE RED(tup)<>SIL DO	(* ignore the highest coefficient *)
		ADV(tup,c,tup);
		CASE INTEGER(c) OF 
		-1:	result:=COMP(tfmkaf(LES,LIST1(i)),result); |
		 0:	result:=COMP(tfmkaf(EQU,LIST1(i)),result); |
		 1:	result:=COMP(tfmkaf(GRE,LIST1(i)),result); |
 		 2: 	
		END;
		i:=i+1;
	END;
	IF result=SIL THEN RETURN VERUM; END; (* dummy *)
	RETURN FORMKFOR(ET,INV(result));
END TFFTUPLE;

PROCEDURE TfShiftVars(phi,offset: LIST):LIST;
(* type formula shift variables. 
phi is a type formula,
offset is an atom. 
All identifiers are shifted at offset positions to the right. *)
BEGIN
	RETURN FORAPPLYATF2(phi,offset,tfshiftaf);
END TfShiftVars;

PROCEDURE tfshiftaf(phi,offset:LIST):LIST;
(* type formula shift atomic formula. phi
is an atomic formula, offset is an atom. all identifiers in phi are shifted. *)
	VAR rel,idl,id,result: LIST;
BEGIN
	tfpaf(phi,  rel,idl);
	result:=SIL;
	WHILE idl<>SIL DO
		ADV(idl,  id,idl);
		result:=COMP(id+offset,result);
	END;
	RETURN tfmkaf(rel,INV(result));
END tfshiftaf;
				
(******************************************************************************
*                         C L A S S I F I C A T I O N                         *
******************************************************************************)

PROCEDURE Class2Sym(class: TfClass):LIST;
(* classification to symbol. class is a constant of type class.
The corresponding mas symbol is returned. *)
BEGIN
	IF class=Tfgood 		THEN RETURN TfGood;
	ELSIF class=Tfbad		THEN RETURN TfBad;
	ELSIF class=Tfdontcare		THEN RETURN TfDontCare;
	ELSIF class=Tfimpossible	THEN RETURN TfImpossible;
	ELSE ERROR(severe,"Class2Sym: Unknown Classification:");
	END;
END Class2Sym;

PROCEDURE Sym2Class(class: LIST):TfClass;
(* symbol to classification. 
class is a mas-symbol the corresponding classification is returned. *)
BEGIN
	IF class=TfGood 		THEN RETURN Tfgood;
	ELSIF class=TfBad		THEN RETURN Tfbad;
	ELSIF class=TfDontCare		THEN RETURN Tfdontcare;
	ELSIF class=TfImpossible	THEN RETURN Tfimpossible;
	ELSE ERROR(severe,"Sym2Class: Unknown Classification:");
	END;
END Sym2Class;

PROCEDURE InitClassSyms();
(* Initialize classification symbols. 
The mas symbols representing classification constants are initialized. *)
BEGIN
	Declare(TfGood,"TfGood");
	Declare(TfBad,"TfBad");
	Declare(TfImpossible,"TfImpossible");
	Declare(TfDontCare,"TfDontCare");
END InitClassSyms;

PROCEDURE TfClassify(tup:LIST):TfClass;
(* type formula classify coefficient tuple.
tup is a coefficient tuple. The classification of tup is returned.
Let f the polynomial which is represented by tup.
If tau(f)=0, then Tfgood is returned,
if tau(f)<0, then Tfdontcare is returned,
if tau(f)>0, then Tfbad is returned.
Is the sum of the upper bounds of the real zeroes do not equal the
degree of f, then TfImpossible is returned. *)
   	VAR type, CZeroes, ZeroesM, Zeroes0, ZeroesP: LIST;
BEGIN
	TfZeroes(tup,   CZeroes, ZeroesM, Zeroes0, ZeroesP);
	IF CZeroes=SIL THEN RETURN Tfimpossible; END;
	IF ZeroesM+Zeroes0+ZeroesP<>CZeroes THEN RETURN Tfimpossible; END;
	type:=ZeroesP-ZeroesM;
	IF type>0 THEN
		RETURN Tfbad;
	ELSIF type=0 THEN
		RETURN Tfgood;
	ELSE (* IF type<0 THEN *)
		RETURN Tfdontcare;
	END;
END TfClassify;

PROCEDURE TfClassifyI(tup:LIST):LIST;
(* type formula classify coefficient tuple interpreter version.
tup is a coefficient tuple. The classification of tup is returned.
Let f the polynomial which is represented by tup.
If tau(f)=0, then TfGood is returned,
if tau(f)<0, then TfDontCare is returned,
if tau(f)>0, then TfBad is returned.
Is the sum of the upper bounds of the real zeroes not equal to the
degree of f, them TfImpossible is returned. 
The classification is returned as an symbol, representing the classification.*)
BEGIN
	RETURN Class2Sym(TfClassify(tup));
END TfClassifyI;


(******************************************************************************
*                    T H E   N A I V E   A L G O R I T H M                    *
******************************************************************************)

PROCEDURE TFGENI(deg: LIST; class: LIST): LIST;
(* TFGEN interpreter version. Like TFGEN but the classification
parameter is a MAS symbol. *)
BEGIN
	RETURN TFGEN(deg,Sym2Class(class));
END TFGENI;

PROCEDURE TFGEN(deg: LIST; class: TfClass): LIST;
(* type formula generate. 
deg is an atom > 1.
A tf-formula is returned. This formula is true, iff 
a tuple t with t_0<>0 has the classification class. *)
	VAR pattern, tup, res: LIST;
	VAR c: TfClass;
BEGIN
	PatternAStart(deg,  tup, pattern);
	res:=SIL;
	REPEAT
		c:=TfClassify(tup);
		IF c=class THEN 
			res:=COMP(TFFTUPLE(tup),res);
		END;
		tup:=TfNextTuple(tup,pattern);
	UNTIL tup=SIL;
	RETURN FORMKFOR(VEL,INV(res));
END TFGEN;

PROCEDURE PatternAStart(deg:LIST; VAR start, pattern:LIST);
(* pattern and start. A pattern and a start value for the computation of
characteristic coefficient tuples is computed. Let (c_0,...,c_deg)
the start value and (p_0,...,p_deg) the pattern. Then the following holds.
If d MOD 4 = 0, then c_0=1 p_0=0. 
If d MOD 4 = 1, then c_0=0 and c_1=1 and p_0=p_1=0.
If d MOD 4 = 2, then c_0=-1 and p_0=0.
If d MOD 4 = 3, then c_0=0 and c_1 = -1 and p_0=p_1=0.
c_deg=1.
*)
	VAR i: LIST;
BEGIN
	IF deg<=0 THEN 
		start:=SIL;
		pattern:=SIL;
		RETURN; 
	END;
	start:=LIST1(1);
	pattern:=LIST1(0);
	FOR i:=1 TO deg-2 DO
		start:=COMP(-1,start);
		pattern:=COMP(1,pattern);
	END;
	CASE INTEGER(deg) MOD 4 OF
	0:	start:=COMP2(1,-1,start);
		pattern:=COMP2(0,1,pattern); 	|
	1:	start:=COMP2(0,1,start);
		pattern:=COMP2(0,0,pattern); 	|
	2:	start:=COMP2(-1,-1,start);
		pattern:=COMP2(0,1,pattern); 	|
	3:	start:=COMP2(0,-1,start);
		pattern:=COMP2(0,0,pattern); 	
	END; 
	RETURN;
END PatternAStart;

PROCEDURE TfNextTuple(last,pattern:LIST):LIST;
(* type formula next tuple. 
last is a list with n elements of the set \{0,-1,1\}. 
pattern is a list with n elements of the set \{0,1\}.
The lexicographic tuple which differs only an those positions that are
1 in list pattern is returned. The constant SIL is returned, if no
lexicographic tuple greater last exists. The result is generated
non-constructive from last. *)
	VAR lp, lpp, rel, modflag: LIST;
BEGIN
	IF last=SIL THEN RETURN SIL; END;
	lp:=last;
	REPEAT
		ADV(lp,rel,lpp);
		ADV(pattern,modflag,pattern);
		IF modflag=1 THEN
			SFIRST(lp,NextRel(rel));
		END;
		lp:=lpp;
	UNTIL (lp=SIL) OR ((rel<>1) AND (modflag=1)) ;
	IF (lp=SIL) AND ((rel=1) OR (modflag=0)) THEN
		RETURN SIL;
	ELSE
		RETURN  last;
	END;
END TfNextTuple;

PROCEDURE NextRel(e: LIST):LIST;
(* next relation. 
e is an code for a relation. 
The code of the next relation (in order <, =, > ) is returned. *)
BEGIN
	CASE INTEGER(e) OF
	-1 : RETURN 0;	|
	 0 : RETURN 1;	|
	 1 : RETURN -1;
	 ELSE
	 	ERROR(severe,"NextRel: unknown relation");
	 END;
END NextRel;

PROCEDURE TfCount(deg: LIST):LIST;
(* type formula count. 
deg is an atom.
Some characteristic coefficient tuples (c_0,...,c_d) in {-1,0,1}^(d+1) 
are generated. The following holds.
If d MOD 4 = 0, then c_0=1.
If d MOD 4 = 1, then c_0=0 and c_1=1.
If d MOD 4 = 2, then c_0=-1 
If d MOD 4 = 3, then c_0=0 and c_1 = -1.
c_deg=1.
A list (Good,Bad,DontCare,Impossible) is returned. 
Each element is the number  of coefficient tuples with the corresponding
classification.
*)
	VAR start, pattern: LIST;
BEGIN
	PatternAStart(deg,  start,pattern);
	RETURN TfCount1(start,pattern);
END TfCount;

PROCEDURE TfCount1(start, pattern: LIST):LIST;
(* type formula count 1. 
start is a list (s_0,...s_d) with elements of the set \{-1,0,1\}, 
pattern is a list (p_0,...,p_d) with elements of \{0,1\}.
The set T := { t in {-1,0,1}^{d+1} | t >= s , t_i=s_i, if p_i=0 }
is computed. 
A list (Good,Bad,DontCare,Impossible) is returned. 
Each element is the number of coefficient tuples with the corresponding
classification. *) 
	VAR c: TfClass;
	VAR table: ARRAY TfClass OF LIST;
	VAR res, tup: LIST;
BEGIN
	tup:=start;
	FOR c:=Tfgood TO Tfimpossible DO
		table[c]:=0;
	END;
	REPEAT
		c:=TfClassify(tup);
		table[c]:=table[c]+1;
		tup:=TfNextTuple(tup,pattern);
	UNTIL tup=SIL;
	res:=SIL;
	FOR c:=Tfimpossible TO Tfgood BY -1 DO
		res:=COMP(table[c],res);
	END;
(*9*)	RETURN res;
END TfCount1;


(******************************************************************************
*                D E S C A R T E S   R U L E   O F   S I G N S                *
******************************************************************************)

PROCEDURE TfZeroes0(tup: LIST):LIST;
(* type formula zeroes 0. 
The numbers of the leading zeroes is returned. 
This is the number of zeroes at the origin of the polynomial SUM tup_i X^i.
For the tuple tup containing only zeroes and for the empty tuple 
the constant SIL is returned. *)
	VAR result,c: LIST;
BEGIN
	IF tup=SIL THEN RETURN 0; END;
	result:=0;
	REPEAT
		ADV(tup,c,tup);
		IF c<>0 THEN
			RETURN result;
		ELSE
			result:=result+1;
		END;
	UNTIL tup=SIL;
	RETURN SIL;
END TfZeroes0;

PROCEDURE TfZeroes(tup: LIST; VAR CZeroes, ZeroesM, Zeroes0, ZeroesP: LIST);
(* type formula zeroes. tup is a coefficient tuple of a univariate 
polynomial f. A upper bound of the real zeroes of f, which are
greater than zero (less than zero) is returned in ZeroesP (ZeroeseM).
The number of zeroes at the origin are returned in Zeroes0. If f has only
real zeroes then the numbers of zeroes are exactly. The computation
of the numbers are done using Descartes rule of signs. The number of
all complex zeroes (=deg(f)=length(tup)-1) is returned in CZeroes.
If tup is a list containing only zeroes, then CZeroes is SIL, and all other
variables are undefined. *)
	VAR even, lzero: BOOLEAN;
	VAR lastp, lastm, cp, cm: LIST;
BEGIN
	even:=FALSE;
	lzero:=TRUE;
	Zeroes0:=0; ZeroesM:=0; ZeroesP:=0; CZeroes:=0;
	IF tup=SIL THEN RETURN; END;
	ADV(tup,lastp,tup);
	lastm:=lastp;
	IF lastp=0 THEN
		Zeroes0:=1;
	ELSE
		lzero:=FALSE;
	END;
	WHILE tup<>SIL DO
		ADV(tup,cp,tup);
		CZeroes:=CZeroes+1;
		IF even THEN cm:=cp; ELSE cm:=-cp; END;
		IF (cp=0) AND lzero THEN
			Zeroes0:=Zeroes0+1;
		ELSIF cp<>0 THEN
			lzero:=FALSE;
			IF lastp+cp=0 THEN
				ZeroesP:=ZeroesP+1;
			END;
			IF lastm+cm=0 THEN
				ZeroesM:=ZeroesM+1;
			END;
			lastp:=cp; lastm:=cm;
		END;
		even:=NOT(even);
	END;
	IF lzero THEN CZeroes:=SIL; END;
END TfZeroes;

PROCEDURE TfZeroesI(tup: LIST):LIST;
(* TfZeroes interpreter version.
This procedure returns the 4 variable parameters of the procedure
TfZeroes as a list containing 4 elements. *)
	VAR c,m,z,p: LIST;
BEGIN
	TfZeroes(tup,  c,m,z,p);
	RETURN LIST4(c,m,z,p);
END TfZeroesI;

PROCEDURE TfSignChs(tup: LIST): LIST;
(* type formula sign changes. 
tup is a list with elements of the set \{-1,0,1\}. 
The number of sign changes of tup is returned. *)
	VAR last, coeff, result: LIST;
BEGIN
	IF tup=SIL THEN RETURN 0; END;
	result:=0;
	ADV(tup,last,tup);
	WHILE tup<>SIL DO
		ADV(tup,coeff,tup);
		IF coeff<>0 THEN
			IF (coeff+last)=0 THEN
				result:=result+1;
			END;
			last:=coeff;
		END;
	END;
	RETURN result;
END TfSignChs;


(******************************************************************************
*                                   M A I N                                   *
******************************************************************************)

BEGIN
	InitClassSyms();
	InitBbfParser();
	TypeFormulaProc:=ComputeTypeFormula;
END TFORM.

(* -EOF- *)
