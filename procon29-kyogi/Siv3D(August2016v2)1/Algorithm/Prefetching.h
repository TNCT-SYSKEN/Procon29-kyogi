#pragma once
#include "../MapClass/Map.h"

class Prefetching {
public:
	void prefetching(void);
private:
	void caluculateSumScore(void);
	int caluculateTileScore(int nowX, int nowY, int step);
	void caluculateMovable(void);
	int maxStep;
	void setMaxStep(int s);
};