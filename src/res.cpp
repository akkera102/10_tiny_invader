#include "res.h"
#include "res/img.h"
#include "lib/oled.h"


//---------------------------------------------------------------------------
const unsigned char* ResNumList[] = {
	bmpN0,
	bmpN1,
	bmpN2,
	bmpN3,
	bmpN4,
	bmpN5,
	bmpN6,
	bmpN7,
	bmpN8,
	bmpN9,
	bmpNa,
};

const unsigned char* ResBarList[] = {
	bmpB1,
	bmpB2,
	bmpB3,
};
//---------------------------------------------------------------------------
void ResInit(void)
{
	// EMPTY
}
//---------------------------------------------------------------------------
void ResDrawNum(u8 pos, u8 num)
{
	ASSERT(num < 11);

	OledDrawBmp(pos*RES_NUM_CX, OLED_SCREEN_CY/2 - RES_NUM_CY/2, (u8*)ResNumList[num]);
}
//---------------------------------------------------------------------------
void ResDrawBar(u8 pos, u8 num)
{
	ASSERT(num - 1 < 3);

	OledDrawBmp(pos*RES_NUM_CX, OLED_SCREEN_CY/2 - RES_NUM_CY/2, (u8*)ResBarList[num - 1]);
}
//---------------------------------------------------------------------------
void ResDrawMsg(void)
{
	OledDrawBmp(0, 4, (u8*)bmpMsg);
}
