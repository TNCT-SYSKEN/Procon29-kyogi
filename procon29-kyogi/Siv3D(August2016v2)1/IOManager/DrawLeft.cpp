#include "DrawLeft.h"
#define MASU_SIZE 45
#define MAX_MAP_SIZE 12
void DrawLeft::drawLeftManager(void)
{
	//Mapの表示
	drawMap();
}

void DrawLeft::drawMap(void) {
	Map * map;
	map = map->getMap();

	//図形の初期化
	const int pos_sup = MASU_SIZE + 5;
	//枠
	const Rect flame(0,0, LEFT_FLAME_VERTICAL, LEFT_FLAME_WIDTH);
	flame.draw();
	//const Texture texture(L"image/1.jpg");
	//texture.draw();
	map->Vertical = 12;
	map->Width = 12;
	//マップのタイルを表示（二重ループで縦横を管理）
	for (int i = 0; i < map->Vertical;i++) {
		for (int j = 0; j < map->Width; j++) {
			
			//Stateの状態に対して表示するマスの変更
			switch (0){//map->board[i][j].State) {
			case 0 :
				//draw non map
				Rect(j * pos_sup + 5 , i * pos_sup + 5 ,MASU_SIZE ,MASU_SIZE).draw(Palette::Gray);
				break;
			case 1 :
				//darw frined map
				Rect(j * pos_sup + 5, i * pos_sup + 5, MASU_SIZE, MASU_SIZE).draw(Palette::Blue);
				break;
			case 2 :
				//draw enemy map
				Rect(j * pos_sup + 5, i * pos_sup + 5, MASU_SIZE, MASU_SIZE).draw(Palette::Red);
				break;
			default:
				break;

			}
		}
	}

	//タイルの枠を表示
	for (int i = 0; i <= map->Vertical; i++) {
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
}

void DrawLeft::drawMovableTile(void)
{
	//自分のエージェントが移動出来る場所の表示
}