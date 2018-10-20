#include "SystemManager.h"

//クラス型変数の宣言
InputOutputManager ioManager;
AlgorithmManager algoManager;
ReadQR readQR;

void SystemManager::startSolver(void)
{
	//システムを開始する
	ReadQR *rqr;
	rqr = rqr->getReadQR();
	rqr->readQR();

	ioManager.init();
}

void SystemManager::endSolver(void)
{
	//システムを終了する条件
	//終わりのターン数に達した場合
	//Endが押された場合
}

void SystemManager::systemManager(void)
{
	
	//アルゴリズムとＩＯマネージャーを管理
	//ゲームの流れの管理する
	UpdateTurnInfo update;
	Setting *setting;
	setting = setting->getSetting();

	if (setting->turnFlag == true) {
		//そのターンのデータを保存＋ターン数を進める
		update.updateManager();
		//最善手を求める
		algoManager.algorithmManager();
		//最善手によって味方エージェントの移動先を表示する
		//敵の入力の受付
		//敵と味方の無効処理
		//敵の入力によって敵エージェントの位置を更新
		//ここまでの流れが終わったらturnFlagをtrueにする
	}
	ioManager.inputOuntputManager();
}

