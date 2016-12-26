#include "enemy.h"
#include "lib/rnd.h"
#include "lib/oled.h"
#include "res.h"
#include "chr.h"
#include "mem.h"

//---------------------------------------------------------------------------
const s8 EnemyWaitList[] = {
	36, 33, 30, 27, 24, 21, 18, 15, 12,
};

//---------------------------------------------------------------------------
ST_ENEMY Enemy;


//---------------------------------------------------------------------------
void EnemyInit(void)
{
	EnemyInit4(0, 0, ENEMY_MAX_CNT, 0);
}
//---------------------------------------------------------------------------
void EnemyInit2(void)
{
	if(++Enemy.pattern >= 9)
	{
		Enemy.pattern = 0;

		if(++Enemy.part >= 2)
		{
			Enemy.part = 0;
		}
	}

	EnemyInit4(Enemy.part, Enemy.pattern, ENEMY_MAX_CNT, Enemy.score);
}
//---------------------------------------------------------------------------
void EnemyInit3(void)
{
	EnemyInit4(Enemy.part, Enemy.pattern, Enemy.cnt + Enemy.dispCnt, Enemy.score);
}
//---------------------------------------------------------------------------
void EnemyInit4(s8 par, s8 pat, s8 cnt, u16 sco)
{
	_Memset(&Enemy, 0x00, sizeof(ST_ENEMY));

	Enemy.part     = par;
	Enemy.pattern  = pat;
	Enemy.cnt      = cnt;
	Enemy.score    = sco;
	Enemy.dispMax  = (par == 0) ? ENEMY_MAX_DISPLAY : ENEMY_MAX_DISPLAY-1;

	EnemyAdd();
}
//---------------------------------------------------------------------------
void EnemyExec(void)
{
	if(++Enemy.wait < EnemyWaitList[Enemy.pattern])
	{
		return;
	}
	Enemy.wait = 0;


	if(Enemy.d[0].is == TRUE)
	{
		Enemy.isHit = TRUE;
		return;
	}
	EnemyMove();


	if(Enemy.cnt == 0)
	{
		return;
	}
	EnemyAdd();
}
//---------------------------------------------------------------------------
void EnemyDraw(void)
{
	s8 i;

	for(i=0; i<Enemy.dispMax; i++)
	{
		if(Enemy.d[i].is == TRUE)
		{
			ResDrawNum(i+2, Enemy.d[i].num);
		}
	}

//	OledDrawStr(0, 5, "par:%d pat:%d", Enemy.part, Enemy.pattern);
//	OledDrawStr(0, 6, "sum:%d sco:%d", Enemy.sum, Enemy.score);
}
//---------------------------------------------------------------------------
void EnemyMove(void)
{
	s8 i;

	for(i=0; i<Enemy.dispMax-1; i++)
	{
		Enemy.d[i].is  = Enemy.d[i+1].is;
		Enemy.d[i].num = Enemy.d[i+1].num;
	}

	Enemy.d[i].is  = FALSE;
	Enemy.d[i].num = 0;
}
//---------------------------------------------------------------------------
void EnemyAdd(void)
{
	s8 num = Rnd(10);

	if(Enemy.isUfo == TRUE)
	{
		Enemy.isUfo = FALSE;
		num = 10;
	}

	Enemy.d[Enemy.dispMax-1].is  = TRUE;
	Enemy.d[Enemy.dispMax-1].num = num;

	Enemy.cnt--;
	Enemy.dispCnt++;
}
//---------------------------------------------------------------------------
void EnemyDel(s8 num)
{
	s8 pos = EnemyGetPos(num);

	// add score
	Enemy.score += (pos + 1) * (10 + (Enemy.part * 10));

	if(num == 10)
	{
		Enemy.score += 300;
	}

	// add sum
	Enemy.sum = (Enemy.sum + num) % 10;

	if(Enemy.sum == 0)
	{
		Enemy.isUfo = TRUE;
	}

	// del enemy
	s8 i;

	for(i=pos; i>0; i--)
	{
		Enemy.d[i].is  = Enemy.d[i-1].is;
		Enemy.d[i].num = Enemy.d[i-1].num;
	}

	Enemy.d[i].is  = FALSE;
	Enemy.d[i].num = 0;

	Enemy.dispCnt--;
}
//---------------------------------------------------------------------------
s8 EnemyGetPos(s8 num)
{
	s8 i;

	for(i=0; i<Enemy.dispMax; i++)
	{
		if(Enemy.d[i].is == TRUE && Enemy.d[i].num == num)
		{
			goto ret;
		}
	}

ret:
	return i;
}
//---------------------------------------------------------------------------
s8 EnemyGetPattern(void)
{
	return Enemy.pattern;
}
//---------------------------------------------------------------------------
u16 EnemyGetScore(void)
{
	return Enemy.score;
}
//---------------------------------------------------------------------------
bool EnemyIsDel(s8 num)
{
	return (EnemyGetPos(num) != Enemy.dispMax) ? TRUE : FALSE;
}
//---------------------------------------------------------------------------
bool EnemyIsChrHit(void)
{
	return Enemy.isHit;
}
//---------------------------------------------------------------------------
bool EnemyIsDestory(void)
{
	return (Enemy.cnt == 0 && Enemy.dispCnt == 0) ? TRUE : FALSE;
}
//---------------------------------------------------------------------------
bool EnemyIsComplete(void)
{
	return (Enemy.part >= 1 && Enemy.pattern >= 8) ? TRUE : FALSE;
}
