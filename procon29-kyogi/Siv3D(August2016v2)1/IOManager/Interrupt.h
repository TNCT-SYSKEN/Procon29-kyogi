#pragma once
#include "../Data/Map.h"
#include "../Data/Evaluation.h"
#include "../gneral.h"
#include <string>
#include "../GUI.h"
#include "../Setting.h"
#include "../Algorithm/AlgorithmManager.h"

class Interrupt {
public:
	Interrupt();
	GUI m_gui;
	void interruptManager(void);
private:
	void backTurn(void);
	void goTurn(void);
	//æ“Ç‚İ‚Ì”ÍˆÍ‚ğXV
	void prefetchingInfo(void);
	//Ä“x’Tõ‚·‚é
	void Research(void);
	void selectAglo();
	void drawScore();
};
