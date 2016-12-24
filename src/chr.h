#ifndef CHR_H
#define CHR_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lib/common.h"

//---------------------------------------------------------------------------
#define CHR_MAX_HP			3
#define CHR_MAX_SHOT		30

//---------------------------------------------------------------------------

typedef struct {
	s8 hp;
	s8 shot;
	s8 sel;

} ST_CHR;



//---------------------------------------------------------------------------
void ChrInit(void);
void ChrInit2(void);
void ChrExec(void);
void ChrDraw(void);

bool ChrIsShotEmpty(void);
bool ChrIsHp(void);

#ifdef __cplusplus
}
#endif
#endif
