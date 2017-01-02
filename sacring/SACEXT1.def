(* ----------------------------------------------------------------------------
 * $Id: SACEXT1.md,v 1.2 1992/02/12 17:34:45 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACEXT1.md,v $
 * Revision 1.2  1992/02/12  17:34:45  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:15:24  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SACEXT1;

(* SAC Extensions 1 Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: SACEXT1.md,v 1.2 1992/02/12 17:34:45 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE LCONC(L: LIST): LIST; 
(*List concatenation.  L is a list (L sub 1 , ..., L sub n ),
n ge 0, such that each L sub i is a list.  M eq CONC(L sub 1 , ...,
L sub n ).  The lists L sub 1 , ..., L sub n are modified.*)


PROCEDURE LEQUAL(A,B: LIST): LIST; 
(*List equality.  A eq (A sub 1 , ..., A sub m ), m ge 0, and
B eq (B sub 1 , ..., B sub n ), n ge 0, are two lists.  b eq 1 if
for each a sub i there is at least one B sub j such that
A sub i eq B sub j, and for each B sub j there is at least
one A sub i with B sub j eq a sub i.  otherwise b eq 0.*)


PROCEDURE LMERGE(A,B: LIST): LIST; 
(*List merge.  A and B are lists of objects.  C is the result of
merging A and B.*)


END SACEXT1.

(* -EOF- *)
