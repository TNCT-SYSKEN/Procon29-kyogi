#include "SystemManager.h"

InputOutputManager *ioManager;

void SystemManager::startSolver(void)
{
	//�N���X�ϐ��̒�`
	//AlgorithmManager *algoManager;



	//�V�X�e�����J�n����
	//algoManager->algorithmManager();
	ioManager->inputOuntputManager();
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
	startSolver();
}

