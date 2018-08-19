#include "MapClass/Map.h"

Map* Map::InsMap = nullptr;
Map* Map::getMap() {
	if (InsMap == nullptr) {
		InsMap = new Map;
	}
	return InsMap;
}