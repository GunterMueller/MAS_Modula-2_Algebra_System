(* ----------------------------------------------------------------------------
 * $Id: MLOGIO.md,v 1.2 1994/11/28 21:04:14 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: MLOGIO.md,v $
 * Revision 1.2  1994/11/28  21:04:14  dolzmann
 * New revision of the MASLOG system: New functions and bug fixes of old one.
 *
 * Revision 1.1  1993/12/17  17:12:14  dolzmann
 * MASLOG is divided into three parts. (MLOGBASE, MLOGIO, MASLOG)
 * Additional input procedures are added.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MLOGIO;
(* Maslog Input Output System Definition Module. *)

(******************************************************************************
*				 M L O G I O				      *
*-----------------------------------------------------------------------------*
* Author:   Andreas Dolzmann                                                  *
* Language: MODULA II (mocka or mtc are possible.)                            *
* System:   Program for the computer algebra system MAS by Heinz Kredel.      *
* Project:  MASLOG
* Remark:   Libraries maskern, maslisp, maslog are used.                      *
* Abstract: A package for the MAS computer algebra system by Heinz Kredel.    *
*           This package implements input and outputroutins for formulas      *
*	    in the format of the MASLOG library.                              *
******************************************************************************)

FROM MASSTOR IMPORT LIST;
FROM MASLISPU IMPORT PROCF0,PROCF1,PROCP1,PROCF3;

CONST rcsid = "$Id: MLOGIO.md,v 1.2 1994/11/28 21:04:14 dolzmann Exp $";
CONST copyright = "Copyright (c) 1993 Universitaet Passau";


(******************************************************************************
*			   P R E T T Y   P R I N T                            *
******************************************************************************)

PROCEDURE FORPPRT(phi: LIST; bbpprt:PROCP1);
(* formula pretty print. phi is a formula; bbpprt a bb-procedure to write a
bb-formula to the output stream; phi is written formated to the output stream.
*)

PROCEDURE FORPPVAR(var: LIST);
(* formula pretty print variable. var is a variable; var is formated written
to the output stream. *)

PROCEDURE FORPPLVAR(lvar: LIST);
(* formula print lvar. L is an lvar object; lvar is formated written to the
output stream. *)


(******************************************************************************
*			      T E X   W R I T E                               *
******************************************************************************)

PROCEDURE FORTEXW(phi: LIST; bbtexw:PROCP1);
(* formula tex write. phi is a formula; bbtexw a bb-procedure to write a
bb-formula in tex style to the outputstream; this procedure writes a formula
in tex style to the outputstream. *)

PROCEDURE FORTEXWVAR(var: LIST);
(* formula tex write variable. var is a variable; this procedure writes var in
tex style to the output stream. *)

PROCEDURE FORTEXWLVAR(lvar: LIST);
(* tex write list of varaiables. lvar is an lvar object; this procedure writes
all variables in lvar in tex style to the outputstream. *)

PROCEDURE FORPREAD(bbread:PROCF0):LIST;
(* formula prefix read. bbread is a bb-procedure to read a bb.formula from 
the input stream. FORPREAD reads a formula in prefix notation from the 
input stream and returns the read formula. *)

PROCEDURE KEYREAD(): LIST;
(*key read. A keyword or a symbol for a keyword is read. A keyword is a string
of letters ore a string of special characters. The keyword or the symbol is 
also terminated by the characters "()[]{}".
This procedure is based on the procedure SREAD1 from the module MASSYM2 *)

PROCEDURE FORRDVAR():LIST;
(* formula read variable. A description of a variable is read from the input 
stream. *)

PROCEDURE FORRDLVAR():LIST;
(* formula read list of variables. One variable or a list of variables are 
read from the input stream. A LVAR-object is returned. *)

PROCEDURE FORIREAD(bbread:PROCF0):LIST;
(* formula infix read. bbread is a bb-procedure to read a bb.formula from the 
input stream. This procedure reads a formula in infix notation 
from the input stream and returns the read formula. *)

END MLOGIO.

(* -EOF- *)
