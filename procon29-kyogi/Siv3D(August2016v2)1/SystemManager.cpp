#include "SystemManager.h"

//�N���X�ϐ��̒�`
AlgorithmManager algoManager;
InputOutputManager ioManager;

void SystemManager::startSolver(void)
{
	//�V�X�e�����J�n����
	algoManager.algorithmManager();
	ioManager.inputOuntputManager();
}

void SystemManager::endSolver(void)
{
	//�V�X�e�����I���������
	//�I���̃^�[�����ɒB�����ꍇ
	//End�������ꂽ�ꍇ
}

void SystemManager::systemManager(void)
{
	startSolver();
	/*
	�A���S���Y���Ƃh�n�}�l�[�W���[���Ǘ�
	startSolver���N��
	InputOutputManager���N��
	AlgorithmManager���N��
	endSolver���N��
	*/
}

