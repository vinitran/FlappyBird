#include "GameObject.h"
#include "TextureManager.h"
int point;

GameObject::GameObject(const char* texturesheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(texturesheet);
	xpos = (double) x;
	ypos = (double) y;
	SDL_QueryTexture(objTexture, NULL, NULL, &image_width, &image_height);
	destRect.h = image_height;
	destRect.w = image_width;
	destRect.x = xpos;
	destRect.y = ypos;
	point = 0;
	bird_movement = 0;
	sound = new PlaySound();
}
GameObject::~GameObject()
{}
int GameObject::point1()
{
	return point / 10;
}
int GameObject::point2()
{
	return point % 10;
}
void GameObject::Update_background()
{
	destRect.x -= 2;
	if (destRect.x == xpos - 432)
	{
		destRect.x = xpos;
	}
}
void GameObject::Update_pipe()
{
	destRect.x -= 2;
	if (destRect.x == - 68)
	{
		destRect.x = 534;
	}
	if (destRect.x == 534)
	{
		srand(static_cast<unsigned int>(time(NULL)));
		rand_pos = (-7 + rand() % 6) * 50;
		destRect.y = (double) rand_pos;
	}
	if (destRect.x == 94)
	{
		point++;
		sound->Sound_Point();
	}
}
void GameObject::Update_bird()
{
	bird_movement += Gravity;
	destRect.y += bird_movement;
}
void GameObject::Click()
{
	bird_movement = 0;
	bird_movement -= 9.25;
}
void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, NULL, &destRect);
}
double GameObject::pos_x()
{
	return destRect.x;
}
double GameObject::pos_y()
{
	return destRect.y;
}
void GameObject::Updatepos_point1()
{
	destRect.x = 180;
}
void GameObject::Updatepos_point2()
{
	destRect.x = 225;
}
void GameObject::Reset()
{
	destRect.x = xpos;
	destRect.y = ypos;
	point = 0;
	bird_movement = 0;
}
