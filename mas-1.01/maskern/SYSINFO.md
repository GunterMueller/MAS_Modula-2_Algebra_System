(* ----------------------------------------------------------------------------
 * $Id: SYSINFO.md,v 1.1 1994/11/28 20:32:52 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1994 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: SYSINFO.md,v $
 * Revision 1.1  1994/11/28  20:32:52  dolzmann
 * New modules SYSINFO.md, SYSINFO.mi, LISTTOOLS.md, and LISTTOOLS.mi.
 * Makefile adapted.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SYSINFO;
(* System Informations Definition Module. *)

(******************************************************************************
*		    S Y S T E M   I N F O R M A T I O N	S	      	      *
*-----------------------------------------------------------------------------*
* Author:   Andreas Dolzmann                                                  *
* Language: Modula II                                                         *
* System:   This program is written for the computer algebra system MAS by    *
*           Heinz Kredel.                                                     *
* Remark:   Only mas kernel algorithms are used.                              *
*           The computation of the number of used cells is time expensive.    *
*           So the number of used cells is not reported normally.             *
* Abstract: This module implements procedures for system resource statistics. *
*           It uses the type SYSINFO to store the information over the        *
*           resources. It is possible to record statistical dates on one      *
*           time and print theses data later.                                 *
******************************************************************************)

FROM MASELEM	IMPORT	GAMMAINT;
FROM MASSTOR	IMPORT	LIST;

TYPE SYSINFO = 
	RECORD
		GarbageCollections:	GAMMAINT; 
		ReclaimedCells:		GAMMAINT; 
		Time: 			GAMMAINT;	
		UsedCells:		GAMMAINT;
		GarbageCollectionTime:	GAMMAINT;
	END; 

CONST rcsid = "$Id: SYSINFO.md,v 1.1 1994/11/28 20:32:52 dolzmann Exp $";
CONST copyright = "Copyright (c) 1994 Universitaet Passau";

VAR Cells: BOOLEAN; (* If true, report cells statistics. *)

PROCEDURE SysInfoStart(VAR s:SYSINFO);
(* system information start. The variable s needs no initialization.
All data in s are lost.
Informations over the usage of system resources are stored. 
Use this procedure to start the recording of statistical data over system 
resource usage. *)

PROCEDURE SysInfoStop(VAR s:SYSINFO);
(* system information stop. The variable s contains informations over system
resources. The usage of this resources between the time of the initialization 
of s and now are stored in s.
Use this procedure to stop the recording of statistical data over system 
resource usage. *)

PROCEDURE SysInfoSum(a,b:SYSINFO; VAR s:SYSINFO);
(* system information sum. The variable s needs no initialization.
The sum of all data in a and b are stored in s. 
Use this procedure to join statistical data of two registration period. *)

PROCEDURE SysInfoWrite(s: SYSINFO);
(* system information write. The variable s contains informations over system
resources. All informations in s are written out. 
Use this procedure to write out the statistical data of a registration *)

END SYSINFO.
