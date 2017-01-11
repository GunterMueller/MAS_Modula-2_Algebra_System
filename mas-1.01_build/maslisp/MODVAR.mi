(* ----------------------------------------------------------------------------
 * $Id: MODVAR.mi,v 1.1 1994/11/28 21:01:28 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1994 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: MODVAR.mi,v $
 * Revision 1.1  1994/11/28  21:01:28  dolzmann
 * New modules MODVAR.md and MODVAR.mi.
 * Procedures for the access to global variables from the interpreter.
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MODVAR;
(* modula global variable implementation module. *)

(******************************************************************************
*		M O D U L A   G L O B A L   V A R I A B L E S		      *
*-----------------------------------------------------------------------------*
* Author:   Andreas Dolzmann                                                  *
* Language: Modula II                                                         *
* System:   This program is written for the computer algebra system MAS by    *
*           Heinz Kredel                                                      *
* Remark:   Libraries maskern, maslisp are used.                              *
*           Module SYSTEM is used!                                            *
* Abstract: This module implements routines for the access to global          *
*           variables of MODULA modules from the MAS interpreter.             *
******************************************************************************)

FROM SYSTEM 	IMPORT	ADR, ADDRESS;

FROM MASBIOS	IMPORT	BLINES, LISTS, SWRITE;
FROM MASELEM	IMPORT	GAMMAINT;
FROM MASERR	IMPORT	ERROR, confusion, fatal, harmless, severe, spotless;
FROM MASLISP	IMPORT	STRNG;
FROM MASLISPU	IMPORT	Declare;
FROM MASSTOR	IMPORT	COMP, LIST, LISTVAR, SIL;
FROM MASSYM2	IMPORT	ENTER, GET, NOSHOW, PUT, UWRIT1, UWRITE; 
FROM SACLIST	IMPORT	CLOUT, LIST2, SECOND;

CONST rcsidi = "$Id: MODVAR.mi,v 1.1 1994/11/28 21:01:28 dolzmann Exp $";
CONST copyrighti = "Copyright (c) 1994 Universitaet Passau";


(******************************************************************************
*                       G L O B A L   V A R I A B L E S                       *
******************************************************************************)

VAR	MGV,		(* Property to mark a modula variable (MVAR)	*)
	CMT,		(* Property to mark a comment of a MVAR.	*)
	SORT, 		(* Property to mark a sort of a MVAR.		*)
	BOOL, 		(* A special sort of a MVAR.			*)
	LST,		(* A special sort of a MVAR.			*)
	ACCESS, 	(* Property to mark the access permissions of 
			   a MVAR.					*)
	RO, 		(* A special access permission.			*)
	RW:  		(* A special access permission.			*)
		LIST;

(******************************************************************************
*                             P R O C E D U R E S                             *
******************************************************************************)

PROCEDURE MVDeclareL(VAR var: LIST; name,comment: ARRAY OF CHAR;
			access: BOOLEAN);
(* modula variable declare list. 
The global variable var is made accessible for the
MAS interpreter under the name name. Comment is a string which explains the
variable. access is a flag that determines, whether var is protected from 
overwriting or not. *)
	VAR sym: LIST;
BEGIN
	Declare(sym,name);
	PUT(sym,MGV,LIST2(NOSHOW,GAMMAINT(ADR(var))));
	PUT(sym,CMT,LIST2(NOSHOW,LISTS(comment)));
	IF access THEN
		PUT(sym,ACCESS,RW);
	ELSE
		PUT(sym,ACCESS,RO);
	END;
	PUT(sym,SORT,LST);
END MVDeclareL;

PROCEDURE MVDeclareB(VAR var: BOOLEAN; name,comment: ARRAY OF CHAR;
			access:BOOLEAN);
(* modula variable declare boolean. 
The global variable var is made accessible for the
MAS interpreter under the name name. Comment is a string which explains the
variable. access is a flag that determines, whether var is protected from 
overwriting or not. *)
	VAR sym: LIST;
BEGIN
	Declare(sym,name);
	PUT(sym,MGV,LIST2(NOSHOW,GAMMAINT(ADR(var))));
	PUT(sym,CMT,LIST2(NOSHOW,LISTS(comment)));
	IF access THEN
		PUT(sym,ACCESS,RW);
	ELSE
		PUT(sym,ACCESS,RO);
	END;
	PUT(sym,SORT,BOOL);
END MVDeclareB;

PROCEDURE MVSET(sym,value:LIST);
(* modula variable set. 
sym is a symbol, value is a list.
The value value is assigned to the modula variable  with the interpreter-name 
sym. *)
	VAR varp: POINTER TO LIST;
	VAR varl: LIST;
	VAR acc,srt: LIST;
BEGIN
	varl:=GET(sym,MGV);
	IF varl=SIL THEN
		ERROR(harmless,"MVSET: unbound modula variable");
		RETURN;
	END;
	acc:=GET(sym,ACCESS);
	IF acc=RO THEN 
		ERROR(harmless,"MVSET: variable is read only");
		RETURN;
	END;
	srt:=GET(sym,SORT);
	IF srt<>LST THEN
		ERROR(harmless,"MVSET: MVSET is possible only for list variables.");
		RETURN;
	END;
	varp:=ADDRESS(SECOND(varl));
	varp^:=value;
END MVSET;

PROCEDURE MVGET(sym:LIST): LIST;
(* modula variable get. The value of the modula variable with the name sym is
returned. *)
	VAR varp: POINTER TO LIST;
	VAR varl:LIST;
	VAR srt: LIST;
BEGIN
	varl:=GET(sym,MGV);
	IF varl=SIL THEN
		ERROR(harmless,"MVGET: unbound modula variable");
		RETURN SIL;
	END;
	srt:=GET(sym,SORT);
	IF srt<>LST THEN
		ERROR(harmless,"MVGET: MVGET is possible only for list variables.");
		RETURN SIL;
	END;
	varp:=ADDRESS(SECOND(varl));
	RETURN varp^;
END MVGET;

PROCEDURE MVFLAG(sym:LIST): LIST;
(* modula variable get. The boolean value of the modula variable with the 
name sym is returned. TRUE is equivalent to 1 and FALSE is equivalent to 0. *)
	VAR varp: POINTER TO BOOLEAN;
	VAR varl:LIST;
	VAR srt: LIST;
BEGIN
	varl:=GET(sym,MGV);
	IF varl=SIL THEN
		ERROR(harmless,"MVGET: unbound modula variable");
		RETURN 0;
	END;
	srt:=GET(sym,SORT);
	IF srt<>BOOL THEN
		ERROR(harmless,"MVFLAG: MVFLAG is possible only for boolean variables.");
		RETURN 0;
	END;
	varp:=ADDRESS(SECOND(varl));
	IF varp^ THEN
		RETURN 1;
	ELSE	
		RETURN 0;
	END;
END MVFLAG;

PROCEDURE MVON(sym:LIST);
(* modula variable on. The value 1 is assigned to the module variable with
the interpreter name sym. *)
	VAR varp: POINTER TO BOOLEAN;
	VAR varl: LIST;
	VAR acc,srt: LIST;
BEGIN
	varl:=GET(sym,MGV);
	IF varl=SIL THEN
		ERROR(harmless,"MVON: unbound modula variable");
		RETURN;
	END;
	acc:=GET(sym,ACCESS);
	IF acc=RO THEN 
		ERROR(harmless,"MVON: variable is read only");
		RETURN;
	END;
	srt:=GET(sym,SORT);
	IF srt<>BOOL THEN
		ERROR(harmless,"MVON: MVON is only for boolean variables possible.");
		RETURN;
	END;
	varp:=ADDRESS(SECOND(varl));
	varp^:=TRUE;
END MVON;

PROCEDURE MVOFF(sym:LIST);
(* modula variable off. The value 0 is assigned to the module variable with
the interpreter name sym. *)
	VAR varp: POINTER TO BOOLEAN;
	VAR varl: LIST;
	VAR acc,srt: LIST;
BEGIN
	varl:=GET(sym,MGV);
	IF varl=SIL THEN
		ERROR(harmless,"MVOFF: unbound modula variable");
		RETURN;
	END;
	acc:=GET(sym,ACCESS);
	IF acc=RO THEN 
		ERROR(harmless,"MVOFF: variable is read only");
		RETURN;
	END;
	srt:=GET(sym,SORT);
	IF srt<>BOOL THEN
		ERROR(harmless,"MVOFF: MVOFF is possible only for boolean variables.");
		RETURN;
	END;
	varp:=ADDRESS(SECOND(varl));
	varp^:=FALSE;
END MVOFF;

PROCEDURE MVHLP(sym:LIST);
(* modula variable help. All known informations over the modula variable with 
the interpreter name sym is printed to the output stream. *)
	VAR varpl: POINTER TO LIST;
	VAR varpb: POINTER TO BOOLEAN;
	VAR varl: LIST;
	VAR acc,srt,cmt: LIST;
BEGIN
	BLINES(0);
	varl:=GET(sym,MGV);
	IF varl=SIL THEN
		UWRIT1(sym);SWRITE(" is not a modula variable. ");BLINES(0);
		RETURN;
	END;
	SWRITE("Modula variable: ");UWRITE(sym);
	acc:=GET(sym,ACCESS);
	IF acc=RO THEN 
		SWRITE("  is a read-only variable");
	ELSE
		SWRITE("  is a read-write variable");
	END;
	(* BLINES(0); *)
	srt:=GET(sym,SORT);
	IF (srt=BOOL) THEN 
		SWRITE(" of the type BOOLEAN.");
	ELSE
		SWRITE(" of the type LIST.");
	END;
	BLINES(0);
	cmt:=SECOND(GET(sym,CMT));
	SWRITE("  Documentation:");BLINES(0);
	SWRITE("    ");
	CLOUT(cmt);
	BLINES(0);
	SWRITE("  Current value: ");BLINES(0);SWRITE("    ");
	IF srt=BOOL THEN
		varpb:=ADDRESS(SECOND(varl));
		IF varpb^ THEN
			SWRITE("TRUE");
		ELSE
			SWRITE("FALSE");
		END;
	ELSE
		varpl:=ADDRESS(SECOND(varl));
		UWRIT1(varpl^);
	END;
	BLINES(0);
END MVHLP;

(******************************************************************************
*                                   M A I N                                   *
******************************************************************************)

BEGIN
	Declare(MGV,"MGV");
	Declare(CMT,"Comment");
	Declare(SORT,"TYPE");
	Declare(BOOL,"BOOLEAN");
	Declare(LST,"LIST");
	Declare(RW,"ReadWrite");
	Declare(RO,"ReadOnly");
	Declare(ACCESS,"Access");
END MODVAR.

(* -EOF- *)
