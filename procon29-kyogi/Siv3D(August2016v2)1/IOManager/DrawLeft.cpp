#include "DrawLeft.h"

void DrawLeft::drawLeftManager(void)
{
	//Map�̕\��
	drawMap();
}

void DrawLeft::drawMap(void) {
	Map *map;
	map = map->getMap();
	//�g
	const Rect flame(0,0, LEFT_FLAME_VERTICAL, LEFT_FLAME_WIDTH);

	//vertical,width�œ�d���[�v���쐬
	for (int i = 0; i < map->Vertical;i++) {
		for (int j = 0; j < map->Width; j++) {
			
		}
	}
}

void DrawLeft::drawAgent(void)
{
	//Map�ɏd�˂�Agent�ʒu�̕\��(����)
}

void DrawLeft::drawTilePoint(void)
{
	//TilePoint��Map�ɏd�˂�`�ŕ\��
}

void DrawLeft::drawMovableTile(void)
{
	//�����̃G�[�W�F���g���ړ��o����ꏊ�̕\��
}