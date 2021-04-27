#pragma once
#include "Game.hpp"
#include "GameObject.h"
#include "List_coordinates.h"

class Map{
public:
	Map();
	~Map();
	void LoadMap();
	void DrawMap();
	void Draw_startgame();
	void Update();
	void Update_startgame();
	void Draw_overgame();
	double x_pos();
	double y_pos();
	void Reset_map();
	GameObject* Continue;
	GameObject* Resume;
private:
	GameObject* background1;
	GameObject* background2;
	GameObject* base1;
	GameObject* base2;
	GameObject* start_game;
	GameObject* Menu_overgame;
	
	GameObject* Ok;
	GameObject* Gameover;
	GameObject* Menu;
	
};
