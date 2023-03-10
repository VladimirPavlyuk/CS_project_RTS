#include <iostream>
#include "player.h"
#include "unit.h"
#include "game.h"
#include <SFML/Graphics.hpp>

int main()
{
	game current_game;
	while (current_game.is_running())
	{
		current_game.events();
		if (current_game.t % 20 == 0)
			current_game.draw();
		current_game.t++;
	}
}