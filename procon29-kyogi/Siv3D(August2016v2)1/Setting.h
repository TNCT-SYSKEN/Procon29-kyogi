#pragma once
#include "gneral.h"
class Setting {
public:
	static Setting* getSetting();
	//������������s����F1
	//�����ǂ݁F0
	int bruteForce = 0;
	int maxStep;
	//true�Ȃ���s
	bool turnFlag;
	vector< vector<int> > bruteForceResults;
private:
	static Setting* InsSetting;
};