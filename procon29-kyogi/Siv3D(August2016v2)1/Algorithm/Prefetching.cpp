#include "Prefetching.h"


vector<int> Prefetching::prefetching(int toX, int toY, bool isRmv = false)
{
	Map *map;
	map = map->getMap();
	vector<pair<Masu, pair<int, int>>> route = {}; //初手なのでたどってきた経路は空になる

	vector<int> ret; //評価値が最終的に入るところ．Prefetchingの戻り値でもある

	if (!isRmv) { //初手が敵タイル除去でない（移動）
		ret.push_back(caluculateSumScore(toX, toY, 0, route, route));
		ret.push_back(caluculateTileScore(toX, toY, 0, route));
		ret.push_back(caluculateMovable(toX, toY, 0));
	}else{ //初手が敵タイル除去
		//とりあえず各評価地を初期化
		ret.push_back(0); ret.push_back(0); ret.push_back(0);
		//8近傍について踏み出す
		for (int i = 0; i < 8; ++i) {
			int dy[] = { 1, 0, -1, 0 , 1, 1, -1, -1 };
			int dx[] = { 0, 1, 0, -1 , 1, -1, 1, -1 };

			int newX = toX + dx[i];
			int newY = toY + dy[i];

			ret[0] += caluculateSumScore(newX, newY, 1, route, route);
			ret[1] += map->board[toY][toX].TilePoint; //敵タイル除去によって得られたタイル点を追加
			ret[1] += caluculateTileScore(newX, newY, 1, route);
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
		for (int i = 0; i < 16; ++i) { //0～7 = 移動，8～15 = 敵タイル除去．ただし，敵タイル除去の場合はその座標に敵タイルがなければ無効．
			int newX, newY;
			newX = nowX + dx[i % 8];
			newY = nowY + dy[i % 8];

			if (newX >= 0 && newX < map->Width && newY >= 0 && newY < map->Vertical && !isVisited(route, newX, newY, Masu::FriendTile)) { //移動先がマップ範囲内で，なおかつこの探索で一度も訪れてない
				if (i < 8) {
					newScore += map->board[newY][newX].TilePoint;

					//経路に現在いるとこを突っ込む
					pair<Masu, pair<int, int>> p;
					pair<int, int> position;
					Masu masu; masu.Status = Masu::FriendTile;
					p.first = masu;
					position.first = nowX; position.second = nowY;
					p.second = position;
					route.push_back(p);

					//囲み判定用の経路に座標をそれぞれ+1して突っ込む
					++position.first; ++position.second;
					p.second = position;
					route4C.push_back(p);

					//囲み判定で水を流し込む対象となる二次元配列．
					vector< vector<int> > visited;
					for (int u = 0; u <= map->Vertical + 1; ++u) {
						vector<int> v(map->Width + 2, 0);
						visited.push_back(v);
					}
					caluculateEncircle(route4C, 0, 0, visited, Masu::FriendTile);
					caluculateEncircle(route4C, map->Width + 1, map->Vertical + 1, visited, Masu::FriendTile);

					for (int u = 1; u <= map->Vertical; ++u) {
						for (int v = 1; v <= map->Width; ++v) {
							//visited[u][v]はcaluculateEncircleによって「囲まれてなければ1，囲まれてるorタイル置かれてたら0」となる．
							//囲まれてるorタイル置かれてる状態で，味方タイルが置かれてない（＝囲まれてる）ならそこのタイル点を加算
							if (!visited[u][v] && !isVisited(route, v - 1, u - 1, Masu::FriendTile) && map->board[u][v].Status != Masu::FriendTile) {
								newScore += abs(map->board[u - 1][v - 1].TilePoint);
							}
						}
					}

					//再帰呼出し
					newScore += caluculateSumScore(newX, newY, step + 1, route, route4C);
				}else{ //敵のタイル除去を選んだ場合
					if(map->board[newY][newX].Status == Masu::EnemyTile){
						//探索の過程でそこを通過してない
						if (!isVisited(route, newX, newY, Masu::FriendTile)) {
							newScore += map->board[newY][newX].TilePoint;
							
							//経路に突っ込んだりの過程は上と同じ．
							pair<Masu, pair<int, int>> p;
							pair<int, int> position;
							Masu masu; masu.Status = Masu::EnemyTile;
							p.first = masu;
							position.first = nowY; position.second = nowX;
							p.second = position;
							route.push_back(p);

							vector< vector<int> > visited;
							for (int u = 0; u <= map->Vertical + 1; ++u) {
								vector<int> v(map->Width + 2, 0);
								visited.push_back(v);
							}

							//敵タイルによる囲み判定をし，敵タイル除去前の得点と敵タイル除去後の得点を比べる．
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

							//再帰呼出し
							newScore += caluculateSumScore(nowX, nowY, step + 1, route, route4C);
						}
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
	//数手先におけるタイル点数によって点数付けしている．かんたん．
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
			//移動先がマップ範囲内で，なおかつ味方タイルが置かれてない（再訪しない）
			if (newX >= 0 && newX < map.Width && newY >= 0 && newY < map.Vertical && !isVisited(route, newX, newY, Masu::FriendTile)) {
				newScore += map.board[newX][newY].TilePoint;

				//経路に突っ込んで再帰呼出し
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
	int dy[] = { 1, 0, -1, 0 , 1, 1, -1, -1};
	int dx[] = { 0, 1, 0, -1 , 1, -1, 1, -1};
	//移動可能マス数によって点数付け
	Setting *setting;
	setting = setting->getSetting();
	if (step >= setting->maxStep) {
		return 0;
	}
	else {
		Map map = *(Map::getMap());
		int newMovable = 0;
		for (int i = 0; i < 8; ++i) {
			int newX, newY;
			newX = nowX + dx[i];
			newY = nowY + dy[i];
			//移動先がマップ範囲内かどうかを確かめてるだけ
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

	//経路 route をとったときの，stチームによる囲み判定をする
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
}
