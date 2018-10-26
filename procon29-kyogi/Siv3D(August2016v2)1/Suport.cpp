#include "Suport.h"
#include "Setting.h"
#include "Data/Map.h"
#define AGENTS 4

//�ړ��ʒu�ɂ���ĕ⏕�\��
void Suport::suportOfficer()
{
	Map *map;
	map = map->getMap();
	Setting *setting;
	setting = setting->getSetting();

	//�i�ߊ����E�Ȃ�g��
	int ry[] = { -1, 0, 1, 1, 1, 0, -1, -1};
	int rx[] = { 1, 1, 1, 0, -1, -1, -1, 0};
	//�i�ߊ������Ȃ�g��
	int ly[] = { 1, 0, -1, -1, -1, 0, 1, 1};
	int lx[] = { -1, -1, -1, 0, 1, 1, 1, 0};

	for (int i = 0;i < AGENTS;i++){
		for (int j = 0; j < 8; j++) {
			if (setting->selectRL) {
				//true:right
				if (map->agents[i].nextPosition.first == (map->agents[i].position.first + ry[j])&&
					map->agents[i].nextPosition.second == (map->agents[i].position.second + rx[j])) {
					map->agents[i].suportNum = j + 1;
				}
			}
			else {
				if (map->agents[i].nextPosition.first == (map->agents[i].position.first + ly[j]) &&
					map->agents[i].nextPosition.second == (map->agents[i].position.second + lx[j])) {
					map->agents[i].suportNum = j + 1;
				}
			}
		}
	}
}