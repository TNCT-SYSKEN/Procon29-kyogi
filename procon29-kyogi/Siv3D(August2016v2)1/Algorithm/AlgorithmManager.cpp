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
		AddEvaluation addEvaluation;
		addEvaluation.addEvaluation();
	}
}