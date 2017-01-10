/* -------------------------------------------------------------------- -*-C-*-
 * $Id: init-path.c,v 1.1 1995/10/24 14:31:53 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Taken from Kpathsearch library version 2.6
 * ----------------------------------------------------------------------------
 * $Log: init-path.c,v $
 * Revision 1.1  1995/10/24 14:31:53  pesch
 * Function kpse_init_path is unfortunately missing from kpasea 2.6.
 * This is a replacement, taken from kpathsea 1.8.
 *
 * ----------------------------------------------------------------------------
 */

/* init-path.c: Find how to initialize a path.

Copyright (C) 1993, 94 Karl Berry.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

const static char rcsid[] = "$Id: init-path.c,v 1.1 1995/10/24 14:31:53 pesch Exp $";
const static char compiletime[] = "Compiled at " __DATE__ " " __TIME__;
# ifdef __GNUC__
const static char compiler[] = "Compiled with GNU C Version " __VERSION__;
# else
const static char compiler[] = "???";
# endif /* __GNUC__ */

#include "config.h"

#ifndef HAVE_KPSE_INIT_PATH

#include <stdlib.h>

#include <kpathsea/default.h>
#include "init-path.h"


/* See init-path.h.  */

string
kpse_init_path PVAR2C(const_string, current,
                      const_string, default_path,  ap)
{
  string env_name;
  string ret;
  string env_path = NULL;

  /* First envvar that's set will exit the loop.  */
  while (!env_path && (env_name = va_arg (ap, string)) != NULL)
    {
      env_path = getenv (env_name);
    }
  va_end (ap);
  
  /* Expand extra colons.  */
  ret = kpse_expand_default (env_path ? env_path : current, default_path);
  
  return ret;
}}

#endif /* HAVE_KPSE_INIT_PATH */
/* -EOF- */
