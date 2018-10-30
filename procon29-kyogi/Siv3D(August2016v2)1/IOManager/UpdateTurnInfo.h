#pragma once
#include "../Data/Map.h"
#include "../Data/Evaluation.h"
#include "../Setting.h"
#include "../Data/TurnManager.h"
#include "../Algorithm/AlgorithmManager.h"

class UpdateTurnInfo {
public:
	void updateManager(void);
	void update();
	void goTurn(void);
	void backTurn(void);
	void incrementTurn(void);
	void research(void);
private:
};