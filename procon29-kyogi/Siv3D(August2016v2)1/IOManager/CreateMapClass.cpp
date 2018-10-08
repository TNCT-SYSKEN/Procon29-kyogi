#include "CreateMapClass.h"

void CreateMapClass::createMapClass(void)
{
	ReadQR rqr;
	input = rqr.readQR(); //�N���X�ϐ� input �ɓǂݎ�������e�����D

	Map *map;
	map = map->getMap();

	createMasuClass();
	createAgent();
}

void CreateMapClass::createMasuClass(void)
{
	//�ǂݎ�������e�����ƂɊe�}�X�N���X���쐬
	//Masu����
	Map *map;
	map = map->getMap();

	for (int j = 0; j < VERTICAL; ++j) {
		for (int i = 0; i < WIDTH; ++i) {
			Masu masu;
			masu.Status = Masu::Non;
			map->board[j][i] = masu;
		}
	}
}

void CreateMapClass::createAgent(void)
{
	//�ǂݎ�������e�����ƂɊe�G�[�W�F���g�N���X���쐬
}

//������� : �ŕ������Cvector<std::string> �ɓ˂�����ŕԂ��D
//�w���p�[�֐��݂����Ȃ��̂ł��D��������Ӗ��͂Ȃ��ł��D
vector<std::string> CreateMapClass::splitStringByCoron(const std::string &s)
{
	vector<string> elems;
	string item;
	for (char ch : s) {
		if (ch == ':') {
			if (!item.empty())
				elems.push_back(item);
			item.clear();
		}
		else {
			item += ch;
		}
	}
	if (!item.empty())
		elems.push_back(item);
	return elems;
}

//������𔼊p�X�y�[�X�ŕ������Cvector<int> ��Ԃ��D
//��Ɠ������w���p�[�֐��ł��D
vector<int> CreateMapClass::splitStringBySpace(const std::string &s)
{
	vector<int> elems;
	string item;
	for (char ch : s) {
		if (ch == ' ') {
			if (!item.empty()) {
				elems.push_back(stoi(item));
			}
			item.clear();
		}
		else {
			item += ch;
		}
	}
	if (!item.empty())
		elems.push_back(stoi(item));
	return elems;
}
