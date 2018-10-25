#include "Judgment.h"
#include "../gneral.h"

//priorityが1（2番目のエージェント）なら，1番目のエージェントとかぶった場合に手を2番目のやつに変更する
pair<int, int> Judgment::judgment(Evaluation evl, int priority)
{
	//評価点によってどの手を決定するのか決める
	pair <int, int> ansPosition;
	pair <int, int> ansPositionReserve = make_pair(0, 0); //行き先が1番目と2番目のエージェントでかぶっていたときのための予備

	vector<double> weight; //各評価項目に対する重み
	weight.push_back(1.0); weight.push_back(1.0); weight.push_back(1.0); //ダミー．動的に変更できるようにしたい．

	int dy[] = { 1, 0, -1, 0 , 1, 1, -1, -1 };
	int dx[] = { 0, 1, 0, -1 , 1, -1, 1, -1 };

	Map *map;
	map = map->getMap();

	double maxValue = 0; //最大の評価値
	for (int i = 0; i < 16; ++i) {
		double value = (evl.SumScore[i] * weight[0]) + (evl.TileScore[i] * weight[1]) + (evl.Movable[i] * weight[2]);
		if (value > maxValue) {
			ansPositionReserve = ansPosition;
			ansPosition = make_pair(dy[i % 8], dx[i % 8]);
			maxValue = value;
		}
	}

	//初手から最善手を引いてしまった場合はansPositionReserveに2番手が格納されないので再探索
	maxValue = 0;
	if(ansPositionReserve == make_pair(0, 0)){
		for (int i = 1; i < 16; ++i) {
			double value = (evl.SumScore[i] * weight[0]) + (evl.TileScore[i] * weight[1]) + (evl.Movable[i] * weight[2]);
			if (value > maxValue) {
				ansPositionReserve = make_pair(dy[i % 8], dx[i % 8]);
				maxValue = value;
			}
		}
	}

	if(priority == 1){
		Agent agent1 = map->agents[0]; Agent agent2 = map->agents[1];
		pair<int, int> ansPositionOf1 = agent1.nextPosition;
		pair<int, int> ansPositionOf2 = make_pair(agent2.position.first + ansPosition.first, agent2.position.second + ansPosition.second);
		if(ansPositionOf1 == ansPositionOf2){ //行き先が被っていたら
			ansPosition = ansPositionReserve; //予備のポジションに変更する
		}
	}
	return ansPosition;
}
