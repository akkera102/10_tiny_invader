#include "mem.h"
#include "lib/eep.h"
#include "lib/rnd.h"


//---------------------------------------------------------------------------
ST_MEM Mem;


//---------------------------------------------------------------------------
void MemInit(void)
{
	_Memset(&Mem, 0x00, sizeof(ST_MEM));


	if(MemIsSave() == TRUE)
	{
		MemLoad();
		
	}

	MemSave(0);
}
//---------------------------------------------------------------------------
void MemLoad(void)
{
	EepSeek(4);

	Mem.scoreHigh = EepRead16();
	Mem.randSeed  = EepRead32();

	RndInitSeed(Mem.randSeed);
}
//---------------------------------------------------------------------------
void MemSave(u16 score)
{
	EepSeek(0);

	EepWrite8('I');
	EepWrite8('N');
	EepWrite8('V');
	EepWrite8('A');

	if(score > Mem.scoreHigh)
	{
		Mem.scoreHigh = score;
	}

	EepWrite16(Mem.scoreHigh);
	EepWrite32(Rnd32() + score);
}
//---------------------------------------------------------------------------
u16 MemGetScoreHigh(void)
{
	return Mem.scoreHigh;
}
//---------------------------------------------------------------------------
bool MemIsSave(void)
{
	EepSeek(0);

	if(EepRead8() != 'I') return FALSE;
	if(EepRead8() != 'N') return FALSE;
	if(EepRead8() != 'V') return FALSE;
	if(EepRead8() != 'A') return FALSE;

	return TRUE;
}
