#include "CreateMapClass.h"

vector< vector<int> > input;
vector< pair<int, int> > agents;

void CreateMapClass::createMapClass(void)
{
	ReadQR rqr;
	std::string data = rqr.readQR();

	//クラス変数 input に読み取った内容を代入していく．
	vector<std::string> tmp1 = splitStringByCoron(data);

	int i = 0;
	int end = tmp1[0][0] - '0'; //謎のコードですが，要するに盤面の高さです．読み込む文字列の最初に来る文字．
	if (input.size() < end) {
		Console::Open();
		for (std::string s : tmp1) {
			if (i > 0 & i <= end) {
				vector<int> tmp2 = splitStringBySpace(s);
				input.push_back(tmp2);
			}else if(i > 0 && i <= end + 2){
				vector<int> tmp2 = splitStringBySpace(s);
				agents.push_back(make_pair(tmp2[0], tmp2[1]));
			}
			++i;
		}
		cout << agents.size() << endl;
		agents.clear();
		agents.push_back(make_pair(splitStringBySpace(tmp1[end + 1])[0], splitStringBySpace(tmp1[end + 1])[1]));
		agents.push_back(make_pair(splitStringBySpace(tmp1[end + 2])[0], splitStringBySpace(tmp1[end + 2])[1]));
		cout << agents.size() << endl;
	}

	createMasuClass();
	createAgent();
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
	Map *map;
	map = map->getMap();

	Console::Open();
	cout << agents[1].first << endl; 

	Agent agent1, agent2;
	agent1.position = agents[0];
	map->agents.push_back(agent1);
	agent2.position = agents[1];
	map->agents.push_back(agent2);
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
