#pragma once
#include "../gneral.h"

class Agent {
public :
	//�G�[�W�F���g�����̃^�[���ɂ����ē����ׂ��ŏI�I�ȍ��W
	pair <int, int> lastPosition = make_pair(0, 0);
	//�G�[�W�F���g�̌��݈ʒu
	pair <int, int> position = make_pair(0, 0);
	//�ǂ̃G�[�W�F���g��
	enum EnemyNumber { friend1, friend2, enemy1, enemy2 };
private:
};
