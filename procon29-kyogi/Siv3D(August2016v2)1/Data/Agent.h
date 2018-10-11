#pragma once
#include "../gneral.h"

class Agent {
public :
	static Agent* getAgent();
	//エージェントがそのターンにおいて動くべき最終的な座標
	pair <int, int> lastPosition = make_pair(0, 0);
	//エージェントの現在位置
	pair <int, int> position = make_pair(0, 0);
	//どのエージェントか
	enum EnemyNumber { friend1, friend2, enemy1, enemy2 };
private:
	//nullptrで初期化用の隠蔽コンストラクタ
	//Agent();
	//オブジェクト
	static Agent *InsAgent;
};
