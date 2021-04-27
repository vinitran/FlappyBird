#pragma once
#include "Collision.h"

class Check_collision
{
public:
	Check_collision();
	~Check_collision();
	void collision_pipe();
	void collision_base();
	bool Colide_pipe();
	bool Colide_base();
	void Update_value();
	
private:
	int time_birdnotfly;
	double xpos_bird;
	double ypos_bird;
	double xpos_pipe;
	double ypos_pipe;
	double bird_velocity;
};
