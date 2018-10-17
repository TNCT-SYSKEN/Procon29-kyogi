#include "Interrupt.h"

Interrupt *Interrupt::InsInterrupt = nullptr;

Interrupt *Interrupt::getInterrupt()
{
	if (InsInterrupt == nullptr) {
		InsInterrupt = new Interrupt;
	}
	return InsInterrupt;
}

void Interrupt::interruptManager(void)
{
	backTurn();
	goTurn();
	prefetchingInfo();
	Research();
}

void Interrupt::backTurn(void)
{
	//1�^�[���߂鏈��
	//�^�[�����Ǘ����Ă���ϐ��̒l�����炷�E�E�H
}

void Interrupt::goTurn(void)
{
	//1�^�[���i��

}

void Interrupt::prefetchingInfo(void)
{
	//�ǂ��܂Ő�ǂނ��̐���ǂݍ���
	//Map�N���X�̒������������E�E�E�H
	//GUI�̐錾
	static GUI gui(GUIStyle::Default);

	gui.setPos(605, 0);
	gui.add(GUIText::Create(L"Input"));
	gui.addln(GUIButton::Create(L"hoge"));

	gui.add(GUINewLine::Create());
}

void Interrupt::Research(void)
{
	//�����^�[���ɂ����ĒT���A���S���Y�����ēx������
}
