/* ----------------------------------------------------------------------------
 * $Id: cmacros.c,v 1.4 1997/08/29 14:33:52 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1994 - 1997 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: cmacros.c,v $
 * Revision 1.4  1997/08/29 14:33:52  pesch
 * Changed ctime to compiletime, due to name conflict.
 *
 * Revision 1.3  1995/03/06  16:07:48  pesch
 * Fixed error in including signal.h
 *
 * Revision 1.2  1994/03/30  11:35:01  pesch
 * Renamed SIGMASK to SigMask. SIGMASK was already defined in AIX signal.h.
 *
 * Revision 1.1  1994/03/11  16:02:00  pesch
 * Interface to C-Macros in header-files.
 *
 * ----------------------------------------------------------------------------
 */

const static char rcsid[] = "$Id: cmacros.c,v 1.4 1997/08/29 14:33:52 pesch Exp $";
const static char copyright[] = "Copyright (c) 1994 - 1997 Universitaet Passau";
const static char compiletime[] = "Compiled at " __DATE__ " " __TIME__;
# ifdef __GNUC__
const static char compiler[] = "Compiled with GNU C Version " __VERSION__;
# else
const static char compiler[] = "???";
# endif /* __GNUC__ */

#include <sys/signal.h>

/* Make sigmask macro available as a function. */
#ifdef SigMask
#undef SigMask
#error SigMask was defined! Why?
#endif

#ifdef sigmask
int SigMask(int s) {return (sigmask(s)); }
#else
int SigMask(int s) {return (1<<(s-1)); }
#endif

/* -EOF- */
