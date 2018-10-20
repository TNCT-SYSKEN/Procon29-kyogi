#pragma once
class Setting {
public:
	static Setting* getSetting();
	//総当たりを実行する：1
	//数的読み：0
	int bruteForce;
	int maxStep;
	//trueなら実行
	bool turnFlag;
private:
	static Setting* InsSetting;
};


