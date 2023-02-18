#include <iostream>
using namespace std;

class Object
{
public:
	
	Object() {};  // �����������.

	~Object()  // ����������.
	{
		
	};

	void hp_check()  // �������� ��.
	{
		if (current_hp <= 0)
			this->execute_death();
	};

	void execute_death()  // ������.
	{
		// ������� ������� �������/���������� ������.
		// �������� ������ (���� �����).
	};

	float check_range(float x, float y)  // �������� ���������� �� �����.
	{
		return(sqrt((x - current_position.x) * (x - current_position.x)) + ((y - current_position.y) * (y - current_position.y)));
	};

	float get_current_x()
	{
		return(current_position.x);
	};

	float get_current_y()
	{
		return(current_position.y);
	}

	int get_current_hp()  // �������� ������� ��.
	{
		return current_hp;
	};

	int get_armor()  // �������� �����.
	{
		return armor;
	}

	float get_vision_range()  // �������� ��������� ������.
	{
		return vision_range;
	};

	float get_detection_range()  // �������� ��������� ��������.
	{

		return detection_range;
	};

	bool is_mechanical()
	{
		if (unit_attributes.mechanical)
			return true;
		else
			return false;
	};
	bool is_biological()
	{
		if (unit_attributes.biological)
			return true;
		else
			return false;
	};
	bool is_light()
	{
		if (unit_attributes.light)
			return true;
		else
			return false;
	};
	bool is_armored()
	{
		if (unit_attributes.armored)
			return true;
		else
			return false;
	};
	bool is_psionic()
	{
		if (unit_attributes.psionic)
			return true;
		else
			return false;
	};
	bool is_large()
	{
		if (unit_attributes.large)
			return true;
		else
			return false;
	};

	char get_player()  // �������� ������, �������� ����������� ����.
	{
		return player;
	};


protected: //  ��������, ����� ������� ������� public.

	char player;  // �����, �������� ����������� ����.

	int max_hp;  //  ������������ ��.

	int current_hp;  // ������� ��.

	struct position  // ��������� ���������.
	{
		float x;
		float y;
	};

	position current_position;  // ��������� �� �����.

	int armor;  // �����.

	struct attributes  // ��������� ���������.
	{
		bool biological;
		bool mechanical;
		bool light;
		bool armored;
		bool psionic;
		bool large;
	};

	attributes unit_attributes;  // ��������.

	float vision_range;  // ��������� ������.

	float detection_range;  // ��������� ��������.

};
