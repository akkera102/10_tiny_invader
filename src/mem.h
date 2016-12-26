#ifndef MEM_H
#define MEM_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lib/common.h"

//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

typedef struct {
	u16 scoreHigh;
	u32 randSeed;

} ST_MEM;

//---------------------------------------------------------------------------
void MemInit(void);
void MemLoad(void);
void MemSave(u16 score);

u16  MemGetScoreHigh(void);
bool MemIsSave(void);


#ifdef __cplusplus
}
#endif
#endif
