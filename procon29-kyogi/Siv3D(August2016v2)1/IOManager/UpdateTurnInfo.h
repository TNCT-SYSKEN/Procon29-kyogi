#pragma once
#include "../Data/Map.h"
#include "../Data/Evaluation.h"
#include "../Setting.h"
#include "../Data/TurnManager.h"

class UpdateTurnInfo {
public:
	void updateManager(void);
	void update();
	void goTurn(void);
	void backTurn(void);
private:
};