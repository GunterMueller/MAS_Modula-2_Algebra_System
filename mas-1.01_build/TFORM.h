#define DEFINITION_TFORM

#ifndef DEFINITION_MASLISPU
#include "MASLISPU.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR TFORM_rcsid[];
extern CHAR TFORM_copyright[];
#define TFORM_Tfgood	0
#define TFORM_Tfbad	1
#define TFORM_Tfdontcare	2
#define TFORM_Tfimpossible	3
typedef unsigned char TFORM_TfClass;
extern MASSTOR_LIST TFORM_tfmkaf ARGS((MASSTOR_LIST rel, MASSTOR_LIST idl));
extern void TFORM_tfpaf ARGS((MASSTOR_LIST af, MASSTOR_LIST *rel, MASSTOR_LIST *idl));
extern MASSTOR_LIST TFORM_tfgrel ARGS((MASSTOR_LIST af));
extern void TFORM_TFPPRT ARGS((MASSTOR_LIST phi));
extern MASSTOR_LIST TFORM_TFIREAD ARGS(());
extern void TFORM_TfUseDb ARGS(());
extern void TFORM_TfComputeTf ARGS(());
extern MASSTOR_LIST TFORM_TfTypeFormula ARGS((MASSTOR_LIST deg));
extern MASSTOR_LIST TFORM_ComputeTypeFormula ARGS((MASSTOR_LIST deg));
extern MASSTOR_LIST TFORM_UseDb ARGS((MASSTOR_LIST deg));
extern MASSTOR_LIST TFORM_TFGENJ ARGS((MASSTOR_LIST deg));
extern MASSTOR_LIST TFORM_TfRecBasis ARGS((MASSTOR_LIST deg));
extern MASSTOR_LIST TFORM_TfCtj ARGS((MASSTOR_LIST deg));
extern MASSTOR_LIST TFORM_TfShiftVars ARGS((MASSTOR_LIST phi, MASSTOR_LIST offset));
extern MASSTOR_LIST TFORM_tfshiftaf ARGS((MASSTOR_LIST phi, MASSTOR_LIST offset));
extern MASSTOR_LIST TFORM_TFFTUPLE ARGS((MASSTOR_LIST tup));
extern MASSTOR_LIST TFORM_Class2Sym ARGS((TFORM_TfClass class));
extern TFORM_TfClass TFORM_Sym2Class ARGS((MASSTOR_LIST class));
extern void TFORM_InitClassSyms ARGS(());
extern TFORM_TfClass TFORM_TfClassify ARGS((MASSTOR_LIST tup));
extern MASSTOR_LIST TFORM_TfClassifyI ARGS((MASSTOR_LIST tup));
extern MASSTOR_LIST TFORM_TFGENI ARGS((MASSTOR_LIST deg, MASSTOR_LIST class));
extern MASSTOR_LIST TFORM_TFGEN ARGS((MASSTOR_LIST deg, TFORM_TfClass class));
extern void TFORM_PatternAStart ARGS((MASSTOR_LIST deg, MASSTOR_LIST *start, MASSTOR_LIST *pattern));
extern MASSTOR_LIST TFORM_TfNextTuple ARGS((MASSTOR_LIST last, MASSTOR_LIST pattern));
extern MASSTOR_LIST TFORM_NextRel ARGS((MASSTOR_LIST e));
extern MASSTOR_LIST TFORM_TfCount ARGS((MASSTOR_LIST deg));
extern MASSTOR_LIST TFORM_TfCount1 ARGS((MASSTOR_LIST start, MASSTOR_LIST pattern));
extern MASSTOR_LIST TFORM_TfZeroes0 ARGS((MASSTOR_LIST tup));
extern void TFORM_TfZeroes ARGS((MASSTOR_LIST tup, MASSTOR_LIST *CZeroes, MASSTOR_LIST *ZeroesM, MASSTOR_LIST *Zeroes0, MASSTOR_LIST *ZeroesP));
extern MASSTOR_LIST TFORM_TfZeroesI ARGS((MASSTOR_LIST tup));
extern MASSTOR_LIST TFORM_TfSignChs ARGS((MASSTOR_LIST tup));
extern void BEGIN_TFORM();
