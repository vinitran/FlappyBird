#include "Map.h"
#include "Bird.h"
#include "GameObject.h"
#include "point.h"
#include "PlaySound.h"
#include "Check_collision.h"

Map* map;
Bird* bird;
PlaySound* sound;
Point* point;
Check_collision* check_collision;
SDL_Renderer* Game::renderer = nullptr;
int xMouse, yMouse;
int times_hit, times_die;
int times;
bool Over_round0;
bool Over_round1;
bool Over_round2;
bool Resume;

Game::Game()
{
	start_game = false;
	isRunning = false;
	bird_alive = true;
	times_hit = 0;
	times_die = 0;
	times = 0;
	GameOver = false;
	round = 0;
	Over_round0 = false;
	Over_round1 = true;
	Over_round2 = true;
	Resume = false;
}
Game::~Game()
{}
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		windown = SDL_CreateWindow(title, xpos, ypos, width, height, 0);
		renderer = SDL_CreateRenderer(windown, -1, 0);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		isRunning = true;
	}
	else isRunning = false;
	SDL_Init(SDL_INIT_AUDIO);
	map = new Map();
	bird = new Bird();
	sound = new PlaySound();
	point = new Point();
	check_collision = new Check_collision();
	map->LoadMap();
}
void Game::event()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
		
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				SDL_GetMouseState(&xMouse, &yMouse);
				if (round == 0)
				{
					sound->Sound_Swoosh();
					round = 1;
					Over_round0 = true;
					Over_round1 = false;
				}
				if(round == 1)
				{
					if (bird_alive == true && Resume == false)
					{
						bird->Click_bird();
						sound->Sound_Click();
						point->Load_point();
					}
					if ((50 < xMouse && xMouse < 212) && (50 < yMouse && yMouse < 106))
					{
						sound->Sound_Swoosh();
						for (int i = 0; i < 2; i++)
						{
							if (Resume == 1)
							{
								Resume = false;
								break;
							}
							else
							{
								Resume = true;
								break;
							}
						}
					}
				}
				if (round == 2)
				{
					if ((25 < xMouse && xMouse < 187) && (500 < yMouse && yMouse < 556))
					{
						round = 0;
						bird->Reset_bird();
						map->Reset_map();
						point->Reset_point();
						GameOver = false;
						bird_alive = true;
						Over_round0 = false;
						Over_round1 = true;
						Over_round2 = true;
						times_die = 0;
						times_hit = 0;
					}
					sound->Sound_Swoosh();
				}
			}
			
		default:
			break;
	}
}
void Game::update()
{
	point->Load_point();
	if (Resume == false)
	{
		if (Over_round0 == false && round == 0)
		{
			map->Update_startgame();
		}
		check_collision->Update_value();
		if (round == 1 && Over_round1 == false)
		{

			if (check_collision->Colide_pipe() == false && check_collision->Colide_base() == false
				&& bird_alive == true)
			{
				map->Update();
			}
			if (check_collision->Colide_pipe() == true || check_collision->Colide_base() == true)
			{
				times_hit++;
				bird_alive = false;
				if (times_hit == 1)	sound->Sound_Hit();
			}
			if (check_collision->Colide_pipe() == true && check_collision->Colide_base() == false)
			{
				times_die++;
				if (times_die == 1)	sound->Sound_Die();
			}
			if (check_collision->Colide_base() == true && Over_round1 == false)
			{
				Over_round1 = true;
				Over_round2 == false;
				GameOver = true;

			}
			std::cout << endl;
			if (check_collision->Colide_base() == false)		bird->Update_bird();
		}
		if (Over_round1 == true && round == 1)	round = 2;

	}
	
}
void Game::render()
{
	SDL_RenderClear(renderer);
	if (round == 1)
	{
		map->DrawMap();
		bird->Draw_bird_fly();
		point->Draw_point();
		if(Resume == true)	map->Continue->Render();
	}
	if (round == 0)
	{
		map->Draw_startgame();
	}
	if (round == 2)
	{
		map->Draw_overgame();
		point->Draw_point_overgame();
		point->Draw_point_Best();
	}
	SDL_RenderPresent(renderer);
}
void Game::clean()
{
	SDL_DestroyWindow(windown);
	SDL_DestroyRenderer(renderer);
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}
void Game::collision()
{
	check_collision->collision_base();
	check_collision->collision_pipe();
}
bool Game::Running()
{ 
	return isRunning; 
}
