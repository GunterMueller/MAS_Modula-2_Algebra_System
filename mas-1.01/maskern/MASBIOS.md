(* ----------------------------------------------------------------------------
 * $Id: MASBIOS.md,v 1.6 1995/03/06 16:00:49 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASBIOS.md,v $
 * Revision 1.6  1995/03/06  16:00:49  pesch
 * Added kpathsea and GNU readline support.
 * Added new procedures IStreamKind, OStreamKind, EStreamKind.
 *
 * Revision 1.5  1993/05/11  10:45:34  kredel
 * Uninitialized variable in input
 *
 * Revision 1.4  1993/03/22  10:34:34  kredel
 * Cosmetic
 *
 * Revision 1.3  1992/10/16  13:47:48  kredel
 * Errors found by Mocka
 *
 * Revision 1.2  1992/02/12  17:31:49  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:10:04  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)
 
DEFINITION MODULE MASBIOS; 

(* MAS Basic I/O System Definition Module. *)

 
(* Import lists and Definitions *) 
 
  FROM MASELEM IMPORT GAMMAINT; 
 
  FROM MASSTOR IMPORT LIST; 
 
  VAR  CHI : GAMMAINT; 
 
CONST rcsid = "$Id: MASBIOS.md,v 1.6 1995/03/06 16:00:49 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";
 
CONST
        termkind = 1; 
        diskkind = 2; 
        ramkind = 3; 
        winkind = 4; 
        nulkind = 5; 
        grakind = 6; 
 
PROCEDURE BKSP(); 
(*Backspace.  Reread the last character from the input stream. *) 
 
 
PROCEDURE BLINES(N : GAMMAINT); 
(*Blank lines.  N is a positive integer.  N records of one blank each 
are output. *) 
 
 
PROCEDURE CREAD(): GAMMAINT; 
(*Character read.  Returns next character from the input stream. *) 
 
 
PROCEDURE CREADB(): GAMMAINT; 
(*Character read, skipping blanks. Returns next character from the 
input stream. *) 
 
 
PROCEDURE CWRITE(C : GAMMAINT); 
(*Character write. The character c is transmitted to the output 
stream. *) 
 
 
PROCEDURE CloseBIOS(); 
(*Close BIOS.  Close all streams and write summary. *) 
 
 
PROCEDURE CUNIT(S : ARRAY OF CHAR): GAMMAINT; 
(*Close unit.  The unit S is closed, with S as the external name. 
CUNIT returns 0 on successful completion, ne 0 else.*) 
 
 
PROCEDURE DIBUFF(); 
(*Display input buffer.  The input buffer status is displayed.*) 
 
 
PROCEDURE DIGIT(C : GAMMAINT): BOOLEAN; 
(*Digit.  c is a character.  If c is a digit then TRUE is returned 
otherwise FALSE is returned. *) 
 
 
PROCEDURE GREAD(): GAMMAINT; 
(*Gamma-integer read.  A gamma-integer is read from the input 
stream.  any preceding blanks are skipped. *) 
 
 
PROCEDURE GWRITE(a : GAMMAINT); 
(*Gamma-integer write.  The gamma-integer a is written in the output 
stream.*) 
 
 
PROCEDURE LETTER(C : GAMMAINT): BOOLEAN; 
(*Letter.  c is a character.  If c is a letter then TRUE is returned 
otherwise FALSE is returned. *) 
 
 
PROCEDURE LISTS(S : ARRAY OF CHAR ): LIST; 
(*List from string. S is a character string with respect to local 
character code. A list if the corresponding ALDES character codes 
is returned.*) 
 
 
PROCEDURE SLIST(A : LIST; VAR S : ARRAY OF CHAR); 
(*String from list. A is a list of ALDES character codes.  
S is a the corresponding character string with respect to local 
character codes. *) 
 
 
PROCEDURE MASCHR(C : GAMMAINT): CHAR; 
(*MAS character.  Returns the local character for the aldes character c. *) 
 
 
PROCEDURE MASORD(C : CHAR): GAMMAINT; 
(*MAS order.  Returns the aldes code for the character c. *) 
 
 
PROCEDURE MASORDI(C : GAMMAINT): GAMMAINT; 
(*MAS order integer.  Returns the aldes code for the integer c.*) 
 
 
PROCEDURE SILINE(VAR S, L, R : GAMMAINT); 
(*Set input line.  The input line length is set to S, the left margin is  
set to L and the right margin is set to R. If any of the values of  
S, L or R is negative, then the corresponding value is left unchanged.  
The values in effect are returned. *) 
 
 
PROCEDURE SIUNIT(S : ARRAY OF CHAR): GAMMAINT; 
(*Set input unit.  iunit is set to n, with s as the external name. 
siunit returns 0 on successful completion, ne 0 else.*) 
 
 
PROCEDURE SOLINE(VAR S, L, R : GAMMAINT); 
(*Set output line.  The output line length is set to S, the left margin is  
set to L and the right margin is set to R. If any of the values of  
S, L or R is negative, then the corresponding value is left unchanged.  
The values in effect are returned. *) 
 
 
PROCEDURE SOUNIT(S : ARRAY OF CHAR): GAMMAINT; 
(*Set output unit.  ounit is set to n, with s as the external name. 
sounit returns 0 on successful completion, ne 0 else. 
the current output buffer is emptied.*) 
 
 
PROCEDURE Summary(); 
(*Summary of stream IO. *) 
 
 
PROCEDURE StorSummary(); 
(*MASSTOR Summary. *) 
 
 
PROCEDURE SWRITE(S : ARRAY OF CHAR); 
(*String write. S is a character string with respect to local  
character codes. The single characters are converted to ALDES codes 
and written to the output stream. *) 
 
 
PROCEDURE TAB(n : GAMMAINT); 
(*Tabulate.  n is a positive integer.  if lmarg le n le rmarg then 
blanks are inserted in obuff until opos eq n.*) 
 
PROCEDURE IStreamKind(): INTEGER;
(* Input stream kind. The kind of the current input stream is returned. *)

PROCEDURE OStreamKind(): INTEGER;
(* Output stream kind. The kind of the current output stream is returned. *)

PROCEDURE EStreamKind(): INTEGER;
(* Error stream kind. The kind of the current error stream is returned. *)

END MASBIOS. 
(* -EOF- *)
