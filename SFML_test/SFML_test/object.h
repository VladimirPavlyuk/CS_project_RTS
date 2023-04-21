#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <queue>
#include "Global.h"


class Object
{
public:

	Object(float x_spawn, float y_spawn, char Side);

	~Object();

	float check_range(float x, float y);

	float square_range(float x, float y);

	float get_radius();

	position get_position();

	int get_number();

	char get_side() const;

	void take_damage(int value);

	virtual void move();

	virtual bool get_move_status();

	virtual void set_move_status_as_true();

	virtual void set_move_status_as_false();

	virtual float get_x_1();

	virtual float get_y_1();  // Спросить!

	virtual void set_x_1(float new_x_1);

	virtual void set_y_1(float new_y_1);

	std::queue<sf::Vector2f> move_order_queue;

protected:

	position current_position;

	float radius;

	int number;

	char side;

	int Max_HP;

	int Current_HP;
};

