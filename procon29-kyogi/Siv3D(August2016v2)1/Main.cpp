# include <Siv3D.hpp>
# include "SystemManager.h"

void Main()
{
	const Font font(30);
	while (System::Update())
	{
		Map *hoge = hoge->getMap();
		hoge->Turn = 10;
		font(hoge->Turn).draw();
		Circle(Mouse::Pos(), 50).draw({ 255, 0, 0, 127 });
	}
}
