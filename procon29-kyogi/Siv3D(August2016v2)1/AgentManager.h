#pragma once
#include "Data/Map.h"
#include "Data/Masu.h"
#define AGENTS 4

//agent�̈ʒu�̍X�V
class AgentManager {
public:
	void setAgentPos();
	void setTurnFlag();
	void checkAgentConflict();
private:
};