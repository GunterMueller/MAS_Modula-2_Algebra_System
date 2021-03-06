#define DEFINITION_DIPAGB

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASLISPU
#include "MASLISPU.h"
#endif

#define DIPAGB_Normal	0
#define DIPAGB_NormalWithSugar	1
extern CHAR DIPAGB_rcsid[];
extern CHAR DIPAGB_copyright[];
extern MASSTOR_LIST DIPAGB_ADDNFEDIP ARGS((MASSTOR_LIST f));
extern MASSTOR_LIST DIPAGB_CPEXTEND ARGS((MASSTOR_LIST f, MASSTOR_LIST g));
extern MASSTOR_LIST DIPAGB_DIPAGB ARGS((MASSTOR_LIST F));
extern MASSTOR_LIST DIPAGB_DIPEXTEND ARGS((MASSTOR_LIST f));
extern MASSTOR_LIST DIPAGB_DIPRWTDG ARGS((MASSTOR_LIST f, MASSTOR_LIST W));
extern MASSTOR_LIST DIPAGB_ECPINSERT ARGS((MASSTOR_LIST CP, MASSTOR_LIST P));
extern MASSTOR_LIST DIPAGB_ECPLCMHT ARGS((MASSTOR_LIST CP));
extern MASSTOR_LIST DIPAGB_ECPPOLY1 ARGS((MASSTOR_LIST CP));
extern MASSTOR_LIST DIPAGB_ECPPOLY2 ARGS((MASSTOR_LIST CP));
extern void DIPAGB_ECPSELECT ARGS((MASSTOR_LIST P, MASSTOR_LIST *CP, MASSTOR_LIST *Q));
extern MASSTOR_LIST DIPAGB_ECPSUGAR ARGS((MASSTOR_LIST CP));
extern MASSTOR_LIST DIPAGB_ECPUNEXTEND ARGS((MASSTOR_LIST CP));
extern void DIPAGB_ECPWRITE ARGS((MASSTOR_LIST CP));
extern MASSTOR_LIST DIPAGB_EDIIFSUGNF ARGS((MASSTOR_LIST P, MASSTOR_LIST f));
extern MASSTOR_LIST DIPAGB_EDIIFSUGSP ARGS((MASSTOR_LIST f, MASSTOR_LIST g));
extern MASSTOR_LIST DIPAGB_EDIPEVL ARGS((MASSTOR_LIST f));
extern MASSTOR_LIST DIPAGB_EDIPNOR ARGS((MASSTOR_LIST P, MASSTOR_LIST f));
extern MASSTOR_LIST DIPAGB_EDIPSP ARGS((MASSTOR_LIST f, MASSTOR_LIST g));
extern MASSTOR_LIST DIPAGB_EDIPSUGAR ARGS((MASSTOR_LIST f));
extern MASSTOR_LIST DIPAGB_EDIPSUGCON ARGS((MASSTOR_LIST f, MASSTOR_LIST S));
extern MASSTOR_LIST DIPAGB_EDIPSUGNOR ARGS((MASSTOR_LIST P, MASSTOR_LIST f));
extern MASSTOR_LIST DIPAGB_EDIPSUGSP ARGS((MASSTOR_LIST f, MASSTOR_LIST g));
extern MASSTOR_LIST DIPAGB_EDIPUNEXTEND ARGS((MASSTOR_LIST f));
extern void DIPAGB_EDIPWRITE ARGS((MASSTOR_LIST f));
extern MASSTOR_LIST DIPAGB_EVRWTDEG ARGS((MASSTOR_LIST U, MASSTOR_LIST W));
extern void DIPAGB_INITUPDATE ARGS((MASSTOR_LIST f, MASSTOR_LIST *G, MASSTOR_LIST *B));
extern MASSTOR_LIST DIPAGB_LDIPEXTEND ARGS((MASSTOR_LIST P));
extern MASSTOR_LIST DIPAGB_LECPUNEXTEND ARGS((MASSTOR_LIST P));
extern void DIPAGB_LECPWRITE ARGS((MASSTOR_LIST P));
extern MASSTOR_LIST DIPAGB_LEDIPUNEXTEND ARGS((MASSTOR_LIST P));
extern void DIPAGB_LEDIPWRITE ARGS((MASSTOR_LIST P));
extern void DIPAGB_LRNWRIT ARGS((MASSTOR_LIST LRN));
extern void DIPAGB_UPDATE ARGS((MASSTOR_LIST h, MASSTOR_LIST *G, MASSTOR_LIST *B));
extern void DIPAGB_UpdateVariableWeight ARGS(());
extern void DIPAGB_SetDIPAGBOptions ARGS((MASSTOR_LIST OPT));
extern void DIPAGB_SetDIPAGBStrategy ARGS((MASSTOR_LIST st));
extern void DIPAGB_SetDIPAGBTraceFlag ARGS((MASSTOR_LIST tf));
extern void DIPAGB_SetDIPAGBVariableWeight ARGS((MASSTOR_LIST VW));
extern void DIPAGB_SetCPExtend ARGS((MASLISPU_PROCF2 EXT));
extern void DIPAGB_SetDIPExtend ARGS((MASLISPU_PROCF1 EXT));
extern void DIPAGB_SetECPInsert ARGS((MASLISPU_PROCF2 INS));
extern void DIPAGB_SetECPSelect ARGS((MASLISPU_PROCP1V2 SEL));
extern void DIPAGB_SetECPWrite ARGS((MASLISPU_PROCP1 WR));
extern void DIPAGB_SetEDIPNormalform ARGS((MASLISPU_PROCF2 NF));
extern void DIPAGB_SetEDIPSPolynomial ARGS((MASLISPU_PROCF2 SP));
extern void DIPAGB_SetEDIPUnExtend ARGS((MASLISPU_PROCF1 UEXT));
extern void DIPAGB_SetEDIPWrite ARGS((MASLISPU_PROCP1 WR));
extern void DIPAGB_SetInit ARGS((MASLISPU_PROCP1V2 INIT));
extern void DIPAGB_SetUpdate ARGS((MASLISPU_PROCP1V2 UPD));
extern void DIPAGB_SetUpdateVariableWeight ARGS((MASLISPU_PROCP0 UPD));
extern void DIPAGB_WriteDIPAGBOptions ARGS(());
extern void DIPAGB_WriteDIPAGBStrategy ARGS(());
extern void DIPAGB_WriteDIPAGBTraceFlag ARGS(());
extern void DIPAGB_WriteDIPAGBVariableWeight ARGS(());
extern void BEGIN_DIPAGB();
