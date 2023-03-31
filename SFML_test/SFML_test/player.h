#pragma once
#include <list>
#include "object.h"
#include "global.h"
#include "scenario.h"
#include "zergling.h"
#include "hydralisk.h"
#include "cmath"


class player
{

public:

	player(char Side);

	~player();

	bool get_camera_control_with_mouse_as_true();

	void set_camera_control_with_mouse_as_true();

	void set_camera_control_with_mouse_as_false();

	void move_camera(sf::Vector2i mouse_position);

	void spawn_unit(int number, position spawn_position);

	bool has_selected_unit_check();

	void set_selection_status_as_true();

	object* unit;

	std::list<object*> units_list_1;

	std::list<object*> units_list_2;

	std::list<object*> ally_units_list;

	std::list<object*> enemy_units_list;

	object* selected;

	sf::View camera;

	position camera_position;

	// char nickname[12];

	// char race;

	char side;

	// char colour;

	// resourses player_resourses;

	// int units[120];  // уточнить число

	// int to_build[120];  // уточнить число

	//std::list<unit*>::iterator to_destroy[120] = { player_units.end() };

private:

	bool camera_control_with_mouse;

	char has_selected_unit;

};
