/* ----------------------------------------------------------------------------
 * $Id: masconf.c,v 1.15 1998/03/06 15:43:33 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 - 1998 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: masconf.c,v $
 * Revision 1.15  1998/03/06 15:43:33  pesch
 * Typo corrections.
 *
 * Revision 1.14  1996/07/21 18:50:44  pesch
 * Completed help text.
 *
 * Revision 1.13  1996/06/15 21:04:21  kredel
 * Adjusted copyright to 1996.
 *
 * Revision 1.12  1996/06/08 18:43:05  pesch
 * Removed basename().
 *
 * Revision 1.11  1996/06/08 18:26:53  pesch
 * Removed unused code, minor corrections.
 *
 * Revision 1.10  1995/11/05 10:52:38  kredel
 * Version 1.00 released
 *
 * Revision 1.9  1995/10/24  14:33:43  pesch
 * Modifications for kpathsea version 2.6. (Version 1.8 is still supported)
 *
 * Revision 1.8  1995/10/12 14:58:55  pesch
 * Text changed.
 *
 * Revision 1.7  1995/09/13  14:20:24  pesch
 * Text changed.
 *
 * Revision 1.6  1995/09/08  19:13:40  pesch
 * Defined EXIT_SUCCESS, EXIT_FAILURE if missing.
 * Fixed typos.
 * Fixed OutFileName if libkpathsea is not available.
 *
 * Revision 1.5  1995/06/15  07:49:15  dolzmann
 * Bug fixed: kpse_init_path requires NULL as the last parameter.
 *
 * Revision 1.4  1995/03/24  15:36:15  pesch
 * Changed inital message.
 *
 * Revision 1.3  1995/03/23  17:43:58  pesch
 * Added new options -E (exit on error) and -c (command).
 *
 * Revision 1.2  1995/03/23  16:01:26  pesch
 * New options -e (exit after loading files) and -o (output file).
 *
 * Revision 1.1  1995/03/06  16:06:40  pesch
 * Replaced MASCONF.mi by masconf.c using the GNU getopt_long function,
 * GNU readline and kpathsea.
 *
 * ----------------------------------------------------------------------------
 */

const static char rcsid[] = "$Id: masconf.c,v 1.15 1998/03/06 15:43:33 pesch Exp $";
const static char copyright[] = "Copyright (c) 1995 - 1998 Universitaet Passau";
const static char compiletime[] = "Compiled at " __DATE__ " " __TIME__;
# ifdef __GNUC__
const static char compiler[] = "Compiled with GNU C Version " __VERSION__;
# else
const static char compiler[] = "???";
# endif /* __GNUC__ */

#include "config.h"
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <SYSTEM_.h>
#include "MASCONF.h"

const char *program_path;
const char *program_name;

#ifdef HAVE_LIBKPATHSEA
# ifdef HAVE_KPATHSEA_PATHSEARCH_H
#  include <kpathsea/pathsearch.h>
# endif
# ifdef HAVE_KPATHSEA_LIB_H
#  include <kpathsea/lib.h>
# endif
# ifdef HAVE_KPATHSEA_INIT_PATH_H
#  include <kpathsea/init-path.h>
# else
#  include "init-path.h"
# endif 
# ifdef HAVE_KPATHSEA_PROGNAME_H
#  include <kpathsea/progname.h>
# endif
#endif /* HAVE_LIBKPATHSEA */

#ifdef HAVE_LIBKPATHSEA
char *masinputpath;
#endif

#ifndef EXIT_SUCCESS
# define EXIT_SUCCESS   0
#endif

#ifndef EXIT_FAILURE
# define EXIT_FAILURE   (1)
#endif

const static char copyright_string[] = "\
Copyright (c) 1989 - 1998 H. Kredel, Universitaet Mannheim\n\
                          M. Pesch, Universitaet Passau\n\
For the SAC-2 libraries:\n\
Copyright (c) 1982 G. E. Collins, University of Ohio\n\
                   R. Loos, Universitaet Tuebingen.\n\n\
(Non-profit redistribution is permitted)\n";

MASELEM_GAMMAINT MASCONF_KBCell;

struct MASCONF_1 MASCONF_InitName;
struct MASCONF_2 MASCONF_FileName;
struct MASCONF_3 MASCONF_OutFileName;
struct MASCONF_4 MASCONF_InitialCommand;
BOOLEAN MASCONF_ExitAfterFiles;
BOOLEAN MASCONF_ExitOnError;

void
usage (int status) {
  if (status != EXIT_SUCCESS)
    fprintf (stderr, "Try `%s %s' for more information.\n", program_name,
             "--help");
  else {
    printf("\nThis is %s, the Modula-2 Algebra System, Version %s\n",
	   PRODUCT, VERSION);
    printf ("\nUsage: %s [Options] [File]\n", program_name);
    fputs ("\n\
Where File is a MAS input file.\n\n\
Options:\n\
      --help            display this help and exit\n\
      --version         output version information and exit\n\
  -C, --copyright       display copyright and copying conditions\n\
  -c COMMAND, --command=COMMAND\n\
                        execute MAS command COMMAND before reading File\n\
",
           stdout);
#ifdef DEBUG
    fputs ("\
  -d, --debug           print debug information\n\
",
           stdout);
#endif
    fputs ("\
\n\
  -e, --exit            exit after all input files have been read\n\
  -E, --exit-on-error   exit when an error occurs\n\
  -f FILE, --file=FILE  input initialization file FILE instead of default\n\
  -m SIZE, --memorysize=SIZE\n\
                        set size of MAS memory to SIZE kbytes\n\
  -o[FILE], --output[=FILE]\n\
                        write output to FILE\n\
  -R, --no-readline     do not use the readline library for input\n\
\n\n\
Send bug-reports, questions, remarks to: mailto:mas@alice.fmi.uni-passau.de\n\
Information about MAS: http://alice.fmi.uni-passau.de/mas.html\n\
Get MAS from: ftp://alice.fmi.uni-passau.de/pub/ComputerAlgebraSystems/mas\n\n\
",
              stdout);
  }
  exit (status);
}

#ifdef DEBUG
int debug=0;
#endif

#ifdef HAVE_LIBREADLINE
int use_readline=1;
#endif

/* If non-zero, display usage information and exit.  */
static int show_help = 0;

/* If non-zero, print the version on standard output and exit.  */
static int show_version = 0;

static const struct option long_options[] =
{
#ifdef DEBUG
  {"debug", no_argument, NULL, 'd'},
#endif
  {"file", required_argument, NULL, 'f'},
  {"memorysize", required_argument, NULL, 'm'},
  {"output", optional_argument, NULL, 'o'},
  {"no-readline", no_argument, NULL, 'R'},
  {"exit", no_argument, NULL, 'e'},
  {"exit-on-error", no_argument, NULL, 'E'},
  {"command", required_argument, NULL, 'c'},

  {"copyright", no_argument, NULL, 'C'},
  {"help", no_argument, &show_help, 1},
  {"version", no_argument, &show_version, 1},

  { 0, 0, 0, 0 },
};

void
SetUp() {
  int c, cflag=0, fflag=0, mflag=0, oflag=0, errflag=0;
  extern int optind;
  extern char *optarg;
  char *s;
  MASCONF_KBCell=1000;
#ifdef HAVE_LIBKPATHSEA
  strcpy(MASCONF_InitName.A, "~/.masrc");
  strcpy(MASCONF_FileName.A, "");
  strcpy(MASCONF_OutFileName.A, "");
  masinputpath=kpse_init_path(DEFAULT_MASINPUTS ":.", DEFAULT_MASINPUTS ":.",
			      "MASINPUTS", NULL);
#else
  strcpy(MASCONF_InitName.A, "MAS.INI");
  strcpy(MASCONF_FileName.A, "");
  strcpy(MASCONF_OutFileName.A, "");
#endif
  MASCONF_ExitAfterFiles=FALSE;
  MASCONF_ExitOnError=FALSE;
  strcpy(MASCONF_InitialCommand.A, "");

  while ((c = getopt_long(SYSTEM_argc, SYSTEM_argv,
#ifdef HAVE_LIBREADLINE
#ifdef DEBUG
			  "RCc:dEef:m:o::",
#else
			  "RCc:Eef:m:o::",
#endif
#else
#ifdef DEBUG
			  "Cc:dEef:m:o::",
#else
			  "Cc:Eef:m:o::",
#endif
#endif

			  long_options, NULL)) != EOF)
    switch (c) {
      case 0 : break;
      case 'c': cflag++; strncpy(MASCONF_InitialCommand.A, optarg, 1000); break;
      case 'C': fprintf (stderr, "%s\n", copyright_string);
        exit (EXIT_SUCCESS);
#ifdef DEBUG
      case 'd': debug++; break;
#endif
      case 'E': MASCONF_ExitOnError=TRUE; break;
      case 'e': MASCONF_ExitAfterFiles=TRUE; break;
      case 'f': fflag++; strncpy(MASCONF_InitName.A, optarg, 253); break;
      case 'm': mflag++; MASCONF_KBCell=atoi(optarg); break;
      case 'o': oflag++; if (optarg != NULL)
	                   strncpy(MASCONF_OutFileName.A, optarg, 253); break;
#ifdef HAVE_LIBREADLINE
      case 'R': use_readline=0; break;
#endif
      default: usage(EXIT_FAILURE); break;
    }
  if (show_version) {
    printf("%s %s\n", PRODUCT, VERSION);
    exit(EXIT_SUCCESS); }
  if (show_help) usage(EXIT_SUCCESS);
  if (optind < SYSTEM_argc) {
    (void) strncpy(MASCONF_FileName.A, SYSTEM_argv[optind], 249);
#ifdef HAVE_EXTEND_FILENAME
    s=extend_filename(MASCONF_FileName.A, "mas");
    (void) strncpy(MASCONF_FileName.A, s, 253);
    free(s);
#endif
   if ((oflag>0) && (MASCONF_OutFileName.A[0]=='\0')) {
      (void) strncpy(MASCONF_OutFileName.A, MASCONF_FileName.A, 249);
#ifdef HAVE_MAKE_SUFFIX
      s=make_suffix(MASCONF_OutFileName.A, "out");
      (void) strncpy(MASCONF_OutFileName.A, s, 253);
      free(s);
#else
      (void) strcat(MASCONF_OutFileName.A, ".out");
#endif
    }
  }
}

void
BEGIN_MASCONF() {
  static BOOLEAN has_been_called = FALSE;
  if (!has_been_called) {
    BEGIN_MASELEM();
    BEGIN_MASmtc();
    BEGIN_Strings();
    has_been_called = TRUE;
#ifdef HAVE_KPSE_SET_PROGNAME
    kpse_set_progname(SYSTEM_argv[0]);
    program_path=program_invocation_name;
    program_name=program_invocation_short_name;
#else
    program_path = SYSTEM_argv[0];
    program_name = strrchr(program_path, '/');
    program_name = program_name ? program_name + 1 : program_path;
#endif
    SetUp();
    printf("\nThis is %s the Modula-2 Algebra System, Version %s.\n\n",
	   PRODUCT, VERSION); fflush(stdout);
  }
};

/* -EOF- */
