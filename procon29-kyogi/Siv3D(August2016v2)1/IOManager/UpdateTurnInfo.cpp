#include "UpdateTurnInfo.h"

void UpdateTurnInfo::updateManager(void)
{
	//ターンごとのデータの更新を行う
	incrementTurn();
	update();
}

//各ターンの最初のデータを保存
void UpdateTurnInfo::update()
{
	//そのターンの情報をターンマネージャに保存
	//現在のデータを取得
	Map *now_map;
	now_map = now_map->getMap();
	Evaluation *now_eva;
	now_eva = now_eva->getEvaluation();
	Setting *now_setting;
	now_setting = now_setting->getSetting();

	TurnManager *turnManager;
	turnManager = turnManager->getTurnManager();

	//現在の情報をターンマネージャに保存
	turnManager->eva[now_map->Turn] = *now_eva;
	//turnManager->setting[now_map->Turn] = *now_setting;
	turnManager->map[now_map->Turn] = *now_map;
}

//一手進処理（保留）
void UpdateTurnInfo::goTurn(void)
{
}

//現在のmap.h , eva , setting.hの中身に1ターン前の情報を代入する
void UpdateTurnInfo::backTurn(void)
{
	//現在のデータを取得
	Map *now_map;
	now_map = now_map->getMap();
	Evaluation *now_eva;
	now_eva = now_eva->getEvaluation();
	Setting *now_setting;
	now_setting = now_setting->getSetting();

	//1ターン前のデータ
	TurnManager *turnManager;
	turnManager = turnManager->getTurnManager();

	//これ以上戻るターンが無い場合は処理を実行しない
	if (now_map->Turn > 1) {
		//1ターン前のデータを代入
		*now_eva = turnManager->eva[now_map->Turn - 1];
		*now_map = turnManager->map[now_map->Turn - 1];
		*now_setting = turnManager->setting[now_map->Turn - 1];
		now_map->Turn--;
	}
}

void UpdateTurnInfo::incrementTurn(void)
{
	Map *map;
	map = map->getMap();

	//ターン数をインクリメント
	map->Turn++;
}

//再探索処理
void UpdateTurnInfo::research(void)
{
	//現在のデータを取得
	Map *now_map;
	now_map = now_map->getMap();
	Evaluation *now_eva;
	now_eva = now_eva->getEvaluation();
	Setting *now_setting;
	now_setting = now_setting->getSetting();

	//その他必要なクラス型変数の宣言
	AlgorithmManager algo;
	TurnManager *turnManager;
	turnManager = turnManager->getTurnManager();

	//ターン始めののデータを代入
	*now_eva = turnManager->eva[now_map->Turn];
	//*now_setting = turnManager->setting[now_map->Turn];
	*now_map = turnManager->map[now_map->Turn];

	//アルゴリズムを動かす
	algo.algorithmManager();
}
