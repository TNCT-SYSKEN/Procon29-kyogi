#pragma once
class Setting {
public:
	static Setting* getSetting();
	//������������s����F1
	//���I�ǂ݁F0
	int bruteForce;
	int maxStep;
	//true�Ȃ���s
	bool turnFlag;
private:
	static Setting* InsSetting;
};


