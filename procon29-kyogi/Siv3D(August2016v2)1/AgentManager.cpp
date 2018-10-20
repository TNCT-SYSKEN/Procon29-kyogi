#include "AgentManager.h"

void AgentManager::setAgentPos()
{
}

void AgentManager::setTurnFlag()
{
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

	//タイル状況によって移動できるか判定
	for (int i = 0; i < AGENTS; i++) {
		//味方のエージェントの場合
		if (0 == i && 1 == i) {
			if (map->board[map->agents[i].nextPosition.first][map->agents[i].nextPosition.second].Status == Masu::EnemyTile) {
				//そのマスに移動できないように
				map->agents[i].canMoveTile = false;
			}
			else {
				map->agents[i].canMoveTile = true;
			}
		}
		//敵エージェントの場合
		if (2 == i || 3 == i) {
			if (map->board[map->agents[i].nextPosition.first][map->agents[i].nextPosition.second].Status == Masu::FriendTile) {
				//そのマスに移動できないように
				map->agents[i].canMoveTile = false;
			}
			else {
				map->agents[i].canMoveTile = true;
			}
		}
	}
}
