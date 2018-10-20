#pragma once
#include "Data/Map.h"
#include "Data/Masu.h"
#include "Setting.h"
#define AGENTS 4

//agent‚ÌˆÊ’u‚ÌXV
class AgentManager {
public:
	void setAgentPos();
	void setTurnFlag();
	void checkAgentConflict();
	void decideAgentAct();
	void moveAgent();
	void eraseAgent();
	void stayAgent();
private:
};