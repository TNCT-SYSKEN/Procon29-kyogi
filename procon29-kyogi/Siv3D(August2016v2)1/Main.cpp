# include <Siv3D.hpp>
# include "SystemManager.h"
using namespace Window;

SystemManager sys;

void Main()
{
	//サイズを変えれるウィンドウに
	Window::SetStyle(WindowStyle::Sizeable);
	//背景色の変更
	Graphics::SetBackground(Palette::White);
	//画面サイズの設定
	//left screen 605 x 605 y
	//right screen 595 x 605 y 
	Resize(1200,605);

	sys.startSolver();
	while (System::Update())
	{
		sys.systemManager();
	}
}
