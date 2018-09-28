# include <Siv3D.hpp>
# include "SystemManager.h"
using namespace Window;

SystemManager *sys;

void Main()
{
	//サイズを変えれるウィンドウに
	Window::SetStyle(WindowStyle::Sizeable);

	Resize(1200,600);
	
	while (System::Update())
	{
		sys->systemManager();
	}
}
