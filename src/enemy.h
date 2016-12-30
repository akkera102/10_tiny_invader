#ifndef ENEMY_H
#define ENEMY_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lib/common.h"

//---------------------------------------------------------------------------
#define ENEMY_MAX_CNT				16
#define ENEMY_MAX_DISPLAY			6


//---------------------------------------------------------------------------

typedef struct {
	bool is;
	s8   num;

} ST_ENEMY_DISPLAY;


typedef struct {
	bool isHit;
	bool isUfo;

	s8   part;
	s8   pattern;

	s8   cnt;								// 1パターンの出現数
	s8   wait;								// 移動ウェイト

	u16  score;
	s8   sum;

	s8   dispMax;							// 最大表示数
	s8   dispCnt;							// 現在の表示数
	ST_ENEMY_DISPLAY d[ENEMY_MAX_DISPLAY];

} ST_ENEMY;


//---------------------------------------------------------------------------
void EnemyInit(void);
void EnemyInit2(void);
void EnemyInit3(void);
void EnemyInit4(s8 par, s8 pat, s8 cnt, u16 sco, bool isUfo);
void EnemyExec(void);
void EnemyDraw(void);

void EnemyMove(void);
void EnemyAdd(void);
void EnemyDel(s8 num);

s8   EnemyGetPos(s8 num);
s8   EnemyGetPattern(void);
u16  EnemyGetScore(void);

bool EnemyIsDel(s8 num);
bool EnemyIsChrHit(void);
bool EnemyIsDestory(void);
bool EnemyIsComplete(void);


#ifdef __cplusplus
}
#endif
#endif
