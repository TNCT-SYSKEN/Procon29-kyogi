#pragma once
#include "../Data/Evaluation.h"
#include "../Data/Map.h"
#include "../gneral.h"
#include "Prefetching.h"

class Judgment {
public:
	//�Ԃ�l��Pair?
	pair<int, int> judgment(Evaluation evl, int priority, Agent agent);
private:
};