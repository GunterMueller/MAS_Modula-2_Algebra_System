(* ----------------------------------------------------------------------------
 * $Id: MASLOADE.mi,v 1.16 1995/03/06 15:55:40 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASLOADE.mi,v $
 * Revision 1.16  1995/03/06  15:55:40  pesch
 * Added procedure GSYSF.
 *
 * Revision 1.15  1994/11/28  21:17:40  dolzmann
 * Removed double entry of DIPLIR.
 *
 * Revision 1.14  1994/11/03  14:56:41  pfeil
 * added procedures SetTraceLevel, SetDecompProc, SetUpdateProc, SetVarOrdOpt,
 * SetFacSugar, SetReduceExp, SetBranchProc, WriteDCGBopt.
 *
 * Revision 1.13  1994/10/27  13:42:03  rose
 * Superfluous function GSYSF removed.
 *
 * Revision 1.12  1994/10/21  15:09:35  pesch
 * added DIPLIR.
 *
 * Revision 1.11  1994/09/01  13:29:45  pfeil
 * added procedures from module DIPDCGB and DIPADOM.
 *
 * Revision 1.10  1994/05/19  10:28:59  rose
 * DIPAGB procedures added.
 *
 * Revision 1.9  1994/04/14  18:04:38  dolzmann
 * Adapted to the new modules ADTOOLS and DIPTOOLS.
 * The procedure AdLoadConvFunc is called after the domains have been loaded.
 *
 * Revision 1.8  1994/03/30  14:42:50  pesch
 * Made GSYSRED available through the interpreter.
 *
 * Revision 1.7  1994/03/14  16:43:39  pesch
 * Minor changes requested by A. Dolzmann.
 *
 * Revision 1.6  1994/03/11  15:39:55  pesch
 * Additions for CGB, MASROOT and NNGB.
 *
 * Revision 1.5  1993/05/11  10:56:35  kredel
 * Added modules MASUGB DIPIDGB DIPDDGB.
 *
 * Revision 1.4  1992/10/15  16:30:35  kredel
 * Changed rcsid variable.
 *
 * Revision 1.3  1992/06/12  13:55:24  kredel
 * Added new domain DOMRP.
 *
 * Revision 1.2  1992/02/12  17:32:52  pesch
 * Moved CONST definition to the right place.
 *
 * Revision 1.1  1992/01/22  15:12:15  kredel
 * Initial revision.
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASLOADE;

(* MAS Load Implementation Module E. *)



(* Import lists and declarations. *)

FROM MASLISPU IMPORT Declare,
                     Compiledp0, Compiledp1, Compiledp2, 
                     Compiledf0, Compiledf1, Compiledf2, Compiledf3,
                     Compiledp1v2, Compiledp2v2, Compiledp2v3, 
                     Compiledp3v2, Compiledp3v3; 

FROM DIPADOM IMPORT DILRD, DILWR, DIFIP, DIREAD, DIWRIT, DIPBCP,
                    DIPEXP, DIPDIF, DIPNEG, DIPROD, DIPSUM, DIPFAC,
		    DIPSFF, DIPS, DIPNF, DIPIRL, DIPLIR; 

FROM MASADOM IMPORT DomSummary, 
                    ADDIF, ADEXP, ADFI, ADFIP, ADGCD, ADGCDE, ADINV, 
                    ADINVT, ADLCM, ADNEG, ADONE, ADPROD, ADQUOT, 
                    ADREAD, ADSIGN, ADSUM, ADWRIT, 
                    ADDDREAD, ADDDWRIT, ADVLDD;
                    
FROM DIPTOOLS	IMPORT	DILPROD, DIPPOWER, DIPFDIPP, DIPPFDIP,
			DIPCONV, DILCONV;

 
FROM DINNGB IMPORT DINNCP, DNNLGB, DNNRGB, DNN2GB, DNNTGB;

FROM DOMAF IMPORT DomLoadAF;
 
FROM DOMI  IMPORT DomLoadI;

FROM DOMFF IMPORT DomLoadFF;

FROM DOMIP IMPORT DomLoadIP;
 
FROM DOMMD IMPORT DomLoadMD;
 
FROM DOMMI IMPORT DomLoadMI;
 
FROM DOMRF IMPORT DomLoadRF;
 
FROM DOMRN IMPORT DomLoadRN;
 
FROM DOMRP IMPORT DomLoadRP;
 
FROM DOMC   IMPORT DomLoadC;

FROM CGBMAIN IMPORT CGBIN, GSYS, GSYSF, GSYSDIM, GSYSRED, CGBFGSYS, CGBGLOBRED,
     	            CGBQFF, CGBQFWRITE;

FROM CGBDSTR IMPORT CdpRead, CdpWrite, CgbWrite, GsWrite, PdWrite;

FROM CGBMISC IMPORT CGBOPT, CGBOPTWRITE;

FROM DOMQ   IMPORT DomLoadQ;
 
FROM DOMO   IMPORT DomLoadO;
 
FROM DOMAPF IMPORT DomLoadAPF;

FROM DIPGB IMPORT DIPGB, DIPNOR, DIPSP, DILIS, 
                  DIIFGB, DIIFNF, DIIFSP, DIIFLS;

FROM DIPDDGB IMPORT DIDPSPOL, DIDPGPOL, DIDPDNF, DIDPCPLMS1, DIDPLM1,
                    DIDPUCPL1, DIDPELIMDGB, DIDPREDDGB,
                    DIDPLEXTAL, DIDPALCMPC, DIDPTDR, DIDPENF,DIDPEGB,
                    DIDPDGB;

FROM DIPDCGB IMPORT SetDCGBopt, SetTraceLevel, SetDecompProc, SetUpdateProc,
		    SetVarOrdOpt, SetReduceExp, SetFacSugar, SetBranchProc,
		    WriteDCGBopt,
		    GroebnerBases1, GroebnerBases2;

FROM DIPAGB IMPORT DIPAGB, LRNWRIT, SetDIPAGBOptions, SetDIPAGBTraceFlag,
                   SetDIPAGBStrategy, SetDIPAGBVariableWeight,
                   WriteDIPAGBOptions, WriteDIPAGBTraceFlag,
                   WriteDIPAGBStrategy, WriteDIPAGBVariableWeight;
                   
FROM ADTOOLS	IMPORT	AdLoadConvFunc;

CONST rcsidi = "$Id: MASLOADE.mi,v 1.16 1995/03/06 15:55:40 pesch Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE InitExternalsE;
(*Initialize external compiled polynomial procedures. *)
BEGIN 
(*1*) (*domains. *)
      DomLoadAF(); 
      DomLoadI();
      DomLoadIP(); 
      DomLoadMD(); 
      DomLoadMI(); 
      DomLoadFF(); 
      DomLoadRF(); 
      DomLoadRN(); 
      DomLoadC(); 
      DomLoadQ(); 
      DomLoadO(); 
      DomLoadRP(); 
      DomLoadAPF(); 
      AdLoadConvFunc();
(*2*) (*from arbitrary domains. *)
      Compiledp0(DomSummary,"DOMAINS");

      Compiledf2(ADDIF,"ADDIF"); 
      Compiledf2(ADEXP,"ADEXP"); 
      Compiledf2(ADFI,"ADFI"); 
      Compiledf2(ADFIP,"ADFIP"); 
      Compiledf2(ADGCD,"ADGCD"); 
      Compiledp2v3(ADGCDE,"ADGCDE"); 
      Compiledf1(ADINV,"ADINV"); 
      Compiledf1(ADINVT,"ADINVT"); 

      Compiledf2(ADLCM,"ADLCM"); 
      Compiledf1(ADNEG,"ADNEG"); 
      Compiledf1(ADONE,"ADONE"); 
      Compiledf2(ADPROD,"ADPROD"); 
      Compiledf2(ADQUOT,"ADQUOT"); 

      Compiledf1(ADREAD,"ADREAD"); 
      Compiledf1(ADSIGN,"ADSIGN"); 
      Compiledf2(ADSUM,"ADSUM"); 
      Compiledp1(ADWRIT,"ADWRIT"); 

      Compiledf0(ADDDREAD,"ADDDREAD"); 
      Compiledp1(ADDDWRIT,"ADDDWRIT"); 
      Compiledf1(ADVLDD,"ADVLDD"); 
(*3*) (*from arbitrary domain distributive polynomials. *)
      Compiledf2(DILRD,"DILRD");
      Compiledp2(DILWR,"DILWR");
      Compiledf2(DIFIP,"DIFIP");
      Compiledf2(DIREAD,"DIREAD");
      Compiledp2(DIWRIT,"DIWRIT");
      Compiledf2(DIPBCP,"DIPBCP");
      Compiledf2(DIPEXP,"DIPEXP");
      Compiledf2(DIPDIF,"DIPDIF");
      Compiledf1(DIPLIR,"DIPLIR");
      Compiledf1(DIPNEG,"DIPNEG");
      Compiledf2(DIPROD,"DIPROD");
      Compiledf2(DIPSUM,"DIPSUM");
      Compiledf2(DIPFAC,"DIPFAC");
      Compiledf2(DIPSFF,"DIPSFF");
      Compiledf2(DIPS,"DIPS");
      Compiledf2(DIPNF,"DIPNF");
(*4*) (*from comprehensive GB. *)
      Compiledp0(CGBIN,"CGBIN");
      Compiledp1(CGBOPT,"CGBOPT");
      Compiledp0(CGBOPTWRITE,"CGBOPTWRITE");
      Compiledf0(CdpRead,"CDPREAD");
      Compiledp1(CdpWrite,"CDPWRITE");
      Compiledf1(GSYS,"GSYS");
      Compiledf1(GSYSF,"GSYSF");
      Compiledf1(GSYSDIM,"GSYSDIM");
      Compiledf1(GSYSRED,"GSYSRED");
      Compiledp1(GsWrite,"GSYSWRITE");
      Compiledf1(CGBFGSYS,"CGBFGSYS");
      Compiledf1(CGBGLOBRED,"CGBGLOBRED");
      Compiledf1(CGBQFF,"CGBQFF");
      Compiledp1(CGBQFWRITE,"CGBQFWRITE");
      Compiledp1(CgbWrite,"CGBWRITE");
      Compiledp1(PdWrite,"PdWRITE");
(*5*) (*from groebner bases system. *)
      Compiledf2(DIPSP,"DIPSP"); (*arbitrary field*)
      Compiledf2(DIPNOR,"DIPNOR");
      Compiledf1(DILIS,"DILIS");
      Compiledf2(DIPGB,"DIPGB");
      Compiledf2(DIIFSP,"DIIFSP"); (*integral*)
      Compiledf3(DIIFNF,"DIIFNF");
      Compiledf1(DIIFLS,"DIIFLS");
      Compiledf2(DIIFGB,"DIIFGB");
(*6*) (*from domain d-groebner bases. *)
      Compiledf2(DIDPSPOL,"DIDPSPOL");
      Compiledf2(DIDPGPOL,"DIDPGPOL");
      Compiledf3(DIDPDNF,"DIDPDNF");
      Compiledf3(DIDPENF,"DIDPENF");
      Compiledf1(DIDPCPLMS1,"DIDPCPLMS1");
      Compiledf1(DIDPELIMDGB,"DIDPELIMDGB");
      Compiledf1(DIDPREDDGB,"DIDPREDDGB");
      Compiledf2(DIDPLM1,"DIDPLM1");
      Compiledf3(DIDPTDR,"DIDPTDR");
      Compiledf2(DIDPDGB,"DIDPDGB");
      Compiledf3(DIDPEGB,"DIDPEGB");

      (* from decompositional groebner bases *)
      Compiledp1(SetDCGBopt,"SetDCGBopt");
      Compiledp1(SetTraceLevel,"SetTraceLevel");
      Compiledp1(SetDecompProc,"SetDecompProc");
      Compiledp1(SetUpdateProc,"SetUpdateProc");
      Compiledp1(SetVarOrdOpt,"SetVarOrdOpt");
      Compiledp1(SetReduceExp,"SetReduceExp");
      Compiledp1(SetFacSugar,"SetFacSugar");
      Compiledp1(SetBranchProc,"SetBranchProc");
      Compiledp0(WriteDCGBopt,"WriteDCGBopt");
      Compiledf1(GroebnerBases1,"GB1");
      Compiledf2(GroebnerBases2,"GB2");

(*7*) (*from DIP arbitrary domain groebner bases. *)
      Compiledf1(DIPAGB,"DIPAGB");
      Compiledp1(LRNWRIT,"LRNWRIT");
      Compiledp1(SetDIPAGBOptions,"SetDIPAGBOptions");
      Compiledp1(SetDIPAGBTraceFlag,"SetDIPAGBTraceFlag");
      Compiledp1(SetDIPAGBStrategy,"SetDIPAGBStrategy");
      Compiledp1(SetDIPAGBVariableWeight,"SetDIPAGBVariableWeight");
      Compiledp0(WriteDIPAGBOptions,"WriteDIPAGBOptions");
      Compiledp0(WriteDIPAGBTraceFlag,"WriteDIPAGBTraceFlag");
      Compiledp0(WriteDIPAGBStrategy,"WriteDIPAGBStrategy");
      Compiledp0(WriteDIPAGBVariableWeight,"WriteDIPAGBVariableWeight");

(*8*) (*from non-notherian GB. *)
      Compiledf3(DINNCP,"DINNCP");
      Compiledf3(DNNLGB,"DNNLGB");
      Compiledf3(DNNRGB,"DNNRGB");
      Compiledf3(DNN2GB,"DNN2GB");
      Compiledf3(DNNTGB,"DNNTGB");
     
(* *) (* from distributive polynomials tools *)      
      Compiledf2(DIPPOWER,"DIPPOWER");
      Compiledf2(DILPROD,"DILPROD");
      Compiledp2v2(DIPFDIPP,"DIPFDIPP");
      Compiledp3v2(DIPPFDIP,"DIPPFDIP");
      Compiledf2(DIPCONV,"DIPCONV");
      Compiledf2(DILCONV,"DILCONV");

(*9*) END InitExternalsE;


END MASLOADE.


(* -EOF- *)








