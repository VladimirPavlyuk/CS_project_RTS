#pragma once
#include <list>
#include "Object.h"
#include "Global.h"
#include "Scenario.h"
#include "Zergling.h"
#include "Hydralisk.h"
#include "cmath"


class Player
{

public:

	Player(char Side, char Race);

	~Player();

	bool get_camera_control_with_mouse_as_true();

	void set_camera_control_with_mouse_as_true();

	void set_camera_control_with_mouse_as_false();

	void move_camera(sf::Vector2i mouse_position);

	void spawn_unit(int number, position spawn_position);

	bool has_selected_unit_check();

	void set_selection_status_as_true();

	//static void initialize_vector_of_lists();

	Object* unit;

	std::list<Object*> units_list_1;

	std::list<Object*> units_list_2;

	std::list<Object*> ally_units_list;

	std::list<Object*> enemy_units_list;

	Object* selected;

	sf::View camera;

	position camera_position;

	// char nickname[12];

	const char race;

	const char side;

	// char colour;

	// resourses player_resourses;

	// int units[120];  // уточнить число

	// int to_build[120];  // уточнить число

	//std::list<unit*>::iterator to_destroy[120] = { player_units.end() };

//protected:

	//static int number_of_sizes;

	//static std::vector <std::list<Object*>> vector_of_lists;

private:

	bool camera_control_with_mouse;

	char has_selected_unit;

};
