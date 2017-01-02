(* ----------------------------------------------------------------------------
 * $Id: MASLOADG.mi,v 1.2 1996/06/08 18:51:42 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASLOADG.mi,v $
 * Revision 1.2  1996/06/08 18:51:42  pesch
 * For G-symmetric polynomial functions.
 *
 * Revision 1.1  1995/11/05 15:29:38  pesch
 * *** empty log message ***
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASLOADG;
(* MAS Load Implementation Module G. *)


FROM GSYMFUIN	IMPORT	GINBAS, GINCHK, GINCUT, GINOPL, GINORP, GINRED,
			GSYINF, GSYNSP, GSYORD, GSYPGR, GSYPGW, GSYSPG;

FROM GSYMFURN	IMPORT	GRNBAS, GRNCHK, GRNCUT, GRNGGB, GRNOPL, GRNORP,
			GRNRED;

FROM GSYMINP	IMPORT	GSPREAD, GSRREAD;

FROM MASLISPU	IMPORT	Compiledf0, Compiledf1, Compiledf2, Compiledf3,
			Compiledp0, Compiledp1, Compiledp2, Compiledp2v2,
			Compiledp2v3, Compiledp3;

FROM NOETHER	IMPORT	NOEINF, NOEL32, NOENSP, NOEPIP, NOEPOW, NOEPPR,
			NOEPRM, NOEPSM, NOERED;

FROM TIPRNGB	IMPORT	DIREGB;

FROM SACPOL	IMPORT	VLREAD;

FROM SUBST	IMPORT	SUBCHK, SUBINF, SUBOPL, SUBORD, SUBORP, SUBPOW,
			SUBRED, SUBSGR, SUBSGW, SUBSYM;

CONST rcsidi = "$Id: MASLOADG.mi,v 1.2 1996/06/08 18:51:42 pesch Exp $";
CONST copyrighti = "Copyright (c) 1995 Universitaet Passau";


PROCEDURE InitExternalsG;
BEGIN
    Compiledf0(GSPREAD, "GSPREAD");
    Compiledf0(GSRREAD, "GSRREAD");

    Compiledf0(VLREAD, "VLREAD"); (* from SACPOL *)

    Compiledp0(GSYINF, "GSYINF"); (* from GSYMFUII *)
    Compiledp1(GSYPGW, "GSYPGW");
    Compiledp1(GSYNSP, "GSYNSP");
    Compiledf1(GSYPGR, "GSYPGR");
    Compiledf1(GSYSPG, "GSYSPG");
    Compiledf1(GSYORD, "GSYORD");

    Compiledp2v2(GINCUT, "GINCUT");
    Compiledp2v3(GINRED, "GINRED");
    Compiledf1(GINBAS, "GINBAS");
    Compiledf2(GINORP, "GINORP");
    Compiledf2(GINOPL, "GINOPL");
    Compiledf3(GINCHK, "GINCHK");

    Compiledp2v2(GRNCUT, "GRNCUT"); (* from GSYMFURN *)
    Compiledp2v3(GRNRED, "GRNRED");
    Compiledf1(GRNBAS, "GRNBAS");
    Compiledf1(GRNGGB, "GRNGGB");
    Compiledf2(GRNORP, "GRNORP");
    Compiledf2(GRNOPL, "GRNOPL");
    Compiledf3(GRNCHK, "GRNCHK");

    Compiledp0(NOEINF, "NOEINF"); (* from NOETHER *)
    Compiledp1(NOENSP, "NOENSP");
    Compiledp2v3(NOERED, "NOERED");
    Compiledf2(NOEL32, "NOEL32");
    Compiledf2(NOEPOW, "NOEPOW");
    Compiledf2(NOEPSM, "NOEPSM");
    Compiledf2(NOEPIP, "NOEPIP");
    Compiledf2(NOEPRM, "NOEPRM");
    Compiledf3(NOEPPR, "NOEPPR");

    Compiledp0(SUBINF, "SUBINF"); (* from SUBST *)
    Compiledp1(SUBSGW, "SUBSGW");
    Compiledp2v3(SUBRED, "SUBRED");
    Compiledf1(SUBSGR, "SUBSGR");
    Compiledf1(SUBORD, "SUBORD");
    Compiledf2(SUBORP, "SUBORP");
    Compiledf2(SUBSYM, "SUBSYM");
    Compiledf2(SUBOPL, "SUBOPL");
    Compiledf2(SUBPOW, "SUBPOW");
    Compiledf3(SUBCHK, "SUBCHK");

    Compiledp2v2(DIREGB, "DIREGB");
END InitExternalsG;

END MASLOADG.
(* -EOF- *)
