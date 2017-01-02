(* ----------------------------------------------------------------------------
 * $Id: MASBIOSU.md,v 1.2 1992/02/12 17:31:51 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASBIOSU.md,v $
 * Revision 1.2  1992/02/12  17:31:51  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:10:06  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASBIOSU;

(* MAS BIOS Utility Definition Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: MASBIOSU.md,v 1.2 1992/02/12 17:31:51 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



(* Procedure declarations. *)

PROCEDURE INP(A: LIST): LIST;
(*Input. Set input unit to stream A, A is an SAC-2 character list. *)


PROCEDURE OUT(A: LIST): LIST;
(*Output. Set output unit to stream A, A is an SAC-2 character list. *)


PROCEDURE SHUT(A: LIST): LIST;
(*Shut. Close stream A, A is an SAC-2 character list. *)


PROCEDURE EDIT(A: LIST): LIST;
(*Edit. Call editor for file A, A is an SAC-2 character list. *)


PROCEDURE DOS(A: LIST): LIST;
(*DOS. Call DOS program with parameters. A is an SAC-2 character list. *)


PROCEDURE CLTIS(A: LIST);
(*Character list to input stream. A is an SAC-2 character list. *)
                       

END MASBIOSU.


(* -EOF- *)
