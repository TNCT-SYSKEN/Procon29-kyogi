#include "SystemManager.h"

//クラス変数の定義
AlgorithmManager algoManager;
InputOutputManager ioManager;

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
	startSolver();
	/*
	アルゴリズムとＩＯマネージャーを管理
	startSolverを起動
	InputOutputManagerを起動
	AlgorithmManagerを起動
	endSolverを起動
	*/
}

