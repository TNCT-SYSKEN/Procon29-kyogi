# include <Siv3D.hpp>
# include "SystemManager.h"
using namespace Window;

SystemManager sys;

void Main()
{
	//背景色の変更
	Graphics::SetBackground(Color(160, 200, 100));
	//サイズを変えれるウィンドウに
	Window::SetStyle(WindowStyle::Sizeable);
	//画面サイズの設定
	//left screen 605 x 605 y
	//right screen 595 x 605 y 
	Resize(1200,605);
	sys.startSolver();
	//GUI
	Interrupt inter;
	Setting *setting;
	setting = setting->getSetting();
	setting->turnFlag = false;
	while (System::Update())
	{
		inter.interruptManager();
		sys.systemManager();
	}
}