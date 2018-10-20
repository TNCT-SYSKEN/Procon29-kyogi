#pragma once
#include <string>
#include <Siv3D.hpp>
#define ReadVERTICAL 20
#define ReadWIDTH 20

class ReadQR {
public:
	static ReadQR* getReadQR();
	void readQR(void);
	string data = "nothing";
private:
	char MapData[ReadVERTICAL][ReadWIDTH];
	int TilePoint[ReadVERTICAL][ReadWIDTH];
	static ReadQR* InsReadQR;
};