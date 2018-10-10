#pragma once
#include "../gneral.h"

class Agent {
public :
	//エージェントがそのターンにおいて動くべき最終的な座標
	pair <int, int> lastPosition = make_pair(0, 0);
	//エージェントの現在位置
	pair <int, int> position;
	//どのエージェントか
	enum EnemyNumber { friend1 = 0, friend2 = 1, enemy1 = 3, enemy2 = 4 };
private:
};
