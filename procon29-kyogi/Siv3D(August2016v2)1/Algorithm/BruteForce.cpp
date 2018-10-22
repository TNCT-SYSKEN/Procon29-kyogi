#include "BruteForce.h"

int dy[] = { 1, 0, -1, 0 , 1, 1, -1, -1 };
int dx[] = { 0, 1, 0, -1 , 1, -1, 1, -1 };

vector<int> ansVec;
int maxAns = 0;

vector<int> BruteForce::bruteForce(int nX, int nY)
{
	int remainingTurn = 3;
	nowX = nX; nowY = nY;

	vector<int> route;

	ansVec = route;
	maxAns = 0;

	calcRoute(remainingTurn, route);
	Println(ansVec);
	Println(maxAns);
	return ansVec;
}

/* TODO: 経路の重複をなくす */
//経路のパターンを生やす．
int BruteForce::calcRoute(int remainingTurn, vector<int> route) {
	if (remainingTurn == 0) {
		//タイル点の計算
		int s1 = calculateScore(nowX, nowY, route);


		//領域点の計算
		Map *map;
		map = map->getMap();
		vector< vector<int> > visited;
		for (int u = 0; u <= map->Vertical + 1; ++u) {
			vector<int> v(map->Width + 2, 0);
			visited.push_back(v);
		}
		
		vector<pair<Masu, pair<int, int>>> route4C;
		int nX = nowX; int nY = nowY;
		for (int i : route) {
			nX += dx[i]; nY += dy[i];
			if (nX < 0 || nX >= map->Width || nY < 0 || nY >= map->Vertical) {
				return -1;
			}
			pair<int, int> po = make_pair(nX+1, nY+1);
			Masu masu;
			route4C.push_back(make_pair(masu, po));
		}

		Prefetching::caluculateEncircle(route4C, 0, 0, visited);

		int s2 = 0;
		for (int u = 1; u <= map->Vertical; ++u) {
			for (int v = 1; v <= map->Width; ++v) {
				if (!visited[u][v] && !Prefetching::isVisited(route4C , v, u)) {
					s2 += abs(map->board[u - 1][v - 1].TilePoint);
				}
			}
		}

		if (s1 + s2 > maxAns) {
			maxAns = s1 + s2;
			ansVec = route;
		}

		return s1 + s2;
	}
	else {
		int maxScore = 0;
		for (int i = 0; i < 8; ++i) {
			vector<int> r1 = route;

			vector<pair<Masu, pair<int, int>>> route4Check;
			int nX = nowX; int nY = nowY;
			for (int j : route) {
				nX += dx[j]; nY += dy[j];
				pair<int, int> po = make_pair(nX, nY);
				Masu masu;
				route4Check.push_back(make_pair(masu, po));
			}

			Map *map;
			map = map->getMap();
			if (!Prefetching::isVisited(route4Check, nX + dx[i], nY + dy[i]) && map->board[nY+dy[i]][nX+dx[i]].Status != Masu::FriendTile && map->board[nY + dy[i]][nX + dx[i]].Status != Masu::EnemyTile) {
				r1.push_back(i);
				int s = calcRoute(remainingTurn - 1, r1);
				if (s > maxScore) {
					maxScore = s;
				}
			}
		}
		return maxScore;
	}
}

//経路 route を取った際のスコアを計算する．
int BruteForce::calculateScore(int nX, int nY, vector<int> route) {
	int tileScore = 0;
	Map *map;
	map = map->getMap();
	for (int i : route) {
		nX += dx[i]; nY += dy[i];
		if (nX < 0 || nX >= map->Width || nY < 0 || nY >= map->Vertical) {
			return -1;
		}
		tileScore += map->board[nY][nX].TilePoint;
	}
	return tileScore;
}
