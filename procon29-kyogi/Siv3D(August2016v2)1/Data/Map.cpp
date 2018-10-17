#include "Map.h"

Map* Map::InsMap = nullptr;
Map* Map::getMap() {
	if (InsMap == nullptr) {
		InsMap = new Map;
		for (int j = 0; j < VERTICAL; ++j) {
			for (int i = 0; i < WIDTH; ++i) {
				Masu masu;
				masu.TilePoint = 0;
				masu.Status = Masu::Non;
				InsMap->board[j][i] = masu;
			}
		}
	}
	return InsMap;
}