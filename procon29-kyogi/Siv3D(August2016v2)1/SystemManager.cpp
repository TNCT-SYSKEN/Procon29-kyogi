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
	Map *map;
	map = map->getMap();
	map->agents[0].nextPosition.first = 1;
	map->agents[0].nextPosition.second = 0;

	map->agents[1].nextPosition.first = 1;
	map->agents[1].nextPosition.second = 2;
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
	Interrupt inter;
	DrawLeft drawLeft;
	AgentManager agentManager;
	Map *map;
	map = map->getMap();
	Setting *setting;
	setting = setting->getSetting();

	if (setting->turnFlag == true) {
		update.updateManager(); //そのターンのデータを保存＋ターン数を進める
		algoManager.algorithmManager(); //最善手を求める
		drawLeft.drawLeftManager();    //最善手によって味方エージェントの移動先を表示する
		inter.inputEnemyMovePos();   //敵の候補地の入力の受付
		agentManager.decideAgentAct();  //敵と味方の候補地によって次に行う行動の決定
		agentManager.agentMoveManager(); //エージェントが実際に行動する
		drawLeft.drawLeftManager();      //行動後の状態を表示
		System::Update();

		//ここまでの流れが終わったらturnFlagをtrueにする
		setting->turnFlag = false;
	}
	ioManager.inputOuntputManager();
}