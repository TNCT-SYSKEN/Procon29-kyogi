#pragma once
#include "Algorithm/AlgorithmManager.h"
#include "IOManager/InputOutputManager.h"
#include "IOManager/DrawMap.h"
#include "AgentManager.h"

class SystemManager {
public:
	//�S�̗̂���̏������Ǘ�
	void systemManager(void);
	void startSolver(void);
private:

	//�J�n

	//�I�������𖞂�������v���O�����I��
	void endSolver(void);
};