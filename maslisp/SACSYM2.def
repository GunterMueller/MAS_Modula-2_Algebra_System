(* ----------------------------------------------------------------------------
 * $Id: SACSYM2.md,v 1.2 1992/02/12 17:32:36 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACSYM2.md,v $
 * Revision 1.2  1992/02/12  17:32:36  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:11:13  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SACSYM2;

(* SAC Symbol 2 Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: SACSYM2.md,v 1.2 1992/02/12 17:32:36 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE STBAL(L,n: LIST): LIST;
(*Symbol tree balance. L is an alphabetical list of n symbol-tree 
nodes (n gt 0), out of which a balanced binary tree S is constructed. *)


PROCEDURE STBALS(VAR A: ARRAY OF LIST; l, r: INTEGER): INTEGER;
(*Symbol tree balance subroutine. The array A contains symbol-tree
nodes in alphabetical order. The binary tree of the symbols in
A[l..r] is constructed and A[m] is its root. *)


PROCEDURE STNLST(T: LIST; VAR L,n: LIST);
(*Symbol tree nodes list. T is a non-empty symbol tree.
L is the list of its nodes in alphabetical order of the 
corresponding symbols and n the number of nodes. This algorithm
is normally used for creating the data as required for STBAL. *)


PROCEDURE SSYTBAL;
(*System symbol tree balance. SYMTB is balanced. *)


END SACSYM2.





(* -EOF- *)
