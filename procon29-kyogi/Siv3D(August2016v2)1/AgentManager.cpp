#include "AgentManager.h"

void AgentManager::agentMoveManager()
{
	Map *map;
	map = map->getMap();

	//各エージェントの動作の読み出し
	for (int i = 0; i < AGENTS; i++) {
		switch (map->agents[i].actAgent) {
		case Agent::move :
			moveAgent(i);
			break;
		case Agent::erase :
			eraseAgent(i);
			break;
		case Agent::stagnation : 
			stayAgent(i);
			break;
		}
	}
}

void AgentManager::setAgentPos()
{
}

void AgentManager::setTurnFlag()
{
	Setting setting;
	//1ターンが終了したらの部分がtrueに置き換わる
	if (true) {
		setting.turnFlag = true;
	}
}

//敵と味方の無効処理
void AgentManager::checkAgentConflict()
{
	Map *map;
	map = map->getMap();

	int count = 0;

	//nextPosによって移動できるどうか判断ok
	for (int i = 0; i < AGENTS; i++) {
		for (int j = 0; j < AGENTS; j++) {
			//agent同士のnextPosを比較し、同じならcount++;
			if (map->agents[i].nextPosition.first == map->agents[j].nextPosition.first &&
				map->agents[i].nextPosition.second == map->agents[j].nextPosition.second) {
				count++;
			}
		}
		//最低一回は自分自身のnextPosと比較するため、count >=2ならばtrue
		if (count >= 2) {
			map->agents[i].canMoveNextPos = true;
		}
		else {
			map->agents[i].canMoveNextPos = false;
		}
		count = 0;
	}

	//移動先にエージェントがいるかどうかの判定ok
	for (int i = 0; i < AGENTS; i++) {
		map->agents[i].beAgent = false;
		for (int j = 0; j < AGENTS; j++) {
			if (i != j) {
				//agent同士のnextPosを比較し、同じならcount++;
				if (map->agents[i].nextPosition.first == map->agents[j].position.first &&
					map->agents[i].nextPosition.second == map->agents[j].position.second) {
					map->agents[i].beAgent = true;
					map->agents[i].beAgentNum =j;
					break;
				}
			}
		}
	}

	//タイル状況によって移動できるか判定ok
	for (int i = 0; i < AGENTS; i++) {
		//味方のエージェントの場合
		if (0 == i || 1 == i) {
			if (map->board[map->agents[i].nextPosition.first][map->agents[i].nextPosition.second].Status == Masu::EnemyTile) {
				//そのマスに移動できないように
				map->agents[i].canMoveTile = true;
			}
			else {
				map->agents[i].canMoveTile = false;
			}
		}
		//敵エージェントの場合
		if (2 == i || 3 == i) {
			if (map->board[map->agents[i].nextPosition.first][map->agents[i].nextPosition.second].Status == Masu::FriendTile) {
				//そのマスに移動できないように
				map->agents[i].canMoveTile = true;
			}
			else {
				map->agents[i].canMoveTile = false;
			}
		}
	}

	//停滞を意思しているかどうかok
	for (int i = 0; i < AGENTS; i++){
		if (map->agents[i].position.first == map->agents[i].nextPosition.first &&
			map->agents[i].position.second == map->agents[i].nextPosition.second) {
			map->agents[i].doStagnation = true;
		}
		else {
			map->agents[i].doStagnation = false;
		}
	}
}

//エージェントの行う動きを決定
void AgentManager::decideAgentAct()
{
	Map *map;
	map = map->getMap();

	checkAgentConflict();

	//移動かどうか判定
	for (int i = 0; i < AGENTS; i++) {
		//移動先が被ってない
		//移動先に相手のタイルがない
		//移動先にエージェントがいない
		//停滞意思表示をしていない
		if (map->agents[i].canMoveNextPos == false &&
			map->agents[i].canMoveTile == false&&
			map->agents[i].beAgent == false&&
			map->agents[i].doStagnation == false) {
			map->agents[i].actAgent = Agent::move;
		}
	}
	
	//除去かどうか判定
	for (int i = 0; i < AGENTS; i++) {
		//移動先が被っていない
		//移動候補地に敵のタイルがある
		if (map->agents[i].canMoveNextPos == false &&
			map->agents[i].canMoveTile == true) {
			//候補地にエージェントがいる
			if (map->agents[i].beAgent == true) {
				//その敵が移動するならtrue
				if (map->agents[map->agents[i].beAgentNum].canMoveNextPos == false &&
					map->agents[map->agents[i].beAgentNum].canMoveTile == false &&
					map->agents[map->agents[i].beAgentNum].beAgent == false &&
					map->agents[map->agents[i].beAgentNum].doStagnation == false) {
					map->agents[i].actAgent = Agent::erase;
				}
			}
			else {
				map->agents[i].actAgent = Agent::erase;
			}
			
		}
	}
	
	//停滞かどうか判定
	for (int i = 0; i < AGENTS;i++) {
		if (map->agents[i].actAgent != Agent::erase&&map->agents[i].actAgent != Agent::move) {
			//移動先が被っている
			//移動先に相手のタイルがある
			//移動先にエージェントがいる
			//停滞意思表示をしている
			if (map->agents[i].beAgent == true ||
				map->agents[i].canMoveNextPos == true ||
				map->agents[i].canMoveTile == true ||
				map->agents[i].doStagnation == true) {
				//停滞：stagnation
				map->agents[i].actAgent = Agent::stagnation;
			}
		}
	}
}

//エージェントの移動
void AgentManager::moveAgent(int agentNum)
{
	Map *map;
	map = map->getMap();

	//候補地に移動
	map->agents[agentNum].position.first = map->agents[agentNum].nextPosition.first;
	map->agents[agentNum].position.second = map->agents[agentNum].nextPosition.second;
	//移動先にタイルを自チームのタイルを置く
	if (agentNum < 2) {
		//味方
		map->board[map->agents[agentNum].position.first][map->agents[agentNum].position.second].Status = Masu::FriendTile;
	}
	else {
		//敵
		map->board[map->agents[agentNum].position.first][map->agents[agentNum].position.second].Status = Masu::EnemyTile;
	}
}

//マスの除去
void AgentManager::eraseAgent(int agentNum)
{
	Map *map;
	map = map->getMap();
	
	//タイルを除去（何も置いてない状態に戻す）
	map->board[map->agents[agentNum].nextPosition.first][map->agents[agentNum].nextPosition.second].Status = Masu::Non;
}

//停滞処理
void AgentManager::stayAgent(int agentNum)
{
	Map *map;
	map = map->getMap();
	//停滞処理なので何もしない
	//次の移動場所に現在の位置を代入
	//map->agents[agentNum].nextPosition.first = map->agents[agentNum].position.first;
	//map->agents[agentNum].nextPosition.second = map->agents[agentNum].position.second;
}
