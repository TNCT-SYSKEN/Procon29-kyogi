#pragma once
#include "ReadQR.h"
#include "../Data/Map.h"
#include "../Data/Masu.h"
#include "string"
#include "../gneral.h"

class CreateMapClass {
public:
	void init(void);
	bool createMapClass(void);
	static std::vector<string> splitStringByCoron(const std::string &s);
	static std::vector<int> splitStringBySpace(const std::string &s);
private:
	void createMasuClass(void);
	void createAgent(void);
};