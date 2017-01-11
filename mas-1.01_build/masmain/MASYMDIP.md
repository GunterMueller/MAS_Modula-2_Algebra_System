(* ----------------------------------------------------------------------------
 * $Id: MASYMDIP.md,v 1.3 1992/10/16 14:23:29 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASYMDIP.md,v $
 * Revision 1.3  1992/10/16  14:23:29  kredel
 * Change in DIPVDEF
 *
 * Revision 1.2  1992/02/12  17:32:57  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:12:00  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASYMDIP;
 
(* MAS Symbol to DIP Definition Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: MASYMDIP.md,v 1.3 1992/10/16 14:23:29 kredel Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



(* Procedure declarations. *)

PROCEDURE DIPVDEF(V: LIST): LIST;
(*DIP define distributive polynomial variable list. 
V is a variable list. The new variable list is returned. *)


PROCEDURE DIPTODEF(T: LIST): LIST;
(*DIP define distributive polynomial term order. 
V is a term order indicator. The old term order indicator 
is returned. *)


PROCEDURE SYM2DIP(T: LIST): LIST;
(*Symbol term to distributive polynomial. *)


PROCEDURE DIP2SYM(D: LIST): LIST;
(*Distributive polynomial to symbol term. *)


PROCEDURE TVARS(T: LIST): LIST;
(*Term variables. T is a term. The list of variables 
occuring in T is returned. *)



PROCEDURE DIRPFT(T, V: LIST): LIST; 
(*Distributive rational polynomial from term. T is a term,
V is a variable list. A distributive rational polynomial 
A in r variables, where r=length(V), r ge 0, is formed 
from term T. *)



PROCEDURE TFDIRP(A, V: LIST): LIST; 
(*Term from distributive rational polynomial. A is a distributive 
rational polynomial in r variables, where r=length(V), r ge 0,
V is a symbol list. A term T is formed from A. *)


PROCEDURE InitExternalsI;
(*Initialize external compiled interface procedures. *)


END MASYMDIP.


(* -EOF- *)
