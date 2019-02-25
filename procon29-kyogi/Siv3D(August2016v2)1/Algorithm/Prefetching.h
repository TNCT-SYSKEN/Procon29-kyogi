#pragma once
#include "../Data/Map.h"
#include "../Data/Masu.h"
#include "../Setting.h"
#include "../gneral.h"
#include "Candidate.h"
#include <vector>
#include <queue>
#define INF 1e09
#define SEARCH_DEPTH 2

class Prefetching {
public:
	pair<int, int> prefetching(Agent);
	int evl(Candidate);
	static void caluculateEncircle(vector<pair<Masu, pair<int, int>>> route, int nowX, int nowY, vector< vector<int> >& visited, Masu::StateOfMasu);
	static bool isVisited(vector<pair<Masu, pair<int, int>>> route, int newX, int newY, Masu::StateOfMasu st) {
		for (pair<Masu, pair<int, int>> p : route) {
			if (newX == p.second.first && newY == p.second.second  && p.first.Status != (st == Masu::EnemyTile ? Masu::FriendTile : Masu::EnemyTile)) return true;
		}
		return false;
	}
private:

};