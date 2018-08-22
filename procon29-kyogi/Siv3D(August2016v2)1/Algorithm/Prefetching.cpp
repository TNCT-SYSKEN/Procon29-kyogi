#include "Prefetching.h"sO

void Prefetching::prefetching(void)
{
	//caluculateSumScore();
	//caluculateTileScore();
	caluculateMovable();
	//�����̐�ǂ݂��Ǘ�
}

int Prefetching::caluculateSumScore(int nowX, int nowY, int step, std::vector<std::pair<Masu, std::pair<int, int>>> route)
{
	int dy[] = { 1, 0, -1, 0 };
	int dx[] = { 0, 1, 0, -1 };
	//�����ɂ����鍇�v�_���ɂ���ē_���t��
	if (step >= maxStep) {
		return 0;
	}
	else {
		Map map = *(Map::getMap());
		int newScore = 0;
		for (int i = 0; i < 4; ++i) {
			int newX, newY;
			newX = nowX + dx[i];
			newY = nowY + dy[i];
			newScore += map.board[newX][newY].TilePoint;
			std::pair<Masu, std::pair<int, int>> p;
			std::pair<int, int> position;
			p.first = map.board[newX][newY];
			position.first = newX; position.second = newY;
			p.second = position;
			route.push_back(p);

			newScore += caluculateSumScore(newX, newY, step + 1, route);
		}
		return newScore;
	}
}

int Prefetching::caluculateTileScore(int nowX, int nowY, int step)
{
	int dy[] = { 1, 0, -1, 0 };
	int dx[] = { 0, 1, 0, -1 };
	//�����ɂ�����^�C���_���ɂ���ē_���t��
	if (step >= maxStep) {
		return 0;
	}
	else {
		Map map = *(Map::getMap());
		int newScore = 0;
		for (int i = 0; i < 4; ++i) {
			int newX, newY;
			newX = nowX + dx[i];
			newY = nowY + dy[i];
			newScore += map.board[newX][newY].TilePoint;
			newScore += caluculateTileScore(newX, newY, step + 1); //�d�����Đ����Ă��܂��̂Ō��׏������ۂ��@�o�H�������Ă������ق��������H
		}
		return newScore;
	}
}

void Prefetching::caluculateMovable(void)
{
	//�����̃}�X�ɂ�����}�X�̈ړ��\�}�X�̐��ɂ���ē_���t��
}

int Prefetching::caluculateEncircle(Map map, std::vector<std::pair<Masu, std::pair<int, int>>> route)
{
	//�o�H route ���Ƃ����Ƃ��̈͂ݔ��������
	std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> visited;

	int i;
	for (i = 0; i < route.size(); ++i) {
		Masu m = route[i].first;
		std::pair<int, int> position = route[i].second;
		int x = position.first;
		int y = position.second;

		for (std::pair<Masu, std::pair<int, int>> dm : route) {
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

				if (isAdjoin(std::make_pair(w, h), position)) {
					for (std::pair<std::pair<int, int>, std::pair<int, int>> r : visited) {
						std::pair<int, int> rf = r.first;
						std::pair<int, int> rs = r.second;

						if (rs.first != route[i - 1].second.first || rs.second != route[i - 1].second.second) {
							//�o�H route �Ɨ̈�Ƃň͂�ł���
						}
					}
					std::pair<int, int> t; t.first = w; t.second = h;
					std::pair<int, int> p; p.first = x; p.second = y;
					visited.push_back(std::make_pair(t, p));
				}
			}
		}
	}
	return 0;
}

void Prefetching::setMaxStep(int s)
{
	//��ǂ݂̐[����ύX����
	maxStep = s;
	return;
}

int Prefetching::getMaxStep(void)
{
	return maxStep;
}