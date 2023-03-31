#pragma once
#include "global.h"
#include "object.h"
#include "vector"


struct initial_unit
{
	int number;
	position spawn_position;
};

extern std::vector<initial_unit> initial_units_1;

extern std::vector<initial_unit> initial_units_2;

extern position start_camera_position_p_1;

extern position window_size;