#include "Global.h"
#include "Object.h"
#include "scenario.h"
#include <SFML/Graphics.hpp>
#include <list>
#include <array>
#pragma once


class Map
{
public:

	Map();

	~Map();

	bool chech_if_point_belongs_to_map(sf::Vector2f point);

	bool check_if_tile_belongs_to_map(sf::Vector2i tile_);

	sf::Vector2i get_tile_by_point(sf::Vector2f point);

	sf::Vector2i get_coordinates_by_point(sf::Vector2f point);

	struct tile
	{
		const position tile_size = { 50, 50 };
		size location;
		sf::Sprite sprite_;
		bool is_passable;
		bool is_buildable;
		bool level;
		bool is_ramp;
		std::list<Object*> units_on_tile;
		bool building_on_tile;
	};

	std::array< std::array <tile, map_size.y + 1>, map_size.x + 1 > map_tiles;

	std::array< std::array <tile, map_size.y + 2>, 1 > outskirt_left;

	std::array< std::array <tile, map_size.y + 2>, 1 > outskirt_right;

	std::array< std::array <tile, 1>, map_size.x > outskirt_top;

	std::array< std::array <tile, 1>, map_size.x > outskirt_bottom;


private:

	sf::Texture texture_grey;

	sf::Texture texture_white;

	sf::Texture texture_black;

};

