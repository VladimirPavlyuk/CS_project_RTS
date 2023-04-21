#pragma once


#include "Movable_ground.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Zergling :
    public Movable_ground
{
public:

    Zergling(float x_spawn, float y_spawn, char Side);

    sf::CircleShape zergling_model;

private:

    static float V_initial;
};

