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

	if (setting->turnFlag == true) {
		update.updateManager(); //���̃^�[���̃f�[�^��ۑ��{�^�[������i�߂�
		algoManager.algorithmManager(); //�őP������߂�
		suport.suportOfficer();         //�����G�[�W�F���g�̓����𐔎��ŕ\��
		inter.drawSuport();
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
		map->friendAreaScore += Prefetching::caluculateAreaScore(Masu::FriendTile);

		map->enemyAreaScore += Prefetching::caluculateAreaScore(Masu::EnemyTile);

		map->friendSumScore = map->friendTileScore + map->friendAreaScore;
		map->enemySumScore = map->enemyTileScore + map->enemyAreaScore;

		//�����܂ł̗��ꂪ�I�������turnFlag��true�ɂ���
		setting->turnFlag = false;
	}
	ioManager.inputOuntputManager();
}