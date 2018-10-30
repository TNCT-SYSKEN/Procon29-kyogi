#pragma once
#include "../Data/Map.h"
#include "../Data/Evaluation.h"
#include "../gneral.h"
#include <string>
#include "../GUI.h"
#include "../Setting.h"
#include "../Algorithm/AlgorithmManager.h"
#include "UpdateTurnInfo.h"
#include "DrawLeft.h"
#define MASU_SIZE 45
#define MAX_MAP_SIZE 12

class Interrupt {
public:
	Interrupt();
	GUI m_gui;
	void inputEnemyMovePos();
	void interruptManager(void);
	void drawSuport();
private:
	static Interrupt *InsInterrupt;
	void backTurn(void);
	void goTurn(void);
	//先読みの範囲を更新
	void prefetchingInfo(void);
	//再度探索する
	void Research(void);
	void start();
	void selectAglo();
	void drawSumScore();
	void drawTileScore();
	void drawAreaScore();
	void drawTurn();
	void drawInfo();
	void setAgentSide();
	void setMaxStep();
};
