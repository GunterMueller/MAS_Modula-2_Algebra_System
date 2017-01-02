/* -------------------------------------------------------------------- -*-C-*-
 * $Id: raise.c,v 1.2 1995/09/13 14:21:00 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: raise.c,v $
 * Revision 1.2  1995/09/13  14:21:00  pesch
 * Includes signal.h now.
 *
 * Revision 1.1  1995/09/12  17:10:29  pesch
 * Replacement for raise() ANSI C library function, which is missing on SUNs.
 *
 * ----------------------------------------------------------------------------
 */

const static char rcsid[] = "$Id: raise.c,v 1.2 1995/09/13 14:21:00 pesch Exp $";
const static char copyright[] = "Copyright (c) 1995 Universitaet Passau";
const static char compiletime[] = "Compiled at " __DATE__ " " __TIME__;
# ifdef __GNUC__
const static char compiler[] = "Compiled with GNU C Version " __VERSION__;
# else
const static char compiler[] = "???";
# endif /* __GNUC__ */

#include "config.h"

#ifndef HAVE_RAISE
#include <signal.h>
#include <sys/types.h>

/* Send signal signal to the calling process.
   Replacement for ANSI C library function raise() which is missing
   on SUNs.
*/
int
raise(int signal) {
  return kill(getpid(), signal);
}

#endif
/* -EOF- */
