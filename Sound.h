#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_mixer.h>

class Sound {
public:
	Sound(const char* file_name);
	~Sound();

	void playSound();

private:
	Mix_Chunk* sound1;
};