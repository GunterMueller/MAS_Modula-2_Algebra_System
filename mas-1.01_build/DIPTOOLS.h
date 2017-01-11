#define DEFINITION_DIPTOOLS

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR DIPTOOLS_rcsid[];
extern CHAR DIPTOOLS_copyright[];
extern MASSTOR_LIST DIPTOOLS_VVECFVLIST ARGS((MASSTOR_LIST v1, MASSTOR_LIST v2));
extern MASSTOR_LIST DIPTOOLS_VVECC ARGS((MASSTOR_LIST v));
extern MASSTOR_LIST DIPTOOLS_DIPONE ARGS((MASSTOR_LIST d));
extern MASSTOR_LIST DIPTOOLS_ADDDFDIP ARGS((MASSTOR_LIST p));
extern MASSTOR_LIST DIPTOOLS_ADDDFDIPD ARGS((MASSTOR_LIST p, MASSTOR_LIST d));
extern MASSTOR_LIST DIPTOOLS_ADDDFDIL ARGS((MASSTOR_LIST l));
extern MASSTOR_LIST DIPTOOLS_ADDDFDILD ARGS((MASSTOR_LIST l, MASSTOR_LIST d));
extern MASSTOR_LIST DIPTOOLS_ADDNFDIP ARGS((MASSTOR_LIST p));
extern MASSTOR_LIST DIPTOOLS_ADDNFDIPD ARGS((MASSTOR_LIST p, MASSTOR_LIST d));
extern MASSTOR_LIST DIPTOOLS_ADDNFDIL ARGS((MASSTOR_LIST l));
extern MASSTOR_LIST DIPTOOLS_ADDNFDILD ARGS((MASSTOR_LIST l, MASSTOR_LIST d));
extern MASSTOR_LIST DIPTOOLS_DIPPOWER ARGS((MASSTOR_LIST p, MASSTOR_LIST n));
extern MASSTOR_LIST DIPTOOLS_DILPROD ARGS((MASSTOR_LIST L, MASSTOR_LIST domain));
extern MASSTOR_LIST DIPTOOLS_DIPDEGI ARGS((MASSTOR_LIST p, MASSTOR_LIST i));
extern MASSTOR_LIST DIPTOOLS_DILMOC ARGS((MASSTOR_LIST L));
extern MASSTOR_LIST DIPTOOLS_DIPPAD ARGS((MASSTOR_LIST p, MASSTOR_LIST i));
extern MASSTOR_LIST DIPTOOLS_DIMPAD ARGS((MASSTOR_LIST c, MASSTOR_LIST ev, MASSTOR_LIST i));
extern void DIPTOOLS_DIPCPP ARGS((MASSTOR_LIST P, MASSTOR_LIST *content, MASSTOR_LIST *ppt));
extern void DIPTOOLS_DIPPCPP ARGS((MASSTOR_LIST P, MASSTOR_LIST *content, MASSTOR_LIST *ppt));
extern BOOLEAN DIPTOOLS_DIPCNST ARGS((MASSTOR_LIST dip));
extern BOOLEAN DIPTOOLS_DIPCNSTR ARGS((MASSTOR_LIST p, MASSTOR_LIST v));
extern BOOLEAN DIPTOOLS_EVCNSTR ARGS((MASSTOR_LIST ev, MASSTOR_LIST mvars));
extern void DIPTOOLS_EvordPush ARGS((MASSTOR_LIST evord));
extern void DIPTOOLS_EvordPop ARGS(());
extern void DIPTOOLS_ValisPush ARGS((MASSTOR_LIST valis));
extern void DIPTOOLS_ValisPop ARGS(());
extern MASSTOR_LIST DIPTOOLS_DILINV ARGS((MASSTOR_LIST dil, MASSTOR_LIST j, MASSTOR_LIST k));
extern void DIPTOOLS_DIPFDIPP ARGS((MASSTOR_LIST p, MASSTOR_LIST NewDd, MASSTOR_LIST *q, MASSTOR_LIST *vlist));
extern MASSTOR_LIST DIPTOOLS_EVEXT ARGS((MASSTOR_LIST p, MASSTOR_LIST evx));
extern MASSTOR_LIST DIPTOOLS_ADPFDIP ARGS((MASSTOR_LIST p, MASSTOR_LIST dd));
extern void DIPTOOLS_DIPPFDIP ARGS((MASSTOR_LIST p, MASSTOR_LIST r, MASSTOR_LIST NewDd, MASSTOR_LIST *q, MASSTOR_LIST *vlist));
extern void DIPTOOLS_MPPFMP ARGS((MASSTOR_LIST Coeff, MASSTOR_LIST Ev, MASSTOR_LIST r, MASSTOR_LIST *RCpol, MASSTOR_LIST *NewEv));
extern MASSTOR_LIST DIPTOOLS_DIPCONV ARGS((MASSTOR_LIST p, MASSTOR_LIST E));
extern MASSTOR_LIST DIPTOOLS_DILCONV ARGS((MASSTOR_LIST P, MASSTOR_LIST E));
extern MASSTOR_LIST DIPTOOLS_DIPFADIP ARGS((MASSTOR_LIST p));
extern MASSTOR_LIST DIPTOOLS_DIPFIP ARGS((MASSTOR_LIST p, MASSTOR_LIST r));
extern MASSTOR_LIST DIPTOOLS_DILPFDIL ARGS((MASSTOR_LIST L, MASSTOR_LIST r, MASSTOR_LIST newdd));
extern MASSTOR_LIST DIPTOOLS_DILFDILP ARGS((MASSTOR_LIST L, MASSTOR_LIST NewDd));
extern MASSTOR_LIST DIPTOOLS_DIPCT ARGS((MASSTOR_LIST p));
extern MASSTOR_LIST DIPTOOLS_DIPIMO ARGS((MASSTOR_LIST p));
extern MASSTOR_LIST DIPTOOLS_DILIMO ARGS((MASSTOR_LIST P));
extern MASSTOR_LIST DIPTOOLS_DIPXCM ARGS((MASSTOR_LIST p, MASSTOR_LIST mvars));
extern MASSTOR_LIST DIPTOOLS_DIPMVV ARGS((MASSTOR_LIST p));
extern void BEGIN_DIPTOOLS();