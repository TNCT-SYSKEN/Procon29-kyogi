#include <fstream>
#include <iostream>

using namespace std;

int main(void){
	ifstream ifs("qrb.txt");
	string str;
	getline(ifs, str);
	string str2 = str.substr(8);
	ifs.close();
	ofstream outputfile("qr.txt");
	outputfile << str2;
	outputfile.close();

}