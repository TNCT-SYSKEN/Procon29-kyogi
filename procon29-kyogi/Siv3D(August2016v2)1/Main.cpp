# include <Siv3D.hpp>
# include "SystemManager.h"

SystemManager *sys;

void Main()
{
	
	const Size targetSize(1280, 720);

	// フルスクリーン可能な解像度一覧を取得
	const Array<Size> resolutions = Graphics::GetFullScreenSize();

	for (const auto& resolution : resolutions)
	{
		Println(resolution);
	}

	const Font font(40);
	while (System::Update())
	{
		if (Input::KeyF.clicked)
		{
			// フルスクリーンモード
			if (!Window::SetFullscreen(true, targetSize))
			{
				System::Exit();
			}
		}

		if (Input::KeyW.clicked)
		{
			// ウィンドウモード
			if (!Window::SetFullscreen(false, targetSize))
			{
				System::Exit();
			}
		}
		sys->systemManager();
	}
}
