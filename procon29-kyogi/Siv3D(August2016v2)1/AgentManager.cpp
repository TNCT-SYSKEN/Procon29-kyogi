#include "AgentManager.h"

void AgentManager::setAgentPos()
{
}

void AgentManager::setTurnFlag()
{
}

//“G‚Æ–¡•û‚Ì–³Œøˆ—
void AgentManager::checkAgentConflict()
{
	Map *map;
	map = map->getMap();

	int count = 0;

	//nextPos‚É‚æ‚Á‚ÄˆÚ“®‚Å‚«‚é‚Ç‚¤‚©”»’f
	for (int i = 0; i < AGENTS; i++) {
		for (int j = 0; j < AGENTS; j++) {
			//agent“¯Žm‚ÌnextPos‚ð”äŠr‚µA“¯‚¶‚È‚çcount++;
			if (map->agents[i].nextPosition.first == map->agents[j].nextPosition.first &&
				map->agents[i].nextPosition.second == map->agents[j].nextPosition.second) {
				count++;
			}
		}
		//Å’áˆê‰ñ‚ÍŽ©•ªŽ©g‚ÌnextPos‚Æ”äŠr‚·‚é‚½‚ßAcount >=2‚È‚ç‚Îtrue
		if (count >= 2) {
			map->agents[i].canMoveNextPos = false;
		}
		else {
			map->agents[i].canMoveNextPos = true;
		}
		count = 0;
	}
}
