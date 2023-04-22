#include "Player.h"
using std::cin;
using std::cout;
using std::endl;

Player::Player(char Side, char Race): side(Side), race(Race)
{
	camera_position = start_camera_position_p_1;
	camera.setCenter(sf::Vector2f(camera_position.x, camera_position.y));
	camera.setSize(sf::Vector2f(window_size.x, window_size.y));

    camera_control_with_mouse = false;

    for (auto unit : initial_units_1)
    {
        if (unit.number == 1)
        {
            units_list_1.push_back(new Zergling(unit.spawn_position.x, unit.spawn_position.y, 1));
        }
        else if (unit.number == 2)
        {
            units_list_1.push_back(new Hydralisk(unit.spawn_position.x, unit.spawn_position.y, 1));
        }
    }

    for (auto unit : initial_units_2)
    {
        if (unit.number == 1)
        {
            units_list_2.push_back(new Zergling(unit.spawn_position.x, unit.spawn_position.y, 2));
        }
        else if (unit.number == 2)
        {
            units_list_2.push_back(new Hydralisk(unit.spawn_position.x, unit.spawn_position.y, 2));
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

    for (auto unit : initial_units_1)
    {
        cout << "." << endl;  // debug
        if (unit.number == 1)
        {
            units_list_1.push_back(new Zergling(unit.spawn_position.x, unit.spawn_position.y, 1));
        }
        else if (unit.number == 2)
        {
            units_list_1.push_back(new Hydralisk(unit.spawn_position.x, unit.spawn_position.y, 1));
        }
    }
    cout << units_list_1.size() << endl;  // debug

    for (auto unit : initial_units_2)
    {
        if (unit.number == 1)
        {
            units_list_2.push_back(new Zergling(unit.spawn_position.x, unit.spawn_position.y, 2));
        }
        else if (unit.number == 2)
        {
            units_list_2.push_back(new Hydralisk(unit.spawn_position.x, unit.spawn_position.y, 2));
        }
    }
    cout << units_list_1.size() << endl;  // debug
}


Player::~Player()
{
}

//void Player::initialize_vector_of_lists()
//{
//    vector_of_lists.resize(2);
//}

bool Player::get_camera_control_with_mouse_as_true()
{
    return camera_control_with_mouse;
}

void Player::set_camera_control_with_mouse_as_true()
{
    camera_control_with_mouse = true;
}

void Player::set_camera_control_with_mouse_as_false()
{
    camera_control_with_mouse = false;
}

void Player::move_camera(sf::Vector2i mouse_position)
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

bool Player::check_selection_status()
{
    if (setected_objects.size() != 0)
        return true;
    else
        return false;
}

void Player::set_selection_status_as_true()
{
    has_selected_unit = true;
}

bool Player::check_if_unit_is_not_already_in_the_list(Object* object_)
{
    for (auto o : setected_objects)
    {
        if (o == object_)
            return false;
    }
    return true;
}
