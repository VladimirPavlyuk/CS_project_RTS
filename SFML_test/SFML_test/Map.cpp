#include "Map.h"

Map::Map()
{
    if (!texture_grey.loadFromFile("./textures/grey.png", sf::IntRect(0, 0, 50, 50)));
    if (!texture_white.loadFromFile("./textures/white.png", sf::IntRect(0, 0, 50, 50)));
    if (!texture_black.loadFromFile("./textures/black.png", sf::IntRect(0, 0, 50, 50)));


    for (int i = 0; i < map_size.y + 2; i++)
    {
        outskirt_left[0][i].building_on_tile = false;
        outskirt_left[0][i].is_buildable = false;
        outskirt_left[0][i].is_passable = false;
        outskirt_left[0][i].is_ramp = false;
        outskirt_left[0][i].level = 0;
        outskirt_left[0][i].location.x = -1;
        outskirt_left[0][i].location.y = i - 1;
        outskirt_left[0][i].sprite_.setTexture(texture_black);
        outskirt_left[0][i].sprite_.setPosition(-1 * 50, (i - 1) * 50);
    }

    for (int i = 0; i < map_size.y + 2; i++)
    {
        outskirt_right[0][i].building_on_tile = false;
        outskirt_right[0][i].is_buildable = false;
        outskirt_right[0][i].is_passable = false;
        outskirt_right[0][i].is_ramp = false;
        outskirt_right[0][i].level = 0;
        outskirt_right[0][i].location.x = map_size.x;
        outskirt_right[0][i].location.y = i - 1;
        outskirt_right[0][i].sprite_.setTexture(texture_black);
        outskirt_right[0][i].sprite_.setPosition(map_size.x * 50, (i - 1) * 50);
    }

    for (int i = 0; i < map_size.x; i++)
    {
        outskirt_top[i][0].building_on_tile = false;
        outskirt_top[i][0].is_buildable = false;
        outskirt_top[i][0].is_passable = false;
        outskirt_top[i][0].is_ramp = false;
        outskirt_top[i][0].level = 0;
        outskirt_top[i][0].location.x = i;
        outskirt_top[i][0].location.y = map_size.y;
        outskirt_top[i][0].sprite_.setTexture(texture_black);
        outskirt_top[i][0].sprite_.setPosition(i * 50, map_size.y * 50);
    }

    for (int i = 0; i < map_size.x; i++)
    {
        outskirt_bottom[i][0].building_on_tile = false;
        outskirt_bottom[i][0].is_buildable = false;
        outskirt_bottom[i][0].is_passable = false;
        outskirt_bottom[i][0].is_ramp = false;
        outskirt_bottom[i][0].level = 0;
        outskirt_bottom[i][0].location.x = i;
        outskirt_bottom[i][0].location.y = -1;
        outskirt_bottom[i][0].sprite_.setTexture(texture_black);
        outskirt_bottom[i][0].sprite_.setPosition(i * 50, -1 * 50);
    }

    for (int i = 1; i <= map_size.x; i++)
    {
        std::cout << i << std::endl;
        for (int j = 1; j <= map_size.y; j++)
        {
            map_tiles[i][j].building_on_tile = false;
            map_tiles[i][j].is_buildable = true;
            map_tiles[i][j].is_ramp = false;
            map_tiles[i][j].level = 1;
            map_tiles[i][j].location.x = i;
            map_tiles[i][j].location.y = j;
            if (j % 6 == 0 and i % 4 == 0)
            {
                map_tiles[i][j].sprite_.setTexture(texture_grey);
                map_tiles[i][j].is_passable = false;
            }
            else
            {
                map_tiles[i][j].sprite_.setTexture(texture_white);
                map_tiles[i][j].is_passable = true;
            }
            map_tiles[i][j].sprite_.setPosition((i - 1) * 50, (j - 1) * 50);
        }
    }
}

Map::~Map()
{
}

bool Map::chech_if_point_belongs_to_map(sf::Vector2f point)
{
    if (point.x <= map_size.x * 50 and point.x >= 0 and point.y <= map_size.y * 50 and point.y >= 0)
        return true;
    else
        return false;
}

bool Map::check_if_tile_belongs_to_map(sf::Vector2i tile_)
{
    if (tile_.x <= map_size.x and tile_.x >= 0 and tile_.y <= map_size.y and tile_.y >= 0)
        return true;
    else
        return false;
}

sf::Vector2i Map::get_tile_by_point(sf::Vector2f point)
{
    if (chech_if_point_belongs_to_map(point))
    {
        sf::Vector2i tile_position;
        tile_position.x = int(point.x / 50) + 1;
        tile_position.y = int(point.y / 50) + 1;
        return tile_position;
    }
    else
        return { 10000, 10000 };
}

sf::Vector2i Map::get_coordinates_by_point(sf::Vector2f point)
{
    if (chech_if_point_belongs_to_map(point))
    {
        sf::Vector2i coordinates;
        coordinates.x = int(point.x) + 1;
        coordinates.y = int(point.y) + 1;
        return coordinates;
    }
    else
        return { 50000, 50000 };
}
