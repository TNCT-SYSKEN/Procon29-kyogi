#include "DrawLeft.h"
#define MASU_SIZE 45
#define MAX_MAP_SIZE 12

DrawLeft::DrawLeft()
{
	font(15);
}

void DrawLeft::drawLeftManager(void)
{
	//Map�̕\��
	drawMap();
	drawTilePoint();
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