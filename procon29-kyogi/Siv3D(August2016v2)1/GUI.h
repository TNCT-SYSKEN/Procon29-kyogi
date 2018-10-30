#pragma once
#include "gneral.h"

class GuI {
public:
	static GuI *getGuI();
	GUI gui;
private:
	static GuI *InsGUI;
};