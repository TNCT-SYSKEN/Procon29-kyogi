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
	//Agent�N���X,Masu�N���X���܂Ƃ߂�z���p�ӂ����
}

void CreateMapClass::createMasuClass(void)
{
	//�ǂݎ�������e�����Ɗe�G�[�W�F���g�N���X���쐬
}

void CreateMapClass::createAgent(void)
{
	//�ǂݎ�������e�����ƂɊe�}�X�N���X���쐬
}
