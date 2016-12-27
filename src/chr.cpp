#include "chr.h"
#include "lib/oled.h"
#include "lib/key.h"
#include "enemy.h"
#include "res.h"
#include "game.h"

//---------------------------------------------------------------------------
ST_CHR Chr;


//---------------------------------------------------------------------------
void ChrInit(void)
{
	_Memset(&Chr, 0x00, sizeof(ST_CHR));

	Chr.hp   = CHR_MAX_HP;
	Chr.shot = CHR_MAX_SHOT;
}
//---------------------------------------------------------------------------
void ChrInit2(void)
{
	Chr.hp--;
	Chr.sel = 0;
}
//---------------------------------------------------------------------------
void ChrExec(void)
{
	u8 trg = KeyGetTrg();

	if(trg & KEY_B)
	{
		Chr.shot--;

		if(EnemyIsDel(Chr.sel) == TRUE)
		{
			EnemyDel(Chr.sel);

			GameSetCnt((Chr.sel == 10) ? 23 : 6);		// wait draw
		}
		else
		{
			GameSetCnt(6);
		}
	}

	if(trg & KEY_L)
	{
		Chr.sel++;
		Chr.sel %= 11;
	}
}
//---------------------------------------------------------------------------
void ChrDraw(void)
{
	ResDrawNum(0, Chr.sel);
	ResDrawBar(1, Chr.hp);

//	OledDrawStr(0, 7, "shot:%d", Chr.shot);
}
//---------------------------------------------------------------------------
bool ChrIsShotEmpty(void)
{
	return (Chr.shot == 0) ? TRUE : FALSE;
}
//---------------------------------------------------------------------------
bool ChrIsHp(void)
{
	return (Chr.hp <= 1) ? TRUE : FALSE;
}
