#include "AlgorithmManager.h"

void AlgorithmManager::algorithmManager(void)
{
	/*
	�������肩�����ǂ݂����f���ēǂݏo��
	*/
	if (turn < THRESHOLD)
	{
		BruteForce bruteForce;
		bruteForce.bruteForce();

	}
	else
	{
		Prefetching prefetching;
		prefetching.prefetching();

		AddEvaluation addEvaluation;
		addEvaluation.addEvaluation();
	}
}
