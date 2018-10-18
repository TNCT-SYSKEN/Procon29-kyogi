#pragma once
#include "Masu.h"
#include "Agent.h"
#define TurnNumber 120
#define ValueOfAgent 2 
#define VERTICAL 12 
#define WIDTH 12

class Map {
public:
	static Map* getMap();
	//縦
	int Vertical;
	//横
	int Width;
	//スコア合計
	int friendSumScore;
	int enemySumScore;
	//タイルポイント
	int friendTileScore;
	int enemyTileScore;
	//領域ポイント
	int friendAreaScore;
	int enemyAreaScore;
	//ターン数
	int Turn;
	//Masuを二次元配列で持っている
	Masu board[VERTICAL][WIDTH];
	//エージェント
	vector< Agent > agents;
private:
	static Map* InsMap;
};
