#include "Movable_ground.h"

Movable_ground::Movable_ground(float x_spawn, float y_spawn, char Side) : Object(x_spawn, y_spawn, Side)
{
	is_moving = false;
	x_1 = current_position.x;
	y_1 = current_position.y;
}

void Movable_ground::move()
{

	if (check_range(x_1, y_1) > 0.01)
	{
		float v_x, v_y, d_x, d_y;
		v_x = floor((v * (x_1 - current_position.x) / check_range(x_1, y_1)) * 100) / 100;
		v_y = floor((v * (y_1 - current_position.y) / check_range(x_1, y_1)) * 100) / 100;
		d_x = v_x * d_t_l;
		d_y = v_y * d_t_l;

		if (abs(x_1 - current_position.x) < d_x)
			current_position.x = x_1;
		else
			current_position.x += d_x;

		if (abs(y_1 - current_position.y) < d_y)
			current_position.y = y_1;
		else
			current_position.y += d_y;
	}
}

bool Movable_ground::get_move_status()
{
	return is_moving;
}

void Movable_ground::set_move_status_as_true()
{
	is_moving = true;
}

void Movable_ground::set_move_status_as_false()
{
	is_moving = false;
}

float Movable_ground::get_x_1()
{
	return x_1;
}

float Movable_ground::get_y_1()
{
	return y_1;
}

void Movable_ground::set_x_1(float new_x_1)
{
	x_1 = new_x_1;
}

void Movable_ground::set_y_1(float new_y_1)
{
	y_1 = new_y_1;
}
