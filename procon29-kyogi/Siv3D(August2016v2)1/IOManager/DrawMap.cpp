#include "DrawMap.h"

DrawLeft drawLeft;
DrawRight drawRight;

void DrawMap::drawManager(void)
{
	//mapの下地、タイルポイント、エージェントの位置、エージェントの移動可能マスの表示
	drawLeft.drawLeftManager();
	//入出力系のGUIの表示
	drawRight.drawRightManager();
}
