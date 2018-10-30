#include "CreateMapClass.h"
#define MAX_WIDTH 12
#define MAX_VERTICAL 12

vector< vector<int> > input;
vector< pair<int, int> > agents;

void CreateMapClass::init(void)
{
	Map *map;
	map = map->getMap();
	for (int j = 0; j < MAX_VERTICAL; ++j) {
		for (int i = 0; i < MAX_WIDTH; ++i) {
			map->board[j][i].Status = Masu::Other;
		}
	}
	//�^�[�����̏�����
	map->Turn = 0;
	Setting *setting;
	setting = setting->getSetting();
	setting->maxStep = 2;
}

/* ReadQR->data �ɂ����Ɠ����Ă�� true ���C�����łȂ���� false ��Ԃ��D*/
bool CreateMapClass::createMapClass(void)
{
	ReadQR *rqr;
	rqr = rqr->getReadQR();
	string data = rqr->data;

	if (data == "nothing") return false;

	//Map->board�̏�����
	init();

	//�N���X�ϐ� input �ɓǂݎ�������e�������Ă����D
	vector<string> tmp1 = splitStringByCoron(data);

	int i = 0;
	vector<int> scale = splitStringBySpace(tmp1[0]);
	int end = scale[0];

	if (input.size() < end) {
		for (string s : tmp1) {
			if ((i > 0) & (i <= end)) {
				vector<int> tmp2 = splitStringBySpace(s);
				input.push_back(tmp2);
			}else if((i > 0) && (i <= end + 2)){
				vector<int> tmp2 = splitStringBySpace(s);
				agents.push_back(make_pair(tmp2[0]-1, tmp2[1]-1));
			}
			++i;
		}
		agents.clear();
		agents.push_back(make_pair(splitStringBySpace(tmp1[end + 1])[0]-1, splitStringBySpace(tmp1[end + 1])[1]-1));
		agents.push_back(make_pair(splitStringBySpace(tmp1[end + 2])[0]-1, splitStringBySpace(tmp1[end + 2])[1]-1));
	}

	//�����ƕ������D
	Map *map;
	map = map->getMap();
	map->Vertical = end;
	map->Width = scale[1];

	createMasuClass();
	createAgent();

	return true;
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
			if ((j== agents[0].first && i== agents[0].second) || (j== agents[1].first && i== agents[1].second)) {
				masu.Status = Masu::FriendTile;
			}
			if ((j== agents[1].first && i== agents[0].second) || (j== agents[0].first && i== agents[1].second)) {
				masu.Status = Masu::EnemyTile;
			}
			map->board[j][i] = masu;
		}
	}
}

void CreateMapClass::createAgent(void)
{
	Map *map;
	map = map->getMap();

	if (map->agents.size() >= 4) return; //1�x�������s���Ȃ��D

	Agent agent1, agent2, agent3, agent4;

	agent1.position = agents[0];
	agent1.Status = Agent::friend1;
	map->agents.push_back(agent1);

	agent2.position = agents[1];
	agent2.Status = Agent::friend2;
	map->agents.push_back(agent2);

	/* �G�G�[�W�F���g�̍��W���v�Z����D */
	pair<int, int> pos1, pos2;
	pos1 = make_pair(agents[1].first, agents[0].second);
	agent3.position = pos1;
	agent3.Status = Agent::enemy1;
	map->agents.push_back(agent3);

	pos2 = make_pair(agents[0].first, agents[1].second);
	agent4.position = pos2;
	agent4.Status = Agent::enemy2;
	map->agents.push_back(agent4);

}

//������� : �ŕ������Cvector<std::string> �ɓ˂�����ŕԂ��D
//�w���p�[�֐��݂����Ȃ��̂ł��D��������Ӗ��͂Ȃ��ł��D
vector<string> CreateMapClass::splitStringByCoron(const string &s)
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
vector<int> CreateMapClass::splitStringBySpace(const string &s)
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
