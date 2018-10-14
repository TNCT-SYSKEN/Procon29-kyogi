#include "DrawLeft.h"
#define MASU_SIZE 45
#define MAX_MAP_SIZE 12


DrawLeft::DrawLeft()
{
	font(15);
	//agent�̉摜�����[�h
	//Texture fri_ob(L"image/friend.png");
	//Texture ene_ob(L"image/enemy.png");
	//fri = fri_ob;
	//ene = ene_ob;
}

void DrawLeft::drawLeftManager(void)
{
	//Map�̕\��
	drawMap();
	drawTilePoint();
	drawAgent();
}

void DrawLeft::drawMap(void) {
	Map * map;
	map = map->getMap();

	//�}�X�̕\�����W�̕⏕
	const int pos_sup = MASU_SIZE + 5;

	map->Vertical = 12;
	map->Width = 12;
	//�}�b�v�̃^�C����\���i��d���[�v�ŏc�����Ǘ��j
	for (int i = 0; i < map->Vertical;i++) {
		for (int j = 0; j < map->Width; j++) {
			
			//State�̏�Ԃɑ΂��ĕ\������}�X�̕ύX
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

	//�^�C���̘g��\��
	for (int i = 0; i <= MAX_MAP_SIZE; i++) {
		//�c���C���̕\��
		Line(2.5, 2.5 + i * pos_sup , MAX_MAP_SIZE * pos_sup, 2.5 + i * pos_sup).draw(5 , Palette::Black);
		//�c���C���̕\��
		Line(2.5 + i * pos_sup, 2.5 , 2.5 + i * pos_sup, MAX_MAP_SIZE * pos_sup).draw(5 , Palette::Black);
	}
	//System::Update();
}

void DrawLeft::drawAgent(void)
{
	//Map�ɏd�˂�Agent�ʒu�̕\��(����)
	Map *map;
	map = map->getMap();
	int pos_sup = MASU_SIZE + 5;
	static Texture fri(L"image/friend.png");
	static Texture ene(L"image/enemy.png");

	for (int i = 0; i < map->agents.size(); i++) {
		switch (map->agents[i].Status) {
		case 0:
		case 1:
			//friend �̏ꍇ
			fri.draw(map->agents[i].position.second * pos_sup + 5 ,map->agents[i].position.first * pos_sup + 5);
			break;
		case 3 :
		case 4 :
			//enemy�̏ꍇ
			ene.draw(map->agents[i].position.second * pos_sup + 5 , map->agents[i].position.first * pos_sup + 5);
			break;
		default:
			break;
		}
	}
}

void DrawLeft::drawTilePoint(void)
{
	//TilePoint��Map�ɏd�˂�`�ŕ\��
	Map *map;
	map = map->getMap();

	int pos_sup = MASU_SIZE + 5;

	for (int i = 0; i < map->Vertical; i++) {
		for (int j = 0; j < map->Width; j++) {
			//Map�O�̃^�C������Ȃ��Ȃ�True
			//Status Other : 3
			if (map->board[i][j].Status != 3) {
				//�^�C���|�C���g��\��
				font(map->board[i][j].TilePoint).draw(10 + pos_sup * j, 10 + pos_sup * i, Palette::Red);
			}
		}
	}
}

void DrawLeft::drawMovableTile(void)
{
	//�����̃G�[�W�F���g���ړ��o����ꏊ�̕\��
}