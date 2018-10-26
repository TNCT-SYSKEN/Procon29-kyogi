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

		//得点を計算する
		map->friendTileScore = 0; map->enemyTileScore = 0; map->friendAreaScore = 0; map->enemyAreaScore = 0;
		map->friendSumScore = 0; map->enemySumScore = 0;

		//タイル点を計算する
		for (int i = 0; i < map->Vertical; ++i) {
			for (int j = 0; j < map->Width; ++j) {
				Masu masu = map->board[i][j];
				if (masu.Status == Masu::FriendTile) {
					map->friendTileScore += masu.TilePoint;
				}
				else if (masu.Status == Masu::EnemyTile) {
					map->enemyTileScore += masu.TilePoint;
				}
			}
		}

		//領域点を計算する
		vector< vector<int> > Fvisited; //味方の囲み計算
		for (int i = 0; i <= map->Vertical + 1; ++i) {
			vector<int> v(map->Width + 2, 0);
			Fvisited.push_back(v);
		}

		vector < pair<Masu, pair<int, int> > > route;
		Prefetching::caluculateEncircle(route, 0, 0, Fvisited, Masu::FriendTile);
		Prefetching::caluculateEncircle(route, map->Width + 1, map->Vertical + 1, Fvisited, Masu::FriendTile);

		for (int u = 1; u <= map->Vertical; ++u) {
			for (int v = 1; v <= map->Width; ++v) {
				if (!Fvisited[u][v] && map->board[u][v].Status != Masu::FriendTile) {
					map->friendAreaScore += abs(map->board[u][v].TilePoint);
				}
			}
		}

		vector< vector<int> > Evisited; //敵の囲み計算
		for (int i = 0; i <= map->Vertical + 1; ++i) {
			vector<int> v(map->Width + 2, 0);
			Evisited.push_back(v);
		}

		Prefetching::caluculateEncircle(route, 0, 0, Evisited, Masu::EnemyTile);
		Prefetching::caluculateEncircle(route, map->Width + 1, map->Vertical + 1, Evisited, Masu::EnemyTile);

		for (int u = 1; u <= map->Vertical; ++u) {
			for (int v = 1; v <= map->Width; ++v) {
				if (!Evisited[u-1][v-1] && map->board[u-1][v-1].Status != Masu::EnemyTile) {
					map->enemyAreaScore += abs(map->board[u-1][v-1].TilePoint);
				}
			}
		}

		map->friendSumScore = map->friendTileScore + map->friendAreaScore;
		map->enemySumScore = map->enemyTileScore + map->enemyAreaScore;

		//ここまでの流れが終わったらturnFlagをtrueにする
		setting->turnFlag = false;
	}
	ioManager.inputOuntputManager()
}

void SystemManager::endSolver(void)
{
	//システムを終了する条件
	//終わりのターン数に達した場合
	//Endが押された場合
}
