#pragma once
#include "../Data/Map.h"
#include "../Data/Masu.h"
#include "../Setting.h"
#include "../gneral.h"
#include <vector>

class Prefetching {
public:
	vector<int> prefetching(int, int, bool);
	int ansScore;
	static void caluculateEncircle(vector<pair<Masu, pair<int, int>>> route, int nowX, int nowY, vector< vector<int> >& visited, Masu::StateOfMasu);
	static bool isVisited(vector<pair<Masu, pair<int, int>>> route, int newX, int newY, Masu::StateOfMasu st) {
		for (pair<Masu, pair<int, int>> p : route) {
			if (newX == p.second.first && newY == p.second.second  && p.first.Status != (st == Masu::EnemyTile ? Masu::FriendTile : Masu::EnemyTile)) return true;
		}
		return false;
	}
private:
	int caluculateSumScore(int nowX, int nowY, int step, vector<pair<Masu, pair<int, int>>> route, vector<pair<Masu, pair<int, int>>> route4C);
	int caluculateTileScore(int nowX, int nowY, int step, vector<pair<Masu, pair<int, int>>> route);
	int caluculateMovable(int nowX, int nowY, int step);
	
	static bool isAdjoin(pair<int, int> p1, pair<int, int > p2) {
		return (abs(p1.first - p2.first) <= 1 && abs(p1.second - p2.second));
	}

};