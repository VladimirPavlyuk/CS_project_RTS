//#include "Unit.h"
#include "Zergling.h"
#include "Movable_ground.h"
#include "Object.h"

float Zergling::V_initial = 100;

Zergling::Zergling(float x_spawn, float y_spawn/*, char Side*/) : Movable_ground(x_spawn, y_spawn)/*, Unit(Side)*/
{
	//max_HP = 35;
	//current_HP = max_HP;
	v = V_initial;
	radius = 10.0;
	number = 1;
}