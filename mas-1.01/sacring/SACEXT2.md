(* ----------------------------------------------------------------------------
 * $Id: SACEXT2.md,v 1.2 1992/02/12 17:34:46 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACEXT2.md,v $
 * Revision 1.2  1992/02/12  17:34:46  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:15:26  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SACEXT2;

(* SAC Extensions 2 Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: SACEXT2.md,v 1.2 1992/02/12 17:34:46 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE RNBCR(A,B: LIST;  VAR M,N,KL: LIST); 
(*Rational number binary common representation.  A and B are binary
rational numbers.  If both A eq 0 and B eq 0, then M eq N eq K eq 0.
If A eq 0, B ne 0, then M eq 0 and N and K are the unique integers
such that B eq N cdot 2 sup k with N odd.  If B eq 0, A ne 0, then
N eq 0 and M and K are the unique integers such that A eq
M cdot 2 sup K with M odd.  If A ne 0 and B ne 0, then M,N, and K
are the unique integers such that A eq M cdot 2 sup K and
B eq N cdot 2 sup K with at least one of M and N odd.*)


END SACEXT2.
(* -EOF- *)
