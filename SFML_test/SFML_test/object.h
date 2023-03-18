#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include "global.h"


class object
{
public:

	object(float x_spawn, float y_spawn);

	~object();

	float check_range(float x, float y);

	float get_radius();

	void move();

	float x_1;
	float y_1;
	bool is_moving;

	position get_position();

	int get_number();

protected:

	position current_position;

	float v;

	float radius;

	int number;
};

