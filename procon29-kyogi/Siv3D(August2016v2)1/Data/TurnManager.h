#pragma once
#include "Map.h"
#include "../Setting.h"
#include "Evaluation.h"
#define MAX_TURN 120

class TurnManager {
public :
	static TurnManager *getTurnManager();
	Map map[MAX_TURN];
	Evaluation eva[MAX_TURN];
	Setting setting[MAX_TURN];
private:
	static TurnManager* InsTurnManager;
};
