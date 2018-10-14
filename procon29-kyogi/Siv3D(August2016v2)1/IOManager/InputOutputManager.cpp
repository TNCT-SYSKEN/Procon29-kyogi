#include "InputOutputManager.h"

//クラス変数の定義
CreateMapClass createMap;
DrawMap drawMap;
UpdateTurnInfo updateTurn;
Interrupt interrupt;

void InputOutputManager::init(void)
{
	//起動時のみ実行
	bool ret;
	do {
		ret = createMap.createMapClass();
	} while (!ret);
}

void InputOutputManager::inputOuntputManager(void)
{
	//DrawMap ,Interrupt,UpdateTurnInfoの制御
	drawMap.drawManager();
	interrupt.interruptManager();
	updateTurn.updateManager();

}
