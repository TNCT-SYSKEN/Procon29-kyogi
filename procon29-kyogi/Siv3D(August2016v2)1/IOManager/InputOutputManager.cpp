#include "InputOutputManager.h"

//�N���X�ϐ��̒�`
CreateMapClass createMap;
DrawMap drawMap;
UpdateTurnInfo updateTurn;
Interrupt *interrupt;

void InputOutputManager::init(void)
{
	//�N�����̂ݎ��s
	bool ret;
	do {
		ret = createMap.createMapClass();
	} while (!ret);
}

void InputOutputManager::inputOuntputManager(void)
{
	//DrawMap ,Interrupt,UpdateTurnInfo�̐���
	//interrupt = interrupt->getInterrupt();

	drawMap.drawManager();
	//����
	//interrupt->interruptManager();
	updateTurn.updateManager();

}
