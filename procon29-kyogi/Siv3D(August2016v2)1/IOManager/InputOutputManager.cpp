#include "InputOutputManager.h"

InputOutputManager::InputOutputManager()
{
	createMap->createMapClass();
}

void InputOutputManager::inputOuntputManager(void)
{
	//DrawMap,CreateMapClass,Interrupt,UpdateTurnInfo�̐���
	//InputOutputManager();
	drawMap->drawManager();
	interrupt->interruptManager();
	updateTurn->updateManager();
}
