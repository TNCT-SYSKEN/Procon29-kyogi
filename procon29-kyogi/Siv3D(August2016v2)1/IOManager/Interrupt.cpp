#include "Interrupt.h"

Interrupt::Interrupt()
	: m_gui(GUIStyle::Default)
{
	m_gui.setPos(605, 0);

	// 水平線
	// Title Input
	// 水平線
	m_gui.add(L"hr", GUIHorizontalLine::Create(1));
	m_gui.horizontalLine(L"hr").style.color = Color(127);
	m_gui.add(GUIText::Create(L"Input"));
	m_gui.add(L"hr", GUIHorizontalLine::Create(1));
	m_gui.horizontalLine(L"hr").style.color = Color(127);

	// ボタン
	m_gui.add(L"goTurn", GUIButton::Create(L"一手進む"));
	m_gui.add(L"backTurn", GUIButton::Create(L"一手戻る"));
	m_gui.addln(L"research", GUIButton::Create(L"再探索"));

	// 先読み深度読み取り
	m_gui.add(L"text0", GUIText::Create(L"先読み深度"));
	m_gui.add(L"prefetchingTF", GUITextField::Create(3));
	m_gui.addln(L"prefetchingSL", GUISlider::Create(0, 100, 0, 200));

	// 全探索、数手先選択
	m_gui.add(L"switchAlgo", GUIToggleSwitch::Create(L"全探索", L"数手先読み", false));

	// 水平線
	//タイトル：スコア
	// 水平線
	m_gui.add(L"hr", GUIHorizontalLine::Create(1));
	m_gui.horizontalLine(L"hr").style.color = Color(127);
	m_gui.add(GUIText::Create(L"Score"));
	m_gui.add(L"hr", GUIHorizontalLine::Create(1));
	m_gui.horizontalLine(L"hr").style.color = Color(127);

	// スコア表示
	//赤チーム合計スコア
	m_gui.add(L"text1", GUIText::Create(L"赤得点　:",80));
	m_gui.text(L"text1").style.color = Palette::Red;
	m_gui.add(L"enemySumScore", GUITextArea::Create(1, 5));
	//青チーム合計スコア
	m_gui.add(L"text2", GUIText::Create(L"青得点　:", 80));
	m_gui.text(L"text2").style.color = Palette::Blue;
	m_gui.addln(L"friendSumScore", GUITextArea::Create(1, 5));

	//赤チームタイルスコア
	m_gui.add(L"text3", GUIText::Create(L"赤タイル:", 80));
	m_gui.text(L"text3").style.color = Palette::Red;
	m_gui.add(L"enemyTileScore", GUITextArea::Create(1, 5));
	//青チームタイル
	m_gui.add(L"text4", GUIText::Create(L"青タイル:",80));
	m_gui.text(L"text4").style.color = Palette::Blue;
	m_gui.addln(L"friendTileScore", GUITextArea::Create(1, 5));

	//赤チーム領域スコア
	m_gui.add(L"text5", GUIText::Create(L"赤エリア:", 80));
	m_gui.text(L"text5").style.color = Palette::Red;
	m_gui.add(L"enemyAreaScore", GUITextArea::Create(1, 5));
	//青チーム領域スコア
	m_gui.add(L"text6", GUIText::Create(L"青エリア:", 80));
	m_gui.text(L"text6").style.color = Palette::Blue;
	m_gui.addln(L"friendAreaScore", GUITextArea::Create(1, 5));

	// 水平線
	//Other表示
	// 水平線
	m_gui.add(L"hr", GUIHorizontalLine::Create(1));
	m_gui.horizontalLine(L"hr").style.color = Color(127);
	m_gui.add(GUIText::Create(L"Other"));
	m_gui.add(L"hr", GUIHorizontalLine::Create(1));
	m_gui.horizontalLine(L"hr").style.color = Color(127);
	
	//ターン数を表示
	m_gui.add(L"text9", GUIText::Create(L"ターン数:", 80));
	m_gui.text(L"text9").style.color = Palette::Black;
	m_gui.addln(L"Turn", GUITextArea::Create(1, 5));

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
	drawSumScore();
	drawTileScore();
	drawAreaScore();
}

//1ターン戻る処理
void Interrupt::backTurn(void)
{
	//ターンを管理している変数の値を減らす・・？
	if (m_gui.button(L"backTurn").pushed) {

	}
}

//1ターン進む
void Interrupt::goTurn(void)
{
	if (m_gui.button(L"goTurn").pushed) {

	}
}

//どこまで先読むかの数を読み込み
void Interrupt::prefetchingInfo(void)
{
	//Mapクラスの中を書き換え・・・？
	Setting *setting;
	setting = setting->getSetting();
	
	// スライダーが変化したら、数値を変更する
	if (m_gui.slider(L"prefetchingSL").hasChanged)
	{
		m_gui.textField(L"prefetchingTF").setText(Format(m_gui.slider(L"prefetchingSL").value));
	}
	// 数値が変化したら、スライダーを変更する
	if (m_gui.textField(L"prefetchingTF").hasChanged)
	{
		m_gui.slider(L"prefetchingSL").setValue(Parse<double>(m_gui.textField(L"prefetchingTF").text));
	}

	//深度の深さを受け付け
	if (m_gui.textField(L"prefetchingTF").hasChanged) {
		setting->maxStep = Parse<int>(m_gui.textField(L"prefetchingTF").text);
	}
}

//同じターンにおいて探索アルゴリズムを再度動かす
void Interrupt::Research(void)
{
	AlgorithmManager algo;

	if (m_gui.button(L"research").pushed) {
		algo.algorithmManager();
	}
}

//全探索と数手先読みのどちらを行うかの選択
void Interrupt::selectAglo()
{
	Setting *setting;
	setting = setting->getSetting();

	//true 数手先読み
	//false 全探索
	if (m_gui.toggleSwitch(L"switchAlgo").enabled == false) {
		setting->bruteForce = 1;
	}
	else if (m_gui.toggleSwitch(L"switchAlgo").enabled == true) {
		setting->bruteForce = 0;
	}
}

//スコア合計を表示
void Interrupt::drawSumScore()
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
	m_gui.textArea(L"friendSumScore").setText(friendSumScore);
	m_gui.textArea(L"enemySumScore").setText(enemySumScore);
}

//タイルスコアの表示
void Interrupt::drawTileScore()
{
	Map *map;
	map = map->getMap();

	//siv3d::Stringの宣言
	String friendTileScore;
	String enemyTileScore;

	//int -> std::string -> siv3d::Stringに変換
	friendTileScore = Widen(to_string(map->friendTileScore));
	enemyTileScore = Widen(to_string(map->enemyTileScore));

	//draw sumScore
	m_gui.textArea(L"friendTileScore").setText(friendTileScore);
	m_gui.textArea(L"enemyTileScore").setText(enemyTileScore);
}

//領域スコアの表示
void Interrupt::drawAreaScore()
{
	Map *map;
	map = map->getMap();

	//siv3d::Stringの宣言
	String friendAreaScore;
	String enemyAreaScore;

	//int -> std::string -> siv3d::Stringに変換
	friendAreaScore = Widen(to_string(map->friendAreaScore));
	enemyAreaScore = Widen(to_string(map->enemyAreaScore));

	//draw sumScore
	m_gui.textArea(L"friendAreaScore").setText(friendAreaScore);
	m_gui.textArea(L"enemyAreaScore").setText(enemyAreaScore);
}

//ターン数を表示
void Interrupt::drawTurn()
{
}
