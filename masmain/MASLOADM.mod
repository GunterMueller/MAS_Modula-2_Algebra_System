(* ----------------------------------------------------------------------------
 * $Id: MASLOADM.mi,v 1.1 1994/03/11 15:37:30 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASLOADM.mi,v $
 * Revision 1.1  1994/03/11  15:37:30  pesch
 * Diplomarbeit F. Lippold
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASLOADM;

(* Import lists and declarations. *)

FROM MASLISPU IMPORT Declare,
                     Compiledf1, Compiledf2, Compiledf3, Compiledf4,
                     Compiledf5, Compiledp1, Compiledp1v2, Compiledp3v2, 
                     Compiledp2v3; 

FROM LINALG IMPORT ADUM, ADVSPROD, ADVSVPROD, ADVVSUM, ADSMPROD, ADMSUM, 
                   ADMPROD, ADMTRACE, ADMPTRACE, ADCHARPOL, ADSIG, ADVWRITE,
                   ADMWRITE, IMRTPROD, ICHARPOL, ISIG;

FROM RRADOM IMPORT  EVUMSORT, EVSSPROD, RRVTEXT, RRZDIM, RRREDTERMS, 
                    RRADSTRCONST, RRADVARMATRICES, RRADPOLMATRIX, RRADQUADFORM,
                    RRADCOUNT;

FROM RRINT IMPORT RRIPIQ, RRIPQSUM, RRISTRCONST, RRIQUADFORM, RRICOUNT;

FROM RRUADOM IMPORT RRUADPOLTOVEC, RRUADSTRCONST, RRUADQUADFORM, RRUADCOUNT;

FROM RRUINT IMPORT RRUIPOLTOVEC, RRUISTRCONST, RRUIQUADFORM, RRUICOUNT;

CONST rcsidi = "$Id: MASLOADM.mi,v 1.1 1994/03/11 15:37:30 pesch Exp $";
CONST copyrighti = "Copyright (c) 1993 Universitaet Passau";

PROCEDURE InitExternalsM;
(*Initialize external compiled real root procedures. *)
BEGIN
      Compiledf2(ADUM,"ADUM");                     (* from LINALG *)
      Compiledf3(ADVSPROD,"ADVSPROD");
      Compiledf2(ADVSVPROD,"ADVSVPROD");
      Compiledf2(ADVVSUM,"ADVVSUM");
      Compiledf2(ADSMPROD,"ADSMPROD");
      Compiledf2(ADMSUM,"ADMSUM");
      Compiledf3(ADMPROD,"ADMPROD");
      Compiledf2(ADMTRACE,"ADMTRACE");
      Compiledf3(ADMPTRACE,"ADMPTRACE");
      Compiledf2(ADCHARPOL,"ADCHARPOL");
      Compiledf2(ADSIG,"ADSIG");
      Compiledp1(ADVWRITE,"ADVWRITE");
      Compiledp1(ADMWRITE,"ADMWRITE");
      Compiledf2(IMRTPROD,"IMRTPROD");
      Compiledf1(ICHARPOL,"ICHARPOL");
      Compiledf1(ISIG,"ISIG");
      
      Compiledf1(EVUMSORT,"EVUMSORT");             (* from RRADOM *)
      Compiledf1(EVSSPROD,"EVSSPROD");
      Compiledf2(RRVTEXT,"RRVTEXT");
      Compiledf1(RRZDIM,"RRZDIM");
      Compiledf1(RRREDTERMS,"RRREDTERMS");
      Compiledp3v2(RRADSTRCONST,"RRADSTRCONST");
      Compiledf4(RRADVARMATRICES,"RRADVARMATRICES");
      Compiledp3v2(RRADPOLMATRIX,"RRADPOLMATRIX");
      Compiledf5(RRADQUADFORM,"RRADQUADFORM");
      Compiledf5(RRADCOUNT,"RRADCOUNT");
      
      Compiledp1v2(RRIPIQ,"RRIPIQ");               (* from RRINT *)
      Compiledp3v2(RRIPQSUM,"RRIPQSUM");           
      Compiledp2v3(RRISTRCONST,"RRISTRCONST");
      Compiledf4(RRIQUADFORM,"RRIQUADFORM");
      Compiledf4(RRICOUNT,"RRICOUNT");

      Compiledf3(RRUADPOLTOVEC,"RRUADPOLTOVEC");   (* from RRUADOM *)
      Compiledf3(RRUADSTRCONST,"RRUADSTRCONST");
      Compiledf1(RRUADQUADFORM,"RRUADQUADFORM");
      Compiledf5(RRUADCOUNT,"RRUADCOUNT");

      Compiledf2(RRUIPOLTOVEC,"RRUIPOLTOVEC");     (* from RRUINT *)
      Compiledf2(RRUISTRCONST,"RRUISTRCONST");
      Compiledf1(RRUIQUADFORM,"RRUIQUADFORM");
      Compiledf4(RRUICOUNT,"RRUICOUNT");
(*9*) END InitExternalsM;

END MASLOADM.

(* -EOF- *)
