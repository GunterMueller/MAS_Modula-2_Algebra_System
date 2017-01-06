(* ----------------------------------------------------------------------------
 * $Id: SACSET.md,v 1.2 1992/02/12 13:19:19 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACSET.md,v $
 * Revision 1.2  1992/02/12  13:19:19  pesch
 * Moved CONST Definition to the right place.
 *
 * Revision 1.1  1992/01/22  15:08:22  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SACSET;

(* SAC Set Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: SACSET.md,v 1.2 1992/02/12 13:19:19 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE LBIBMS(L: LIST): LIST;
(*List of beta-integers bubble-merge sort.  L is an arbitrary list of
beta-integers, possibly with repetitions.  M is the result of sorting
L into non-decreasing order.  A combination of bubble-sort and merge-
sort is used.  The list L is modified to produce M.*)


PROCEDURE LBIBS(L: LIST);
(*List of beta-integers bubble sort.  L is an arbitrary list of
beta-integers, with possible repetitions.  L is sorted into
non-decreasing order by the bubble-sort method.  The list L, though not
its location, is modified.*)


PROCEDURE LBIM(L1,L2: LIST): LIST;
(*List of beta-integers merge.  L1 and L2 are arbitrary lists of
beta-integers in non-decreasing order.  L is the merge of L1 and L2.
L1 and L2 are modified to produce L.*)


PROCEDURE SCOMP(AL,L: LIST): LIST;
(*Set composition. a is a beta-integer, L is a set of beta-integers.
LP is the union of SET(a) and L. *)


PROCEDURE SDIFF(A,B: LIST): LIST;
(*Set difference.  A and B are sets of beta-integers.  C=A-B.*)


PROCEDURE SINTER(A,B: LIST): LIST;
(*Set intersection.  A and B are sets of beta-integers.  C is the
intersection of A and B.*)


PROCEDURE SUNION(A,B: LIST): LIST;
(*Set union.  A and B are sets of beta-integers.  C is the union of
A and B.*)


PROCEDURE USCOMP(AL,L: LIST): LIST;
(*Unordered set composition. a is an object, L is an unordered set.
LP is the union of SET(a) and L. *)
 

PROCEDURE USDIFF(A,B: LIST): LIST;
(*Unordered set difference.  A and B are unordered sets.  C is the
difference A-B.*)


PROCEDURE USINT(A,B: LIST): LIST;
(*Unordered set intersection.  A and B are unordered sets.  C is the
intersection of A and B.*)


PROCEDURE USUN(A,B: LIST): LIST;
(*Unordered set union.  A and B are unordered sets.  C is the union
of A and B.*)


END SACSET.


(* -EOF- *)
