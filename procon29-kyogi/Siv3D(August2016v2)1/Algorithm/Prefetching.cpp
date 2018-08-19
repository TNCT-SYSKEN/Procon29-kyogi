#include "Prefetching.h"
#include <vector>

void Prefetching::prefetching(void)
{
	//caluculateSumScore();
	//caluculateTileScore();
	caluculateMovable();
	//数手先の先読みを管理
}

int Prefetching::caluculateSumScore(int nowX, int nowY, int step, std::vector<Masu> route)
{
	int dy[] = { 1, 0, -1, 0 };
	int dx[] = { 0, 1, 0, -1 };
	//数手先における合計点数によって点数付け
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
	//数手先におけるタイル点数によって点数付け
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
			newScore += caluculateTileScore(newX, newY, step + 1); //重複して数えてしまうので欠陥処理っぽい　経路を持っておいたほうがいい？
		}
		return newScore;
	}
}

void Prefetching::caluculateMovable(void)
{
	//数手先のマスにおけるマスの移動可能マスの数によって点数付け
}

int Prefetching::caluculateEncircle(Map map, std::vector<Masu> route)
{
	//経路 route をとったときの囲み判定をして，領域ポイントの総計を返す
	map;
	return 0;
}

void Prefetching::setMaxStep(int s)
{
	//先読みの深さを変更する
	maxStep = s;
	return;
}

int Prefetching::getMaxStep(void)
{
	return maxStep;
}