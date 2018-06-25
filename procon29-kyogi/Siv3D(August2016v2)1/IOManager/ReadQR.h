#pragma once
#define Heghit 20
#define Width 20

class ReadQR {
public:
	char readQR(void);
private:
	char MapData[Heghit][Width];
	int TilePoint[Heghit][Width];
};