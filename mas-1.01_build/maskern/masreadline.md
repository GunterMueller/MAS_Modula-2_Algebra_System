(* ----------------------------------------------------------------------------
 * $Id: masreadline.md,v 1.1 1995/03/06 16:35:08 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: masreadline.md,v $
 * Revision 1.1  1995/03/06  16:35:08  pesch
 * New function masReadL to replace Readl(StdInput, ). Will use the GNU readline
 * library if available. A history file .mashistory or ~/.mashistory if kpathsea
 * is available will be kept.
 *
 * ----------------------------------------------------------------------------
 *)

FOREIGN MODULE masreadline;
(* readline Foreign Module. *)

FROM Strings IMPORT tString;

PROCEDURE masReadL(VAR s: tString);
(* MAS Read Line.
Reads a line from StdInput and returns it in s using the GNU
readline library. *)

END masreadline.
(* -EOF- *)




