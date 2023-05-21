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
float Object::get_radius() const
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

position Object::get_position() const
{
	return current_position;
}

int Object::get_number() const
{
	return number;
}

void Object::move()
{
}

bool Object::get_move_status() const
{
	return true;
}

void Object::set_move_status_as_true()
{
}

void Object::set_move_status_as_false()
{
}

float Object::get_x_1() const
{
	return current_position.x;
}

float Object::get_y_1() const // Спросить!
{
	return current_position.y;
}

void Object::set_x_1(float new_x_1)
{
}

void Object::set_y_1(float new_y_1)
{
}
