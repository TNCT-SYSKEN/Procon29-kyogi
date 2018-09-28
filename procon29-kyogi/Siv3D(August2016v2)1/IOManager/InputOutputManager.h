#pragma once
#include "CreateMapClass.h"
#include "DrawMap.h"
#include "UpdateTurnInfo.h"
#include "Interrupt.h"

class InputOutputManager {
public:
	//�N���X�ϐ��̒�`
	CreateMapClass *createMap;
	DrawMap *drawMap;
	UpdateTurnInfo *updateTurn;
	Interrupt *interrupt;
	//CreateMap���N��
	InputOutputManager();
	//IO�֘A���Ǘ�
	void inputOuntputManager(void);
private:
};