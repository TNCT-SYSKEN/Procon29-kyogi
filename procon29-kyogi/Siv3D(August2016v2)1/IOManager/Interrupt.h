#pragma once
class Interrupt {
public:
	void interruptManager(void);
private:
	void backTurn(void);
	void goTurn(void);
	//��ǂ݂͈̔͂��X�V
	void prefetchingInfo(void);
	//�ēx�T������
	void Research(void);
};