#pragma once
class Setting {
public:
	static Setting* getSetting();
	//������������s����F1
	//�����ǂ݁F0
	int bruteForce = 0;
	int maxStep = 5;
private:
	static Setting* InsSetting;
};


