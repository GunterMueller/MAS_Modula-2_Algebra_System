(* ----------------------------------------------------------------------------
 * $id$
 * ----------------------------------------------------------------------------
 * Copyright (c) 1994 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: MODVAR.md,v $
 * Revision 1.2  1995/12/16 14:46:01  kredel
 * Comments slightly edited.
 *
 * Revision 1.1  1994/11/28  21:01:24  dolzmann
 * New modules MODVAR.md and MODVAR.mi.
 * Procedures for the access to global variables from the interpreter.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MODVAR;
(* Modula Global Variable Implementation Module. *)

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

FROM MASSTOR 	IMPORT	LIST;

CONST rcsid = "$Id: MODVAR.md,v 1.2 1995/12/16 14:46:01 kredel Exp $";
CONST copyright = "Copyright (c) 1993 Universitaet Passau";

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

PROCEDURE MVDeclareB(VAR var: BOOLEAN; name,comment: ARRAY OF CHAR;
			access:BOOLEAN);
(* modula variable declare boolean. 
The global variable var is made accessible for the
MAS interpreter under the name name. Comment is a string which explains the
variable. access is a flag that determines, whether var is protected from 
overwriting or not. *)

PROCEDURE MVSET(sym,value:LIST);
(* modula variable set. 
sym is a symbol, value is a list.
The value value is assigned to the modula variable  with the interpreter-name 
sym. *)

PROCEDURE MVGET(sym:LIST): LIST;
(* modula variable get. The value of the modula variable with the name sym is
returned. *)

PROCEDURE MVFLAG(sym:LIST): LIST;
(* modula variable get. The boolean value of the modula variable with the 
name sym is returned. TRUE is equivalent to 1 and FALSE is equivalent to 0. *)

PROCEDURE MVON(sym:LIST);
(* modula variable on. The value 1 is assigned to the module variable with
the interpreter name sym. *)

PROCEDURE MVOFF(sym:LIST);
(* modula variable off. The value 0 is assigned to the module variable with
the interpreter name sym. *)

PROCEDURE MVHLP(sym:LIST);
(* modula variable help. All known informations over the modula variable with 
the interpreter name sym is printed to the output stream. *)

END MODVAR.

(* -EOF- *)
