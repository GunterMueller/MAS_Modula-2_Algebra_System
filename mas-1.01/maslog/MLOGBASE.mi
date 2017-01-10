(* ----------------------------------------------------------------------------
 * $Id: MLOGBASE.mi,v 1.3 1994/11/28 21:04:13 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: MLOGBASE.mi,v $
 * Revision 1.3  1994/11/28  21:04:13  dolzmann
 * New revision of the MASLOG system: New functions and bug fixes of old one.
 *
 * Revision 1.2  1993/12/20  19:56:03  dolzmann
 * Printable names for the operator symbols are changed.
 *
 * Revision 1.1  1993/12/17  17:12:13  dolzmann
 * MASLOG is divided into three parts. (MLOGBASE, MLOGIO, MASLOG)
 * Additional input procedures are added.
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MLOGBASE;
(* Maslog Base Implementation Module. *)

(******************************************************************************
*			       M L O G B A S E				      *
*-----------------------------------------------------------------------------*
* Author:   Andreas Dolzmann                                                  *
* Language: MODULA II (mocka or mtc are possible.)                            *
* System:   Program for the computer algebra system MAS by Heinz Kredel.      *
* Project:  MASLOG
* Remark:   Libraries maskern, maslisp are used.                              *
* Abstract: A package for the MAS computer algebra system by Heinz Kredel.    *
*           This package implements basic routins on formulas of the first    *
*           order predicate calculus.                                         *
******************************************************************************)

FROM MASBIOS	IMPORT	LISTS;
FROM MASSTOR	IMPORT	ADV, COMP, FIRST, LIST, LIST1, LISTVAR, RED, SIL; 
FROM MASLISPU	IMPORT	Declare;
FROM MASSYM	IMPORT	ATOM;
FROM MASSYM2	IMPORT	ASSOC, ASSOCQ, SYMBOL; 
FROM SACLIST	IMPORT	ADV2, ADV3, COMP2, LIST2, LIST3, SECOND;

CONST rcsidi = "$Id: MLOGBASE.mi,v 1.3 1994/11/28 21:04:13 dolzmann Exp $";
CONST copyrighti = "Copyright (c) 1993 Universitaet Passau";

(******************************************************************************
*                       G L O B A L   V A R I A B L E S                       *
******************************************************************************)

VAR VARTAB: LIST;	(* Symbol table for all identifier of variables. *)

(******************************************************************************
*			 B A S I C   R O U T I N E S                          *
******************************************************************************)


PROCEDURE FORGOP(phi: LIST): LIST;
(* formula get operation. phi is a formula; the operation keyword of the
formula phi is returned.*)
BEGIN
	IF phi=SIL THEN RETURN SIL; END;
	IF SYMBOL(phi) THEN RETURN phi; END;
	RETURN FIRST(phi);
END FORGOP;

PROCEDURE FORGARGS(phi: LIST): LIST;
(* formula get arguments. phi is a formula; the arguments of the top level
operation of the formula phi are returned. You must not apply FORGARGS to
formulas without arguments! *)
BEGIN
	RETURN RED(phi);
END FORGARGS;

PROCEDURE FORGLVAR(lvar: LIST): LIST;
(* formula get list of variables. lvar is an object that describes a list of
variables; FORGLVAR returns a list of all variables in lvar.  *)
BEGIN
	RETURN RED(lvar);
END FORGLVAR;

PROCEDURE FORPFOR(phi: LIST; VAR op: LIST; VAR args: LIST);
(* formula parse formula. phi is a formula; FORPFOR returns in op the top
level operation symbol of phi and in args the arguments of the operation op.
*)
BEGIN
	IF SYMBOL(phi)
	THEN
		op:=phi;
		args:=SIL;
	ELSE
		ADV(phi,op,args);
	END;
END FORPFOR;

PROCEDURE FORPARGS(phi: LIST; VAR first, red: LIST);
(* formula parse arguments. phi is an object that describes a list of
arguments of an operation; FORPARGS returns in first the 1st argument of the
list and in red the list of all following arguments. *)
BEGIN
	ADV(phi,first,red);
END FORPARGS;

PROCEDURE FORPUNOP(phi: LIST; VAR op, arg: LIST);
(* formula parse unary operation. phi is a unary operation. The operator
symbol op and the argument arg are returned. *)
	VAR dummy: LIST;
BEGIN
	ADV2(phi,op,arg,dummy);
END FORPUNOP;

PROCEDURE FORPBINOP(phi: LIST; VAR op, first, second: LIST);
(* formula parse binary operation. phi is a binary operation. The operator
symbol op and the arguments first and second are returned. *)
	VAR dummy: LIST;
BEGIN
	ADV3(phi,op,first,second,dummy);
END FORPBINOP;

PROCEDURE FORPUNOPA(arglist: LIST; VAR arg: LIST);
(* formula parse unary operation argument. arglist is a list containing the
argument of a unary operator; FORPUNOPA returns in arg the arguments *)
	VAR dummy: LIST;
BEGIN
	ADV(arglist,arg,dummy);
END FORPUNOPA;

PROCEDURE FORPBINOPA(red: LIST; VAR first, second: LIST);
(* formula parse binary operation argument. red is a list of the arguments of
a binary operator; FORPBINOPA returns in first the 1st and in second the 2nd
argument.  *)
	VAR dummy: LIST;
BEGIN
	ADV2(red,first,second,dummy);
END FORPBINOPA;

PROCEDURE FORPQUANT(phi: LIST; VAR quant, vars, formula: LIST);
(* formula parse quantifier. phi is a quantified formula; FORPQUANT returns in
quant the quantifier of the formula phi, in vars the list of the bound
variables (as an lvar object) and in formula the formula phi without
quantifier. *)
	VAR dummy: LIST;
BEGIN
	ADV3(phi,quant,vars,formula,dummy);
END FORPQUANT;

PROCEDURE FORPQUANTA(red: LIST; VAR lvar, formula: LIST);
(* formula parse quantifier arguments. red is the reductum of a quantified
formula (e.g returned from FORPFOR); FORPQUANTA returns in lvar a list of all
quantified variables as an lvar object and in formula the formula without
quantifier.  *)
	VAR dummy: LIST;
BEGIN
	ADV2(red,lvar,formula,dummy);
END FORPQUANTA;

PROCEDURE FORPLVAR(lvar: LIST; VAR varlist: LIST);
(* formula parse list of variables. lvar is an object that describes a list of
variables; the list of all variables in lvar is returned in varlist. *)
	VAR dummy: LIST;
BEGIN
	ADV(lvar,dummy,varlist);
END FORPLVAR;

PROCEDURE FORPVAR(var: LIST; VAR name, sort: LIST);
(* formula parse variable. phi is a variable; FORPVAR returns in name the name
and in sort the sort of var. *)
	VAR dummy1, dummy2: LIST;
BEGIN
	ADV3(var,dummy1,name,sort,dummy2);
END FORPVAR;

PROCEDURE FORPVARA(red: LIST; VAR name, sort:LIST);
(* formula parse variable arguments. red is the reductum of a variable (e.g.
returned from FORPFOR); FORPVARA returns in name the name and in sort the sort
of the variable. *)
	VAR dummy: LIST;
BEGIN
	ADV2(red,name,sort,dummy);
END FORPVARA;

PROCEDURE FORMKFOR(op,args:LIST):LIST;
(* formula make formula. op is a operation symbol; args a list of arguments;
the formula op(arg1,arg2,...) is returned, if args=(arg1,arg2,...).  You can
generate constants with this function, too. *)
BEGIN
	IF (op=VERUM) OR (op=FALSUM)
	THEN
		RETURN op
	ELSE
		RETURN COMP(op,args);
	END;
END FORMKFOR;

PROCEDURE FORMKCNST(cnst: LIST):LIST;
(* formula make constant, i.e. a function with 0 arguments. cnst is a
constant; the formula 'cnst()' is returned *)
BEGIN
	RETURN cnst;
END FORMKCNST;

PROCEDURE FORMKUNOP(op,arg:LIST):LIST;
(* formula make unary operation. op is a operation symbol, arg is a argument;
the formula op(arg) is returned. *)
BEGIN
	RETURN LIST2(op,arg);
END FORMKUNOP;

PROCEDURE FORMKBINOP(op,arg1,arg2:LIST): LIST;
(* formula make binary operation. op is the operation symbol, arg1, arg2 are
the arguments; the formula op(arg1,arg2) is returned. *)
BEGIN
	RETURN LIST3(op,arg1,arg2);
END FORMKBINOP;

PROCEDURE FORMKVAR(name,sort:LIST):LIST;
(* formula make variable. name is the name, sort the sort of the variable; an
object that describes the variable is returned. *)
BEGIN
	RETURN LIST3(TVAR,name,sort);
END FORMKVAR;

PROCEDURE FORMKLVAR(vars:LIST):LIST;
(* formula make list of variables. vars is a list of the form (var1,
var2,...); an lvar object that represents the list of variables in vars is
returned. *)
BEGIN
	RETURN COMP(LVAR,vars);
END FORMKLVAR;

PROCEDURE FORMKQUANT(quant,vars,formula:LIST):LIST;
(* formula make quantifier. quant is the quantifier symbol, vars is a list of
variables, and formula the bound formula; the formula 'quant vars: formula'
is returned. *)
BEGIN
	RETURN LIST3(quant,vars,formula);
END FORMKQUANT;

PROCEDURE FORTST(L: LIST; bbtst:PROCFB1):BOOLEAN;
(* formula test. L is a list, bbtst a bb-procedure to test whether a list
represents a bb-formula or not; FORTST returns TRUE, if and only if L
represents a formula. *)
	VAR op, red, arg, arg1, arg2, lvar, qform, dummy: LIST;
	VAR isformula: BOOLEAN;
BEGIN
	IF L = SIL THEN RETURN FALSE; END;
	IF SYMBOL(L)
	THEN
		RETURN (L=VERUM) OR (L=FALSUM)
	END;
	IF ATOM(L)
	THEN
		RETURN FALSE;
	END;
	ADV(L,op,red);
	IF NOT SYMBOL(op)
		THEN RETURN FALSE;	(* Every correct object starts with a
					*  symbol (keyword). *)
	END;
	IF (op=ET) OR (op=VEL)		(* All functions with one ore more
					*  arguments. *)
	THEN
		IF red = SIL		(* No argument? *)
		THEN
			RETURN FALSE;
		END;
		isformula:=TRUE;
		WHILE (red <> SIL) AND isformula DO	(* All arguments
							 * correct? *)
			ADV(red,arg,red);
			isformula:=FORTST(arg,bbtst);
		END;
		RETURN isformula;
	ELSIF op=NON			(* All functions with exactly one
					*  argument. *)
	THEN
		IF (red=SIL) OR (RED(red)<>SIL)	(* number of arguments *)
		THEN
			RETURN FALSE;
		ELSE
			ADV(red,arg,dummy);
			RETURN FORTST(arg,bbtst);
		END;
	ELSIF (op=EXIST) OR (op=FORALL)	(* only quantifiers *)
	THEN
		IF (red=SIL) OR (RED(red)=SIL)
		THEN
			RETURN FALSE;
		END;
		ADV2(red,lvar,qform,dummy);
		RETURN (dummy=SIL) AND
			FORISLVAR(lvar) AND FORTST(qform,bbtst);
	ELSIF (op=IMP) OR (op=REP) OR (op=EQUIV) OR (op=XOR)	(* binary
								* operators *)
	THEN
		IF (red=SIL) THEN RETURN FALSE; END;
		ADV(red,arg1,red);
		IF red=SIL THEN RETURN FALSE; END;
		ADV(red,arg2,red);
		IF (red<>SIL) THEN RETURN FALSE; END;
		RETURN FORTST(arg1,bbtst) AND FORTST(arg2,bbtst);
	ELSIF op=TVAR
	THEN
		RETURN FORISBOOLVAR(L);
	ELSE
		RETURN bbtst(L);
	END;
END FORTST;

PROCEDURE FORISVAR(L: LIST):BOOLEAN;
(* formula is variable. L is a list; FORISVAR returns TRUE if and only if L
represents a variable. (The type of the variable is not checked.)  *)
	VAR key, name, sort, red: LIST;
BEGIN
	IF L = SIL THEN RETURN FALSE; END;
	IF ATOM(L) OR SYMBOL(L) THEN RETURN FALSE; END;

	ADV(L,key,red);
	IF (NOT SYMBOL(key)) OR (key<>TVAR)
	THEN
		RETURN FALSE;
	END;
	IF red=SIL THEN RETURN FALSE; END;
	ADV(red,name,red);
	IF (red=SIL) (* OR NOT SYMBOL(name) *)THEN RETURN FALSE; END;
	ADV(red,sort,red);
	IF (red<>SIL) (* OR NOT SYMBOL(sort) *) THEN RETURN FALSE; END;
	RETURN TRUE;		(* No typechecking at moment. *)
END FORISVAR;

PROCEDURE FORISBOOLVAR(L: LIST):BOOLEAN;
(* formula is boolean variable. L is a list; FORISBOOLVAR returns true if and
only if L represents a boolean variable *)
	VAR key, name, sort, red: LIST;
BEGIN
	IF L=SIL THEN RETURN FALSE; END;
	IF ATOM(L) OR SYMBOL(L) THEN RETURN FALSE; END;

	ADV(L,key,red);
	IF (NOT SYMBOL(key)) OR (key<>TVAR)
	THEN
		RETURN FALSE;
	END;
	IF red=SIL THEN RETURN FALSE; END;
	ADV(red,name,red);
	IF (red=SIL) OR NOT SYMBOL(name) THEN RETURN FALSE; END;
	ADV(red,sort,red);
	IF (red<>SIL) OR NOT SYMBOL(sort) THEN RETURN FALSE; END;
	RETURN sort=BOOL
END FORISBOOLVAR;

PROCEDURE FORISLVAR(L: LIST): BOOLEAN;
(* formula is variable list. L is a list; FORISLVAR returns TRUE if and only
if L represents an lvar-object. *)
	VAR elem, key, red: LIST;
	VAR is: BOOLEAN;
BEGIN
	IF L=SIL THEN RETURN FALSE; END;
	IF SYMBOL(L) OR ATOM(L) THEN RETURN FALSE; END;

	ADV(L,key,red);
	IF (red=SIL) OR (key<>LVAR) THEN RETURN FALSE; END;
	REPEAT
		ADV(red,elem,red);
		is:=FORISVAR(elem);
	UNTIL (red=SIL) OR (NOT is);
	RETURN is;
END FORISLVAR;


(******************************************************************************
*                      I S   A T O M I C   F O R M U L A                      *
******************************************************************************)

PROCEDURE FORISATOM(phi: LIST): BOOLEAN;
(* formula is atomic formula. phi is a formula, FORISATOM returns true, if and
only if phi is an atomic formula. An atomic formula is either VERUM or FALSUM
or a bb-formula or a variable of type bool. *)
	VAR op, res: LIST;
BEGIN
	FORPFOR(phi,op,res);
	RETURN (op=TVAR) OR (op=VERUM) OR (op=FALSUM) OR
		((op<>EXIST) AND (op<>FORALL) AND (op<>VEL) AND (op<>ET)
		AND (op<>IMP) AND (op<>REP) AND (op<>EQUIV) AND (op<>XOR)
		AND (op<>NON))
END FORISATOM;

PROCEDURE FORISBBFOR(phi: LIST):BOOLEAN;
(* formula is black-box formula. phi is a formula. TRUE is returned iff
phi is a black-box formula. *)
	VAR op: LIST;
BEGIN
	op:=FORGOP(phi);
	RETURN	(op<>EXIST) AND (op<>FORALL) AND 
		(op<>VEL) AND (op<>ET) AND 
		(op<>IMP) AND (op<>REP) AND (op<>EQUIV) AND (op<>XOR) AND 
		(op<>NON) AND 
		(op<>TVAR) AND (op<>VERUM) AND (op<>FALSUM); 
END FORISBBFOR;

(******************************************************************************
*                                 V A R T A B                                 *
******************************************************************************)

(* In the following section the procedures for handling the VARTAB are 
implemented. VARTAB is a table of all identifiers which are necessary to 
identify a variable and its sort unique. The structure of VARTAB is a 
assoc-list of pairs (name:identifier). Identifiers are beta-integers.
This structure of VARTAB is internal. There are external procedures to 
acess the VARTAB from modules. *)

PROCEDURE FORVTSTORE():LIST;
(* formula variable table store. The actual VARTAB is returned. *)
BEGIN
	RETURN VARTAB;
END FORVTSTORE;

PROCEDURE FORVTRESTORE(vt: LIST):LIST;
(* formula variable table restore. Vt is a variable table. 
The actual VARTAB is set to the value of vt. The old value of VARTAB is 
returned. *)
BEGIN
	VARTAB:=vt;
	RETURN VARTAB;
END FORVTRESTORE;

PROCEDURE FORVTENTER(sym: LIST):LIST;
(* formula variable table enter. Sym is a CLIST. 
The symbol with print name sym is entered in 
the actual variable table, if no symbol with name sym exists. 
The unique identifier is returned. 
*)
	VAR id,lastid: LIST; 
BEGIN
	id:=ASSOCQ(sym,VARTAB);
	IF id=SIL THEN
		IF VARTAB=SIL THEN
			lastid:=0;
		ELSE
			lastid:=SECOND(VARTAB);
		END;
		id:=lastid+1;
		VARTAB:=COMP2(sym,id,VARTAB);
	ELSE
		id:=FIRST(id);
	END;
	RETURN id;
END FORVTENTER;

PROCEDURE FORVTGET(id: LIST): LIST;
(* formula variable table get. The clist of the 
name of the symbol with identifier id is 
returned. If no symbol with identifier id exists, then 
SIL is returned. *)
	VAR l,i,s,name: LIST; 
BEGIN
	IF id <= 0 THEN RETURN SIL; END; 
	l:=VARTAB;
	i:=0;
	WHILE (l<>SIL) AND (i<>id) DO 
		ADV2(l,s,i,l);
	END;
	IF id=i THEN 
		name:=s;
	ELSE
		name:=SIL;
	END;
 	RETURN name;
END FORVTGET;

(******************************************************************************
*			 I N I T I A L I Z A T I O N			      *
******************************************************************************)

BEGIN (* OF INITIALIZATION *)
	LISTVAR(VARTAB);
	VARTAB:=SIL;
	BOOL:=FORVTENTER(LISTS("BOOL"));
	ANY:=FORVTENTER(LISTS("ANY"));
	Declare(ET,    "FORAND");
	Declare(VEL,   "FOROR");
	Declare(NON,   "FORNOT");
	Declare(VERUM, "TRUE");
	Declare(FALSUM,"FALSE");
	Declare(FORALL,"FORALL");
	Declare(EXIST, "FOREX");
	Declare(TVAR,  "FORVAR");
	Declare(LVAR,  "LVAR");
(*	Declare(ANY,   "ANY");
	Declare(BOOL,  "BOOL"); *)
	Declare(REP,   "FORREPL");
	Declare(IMP,   "FORIMPL");
	Declare(EQUIV, "FOREQUIV");
	Declare(XOR,   "FORXOR");
END MLOGBASE.

(* -EOF- *)
