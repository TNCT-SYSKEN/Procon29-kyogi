#include "AlgorithmManager.h"

void AlgorithmManager::algorithmManager(void)
{
	/*
	‘“–‚½‚è‚©”Žèæ“Ç‚Ý‚©”»’f‚µ‚Ä“Ç‚Ýo‚·
	*/
	Setting *setting;
	setting = setting->getSetting();

	if (setting->bruteForce) {
		Map *map;
		map = map->getMap();
		BruteForce bruteForce;

		Agent agent1 = map->agents[0];
		bruteForce.bruteForce(agent1.position.second, agent1.position.first);

		Agent agent2 = map->agents[1];
		bruteForce.bruteForce(agent2.position.second, agent2.position.first);
	} else {
		Map *map;
		map = map->getMap();

		AddEvaluation addEvaluation;

		Agent agent1 = map->agents[0];
		map->agents[0].nextPosition = addEvaluation.addEvaluation(agent1);

		Agent agent2 = map->agents[1];
		map->agents[1].nextPosition = addEvaluation.addEvaluation(agent2);
	}
}