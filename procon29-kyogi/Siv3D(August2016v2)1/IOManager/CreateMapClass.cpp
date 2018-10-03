#include "CreateMapClass.h"

void CreateMapClass::createMapClass(void)
{
	Map *map;
	map = map->getMap();
	for (int j = 0; j < VERTICAL; ++j) {
		for (int i = 0; i < WIDTH; ++i) {
			Masu masu;
			
			map->board[j][i];
		}
	}
	//Agentクラス,Masuクラスをまとめる配列を用意し代入
}

void CreateMapClass::createMasuClass(void)
{
	//読み取った内容をもと各エージェントクラスを作成
}

void CreateMapClass::createAgent(void)
{
	//読み取った内容をもとに各マスクラスを作成
}
