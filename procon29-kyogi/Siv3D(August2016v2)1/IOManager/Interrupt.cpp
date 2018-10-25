#include "Interrupt.h"

Interrupt::Interrupt()
	: m_gui(GUIStyle::Default)
{
	m_gui.setPos(605, 0);

	// ������
	// Title Input
	// ������
	m_gui.add(L"hr", GUIHorizontalLine::Create(1));
	m_gui.horizontalLine(L"hr").style.color = Color(127);
	m_gui.add(GUIText::Create(L"Input"));
	m_gui.add(L"hr", GUIHorizontalLine::Create(1));
	m_gui.horizontalLine(L"hr").style.color = Color(127);

	// �{�^��
	m_gui.add(L"goTurn", GUIButton::Create(L"���i��"));
	m_gui.add(L"backTurn", GUIButton::Create(L"���߂�"));
	m_gui.add(L"research", GUIButton::Create(L"�ĒT��"));
	m_gui.addln(L"start", GUIButton::Create(L"�^�[���̊J�n"));

	// ��ǂݐ[�x�ǂݎ��
	m_gui.add(L"text0", GUIText::Create(L"��ǂݐ[�x"));
	m_gui.add(L"prefetchingTF", GUITextField::Create(3));
	m_gui.addln(L"prefetchingSL", GUISlider::Create(0, 100, 0, 200));

	// �S�T���A�����I��
	m_gui.add(L"switchAlgo", GUIToggleSwitch::Create(L"�S�T��", L"�����ǂ�", false));

	// ������
	//�^�C�g���F�X�R�A
	// ������
	m_gui.add(L"hr", GUIHorizontalLine::Create(1));
	m_gui.horizontalLine(L"hr").style.color = Color(127);
	m_gui.add(GUIText::Create(L"Score"));
	m_gui.add(L"hr", GUIHorizontalLine::Create(1));
	m_gui.horizontalLine(L"hr").style.color = Color(127);

	// �X�R�A�\��
	//�ԃ`�[�����v�X�R�A
	m_gui.add(L"text1", GUIText::Create(L"�ԓ��_�@:",80));
	m_gui.text(L"text1").style.color = Palette::Red;
	m_gui.add(L"enemySumScore", GUITextArea::Create(1, 5));
	//�`�[�����v�X�R�A
	m_gui.add(L"text2", GUIText::Create(L"���_�@:", 80));
	m_gui.text(L"text2").style.color = Palette::Blue;
	m_gui.addln(L"friendSumScore", GUITextArea::Create(1, 5));

	//�ԃ`�[���^�C���X�R�A
	m_gui.add(L"text3", GUIText::Create(L"�ԃ^�C��:", 80));
	m_gui.text(L"text3").style.color = Palette::Red;
	m_gui.add(L"enemyTileScore", GUITextArea::Create(1, 5));
	//�`�[���^�C��
	m_gui.add(L"text4", GUIText::Create(L"�^�C��:",80));
	m_gui.text(L"text4").style.color = Palette::Blue;
	m_gui.addln(L"friendTileScore", GUITextArea::Create(1, 5));

	//�ԃ`�[���̈�X�R�A
	m_gui.add(L"text5", GUIText::Create(L"�ԃG���A:", 80));
	m_gui.text(L"text5").style.color = Palette::Red;
	m_gui.add(L"enemyAreaScore", GUITextArea::Create(1, 5));
	//�`�[���̈�X�R�A
	m_gui.add(L"text6", GUIText::Create(L"�G���A:", 80));
	m_gui.text(L"text6").style.color = Palette::Blue;
	m_gui.addln(L"friendAreaScore", GUITextArea::Create(1, 5));

	// ������
	//Other�\��
	// ������
	m_gui.add(L"hr", GUIHorizontalLine::Create(1));
	m_gui.horizontalLine(L"hr").style.color = Color(127);
	m_gui.add(GUIText::Create(L"Other"));
	m_gui.add(L"hr", GUIHorizontalLine::Create(1));
	m_gui.horizontalLine(L"hr").style.color = Color(127);
	
	//�^�[������\��
	m_gui.add(L"text9", GUIText::Create(L"�^�[����:", 80));
	m_gui.text(L"text9").style.color = Palette::Black;
	m_gui.addln(L"Turn", GUITextArea::Create(1, 5));
	
	//Infomation
	m_gui.add(L"text10", GUIText::Create(L"Information", 80));
	m_gui.text(L"text10").style.color = Palette::Black;
	m_gui.addln(L"Info", GUITextArea::Create(4, 8));

	// �����̐ݒ�
	m_gui.style.width = 595;
	m_gui.style.showTitle = true;

}

void Interrupt::interruptManager(void)
{
	backTurn();
	//goTurn();
	prefetchingInfo();
	Research();
	start();
	selectAglo();
	drawSumScore();
	drawTileScore();
	drawAreaScore();
	drawTurn();
}

//1�^�[���߂鏈��
void Interrupt::backTurn(void)
{
	UpdateTurnInfo update;
	//�^�[�����Ǘ����Ă���ϐ��̒l�����炷�E�E�H
	if (m_gui.button(L"backTurn").pushed) {
		update.backTurn();
	}
}

//1�^�[���i��
void Interrupt::goTurn(void)
{
	if (m_gui.button(L"goTurn").pushed) {

	}
}

//�ǂ��܂Ő�ǂނ��̐���ǂݍ���
void Interrupt::prefetchingInfo(void)
{
	//Map�N���X�̒������������E�E�E�H
	Setting *setting;
	setting = setting->getSetting();
	
	// �X���C�_�[���ω�������A���l��ύX����
	if (m_gui.slider(L"prefetchingSL").hasChanged)
	{
		m_gui.textField(L"prefetchingTF").setText(Format(m_gui.slider(L"prefetchingSL").value));
	}
	// ���l���ω�������A�X���C�_�[��ύX����
	if (m_gui.textField(L"prefetchingTF").hasChanged)
	{
		m_gui.slider(L"prefetchingSL").setValue(Parse<double>(m_gui.textField(L"prefetchingTF").text));
	}

	//�[�x�̐[�����󂯕t��
	if (m_gui.textField(L"prefetchingTF").hasChanged) {
		setting->maxStep = Parse<int>(m_gui.textField(L"prefetchingTF").text);
	}
}

//�����^�[���ɂ����ĒT���A���S���Y�����ēx������
void Interrupt::Research(void)
{
	UpdateTurnInfo update;

	if (m_gui.button(L"research").pushed) {
		update.research();
	}
}

void Interrupt::start()
{
	Setting *setting;
	setting = setting->getSetting();

	if (m_gui.button(L"start").pushed) {
		setting->turnFlag = true;
	}
}

//�S�T���Ɛ����ǂ݂̂ǂ�����s�����̑I��
void Interrupt::selectAglo()
{
	Setting *setting;
	setting = setting->getSetting();

	//true �����ǂ�
	//false �S�T��
	if (m_gui.toggleSwitch(L"switchAlgo").isRight) {
		setting->bruteForce = 1;
	}
	else{
		setting->bruteForce = 0;
	}
}

//�X�R�A���v��\��
void Interrupt::drawSumScore()
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
	m_gui.textArea(L"friendSumScore").setText(friendSumScore);
	m_gui.textArea(L"enemySumScore").setText(enemySumScore);
}

//�^�C���X�R�A�̕\��
void Interrupt::drawTileScore()
{
	Map *map;
	map = map->getMap();

	//siv3d::String�̐錾
	String friendTileScore;
	String enemyTileScore;

	//int -> std::string -> siv3d::String�ɕϊ�
	friendTileScore = Widen(to_string(map->friendTileScore));
	enemyTileScore = Widen(to_string(map->enemyTileScore));

	//draw sumScore
	m_gui.textArea(L"friendTileScore").setText(friendTileScore);
	m_gui.textArea(L"enemyTileScore").setText(enemyTileScore);
}

//�̈�X�R�A�̕\��
void Interrupt::drawAreaScore()
{
	Map *map;
	map = map->getMap();

	//siv3d::String�̐錾
	String friendAreaScore;
	String enemyAreaScore;

	//int -> std::string -> siv3d::String�ɕϊ�
	friendAreaScore = Widen(to_string(map->friendAreaScore));
	enemyAreaScore = Widen(to_string(map->enemyAreaScore));

	//draw sumScore
	m_gui.textArea(L"friendAreaScore").setText(friendAreaScore);
	m_gui.textArea(L"enemyAreaScore").setText(enemyAreaScore);
}

//�^�[������\��
void Interrupt::drawTurn()
{
	Map *map;
	map = map->getMap();

	//siv3d::String�̐錾
	String Turn;

	//int -> std::string -> siv3d::String�ɕϊ�
	Turn = Widen(to_string(map->Turn));

	m_gui.textArea(L"Turn").setText(Turn);
}

//����\��
void Interrupt::drawInfo()
{
	
}

//�G�̈ړ����n�̓���
void Interrupt::inputEnemyMovePos()
{
	Map *map;
	map = map->getMap();
	DrawLeft drawLeft;

	bool roopBreak = false;
	//�}�X�̕\�����W�̕⏕
	const int pos_sup = MASU_SIZE + 5;
	
	//�G�G�[�W�F���g�����Q��
	for (int k = 2; k <= 3; k++) {
		String text = Format(L"EnemyAgent[", k - 1, L"]�̈ړ�����N���b�N���Ă�������");
		m_gui.textArea(L"Info").setText(text);
		System::Update();
		while (System::Update()) {
			if (Input::MouseL.clicked) {
				const Point pos = Mouse::Pos();
				int count = 0;
				for (int i = 0; i < 12;i++) {
					//x�����ʒu�ł����Ƃǂ��Ȃ̂�
					if (5 + pos_sup * i < pos.x&&pos.x < pos_sup * (i + 1)) {
						map->agents[k].nextPosition.second = i;
						count++;
					}
					//y�����ʒu�Ō����Ƃǂ��Ȃ̂�
					if (5 + pos_sup * i < pos.y&&pos.y < pos_sup * (i + 1)) {
						map->agents[k].nextPosition.first = i;
						count++;
					}
				}
				//x , y����nextPos��������ꂽ���m�F
				if (count == 2) {
					roopBreak = true;
				}
			}
			//draw left map
			drawLeft.drawLeftManager();
			if (roopBreak) {
				break;
			}
		}
		roopBreak = false;
	}

	m_gui.textArea(L"Info").setText(L"�G�G�[�W�F���g�̈ʒu���͂��������܂����B");
	System::Update();
}
