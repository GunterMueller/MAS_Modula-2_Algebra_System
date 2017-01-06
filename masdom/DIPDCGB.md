(* ----------------------------------------------------------------------------
 * $Id: DIPDCGB.md,v 1.3 1994/11/28 20:52:49 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1994 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPDCGB.md,v $
 * Revision 1.3  1994/11/28  20:52:49  dolzmann
 * Syntactical errors corrected.
 * Usage of predefined procedure types.
 *
 * Revision 1.2  1994/11/03  14:40:54  pfeil
 * added procedures SetTraceLevel, SetDecompProc, SetUpdateProc, SetVarOrdOpt,
 * SetFacSugar, SetReduceExp, SetBranchProc, WriteDCGBopt.
 * modified procedure GroebnerBases1 for sugar.
 * added procedure EQIEQ (Graebe/Lassner) for procedure GrobnerBases2
 *
 * Revision 1.1  1994/08/31  13:27:45  pfeil
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DIPDCGB;

(* DIP Decompositional Groebner Bases Definition Module. *)



FROM MASSTOR IMPORT LIST;
FROM MASLISPU IMPORT PROCF1, PROCF2, PROCP1V2, PROCP0V2; 

CONST rcsid = "$Id: DIPDCGB.md,v 1.3 1994/11/28 20:52:49 dolzmann Exp $";
CONST copyright = "Copyright (c) 1989 - 1994 Universitaet Passau";


(* TYPE	PROCF1 = PROCEDURE(LIST): LIST;
	PROCF2 = PROCEDURE(LIST, LIST): LIST;
	PROCP1V2 = PROCEDURE(LIST, VAR LIST, VAR LIST);
	PROCP0V2 = PROCEDURE(VAR LIST, VAR LIST); *)

PROCEDURE SetTraceLevel(TL: INTEGER);
(* Set Trace-Level for decompositional groebner bases:
      0 = no output, except with VOOB,
     >0 = output of time and result after computation,
     >1 = output of messages about tree of computation:
	  number of canceled branches/factors, "cancel factor",
          "cancel branch", "groebner base", "branch w.o. zeros",
     >2 = output of s-polynomials and normalforms,
     >3 = output of parameters of local procedures
          and of time and groebner bases during computation. *)

PROCEDURE SetDecompProc(DCP: INTEGER);
(* Set Decomposition-Procedure for decompositional groebner bases:
      1 = DIPFAC,
      2 = DIPSFF. *)

PROCEDURE SetUpdateProc(UP: INTEGER);
(* Set Update-Procedure for decompositional groebner bases: 
      1 = UPDATE from module DIPAGB. *)

PROCEDURE SetVarOrdOpt(VOO: INTEGER);
(* Set Variable-Order-Optimization for decompositional groebner bases: 
      0 = don`t optimize,
      1 = optimize at begin only,
      2 = optimize factorization only,
      3 = optimize at begin and factorization *)

PROCEDURE SetFacSugar(FS: INTEGER);
(* Set Factor-Sugar for procedure GroebnerBases1: 
      0 = sugar of factor is total degree of factor,
      1 = sugar of factor is old sugar *)

PROCEDURE SetReduceExp(RE: INTEGER);
(* Set Reduce-Exponent for procedure GroebnerBases2:
      1 = reduce (no power of) polynomial
     >1 = reduce corresponding power of polynomial *)

PROCEDURE SetBranchProc(BP: INTEGER);
(* Set Branch-Procedure for procedure GroebnerBases2:
      1 = SSCO  - new branch for each subset of factors,
      2 = EQIEQ - new branch for each factor *)

PROCEDURE SetDCGBopt(options: LIST);
(* Set options for decompositional groebner bases.
   options is a list of 7 or less elements in following order:
   1. Trace-Level (0-4),
   2. No. of Decomposition-Procedure (1,2),
   3. No. of Update-Procedure (1),
   4. Optimization of variable order (0,1,2,3),
   5. Sugar of factors for Procedure GroebnerBases1 (0,1),
   6. Reduce-Exponent for procedure GroebnerBases2 (>0),
   7. No. of Branch-Procedure in GroebnerBases2 (1,2).
*)

PROCEDURE WriteDCGBopt;
(* write decompositional groebner bases options *)


PROCEDURE GroebnerBases1(G: LIST): LIST; 
(* Distributive polynomials decompositional groebner bases 1.
   G is a list of polynomials in distributive representation
   over an arbitrary domain,
   returns a list (GB1,...,GBk) of groebner bases,
   where Z(G) = Z(GB1) v ... v Z(GBk). *)


PROCEDURE GroebnerBases2(G,U: LIST): LIST; 
(* Distributive polynomials decompositional groebner bases 2.
   G and U are lists of polynomials in distributive representation
   over an arbitrary domain,
   returns a list ((GB1,U1),...,(GBk,Uk)) of pairs (Gi,Ui), where
   Gi is a groebner bases, Ui is a list of polynomials and
   Z(G) n D(U) = (Z(GB1) n D(U1)) v ... v (Z(GBk) n D(Uk)). *)


END DIPDCGB.

(* -EOF- *)
