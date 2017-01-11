IMPLEMENTATION MODULE MLMLDEMO;

(* ----------------------------------------------------------------------------
 * $Id: MLMLDEMO.mi,v 1.2 1993/12/17 17:38:55 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: MLMLDEMO.mi,v $
 * Revision 1.2  1993/12/17  17:38:55  dolzmann
 * Adapted to the divided MASLOG.
 *
 * Revision 1.1  1993/07/13  14:45:31  dolzmann
 * The configuration-files of MASLOG and MLDEMO.
 *
 * ----------------------------------------------------------------------------
 *)

(******************************************************************************
*	   M A S L O A D   M A S L O G    D E M O N S T R A T I O N	      *
*-----------------------------------------------------------------------------*
* Author:   Andreas Dolzmann                                                  *
* Language: Modula II (mtc or mocka are possible)                             *
* System:   Program for the computer algebra system MAS by Heinz Kredel.      *
* Remark:   This module requires the MASLOG-System.                           *
* Abstract: This is the configuration module for MLDEMO. MLDEMO is a example  *
*           example apllication for MASLOG.                                   *
******************************************************************************)

FROM MLDEMO	IMPORT 	MLDTST, MLDMKPOS, MLDMKPOS1, MLDSMPL, MLDPPRT, 
			MLDTEXW, MLDMKDNF, MLDMKCNF, MLDSUBSTVAR, MLDMKPRENEX,
			MLDPREPQE, MLDCONTVAR, MLDCONTBDVAR, MLDAPPLYAT,
			MLDMKVD,MLDPREAD,MLDIREAD;

FROM MASLISPU 	IMPORT 	Compiledp0, Compiledp1, Compiledf1, Compiledf2,
     			Compiledf3, Compiledp2, Compiledf0;

CONST rcsidi = "$Id: MLMLDEMO.mi,v 1.2 1993/12/17 17:38:55 dolzmann Exp $";
CONST copyrighti = "Copyright (c) 1993 Universitaet Passau";

PROCEDURE InitExternalsMLDEMO();
(* Initialize externals maslog demonstration procedures. *)
BEGIN
	Compiledf1(MLDMKPOS,"MLDMKPOS");
	Compiledf2(MLDMKPOS1,"MLDMKPOS1");
	Compiledf1(MLDSMPL,"MLDSMPL");
	Compiledf1(MLDTST,"MLDTST");
	Compiledp1(MLDPPRT,"MLDPPRT");
	Compiledp1(MLDTEXW,"MLDTEXW");
	Compiledf1(MLDMKDNF,"MLDMKDNF");
	Compiledf1(MLDMKCNF,"MLDMKCNF");
	Compiledf3(MLDSUBSTVAR,"MLDSUBSTVAR");
	Compiledf2(MLDMKPRENEX,"MLDMKPRENEX");
	Compiledf1(MLDPREPQE,"MLDPREPQE");
	Compiledf2(MLDCONTVAR,"MLDCONTVAR");
	Compiledf2(MLDCONTBDVAR,"MLDCONTBDVAR");
	Compiledf1(MLDAPPLYAT,"MLDAPPLYAT");
	Compiledf1(MLDMKVD,"MLDMKVD");
	Compiledf0(MLDPREAD,"MLDPREAD");
	Compiledf0(MLDIREAD,"MLDIREAD");
END InitExternalsMLDEMO;

END MLMLDEMO.

(* -EOF- *)