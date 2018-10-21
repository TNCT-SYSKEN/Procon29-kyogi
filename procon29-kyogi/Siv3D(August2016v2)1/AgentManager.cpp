#include "AgentManager.h"

void AgentManager::setAgentPos()
{
}

void AgentManager::setTurnFlag()
{
	Setting setting;
	//1�^�[�����I��������̕�����true�ɒu�������
	if (true) {
		setting.turnFlag = true;
	}
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

	//�ړ���ɓG�̃G�[�W�F���g�����邩�ǂ����̔���
	for (int i = 0; i < AGENTS; i++) {
		for (int j = 0; j < AGENTS; j++) {
			if (i != j) {
				//agent���m��nextPos���r���A�����Ȃ�count++;
				if (map->agents[i].nextPosition.first == map->agents[j].position.first &&
					map->agents[i].nextPosition.second == map->agents[j].position.second) {
					map->agents[i].beAgent = true;
					map->agents[i].beAgentNum =j;
				}
			}
		}
	}

	//�^�C���󋵂ɂ���Ĉړ��ł��邩����
	for (int i = 0; i < AGENTS; i++) {
		//�����̃G�[�W�F���g�̏ꍇ
		if (0 == i && 1 == i) {
			if (map->board[map->agents[i].nextPosition.first][map->agents[i].nextPosition.second].Status == Masu::EnemyTile) {
				//���̃}�X�Ɉړ��ł��Ȃ��悤��
				map->agents[i].canMoveTile = true;
			}
			else {
				map->agents[i].canMoveTile = false;
			}
		}
		//�G�G�[�W�F���g�̏ꍇ
		if (2 == i || 3 == i) {
			if (map->board[map->agents[i].nextPosition.first][map->agents[i].nextPosition.second].Status == Masu::FriendTile) {
				//���̃}�X�Ɉړ��ł��Ȃ��悤��
				map->agents[i].canMoveTile = true;
			}
			else {
				map->agents[i].canMoveTile = false;
			}
		}
	}
}

//�G�[�W�F���g�̍s������������
void AgentManager::decideAgentAct()
{
	Map *map;
	map = map->getMap();

	//�ړ����ǂ�������
	for (int i = 0; i < AGENTS; i++) {
		//�ړ��悪����ĂȂ�
		//�ړ���ɑ���̃^�C�����Ȃ�
		if (map->agents[i].canMoveNextPos == true && map->agents[i].canMoveTile == false) {
			map->agents[i].actAgent = Agent::move;
		}
	}

	//�������ǂ�������
	int x_pos;
	int y_pos;
	for (int i = 0; i < AGENTS; i++) {
		x_pos = map->agents[i].nextPosition.second;
		y_pos = map->agents[i].nextPosition.first;
		//�ړ��悪����Ă��Ȃ�
		//�ړ����n�ɓG�̃^�C��������
		if (map->agents[i].canMoveNextPos == true && map->agents[i].canMoveTile == true) {
			//���n�ɓG������
			if (map->agents[i].beAgent == true) {
				//���̓G�̌��n�ɂ��̃G�[�W�F���g�Ƃ͈Ⴄ�^�C�����Ȃ�
				//���̓G���ړ��ł���Ȃ��erase
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

	//��؂��ǂ�������
	for (int i = 0; i < AGENTS;i++) {
		if (map->agents[i].position.first == map->agents[i].nextPosition.first &&
			map->agents[i].position.second == map->agents[i].nextPosition.second) {
			//��؁Fstagnation
			map->agents[i].actAgent = Agent::stagnation;
		}
	}
}

//�G�[�W�F���g�̈ړ�
void AgentManager::moveAgent()
{
}

//�}�X�̍폜
void AgentManager::eraseAgent()
{
}

//��؏���
void AgentManager::stayAgent()
{
}
