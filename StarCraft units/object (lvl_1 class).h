#pragma once
class object
{
public:

	object() {};

	~object()
	{

	};

	void hp_check();

	void execute_death();

	float check_range(float x, float y);

	float get_current_x();

	float get_current_y();

	int get_current_hp();

	int get_armor();

	float get_vision_range();

	float get_detection_range();

	bool is_mechanical();

	bool is_biological();

	bool is_light();

	bool is_armored();

	bool is_psionic();

	bool is_large();

	bool is_air_target();

	bool is_ground_target();

	char get_player();

	int get_number();

protected:

	char player;

	int max_hp;

	int current_hp;

	struct position
	{
		float x;
		float y;
	};

	position current_position;

	int armor;

	struct attributes
	{
		bool biological;
		bool mechanical;
		bool light;
		bool armored;
		bool psionic;
		bool large;
		bool air_target;
		bool ground_target;
	};

	attributes unit_attributes;

	float vision_range;

	float detection_range;

	int number;  

};