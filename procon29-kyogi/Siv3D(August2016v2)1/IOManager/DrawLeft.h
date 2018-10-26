#pragma once
#include "../Data/Map.h"
#include "../Data/Agent.h"
#include "../gneral.h"
#include "../Setting.h"

#define LEFT_FLAME_WIDTH 1200
#define LEFT_FLAME_VERTICAL 605


class DrawLeft {
public:
	DrawLeft();
	void drawLeftManager(void);
	//最善手を表示するエージェントはどれなのかを渡す
	void drawBestTile(int);
private:
	Font font;
	void drawMap(void);
	void drawAgent(void);
	void drawTilePoint(void);
	void drawMovableTile(void);
	void drawNextPosition(void);
}; 