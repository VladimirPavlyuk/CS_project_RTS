#pragma once

class Unit
{
public:
	Unit(char Side);

	~Unit();

	char get_side();

	//char get_race();


protected:

	const char side;

	//const char race;

};

