(* ----------------------------------------------------------------------------
 * $Id: massig.md,v 1.3 1995/12/16 13:37:38 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: massig.md,v $
 * Revision 1.3  1995/12/16 13:37:38  kredel
 * Fixed rcs comments.
 *
 * Revision 1.2  1995/12/16  13:11:21  kredel
 * Comments provided.
 *
 * Revision 1.1  1995/11/04  20:40:04  pesch
 * Renamed massignal.m? to massig.m? because of conflict with MASSIGNAL.m?
 * on certain OS.
 *
 * Revision 1.1  1995/09/12 17:22:50  pesch
 * Signal handling function are now declared in massignal.
 * Action has been changed according to ANSI C.
 * signal.* and massignal.* have been removed, the former because of
 * name clash with signal.h.
 *
 * ----------------------------------------------------------------------------
 *)

FOREIGN MODULE massig;

(* MAS Signal Handling Foreign Module. 
 * Definitions from <signal.h>: 
 *)

CONST rcsid = "$Id: massig.md,v 1.3 1995/12/16 13:37:38 kredel Exp $";
CONST copyright = "Copyright (c) 1995 Universitaet Passau";

CONST SIGMAX    = 63;

CONST	SIGHUP	=  1;	(* hangup, generated when terminal disconnects *)
CONST	SIGINT	=  2;	(* interrupt, generated from terminal special char *)
CONST	SIGQUIT	=  3;	(* ( * ) quit, generated from terminal special char *)
CONST	SIGILL	=  4;	(* ( * ) illegal instruction (not reset when caught)*)
CONST	SIGTRAP	=  5;	(* ( * ) trace trap (not reset when caught) *)
CONST	SIGABRT =  6;	(* ( * ) abort process *)
CONST   SIGEMT	=  7;	(* EMT intruction *)
CONST	SIGFPE	=  8;	(* ( * ) floating point exception *)
CONST	SIGKILL	=  9;	(* kill (cannot be caught or ignored) *)
CONST	SIGBUS	= 10;	(* ( * ) bus error (specification exception) *)
CONST	SIGSEGV	= 11;	(* ( * ) segmentation violation *)
CONST	SIGSYS	= 12;	(* ( * ) bad argument to system call *)
CONST	SIGPIPE	= 13;	(* write on a pipe with no one to read it *)
CONST	SIGALRM	= 14;	(* alarm clock timeout *)
CONST	SIGTERM	= 15;	(* software termination signal *)
CONST	SIGURG 	= 16;	(* (+) urgent contition on I/O channel *)
CONST	SIGSTOP	= 17;	(* (@) stop (cannot be caught or ignored) *)
CONST	SIGTSTP	= 18;	(* (@) interactive stop *)
CONST	SIGCONT	= 19;	(* (!) continue (cannot be caught or ignored) *)
CONST   SIGCHLD = 20;	(* (+) sent to parent on child stop or exit *)
CONST   SIGTTIN = 21;	(* (@) background read attempted from control terminal*)
CONST SIGTTOU   = 22;	(* (@) background write attempted to control terminal *)
CONST SIGIO	= 23;	(* (+) I/O possible, or completed *)
CONST SIGXCPU	= 24;	(* cpu time limit exceeded (see setrlimit()) *)
CONST SIGXFSZ	= 25;	(* file size limit exceeded (see setrlimit()) *)
CONST SIGMSG    = 27;	(* input data is in the HFT ring buffer *)
CONST SIGWINCH  = 28;	(* (+) window size changed *)
CONST SIGPWR    = 29;	(* (+) power-fail restart *)
CONST SIGUSR1   = 30;	(* user defined signal 1 *)
CONST SIGUSR2   = 31;	(* user defined signal 2 *)
CONST SIGPROF   = 32;	(* profiling time alarm (see setitimer) *)
CONST SIGDANGER = 33;	(* system crash imminent; free up some page space *)
CONST SIGVTALRM = 34;	(* virtual time alarm (see setitimer) *)
CONST SIGMIGRATE = 35;	(* migrate process (see TCF)*)
CONST SIGPRE	= 36;	(* programming exception *)
CONST SIGGRANT  = 60;   (* HFT monitor mode granted *)
CONST SIGRETRACT = 61;  (* HFT monitor mode should be relinguished *)
CONST SIGSOUND  = 62;   (* HFT sound control has completed *)
CONST SIGSAK    = 63;	(* secure attention key *)


TYPE Action = PROCEDURE(INTEGER); (* POSIX *)

VAR SIG_DFL, SIG_IGN, SIG_ACK, SIG_ERR: Action; 


PROCEDURE signal(s: INTEGER; h: Action): Action;
(* Set system signal handler. *)

PROCEDURE raise(s: INTEGER): INTEGER;
(* Raise signal s. *)

PROCEDURE sigblock(mask: INTEGER):INTEGER;
(* Block signals. *)

PROCEDURE sigsetmask(mask: INTEGER): INTEGER;
(* Set signal mask. *)

PROCEDURE SigMask(s: INTEGER): INTEGER;
(* Signal mask. *)

END massig.
(* -EOF- *)
