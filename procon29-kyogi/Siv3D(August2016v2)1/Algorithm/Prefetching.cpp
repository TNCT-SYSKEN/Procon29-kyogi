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

int Prefetching::caluculateEncircle(Map map, vector<pair<Masu, pair<int, int>>> route)
{
	//�o�H route ���Ƃ����Ƃ��̈͂ݔ��������
	vector<pair<pair<int, int>, pair<int, int>>> visited;

	int i;
	for (i = 0; i < route.size(); ++i) {
		Masu m = route[i].first;
		pair<int, int> position = route[i].second;
		int x = position.first;
		int y = position.second;

		for (pair<Masu, pair<int, int>> dm : route) {
			int dx = dm.second.first;
			int dy = dm.second.second;

			if (isAdjoin(dm.second, position)) {
				if (dx != route[i - 1].second.first || dy != route[i - 1].second.second) {
					//�o�H route �P�Ƃň͂�ł���
				}
			}
		}

		//���̈�ƌo�H�Ƃ��אڕ��s���Ă���ꍇ�͂�������l���Ȃ����Ƃɂ���D
		//�����̓��_���v�Z���邱�ƂŎ����I�ɂ��̏ꍇ�ɂ��Ă��l���ł������D
		for (int w = 0; w < map.Width; ++w) {
			for (int h = 0; h < map.Vertical; ++h) {
				Masu dm = map.board[h][w];

				if (isAdjoin(make_pair(w, h), position)) {
					for (pair<pair<int, int>, pair<int, int>> r : visited) {
						pair<int, int> rf = r.first;
						pair<int, int> rs = r.second;

						if (rs.first != route[i - 1].second.first || rs.second != route[i - 1].second.second) {
							//�o�H route �Ɨ̈�Ƃň͂�ł���
						}
					}
					pair<int, int> t; t.first = w; t.second = h;
					pair<int, int> p; p.first = x; p.second = y;
					visited.push_back(make_pair(t, p));
				}
			}
		}
	}
	return 0;
}
