#include "DrawLeft.h"

void DrawLeft::drawLeftManager(void)
{
	//Map�̕\��
	drawMap();
}

void DrawLeft::drawMap(void) {
	map = map->getMap();

	//�g
	const Rect flame(0,0, LEFT_FLAME_VERTICAL, LEFT_FLAME_WIDTH);

	//vertical,width�œ�d���[�v���쐬
	for (int i = 0; i < map->Vertical;i++) {
		for (int j = 0; j < map->Width; j++) {
			//���g��null����Ȃ��Ȃ��
			switch (map->board[i][j].State) {
			case 0 :
				//draw non map
				break;
			case 1 :
				//darw frined map
				break;
			case 2 :
				//draw enemy map
				break;
			default:
				break;

			}
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