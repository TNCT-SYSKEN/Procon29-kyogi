#include "AddEvaluation.h"

//AgentNum �̓G�[�W�F���g�̔ԍ��D1��2
pair<int, int> AddEvaluation::addEvaluation(Agent agent, int agentNum)
{
	//JudgmentEncircle() , Prefetching()�ŕ]���_�t������
	//Judgment�ōŏI������肵Pair�ōŏI�I�Ȉʒu�ŕԂ��H

	//������8�ߖT�̊e�_�ɂ��ĕ]���_�����߁CEvaluation�ɓ˂����ށD���Ԃ͈ȉ��̔z��ɏ]���D
	int dy[] = { 1, 0, -1, 0 , 1, 1, -1, -1 };
	int dx[] = { 0, 1, 0, -1 , 1, -1, 1, -1 };
	Evaluation *evl;
	evl = evl->getEvaluation();

	Map *map;
	map = map->getMap();

	for (int i = 0; i < 16; ++i) {
		Prefetching prefetching;
		int newX = agent.position.second + dx[i % 8];
		int newY = agent.position.first + dy[i % 8];
		evl->SumScore[i] = -1;
		evl->TileScore[i] = -1;
		evl->Movable[i] = -1;
		if (newX >= 0 && newX < map->Width && newY >= 0 && newY < map->Vertical) {
			if ((map->board[newY][newX].Status == Masu::EnemyTile && i >= 8) || (map->board[newY][newX].Status == Masu::Non && i < 8)) {
				vector<int> ret = prefetching.prefetching(newX, newY, i >= 8);
				evl->SumScore[i] = ret[0];
				evl->TileScore[i] = ret[1];
				evl->Movable[i] = ret[2];
			}
		}
		JudgmentEncircle judgeEncircle;
		judgeEncircle.judgmentEncircle();
	}

	//Evaluation���󂯂ĕ]�����C�œK�Ȏ���o���D
	Judgment judge;
	pair<int, int> ansPosition = judge.judgment(*evl, (agentNum == 2) ? 1 : 0);

	return make_pair(agent.position.first + ansPosition.first , agent.position.second + ansPosition.second);
}
