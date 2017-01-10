/* ------------------------------------------------------------------- -*-C-*-
$Id: acconfig.h,v 1.3 1996/06/08 14:58:40 pesch Exp $
------------------------------------------------------------------------------
acconfig.h for MAS
This file is used by autoheader
------------------------------------------------------------------------------
This file is part of MAS.
------------------------------------------------------------------------------
Copyright (c) 1995 Universitaet Passau
------------------------------------------------------------------------------
$Log: acconfig.h,v $
Revision 1.3  1996/06/08 14:58:40  pesch
Use new stack direction check.

Revision 1.2  1995/09/12  17:08:03  pesch
Added tests for stack direction, termcap, atexit, raise.

Revision 1.1  1995/03/06  17:01:15  pesch
New files to make mas using GNU autoconf and GNU make. This replaces
the old Makefiles.

---------------------------------------------------------------------------- */

/* Define if you have the old mtc/reuse */
#undef OLD_MTC

/* Define to the name of the distribution.  */
#undef PRODUCT

/* Define to the version of the distribution.  */
#undef VERSION

/* Define if you do not want floating point arithmetic to be used. */
#undef NO_FLOAT

@BOTTOM@

#if !defined(HAVE_LIBREUSE) || !defined(HAVE_SYSTEM_H)
# error Sorry, MAS will not compile without the reuse library!
#endif

/* -EOF- */
