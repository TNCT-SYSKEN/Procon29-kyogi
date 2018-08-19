#include "Prefetching.h"

void Prefetching::prefetching(void)
{
	caluculateSumScore();
	//caluculateTileScore();
	caluculateMovable();
	//数手先の先読みを管理
}

void Prefetching::caluculateSumScore(void)
{
	//数手先における合計点数によって点数付け
}
int Prefetching::caluculateTileScore(int nowX, int nowY, int step)
{
	//数手先における合計点数によって点数付け
	if (step >= 5) { //あとで5の部分を変数にして，外部から変更できるようにする
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
	//数手先のマスにおけるマスの移動可能マスの数によって点数付け
}

void Prefetching::setMaxStep(int s) {
	//先読みの深さを変更する
	(*this).maxStep = s;
	return;
}
