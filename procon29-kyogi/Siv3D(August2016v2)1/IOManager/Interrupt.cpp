#include "Interrupt.h"

void Interrupt::interruptManager(void)
{
	eva.SumScore;
	backTurn();
	goTurn();
	prefetchingInfo();
	Research();
}

void Interrupt::backTurn(void)
{
	//1ターン戻る処理
	//ターンを管理している変数の値を減らす・・？
}

void Interrupt::goTurn(void)
{
	
}

void Interrupt::prefetchingInfo(void)
{
	//どこまで先読むかの数を読み込み
	//Mapクラスの中を書き換え・・・？
}

void Interrupt::Research(void)
{
	//同じターンにおいて探索アルゴリズムを再度動かす
}
