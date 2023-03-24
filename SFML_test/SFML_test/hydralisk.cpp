#include "hydralisk.h"
#include "object.h"

float hydralisk::V_initial = 100;

hydralisk::hydralisk(float x_spawn, float y_spawn) : movable_ground(x_spawn, y_spawn)
{
	v = V_initial;
	number = 2;
	radius = 30;
}

