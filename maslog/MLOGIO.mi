(* ----------------------------------------------------------------------------
 * $Id: MLOGIO.mi,v 1.2 1994/11/28 21:04:15 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: MLOGIO.mi,v $
 * Revision 1.2  1994/11/28  21:04:15  dolzmann
 * New revision of the MASLOG system: New functions and bug fixes of old one.
 *
 * Revision 1.1  1993/12/17  17:12:15  dolzmann
 * MASLOG is divided into three parts. (MLOGBASE, MLOGIO, MASLOG)
 * Additional input procedures are added.
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MLOGIO;
(* Maslog Input Output System Implementation Module. *)

(******************************************************************************
*				 M L O G I O				      *
*-----------------------------------------------------------------------------*
* Author:   Andreas Dolzmann                                                  *
* Language: MODULA II (mocka or mtc are possible.)                            *
* System:   Program for the computer algebra system MAS by Heinz Kredel.      *
* Project:  MASLOG                                                            *
* Remark:   Libraries maskern, maslisp, maslog are used.                      *
* Abstract: A package for the MAS computer algebra system by Heinz Kredel.    *
*           This package implements input and outputroutins for formulas      *
*	    in the format of the MASLOG library.                              *
******************************************************************************)

FROM MASELEM	IMPORT	GAMMAINT, MASEVEN, MASMAX, MASREM;
FROM MASSTOR	IMPORT	ADV, COMP, FIRST, INV, LENGTH, LIST, LIST1, LISTVAR,
			RED, SIL;
FROM MASERR	IMPORT	ERROR, confusion, fatal, harmless, severe, spotless;
FROM MASLISP	IMPORT	ENV;
FROM MASLISPU	IMPORT	Declare, PROCF0, PROCF1, PROCF3, PROCP1;
FROM MASBIOS	IMPORT	BKSP, BLINES, CREAD, CREADB, CWRITE, DIBUFF, DIGIT,
			LETTER, LISTS, MASORD, SWRITE;
FROM MASSYM	IMPORT	ATOM, UWRIT1, UWRITE;
FROM MASSYM2	IMPORT	ACOMP, ASSOCQ, ENTER, EXPLOD, GENSYM, SREAD, SREAD1,
			SYMBOL, SYWRIT;
FROM SACLIST	IMPORT	ADV2, ADV3, AREAD, AWRITE, CCONC, CINV, CLOUT, COMP2,
			CONC, EQUAL, LIST10, LIST2, LIST3, LIST4, LIST5,
			MEMBER, SECOND, THIRD;
FROM MLOGBASE	IMPORT	ANY, BOOL, EQUIV, ET, EXIST, FALSUM, FORALL,
			FORGARGS, FORGLVAR, FORGOP, FORISBOOLVAR, FORISLVAR,
			FORISVAR, FORMKBINOP, FORMKCNST, FORMKFOR, FORMKLVAR,
			FORMKQUANT, FORMKUNOP, FORMKVAR, FORPARGS, FORPBINOP,
			FORPBINOPA, FORPFOR, FORPLVAR, FORPQUANT, FORPQUANTA,
			FORPUNOP, FORPUNOPA, FORPVAR, FORPVARA, FORTST,
			FORVTENTER, FORVTGET, IMP, NON, REP, TVAR, VEL,
			VERUM, XOR;

CONST rcsidi = "$Id: MLOGIO.mi,v 1.2 1994/11/28 21:04:15 dolzmann Exp $";
CONST copyrighti = "Copyright (c) 1993 Universitaet Passau";

VAR ParserSyms: LIST; (* name table for the formula parser. *)

(******************************************************************************
*			   P R E T T Y   P R I N T                            *
******************************************************************************)

PROCEDURE FORPPRT(phi: LIST; bbpprt:PROCP1);
(* formula pretty print. phi is a formula; bbpprt a bb-procedure to write a
bb-formula to the output stream; phi is written formated to the output stream.
*)
	VAR op, red, arg, arg1, arg2, vars, qform, dummy, sort, name: LIST;
BEGIN
	IF phi = SIL THEN SWRITE("SIL"); RETURN; END;

	FORPFOR(phi,op,red);
	IF (op=VERUM) OR (op=FALSUM)
	THEN
		pprtop(op);
	ELSIF (op=VEL) OR (op=ET)
	THEN
		FORPARGS(red,arg,red);
		SWRITE("(");
		FORPPRT(arg,bbpprt);
		WHILE red <> SIL DO
			FORPARGS(red,arg,red);
			pprtop(op);
			FORPPRT(arg,bbpprt)
		END;
		SWRITE(")");
	ELSIF op=NON
	THEN
		FORPUNOPA(red,arg);
		pprtop(op);
		SWRITE("(");
		FORPPRT(arg,bbpprt);
		SWRITE(")");
	ELSIF (op=IMP) OR (op=REP) OR (op=EQUIV) OR (op=XOR)
	THEN
		FORPBINOPA(red,arg1,arg2);
		SWRITE("(");
		FORPPRT(arg1,bbpprt);
		pprtop(op);
		FORPPRT(arg2,bbpprt);
		SWRITE(")");
	ELSIF (op=EXIST) OR (op=FORALL)
	THEN
		FORPQUANTA(red,vars,qform);
		SWRITE("(");
		pprtop(op);
		FORPPLVAR(vars);
		SWRITE(":");
		FORPPRT(qform,bbpprt);
		SWRITE(")");
	ELSIF op=TVAR
	THEN
		FORPPVAR(phi);
	ELSE
		bbpprt(phi);
	END;
END FORPPRT;

PROCEDURE pprtop(op: LIST);
(* pretty print operator. a symbol for an operator is written to the output
stream. *)
BEGIN
	IF (op=IMP)	THEN SWRITE(" => ");	RETURN;	END;
	IF (op=REP)	THEN SWRITE(" <= "); 	RETURN; END;
	IF (op=EQUIV)	THEN SWRITE(" <=> "); 	RETURN; END;
	IF (op=XOR)	THEN SWRITE(" <#> "); 	RETURN; END;
	IF (op=ET)	THEN SWRITE(" /\ "); 	RETURN; END;
	IF (op=VEL)	THEN SWRITE(" \/ "); 	RETURN; END;
	IF (op=NON)	THEN SWRITE("-- "); 	RETURN; END;
	IF (op=EXIST)	THEN SWRITE("EX "); 	RETURN; END;
	IF (op=FORALL)	THEN SWRITE("FA "); 	RETURN; END;
	IF (op=VERUM)	THEN SWRITE("TRUE"); 	RETURN; END;
	IF (op=FALSUM)	THEN SWRITE("FALSE"); 	RETURN; END;
END pprtop;

PROCEDURE FORPPVAR(var: LIST);
(* formula pretty print variable. var is a variable; var is formated written
to the output stream. *)
	VAR name, sort: LIST;
BEGIN
	FORPVAR(var,name,sort);
	CLOUT(FORVTGET(name));
	IF (sort<>ANY) AND (sort<>BOOL) THEN 
		SWRITE("{");
		CLOUT(FORVTGET(sort));
		SWRITE("}");
	END; 
(*	SWRITE("<");
	CLOUT(FORVTGET(name));
	SWRITE(":");
	CLOUT(FORVTGET(sort));
	SWRITE(">"); *)
END FORPPVAR;

PROCEDURE FORPPLVAR(lvar: LIST);
(* formula print lvar. L is an lvar object; lvar is formated written to the
output stream. *)
	VAR var, varlist: LIST;
BEGIN
	FORPLVAR(lvar,varlist);
	IF varlist=SIL THEN RETURN END; 
	FORPARGS(varlist,var,varlist);
	FORPPVAR(var);
	WHILE varlist <> SIL DO
		SWRITE(",");
		FORPARGS(varlist,var,varlist);
		FORPPVAR(var);
	END;
END FORPPLVAR;


(******************************************************************************
*			      T E X   W R I T E                               *
******************************************************************************)

PROCEDURE FORTEXW(phi: LIST; bbtexw:PROCP1);
(* formula tex write. phi is a formula; bbtexw a bb-procedure to write a
bb-formula in tex style to the outputstream; this procedure writes a formula
in tex style to the outputstream. *)
	VAR op, red, arg, arg1, arg2, vars, qform:  LIST;
BEGIN
	IF phi = SIL THEN SWRITE("SIL"); RETURN; END;
	FORPFOR(phi,op,red);
	IF (op=VERUM) OR (op=FALSUM)
	THEN
		BLINES(0);
		ptexsymbol(phi);
	ELSIF (op=ET) OR (op=VEL)
	THEN
		BLINES(0);
		FORPARGS(red,arg,red);
		SWRITE("(");
		FORTEXW(arg,bbtexw);
		WHILE red <> SIL DO
			FORPARGS(red,arg,red);
			SWRITE(" ");
			ptexsymbol(op);
			SWRITE(" ");
			FORTEXW(arg,bbtexw)
		END;
		SWRITE(")");
	ELSIF op=NON
	THEN
		BLINES(0);
		SWRITE("(");
		ptexsymbol(op);
		FORPUNOPA(red,arg);
		FORTEXW(arg,bbtexw);
		SWRITE(")");
	ELSIF (op=EXIST) OR (op=FORALL)
	THEN
		BLINES(0);
		FORPQUANTA(red,vars,qform);
		SWRITE("(");
		ptexsymbol(op);
		FORTEXWLVAR(vars);
		SWRITE("(");
		FORTEXW(qform,bbtexw);
		SWRITE("))");
	ELSIF (op=IMP) OR (op=REP) OR (op=EQUIV) OR (op=XOR)
	THEN
		BLINES(0);
		FORPBINOPA(red,arg1,arg2);
		SWRITE("(");
		FORTEXW(arg1,bbtexw);
		ptexsymbol(op);
		FORTEXW(arg2,bbtexw);
		SWRITE(")");
	ELSIF (op=TVAR)
	THEN
		BLINES(0);
		FORTEXWVAR(phi);
	ELSE
		BLINES(0);
		bbtexw(phi);
	END;
END FORTEXW;

PROCEDURE FORTEXWVAR(var: LIST);
(* formula tex write variable. var is a variable; this procedure writes var in
tex style to the output stream. *)
	VAR name, sort: LIST;
BEGIN
(*	BLINES(0);
	FORPVAR(var,name,sort);
	SWRITE("\mbox{");
	CLOUT(FORVTGET(name));
	SWRITE("}:\mbox{");
	CLOUT(FORVTGET(sort));
	SWRITE("}"); *)

	FORPVAR(var,name,sort);
	CLOUT(FORVTGET(name));
	IF (sort<>ANY) AND (sort<>BOOL) THEN 
		SWRITE("{");
		CLOUT(FORVTGET(sort));
		SWRITE("}");
	END; 
END FORTEXWVAR;


PROCEDURE FORTEXWLVAR(lvar: LIST);
(* tex write list of varaiables. lvar is an lvar object; this procedure writes
all variables in lvar in tex style to the outputstream. *)
	VAR var, red, sort, name: LIST;
BEGIN
	FORPLVAR(lvar,red);
	ADV(red,var,red);
	FORTEXWVAR(var);
	WHILE red <> SIL DO
		ADV(red,var,red);
		SWRITE(", ");
		FORTEXWVAR(var);
	END;
END FORTEXWLVAR;

PROCEDURE ptexsymbol(sym: LIST);
(* print tex symbol. sym is predifened MASLOG symbol; writes sym in tex style
to the output stream. *)
BEGIN
	IF sym=VERUM	THEN SWRITE("\mbox{TRUE}");	RETURN; END;
	IF sym=FALSUM	THEN SWRITE("\mbox{FALSE}");	RETURN; END;
	IF sym=NON	THEN SWRITE("\lnot");		RETURN; END;
	IF sym=ET	THEN SWRITE("\land");		RETURN; END;
	IF sym=VEL	THEN SWRITE("\lor");		RETURN; END;
	IF sym=IMP	THEN SWRITE("\Rightarrow");	RETURN; END;
	IF sym=REP	THEN SWRITE("\Leftarrow");	RETURN; END;
	IF sym=EQUIV	THEN SWRITE("\iff");		RETURN; END;
	IF sym=XOR	THEN SWRITE("\oplus");		RETURN; END;
	IF sym=EXIST	THEN SWRITE("\exists ");	RETURN; END;
	IF sym=FORALL	THEN SWRITE("\forall " );	RETURN; END;
	SWRITE("\mbox{???}"); RETURN;
END ptexsymbol;

(******************************************************************************
*                    R E A D   P R E F I X   F O R M U L A                    *
******************************************************************************)

PROCEDURE FORPREAD(bbread: PROCF0):LIST;
(* formula prefix read. bbread is a bb-procedure to read a bb.formula from 
the input stream. FORPREAD reads a formula in prefix notation from the 
input stream and returns the read formula. *)
	VAR c:GAMMAINT;
	VAR result, args, sym, info, noargs, key: LIST;
BEGIN
	c:=CREADB();
	IF c=70 (* c=MASORD("(") *)  THEN
		result:=FORPREAD(bbread);
		c:=CREADB();
		IF c<>MASORD(")") THEN
			DIBUFF();
			ERROR(severe,") expected");
			BKSP();
		END;
		RETURN result;
	ELSIF c=85 (* c=MASORD("[") *) THEN
		BKSP();
		result:=atomicread(bbread);
		RETURN result;
	ELSE
		BKSP();
		key:=KEYREAD();
		result:=upcase(key);
		info:=ASSOCQ(result,ParserSyms);
		IF info=SIL THEN 		(* treat as a variable. *)
			RETURN FORRDVARA(key,BOOL);
		ELSE
			info:=FIRST(info);
			sym:=FIRST(info);
			noargs:=SECOND(info);	(* number of arguments *)
			IF noargs=0 THEN 
				RETURN FORMKCNST(sym);
			ELSIF noargs=-1 THEN
				args:=multiarg(bbread);
				RETURN FORMKFOR(sym,args);
			ELSIF noargs=1 THEN
				args:=onearg(bbread);
				RETURN FORMKUNOP(sym,args);
			ELSIF noargs=-2 THEN
				args:=FORRDQUANTA(bbread);
				RETURN FORMKQUANT(sym,FIRST(args),
					SECOND(args));
			ELSIF noargs=2 THEN
				args:=twoargs(bbread);
				RETURN FORMKBINOP(sym,FIRST(args),
					SECOND(args));
			ELSE 
				ERROR(severe,"FORPREAD: unknown noarg");
				RETURN SIL;
			END;
		END;
	END;	
END FORPREAD;

PROCEDURE FORRDVAR():LIST;
(* formula read variable. A description of a variable is read from the input 
stream. *)
	VAR c: GAMMAINT;
	VAR name, sort, sname, ssort:LIST;
BEGIN
	name:=SREAD1();
	IF NOT isvarname(name) THEN
		DIBUFF();
		ERROR(severe,"not valid as a variable name");
	END;
	sname:=FORVTENTER(name);
	c:=CREAD();
	IF c=91 (* c=MASORD("{") *) THEN 	(* { read sort of variable. *)
		sort:=SREAD1();
		IF NOT isvarname(sort) THEN
			DIBUFF();
			ERROR(severe,"not valid as a sort name");
		END;
		ssort:=FORVTENTER(sort);
		c:=CREADB();
		IF c<>92 (* c<>MASORD("}") *) THEN
			DIBUFF();
			ERROR(severe,"} expected");
			BKSP();
		END;
	ELSE
		BKSP();
		ssort:=ANY;
	END;		
	RETURN FORMKVAR(sname,ssort);
END FORRDVAR;

PROCEDURE FORRDVARA(name,sdefault:LIST):LIST;
(* formula read variable arguments. name is a name of a variable. If the next
string in the input stream is a sort name then the sort name is read otherwise
sdefault is taken as a sort name. The complete description of the variable is 
returned.  *)
	VAR c: GAMMAINT;
	VAR  sort, sname,ssort: LIST;
BEGIN
	IF NOT isvarname(name) THEN
		DIBUFF();
		ERROR(severe,"not valid as a variable name");
	END;
	sname:=FORVTENTER(name);
	c:=CREAD();
	IF c=91 (* c=MASORD("{") *) THEN 	(* read sort of variable. *)
		sort:=SREAD1();
		IF NOT isvarname(sort) THEN
			DIBUFF();
			ERROR(severe,"not valid as a sort name");
		END;		
		ssort:=FORVTENTER(sort);
		c:=CREADB();
		IF c<>92 (* c<>MASORD("}") *) THEN
			DIBUFF();
			ERROR(severe,"} expected");
			BKSP();
		END;
	ELSE
		BKSP();
		ssort:=sdefault;
	END;		
	RETURN FORMKVAR(sname,ssort);
END FORRDVARA;

PROCEDURE FORRDLVAR():LIST;
(* formula read list of variables. One variable or a list of variables are 
read from the input stream. A LVAR-object is returned. *)
	VAR c: GAMMAINT;
	VAR var, vlist: LIST;
BEGIN
	c:=CREADB();
	IF LETTER(c) THEN
		BKSP();
		var:=FORRDVAR();
		RETURN FORMKLVAR(LIST1(var));
	ELSIF c=70 (* c=MASORD("(") *) THEN		(* read a list *)
		vlist:=SIL;
		c:=CREADB();
		WHILE c<>71 (* MASORD(")") *) DO
			BKSP();
			var:=FORRDVAR();
			vlist:=COMP(var,vlist);
			c:=CREADB();
			IF c=63 (* c=MASORD(",") *) THEN c:=CREADB(); END;
		END;
		RETURN FORMKLVAR(INV(vlist));
	ELSE
		DIBUFF();
		ERROR(severe,") expected");
		BKSP();
		RETURN SIL;
	END;
END FORRDLVAR; 

PROCEDURE FORRDQUANTA(bbread: PROCF0):LIST;
(* formula read quantifier arguments. 
The arguments of  a quantifier is read from the input stream. A list is 
returned. The first element of the list is the list of bound variables of
the quantifier (as an LVAR-object). The second element of the list is the 
bound formula. *)
	VAR c:GAMMAINT;
	VAR varlist, phi: LIST;
BEGIN
	c:=CREADB();
	IF c<>70 (* c<>MASORD("(") *) THEN
		DIBUFF();
		ERROR(severe,"( expected");
		BKSP();
		RETURN SIL;
	END;
	varlist:=FORRDLVAR();
	c:=CREADB();
	IF c<>63 (* c<>MASORD(",") *) THEN BKSP(); END;
	phi:=FORPREAD(bbread);
	c:=CREADB();
	IF c<>71 (* c<>MASORD(")") *) THEN
		DIBUFF();
		ERROR(severe,") expected");
		BKSP();
		RETURN LIST2(varlist,phi);
	END;
	RETURN LIST2(varlist,phi);
END FORRDQUANTA;

PROCEDURE onearg(bbread:PROCF0):LIST;
(* one argument. One argument is read from the input stream and is returned. *)
	VAR c: GAMMAINT;
	VAR arg: LIST;
BEGIN
	c:=CREADB();
	IF c<>70 (* c<>MASORD("(") *) THEN
		DIBUFF();
		ERROR(severe,"( expected");
		BKSP();
		RETURN SIL;
	END;
	arg:=FORPREAD(bbread);
	c:=CREADB();
	IF c<>71 (* c<>MASORD(")" *) THEN
		DIBUFF();
		ERROR(severe,") expected");
		BKSP();
		RETURN arg;
	END;
	RETURN arg;
END onearg;

PROCEDURE twoargs(bbread:PROCF0):LIST;
(* two arumgents. Two arguments are read from the input stream and are 
returned. *)
	VAR c: GAMMAINT;
	VAR arg, result: LIST;
	VAR i:INTEGER;
BEGIN
	c:=CREADB();
	IF c<>70 (* c<>MASORD("(") *) THEN
		DIBUFF();
		ERROR(severe,"( expected");
		BKSP();
		RETURN SIL;
	END;
	result:=SIL;
	FOR i:=1 TO 2 DO
		arg:=FORPREAD(bbread);
		result:=COMP(arg,result);
		c:=CREADB();
		IF c<>63 (* c<>MASORD(",") *) THEN BKSP(); END;
	END;
	c:=CREADB();
	IF c<>71 (* c<>MASORD(")") *) THEN 
		DIBUFF();
		ERROR(severe,") expected");
		BKSP();
	END;
	RETURN INV(result);
END twoargs;	

PROCEDURE multiarg(bbread:PROCF0):LIST;
(* multi arguments. bbread is a bb-procedure to read a bb-formula from the
input stream. A list of arguments is read from the input stream and is
returned. *)
	VAR c: GAMMAINT;
	VAR arg, result: LIST;
BEGIN
	c:=CREADB();
	IF c<>70 (* c<>MASORD("(") *) THEN
		DIBUFF();
		ERROR(severe,"( expected");
		BKSP();
		RETURN SIL;
	END;
	c:=CREADB();
	result:=SIL;
	WHILE c<>71 (* MASORD(")") *) DO
		BKSP();
		arg:=FORPREAD(bbread);
		result:=COMP(arg,result);
		c:=CREADB();
		IF c=63 (* c=MASORD(",") *) THEN c:=CREADB(); END;
	END;
	RETURN INV(result);
END multiarg;

PROCEDURE atomicread(bbread:PROCF0):LIST;
(* atomic read. bbread is a bb-procedure to read a bb-formula from the
input stream. A bb-formula is read from the input stream. *)
	VAR c:GAMMAINT;
	VAR result:LIST;
BEGIN
	c:=CREADB(); (* ignore [ *)
	result:=bbread();
	c:=CREADB();
	IF c<>87 (* c<>MASORD("]") *) THEN
		DIBUFF();
		ERROR(severe,"] expected");
		BKSP();
	END;
	RETURN result;
END atomicread;


PROCEDURE KEYREAD(): LIST;
(*key read. A keyword or a symbol for a keyword is read. A keyword is a string
of letters ore a string of special characters. The keyword or the symbol is 
also terminated by the characters "()[]{}".
The read keyword is returned a a CLIST.
This procedure is based on the procedure SREAD1 from the module MASSYM2 *)
	VAR  C, L: LIST;
	VAR end:LIST;
BEGIN
	L:=SIL; 
	C:=CREADB();
	IF LETTER(C) THEN
		REPEAT 
			L:=COMP(C,L);
			C:=CREAD();
		UNTIL NOT DIGIT(C) AND NOT LETTER(C);
	ELSE
		REPEAT 
			L:=COMP(C,L);
			C:=CREAD();
		UNTIL ((C=70) OR (C=71) OR (C=72) OR (C=85) OR (C=87) OR 
			(C=91) OR (C=92) OR DIGIT(C) OR LETTER(C) );
	END;
	BKSP; 
	L:=INV(L);
	RETURN(L); 
END KEYREAD;


PROCEDURE InitParser();
(* Initialize the internal data structures for the formula parsers
FORPREAD and FORIREAD. 
ParserSyms is a global name table for the parser. It has the format of a 
ASSOC-list. The first entry in the ASSOC-list is the representation of a
symbol. The second entry is a list which describes the symbol. The first 
entry of this list is the internal representation of the symbol, the second
entry describes the arity of the symbol, and the third entry is the priority
of the symbol. *)
BEGIN
	ParserSyms:=SIL;
	LISTVAR(ParserSyms);
	ParserSyms:=COMP2( LISTS("T"),	    LIST3(VERUM,   0,-1), ParserSyms);
	ParserSyms:=COMP2( LISTS("TRUE"),   LIST3(VERUM,   0,-1), ParserSyms);
	ParserSyms:=COMP2( LISTS("VERUM"),  LIST3(VERUM,   0,-1), ParserSyms);
	ParserSyms:=COMP2( LISTS("FALSE"),  LIST3(FALSUM,  0,-1), ParserSyms);
	ParserSyms:=COMP2( LISTS("F"),      LIST3(FALSUM,  0,-1), ParserSyms);
	ParserSyms:=COMP2( LISTS("FALSUM"), LIST3(FALSUM,  0,-1), ParserSyms);
	ParserSyms:=COMP2( LISTS("ET"),     LIST3(ET,     -1, 2), ParserSyms);
	ParserSyms:=COMP2( LISTS("AND"),    LIST3(ET,     -1, 2), ParserSyms);
	ParserSyms:=COMP2( LISTS("/\"),     LIST3(ET,     -1, 2), ParserSyms);
	ParserSyms:=COMP2( LISTS("OR"),     LIST3(VEL,    -1, 3), ParserSyms);
	ParserSyms:=COMP2( LISTS("VEL"),    LIST3(VEL,    -1, 3), ParserSyms);
	ParserSyms:=COMP2( LISTS("\/"),     LIST3(VEL,    -1, 3), ParserSyms);
	ParserSyms:=COMP2( LISTS("NOT"),    LIST3(NON,     1, 1), ParserSyms);
	ParserSyms:=COMP2( LISTS("NOTT"),   LIST3(NON,     1, 1), ParserSyms);
	ParserSyms:=COMP2( LISTS("NON"),    LIST3(NON,     1, 1), ParserSyms);
	ParserSyms:=COMP2( LISTS("~"),      LIST3(NON,     1, 1), ParserSyms);
	ParserSyms:=COMP2( LISTS("--"),     LIST3(NON,     1, 1), ParserSyms);
	ParserSyms:=COMP2( LISTS("FORALL"), LIST3(FORALL, -2, 6), ParserSyms);
	ParserSyms:=COMP2( LISTS("ALL"),    LIST3(FORALL, -2, 6), ParserSyms);
	ParserSyms:=COMP2( LISTS("FA"),     LIST3(FORALL, -2, 6), ParserSyms);
	ParserSyms:=COMP2( LISTS("EX"),	    LIST3(EXIST,  -2, 6), ParserSyms);
	ParserSyms:=COMP2( LISTS("EXIST"),  LIST3(EXIST,  -2, 6), ParserSyms);
	ParserSyms:=COMP2( LISTS("EXISTS"),  LIST3(EXIST,  -2, 6), ParserSyms);
	ParserSyms:=COMP2( LISTS("E"),      LIST3(EXIST,  -2, 6), ParserSyms);
	ParserSyms:=COMP2( LISTS("EQUIV"),  LIST3(EQUIV,   2, 5), ParserSyms);
	ParserSyms:=COMP2( LISTS("<===>"),  LIST3(EQUIV,   2, 5), ParserSyms);
	ParserSyms:=COMP2( LISTS("<=>"),    LIST3(EQUIV,   2, 5), ParserSyms);
	ParserSyms:=COMP2( LISTS("IMP"),    LIST3(IMP,     2, 4), ParserSyms);
	ParserSyms:=COMP2( LISTS("IMPL"),   LIST3(IMP,     2, 4), ParserSyms);
	ParserSyms:=COMP2( LISTS("===>"),   LIST3(IMP,     2, 4), ParserSyms);
	ParserSyms:=COMP2( LISTS("==>"),    LIST3(IMP,     2, 4), ParserSyms);
	ParserSyms:=COMP2( LISTS("=>"),     LIST3(IMP,     2, 4), ParserSyms);
	ParserSyms:=COMP2( LISTS("REP"),    LIST3(REP,     2, 4), ParserSyms);
	ParserSyms:=COMP2( LISTS("REPL"),   LIST3(REP,     2, 4), ParserSyms);
	ParserSyms:=COMP2( LISTS("<==="),   LIST3(REP,     2, 4), ParserSyms);
	ParserSyms:=COMP2( LISTS("<=="),    LIST3(REP,     2, 4), ParserSyms);
	ParserSyms:=COMP2( LISTS("<="),     LIST3(REP,     2, 4), ParserSyms);
	ParserSyms:=COMP2( LISTS("XOR"),    LIST3(XOR,     2, 5), ParserSyms);
	ParserSyms:=COMP2( LISTS("ANTIV"),  LIST3(XOR,     2, 5), ParserSyms);
	ParserSyms:=COMP2( LISTS("+"),      LIST3(XOR,     2, 5), ParserSyms);
	ParserSyms:=COMP2( LISTS("<=/=>"),  LIST3(XOR,     2, 5), ParserSyms);
	ParserSyms:=COMP2( LISTS("</>"),    LIST3(XOR,     2, 5), ParserSyms);
	ParserSyms:=COMP2( LISTS("<#>"),    LIST3(XOR,     2, 5), ParserSyms);
END InitParser;

PROCEDURE upcase(clist:LIST):LIST;
(* upcase character list. clist is a character list. 
All letters in clist are converted to upper case. The result is returned. *)
	VAR c:GAMMAINT;
	VAR result:LIST;
BEGIN
	result:=SIL;
	WHILE clist<>SIL DO
		ADV(clist,c,clist);
		IF LETTER(c) AND MASEVEN(c) THEN
			result:=COMP(c+1,result);
		ELSE
			result:=COMP(c,result);
		END;
	END;
	RETURN INV(result);
END upcase;

(******************************************************************************
*                     R E A D   I N F I X   F O R M U L A                     *
******************************************************************************)

PROCEDURE FORIREAD(bbread:PROCF0):LIST;
(* formula infix read. bbread is a bb-procedure to read a bb.formula from the 
input stream. This procedure reads a formula in infix notation 
from the input stream and returns the read formula. *)
	VAR c: GAMMAINT;
	VAR result, info, sym, noargs, args, key, dummy: LIST;
	VAR opstack, argstack: LIST;
	VAR parlevel: LIST; (*parenthesis level*)
	VAR expectop: BOOLEAN; (* expect operator symbol. If expectop is true 
				  then the next symbol must be an operator. *)
	VAR exitifparl0: BOOLEAN; 
BEGIN
	(* to do; correct use of exitifparl0
	          poping unary operation from operator stack, if an arguments 
	          is pushed on the argument stack. *)

	opstack:=SIL;
	argstack:=SIL;
	expectop:=FALSE;
	parlevel:=0;
	c:=CREADB();
	BKSP();
(*	IF c=MASORD("(") THEN 
		exitifparl0:=TRUE;
	ELSE
		exitifparl0:=FALSE;
	END; *)
exitifparl0:=FALSE;
	LOOP
		c:=CREADB();
		IF c=70 (* c=MASORD("(") *)  THEN
			parlevel:=parlevel+1; 
			push(LIST3(70,-99,99),opstack);			
			IF expectop THEN 
				DIBUFF();
				ERROR(severe,"operator expected");
			END;
		ELSIF c=71 (* c=MASORD(")") *) THEN
			IF parlevel<=0 THEN
				DIBUFF();
				ERROR(severe,"incorrect parenthesis");
			END;
			IF NOT expectop THEN 
				DIBUFF();
				ERROR(severe,"argument expected")
			END;
			parlevel:=parlevel-1;
			gensubformula(99,opstack,argstack);
			pop(dummy,opstack);
			IF FIRST(dummy)<>70 THEN
				DIBUFF();
				ERROR(severe,"incocrect parenthesis");
			END;
			IF exitifparl0 THEN EXIT; END;
		ELSIF c=85 (* c=MASORD("[") *) THEN
			IF expectop THEN
				DIBUFF();
				ERROR(severe,"operator expected");
			END;
			expectop:=TRUE; 
			BKSP();
			result:=atomicread(bbread);
			push(result,argstack);
		ELSIF c=75 (* c=MASORD("#") *) THEN 
			IF expectop THEN 
				DIBUFF();
				ERROR(severe,"operator expected");
			END; 
			push(rdmasvar(),argstack);
			expectop:=TRUE;
		ELSIF c=62 (* c=MASORD(".") *) THEN 
			EXIT;
		ELSE
			BKSP();
			key:=KEYREAD();
			result:=upcase(key);
			info:=ASSOCQ(result,ParserSyms);
			IF info=SIL THEN 	(* treat as a variable. *)
				IF expectop THEN 
					DIBUFF();
					ERROR(severe,"operator expected");
				END;
				push(FORRDVARA(key,BOOL),argstack);
				expectop:=TRUE; 
			ELSE				
				info:=FIRST(info);			
				sym:=FIRST(info);
				noargs:=SECOND(info); (* number of arguments *)
				IF noargs=0 THEN
					IF expectop THEN 
						DIBUFF();
						ERROR(severe,"operator expected");
					END;
					expectop:=TRUE;
					push(FORMKCNST(sym),argstack);
				ELSIF noargs=1 THEN 
					IF expectop THEN 
						DIBUFF();
						ERROR(severe,"operator expected")
					END;
					pushop(info,opstack,argstack);
				ELSIF noargs=2 THEN 
					IF NOT expectop THEN 
						DIBUFF();
						ERROR(severe,"argument expected");
					END;
					pushop(info,opstack,argstack);
					expectop:=FALSE;
				ELSIF noargs=-1 THEN 
					IF NOT expectop THEN 
						DIBUFF();
						ERROR(severe,"argument expected");
					END;
					pushop(info,opstack,argstack);
					expectop:=FALSE;
				ELSIF noargs=-2 THEN
					IF expectop THEN 
						DIBUFF();
						ERROR(severe,"operator expected");
					END;				 
					rdquanta(info,
						opstack,argstack,bbread);
				ELSE
					ERROR(severe,"parity not valid");
					pushop(info,opstack,argstack);
				END;
			END
		END;
	END;
	IF parlevel>0 THEN 
		DIBUFF();
		ERROR(severe,"incorrect parenthesis");
	END;
	RETURN genformula(opstack,argstack);
END FORIREAD;

PROCEDURE pushop(op:LIST;VAR opstack, argstack:LIST);
(* push operator. Op is a list which describes an operator. opstack, argstack
are the internal stacks of the parser. An operator is pushed to the 
opstack. Subformuls are generated if it is possible. *)
	VAR sym, noargs, prio, lastop, lastsym, lastnoargs, lastprio:LIST;
	VAR phi:LIST;
BEGIN
	IF opstack=SIL THEN push(op,opstack); RETURN; END;
	sym:=FIRST(op);
	noargs:=SECOND(op); (* number of arguments *)
	prio:=THIRD(op);
	lastop:=FIRST(opstack);
	lastsym:=FIRST(lastop);
	lastnoargs:=SECOND(lastop);
	lastprio:=THIRD(lastop);
	IF prio<lastprio THEN
		push(op,opstack);
		RETURN;
	ELSIF prio>lastprio THEN
		gensubformula(prio,opstack,argstack);
		push(op,opstack);
	ELSIF prio=lastprio THEN
		IF noargs=1 THEN
			push(op,opstack);
		ELSIF (noargs>1) THEN
			gensubformula(prio,opstack,argstack);
			push(op,opstack);
		ELSIF (noargs=-1) AND (sym=lastsym) THEN
			push(op,opstack);
		ELSIF (noargs=-1) AND (sym<>lastsym) THEN
			gensubformula(prio,opstack,argstack);
			push(op,opstack);
		ELSIF noargs=-2 THEN
			IF lastnoargs=-2 THEN 
				push(op,opstack);
			ELSE 
				gensubformula(prio,opstack,argstack);
				push(op,opstack);
			END;
		ELSE
			DIBUFF();
			ERROR(severe,"INTERNAL ERROR (pushop): wrong noargs ");
		END;	
	(* ELSE  impossible *)
	END;
END pushop;

PROCEDURE push(elem:LIST; VAR stack:LIST);
(* push. push the element elem to the stack stack. *)
BEGIN
	stack:=COMP(elem,stack);
END push;

PROCEDURE pop(VAR elem, stack:LIST);
(* pop. pop the elem elem from the stack stack.  *)
BEGIN
	IF stack=SIL THEN
		ERROR(fatal,"POP: pop to empty stack");
		elem:=SIL;
		RETURN;
	ELSE
		ADV(stack,elem,stack);
		RETURN;
	END;
END pop;

PROCEDURE pop2(VAR elem1,elem2,stack:LIST);
(* pop two elements. pop two elements elem1 and elem2 from the stack stack. *)
BEGIN
	IF (stack=SIL) OR (RED(stack)=SIL) THEN
		ERROR(fatal,"POP2: pop to empty stack");
		elem1:=SIL;
		elem2:=SIL;
		RETURN;
	ELSE
		ADV2(stack,elem1,elem2,stack);
		RETURN;
	END;
END pop2;

PROCEDURE gensubformula(prio:LIST;VAR opstack,argstack:LIST);
(* generate subformula. Generate a subformula in respect to the stacks 
opstack and argstack. The provedure terminates, if either opstack is empty
or the priority of the top of the opstack is lower (i.e prio has a numeric
lower value than the priority of the top of the stack opstack.) than prio. *)
	VAR lastop, lastsym, lastnoargs, lastprio, result: LIST;
	VAR arg, arg1, arg2: LIST;
BEGIN
	WHILE (opstack<>SIL) AND (THIRD(FIRST(opstack))<=prio) 
		AND (FIRST(FIRST(opstack))<>70) DO
		pop(lastop,opstack);
		lastsym:=FIRST(lastop);
		lastnoargs:=SECOND(lastop);
		lastprio:=THIRD(lastop);
		IF lastnoargs=1 THEN 
			pop(arg,argstack);
			push(FORMKUNOP(lastsym,arg),argstack);
		ELSIF lastnoargs=2 THEN
			pop2(arg2,arg1,argstack);
			push(FORMKBINOP(lastsym,arg1,arg2),argstack);
		ELSIF lastnoargs=-1 THEN
			aanop(lastsym,opstack,argstack);
		ELSIF lastnoargs=-2 THEN
			pop2(arg2,arg1,argstack);
			push(FORMKQUANT(lastsym,arg1,arg2),argstack);
		ELSE
			DIBUFF();
			ERROR(severe,"INTERNAL ERROR (gensubf): wrong noargs");
		END; 
	END;
END gensubformula;

PROCEDURE genformula(VAR opstack,argstack:LIST):LIST;
(* generate formula. The stacks opstack and argstack are taked down. The 
resulting formula is returned. *)
	VAR result:LIST;
BEGIN
	IF opstack=SIL THEN 
		IF argstack=SIL THEN RETURN VERUM; END;
		ADV(argstack,result,argstack);
	ELSE
		gensubformula(99,opstack,argstack);
		ADV(argstack,result,argstack);
	END;
	RETURN result;
END genformula;

PROCEDURE aanop(lastsym:LIST;VAR opstack,argstack:LIST);
(* arbitrary argument number operation. An operator vel or et is taken from 
the opstack. *)
	VAR arg,arg1,arg2, arglist, op: LIST;
BEGIN	
	arglist:=SIL;
	pop2(arg2,arg1,argstack);
	arglist:=LIST2(arg1,arg2);
	WHILE (opstack<>SIL) AND (FIRST(FIRST(opstack))=lastsym) DO
		ADV(opstack,op,opstack);
		ADV(argstack,arg,argstack);
		arglist:=COMP(arg,arglist);
	END;
	push(FORMKFOR(lastsym,arglist),argstack);
	RETURN;
END aanop;

PROCEDURE rdvlist():LIST;
(* formula read list of variables. One variable or a list of variables are 
read from the input stream. *)
	VAR c: GAMMAINT;
	VAR var, vlist: LIST;
BEGIN
	vlist:=SIL;
	c:=CREADB();
	WHILE (c<>79) AND (c<>70) (* MASORD(":") MASORS("("). *) DO
		BKSP();
		var:=FORRDVAR();
		vlist:=COMP(var,vlist);
		c:=CREADB();
		IF c=63 (* c=MASORD(",") *) THEN c:=CREADB(); END;
	END;
	IF c=70 THEN BKSP(); END;
	RETURN FORMKLVAR(INV(vlist));
END rdvlist; 

PROCEDURE rdquanta(quant:LIST; VAR opstack, argstack:LIST;bbread:PROCF0);
(* formula read quantifier arguments. quant is a symbol for a quantifier,
opstack and argstack are the internal stacks of the parser. 
The symbol quant is pushed to the opstack, a list of variables is read 
from the input stream and is pushed to the argstack. *)
	VAR c:GAMMAINT;
	VAR varlist,phi,vars,alist:LIST;
BEGIN
	c:=CREADB();
	IF c=70 THEN
		BKSP();
		alist:=FORRDQUANTA(bbread);
		vars:=FIRST(alist);
		phi:=SECOND(alist);
		push(FORMKQUANT(quant,vars,phi),argstack);
		RETURN;
	END;
	BKSP();
	varlist:=rdvlist();
	pushop(quant,opstack,argstack);
	push(varlist,argstack);
END rdquanta;

PROCEDURE rdmasvar():LIST; 
(* read mas variable. The next symbol s of the input stream is read and the 
value of the mas interpreter variable with name s is returned. *)
	VAR s: LIST;
	VAR V,var,val: LIST;
BEGIN
	V:=ENV;
	s:=SREAD();
	WHILE (V<>SIL) DO
		ADV2(V,var,val,V);
		IF var=s THEN RETURN val END; 
	END;
	DIBUFF();
	ERROR(severe,"not defined as a mas variable"); 
	RETURN VERUM;
END rdmasvar;

PROCEDURE isvarname(name:LIST):BOOLEAN;
(* is variable name. name is a CLIST. returns true if the first character 
of name is a letter and all following charaters are letters or digits. *)
	VAR c: LIST;
BEGIN
	IF name=SIL THEN RETURN FALSE; END;
	ADV(name,c,name);
	IF NOT LETTER(c) THEN RETURN FALSE; END;
	WHILE name<>SIL DO 
		ADV(name,c,name);
		IF NOT(LETTER(c) OR DIGIT(c)) THEN RETURN FALSE; END;
	END;
	RETURN TRUE;
END isvarname; 

(******************************************************************************
*                                   M A I N                                   *
******************************************************************************)

BEGIN
	InitParser();
END MLOGIO.
