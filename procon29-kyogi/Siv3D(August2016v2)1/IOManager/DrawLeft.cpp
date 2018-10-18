#include "DrawLeft.h"
#define MASU_SIZE 45
#define MAX_MAP_SIZE 12


DrawLeft::DrawLeft()
{
	font(15);
	//agentの画像をロード
	//Texture fri_ob(L"image/friend.png");
	//Texture ene_ob(L"image/enemy.png");
	//fri = fri_ob;
	//ene = ene_ob;
}

void DrawLeft::drawLeftManager(void)
{
	//Mapの表示
	drawMap();
	drawTilePoint();
	drawAgent();
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
			case Masu::Non:
				//draw non map
				Rect(j * pos_sup + 5 , i * pos_sup + 5 ,MASU_SIZE ,MASU_SIZE).draw(Palette::Gray);
				break;
			case Masu::FriendTile :
				//draw frined map
				Rect(j * pos_sup + 5, i * pos_sup + 5, MASU_SIZE, MASU_SIZE).draw(Palette::Skyblue);
				break;
			case Masu::EnemyTile :
				//draw enemy map
				Rect(j * pos_sup + 5, i * pos_sup + 5, MASU_SIZE, MASU_SIZE).draw(Palette::Lightpink);
				break;
			case Masu::Other :
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
	Map *map;
	map = map->getMap();
	int pos_sup = MASU_SIZE + 5;
	//picture agent
	static Texture fri1(L"image/friend1.png");
	static Texture fri2(L"image/friend2.png");
	static Texture ene1(L"image/enemy1.png");
	static Texture ene2(L"image/enemy2.png");

	for (int i = 0; i < map->agents.size(); i++) {
		switch (map->agents[i].Status) {
		case Agent::friend1:
			fri1.draw(map->agents[i].position.second * pos_sup + 5, map->agents[i].position.first * pos_sup + 5);
			break;
		case Agent::friend2:
			//friend の場合
			fri2.draw(map->agents[i].position.second * pos_sup + 5 ,map->agents[i].position.first * pos_sup + 5);
			break;
		case Agent::enemy1 :
			ene1.draw(map->agents[i].position.second * pos_sup + 5, map->agents[i].position.first * pos_sup + 5);
			break;
		case Agent::enemy2 :
			//enemyの場合
			ene2.draw(map->agents[i].position.second * pos_sup + 5 , map->agents[i].position.first * pos_sup + 5);
			break;
		default:
			break;
		}
	}
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
			if (map->board[i][j].Status != Masu::Other) {
				//タイルポイントを表示
				font(map->board[i][j].TilePoint).draw(10 + pos_sup * j, 10 + pos_sup * i, Palette::Yellow);
			}
		}
	}
}

void DrawLeft::drawMovableTile(void)
{
	//自分のエージェントが移動出来る場所の表示
}