#pragma once
#include "../gneral.h"

class Agent {
public :
	//�G�[�W�F���g�����̃^�[���ɂ����ē����ׂ��ŏI�I�ȍ��W
	pair <int, int> nextPosition;
	bool canMoveNextPos;
	bool camMoveTile;
	//�G�[�W�F���g����������^�C���̍��W
	pair <int, int> erasePosition;
	//�G�[�W�F���g�̌��݈ʒu
	pair <int, int> position;
	//�G�[�W�F���g���s���s��
	enum actAgent{
		//���
		stagnation = 0,
		//�ړ�
		move = 1,
		//�^�C������
		erase = 2
	};
	actAgent actAgent;
	//�ǂ̃G�[�W�F���g��
	enum EnemyNumber { friend1 = 0, friend2 = 1, enemy1 = 3, enemy2 = 4 };
	EnemyNumber Status;
private:
};
