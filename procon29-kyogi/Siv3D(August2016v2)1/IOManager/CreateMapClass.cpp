#include "CreateMapClass.h"

void CreateMapClass::createMapClass(void)
{
	ReadQR rqr;
	input = rqr.readQR(); //クラス変数 input に読み取った内容を代入．

	Map *map;
	map = map->getMap();

	createMasuClass();
	createAgent();
}

void CreateMapClass::createMasuClass(void)
{
	//読み取った内容をもとに各マスクラスを作成
	//Masuを代入
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
	//読み取った内容をもとに各エージェントクラスを作成
}

//文字列を : で分割し，vector<std::string> に突っ込んで返す．
//ヘルパー関数みたいなものです．さしたる意味はないです．
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

//文字列を半角スペースで分割し，vector<int> を返す．
//上と同じくヘルパー関数です．
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
