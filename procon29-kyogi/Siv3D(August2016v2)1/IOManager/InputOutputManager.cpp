#include "InputOutputManager.h"

DrawMap *drawMap;

InputOutputManager::InputOutputManager()
{
	//createMap->createMapClass();
}

void InputOutputManager::inputOuntputManager(void)
{
	//�N���X�ϐ��̒�`
	//CreateMapClass *createMap;

	//UpdateTurnInfo *updateTurn;
	//Interrupt *interrupt;
	//DrawMap,CreateMapClass,Interrupt,UpdateTurnInfo�̐���
	drawMap->drawManager();
	//interrupt->interruptManager();
	//updateTurn->updateManager();
}
