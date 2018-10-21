#include "BruteForce.h"

int dy[] = { 1, 0, -1, 0 , 1, 1, -1, -1 };
int dx[] = { 0, 1, 0, -1 , 1, -1, 1, -1 };

void BruteForce::bruteForce(void)
{
	//経路のパターンを生やす．

	//残りターン数．現在はダミー
	int remainingTurn = 3;
}

//経路 route を取った際のスコアを計算する．
int BruteForce::calculateScore(int nowX, int nowY, vector<int> route) {
	int tileScore = 0;
	Map *map;
	map = map->getMap();
	for (int i : route) {
		nowX += dx[i]; nowY += dy[i];
		tileScore += map->board[nowY][nowX].TilePoint;
	}
}
