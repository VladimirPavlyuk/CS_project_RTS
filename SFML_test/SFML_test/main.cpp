#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>	
#include <cmath>
#include "game.h"
// Волновой алгоритм
// Поис путей, перграды из многоугольников
// z-order
int main()
{
	game current_game;
	while (current_game.check_status()) //
	{
		current_game.time_reset.restart();
		// std::cout << current_game.time_logical << " " << current_game.check_status() << std::endl;  // debug
		current_game.events();
		if (current_game.time_logical % 20 == 0)
			current_game.draw();
		//if (current_game.time_logical % 10000 == 0)
		//	std::cout << current_game.time_logical << std::endl;  // debug
		while (current_game.time_reset.getElapsedTime().asMilliseconds() < 1)
		{ }
		//std::cout << current_game.time_logical << " " << current_game.time_real.getElapsedTime().asMilliseconds() << " "  // Debug
		//	<< current_game.time_reset.getElapsedTime().asMicroseconds() << std::endl;
		current_game.time_logical ++;
	}
}