/* config.h.  Generated automatically by configure.  */
/* config.h.in.  Generated automatically from configure.in by autoheader.  */

/* If using the C implementation of alloca, define if you know the
   direction of stack growth for your system; otherwise it will be
   automatically deduced at run-time.
 STACK_DIRECTION > 0 => grows toward higher addresses
 STACK_DIRECTION < 0 => grows toward lower addresses
 STACK_DIRECTION = 0 => direction of growth unknown
 */
#define STACK_DIRECTION -1

/* Define if you have the old mtc/reuse */
/* #undef OLD_MTC */

/* Define to the name of the distribution.  */
#define PRODUCT "MAS"

/* Define to the version of the distribution.  */
#define VERSION "1.01"

/* Define if you have the atexit function.  */
#define HAVE_ATEXIT 1

/* Define if you have the extend_filename function.  */
#define HAVE_EXTEND_FILENAME 1

/* Define if you have the kpse_init_path function.  */
/* #undef HAVE_KPSE_INIT_PATH */

/* Define if you have the kpse_path_search function.  */
#define HAVE_KPSE_PATH_SEARCH 1

/* Define if you have the kpse_set_progname function.  */
/* #undef HAVE_KPSE_SET_PROGNAME */

/* Define if you have the make_suffix function.  */
#define HAVE_MAKE_SUFFIX 1

/* Define if you have the on_exit function.  */
#define HAVE_ON_EXIT 1

/* Define if you have the raise function.  */
#define HAVE_RAISE 1

/* Define if you have the <System.h> header file.  */
/* #undef HAVE_SYSTEM_H */

/* Define if you have the <kpathsea/init_path.h> header file.  */
/* #undef HAVE_KPATHSEA_INIT_PATH_H */

/* Define if you have the <kpathsea/lib.h> header file.  */
#define HAVE_KPATHSEA_LIB_H 1

/* Define if you have the <kpathsea/pathsearch.h> header file.  */
#define HAVE_KPATHSEA_PATHSEARCH_H 1

/* Define if you have the <kpathsea/progname.h> header file.  */
#define HAVE_KPATHSEA_PROGNAME_H 1

/* Define if you have the <readline/readline.h> header file.  */
#define HAVE_READLINE_READLINE_H 1

/* Define if you have the <termcap.h> header file.  */
#define HAVE_TERMCAP_H 1

/* Define if you have the kpathsea library (-lkpathsea).  */
#define HAVE_LIBKPATHSEA 1

/* Define if you have the readline library (-lreadline).  */
#define HAVE_LIBREADLINE 1

/* Define if you have the reuse library (-lreuse).  */
/* #undef HAVE_LIBREUSE */

/* Define if you have the termcap library (-ltermcap).  */
#define HAVE_LIBTERMCAP 1

#if !defined(HAVE_LIBREUSE) || !defined(HAVE_SYSTEM_H)
# error Sorry, MAS will not compile without the reuse library!
#endif

/* -EOF- */
