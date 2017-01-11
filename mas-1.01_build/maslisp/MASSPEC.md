(* ----------------------------------------------------------------------------
 * $Id: MASSPEC.md,v 1.3 1992/10/16 13:53:40 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASSPEC.md,v $
 * Revision 1.3  1992/10/16  13:53:40  kredel
 * Errors found by Mocka corrected
 *
 * Revision 1.2  1992/02/12  17:32:29  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:11:06  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASSPEC;

(* MAS Specification Definition Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST; 

CONST rcsid = "$Id: MASSPEC.md,v 1.3 1992/10/16 13:53:40 kredel Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE EVALUATE(X: LIST; VAR ENV: LIST): LIST;
(*Lisp evaluator. X is an S-expression, ENV is an environment. *)


END MASSPEC.



(* -EOF- *)
