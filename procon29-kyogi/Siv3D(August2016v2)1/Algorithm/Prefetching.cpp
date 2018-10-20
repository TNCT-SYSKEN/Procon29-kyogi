#include "Prefetching.h"

vector<int> Prefetching::prefetching(int toX, int toY)
{
	Map *map;
	map = map->getMap();
	vector<Agent> agents = map->agents;
	vector<pair<Masu, pair<int, int>>> rout = {};

	vector<int> ret;
	ret.push_back(caluculateSumScore(toX, toY, 0, rout));
	ret.push_back(caluculateTileScore(toX, toY, 0, rout));
	ret.push_back(caluculateMovable(toX, toY, 0));

	vector< vector<int> > visited;
	for (int i = 0; i < map->Vertical; ++i) {
		vector<int> v(map->Width, 0);
		visited.push_back(v);
	}
	vector<pair<Masu, pair<int, int>>> route;

	pair<Masu, pair<int, int>> p;
	p.first = map->board[0][1];
	p.second = make_pair(1, 0);
	route.push_back(p);
	p.first = map->board[0][2];
	p.second = make_pair(2, 0);
	route.push_back(p);
	p.first = map->board[0][3];
	p.second = make_pair(3, 0);
	route.push_back(p);
	p.first = map->board[1][3];
	p.second = make_pair(3, 1);
	route.push_back(p);
	p.first = map->board[2][3];
	p.second = make_pair(3, 2);
	route.push_back(p);
	p.first = map->board[2][2];
	p.second = make_pair(2, 2);
	route.push_back(p);
	p.first = map->board[2][1];
	p.second = make_pair(1, 2);
	route.push_back(p);
	p.first = map->board[1][1];
	p.second = make_pair(1, 1);
	route.push_back(p);

	caluculateEncircle(route, 0, 0, visited);

	Println(Widen("result"));
	for (int i = 0; i < map->Vertical; ++i) {
		for (int j = 0; j < map->Width; ++j) {
			Print(visited[i][j]);
			Print(Widen(" "));
		}
		Println();
	}

	return ret;
}

int Prefetching::caluculateSumScore(int nowX, int nowY, int step, vector<pair<Masu, pair<int, int>>> route)
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
		Map map = *(Map::getMap());
		int newScore = 0;
		for (int i = 0; i < 8; ++i) {
			int newX, newY;
			newX = nowX + dx[i];
			newY = nowY + dy[i];
			if (newX >= 0 && newX < map.Width && newY >= 0 && newY < map.Vertical && !isVisited(route, newX, newY)) {
				newScore += map.board[newX][newY].TilePoint;

				pair<Masu, pair<int, int>> p;
				pair<int, int> position;
				p.first = map.board[nowX][nowY];
				position.first = nowX; position.second = nowY;
				p.second = position;
				route.push_back(p);

				newScore += caluculateSumScore(newX, newY, step + 1, route);
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
			if (newX >= 0 && newX < map.Width && newY >= 0 && newY < map.Vertical && !isVisited(route, newX, newY)) {
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

void Prefetching::caluculateEncircle(vector<pair<Masu, pair<int, int>>> route, int nowX, int nowY, vector< vector<int> >& visited)
{
	int dy[] = { 1, 0, -1, 0 };
	int dx[] = { 0, 1, 0, -1 };

	//経路 route をとったときの囲み判定をする
	Map map = *(Map::getMap());

	for (int i = 0; i < 4; ++i) {
		visited[nowY][nowX] = 1;
		int newX = nowX + dx[i];
		int newY = nowY + dy[i];
		if (newX >= 0 && newX < map.Width && newY >= 0 && newY < map.Vertical) {
			if (!visited[newY][newX] && !isVisited(route, newX, newY)) {
				caluculateEncircle(route, newX, newY, visited);

			}
		}
	}
}
