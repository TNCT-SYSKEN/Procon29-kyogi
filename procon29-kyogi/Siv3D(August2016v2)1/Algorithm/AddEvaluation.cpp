#include "AddEvaluation.h"

pair<int, int> AddEvaluation::addEvaluation(Agent agent)
{
	//JudgmentEncircle() , Prefetching()�ŕ]���_�t������
	//Judgment�ōŏI������肵Pair�ōŏI�I�Ȉʒu�ŕԂ��H

	//������8�ߖT�̊e�_�ɂ��ĕ]���_�����߁CEvaluation�ɓ˂����ށD���Ԃ͈ȉ��̔z��ɏ]���D
	int dy[] = { 1, 0, -1, 0 , 1, 1, -1, -1};
	int dx[] = { 0, 1, 0, -1 , 1, -1, 1, -1 };
	Evaluation evl;

	for (int i = 0; i < 8; ++i) {
		Prefetching prefetching;
		int newX = agent.position.second + dx[i];
		int newY = agent.position.first + dy[i];
		Map *map;
		map = map->getMap();
		if (newX >= 0 && newX < map->Width && newY >= 0 && newY < map->Vertical) {
			vector<int> ret = prefetching.prefetching(newX, newY);
			evl.SumScore[i] = ret[0]; evl.TileScore[i] = ret[1]; evl.Movable[i] = ret[2];
		}
		JudgmentEncircle judgeEncircle;
		judgeEncircle.judgmentEncircle();
	}

	//Evaluation���󂯂ĕ]�����C�œK�Ȏ���o���D
	Judgment judge;
	pair<int, int> ansPosition = judge.judgment(evl);

	return make_pair(agent.position.first + ansPosition.first , agent.position.second + ansPosition.second);
}