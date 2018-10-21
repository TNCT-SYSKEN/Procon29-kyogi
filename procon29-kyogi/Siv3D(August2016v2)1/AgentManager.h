#pragma once
#include "Data/Map.h"
#include "Data/Masu.h"
#include "Setting.h"
#define AGENTS 4

//agentの位置の更新
class AgentManager {
public:
	void agentManager();
	void setAgentPos();
	void setTurnFlag();
	void checkAgentConflict();
	void decideAgentAct();
	void moveAgent(int agentNum);
	void eraseAgent(int agentNum);
	void stayAgent(int agentNum);
private:
};