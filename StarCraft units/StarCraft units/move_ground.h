#pragma once
#include "unit.h"
#include "global.h"

class move_ground : public unit
{

public:
	
	int get_v();

	void get_coordinates(int x, int y);

	void move();



private:
	bool is_moving;
	float v;
	float x_1;
	float y_1;

};

