#include "SystemManager.h"

//�N���X�^�ϐ��̐錾
InputOutputManager ioManager;
AlgorithmManager algoManager;
ReadQR readQR;

void SystemManager::startSolver(void)
{
	//�V�X�e�����J�n����
	ReadQR *rqr;
	rqr = rqr->getReadQR();
	rqr->readQR();

	ioManager.init();
}

void SystemManager::endSolver(void)
{
	//�V�X�e�����I���������
	//�I���̃^�[�����ɒB�����ꍇ
	//End�������ꂽ�ꍇ
}

void SystemManager::systemManager(void)
{
	
	//�A���S���Y���Ƃh�n�}�l�[�W���[���Ǘ�
	//�Q�[���̗���̊Ǘ�����
	UpdateTurnInfo update;
	Interrupt inter;
	DrawLeft drawLeft;
	AgentManager agentManager;
	Map *map;
	map = map->getMap();
	Setting *setting;
	setting = setting->getSetting();
	
	if (setting->turnFlag == true) {
		update.updateManager(); //���̃^�[���̃f�[�^��ۑ��{�^�[������i�߂�
		algoManager.algorithmManager(); //�őP������߂�
		drawLeft.drawLeftManager();    //�őP��ɂ���Ė����G�[�W�F���g�̈ړ����\������
		inter.inputEnemyMovePos();   //�G�̌��n�̓��͂̎�t
		agentManager.decideAgentAct();  //�G�Ɩ����̌��n�ɂ���Ď��ɍs���s���̌���
		agentManager.agentMoveManager(); //�G�[�W�F���g�����ۂɍs������
		drawLeft.drawLeftManager();      //�s����̏�Ԃ�\��
		System::Update();
		map->agents[2].nextPosition.first;
		map->agents[2].nextPosition.second;
		//�����܂ł̗��ꂪ�I�������turnFlag��true�ɂ���
		setting->turnFlag = false;
	}
	ioManager.inputOuntputManager();
}

