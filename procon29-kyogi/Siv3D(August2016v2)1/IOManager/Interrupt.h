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
	//先読みの範囲を更新
	void prefetchingInfo(void);
	//再度探索する
	void Research(void);
};