# include <Siv3D.hpp>
# include "SystemManager.h"
using namespace Window;

SystemManager sys;
void hoge() {
	static GUI gui(GUIStyle::Default);

	gui.setPos(605, 0);
	gui.add(GUIText::Create(L"Input"));
	gui.addln(GUIButton::Create(L"hoge"));

	gui.add(GUINewLine::Create());
}
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
	//hoge();
	//GUI
	Interrupt inter;
	while (System::Update())
	{
		inter.interruptManager();
		sys.systemManager();
	}
}