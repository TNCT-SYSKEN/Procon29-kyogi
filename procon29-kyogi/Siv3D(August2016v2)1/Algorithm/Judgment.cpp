#include "Judgment.h"
#include "../gneral.h"

//priority��1�i2�Ԗڂ̃G�[�W�F���g�j�Ȃ�C1�Ԗڂ̃G�[�W�F���g�Ƃ��Ԃ����ꍇ�Ɏ��2�Ԗڂ̂�ɕύX����
pair<int, int> Judgment::judgment(Evaluation evl, int priority, Agent agent)
{
	//�]���_�ɂ���Ăǂ̎�����肷��̂����߂�
	pair <int, int> ansPosition;
	pair <int, int> ansPositionReserve = make_pair(0, 0); //�s���悪1�Ԗڂ�2�Ԗڂ̃G�[�W�F���g�ł��Ԃ��Ă����Ƃ��̂��߂̗\��
	//sum , tile ,move , naname , 1ttesakinotairunotokutenn, �݂͂�j����, �O��
	vector<double> weight = { 14, 8, 5, 13, 40 , 30, 30}; //�e�]�����ڂɑ΂���d��
	
	int dy[] = { 1, 0, -1, 0 , 1, 1, -1, -1 };
	int dx[] = { 0, 1, 0, -1 , 1, -1, 1, -1 };

	Map *map;
	map = map->getMap();

	double maxValue = 0; //�ő�̕]���l
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
				vector< vector<int> > Evisited; //�G�̈͂݌v�Z
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

	//���肩��őP��������Ă��܂����ꍇ��ansPositionReserve��2�Ԏ肪�i�[����Ȃ��̂ōĒT��
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
		if(ansPositionOf1 == ansPositionOf2){ //�s���悪����Ă�����
			ansPosition = ansPositionReserve; //�\���̃|�W�V�����ɕύX����
		}
	}
	return ansPosition;
}
