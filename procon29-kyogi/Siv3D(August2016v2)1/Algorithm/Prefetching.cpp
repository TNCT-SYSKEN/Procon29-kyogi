#include "Prefetching.h"

void Prefetching::prefetching(void)
{
	caluculateSumScore();
	//caluculateTileScore();
	caluculateMovable();
	//�����̐�ǂ݂��Ǘ�
}

void Prefetching::caluculateSumScore(void)
{
	//�����ɂ����鍇�v�_���ɂ���ē_���t��
}
int Prefetching::caluculateTileScore(int nowX, int nowY, int step)
{
	//�����ɂ����鍇�v�_���ɂ���ē_���t��
	if (step >= 5) { //���Ƃ�5�̕�����ϐ��ɂ��āC�O������ύX�ł���悤�ɂ���
		return 0;
	}
	else {
		Map map;
		int newScore = 0;
		for (int i = -1; i <= 1; ++i) {
			for (int j = -1; j <= 1; ++j) {
				if (i != 0 || j != 0) {
					int newX, newY;
					newX = nowX + i;
					newY = nowY + j;
					newScore += map.Map[newX][newY].TilePoint;
					newScore += (newX, newY, step + 1);
				}
			}
		}
		return newScore;
	}
}

void Prefetching::caluculateMovable(void)
{
	//�����̃}�X�ɂ�����}�X�̈ړ��\�}�X�̐��ɂ���ē_���t��
}

void Prefetching::setMaxStep(int s) {
	//��ǂ݂̐[����ύX����
	(*this).maxStep = s;
	return;
}
