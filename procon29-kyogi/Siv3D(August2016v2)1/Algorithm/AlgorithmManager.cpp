#include "AlgorithmManager.h"

void AlgorithmManager::algorithmManager(void)
{
	/*
	�������肩�����ǂ݂����f���ēǂݏo��
	*/
	Setting *setting;
	setting = setting->getSetting();
	if (setting->bruteForce) {
		BruteForce bruteForce;
		bruteForce.bruteForce();
	} else {
		Map *map;
		map = map->getMap();
		Println(map->agents[0].lastPosition.first);
		Agent agent1 = map->agents[0];
		AddEvaluation addEvaluation;
		addEvaluation.addEvaluation(agent1);
		Println(map->agents[0].lastPosition.first);
	}
}