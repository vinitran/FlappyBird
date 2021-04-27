#include "Collision.h"

Collision::Collision()
{}
Collision::~Collision()
{}

bool Collision::Check_base(double y_posbird, double y_posbase)
{
	if (y_posbird > y_posbase)
	{
		return true;
	}
	return false;
}

bool Collision::Check_pipe(double x_posbird, double y_posbird, double x_pospipe, double y_pospipe)
{
	if ((x_pospipe < x_posbird && x_posbird < x_pospipe + 67) && 
		( y_posbird < y_pospipe + 413 || (y_pospipe + 600 < y_posbird && y_posbird < y_pospipe + 1013)))
	{
		return true;
	}
	return false;
}