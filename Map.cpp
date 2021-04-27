#include "Map.h"

GameObject* pipe1;
GameObject* pipe2;
GameObject* pipe3;

Map::Map()
{
	background1 = new GameObject("background.png", 0, 0);
	background2 = new GameObject("background.png", 432, 0);
	pipe1 = new GameObject("pipe.png", 832, -200);
	pipe2 = new GameObject("pipe.png", 1032, -200);
	pipe3 = new GameObject("pipe.png", 1232, -200);
	base1 = new GameObject("base.png", 0, 630);
	base2 = new GameObject("base.png", 432, 630);
	start_game = new GameObject("start_game.png", 40, 50);
	Menu_overgame = new GameObject("menu_overgame.png", 17, 190);
	Ok = new GameObject("ok.png", 25, 500);
	Resume = new GameObject("resume.png", 50, 50);
	Gameover = new GameObject("Gameover.png", 5, 50);
	Menu = new GameObject("menu.png", 250, 496);
	Continue = new GameObject("continue.png", 50, 50);
}
void Map::Reset_map()
{
	background1->Reset();
	background2->Reset();
	pipe1->Reset();
	pipe2->Reset();
	pipe3->Reset();
	base1->Reset();
	base2->Reset();
}
void Map::LoadMap()
{}
void Map::Update()
{
	background1->Update_background();
	background2->Update_background();
	pipe1->Update_pipe();
	pipe2->Update_pipe();
	pipe3->Update_pipe();
	base1->Update_background();
	base2->Update_background();
}
void Map::Update_startgame()
{
	background1->Update_background();
	background2->Update_background();
	base1->Update_background();
	base2->Update_background();
}
void Map::DrawMap()
{
	background1->Render();
	background2->Render();
	pipe1->Render();
	pipe2->Render();
	pipe3->Render();
	base1->Render();
	base2->Render();
	Resume->Render();
}
void Map::Draw_startgame()
{
	background1->Render();
	background2->Render();
	base1->Render();
	base2->Render();
	start_game->Render();
	
}
void Map::Draw_overgame()
{
	background1->Render();
	background2->Render();
	base1->Render();
	base2->Render();
	Ok->Render();
	Menu->Render();
	Gameover->Render();
	Menu_overgame->Render();
}
double Map::x_pos()
{
	if ((pipe1->pos_x() < 240) && (pipe1->pos_x() > 50))	return pipe1->pos_x();
	if ((pipe2->pos_x() < 240) && (pipe2->pos_x() > 50))	return pipe2->pos_x();
	if ((pipe3->pos_x() < 240) && (pipe3->pos_x() > 50))	return pipe3->pos_x();
	return 1000;
}
double Map::y_pos()
{
	if ((pipe1->pos_x() < 240) && (pipe1->pos_x() > 50))	return pipe1->pos_y();
	if ((pipe2->pos_x() < 240) && (pipe2->pos_x() > 50))	return pipe2->pos_y();
	if ((pipe3->pos_x() < 240) && (pipe3->pos_x() > 50))	return pipe3->pos_y();
	return 1000;
}