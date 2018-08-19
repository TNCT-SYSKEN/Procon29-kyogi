#include "AlgorithmManager.h"

void AlgorithmManager::algorithmManager(void)
{
	/*
	‘“–‚½‚è‚©”èæ“Ç‚İ‚©”»’f‚µ‚Ä“Ç‚İo‚·
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
