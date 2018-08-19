#include "AddEvaluation.h"

void AddEvaluation::addEvaluation(void)
{
	//JudgmentEncircle() , Prefetching()で評価点付けする
	//Judgmentで最終手を決定しPairで最終的な位置で返す？

	Prefetching prefetching;
	prefetching.prefetching();

	JudgmentEncircle judgeEncircle;
	judgeEncircle.judgmentEncircle();

	Judgment judge;
	judge.judgment();
}