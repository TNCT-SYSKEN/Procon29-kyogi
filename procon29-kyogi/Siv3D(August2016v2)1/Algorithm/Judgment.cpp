#include "Judgment.h"
#include "../gneral.h"

std::pair<int, int> Judgment::judgment(Evaluation evl)
{
	//評価点によってどの手を決定するのか決める
	pair <int, int> ansPosition;

	vector<double> weight; //各評価項目に対する重み
	weight.push_back(1.0); weight.push_back(1.0); weight.push_back(1.0); //ダミー．動的に変更できるようにしたい．

	int dx[] = { 0, 1, 0, -1 , 1, -1, 1, -1 };
	int dy[] = { 1, 0, -1, 0 , 1, 1, -1, -1 };

	double maxValue = 0; //最大の評価値
	for (int i = 0; i < 8; ++i) {
		double value = (evl.SumScore[i] * weight[0]) + (evl.TileScore[i] * weight[1]) + (evl.Movable[i] * weight[2]);
		if (value > maxValue) {
			ansPosition = make_pair(dx[i], dy[i]);
			maxValue = value;
		}
	}

	return ansPosition;
}
