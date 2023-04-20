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

	void end_run();

	void start_run();

	void move_order(sf::Vector2f move_to);

	player* player_1;

	sf::RenderWindow window;

	int time_logical;

	sf::Clock time_real;

	sf::Clock time_reset;

private:

	bool is_running;

};

