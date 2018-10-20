#include "Judgment.h"
#include "../gneral.h"

std::pair<int, int> Judgment::judgment(Evaluation evl)
{
	//�]���_�ɂ���Ăǂ̎�����肷��̂����߂�
	pair <int, int> ansPosition;

	vector<double> weight; //�e�]�����ڂɑ΂���d��
	weight.push_back(1.0); weight.push_back(1.0); weight.push_back(1.0); //�_�~�[�D���I�ɕύX�ł���悤�ɂ������D

	int dx[] = { 0, 1, 0, -1 , 1, -1, 1, -1 };
	int dy[] = { 1, 0, -1, 0 , 1, 1, -1, -1 };

	double maxValue = 0; //�ő�̕]���l
	for (int i = 0; i < 8; ++i) {
		double value = (evl.SumScore[i] * weight[0]) + (evl.TileScore[i] * weight[1]) + (evl.Movable[i] * weight[2]);
		if (value > maxValue) {
			ansPosition = make_pair(dx[i], dy[i]);
			maxValue = value;
		}
	}

	return ansPosition;
}
