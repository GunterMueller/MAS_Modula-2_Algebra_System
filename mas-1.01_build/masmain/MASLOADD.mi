(* ----------------------------------------------------------------------------
 * $Id: MASLOADD.mi,v 1.4 1993/05/11 10:56:34 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASLOADD.mi,v $
 * Revision 1.4  1993/05/11  10:56:34  kredel
 * Added modules MASUGB DIPIDGB DIPDDGB
 *
 * Revision 1.3  1992/10/15  16:30:35  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:32:51  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:12:13  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASLOADD;

(* MAS Load Implementation Module D. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST; 

FROM MASLISPU IMPORT Declare,
                     Compiledp0, Compiledp1, Compiledp2, Compiledp3, 
                     Compiledp4,  
                     Compiledf0, Compiledf1, Compiledf2, Compiledf3,
                     Compiledp1v2, Compiledp1v3, 
                     Compiledp2v2, Compiledp2v3; 

FROM DIPC IMPORT VALIS;

FROM DIPROOT IMPORT GBZSET;

FROM DIPDEC0 IMPORT DIRPDA, DIRLPD, DIRLPW; 

FROM DIPDIM IMPORT DILDIM, DIDIMWR; 

FROM DIPIDEAL IMPORT DIRLCT, DIRLIP; 

FROM MASUGB IMPORT UGBBIN;

FROM DIPIDGB IMPORT  DIIPSPOL, DIIPGPOL, DIIPDNF, DIIPCPLMS1, DIIPLM1,
                     DIIPUCPL1, DIIPELIMDGB, DIIPREDDGB,
                     DIIPLEXTAL, DIIPALCMPC, DIIPTDR, DIIPENF,DIIPEGB,
                     DIIPDGB;


CONST rcsidi = "$Id: MASLOADD.mi,v 1.4 1993/05/11 10:56:34 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE InitExternalsD;
(*Initialize external compiled ideal decomposition and root procedures. *)
BEGIN 
(*1*) (*from DIPDIM system. *)
      Compiledp1v3(DILDIM,"DILDIM"); 
      Compiledp4(DIDIMWR,"DIDIMWR"); 
      Compiledp1(DIM,"DIMENSION"); 
(*2*) (*from DIPDEC0 system. *)
      Compiledf2(DIRPDA,"DIRPDA"); 
      Compiledf2(DIRLPD,"DIRLPD"); 
      Compiledp3(DIRLPW,"DIRLPW"); 
      Compiledp1(DECA,"DECOMP0A"); 
      Compiledp1(DEC0,"DECOMP0"); 
(*3*) (*from DIPIDEAL system. *)
      Compiledf2(DIRLCT,"DIRLCT"); 
      Compiledf3(DIRLIP,"DIRLIP"); 
(*4*) (*from DIPROOT system. *)
      Compiledp2(ZSET,"ZSET"); 
      Compiledp2(ZSET,"ROOTS"); 
      Compiledp3(GBZSET,"GBZSET"); 
(*5*) (*from UGB system. *)
      Compiledp0(UGBBIN,"UGBBIN"); 
      Compiledp0(UGBBIN,"UGBIN"); (*for convienience.*) 
(*6*) (*from integer d-groebner bases. *)
      Compiledf2(DIIPSPOL,"DIIPSPOL");
      Compiledf2(DIIPGPOL,"DIIPGPOL");
      Compiledf3(DIIPDNF,"DIIPDNF");
      Compiledf3(DIIPENF,"DIIPENF");
      Compiledf1(DIIPCPLMS1,"DIIPCPLMS1");
      Compiledf1(DIIPELIMDGB,"DIIPELIMDGB");
      Compiledf1(DIIPREDDGB,"DIIPREDDGB");
      Compiledf2(DIIPLM1,"DIIPLM1");
      Compiledf3(DIIPTDR,"DIIPTDR");
      Compiledf2(DIIPDGB,"DIIPDGB");
      Compiledf2(DIIPEGB,"DIIPEGB");
(*9*) END InitExternalsD;


PROCEDURE ZSET(P,e: LIST);
(*Zero set. Interface to GBZSET. *)
BEGIN
(*1*) GBZSET(VALIS,P,e);
(*9*) END ZSET;


PROCEDURE DIM(P: LIST);
(*Dimension. Interface to DILDIM and DIDIMWR. *)
VAR   DL, S, M: LIST;
BEGIN
(*1*) DILDIM(P, DL,S,M); DIDIMWR(DL,S,M,VALIS);
(*9*) END DIM;


PROCEDURE DEC0(P: LIST);
(*Decomposition. Interface to DIRLPD and DIRLPW. *)
VAR   L: LIST;
BEGIN
(*1*) L:=DIRLPD(P,VALIS); DIRLPW(P,VALIS,L); 
(*9*) END DEC0;


PROCEDURE DECA(P: LIST);
(*Decomposition over Q(alpha). Interface to DIRPDA and DIRLPW. *)
VAR   L: LIST;
BEGIN
(*1*) L:=DIRPDA(P,VALIS); DIRLPW(P,VALIS,L); 
(*9*) END DECA;


END MASLOADD.

(* -EOF- *)
