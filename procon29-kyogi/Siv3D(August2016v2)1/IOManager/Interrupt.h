#pragma once
//#include "../MapClass/Map.h"
#include "../Data/Evaluation.h"

class Interrupt {
public:
	void interruptManager(void);
private:
	void backTurn(void);
	void goTurn(void);
	//æ“Ç‚İ‚Ì”ÍˆÍ‚ğXV
	void prefetchingInfo(void);
	//Ä“x’Tõ‚·‚é
	void Research(void);
};