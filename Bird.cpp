#include "Bird.h"

GameObject* Bird_info[15];
int time_notfly;
int time_fly;
bool bird_fly;
int simple;

Bird::Bird()
{
	simple = 0;
	time_fly = 0;
	bird_fly = false;
	time_notfly = 0;
	Bird_info[0] =	new GameObject("bird_down_330.png", 86, 400);			//bird_image_down
	Bird_info[1] =	new GameObject("bird_mid_330.png", 86, 400);			//bird_image_mid
	Bird_info[2] =	new GameObject("bird_up_330.png", 86, 400);				//bird_image_up
	Bird_info[3] =	new GameObject("bird_mid_notfly_340.png", 86, 400);		//bird_image_mid_notfly340
	Bird_info[4] =	new GameObject("bird_mid_notfly_350.png", 86, 400);		//bird_image_mid_notfly350
	Bird_info[5] =	new GameObject("bird_mid_notfly_360.png", 86, 400);		//bird_image_mid_notfly360
	Bird_info[6] =	new GameObject("bird_mid_notfly_10.png", 86, 400);		//bird_image_mid_notfly10
	Bird_info[7] =	new GameObject("bird_mid_notfly_20.png", 86, 400);		//bird_image_mid_notfly20
	Bird_info[8] =	new GameObject("bird_mid_notfly_30.png", 86, 400);		//bird_image_mid_notfly30
	Bird_info[9] =	new GameObject("bird_mid_notfly_40.png", 86, 400);		//bird_image_mid_notfly40
	Bird_info[10] =	new GameObject("bird_mid_notfly_50.png", 86, 400);		//bird_image_mid_notfly50
	Bird_info[11] =	new GameObject("bird_mid_notfly_60.png", 86, 400);		//bird_image_mid_notfly60
	Bird_info[12] =	new GameObject("bird_mid_notfly_70.png", 86, 400);		//bird_image_mid_notfly70
	Bird_info[13] =	new GameObject("bird_mid_notfly_80.png", 86, 400);		//bird_image_mid_notfly80
	Bird_info[14] =	new GameObject("bird_mid_notfly_90.png", 86, 400);		//bird_image_mid_notfly90
}

void Bird::Draw_bird_fly()
{
	if (bird_fly == true)
	{
		if ((time_fly % 18 >= 0) && (time_fly % 18 < 3))
		{
			simple = 0;
			Bird_info[0]->Render();
		}
		if ((time_fly % 18 >= 3) && (time_fly % 18 < 6)) 
		{
			simple = 1;
			Bird_info[1]->Render();
		}
		if ((time_fly % 18 >= 6) && (time_fly % 18 < 9))
		{
			simple = 2;
			Bird_info[2]->Render();
		}
		if ((time_fly % 18 >= 9) && (time_fly % 18 < 12)) 
		{
			simple = 2;
			Bird_info[2]->Render();
		}
		if ((time_fly % 18 >= 12) && (time_fly % 18 < 15)) 
		{
			simple = 1;
			Bird_info[1]->Render();
		}
		if ((time_fly % 18 >= 15) && (time_fly % 18 < 18))
		{
			simple = 0;
			Bird_info[0]->Render();
		}
	}
	else
	{
		if ((time_notfly >= 0) && (time_notfly < 5))
		{
			simple = 3;
			Bird_info[3]->Render();
		}
		if ((time_notfly >= 5) && (time_notfly < 10)) 
		{
			simple = 4;
			Bird_info[4]->Render();
		}
		if ((time_notfly >= 10) && (time_notfly < 15)) 
		{
			simple = 5;
			Bird_info[5]->Render();
		}
		if ((time_notfly >= 15) && (time_notfly < 20)) 
		{
			simple = 6;
			Bird_info[6]->Render();
		}
		if ((time_notfly >= 20) && (time_notfly < 25)) 
		{
			simple = 7;
			Bird_info[7]->Render();
		}
		if ((time_notfly >= 25) && (time_notfly < 30)) 
		{
			simple = 8;
			Bird_info[8]->Render();
		}
		if ((time_notfly >= 30) && (time_notfly < 35)) 
		{
			simple = 9;
			Bird_info[9]->Render();
		}
		if ((time_notfly >= 35) && (time_notfly < 40)) 
		{
			simple = 10;
			Bird_info[10]->Render();
		}
		if ((time_notfly >= 40) && (time_notfly < 45)) 
		{
			simple = 11;
			Bird_info[11]->Render();
		}
		if ((time_notfly >= 45) && (time_notfly < 50)) 
		{
			simple = 12;
			Bird_info[12]->Render();
		}
		if ((time_notfly >= 50) && (time_notfly < 55)) 
		{
			simple = 13;
			Bird_info[13]->Render();
		}
		if (time_notfly >= 55)
		{
			simple = 14;
			Bird_info[14]->Render();
		}
	}
}

void Bird::Update_bird()
{
	time_fly++;
	for (int i = 0; i < 15; i++)
	{
		Bird_info[i]->Update_bird();
	}
	if (Bird_info[0]->bird_movement < 0) bird_fly = true;
	if (Bird_info[0]->bird_movement >= 0) bird_fly = false;
	if (bird_fly == true) time_notfly = 0;
	if (bird_fly == false) time_notfly++;
}
void Bird::Reset_bird()
{
	simple = 0;
	time_fly = 0;
	bird_fly = false;
	time_notfly = 0;
	for (int i = 0; i < 15; i++)
	{
		Bird_info[i]->Reset();
	}
}
void Bird::Click_bird()
{
	for (int i = 0; i < 15; i++)
	{
		Bird_info[i]->Click();
	}
}
double Bird::x_pos()
{
	return Bird_info[0]->pos_x();
}
double Bird::y_pos()
{
	return Bird_info[0]->pos_y();
}
double Bird::velocity()
{
	return Bird_info[0]->bird_movement;
}
int Bird::value_timenotfly()
{
	return time_notfly;
}
int Bird::value_simple()
{
	return simple;
}
bool Bird::check_birdfly()
{
	if (bird_fly == true)
	{
		return true;
	}
	return false;
}