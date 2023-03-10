#include "game.h"
#include "global.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

game::game()
{
	//  create map, � ����� ����� ��������� ���������� ������ � �������.
	sides_number = sides_global;  // ���� ��� �� global, ����� ����� �� ������ ���� � ������� config-������/
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
			//sides[side][player]  ������ ������ ������, ��������� ������ ��������, ��������� ��������
		}
	}
}

void game::draw()
{
	// ����� �� �����
}
