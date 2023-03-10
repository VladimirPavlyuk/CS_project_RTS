#include "object.h"

object::object(float x_spawn, float y_spawn)
{
	{
		is_moving = false;
		current_position.x = x_spawn;
		current_position.y = y_spawn;
		x_1 = current_position.x;
		y_1 = current_position.y;
	}
}

object::~object()
{
}

float object::check_range(float x, float y)
{
    return( sqrt( ((x - current_position.x) * (x - current_position.x)) + ((y - current_position.y) * (y - current_position.y)) ) );
};

void object::move()
{
	std::cout << "started moving" << std::endl;  // debug
	float v_x, v_y, d_x, d_y;
	v_x = floor((v * (x_1 - current_position.x) / check_range(x_1, y_1)) * 100) / 100;
	v_y = floor((v * (y_1 - current_position.y) / check_range(x_1, y_1)) * 100) / 100;
	d_x = v_x * d_t_l;
	d_y = v_y * d_t_l;

	std::cout << "x_1, y_1 " << x_1 << " " << y_1 << std::endl;  // debug
	std::cout << "range " << check_range(x_1, y_1) << std::endl;  // debug
	std::cout << "v " << v_x << " " << v_y << std::endl;  // debug
	std::cout << "d " << d_x << " " << d_y << std::endl;  // debug

	if (abs(x_1 - current_position.x) < d_x)
		current_position.x = x_1;
	else
		current_position.x += d_x;

	if (abs(y_1 - current_position.y) < d_y)
		current_position.y = y_1;
	else
		current_position.y += d_y;

	if (check_range(x_1, y_1) <= 0.01)
		is_moving = false;
}

position object::get_position()
{
	return current_position;
}

