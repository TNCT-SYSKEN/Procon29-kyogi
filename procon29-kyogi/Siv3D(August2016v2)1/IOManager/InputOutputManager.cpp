#include "InputOutputManager.h"

//クラス変数の定義
CreateMapClass createMap;
DrawMap drawMap;
UpdateTurnInfo updateTurn;
Interrupt interrupt;

InputOutputManager::InputOutputManager()
{
	//起動時のみ実行
}

void InputOutputManager::inputOuntputManager(void)
{
	//DrawMap ,Interrupt,UpdateTurnInfoの制御
	drawMap.drawManager();
	interrupt.interruptManager();
	updateTurn.updateManager();

	bool ret;
	do {
		ret = createMap.createMapClass();
	} while (!ret);
}
