#include "BruteForce.h"

int dy[] = { 1, 0, -1, 0 , 1, 1, -1, -1 };
int dx[] = { 0, 1, 0, -1 , 1, -1, 1, -1 };

void BruteForce::bruteForce(void)
{
	//�o�H�̃p�^�[���𐶂₷�D

	//�c��^�[�����D���݂̓_�~�[
	int remainingTurn = 3;
}

//�o�H route ��������ۂ̃X�R�A���v�Z����D
int BruteForce::calculateScore(int nowX, int nowY, vector<int> route) {
	int tileScore = 0;
	Map *map;
	map = map->getMap();
	for (int i : route) {
		nowX += dx[i]; nowY += dy[i];
		tileScore += map->board[nowY][nowX].TilePoint;
	}
}
