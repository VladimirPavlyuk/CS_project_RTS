#include "game.h"
#include "global.h"

game::game()
{
	//  create map, � ����� ����� ��������� ���������� ������ � �������.
	sides_number = sides_;  // ���� ��� �� global, ����� ����� �� ������ ���� � ������� config-������/
	players_for_side_number = players_for_side_;
	sides = new player * [sides_number];
	for (int side = 0; side < sides_number; side++)
	{
		sides[side] = new player[players_for_side_number];
	}
	// init players



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
