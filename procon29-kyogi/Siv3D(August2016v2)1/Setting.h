#pragma once
class Setting {
public:
	static Setting* getSetting();
	//������������s���邩�ǂ���1��0��ێ�
	int bruteForce = 0;
	int maxStep = 5;
private:
	static Setting* InsSetting;
};


