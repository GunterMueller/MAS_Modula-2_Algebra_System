(* ----------------------------------------------------------------------------
 * $Id: SYZGB.md,v 1.3 1992/10/16 13:58:13 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SYZGB.md,v $
 * Revision 1.3  1992/10/16  13:58:13  kredel
 * Cosmetic
 *
 * Revision 1.2  1992/02/12  17:33:17  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:12:42  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SYZGB;

(* Syzygy Groebner Base Definition Module. *)


(* Author: J. Philipp, Uni Passau, 1991. *)


FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: SYZGB.md,v 1.3 1992/10/16 13:58:13 kredel Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";

 

PROCEDURE MGB(PM, SANZ : LIST): LIST;
(* Modul Groebner Base. Berechnet wird die Modul Groebner Basis fuer die
Polynommatrix PM. Das Bit SANZ steuert die Anzeigeart. *)


PROCEDURE NLMGB(PM, SANZ : LIST; VAR T : LIST): LIST;
(* Non-Commutative Modul Groebner Base. Berechnet wird die Modul Groebner 
Basis fuer die Polynommatrix PM. Das Bit SANZ steuert die Anzeigeart. *)


PROCEDURE GBE(PL, SANZ, L : LIST): LIST;
(* Groebner Base with Exponent Vector Check. Berechnung der Groebner Basis 
von PL unter Beruecksichtigung des Exponentenvektors der Hoechsten Terme.
S-Polynome werden nur bei solchen Polynomen gebildet, deren HT-Exponen-
tenvektor in den ersten L Stellen uebereinstimmt. *)


PROCEDURE GBF(PL, SANZ: LIST; VAR GBTM : LIST): LIST;
(* Groebner Base with Factors. Groebner Basis Berechnung mit Faktoren.
Waehrend des Programmdurchlaufs wird die ''Entstehungsgeschichte'' der
Groebner Basis von PL dokumentiert, d.h. jedes neu hinzugenommene
Basispolynom wird dargestellt durch Faktoren GBTM bezogen auf die
Ausgangspolynome. *)


PROCEDURE GBEF(PL, SANZ, L : LIST; VAR GBTM : LIST): LIST;
(* Groebner Base with Exponent Vector Check and Factors. Kombination der
Eigenschaften der Funktionen GBE und GBF. *)


PROCEDURE NLGBE(PL, SANZ, L : LIST; VAR T : LIST): LIST;
(* Non-Commutative Groebner Base with Exponent Vector Check. Berechnung der
Groebner Basis von PL unter Beruecksichtigung des Exponentenvektors der
Hoechsten Terme. S-Polynome werden nur bei solchen Polynomen gebildet, deren
HT-Exponentenvektor in den ersten L Stellen uebereinstimmt. *)


PROCEDURE NLGBF(PL, SANZ: LIST; VAR GBTM, T: LIST): LIST;
(* Non-Commutative Groebner Base with Factors. Groebner Basis Berechnung mit
Faktoren. W"ahrend des Programmdurchlaufs wird die ''Entstehungsgeschichte''
der Groebner Basis von PL dokumentiert, d.h. jedes neu hinzugenommene
Basispolynom wird dargestellt durch Faktoren GBTM bezogen auf die
Ausgangspolynome. *)


PROCEDURE NLGBEF(PL, SANZ, L : LIST; VAR GBTM, T : LIST): LIST;
(* Non-Commutative Groebner Base with Exponent Vector Check and Factors.
Kombination der Eigenschaften der Funktionen NGBE und NGBF. *)


END SYZGB.
(* -EOF- *)
