#pragma
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
	//�X�R�A���v(�c���G�[�W�F���g�̋��,�����e�^�[�����Ƃ̓_����ۑ�
	int SumScore[ValueOfAgent][TurnNumber];
	//�^�[����
	int Turn;
	//Masu��񎟌��z��Ŏ����Ă���
	Masu board[VERTICAL][WIDTH];
private:
	static Map* InsMap;
};
