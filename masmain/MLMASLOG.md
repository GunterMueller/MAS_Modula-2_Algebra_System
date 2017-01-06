(* ----------------------------------------------------------------------------
 * $Id: MLMASLOG.md,v 1.2 1995/11/05 14:04:41 kredel Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: MLMASLOG.md,v $
 * Revision 1.2  1995/11/05  14:04:41  kredel
 * Added module comment
 *
 * Revision 1.1  1993/07/13  14:45:28  dolzmann
 * The configuration-files of MASLOG and MLDEMO.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MLMASLOG;

(* MAS Logic Configuration Implementation Module. *) 

(******************************************************************************
*			 M A S L O A D    M A S L O G			      *
*-----------------------------------------------------------------------------*
* Author:   Andreas Dolzmann                                                  *
* Language: MODULA II (mocka or mtc are possible)                             *
* System:   Program for the computer algebra system MAS by Heinz Kredel       *
* Remark:   Library maslog is used.                                           *
* Abstract: This is the configuration module for the MASLOG-System.           *
******************************************************************************)

FROM MASSTOR	IMPORT	LIST;

CONST rcsid = "$Id: MLMASLOG.md,v 1.2 1995/11/05 14:04:41 kredel Exp $";
CONST copyright = "Copyright (c) 1993 Universitaet Passau";

PROCEDURE InitExternalsML;
(* Initialze external compiled logic procedures. *)
	
END MLMASLOG.

(* -EOF- *)
