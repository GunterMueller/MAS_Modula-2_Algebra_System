(* ----------------------------------------------------------------------------
 * $Id: MASSYM.md,v 1.2 1992/02/12 17:32:31 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASSYM.md,v $
 * Revision 1.2  1992/02/12  17:32:31  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:11:07  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASSYM;

(* MAS Symbol Definition Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST;


VAR NOSHOW: LIST;
CONST rcsid = "$Id: MASSYM.md,v 1.2 1992/02/12 17:32:31 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



(* Procedure declarations. *)

PROCEDURE ATOM(X: LIST): BOOLEAN;
(*Atom. Test if X is an atom. *)


PROCEDURE ELEMP(X: LIST): BOOLEAN;
(*Elementary Pointer. Test if X is an elementary SAC-2 structure. *)


PROCEDURE MEMQ(AL,L: LIST): BOOLEAN;
(*Membership test equal pointers.  a is an object, L a list. t=1 if 
the pointer or atom a occurs in L and otherwise t=0.*)


PROCEDURE OCCURQ(AL,L: LIST): BOOLEAN;
(*Occurs test equal pointers. a and L are objects. t=TRUE if 
the pointer or atom a occurs in L and otherwise t=FALSE. *)


PROCEDURE UREAD(): LIST;
(*Universal read. The next atom, symbol, string or list over atoms, 
strings and symbols is read and stored under L. Blanks may occur 
anywhere. Elements of a list may or may not be separated by a comma.*)


PROCEDURE UWRITE(L: LIST);
(*Universal write. L is an atom, symbol or a list over
atoms and symbols. L is written in the output stream,
followed by blines. *)


PROCEDURE UWRIT1(L: LIST);
(*Universal write, 1. subalgorithm. L is an atom, a symbol
or a list over atoms or symbols. L is written in the output
stream. *)


PROCEDURE UNIFY(A,B: LIST; VAR S: LIST): BOOLEAN;
(*Unification. A and B are objects. If there exists a 
most general unificator of A and B, then S is the list of 
substitutions. In this case TRUE is returned. If no unificator
exists, then FALSE is returned and S is undefined. *)


PROCEDURE GENARRAY(A: LIST): LIST;
(*Generate array reference symbol. S is a generated symbol. *)


PROCEDURE GENINDEX(A: LIST): LIST;
(*Generate index set. I is an index set. *)


PROCEDURE ARRAYDEC(A: LIST): LIST;
(*Generate array name declarations. A is an array reference. *)


END MASSYM.


(* -EOF- *)
