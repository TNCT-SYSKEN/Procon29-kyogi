#include "Judgment.h"
#include "../gneral.h"

//priorityが1（2番目のエージェント）なら，1番目のエージェントとかぶった場合に手を2番目のやつに変更する
pair<int, int> Judgment::judgment(Evaluation evl, int priority, Agent agent)
{
	//評価点によってどの手を決定するのか決める
	pair <int, int> ansPosition;
	pair <int, int> ansPositionReserve = make_pair(0, 0); //行き先が1番目と2番目のエージェントでかぶっていたときのための予備
	//sum , tile ,move , naname , 1ttesakinotairunotokutenn, 囲みを破るやつ, 外側
	vector<double> weight = { 14, 8, 5, 13, 40 , 30, 30}; //各評価項目に対する重み
	
	int dy[] = { 1, 0, -1, 0 , 1, 1, -1, -1 };
	int dx[] = { 0, 1, 0, -1 , 1, -1, 1, -1 };

	Map *map;
	map = map->getMap();

	double maxValue = 0; //最大の評価値
	for (int i = 0; i < 16; ++i) {

		double value = (evl.SumScore[i] * weight[0]) + (evl.TileScore[i] * weight[1]) + (evl.Movable[i] * weight[2]) + (i % 8 >= 4 ? weight[3] : 0);
		int toY = agent.position.first + dy[i % 8];
		int toX = agent.position.second + dx[i % 8];
		int centerY = map->Vertical / 2;
		int centerX = map->Width / 2;
		value += weight[6] * (abs(toX - centerX) + abs(toY - centerY));
		if (toY >= 0 && toY < map->Vertical && toX >= 0 && toX < map->Width){
			value += map->board[toY][toX].TilePoint * weight[4];
			if (i >= 8 && map->board[toY][toX].Status == Masu::EnemyTile) {
				int s = 0, k = 0;
				vector< vector<int> > Evisited; //敵の囲み計算
				for (int j = 0; j <= map->Vertical + 1; ++j) {
					vector<int> v(map->Width + 2, 0);
					Evisited.push_back(v);
				}

				vector<pair< Masu, pair<int, int> > > route = {};
				Prefetching::caluculateEncircle(route, 0, 0, Evisited, Masu::EnemyTile);
				Prefetching::caluculateEncircle(route, map->Width + 1, map->Vertical + 1, Evisited, Masu::EnemyTile);

				for (int u = 1; u <= map->Vertical; ++u) {
					for (int v = 1; v <= map->Width; ++v) {
						if (!Evisited[u - 1][v - 1] && map->board[u - 1][v - 1].Status != Masu::EnemyTile) {
							s += abs(map->board[u - 1][v - 1].TilePoint);
						}
					}
				}

				Evisited.clear();
				for (int j = 0; j <= map->Vertical + 1; ++j) {
					vector<int> v(map->Width + 2, 0);
					Evisited.push_back(v);
				}
				Masu::StateOfMasu m = map->board[toY][toX].Status;
				map->board[toY][toX].Status = Masu::Non;

				Prefetching::caluculateEncircle(route, 0, 0, Evisited, Masu::EnemyTile);
				Prefetching::caluculateEncircle(route, map->Width + 1, map->Vertical + 1, Evisited, Masu::EnemyTile);

				for (int u = 1; u <= map->Vertical; ++u) {
					for (int v = 1; v <= map->Width; ++v) {
						if (!Evisited[u - 1][v - 1] && map->board[u - 1][v - 1].Status != Masu::EnemyTile) {
							k += abs(map->board[u - 1][v - 1].TilePoint);
						}
					}
				}

				map->board[toY][toX].Status = m;
				value += (s-k) * weight[5];
			}
		}
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
