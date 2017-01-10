/* ----------------------------------------------------------------------------
 * $Id: clock.c,v 1.2 1995/09/12 17:26:54 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: clock.c,v $
 * Revision 1.2  1995/09/12  17:26:54  pesch
 * Defined CLK_TCK for SUNs.
 *
 * Revision 1.1  1995/03/06  16:28:38  pesch
 * New function ClocK returns milliseconds of the processes cpu-time (was no
 * longer available in new reuse library).
 *
 * ----------------------------------------------------------------------------
 */

const static char rcsid[] = "$Id: clock.c,v 1.2 1995/09/12 17:26:54 pesch Exp $";
const static char copyright[] = "Copyright (c) 1995 Universitaet Passau";
const static char compiletime[] = "Compiled at " __DATE__ " " __TIME__;
# ifdef __GNUC__
const static char compiler[] = "Compiled with GNU C Version " __VERSION__;
# else
const static char compiler[] = "???";
# endif /* __GNUC__ */

#include <time.h>
#include <sys/times.h>

#if defined(sun) && !defined(CLK_TCK)
#define CLK_TCK 60
#endif

#ifndef CLK_TCK
#error CLK_TCK undefined, why?
#endif

/* returns milliseconds of the processes cpu-time */
long ClocK() {
  struct tms t;
  (void) times(&t);
#ifndef NO_FLOAT
  return((long)((double)t.tms_utime*1000.0/(double)CLK_TCK));
#else
  return((long)(t.tms_utime*(1000/CLK_TCK)));
#endif
}

void BEGIN_clock(){};

/* -EOF- */
