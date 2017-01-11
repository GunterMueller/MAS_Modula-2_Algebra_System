/* ----------------------------------------------------------------------------
 * $Id: maskpathsea.c,v 1.3 1995/10/24 14:33:46 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: maskpathsea.c,v $
 * Revision 1.3  1995/10/24 14:33:46  pesch
 * Modifications for kpathsea version 2.6. (Version 1.8 is still supported)
 *
 * Revision 1.2  1995/03/23  15:57:58  pesch
 * Added BEGIN_maskpathsea.
 * Corrected handling of MASINPUTS.
 *
 * Revision 1.1  1995/03/06  16:31:23  pesch
 * New function masReadOpen. Opens a file using kpathsea if available.
 * In this case the environment variable MASINPUTS is used as search path,
 * when opening files for reading.
 *
 * ----------------------------------------------------------------------------
 */

const static char rcsid[] = "$Id: maskpathsea.c,v 1.3 1995/10/24 14:33:46 pesch Exp $";
const static char copyright[] = "Copyright (c) 1995 Universitaet Passau";
const static char compiletime[] = "Compiled at " __DATE__ " " __TIME__;
# ifdef __GNUC__
const static char compiler[] = "Compiled with GNU C Version " __VERSION__;
# else
const static char compiler[] = "???";
# endif /* __GNUC__ */

#include <SYSTEM_.h>
#include <IO.h>
#include "config.h"

#ifdef HAVE_LIBKPATHSEA
# ifdef HAVE_KPATHSEA_PATHSEARCH_H
#  include <kpathsea/pathsearch.h>
# endif  /* HAVE_KPATHSEA_PATHSEARCH_H */
#endif  /* HAVE_LIBKPATHSEA */

#ifdef HAVE_LIBKPATHSEA
extern char *masinputpath;
#endif /* HAVE_LIBKPATHSEA */

IO_tFile masReadOpen (CHAR file[], LONGCARD O_1){
#ifdef HAVE_KPSE_PATH_SEARCH
  char *s;
  s=kpse_path_search(masinputpath, file, 1);
  if (s != NULL) return IO_ReadOpen(s, strlen(s));
  else return (IO_tFile) -1;
#else
  return IO_ReadOpen(file, O_1);
#endif /* HAVE_KPSE_PATH_SEARCH */
}

void
BEGIN_maskpathsea() {
  static BOOLEAN has_been_called = FALSE;
  if (!has_been_called) {
    BEGIN_IO;
    BEGIN_MASCONF();
    has_been_called = TRUE;
  }
};
/* -EOF- */
