#define DEFINITION_MODVAR

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR MODVAR_rcsid[];
extern CHAR MODVAR_copyright[];
extern void MODVAR_MVDeclareL ARGS((MASSTOR_LIST *var, CHAR name[], LONGCARD , CHAR comment[], LONGCARD , BOOLEAN access));
extern void MODVAR_MVDeclareB ARGS((BOOLEAN *var, CHAR name[], LONGCARD , CHAR comment[], LONGCARD , BOOLEAN access));
extern void MODVAR_MVSET ARGS((MASSTOR_LIST sym, MASSTOR_LIST value));
extern MASSTOR_LIST MODVAR_MVGET ARGS((MASSTOR_LIST sym));
extern MASSTOR_LIST MODVAR_MVFLAG ARGS((MASSTOR_LIST sym));
extern void MODVAR_MVON ARGS((MASSTOR_LIST sym));
extern void MODVAR_MVOFF ARGS((MASSTOR_LIST sym));
extern void MODVAR_MVHLP ARGS((MASSTOR_LIST sym));
extern void BEGIN_MODVAR();
