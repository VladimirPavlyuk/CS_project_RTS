#pragma once
#include "global.h"
#include "object.h"
#include "vector"


struct initial_unit
{
	int number;
	position spawn_position;
};

extern std::vector<initial_unit> initial_units;