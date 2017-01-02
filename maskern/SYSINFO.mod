(* ----------------------------------------------------------------------------
 * $Id: SYSINFO.mi,v 1.1 1994/11/28 20:32:53 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1994 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: SYSINFO.mi,v $
 * Revision 1.1  1994/11/28  20:32:53  dolzmann
 * New modules SYSINFO.md, SYSINFO.mi, LISTTOOLS.md, and LISTTOOLS.mi.
 * Makefile adapted.
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SYSINFO;
(* System Informations Implementation Module. *)

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

FROM MASBIOS	IMPORT	BLINES, SWRITE;
FROM MASELEM	IMPORT	GAMMAINT;
FROM MASSTOR	IMPORT	CELLS, GCC, GCCC, NU, TAU, TIME;
FROM SACLIST	IMPORT	AWRITE; 

CONST rcsidi = "$Id: SYSINFO.mi,v 1.1 1994/11/28 20:32:53 dolzmann Exp $";
CONST copyrighti = "Copyright (c) 1994 Universitaet Passau";

PROCEDURE SysInfoStart(VAR s:SYSINFO);
(* system information start. The variable s needs no initialization.
All data in s are lost.
Informations over the usage of system resources are stored. 
Use this procedure to start the recording of statistical data over system 
resource usage. *)
BEGIN
	WITH s DO
		Time:=TIME();
		GarbageCollections:=GCC;
		ReclaimedCells:=GCCC;
		IF Cells THEN UsedCells:=CELLS(); END;
		GarbageCollectionTime:=TAU;
	END;
END SysInfoStart;

PROCEDURE SysInfoStop(VAR s:SYSINFO);
(* system information stop. The variable s contains informations over system
resources. The usage of this resources between the time of the initialization 
of s and now are stored in s.
Use this procedure to stop the recording of statistical data over system 
resource usage. *)
BEGIN
	WITH s DO
		Time:=TIME()-Time;
		GarbageCollections:=GCC-GarbageCollections;
		ReclaimedCells:=GCCC-ReclaimedCells;
		IF Cells THEN UsedCells:=CELLS()-UsedCells; END;
		GarbageCollectionTime:=TAU-GarbageCollectionTime;
	END;
END SysInfoStop;

PROCEDURE SysInfoSum(a,b:SYSINFO; VAR s:SYSINFO);
(* system information sum. The variable s needs no initialization.
The sum of all data in a and b are stored in s. 
Use this procedure to join statistical data of two registration period. *)
BEGIN
	WITH s DO
		Time:=a.Time+b.Time;
		GarbageCollections:=a.GarbageCollections+b.GarbageCollections;
		ReclaimedCells:=a.ReclaimedCells+b.ReclaimedCells;
		IF Cells THEN UsedCells:=a.UsedCells+b.UsedCells END;
		GarbageCollectionTime:=a.GarbageCollectionTime+
						b.GarbageCollectionTime;
	END;
END SysInfoSum;

PROCEDURE SysInfoWrite(s: SYSINFO);
(* system information write. The variable s contains informations over system
resources. All informations in s are written out. 
Use this procedure to write out the statistical data of a registration *)
BEGIN
	WITH s DO
		SWRITE("SysInfo: Time: ");
		AWRITE(Time);
		IF GarbageCollections>0 THEN 
			SWRITE(" ms plus ");
			AWRITE(GarbageCollectionTime);
			SWRITE(" ms garbage collection time. ");
		ELSE
			SWRITE(" ms.");
		END;
		BLINES(0);
		IF Cells THEN
			SWRITE("         "); 
			SWRITE("Cells: ");
			AWRITE(UsedCells);
			SWRITE(" cells used of "); 
			AWRITE(NU);
			SWRITE(" cells.");
			BLINES(0);
		END;
		IF GarbageCollections>0 THEN 
			SWRITE("         ");
			SWRITE("GC: ");
			AWRITE(ReclaimedCells);
			SWRITE(" cells reclaimed in ");
			AWRITE(GarbageCollectionTime);
			SWRITE(" ms with ");
			AWRITE(GarbageCollections);
			IF GarbageCollections>1 THEN
				SWRITE(" gc's.");
			ELSE
				SWRITE(" gc.");
			END;
			BLINES(0);
		END;
	END;
END SysInfoWrite;

BEGIN
	Cells:=FALSE;
END SYSINFO.

(* -EOF- *)
