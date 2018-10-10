#pragma once
#include "CreateMapClass.h"
#include "DrawMap.h"
#include "UpdateTurnInfo.h"
#include "Interrupt.h"
//クラス変数の定義
CreateMapClass *createMap;
DrawMap *drawMap;
UpdateTurnInfo *updateTurn;
Interrupt *interrupt;

class InputOutputManager {
public:
	//CreateMapを起動
	InputOutputManager();
	//IO関連を管理
	void inputOuntputManager(void);
private:
};