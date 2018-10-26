#include "Prefetching.h"


vector<int> Prefetching::prefetching(int toX, int toY, bool isRmv = false)
{
	Map *map;
	map = map->getMap();
	vector<pair<Masu, pair<int, int>>> route = {}; //����Ȃ̂ł��ǂ��Ă����o�H�͋�ɂȂ�

	vector<int> ret; //�]���l���ŏI�I�ɓ���Ƃ���DPrefetching�̖߂�l�ł�����

	if (!isRmv) { //���肪�G�^�C�������łȂ��i�ړ��j
		ret.push_back(caluculateSumScore(toX, toY, 0, route, route));
		ret.push_back(caluculateTileScore(toX, toY, 0, route));
		ret.push_back(caluculateMovable(toX, toY, 0));
	}else{ //���肪�G�^�C������
		//�Ƃ肠�����e�]���n��������
		ret.push_back(0); ret.push_back(0); ret.push_back(0);
		//8�ߖT�ɂ��ē��ݏo��
		for (int i = 0; i < 8; ++i) {
			int dy[] = { 1, 0, -1, 0 , 1, 1, -1, -1 };
			int dx[] = { 0, 1, 0, -1 , 1, -1, 1, -1 };

			int newX = toX + dx[i];
			int newY = toY + dy[i];

			ret[0] += caluculateSumScore(newX, newY, 1, route, route);
			ret[1] += map->board[toY][toX].TilePoint; //�G�^�C�������ɂ���ē���ꂽ�^�C���_��ǉ�
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
	//�����ɂ����鍇�v�_���ɂ���ē_���t��
	Setting *setting;
	setting = setting->getSetting();
	if (step >= setting->maxStep) {
		return 0;
	}
	
	else {
		Map *map;
		map = map->getMap();
		int newScore = 0;
		for (int i = 0; i < 16; ++i) { //0�`7 = �ړ��C8�`15 = �G�^�C�������D�������C�G�^�C�������̏ꍇ�͂��̍��W�ɓG�^�C�����Ȃ���Ζ����D
			int newX, newY;
			newX = nowX + dx[i % 8];
			newY = nowY + dy[i % 8];

			if (newX >= 0 && newX < map->Width && newY >= 0 && newY < map->Vertical && !isVisited(route, newX, newY, Masu::FriendTile)) { //�ړ��悪�}�b�v�͈͓��ŁC�Ȃ������̒T���ň�x���K��ĂȂ�
				if (i < 8) {
					newScore += map->board[newY][newX].TilePoint;

					//�o�H�Ɍ��݂���Ƃ���˂�����
					pair<Masu, pair<int, int>> p;
					pair<int, int> position;
					Masu masu; masu.Status = Masu::FriendTile;
					p.first = masu;
					position.first = nowX; position.second = nowY;
					p.second = position;
					route.push_back(p);

					//�͂ݔ���p�̌o�H�ɍ��W�����ꂼ��+1���ē˂�����
					++position.first; ++position.second;
					p.second = position;
					route4C.push_back(p);

					//�͂ݔ���Ő��𗬂����ޑΏۂƂȂ�񎟌��z��D
					vector< vector<int> > visited;
					for (int u = 0; u <= map->Vertical + 1; ++u) {
						vector<int> v(map->Width + 2, 0);
						visited.push_back(v);
					}
					caluculateEncircle(route4C, 0, 0, visited, Masu::FriendTile);
					caluculateEncircle(route4C, map->Width + 1, map->Vertical + 1, visited, Masu::FriendTile);

					for (int u = 1; u <= map->Vertical; ++u) {
						for (int v = 1; v <= map->Width; ++v) {
							//visited[u][v]��caluculateEncircle�ɂ���āu�͂܂�ĂȂ����1�C�͂܂�Ă�or�^�C���u����Ă���0�v�ƂȂ�D
							//�͂܂�Ă�or�^�C���u����Ă��ԂŁC�����^�C�����u����ĂȂ��i���͂܂�Ă�j�Ȃ炻���̃^�C���_�����Z
							if (!visited[u][v] && !isVisited(route, v - 1, u - 1, Masu::FriendTile) && map->board[u][v].Status != Masu::FriendTile) {
								newScore += abs(map->board[u - 1][v - 1].TilePoint);
							}
						}
					}

					//�ċA�ďo��
					newScore += caluculateSumScore(newX, newY, step + 1, route, route4C);
				}else{ //�G�̃^�C��������I�񂾏ꍇ
					if(map->board[newY][newX].Status == Masu::EnemyTile){
						//�T���̉ߒ��ł�����ʉ߂��ĂȂ�
						if (!isVisited(route, newX, newY, Masu::FriendTile)) {
							newScore += map->board[newY][newX].TilePoint;
							
							//�o�H�ɓ˂����񂾂�̉ߒ��͏�Ɠ����D
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

							//�G�^�C���ɂ��͂ݔ�������C�G�^�C�������O�̓��_�ƓG�^�C��������̓��_���ׂ�D
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

							//�ċA�ďo��
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
	//�����ɂ�����^�C���_���ɂ���ē_���t�����Ă���D���񂽂�D
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
			//�ړ��悪�}�b�v�͈͓��ŁC�Ȃ��������^�C�����u����ĂȂ��i�ĖK���Ȃ��j
			if (newX >= 0 && newX < map.Width && newY >= 0 && newY < map.Vertical && !isVisited(route, newX, newY, Masu::FriendTile)) {
				newScore += map.board[newX][newY].TilePoint;

				//�o�H�ɓ˂�����ōċA�ďo��
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
	//�ړ��\�}�X���ɂ���ē_���t��
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
			//�ړ��悪�}�b�v�͈͓����ǂ������m���߂Ă邾��
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
