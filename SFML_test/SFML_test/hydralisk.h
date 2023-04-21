#pragma once
#include "Movable_ground.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Hydralisk :
    public Movable_ground
{
public:

    Hydralisk(float x_spawn, float y_spawn, char Side);

    sf::CircleShape hydralisk_model;

private:

    static float V_initial;
};


