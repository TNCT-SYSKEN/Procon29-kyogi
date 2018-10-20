#pragma once
#include "../Data/Map.h"
#include "../Setting.h"
#include <vector>

class Prefetching {
public:
	vector<int> prefetching(int, int);
	int ansScore;
private:
	int caluculateSumScore(int nowX, int nowY, int step, vector<pair<Masu, pair<int, int>>> route);
	int caluculateTileScore(int nowX, int nowY, int step, vector<pair<Masu, pair<int, int>>> route);
	int caluculateMovable(int nowX, int nowY, int step);
	void caluculateEncircle(vector<pair<Masu, pair<int, int>>> route, int nowX, int nowY, vector< vector<int> >& visited);
	static bool isAdjoin(pair<int, int> p1, pair<int, int > p2) {
		return (abs(p1.first - p2.first) <= 1 && abs(p1.second - p2.second));
	}
	static bool isVisited(vector<pair<Masu, pair<int, int>>> route, int newX, int newY) {
		for (pair<Masu, pair<int, int>> p : route) {
			if (newX == p.second.first && newY == p.second.second) return true;
		}
		return false;
	}
};