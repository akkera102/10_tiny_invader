#include "game.h"
#include "lib/key.h"
#include "res.h"
#include "chr.h"
#include "enemy.h"
#include "mem.h"


//---------------------------------------------------------------------------
ST_GAME Game;


//---------------------------------------------------------------------------
void GameInit(void)
{
	_Memset(&Game, 0x00, sizeof(ST_GAME));
}
//---------------------------------------------------------------------------
void GameExec(void)
{
	switch(Game.act)
	{
	case GAME_ACT_RESET: GameExecReset(); break;
	case GAME_ACT_START: GameExecStart(); break;
	case GAME_ACT_PLAY:  GameExecPlay();  break;
	case GAME_ACT_CLEAR: GameExecClear(); break;
	case GAME_ACT_HIT:   GameExecHit();   break;
	case GAME_ACT_OVER:  GameExecOver();  break;

	default:
		ERROR(Game.act);
		break;
	}
}
//---------------------------------------------------------------------------
void GameExecReset(void)
{
	ResInit();
	MemInit();
	ChrInit();
	EnemyInit();

	GameSetAct(GAME_ACT_START);
}
//---------------------------------------------------------------------------
void GameExecStart(void)
{
	Game.cnt++;

	if(Game.cnt < 2*30)
	{
		GameDrawScoreHigh();
		return;
	}

	if(Game.cnt < 4*30)
	{
		GameDrawCount();
		return;
	}

	GameDrawCount();
	GameSetAct(GAME_ACT_PLAY);
}
//---------------------------------------------------------------------------
void GameExecPlay(void)
{
	if(Game.cnt != 0)
	{
		Game.cnt--;
		ChrExec();

		return;
	}

	if(EnemyIsDestory() == TRUE)
	{
		if(EnemyIsComplete() == TRUE)
		{
			GameSetAct(GAME_ACT_OVER);
		}
		else
		{
			GameSetAct(GAME_ACT_CLEAR);
		}
		return;
	}

	if(EnemyIsChrHit() == TRUE)
	{
		if(ChrIsHp() == TRUE)
		{
			GameSetAct(GAME_ACT_OVER);
		}
		else
		{
			GameSetAct(GAME_ACT_HIT);
		}
		return;
	}


	ChrDraw();
	EnemyDraw();

	ChrExec();
	EnemyExec();


	if(ChrIsShotEmpty() == TRUE)
	{
		GameSetAct(GAME_ACT_OVER);
		return;
	}
}
//---------------------------------------------------------------------------
void GameExecClear(void)
{
	GameDrawPattern();
	GameDrawScore();

	if(++Game.cnt < 2*30)
	{
		return;
	}

	EnemyInit2();
	ChrInit();

	GameSetAct(GAME_ACT_PLAY);
}
//---------------------------------------------------------------------------
void GameExecHit(void)
{
	GameDrawScore();

	if(++Game.cnt < 2*30)
	{
		return;
	}

	EnemyInit3();
	ChrInit2();

	GameSetAct(GAME_ACT_PLAY);
}
//---------------------------------------------------------------------------
void GameExecOver(void)
{
	GameDrawPattern();
	GameDrawScore();
	ResDrawMsg();

	if(KeyGetTrg() & KEY_A)
	{
		MemSave(EnemyGetScore());
		GameSetAct(GAME_ACT_RESET);
	}
}
//---------------------------------------------------------------------------
void GameDrawNum(u16 num)
{
	s8 i;

	for(i=7; i>=2; i--)
	{
		ResDrawNum(i, num % 10);
		num /= 10;
	}
}
//---------------------------------------------------------------------------
void GameDrawScore(void)
{
	GameDrawNum(EnemyGetScore());
}
//---------------------------------------------------------------------------
void GameDrawScoreHigh(void)
{
	GameDrawNum(MemGetScoreHigh());
}
//---------------------------------------------------------------------------
void GameDrawCount(void)
{
	ResDrawNum(3, 1);
	ResDrawNum(4, 6);
	ResDrawBar(5);
	ResDrawNum(6, 3);
	ResDrawNum(7, 0);
}
//---------------------------------------------------------------------------
void GameDrawPattern(void)
{
	ResDrawNum(0, EnemyGetPattern() + 1);
	ResDrawBar(1);
}
//---------------------------------------------------------------------------
void GameSetAct(u8 act)
{
	Game.act = act;
	Game.cnt = 0;
}
//---------------------------------------------------------------------------
void GameSetCnt(u8 cnt)
{
	Game.cnt = cnt;
}
