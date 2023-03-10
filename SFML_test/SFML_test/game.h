#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include "player.h"

class game
{



public:

	int check_status();

	game();

	~game();

	void events();

	void draw();


	bool is_running;

	player* player_1;

	sf::RenderWindow window;

	int time_logical;
};

