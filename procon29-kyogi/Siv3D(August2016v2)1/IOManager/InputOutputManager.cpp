#include "InputOutputManager.h"

InputOutputManager::InputOutputManager()
{
	createMap->createMapClass();
}

void InputOutputManager::inputOuntputManager(void)
{
	//DrawMap,CreateMapClass,Interrupt,UpdateTurnInfo‚Ì§Œä
	drawMap->draw();
	interrupt->interruptManager();
	updateTurn->updateManager();
}
