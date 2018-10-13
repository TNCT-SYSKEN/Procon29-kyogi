#include "InputOutputManager.h"

//クラス変数の定義
CreateMapClass createMap;
DrawMap drawMap;
UpdateTurnInfo updateTurn;
Interrupt interrupt;

InputOutputManager::InputOutputManager()
{
	//起動時ののみ実行
	createMap.createMapClass();
}

void InputOutputManager::inputOuntputManager(void)
{
	//DrawMap ,Interrupt,UpdateTurnInfoの制御
	drawMap.drawManager();
	interrupt.interruptManager();
	updateTurn.updateManager();
}
