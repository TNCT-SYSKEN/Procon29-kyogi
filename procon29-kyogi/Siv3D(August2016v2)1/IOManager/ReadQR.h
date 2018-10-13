#pragma once
#include <string>
#define ReadVERTICAL 20
#define ReadWIDTH 20

class ReadQR {
public:
	std::string readQR(void);
private:
	char MapData[ReadVERTICAL][ReadWIDTH];
	int TilePoint[ReadVERTICAL][ReadWIDTH];
};