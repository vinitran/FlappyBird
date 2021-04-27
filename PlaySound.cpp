#include "PlaySound.h"

PlaySound::PlaySound()
{
	Sound_click = new LoadSound("wing.wav");
	Sound_point = new LoadSound("point.wav");
	Sound_hit = new LoadSound("hit.wav");
	Sound_swoosh = new LoadSound("swoosh.wav");
	Sound_die = new LoadSound("die.wav");
}
PlaySound::~PlaySound()
{}
void PlaySound::Sound_Click()
{
	Sound_click->PlaySound();
}
void PlaySound::Sound_Point()
{
	Sound_point->PlaySound();
}
void PlaySound::Sound_Hit()
{
	Sound_hit->PlaySound();
}
void PlaySound::Sound_Swoosh()
{
	Sound_swoosh->PlaySound();
}
void PlaySound::Sound_Die()
{
	Sound_die->PlaySound();
}