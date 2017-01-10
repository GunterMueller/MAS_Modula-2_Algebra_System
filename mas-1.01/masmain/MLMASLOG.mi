(* ----------------------------------------------------------------------------
 * $Id: MLMASLOG.mi,v 1.3 1994/11/28 21:14:31 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: MLMASLOG.mi,v $
 * Revision 1.3  1994/11/28  21:14:31  dolzmann
 * New functions of the polynomial equation systems.
 * New functions of the real quantifier elimination package.
 *
 * Revision 1.2  1993/12/17  17:38:52  dolzmann
 * Adapted to the divided MASLOG.
 *
 * Revision 1.1  1993/07/13  14:45:29  dolzmann
 * The configuration-files of MASLOG and MLDEMO.
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MLMASLOG;

(******************************************************************************
*			 M A S L O A D    M A S L O G			      *
*-----------------------------------------------------------------------------*
* Author:   Andreas Dolzmann                                                  *
* Language: MODULA II (mocka or mtc are possible)                             *
* System:   Program for the computer algebra system MAS by Heinz Kredel       *
* Remark:   Library maslog is used.                                           *
* Abstract: This is the configuration module for the MASLOG-System.           *
******************************************************************************)

FROM MASLOG	IMPORT	FORELIMXOPS, FORIMQB, FORMKPRENEX, FORMKPRENEX1,
			FORMKPRENEXI, FORCOUNTAF;


FROM MLOGBASE	IMPORT	FORMKBINOP, FORMKCNST, FORMKFOR, FORMKLVAR,
			FORMKQUANT, FORMKUNOP, FORMKVAR,
			FORVTSTORE, FORVTRESTORE, FORVTENTER, FORVTGET;
			
FROM MLOGIO	IMPORT	FORPPLVAR, FORPPVAR, FORRDLVAR, FORRDVAR,
			FORTEXWLVAR, FORTEXWVAR, KEYREAD;
			
FROM MODVAR	IMPORT	MVDeclareB, MVDeclareL, MVFLAG, MVGET, MVHLP, MVOFF,
			MVON, MVSET;
			
FROM MASLISPU	IMPORT	Compiledf0, Compiledf1, Compiledf2, Compiledf3,
			Compiledp0, Compiledp1, Compiledp1v2, Compiledp1v3,
			Compiledp2, Compiledp2v2, Compiledp2v3, Compiledp3,
			Compiledp3v2;

FROM PQBASE	IMPORT	DOMAIN, PQELIMXOPS, PQELIMXOPS1, PQIREAD, PQMKCNF,
			PQMKDNF, PQMKPOS, PQMKPRENEX, PQMKVD, PQPPRT,
			PQPREAD, PQPRING, PQPRINGWR, PQSIMPLIFY, PQSIMPLIFYP,
			PQSMPL, PQTEXW, pqmkaf;
			
FROM RQEPRRC	IMPORT	RQEQE, RQEOPTSET, RQEOPTWR, RqeOpt; 

FROM SYSINFO	IMPORT	Cells;

FROM TFORM	IMPORT	TFFTUPLE, TFGENI, TFGENJ, TFPPRT, TfClassifyI,
			TfCount, TfCount1, TfCtj, TfNextTuple, TfSignChs,
			TfZeroes0, TfZeroesI, TFIREAD,
			TfTypeFormula, TfComputeTf, TfUseDb;


CONST rcsidi = "$Id: MLMASLOG.mi,v 1.3 1994/11/28 21:14:31 dolzmann Exp $";
CONST copyrighti = "Copyright (c) 1993 Universitaet Passau";

PROCEDURE InitExternalsML();
(* Initialze external compiled logic procedures. *)
BEGIN
	Compiledp2(MVSET,"MVSET");		
	Compiledf1(MVGET,"MVGET");
	Compiledp1(MVON,"MVON");
	Compiledp1(MVOFF,"MVOFF");
	Compiledp1(MVHLP,"MVHLP");
	Compiledf1(MVFLAG,"MVFLAG");

	Compiledf2(FORMKFOR,"FORMKFOR");
	Compiledf1(FORMKCNST,"FORMKCNST");
	Compiledf2(FORMKUNOP,"FORMKUNOP");
	Compiledf3(FORMKBINOP,"FORMKBINOP");
	Compiledf2(FORMKVAR,"FORMKVAR");
	Compiledf1(FORMKLVAR,"FORMKLVAR");
	Compiledf3(FORMKQUANT,"FORMKQUANT");
	Compiledf2(FORELIMXOPS,"FORELIMXOPS");	
	Compiledp1(FORPPVAR,"FORPPVAR");
	Compiledp1(FORPPLVAR,"FORPPLVAR");
	Compiledp1(FORTEXWVAR,"FORTEXWVAR");
	Compiledp1(FORTEXWLVAR,"FORTEXWLVAR");
	Compiledf0(FORRDVAR,"FORRDVAR");
	Compiledf0(FORRDLVAR,"FORRDLVAR");
	Compiledf0(KEYREAD,"KEYREAD");	
	Compiledf0(FORVTSTORE,"FORVTSTORE");
	Compiledf1(FORVTRESTORE,"FORVTRESTORE");
	Compiledf1(FORVTENTER,"FORVTENTER");
	Compiledf1(FORVTGET,"FORVTGET");
	Compiledf1(FORIMQB,"FORIMQB");
	Compiledf1(FORCOUNTAF,"FORCOUNTAF");
	Compiledf2(FORMKPRENEX,"FORMKPRENEX");
	Compiledf2(FORMKPRENEXI,"FORMKPRENEXI");
	Compiledf1(FORMKPRENEX1,"FORMKPRENEX1");

	Compiledf2(pqmkaf,"pqmkaf");	
	Compiledf0(PQPREAD,"PQPREAD");
	Compiledf0(PQIREAD,"PQIREAD");	
	Compiledp1(PQPPRT,"PQPPRT");
	Compiledp1(PQTEXW,"PQTEXW");
	Compiledf1(PQMKCNF,"PQMKCNF");
	Compiledf1(PQMKDNF,"PQMKDNF");
	Compiledf1(PQSMPL,"PQSMPL");
	Compiledp0(PQPRINGWR,"PQPRINGWR");
	Compiledf1(PQPRING,"PQPRING");
	Compiledf1(PQELIMXOPS,"PQELIMXOPS");
	Compiledf2(PQELIMXOPS1,"PQELIMXOPS1");
	Compiledf2(PQMKPRENEX,"PQMKPRENEX");
	Compiledf1(PQMKPOS,"PQMKPOS");
	Compiledf2(PQSIMPLIFYP,"PQSIMPLIFYP");
	Compiledf1(PQMKVD,"PQMKVD");
	Compiledf1(PQSIMPLIFY,"PQSIMPLIFY");

	Compiledf1(RQEQE,"RQEQE");
	Compiledf1(RQEOPTSET,"RQEOPTSET");
	Compiledp0(RQEOPTWR,"RQEOPTWR");

	Compiledf2(TfNextTuple,"TfNextTuple");
	Compiledf1(TfSignChs,"TfSignChs");
	Compiledf1(TfZeroes0,"TfZeroes0");
	Compiledf1(TfZeroesI,"TfZeroes");
	Compiledf1(TfClassifyI,"TfClassify");
	Compiledf1(TfCount,"TfCount");
	Compiledf2(TfCount1,"TfCount1");
	Compiledf2(TFGENI,"TFGEN");
	Compiledf1(TFFTUPLE,"TFFTUPLE");
	Compiledp1(TFPPRT,"TFPPRT");
	Compiledf1(TfCtj,"TfCtj");
	Compiledf1(TFGENJ,"TFGENJ");
	Compiledf0(TFIREAD,"TFIREAD");
	Compiledf1(TfTypeFormula,"TfTypeFormula");
	Compiledp0(TfUseDb,"TfUseDb");
	Compiledp0(TfComputeTf,"TfComputeTf");	
	
	MVDeclareB(Cells,"SysinfoCells",
		"Determines whether the cell statistics is reported.",
		TRUE);
		
END InitExternalsML;

END MLMASLOG.

(* -EOF- *)
