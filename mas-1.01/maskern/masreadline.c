/* -------------------------------------------------------------------- -*-C-*-
 * $Id: masreadline.c,v 1.4 1995/11/04 17:54:51 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: masreadline.c,v $
 * Revision 1.4  1995/11/04 17:54:51  pesch
 * Fixed typos.
 *
 * Revision 1.3  1995/09/13  14:23:48  pesch
 * New function xputchar() rplaces putchar which may be a cpp-macro.
 *
 * Revision 1.2  1995/09/12  17:19:40  pesch
 * Now uses termcap, if possible.
 * Corrected prompt for lisp and ALDES mode.
 * Uses on_exit() if atexit() is not available (as on SUNs).
 *
 * Revision 1.1  1995/03/06  16:35:07  pesch
 * New function masReadL to replace Readl(StdInput, ). Will use the GNU readline
 * library if available. A history file .mashistory or ~/.mashistory if kpathsea
 * is available will be kept.
 *
 * ----------------------------------------------------------------------------
 */

const static char rcsid[] = "$Id: masreadline.c,v 1.4 1995/11/04 17:54:51 pesch Exp $";
const static char copyright[] = "Copyright (c) 1995 Universitaet Passau";
const static char compiletime[] = "Compiled at " __DATE__ " " __TIME__;
#ifdef __GNUC__
const static char compiler[] = "Compiled with GNU C Version " __VERSION__;
#else
const static char compiler[] = "???";
#endif /* __GNUC__ */

#include <SYSTEM_.h>

#ifndef DEFINITION_IO
# include <IO.h>
#endif

#ifndef DEFINITION_Strings
# include <Strings.h>
#endif

#include <config.h>

#include <string.h>

#ifdef HAVE_LIBREADLINE
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
#endif /* HAVE_LIBREADLINE */

#ifdef HAVE_LIBKPATHSEA
# include <kpathsea/pathsearch.h>
#endif /* HAVE_LIBKPATHSEA */

#ifdef HAVE_LIBREADLINE

#ifdef HAVE_TERMCAP_H
# include <termcap.h>
#elif defined HAVE_LIBTERMCAP
extern int tgetent(char *, char *);
extern char *tgetstr(char *, char **);
extern char *tgoto(char *, int, int, ...);
extern int tputs(char *, int, int (*)());
extern char *BC, *UP;
#endif
 
#ifndef DEFINITION_MASU
# include "MASU.h"
#endif


extern int use_readline;
extern const char *program_name;
static char * tc_le;

/* Same as putchar() but surely not a macro */
int
xputchar(char c) { return putchar(c); }

/* Read a string, and return a pointer to it.  Returns NULL on EOF. */
char *
rl_gets () {

  /* A static variable for holding the line. */

  static char *line_read = (char *)NULL;
  /* If the buffer has already been allocated, return the memory
     to the free pool. */
  if (line_read) {
    free (line_read);
    line_read = (char *)NULL;
  }
  
  /* Get a line from the user. */
  if (MASU_PromptFirst==TRUE) {
    { int i;
      for (i=0; i<MASU_WroteChars; i++) 
#ifdef HAVE_LIBTERMCAP
	tputs(tc_le, 1, xputchar);
#else
        printf(tc_le);
#endif
    }
    switch (MASU_PromptType) {
    case 0: line_read = readline ("MAS: "); break;
    case 1: line_read = readline ("LISP: "); break;
    case 2: line_read = readline ("ALD: "); break;
    default: line_read = readline ("MAS: ");
    }
    MASU_WroteChars=0;
    MASU_PromptFirst=FALSE;
  }
  else line_read = readline ("> ");
  
  /* If the line has any text in it, save it on the history. */
  if (line_read && *line_read) add_history (line_read);

  return (line_read);
}

#endif /* HAVE_LIBREADLINE */


void masReadL (Strings_tString *s) {

#ifdef HAVE_LIBREADLINE
  if (use_readline==1) {
    char *g;
    s->Chars.A[Strings_cMaxStrLength]='\0';
    s->Chars.A[0]='X';
    if ((g=rl_gets()) != (char *) NULL) {
      (void) strncpy((s->Chars.A)+1, g, Strings_cMaxStrLength-1);
      s->Length=(Strings_tStringIndex) strlen((s->Chars.A)+1);
    }
    else {
      (void) strncpy((s->Chars.A)+1,".EXIT().", Strings_cMaxStrLength-1);
      s->Length=(Strings_tStringIndex) strlen((s->Chars.A)+1);
    }
  }
  else
#endif /* HAVE_LIBREADLINE */
    Strings_ReadL(IO_StdInput, s);
}

static char * mashistory="";

static char tc_buffer[2048];

#ifdef HAVE_LIBREADLINE
static void rlexit() {(void) write_history(mashistory);}
#endif

void
BEGIN_masreadline() {
  static BOOLEAN has_been_called = FALSE;
  if (!has_been_called) {
#ifdef HAVE_LIBREADLINE
    using_history();
#ifdef HAVE_LIBKPATHSEA
    mashistory=kpse_path_search("", "~/.mashistory", 1);
    if (mashistory==NULL)
#endif /* HAVE_LIBKPATHSEA */
    mashistory=".mashistory";
    (void) read_history(mashistory);;

#ifdef HAVE_ATEXIT
    atexit(rlexit);
#elif defined HAVE_ON_EXIT
    on_exit(rlexit);
#else
#error You do not have atexit() (or on_exit()). Complain to your vendor!
#endif

#ifdef HAVE_LIBTERMCAP
    { int t; char *term;
      term=getenv("TERM");
      if (term==(char *)NULL) {
	fprintf(stderr, "\n%s: Error: Environment variable TERM not set.\n",
		program_name);
	exit(-3);
      }

      t=tgetent(tc_buffer, term);
      if (t==0) {
	fprintf(stderr, "\n%s: Error: No entry for %s in termcap.\n",
		program_name, term);
	exit(-3);
      }
      if (t==-1) {
	fprintf(stderr, "\n%s: Error: No termcap file.\n",
		program_name);
	exit(-3);
      }
    }
    { char *tc_area=(char *) malloc(strlen(tc_buffer));
      if((tc_le=tgetstr("le", &tc_area))==(char *)NULL) tc_le="\b";
    }
#else
    tc_le="\b";
#endif /* HAVE_LIBTERMCAP */

#endif /* HAVE_LIBREADLINE */
  }
};
/* -EOF- */
