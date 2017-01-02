(* ----------------------------------------------------------------------------
 * $Id: SYZFUNC.md,v 1.3 1995/11/04 18:00:50 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SYZFUNC.md,v $
 * Revision 1.3  1995/11/04 18:00:50  pesch
 * Changed comments violating documentation rules.
 *
 * Revision 1.2  1992/02/12  17:33:15  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:12:39  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SYZFUNC;

(* Syzygy Functions Definition Module. *)


(* Author: J. Philipp, Uni Passau, 1991. *)


FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: SYZFUNC.md,v 1.3 1995/11/04 18:00:50 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";

 

PROCEDURE SPC(P1, P2 : LIST; VAR SPFL, SP : LIST);
(* S-Polynomial with Coefficients. Berechnet das S-Pol SP von P1 und P2,
und speichert die zugehoerigen Faktoren Uij und Vij in dieser Reihenfolge
unter SPFL ab. *)


PROCEDURE NLSPC(P1, P2 : LIST; VAR SPFL, SP, T : LIST);
(* Non-Commutative S-Polynomial with Coefficients. Berechnet nicht-
kommutative das S-Pol SP von P1 und P2, und speichert die zugehoerigen
Faktoren Uij und Vij in dieser Reihenfolge unter SPFL ab. *)


PROCEDURE SPCGB(GB : LIST; VAR SPFL, SPL : LIST);
(* S-Polynomials with Coefficients for Groebner Base. Berechnet die 
S-Polynome aller Polynome in GB und speichert diese in SPL ab. Die 
zugehoerigen Faktoren Uij und Vij aller S-Polynome werden in dieser 
Reihenfolge unter SPFL abgelegt. *)


PROCEDURE NLSPCGB(GB : LIST; VAR SPFL, SPL, T : LIST);
(* Non-Commutative S-Polynomials with Coefficients for Groebner Base. 
Berechnet die nicht-kommutativen S-Polynome aller Polynome in GB und 
speichert diese in SPL ab. Die zugehoerigen Faktoren Uij und Vij aller 
S-Polynome werden in dieser Reihenfolge unter SPFL abgelegt. *)


PROCEDURE SPCEGB(GB, L : LIST; VAR SPFL, SPL : LIST);
(* S-Polynomials with Coefficients and Exponenetvector-Check for Groebner Base.
Berechnet die S-Polynome aller Polynome in GB unter Beruecksichtigung der
Gleichheit der fuehrenden L Stellen des Exponenetenvektors der HT, und
speichert diese in SPL ab. Die zugehoerigen Faktoren Uij und Vij aller
S-Polynome werden in dieser Reihenfolge unter SPFL abgelegt. Konnte ein
S-Polynom nicht gebildet werden, dann wird an die Liste SPFL als
Steuerbit eine Null angehaengt. *)


PROCEDURE NLSPCEGB(GB, L : LIST; VAR SPFL, SPL, T : LIST);
(* Non-Commutative S-Polynomials with Coefficients and Exponenetvector-Check
for Groebner Base. Berechnet die nicht-kommutativen S-Polynome aller 
Polynome in GB unter Beruecksichtigung der Gleichheit der fuehrenden 
L Stellen des Exponenetenvektors der HT, und speichert diese in SPL ab. 
Die zugehoerigen Faktoren Uij und Vij aller S-Polynome werden in dieser 
Reihenfolge unter SPFL abgelegt. Konnte ein S-Polynom nicht gebildet 
werden, dann wird an die Liste SPFL als Steuerbit eine Null angehaengt. *)


PROCEDURE RCSP(GB, SPL : LIST): LIST;
(* Reduction Chain of S-Polynomials. Fuer alle S-Polynome in SPL werden
diejenigen Faktoren gespeichert, die noetig sind, um ein S-Polynom
bzgl. der Groebner Basis GB zu Null zu reduzieren.
Bsp.: Sei GB = (G1, G2, G3) und gelte SPi - P1 G1 - P2 G2 - P3 G1 = 0.
Dann hat die i-te Zeile der Ergebnismatrix die Gestalt: (P1+P3, P2, 0). *)


PROCEDURE RCSPR(PL : LIST; VAR SP : LIST): LIST;
(* Reduction Chain of S-Polynomials with Remainder. Fuer das S-Polynome 
SP werden diejenigen Faktoren gespeichert, die noetig sind, um dieses 
S-Polynom bzgl. der Polynome in PL zu Null zu reduzieren. Konnte bei 
einem Durchlauf nicht mehr reduziert werden, dann bricht das Verfahren 
mit den bereits errechneten Werten ab.
Bsp.: Sei PL = (P1, P2, P3) und gelte SP - F1 P1 - F2 P2 - F3 P1 = 0.
Dann hat die Ergebniszeile die Gestalt: (F1+F3, F2, 0). *)


PROCEDURE NLRCSPR(PL : LIST; VAR SP, T : LIST): LIST;
(* Reduction Chain of S-Polynomials with Remainder. Fuer das S-Polynome 
SP werden diejenigen Faktoren gespeichert, die noetig sind, um dieses 
S-Polynom bzgl. der Polynome in PL zu Null zu reduzieren. Konnte bei 
einem Durchlauf nicht mehr reduziert werden, dann bricht das Verfahren 
mit den bereits errechneten Werten ab.
Bsp.: Sei PL = (P1, P2, P3) und gelte SP - F1 P1 - F2 P2 - F3 P1 = 0.
Dann hat die Ergebniszeile die Gestalt: (F1+F3, F2, 0). *)


PROCEDURE NLRCSP(GB, SPL : LIST; VAR T : LIST): LIST;
(* Non-Commutative Reduction Chain of S-Polynomials. Fuer alle S-Polynome 
in SPL werden diejenigen Faktoren gespeichert, die noetig sind, um 
eine S-Polynom bzgl. der Groebner Basis GB und der Kommutatorrelationen 
T zu Null zu reduzieren.
Bsp.: Sei GB = (G1, G2, G3) und gelte SPi - P1 G1 - P2 G2 - P3 G1 = 0.
Dann hat die i-te Zeile der Ergebnismatrix die Gestalt: (P1+P3, P2, 0). *)


PROCEDURE SYGB(SPFL, SPAK : LIST): LIST;
(* Syzygy for Groebner Base. Berechnet wird aufgrund bereits erzeugter
Faktorenliste SPFL und den S-Polynom Ableitungsketten SPAK ein
Loesungsmodulgenerator fuer eine homogene Gleichung, wobei die Polynome
dieser Gleichung eine Groebner Basis bilden. *)


PROCEDURE SYGBE(SPFL, SPAK : LIST): LIST;
(* Syzygy for Groebner Base with Exponent Vector. Berechnet wird aufgrund
bereits erzeugter Faktorenliste SPFL und den S-Polynom Ableitungsketten 
SPAK ein Loesungsmodulgenerator fuer eine homogene Gleichung, wobei die 
Polynome dieser Gleichung eine Groebner Basis bilden. Hier wird das bei 
SPCEGB in die Faktorliste SPFL eingetragene Steuerbit 0 verwertet, das 
besagt, dass sofort ein neuer Schleifendurchlauf beginnen soll. *)


PROCEDURE MMULT(SY1, GBTM : LIST): LIST;
(* Matrix Multiplication. Das Produkt der Matrizen SY1 * GBTM ergibt 
die Loesungsmatrix. *)


PROCEDURE NLMMULT(SY1, GBTM : LIST; VAR T : LIST): LIST;
(* Non-Commutative Matrix Multiplication. Das nicht-kommutative Produkt
der Matrizen SY1 * GBTM ergibt die Loesungsmatrix. *)


PROCEDURE BGFUP(P1, P2, SP, SPN, SPFL, GB, SPAK, GBTM : LIST): LIST;
(* Base Generators Factor Update. Fuer das zu einer Groebner Basis GB 
neu hinzugenommene normierte Polynom SPN werden dessen Abhaengigkeiten 
zu den Grundpolynomen berechnet. Dazu werden die Polynome P1 und P2, 
aus denen SP gebildet wurde, die zwei Faktoren des S-Polynoms in SPFL, 
die Ableitungskette des urspruenglichen S-Polynoms SPAK und die bereits 
bestehende Faktormatrix GBTM verwendet. *)


PROCEDURE NLBGFUP(P1, P2, SP, SPN, SPFL, GB, SPAK, GBTM : LIST; 
                  VAR T : LIST): LIST;
(* Non-Commutative Base Generators Factor Update. Fuer das zu einer 
Groebner Basis GB neu hinzugenommene normierte Polynom SPN werden 
dessen Abhaengigkeiten zu den Grundpolynomen berechnet. Dazu werden 
die Polynome P1 und P2, aus denen SP mit nicht-kommutativer 
Multiplikation gebildet wurde, die zwei Faktoren des S-Polynoms in 
SPFL und die bereits bestehende Faktormatrix GBTM verwendet. *)


PROCEDURE DGBRED(GB, GBTM : LIST; VAR SY : LIST): LIST;
(* Discrete Groebner Base Reduction. Konnte ein Polynom P aus GB 
bzgl. GB ohne P nicht zu Null reduziert werden, dann verbleibt es im 
Ursprungszustand in der Groebner Basis GB. Hat die so reduzierte 
GB nur noch ein Polynom, dann wird die Syzygie abhaengig von der 
Faktormatrix GBTM berechnet. *)


PROCEDURE NLDGBRED(GB, GBTM : LIST; VAR SY, T : LIST): LIST;
(* Non-Commutative Discrete Groebner Base Reduction. Konnte ein Polynom 
P aus GB bzgl. GB ohne P nicht zu Null reduziert werden, dann verbleibt 
es im Ursprungszustand in der Groebner Basis GB. Verwendung findet 
hier die Bildung der Linksnormalform mit DINLNF. Hat die so 
reduzierte GB nur noch ein Polynom, dann wird die Syzygie abhaengig 
von der Faktormatrix GBTM berechnet. *)


PROCEDURE SYONP(GB1, GB2, GBTM : LIST): LIST;
(* Syzygy for old Polynomials by new Polynomials. Berechnet einen
Loesungsmodulgenerator ausgehend von der Groebner Basis GB1 unter
Zuhilfenahme der alten Polynome und der Faktormatrix GBTM. GB2 ist 
die eventuell reduzierte Groebner Basis. *)


PROCEDURE NLSYONP(GB1, GB2, GBTM : LIST; VAR T : LIST): LIST;
(* Syzygy for one Polynomial. Berechnet einen Loesungsmodulgenerator 
fuer das Polynom P unter Zuhilfenahme der Faktormatrix GBTM. *)


PROCEDURE DINPQ(P1, P2 : LIST; VAR T : LIST): LIST;
(* Distributive non-commutative Polynomial Quotient. Berechnet wird 
der nicht-kommutaive Quotient P1/P2=P3; *)


PROCEDURE PLMULT(SY, PL : LIST): LIST;
(* Polynomial List Multiplication. Multipliziert die Polynome der 
Listen SY und PL komponentenweise, und addiert die erhaltenen 
Ergebnisse. *)


PROCEDURE NLPLMULT(SY, PL : LIST; VAR T : LIST): LIST;
(* Non-Commutative Polynomial List Multiplication. Multipliziert die 
Polynome der Listen SY und PL komponentenweise, und addiert die 
erhaltenen Ergebnisse. *)


END SYZFUNC.
(* -EOF- *)
