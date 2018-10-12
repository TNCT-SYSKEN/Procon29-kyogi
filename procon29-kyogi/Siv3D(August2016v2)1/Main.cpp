# include <Siv3D.hpp>
# include "SystemManager.h"
using namespace Window;

SystemManager *sys;

void Main()
{
	int width, height;

	//サイズを変えれるウィンドウに
	Window::SetStyle(WindowStyle::Sizeable);
	
	width = Width();
	height = Height();

	Resize(width, height);

	while (System::Update())
	{
		sys->systemManager();
	}
}
