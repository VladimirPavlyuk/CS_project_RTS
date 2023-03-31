#pragma once
#include "Object.h"

class Movable_ground :
    public Object
{
public:

    Movable_ground(float x_spawn, float y_spawn);

    void move();

    bool get_move_status();

    void set_move_status_as_true();

    void set_move_status_as_false();

    float get_x_1();

    float get_y_1();

    void set_x_1(float new_y_1);

    void set_y_1(float new_x_1);

    float v;

protected:

    float x_1;
    float y_1;
    bool is_moving;
};

