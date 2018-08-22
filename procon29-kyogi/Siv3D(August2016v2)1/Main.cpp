# include <Siv3D.hpp>
# include "SystemManager.h"

SystemManager *sys;

void Main()
{
	while (System::Update())
	{
		sys->systemManager();
	}
}
