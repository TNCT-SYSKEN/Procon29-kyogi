#pragma once
#include "Algorithm/AlgorithmManager.h"
#include "IOManager/InputOutputManager.h"

class SystemManager {
public:
	//クラス変数の定義
	AlgorithmManager *algoManager;
	InputOutputManager *ioManager;

	//全体の流れの処理を管理
	void systemManager(void);
private:
	//開始
	void startSolver(void);
	//終了条件を満たしたらプログラム終了
	void endSolver(void);
};