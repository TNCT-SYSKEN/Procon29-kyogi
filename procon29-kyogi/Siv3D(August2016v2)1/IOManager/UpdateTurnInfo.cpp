#include "UpdateTurnInfo.h"

void UpdateTurnInfo::updateManager(void)
{
	//ターンごとのデータの更新を行う
	//TurnManager->
}

//各ターンの最初のデータを保存
void UpdateTurnInfo::update()
{
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
	}
}
