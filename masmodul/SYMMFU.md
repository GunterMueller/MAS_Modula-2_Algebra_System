(* ----------------------------------------------------------------------------
 * $Id: SYMMFU.md,v 1.3 1992/10/16 13:58:12 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SYMMFU.md,v $
 * Revision 1.3  1992/10/16  13:58:12  kredel
 * Cosmetic
 *
 * Revision 1.2  1992/02/12  17:33:14  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:12:37  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SYMMFU;

(* Symmetric Functions Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: SYMMFU.md,v 1.3 1992/10/16 13:58:12 kredel Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DIRPSR(Q,PL: LIST;  VAR P1,P2: LIST); 
(*Distributive rational polynomial symmetric function reduction. 
Q is a list of the rl elementary symmetric functions in rl 
variables. pl is reduced modulo Q to p2, the reduction relation 
is p1. *)


PROCEDURE DIRPSE(Q,U: LIST;  VAR PL,V: LIST); 
(*Distributive rational polynomial symm. function exponent reduction.
Q is a list of the rl elementary symmetric functions in rl 
variables. pl is a product of elemenatry symmetric polynomials such 
that head term pl = u. v is the exponent vector of the product. *)


PROCEDURE DIRPES(RL: LIST): LIST; 
(*Distributive rational polynomial elementary symmetric functions.
Q is a list of the rl elementary symmetric functions in rl 
variables. *)


PROCEDURE EVASC(U: LIST): LIST; 
(*Exponent vector ascending. U is an exponent vector of length rl,
U=(u1, ...  ,url).  tl = 1 if u1 le ...  le url, else tl = 0. *)


END SYMMFU.


(* -EOF- *)
