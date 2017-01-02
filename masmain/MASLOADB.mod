(* ----------------------------------------------------------------------------
 * $Id: MASLOADB.mi,v 1.8 1995/11/05 09:08:56 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASLOADB.mi,v $
 * Revision 1.8  1995/11/05 09:08:56  kredel
 * Access to PRIME.
 *
 * Revision 1.7  1995/11/04  22:14:39  pesch
 * New procedures EVOWRITE and EvordWrite.
 *
 * Revision 1.6  1995/11/04 20:36:21  pesch
 * Added DILBSO, DILFPL, PLFDIL, DIPBSO.
 *
 * Revision 1.5  1994/03/11  15:39:55  pesch
 * Additions for CGB, MASROOT and NNGB.
 *
 * Revision 1.4  1993/03/23  12:12:53  kredel
 * Added DIILWR
 *
 * Revision 1.3  1992/10/15  16:30:33  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:32:50  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:12:09  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASLOADB;

(* MAS Load Implementation Module B. *)



(* Import lists and declarations. *)

FROM MASLISPU	IMPORT	Compiledf0, Compiledf1, Compiledf2, Compiledf3,
			Compiledp0, Compiledp1, Compiledp1v2, Compiledp1v3,
			Compiledp2, Compiledp2v2, Compiledp2v3, Compiledp3,
			Compiledp3v2, Compiledp3v3, Declare;

FROM SACPOL IMPORT PFDP, PRIME;

FROM SACDPOL	IMPORT	DMPPRD, DMPSUM, DMUPNR, DPFP;

FROM SACIPOL	IMPORT	IPEXP, IPNEG, IPPROD, IPQR, IPSUM;

FROM SACPGCD	IMPORT	IPCPP, IPGCDC, IPPGSD, IPRES, IPRPRS;

FROM SACPFAC	IMPORT	IPFAC;

FROM SACROOT	IMPORT	IPRIM; 

FROM DIPC	IMPORT	DILBSO, DILFPL, DIPBSO, DIPEVL, DIPFMO, DIPFP,
			DIPLBC, DIPLDC, DIPMAD, DIPMRD, EVCADD, EVCOMP,
			EVDFSI, EVDIF, EVDOV, EVLCM, EVORD, EVOWRITE, EVSIGN,
			EVSUM, EVTDEG, EvordWrite, IGRLEX, INVLEX, PFDIP,
			PLFDIL, VALIS;

FROM DIPI	IMPORT	DIIFRP, DIILFR, DIILRD, DIILWR, DIIPDF, DIIPEX,
			DIIPPS, DIIPQR, DIIPRD, DIIPSM, DIIPWR;

FROM DIPRN	IMPORT	DIRFIP, DIRLRD, DIRLWR, DIRPDM, DIRPEX, DIRPNG,
			DIRPPR, DIRPQ, DIRPQR, DIRPRD, DIRPRP, DIRPRQ,
			DIRPSG, DIRPSM, DIRPWR;

FROM DIPRNPOL	IMPORT	RUPGCD;

FROM DIPRNGB	IMPORT	DIRLIS, DIRPGB, DIRPNF, DIRPSP;

FROM DIPIGB	IMPORT	DIILIS, DIIPGB, DIIPNF, DIIPSP;

FROM DIPGCD	IMPORT	DIRFAC;

FROM DIPTOO	IMPORT	DIPVOP; 

FROM MASYMDIP	IMPORT	InitExternalsI;

CONST rcsidi = "$Id: MASLOADB.mi,v 1.8 1995/11/05 09:08:56 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE InitExternalsB;
(*Initialize external compiled polynomial procedures. *)
BEGIN 
(*1*) (*from dense polynomial system. *)
      Compiledf2(DPFP,"DPFP"); 
(*2*) (*from recursive polynomial system. *)
      Compiledf2(PFDP,"PFDP");
      Compiledf0(GetPRIME,"PRIME");
      Compiledf3(IPPROD,"IPPROD");
      Compiledf3(IPSUM,"IPSUM");
      Compiledf3(IPEXP,"IPEXP");
      Compiledf2(IPNEG,"IPNEG"); 
(*3*) (*from distributive polynomial system. *)
      Compiledp1v2(PFDIP,"PFDIP");

      Compiledp1(DILBSO,"DILBSO");
      Compiledf2(DILFPL,"DILFPL");
      Compiledp1v2(PLFDIL,"PLFDIL");
      Compiledp1(DIPBSO,"DIPBSO");
      Compiledf1(DIPLDC,"DIPLDC");
      Compiledf1(DIPLBC,"DIPLBC");
      Compiledf2(DIRPRP,"DIRPRP");
      Compiledf1(DIRPSG,"DIRPSG");
      Compiledf1(DIRPRD,"DIRPRD");
      Compiledp3(DIRPWR,"DIRPWR");
      Compiledf1(DIRPDM,"DIRPDM");
      Compiledf2(DIRPQ,"DIRPQ");
      Compiledp2v2(DIRPQR,"DIRPQR");
      Compiledf2(DIRPRQ,"DIRPRQ");
      Compiledf2(RUPGCD,"RUPGCD");

      Compiledp2v2(EVDFSI,"EVDFSI");    (* used for AD-version *)
      Compiledf1(EVDOV,"EVDOV");
      Compiledf2(EVCOMP,"EVCOMP");
      Compiledp3v2(EVCADD,"EVCADD");
      Compiledp1(EVOWRITE,"EVOWRITE");
      Compiledp0(EvordWrite,"EVORDWRITE");
      Compiledf2(EVSUM,"EVSUM");
      Compiledf2(EVDIF,"EVDIF");
      Compiledf1(EVSIGN,"EVSIGN");
      Compiledf2(EVLCM,"EVLCM");
      Compiledf1(EVTDEG,"EVTDEG");
      Compiledf1(DIPEVL,"DIPEVL");
      Compiledf2(DIPFMO,"DIPFMO");
      Compiledf1(DIPMRD,"DIPMRD");
      Compiledp1v3(DIPMAD,"DIPMAD");

      Compiledf2(DIPFP,"DIPFP");
      Compiledf1(DIIFRP,"DIIFRP");
      Compiledf1(DIILFR,"DIILFR");
      Compiledf2(DIIPPS,"DIIPPS");
      Compiledp2v2(DIIPQR,"DIIPQR");
      Compiledp2(DIILWR,"DIILWR");
      Compiledf1(DIRFIP,"DIRFIP");
      Compiledf1(DIRLRD,"DIRLRD");
      Compiledf2(DIRPPR,"DIRPPR");
      Compiledf2(DIRPSM,"DIRPSM");
      Compiledf2(DIRPEX,"DIRPEX");
      Compiledf1(DIRPNG,"DIRPNG");
      Compiledp2v2(DIPVOP,"DIPVOP");
(*4*) (*from groebner bases system. *)
      Compiledf2(DIRPSP,"DIRPSP"); (*rational*)
      Compiledf2(DIRPNF,"DIRPNF");
      Compiledf1(DIRLIS,"DIRLIS");
      Compiledf2(DIRPGB,"DIRPGB");
      Compiledf2(DIIPSP,"DIIPSP"); (*integral*)
      Compiledf3(DIIPNF,"DIIPNF");
      Compiledf1(DIILIS,"DIILIS");
      Compiledf2(DIIPGB,"DIIPGB");
      Compiledf1(DIIPRD,"DIIPRD");
      Compiledp2(DIIPWR,"DIIPWR");
      Compiledf1(DIILRD,"DIILRD");
      Compiledf2(DIIPDF,"DIIPDF");
      Compiledf2(DIIPSM,"DIIPSM");
      Compiledf2(DIIPEX,"DIIPEX");
(*5*) (*from gcd system, factorization and root. *)
      Compiledp3v3(IPGCDC,"IPGCDC");
      Compiledf3(IPRES,"IPRES");
      Compiledf3(IPRPRS,"IPRPRS");
      Compiledp2v3(IPFAC,"IPFAC");
      Compiledf1(DIRFAC,"DIRFAC");
      Compiledf1(IPRIM,"IPRIM");
(*6*) (*initialize symbol interface. *)
      InitExternalsI;
(*9*) END InitExternalsB;


PROCEDURE GetPRIME(): LIST;
(*access global variable via function. *)
BEGIN RETURN(PRIME) END GetPRIME;


END MASLOADB.



(* -EOF- *)
