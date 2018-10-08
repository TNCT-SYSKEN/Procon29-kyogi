#include "CreateMapClass.h"

vector< vector<int> > input;

void CreateMapClass::createMapClass(void)
{
	ReadQR rqr;
	std::string data = rqr.readQR();

	//�N���X�ϐ� input �ɓǂݎ�������e�������Ă����D
	vector<std::string> tmp1 = splitStringByCoron(data);

	int i = 0;
	int end = tmp1[0][0] - '0'; //��̃R�[�h�ł����C�v����ɔՖʂ̍����ł��D�ǂݍ��ޕ�����̍ŏ��ɗ��镶���D
	if (input.size() < end) {
		for (std::string s : tmp1) {
			if (i) {
				vector<int> tmp2 = splitStringBySpace(s);
				input.push_back(tmp2);
			}
			++i;
			if (i > end) break;
		}
	}

	createMasuClass();
	//createAgent();
}

void CreateMapClass::createMasuClass(void)
{
	//�ǂݎ�������e�����Ƃ�Masu����
	Map *map;
	map = map->getMap();

	for (int j = 0; j < input.size(); ++j) {
		vector<int> v = input[j];
		for (int i = 0; i < v.size(); ++i) {
			Masu masu;
			masu.TilePoint = v[i];
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
