#pragma once
#include "MapClass/Map.h"
#define TurnValue 120

class TurnManager {
public :
	TurnManager *getTurnManager();
	Map Turn[TurnValue];
private:
	static TurnManager * InsTurnManager;
};
