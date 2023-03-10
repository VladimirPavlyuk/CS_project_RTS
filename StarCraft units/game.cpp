#include "game.h"
#include "global.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

game::game()
{
	//  create map, к карте будут прив€заны количество сторон и игроков.
	sides_number = sides_global;  // ѕока что из global, затем выбор из разных карт с помощью config-файлов/
	players_for_side_number = players_for_side_global;
	sides = new player * [sides_number];
	for (int side = 0; side < sides_number; side++)
	{
		sides[side] = new player[players_for_side_number];
	}
	// init players



}

game::~game()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
}

int game::get_global_time()
{
	return global_time.getElapsedTime().asMilliseconds();
}

bool game::is_running()
{
	return false;
}

void game::events()
{
	for (int side = 0; side < sides_number; side++)
	{
		for (int player = 0; player < players_for_side_number; player++)
		{
			//sides[side][player]  обойти список юнитов, проверить статус движени€, исполн€ть движение
		}
	}
}

void game::draw()
{
	// вывод на экран
}
