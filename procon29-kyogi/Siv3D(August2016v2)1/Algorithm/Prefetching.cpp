#include "Prefetching.h"
#include <vector>

void Prefetching::prefetching(void)
{
	//caluculateSumScore();
	//caluculateTileScore();
	caluculateMovable();
	//�����̐�ǂ݂��Ǘ�
}

int Prefetching::caluculateSumScore(int nowX, int nowY, int step, std::vector<Masu> route)
{
	int dy[] = { 1, 0, -1, 0 };
	int dx[] = { 0, 1, 0, -1 };
	//�����ɂ����鍇�v�_���ɂ���ē_���t��
	if (step >= maxStep) {
		return 0;
	}
	else {
		Map map;
		int newScore = 0;
		for (int i = 0; i < 4; ++i) {
			int newX, newY;
			newX = nowX + dx[i];
			newY = nowY + dy[i];
			newScore += map.board[newX][newY].TilePoint;
			route.push_back(map.board[newX][newY]);

			newScore += caluculateSumScore(newX, newY, step + 1, route);
		}
		return newScore;
	}
}

int Prefetching::caluculateTileScore(int nowX, int nowY, int step)
{
	int dy[] = { 1, 0, -1, 0 };
	int dx[] = { 0, 1, 0, -1 };
	//�����ɂ�����^�C���_���ɂ���ē_���t��
	if (step >= maxStep) {
		return 0;
	}
	else {
		Map map;
		int newScore = 0;
		for (int i = 0; i < 4; ++i) {
			int newX, newY;
			newX = nowX + dx[i];
			newY = nowY + dy[i];
			newScore += map.board[newX][newY].TilePoint;
			newScore += caluculateTileScore(newX, newY, step + 1); //�d�����Đ����Ă��܂��̂Ō��׏������ۂ��@�o�H�������Ă������ق��������H
		}
		return newScore;
	}
}

void Prefetching::caluculateMovable(void)
{
	//�����̃}�X�ɂ�����}�X�̈ړ��\�}�X�̐��ɂ���ē_���t��
}

int Prefetching::caluculateEncircle(Map map, std::vector<Masu> route)
{
	//�o�H route ���Ƃ����Ƃ��̈͂ݔ�������āC�̈�|�C���g�̑��v��Ԃ�
	map;
	return 0;
}

void Prefetching::setMaxStep(int s)
{
	//��ǂ݂̐[����ύX����
	maxStep = s;
	return;
}

int Prefetching::getMaxStep(void)
{
	return maxStep;
}