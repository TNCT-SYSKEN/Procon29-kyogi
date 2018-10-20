#pragma once
#include "../Data/Map.h"
#include "../Setting.h"
#include <vector>

class Prefetching {
public:
	vector<int> prefetching(int, int);
	int ansScore;
private:
	int caluculateSumScore(int nowX, int nowY, int step, std::vector<std::pair<Masu, std::pair<int, int>>> route);
	int caluculateTileScore(int nowX, int nowY, int step);
	int caluculateMovable(int nowX, int nowY, int step);
	int caluculateEncircle(Map map, std::vector<std::pair<Masu, std::pair<int, int>>> route);
	static bool isAdjoin(std::pair<int, int> p1, std::pair<int, int > p2) {
		return (abs(p1.first - p2.first) <= 1 && abs(p1.second - p2.second));
	}
};