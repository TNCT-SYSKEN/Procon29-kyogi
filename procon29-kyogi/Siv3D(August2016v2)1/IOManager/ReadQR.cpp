#include "ReadQR.h"

ReadQR* ReadQR::InsReadQR = nullptr;
ReadQR* ReadQR::getReadQR() {
	if (InsReadQR == nullptr) {
		InsReadQR = new ReadQR;
	}
	return InsReadQR;
}
void ReadQR::readQR(void)
{
	//Zbar��p����QR�R�[�h�̓ǂݎ�肷��
	//�ǂݎ����QRCode�֑�����ACreateMapClass�֖߂�l�Ƃ��ēn��

	if (data == "nothing") {
		TextReader reader(L"qr.txt");
		String line;
		reader.readLine(line);
		data = line.narrow();
	}
}
