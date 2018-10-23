#pragma once
#include "gneral.h"
class Setting {
public:
	static Setting* getSetting();
	//総当たりを実行する：1
	//数手先読み：0
	int bruteForce = 0;
	int maxStep;
	//trueなら実行
	bool turnFlag;
	vector< vector<int> > bruteForceResults;
private:
	static Setting* InsSetting;
};