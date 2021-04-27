#pragma once
#include "Game.hpp"

class LoadSound {
public:
	LoadSound(const char* file_name);
	~LoadSound();
	void PlaySound();
private:
	Mix_Chunk* sound;
};