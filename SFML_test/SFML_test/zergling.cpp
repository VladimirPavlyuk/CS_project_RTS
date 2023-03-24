#include "zergling.h"
#include "movable_ground.h"
#include "object.h"

float zergling::V_initial = 100;

zergling::zergling(float x_spawn, float y_spawn) : movable_ground(x_spawn, y_spawn)
{
	v = V_initial;
	radius = 10.0;
	number = 1;
}