#pragma once
//Žü•Ó”ª‹ß–T
#define AroundEight 8

class  Evaluation{
public:
	//•]‰¿“_
	int Score[AroundEight];

	static Evaluation* Evaluation::getEvaluation();
private:
	static Evaluation *InsEvaluation;
};