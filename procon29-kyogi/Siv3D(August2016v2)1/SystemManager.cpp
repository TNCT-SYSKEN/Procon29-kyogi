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
	Suport suport;
	Setting *setting;
	setting = setting->getSetting();

	static int prms1[5] = { 4, 4, 4, 4, 3 };
	static int prms2[5] = { 3, 3, 2, 1, 2 };
	static int fwin;
	static int ewin;
	static int best = 0;
	static int bestprms[5] = { 4, 4, 4, 4, 3 };
	int a1x = 0; int a1y = 0;
	int a2x = 0; int a2y = 0;
	if (setting->turnFlag == true) {
		//update.updateManager(); //���̃^�[���̃f�[�^��ۑ��{�^�[������i�߂�
		map->Turn += 1;
		algoManager.algorithmManager(prms1, prms2); //�őP������߂�
		suport.suportOfficer();         //�����G�[�W�F���g�̓����𐔎��ŕ\��
		inter.drawSuport();
		drawLeft.drawLeftManager();    //�őP��ɂ���Ė����G�[�W�F���g�̈ړ����\������
		//inter.inputEnemyMovePos();   //�G�̌��n�̓��͂̎�t

		int x1 = map->agents[2].nextPosition.first;
		int y1 = map->agents[2].nextPosition.second;
		int x2 = map->agents[3].nextPosition.first;
		int y2 = map->agents[3].nextPosition.second;

		std::random_device rnd;
		std::mt19937 mt(rnd());
		std::uniform_int_distribution<int> unr(-1, 1);

		if (a1x == x1 && a1y == y1) {
			map->agents[2].nextPosition.first += unr(mt);
			map->agents[2].nextPosition.second += unr(mt);
		}

		if (a2x == x2 && a2y == y2) {
			map->agents[3].nextPosition.first += unr(mt);
			map->agents[3].nextPosition.second += unr(mt);
		}
		
		a1x = x1;
		a1y = y1;
		a2x = x2;
		a2y = y2;

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
		map->friendAreaScore += Prefetching::caluculateAreaScore(Masu::FriendTile);

		map->enemyAreaScore += Prefetching::caluculateAreaScore(Masu::EnemyTile);

		map->friendSumScore = map->friendTileScore + map->friendAreaScore;
		map->enemySumScore = map->enemyTileScore + map->enemyAreaScore;

		//�����܂ł̗��ꂪ�I�������turnFlag��true�ɂ���
		//setting->turnFlag = false;
		if (map->Turn == 40) {
			std::random_device rnd;
			std::mt19937 mt(rnd());
			std::uniform_int_distribution<int> unr(1, 10);
			int d = map->friendSumScore - map->enemySumScore;
			//Println(d);
			if (d > 0) {
				prms2[0] = unr(mt);
				prms2[1] = unr(mt);
				prms2[2] = unr(mt);
				prms2[3] = unr(mt);
				prms2[4] = unr(mt);
				++fwin;
				if (fwin > best) {
					best = fwin;
					bestprms[0] = prms1[0];
					bestprms[1] = prms1[1];
					bestprms[2] = prms1[2];
					bestprms[3] = prms1[3];
					bestprms[4] = prms1[4];
				}
				ewin = 0;
			}
			else {
				prms1[0] = unr(mt);
				prms1[1] = unr(mt);
				prms1[2] = unr(mt);
				prms1[3] = unr(mt);
				prms1[4] = unr(mt);
				++ewin;
				if (ewin > best) {
					best = ewin;
					bestprms[0] = prms2[0];
					bestprms[1] = prms2[1];
					bestprms[2] = prms2[2];
					bestprms[3] = prms2[3];
					bestprms[4] = prms2[4];
				}
				fwin = 0;
			}
			ofstream file;
			file.open("logs.txt", ios::app);
			file << fwin << " " << ewin << " "<< d << " " << best << endl;
			file << prms1[0] << " " << prms1[1] << " " << prms1[2] << " " << prms1[3] << " " << prms1[4] << endl;
			file << prms2[0] << " " << prms2[1] << " " << prms2[2] << " " << prms2[3] << " " << prms2[4] << endl;
			file << bestprms[0] << " " << bestprms[1] << " " << bestprms[2] << " " << bestprms[3] << " " << bestprms[4] << endl << endl;
			file.close();
			//Println(d, L" ", fwin, L" ", ewin, L" ");
			map->agents.clear();
			ioManager.init();
		}
	}
	ioManager.inputOuntputManager();
}