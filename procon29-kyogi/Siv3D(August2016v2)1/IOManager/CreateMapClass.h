#pragma once
#include "ReadQR.h"
#include "../Data/Map.h"
#include "../Data/Masu.h"
#include "string"
#include "../gneral.h"
#include "../Setting.h"

class CreateMapClass {
public:
	void init(void);
	bool createMapClass(void);
	static vector<string> splitStringByCoron(const string &s);
	static vector<int> splitStringBySpace(const string &s);
private:
	void createMasuClass(void);
	void createAgent(void);
};