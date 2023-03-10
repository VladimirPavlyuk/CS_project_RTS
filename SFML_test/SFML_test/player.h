#pragma once
#include <list>
#include "object.h"


class player
{



public:

	player();

	~player();

	object* unit;

	char nickname[12];

	char race;

	char side;

	char colour;

	unsigned int minerals;

	struct resourses
	{
		int minerals;
		int gas;
		int supply_available;
		int supply_current;
	};

	resourses player_resourses;

	int units[120];  // уточнить число

	int to_build[120];  // уточнить число

	//std::list<unit*>::iterator to_destroy[120] = { player_units.end() };

};
