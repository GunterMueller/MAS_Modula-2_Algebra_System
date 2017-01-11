(* ----------------------------------------------------------------------------
 * $Id: SYZHLP.md,v 1.2 1992/02/12 17:33:18 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SYZHLP.md,v $
 * Revision 1.2  1992/02/12  17:33:18  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:12:44  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SYZHLP;

(* Syzygy Utility Programs Definition Module. *)


(* Author: J. Philipp, Uni Passau, 1991. *)


FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: SYZHLP.md,v 1.2 1992/02/12 17:33:18 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE ALFA(L : LIST);
(* Automatic Linear Form Adaption. Fuehrt bei einer gegebenen Linearform
von EVORD L neue Variablen mit Graden groesser als der hoechste Grad
der EVORD-Polynome ein. *)


PROCEDURE ALFRA(L : LIST);
(* Automatic Linear Form Readaption. Gegenstueck zu ALFA. Reduziert bei
gegebener Linearform von EVORD die fuehrenden L Polynome. *)


PROCEDURE ADDPPOS(PL, P, POS : LIST): LIST;
(* Add Polynomial P at Position. Gegeben ist eine Polynomliste PL. Dann 
wird P an der POS-ten Position dieser Liste zu dem dort vorhandenen Polynom
addiert. *)


PROCEDURE PLWR(PL, VL : LIST);
(* Polynomial List Write. Am Bildschirm wird die Polynomliste PL bzgl.
der Variablenliste VL ausgegeben. *)


PROCEDURE PMWR(PM, VL : LIST);
(* Polynomial Matrix Write. Am Bildschirm wird die Polynommatrix PM 
(Liste ueber Listen) bzgl. der Variablenliste VL ausgegeben. *)


PROCEDURE APP0(PM : LIST): LIST;
(* Append 0. Haengt an jede Polynomliste von PM das Nullpolynom an. *)


PROCEDURE ADDLAST(P, PL : LIST): LIST;
(* Add last Polynomial. Addiert das Polynom P zum letzten Polynom der
Polynomliste PL. *)


PROCEDURE POS(P, PL : LIST): LIST;
(* Position of Polynomial. Bestimmt die Position des Polynoms P in der
Polynomliste PL. *)


PROCEDURE POL(PL, POS : LIST): LIST;
(* Polynomial at Position. Bestimmt das Polynom an der POS-ten Stelle in 
der Polynomliste PL. *)


PROCEDURE GENPOSV(GB, GBR : LIST): LIST;
(* Generate Postion Vector. Gegeben ist eine Groebner Basis GB und die dazu-
gehoerige diskret reduzierte Groebner Basis GBR. Bestimmt wird nun ein
Vektor mit Nullen und Einsen, bei dem die Einsen an der Position stehen,
an der ein Polynom aus GB nicht ganz zu Null reduziert werden konnte.
Zusaetzlich bleiben immer mindestens zwei Polynome aus GB uebrig.
Bsp.: GB = (P1, P2, P3), GBR = (P2, P3), dann ist POSV = (0, 1, 1). *)


PROCEDURE INSPOSV(PM, POSV : LIST): LIST;
(* Insert Position Vector. Fuegt bei der Polynommatrix PM in jede Polynomliste
PL Nullen an den Stellen ein, an denen bei POSV auch Nullen stehen.
Bsp.: Sei eine Polynomliste PLi = (P1, P2, P3), und sei
POSV = (0, 1, 0, 1, 1, 0, 0). Dann wird als neue Polynomliste
(0, P1, 0, P2, P3, 0, 0) an die Matrix zurueckgegeben. *)


PROCEDURE EXPPL(P, GB : LIST): LIST;
(* Exclude P from GB. Loescht das Polynom P aus der Polynomliste GB. *)


PROCEDURE EX0PL(PL : LIST): LIST;
(* Exclude 0 from PL. Loescht alle Nullen aus der Polynomliste PL. *)


PROCEDURE EVF(EV, L : LIST): LIST;
(* Exponent Vector First. Liefert die ersten L Stellen des Exponentenvektors
EV zurueck. Bsp.: Sei EV = (4, 3, 0, 1, 9), und sei L = 3, dann wird 
(4, 3, 0) zurueckgegeben. *)


PROCEDURE EVR(PM, L : LIST): LIST;
(* Exponent Vector Reduction. Bei der Polynommatrix PM wird jeder
Exponentenvektor jeden Polynoms um die ersten L Stellen gekuerzt. *)


PROCEDURE MREAD(VL : LIST): LIST;
(* Matrix Read. Liest eine Polynommatrix entsprechend der Variablenliste 
VL und der gegebenen Einheit (Textdatei, "Bildschirm") ein. *)


PROCEDURE NMREAD(VL, T : LIST): LIST;
(* Non-Commutative Matrix Read. Liest eine Polynommatrix mit nicht-
kommutativen Polynomen entsprechend der Variablenliste VL, der Relations-
matrix T und der gegebenen Einheit (Textdatei, "Bildschirm") ein. *)


PROCEDURE TA(L : LIST; T : LIST): LIST;
(* T Adaption. Die Exponentenvektoren jeden Polynoms in der Polynomliste T
werden um L Stellen erweitert. Bsp.: Sei EV = (2, 1, 3) und L = 2, 
dann wird EV zu (0, 0, 2, 1, 3). *)


PROCEDURE TR(L : LIST; T : LIST): LIST;
(* T Readaption. Die Exponentenvektoren jeden Polynoms in der Polynomliste 
T werden um L Stellen gekuerzt. Bsp.: Sei EV = (0, 0, 2, 1, 3) und 
L = 2, dann wird EV zu (2, 1, 3). *)


PROCEDURE NEXTPAIR(VAR P1, P2, PPL : LIST);
(* Next Pair of Polynomials. Bestimmt aus der Polynompaarliste PPL das
naechste Paar P1, P2 von Polynomen. Gleichzeitig wird dieses Paar aus
der Liste entfernt. Siehe Groebner Basis Algorithmen! *)


PROCEDURE EVT(P1, P2, L : LIST): LIST;
(* Exponent Vector Test. Ueberprueft, ob die Exponentenvektoren der HT der
Polynome P1 und P2 in den fuehrenden L Stellen uebereinstimmen. Ist dies
der Fall, dann wird die 1, ansonsten die 0 zurueckgegeben. *)


PROCEDURE WRS1(SZ, C1, C2, C3 : LIST);
(* Write Situation. Ausgegben wird die CPU-Zeit minus eine Startzeit SZ,
die Anzahl der H-Polynome C1, die Anzahl der S-Polynome C2 und die
Anzahl der uebrigen Paare von Polynomen C3. *)


PROCEDURE WRS2(SZ, C1, TW1, C2, SPN, C3 : LIST);
(* Write Situation. Ausgegben wird die CPU-Zeit minus eine Startzeit SZ,
die Anzahl der H-Polynome C1 und das letzte H-Polynom, die Anzahl der
S-Polynome C2 und das letzte S-Polynom, sowie die Anzahl der uebrigen
Paare von Polynomen C3. *)


PROCEDURE EVL(PM : LIST) : LIST;
(* Exponent Vector Length. Bestimmt in einer Polynommatrix PM die Laenge des
Exponentenvektors des ersten Polynoms ungleich dem Nullpolynom. *)


PROCEDURE NORMF(VAR PL, GBTM : LIST);
(* Normative Factors. Berechnet eine Matrix GBTM, auf deren Hauptdiagonalen
die Normfaktoren der Polynome der Polynomliste PL stehen. *)


PROCEDURE GBTMRED(GBTM, POSV : LIST) : LIST;
(* GBTM Reduction. Reduziert die Spalten von GBTM entsprechend der
auftretenden Nullen in POSV. *)


PROCEDURE MTPLV(PM : LIST; VAR L : LIST): LIST;
(* Matrix to Polynomial List Vertical. Erzeugt eine Polynomliste PL derart,
dass L (gleich Zeilenzahl) neue verschiedene Variablen mit der Matrix
multipliziert werden (1. Variable mit der 1. Zeile, ...), und anschliessend
die so erhaltene Matrix spaltenweise aufaddiert wird. *)


PROCEDURE PLVTM(PL, L : LIST): LIST;
(* Polynomial List Vertical To Matrix. Das Gegenstueck zu MTPLV. Beachtet
werden mua hierbei nur, dass Anteile der Polynome aus der Polynomliste PL
enstprechend der L neu eingefuehrten Variablen wieder in eine Matrix
zerlegt werden, d.h. das erste Polynom der Polynomliste PL verteilt sich
in der ersten Spalte, ... . *)


PROCEDURE MTPLH(PM : LIST; VAR L : LIST): LIST;
(* Matrix to Polynomial List Horizontal. Erzeugt eine Polynomliste PL derart,
dass L (gleich Spaltenzahl) neue verschiedene Variablen mit der Matrix
multipliziert werden (1. Variable mit der 1. Spalte, ...), und anschlieaend
die so erhaltene Matrix zeilenweise aufaddiert wird. *)



PROCEDURE PLHTP(PL : LIST): LIST;
(* Polynomial List Horizontal To Polynomial. Jedes Polynom aus PL wird mit
einer neuen , zu den anderen verschiedenen, Variablen multipliziert und
zu einem Polynom aufaddiert. *)



PROCEDURE VMADD(PM : LIST): LIST;
(* Vertical Matrix Addition. Erzeugt wird eine Polynomliste, deren Elemente
aus den aufaddierten Spalten der Matrix PM gebildet wurden. *)


END SYZHLP.

(* -EOF- *)
