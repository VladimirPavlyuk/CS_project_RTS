#include "hydralisk.h"
#include "object.h"

hydralisk::hydralisk(float x_spawn, float y_spawn) : object(x_spawn, y_spawn)
{
	v = V;
	number = 2;
	radius = 30;
}

