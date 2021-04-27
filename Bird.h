#pragma once
#include "Game.hpp"
#include "GameObject.h"

class Bird {
public:
	Bird();
	~Bird();
	void Draw_bird_fly();
	void Draw_bird_notfly();
	void Update_bird();
	void conllision();
	void Click_bird();
	double x_pos();
	double y_pos();
	double velocity();
	int value_timenotfly();
	int value_simple();
	bool check_birdfly();
	void Reset_bird();
private:
};
