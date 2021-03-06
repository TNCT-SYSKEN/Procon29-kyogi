#pragma once
#include "../gneral.h"
#include "../Data/Map.h"
#include "./Prefetching.h"

class BruteForce {
public:
	vector<int> bruteForce(int, int);
private:
	int calculateScore(int, int, vector<int>);
	int calcRoute(int, vector<int>);
	int nowX, nowY;
};