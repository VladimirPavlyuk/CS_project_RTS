#pragma once
class unit
{
public:

	unit();

	~unit();

	void hp_check();

	void execute_delete(); 

	void execute_death();

	float check_range(float x, float y);

	float get_current_x();

	float get_current_y();

	int get_current_hp();

	int get_armor();

	float get_vision_range();

	bool is_mechanical();

	bool is_biological();

	bool is_light();

	bool is_armored();

	bool is_psionic();

	bool is_massive();

	bool is_building();

	bool is_air_target();

	bool is_ground_target();
	
	bool is_detector();

	bool is_invisible();

	bool is_borrowed();

	bool is_being_transported();

	bool movable();

	bool attacker();

	char get_player();

	char get_side();

	int get_minerals_cost();

	int get_gas_cost();

	int get_supply_cost();

	int get_number();

	virtual bool get_requirnments();

protected:

	char side;

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

	int minerals_cost;

	int gas_cost;

	int supply_cost;

	struct attributes
	{
		bool biological;		//0
		bool mechanical;		//1
		bool light;				//2
		bool armored;			//3
		bool psionic;			//4
		bool massive;			//5
		bool building;			//6
		bool air_target;		//7
		bool ground_target;		//8
		bool detector;			//9
		bool borrowed;			//10
		bool invisible;			//11
		bool invisible_now;		//12
		bool being_transported;	//13
		bool movable;			//14
		bool attacker;			//15
	};

	bool array_of_attributes[16];

	attributes unit_attributes;

	float vision_range;

	int number;

};