#pragma once
class Setting {
public:
	static Setting* getSetting();
	//総当たりを実行する：1
	//数手先読み：0
	int bruteForce = 0;
	int maxStep;
private:
	static Setting* InsSetting;
};


