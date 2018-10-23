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

	//nextPosによって移動できるどうか判断
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
			map->agents[i].canMoveNextPos = false;
		}
		else {
			map->agents[i].canMoveNextPos = true;
		}
		count = 0;
	}

	//移動先に敵のエージェントがいるかどうかの判定
	for (int i = 0; i < AGENTS; i++) {
		for (int j = 0; j < AGENTS; j++) {
			if (i != j) {
				//agent同士のnextPosを比較し、同じならcount++;
				if (map->agents[i].nextPosition.first == map->agents[j].position.first &&
					map->agents[i].nextPosition.second == map->agents[j].position.second) {
					map->agents[i].beAgent = true;
					map->agents[i].beAgentNum =j;
					break;
				}
				else {
					map->agents[i].beAgent = false;
				}
			}
		}
	}

	//タイル状況によって移動できるか判定
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
		if (map->agents[i].canMoveNextPos == true && map->agents[i].canMoveTile == false&&
			map->agents[i].beAgent == false) {
			map->agents[i].actAgent = Agent::move;
		}
	}
	/*
	//除去かどうか判定
	int x_pos;
	int y_pos;
	for (int i = 0; i < AGENTS; i++) {
		x_pos = map->agents[i].nextPosition.second;
		y_pos = map->agents[i].nextPosition.first;
		//移動先が被っていない
		//移動候補地に敵のタイルがある
		if (map->agents[i].canMoveNextPos == true && map->agents[i].canMoveTile == true) {
			//候補地に敵がいる
			if (map->agents[i].beAgent == true) {
				//その敵の候補地にそのエージェントとは違うタイルがない
				//その敵が移動できるならばerase
				if (map->agents[map->agents[i].beAgentNum].canMoveTile == false && 
					map->agents[map->agents[i].beAgentNum].canMoveNextPos == true) {
					map->agents[i].actAgent = Agent::erase;
				}
			}
			else {
				map->agents[i].actAgent = Agent::erase;
			}
			
		}
	}
	*/
	//停滞かどうか判定
	for (int i = 0; i < AGENTS;i++) {
		if (map->agents[i].Status != Agent::move) {
			if (map->agents[i].position.first == map->agents[i].nextPosition.first &&
				map->agents[i].position.second == map->agents[i].nextPosition.second) {
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
