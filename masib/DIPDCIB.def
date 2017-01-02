(* ----------------------------------------------------------------------------
 * $Id: DIPDCIB.md,v 1.1 1995/10/12 14:44:48 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPDCIB.md,v $
 * Revision 1.1  1995/10/12 14:44:48  pesch
 * Diplomarbeit Rainer Grosse-Gehling.
 * Involutive Bases.
 * Slightly edited.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DIPDCIB;

(* DIP Decompositional Involutive Bases Definition Module. *)

FROM MASSTOR IMPORT LIST;

CONST rcsidi = "$Id: DIPDCIB.md,v 1.1 1995/10/12 14:44:48 pesch Exp $";
CONST copyrighti = "Copyright (c) 1995 Universitaet Passau";

PROCEDURE SetDCIBopt(options: LIST);
(* Set decompositional involutive base options.
   Input: a list of max. 4 options in the order: TraceLevel, DecomProc,
   VarOrd, Depth of tree. *)

PROCEDURE SetDCIBTraceLevel(TL: INTEGER);
(* Set Decompositional involutive base Trace Level.
   Input: an integer 0<= TL <= 3, 
   0: default, no output, 
  >0: output of time,
  >1: output of messages about tree of computation,
  >2: detailed messages about tree of computation. *)

PROCEDURE SetDCIBDecomp(DCP: INTEGER);
(* Set decompositional involutive base decomposition.
   Set the procedure which is used for polynomial decomposition.
   1: complete factorisation
   2: squarefree decomposition  *)

PROCEDURE SetDCIBVarOrdOpt(VOO: INTEGER);
(* Set decompositional involutive base variable order option.
  VOO is an integer with meaning:
  0: do not optimize,
  1: optimize at factorization *)

PROCEDURE SetDCIBdepth(d: INTEGER);
(* Set decompositional involutive base depth of tree.
   Input: an integer with
   <0: unrestricted growth of tree
    0: no computation possible,
   >0: depth of tree is restricted through d *)

PROCEDURE InvolutiveBases(G, V: LIST): LIST; 
(* Involutive Bases.
   G is a list of polynomials in distributive representation
   over an arbitrary domain,
   returns a list (IB1,...,IBk) of involutive bases,
   where Z(G) = Z(IB1) v ... v Z(IBk). *)

PROCEDURE DILNFJ(H,G: LIST): INTEGER;
(* Distributive Polynomial List normalform in the sense of Janet.
   H,G are distributive polynomial lists,
   returns 0 if each polynomial in H is Janet-reducible to 0 modulo G,
   1 else. *)

PROCEDURE IBLWR(PP,V: LIST);
(* Involutive bases list write.
   PP is a list of involutive bases in distributive representation.
   V is a variable list *)

PROCEDURE DecCounter(VAR counter: LIST; VAR length_of_counter: INTEGER);
(* Decrement counter.
   counter is a list of integers, the first element of counter is removed *)

PROCEDURE IncCounter(VAR counter: LIST; VAR loc: INTEGER; add: INTEGER);
(* Increment counter.
   Increment the first entry of the counter list or append a new element.
   Input: counter: a list of integers, 
          add = 0: append a new element and increment counterlength loc, or
          add>0: increment the first element by add *)

PROCEDURE CounterWR(counter: LIST);
(* Counter Write. 
   write the given list counter as the number of a reached node *)

END DIPDCIB.

(* -EOF- *)
