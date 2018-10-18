#include "GUI.h"

GuI *GuI::InsGUI = nullptr;

GuI *GuI::getGuI()
{
	if (InsGUI == nullptr) {
		InsGUI = new GuI;
	}
	return InsGUI;
}