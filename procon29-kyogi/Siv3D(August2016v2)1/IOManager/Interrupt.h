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
private:
	void backTurn(void);
	void goTurn(void);
	//æ“Ç‚İ‚Ì”ÍˆÍ‚ğXV
	void prefetchingInfo(void);
	//Ä“x’Tõ‚·‚é
	void Research(void);
	void selectAglo();
	void drawSumScore();
	void drawTileScore();
	void drawAreaScore();
	void drawTurn();
	void drawInfo();
};
