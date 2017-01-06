(* ----------------------------------------------------------------------------
 * $Id: GSYMINP.mi,v 1.1 1996/06/08 18:52:49 pesch Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1996 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: GSYMINP.mi,v $
 * Revision 1.1  1996/06/08 18:52:49  pesch
 * Input procedures for G-symmetric polynomials.
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE GSYMINP;

(* GSYM Input Implementation Module. *)

FROM DIPC	IMPORT	EVORD, IGRLEX, INVLEX, REVITDG, PLFDIL, REVILEX,
			VALIS;

FROM DIPI	IMPORT	DIILRD, DIIPDF, DIIPEX, DIIPIP, DIIPNG, DIIPPR,
			DIIPSM, DIIPSO, DIIPWR;

FROM DIPRN	IMPORT	DIRLRD, DIRLWR, DIRPPR, DIRPWR;

FROM MASBIOS	IMPORT	BKSP, BLINES, CREADB, MASORD, SWRITE;

FROM MASSTOR	IMPORT	COMP, FIRST, INV, LENGTH, LIST, LIST1, SIL;

FROM SACPOL	IMPORT	VLREAD;

CONST rcsidi = "$Id: GSYMINP.mi,v 1.1 1996/06/08 18:52:49 pesch Exp $";
CONST copyrighti = "Copyright (c) 1996 Universitaet Passau";

PROCEDURE GSDREAD(): LIST;
(* G-symmetric descriptor read.
--- to do ---: remove *)
VAR   P, T, V, E, Q, r, X: LIST; (* read polynomial descriptor *)
BEGIN P:=SIL;                    (* i.e. variable list & term order *)
REPEAT V:=VLREAD(); BLINES(1); UNTIL V <> SIL;
VALIS:=V;
REPEAT E:=CREADB(); BLINES(1);
    UNTIL   (E = MASORD("("))
         OR (E = MASORD("S"))
         OR (E = MASORD("L"))
         OR (E = MASORD("P"))
         OR (E = MASORD("G")); (* end of repeat *)
IF E = MASORD("S") THEN EVORD:=REVILEX END;
IF E = MASORD("L") THEN EVORD:=INVLEX END;
IF E = MASORD("P") THEN EVORD:=REVITDG END;
IF E = MASORD("G") THEN EVORD:=IGRLEX END;
IF E = MASORD("(") THEN BKSP;
    T:=LIST1(LIST1(MASORD("T")));
    X:=EVORD;
    EVORD:=INVLEX;
    P:=DIILRD(T);
    PLFDIL(P, r, Q);
    EVORD:=X;
    IF LENGTH(Q) = LENGTH(V) THEN EVORD:=INV(Q);
    ELSE SWRITE("Wrong number of polynomials."); BLINES(0); END;
    END; (* of if *)
RETURN(COMP(V, LIST1(EVORD)))
END GSDREAD;

PROCEDURE GSPREAD(): LIST;
(* G-symmetric polynomial read.
--- to do ---: remove *)
VAR   P, V, X: LIST;
BEGIN P:=SIL;
X:=GSDREAD(); V:=FIRST(X);
REPEAT SWRITE("Enter polynomial list: "); P:=DIILRD(V); BLINES(0);
    UNTIL P <> SIL; (* end of repeat *)
RETURN(P)
END GSPREAD;


PROCEDURE GSRDREAD(): LIST;
(* G-symmetric rational descriptor read.
--- to do ---: remove *)
VAR   P, T, V, E, Q, r, X: LIST; (* read polynomial descriptor *)
BEGIN P:=SIL;                    (* i.e. variable list & term order *)
REPEAT V:=VLREAD(); BLINES(1); UNTIL V <> SIL;
VALIS:=V;
REPEAT E:=CREADB(); BLINES(1);
    UNTIL   (E = MASORD("("))
         OR (E = MASORD("S"))
         OR (E = MASORD("L"))
         OR (E = MASORD("P"))
         OR (E = MASORD("G")); (* end of repeat *)
IF E = MASORD("S") THEN EVORD:=REVILEX END;
IF E = MASORD("L") THEN EVORD:=INVLEX END;
IF E = MASORD("P") THEN EVORD:=REVITDG END;
IF E = MASORD("G") THEN EVORD:=IGRLEX END;
IF E = MASORD("(") THEN BKSP;
    T:=LIST1(LIST1(MASORD("T")));
    X:=EVORD;
    EVORD:=INVLEX;
    P:=DIRLRD(T);
    PLFDIL(P, r, Q);
    EVORD:=X;
    IF LENGTH(Q) = LENGTH(V) THEN EVORD:=INV(Q);
    ELSE SWRITE("Wrong number of polynomials."); BLINES(0); END;
    END; (* of if *)
RETURN(COMP(V, LIST1(EVORD)))
END GSRDREAD;

PROCEDURE GSRREAD(): LIST;
(* G-symmetric rational polynomial read.
--- to do ---: remove *)
VAR   P, V, X: LIST;
BEGIN P:=SIL;
X:=GSRDREAD(); V:=FIRST(X);
REPEAT SWRITE("Enter polynomial list: "); P:=DIRLRD(V); BLINES(0);
    UNTIL P <> SIL; (* end of repeat *)
RETURN(P)
END GSRREAD;


END GSYMINP.
(* -EOF- *)
