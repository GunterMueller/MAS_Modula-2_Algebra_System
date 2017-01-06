(* ----------------------------------------------------------------------------
 * $Id: MASUGB.mi,v 1.3 1995/11/05 09:12:10 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASUGB.mi,v $
 * Revision 1.3  1995/11/05 09:12:10  kredel
 * Improved error handling and cosmetic.
 *
 * Revision 1.2  1994/03/11  15:47:31  pesch
 * Corrections suggested by A. Dolzmann.
 * Correct number of arguments in procedure calls, etc.
 *
 * Revision 1.1  1993/05/11  10:11:17  kredel
 * Initial Revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASUGB;

(* Universal Groebner Bases Implementation Module. *)


(* Author: T. Belkahia, Uni Passau, 1992. *)


FROM MASSTOR IMPORT ADV, FIRST, LIST, LIST1, RED, SIL, LENGTH, 
                    INV, COMP, SRED, SFIRST, BETA;

FROM MASERR  IMPORT severe, ERROR;

FROM MASBIOS IMPORT SWRITE, BLINES, CREADB, MASORD, LETTER, 
                    SIUNIT, BKSP, LISTS;

FROM SACLIST IMPORT ADV2, AWRITE, LWRITE, CCONC, CINV, COMP2, LIST5, 
                    EQUAL, MEMBER, LIST4, THIRD, FOURTH, FIRST2, 
                    SECOND, LAST, OREAD, OWRITE, LIST3, LIST2;

FROM SACRN   IMPORT RNINT, RNQ, RNPROD, RNINV, RNDIF, RNSUM, 
                    RNSIGN, RNCOMP, RNABS, RNNEG;

FROM MASRN   IMPORT RNMAX;

FROM SACI    IMPORT IQR, IPROD, ILCM, IMAX;

FROM SACPOL  IMPORT VLREAD; 

FROM SACSET  IMPORT USUN;

FROM DIPC    IMPORT DIPEVL, DIPFMO, DIPMAD, EVDEL, EVDIF, EVLCM, EVMT, 
                    EVIGLC, EVILCP, EVORD, EVSUM, DIPTDG, 
                    DIPINV, DIPLBC, DIPMPV, DIPLPM, DILBSO, DIPMCP,
                    VALIS, LEX, INVLEX, GRLEX, IGRLEX;

FROM DIPRN   IMPORT DIRPDF, DIRPNG, DIRPPR, DIRPQ, DIRPRP, DIRPSM, 
                    DIRPMC, DIRLWR, DIRLRD;

FROM DIPRNGB IMPORT DIRPNF, DIRPGB, EVPLM, EVPLSO;

FROM MASSYM2 IMPORT SREAD1;

FROM MASELEM IMPORT GAMMAINT;

CONST rcsidi = "$Id: MASUGB.mi,v 1.3 1995/11/05 09:12:10 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1993 Universitaet Passau";


(*Note: a linear form is represented as a vector of rational numbers, 
        instead as a vector of univariate recursive integral polynomials 
        in the DIPC module. *)
 

PROCEDURE UGBBIN(); 
(*UGB input, execute and output. 
Diese hauptprozedur liest die eingabedatei ein (die
polynome, die variablen und ihre anzahl durch pread, den
parameter durch rdpar und die option durch execrd). Die
funktion exeugb wird anschliessend aufgerufen.
UGBBIN wird vom hauptprogramm main aufgerufen. *)
VAR   I, L, OPT, PAR, V: LIST;
BEGIN
(*1*) PREAD(L,I,V); OPREAD(PAR,OPT); EXEUGB(L,I,V,PAR,OPT); 
(*4*) RETURN; END UGBBIN; 


PROCEDURE EXEUGB(L,I,V,PAR,OPT: LIST); 
(*UGB execute. 
Diese prozedur ruft, abhaengig von der option opt  die 
prozeduren lf, plf, ugb und pugb. Diese prozeduren 
realisieren die verschiedenen optionen, die im abschnitt 
benutzerschnittstelle besprochen wurden.
Die prozedur wird von der hauptprozedur ugbbin aufgerufen. *)
BEGIN
(*1*) IF MEMBER(1,OPT) = 1 THEN LF(L,I,V,PAR,OPT); ELSE
         IF MEMBER(2,OPT) = 1 THEN PLF(L,I,V,PAR,OPT); ELSE
            IF MEMBER(3,OPT) = 1 THEN UGB(L,I,V,PAR,OPT); ELSE 
               IF MEMBER(4,OPT) = 1 THEN PUGB(L,I,V,PAR,OPT); END; 
               END;  
            END; 
         END; 
(*4*) RETURN; END EXEUGB; 


PROCEDURE LF(L,I,V,PAR,OPT: LIST);  
(*UGB linear form. 
Die prozedur berechnet die linearformen nach der option
LF. Vergleiche benutzerschnittstelle und 5.1.6. 
Die prozedur wird von exeugb aufgerufen. *)
VAR   DIFALT, KALT, NEUFLF, NURLF, OLDL, P, PALT, Q, STAKK: LIST;  
BEGIN
(*1*) SWRITE("Option ... LF"); BLINES(1); Q:=EXPTU(L);  
      IF PAR = 8 THEN
         SWRITE("Die Liste der Terme als ganzzahlige Tupel ist "); 
         BLINES(1); OWRITE(Q); BLINES(1); END;  
      P:=MAKERN(Q); PALT:=SIL; DIFALT:=SIL; 
      OLDL:=LIST3(SIL,SIL,SIL); KALT:=SIL;  
      STAKK:=PROJEC(PALT,P,DIFALT,OLDL,I,PAR);  
      ALLELN(STAKK,L,KALT,I,PAR, NEUFLF,NURLF); 
      IF PAR = 8 THEN SWRITE("Die Linearformen sind"); BLINES(1); 
         OWRITE(NEUFLF); BLINES(2); END; 
(*4*) RETURN; END LF;  


PROCEDURE PLF(L,I,V,PAR,OPT: LIST); 
(*UGB linear form with precomputed linear forms. 
Die prozedur berechnet die linearformen nach der option
plf. Vergleiche benutzerschnittstelle und 5.1.7.
Die prozedur wird von exeugb aufgerufen. *)
VAR   DEG, DIFALT, IP, KALT, LFP, LFQ, NEWLF, NP, OLDL,
      PALT, Q, Q2: LIST;  
BEGIN
(*1*) SWRITE("Option ... PLF"); BLINES(1); SUNIT1(I); 
(*2*) IP:=I; Q:=EXPTU(L); 
      IF PAR = 8 THEN
         SWRITE("Die Liste der Terme als ganzzahlige Tupel ist "); 
         BLINES(1); OWRITE(Q); BLINES(1); END;  
      Q:=MAKERN(Q); PALT:=SIL; DIFALT:=SIL; 
      OLDL:=LIST3(SIL,SIL,SIL); KALT:=SIL;  
      PROJ(PALT,Q,DIFALT,OLDL,I, NP,Q2,DEG); 
      IF PAR = 8 THEN
         SWRITE("Gradschranke dieser Dimension ist "); 
         OWRITE(2*DEG); BLINES(1); END;  
      SWRITE("Datei einlesen ..."); BLINES(1); LFQ:=OREAD(); 
      IF I <> 3 THEN DEG:=2*DEG; END; 
      LFP:=LFGET(DEG,LFQ); IP:=IP-1; 
      IF PAR = 8 THEN OWRITE(LENGTH(LFP)); 
         SWRITE(" eingelesene Linearformen  "); BLINES(1); END;  
      SWRITE("Berechnung der Linearformen ... "); BLINES(1); 
      NEWLF:=MKLF1(LFP,Q2,NP,IP);  
      SWRITE("Die berechneten Linearformen sind   "); 
      OWRITE(LENGTH(NEWLF)); BLINES(1);  
      IF PAR = 8 THEN SWRITE("Die Linearformen sind"); BLINES(1); 
         OWRITE(NEWLF); BLINES(2); END;  
(*5*) RETURN; END PLF; 


PROCEDURE UGB(L,I,V,PAR,OPT: LIST); 
(*Universal Groebner base. 
Die prozedur berechnet eine universelle groebner basis 
nach der option ugb. Vergleiche benutzerschnittstelle
und 5.2.4.
Die prozedur wird von exeugb aufgerufen. *)
VAR   DIFALT, G, GB, KALT, NEUFLF, NURLF, OLDL, P, PALT, Q, STAKK, UL:
      LIST; 
BEGIN
(*1*) SWRITE("Option ... UGB"); BLINES(1); 
      IF I = 1 THEN G:=DIRPGB(L,0); 
         SWRITE("*************************************."); BLINES(1); 
         SWRITE("es gibt nur eine zulaessige Ordnung  ."); BLINES(1); 
         SWRITE("     die Linearform ist (1)          ."); BLINES(1); 
         SWRITE("*************************************."); BLINES(1); 
         WRUGB(G,V); RETURN; END; 
      Q:=EXPTU(L); 
      IF PAR = 8 THEN
         SWRITE("Die Liste der Terme als ganzzahlige Tupel ist "); 
         BLINES(1); OWRITE(Q); BLINES(1); END;  
      P:=MAKERN(Q); PALT:=SIL; DIFALT:=SIL; 
      OLDL:=LIST3(SIL,SIL,SIL); KALT:=SIL;  
      STAKK:=PROJEC(PALT,P,DIFALT,OLDL,I,PAR); LFALL(STAKK,L,KALT,I,
      NEUFLF,NURLF); GB:=UG(NEUFLF,I,V,STAKK,L,NURLF,PAR); 
      UL:=WRUGF(GB,V,PAR); BLINES(2); WRUGB(UL,V); 
(*4*) RETURN; END UGB; 


PROCEDURE PUGB(L,I,V,PAR,OPT: LIST); 
(*Universal Groebner base with precomputed linear forms. 
Die prozedur berechnet eine universelle groebner basis 
nach der option pugb. Vergleiche benutzerschnittstelle 
und 5.2.5.
Die prozedur wird von exeugb aufgerufen. *)
VAR   DEG, GB, LF, LFLIST, LFQ, NURLF, R, UL: LIST; 
BEGIN
(*1*) SWRITE("Option ... PUGB"); BLINES(1); SUNIT2(I); DEG:=LDEG(L);  
      IF PAR = 8 THEN SWRITE("Grad der Polynome ... "); 
         OWRITE(DEG); BLINES(1); END;  
      SWRITE("Lese Linearfomen ... "); BLINES(1);  
      IF I = 2 THEN IQR(DEG,2, DEG,R); 
         IF R <> 0 THEN DEG:=DEG+1; END; 
         END; 
      LFQ:=OREAD(); LF:=LFGET(DEG,LFQ); LF:=DO1(LF); 
      IF PAR = 8 THEN OWRITE(LENGTH(LF)); 
         SWRITE(" eingelesene Linearformen"); BLINES(1); END; 
      MKLIST(LF,L, LFLIST,NURLF);  
      GB:=PUG(LFLIST,I,V,L,DEG,NURLF,PAR,LFQ); UL:=WRUGF(GB,V,PAR); 
      BLINES(1); WRUGB(UL,V); 
(*4*) RETURN; END PUGB; 


PROCEDURE SUNIT1(I: LIST); 
(*UGB set input unit 1. 
Diese prozedur stellt bei der option plf die richtige
datei zum einlesen von linearformen bereit. I ist
die anzahl der variablen. Die vorberechneten lineraformen
sind je nach der anzahl der variablen in verschiedenen 
dateien gespeichert. Diese prozedur wird von der prozedur
plf aufgerufen. *)
VAR r: GAMMAINT;
BEGIN
(*1*) (*ISLM:=2; ISIZE:=80;*) r:=0;
(*2*) IF (I = 1) OR (I = 2) THEN
         SWRITE("Diese Option ist ab 3 Variablen sinnvoll.");  
         BLINES(1); RETURN; ELSE
         IF I = 3 THEN r:=SIUNIT("ugblade/linform.lade1"); ELSE
            IF I = 4 THEN r:=SIUNIT("ugblade/linform.lade2"); ELSE
               IF I = 5 THEN r:=SIUNIT("ugblade/linform.lade3"); ELSE 
                  IF I >= 6 THEN
                     SWRITE("Anzahl der Variablen zu hoch."); BLINES(1); 
                     RETURN; END; 
                  END; 
               END;  
            END; 
         END; 
      IF r <> 0 THEN ERROR(severe,"SUNIT1: Cannot open file."); END;   
(*5*) RETURN; END SUNIT1; 


PROCEDURE SUNIT2(I: LIST); 
(*UGB set input unit 2.
Diese prozedur stellt bei der option pugb die richtige 
datei zum einlesen von linearformen bereit. I ist
die anzahl der variablen. Die vorberechneten lineraformen
sind je nach der anzahl der variablen in verschiedenen 
dateien gespeichert. Diese prozedur wird von der prozedur
pugb aufgerufen. *)
VAR r: GAMMAINT;
BEGIN
(*1*) (* ISLM:=2; ISIZE:=80; *) r:=0;
(*2*) IF I = 1 THEN
         SWRITE("Diese Option ist ab 2 Variablen sinnvoll.");  
         BLINES(1); RETURN; ELSE
         IF I = 2 THEN r:=SIUNIT("ugblade/linform.lade1"); ELSE
            IF I = 3 THEN r:=SIUNIT("ugblade/linform.lade2"); ELSE
               IF I = 4 THEN r:=SIUNIT("ugblade/linform.lade3"); ELSE 
                  IF I = 5 THEN r:=SIUNIT("ugblade/linform.lade4"); ELSE 
                     IF I >= 6 THEN
                        SWRITE("Anzahl der Variablen zu hoch.");  
                        BLINES(1); RETURN; END; 
                     END; 
                  END; 
               END;  
            END; 
         END; 
      IF r <> 0 THEN ERROR(severe,"SUNIT2: Cannot open file."); END;   
(*5*) RETURN; END SUNIT2; 


PROCEDURE PREAD( VAR L,I,V: LIST);  
(*UGB polynomial read. 
Die polynome werden von der eingabedatei eingelesen.
Diese funktion wird von der hauptprozedur ugbbin
aufgerufen. *)
BEGIN
(*1*) V:=VLREAD(); L:=DIRLRD(V); I:=LENGTH(V); 
      SWRITE("Die eingegebenen Polynome sind "); BLINES(1); 
      DIRLWR(L,V,-1); BLINES(1); 
(*4*) RETURN; END PREAD;  


PROCEDURE OPREAD( VAR PAR,OPT: LIST);  
(*UGB options and parameter read. 
Diese prozedur liest von der eingabedatei den parameter
par (zustaendig fuer zwischenausgaben) durch die prozedur
rdpar und die option opt (steht fuer lf, plf, ugb, pugb) 
durch die prozedur execrd.
Diese prozedur wird von der hauptprozedur ugbbin
aufgerufen. *)
BEGIN
(*1*) PAR:=RDPAR();  
      IF PAR = 8 THEN SWRITE("Zwischenausgaben ... JA"); 
         BLINES(1); ELSE
         IF PAR = 9 THEN SWRITE("Zwischenausgaben ... NEIN"); 
            BLINES(1); END; 
         END; 
      OPT:=EXECRD(); 
(*4*) RETURN; END OPREAD; 


PROCEDURE EXPTU(L: LIST): LIST; 
(*UGB extract exponent vector list from polynomial list. 
Aus den polynomen wird die liste der terme berechnet.
Da jeder term mit dem tupel seiner exponenten 
identifizert werden kann, wird die liste der
exponententupel ausgegeben. 
Diese funktion wird von den prozeduren mklist, newdif, 
isneu, ug, pug, lf, plf, ugb und pugb. *)
VAR   A, B, E, J1Y, LP, Q: LIST; 
BEGIN
(*1*) Q:=SIL; LP:=L;  
      WHILE LP <> SIL DO ADV(LP, A,LP); 
            IF A <> 0 THEN
               WHILE A <> SIL DO DIPMAD(A, B,E,A); J1Y:=LIST1(E);  
                     Q:=USUN(J1Y,Q); END; 
               END;  
            END; 
(*2*) Q:=INV(Q); 
(*5*) RETURN(Q); END EXPTU; 


PROCEDURE MAKERN(Q: LIST): LIST;  
(*UGB rational exponent vector list from integer ev list. 
Makern transformiert die ganzzahlige struktur der 
exponententupel in eine rationalzahlige struktur
diese funktion wird von den funktionen mklist, neulf
und newdif aufgerufen. *)
VAR   A, A1, B, C, L1, P, QP: LIST;  
BEGIN
(*1*) QP:=Q; P:=SIL; L1:=SIL; 
(*2*) WHILE QP <> SIL DO ADV(QP, A,QP); A1:=SIL; 
            WHILE A <> SIL DO ADV(A, B,A); C:=RNINT(B); 
                  A1:=COMP(C,A1); END; 
            A1:=INV(A1); L1:=COMP(A1,L1); END;  
      P:=INV(L1); 
(*5*) RETURN(P); END MAKERN;  


PROCEDURE SCMULT(I,U: LIST): LIST; 
(*UGB rational exponent vector rational number product. 
Hilfsfunktion zur berechnung vom skalarprodukt zwischen 
rationalzahligen vektoren. 
Diese funktion wird von der funktion mkset aufgerufen. *)
VAR   A, IP, SKTU, T, UP, V: LIST; 
BEGIN
(*1*) UP:=U; IP:=I; V:=SIL; SKTU:=SIL; 
(*2*) WHILE UP <> SIL DO ADV(UP, A,UP); T:=RNPROD(A,IP);  
            V:=COMP(T,V); END;  
(*3*) SKTU:=INV(V);  
(*6*) RETURN(SKTU); END SCMULT; 


PROCEDURE PDIF(R,S,DIFALT: LIST): LIST; 
(*UGB rational exponent vector list difference list, incremental. 
Berechnet (r-s) vereinigt mit (s-s).Diese prozedur ist
im hinblick auf die berechnung von universellen groebner
basen geschrieben. S entspricht der menge der neuen terme, 
die nach der reduktion entstehen. R enspricht der alten 
menge von termen. Da r-r in einem vorherigen schritt
schon berechnet wurde, berechnet die prozedur nur r-r 
vereinigt mit s-s.
Diese funktion wird von den funktionen projec, proj und 
newdif aufgerufen. *)
VAR   B, C, C1, D, RP, SP: LIST; 
BEGIN
(*1*) RP:=R; SP:=S; B:=DIFF1(RP,SP); D:=DIFF(SP); C1:=USUN(B,D);  
      C:=USUN(C1,DIFALT); 
(*4*) RETURN(C); END PDIF; 


PROCEDURE MKSET(R: LIST;  VAR P2,P3,RR: LIST); 
(*UGB rational exponent vector list difference list. 
Berechnet die mengen p1, p2, p3 und die reduzierte menge
von p - p wie sie im theoretischen teil der diplomarbeit
beschrieben ist. Die eingabe ist r. P1 und p2 sind die
projektionen. P3 ist die vereinigung von p1 und p2.
Rr entspricht der reduzierten menge von p - p. 
Nur p2, p3 und rr werden zurueckgegeben. 
Diese funktion wird von den funktionen projec und proj
aufgerufen. *)
VAR   A, B, C, EE, J1Y, P1, P1P, P2P, RP, XP: LIST; 
BEGIN
(*1*) RP:=R; RR:=SIL; P1:=SIL; P2:=SIL; P3:=SIL; 
(*2*) WHILE RP <> SIL DO ADV(RP, A,RP); XP:=A; ADV(A, B,A); 
            IF NULRNV(A) <> 1 THEN 
               IF B = 0 THEN
                  IF MEMBER(A,P1) <> 1 THEN RR:=COMP(XP,RR);  
                     P1:=COMP(A,P1); END; 
                  ELSE B:=RNINV(B); C:=SCMULT(B,A);  
                  IF MEMBER(C,P2) <> 1 THEN RR:=COMP(XP,RR);  
                     P2:=COMP(C,P2); END; 
                  END; 
               END;  
            END; 
      P1P:=P1; P2P:=P2; 
      WHILE P1P <> SIL DO ADV(P1P, A,P1P); J1Y:=-1;  
            J1Y:=LIST2(J1Y,1); EE:=SCMULT(J1Y,A); 
            IF (MEMBER(EE,P2P) <> 1) AND (MEMBER(A,P2P) <> 1)
               THEN P2P:=COMP(A,P2P); END;  
            END; 
      P3:=P2P; P3:=CINV(P3);  
(*5*) RETURN; END MKSET;  


PROCEDURE PROJEC(R,S,DIFALT,OLDL,I,PAR: LIST): LIST; 
(*UGB projection to dimension 1. 
Berechnet die projektionen der eingabemenge r bis zur
dimension 1. Die ausgabe ist ein stapel der tupel der
form (p2,p) verschiedener dimensionen enthaelt.
P2 wird in jeder dimension zur berechnung der schnitte 
und p zum vergleich von ordnungen benutzt.
Diese prozedur ruft die prozeduren pdif und mkset auf. 
Die prozedur degre bestimmt fuer jede projektion den 
maximalen totalgrad der terme. 
Diese funktion wird von den funktionen lf, plf, ugb und
newdif aufgerufen. *)
VAR   B, C, D, DEG, E, IP, M, RP, RS, SERIE, STAKK: LIST; 
BEGIN
(*1*) SWRITE("Projektionen ... "); BLINES(1); RS:=S; RP:=R;  
      STAKK:=SIL; SERIE:=SIL; IP:=I; M:=IP; 
(*2*) WHILE M >= 2 DO M:=M-1;  
            IF PAR = 8 THEN SWRITE("Dimension ... "); OWRITE(M); 
               BLINES(1); END;  
            EVLRNBSO(RS); D:=PDIF(RP,RS,DIFALT); MKSET(D, B,C,D); 
            DEG:=DEGRE(C); DEG:=2*DEG;  
            IF PAR = 8 THEN
               SWRITE("Gradschranke dieser Dimension ist "); 
               OWRITE(DEG); BLINES(1); END; 
            E:=LIST2(D,B); STAKK:=COMP(E,STAKK); RP:=SIL; RS:=C; END; 
(*5*) RETURN(STAKK); END PROJEC; 


PROCEDURE PROJ(R,S,DIFALT,OLDL,I: LIST;  VAR D,B,DEG: LIST); 
(*UGB projection, one dimension. 
Berechnet die projektion der eingabemenge r auf eine 
niedrigere dimension. Die ausgabe besteht aus b
(entspricht p2 in definition 2.2.1), d (entspricht der 
reduzierten differenz r - r), sowie deg.
Diese prozedur ruft die prozeduren pdif und mkset auf. 
Die prozedur degre bestimmt den maximalen totalgrad deg
der terme der projektion. 
Diese funktion wird von der funktion plf aufgerufen. *)
VAR   C, IP, M, RP, RS, SERIE, STAKK: LIST; 
BEGIN
(*1*) RS:=S; RP:=R; STAKK:=SIL; SERIE:=SIL; IP:=I; M:=IP; 
(*2*) EVLRNBSO(RS); D:=PDIF(RP,RS,DIFALT); MKSET(D, B,C,D); DEG:=DEGRE(C); 
      STAKK:=COMP2(D,B,STAKK);  
(*5*) RETURN; END PROJ; 


PROCEDURE DIFF(R: LIST): LIST; 
(*UGB difference set for rational exponent vector list. 
Diese prozedur berechnet fuer die eingabemenge von
tupel r die reduzierte menge r - r. das ergebnis wird 
in r zurueckgegeben.
diese funktion wird von den funktionen mklist und pdif
aufgerufen. *)
VAR   A, AP, B, E, EE, ELT, ERG, RP, SP: LIST; 
BEGIN
(*1*) RP:=R; ERG:=SIL; 
      IF RP = SIL THEN RETURN(ERG); END; 
(*2*) SP:=RED(R); ELT:=SIL;
      WHILE RP <> SIL DO ADV(RP, A,RP);  
            WHILE SP <> SIL DO AP:=A; ADV(SP, B,SP); 
                  E:=RNVDIF(AP,B); EE:=RNVDIF(B,AP);  
                  IF (MEMBER(E,ERG) <> 1) AND (MEMBER(EE,ERG) <> 1) 
                     THEN ERG:=COMP(E,ERG); END;  
                  END; 
            SP:=RED(RP); END; 
(*5*) RETURN(ERG); END DIFF;  


PROCEDURE DIFF1(R,S: LIST): LIST; 
(*UGB difference set for two rational exponent vector list. 
Berechnet fuer die eingabemengen r und s von exponeneten
tupel die reduzierte menge r - s. das ergebnis wird in
erg zurueckgegeben. 
diese funktion wird von der funktion pdif aufgerufen. *)
VAR   A, AP, B, ELT, ERG, RP, SP: LIST;  
BEGIN
(*1*) RP:=R; SP:=S; ELT:=SIL; ERG:=SIL; 
      IF (RP = SIL) OR (SP = SIL) THEN RETURN(ERG); END;
(*2*) WHILE RP <> SIL DO ADV(RP, A,RP); SP:=S; 
            WHILE SP <> SIL DO AP:=A; ADV(SP, B,SP); 
                  ELT:=RNVDIF(AP,B);  
                  IF MEMBER(ELT,ERG) <> 1 THEN
                     ERG:=COMP(ELT,ERG); END;  
                  END; 
            END;  
(*4*) RETURN(ERG); END DIFF1; 


PROCEDURE RNVDIF(A,B: LIST): LIST; 
(*UGB rational exponent vector difference. 
Berechnet die komponentenweise differenz von zwei
rationalzahligen vektoren. die differenz von zwei
rationalzahlen wird durch die prozedur rndif berechnet.
diese funktion wird von den funktionen diff und diff1
aufgerufen. *)
VAR   AA, AQ, BB, BQ, C, CC: LIST; 
BEGIN
(*1*) C:=SIL; AQ:=A; BQ:=B;  
(*2*) WHILE AQ <> SIL DO ADV(AQ, AA,AQ); ADV(BQ, BB,BQ);  
            CC:=RNDIF(AA,BB); C:=COMP(CC,C); END; 
(*3*) C:=INV(C); 
(*6*) RETURN(C); END RNVDIF;  


PROCEDURE SCPROD(A,B: LIST): LIST; 
(*UGB rational exponent vector scalar product. 
Berechnet das skalarprodukt von zwei rationalzahligen
vektoren. die prozedur rnprod berechnet das produkt
zweier rationalzahlen. die prozedur rnsum berechnet die
summe von zwei rationalzahlen. das ergebnis wird in c
zurueckgegeben.
diese funktion wird von den funktionen cq2, cp2, pkegel
und cspur aufgerufen. *)
VAR   AA, AP, BB, BP, C, CC: LIST; 
BEGIN
(*1*) AP:=A; BP:=B; C:=0; 
(*2*) WHILE AP <> SIL DO ADV(AP, AA,AP); ADV(BP, BB,BP);  
            CC:=RNPROD(AA,BB); C:=RNSUM(CC,C); END;  
(*5*) RETURN(C); END SCPROD;  


PROCEDURE SKPRO2(A,B: LIST): LIST; 
(*UGB rational exponent vector scalar product with integer ev. 
Diese funktion ist eine spezielle skalarprodukt-funktion.
da die ausgerechneten linearformen rationahlzahlig sind
und die exponententupel ganzzahlig sind, werden diese
zunaechst als rationahlzahlen dargestellt und dann das 
skalarprodukt gebildet. 
diese funktion wird von evlfcp aufgerufen. *) 
VAR   AA, AP, BB, BP, C, CC: LIST; 
BEGIN
(*1*) AP:=A; BP:=B; C:=0; 
(*2*) WHILE AP <> SIL DO ADV(AP, AA,AP); ADV(BP, BB,BP);  
            BB:=RNINT(BB); CC:=RNPROD(AA,BB); C:=RNSUM(CC,C); END;  
(*5*) RETURN(C); END SKPRO2;  

  
PROCEDURE LRNBMS(L: LIST): LIST;
(*List of rational numbers bubble-merge sort.  L is an arbitrary list of
rational numbers, possibly with repetitions.  M is the result of sorting
L into non-decreasing order.  A combination of bubble-sort and merge-
sort is used.  The list L is modified to produce M.*)
VAR  B, BP, C, IL, J1Y, JL, KL, L1, L2, LP, LPP, LPPP, M, ML, NL, QL,
     QLP, RL, TL: LIST;
BEGIN
(*1*) (*short list.*) TL:=10; NL:=LENGTH(L);
      IF NL < TL THEN LRNBS(L); M:=L; RETURN(M); END;
(*2*) (*prepare for merge.*) KL:=0; ML:=1; QL:=NL;
      REPEAT KL:=KL+1; ML:=ML+ML; QL:=QL DIV 2;
             UNTIL QL < TL;
      J1Y:=ML*QL; RL:=NL-J1Y; B:=SIL; LP:=L;
      FOR IL:=1 TO ML DO
          IF IL <= RL THEN QLP:=QL; ELSE QLP:=QL-1; END;
          LPP:=LP;
          FOR JL:=1 TO QLP DO LPP:=RED(LPP); END;
          LPPP:=RED(LPP); SRED(LPP,SIL); LRNBS(LP); B:=COMP(LP,B);
          LP:=LPPP; END;
(*3*) (*merge.*)
      FOR IL:=1 TO KL DO C:=SIL; BP:=B;
          REPEAT ADV2(BP,L1,L2,BP); L1:=LRNM(L1,L2); C:=COMP(L1,C);
                 UNTIL BP = SIL;
          B:=C; END;
      M:=FIRST(B); RETURN(M);
(*6*) END LRNBMS;


PROCEDURE LRNBS(L: LIST);
(*List of rational numbers bubble sort.  L is an arbitrary list of
rational numbers, with possible repetitions.  L is sorted into
non-decreasing order by the bubble-sort method.  The list L, though not
its location, is modified.*)
VAR  ALP, ALPP, LP, LPP, M, MP: LIST;
BEGIN
(*1*) (*trivial case.*)
      IF L = SIL THEN RETURN; END;
(*2*) (*general case.*) M:=SIL;
      REPEAT LP:=L; LPP:=RED(LP); ALP:=FIRST(LP); MP:=SIL;
             WHILE LPP <> M DO ALPP:=FIRST(LPP);
                   IF RNCOMP(ALP,ALPP) > 0 THEN SFIRST(LP,ALPP);
                      SFIRST(LPP,ALP); MP:=LPP; 
                      ELSE ALP:=ALPP; END;
                   LP:=LPP; LPP:=RED(LP); END;
             M:=MP;
             UNTIL M = SIL;
      RETURN;
(*5*) END LRNBS;


PROCEDURE LRNM(L1,L2: LIST): LIST;
(*List of rational numbers merge.  L1 and L2 are arbitrary lists of
rational numbers in non-decreasing order.  L is the merge of L1 and L2.
L1 and L2 are modified to produce L.*)
(*goto-free version of LRNM from ALDES implementation guide,
by R. Loos. *) 
VAR  AL1, AL2, L, LP, LS, LP1, LP2, LPP1, LPP2: LIST;
BEGIN
(*1*) (*initialize. *) LP1:=L1; LP2:=L2; L:=SIL; LS:=SIL;
(*2*) (*merge l1 and l2. *) 
      WHILE (LP1 <> SIL) AND (LP2 <> SIL) DO 
            ADV(LP1,AL1,LPP1); ADV(LP2,AL2,LPP2);
            IF RNCOMP(AL1,AL2) < 0 THEN LP:=LP1; LP1:=LPP1;
                         ELSE LP:=LP2; LP2:=LPP2; END;
            IF LS = SIL THEN LS:=LP; L:=LP;
                        ELSE SRED(LS,LP); LS:=LP; END;
            END;
(*3*) (*finish. *) IF LP2 <> SIL THEN LP1:=LP2; END;
      IF LS = SIL THEN L:=LP;
                  ELSE SRED(LS,LP1); END;
      RETURN(L);
(*4*) END LRNM;                                                 


PROCEDURE COMPLF(C,D,KLIST,NP,JP,M: LIST; VAR LFORM,KLISTP,J: LIST); 
(*UGB compute linear form from difference set. 
Diese prozedur berechnet fuer die linearform c und die
menge der schnitte d die neuen linearformen. klist
enthaelt die spuren der schon berechneten linearformen
np entspricht der reduzierten menge  p - p und wird
dazu verwendet um die neuen spuren zu berechnen.
lform enthaelt als ausgabe alle bisher berechneten
linearformen. klistp die dazugehoerigen spuren. alle
spuren sind verschieden.
die funktion wird von der funktion mklf1 aufgerufen. *)
VAR   A, DP, K, KALT, KLISTH, U: LIST;  
BEGIN
(*1*) DP:=D; LFORM:=SIL; J:=JP; KLISTP:=KLIST; KALT:=SIL; 
      KLISTH:=SIL;  
(*2*) WHILE DP <> SIL DO ADV(DP, A,DP); 
            IF M <> 1 THEN A:=COMP(A,C); K:=PKEGEL(A,NP,KALT);  
               U:=COMPA1(K,KLISTP); 
               IF U <> 1 THEN KLISTH:=COMP(K,KLISTH);  
                  LFORM:=COMP(A,LFORM); END; 
               ELSE A:=LIST1(A); LFORM:=COMP(A,LFORM); END; 
            END; 
      KLISTP:=CCONC(KLISTP,KLISTH); 
(*5*) RETURN; END COMPLF; 


PROCEDURE CQ2(C,Q2,M: LIST): LIST; 
(*UGB linear form product with rational exponent vector list. 
Diese prozedur berechnet fuer eine linearform c und eine 
liste q2, beide der gleichen dimension, das produkt c * q2. 
die elemente von c * q2 bestehen aus dem skalarprodukt von
c mit den einzelnen elementen von q2. da diese menge dazu
verwendet wird, um die schnitte zu bilden, werden nur die
negativen elemente gespeichert.
die funktion wird von der funktion mklf1 aufgerufen. *)
VAR   A, AA, CP, J1Y, Q2P, TR: LIST; 
BEGIN
(*1*) CP:=C; Q2P:=Q2; TR:=SIL; 
(*2*) WHILE Q2P <> SIL DO ADV(Q2P, A,Q2P);  
            IF M <> 1 THEN AA:=SCPROD(C,A); J1Y:=LASTEL(A); 
                           AA:=RNSUM(AA,J1Y); 
               ELSE AA:=FIRST(A); END;  
            IF (RNCOMP(AA,0) <= -1) AND (MEMBER(AA,TR) <> 1)
               THEN TR:=COMP(AA,TR); END; 
            END; 
(*5*) RETURN(TR); END CQ2; 


PROCEDURE RNVABS(A: LIST): LIST;  
(*Rational number list absolute values. 
Diese prozedur berechnet fuer die liste a von rational- 
zahlen den absolutbetrag ihrer komponenten. die prozedur
rnabs berechnet den absolutbetrag einer rationalzahl. 
das ergebnis wird in der liste b zurueckgegeben.
die funktion wird von den funktionen mklf1, mklf2 und 
mklf3 aufgerufen. *)
VAR   AA, AP, B: LIST; 
BEGIN
(*1*) AP:=A; B:=SIL;  
(*2*) WHILE AP <> SIL DO ADV(AP, AA,AP); AA:=RNABS(AA); 
            B:=COMP(AA,B); END; 
      B:=INV(B); 
(*5*) RETURN(B); END RNVABS;  


PROCEDURE CUT(TR: LIST): LIST; 
(*UGB set of cuts. 
Berechnet fuer die eingabemenge tr die menge der 
schnitte d. fuer die inneren punkte wird das
algebraische mittel gebildet. fuer die aeusseren punkte
wird 1 addiert beziehungsweise die zahl halbiert.
die funktion wird von den funktionen mklf1, mklf2 und
mklf3 aufgerufen. *)
VAR   A, B, D, ERST, G, H, J, J1Y, J2Y, MITTE, ND, TRACEP, Z: LIST; 
BEGIN
(*1*) TRACEP:=TR; D:=SIL; G:=FIRST(TRACEP); J1Y:=RNINT(0); 
      H:=RNSUM(G,J1Y); J:=LAST(TRACEP); J:=FIRST(J); 
(*2*) J1Y:=RNINT(2); ERST:=RNQ(H,J1Y); J1Y:=RNINT(1); ND:=RNSUM(J,J1Y); 
      D:=COMP(ERST,D); Z:=LENGTH(TRACEP);  
(*3*) WHILE Z >= 2 DO A:=FIRST(TRACEP); B:=SECOND(TRACEP); 
            TRACEP:=RED(TRACEP); Z:=LENGTH(TRACEP); J1Y:=RNSUM(A,B);  
            J2Y:=RNINT(2); MITTE:=RNQ(J1Y,J2Y); D:=COMP(MITTE,D); END; 
      D:=COMP(ND,D); 
(*6*) RETURN(D); END CUT; 


PROCEDURE ALLELN(STAKK,L,KALT,I,PAR: LIST;  VAR LF,NURLF: LIST); 
(*UGB all linear forms from stack of projections. 
Diese funktion berechnet aus dem stapel der projektionen
stakk alle linearformen nurlf. die prozedur mklf1 wird 
aufgerufen.
diese funktion wird von der prozedur lf aufgerufen. *)
VAR   A, IP, J1Y, LFX, LY, M, N, NEWLF, Q2, STAKKP: LIST; 
BEGIN
(*1*) SWRITE("Rekursive Berechnung der Linearformen ... "); BLINES(1); 
      STAKKP:=STAKK; M:=1; IP:=I;  
(*2*) J1Y:=RNINT(1); LFX:=LIST1(J1Y); LY:=SIL; LF:=LIST1(LFX); 
      IP:=IP-1; NEWLF:=SIL;  
      WHILE M <= IP DO ADV(STAKKP, A,STAKKP); N:=FIRST(A); 
            Q2:=SECOND(A); 
            IF PAR = 8 THEN SWRITE("Dimension ..."); OWRITE(M+1); 
               BLINES(1); SWRITE("Die Spur hat "); OWRITE(LENGTH(N)); 
               SWRITE(" Elemente"); BLINES(1); END; 
            NURLF:=MKLF1(LF,Q2,N,M); 
            IF (PAR = 8) AND (M <> IP) THEN 
               SWRITE("Die bisher rekursiv berechneten Linearformen sind "); 
               OWRITE(LENGTH(NURLF)); 
               SWRITE(" Linearformen  "); BLINES(1); END; 
            M:=M+1; LF:=NURLF; END; 
      SWRITE("Die berechneten Linearformen sind "); OWRITE(LENGTH(LF)); 
      SWRITE(" Linearformen  "); BLINES(1); 
(*5*) RETURN; END ALLELN; 


PROCEDURE MKLF1(LFP,Q2,NP,M: LIST): LIST;  
(*UGB make new linear forms 1. 
Diese prozedur berechnet fuer eine liste von linearformen
lfp die neuen linearformen newlf. die menge q2 wird dazu 
verwendet, die schnitte zu berechnen. die menge np 
dient dazu, die ueberfluessigen linearformen zu eliminieren.
diese funktion wird von der prozedur plf und alleln
aufgerufen. *)
VAR   A, B, D, J, J1Y, KLIST, LF, NEWLF, TR: LIST; 
BEGIN
(*1*) LF:=LFP; NEWLF:=SIL; KLIST:=SIL; J:=0;  
(*2*) WHILE LF <> SIL DO D:=SIL; ADV(LF, B,LF); 
            IF Q2 = SIL THEN J1Y:=LIST2(1,1); D:=LIST1(J1Y); 
               ELSE TR:=CQ2(B,Q2,M); TR:=RNVABS(TR); TR:=LRNBMS(TR); 
                    D:=CUT(TR); END; 
            COMPLF(B,D,KLIST,NP,J,M, A,KLIST,J); NEWLF:=USUN(A,NEWLF); 
            END; 
(*5*) RETURN(NEWLF); END MKLF1; 


PROCEDURE NULRNV(A: LIST): LIST;  
(*Rational number vector null test.  
Diese prozedur ueberprueft ob ein vektor a der nullvektor
ist. i ist 1 falls a der nullvektor ist ansonsten 0.
diese funktion wird von der funktion mkset aufgerufen. *)
VAR   AP, B, I: LIST; 
BEGIN
(*1*) AP:=A; I:=1; 
(*2*) WHILE AP <> SIL DO ADV(AP, B,AP); 
            IF B <> 0 THEN I:=0; RETURN(I); END; 
            END; 
(*5*) RETURN(I); END NULRNV;  


PROCEDURE PKEGEL(C,N,KALT: LIST): LIST; 
(*UGB trace for linear form. 
Diese funktion berechnet die spur k bezueglich der linear-
form c und der menge n in kodierter form. die spur wird
nach der methode der wortkodierung (abschnitt 5.1.4)
gebildet. 
diese funktion wird von der funktion complf aufgerufen. *)
VAR   A, AA, B, B2, D, I, J1Y, K, NP: LIST; 
BEGIN
(*1*) A:=KALT; NP:=N; K:=SIL; I:=0; B:=0; B2:=BETA DIV 2; 
(*2*) WHILE NP <> SIL DO ADV(NP, AA,NP); D:=SCPROD(C,AA); 
            J1Y:=LASTEL(AA); D:=RNSUM(D,J1Y); D:=RNSIGN(D); 
            IF D = -1 THEN D:=0; END;  
            J1Y:=2*B; B:=J1Y+D; 
            IF B >= B2 THEN K:=COMP(B,K); B:=0; END; 
            END; 
(*3*) IF B < B2 THEN K:=COMP(B,K); END; 
(*6*) RETURN(K); END PKEGEL;  


PROCEDURE COMPA1(K,KLIST: LIST): LIST;  
(*UGB trace member in trace list. 
Diese funktion stellt fest ob eine spur k in einer liste von
spuren vorhanden ist. j ist gleich 1 falls k in klist liegt,
ansonsten 0.
diese funktion wird von den funktionen complf, clf2, clf3
aufgerufen. *)
VAR   A, J, KLISTP: LIST; 
BEGIN
(*1*) KLISTP:=KLIST; J:=0; 
(*2*) IF KLISTP = SIL THEN J:=0; 
         ELSE
         WHILE KLISTP <> SIL DO ADV(KLISTP, A,KLISTP); 
               J:=COMPA2(K,A);  
               IF J = 1 THEN RETURN(J); END; 
               END;  
         END; 
(*5*) RETURN(J); END COMPA1;  


PROCEDURE COMPA2(K,A: LIST): LIST; 
(*UGB trace compare. 
Diese funktion ueberprueft zwei spuren k und a auf 
gleichheit. u ist gleich 1 falls a und k gleich sind,
ansonsten 0.
diese funktion wird von den funktionen compa1, dfp, dipmc2, 
zulfo und isneu aufgerufen. *)
VAR   AP, B, C, KP, U: LIST; 
BEGIN
(*1*) KP:=K; U:=1; AP:=A; U:=1; 
(*2*) WHILE (KP <> SIL) AND (AP <> SIL) DO 
            ADV(KP, B,KP); ADV(AP, C,AP); 
            IF B <> C THEN U:=0; RETURN(U); END; 
            END; 
      IF (KP <> SIL) OR (AP <> SIL) THEN U:=0; END; 
(*5*) RETURN(U); END COMPA2;  


PROCEDURE LASTEL(Y: LIST): LIST;  
(*Last element. 
X ist das letzte element der liste y. *)
VAR   X, YP: LIST; 
BEGIN
(*1*) YP:=LAST(Y); X:=FIRST(YP); 
(*4*) RETURN(X); END LASTEL;  


PROCEDURE EVLRNBSO(A: LIST); 
(*Rational exponent vector list bubble sort. a is a list of
rational exponent vectors, a is sorted 
with respect to the termordering defined in EVORD 
by the bubble-sort method, two exponent vectors with equal
exponents will lead to an error. the
list a but not its location, is modified.*) 
VAR   AP, APP, B, BP, ELP, ELPP, TL, DUMMY, evo: LIST; 
BEGIN
(*1*) (*Trivial case.*)  
      IF A = 0 THEN RETURN; END;  
      evo:=EVORD; EVORD:=GRLEX; (*???????, others not implem.*) 
(*2*) (*General case.*) B:=SIL;  
      REPEAT AP:=A; ADV(AP, ELP,APP); BP:=SIL; 
             WHILE APP <> B DO ADV(APP, ELPP,DUMMY); (*DIPMAD???*) 
                   TL:=EVRNC(ELP,ELPP);  
                   IF TL = 0 THEN (*GO TO 3;*)
                      (*3*) (*To equal exponent vectors.*) 
                      ERROR(severe,"RNLBSO: To equal exponent vectors"); 
                      EVORD:=evo; RETURN; END; 
                   IF TL > 0 THEN SFIRST(AP,ELPP); SFIRST(APP,ELP); 
                      BP:=APP; ELSE ELP:=ELPP; END;  
                   AP:=APP; APP:=RED(AP); END;  
             B:=BP;  
             UNTIL B = SIL; 
      EVORD:=evo; RETURN; 
(*6*) END EVLRNBSO; 


PROCEDURE EVRNGL(U,V: LIST): LIST; 
(*Rational exponent vector inverse graded lexicographical compare.
u=(ul1, ..., ulrl), v=(vl1, ..., vlrl) are rational exponent vectors.
tl=0 if u eq v. tl=1 if u gt v. tl=-1 if u lt v. eq, gt, lt
with respect to the inverse graded lexicographical ordering
of the exponent vectors. rl is the length of u and v.*)
VAR   SL, TL, UL, ULP, US, VL, VLP, VS: LIST;
BEGIN
(*1*) (*lexicographical compare.*) TL:=0; US:=U; VS:=V;
      LOOP IF US = SIL THEN EXIT END; 
           ADV(US, UL,US); ADV(VS, VL,VS);
           SL:=RNCOMP(UL,VL);
           IF SL > 0 THEN TL:=1; EXIT; ELSE
              IF SL < 0 THEN TL:=-1; EXIT; END;
              END;
           END;
      IF TL = 0 THEN RETURN(TL) END;
(*2*) (*graduaded compare.*)
      WHILE US <> SIL DO ADV(US, ULP,US); ADV(VS, VLP,VS); 
            UL:=RNSUM(UL,ULP); VL:=RNSUM(VL,VLP); END;
      SL:=RNCOMP(UL,VL);
      IF SL <> 0 THEN TL:=SL; END; 
      RETURN(TL);
(*5*) END EVRNGL;


PROCEDURE EVRNC(U,V: LIST): LIST; 
(*Rational exponent vector compare. u=(ul1, ...,ulrl), v=(vl1, ...,vlrl)
are exponent vectors. rl is the length of u and v.
tl=0 if u eq v. tl=1 if u gt v. tl=-1 if u lt v. eq, gt, lt
with respect to the ordering of the exponent vectors specified
in the global variable EVORD. lexicographical, inverse
lexicographical, graded lexicograhpical, inverse graded
lexicographical orderings are possible. *)
VAR   TL: LIST;  
BEGIN
(*1*) (*Compare.*)  
      CASE EVORD OF
           GRLEX : TL:=EVRNGL(U,V); TL:=-TL; | 
           IGRLEX : TL:=EVRNGL(U,V); END; 
(*4*) RETURN(TL); END EVRNC;  


PROCEDURE DEGRE(Q: LIST): LIST; 
(*UGB total degree of a list of rational exponent vectors. 
Q ist eine liste von rationalzahligen tupeln. der maximale
totalgrad der in q vorkommt wird berechnet.
diese prozedur wird von den funktionen projec und proj 
aufgerufen. *)
VAR   A, B, D, D1, H, J1Y, Q1, Q1P, QP, T: LIST; 
BEGIN
(*1*) D:=0; QP:=Q; 
(*2*) WHILE QP <> SIL DO H:=1; ADV(QP, Q1,QP); Q1P:=Q1; 
            WHILE Q1 <> SIL DO ADV(Q1, A,Q1); 
                  IF A <> 0 THEN J1Y:=SECOND(A); H:=ILCM(H,J1Y); END; 
                  END; 
            H:=RNINT(H); D1:=0; 
            WHILE Q1P <> SIL DO ADV(Q1P, B,Q1P); T:=RNPROD(B,H); 
                  T:=RNABS(T); D1:=RNSUM(T,D1); END; 
            D:=RNMAX(D1,D); END; 
      IF D <> 0 THEN D:=FIRST(D) END; 
(*5*) RETURN(D); END DEGRE; 


PROCEDURE RDPAR(): LIST; 
(*UGB read parameter. 
Diese funktion liest aus der eingabedatei den parameter
par. zulaessige werte sind y oder n. bei y werden zwischen
berechnungen ausgegeben, bei n nicht.
diese funktion wird von der prozedur opread aufgerufen. *)
VAR   PAR: LIST; 
BEGIN
(*1*) PAR:=CREADB(); 
(*2*) IF PAR = MASORD("Y") THEN PAR:=8; ELSE 
         IF PAR = MASORD("N") THEN PAR:=9; ELSE
            SWRITE("***  Fehler bei Parameterangabe"); BLINES(1); 
            SWRITE("***  Bitte nur Y oder N angeben"); BLINES(1); 
            PAR:=9; END; 
         END; 
(*5*) RETURN(PAR); END RDPAR; 


PROCEDURE EXECRD(): LIST;  
(*UGB execution options read. 
Diese funktion liest aus der eingabedatei die 
auszufuehrende option. moegliche optionen sind lf  plf  ugb 
und pugb. vor der option muss das wort exec stehen. die
option ist mit einem punkt abzuschliessen.
beispiel  exec ugb.
diese funktion wurde mit geringfuegigen aenderungen aus
der aldes-bibliothek entnommen.
diese funktion wird von der hauptprozedur ugbbin aufgerufen. *)
VAR   A, C, NP, NR, NRLIST, S: LIST; 
BEGIN
(*1*) C:=CREADB(); 
      IF C <> MASORD(".") THEN 
         ERROR(severe,"EXECRD: . expected."); 
         RETURN(NRLIST); END; 
      NRLIST:=SIL;  
(*2*) (* Read exec .*) C:=CREADB(); NP:=SIL;  
(*3*) (* Check options .*) 
      IF LETTER(C) THEN BKSP; S:=SREAD1();  
         IF EQUAL(S,LISTS("EXEC")) = 1 THEN 
            REPEAT C:=CREADB(); 
                   IF C <> MASORD(".") THEN BKSP; A:=SREAD1(); 
                      SEENR(A, NR); 
                      IF NR <> SIL THEN NRLIST:=COMP(NR,NRLIST); 
                      END; 
                      END; 
                   UNTIL C = MASORD("."); 
            ELSE ERROR(severe,"EXECRD: EXEC expected.");  
            RETURN(NRLIST); END; 
         END; 
(*4*) IF NRLIST = SIL THEN 
         ERROR(severe,"EXECRD: no options found.");  
         END;  
(*7*) RETURN(NRLIST); END EXECRD;  


PROCEDURE SEENR(AC: LIST;  VAR NR: LIST);  
(*UGB number of option. 
Diese funktion ermittelt fuer eine option ac eine
schluesselzahl nr. die funktion stammt bis auf einige
aenderungen aus der aldes-bibliothek.
diese funktion wird von der funktion execrd aufgerufen. *)
VAR   NM: LIST; 
BEGIN
(*1*) (*Berechnung der linearformen.*) NM:=LISTS("LF");  
      IF EQUAL(AC,NM) = 1 THEN NR:=1; RETURN; END;  
(*2*) (*Berechnung der linearformen mittels preprocessing*)  
      NM:=LISTS("PLF"); 
      IF EQUAL(AC,NM) = 1 THEN NR:=2; RETURN; END;  
(*3*) (*Universelle groebner basis.*) NM:=LISTS("UGB"); 
      IF EQUAL(AC,NM) = 1 THEN NR:=3; RETURN; END;  
(*4*) (*Universelle groebner basis mittels preprocessing.*)  
      NM:=LISTS("PUGB"); 
      IF EQUAL(AC,NM) = 1 THEN NR:=4; RETURN; END;  
(*8*) (*Error .*) ERROR(severe,"SEENR: unknown option.");
(*11*) RETURN; END SEENR; 


PROCEDURE LFGET(DEG,LF: LIST): LIST;  
(*UGB get linear form from list of linear forms. 
Diese funktion holt aus der liste lf der gespeicherten 
linearformen, abhaengig vom grad deg, die benoetigten
linearformen.
diese funktion wird von den funktionen plf, pugb und pug 
aufgerufen. *)
VAR   D, LFP, LFQ: LIST; 
BEGIN
(*1*) LFP:=LF; D:=0; 
      IF DEG > LENGTH(LF) THEN
         SWRITE("******************************"); BLINES(1); 
         SWRITE(" Berechnung nicht Fortsetzbar "); BLINES(1); 
         SWRITE("        Grad zu hoch          "); BLINES(1); 
         SWRITE("******************************"); BLINES(1); 
         RETURN(SIL); 
      END;  
(*2*) WHILE D < DEG DO ADV(LFP, LFQ,LFP); D:=D+1; END; 
(*5*) RETURN(LFQ); END LFGET; 


PROCEDURE MKLF2(LFP,Q2,NP,M,L: LIST;  VAR NEWLF,LISTLF: LIST); 
(*UGB make new linear forms 2. 
Diese funktion ist genau analog zu mklf1. die linear-
formen werden im gegensatz zu onenlf auch mit der zahl 1 
als letzte komponente der linearformen berechnet.
diese funktion wird von der funktion lfall aufgerufen. *)
VAR   A, AA, B, D, J, J1Y, KLIST, LF, TR: LIST;  
BEGIN
(*1*) LF:=LFP; NEWLF:=SIL; KLIST:=SIL; J:=0; LISTLF:=SIL;  
(*2*) WHILE LF <> SIL DO D:=SIL; ADV(LF, B,LF); 
            IF Q2 = SIL 
               THEN J1Y:=LIST2(1,1); D:=LIST1(J1Y); 
               ELSE TR:=CP2(B,Q2); TR:=RNVABS(TR); 
                    TR:=LRNBMS(TR); D:=CUT(TR); END;  
            CLF2(B,D,KLIST,NP,J,M,L, A,KLIST,J,AA);  
            NEWLF:=USUN(A,NEWLF); LISTLF:=USUN(AA,LISTLF); END; 
(*5*) RETURN; END MKLF2;  


PROCEDURE CLF2(C,D,KLIST,NP,JP,M,L: LIST; VAR LFORM,KLISTP,J,RECLF: LIST);  
(*UGB compute linear form from difference set 2.
Diese funktion funktionniert genauso wie complf, mit dem 
unterschied, dass das element 1 als letzte komponente
der linearform gespeichert wird. 
diese funktion wird von der funktion mklf2 aufgerufen. *)
VAR   A, DP, J1Y, K, KALT, KLISTH, U: LIST; 
BEGIN
(*1*) DP:=D; LFORM:=SIL; J:=JP; KLISTP:=KLIST; KALT:=SIL; 
      KLISTH:=SIL; RECLF:=SIL; 
(*2*) WHILE DP <> SIL DO ADV(DP, A,DP); A:=COMP(A,C);  
            K:=CSPUR(A,NP,KALT); 
            IF M <> 1 THEN U:=COMPA1(K,KLISTP);  
               IF U <> 1 THEN KLISTH:=COMP(K,KLISTH);  
                  J1Y:=LIST4(A,L,K,NP); RECLF:=COMP(J1Y,RECLF); 
                  LFORM:=COMP(A,LFORM); END; 
               ELSE LFORM:=COMP(A,LFORM); J1Y:=LIST4(A,L,K,NP); 
               RECLF:=COMP(J1Y,RECLF); END; 
            END; 
      KLISTP:=CCONC(KLISTP,KLISTH); 
(*5*) RETURN; END CLF2; 


PROCEDURE CP2(C,Q2: LIST): LIST;  
(*UGB linear form product with rational exponent vector list 2. 
Diese funktion funktionniert genauso wie cq2, mit dem
unterschied, dass das element 1 als letzte komponente
der linearform gespeichert wird. 
diese funktion wird von den funktionen mklf2 und mklf3 
aufgerufen. *)
VAR   A, AA, CP, Q2P, TR: LIST;  
BEGIN
(*1*) CP:=C; Q2P:=Q2; TR:=SIL; 
(*2*) WHILE Q2P <> SIL DO ADV(Q2P, A,Q2P); AA:=SCPROD(C,A); 
            IF (RNCOMP(AA,0) <= -1) AND (MEMBER(AA,TR) <> 1)
               THEN TR:=COMP(AA,TR); END; 
            END; 
(*5*) RETURN(TR); END CP2; 


PROCEDURE CSPUR(C,N,KALT: LIST): LIST;  
(*UGB trace for linear form 2. 
Diese funktion funktionniert genauso wie pkegel, mit dem 
unterschied, dass das element 1 als letzte komponente
der linearform gespeichert wird. 
diese funktion wird von den funktionen clf2, clf3 und zulfo 
aufgerufen. *)
VAR   A, AA, B, B2, D, I, J1Y, K, NP: LIST; 
BEGIN
(*1*) A:=KALT; NP:=N; K:=SIL; I:=0; B:=0; B2:=SIL DIV 2; 
(*3*) WHILE NP <> SIL DO ADV(NP, AA,NP); D:=SCPROD(C,AA); 
            D:=RNSIGN(D); 
            IF D = -1 THEN D:=0; END;  
            J1Y:=2*B; B:=J1Y+D; 
            IF B >= B2 THEN K:=COMP(B,K); B:=0; END; 
            END; 
(*4*) IF B < B2 THEN K:=COMP(B,K); END; 
(*7*) RETURN(K); END CSPUR; 


PROCEDURE MKNEWP(P,POL,PRS: LIST): LIST; 
(*UGB make new critical pairs. 
Diese funktion aktualisiert die menge der paare prs der
polynomliste p um die paare der form (pol,f) wobei f aus 
p und pol ein polynom ist. das ergebnis ist ppairs.
das buchberger-kriterium ist implementiert.
diese funktion wird von der funktion gs2 aufgerufen. *)
VAR   C, COL1, COL2, DL, EL, ELI, ELJ, PAIRS, PLI, PP, PPAIRS, SL: LIST; 
BEGIN
(*1*) PP:=P; PPAIRS:=SIL; PAIRS:=PRS; 
(*2*) (*Update pairs .*) COL1:=POL; ELI:=DIPEVL(COL1);  
      WHILE PP <> SIL DO ADV(PP, PLI,PP); COL2:=PLI; 
            ELJ:=DIPEVL(COL2); EL:=EVLCM(ELI,ELJ); SL:=EVSUM(ELI,ELJ); 
            C:=EQUAL(EL,SL);  
            IF C <> 1 THEN DL:=LIST3(EL,POL,PLI); 
               PPAIRS:=COMP(DL,PPAIRS); END; 
            END; 
(*3*) PPAIRS:=EVPLSO(PPAIRS); 
      IF PAIRS <> SIL THEN PAIRS:=INV(CINV(PAIRS)); (*copy*) 
         PPAIRS:=EVPLM(PAIRS,PPAIRS); END;  
(*6*) RETURN(PPAIRS); END MKNEWP;  


PROCEDURE MKPAIR(PP: LIST;  VAR PAIRS: LIST);  
(*UGB make critical pairs for polynomial list. 
Diese funktion berechnet aus der liste pp von polynomen 
die menge der paare pairs. das buchberger-kriterium ist
implementiert. 
diese funktion wird von der funktion gs1 aufgerufen. *) 
VAR   C, COL1, COL2, DL, EL, ELI, ELJ, PI, PJ, PSS, Q, QP, SL: LIST; 
BEGIN
(*1*) PAIRS:=SIL; 
      IF (PP = SIL) OR (RED(PP) = SIL) THEN RETURN; END;  
(*2*) (*Construct pairs. *) PSS:=PP;  
      REPEAT ADV(PSS, PI,QP); COL1:=PI; ELI:=DIPEVL(COL1); 
             WHILE QP <> SIL DO ADV(QP, PJ,QP); COL2:=PJ; 
                   ELJ:=DIPEVL(COL2); EL:=EVLCM(ELI,ELJ);  
                   SL:=EVSUM(ELI,ELJ); C:=EQUAL(EL,SL);  
                   IF C <> 1 THEN DL:=LIST3(EL,PI,PJ); 
                      PAIRS:=COMP(DL,PAIRS); Q:=COMP(PJ,Q); END;  
                   END; 
             PSS:=RED(PSS); 
             UNTIL PSS = SIL; 
(*3*) IF PAIRS <> SIL THEN PAIRS:=EVPLSO(PAIRS); END;  
(*6*) RETURN; END MKPAIR; 


PROCEDURE MKSP1(X,L,PAIRS,I,V: LIST;  VAR D,PAIRSP: LIST); 
(*UGB compute next non-zero reduced S-polynomial.  
Diese funktion bildet bezueglich der linearform x und der
polynommenge l aus der liste von paaren pairs solange
ein s-polynom (dirpsp) und fuehrt es zu normalform (dirrnf) 
bis das s-polynom d nicht null ist oder die liste der paare 
pairsp leer ist.
diese funktion wird von den funktionen ug und pug
aufgerufen. *)
VAR   B, B1, B2, B3, C: LIST;  
BEGIN
(*1*) PAIRSP:=PAIRS; D:=0; 
(*2*) WHILE (PAIRSP <> SIL) AND (D = 0) DO 
            ADV(PAIRSP,B,PAIRSP); FIRST2(RED(B),B2,B3); 
            C:=DIRPSP(B2,B3,X); D:=DIRRNF(L,C,X,V); END; 
(*5*) RETURN; END MKSP1;  


PROCEDURE GS1(LF,V,PAR: LIST): LIST;  
(*UGB generate stack of sorted polynomials and critical pairs 1. 
Lf ist ein tupel der form (a,l,k,n). dabei ist a eine linear-
form, l eine liste von polynomen, k die dazugehoerige
spur und n die reduzierte differenz p - p der 
entsprechenden menge von exponententupel. 
diese prozedur ordnet die polynome nach den linearformen 
und berechnet die menge der dazugehoerigen paare b.
die ausgabe stak besteht aus tupeln der form (a,l,k,n,b).
diese funktion wird von den funktionen ug und pug
aufgerufen. *) 
VAR   A, B, J1Y, J2Y, LFP, LP, PAIRS, STAK, X, evo: LIST; 
BEGIN
(*1*) LFP:=LF; STAK:=SIL; evo:=EVORD; 
      IF PAR = 8 THEN
         SWRITE("Ordne die Polynome nach den Linearformen"); BLINES(1); 
         END; 
(*2*) WHILE LFP <> SIL DO ADV(LFP, A,LFP); FIRST2(A,B,LP); 
            EVORD:=B; LP:=POLCOP(LP); DILBSO(LP);  
            MKPAIR(LP, PAIRS); J1Y:=THIRD(A); J2Y:=FOURTH(A); 
            X:=LIST5(B,LP,J1Y,J2Y,PAIRS); J1Y:=LIST1(X); 
            STAK:=USUN(J1Y,STAK); END; 
      EVORD:=evo;
(*5*) RETURN(STAK); END GS1;  


PROCEDURE MERGE(STALT,STNEU: LIST): LIST;  
(*UGB merge stacks. 
Diese funktion mischt die zwei stapel stalt und stneu zu 
einem stapel stak wie in 5.2.3 beschrieben ist. 
diese funktion wird von der funktion neulf aufgerufen. *)
VAR   A, B, C, D, J1Y, J2Y, STAK, STALTP, STNEUP: LIST; 
BEGIN
(*1*) STALTP:=STALT; STNEUP:=STNEU; STAK:=SIL; 
(*2*) WHILE STALTP <> SIL DO ADV(STALTP, A,STALTP); 
            ADV(STNEUP, B,STNEUP); J1Y:=FIRST(A); J2Y:=FIRST(B); 
            D:=USUN(J1Y,J2Y); 
            J1Y:=SECOND(A); J2Y:=SECOND(B); C:=USUN(J1Y,J2Y); 
            J1Y:=LIST2(D,C); STAK:=COMP(J1Y,STAK); STAK:=INV(STAK); END; 
(*5*) RETURN(STAK); END MERGE;  


PROCEDURE WRUGF(X,V,PAR: LIST): LIST; 
(*Write universal Groebner family. 
Diese funktion gibt eine berechnete universelle 
groebnerfamilie  auf dem ausgabegeraet aus. es wird
jeweils eine linearform und die dazugehoerige polynommenge
ausgegeben. 
diese funktion wird von den prozeduren ugb und pugb
aufgerufen. *)
VAR   evo, A, L, LP, p, UL, XP: LIST; 
BEGIN
(*1*) XP:=X; UL:=SIL; 
      IF PAR = 8 THEN
         SWRITE("        ************************************"); BLINES(1); 
         SWRITE("             Universelle Groebnerfamilie"); BLINES(1);  
         SWRITE("        ************************************"); BLINES(2); 
         END;
      evo:=EVORD; EVORD:=INVLEX; 
(*2*) WHILE XP <> SIL DO ADV(XP, A,XP); 
            IF PAR = 8 THEN
               SWRITE("-----------------------------"); BLINES(1); 
               OWRITE(FIRST(A)); BLINES(1); 
               SWRITE("-----------------------------"); BLINES(1); 
               DIRLWR(SECOND(A),V,-1); BLINES(1); END; 
            L:=SECOND(A); L:=POLCOP(L); DILBSO(L);   
            LP:=L; 
            WHILE LP <> SIL DO p:=DIRPMC(FIRST(LP)); 
                  SFIRST(LP,p); LP:=RED(LP); END;      
            UL:=USUN(L,UL); END; 
      UL:=DIPLPM(UL); EVORD:=evo;
(*5*) RETURN(UL); END WRUGF;  


PROCEDURE WRUGB(UL,V: LIST);  
(*Write universal Groebner base. 
Diese funktion gibt eine berechnete universelle 
groebnerbasis ul auf dem ausgabegeraet aus.
diese prozedur wird von den prozeduren ugb und pugb
aufgerufen. *)
BEGIN
(*1*) SWRITE("       ************************************"); BLINES(1); 
      SWRITE("              Universelle Groebnerbasis"); BLINES(1); 
      SWRITE("       ************************************"); BLINES(1); 
      DIRLWR(UL,V,-1);  
(*4*) RETURN; END WRUGB;  


PROCEDURE POLCOP(L: LIST): LIST;  
(*Two level list copy. 
Diese funktion macht eine kopie p der polynomliste l.
diese funktion wird von den funktionen gs1, gs2 und wrugf
aufgerufen. *)
VAR   A, B, J1Y, LP, P: LIST;  
BEGIN
(*1*) LP:=L; P:=SIL;  
(*2*) WHILE LP <> SIL DO ADV(LP, A,LP); B:=INV(CINV(A)); 
            P:=COMP(B,P); END;  
      P:=INV(P); 
(*5*) RETURN(P); END POLCOP;  


PROCEDURE DFP(A,B: LIST): LIST; 
(*UGB distributive rational polynomial difference. 
Diese funktion bildet aus den beiden polynomen a und b 
die distributive differenz a - b. das ergebnis ist cp. 
diese funktion unterscheidet sich von der in der aldes 
bibliothek vorhandenen funktion. sie berechnet die 
differenz bezueglich der in der globalen variablen 
EVORD gesetzten ordnung.
diese funktion wird von den funktionen dirrnf und dirpsp 
aufgerufen. *)
VAR   AL, AP, APP, BL, BP, C, CL, CP, CPP, EL, FL, SL: LIST; 
BEGIN
(*1*) (* a or b zero.*) 
      IF A = 0 THEN C:=DIRPNG(B); RETURN(C); END; 
      IF B = 0 THEN C:=A; RETURN(C); END; 
(*2*) (*match coefficients.*) AP:=A; BP:=B; CP:=SIL; 
      REPEAT EL:=DIPEVL(AP); FL:=DIPEVL(BP); 
             SL:=EVCOMP(EL,FL); 
             IF SL = 0 THEN SL:=EVILCP(EL,FL); END;
             IF SL = 1 THEN DIPMAD(AP, AL,EL,AP); 
                CP:=DIPMCP(EL,AL,CP); ELSE
                IF SL = -1 THEN DIPMAD(BP, BL,FL,BP); 
                   CL:=RNNEG(BL); CP:=DIPMCP(FL,CL,CP); 
                   ELSE DIPMAD(AP,AL,EL,AP); DIPMAD(BP, BL,FL,BP); 
                   CL:=RNDIF(AL,BL); 
                   IF CL <> 0 THEN CP:=DIPMCP(EL,CL,CP); END; 
                   END; 
                END; 
             UNTIL (AP = SIL) OR (BP = SIL); 
(*3*) (*finish.*) APP:=AP; 
      IF AP = SIL THEN
         IF BP <> SIL THEN APP:=DIRPNG(BP); END; 
         END; 
      IF CP = SIL THEN C:=APP; ELSE CPP:=CP; C:=INV(CP); 
         SRED(CPP,APP); END; 
      IF C = SIL THEN C:=0; END; 
      RETURN(C); 
(*5*) END DFP; 


PROCEDURE SFP(A,B: LIST): LIST; 
(*UGB distributive rational polynomial sum. 
Diese funktion bildet aus den beiden polynomen a und b 
die distributive summe a + b. das ergebnis ist cp. 
diese funktion unterscheidet sich von der in der aldes 
bibliothek vorhandenen funktion. sie berechnet die 
differenz bezueglich der in der globalen variablen 
EVORD gesetzten ordnung.
diese funktion wird von den funktionen dirrnf aufgerufen. *)
VAR   AL, AP, APP, BL, BP, C, CL, CP, CPP, EL, FL, SL: LIST; 
BEGIN
(*1*) (* a or b zero.*) 
      IF A = 0 THEN C:=B; RETURN(C); END; 
      IF B = 0 THEN C:=A; RETURN(C); END; 
(*2*) (*match coefficients.*) AP:=A; BP:=B; CP:=SIL; 
      REPEAT EL:=DIPEVL(AP); FL:=DIPEVL(BP); 
             SL:=EVCOMP(EL,FL); 
             IF SL = 0 THEN SL:=EVILCP(EL,FL); END;
             IF SL = 1 THEN DIPMAD(AP, AL,EL,AP); 
                CP:=DIPMCP(EL,AL,CP); ELSE
                IF SL = -1 THEN DIPMAD(BP, BL,FL,BP); 
                   CP:=DIPMCP(FL,BL,CP); 
                   ELSE DIPMAD(AP,AL,EL,AP); DIPMAD(BP, BL,FL,BP); 
                   CL:=RNSUM(AL,BL); 
                   IF CL <> 0 THEN CP:=DIPMCP(EL,CL,CP); END; 
                   END; 
                END; 
             UNTIL (AP = SIL) OR (BP = SIL); 
(*3*) (*finish.*) APP:=AP; 
      IF AP = SIL THEN
         IF BP <> SIL THEN APP:=BP; END; 
         END; 
      IF CP = SIL THEN C:=APP; ELSE CPP:=CP; C:=INV(CP); 
         SRED(CPP,APP); END; 
      IF C = SIL THEN C:=0; END; 
      RETURN(C); 
(*5*) END SFP; 


PROCEDURE EVLFCP(L,U,V: LIST): LIST;  
(*UGB exponent vector linear form compare. 
Diese funktion vergleicht die exponententupel u und v
zweier terme bezueglich der linearform l. das ergebnis 
t ist gleich 1 falls u groesser als v ist, 0 falls sie 
gleich sind  und -1 ansonsten.
diese funktion wird von der funktion evcomp aufgerufen. *)
VAR   A, B, T: LIST;  
BEGIN
(*1*) A:=SKPRO2(L,U); B:=SKPRO2(L,V); T:=RNCOMP(A,B); 
(*4*) RETURN(T); END EVLFCP;  


PROCEDURE PCOMP(X,Y: LIST): LIST; 
(*UGB distributive polynomial composition. 
Diese funktion bildet aus den beiden polynomen x und y 
ein polynom z, sodass das polynom x der ersten teil, und 
y der zweite teil ist.
diese funktion wird von den funktionen dfp und dipmc2
aufgerufen. *)
VAR   A, C, XP, Z: LIST;  
BEGIN
(*1*) XP:=X; Z:=Y; 
(*2*) IF X = SIL THEN Z:=Y; RETURN(Z); END;  
(*3*) IF Y = SIL THEN Z:=X; RETURN(Z); END;  
      WHILE XP <> SIL DO DIPMAD(XP, A,C,XP); Z:=DIPMCP(A,C,Z); END; 
(*6*) RETURN(Z); END PCOMP; 


PROCEDURE EVCOMP(U,V: LIST): LIST; 
(*UGB exponent vector compare. 
Diese funktion vergleicht die exponententupel u und v
zweier terme bezueglich der termordnung, die in der
globalen variable EVORD gespeichert ist. das ergebnis
tl ist gleich 1 falls u groesser als v ist, 0 falls sie
gleich sind  und -1 ansonsten. *)
VAR   TL: LIST;  
BEGIN
(*1*) (*Compare with linear form.*) 
      IF EVORD > SIL THEN TL:=EVLFCP(EVORD,U,V); RETURN(TL); END; 
(*2*) (*Compare with evord.*)  
      CASE EVORD OF
           LEX    : TL:=EVILCP(U,V); TL:=-TL |
           INVLEX : TL:=EVILCP(U,V); |
           GRLEX  : TL:=EVIGLC(U,V); TL:=-TL | 
           IGRLEX : TL:=EVIGLC(U,V); END; 
(*5*) RETURN(TL); END EVCOMP; 


PROCEDURE DIPMC2(A,C,P: LIST): LIST;  
(*UGB distributive polynomial composition 2. 
Diese funktion bildet aus dem koeffizient a, dem term c
und dem polynom p ein neues polynom dp.
diese funktion wird von der funktione dirrnf aufgerufen. *)
VAR   AA, AP, CC, DP, PP, U: LIST; 
BEGIN
(*1*) PP:=P; DP:=SIL; U:=0; AP:=A; 
(*2*) WHILE (PP <> SIL) AND (U <> 1) DO DIPMAD(PP, AA,CC,PP);  
            U:=COMPA2(CC,C);  
            IF U = 1 THEN AP:=RNSUM(AP,AA); 
               ELSE DP:=DIPMCP(AA,CC,DP); END; 
            END; 
      DP:=PCOMP(PP,DP); 
      IF AP <> 0 THEN DP:=DIPMCP(AP,C,DP); END;  
(*5*) RETURN(DP); END DIPMC2; 


PROCEDURE DIRRNF(P,S,X,V: LIST): LIST;  
(*UGB distributive polynomial normalform. 
Diese funktion berechnet die normalform r eines polynoms 
s mit rationalen koeffizienten bezueglich der liste von
polynomen p und der ordnung, die von der linearform x
induziert wird.
diese funktion wird von der funktione mksp1 aufgerufen. *) 
VAR   AP, APP, BL, FL, PP, Q, QA, QE, QP, R, RP, SL, SP, TA, TE: LIST; 
BEGIN
(*1*) (*S=0. *) 
      IF (S = 0) OR (P = SIL) THEN R:=S; RETURN(R); END;  
(*2*) (*Reduction step.*) R:=0; SP:=S;  
      REPEAT DIPMAD(SP, TA,TE,SP); 
             IF SP = SIL THEN SP:=0; END;  
             PP:=P;  
             REPEAT ADV(PP, Q,PP); DIPMAD(Q, QA,QE,QP); SL:=EVMT(TE,QE); 
                    UNTIL (PP = SIL) OR (SL = 1); 
             IF SL = 0 THEN RP:=DIPFMO(TA,TE); R:=SFP(R,RP); 
                ELSE
                IF QP <> SIL THEN FL:=EVDIF(TE,QE); BL:=RNQ(TA,QA); 
                   AP:=DIPFMO(BL,FL); APP:=DIRPPR(QP,AP);  
                   SP:=DFP(SP,APP); END; 
                END; 
             UNTIL SP = 0; 
(*3*) (*Finish.*) 
(*6*) RETURN(R); END DIRRNF;  


PROCEDURE DIRPSP(A,B,X: LIST): LIST;  
(*UGB distributive polynomial S-polynomial. 
Diese funktion berechnet das s-polynom c der polynome a
und b bezueglich der ordnung, die von der linearform x 
induziert wird.
diese funktion wird von der funktion mksp1 aufgerufen. *) 
VAR   evo, AL, AP, APP, BL, BP, BPP, C, CL, EL, EL1, FL, FL1, GL: LIST; 
BEGIN
(*1*) C:=0;  
      IF (A = 0) OR (B = 0) THEN RETURN(C); END; 
      DIPMAD(A, AL,EL,AP); DIPMAD(B, BL,FL,BP); 
      IF (AP = SIL) AND (BP = SIL) THEN RETURN(C); END; 
(*2*) (*Reduction. *) GL:=EVLCM(EL,FL); 
      IF AP = SIL THEN FL1:=EVDIF(GL,FL); CL:=RNNEG(AL); 
         BPP:=DIPFMO(CL,FL1); C:=DIRPPR(BP,BPP); RETURN(C); END;  
      IF BP = SIL THEN EL1:=EVDIF(GL,EL); APP:=DIPFMO(BL,EL1); 
         C:=DIRPPR(AP,APP); RETURN(C); END; 
(*3*) (*General case. *) evo:=EVORD; EVORD:=X; 
      EL1:=EVDIF(GL,EL); FL1:=EVDIF(GL,FL); 
      APP:=DIPFMO(BL,EL1); BPP:=DIPFMO(AL,FL1); APP:=DIRPPR(AP,APP); 
      BPP:=DIRPPR(BP,BPP); C:=DFP(APP,BPP); (*????*)
      EVORD:=evo;
(*6*) RETURN(C); END DIRPSP;  


PROCEDURE UG(LF,I,V,STAP,P,NURLF,PAR: LIST): LIST;  
(*Universal Groebner base. 
Diese funktion berechnet eine universelle groebner-
familie ugf. lf sind tupel der form (a,l,k,n), wobei l 
die eingabemenge von polynomen, a eine von allen
dazugehoerigen linearformen, k die spur und n die
reduzierte differenz der eingabemenge der exponententupel
ist. die berechnung realisiert die option ugb.
diese funktion wird von der funktion ugb aufgerufen. *)
VAR   evo, D, DS, DSUM, FLAG, J1Y, J2Y, J3Y, L, LFALT, LFEND, LFNEU, LFP, 
      LFTEMP, LNEU, LSUM, PAARE, PAIRS, SEMA, STAPP, U, UGF, X: LIST; 
      fin: BOOLEAN;
BEGIN
(*1*) UGF:=SIL; LFP:=LF; STAPP:=STAP; LFTEMP:=SIL; LFEND:=SIL; 
(*2*) LFP:=GS1(LFP,V,PAR); LSUM:=EXPTU(P); DSUM:=SIL; LFALT:=NURLF; 
      IF PAR = 8 THEN SWRITE("Reduktionsschritt"); BLINES(1); END; 
      evo:=EVORD; 
REPEAT  
(*3*) LSUM:=USUN(LSUM,DSUM); LFTEMP:=SIL; FLAG:=0; DSUM:=SIL; 
      WHILE LFP <> SIL DO DS:=SIL; ADV(LFP, X,LFP); 
            EVORD:=FIRST(X); L:=SECOND(X); PAIRS:=LASTEL(X);  
            MKSP1(FIRST(X),L,PAIRS,I,V, D,PAARE); 
            IF D = 0 THEN UGF:=COMP(X,UGF); J1Y:=FIRST(X); 
                          LFEND:=COMP(J1Y,LFEND); 
               ELSE LNEU:=COMP(D,L);  
               J1Y:=LIST1(D); DSUM:=USUN(J1Y,DSUM); J1Y:=FIRST(X);  
               J2Y:=THIRD(X); J3Y:=FOURTH(X); 
               J1Y:=LIST5(J1Y,LNEU,J2Y,J3Y,PAARE); 
               LFTEMP:=COMP(J1Y,LFTEMP); FLAG:=1; END; 
            END; 
LOOP fin:=FALSE; 
      IF FLAG = 1 THEN ISNEU(DSUM,LSUM,PAR, SEMA,DSUM);  
         IF SEMA = 1 THEN NEULF(STAPP,DSUM,LSUM,I,V,PAR,LFNEU,STAPP); 
            U:=ISNEUL(LFNEU,LFALT,PAR); LFALT:=LFNEU; 
            IF U = 0 THEN
               IF PAR = 8 THEN SWRITE("Keine neuen Linearformen"); 
                  BLINES(1); END;  
               LFP:=NONEWL(LFTEMP); LFP:=GS2(LFP,V,PAR); BLINES(1); 
               EXIT; (*GO TO 3*) END; 
            IF U = 1 THEN
               IF PAR = 8 THEN
                  SWRITE("Neue Linearformen entstanden "); BLINES(1); 
                  END; 
               LFP:=NEWL(LFTEMP,LFNEU,LFEND); BLINES(1); 
               LFP:=GS2(LFP,V,PAR); EXIT; (*GO TO 3*) END; 
            END; 
         IF SEMA = 0 THEN LFP:=NONEWL(LFTEMP); LFP:=GS2(LFP,V,PAR); 
            BLINES(1); EXIT; (*GO TO 3*) END; 
         END; 
fin:=TRUE; EXIT END; (*loop*)
UNTIL fin;
      EVORD:=evo;
(*6*) RETURN(UGF); END UG; 


PROCEDURE PUG(LF,I,V,P,DEGP,NURLF,PAR,LFQ: LIST): LIST; 
(*Universal Groebner base using precomputation.
Diese funktion berechnet eine universelle groebner-
familie ugf. lf sind tupel der form (a,l,k,n), wobei l 
die eingabemenge von polynomen, a eine von allen
dazugehoerigen linearformen, k die spur und n die
reduzierte differenz der eingabemenge der exponententupel
ist.
die berechnung realisiert die option pugb.
diese funktion wird von der funktion pugb aufgerufen. *)
VAR   evo, D, DEG, DEG1, DS, DSUM, DSUM1, FLAG, J1Y, J2Y, J3Y, L, LFALT,
      LFEND, LFNEU, LFP, LFTEMP, LNEU, LSUM, PAARE, PAIRS, R, SEMA, U,
      UGF, X: LIST; 
      fin: BOOLEAN;
BEGIN
(*1*) UGF:=SIL; LFP:=LF; LFTEMP:=SIL; LFEND:=SIL; DEG:=DEGP; 
(*2*) LFP:=GS1(LFP,V,PAR); LSUM:=EXPTU(P); DSUM:=SIL; LFALT:=NURLF; 
      IF PAR = 8 THEN SWRITE("Reduktionsschritt"); BLINES(1); END; 
      evo:=EVORD; 
REPEAT  
(*3*) LSUM:=USUN(LSUM,DSUM); LFTEMP:=SIL; FLAG:=0; DSUM:=SIL; 
      WHILE LFP <> SIL DO DS:=SIL; ADV(LFP, X,LFP); 
            EVORD:=FIRST(X); L:=SECOND(X); PAIRS:=LASTEL(X);  
            MKSP1(FIRST(X),L,PAIRS,I,V, D,PAARE); 
            IF D = 0 THEN UGF:=COMP(X,UGF); J1Y:=FIRST(X); 
                          LFEND:=COMP(J1Y,LFEND); 
               ELSE LNEU:=COMP(D,L);  
               J1Y:=LIST1(D); DSUM:=USUN(J1Y,DSUM); J1Y:=FIRST(X);  
               J2Y:=THIRD(X); J3Y:=FOURTH(X); 
               J1Y:=LIST5(J1Y,LNEU,J2Y,J3Y,PAARE); 
               LFTEMP:=COMP(J1Y,LFTEMP); FLAG:=1; END; 
            END; 
LOOP fin:=FALSE; 
      IF FLAG = 1 THEN DSUM1:=DSUM; ISNEU(DSUM,LSUM,PAR,SEMA,DSUM); 
         IF SEMA = 1 THEN DEG1:=LDEG(DSUM1); 
            IF PAR = 8 THEN SWRITE("Grad der Polynome  ");  
               OWRITE(DEG1); BLINES(1); END; 
            IF DEG1 > DEG THEN SWRITE("Lese Linearfomen ... ");  
               IF I = 2 THEN IQR(DEG1,2, DEG1,R); 
                  IF R <> 0 THEN DEG1:=DEG1+1; END;  
                  END; 
               IF PAR = 8 THEN BLINES(1); END;  
               LFNEU:=LFGET(DEG1,LFQ); LFNEU:=DO1(LFNEU);  
               U:=ISNEUL(LFNEU,LFALT,PAR); DEG:=DEG1; 
               ELSE U:=0; LFNEU:=LFALT; END;  
            LFALT:=LFNEU; 
            IF U = 0 THEN
               IF PAR = 8 THEN SWRITE("Keine neuen Linearformen"); 
                  BLINES(1); END;  
               LFP:=NONEWL(LFTEMP); LFP:=GS2(LFP,V,PAR); BLINES(1); 
               EXIT; (*GO TO 3*) END;  
            IF U = 1 THEN
               IF PAR = 8 THEN
                  SWRITE("Neue linearformen entstanden "); BLINES(1); 
                  END; 
               LFP:=NEWL(LFTEMP,LFNEU,LFEND); BLINES(1); 
               LFP:=GS2(LFP,V,PAR); EXIT; (*GO TO 3*) END; 
            END; 
         IF SEMA = 0 THEN LFNEU:=LFALT; LFP:=NONEWL(LFTEMP); 
            BLINES(1); LFP:=GS2(LFP,V,PAR); BLINES(1); 
            EXIT; (*GO TO 3*) END;  
         END; 
fin:=TRUE; EXIT END; (*loop*)
UNTIL fin;
      EVORD:=evo;
(*6*) RETURN(UGF); END PUG; 


PROCEDURE NEWL(LFTEMP,LFNEU,LFEND: LIST): LIST;  
(*UGB update linear forms from new terms. 
Lfneu ist die menge der linearformen auf der neuen menge 
von termen. die funktion stellt fest welche von diesen 
linearformen die alten fortsetzen und aktualisiert 
das zwischenergebnis lftemp durch lfp. 
die funktion wird auch nur aufgerufen wenn neue 
linearformen enstanden sind.
diese funktion wird von den funktionen ug und pug
aufgerufen. *)
VAR   LF, LFNEUP, LFP, LL, SP, X: LIST; 
BEGIN
(*1*) SP:=LFTEMP; LFNEUP:=LFNEU; LL:=SIL;  
(*2*) WHILE SP <> SIL DO ADV(SP, X,SP); 
            ZULFO(LFNEUP,X,LL,LFEND,LFP,LF); 
            LFNEUP:=LF; LL:=LFP; END;  
(*5*) RETURN(LFP); END NEWL;  


PROCEDURE ZULFO(LFNEU,X,LL,LFEND: LIST;  VAR LFP,LF: LIST);  
(*UGB find admissible extensions of linear forms. 
Diese funktion stellt fest, welche linearformen aus lfneu
die linearform von x fortsetzen. diese linearformen mit
den aktualisierten daten (spur, paare) ersetzen dann x 
in ll. das ergebnis ist lfp.
diese funktion wird von der funktion newl aufgerufen. *)
VAR   A, D, DIFNEU, J1Y, K1, KALT, L, LFNEU1, LFNEUP, LNEU, NEWKEG, U: LIST; 
BEGIN
(*1*) LFNEUP:=LFNEU; KALT:=SIL; LFNEU1:=SIL; LFP:=LL;  
(*2*) WHILE LFNEUP <> SIL DO ADV(LFNEUP, A,LFNEUP); J1Y:=FOURTH(X); 
            K1:=CSPUR(A,J1Y,KALT); J1Y:=THIRD(X); U:=COMPA2(J1Y,K1); 
            IF U = 1 THEN LNEU:=SECOND(X); ADV(LNEU, D,L); 
               J1Y:=FOURTH(X); DIFNEU:=NEWDIF(L,D,J1Y);  
               NEWKEG:=CSPUR(A,DIFNEU,KALT); J1Y:=LASTEL(X);  
               J1Y:=LIST5(A,LNEU,NEWKEG,DIFNEU,J1Y); LFP:=COMP(J1Y,LFP); 
               ELSE LFNEU1:=COMP(A,LFNEU1); END;  
            END; 
      LF:=LFNEU1; 
(*5*) RETURN; END ZULFO;  


PROCEDURE NONEWL(LFTEMP: LIST): LIST; 
(*UGB update linear forms without new terms. 
Diese funktion wird aufgerufen wenn keine linearformen 
entstanden sind. sie aktualisiert lftemp durch lfp.
diese funktion wird von den funktionen ug und pug
aufgerufen. *)
VAR   D, DIFNEU, J1Y, J2Y, KALT, L, LFP, LFTEP, LNEU, NEWKEG, X: LIST; 
BEGIN
(*1*) LFTEP:=LFTEMP; KALT:=SIL; LFP:=SIL; 
(*2*) WHILE LFTEP <> SIL DO ADV(LFTEP, X,LFTEP); LNEU:=SECOND(X);  
            ADV(LNEU, D,L); J1Y:=FOURTH(X); DIFNEU:=NEWDIF(L,D,J1Y); 
            J1Y:=FIRST(X); NEWKEG:=CSPUR(J1Y,DIFNEU,KALT); 
            J1Y:=FIRST(X); J2Y:=LASTEL(X);  
            J1Y:=LIST5(J1Y,LNEU,NEWKEG,DIFNEU,J2Y); LFP:=COMP(J1Y,LFP); 
            END; 
(*5*) RETURN(LFP); END NONEWL;  


PROCEDURE ISNEUL(LFALT,LFNEU,PAR: LIST): LIST; 
(*UGB new linear form test.
Lfalt ist die alte liste von linearformen, lfneu die
neue. diese funktion stellt fest ob neue linearformen
entstanden sind (u gleich 1) oder nicht (u gleich 0).
diese funktion wird von den funktionen ug und pug
aufgerufen. *)
VAR   I, J, U: LIST;  
BEGIN
(*1*) I:=LENGTH(LFALT); J:=LENGTH(LFNEU);  
(*2*) IF I = J THEN U:=0; ELSE U:=1; END;  
(*5*) RETURN(U); END ISNEUL;  


PROCEDURE NEULF(STAP,DSUM,LSUM,I,V,PAR: LIST; VAR LFNEU,NEUST: LIST); 
(*UGB compute new linear forms from new terms. 
Diese funktion berechnet, nachdem neue terme entstanden
sind, die neuen linearformen. die berechnung basiert
auf die bereits beschriebenen funktionen und prozeduren
zur berechnung von linearformen. 
dsum ist die liste der neuen s-polynome, lsum die liste
der alten polynome, stap der alte stapel der projektionen.
das ergebnis ist die liste der neuen linearformen lfneu
und der neue stapel von projektionen neust.
diese funktion wird von der funktion ug aufgerufen. *)
VAR   DIFALT, E, KALT, OLDL, PSUM: LIST; 
BEGIN
(*1*) E:=DSUM; E:=MAKERN(E); DIFALT:=SIL; OLDL:=SIL; KALT:=SIL;  
(*2*) PSUM:=LSUM; PSUM:=MAKERN(PSUM); NEUST:=SIL; 
      OLDL:=LIST3(SIL,SIL,SIL); 
(*3*) NEUST:=PROJEC(PSUM,E,DIFALT,OLDL,I,PAR);  
(*4*) NEUST:=MERGE(STAP,NEUST); 
(*5*) LFNEU:=ALLLF(NEUST,KALT,I);  
(*8*) RETURN; END NEULF;  


PROCEDURE ISNEU(DSUM,LSUM,PAR: LIST;  VAR SEMA,DD: LIST); 
(*UGB new terms test. 
Diese funktion stellt fest, ob neue terme in dusm entstanden
sind. 
dsum ist die liste der neuen s-polynome in normalform, 
lsum die alte liste von polynomen. die ausgabe sema ist
gleich 1 falls neue terme entstanden sind. ansonsten 0.
dd ist die liste der neuen terme.
diese funktion wird von den funktionen ug und pug
aufgerufen. *)
VAR   A, B, D, LP, TEMP, U, COUNT: LIST;  
BEGIN
(*1*) LP:=LSUM; D:=EXPTU(DSUM); COUNT:=0; DD:=SIL;  
(*2*) WHILE D <> SIL DO ADV(D, A,D); TEMP:=SIL; U:=0; 
            WHILE (LP <> SIL) AND (U <> 1) DO ADV(LP, B,LP); 
                  U:=COMPA2(A,B);  
                  IF U <> 1 THEN TEMP:=COMP(B,TEMP); END; 
                  END; 
            LP:=TCOMP(TEMP,LP); 
            IF U <> 1 THEN COUNT:=COUNT+1; DD:=COMP(A,DD); END; 
            END; 
      IF COUNT > 0 THEN SEMA:=1;  
         IF (COUNT = 1) AND (PAR = 8) THEN 
            SWRITE("Es ist nur ein neuer Term entstanden"); BLINES(1); 
            END; 
         IF (COUNT >= 2) AND (PAR = 8) THEN 
            SWRITE("es sind "); OWRITE(COUNT); 
            SWRITE(" neue Terme entstanden"); BLINES(1); END; 
         END; 
      IF COUNT = 0 THEN SEMA:=0;  
         IF PAR = 8 THEN 
            SWRITE("es ist kein neuer Term entstanden"); BLINES(1); 
         END; 
         END; 
(*5*) RETURN; END ISNEU;  


PROCEDURE TCOMP(X,Y: LIST): LIST; 
(*UGB list constructive conc. ??CCONC??
X und y sind zwei listen. diese prozedur konkatiniert sie
zu einer liste z.
diese funktion wird von der funktion isneu aufgerufen. *)
VAR   A, XP, Z: LIST; 
BEGIN
(*1*) XP:=X; Z:=Y; 
(*2*) IF X = SIL THEN Z:=Y; RETURN(Z); END;  
(*3*) IF Y = SIL THEN Z:=X; RETURN(Z); END;  
      WHILE XP <> SIL DO ADV(XP, A,XP); Z:=COMP(A,Z); END; 
(*6*) RETURN(Z); END TCOMP; 


PROCEDURE NEWDIF(L,D,DIFALT: LIST): LIST;  
(*UGB exponent vector list difference from polynomials. 
Diese funktion liest durch die funktion exptu die
exponententupel der terme von l und d und berechnet mit
hilfe der funktion pdif die differenz. fuer die 
berechnung der neuen differenz wird das schon berechnete 
ergebnis genutzt.
diese funktion wird von den funktionen zulfo und nonewl
aufgerufen. *) 
VAR   D1, D2, DIFALP, DIFNEU, J1Y, L1, L2: LIST; 
BEGIN
(*1*) L2:=EXPTU(L); L1:=MAKERN(L2); J1Y:=LIST1(D); D2:=EXPTU(J1Y);  
      D1:=MAKERN(D2); DIFALP:=DIFALT;  
(*2*) DIFNEU:=PDIF(L1,D1,DIFALP);  
(*5*) RETURN(DIFNEU); END NEWDIF;  


PROCEDURE GS2(LF,V,PAR: LIST): LIST;  
(*UGB generate stack of sorted polynomials and critical pairs 2.
Diese funktion funktioniert aehnlich zu gs1. sie ist wegen
der uebersichtlichkeit getrennt geschrieben. die funktion
aktualisiert die zwischenergebnisse lf (tupel der form 
(a,l,k,n,b) wie die ausgabe von gs1), d.h sie ordnet
die polynome neu und aktualisiert die mengen von paaren. 
diese funktion wird von den funktionen ug und pug
aufgerufen. *)
VAR   evo, A, B, J1Y, J2Y, J3Y, LFP, LP, LP1, PAIRS, STAK, X: LIST;  
BEGIN
(*1*) LFP:=LF; STAK:=SIL; evo:=EVORD; 
      IF PAR = 8 THEN
         SWRITE("Ordne die Polynome nach den neuen Linearformen"); 
         BLINES(1); END;  
(*2*) WHILE LFP <> SIL DO ADV(LFP, A,LFP); B:=FIRST(A); 
            LP:=SECOND(A); EVORD:=B; LP:=POLCOP(LP); DILBSO(LP);  
            LP1:=LP; J1Y:=RED(LP); J2Y:=FIRST(LP); J3Y:=LASTEL(A);  
            PAIRS:=MKNEWP(J1Y,J2Y,J3Y); J1Y:=THIRD(A); J2Y:=FOURTH(A); 
            X:=LIST5(B,LP1,J1Y,J2Y,PAIRS); J1Y:=LIST1(X);  
            STAK:=USUN(J1Y,STAK); END; 
      EVORD:=evo; 
(*5*) RETURN(STAK); END GS2;  


PROCEDURE ALLLF(STAKK,KALT,I: LIST): LIST; 
(*UGB all linear forms from stack of projections and print. 
Die funktion funktionniert genauso wie lfall. hier 
werden nur die linearformen berechnet und ausgegeben.
diese funktion wird von der funktion neulf aufgerufen. *)
VAR   A, IP, J1Y, LENG, LF, LFX, LISTLF, LY, M, N, NEWLF, NURLF, Q2, 
      STAKKP: LIST; 
BEGIN
(*1*) STAKKP:=STAKK; M:=1; IP:=I; LISTLF:=SIL; 
(*2*) J1Y:=RNINT(1); LFX:=LIST1(J1Y); LY:=SIL; LF:=LIST1(LFX); 
      IP:=IP-1; NEWLF:=SIL;  
      WHILE M <= IP DO ADV(STAKKP, A,STAKKP); N:=FIRST(A); 
            Q2:=SECOND(A); NURLF:=MKLF3(LF,Q2,N,M); M:=M+1; LF:=NURLF; 
            END; 
      SWRITE("Die disjunkten Linearformen sind "); OWRITE(LENGTH(NURLF)); 
      SWRITE(" Linearformen  "); BLINES(1); NURLF:=LF;  
(*5*) RETURN(NURLF); END ALLLF; 


PROCEDURE LFALL(STAKK,L,KALT,I: LIST; VAR LISTLF,NURLF: LIST); 
(*UGB all linear forms from stack of projections 1. 
Diese funktion funktionniert genauso wie alleln, mit dem 
unterschied, dass das element 1 als letzte komponente
der linearform gespeichert wird. 
diese funktion wird von der funktion ugb aufgerufen. *)
VAR   A, IP, J1Y, LF, LFX, LY, M, N, NEWLF, Q2, STAKKP: LIST; 
BEGIN
(*1*) STAKKP:=STAKK; M:=1; IP:=I; LISTLF:=SIL; 
(*2*) J1Y:=RNINT(1); LFX:=LIST1(J1Y); LY:=SIL; LF:=LIST1(LFX); 
      IP:=IP-1; NEWLF:=SIL;  
      WHILE M <= IP DO ADV(STAKKP, A,STAKKP); N:=FIRST(A); 
            Q2:=SECOND(A); MKLF2(LF,Q2,N,M,L, NURLF,LISTLF); M:=M+1; 
            LF:=NURLF; END; 
      NURLF:=LF; SWRITE("Die berechneten Linearformen sind "); 
      OWRITE(LENGTH(NURLF)); BLINES(1);  
(*5*) RETURN; END LFALL;  


PROCEDURE MKLF3(LFP,Q2,NP,M: LIST): LIST;  
(*UGB make new linear forms 3.
Diese funktionniert genauso wie mklf2. hier werden nur 
die linearformen (newlf) berechnet und ausgegeben. 
diese funktion wird von der funktion alllf aufgerufen. *) 
VAR   A, B, D, J, J1Y, KLIST, LF, LISTLF, NEWLF, TR: LIST; 
BEGIN
(*1*) LF:=LFP; NEWLF:=SIL; KLIST:=SIL; J:=0; LISTLF:=SIL;  
(*2*) WHILE LF <> SIL DO D:=SIL; ADV(LF, B,LF); 
            IF Q2 = SIL THEN J1Y:=LIST2(1,1); D:=LIST1(J1Y); 
               ELSE TR:=CP2(B,Q2); TR:=RNVABS(TR); TR:=LRNBMS(TR); 
                    D:=CUT(TR); END;  
            CLF3(B,D,KLIST,NP,J,M, A,KLIST,J); NEWLF:=USUN(A,NEWLF); 
      END;  
(*5*) RETURN(NEWLF); END MKLF3; 


PROCEDURE CLF3(C,D,KLIST,NP,JP,M: LIST;  VAR LFORM,KLISTP,J: LIST); 
(*UGB compute linear form from difference set 3.
Diese funktionniert genauso wie clf2. hier werden nur
die linearformen (lform) berechnet und ausgegeben. 
diese funktion wird von der funktion mklf3 aufgerufen. *) 
VAR   A, DP, K, KALT, KLISTH, U: LIST;  
BEGIN
(*1*) DP:=D; LFORM:=SIL; J:=JP; KLISTP:=KLIST; KALT:=SIL; 
      KLISTH:=SIL;  
(*2*) WHILE DP <> SIL DO ADV(DP, A,DP); A:=COMP(A,C);  
            K:=CSPUR(A,NP,KALT); 
            IF M <> 1 THEN U:=COMPA1(K,KLISTP);  
               IF U <> 1 THEN KLISTH:=COMP(K,KLISTH);  
                  LFORM:=COMP(A,LFORM); END; 
               ELSE LFORM:=COMP(A,LFORM); END;  
            END; 
      KLISTP:=CCONC(KLISTP,KLISTH); 
(*5*) RETURN; END CLF3; 


PROCEDURE DO1(LFP: LIST): LIST; 
(*UGB add last component to exponent vector. 
Um speicherplatz zu sparen wurden die linearformen ohne
das 1 element als letzte komponente gespeichert. diese 
funktion fuegt fuer die liste der linearformen lfp das 
element 1 ein. das ergebnis ist lf1. 
diese funktion wird von der funktion pugb aufgerufen. *)
VAR   A, LF, LF1, E: LIST; 
BEGIN
(*1*) LF:=LFP; LF1:=SIL; E:=LIST1(RNINT(1)); 
      WHILE LF <> SIL DO ADV(LF, A,LF); A:=CCONC(A,E); 
            LF1:=COMP(A,LF1); END; 
      LF1:=INV(LF1); 
(*4*) RETURN(LF1); END DO1; 


PROCEDURE MKLIST(LF,L: LIST;  VAR LFLIST,NURLF: LIST);  
(*UGB make trace and cuts. 
Diese funktion wird aufgerufen bei der option pugb. die
liste der eingelesenen linearformen lf ist groesser als
noetig. diese funktion reduziert diese linearformen,
sodass bezueglich der menge p von polynomen verschiedene 
ordnungen ergeben. nurlf ist dann das ergebnis. listlf 
besteht aus tupel der form (a,l,k,n) wie das ergebnis von
lfall.
diese funktion wird von der funktion pugb aufgerufen. *)
VAR   A, J1Y, K, KALT, KLIST, LFP, P, Q: LIST; 
BEGIN
(*1*) LFP:=LF; KALT:=SIL; KLIST:=SIL; NURLF:=SIL; LFLIST:=SIL;  
      Q:=EXPTU(L); P:=MAKERN(Q); 
(*2*) P:=DIFF(P); 
(*3*) WHILE LFP <> SIL DO ADV(LFP, A,LFP); K:=CSPUR(A,P,KALT);  
            NURLF:=COMP(A,NURLF); J1Y:=LIST4(A,L,K,P); 
            LFLIST:=COMP(J1Y,LFLIST); END;  
(*6*) RETURN; END MKLIST; 


PROCEDURE LDEG(L: LIST): LIST; 
(*Distributive polynomial list total degree. 
Diese funktion bestimmt fuer eine liste von polynomen l
den maximalen totalgrad, der darin auftaucht. 
diese funktion wird von den funktionen pug und pugb
aufgerufen. *)
VAR   DEG, DEG1, L1, LP: LIST; 
BEGIN
(*1*) LP:=L; DEG:=0; 
(*2*) WHILE LP <> SIL DO ADV(LP, L1,LP); DEG1:=DIPTDG(L1); 
            DEG:=IMAX(DEG,DEG1); END;  
(*5*) RETURN(DEG); END LDEG;  



END MASUGB.
