(* ----------------------------------------------------------------------------
 * $Id: RQEPRRC.md,v 1.1 1994/11/28 21:10:05 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1994 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: RQEPRRC.md,v $
 * Revision 1.1  1994/11/28  21:10:05  dolzmann
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

DEFINITION MODULE RQEPRRC;
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

FROM MASLISPU	IMPORT	PROCF1, PROCF2, PROCF3, PROCP1;
FROM MASSTOR	IMPORT	LIST;

CONST rcsid = "$Id: RQEPRRC.md,v 1.1 1994/11/28 21:10:05 dolzmann Exp $";
CONST copyright = "Copyright (c) 1994 Universitaet Passau";

TYPE RQEOPTIONS=
	RECORD
		TraceLevel: INTEGER;
		DimensionZeroOnly: BOOLEAN;
	END;
	
VAR RqeOpt: RQEOPTIONS; 

VAR PolFmt: 
	RECORD
		AllVars:     LIST; (* All variables occuring somewhere. *)
		BoundVars:   LIST; (* Variables bound by a quantifier.  *)
		FreeVars:    LIST; (* The complement of BoundVars.      *) 
		Permutation: LIST; (* A permutation vector.            *)
	END;
	
(* This global variable holds information over the actual polynomial ring  
used for the representation of terms of an orderd ring. 
The entry AllVars is a list off all variables occuring in the polynomials
in the order of VALIS of the input polynomials. 
The entry BoundVars contains the list off all bound variables.  
The entry FreeVars contains the complement off BoundVars with respect
to AllVars.
The entry Permutation contains a permutation vector. This variable 
describes the permutation of the list AllVars to achive a variable 
list in which FreeVars occur first. *)

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

PROCEDURE RQEOPTWR();
(* real quantifier elimination option write. 
The actual options are written to the output stream. *)

PROCEDURE RQEOPTSET(opt:LIST):LIST;
(* real quantifier elimination options set. 
opt is a list of options. 
The first element of opt is the trace level. 
The second element of opt is a flag. If this flag is true, then 
partial elimination of zero dimensional ideals are done. Otherwise full
quantifier elimination is done.
The old option list is returned. *)

END RQEPRRC.
(* -EOF- *)

