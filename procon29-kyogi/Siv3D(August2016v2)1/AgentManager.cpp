#include "AgentManager.h"

void AgentManager::agentMoveManager()
{
	Map *map;
	map = map->getMap();

	//�e�G�[�W�F���g�̓���̓ǂݏo��
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

	//nextPos�ɂ���Ĉړ��ł���ǂ������fok
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
			map->agents[i].canMoveNextPos = true;
		}
		else {
			map->agents[i].canMoveNextPos = false;
		}
		count = 0;
	}

	//�ړ���ɃG�[�W�F���g�����邩�ǂ����̔���ok
	for (int i = 0; i < AGENTS; i++) {
		map->agents[i].beAgent = false;
		for (int j = 0; j < AGENTS; j++) {
			if (i != j) {
				//agent���m��nextPos���r���A�����Ȃ�count++;
				if (map->agents[i].nextPosition.first == map->agents[j].position.first &&
					map->agents[i].nextPosition.second == map->agents[j].position.second) {
					map->agents[i].beAgent = true;
					map->agents[i].beAgentNum =j;
					break;
				}
			}
		}
	}

	//�^�C���󋵂ɂ���Ĉړ��ł��邩����ok
	for (int i = 0; i < AGENTS; i++) {
		//�����̃G�[�W�F���g�̏ꍇ
		if (0 == i || 1 == i) {
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

	//��؂��ӎv���Ă��邩�ǂ���ok
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

//�G�[�W�F���g�̍s������������
void AgentManager::decideAgentAct()
{
	Map *map;
	map = map->getMap();

	checkAgentConflict();

	//�ړ����ǂ�������
	for (int i = 0; i < AGENTS; i++) {
		//�ړ��悪����ĂȂ�
		//�ړ���ɑ���̃^�C�����Ȃ�
		//�ړ���ɃG�[�W�F���g�����Ȃ�
		//��؈ӎv�\�������Ă��Ȃ�
		if (map->agents[i].canMoveNextPos == false &&
			map->agents[i].canMoveTile == false&&
			map->agents[i].beAgent == false&&
			map->agents[i].doStagnation == false) {
			map->agents[i].actAgent = Agent::move;
		}
	}
	
	//�������ǂ�������
	for (int i = 0; i < AGENTS; i++) {
		//�ړ��悪����Ă��Ȃ�
		//�ړ����n�ɓG�̃^�C��������
		if (map->agents[i].canMoveNextPos == false &&
			map->agents[i].canMoveTile == true) {
			//���n�ɃG�[�W�F���g������
			if (map->agents[i].beAgent == true) {
				//���̓G���ړ�����Ȃ�true
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
	
	//��؂��ǂ�������
	for (int i = 0; i < AGENTS;i++) {
		if (map->agents[i].actAgent != Agent::erase&&map->agents[i].actAgent != Agent::move) {
			//�ړ��悪����Ă���
			//�ړ���ɑ���̃^�C��������
			//�ړ���ɃG�[�W�F���g������
			//��؈ӎv�\�������Ă���
			if (map->agents[i].beAgent == true ||
				map->agents[i].canMoveNextPos == true ||
				map->agents[i].canMoveTile == true ||
				map->agents[i].doStagnation == true) {
				//��؁Fstagnation
				map->agents[i].actAgent = Agent::stagnation;
			}
		}
	}
}

//�G�[�W�F���g�̈ړ�
void AgentManager::moveAgent(int agentNum)
{
	Map *map;
	map = map->getMap();

	//���n�Ɉړ�
	map->agents[agentNum].position.first = map->agents[agentNum].nextPosition.first;
	map->agents[agentNum].position.second = map->agents[agentNum].nextPosition.second;
	//�ړ���Ƀ^�C�������`�[���̃^�C����u��
	if (agentNum < 2) {
		//����
		map->board[map->agents[agentNum].position.first][map->agents[agentNum].position.second].Status = Masu::FriendTile;
	}
	else {
		//�G
		map->board[map->agents[agentNum].position.first][map->agents[agentNum].position.second].Status = Masu::EnemyTile;
	}
}

//�}�X�̏���
void AgentManager::eraseAgent(int agentNum)
{
	Map *map;
	map = map->getMap();
	
	//�^�C���������i�����u���ĂȂ���Ԃɖ߂��j
	map->board[map->agents[agentNum].nextPosition.first][map->agents[agentNum].nextPosition.second].Status = Masu::Non;
}

//��؏���
void AgentManager::stayAgent(int agentNum)
{
	Map *map;
	map = map->getMap();
	//��؏����Ȃ̂ŉ������Ȃ�
	//���̈ړ��ꏊ�Ɍ��݂̈ʒu����
	//map->agents[agentNum].nextPosition.first = map->agents[agentNum].position.first;
	//map->agents[agentNum].nextPosition.second = map->agents[agentNum].position.second;
}
