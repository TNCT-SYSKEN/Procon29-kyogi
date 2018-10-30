#pragma once
#include "Data/Map.h"
#include "Data/Masu.h"
#include "Setting.h"
#define AGENTS 4

//agent‚ÌˆÊ’u‚ÌXV
class AgentManager {
public:
	void agentMoveManager();
	void setAgentPos();
	void setTurnFlag();
	void checkAgentConflict();
	void decideAgentAct();
	void moveAgent(int agentNum);
	void eraseAgent(int agentNum);
	void stayAgent(int agentNum);
private:
};