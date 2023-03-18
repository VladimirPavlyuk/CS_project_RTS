#include "zergling.h"
#include "object.h"

zergling::zergling(float x_spawn, float y_spawn) : object(x_spawn, y_spawn)
{
	v = V;
	radius = 10.0;
	number = 1;
}