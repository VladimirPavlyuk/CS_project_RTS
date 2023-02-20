#include <iostream>
#include "object (lvl_1 class).h"
using namespace std;

object::object()
{	
	// Constructor (spawn of object).
	// Create element in array/list.
}

void object::hp_check()
{
	if (current_hp <= 0)
	this->execute_death();
};

void object::execute_death()  // Death.
{
// Delete element in array/list.
// Death animation.
};

float object::check_range(float x, float y)
{
	return(sqrt((x - current_position.x) * (x - current_position.x)) + ((y - current_position.y) * (y - current_position.y)));
};

float object::get_current_x()
{
	return(current_position.x);
};

float object::get_current_y()
{
	return(current_position.y);
};

int object::get_current_hp()
{
	return current_hp;
};

int object::get_armor()
{
	return armor;
};

float object::get_vision_range()
{
	return vision_range;
};

bool object::is_mechanical()
{
	return unit_attributes.mechanical;
};

bool object::is_biological()
{
	return unit_attributes.biological;
};

bool object::is_light()
{
	return unit_attributes.light;
};

bool object::is_armored()
{
	return unit_attributes.armored;
};

bool object::is_psionic()
{
	return unit_attributes.psionic;
}

bool object::is_massive()
{
	return unit_attributes.massive;
}

bool object::is_building()
{
	return unit_attributes.building;
}

bool object::is_air_target()
{
	return unit_attributes.air_target;
};

bool object::is_ground_target()
{
	return unit_attributes.ground_target;
}
bool object::is_detector()
{
	return unit_attributes.detector;
};

char object::get_player()
{
	return player;
}
int object::get_minerals_cost()
{
	return minerals_cost;
}
int object::get_gas_cost()
{
	return gas_cost;
}
int object::get_supply_cost()
{
	return supply_cost;
}
;

int object::get_number()
{
	return number;
}
