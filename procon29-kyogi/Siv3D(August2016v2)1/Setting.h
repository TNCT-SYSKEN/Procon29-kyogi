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
	//�i�ߊ����ǂ���ɋ��邩
	//true:right false:left
	bool selectRL;
	vector< vector<int> > bruteForceResults;
	int params[5] = { 7, 4, 3, 3, 2 };//�d�݁D���ɁC�̈�_�C���`�[���̈͂݁C����`�[���̈͂݁C�G�[�W�F���g�ԋ����C���R�x
private:
	static Setting* InsSetting;
};