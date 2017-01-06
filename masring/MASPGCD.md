(* ----------------------------------------------------------------------------
 * $Id: MASPGCD.md,v 1.2 1994/06/16 13:00:58 pfeil Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1994 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASPGCD.md,v $
 * Revision 1.2  1994/06/16  13:00:58  pfeil
 * corrected errors found by mocka.
 *
 * Revision 1.1  1994/06/10  12:10:18  pfeil
 * Initial revision. Procedures for squarefree factorization of integral
 * polynomials.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASPGCD;

(* MAS Polynomial GCD and RES System Definition Module. *)



(* Import lists and declarations. *)


FROM MASSTOR IMPORT LIST;


CONST rcsid = "$Id: MASPGCD.md,v 1.2 1994/06/16 13:00:58 pfeil Exp $";
CONST copyright = "Copyright (c) 1989 - 1994 Universitaet Passau";


PROCEDURE IPSFF(r,f: LIST): LIST;
(* integral polynomial squarefree factorization
   f is a primitive polynomial in r variables,
   returns a list ((e1,p1),...,(ek,pk)), 
   ei positive integers, pi squarefree polynomials,
   where f = p1**e1 * ... * pk**ek *)

PROCEDURE IPFLMER(r,F1,F2: LIST): LIST;
(* integral polynomial factorlist merge.
   F1 and F2 are factorlists ((e1,p1),...,(ek,pk)),
   ei positive integers, pi integer polynomials in r variables,
   as computed in IPSFF.
   returns the merge of F1 and F2. *)

END MASPGCD.

