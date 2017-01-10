(* ----------------------------------------------------------------------------
 * $Id: MASLOAD.mi,v 1.8 1995/11/05 15:29:35 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASLOAD.mi,v $
 * Revision 1.8  1995/11/05 15:29:35  pesch
 * *** empty log message ***
 *
 * Revision 1.7  1995/10/12 14:43:45  pesch
 * Diplomarbeit Rainer Grosse-Gehling.
 * Involutive Bases.
 * Slightly edited.
 *
 * Revision 1.6  1994/03/11  15:39:54  pesch
 * Additions for CGB, MASROOT and NNGB.
 *
 * Revision 1.5  1993/12/18  20:27:48  dolzmann
 * Procedures for the PQSMPL-System are loaded.
 *
 * Revision 1.4  1993/07/13  14:45:28  dolzmann
 * The configuration-files of MASLOG and MLDEMO.
 *
 * Revision 1.3  1992/10/15  16:30:32  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:32:48  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:12:05  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASLOAD;

(* MAS Load Implementation Module. *)



(* Import lists and declarations. *)

(*
FROM MASLOADT IMPORT InitExternalsT; (*for test *)
*)
FROM MASLOADA IMPORT InitExternalsA;

FROM MASLOADB IMPORT InitExternalsB;

FROM MASLOADC IMPORT InitExternalsC;

FROM MASLOADD IMPORT InitExternalsD;

FROM MASLOADE IMPORT InitExternalsE;

FROM MASLOADG IMPORT InitExternalsG;

FROM MASLOADJ IMPORT InitExternalsJ;

FROM MASLOADL IMPORT InitExternalsL;

FROM MASLOADM IMPORT InitExternalsM;

FROM MASLOADS IMPORT InitExternalsS;

FROM MASLOADQ IMPORT InitExternalsQ;

FROM MLMASLOG IMPORT InitExternalsML;

FROM MLMLDEMO IMPORT InitExternalsMLDEMO;

FROM MLPQSMPL IMPORT InitExternalsPQSMPL;

CONST rcsidi = "$Id: MASLOAD.mi,v 1.8 1995/11/05 15:29:35 pesch Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1995 Universitaet Passau";



PROCEDURE InitExternals;
(*Initialize external compiled procedures. *)
BEGIN 
     (*from Test.                           InitExternalsT; *)  
     (*from Arithmetic.                  *) InitExternalsA; 
     (*from Polynomials.                 *) InitExternalsB;    
     (*from Non commutative Polynomials. *) InitExternalsC; 
     (*from Real Root.                   *) InitExternalsD; 
     (*from Permutation invariant Poly.  *) InitExternalsG;
     (*from Arbitrary Domain.            *) InitExternalsE; 
     (*from Involutive bases             *) InitExternalsJ;
     (*from .                            *) InitExternalsQ; 
     (*from Linear Algebra.              *) InitExternalsL;   
           	    	      	   	    InitExternalsM;
     (*from Syzygy.                      *) InitExternalsS;
     (*from Logic		         *) InitExternalsML;
     (*from Logic Demonstration          *) InitExternalsMLDEMO; 
     (*from Polynomial Equation          *) InitExternalsPQSMPL;
END InitExternals;


END MASLOAD.


(* -EOF- *)
