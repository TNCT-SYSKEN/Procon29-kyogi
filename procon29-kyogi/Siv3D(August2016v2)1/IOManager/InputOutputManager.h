#pragma once
#include "CreateMapClass.h"
#include "DrawMap.h"
#include "UpdateTurnInfo.h"
#include "Interrupt.h"
//�N���X�ϐ��̒�`
CreateMapClass *createMap;
DrawMap *drawMap;
UpdateTurnInfo *updateTurn;
Interrupt *interrupt;

class InputOutputManager {
public:
	//CreateMap���N��
	InputOutputManager();
	//IO�֘A���Ǘ�
	void inputOuntputManager(void);
private:
};