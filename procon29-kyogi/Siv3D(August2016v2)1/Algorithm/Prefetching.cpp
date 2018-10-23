#include "Prefetching.h"


vector<int> Prefetching::prefetching(int toX, int toY, bool isRmv = false)
{
	Map *map;
	map = map->getMap();
	vector<pair<Masu, pair<int, int>>> route = {};

	vector<int> ret;

	if (!isRmv) {
		ret.push_back(caluculateSumScore(toX, toY, 0, route, route));
		ret.push_back(caluculateTileScore(toX, toY, 0, route));
		ret.push_back(caluculateMovable(toX, toY, 0));
	}else{
		ret.push_back(0); ret.push_back(0); ret.push_back(0);
		for (int i = 0; i < 8; ++i) {
			int dy[] = { 1, 0, -1, 0 , 1, 1, -1, -1 };
			int dx[] = { 0, 1, 0, -1 , 1, -1, 1, -1 };

			int newX = toX + dx[i];
			int newY = toY + dy[i];

			ret[0] += caluculateSumScore(newX, newY, 1, route, route);
			ret[1] += caluculateTileScore(newX, newY, 0, route);
			ret[2] += caluculateMovable(newX, newY, 1);
		}
	}

	return ret;
}

int Prefetching::caluculateSumScore(int nowX, int nowY, int step, vector<pair<Masu, pair<int, int>>> route, vector<pair<Masu, pair<int, int>>> route4C)
{
	int dy[] = { 1, 0, -1, 0 , 1, 1, -1, -1 };
	int dx[] = { 0, 1, 0, -1 , 1, -1, 1, -1 };
	//数手先における合計点数によって点数付け
	Setting *setting;
	setting = setting->getSetting();
	if (step >= setting->maxStep) {
		return 0;
	}
	
	else {
		Map *map;
		map = map->getMap();
		int newScore = 0;
		for (int i = 0; i < 16; ++i) {
			int newX, newY;
			newX = nowX + dx[i % 8];
			newY = nowY + dy[i % 8];

			if (newX >= 0 && newX < map->Width && newY >= 0 && newY < map->Vertical && !isVisited(route, newX, newY, Masu::FriendTile)) {
				if (i < 8) {
					newScore += map->board[newX][newY].TilePoint;

					pair<Masu, pair<int, int>> p;
					pair<int, int> position;
					Masu masu; masu.Status = Masu::FriendTile;
					p.first = masu;
					position.first = nowX; position.second = nowY;
					p.second = position;
					route.push_back(p);

					++position.first; ++position.second;
					p.second = position;
					route4C.push_back(p);

					vector< vector<int> > visited;
					for (int u = 0; u <= map->Vertical + 1; ++u) {
						vector<int> v(map->Width + 2, 0);
						visited.push_back(v);
					}
					caluculateEncircle(route4C, 0, 0, visited, Masu::FriendTile);

					for (int u = 1; u <= map->Vertical; ++u) {
						for (int v = 1; v <= map->Width; ++v) {
							if (!visited[u][v] && !isVisited(route, v - 1, u - 1, Masu::FriendTile) && map->board[u][v].Status != Masu::FriendTile) {
								newScore += abs(map->board[u - 1][v - 1].TilePoint);
							}
						}
					}

					newScore += caluculateSumScore(newX, newY, step + 1, route, route4C);
				}else{ //敵のタイル除去を選んだ場合
					if(map->board[newY][newX].Status == Masu::EnemyTile){
						if (!isVisited(route, newX, newY, Masu::FriendTile)) {
							newScore += map->board[newY][newX].TilePoint;

							pair<Masu, pair<int, int>> p;
							pair<int, int> position;
							Masu masu; masu.Status = Masu::EnemyTile;
							p.first = masu;
							position.first = nowX; position.second = nowY;
							p.second = position;
							route.push_back(p);

							vector< vector<int> > visited;
							for (int u = 0; u <= map->Vertical + 1; ++u) {
								vector<int> v(map->Width + 2, 0);
								visited.push_back(v);
							}

							int se = 0;
							caluculateEncircle(route4C, 0, 0, visited, Masu::EnemyTile);
							for (int u = 1; u <= map->Vertical; ++u) {
								for (int v = 1; v <= map->Width; ++v) {
									if (!visited[u][v] && map->board[u-1][v-1].Status != Masu::EnemyTile) {
										se += abs(map->board[u - 1][v - 1].TilePoint);
									}
								}
							}

							++position.first; ++position.second;
							p.second = position;
							masu.Status = Masu::EnemyTile;
							p.first = masu;
							route4C.push_back(p);

							caluculateEncircle(route4C, 0, 0, visited, Masu::EnemyTile);

							for (int u = 1; u <= map->Vertical; ++u) {
								for (int v = 1; v <= map->Width; ++v) {
									if (!visited[u][v] && map->board[u - 1][v - 1].Status != Masu::EnemyTile && !(u-1 == newY && v-1 == newX)) {
										se -= abs(map->board[u - 1][v - 1].TilePoint);
									}
								}
							}

							newScore += se;

							newScore += caluculateSumScore(nowX, nowY, step + 1, route, route4C);
						}
					}else{
						return 0;
					}
				}
			}
		}
		return newScore;
	}
}

int Prefetching::caluculateTileScore(int nowX, int nowY, int step, vector<pair<Masu, pair<int, int>>> route)
{
	int dy[] = { 1, 0, -1, 0 , 1, 1, -1, -1 };
	int dx[] = { 0, 1, 0, -1 , 1, -1, 1, -1 };
	//数手先におけるタイル点数によって点数付け
	Setting *setting;
	setting = setting->getSetting();
	if (step >= setting->maxStep) {
		return 0;
	}
	else {
		Map map = *(Map::getMap());
		int newScore = 0;
		for (int i = 0; i < 8; ++i) {
			int newX, newY;
			newX = nowX + dx[i];
			newY = nowY + dy[i];
			if (newX >= 0 && newX < map.Width && newY >= 0 && newY < map.Vertical && !isVisited(route, newX, newY, Masu::FriendTile)) {
				newScore += map.board[newX][newY].TilePoint;

				pair<Masu, pair<int, int>> p;
				pair<int, int> position;
				p.first = map.board[nowX][nowY];
				position.first = nowX; position.second = nowY;
				p.second = position;
				route.push_back(p);

				newScore += caluculateTileScore(newX, newY, step + 1, route);
			}
		}
		return newScore;
	}
}

int Prefetching::caluculateMovable(int nowX, int nowY, int step)
{
	int dy[] = { 1, 0, -1, 0 };
	int dx[] = { 0, 1, 0, -1 };
	//移動可能マス数によって点数付け
	Setting *setting;
	setting = setting->getSetting();
	if (step >= setting->maxStep) {
		return 0;
	}
	else {
		Map map = *(Map::getMap());
		int newMovable = 0;
		for (int i = 0; i < 4; ++i) {
			int newX, newY;
			newX = nowX + dx[i];
			newY = nowY + dy[i];
			if (newX >= 0 && newX < map.Width && newY >= 0 && newY < map.Vertical) {
				++newMovable;
				newMovable += caluculateMovable(newX, newY, step + 1);
			}
		}
		return newMovable;
	}
}

void Prefetching::caluculateEncircle(vector<pair<Masu, pair<int, int>>> route, int nowX, int nowY, vector< vector<int> >& visited, Masu::StateOfMasu st)
{
	int dy[] = { 1, 0, -1, 0 };
	int dx[] = { 0, 1, 0, -1 };

	//経路 route をとったときの囲み判定をする
	Map map = *(Map::getMap());

	for (int i = 0; i < 4; ++i) {
		visited[nowY][nowX] = 1;
		int newX = nowX + dx[i];
		int newY = nowY + dy[i];
		if (newX >= 0 && newX <= map.Width + 1 && newY >= 0 && newY <= map.Vertical + 1) {
			if (!visited[newY][newX] && !isVisited(route, newX, newY, st) && map.board[newY][newX].Status != st) {
				caluculateEncircle(route, newX, newY, visited, st);
			}
		}
	}
}
