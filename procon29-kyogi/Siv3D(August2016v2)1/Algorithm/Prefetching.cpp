#include "Prefetching.h"

vector<int> Prefetching::prefetching(int toX, int toY)
{
	Map *map;
	map = map->getMap();
	vector<Agent> agents = map->agents;
	vector<pair<Masu, pair<int, int>>> route = {};

	vector<int> ret;
	ret.push_back(caluculateSumScore(toX, toY, 0, route));
	ret.push_back(caluculateTileScore(toX, toY, 0, route));
	ret.push_back(caluculateMovable(toX, toY, 0));

	return ret;
}

int Prefetching::caluculateSumScore(int nowX, int nowY, int step, vector<pair<Masu, pair<int, int>>> route)
{
	int dy[] = { 1, 0, -1, 0 , 1, 1, -1, -1 };
	int dx[] = { 0, 1, 0, -1 , 1, -1, 1, -1 };
	//�����ɂ����鍇�v�_���ɂ���ē_���t��
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
	//�����ɂ�����^�C���_���ɂ���ē_���t��
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
	//�ړ��\�}�X���ɂ���ē_���t��
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

	//�o�H route ���Ƃ����Ƃ��̈͂ݔ��������
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
