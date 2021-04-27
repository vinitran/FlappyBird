#pragma once
#include "Bird.h"
#include "Map.h"

class Collision {
public:
	Collision();
	~Collision();

	bool Check_pipe(double x_posbird, double y_posbird, double x_pospipe, double y_pospipe);
	bool Check_base(double y_posbird, double y_posbase);

private:
	
};