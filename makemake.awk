# ------------------------------------------------------------------ -*-AWK-*-
# $Id: makemake.awk,v 1.3 1995/10/24 14:36:56 pesch Exp $
# ----------------------------------------------------------------------------
# The awk part of the makemake Makefile generator for MAS
# ----------------------------------------------------------------------------
# This file is part of MAS.
# ----------------------------------------------------------------------------
# Copyright (c) 1995 Universitaet Passau
# ----------------------------------------------------------------------------
# $Log: makemake.awk,v $
# Revision 1.3  1995/10/24 14:36:56  pesch
# Fixed generation of dependencies for .c files, which were not created.
# Will now generate useful dependencies if some .h files can not be
# found (when bootstrapping), too.
#
# Revision 1.2  1995/03/08  14:05:49  pesch
# Id will now be written to generated files.
#
# Revision 1.1  1995/03/06  17:01:17  pesch
# New files to make mas using GNU autoconf and GNU make. This replaces
# the old Makefiles.
#
# ----------------------------------------------------------------------------
#
BEGIN {
  print"# ------------------------------------------------------------- -*-Makefile-*-"
  print"# Generated automatically using makemake for MAS"
  print"# $Id: makemake.awk,v 1.3 1995/10/24 14:36:56 pesch Exp $"
  print"# ----------------------------------------------------------------------------"
  print"# This file is part of MAS."
  print"# ----------------------------------------------------------------------------"
  print"# Copyright (c) 1995 Universitaet Passau"
  print"# ----------------------------------------------------------------------------"
  print ""
  conf ["SYSTEM"] = 1;
  conf ["System"] = 1;
  conf ["IO"] = 1;
  conf ["Strings"] = 1;
  conf ["Times"] = 1;
  conf ["SysCall"] = 1;
  conf ["Memory"] = 1;
  conf ["StdIO"] = 1;
  cdep = 0;
}
/DIR\*/ {
  FS="*"
  dir_name = $2
  dir_lib = "$(" dir_name "_LIB)"
  FS=" "
#  print ""
#  print dir_name"_LIBS="
}
/MI\*/ {
  print "" 
  FS="*"
  print dir_name"_MI=" $2
  FS=" "
}
/MD\*/ {
  print "" 
  FS="*"
  print dir_name"_MD=" $2
  FS=" "
}
/MDP\*/ {
  print ""
  FS="*"
  print""dir_name"_MDP=" $2
  FS=" "
}
/MIP\*/ {
  print ""
  FS="*"
  print""dir_name"_MIP=" $2
  FS=" "
}
/CINC\*/ {
  print ""
  FS="*"
  print""dir_name"_CINC=" $2
  FS=" "
}
/CSRC\*/ {
  print ""
  FS="*"
  print""dir_name"_CSRC=" $2
  FS=" "
  print ""
  print""dir_name"_OBJS=$("dir_name"_CSRC:.c=.o) $("dir_name"_MI:.mi=.o) $("dir_name"_MIP:.mip=.o)"
}
/ALLSRC\*/ {
  print ""
  FS="*"
  print""dir_name"_ALLSRC=" $2
  FS=" "
}
/MKDEP\*/ {
  print ""
  FS="*"
  print $2
  FS=" "
}
/DEFINITION/ {
  name = $3
    extension = ".h"
      print ""
}
/FOREIGN/ {
  name = $3
    extension = ".h"
      print ""
}
/IMPLEMENTATION/ {
  name = $3
    extension = ".o"
      print ""
	print dir_lib "(" name extension "): " name ".c " name ".h"
      }
/PROGRAM/ {
  name = $3
    extension = ".o"
      print ""
	print dir_lib "(" name extension "): " name ".c"
}
/IMPORT/ {
         if (conf [$2] != 1) {
	   if (extension == ".h") {
	     print name extension ": " $2 ".h"
	   }
	   if (extension == ".o") {
	     print dir_lib "(" name extension "): " $2 ".h"
	   }
	 }
}
/CDEP*/ {
  cdep = 1
}
/.*\.o/ {
  print ""
  FS=":"
  print dir_lib "(" $1 "):" $2
  FS=" "
}
/  .*/ {
  if (cdep == 1) {
    print
  }
} 
/.*\.c:[0-9]*: header file/ {
  if (cdep == 1) {
    print ""
    FS=":"
    s=split($1, a, ".c")
    s=split($3, b, "'")
    print dir_lib "(" a[1]".o): "b[2]
    FS=" "
  }
}
END {
  print ""
    print"# -EOF-"
}
# -EOF-
