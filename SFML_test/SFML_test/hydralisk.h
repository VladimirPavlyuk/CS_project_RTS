#pragma once
#include "object.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class hydralisk :
    public object
{
public:

    hydralisk(float x_spawn, float y_spawn);

    sf::CircleShape hydralisk_model;

private:

    const float V = 50;
};


