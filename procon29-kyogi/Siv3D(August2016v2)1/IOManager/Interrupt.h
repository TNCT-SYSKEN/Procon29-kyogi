#pragma once
#include "../MapClass/Map.h"
#include "../MapClass/Evaluation.h"

class Interrupt {
public:
	Evaluation eva;
	void interruptManager(void);
private:
	void backTurn(void);
	void goTurn(void);
	//��ǂ݂͈̔͂��X�V
	void prefetchingInfo(void);
	//�ēx�T������
	void Research(void);
};