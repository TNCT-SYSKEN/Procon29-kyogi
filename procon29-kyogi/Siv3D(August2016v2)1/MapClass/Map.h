#pragma
#include "Masu.h"

#define TurnNumber 120
#define ValueOfAgent 2 
#define VERTICAL 12
#define WIDTH 12

class Map {
public:
	//縦
	int Vertical;
	//横
	int Width;
	//スコア合計(縦がエージェントの区別,横が各ターンごとの点数を保存
	int SumScore[ValueOfAgent][TurnNumber];
	//ターン数
	int Turn;
	//Masuを二次元配列で持っている
	Masu map[VERTICAL][WIDTH];
private:
};