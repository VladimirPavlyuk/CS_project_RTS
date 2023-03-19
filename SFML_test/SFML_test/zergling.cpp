#include "zergling.h"
#include "movable_ground.h"
#include "object.h"

zergling::zergling(float x_spawn, float y_spawn) : movable_ground(x_spawn, y_spawn)
{
	v = V;
	radius = 10.0;
	number = 1;
}