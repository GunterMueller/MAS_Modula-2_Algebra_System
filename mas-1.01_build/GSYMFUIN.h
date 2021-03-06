#define DEFINITION_GSYMFUIN

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

extern CHAR GSYMFUIN_rcsid[];
extern CHAR GSYMFUIN_copyright[];
extern void GSYMFUIN_GSYINF ARGS(());
extern MASSTOR_LIST GSYMFUIN_GSYPGR ARGS((MASELEM_GAMMAINT M));
extern void GSYMFUIN_GSYPGW ARGS((MASSTOR_LIST PG));
extern MASSTOR_LIST GSYMFUIN_GINORP ARGS((MASSTOR_LIST PG, MASSTOR_LIST MO));
extern MASELEM_GAMMAINT GSYMFUIN_GSYORD ARGS((MASSTOR_LIST PG));
extern void GSYMFUIN_GSYNSP ARGS((MASSTOR_LIST PG));
extern MASSTOR_LIST GSYMFUIN_GSYSPG ARGS((MASELEM_GAMMAINT N));
extern MASSTOR_LIST GSYMFUIN_GINOPL ARGS((MASSTOR_LIST PG, MASSTOR_LIST ML));
extern void GSYMFUIN_GINCUT ARGS((MASSTOR_LIST PG, MASSTOR_LIST POL, MASSTOR_LIST *POL_1, MASSTOR_LIST *POL_2));
extern MASSTOR_LIST GSYMFUIN_GINCHK ARGS((MASSTOR_LIST PG, MASSTOR_LIST BASE, MASSTOR_LIST POL));
extern void GSYMFUIN_GINCHKBAS ARGS((MASSTOR_LIST *BASE, MASSTOR_LIST *POL));
extern MASELEM_GAMMAINT GSYMFUIN_GSYTWG ARGS((MASSTOR_LIST TERM1, MASSTOR_LIST TERM2));
extern MASELEM_GAMMAINT GSYMFUIN_GSYMLT ARGS((MASELEM_GAMMAINT N));
extern MASSTOR_LIST GSYMFUIN_GSYADD ARGS((MASSTOR_LIST TERM));
extern void GSYMFUIN_GINRED ARGS((MASSTOR_LIST PG, MASSTOR_LIST POL, MASSTOR_LIST *BASE, MASSTOR_LIST *BASE_POL, MASSTOR_LIST *REM_POL));
extern MASSTOR_LIST GSYMFUIN_GINBAS ARGS((MASSTOR_LIST PG));
extern void BEGIN_GSYMFUIN();
