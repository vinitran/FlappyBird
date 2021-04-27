#include "LoadSound.h"


LoadSound::LoadSound(const char* file_name)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		Mix_GetError();
	}
	sound = Mix_LoadWAV(file_name);
}
LoadSound::~LoadSound()
{}
void LoadSound::PlaySound()
{
	Mix_PlayChannel(-1, sound, 0);
}