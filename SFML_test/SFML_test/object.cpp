#include "Object.h"

Object::Object(float x_spawn, float y_spawn, char Side)
{
	{
		current_position.x = x_spawn;
		current_position.y = y_spawn;
		side = Side;
	}
}

Object::~Object()
{
}

float Object::check_range(float x, float y)
{
    return( sqrt( ((x - current_position.x) * (x - current_position.x)) + ((y - current_position.y) * (y - current_position.y)) ) );
}
float Object::square_range(float x, float y)
{
	return ((x - current_position.x) * (x - current_position.x)) + ((y - current_position.y) * (y - current_position.y));
}
float Object::get_radius()
{
	return radius;
}

char Object::get_side() const
{
	return side;
}

void Object::take_damage(int value)
{
	Current_HP -= value; 
}

position Object::get_position()
{
	return current_position;
}

int Object::get_number()
{
	return number;
}

void Object::move()
{
}

bool Object::get_move_status()
{
	return true;
}

void Object::set_move_status_as_true()
{
}

void Object::set_move_status_as_false()
{
}

float Object::get_x_1()
{
	return current_position.x;
}

float Object::get_y_1()  // Спросить!
{
	return current_position.y;
}

void Object::set_x_1(float new_x_1)
{
}

void Object::set_y_1(float new_y_1)
{
}
