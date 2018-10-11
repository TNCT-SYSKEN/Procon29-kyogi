#pragma once
#include "../Data/Map.h"
#include "../Data/Agent.h"
#include "../gneral.h"

#define LEFT_FLAME_WIDTH 1200
#define LEFT_FLAME_VERTICAL 600


class DrawLeft {
public:
	void drawLeftManager(void);
private:

	void drawMap(void);
	void drawAgent(void);
	void drawTilePoint(void);
	void drawMovableTile(void);
}; 