#include "game.h"
#include "global.h"

game::game()
{
	//  create map, к карте будут прив€заны количество сторон и игроков.
	sides_number = sides_;  // ѕока что из global, затем выбор из разных карт с помощью config-файлов/
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
			//sides[side][player]  обойти список юнитов, проверить статус движени€, исполн€ть движение
		}
	}
}

void game::draw()
{
	// вывод на экран
}
