#include "point.h"

GameObject* image1[10];
GameObject* image2[10];
GameObject* image3[10];
GameObject* image4[10];
GameObject* image5[10];
GameObject* image6[10];

Point::Point()
{
	//
	image1[0] = new GameObject("0.png", 182, 50);
	image1[1] = new GameObject("1.png", 200, 50);
	image1[2] = new GameObject("2.png", 182, 50);
	image1[3] = new GameObject("3.png", 182, 50);
	image1[4] = new GameObject("4.png", 182, 50);
	image1[5] = new GameObject("5.png", 182, 50);
	image1[6] = new GameObject("6.png", 182, 50);
	image1[7] = new GameObject("7.png", 182, 50);
	image1[8] = new GameObject("8.png", 182, 50);
	image1[9] = new GameObject("9.png", 182, 50);
	//
	image2[0] = new GameObject("0.png", 230, 50);
	image2[1] = new GameObject("1.png", 230, 50);
	image2[2] = new GameObject("2.png", 230, 50);
	image2[3] = new GameObject("3.png", 230, 50);
	image2[4] = new GameObject("4.png", 230, 50);
	image2[5] = new GameObject("5.png", 230, 50);
	image2[6] = new GameObject("6.png", 230, 50);
	image2[7] = new GameObject("7.png", 230, 50);
	image2[8] = new GameObject("8.png", 230, 50);
	image2[9] = new GameObject("9.png", 230, 50);
	//
	image3[0] = new GameObject("0_point.png", 350, 250);
	image3[1] = new GameObject("1_point.png", 355, 250);
	image3[2] = new GameObject("2_point.png", 350, 250);
	image3[3] = new GameObject("3_point.png", 350, 250);
	image3[4] = new GameObject("4_point.png", 350, 250);
	image3[5] = new GameObject("5_point.png", 350, 250);
	image3[6] = new GameObject("6_point.png", 350, 250);
	image3[7] = new GameObject("7_point.png", 350, 250);
	image3[8] = new GameObject("8_point.png", 350, 250);
	image3[9] = new GameObject("9_point.png", 350, 250);
	//
	image4[0] = new GameObject("0_point.png", 320, 250);
	image4[1] = new GameObject("1_point.png", 330, 250);
	image4[2] = new GameObject("2_point.png", 320, 250);
	image4[3] = new GameObject("3_point.png", 320, 250);
	image4[4] = new GameObject("4_point.png", 320, 250);
	image4[5] = new GameObject("5_point.png", 320, 250);
	image4[6] = new GameObject("6_point.png", 320, 250);
	image4[7] = new GameObject("7_point.png", 320, 250);
	image4[8] = new GameObject("8_point.png", 320, 250);
	image4[9] = new GameObject("9_point.png", 320, 250);
	//
	image5[0] = new GameObject("0_point.png", 350, 320);
	image5[1] = new GameObject("1_point.png", 355, 320);
	image5[2] = new GameObject("2_point.png", 350, 320);
	image5[3] = new GameObject("3_point.png", 350, 320);
	image5[4] = new GameObject("4_point.png", 350, 320);
	image5[5] = new GameObject("5_point.png", 350, 320);
	image5[6] = new GameObject("6_point.png", 350, 320);
	image5[7] = new GameObject("7_point.png", 350, 320);
	image5[8] = new GameObject("8_point.png", 350, 320);
	image5[9] = new GameObject("9_point.png", 350, 320);
	//
	image6[0] = new GameObject("0_point.png", 320, 320);
	image6[1] = new GameObject("1_point.png", 330, 320);
	image6[2] = new GameObject("2_point.png", 320, 320);
	image6[3] = new GameObject("3_point.png", 320, 320);
	image6[4] = new GameObject("4_point.png", 320, 320);
	image6[5] = new GameObject("5_point.png", 320, 320);
	image6[6] = new GameObject("6_point.png", 320, 320);
	image6[7] = new GameObject("7_point.png", 320, 320);
	image6[8] = new GameObject("8_point.png", 320, 320);
	image6[9] = new GameObject("9_point.png", 320, 320);
}
void Point::Load_point()
{}
void Point::Draw_point()
{
	if (image1[0]->point1() > 0)
	{
		for (int i = 0; i <= 9; i++)
		{
			image2[i]->Updatepos_point2();
			image1[i]->Updatepos_point1();
			if (image1[0]->point1() == i)	image1[i]->Render();
			if (image2[0]->point2() == i)	image2[i]->Render();
		}
	}
	if (image1[0]->point1() == 0)
	{
		for (int i = 0; i <= 9; i++)
		{
			image2[i]->Updatepos_point1();
			if (image2[0]->point2() == i)	image2[i]->Render();
		}
	}
}
void Point::Draw_point_overgame()
{

	if (image1[0]->point1() > 0)
	{
		for (int i = 0; i <= 9; i++)
		{
			if (image4[0]->point1() == i)	image4[i]->Render();
			if (image3[0]->point2() == i)	image3[i]->Render();
		}
	}
	if (image1[0]->point1() == 0)
	{
		for (int i = 0; i <= 9; i++)
		{
			
			if (image3[0]->point2() == i)	image3[i]->Render();
		}
	}
}
void Point::Draw_point_Best()
{

	if (image1[0]->point1() > 0)
	{
		for (int i = 0; i <= 9; i++)
		{
			if (image6[0]->point1() == i)	image6[i]->Render();
			if (image5[0]->point2() == i)	image5[i]->Render();
		}
	}
	if (image1[0]->point1() == 0)
	{
		for (int i = 0; i <= 9; i++)
		{

			if (image5[0]->point2() == i)	image5[i]->Render();
		}
	}
}
void Point::Reset_point()
{
	for (int i = 0; i < 10; i++)
	{
		image1[i]->Reset();
		image2[i]->Reset();
		image3[i]->Reset();
		image4[i]->Reset();
		image5[i]->Reset();
		image6[i]->Reset();
	}
}