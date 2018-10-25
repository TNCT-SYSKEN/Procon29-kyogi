#include "SystemManager.h"

//�N���X�^�ϐ��̐錾
InputOutputManager ioManager;
AlgorithmManager algoManager;
ReadQR readQR;

void SystemManager::startSolver(void)
{
	//�V�X�e�����J�n����
	ReadQR *rqr;
	rqr = rqr->getReadQR();
	rqr->readQR();

	ioManager.init();
	Map *map;
	map = map->getMap();
	map->agents[0].nextPosition.first = 1;
	map->agents[0].nextPosition.second = 0;

	map->agents[1].nextPosition.first = 1;
	map->agents[1].nextPosition.second = 2;
}

void SystemManager::endSolver(void)
{
	//�V�X�e�����I���������
	//�I���̃^�[�����ɒB�����ꍇ
	//End�������ꂽ�ꍇ
}

void SystemManager::systemManager(void)
{
	//�A���S���Y���Ƃh�n�}�l�[�W���[���Ǘ�
	//�Q�[���̗���̊Ǘ�����
	UpdateTurnInfo update;
	Interrupt inter;
	DrawLeft drawLeft;
	AgentManager agentManager;
	Map *map;
	map = map->getMap();
	Setting *setting;
	setting = setting->getSetting();

	if (setting->turnFlag == true) {
		update.updateManager(); //���̃^�[���̃f�[�^��ۑ��{�^�[������i�߂�
		algoManager.algorithmManager(); //�őP������߂�
		drawLeft.drawLeftManager();    //�őP��ɂ���Ė����G�[�W�F���g�̈ړ����\������
		inter.inputEnemyMovePos();   //�G�̌��n�̓��͂̎�t
		agentManager.decideAgentAct();  //�G�Ɩ����̌��n�ɂ���Ď��ɍs���s���̌���
		agentManager.agentMoveManager(); //�G�[�W�F���g�����ۂɍs������
		drawLeft.drawLeftManager();      //�s����̏�Ԃ�\��
		System::Update();

		//���_���v�Z����
		map->friendTileScore = 0; map->enemyTileScore = 0; map->friendAreaScore = 0; map->enemyAreaScore = 0;
		map->friendSumScore = 0; map->enemySumScore = 0;

		//�^�C���_���v�Z����
		for (int i = 0; i < map->Vertical; ++i) {
			for (int j = 0; j < map->Width; ++j) {
				Masu masu = map->board[i][j];
				if (masu.Status == Masu::FriendTile) {
					map->friendTileScore += masu.TilePoint;
				}
				else if (masu.Status == Masu::EnemyTile) {
					map->enemyTileScore += masu.TilePoint;
				}
			}
		}

		//�̈�_���v�Z����
		vector< vector<int> > Fvisited; //�����̈͂݌v�Z
		for (int i = 0; i <= map->Vertical + 1; ++i) {
			vector<int> v(map->Width + 2, 0);
			Fvisited.push_back(v);
		}

		vector < pair<Masu, pair<int, int> > > route;
		Prefetching::caluculateEncircle(route, 0, 0, Fvisited, Masu::FriendTile);

		for (int u = 1; u <= map->Vertical; ++u) {
			for (int v = 1; v <= map->Width; ++v) {
				if (!Fvisited[u][v] && map->board[u][v].Status != Masu::FriendTile) {
					map->friendAreaScore += abs(map->board[u][v].TilePoint);
				}
			}
		}

		vector< vector<int> > Evisited; //�G�̈͂݌v�Z
		for (int i = 0; i <= map->Vertical + 1; ++i) {
			vector<int> v(map->Width + 2, 0);
			Evisited.push_back(v);
		}

		Prefetching::caluculateEncircle(route, 0, 0, Evisited, Masu::EnemyTile);

		for (int u = 1; u <= map->Vertical; ++u) {
			for (int v = 1; v <= map->Width; ++v) {
				if (!Evisited[u][v] && map->board[u][v].Status != Masu::EnemyTile) {
					map->enemyAreaScore += abs(map->board[u][v].TilePoint);
				}
			}
		}

		map->friendSumScore = map->friendTileScore + map->friendAreaScore;
		map->enemySumScore = map->enemyTileScore + map->enemyAreaScore;

		//�����܂ł̗��ꂪ�I�������turnFlag��true�ɂ���
		setting->turnFlag = false;
	}
	ioManager.inputOuntputManager();
}
