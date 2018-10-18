#pragma once
#include "Masu.h"
#include "Agent.h"
#define TurnNumber 120
#define ValueOfAgent 2 
#define VERTICAL 12 
#define WIDTH 12

class Map {
public:
	static Map* getMap();
	//�c
	int Vertical;
	//��
	int Width;
	//�X�R�A���v
	int friendSumScore;
	int enemySumScore;
	//�^�C���|�C���g
	int friendTileScore;
	int enemyTileScore;
	//�̈�|�C���g
	int friendAreaScore;
	int enemyAreaScore;
	//�^�[����
	int Turn;
	//Masu��񎟌��z��Ŏ����Ă���
	Masu board[VERTICAL][WIDTH];
	//�G�[�W�F���g
	vector< Agent > agents;
private:
	static Map* InsMap;
};
