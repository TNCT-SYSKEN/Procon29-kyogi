#pragma once
#include "../gneral.h"

class Agent {
public :
	//エージェントがそのターンにおいて動くべき最終的な座標
	pair <int, int> nextPosition;
	bool canMoveNextPos;
	bool camMoveTile;
	//エージェントが除去するタイルの座標
	pair <int, int> erasePosition;
	//エージェントの現在位置
	pair <int, int> position;
	//エージェントが行う行動
	enum actAgent{
		//停滞
		stagnation = 0,
		//移動
		move = 1,
		//タイル除去
		erase = 2
	};
	actAgent actAgent;
	//どのエージェントか
	enum EnemyNumber { friend1 = 0, friend2 = 1, enemy1 = 3, enemy2 = 4 };
	EnemyNumber Status;
private:
};
