(* ----------------------------------------------------------------------------
 * $Id: massig.mi,v 1.1 1995/11/04 20:40:06 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: massig.mi,v $
 * Revision 1.1  1995/11/04 20:40:06  pesch
 * Renamed massignal.m? to massig.m? because of conflict with MASSIGNAL.m?
 * on certain OS.
 *
 * Revision 1.1  1995/09/12 17:22:50  pesch
 * Signal handling function are now declared in massignal.
 * Action has been changed according to ANSI C.
 * signal.* and massignal.* have been removed, the former because of
 * name clash with signal.h.
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE massig;

(* MAS Signal Handling Implementation Module. *)

CONST rcsidi = "$Id: massig.mi,v 1.1 1995/11/04 20:40:06 pesch Exp $";
CONST copyrighti = "Copyright (c) 1995 Universitaet Passau";

BEGIN 
     SIG_DFL:=Action(0);
     SIG_IGN:=Action(1);
     SIG_ACK:=Action(4);
     SIG_ERR:=Action(-1);
END massig.

(* -EOF- *)
