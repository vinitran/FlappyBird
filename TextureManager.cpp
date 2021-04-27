#include "TextureManager.h"
SDL_Texture* TextureManager::LoadTexture(const char* file_name)
{
	SDL_Surface* image = IMG_Load(file_name);
	SDL_Texture* image_texture = SDL_CreateTextureFromSurface(Game::renderer, image);
	SDL_FreeSurface(image);
	return image_texture;
}