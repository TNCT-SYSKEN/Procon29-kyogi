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
	�������肩�����ǂ݂����f���ēǂݏo��
	*/

	/*
	if (1) { // ����p�̃t���O�����Ƃœ˂�����
		BruteForce bruteForce;
		bruteForce.bruteForce();
	} else {
		AddEvaluation addEvaluation;
		addEvaluation.addEvaluation();
	}
	*/
}