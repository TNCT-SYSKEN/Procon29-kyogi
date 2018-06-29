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
	//æ“Ç‚İ‚Ì”ÍˆÍ‚ğXV
	void prefetchingInfo(void);
	//Ä“x’Tõ‚·‚é
	void Research(void);
};