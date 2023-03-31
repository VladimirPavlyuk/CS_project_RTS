#include "Hydralisk.h"
#include "Object.h"

float Hydralisk::V_initial = 100;

Hydralisk::Hydralisk(float x_spawn, float y_spawn) : Movable_ground(x_spawn, y_spawn)
{
	v = V_initial;
	number = 2;
	radius = 30;
}

