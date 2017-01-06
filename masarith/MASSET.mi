(* ----------------------------------------------------------------------------
 * $Id: MASSET.mi,v 1.1 1994/11/28 20:39:36 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1994 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: MASSET.mi,v $
 * Revision 1.1  1994/11/28  20:39:36  dolzmann
 * New modules MASCOMB.md, MASCOMB.mi, MASSET.md, and MASSET.mi.
 * Makefile adapted.
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASSET;
(* Mas Set Implementation Module. *)

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

FROM MASSTOR	IMPORT	ADV, COMP, FIRST, INV, LENGTH, LIST, LIST1, LISTVAR,
			RED, SFIRST, SIL, SRED;
FROM MASBIOS	IMPORT	BKSP, BLINES, CREAD, CREADB, CWRITE, DIBUFF, DIGIT,
			LETTER, LISTS, MASORD, SWRITE;
FROM SACLIST	IMPORT	ADV2, ADV3, ADV4, AWRITE, CCONC, CINV, CLOUT, COMP2,
			CONC, EQUAL, LIST10, LIST2, LIST3, LIST4, LIST5,
			MEMBER, SECOND, THIRD, FIRST2;
FROM MASSYM	IMPORT	ATOM, MEMQ;


CONST rcsidi = "$Id: MASSET.mi,v 1.1 1994/11/28 20:39:36 dolzmann Exp $";
CONST copyrighti = "Copyright (c) 1994 Universitaet Passau";

(******************************************************************************
* A set is a list containing the elements of the set.                         *
* Each element must not occur more than one times. Elements are               *
* arbitrary MAS objects. The comparison between elements is with EQUAL or =   *
* done. Procedures with the suffix Q use EQUAL the other procedures use       *
* =.                                                                          *
******************************************************************************)

PROCEDURE SetAdd(e,S:LIST):LIST;
(* set add. S is a set, e is an element. A set containing all elements of S
and the element e is returned. If e is not a element of the set S, e is the
first element in the list representing S. *)
BEGIN
	IF MEMQ(e,S) THEN
		RETURN S;
	ELSE
		RETURN COMP(e,S);
	END;
END SetAdd; 

PROCEDURE SetAddQ(e,S:LIST):LIST;
(* set add equal. S is a set, e is an element. 
A set containing all elements of S
and the element e is returned. If e is not a element of the set S, e is the
first element in the list representing S. *)
BEGIN
	IF MEMBER(e,S)=1 THEN
		RETURN S;
	ELSE
		RETURN COMP(e,S);
	END;
END SetAddQ; 

PROCEDURE SetUnion(S1,S2:LIST):LIST;
(* set union. S1 and S2 are sets. The union of S1 and S2 is returned. 
The elements of S2 not occuring in set1 are added to S1. *)
	VAR elem: LIST;
BEGIN
	WHILE S2<>SIL DO
		ADV(S2,elem,S2);
		S1:=SetAdd(elem,S1);
	END;
	RETURN S1 ;
END SetUnion;

PROCEDURE SetUnionQ(S1,S2:LIST):LIST;
(* set union equal. S1 and S2 are sets. The union of S1 and S2 is returned. 
The elements of S2 not occuring in set1 are added to S1. *)
	VAR elem: LIST;
BEGIN
	WHILE S2<>SIL DO
		ADV(S2,elem,S2);
		S1:=SetAddQ(elem,S1);
	END;
	RETURN S1 ;
END SetUnionQ;

PROCEDURE SetElementP(e,S:LIST):BOOLEAN;
(* set element predicate. e is an element, S is a set. 
SetElementP returns true iff e is a element of S *)
BEGIN
	RETURN MEMQ(e,S);
END SetElementP;

PROCEDURE SetElementPQ(e,S:LIST):BOOLEAN;
(* set element predicate equal. e is an element, S is a set. 
SetElementP returns true iff e is a element of S *)
BEGIN
	RETURN MEMBER(e,S)=1;
END SetElementPQ;

PROCEDURE SetMinus(e,S:LIST):LIST;
(* set minus. e is an element. S is a set. If e is an element of the set
S then a set containing all elements of S except of the element e is returned.
Otherwise the set S is returned. S is modified to build the result. *)
	VAR last,elem,SP,SPP: LIST;
BEGIN
	IF FIRST(S)=e THEN RETURN RED(S); END;
	last:=S;
	SP:=S;
	WHILE SP<>SIL DO 
		ADV(SP,elem,SPP);
		IF elem=e THEN
			SRED(last,SPP);
			RETURN S;
		END;
		last:=SP;
		SP:=SPP;
	END;
	RETURN S;
END SetMinus;

PROCEDURE SetMinusQ(e,S:LIST):LIST;
(* set minus equal. e is an element. S is a set. If e is an element of the set
S then a set containing all elements of S except of the element e is returned.
Otherwise the set S is returned. S is modified to build the result. *)
	VAR last,elem,SP,SPP: LIST;
BEGIN
	IF EQUAL(FIRST(S),e)=1 THEN RETURN RED(S); END;
	last:=S;
	SP:=S;
	WHILE SP<>SIL DO 
		ADV(SP,elem,SPP);
		IF EQUAL(elem,e)=1 THEN
			SRED(last,SPP);
			RETURN S;
		END;
		last:=SP;
		SP:=SPP;
	END;
	RETURN S;
END SetMinusQ;

PROCEDURE SetMinusC(e,S:LIST):LIST;
(* set minus constructive. 
e is an element. S is a set. If e is an element of the set
S then a set containing all elements of S except of the element e is returned.
Otherwise the set S is returned. *)
	VAR result,elem: LIST;
BEGIN
	WHILE S<>SIL DO 
		ADV(S,elem,S);
		IF elem<>e THEN
			result:=COMP(elem,result);
		END;
	END;
	RETURN INV(result);
END SetMinusC;

PROCEDURE SetMinusCQ(e,S:LIST):LIST;
(* set minus constructive equal. 
e is an element. S is a set. If e is an element of the set
S then a set containing all elements of S except of the element e is returned.
Otherwise the set S is returned. *)
	VAR result,elem: LIST;
BEGIN
	WHILE S<>SIL DO 
		ADV(S,elem,S);
		IF MEMBER(elem,e)=0 THEN
			result:=COMP(elem,result);
		END;
	END;
	RETURN INV(result);
END SetMinusCQ;


PROCEDURE SetComplement(S1,S2:LIST):LIST;
(* set complement. S1 and S2 are sets.
The complement of S1 with respect to S2 is returned. *)
	VAR e,result:LIST;
BEGIN
	result:=SIL;
	WHILE S2<>SIL DO
		ADV(S2,e,S2);
		IF NOT MEMQ(e,S1) THEN
			result:=COMP(e,result);
		END;
	END;
	RETURN INV(result);
END SetComplement;

PROCEDURE SetComplementQ(S1,S2:LIST):LIST;
(* set complement. S1 and S2 are sets.
The complement of S1 with respect to S2 is returned. *)
	VAR e,result:LIST;
BEGIN
	result:=SIL;
	WHILE S2<>SIL DO
		ADV(S2,e,S2);
		IF MEMBER(e,S1)=0 THEN
			result:=COMP(e,result);
		END;
	END;
	RETURN INV(result);
END SetComplementQ;

END MASSET.
