(* ----------------------------------------------------------------------------
 * $Id: SYZMAIN.md,v 1.2 1992/02/12 17:33:20 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SYZMAIN.md,v $
 * Revision 1.2  1992/02/12  17:33:20  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:12:46  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SYZMAIN;

(* Syzygy Main Programs Definition Module. *)


(* Author: J. Philipp, Uni Passau, 1991. *)


FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: SYZMAIN.md,v 1.2 1992/02/12 17:33:20 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE SYHC(PM, SANZ, SRD : LIST): LIST;
(* Syzygy for homogenous commutative system of equation. Berechnet die
Syzygien fuer ein kommutatives Gleichungssystem. Das Bit SRD steuert
eine moegliche Reduktion waehrend des Verfahrens. Das Bit SANZ regelt die
Anzeigeart von Zwischenergebnissen. *)


PROCEDURE HEQ(PL, SANZ, SRD : LIST): LIST;
(* Homogenous Equation. Berechnet den Syzygienmodul fuer eine Gleichung mit 
den Polynomen aus PL. Das Bit SRD steuert eine moegliche Reduktion waehrend 
des Verfahrens. Das Bit SANZ regelt die Anzeigeart von Zwischenergebnissen.*)


PROCEDURE HSEQ(PM, SANZ, SRD : LIST): LIST;
(* Homogenous System of Equation. Berechnet den Syzygienmodul fuer das
Gleichungssystem mit den Polynomen aus der Matrix PM. Das Bit SRD steuert
eine moegliche Reduktion waehrend des Verfahrens. Das Bit SANZ regelt die
Anzeigeart von Zwischenergebnissen.*)


PROCEDURE SYTHC(SY, PM, VL : LIST);
(* Syzygy Test for homogenous commutative Case. Testet, ob der berechnete
Loesungsgenerator SY jede einzelne Gleichung von PM loest. Die Polynome
der errechnten linken Seiten der Gleichungen werden ausgegeben. *)


PROCEDURE SIC(PM, PL, SANZ, SRD : LIST): LIST;
(* Special Solution for inhomogenous commutative system of equation.
Berechnet eine spezielle Loesung fuer ein kommutatives Gleichungssystem PM.
Die Polynome der rechten Seite stehen in der Liste PL. Das Bit SRD steuert
eine moegliche Reduktion waehrend des Verfahrens. Das Bit SANZ regelt die
Anzeigeart von Zwischenergebnissen.*)


PROCEDURE IEQ(PL, P, SANZ, SRD : LIST): LIST;
(* Special Solution for inhomogenous commutative equation. Berechnet eine
spezielle Loesung fuer eine lineare Gleichung PL. Das Polynom der rechten
Seite ist P. Das Bit SRD steuert eine moegliche Reduktion waehrend des
Verfahrens. Das Bit SANZ regelt die Anzeigeart von Zwischenergebnissen.*)


PROCEDURE ISEQ(PM, PL, SANZ, SRD : LIST): LIST;
(* Special Solution for inhomogenous commutative system of equation.
Berechnet eine spezielle Loesung fuer ein kommutatives Gleichungssystem PM.
Die Polynome der rechten Seite stehen in der Liste PL. Das Bit SRD steuert
eine moegliche Reduktion waehrend des Verfahrens. Das Bit SANZ regelt die
Anzeigeart von Zwischenergebnissen.*)


PROCEDURE STIC(SY, PM, PL, VL : LIST);
(* Solution Test for inhomogenous commutative Case. Testet, ob der berechnete
Loesungsvektor SY jede einzelne Gleichung von PM loest. Die Polynome
der errechnten linken Seiten werden von denen der rechten Seite abgezogen,
und das Ergebnis dieser Differenz wird ausgegeben. *)


PROCEDURE SYHNL(PM, SANZ, SRD, T : LIST): LIST;
(* Syzygy for homogenous non-commutative system of equation. Berechnet die
Syzygien fuer ein nicht-kommutatives Gleichungssystem. Das Bit SRD steuert
eine moegliche Reduktion waehrend des Verfahrens. Das Bit SANZ regelt die
Anzeigeart von Zwischenergebnissen. *)


PROCEDURE NLHEQ(PL, SANZ, SRD, T : LIST): LIST;
(* Non-Commutative Homogenous Equation. Berechnet den Syzygienmodul fuer eine
Gleichung mit den Polynomen aus PL. Das Bit SRD steuert eine moegliche
Reduktion waehrend des Verfahrens. Das Bit SANZ regelt die Anzeigeart von
Zwischenergebnissen.*)


PROCEDURE NLHSEQ(PM, SANZ, SRD, T : LIST): LIST;
(* Non-Commutative Homogenous System of Equation. Berechnet den Syzygienmodul
fuer das Gleichungssystem mit den Polynomen aus der Matrix PM. Das Bit SRD
steuert eine moegliche Reduktion waehrend des Verfahrens. Das Bit SANZ regelt
die Anzeigeart von Zwischenergebnissen.*)


PROCEDURE SYTHNL(SY, PM, VL, T : LIST);
(* Syzygy Test for homogenous non-commutative Case. Testet, ob der berechnete
Loesungsgenerator SY jede einzelne Gleichung von PM loest. Die Polynome
der errechnten linken Seiten der Gleichungen werden ausgegeben. *)


PROCEDURE SINL(PM, PL, SANZ, SRD, T : LIST): LIST;
(* Special Solution for inhomogenous non-commutative system of equation.
Berechnet eine spezielle Loesung fuer ein nicht-kommutatives Gleichungs-
system PM. Die Polynome der rechten Seite stehen in der Liste PL. Das
Bit SRD steuert eine moegliche Reduktion waehrend des Verfahrens. Das
Bit SANZ regelt die Anzeigeart von Zwischenergebnissen.*)


PROCEDURE NLIEQ(PL, P, SANZ, SRD, T : LIST): LIST;
(* Special Solution for inhomogenous non-commutative equation. Berechnet eine
spezielle Loesung fuer eine lineare Gleichung PL. Das Polynom der rechten
Seite ist P. Das Bit SRD steuert eine moegliche Reduktion waehrend des
Verfahrens. Das Bit SANZ regelt die Anzeigeart von Zwischenergebnissen.*)


PROCEDURE NLISEQ(PM, PL, SANZ, SRD, T : LIST): LIST;
(* Special Solution for inhomogenous non-commutative system of equation.
Berechnet eine spezielle Loesung fuer ein nicht-kommutatives Gleichungs-
system PM. Die Polynome der rechten Seite stehen in der Liste PL. Das
Bit SRD steuert eine moegliche Reduktion waehrend des Verfahrens. Das Bit
SANZ regelt die Anzeigeart von Zwischenergebnissen.*)


PROCEDURE STINL(SY, PM, PL, VL, T : LIST);
(* Solution Test for inhomogenous non-commutative Case. Testet, ob der
berechnete Loesungsvektor SY jede einzelne Gleichung von PM loest. Die
Polynome der errechnten linken Seiten werden von denen der rechten Seite
abgezogen, und das Ergebnis dieser Differenz wird ausgegeben. *)


PROCEDURE OREC(P1, P2 : LIST; VAR P3, P4, T : LIST);
(* Ore Condition. Fuer gegebene Polynome P1 und P2 werden Polynome P3 und P4
berechnet, sodass P3*P1 = P4*P2. Die Multiplikation * ist die nicht-
kommutative Multiplikation. *)


END SYZMAIN.



(* -EOF- *)
