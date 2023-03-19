#pragma once
#include "object.h"
#include "movable_ground.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class zergling :
    public movable_ground
{
public:

    zergling(float x_spawn, float y_spawn);

    sf::CircleShape zergling_model;

private:

    const float V = 100;
};

