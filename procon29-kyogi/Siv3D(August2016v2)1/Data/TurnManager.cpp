#include "TurnManager.h"

TurnManager* TurnManager::InsTurnManager = nullptr;
TurnManager* TurnManager::getTurnManager() {
	if (InsTurnManager == nullptr) {
		InsTurnManager = new TurnManager;
	}
	return InsTurnManager;
}