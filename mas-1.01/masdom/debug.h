#ifdef DEBUG
#define DEB_LWRITE(a) SWRITE("DEBUG: "); SWRITE(#a); SWRITE("=");\
FLWRITE(a); BLINES(0);
#define DEB_BEGIN(a) SWRITE("DEBUG: BEGIN: "); SWRITE(#a); BLINES(0);
#define DEB_END(a) SWRITE("DEBUG: END: "); SWRITE(#a); BLINES(0);
#else
#define DEB_LWRITE(a)
#define DEB_BEGIN(a)
#define DEB_END(a)
#endif
