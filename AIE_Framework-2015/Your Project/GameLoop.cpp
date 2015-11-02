#include "GameLoop.h"

System::Point2D<int>pos{ 350,80 };
System::Size2D<int>siz{ 100,50 };
System::Color<int>col{ 300,450,150,1600 };

System::Point2D<int>po{ 800,500 };

void GameLoop::Loop()
{
	SDL_Event sdlEvent; // Will hold the next event to be parsed

	while (m_bRunning)
	{
		// Events get called one at a time, so if multiple things happen in one frame, they get parsed individually through 'SDL_PollEvent'
		// The next event to parse gets stored into 'sdlEvent', and then passed to the 'EventHandler' class which will call it's appropriate function here
		// 'SDL_PollEvent' returns 0 when there are no more events to parse
		while (SDL_PollEvent(&sdlEvent))
		{
			// Calls the redefined event function for the EventHandler class
			// Refer to its header file and cpp for more information on what each inherited function is capable of
			// and its syntax
			OnEvent(sdlEvent);
		}
		Update();

		LateUpdate();

		Draw();

		Graphics::Flip(); // Required to update the window with all the newly drawn content
	}
}

void GameLoop::Update()
{

}
void GameLoop::LateUpdate()
{

}

void GameLoop::Draw()
{
	// Objects are drawn in a painter's layer fashion meaning the first object drawn is on the bottom, and the last one drawn is on the top
	// just like a painter would paint onto a canvas
	
	// Ben's
	Graphics::DrawRect({ 400, 400 }, { 450, 400 }, { 160, 65, 255, 255 });
	Graphics::DrawRect({ 250, 500 }, { 1000, 200 }, { 0, 255, 0, 255 });

	Graphics::DrawLine({ 10, 10 }, { 100, 100 }, { 255, 255, 255, 255 });
	Graphics::DrawPoint({ 5, 5 }, { 255, 255, 255, 255 });

	Graphics::DrawRing({ 140, 140 }, 50, 25, { 50, 0, 200, 255 });
	Graphics::DrawCircle({ 800, 450 }, 200, 50, { 0, 255, 255, 150 });
	
	// mine
	Graphics::DrawRect({ 350,80 }, { 260, 250 }, { 0,80,34,1500 });

	Graphics::DrawCircle({ pos.X,pos.Y },  siz.H, siz.W, {col.Red,col.Blue,col.Green,col.Alpha});

	Graphics::DrawLine({ 15,15 }, { 60,60 }, { 20,68,150,83 });
	Graphics::DrawPoint({ 20,20 }, { 60,150,800,350 });

	Graphics::DrawCircle({ po.X,po.Y }, 15, 100, { 0,50,50,100 });
}

void GameLoop::OnKeyDown(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{

	switch (ac_sdlSym)
	{
	case SDLK_ESCAPE: m_bRunning = false; break; // End the loop

	default: printf("%s\n", SDL_GetKeyName(ac_sdlSym)); break;
	}
	//movement
	if (ac_sdlSym == SDLK_UP)
	{
		pos.Y = pos.Y - 50;
	}

	if (ac_sdlSym == SDLK_LEFT)
	{
		pos.X = pos.X - 50;
	}

	if (ac_sdlSym == SDLK_DOWN)
	{
		pos.Y = pos.Y + 50;
	}

	if (ac_sdlSym == SDLK_RIGHT)
	{
		pos.X = pos.X + 50;
	}


	//bullet movement
	if (ac_sdlSym == SDLK_1)
	{
		po.X = po.X * 10;
	}
	

	//size
	if (ac_sdlSym == SDLK_w)
	{
		siz.H = siz.H + 10;
	}
	if (ac_sdlSym == SDLK_a)
	{
		siz.W = siz.W - 10;
	}
	if (ac_sdlSym == SDLK_s)
	{
		siz.H = siz.H - 10;
	}
	if (ac_sdlSym == SDLK_d)
	{
		siz.W = siz.W + 10;
	}

	//color
	if (ac_sdlSym == SDLK_p)
	{
		col.Alpha = col.Alpha + 50;
	}
	if (ac_sdlSym == SDLK_l)
	{
		col.Alpha = col.Alpha - 50;
	}
	if (ac_sdlSym == SDLK_o)
	{
		col.Blue = col.Blue + 50;
	}
	if (ac_sdlSym == SDLK_k)
	{
		col.Blue = col.Blue - 50;
	}
	if (ac_sdlSym == SDLK_i)
	{
		col.Green = col.Green + 50;
	}
	if (ac_sdlSym == SDLK_j)
	{
		col.Green = col.Green - 50;
	}
	if (ac_sdlSym == SDLK_u)
	{
		col.Red = col.Red + 50;
	}
	if (ac_sdlSym == SDLK_h)
	{
		col.Red = col.Red - 50;
	}
}
void GameLoop::OnKeyUp(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	switch (ac_sdlSym)
	{
	default: break;
	}

}
void GameLoop::OnExit()
{
	m_bRunning = false; // End the loop
}

GameLoop::GameLoop()
{
	m_bRunning = true;
}
GameLoop::~GameLoop()
{

}
