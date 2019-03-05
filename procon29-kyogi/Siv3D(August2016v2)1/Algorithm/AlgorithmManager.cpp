#include "AlgorithmManager.h"

void AlgorithmManager::algorithmManager(int prms1[5], int prms2[5])
{
	/*
	総当たりか数手先読みか判断して読み出す
	*/
	Setting *setting;
	setting = setting->getSetting();

	if (setting->bruteForce) {
		Map *map;
		map = map->getMap();

		BruteForce bruteForce;

		Agent agent1 = map->agents[0];
		setting->bruteForceResults.push_back(bruteForce.bruteForce(agent1.position.second, agent1.position.first));

		Agent agent2 = map->agents[1];
		setting->bruteForceResults.push_back(bruteForce.bruteForce(agent2.position.second, agent2.position.first));
	} else {
		Map *map;
		map = map->getMap();

		AddEvaluation addEvaluation;

		Agent agent1 = map->agents[0];
		map->agents[0].nextPosition = addEvaluation.addEvaluation(agent1, 1, prms1);

		Agent agent2 = map->agents[1];
		map->agents[1].nextPosition = addEvaluation.addEvaluation(agent2, 2, prms1);

		Agent agent3 = map->agents[2];
		map->agents[2].nextPosition = addEvaluation.addEvaluation(agent3, 3, prms2);

		Agent agent4 = map->agents[3];
		map->agents[3].nextPosition = addEvaluation.addEvaluation(agent4, 4, prms2);
	}
}