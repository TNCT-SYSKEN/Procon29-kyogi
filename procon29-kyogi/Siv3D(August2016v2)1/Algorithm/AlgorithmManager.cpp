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
		AddEvaluation addEvaluation;
		addEvaluation.addEvaluation();
	}
}