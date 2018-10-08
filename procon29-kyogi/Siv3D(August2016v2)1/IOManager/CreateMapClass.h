#pragma once
#include "ReadQR.h"
#include "../Data/Map.h"
#include "../Data/Masu.h"
#include "string"

class CreateMapClass {
public:
	void createMapClass(void);
	static std::vector<string> splitStringByCoron(const std::string &s);
	static std::vector<int> splitStringBySpace(const std::string &s);
private:
	void createMasuClass(void);
	void createAgent(void);
	std::string input;
};