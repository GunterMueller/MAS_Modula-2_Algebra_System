(* ----------------------------------------------------------------------------
 * $Id: SUBST.mi,v 1.1 1995/11/05 15:57:36 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SUBST.mi,v $
 * Revision 1.1  1995/11/05 15:57:36  pesch
 * Diplomarbeit Manfred Goebel, Reduktion G-symmetrischer Polynome fuer
 * beliebige Permutationsgruppen G, slightly edited.
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SUBST;
(* Substitution Group Polynomial System Implementation Module. *)

FROM MASELEM	IMPORT	GAMMAINT;

FROM MASSTOR	IMPORT	ADV, COMP, FIRST, INV, LENGTH, LIST, LIST1, SIL;

FROM MASBIOS	IMPORT	BLINES, SWRITE;

FROM SACLIST	IMPORT	EQUAL, LELT, MEMBER, OWRITE;

FROM SACRN	IMPORT	RNINT;

FROM LINALGRN	IMPORT	RNMDET, RNMPROD, RNMREAD; 

FROM DIPRN	IMPORT	DIRPDF, DIRPEX, DIRPPR, DIRPRP, DIRPRQ, DIRPSM;

FROM DIPC	IMPORT	DIPFMO, DIPMAD, EVCADD, EVDEL, EVTDEG;

FROM GSYMFUIN	IMPORT	GSYSPG;

FROM GSYMFURN	IMPORT	GRNCHKBAS;

FROM NOETHER	IMPORT	MERGE, NOEL32, NOEPIP, NOEPPR, NOEPRM, NOEPSM,
			NOESRT;

CONST rcsidi = "$Id: SUBST.mi,v 1.1 1995/11/05 15:57:36 pesch Exp $";
CONST copyrighti = "Copyright (c) 1995 Universitaet Passau";

PROCEDURE SUBINF();
BEGIN
BLINES(1);
SWRITE("Substitution Group Polynomial System Package:");
BLINES(0);
SWRITE("---------------------------------------------");
BLINES(1);
SWRITE("               SG := SUBSGR(Number_of_Variables).");
BLINES(0);
SWRITE("            Order := SUBORD(SG).");
BLINES(0);
SWRITE("            Orbit := SUBORP(SG, Polynom).");
BLINES(0);
SWRITE("           0_or_1 := SUBSYM(SG, Polynom).");
BLINES(0); 
SWRITE("       Orbit_List := SUBOPL(SG, Monom_List).");
BLINES(0);
SWRITE("          Polynom := SUBCHK(SG, Base, Base_Polynom).");
BLINES(0); 
SWRITE("     SK_Power_Sum := SUBPOW(SG, Degree).");
BLINES(1);
SWRITE("SUBRED(SG, Polynom, Base, Base_Polynom, Remainder_Polynom).");
BLINES(0);
SWRITE("SUBINF().");	
BLINES(0);
SWRITE("SUBSGW(SG).");
END SUBINF;

PROCEDURE SUBSGR(N: GAMMAINT): LIST;
VAR SG, NSG, XSG, YSG, XX, YY, VEC, T: LIST;
    I, K, N: GAMMAINT;
BEGIN
SG := SIL;
NSG := SIL;
XSG := SIL;
XX := RNMREAD();
WHILE XX # SIL DO
     IF LENGTH(XX) # N THEN SWRITE("Length error, try again! ");
     ELSE IF MEMBER(XX, XSG) = 0 THEN I := 1;
               YY := XX;
               LOOP IF YY = SIL THEN EXIT; END;
                    ADV(YY, VEC, YY);
                    IF LENGTH(VEC) # N THEN EXIT; END;
                    I := I + 1;
                    END; (* of loop *)
               IF (I >= N) AND (RNMDET(XX) # 0) THEN XSG := COMP(XX, XSG);
               ELSE SWRITE("No substitution, try again! "); END;
               END; (* of if *)
          END; (* of if *)
     XX := RNMREAD();
     END; (* of while *)
SG := XSG;
K := 0;
BLINES(0); 
REPEAT
    K := K + 1;
    NSG := SG; 
    N := LENGTH(SG);
    WHILE NSG # SIL DO
         ADV(NSG, XX, NSG);
         YSG := XSG;
         WHILE YSG # SIL DO
              ADV(YSG, YY, YSG);
              T := RNMPROD(XX, YY);
              IF (MEMBER(T, SG) = 0) THEN 
                   SG := COMP(T, SG); 
                   OWRITE(K); SWRITE(" "); 
                   END; (* of if *)
              END; (* of while *)
         END; (* of while *)
UNTIL (LENGTH(SG) = N) OR (K > 50); (* of repeat *)
RETURN(SG);
END SUBSGR;

PROCEDURE SUBSGW(SG: LIST);
VAR PI: LIST;
    I: GAMMAINT;
BEGIN
I := 0;
WHILE SG # SIL DO
    ADV(SG, PI, SG);
    I := I + 1;
    BLINES(1); OWRITE(I); SWRITE(")  "); OWRITE(PI);
    END; (* of while *);    
END SUBSGW;

PROCEDURE SUBORD(SG: LIST): GAMMAINT;
BEGIN
RETURN(LENGTH(SG));
END SUBORD;

PROCEDURE PERM(PI, POL: LIST): LIST;
VAR RES, FF, XX, SUM, VEC, HK, HT, NFF, PROD: LIST;
    I, J, N: GAMMAINT;
BEGIN
RES := 0;
IF (PI = SIL) OR (POL = 0) THEN RETURN(RES); END;
N := LENGTH(FIRST(PI));
FF := SIL;
WHILE PI # SIL DO
    ADV(PI, VEC, PI);
    SUM := 0;
    FOR I := 1 TO N DO
         IF LELT(VEC, I) # 0 THEN
              XX := SIL;
              FOR J := 1 TO N DO
                   IF I = J THEN XX := COMP(1, XX); 
                   ELSE XX := COMP(0, XX); END;
                   END; (* of for *)
              SUM := DIRPSM(SUM, DIPFMO(LELT(VEC, I), XX));  
              END; (* of if *)
         END; (* of for *)
    FF := COMP(SUM, FF);	
    END; (* of while *)
WHILE POL # SIL DO
    DIPMAD(POL, HK, HT, POL);
    PROD := DIRPEX(DIPFMO(HK, HT), 0);
    NFF := FF;
    WHILE HT # SIL DO
         ADV(HT, XX, HT);
         ADV(NFF, SUM, NFF);
         PROD := DIRPPR(PROD, DIRPEX(SUM, XX));
         END; (* of while *)
    RES := DIRPSM(RES, DIRPRP(PROD, HK));
    END; (* of while *)
RETURN(RES);
END PERM;

PROCEDURE SUBORP(SG, POL: LIST): LIST;
VAR RES, PI: LIST;
    ORDER: GAMMAINT;
BEGIN
RES := 0;
IF (SG = SIL) OR (POL = 0) THEN RETURN(RES); END;
ORDER :=SUBORD(SG);
WHILE SG # SIL DO
    ADV(SG, PI, SG);
    RES := DIRPSM(RES, PERM(PI, POL));
    END; (* of while *)
RES := DIRPRQ(RES, RNINT(ORDER));
RETURN(RES);
END SUBORP;

PROCEDURE SUBSYM(SG, POL: LIST): GAMMAINT;
VAR PI: LIST;
BEGIN
WHILE SG # SIL DO
    ADV(SG, PI, SG);
    IF DIRPDF(POL, PERM(PI, POL)) # 0 THEN RETURN(0); END;
    END; (* of while *)
RETURN(1);
END SUBSYM;

PROCEDURE SUBOPL(SG, ML: LIST): LIST;
VAR HM, RES: LIST;
BEGIN
RES := SIL;
WHILE ML # SIL DO
    ADV(ML, HM, ML);
    RES := COMP(SUBORP(SG, HM), RES);
    END; (* of while *)
RETURN(INV(RES));
END SUBOPL;

PROCEDURE SUBCHK(SG, BASE, POL: LIST): LIST;
VAR RES, HK, HT, BASEORBIT, PROD: LIST;
    I, N: GAMMAINT;
BEGIN
RES := 0;
IF POL = 0 THEN RETURN(RES); END;
N := LENGTH(BASE);
IF N = 0 THEN RETURN(RES); END;
BASEORBIT := SUBOPL(SG, BASE);
WHILE POL # 0 DO
    DIPMAD(POL, HK, HT, POL);
    IF POL = SIL THEN POL := 0; END;
    PROD := DIRPEX(LELT(BASEORBIT, 1), 0);
    FOR I := 1 TO N DO
         PROD := DIRPPR(PROD, DIRPEX(LELT(BASEORBIT, I), LELT(HT, I)));
         END; (* of for *)
    RES := DIRPSM(RES, DIRPRP(PROD, HK));
    END; (* of while *)
RETURN(RES);
END SUBCHK;

PROCEDURE SUBPOW(SG: LIST; K: GAMMAINT): LIST;
VAR POL, XPOL, HKPOL, HKBASE, XHK, HK, HT, XX: LIST;
    I, J, N, ORDER: GAMMAINT;
BEGIN
POL := 0;
IF SG = SIL THEN RETURN(POL); END;
XPOL := 0;
N := LENGTH(FIRST(FIRST(SG)));
ORDER := SUBORD(SG);
FOR I := 1 TO N DO
    HT := SIL;
    FOR J := 1 TO N DO
         IF I = J THEN HT := COMP(1, HT);
              ELSE HT := COMP(0, HT); END; (* of if *)
         END; (* of for *)
    XPOL := DIRPSM(XPOL, DIPFMO(RNINT(1), HT));
    END; (* of for *)
XPOL := DIRPEX(XPOL, K);
POL := SIL;
WHILE XPOL # SIL DO
    DIPMAD(XPOL, HK, HT, XPOL);
    XX := DIPFMO(RNINT(1), HT);
    IF SUBORP(SG, XX) # 0 THEN 
         HKPOL := DIRPRP(DIPFMO(RNINT(ORDER), LIST1(1)), HK);
         HKBASE := LIST1(XX);
         XHK := SIL;
         XHK := COMP(HKPOL, COMP(HKBASE, XHK));
         POL := COMP(HT, COMP(XHK, POL));
         END; (* of if *)
    END; (* of while *)
POL := NOESRT(POL);
RETURN(POL);
END SUBPOW;

PROCEDURE COMPARE(SG, SKL, SKP, TERM: LIST; VAR BASE, POL: LIST);
VAR HK, HT, XHK, XHT, XX, YY, PROD, RES, NSKL, DUMMY: LIST;
    I, J, N, ORDER: GAMMAINT;
BEGIN
BASE := SIL; POL := 0;
IF SG = SIL THEN RETURN; END;
YY := SUBORP(SG, DIPFMO(RNINT(1), TERM));
IF YY = 0 THEN RETURN; END;
ORDER := SUBORD(SG);
IF SKP = 0 THEN RETURN; END;
N := LENGTH(SKL);
IF N = 0 THEN RETURN; END;
NSKL := SIL;
FOR I := N TO 1 BY -1 DO NSKL := COMP(NOEPRM(LELT(SKL, I), TERM), NSKL); END;
RES := SIL;
BLINES(0); SWRITE("SKP "); OWRITE(SKP);
WHILE SKP # SIL DO
    DIPMAD(SKP, HK, HT, SKP);
    BLINES(0); SWRITE("HT = "); OWRITE(HT);
    PROD := SIL;
    FOR I := 1 TO N DO
         FOR J := 1 TO LELT(HT, I) DO
              PROD := NOEPPR(PROD, LELT(NSKL, I), TERM); END;
         END; (* of for *)
    RES := NOEPSM(RES, NOEPIP(PROD, HK));
    END; (* of while *)
LOOP IF RES = SIL THEN RETURN; END;
    DIPMAD(RES, XHK, XHT, RES);
    IF EQUAL(XHT, TERM) = 1 THEN
         DIPMAD(XHK, BASE, POL, DUMMY);
         EXIT;
         END; (* of if *)
    END; (* of loop *)
XX := SUBCHK(SG, BASE, POL);
IF XX = 0 THEN RETURN; END;
DIPMAD(XX, HK, HT, DUMMY);
POL := DIRPRQ(POL, HK);
DIPMAD(YY, HK, HT, DUMMY);
POL := DIRPRP(POL, HK);
END COMPARE;

PROCEDURE SUBBRM(SG: LIST; VAR BASE, POL: LIST);
VAR XBASE, NBASE, NPOL, NHT, HT, HK, XX, YY, EL, DUMMY: LIST;
    I, K, N: GAMMAINT;
BEGIN
IF POL = 0 THEN BASE := SIL; END;
IF BASE = SIL THEN RETURN; END;
NBASE := BASE; 
BASE := SIL;
N := 0;
WHILE NBASE # SIL DO
    ADV(NBASE, XX, NBASE);
    BASE := COMP(XX, BASE);
    N := N + 1;	
    XBASE := SIL;
    K := 0;
    FOR I := 1 TO LENGTH(NBASE) DO	
         YY := LELT(NBASE, I);	
         IF (DIRPDF(SUBORP(SG, XX), SUBORP(SG, YY)) = 0) THEN
              NPOL := POL;
              POL := 0;
              WHILE NPOL # SIL DO
                   DIPMAD(NPOL, HK, HT, NPOL);
                   EVDEL(HT, N+I-K, NHT, EL);
                   EVCADD(NHT, N, EL, HT, DUMMY);
                   POL := DIRPSM(POL, DIPFMO(HK, HT));
                   END; (* of while *)
              K := K + 1;
         ELSE XBASE := COMP(YY, XBASE); END; (* of if *)
         END; (* of for *)
    NBASE := INV(XBASE);              
    END; (* of while *)
BASE := INV(BASE);
END SUBBRM;

PROCEDURE SUBRED(SG, POL: LIST; VAR BASE, BASEPOL, REMPOL: LIST);
VAR HK, HT, SKL, SKP, PSM, BASE1, BASEPOL1, XX, DUMMY: LIST;
    ORDER, DEGREE, KK, I: GAMMAINT;
BEGIN
BASE := SIL;
BASEPOL := SIL;
REMPOL := 0;
IF (POL = 0) OR (SG = SIL) THEN RETURN; END;
ORDER := LENGTH(SG);
IF (SUBSYM(SG, POL) # 1) THEN REMPOL := POL; 
ELSE SKL := SIL;
     FOR I := 1 TO ORDER DO SKL := COMP(SUBPOW(SG, I), SKL); END;
     WHILE POL # SIL DO
          DIPMAD(POL, HK, HT, POL);
          DEGREE := EVTDEG(HT);
          IF DEGREE <= ORDER THEN
               BASE1 := LIST1(DIPFMO(RNINT(1), HT));
               BASEPOL1 := DIPFMO(HK, LIST1(1));
          ELSE SKP := NOEL32(ORDER, DEGREE);
               COMPARE(SG, SKL, SKP, HT, BASE1, BASEPOL1);
               BASEPOL1 := DIRPRP(BASEPOL1, HK);
               END; (* of if *)
          MERGE(TRUE, BASE1, BASEPOL1, BASE, BASEPOL);
          END; (* of while *)
     END; (* of if *)
SUBBRM(SG, BASE, BASEPOL);
GRNCHKBAS(BASE, BASEPOL);
BLINES(1); SWRITE("SUBRED exit (BASE): "); OWRITE(BASE);
BLINES(0); SWRITE("SUBRED exit (BASEPOL): "); OWRITE(BASEPOL);
BLINES(0); SWRITE("SUBRED exit (REMPOL): "); OWRITE(REMPOL);
END SUBRED;

END SUBST.

(* -EOF- *)
