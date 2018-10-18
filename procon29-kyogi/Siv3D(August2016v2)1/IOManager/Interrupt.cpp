#include "Interrupt.h"

Interrupt::Interrupt()
	: m_gui(GUIStyle::Default)
{
	m_gui.setPos(605, 0);

	// ������
	m_gui.add(L"hr", GUIHorizontalLine::Create(1));
	m_gui.horizontalLine(L"hr").style.color = Color(127);
	// Title Input
	m_gui.add(GUIText::Create(L"Input"));
	// ������
	m_gui.add(L"hr", GUIHorizontalLine::Create(1));
	m_gui.horizontalLine(L"hr").style.color = Color(127);

	// �{�^��
	m_gui.add(L"bt1", GUIButton::Create(L"���i��"));
	m_gui.add(L"bt2", GUIButton::Create(L"���߂�"));
	m_gui.addln(L"bt3", GUIButton::Create(L"�ĒT��"));

	// ��ǂݐ[�x�ǂݎ��
	m_gui.add(L"tf1", GUITextField::Create(3));
	m_gui.addln(L"sl1", GUISlider::Create(0, 100, 0, 200));

	// �S�T���A�����I��
	m_gui.add(L"ts1", GUIToggleSwitch::Create(L"�S�T��", L"�����ǂ�", false));

	// ������
	m_gui.add(L"hr", GUIHorizontalLine::Create(1));
	m_gui.horizontalLine(L"hr").style.color = Color(127);

	//�^�C�g���F�X�R�A
	m_gui.add(GUIText::Create(L"Score"));
	
	// ������
	m_gui.add(L"hr", GUIHorizontalLine::Create(1));
	m_gui.horizontalLine(L"hr").style.color = Color(127);

	// �X�R�A�\��
	//�ԃ`�[�����v�X�R�A
	m_gui.add(L"text1", GUIText::Create(L"�ԓ��_:",60));
	m_gui.text(L"text1").style.color = Palette::Red;
	m_gui.add(L"ta1", GUITextArea::Create(1, 10));

	//�`�[�����v�X�R�A
	m_gui.add(L"text2", GUIText::Create(L"���_:", 60));
	m_gui.text(L"text2").style.color = Palette::Blue;
	m_gui.addln(L"ta2", GUITextArea::Create(1, 10));

	//�ԃ`�[���^�C���X�R�A
	m_gui.add(L"text3", GUIText::Create(L"�ԃ^�C��:", 80));
	m_gui.text(L"text3").style.color = Palette::Red;
	m_gui.add(L"ta3", GUITextArea::Create(1, 5));
	
	//�`�[���^�C��
	m_gui.add(L"text4", GUIText::Create(L"�ԃ^�C��:",80));
	m_gui.text(L"text4").style.color = Palette::Blue;
	m_gui.add(L"ta4", GUITextArea::Create(1, 5));

	// ������
	m_gui.add(L"hr", GUIHorizontalLine::Create(1));
	m_gui.horizontalLine(L"hr").style.color = Color(127);

	//Other�\��
	m_gui.add(GUIText::Create(L"Other"));

	// ������
	m_gui.add(L"hr", GUIHorizontalLine::Create(1));
	m_gui.horizontalLine(L"hr").style.color = Color(127);
	
	// �����̐ݒ�
	m_gui.style.width = 595;
	m_gui.style.showTitle = true;

}

void Interrupt::interruptManager(void)
{
	//backTurn();
	//goTurn();
	prefetchingInfo();
	Research();
	selectAglo();
	drawScore();
}

void Interrupt::backTurn(void)
{
	//1�^�[���߂鏈��
	//�^�[�����Ǘ����Ă���ϐ��̒l�����炷�E�E�H
	if (m_gui.button(L"bt2").pushed) {

	}
}

void Interrupt::goTurn(void)
{
	//1�^�[���i��
	if (m_gui.button(L"bt1").pushed) {

	}
}

void Interrupt::prefetchingInfo(void)
{
	//�ǂ��܂Ő�ǂނ��̐���ǂݍ���
	//Map�N���X�̒������������E�E�E�H
	Setting *setting;
	setting = setting->getSetting();
	
	// �X���C�_�[���ω�������A���l��ύX����
	if (m_gui.slider(L"sl1").hasChanged)
	{
		m_gui.textField(L"tf1").setText(Format(m_gui.slider(L"sl1").value));
	}
	// ���l���ω�������A�X���C�_�[��ύX����
	if (m_gui.textField(L"tf1").hasChanged)
	{
		m_gui.slider(L"sl1").setValue(Parse<double>(m_gui.textField(L"tf1").text));
	}

	//�[�x�̐[�����󂯕t��
	if (m_gui.textField(L"tf1").hasChanged) {
		setting->maxStep = Parse<int>(m_gui.textField(L"tf1").text);
	}
}

void Interrupt::Research(void)
{
	AlgorithmManager algo;

	//�����^�[���ɂ����ĒT���A���S���Y�����ēx������
	if (m_gui.button(L"bt3").pushed) {
		algo.algorithmManager();
	}
}

void Interrupt::selectAglo()
{
	Setting *setting;
	setting = setting->getSetting();

	//true �����ǂ�
	//false �S�T��
	if (m_gui.toggleSwitch(L"ts1").enabled == false) {
		setting->bruteForce = 1;
	}
	else if (m_gui.toggleSwitch(L"ts1").enabled == true) {
		setting->bruteForce = 0;
	}
}

void Interrupt::drawScore()
{
	Map *map;
	map = map->getMap();

	//siv3d::String�̐錾
	String friendSumScore;
	String enemySumScore;

	//int -> std::string -> siv3d::String�ɕϊ�
	friendSumScore = Widen(to_string(map->friendSumScore));
	enemySumScore = Widen(to_string(map->enemySumScore));

	//draw sumScore
	m_gui.textArea(L"ta1").setText(friendSumScore);
	m_gui.textArea(L"ta2").setText(friendSumScore);
}
