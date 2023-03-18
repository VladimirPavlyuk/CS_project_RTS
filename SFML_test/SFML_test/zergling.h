#pragma once
#include "object.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class zergling :
    public object
{
public:

    zergling(float x_spawn, float y_spawn);

    sf::CircleShape zergling_model;

private:

    const float V = 100;
};

