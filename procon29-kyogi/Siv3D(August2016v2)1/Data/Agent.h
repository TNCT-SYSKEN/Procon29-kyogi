#pragma once
#include "../gneral.h"

class Agent {
public :
	//エージェントがそのターンにおいて動くべき最終的な座標
	pair <int, int> nextPosition;
	//移動先が他のエージェント被っている
	bool canMoveNextPos;
	//移動先にてきのたいるがある
	bool canMoveTile;
	//移動先がエージェントが居る
	bool beAgent;
	//停滞を意思表示している
	bool doStagnation;
	int beAgentNum;
	//移動先の数字
	int suportNum;
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
