#include "DrawMap.h"

DrawLeft * drawLeft;
DrawRight * drawRight;

void DrawMap::drawManager(void)
{
	drawLeft->drawLeftManager();
	//drawRight->drawRightManager();
}
