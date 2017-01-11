(* ----------------------------------------------------------------------------
 * $Id: MLPQSMPL.mi,v 1.4 1994/11/28 21:14:33 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: MLPQSMPL.mi,v $
 * Revision 1.4  1994/11/28  21:14:33  dolzmann
 * New functions of the polynomial equation systems.
 * New functions of the real quantifier elimination package.
 *
 * Revision 1.3  1994/05/19  10:29:03  rose
 * DIPAGB procedures added.
 *
 * Revision 1.2  1994/03/11  15:39:56  pesch
 * Additions for CGB, MASROOT and NNGB.
 *
 * Revision 1.1  1993/12/18  20:25:47  dolzmann
 * Configuration module for the PQSMPL-System.
 *
 * ----------------------------------------------------------------------------
 *)
 
IMPLEMENTATION MODULE MLPQSMPL;
(* Masload Polynomial Eqaution Simplify Implementation Module *)

(******************************************************************************
*		     M A S L O A D   P Q S I M P L I F Y		      *
*-----------------------------------------------------------------------------*
* Author:   Andreas Dolzmann                                                  *
* Language: Modula II                                                         *
* System:   This program is written for the computer algebra system MAS by    *
*           Heinz Kredel.                                                     *
* Remark:   Libraries maskern, maslisp, maslog, masdom, maspoly, ...          *
*           are used.                                                         *
* Abstract: The configuration module for the PQ-System.                       *
******************************************************************************)


FROM MASLISPU 	IMPORT 	Compiledp0, Compiledp1, Compiledf0, 
			Compiledf1, Compiledf2, 
     			Compiledf3, Compiledp2, Compiledp2v3;
			
FROM PQSMPL	IMPORT	PQCnfSimplify, PQDEMO, PQDnfSimplify, PQOPT, PQOPTWR,
			PQSCNF, PQSDNF;
					
CONST rcsidi = "$Id: MLPQSMPL.mi,v 1.4 1994/11/28 21:14:33 dolzmann Exp $";
CONST copyrighti = "Copyright (c) 1993 Universitaet Passau";


PROCEDURE InitExternalsPQSMPL();
(* initialize external compiled PQS-procedures. *)
BEGIN
	(* from PQSMPL import *)	
	Compiledf1(PQSCNF,"PQSCNF");
	Compiledf1(PQSDNF,"PQSDNF");
	Compiledf1(PQCnfSimplify,"PQCnfSimplify");
	Compiledf1(PQDnfSimplify,"PQDnfSimplify");
	Compiledf1(PQOPT,"PQOPT");
	Compiledp0(PQOPTWR,"PQOPTWR");	
	Compiledp0(PQDEMO,"PQDEMO");
END InitExternalsPQSMPL;

END MLPQSMPL.

(* -EOF- *)
