#define DEFINITION_MASERR

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#define MASERR_spotless	0
#define MASERR_harmless	1
#define MASERR_severe	2
#define MASERR_fatal	3
#define MASERR_confusion	9
extern CHAR MASERR_rcsid[];
extern CHAR MASERR_copyright[];
typedef void (*MASERR_P0) ARGS(());
extern MASERR_P0 MASERR_DebugProcessor;
extern MASELEM_GAMMAINT MASERR_history;
extern void MASERR_ERROR ARGS((MASELEM_GAMMAINT a, CHAR s[], LONGCARD ));
extern MASELEM_GAMMAINT MASERR_ErrorHandler ARGS((MASERR_P0 a));
extern void BEGIN_MASERR();
