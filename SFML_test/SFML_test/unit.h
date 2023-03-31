#pragma once

class unit
{
public:

	unit();

	~unit();

	char get_side();

	char get_race();


protected:

	char side;

	char race;

	int max_HP;

	int current_HP;


};

