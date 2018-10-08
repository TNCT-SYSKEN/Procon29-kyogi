#include "CreateMapClass.h"

vector< vector<int> > input;

void CreateMapClass::createMapClass(void)
{
	ReadQR rqr;
	std::string data = rqr.readQR();

	//クラス変数 input に読み取った内容を代入していく．
	vector<std::string> tmp1 = splitStringByCoron(data);

	int i = 0;
	int end = tmp1[0][0] - '0'; //謎のコードですが，要するに盤面の高さです．読み込む文字列の最初に来る文字．
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
	//読み取った内容をもとにMasuを代入
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
