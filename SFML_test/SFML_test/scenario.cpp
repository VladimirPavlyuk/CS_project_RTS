#include "Scenario.h"
#include "vector"
#include <list>
#include "Zergling.h"

initial_unit u_1_1 = { 1, 100, 100 };
initial_unit u_1_2 = { 1, 150, 150 };
initial_unit u_1_3 = { 2, 200, 200 };

initial_unit u_2_1 = { 2, 300, 300 };







std::vector<initial_unit> initial_units_1 = { u_1_1, u_1_2, u_1_3 };

std::vector<initial_unit> initial_units_2 = { u_2_1 };



//int number_of_sizes = 2;
//
//std::vector <std::list<Object*>> vectors_of_units(number_of_sizes);
//
//Zergling* u1 = new Zergling(initial_units_1[1].spawn_position.x, initial_units_1[1].spawn_position.y, 1);
//
//for (auto i : vectors_of_units)




position start_camera_position_p_1 = { 0, 0 };

position window_size = { 800, 600 };



