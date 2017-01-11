/* -------------------------------------------------------------------- -*-C-*-
 * $Id: init-path.h,v 1.1 1995/10/24 14:31:56 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Taken from Kpathsearch library version 2.6
 * ----------------------------------------------------------------------------
 * $Log: init-path.h,v $
 * Revision 1.1  1995/10/24 14:31:56  pesch
 * Function kpse_init_path is unfortunately missing from kpasea 2.6.
 * This is a replacement, taken from kpathsea 1.8.
 *
 * ----------------------------------------------------------------------------
 */

/* init-path.h: Declarations for path initialization.

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

#ifndef KPATHSEA_INIT_PATH_H
#define KPATHSEA_INIT_PATH_H

// GM 1/9/2016
//#include <kpathsea/c-vararg.h>
#include <kpathsea/types.h>

/* The first arguments are fixed.  Any number of additional arguments,
   must be strings naming environment variables, terminated with NULL.
   
   Expand the value of the first set environment variable, or CURRENT if
   none are set, with `kpse_expand_default' (with DEFAULT_PATH), and
   return the result.  */
extern string kpse_init_path = PVAR2H(const_string current,
                                    const_string default_path);

#endif /* not KPATHSEA_INIT_PATH_H */
/* -EOF- */
