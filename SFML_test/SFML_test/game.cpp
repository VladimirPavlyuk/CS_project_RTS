#include "game.h"
#include "global.h"
#include "player.h"
#include "zergling.h"
#include "hydralisk.h"
#include "scenario.h"

void game::end_run()
{
    this->is_running = false;
}

void game::start_run()
{
    this->is_running = true;
}

int game::check_status()
{
    if (is_running)
        return 1;
    else
        return 0;
}

game::game() : is_running(true), player_1(new player), window(sf::VideoMode(800, 600), "Game_window"), time_logical(0)
{
    for (auto unit : initial_units)
    {
        if (unit.number == 1)
        {
            player_1->units_list.push_back(new zergling(unit.spawn_position.x, unit.spawn_position.y));
        }
        else if (unit.number == 2)
        {
            player_1->units_list.push_back(new hydralisk(unit.spawn_position.x, unit.spawn_position.y));
        }
    }
}

game::~game()
{
    player_1->units_list.clear();
    delete player_1->selected;
    delete player_1;
}

void game::events()
{
    sf::Vector2i mouse_position;

    sf::Event event;

    // while there are pending events...
    while (window.pollEvent(event))
    {
        // check the type of the event...
        
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                mouse_position = sf::Mouse::getPosition(window);
                for (auto unit : player_1->units_list)
                {   
                    if (unit->get_position().x - unit->get_radius() <= mouse_position.x <= unit->get_position().x + unit->get_radius() and
                        unit->get_position().y - unit->get_radius() <= mouse_position.y <= unit->get_position().y + unit->get_radius())
                    {
                        if (unit->check_range(mouse_position.x, mouse_position.y) <= unit->get_radius())
                        {
                            player_1->selected = unit;
                            player_1->has_selected_unit = true;
                        }
                    }
                }

            }
            if (player_1->has_selected_unit == true and sf::Mouse::isButtonPressed(sf::Mouse::Right) == true)
            {
                mouse_position = sf::Mouse::getPosition(window);
                player_1->selected->x_1 = mouse_position.x;
                player_1->selected->y_1 = mouse_position.y;
                player_1->selected->is_moving = true;
            }
        
        // window closed
        if (event.type == sf::Event::Closed)
        {
            this->is_running = false;
            window.close();
        }
    }

    for (auto unit : player_1->units_list)
    {
        if (unit->is_moving == true)
        {
            unit->move();
        }
    }

    if (player_1->has_selected_unit)
    {
       // std::cout << player_1->selected->x_1 << " " << player_1->selected->y_1 << std::endl;
       // std::cout << player_1->selected->get_position().x << " " << player_1->selected->get_position().y << std::endl;
    }
}

void game::draw()
{
    // std::cout << "draw_attempt" << " " << this->player_1->unit->get_position().x << " " << this->player_1->unit->get_position().y << std::endl;  // debug
    window.clear(sf::Color::Black);
    for (auto unit : player_1->units_list)
    {
        if (unit->get_number() == 1)
        {
            sf::CircleShape zergling_model(10);
            zergling_model.setPosition(unit->get_position().x - unit->get_radius(), unit->get_position().y - unit->get_radius());
            window.draw(zergling_model);
        }
        else if (unit->get_number() == 2)
        {
            sf::CircleShape hydralisk_model(30);
            hydralisk_model.setPosition(unit->get_position().x - unit->get_radius(), unit->get_position().y - unit->get_radius());
            window.draw(hydralisk_model);
        }
    }
    window.display();
}
