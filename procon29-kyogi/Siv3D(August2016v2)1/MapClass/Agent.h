#pragma once
#include "../gneral.h"

class Agent {
public :
	//エージェントの位置
	pair <int , int> position = make_pair(0 , 0);
	//どのエージェントか
	enum EnemyNumber { riend1 = 0, friend2 = 1, enemy1 = 3, enemy2 = 4 };
private:
};
