#pragma once
class Setting {
public:
	static Setting* getSetting();
	//‘“–‚½‚è‚ğÀs‚·‚éF1
	//”èæ“Ç‚İF0
	int bruteForce = 0;
	int maxStep;
private:
	static Setting* InsSetting;
};


