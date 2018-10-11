# include <Siv3D.hpp>
# include "SystemManager.h"
using namespace Window;

SystemManager *sys;

void Main()
{
	//サイズを変えれるウィンドウに
	Window::SetStyle(WindowStyle::Sizeable);
	//背景色の変更
	Graphics::SetBackground(Palette::White);
	//画面サイズの設定
	Resize(1200,610);
	
	while (System::Update())
	{
		sys->systemManager();
		Println(1);
	}
}
