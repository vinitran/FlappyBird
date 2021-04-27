#pragma once
#include "LoadSound.h"

class PlaySound {
public:
	PlaySound();
	~PlaySound();
	void Sound_Click();
	void Sound_Point();
	void Sound_Hit();
	void Sound_Swoosh();
	void Sound_Die();

private:
	LoadSound* Sound_click;
	LoadSound* Sound_point;
	LoadSound* Sound_hit;
	LoadSound* Sound_swoosh;
	LoadSound* Sound_die;
};