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
	//æ“Ç‚İ‚Ì”ÍˆÍ‚ğXV
	void prefetchingInfo(void);
	//Ä“x’Tõ‚·‚é
	void Research(void);
};