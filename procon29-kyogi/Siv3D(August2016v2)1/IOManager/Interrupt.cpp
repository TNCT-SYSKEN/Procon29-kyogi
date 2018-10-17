#include "Interrupt.h"

Interrupt *Interrupt::InsInterrupt = nullptr;

Interrupt *Interrupt::getInterrupt()
{
	if (InsInterrupt == nullptr) {
		InsInterrupt = new Interrupt;
	}
	return InsInterrupt;
}

void Interrupt::interruptManager(void)
{
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
	//1ターン進む

}

void Interrupt::prefetchingInfo(void)
{
	//どこまで先読むかの数を読み込み
	//Mapクラスの中を書き換え・・・？
	//GUIの宣言
	static GUI gui(GUIStyle::Default);

	gui.setPos(605, 0);
	gui.add(GUIText::Create(L"Input"));
	gui.addln(GUIButton::Create(L"hoge"));

	gui.add(GUINewLine::Create());
}

void Interrupt::Research(void)
{
	//同じターンにおいて探索アルゴリズムを再度動かす
}
