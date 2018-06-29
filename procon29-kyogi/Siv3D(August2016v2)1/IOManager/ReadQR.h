#pragma once
#define VERTICAL 20
#define WIDTH 20

class ReadQR {
public:
	char readQR(void);
private:
	char MapData[VERTICAL][WIDTH];
	int TilePoint[VERTICAL][WIDTH];
};