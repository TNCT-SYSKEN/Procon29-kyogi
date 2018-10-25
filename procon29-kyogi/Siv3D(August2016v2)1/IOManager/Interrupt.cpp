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
	m_gui.add(L"research", GUIButton::Create(L"再探索"));
	m_gui.addln(L"start", GUIButton::Create(L"ターンの開始"));

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
	
	//Infomation
	m_gui.add(L"text10", GUIText::Create(L"Information", 80));
	m_gui.text(L"text10").style.color = Palette::Black;
	m_gui.addln(L"Info", GUITextArea::Create(4, 8));

	// 横幅の設定
	m_gui.style.width = 595;
	m_gui.style.showTitle = true;

}

void Interrupt::interruptManager(void)
{
	backTurn();
	//goTurn();
	prefetchingInfo();
	Research();
	start();
	selectAglo();
	drawSumScore();
	drawTileScore();
	drawAreaScore();
	drawTurn();
}

//1ターン戻る処理
void Interrupt::backTurn(void)
{
	UpdateTurnInfo update;
	//ターンを管理している変数の値を減らす・・？
	if (m_gui.button(L"backTurn").pushed) {
		update.backTurn();
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
	UpdateTurnInfo update;

	if (m_gui.button(L"research").pushed) {
		update.research();
	}
}

void Interrupt::start()
{
	Setting *setting;
	setting = setting->getSetting();

	if (m_gui.button(L"start").pushed) {
		setting->turnFlag = true;
	}
}

//全探索と数手先読みのどちらを行うかの選択
void Interrupt::selectAglo()
{
	Setting *setting;
	setting = setting->getSetting();

	//true 数手先読み
	//false 全探索
	if (m_gui.toggleSwitch(L"switchAlgo").isRight) {
		setting->bruteForce = 1;
	}
	else{
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
	Map *map;
	map = map->getMap();

	//siv3d::Stringの宣言
	String Turn;

	//int -> std::string -> siv3d::Stringに変換
	Turn = Widen(to_string(map->Turn));

	m_gui.textArea(L"Turn").setText(Turn);
}

//情報を表示
void Interrupt::drawInfo()
{
	
}

//敵の移動候補地の入力
void Interrupt::inputEnemyMovePos()
{
	Map *map;
	map = map->getMap();
	DrawLeft drawLeft;

	bool roopBreak = false;
	//マスの表示座標の補助
	const int pos_sup = MASU_SIZE + 5;
	
	//敵エージェントだけ参照
	for (int k = 2; k <= 3; k++) {
		String text = Format(L"EnemyAgent[", k - 1, L"]の移動先をクリックしてください");
		m_gui.textArea(L"Info").setText(text);
		System::Update();
		while (System::Update()) {
			if (Input::MouseL.clicked) {
				const Point pos = Mouse::Pos();
				int count = 0;
				for (int i = 0; i < 12;i++) {
					//x軸が位置でいうとどこなのか
					if (5 + pos_sup * i < pos.x&&pos.x < pos_sup * (i + 1)) {
						map->agents[k].nextPosition.second = i;
						count++;
					}
					//y軸が位置で言うとどこなのか
					if (5 + pos_sup * i < pos.y&&pos.y < pos_sup * (i + 1)) {
						map->agents[k].nextPosition.first = i;
						count++;
					}
				}
				//x , y両方nextPosが代入されたか確認
				if (count == 2) {
					roopBreak = true;
				}
			}
			//draw left map
			drawLeft.drawLeftManager();
			if (roopBreak) {
				break;
			}
		}
		roopBreak = false;
	}

	m_gui.textArea(L"Info").setText(L"敵エージェントの位置入力が完了しました。");
	System::Update();
}
