(* ----------------------------------------------------------------------------
 * $Id: clock.md,v 1.2 1995/12/16 13:11:20 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: clock.md,v $
 * Revision 1.2  1995/12/16 13:11:20  kredel
 * Comments provided.
 *
 * Revision 1.1  1995/03/06  16:28:39  pesch
 * New function ClocK returns milliseconds of the processes cpu-time (was no
 * longer available in new reuse library).
 *
 * ----------------------------------------------------------------------------
 *)

FOREIGN MODULE clock;
(* clock Foreign Module. *)

PROCEDURE ClocK(): LONGINT;
(* ClocK returns milliseconds of the processes cpu-time. *)

END clock.
(* -EOF- *)




