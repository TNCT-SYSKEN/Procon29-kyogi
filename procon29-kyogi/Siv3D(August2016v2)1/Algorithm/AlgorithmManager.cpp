#include "AlgorithmManager.h"
#include "../Data/Map.h"
void AlgorithmManager::algorithmManager(void)
{
	Map *map;
	map = map->getMap();
	map->agents[0].nextPosition.first = 1;
	map->agents[0].nextPosition.second = 0;

	map->agents[1].nextPosition.first = 1;
	map->agents[1].nextPosition.second = 2;
	/*
	総当たりか数手先読みか判断して読み出す
	*/

	/*
	if (1) { // 判定用のフラグをあとで突っ込む
		BruteForce bruteForce;
		bruteForce.bruteForce();
	} else {
		AddEvaluation addEvaluation;
		addEvaluation.addEvaluation();
	}
	*/
}