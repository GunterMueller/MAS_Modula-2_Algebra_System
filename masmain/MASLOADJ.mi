(* ----------------------------------------------------------------------------
 * $Id: MASLOADJ.mi,v 1.1 1995/10/12 14:43:43 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASLOADJ.mi,v $
 * Revision 1.1  1995/10/12 14:43:43  pesch
 * Diplomarbeit Rainer Grosse-Gehling.
 * Involutive Bases.
 * Slightly edited.
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASLOADJ;

(*MAS Load Implementation Module J. *)

(* Import lists and declarations. *)

FROM ADEXTRA IMPORT	IBeqGB;

FROM DIPDCIB IMPORT	IBLWR, InvolutiveBases, SetDCIBopt, SetDCIBTraceLevel,
			SetDCIBDecomp, SetDCIBVarOrdOpt, SetDCIBdepth;

FROM DIPIB IMPORT	ADPNFJ, DIPIB, DIPIB2, DIPIB3, DIPIB4, DILISJ,
			SetDIPIBopt, SetDIPIBTraceLevel, SetDIPIBCancel, 
			SetDIPIBSelect, SetDIPIBISJ, SetDomainNFJ,
			SetDIPIBCrit, ADCAN;

FROM DIPIIB IMPORT 	DIILISJ, DIIPIB, DIIPIB2, DIIPIB3, DIIPNFJ;

FROM DIPRNIB IMPORT	DIRPNFJ, DIRLISJ, DIRPIB, DIRPIB2;

FROM MASLISPU IMPORT 	Declare,  
			Compiledp0, Compiledp1, Compiledp2,
			Compiledf1, Compiledf2, Compiledf3,
			Compiledp2v2, Compiledp1v3, Compiledp1v2;

FROM MASSTOR IMPORT 	LIST, LENGTH;

CONST rcsidi = "$Id: MASLOADJ.mi,v 1.1 1995/10/12 14:43:43 pesch Exp $";
CONST copyrighti = "Copyright (c) 1995 Universitaet Passau";


PROCEDURE InitExternalsJ;
(* Initialize external compiled procedures *)
BEGIN 
		SetDomainNFJ();
(* ADEXTRA *)	Compiledf2(IBeqGB, "IBeqGB");
(* ADNORJ *)	Compiledp2v2(ADPNFJ, "ADPNFJ");
(* DIPIB *)	Compiledp1v2(DILISJ, "DILISJ");
		Compiledf1(DIPIB, "DIPIB");
		Compiledf1(DIPIB2, "DIPIB2");
		Compiledf1(DIPIB3, "DIPIB3");
		Compiledf1(DIPIB4, "DIPIB4");
		Compiledp1(SetDIPIBopt, "SetDIPIBopt");
		Compiledp1(SetDIPIBTraceLevel, "SetDIPIBTraceLevel");
		Compiledp1(SetDIPIBCancel, "SetDIPIBCancel");
		Compiledp1(SetDIPIBSelect, "SetDIPIBSelect");
		Compiledp1(SetDIPIBISJ, "SetDIPIBISJ");
		Compiledp1(SetDIPIBCrit, "SetDIPIBCrit");
		Compiledf1(ADCAN, "ADCAN");
(*DIPIIB*)	Compiledf3(DIIPNFJ, "DIIPNFJ");
      		Compiledf1(DIILISJ, "DIILISJ");
      		Compiledf1(DIIPIB, "DIIPIB");
      		Compiledf1(DIIPIB2, "DIIPIB2");
		Compiledf1(DIIPIB3, "DIIPIB3");
(*DIPRNIB*)	Compiledf3(DIRPNFJ, "DIRPNFJ");
		Compiledf1(DIRLISJ, "DIRLISJ");
		Compiledf1(DIRPIB, "DIRPIB");
		Compiledf1(DIRPIB2, "DIRPIB2");
(* DIPDCIB *)	Compiledf2(InvolutiveBases, "IB");
		Compiledp2(IBLWR, "IBLWR");
		Compiledp1(SetDCIBopt, "SetDCIBopt");
                Compiledp1(SetDCIBTraceLevel, "SetDCIBTraceLevel");
		Compiledp1(SetDCIBDecomp, "SetDCIBDecomp");
		Compiledp1(SetDCIBVarOrdOpt, "SetDCIBVarOrdOpt");
		Compiledp1(SetDCIBdepth, "SetDCIBdepth");
END InitExternalsJ;

END MASLOADJ.
