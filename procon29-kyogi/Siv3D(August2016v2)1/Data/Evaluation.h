#pragma once
//���Ӕ��ߖT
#define AroundEight 8

class  Evaluation{
public:
	//���v�_�ɂ��]���_
	int SumScore[AroundEight*2];
	//�^�C���ɂ��]���_
	int TileScore[AroundEight*2];
	//���ߖT�̈ړ��\�}�X
	int Movable[AroundEight*2];

	static Evaluation* Evaluation::getEvaluation();
private:
	static Evaluation *InsEvaluation;

};