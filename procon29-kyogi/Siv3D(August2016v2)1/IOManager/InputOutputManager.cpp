#include "InputOutputManager.h"

//�N���X�ϐ��̒�`
CreateMapClass createMap;
DrawMap drawMap;
UpdateTurnInfo updateTurn;
Interrupt interrupt;

InputOutputManager::InputOutputManager()
{
	//�N�����̂ݎ��s
}

void InputOutputManager::inputOuntputManager(void)
{
	//DrawMap ,Interrupt,UpdateTurnInfo�̐���
	drawMap.drawManager();
	interrupt.interruptManager();
	updateTurn.updateManager();

	bool ret;
	do {
		ret = createMap.createMapClass();
	} while (!ret);
}
