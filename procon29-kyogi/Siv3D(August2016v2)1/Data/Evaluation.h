#pragma once
//���Ӕ��ߖT
#define AroundEight 8

class  Evaluation{
public:
	static Evaluation* getEvaluation();
	//���v�_�ɂ��]���_
	int SumScore[AroundEight];
	//�^�C���ɂ��]���_
	int TileScore[AroundEight];
	//���ߖT�̈ړ��\�}�X
	int Movable[AroundEight];
};