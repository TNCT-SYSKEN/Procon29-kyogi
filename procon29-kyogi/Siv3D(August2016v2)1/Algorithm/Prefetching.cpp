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
	/*
	int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	*/

	int dx[8] = { 1, -1, 0, 0 , 1, 1, -1, -1};
	int dy[8] = { 0, 0, 1, -1 , 1, -1, 1, -1};
	Candidate c;

	Setting *setting;
	setting = setting->getSetting();

	int bestEvl = -INF;

	// TODO: (x, y)順序バラバラ問題の最終的解決

	bool enemy_visited[VERTICAL][WIDTH] = { false };

	queue< pair<int, int> > q;
	for (int i = 0; i < map->Vertical; ++i) {
		q.push(make_pair(-1, i));
		q.push(make_pair(map->Width, i));
	}
	for (int i = 0; i < map->Width; ++i) {
		q.push(make_pair(i, -1));
		q.push(make_pair(i, map->Vertical));
	}

	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int newX = now.first + dx[i];
			int newY = now.second + dy[i];
			if (newX >= 0 && newX < map->Width && newY >= 0 && newY < map->Vertical && !enemy_visited[newY][newX] && map->board[newY][newX].Status != Masu::EnemyTile) {
				q.push(make_pair(newX, newY));
				enemy_visited[newY][newX] = true;
			}
		}
	}

	while (!candidates.empty()) {
		c = *(candidates.front()); Candidate* c_pt = candidates.front(); candidates.pop();
		for (int i = 0; i < 8; ++i) {
			pair<int, int> pos = make_pair(c.pos.first + dx[i], c.pos.second + dy[i]);
			if (pos.first >= 0 && pos.first < map->Width && !(c.step == 0 && agentNum == 2 && pos.first == map->agents[0].nextPosition.second && pos.second == map->agents[0].nextPosition.first)) {
				if (pos.second >= 0 && pos.second < map->Vertical) {
					Candidate* nextCand = new Candidate();
					nextCand->pos = pos;
					nextCand->step = c.step + 1;
					nextCand->before = c_pt;
					int newEvl = -INF;

					if (c.step < setting->maxStep) {
						bool enemy_visited_copy[VERTICAL][WIDTH];
						memcpy(enemy_visited_copy, enemy_visited, sizeof(enemy_visited));
						newEvl = evl(*nextCand, enemy_visited_copy, agentNum);
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

	if (best.before == nullptr) {
		return make_pair(agent.position.first, agent.position.second);
	}

	while (best.step > 1) {
		best = *(best.before);
	}//TODO: ここで Segmentation Fault が発生することがまれにある

	return make_pair(best.pos.second, best.pos.first);
}

int Prefetching::evl(Candidate c, bool enemy_visited[VERTICAL][WIDTH], int agentNum) {
	int point = 0;
	Map *map;
	map = map->getMap();
	bool isOccupied[VERTICAL][WIDTH] = { false };

	queue< pair<int, int> > eq;

	int evl_params[5] = { 3, 4, 4, 3, 3}; //重み．順に，領域点，自チームの囲み，相手チームの囲み，エージェント間距離，自由度

	isOccupied[map->agents[0].position.second][map->agents[0].position.first] = true;
	isOccupied[map->agents[1].position.second][map->agents[1].position.first] = true;

	while (c.before != nullptr) {
		if (!isOccupied[c.pos.second][c.pos.first] && map->board[c.pos.second][c.pos.first].Status != Masu::FriendTile) {
			point += evl_params[0] * map->board[c.pos.second][c.pos.first].TilePoint;
			if (map->board[c.pos.second][c.pos.first].Status == Masu::EnemyTile) {
				eq.push(make_pair(c.pos.first, c.pos.second));
			}
			else {
				isOccupied[c.pos.second][c.pos.first] = true;
			}
		}
		c = *(c.before);
	}

	for (int i = 0; i < map->Vertical; ++i) {
		for (int j = 0; j < map->Width; ++j) {
			if (map->board[i][j].Status == Masu::FriendTile) isOccupied[i][j] = true;
		}
	}

	bool visited[VERTICAL][WIDTH] = { false };
	queue< pair<int, int> > q;

	for (int i = 0; i < map->Vertical; ++i) {
		q.push(make_pair(-1, i));
		q.push(make_pair(map->Width, i));
	}
	for (int i = 0; i < map->Width; ++i) {
		q.push(make_pair(i, -1));
		q.push(make_pair(i, map->Vertical));
	}

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
			if (!visited[i][j] && !isOccupied[i][j]) {
				point += evl_params[1] * abs(map->board[i][j].TilePoint);
				//Println(i, L" ", j, L" ", map->board[i][j].TilePoint);
			}
		}
	}

	int dx[8] = { 1, -1, 0, 0 , 1, 1, -1, -1 };
	int dy[8] = { 0, 0, 1, -1 , 1, -1, 1, -1 };

	while (!eq.empty()) {
		pair<int, int> now = eq.front(); eq.pop();
		for (int i = 0; i < 4; ++i) {
			int newX = now.first + dx[i];
			int newY = now.second + dy[i];
			if (newX >= 0 && newX < map->Width && newY >= 0 && newY < map->Vertical && !enemy_visited[newY][newX] && map->board[newY][newX].Status != Masu::EnemyTile) {
				q.push(make_pair(newX, newY));
				enemy_visited[newY][newX] = true;
				//Println(newX, L" ", newY, L" ", map->board[newY][newX].TilePoint);
				point += evl_params[2] * abs(map->board[newY][newX].TilePoint);
			}
		}
	}

	//エージェント間距離を計算
	
	int dist;
	if (agentNum == 1) {
		dist = abs(map->agents[1].position.first - c.pos.second) + abs(map->agents[1].position.second - c.pos.first);
	}
	else {
		dist = abs(map->agents[1].nextPosition.first - c.pos.second) + abs(map->agents[1].nextPosition.second - c.pos.first);
	}

	point += evl_params[3] * dist;

	int freedom = 0;

	//自由度を計算
	for (int i = 0; i < 8; ++i) {
		int newX = c.pos.first + dx[i];
		int newY = c.pos.second + dy[i];
		if (newX >= 0 && newX < map->Width && newY >= 0 && newY < map->Vertical && !isOccupied[newY][newX]) {
			freedom += 1;
		}
	}

	point += evl_params[4] * freedom;

	return point;
}

int Prefetching::caluculateAreaScore(Masu::StateOfMasu st)
{
	//st チームの領域点を計算する．
	/*
	int dy[] = { 1, 0, -1, 0 };
	int dx[] = { 0, 1, 0, -1 };

	
	Map map = *(Map::getMap());

	//水を4近傍にドバーッと流す
	for (int i = 0; i < 4; ++i) {
		visited[nowY][nowX] = 1;
		int newX = nowX + dx[i];
		int newY = nowY + dy[i];
		//4近傍に水が流れ込む処理．マップ範囲内で，なおかつ経路に含まれてなく，タイルが置かれてない
		if (newX >= 0 && newX <= map.Width + 1 && newY >= 0 && newY <= map.Vertical + 1) {
			if (!visited[newY][newX] && !isVisited(route, newX, newY, st) && map.board[newY][newX].Status != st) {
				caluculateEncircle(route, newX, newY, visited, st);
			}
		}
	}
	*/

	Map *map;
	map = map->getMap();
	int dx[] = { 0, 1, 0, -1 };
	int dy[] = { 1, 0, -1, 0 };

	bool visited[VERTICAL][WIDTH] = { false };
	queue< pair<int, int> > q;
	for (int i = 0; i < map->Vertical; ++i) {
		q.push(make_pair(-1, i));
		q.push(make_pair(map->Width, i));
	}
	for (int i = 0; i < map->Width; ++i) {
		q.push(make_pair(i, -1));
		q.push(make_pair(i, map->Vertical));
	}

	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int newX = now.first + dx[i];
			int newY = now.second + dy[i];
			if (newX >= 0 && newX < map->Width && newY >= 0 && newY < map->Vertical && !visited[newY][newX] && map->board[newY][newX].Status != st) {
				q.push(make_pair(newX, newY));
				visited[newY][newX] = true;
			}
		}
	}

	int score = 0;

	for (int i = 0; i < map->Vertical; ++i) {
		for (int j = 0; j < map->Width; ++j) {
			if (!visited[i][j] && map->board[i][j].Status != st) {
				score += abs(map->board[i][j].TilePoint);
				//Println(i, L" ", j, L" ", map->board[i][j].TilePoint);
			}
		}
	}

	return score;
}
