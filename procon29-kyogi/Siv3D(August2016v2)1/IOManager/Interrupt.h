#pragma once
#include "../Data/Map.h"
#include "../Data/Evaluation.h"
#include "../gneral.h"
#include <string>
#include "../GUI.h"
#include "../Setting.h"
#include "../Algorithm/AlgorithmManager.h"
#include "UpdateTurnInfo.h"

class Interrupt {
public:
	Interrupt();
	GUI m_gui;
	void inputEnemyMovePos();
	void interruptManager(void);
private:
	void backTurn(void);
	void goTurn(void);
	//先読みの範囲を更新
	void prefetchingInfo(void);
	//再度探索する
	void Research(void);
	void selectAglo();
	void drawSumScore();
	void drawTileScore();
	void drawAreaScore();
	void drawTurn();
};
