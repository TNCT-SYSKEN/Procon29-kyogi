#pragma once
#include "Algorithm/AlgorithmManager.h"
#include "IOManager/InputOutputManager.h"

class SystemManager {
public:
	//�N���X�ϐ��̒�`
	AlgorithmManager *algoManager;
	InputOutputManager *ioManager;

	//�S�̗̂���̏������Ǘ�
	void systemManager(void);
private:
	//�J�n
	void startSolver(void);
	//�I�������𖞂�������v���O�����I��
	void endSolver(void);
};