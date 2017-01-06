(* ----------------------------------------------------------------------------
 * $Id: SACEXT6.mi,v 1.3 1992/10/15 16:28:58 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACEXT6.mi,v $
 * Revision 1.3  1992/10/15  16:28:58  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:34:52  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:16:02  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACEXT6;

(* SAC Extensions 6 Implementation Module. *)



(* Import lists and declarations. *) 

FROM MASSTOR IMPORT LIST, SIL, BETA,
                    COMP, SRED, ADV, FIRST, RED;

FROM SACLIST IMPORT CONC;

FROM SACEXT5 IMPORT IPCSFB; 

FROM SACPFAC IMPORT ISFPF; 

CONST rcsidi = "$Id: SACEXT6.mi,v 1.3 1992/10/15 16:28:58 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE IPFSFB(RL,A: LIST): LIST; 
(*Integral polynomial finest squarefree basis.  A eq (A sub 1 , ...,
A sub n ), n ge 0, is a list of positive primitive integral
polynomials in r variables, r ge 1, each of which is of positive
degree in its main variable.  B is a finest squarefree basis for A.*)
VAR  B, B1, BP, BS, L: LIST; 
BEGIN
(*1*) (*get coarsest squarefree basis for a.*) BS:=IPCSFB(RL,A); 
(*2*) (*factor each basis element.*) B:=BETA; 
      WHILE BS <> SIL DO ADV(BS, B1,BS); L:=ISFPF(RL,B1); 
            BP:=CONC(L,B); B:=BP; END; 
      RETURN(B); 
(*5*) END IPFSFB; 


END SACEXT6.
(* -EOF- *)
