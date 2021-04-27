#include "Sound.h"
#include "TextureManager.h"

Sound::Sound(const char* file_name)
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	sound1 = TextureManager::addSoundEffect(file_name);
}

void Sound::playSound()
{
	Mix_PlayChannel(-1, sound1, 0);
}