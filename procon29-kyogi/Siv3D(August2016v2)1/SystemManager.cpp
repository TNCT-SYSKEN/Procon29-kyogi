#include "SystemManager.h"

//クラス型変数の宣言
InputOutputManager ioManager;
AlgorithmManager algoManager;

void SystemManager::startSolver(void)
{
	//システムを開始する
	algoManager.algorithmManager();
	ioManager.inputOuntputManager();
}

void SystemManager::endSolver(void)
{
	//システムを終了する条件
	//終わりのターン数に達した場合
	//Endが押された場合
}

void SystemManager::systemManager(void)
{
	/*
	アルゴリズムとＩＯマネージャーを管理
	startSolver
	InputOutputManagerを起動
	AlgorithmManagerを起動
	endSolverを起動
	*/
	startSolver();
	endSolver();
}

