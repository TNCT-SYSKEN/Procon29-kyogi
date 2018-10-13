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
	//Zbarを用いてQRコードの読み取りする
	//読み取ったQRCodeへ代入し、CreateMapClassへ戻り値として渡す

	if (data == "nothing") {
		TextReader reader(L"qr.txt");
		String line;
		reader.readLine(line);
		data = line.narrow();
	}
}
