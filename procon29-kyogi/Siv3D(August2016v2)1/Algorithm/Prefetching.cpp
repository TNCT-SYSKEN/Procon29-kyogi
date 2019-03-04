#include "Prefetching.h"

pair<int, int> Prefetching::prefetching(Agent agent, int agentNum)
{
	Map *map;
	map = map->getMap();
	pair<int, int> ans;
	queue<Candidate*> candidates;
	Candidate initialCand(agent.position.second, agent.position.first, 0, nullptr);
	unordered_map<string, Candidate> visited;
	Candidate best = initialCand;
	candidates.push(&initialCand);
	int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	Candidate c;

	Setting *setting;
	setting = setting->getSetting();

	int bestEvl = -INF;

	// TODO: (x, y)�����o���o�����̍ŏI�I����

	while (!candidates.empty()) {
		c = *(candidates.front()); Candidate* c_pt = candidates.front(); candidates.pop();
		for (int i = 0; i < 8; ++i) {
			pair<int, int> pos = make_pair(c.pos.first + dx[i], c.pos.second + dy[i]);
			if (c.step == 0 && agentNum == 2) {
				if (pos == map->agents[0].nextPosition) continue;
			}
			if (pos.first >= 0 && pos.first < map->Width) {
				if (pos.second >= 0 && pos.second < map->Vertical) {
					Candidate* nextCand = new Candidate();
					nextCand->pos = pos;
					nextCand->step = c.step + 1;
					nextCand->before = c_pt;
					int newEvl = -INF;

					if (c.step < setting->maxStep) {
						newEvl = evl(*nextCand);
						candidates.push(nextCand);
						if (newEvl > bestEvl) {
							best = *nextCand;
							bestEvl = newEvl;
						}
					}
				}
			}
		}
	}

	if (best.step <= 0) {
		return make_pair(agent.position.first, agent.position.second);
	}

	do{
		best = *(best.before);
	} while (best.before->step > 0);

	return make_pair(best.pos.second, best.pos.first);
}

int Prefetching::evl(Candidate c) {
	int point = 0;
	Map *map;
	map = map->getMap();
	bool isOccupied[VERTICAL][WIDTH] = { false };

	while (c.before != nullptr) {
		if (!isOccupied[c.pos.second][c.pos.first] && map->board[c.pos.second][c.pos.first].Status != Masu::FriendTile) {
			point += map->board[c.pos.second][c.pos.first].TilePoint;
			isOccupied[c.pos.second][c.pos.first] = true;
		}
		c = *(c.before);
	}

	bool visited[VERTICAL][WIDTH] = { false };
	queue< pair<int, int> > q;
	q.push(make_pair(-1, -1));
	q.push(make_pair(map->Vertical, -1));
	q.push(make_pair(-1, map->Width));
	q.push(make_pair(map->Vertical, map->Width));

	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		int dx[] = { 0, 1, 0, -1 };
		int dy[] = { 1, 0, -1, 0 };
		for (int i = 0; i < 4; ++i) {
			int newX = now.first + dx[i];
			int newY = now.second + dy[i];
			if (newX >= 0 && newX < map->Width && newY >= 0 && newY < map->Vertical && !visited[newY][newX] && !isOccupied[newY][newX]) {
				q.push(make_pair(newX, newY));
				visited[newY][newX] = true;
			}
		}
	}

	for (int i = 0; i < map->Vertical; ++i) {
		for (int j = 0; j < map->Width; ++j) {
			if (!visited[i][j]) {
				point += 2 * abs(map->board[i][j].TilePoint);
			}
		}
	}
	
	return point;
}

void Prefetching::caluculateEncircle(vector<pair<Masu, pair<int, int>>> route, int nowX, int nowY, vector< vector<int> >& visited, Masu::StateOfMasu st)
{
	int dy[] = { 1, 0, -1, 0 };
	int dx[] = { 0, 1, 0, -1 };

	//�o�H route ���Ƃ����Ƃ��́Cst�`�[���ɂ��͂ݔ��������
	Map map = *(Map::getMap());

	//����4�ߖT�Ƀh�o�[�b�Ɨ���
	for (int i = 0; i < 4; ++i) {
		visited[nowY][nowX] = 1;
		int newX = nowX + dx[i];
		int newY = nowY + dy[i];
		//4�ߖT�ɐ������ꍞ�ޏ����D�}�b�v�͈͓��ŁC�Ȃ����o�H�Ɋ܂܂�ĂȂ��C�^�C�����u����ĂȂ�
		if (newX >= 0 && newX <= map.Width + 1 && newY >= 0 && newY <= map.Vertical + 1) {
			if (!visited[newY][newX] && !isVisited(route, newX, newY, st) && map.board[newY][newX].Status != st) {
				caluculateEncircle(route, newX, newY, visited, st);
			}
		}
	}
}
