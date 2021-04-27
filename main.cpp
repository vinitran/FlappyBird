#include "Game.hpp"

Game* game = nullptr;
int main(int argc, char *argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;
	game = new Game();
	game->init("FLAPPY BIRD", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 432, 768,false);
	while (game->Running())
	{
		frameStart = SDL_GetTicks();
		game->event();
		game->render();
		game->update();
		
		game->collision();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay( frameDelay - frameTime);
		}
	}
	game->clean();
	return 0;
}