#define DEFINITION_MASU

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern BOOLEAN MASU_Time, MASU_Debug, MASU_PromptFirst;
extern INTEGER MASU_WroteChars, MASU_PromptType;
extern CHAR MASU_rcsid[];
extern CHAR MASU_copyright[];
extern void MASU_InitExternalsU ARGS(());
extern MASSTOR_LIST MASU_DoParse ARGS(());
extern void MASU_DoWrite ARGS((MASSTOR_LIST Y));
extern void MASU_MWRITE ARGS((MASSTOR_LIST Y));
extern void MASU_MWRIT1 ARGS((MASSTOR_LIST Y, BOOLEAN top));
extern void BEGIN_MASU();
