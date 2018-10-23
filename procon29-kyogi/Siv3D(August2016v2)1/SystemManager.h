#pragma once
#include "Algorithm/AlgorithmManager.h"
#include "IOManager/InputOutputManager.h"
#include "IOManager/DrawMap.h"
#include "AgentManager.h"

class SystemManager {
public:
	//全体の流れの処理を管理
	void systemManager(void);
	void startSolver(void);
private:

	//開始

	//終了条件を満たしたらプログラム終了
	void endSolver(void);
};