#include "AddEvaluation.h"

//AgentNum �̓G�[�W�F���g�̔ԍ��D1��2
pair<int, int> AddEvaluation::addEvaluation(Agent agent, int agentNum, int *prms)
{
	Map *map;
	map = map->getMap();

	Prefetching pref;
	pref.evl_params[0] = prms[0];
	pref.evl_params[1] = prms[1];
	pref.evl_params[2] = prms[2];
	pref.evl_params[3] = prms[3];
	pref.evl_params[4] = prms[4];
	return pref.prefetching(agent, agentNum);
}
