#include "UpdateTurnInfo.h"

void UpdateTurnInfo::updateManager(void)
{
	//�^�[�����Ƃ̃f�[�^�̍X�V���s��
	incrementTurn();
	update();
}

//�e�^�[���̍ŏ��̃f�[�^��ۑ�
void UpdateTurnInfo::update()
{
	//���̃^�[���̏����^�[���}�l�[�W���ɕۑ�
	//���݂̃f�[�^���擾
	Map *now_map;
	now_map = now_map->getMap();
	Evaluation *now_eva;
	now_eva = now_eva->getEvaluation();
	Setting *now_setting;
	now_setting = now_setting->getSetting();

	TurnManager *turnManager;
	turnManager = turnManager->getTurnManager();

	//���݂̏����^�[���}�l�[�W���ɕۑ�
	turnManager->eva[now_map->Turn] = *now_eva;
	//turnManager->setting[now_map->Turn] = *now_setting;
	turnManager->map[now_map->Turn] = *now_map;
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
		now_map->Turn--;
	}
}

void UpdateTurnInfo::incrementTurn(void)
{
	Map *map;
	map = map->getMap();

	//�^�[�������C���N�������g
	map->Turn++;
}

//�ĒT������
void UpdateTurnInfo::research(void)
{
	//���݂̃f�[�^���擾
	Map *now_map;
	now_map = now_map->getMap();
	Evaluation *now_eva;
	now_eva = now_eva->getEvaluation();
	Setting *now_setting;
	now_setting = now_setting->getSetting();

	//���̑��K�v�ȃN���X�^�ϐ��̐錾
	AlgorithmManager algo;
	TurnManager *turnManager;
	turnManager = turnManager->getTurnManager();

	//�^�[���n�߂̂̃f�[�^����
	*now_eva = turnManager->eva[now_map->Turn];
	//*now_setting = turnManager->setting[now_map->Turn];
	*now_map = turnManager->map[now_map->Turn];

	//�A���S���Y���𓮂���
	algo.algorithmManager();
}
