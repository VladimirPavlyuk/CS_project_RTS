#pragma once
#include "player.h"
class game
{
public:

	game();

	~game();


	int t; // global time, ���������� � ���������� �����

	bool is_running();

	void events();

	void draw();

	char map;

	int sides_number;

	int players_for_side_number;

	player** sides;

};

