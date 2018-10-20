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
	Setting *setting;
	setting = setting->getSetting();

	if (setting->turnFlag == true) {
		//���̃^�[���̃f�[�^��ۑ��{�^�[������i�߂�
		update.updateManager();
		//�őP������߂�
		algoManager.algorithmManager();
		//�őP��ɂ���Ė����G�[�W�F���g�̈ړ����\������
		//�G�̓��͂̎�t
		//�G�Ɩ����̖�������
		//�G�̓��͂ɂ���ēG�G�[�W�F���g�̈ʒu���X�V
		//�����܂ł̗��ꂪ�I�������turnFlag��true�ɂ���
	}
	ioManager.inputOuntputManager();
}

