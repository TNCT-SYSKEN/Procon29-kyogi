#pragma once
#include "../gneral.h"

class Agent {
public :
	//�G�[�W�F���g�����̃^�[���ɂ����ē����ׂ��ŏI�I�ȍ��W
	pair <int, int> lastPosition = make_pair(0, 0);
	//�G�[�W�F���g�̌��݈ʒu
	pair <int, int> position;
	//�ǂ̃G�[�W�F���g��
	enum EnemyNumber { friend1 = 0, friend2 = 1, enemy1 = 3, enemy2 = 4 };
private:
};
