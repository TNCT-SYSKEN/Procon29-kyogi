#include "DrawLeft.h"
#define MASU_SIZE 45
#define MAX_MAP_SIZE 12

DrawLeft::DrawLeft()
{
	font(15);
}

void DrawLeft::drawLeftManager(void)
{
	//Mapの表示
	drawMap();
	drawTilePoint();
}

void DrawLeft::drawMap(void) {
	Map * map;
	map = map->getMap();

	//マスの表示座標の補助
	const int pos_sup = MASU_SIZE + 5;

	map->Vertical = 12;
	map->Width = 12;
	//マップのタイルを表示（二重ループで縦横を管理）
	for (int i = 0; i < map->Vertical;i++) {
		for (int j = 0; j < map->Width; j++) {
			
			//Stateの状態に対して表示するマスの変更
			switch (map->board[i][j].Status) {
			case 0 :
				//draw non map
				Rect(j * pos_sup + 5 , i * pos_sup + 5 ,MASU_SIZE ,MASU_SIZE).draw(Palette::Gray);
				break;
			case 1 :
				//draw frined map
				Rect(j * pos_sup + 5, i * pos_sup + 5, MASU_SIZE, MASU_SIZE).draw(Palette::Blue);
				break;
			case 2 :
				//draw enemy map
				Rect(j * pos_sup + 5, i * pos_sup + 5, MASU_SIZE, MASU_SIZE).draw(Palette::Red);
				break;
			case 3 :
				Rect(j * pos_sup + 5, i * pos_sup + 5, MASU_SIZE, MASU_SIZE).draw(Palette::Black);
				break;
			default:
				break;

			}
		}
	}

	//タイルの枠を表示
	for (int i = 0; i <= MAX_MAP_SIZE; i++) {
		//縦ラインの表示
		Line(2.5, 2.5 + i * pos_sup , MAX_MAP_SIZE * pos_sup, 2.5 + i * pos_sup).draw(5 , Palette::Black);
		//縦ラインの表示
		Line(2.5 + i * pos_sup, 2.5 , 2.5 + i * pos_sup, MAX_MAP_SIZE * pos_sup).draw(5 , Palette::Black);
	}
	//System::Update();
}

void DrawLeft::drawAgent(void)
{
	//Mapに重ねてAgent位置の表示(両方)
}

void DrawLeft::drawTilePoint(void)
{
	//TilePointをMapに重ねる形で表示
	Map *map;
	map = map->getMap();

	int pos_sup = MASU_SIZE + 5;

	for (int i = 0; i < map->Vertical; i++) {
		for (int j = 0; j < map->Width; j++) {
			//Map外のタイルじゃないならTrue
			//Status Other : 3
			if (map->board[i][j].Status != 3) {
				//タイルポイントを表示
				font(map->board[i][j].TilePoint).draw(10 + pos_sup * j, 10 + pos_sup * i, Palette::Red);
			}
		}
	}
}

void DrawLeft::drawMovableTile(void)
{
	//自分のエージェントが移動出来る場所の表示
}