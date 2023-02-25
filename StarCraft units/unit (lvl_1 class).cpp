#include <iostream>
#include "unit (lvl_1 class).h"
using namespace std;

unit::unit()
{	
	// Constructor (spawn of object).
	// Create element in array/list.
}

void unit::hp_check()
{
	if (current_hp <= 0)
	this->execute_delete();
};

void unit::execute_delete()  // Death.
{
// Delete element in array/list.
// Death animation.
}
void unit::execute_death()
{
}
;

float unit::check_range(float x, float y)
{
	return(sqrt((x - current_position.x) * (x - current_position.x)) + ((y - current_position.y) * (y - current_position.y)));
};

float unit::get_current_x()
{
	return(current_position.x);
};

float unit::get_current_y()
{
	return(current_position.y);
};

int unit::get_current_hp()
{
	return current_hp;
};

int unit::get_armor()
{
	return armor;
};

float unit::get_vision_range()
{
	return vision_range;
};

bool unit::is_mechanical()
{
	return unit_attributes.mechanical;
};

bool unit::is_biological()
{
	return unit_attributes.biological;
};

bool unit::is_light()
{
	return unit_attributes.light;
};

bool unit::is_armored()
{
	return unit_attributes.armored;
};

bool unit::is_psionic()
{
	return unit_attributes.psionic;
}

bool unit::is_massive()
{
	return unit_attributes.massive;
}

bool unit::is_building()
{
	return unit_attributes.building;
}

bool unit::is_air_target()
{
	return unit_attributes.air_target;
};

bool unit::is_ground_target()
{
	return unit_attributes.ground_target;
}
bool unit::is_detector()
{
	return unit_attributes.detector;
}
bool unit::is_invisible()
{
	return unit_attributes.invisible;
}
bool unit::is_borrowed()
{
	return unit_attributes.borrowed;
}
bool unit::is_being_transported()
{
	return unit_attributes.being_transported;
}
bool unit::movable()
{
	return unit_attributes.movable;
}
bool unit::attacker()
{
	return unit_attributes.attacker;
}
;

char unit::get_player()
{
	return player;
}
char unit::get_side()
{
	return side;
}
int unit::get_minerals_cost()
{
	return minerals_cost;
}
int unit::get_gas_cost()
{
	return gas_cost;
}
int unit::get_supply_cost()
{
	return supply_cost;
}
;

int unit::get_number()
{
	return number;
}

bool unit::get_requirnments()
{
	return false;
}
