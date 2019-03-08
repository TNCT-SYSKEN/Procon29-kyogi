#include "AlgorithmManager.h"

void AlgorithmManager::algorithmManager(void)
{
	/*
	総当たりか数手先読みか判断して読み出す
	*/
	Setting *setting;
	setting = setting->getSetting();

	Map *map;
	map = map->getMap();

	AddEvaluation addEvaluation;

	Agent agent1 = map->agents[0];
	map->agents[0].nextPosition = addEvaluation.addEvaluation(agent1, 1);

	Println();

	Agent agent2 = map->agents[1];
	map->agents[1].nextPosition = addEvaluation.addEvaluation(agent2, 2);

	Println();
}