#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include "game.h"

int main()
{
	game current_game;
	while (current_game.check_status()) //
	{
		// std::cout << current_game.time_logical << " " << current_game.check_status() << std::endl;  // debug
		current_game.events();
		if (current_game.time_logical % 20 == 0)
			current_game.draw();
		if (current_game.time_logical % 10000 == 0)
			std::cout << current_game.time_logical << std::endl;  // debug
		current_game.time_logical ++;
	}
}