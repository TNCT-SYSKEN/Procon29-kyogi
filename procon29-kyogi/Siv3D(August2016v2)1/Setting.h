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
	//司令官がどちらに居るか
	//true:right false:left
	bool selectRL;
	vector< vector<int> > bruteForceResults;
	int params[5] = { 7, 4, 3, 3, 2 };//重み．順に，領域点，自チームの囲み，相手チームの囲み，エージェント間距離，自由度
private:
	static Setting* InsSetting;
};