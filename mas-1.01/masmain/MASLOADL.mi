(* ----------------------------------------------------------------------------
 * $Id: MASLOADL.mi,v 1.3 1992/10/15 16:30:36 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASLOADL.mi,v $
 * Revision 1.3  1992/10/15  16:30:36  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:32:53  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:12:17  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASLOADL;

(* MAS Load Implementation Module L. *)


  FROM MASLISPU IMPORT Compiledf0, Compiledf1, Compiledf2, 
       Compiledf3, Compiledf4, Compiledp1, Compiledp2, 
       Compiledp2v2, Compiledp1v2;

  FROM LINALGRN IMPORT 

       MGET, MSET, MDIM, MTRANS, VEL, MMINOR, MRANG,  

       RNMHILBERT, RNVMAX, RNVWRITE, RNVREAD, RNVLC, RNVSPROD, 
       RNSVPROD, RNVDIF, RNVQ, RNVQF, 
       RNVVSUM, RNVSVSUM, RNVSSUM, RNVFIV,  
       RNVSVPROD, RNVVPROD, 

       RNMMAX, RNMWRITE, RNMREAD, RNMFIM, RNUM, 
       RNMPROD, RNMSUM, RNSMPROD, RNMDIF,

       RNMDET, RNMDETL, RNMGE,
       RNMGELUD, RNMLT, RNMUT, RNMSDS, RNMINV, RNMUNS;

  FROM LINALGI IMPORT 

      IVMAX, IVWRITE, IVVDIF, IKM, IVLC, IVSQ, 
      IVVSUM, IVSVSUM, IVSSUM, IVSVPROD, IVVPROD,  

      IMMAX, IMWRITE, IUM, 
      IMPROD, IMSUM, ISMPROD, IMDIF, IVSPROD, 

      IVFRNV, IVFRNV1, IMFRNM, IMFRNM1, IMDETL, IMDET,
      IMGE, IMGELUD, IMLT, IMUT, IMSDS, RNMINVI, IMUNS; 


  FROM SACLDIO IMPORT MAIPDE;

CONST rcsidi = "$Id: MASLOADL.mi,v 1.3 1992/10/15 16:30:36 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE InitExternalsL();
(*Initialize external compiled linear algebra procedures. *)
BEGIN
(*1*) (* arbitrary matrices *)
      Compiledf1(MDIM, "MDIM");
      Compiledf1(MTRANS, "MTRANS");
      Compiledf2(VEL, "VEL");
      Compiledf3(MGET, "MGET");
      Compiledf4(MSET, "MSET");
      Compiledf3(MMINOR, "MMINOR");
      Compiledf1(MRANG, "MRANG");

(*2*) (* rational matrices *)
      Compiledf2(RNMHILBERT, "RNMHILBERT");
      Compiledf2(RNUM, "RNUM");
      Compiledp2(RNVWRITE, "RNVWRITE");
      Compiledf0(RNVREAD, "RNVREAD");

      Compiledf1(RNVMAX, "RNVMAX");
      Compiledf1(RNVSSUM, "RNVSSUM");
      Compiledf4(RNVLC, "RNVLC");
      Compiledf1(RNVFIV, "RNVFIV");
      Compiledf1(RNVQF, "RNVQF");
      Compiledf2(RNVQ, "RNVQ");
      Compiledf2(RNVSPROD, "RNVSPROD");
      Compiledf2(RNSVPROD, "RNSVPROD");
      Compiledf2(RNVVSUM, "RNVVSUM");
      Compiledf2(RNVSVSUM, "RNVSVSUM");
      Compiledf2(RNVSVPROD, "RNVSVPROD");
      Compiledf2(RNVVPROD, "RNVVPROD");
      Compiledf2(RNVDIF, "RNVDIF");

      Compiledf1(RNMMAX, "RNMMAX");
      Compiledp2(RNMWRITE, "RNMWRITE");
      Compiledf0(RNMREAD, "RNMREAD");
      Compiledf1(RNMFIM, "RNMFIM");
      Compiledf2(RNMPROD, "RNMPROD");
      Compiledf2(RNMSUM, "RNMSUM");
      Compiledf2(RNSMPROD, "RNSMPROD");
      Compiledf2(RNMDIF, "RNMDIF");

      Compiledf1(RNMGE, "RNMGE");
      Compiledf1(RNMDET, "RNMDET");
      Compiledf1(RNMDETL, "RNMDETL");
      Compiledp1v2(RNMGELUD, "RNMGELUD");
      Compiledf2(RNMLT, "RNMLT");
      Compiledf2(RNMUT, "RNMUT");
      Compiledf3(RNMSDS, "RNMSDS");
      Compiledf1(RNMINV, "RNMINV");
      Compiledf1(RNMUNS, "RNMUNS");

(*3*) (* integer matrices *)
      Compiledf2(IUM, "IUM");
      Compiledp1(IVWRITE, "IVWRITE");
      Compiledf2(IKM, "IKM");
      Compiledf4(IVLC, "IVLC");
      Compiledf2(IVSQ, "IVSQ");
      Compiledf1(IVMAX, "IVMAX");
      Compiledf1(IVSSUM, "IVSSUM");
      Compiledf2(IVVDIF, "IVVDIF");
      Compiledf2(IVVSUM, "IVVSUM");
      Compiledf2(IVSVSUM, "IVSVSUM");
      Compiledf2(IVSVPROD, "IVSVPROD");
      Compiledf2(IVVPROD, "IVVPROD");
      Compiledf2(IVSPROD, "IVSPROD");
      Compiledp2v2(IVFRNV1, "IVFRNV1");
      Compiledf1(IVFRNV, "IVFRNV");

      Compiledp1(IMWRITE, "IMWRITE");
      Compiledf1(IMMAX, "IMMAX");
      Compiledf2(IMPROD, "IMPROD");
      Compiledf2(IMSUM, "IMSUM");
      Compiledf2(ISMPROD, "ISMPROD");
      Compiledf2(IMDIF, "IMDIF");
      Compiledp2v2(IMFRNM1, "IMFRNM1");
      Compiledf1(IMFRNM, "IMFRNM");

      Compiledf1(IMGE, "IMGE");
      Compiledf1(IMDET, "IMDET");
      Compiledf1(IMDETL, "IMDETL");
      Compiledp1v2(IMGELUD, "IMGELUD");
      Compiledf2(IMLT, "IMLT");
      Compiledf2(IMUT, "IMUT");
      Compiledf3(IMSDS, "IMSDS");
      Compiledf1(RNMINVI, "RNMINVI");
      Compiledf1(IMUNS, "IMUNS");
(*4*) (* other matrices *)
      Compiledf2(MAIPDE, "MAIPDE");
(*9*) END InitExternalsL;


END MASLOADL.
(* -EOF- *)
