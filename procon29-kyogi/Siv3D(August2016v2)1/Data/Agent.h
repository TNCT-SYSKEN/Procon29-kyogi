#pragma once
#include "../gneral.h"

class Agent {
public :
	//�G�[�W�F���g�����̃^�[���ɂ����ē����ׂ��ŏI�I�ȍ��W
	pair <int, int> nextPosition;
	//�ړ��悪���̃G�[�W�F���g����Ă���
	bool canMoveNextPos;
	//�ړ���ɂĂ��̂����邪����
	bool canMoveTile;
	//�ړ��悪�G�[�W�F���g������
	bool beAgent;
	//��؂��ӎv�\�����Ă���
	bool doStagnation;
	int beAgentNum;
	//�ړ���̐���
	int suportNum;
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
