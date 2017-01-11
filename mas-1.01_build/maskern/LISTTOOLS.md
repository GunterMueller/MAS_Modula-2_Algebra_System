(* ----------------------------------------------------------------------------
 * $Id: LISTTOOLS.md,v 1.1 1994/11/28 20:32:48 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1994 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: LISTTOOLS.md,v $
 * Revision 1.1  1994/11/28  20:32:48  dolzmann
 * New modules SYSINFO.md, SYSINFO.mi, LISTTOOLS.md, and LISTTOOLS.mi.
 * Makefile adapted.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE LISTTOOLS;
(* List Tools Definition Module. *)

FROM MASSTOR	IMPORT	LIST;

CONST rcsid = "$Id: LISTTOOLS.md,v 1.1 1994/11/28 20:32:48 dolzmann Exp $";
CONST copyright = "Copyright (c) 1994 Universitaet Passau";


PROCEDURE CLISTFA(atom:LIST):LIST;
(* character list from atom. 
The decimal printable representation of atom is returned as a character 
list. *)

PROCEDURE LIST6(a1,a2,a3,a4,a5,a6:LIST):LIST;
(* list of 6 elements. The list (a1,a2,...a6) is returned. *)

PROCEDURE LPAIRS(L:LIST):LIST;
(* list pairs. L=(l1,...ln) is a list. A list containing all lists (li,lj),
where li and lj are elements of L and i <> j is returned. *)

PROCEDURE LSRCHQ(a,L:LIST):LIST;
(* List search equal. 
a is an element, 
L is a list.
The first position of a in L is returned if a is member of L, 
otherwise 0 is returned. *)

PROCEDURE UPCASE(clist:LIST):LIST;
(* upcase character list. 
clist is a character list. All letters in clist are converted to upper case. 
The result is returned. *)


END LISTTOOLS.

(* -EOF- *)
