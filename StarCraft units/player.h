#pragma once
#include <list>
#include "unit (lvl_1 class).h"


class player
{

public:
	
	player();

	~player();

	list<unit*> player_units;

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

	list<unit*>::iterator to_destroy[120] = { player_units.end() }; 
	
};

