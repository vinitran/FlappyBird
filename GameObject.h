#pragma once
#include "Game.hpp"
#include "PlaySound.h"
class GameObject{
public:
	GameObject(const char* texturesheet,int x, int y);
	~GameObject();
	void Update_background();
	void Update_pipe();
	void Render();
	void Update_bird();
	void Click();
	int point1();
	int point2();
	double bird_movement;
	double pos_x();
	double pos_y();
	void Updatepos_point1();
	void Updatepos_point2();
	void Reset();
private:
	int xpos;
	int ypos;
	int image_width, image_height;
	const double Gravity = 0.45;
	SDL_Texture* objTexture;
	SDL_Rect destRect;
	PlaySound* sound;
	int rand_pos;
};
