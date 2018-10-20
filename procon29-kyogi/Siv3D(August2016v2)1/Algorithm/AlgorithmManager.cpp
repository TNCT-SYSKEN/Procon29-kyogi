#include "AlgorithmManager.h"

void AlgorithmManager::algorithmManager(void)
{
	/*
	‘“–‚½‚è‚©”Žèæ“Ç‚Ý‚©”»’f‚µ‚Ä“Ç‚Ýo‚·
	*/
	Setting *setting;
	setting = setting->getSetting();
	if (setting->bruteForce) {
		BruteForce bruteForce;
		bruteForce.bruteForce();
	} else {
		Map *map;
		map = map->getMap();

		AddEvaluation addEvaluation;

		Agent agent1 = map->agents[0];
		map->agents[0].lastPosition = addEvaluation.addEvaluation(agent1);

		Agent agent2 = map->agents[1];
		map->agents[1].lastPosition = addEvaluation.addEvaluation(agent2);
	}
}