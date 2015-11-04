#include "GameLoop.h"

System::Point2D<int>pos{ 405,620 };
System::Point2D<float>po{ pos.X,pos.Y };
System::Size2D<int>siz{ 5,50 };
System::Color<int>col{ 255,255,255,255 };
bool collision = false;
int bulletlife = 32;

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
	//Graphics::DrawRect({ 400, 400 }, { 450, 400 }, { 160, 65, 255, 255 });
	//Graphics::DrawRect({ 250, 500 }, { 1000, 200 }, { 0, 255, 0, 255 });

	//Graphics::DrawLine({ 10, 10 }, { 100, 100 }, { 255, 255, 255, 255 });
	//Graphics::DrawPoint({ 5, 5 }, { 255, 255, 255, 255 });

	//Graphics::DrawRing({ 140, 140 }, 50, 25, { 50, 0, 200, 255 });
	//Graphics::DrawCircle({ 800, 450 }, 200, 50, { 0, 255, 255, 150 });
	
	// mine
	Graphics::DrawRect({ 255,80 }, { 255, 250 }, { 0,80,34,255 });
	Graphics::DrawRect({900,2}, { 400, 923 }, { 250, 0, 0, 255 });

	//Graphics::DrawRect({ po.X,po.Y }, { 4, 10 }, { 250, 0, 0, 255 });

	Graphics::DrawCircle({ pos.X,pos.Y },  siz.H, siz.W, {col.Red,col.Blue,col.Green,col.Alpha});
	Graphics::DrawCircle({ pos.X,pos.Y }, 4, 10, { 250, 0, 0, 255 });

	Graphics::DrawLine({ 100,10 }, { 20,200 }, { 255,0,0,255 });
	Graphics::DrawPoint({ 400,400 }, { 60,150,255,255 });

}

void GameLoop::OnKeyDown(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	switch (ac_sdlSym)
	{
	case SDLK_ESCAPE: m_bRunning = false; break; // End the loop
	
	default: printf("%s\n", SDL_GetKeyName(ac_sdlSym)); break;
	}
	
	switch (collision)
	{

	case 1:
		
		if (collision = true)
		{
			pos.X = pos.X = 0;
			pos.Y = pos.Y = 0;
			
		}
	}

	//movement
	if (ac_sdlSym == SDLK_UP)
	{
		pos.Y = pos.Y - 5;
	}

	if (ac_sdlSym == SDLK_LEFT)
	{
		pos.X = pos.X - 5;
	}

	if (ac_sdlSym == SDLK_DOWN)
	{
		pos.Y = pos.Y + 5;
	}

	if (ac_sdlSym == SDLK_RIGHT)
	{
		pos.X = pos.X + 5;
	}


	//bullet movement
	if (ac_sdlSym == SDLK_KP_2)
	{
		if (bulletlife = 32)
		{
			bulletlife = po.Y;
			po.Y = po.Y + 1000;
			Graphics::DrawRect({ po.X,po.Y }, { 4, 10 }, { 250, 0, 0, 255 });
		}
	}

	if (ac_sdlSym == SDLK_KP_6)
	{
		if (bulletlife = 32)
		{
			bulletlife = po.X;
			po.X = po.X + 10000;
			Graphics::DrawRect({ po.X,po.Y }, { 4, 10 }, { 250, 0, 0, 255 });
		}
	}
	
	if (ac_sdlSym == SDLK_KP_8)
	{
		if (bulletlife = 32)
		{
			bulletlife = po.Y;
			po.Y = po.Y - 1000;
			Graphics::DrawRect({ po.X,po.Y }, { 4, 10 }, { 250, 0, 0, 255 });
		}
	}
	
	if (ac_sdlSym == SDLK_KP_4)
	{
		if (bulletlife = 32)
		{
			bulletlife = po.X;
			po.X = po.X - 10000;
			Graphics::DrawRect({ po.X,po.Y }, { 4, 10 }, { 250, 0, 0, 255 });
		}
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
