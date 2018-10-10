#pragma once
#include "../Data/Map.h"
#include "../Data/Agent.h"
#include "../gneral.h"

#define LEFT_FLAME_WIDTH 610
#define LEFT_FLAME_VERTICAL 810

Map * map;
Agent * agent;

class DrawLeft {
public:
	void drawLeftManager(void);
private:

	void drawMap(void);
	void drawAgent(void);
	void drawTilePoint(void);
	void drawMovableTile(void);
}; 