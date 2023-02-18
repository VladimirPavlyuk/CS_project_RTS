#include <iostream>
using namespace std;

class Object
{
public:
	
	Object() {};  // Конструктор.

	~Object()  // Деструктор.
	{
		
	};

	void hp_check()  // Проверка ХП.
	{
		if (current_hp <= 0)
			this->execute_death();
	};

	void execute_death()  // Смерть.
	{
		// Удалить элемент массива/связанного списка.
		// Анимация смерти (если будет).
	};

	float check_range(float x, float y)  // Проверка расстояния до точки.
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

	int get_current_hp()  // Получить текущее ХП.
	{
		return current_hp;
	};

	int get_armor()  // Получить броню.
	{
		return armor;
	}

	float get_vision_range()  // Получить дальность обзора.
	{
		return vision_range;
	};

	float get_detection_range()  // Получить дальность детекции.
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

	char get_player()  // Получить игрока, которому принадлежит юнит.
	{
		return player;
	};


protected: //  Возможно, часть придётся сделать public.

	char player;  // Игрок, которому принадлежит юнит.

	int max_hp;  //  Максимальное ХП.

	int current_hp;  // Текущее ХП.

	struct position  // Структура координат.
	{
		float x;
		float y;
	};

	position current_position;  // Положение на карте.

	int armor;  // Броня.

	struct attributes  // Структура атрибутов.
	{
		bool biological;
		bool mechanical;
		bool light;
		bool armored;
		bool psionic;
		bool large;
	};

	attributes unit_attributes;  // Атрибуты.

	float vision_range;  // Дальность обзора.

	float detection_range;  // Дальность детекции.

};
