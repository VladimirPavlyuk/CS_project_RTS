#include "player.h"

player::player(char Side): side(Side)
{
	camera_position = start_camera_position_p_1;
	camera.setCenter(sf::Vector2f(camera_position.x, camera_position.y));
	camera.setSize(sf::Vector2f(window_size.x, window_size.y));

    camera_control_with_mouse = false;

    for (auto unit : initial_units_1)
    {
        if (unit.number == 1)
        {
            units_list_1.push_back(new zergling(unit.spawn_position.x, unit.spawn_position.y));
        }
        else if (unit.number == 2)
        {
            units_list_1.push_back(new hydralisk(unit.spawn_position.x, unit.spawn_position.y));
        }
    }

    for (auto unit : initial_units_2)
    {
        if (unit.number == 1)
        {
            units_list_2.push_back(new zergling(unit.spawn_position.x, unit.spawn_position.y));
        }
        else if (unit.number == 2)
        {
            units_list_2.push_back(new hydralisk(unit.spawn_position.x, unit.spawn_position.y));
        }
    }

    if (side == 1)
    {
        ally_units_list  = std::move(units_list_1);

        enemy_units_list = std::move(units_list_2);
    }

    else
    {
        ally_units_list  = std::move(units_list_2);

        enemy_units_list = std::move(units_list_1);
    };

}

player::~player()
{
}

bool player::get_camera_control_with_mouse_as_true()
{
    return camera_control_with_mouse;
}

void player::set_camera_control_with_mouse_as_true()
{
    camera_control_with_mouse = true;
}

void player::set_camera_control_with_mouse_as_false()
{
    camera_control_with_mouse = false;
}

void player::move_camera(sf::Vector2i mouse_position)
{
    float r_x = mouse_position.x - window_size.x / 2;
    float r_y = mouse_position.y - window_size.y / 2;
    float r = sqrt(r_x * r_x + r_y * r_y);
    float cos = r_x / r;
    float sin = r_y / r;
    float d_x = camera_speed * d_t_l * cos;
    float d_y = camera_speed * d_t_l * sin;
    camera_position.x += d_x;
    camera_position.y += d_y;
}

bool player::has_selected_unit_check()
{
	return has_selected_unit;
}

void player::set_selection_status_as_true()
{
    has_selected_unit = true;
}
