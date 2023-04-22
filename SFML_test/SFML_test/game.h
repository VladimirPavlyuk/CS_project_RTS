#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include "Player.h"
#include "Map.h"

class Game
{



public:

	int check_status();

	Game();

	~Game();

	void move_order(sf::Vector2f move_to);

	bool check_if_position_is_available_for_movement(sf::Vector2f point, Object* unit_);

	void events();

	void draw();

	void end_run();

	void start_run();

	Player* player_1;

	sf::RenderWindow window;

	int time_logical;

	sf::Clock time_real;

	sf::Clock time_reset;

	Map* map;

private:

	bool is_running;

};

