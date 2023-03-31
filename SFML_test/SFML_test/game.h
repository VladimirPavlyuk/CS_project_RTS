#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include "Player.h"

class Game
{



public:

	int check_status();

	Game();

	~Game();

	void events();

	void draw();

	void end_run();

	void start_run();

	Player* player_1;

	sf::RenderWindow window;

	int time_logical;

	sf::Clock time_real;

	sf::Clock time_reset;

private:

	bool is_running;

};

