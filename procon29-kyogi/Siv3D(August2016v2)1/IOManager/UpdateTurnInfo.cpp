#include "UpdateTurnInfo.h"

void UpdateTurnInfo::updateManager(void)
{
	//�^�[�����Ƃ̃f�[�^�̍X�V���s��
	//TurnManager->
}

//�e�^�[���̍ŏ��̃f�[�^��ۑ�
void UpdateTurnInfo::update()
{
}

//���i�����i�ۗ��j
void UpdateTurnInfo::goTurn(void)
{
}

//���݂�map.h , eva , setting.h�̒��g��1�^�[���O�̏���������
void UpdateTurnInfo::backTurn(void)
{
	//���݂̃f�[�^���擾
	Map *now_map;
	now_map = now_map->getMap();
	Evaluation *now_eva;
	now_eva = now_eva->getEvaluation();
	Setting *now_setting;
	now_setting = now_setting->getSetting();

	//1�^�[���O�̃f�[�^
	TurnManager *turnManager;
	turnManager = turnManager->getTurnManager();

	//����ȏ�߂�^�[���������ꍇ�͏��������s���Ȃ�
	if (now_map->Turn > 1) {
		//1�^�[���O�̃f�[�^����
		*now_eva = turnManager->eva[now_map->Turn - 1];
		*now_map = turnManager->map[now_map->Turn - 1];
		*now_setting = turnManager->setting[now_map->Turn - 1];
	}
}
