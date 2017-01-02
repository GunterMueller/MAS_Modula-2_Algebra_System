(* ----------------------------------------------------------------------------
 * $Id: MASSTOR.md,v 1.3 1995/12/16 14:51:35 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASSTOR.md,v $
 * Revision 1.3  1995/12/16 14:51:35  kredel
 * Removed old Atari related comments.
 *
 * Revision 1.2  1992/02/12  17:31:56  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:10:14  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASSTOR;

(* MAS Storage Definition Module. *)



(* Import lists and Definitions *) 

FROM MASELEM IMPORT GAMMAINT;

FROM SYSTEM IMPORT ADDRESS;


TYPE LIST = GAMMAINT;


VAR BETA, BETA1, SIL: LIST;

    NU, GCC, GCCC, GCM, RHO,

    TAU, TAU0: GAMMAINT;

CONST rcsid = "$Id: MASSTOR.md,v 1.3 1995/12/16 14:51:35 kredel Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE ADV(L: LIST; VAR a, LP: LIST);
(*Advance.  L is a non-null list.  a=FIRST(L) and LP=RED(L). *)


PROCEDURE CELLS(): GAMMAINT;
(*Cells. Returns the used cells since storage initialization. *)


PROCEDURE CLOCK(): GAMMAINT;
(*Clock. Returns the current CPU clock reading in seconds. *)


PROCEDURE COMP(a,L: LIST): LIST;
(*Composition.  a is an object.  L is a list.  Returns the 
composition of a and L. *)


PROCEDURE DEQUE(L: LIST): LIST;
(*Dequeue.  L is a non empty queue representing list.  Returns a, the 
first object from the queue. L is updated. *)


PROCEDURE EMPTYQUE(M: LIST): BOOLEAN;
(*Empty Queue.  Tests if a queue is empty. *)


PROCEDURE ENQUE(a,L: LIST);
(*Enqueue.  a is an object.  L is a queue representing list. Appends a
to the quque L. *)


PROCEDURE FIRST(L: LIST): LIST;
(*First.  L is a non-null list.  a is the first element of L. *)


PROCEDURE NEWQUE(): LIST;
(*New Queue.  Returns a new empty queue. *)


PROCEDURE INV(L: LIST): LIST;
(*Inverse.  L is a list.  The inverse of L is returned.  The list L is
modified. *)


PROCEDURE LENGTH(L: LIST): GAMMAINT;
(*Length.  L is a list.  Returns length(L).*)


PROCEDURE LIST1(a: LIST): LIST;
(*List, 1 element.  a is an object.  L is the list (a). *)


PROCEDURE LISTVAR(VAR L: LIST);
(*List variable.  L is a list.  The address of L is made accessible
to the garbage collector. *)


PROCEDURE RED(L: LIST): LIST;
(*Reductum.  L is a non-null list.  Returns the reductum of L. *)


PROCEDURE SFIRST(L, a: LIST);
(*Set first.  L is a non-null list.  a is an object.  The first
element of L is changed to a. *)


PROCEDURE SRED(L, LP: LIST);
(*Set reductum.  L is a non-null list.  LP is a list.  The reductum
of L is changed to LP. *)


PROCEDURE TIME(): GAMMAINT;
(*Time. Returns the CLOCK minus the garbage collection time TAU.  *)


END MASSTOR.


(* -EOF- *)
