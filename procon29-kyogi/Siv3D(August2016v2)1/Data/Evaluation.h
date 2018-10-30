#pragma once
//周辺八近傍
#define AroundEight 8

class  Evaluation{
public:
	//合計点による評価点
	int SumScore[AroundEight*2];
	//タイルによる評価点
	int TileScore[AroundEight*2];
	//八近傍の移動可能マス
	int Movable[AroundEight*2];

	static Evaluation* Evaluation::getEvaluation();
private:
	static Evaluation *InsEvaluation;

};