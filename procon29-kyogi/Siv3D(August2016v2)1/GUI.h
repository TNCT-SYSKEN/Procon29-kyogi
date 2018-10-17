#pragma once
#include "gneral.h"

class GuI {
public:
	static GuI *getGuI();
private:
	GUI inter_gui;
	static GuI *InsGUI;
};