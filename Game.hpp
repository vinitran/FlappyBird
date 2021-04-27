#ifndef Game_hpp
#define Game_hpp

#include <SDL_image.h>
#include <time.h>
#include <random>
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_mixer.h>
using namespace std;

class Game {
public:
	Game();
	~Game();
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void update();
	void render();
	void clean();
	void event();
	bool Running();
	static SDL_Renderer* renderer;
	void collision();

private:
	bool isRunning;
	bool start_game;
	SDL_Window *windown;
	SDL_Texture* image_texture;
	SDL_Rect texture_destination;
	bool bird_alive;
	bool GameOver;
	
	int round;
};
#endif
