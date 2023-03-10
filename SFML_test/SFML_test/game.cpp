#include "game.h"
#include "global.h"
#include "player.h"
#include "zergling.h"

int game::check_status()
{
    if (is_running)
        return 1;
    else
        return 0;
}

game::game() : is_running(true), player_1(new player), window(sf::VideoMode(800, 600), "Game_window"), time_logical(0)
{
    player_1->unit = new zergling(100, 100);
}

game::~game()
{
    delete this->player_1->unit;
    delete this->player_1;
}

void game::events()
{
    sf::Vector2i mouse_position;

    sf::Event event;

    // while there are pending events...
    if (window.pollEvent(event))
    {
        // check the type of the event...
        switch (event.type)
        {
        case sf::Event::MouseButtonPressed:
            mouse_position = sf::Mouse::getPosition(window);
            player_1->unit->x_1 = mouse_position.x;
            player_1->unit->y_1 = mouse_position.y;
            player_1->unit->is_moving =  true;

            // window closed
        if (event.type == sf::Event::Closed)
            window.close();
        }
    }

    // перемещение
    if (player_1->unit->is_moving)
        player_1->unit->move();
}

void game::draw()
{
    // std::cout << "draw_attempt" << " " << this->player_1->unit->get_position().x << " " << this->player_1->unit->get_position().y << std::endl;  // debug
    window.clear(sf::Color::Black);
    sf::CircleShape zergling_model(50.f);
    zergling_model.setPosition(this->player_1->unit->get_position().x, this->player_1->unit->get_position().y);
    window.draw(zergling_model);
    window.display();
}
