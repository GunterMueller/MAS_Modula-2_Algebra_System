(* ----------------------------------------------------------------------------
 * $Id: DIPGCD.md,v 1.2 1992/02/12 17:34:17 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPGCD.md,v $
 * Revision 1.2  1992/02/12  17:34:17  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:14:33  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DIPGCD;


(* DIP GCD Definition Module. *)



FROM MASSTOR IMPORT LIST;
     
CONST rcsid = "$Id: DIPGCD.md,v 1.2 1992/02/12 17:34:17 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DIRFAC(P: LIST): LIST; 
(*Distributive rational polynomial factorisation.
P is a distributive rational polynomial.
PP=((e1,P1), ...,(en,Pn)), where P=P1**e1+ ... +Pn**en. *)


PROCEDURE IPLCM(RL,A,B: LIST): LIST; 
(*Integral polynomial least common multiple. A and B are integal
polynomials. C=LCM(A,B), a nonnegative integral polynomial.*)
                                            

END DIPGCD.



(* -EOF- *)
