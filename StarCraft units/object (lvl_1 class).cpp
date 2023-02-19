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

float object::get_detection_range()
{
	return detection_range;
};

bool object::is_mechanical()
{
	if (unit_attributes.mechanical)
		return true;
	else
		return false;
};

bool object::is_biological()
{
	if (unit_attributes.biological)
		return true;
	else
		return false;
};

bool object::is_light()
{
	if (unit_attributes.light)
		return true;
	else
		return false;
};

bool object::is_armored()
{
	if (unit_attributes.armored)
		return true;
	else
		return false;
};

bool object::is_psionic()
{
	if (unit_attributes.psionic)
		return true;
	else
		return false;
};

bool object::is_large()
{
	if (unit_attributes.large)
		return true;
	else
		return false;
}

bool object::is_air_target()
{
	if (unit_attributes.air_target)
		return true;
	else
		return false;
};

bool object::is_ground_target()
{
	if (unit_attributes.ground_target)
		return true;
	else
		return false;
};

char object::get_player()
{
	return player;
};

int object::get_number()
{
	return number;
};