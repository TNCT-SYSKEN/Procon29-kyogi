#include "AddEvaluation.h"

pair<int, int> AddEvaluation::addEvaluation(Agent agent)
{
	//JudgmentEncircle() , Prefetching()で評価点付けする
	//Judgmentで最終手を決定しPairで最終的な位置で返す？

	//ここで8近傍の各点について評価点を求め，Evaluationに突っ込む．順番は以下の配列に従う．
	int dy[] = { 1, 0, -1, 0 , 1, 1, -1, -1};
	int dx[] = { 0, 1, 0, -1 , 1, -1, 1, -1 };
	Evaluation evl;

	for (int i = 0; i < 8; ++i) {
		Prefetching prefetching;
		vector<int> ret = prefetching.prefetching(agent.position.second + dx[i], agent.position.first + dy[i]);

		evl.SumScore[i] = ret[0]; evl.TileScore[i] = ret[1]; evl.Movable[i] = ret[2];
		JudgmentEncircle judgeEncircle;
		judgeEncircle.judgmentEncircle();
	}

	//Evaluationを受けて評価し，最適な手を出す．
	Judgment judge;
	pair<int, int> ansPosition = judge.judgment(evl);

	return make_pair(agent.position.first + ansPosition.first , agent.position.second + ansPosition.second);
}