#include "object.h"

object::object(float x_spawn, float y_spawn)
{
	{
		current_position.x = x_spawn;
		current_position.y = y_spawn;
	}
}

object::~object()
{
}

float object::check_range(float x, float y)
{
    return( sqrt( ((x - current_position.x) * (x - current_position.x)) + ((y - current_position.y) * (y - current_position.y)) ) );
}
float object::get_radius()
{
	return radius;
}
;

position object::get_position()
{
	return current_position;
}

int object::get_number()
{
	return number;
}

void object::move()
{
}

bool object::get_move_status()
{
	return true;
}

void object::set_move_status_as_true()
{
}

void object::set_move_status_as_false()
{
}

float object::get_x_1()
{
	return current_position.x;
}

float object::get_y_1()  // Спросить!
{
	return current_position.y;
}

void object::set_x_1(float new_x_1)
{
}

void object::set_y_1(float new_y_1)
{
}
