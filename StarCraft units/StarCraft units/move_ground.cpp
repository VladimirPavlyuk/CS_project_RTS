#include "move_ground.h"
#include "global.h"
#include <math.h>

int move_ground::get_v()
{
	return v;
}

void move_ground::get_coordinates(int x, int y)
{
	x_1 = x;
	y_1 = y;
	if (check_range(x_1, y_1) > 0.01)
		is_moving = true;
	else
		is_moving = false;
}

void move_ground::move()
{
	float v_x, v_y, d_x, d_y;
	v_x = floor((v * (x_1 - current_position.x) / check_range(x_1, y_1)) * 100) / 100;
	v_y = floor((v * (y_1 - current_position.y) / check_range(x_1, y_1)) * 100) / 100;
	d_x = floor(v_x * d_t_l * 100) / 100;
	d_y = floor(v_y * d_t_l * 100) / 100;

	if (x_1 - current_position.x < d_x)
		current_position.x = x_1;
	else
		current_position.x += d_x;

	if (y_1 - current_position.y < d_y)
		current_position.y = y_1;
	else
		current_position.y += d_y;

	if (check_range(x_1, y_1) <= 0.01)
		is_moving = false;

}
