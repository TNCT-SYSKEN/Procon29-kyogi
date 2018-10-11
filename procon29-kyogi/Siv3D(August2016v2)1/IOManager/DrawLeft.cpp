#include "DrawLeft.h"
#define MASU_SIZE 45
#define MAX_MAP_SIZE 12
void DrawLeft::drawLeftManager(void)
{
	//Map�̕\��
	drawMap();
}

void DrawLeft::drawMap(void) {
	Map * map;
	map = map->getMap();

	//�}�`�̏�����
	const int pos_sup = MASU_SIZE + 5;
	//�g
	const Rect flame(0,0, LEFT_FLAME_VERTICAL, LEFT_FLAME_WIDTH);
	flame.draw();
	//const Texture texture(L"image/1.jpg");
	//texture.draw();
	map->Vertical = 12;
	map->Width = 12;
	//�}�b�v�̃^�C����\���i��d���[�v�ŏc�����Ǘ��j
	for (int i = 0; i < map->Vertical;i++) {
		for (int j = 0; j < map->Width; j++) {
			
			//State�̏�Ԃɑ΂��ĕ\������}�X�̕ύX
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

	//�^�C���̘g��\��
	for (int i = 0; i <= map->Vertical; i++) {
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
}

void DrawLeft::drawMovableTile(void)
{
	//�����̃G�[�W�F���g���ړ��o����ꏊ�̕\��
}