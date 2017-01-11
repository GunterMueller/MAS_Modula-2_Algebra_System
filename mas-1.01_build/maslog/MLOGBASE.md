(* ----------------------------------------------------------------------------
 * $Id: MLOGBASE.md,v 1.2 1994/11/28 21:04:12 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: MLOGBASE.md,v $
 * Revision 1.2  1994/11/28  21:04:12  dolzmann
 * New revision of the MASLOG system: New functions and bug fixes of old one.
 *
 * Revision 1.1  1993/12/17  17:12:12  dolzmann
 * MASLOG is divided into three parts. (MLOGBASE, MLOGIO, MASLOG)
 * Additional input procedures are added.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MLOGBASE;
(* Maslog Base Definition Module. *)

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

FROM MASSTOR IMPORT LIST;

(******************************************************************************
*                       T Y P E   D E F I N I T I O N S                       *
******************************************************************************)

TYPE PROCFB1=PROCEDURE(LIST):BOOLEAN;
TYPE PROCFB2=PROCEDURE(LIST, LIST):BOOLEAN;

(******************************************************************************
*                              C O N S T A N T S                              *
******************************************************************************)

CONST rcsid = "$Id: MLOGBASE.md,v 1.2 1994/11/28 21:04:12 dolzmann Exp $";
CONST copyright = "Copyright (c) 1993 Universitaet Passau";

(******************************************************************************
*                       G L O B A L   V A R I A B L E S                       *
******************************************************************************)


VAR ET, VEL, NON, VERUM, FALSUM, EXIST, FORALL, 	(* symbols for	*)
	TVAR, REP, IMP, EQUIV, ANTIV, XOR, LVAR: LIST;	(* keywords.	*)

VAR ANY, BOOL: LIST;	(* Special identifier in VARTAB *)

(******************************************************************************
*			 B A S I C   R O U T I N E S                          *
******************************************************************************)

PROCEDURE FORGOP(phi: LIST): LIST;
(* formula get operation. phi is a formula; the operation keyword of the
formula phi is returned.*)

PROCEDURE FORGARGS(phi: LIST): LIST;
(* formula get arguments. phi is a formula; the arguments of the top level
operation of the formula phi are returned. You must not apply FORGARGS to
formulas without arguments! *)

PROCEDURE FORGLVAR(lvar: LIST): LIST;
(* formula get list of variables. lvar is an object that describes a list of
variables; FORGLVAR returns a list of all variables in lvar.  *)

PROCEDURE FORPFOR(phi: LIST; VAR op: LIST; VAR args: LIST);
(* formula parse formula. phi is a formula; FORPFOR returns in op the top
level operation symbol of phi and in args the arguments of the operation op.
*)

PROCEDURE FORPARGS(phi: LIST; VAR first, red: LIST);
(* formula parse arguments. phi is an object that describes a list of
arguments of an operation; FORPARGS returns in first the 1st argument of the
list and in red the list of all following arguments. *)

PROCEDURE FORPUNOP(phi: LIST; VAR op, arg: LIST);
(* formula parse unary operation. phi is a unary operation. The operator
symbol op and the argument arg are returned. *)

PROCEDURE FORPBINOP(phi: LIST; VAR op, first, second: LIST);
(* formula parse binary operation. phi is a binary operation. The operator
symbol op and the arguments first and second are returned. *)

PROCEDURE FORPUNOPA(arglist: LIST; VAR arg: LIST);
(* formula parse unary operation argument. arglist is a list containing the
argument of a unary operator; FORPUNOPA returns in arg the arguments *)

PROCEDURE FORPBINOPA(red: LIST; VAR first, second: LIST);
(* formula parse binary operation argument. red is a list of the arguments of
a binary operator; FORPBINOPA returns in first the 1st and in second the 2nd
argument.  *)

PROCEDURE FORPQUANT(phi: LIST; VAR quant, vars, formula: LIST);
(* formula parse quantifier. phi is a quantified formula; FORPQUANT returns in
quant the quantifier of the formula phi, in vars the list of the bound
variables (as an lvar object) and in formula the formula phi without
quantifier. *)

PROCEDURE FORPQUANTA(red: LIST; VAR lvar, formula: LIST);
(* formula parse quantifier arguments. red is the reductum of a quantified
formula (e.g returned from FORPFOR); FORPQUANTA returns in lvar a list of all
quantified variables as an lvar object and in formula the formula without
quantifier.  *)

PROCEDURE FORPLVAR(lvar: LIST; VAR varlist: LIST);
(* formula parse list of variables. lvar is an object that describes a list of
variables; the list of all variables in lvar is returned in varlist. *)

PROCEDURE FORPVAR(var: LIST; VAR name, sort: LIST);
(* formula parse variable. phi is a variable; FORPVAR returns in name the name
and in sort the sort of var. *)

PROCEDURE FORPVARA(red: LIST; VAR name, sort:LIST);
(* formula parse variable arguments. red is the reductum of a variable (e.g.
returned from FORPFOR); FORPVARA returns in name the name and in sort the sort
of the variable. *)

PROCEDURE FORMKFOR(op,args:LIST):LIST;
(* formula make formula. op is a operation symbol; args a list of arguments;
the formula op(arg1,arg2,...) is returned, if args=(arg1,arg2,...).  You can
generate constants with this function, too. *)

PROCEDURE FORMKCNST(cnst: LIST):LIST;
(* formula make constant, i.e. a function with 0 arguments. cnst is a
constant; the formula 'cnst()' is returned *)

PROCEDURE FORMKUNOP(op,arg:LIST):LIST;
(* formula make unary operation. op is a operation symbol, arg is a argument;
the formula op(arg) is returned. *)

PROCEDURE FORMKBINOP(op,arg1,arg2:LIST): LIST;
(* formula make binary operation. op is the operation symbol, arg1, arg2 are
the arguments; the formula op(arg1,arg2) is returned. *)

PROCEDURE FORMKVAR(name,sort:LIST):LIST;
(* formula make variable. name is the name, sort the sort of the variable; an
object that describes the variable is returned. *)

PROCEDURE FORMKLVAR(vars:LIST):LIST;
(* formula make list of variables. vars is a list of the form (var1,
var2,...); an lvar object that represents the list of variables in vars is
returned. *)

PROCEDURE FORMKQUANT(quant,vars,formula:LIST):LIST;
(* formula make quantifier. quant is the quantifier symbol, vars is a list of
variables, and formula the bound formula; the formula 'quant vars: formula'
is returned. *)

PROCEDURE FORTST(L: LIST; bbtst:PROCFB1):BOOLEAN;
(* formula test. L is a list, bbtst a bb-procedure to test whether a list
represents a bb-formula or not; FORTST returns TRUE, if and only if L
represents a formula. *)

PROCEDURE FORISVAR(L: LIST):BOOLEAN;
(* formula is variable. L is a list; FORISVAR returns TRUE if and only if L
represents a variable. (The type of the variable is not checked.)  *)

PROCEDURE FORISBOOLVAR(L: LIST):BOOLEAN;
(* formula is boolean variable. L is a list; FORISBOOLVAR returns true if and
only if L represents a boolean variable *)

PROCEDURE FORISLVAR(L: LIST): BOOLEAN;
(* formula is variable list. L is a list; FORISLVAR returns TRUE if and only
if L represents an lvar-object. *)

(******************************************************************************
*                      I S   A T O M I C   F O R M U L A                      *
******************************************************************************)

PROCEDURE FORISATOM(phi: LIST): BOOLEAN;
(* formula is atomic formula. phi is a formula, FORISATOM returns true, if and
only if phi is an atomic formula. An atomic formula is either VERUM or FALSUM
or a bb-formula or a variable of type bool. *)

PROCEDURE FORISBBFOR(phi: LIST):BOOLEAN;
(* formula is black-box formula. phi is a formula. TRUE is returned iff
phi is a black-box formula. *)

(******************************************************************************
*                                 V A R T A B                                 *
******************************************************************************)

PROCEDURE FORVTSTORE():LIST;
(* formula variable table store. The actual VARTAB is returned. *)

PROCEDURE FORVTRESTORE(vt: LIST):LIST;
(* formula variable table restore. Vt is a variable table. 
The actual VARTAB is set to the value of vt. The old value of VARTAB is 
returned. *)

PROCEDURE FORVTENTER(sym: LIST):LIST;
(* formula variable table enter. Sym is a CLIST. 
The symbol with print name sym is entered in 
the actual variable table, if no symbol with name sym exists. 
The unique identifier is returned. 
*)

PROCEDURE FORVTGET(id: LIST): LIST;
(* formula variable table get. The clist of the 
name of the symbol with identifier id is 
returned. If no symbol with identifier id exists, then 
SIL is returned. *)

END MLOGBASE.

(* -EOF- *)
