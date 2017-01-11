(* ----------------------------------------------------------------------------
 * $Id: GSYMINP.md,v 1.2 1996/06/09 10:20:20 pesch Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1996 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: GSYMINP.md,v $
 * Revision 1.2  1996/06/09 10:20:20  pesch
 * Removed unneccessary VAR line.
 *
 * Revision 1.1  1996/06/08 18:52:46  pesch
 * Input procedures for G-symmetric polynomials.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE GSYMINP;

(* GSYM Input Definition Module. *)

FROM MASSTOR	IMPORT	LIST;

CONST rcsid = "$Id: GSYMINP.md,v 1.2 1996/06/09 10:20:20 pesch Exp $";
CONST copyright = "Copyright (c) 1996 Universitaet Passau";

PROCEDURE GSDREAD(): LIST;
(* G-symmetric descriptor read.
--- to do ---: remove *)

PROCEDURE GSPREAD(): LIST;
(* G-symmetric polynomial read.
--- to do ---: remove *)

PROCEDURE GSRDREAD(): LIST;
(* G-symmetric rational descriptor read.
--- to do ---: remove *)

PROCEDURE GSRREAD(): LIST;
(* G-symmetric rational polynomial read.
--- to do ---: remove *)

END GSYMINP.
(* -EOF- *)
