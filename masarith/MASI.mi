(* ----------------------------------------------------------------------------
 * $Id: MASI.mi,v 1.3 1992/10/15 16:28:12 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASI.mi,v $
 * Revision 1.3  1992/10/15  16:28:12  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  13:19:04  pesch
 * Moved CONST Definition to the right place.
 *
 * Revision 1.1  1992/01/22  15:08:28  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASI;

(* MAS Integer Implementation Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT INV, LIST, SIL, BETA, ADV, 
                    SFIRST, SRED, COMP, FIRST, RED, LENGTH;

FROM SACLIST IMPORT LIST2, FIRST2, COMP2, LIST3;

FROM SACD IMPORT DQR, DPR;

FROM SACI IMPORT ISUM, IDPR, IDIF, ISEG, ISSUM, IRAND;


CONST rcsidi = "$Id: MASI.mi,v 1.3 1992/10/15 16:28:12 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE IPROD(A,B: LIST): LIST; 
(*Integer product.  A and B are integers.  C=A*B. For long
integers Karatsubas method is used. *)
VAR  A0, A1, AL, AP, AP0, APP, AS, B0, B1, BL, BP, BP0, BS, C, C0, C1,
     C2, CH, CL, CLP, CP, CPP, CS, CSP, EL, FL, I, KL, L, ML, NL, TL:
     LIST; 
BEGIN
(*1*) (*a or b zero.*) 
      IF (A = 0) OR (B = 0) THEN C:=0; RETURN(C); END; 
(*2*) (*a and b single-precision.*) 
      IF (A < BETA) AND (B < BETA) THEN DPR(A,B, CLP,CL); 
         IF CLP = 0 THEN C:=CL; ELSE C:=LIST2(CL,CLP); END; 
         RETURN(C); END; 
(*3*) (*a or b single-precision.*) 
      IF A < BETA THEN C:=IDPR(B,A); RETURN(C); END; 
      IF B < BETA THEN C:=IDPR(A,B); RETURN(C); END; 
(*4*) (*interchange if b is longer.*) ML:=LENGTH(A); NL:=LENGTH(B); 
      IF ML >= NL THEN AP0:=A; BP0:=B; ELSE AP0:=B; BP0:=A; TL:=ML; 
         ML:=NL; NL:=TL; END; 
(*5*) (*branch to karatsuba steps for long integers. *) 
IF NL <= 16 THEN  
      AP:=AP0; BP:=BP0; 
(*6*) (*classical steps. set product to zero.*) C:=LIST2(0,0); CS:=C; 
      FOR I:=1 TO ML+NL-2 DO C:=COMP(0,C); END; 
(*7*) (*multiply digits and add products.*) CP:=C; 
      REPEAT APP:=AP; ADV(BP, BL,BP); 
             IF BL <> 0 THEN CPP:=CP; CLP:=0; 
                REPEAT ADV(APP, AL,APP); DPR(AL,BL, EL,FL); 
                       CL:=FIRST(CPP); CL:=CL+FL; CL:=CL+CLP; 
                       CLP:=CL DIV BETA; TL:=CLP*BETA; CL:=CL-TL; 
                       SFIRST(CPP,CL); CLP:=EL+CLP; CPP:=RED(CPP); 
                       UNTIL APP = SIL; 
                SFIRST(CPP,CLP); END; 
             CP:=RED(CP); 
             UNTIL BP = SIL; 
(*8*) (*leading digit zero. *) 
      IF CLP = 0 THEN SRED(CS,SIL); END; 
      RETURN(C); 
      END;
(*9*) (*karatsuba steps. ml ge 2*nl.*) 
      IF ML >= 2*NL THEN L:=BETA; 
         REPEAT ISEG(AP0,NL, AP0,A0); C0:=IPROD(A0,BP0); L:=COMP(C0,L); 
                UNTIL AP0 = 0; 
         L:=INV(L); C:=ISSUM(NL,L); RETURN(C); END; 
(*10*) (*nl le ml lt 2*nl.*) KL:=ML DIV 2; 
       IF ML > (KL+KL) THEN KL:=KL+1; END; 
       ISEG(AP0,KL, A1,A0); ISEG(BP0,KL, B1,B0); AS:=ISUM(A1,A0); 
       BS:=ISUM(B1,B0); C2:=IPROD(A1,B1); C0:=IPROD(A0,B0); 
       CSP:=IPROD(AS,BS); CH:=ISUM(C0,C2); C1:=IDIF(CSP,CH); 
       L:=LIST3(C0,C1,C2); C:=ISSUM(KL,L); RETURN(C); 
(*13*) END IPROD; 


END MASI.


(* -EOF- *)
