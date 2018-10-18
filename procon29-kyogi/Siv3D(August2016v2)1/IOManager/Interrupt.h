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
	//��ǂ݂͈̔͂��X�V
	void prefetchingInfo(void);
	//�ēx�T������
	void Research(void);
	void selectAglo();
	void drawScore();
};
