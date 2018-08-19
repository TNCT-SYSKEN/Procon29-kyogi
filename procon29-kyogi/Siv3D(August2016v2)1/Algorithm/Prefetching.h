#pragma once
#include "../MapClass/Map.h"
#include <vector>

class Prefetching {
public:
	void prefetching(void);
	void setMaxStep(int s);
	int getMaxStep(void);
private:
	int caluculateSumScore(int nowX, int nowY, int step, std::vector<Masu> route);
	int caluculateTileScore(int nowX, int nowY, int step);
	void caluculateMovable(void);
	int caluculateEncircle(Map map, std::vector<Masu> route);
	int maxStep;
};