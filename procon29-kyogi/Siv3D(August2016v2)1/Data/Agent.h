#pragma once
#include "../gneral.h"

class Agent {
public :
	static Agent* getAgent();
	//�G�[�W�F���g�����̃^�[���ɂ����ē����ׂ��ŏI�I�ȍ��W
	pair <int, int> lastPosition = make_pair(0, 0);
	//�G�[�W�F���g�̌��݈ʒu
	pair <int, int> position = make_pair(0, 0);
	//�ǂ̃G�[�W�F���g��
	enum EnemyNumber { friend1, friend2, enemy1, enemy2 };
private:
	//nullptr�ŏ������p�̉B���R���X�g���N�^
	//Agent();
	//�I�u�W�F�N�g
	static Agent *InsAgent;
};
