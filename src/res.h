#ifndef RES_H
#define RES_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lib/common.h"

//---------------------------------------------------------------------------
#define RES_NUM_CX				16
#define RES_NUM_CY				24


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void ResInit(void);

void ResDrawNum(u8 pos, u8 num);
void ResDrawBar(u8 pos, u8 num);
void ResDrawMsg(void);


#ifdef __cplusplus
}
#endif
#endif
