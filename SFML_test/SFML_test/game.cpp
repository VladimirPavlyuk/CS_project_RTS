#include "Game.h"
#include "Global.h"
#include "Player.h"
#include "Zergling.h"
#include "Hydralisk.h"
#include "Scenario.h"

using std::cout;
using std::endl;

void Game::end_run()
{
    this->is_running = false;
}

void Game::start_run()
{
    this->is_running = true;
}

int Game::check_status()
{
    if (is_running)
        return 1;
    else
        return 0;
}

Game::Game() : is_running(true), player_1(new Player(1, 1)), window(sf::VideoMode(window_size.x, window_size.y), "Game_window"), time_logical(0)
{
}

Game::~Game()
{
    player_1->ally_units_list.clear();
    player_1->enemy_units_list.clear();
    delete player_1->selected;
    delete player_1;
}

void Game::events()  // Events loop
{
    sf::Vector2i mouse_position_window;

    sf::Vector2f mouse_position_world;

    sf::Event event;

    while (window.pollEvent(event))  // External events (controller)
    {  
         if (sf::Mouse::isButtonPressed(sf::Mouse::Left))  // Unit selection
         {
             mouse_position_window = sf::Mouse::getPosition(window);
             mouse_position_world = window.mapPixelToCoords(mouse_position_window);
             for (auto unit : player_1->ally_units_list)
             {   
                 if (unit->get_position().x - unit->get_radius() <= mouse_position_world.x and mouse_position_world.x <= unit->get_position().x + unit->get_radius() and
                     unit->get_position().y - unit->get_radius() <= mouse_position_world.y and mouse_position_world.y  <= unit->get_position().y + unit->get_radius())
                 {
                     if (unit->square_range(mouse_position_world.x, mouse_position_world.y) <= unit->get_radius() * unit->get_radius())
                     {
                         player_1->selected = unit;
                         player_1->set_selection_status_as_true();
                     }
                 }
                 
             }
             cout << endl;

         }
         if (player_1->has_selected_unit_check() and sf::Mouse::isButtonPressed(sf::Mouse::Right) == true and  // Move order
             sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) == false)
         {
             mouse_position_window = sf::Mouse::getPosition(window);
             mouse_position_world = window.mapPixelToCoords(mouse_position_window);
             player_1->selected->set_x_1(mouse_position_world.x);
             player_1->selected->set_y_1(mouse_position_world.y);
             player_1->selected->set_move_status_as_true();
             while (player_1->selected->move_order_queue.empty() == 0)
             {
                 player_1->selected->move_order_queue.pop();
             }
         }
         if (player_1->has_selected_unit_check() and player_1->selected->get_move_status()  // Shift move order
             and sf::Mouse::isButtonPressed(sf::Mouse::Right) == true and sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
         {
             mouse_position_window = sf::Mouse::getPosition(window);
             mouse_position_world = window.mapPixelToCoords(mouse_position_window);
             player_1->selected->move_order_queue.push(mouse_position_world);
         }
        

            // Camera control

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))  // with keyboard
                player_1->camera_position.y -= camera_speed;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                player_1->camera_position.y += camera_speed;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                player_1->camera_position.x -= camera_speed;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                player_1->camera_position.x += camera_speed;

            mouse_position_window = sf::Mouse::getPosition(window);  // with mouse
            if (mouse_position_window.x <= window_size.x / 70 or mouse_position_window.x >= window_size.x / 70 * 69
                or mouse_position_window.y <= window_size.y / 70 or mouse_position_window.y >= window_size.y / 70 * 69)
            {
                player_1->set_camera_control_with_mouse_as_true();
            }
            else
            {
                player_1->set_camera_control_with_mouse_as_false();
            }

        if (event.type == sf::Event::Closed)  // Close game
        {
            this->is_running = false;
            window.close();
        }
    }

    for (auto unit : player_1->ally_units_list)  // Orders execution
    {
        if (unit->get_move_status() == true)  // Move execution
        {
            unit->move(); 
            if (unit->check_range(unit->get_x_1(), unit->get_y_1()) <= 0.01)  // Shift move execution
            {
                if (unit->move_order_queue.empty() == 0)
                {
                    sf::Vector2f new_order = unit->move_order_queue.front();
                    unit->move_order_queue.pop();
                    unit->set_x_1(new_order.x);
                    unit->set_y_1(new_order.y);
                }
                else
                    unit->set_move_status_as_false();
            }
        }
    }
    if (player_1->get_camera_control_with_mouse_as_true())
    {
        player_1->move_camera(sf::Mouse::getPosition(window));
    }

}

void Game::draw()  // (view)
{

    player_1->camera.setCenter(player_1->camera_position.x, player_1->camera_position.y);
    window.setView(player_1->camera);
    window.clear(sf::Color::Black);

    sf::CircleShape zergling_ally_model(10);
    zergling_ally_model.setFillColor(sf::Color::Green);
    sf::CircleShape hydralisk_ally_model(30);
    hydralisk_ally_model.setFillColor(sf::Color::Green);

    sf::CircleShape zergling_enemy_model(10);
    zergling_enemy_model.setFillColor(sf::Color::Red);
    sf::CircleShape hydralisk_enemy_model(30);
    hydralisk_enemy_model.setFillColor(sf::Color::Red);

    for (auto unit : player_1->ally_units_list)
    {
        if (unit->get_number() == 1)
        {
            zergling_ally_model.setPosition(unit->get_position().x - unit->get_radius(), unit->get_position().y - unit->get_radius());
            window.draw(zergling_ally_model);
        }
        else if (unit->get_number() == 2)
        {
            hydralisk_ally_model.setPosition(unit->get_position().x - unit->get_radius(), unit->get_position().y - unit->get_radius());
            window.draw(hydralisk_ally_model);
        }
    }

    for (auto unit : player_1->enemy_units_list)
    {
        if (unit->get_number() == 1)
        {
            zergling_enemy_model.setPosition(unit->get_position().x - unit->get_radius(), unit->get_position().y - unit->get_radius());
            window.draw(zergling_enemy_model);
        }
        else if (unit->get_number() == 2)
        {
            hydralisk_enemy_model.setPosition(unit->get_position().x - unit->get_radius(), unit->get_position().y - unit->get_radius());
            window.draw(hydralisk_enemy_model);
        }
    }
    window.display();
}
