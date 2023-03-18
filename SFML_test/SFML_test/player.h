#pragma once
#include <list>
#include "object.h"
#include "global.h"


class player
{

public:


	player();

	~player();

	void spawn_unit(int number, position spawn_position);

	bool has_selected_unit_check();	

	object* unit;

	std::list<object*> units_list;

	object* selected;

	char has_selected_unit;

	// char nickname[12];

	// char race;

	// char side;

	// char colour;

	// resourses player_resourses;

	// int units[120];  // уточнить число

	// int to_build[120];  // уточнить число

	//std::list<unit*>::iterator to_destroy[120] = { player_units.end() };

};
