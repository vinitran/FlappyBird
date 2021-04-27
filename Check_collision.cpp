#include "Check_collision.h"
#include "List_coordinates.h"

Bird* check_collision_bird;
Map* check_collision_pipe;
Collision* check_colision;
List_coordinates* List_image[15];
int value_simple;
bool colide_pipe;
bool colide_base;

Check_collision::Check_collision()
{
	check_colision = new Collision();
	check_collision_bird = new Bird();
	check_collision_pipe = new Map();
	List_image[0] = new List_coordinates("list_image_mid.txt");				//list_image_mid
	List_image[1] = new List_coordinates("list_image_up.txt");				//list_image_up
	List_image[2] = new List_coordinates("list_image_down.txt");			//list_image_down
	List_image[3] = new List_coordinates("list_image_mid_notfly340.txt");	//list_image_mid_notfly340
	List_image[4] = new List_coordinates("list_image_mid_notfly350.txt");	//list_image_mid_notfly350
	List_image[5] = new List_coordinates("list_image_mid_notfly360.txt");	//list_image_mid_notfly360
	List_image[6] = new List_coordinates("list_image_mid_notfly10.txt");	//list_image_mid_notfly10
	List_image[7] = new List_coordinates("list_image_mid_notfly20.txt");	//list_image_mid_notfly20
	List_image[8] = new List_coordinates("list_image_mid_notfly30.txt");	//list_image_mid_notfly30
	List_image[9] = new List_coordinates("list_image_mid_notfly40.txt");	//list_image_mid_notfly40
	List_image[10] = new List_coordinates("list_image_mid_notfly50.txt");	//list_image_mid_notfly50
	List_image[11] = new List_coordinates("list_image_mid_notfly60.txt");	//list_image_mid_notfly60
	List_image[12] = new List_coordinates("list_image_mid_notfly70.txt");	//list_image_mid_notfly70
	List_image[13] = new List_coordinates("list_image_mid_notfly80.txt");	//list_image_mid_notfly80
	List_image[14] = new List_coordinates("list_image_mid_notfly90.txt");	//list_image_mid_notfly90
	colide_pipe = false;
	colide_base = false;
}
Check_collision::~Check_collision()
{}

void Check_collision::Update_value()
{
	xpos_bird = check_collision_bird->x_pos();
	ypos_bird = check_collision_bird->y_pos();
	xpos_pipe = check_collision_pipe->x_pos();
	ypos_pipe = check_collision_pipe->y_pos();
	bird_velocity = check_collision_bird->velocity();
	value_simple = check_collision_bird->value_simple();
	time_birdnotfly = check_collision_bird->value_timenotfly();
}

void Check_collision::collision_pipe()
{
	for (int i = 0; i < 15; i++)
	{
		if (check_colision->Check_pipe(xpos_bird + List_image[value_simple]->arr_position[i][0],
			ypos_bird + List_image[value_simple]->arr_position[i][1], xpos_pipe, ypos_pipe) == true)
		{
			colide_pipe = true;
			break;
		}
		else 
		{
			colide_pipe = false;
		}
	}
}

void Check_collision::collision_base()
{
	for (int i = 0; i < 15; i++)
	{
		if (check_colision->Check_base(	ypos_bird + List_image[value_simple]->arr_position[i][1], 630) == true)
		{
			colide_base = true;
			break;
		}
		else
		{
			colide_base = false;
		}
	}
}
bool Check_collision::Colide_pipe()
{
	if (colide_pipe == true)	return true;
	return false;
}
bool Check_collision::Colide_base()
{
	if (colide_base == true)	return true;
	return false;
}
