#ifndef GAME_H
#define GAME_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lib/common.h"

//---------------------------------------------------------------------------
enum {
	GAME_ACT_RESET,
	GAME_ACT_START,
	GAME_ACT_PLAY,
	GAME_ACT_CLEAR,
	GAME_ACT_HIT,
	GAME_ACT_OVER,
};

//---------------------------------------------------------------------------

typedef struct {
	u8 act;
	u8 cnt;

} ST_GAME;



//---------------------------------------------------------------------------
void GameInit(void);
void GameExec(void);
void GameExecReset(void);
void GameExecStart(void);
void GameExecPlay(void);
void GameExecClear(void);
void GameExecHit(void);
void GameExecOver(void);

void GameDrawNum(u16 num);
void GameDrawScore(void);
void GameDrawScoreHigh(void);
void GameDrawCount(void);
void GameDrawPattern(void);

void GameSetAct(u8 act);
void GameSetCnt(u8 cnt);

#ifdef __cplusplus
}
#endif
#endif
