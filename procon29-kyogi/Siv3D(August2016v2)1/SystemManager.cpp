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
	algoManager.algorithmManager();
}

void SystemManager::endSolver(void)
{
	//�V�X�e�����I���������
	//�I���̃^�[�����ɒB�����ꍇ
	//End�������ꂽ�ꍇ
}

void SystemManager::systemManager(void)
{
	/*
	�A���S���Y���Ƃh�n�}�l�[�W���[���Ǘ�
	startSolver
	InputOutputManager���N��
	AlgorithmManager���N��
	endSolver���N��
	*/
	
	ioManager.inputOuntputManager();
}

