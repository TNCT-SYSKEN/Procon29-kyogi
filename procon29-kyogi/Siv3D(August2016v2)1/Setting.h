#pragma once
class Setting {
public:
	static Setting* getSetting();
	//������������s����F1
	//�����ǂ݁F0
	int bruteForce = 0;
	int maxStep;
private:
	static Setting* InsSetting;
};


