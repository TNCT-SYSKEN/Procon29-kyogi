#pragma once
class Setting {
public:
	static Setting* getSetting();
	//������������s���邩�ǂ���1��0��ێ�
	int bruteForce = 0;
private:
	static Setting* InsSetting;
};


