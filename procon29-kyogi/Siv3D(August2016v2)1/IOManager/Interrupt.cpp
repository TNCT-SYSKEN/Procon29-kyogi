#include "Interrupt.h"

Interrupt::Interrupt()
	: m_gui(GUIStyle::Default)
{
	m_gui.setPos(605, 0);

	// 水平線
	m_gui.add(L"hr", GUIHorizontalLine::Create(1));
	m_gui.horizontalLine(L"hr").style.color = Color(127);
	// Title Input
	m_gui.add(GUIText::Create(L"Input"));
	// 水平線
	m_gui.add(L"hr", GUIHorizontalLine::Create(1));
	m_gui.horizontalLine(L"hr").style.color = Color(127);

	// ボタン
	m_gui.add(L"bt1", GUIButton::Create(L"一手進む"));
	m_gui.add(L"bt2", GUIButton::Create(L"一手戻る"));
	m_gui.addln(L"bt3", GUIButton::Create(L"再探索"));

	// 先読み深度読み取り
	m_gui.add(L"tf1", GUITextField::Create(3));
	m_gui.addln(L"sl1", GUISlider::Create(0, 100, 0, 200));

	// 全探索、数手先選択
	m_gui.add(L"ts1", GUIToggleSwitch::Create(L"全探索", L"数手先読み", false));

	// 水平線
	m_gui.add(L"hr", GUIHorizontalLine::Create(1));
	m_gui.horizontalLine(L"hr").style.color = Color(127);

	//タイトル：スコア
	m_gui.add(GUIText::Create(L"Score"));
	
	// 水平線
	m_gui.add(L"hr", GUIHorizontalLine::Create(1));
	m_gui.horizontalLine(L"hr").style.color = Color(127);

	// スコア表示
	//赤チーム合計スコア
	m_gui.add(L"text1", GUIText::Create(L"赤得点:",60));
	m_gui.text(L"text1").style.color = Palette::Red;
	m_gui.add(L"ta1", GUITextArea::Create(1, 10));

	//青チーム合計スコア
	m_gui.add(L"text2", GUIText::Create(L"青得点:", 60));
	m_gui.text(L"text2").style.color = Palette::Blue;
	m_gui.addln(L"ta2", GUITextArea::Create(1, 10));

	//赤チームタイルスコア
	m_gui.add(L"text3", GUIText::Create(L"赤タイル:", 80));
	m_gui.text(L"text3").style.color = Palette::Red;
	m_gui.add(L"ta3", GUITextArea::Create(1, 5));
	
	//青チームタイル
	m_gui.add(L"text4", GUIText::Create(L"赤タイル:",80));
	m_gui.text(L"text4").style.color = Palette::Blue;
	m_gui.add(L"ta4", GUITextArea::Create(1, 5));

	// 水平線
	m_gui.add(L"hr", GUIHorizontalLine::Create(1));
	m_gui.horizontalLine(L"hr").style.color = Color(127);

	//Other表示
	m_gui.add(GUIText::Create(L"Other"));

	// 水平線
	m_gui.add(L"hr", GUIHorizontalLine::Create(1));
	m_gui.horizontalLine(L"hr").style.color = Color(127);
	
	// 横幅の設定
	m_gui.style.width = 595;
	m_gui.style.showTitle = true;

}

void Interrupt::interruptManager(void)
{
	//backTurn();
	//goTurn();
	prefetchingInfo();
	Research();
	selectAglo();
	drawScore();
}

void Interrupt::backTurn(void)
{
	//1ターン戻る処理
	//ターンを管理している変数の値を減らす・・？
	if (m_gui.button(L"bt2").pushed) {

	}
}

void Interrupt::goTurn(void)
{
	//1ターン進む
	if (m_gui.button(L"bt1").pushed) {

	}
}

void Interrupt::prefetchingInfo(void)
{
	//どこまで先読むかの数を読み込み
	//Mapクラスの中を書き換え・・・？
	Setting *setting;
	setting = setting->getSetting();
	
	// スライダーが変化したら、数値を変更する
	if (m_gui.slider(L"sl1").hasChanged)
	{
		m_gui.textField(L"tf1").setText(Format(m_gui.slider(L"sl1").value));
	}
	// 数値が変化したら、スライダーを変更する
	if (m_gui.textField(L"tf1").hasChanged)
	{
		m_gui.slider(L"sl1").setValue(Parse<double>(m_gui.textField(L"tf1").text));
	}

	//深度の深さを受け付け
	if (m_gui.textField(L"tf1").hasChanged) {
		setting->maxStep = Parse<int>(m_gui.textField(L"tf1").text);
	}
}

void Interrupt::Research(void)
{
	AlgorithmManager algo;

	//同じターンにおいて探索アルゴリズムを再度動かす
	if (m_gui.button(L"bt3").pushed) {
		algo.algorithmManager();
	}
}

void Interrupt::selectAglo()
{
	Setting *setting;
	setting = setting->getSetting();

	//true 数手先読み
	//false 全探索
	if (m_gui.toggleSwitch(L"ts1").enabled == false) {
		setting->bruteForce = 1;
	}
	else if (m_gui.toggleSwitch(L"ts1").enabled == true) {
		setting->bruteForce = 0;
	}
}

void Interrupt::drawScore()
{
	Map *map;
	map = map->getMap();

	//siv3d::Stringの宣言
	String friendSumScore;
	String enemySumScore;

	//int -> std::string -> siv3d::Stringに変換
	friendSumScore = Widen(to_string(map->friendSumScore));
	enemySumScore = Widen(to_string(map->enemySumScore));

	//draw sumScore
	m_gui.textArea(L"ta1").setText(friendSumScore);
	m_gui.textArea(L"ta2").setText(friendSumScore);
}
