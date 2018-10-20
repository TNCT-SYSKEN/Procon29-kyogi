#include "AgentManager.h"

void AgentManager::setAgentPos()
{
}

void AgentManager::setTurnFlag()
{
}

//�G�Ɩ����̖�������
void AgentManager::checkAgentConflict()
{
	Map *map;
	map = map->getMap();

	int count = 0;

	//nextPos�ɂ���Ĉړ��ł���ǂ������f
	for (int i = 0; i < AGENTS; i++) {
		for (int j = 0; j < AGENTS; j++) {
			//agent���m��nextPos���r���A�����Ȃ�count++;
			if (map->agents[i].nextPosition.first == map->agents[j].nextPosition.first &&
				map->agents[i].nextPosition.second == map->agents[j].nextPosition.second) {
				count++;
			}
		}
		//�Œ���͎������g��nextPos�Ɣ�r���邽�߁Acount >=2�Ȃ��true
		if (count >= 2) {
			map->agents[i].canMoveNextPos = false;
		}
		else {
			map->agents[i].canMoveNextPos = true;
		}
		count = 0;
	}

	//�^�C���󋵂ɂ���Ĉړ��ł��邩����
	for (int i = 0; i < AGENTS; i++) {
		//�����̃G�[�W�F���g�̏ꍇ
		if (0 == i && 1 == i) {
			if (map->board[map->agents[i].nextPosition.first][map->agents[i].nextPosition.second].Status == Masu::EnemyTile) {
				//���̃}�X�Ɉړ��ł��Ȃ��悤��
				map->agents[i].canMoveTile = false;
			}
			else {
				map->agents[i].canMoveTile = true;
			}
		}
		//�G�G�[�W�F���g�̏ꍇ
		if (2 == i || 3 == i) {
			if (map->board[map->agents[i].nextPosition.first][map->agents[i].nextPosition.second].Status == Masu::FriendTile) {
				//���̃}�X�Ɉړ��ł��Ȃ��悤��
				map->agents[i].canMoveTile = false;
			}
			else {
				map->agents[i].canMoveTile = true;
			}
		}
	}
}
