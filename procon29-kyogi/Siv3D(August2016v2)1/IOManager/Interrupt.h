#pragma once
#include "../Data/Map.h"
#include "../Data/Evaluation.h"

class Interrupt {
public:
	static Interrupt *getInterrupt();
	void interruptManager(void);
private:
	static Interrupt *InsInterrupt;
	void backTurn(void);
	void goTurn(void);
	//��ǂ݂͈̔͂��X�V
	void prefetchingInfo(void);
	//�ēx�T������
	void Research(void);
};