#include "Judgment.h"
#include "../gneral.h"

//priority��1�i2�Ԗڂ̃G�[�W�F���g�j�Ȃ�C1�Ԗڂ̃G�[�W�F���g�Ƃ��Ԃ����ꍇ�Ɏ��2�Ԗڂ̂�ɕύX����
pair<int, int> Judgment::judgment(Evaluation evl, int priority)
{
	//�]���_�ɂ���Ăǂ̎�����肷��̂����߂�
	pair <int, int> ansPosition;
	pair <int, int> ansPositionReserve = make_pair(0, 0); //�s���悪1�Ԗڂ�2�Ԗڂ̃G�[�W�F���g�ł��Ԃ��Ă����Ƃ��̂��߂̗\��

	vector<double> weight; //�e�]�����ڂɑ΂���d��
	weight.push_back(1.0); weight.push_back(1.0); weight.push_back(1.0); //�_�~�[�D���I�ɕύX�ł���悤�ɂ������D

	int dy[] = { 1, 0, -1, 0 , 1, 1, -1, -1 };
	int dx[] = { 0, 1, 0, -1 , 1, -1, 1, -1 };

	Map *map;
	map = map->getMap();

	double maxValue = 0; //�ő�̕]���l
	for (int i = 0; i < 16; ++i) {
		double value = (evl.SumScore[i] * weight[0]) + (evl.TileScore[i] * weight[1]) + (evl.Movable[i] * weight[2]);
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
