#pragma once
#define ReadVERTICAL 20
#define ReadWIDTH 20

class ReadQR {
public:
	char readQR(void);
private:
	char MapData[ReadVERTICAL][ReadWIDTH];
	int TilePoint[ReadVERTICAL][ReadWIDTH];
};