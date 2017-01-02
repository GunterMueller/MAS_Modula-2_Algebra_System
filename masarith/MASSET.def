(* ----------------------------------------------------------------------------
 * $Id: MASSET.md,v 1.2 1995/12/16 15:03:27 kredel Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: MASSET.md,v $
 * Revision 1.2  1995/12/16 15:03:27  kredel
 * Comments slightly edited.
 *
 * Revision 1.1  1994/11/28  20:39:35  dolzmann
 * New modules MASCOMB.md, MASCOMB.mi, MASSET.md, and MASSET.mi.
 * Makefile adapted.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASSET;
(* MAS Set Definition Module. *)

(******************************************************************************
*				 M A S S E T				      *
*-----------------------------------------------------------------------------*
* Author:   Andreas Dolzmann                                                  *
* Language: Modula II                                                         *
* System:   This program is written for the computer algebra system MAS by    *
*           Heinz Kredel.                                                     *
* Abstract: Implementation of procedures for the manipulation of sets.        *
*           Sets are only a special view of lists.                            *
******************************************************************************)

FROM MASSTOR	IMPORT	LIST;

TYPE SetRel=(subset,superset,setequal,setnorel); 

CONST rcsid = "$Id: MASSET.md,v 1.2 1995/12/16 15:03:27 kredel Exp $";
CONST copyright = "Copyright (c) 1994 Universitaet Passau";

(******************************************************************************
* A set is only a list containing the elements of the set. Elements are       *
* arbitrary MAS objects. The comparison between elements is with EQUAL or =   *
* done. Procedures with the suffix Q use EQUAL the other procedures use       *
* =                                                                           *
******************************************************************************)

PROCEDURE SetAdd(e,S:LIST):LIST;
(* Set add. S is a set, e is an element. A set containing all elements of S
and the element e is returned. If e is not a element of the set S, e is the
first element in the list representing S. *)

PROCEDURE SetAddQ(e,S:LIST):LIST;
(* Set add equal. S is a set, e is an element. 
A set containing all elements of S
and the element e is returned. If e is not a element of the set S, e is the
first element in the list representing S. *)

PROCEDURE SetUnion(S1,S2:LIST):LIST;
(* Set union. S1 and S2 are sets. The union of S1 and S2 is returned. 
The elements of S2 not occuring in set1 are added to S1. *)

PROCEDURE SetUnionQ(S1,S2:LIST):LIST;
(* Set union equal. S1 and S2 are sets. The union of S1 and S2 is returned. 
The elements of S2 not occuring in set1 are added to S1. *)

PROCEDURE SetElementP(e,S:LIST):BOOLEAN;
(* Set element predicate. e is an element, S is a set. 
SetElementP returns true iff e is a element of S *)

PROCEDURE SetElementPQ(e,S:LIST):BOOLEAN;
(* Set element predicate equal. e is an element, S is a set. 
SetElementP returns true iff e is a element of S *)

PROCEDURE SetMinus(e,S:LIST):LIST;
(* Set minus. e is an element. S is a set. If e is an element of the set
S then a set containing all elements of S except of the element e is returned.
Otherwise the set S is returned. S is modified to build the result. *)

PROCEDURE SetMinusQ(e,S:LIST):LIST;
(* Set minus equal. e is an element. S is a set. If e is an element of the set
S then a set containing all elements of S except of the element e is returned.
Otherwise the set S is returned. S is modified to build the result. *)

PROCEDURE SetMinusC(e,S:LIST):LIST;
(* Set minus constructive. 
e is an element. S is a set. If e is an element of the set
S then a set containing all elements of S except of the element e is returned.
Otherwise the set S is returned. *)

PROCEDURE SetMinusCQ(e,S:LIST):LIST;
(* Set minus constructive equal. 
e is an element. S is a set. If e is an element of the set
S then a set containing all elements of S except of the element e is returned.
Otherwise the set S is returned. *)

PROCEDURE SetComplement(S1,S2:LIST):LIST;
(* Set complement. S1 and S2 are sets.
The complement of S1 with respect to S2 is returned. *)

PROCEDURE SetComplementQ(S1,S2:LIST):LIST;
(* set complement. S1 and S2 are sets.
The complement of S1 with respect to S2 is returned. *)

END MASSET.
