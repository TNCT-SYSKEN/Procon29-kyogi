#include "DrawMap.h"

DrawLeft drawLeft;
DrawRight drawRight;

void DrawMap::drawManager(void)
{
	//map�̉��n�A�^�C���|�C���g�A�G�[�W�F���g�̈ʒu�A�G�[�W�F���g�̈ړ��\�}�X�̕\��
	drawLeft.drawLeftManager();
	//���o�͌n��GUI�̕\��
	drawRight.drawRightManager();
}
