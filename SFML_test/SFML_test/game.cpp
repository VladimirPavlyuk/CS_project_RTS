#include "game.h"
#include "global.h"
#include "player.h"
#include "zergling.h"
#include "hydralisk.h"
#include "scenario.h"
#include "array"
#include "vector"

using std::cout;
using std::endl;

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

game::game() : is_running(true), player_1(new player), window(sf::VideoMode(window_size.x, window_size.y), "Game_window"), time_logical(0)
{
}

game::~game()
{
    player_1->units_list.clear();
    delete player_1->selected;
    delete player_1;
}

void game::move_order(sf::Vector2f move_to)
{
    if (player_1->setected_objects.size() == 1 and sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) == false)
    {
        player_1->setected_objects.front()->set_x_1(move_to.x);
        player_1->setected_objects.front()->set_y_1(move_to.y);
        player_1->setected_objects.front()->set_move_status_as_true();
        while (player_1->setected_objects.front()->move_order_queue.empty() == 0)
        {
            player_1->setected_objects.front()->move_order_queue.pop();
        }
    }

    else if (player_1->setected_objects.size() == 1 and sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) == true)
    {
        player_1->setected_objects.front()->move_order_queue.push(move_to);
    }

    else if (player_1->setected_objects.size() > 1 and sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) == false)
    {
        position r_current {0, 0};
        for (auto unit_ : player_1->setected_objects)
        {
            r_current.x += unit_->get_position().x;
            r_current.y += unit_->get_position().y;
        }
        r_current.x /= player_1->setected_objects.size();
        r_current.y /= player_1->setected_objects.size();

        //constexpr int number_of_selected_units = player_1->setected_objects.size();
        //std::array<position, number_of_selected_units>
        std::vector<position> new_r;
        for (auto unit_ : player_1->setected_objects)
        {
            position delta_r_i;
            delta_r_i.x = unit_->get_position().x - r_current.x;
            delta_r_i.y = unit_->get_position().y - r_current.y;
            position new_r_i;
            new_r_i.x = move_to.x + delta_r_i.x;
            new_r_i.y = move_to.y + delta_r_i.y;
            new_r.push_back(new_r_i);
        }

        int counter = 0;
        for (auto unit_ : player_1->setected_objects)
        {
            unit_->set_x_1(new_r[counter].x);
            unit_->set_y_1(new_r[counter].y);
            unit_->set_move_status_as_true();
            while (unit_->move_order_queue.empty() == 0)
            {
                unit_->move_order_queue.pop();
            }
            counter++;
        }
    }
    else if (player_1->setected_objects.size() > 1 and sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) == true)
    {
        position r_current{ 0, 0 };
        for (auto unit_ : player_1->setected_objects)
        {
            r_current.x += unit_->get_position().x;
            r_current.y += unit_->get_position().y;
        }
        r_current.x /= player_1->setected_objects.size();
        r_current.y /= player_1->setected_objects.size();

        //constexpr int number_of_selected_units = player_1->setected_objects.size();
        //std::array<position, number_of_selected_units>;
        std::vector<sf::Vector2f> new_r;
        for (auto unit_ : player_1->setected_objects)
        {
            position delta_r_i;
            delta_r_i.x = unit_->get_position().x - r_current.x;
            delta_r_i.y = unit_->get_position().y - r_current.y;
            sf::Vector2f new_r_i;
            new_r_i.x = move_to.x + delta_r_i.x;
            new_r_i.y = move_to.y + delta_r_i.y;
            new_r.push_back(new_r_i);
        }

        int counter = 0;
        for (auto unit_ : player_1->setected_objects)
        {
            cout << counter << endl;  // debug
            unit_->move_order_queue.push((new_r[counter]));
            counter++;
        }
    }
}

void game::events()  // Events loop
{
    sf::Vector2i mouse_position_window;

    sf::Vector2f mouse_position_world;

    sf::Event event;

    while (window.pollEvent(event))  // External events (controller)
    {  
         if (sf::Mouse::isButtonPressed(sf::Mouse::Left) and sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) == false)  // Unit selection
         {
             if (player_1->check_selection_status())
                 player_1->setected_objects.clear();
             mouse_position_window = sf::Mouse::getPosition(window);
             mouse_position_world = window.mapPixelToCoords(mouse_position_window);
             for (auto unit : player_1->units_list)
             {   
                 if (unit->get_position().x - unit->get_radius() <= mouse_position_world.x and mouse_position_world.x <= unit->get_position().x + unit->get_radius() and
                     unit->get_position().y - unit->get_radius() <= mouse_position_world.y and mouse_position_world.y  <= unit->get_position().y + unit->get_radius())
                 {
                     if (unit->square_range(mouse_position_world.x, mouse_position_world.y) <= unit->get_radius() * unit->get_radius())
                     {
                         player_1->setected_objects.push_back(unit);
                         player_1->set_selection_status_as_true();
                     }
                 }
             }
         }
         if (sf::Mouse::isButtonPressed(sf::Mouse::Left) and sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) and player_1->check_selection_status())  // Shift unit selection
         {
             mouse_position_window = sf::Mouse::getPosition(window);
             mouse_position_world = window.mapPixelToCoords(mouse_position_window);
             for (auto unit : player_1->units_list)
             {
                 if (unit->get_position().x - unit->get_radius() <= mouse_position_world.x and mouse_position_world.x <= unit->get_position().x + unit->get_radius() and
                     unit->get_position().y - unit->get_radius() <= mouse_position_world.y and mouse_position_world.y <= unit->get_position().y + unit->get_radius())
                 {
                     if (unit->square_range(mouse_position_world.x, mouse_position_world.y) <= unit->get_radius() * unit->get_radius())
                     {
                         if (player_1->check_if_unit_is_not_already_in_the_list(unit))
                            player_1->setected_objects.push_back(unit);
                     }
                 }
             }
         }
         if (player_1->check_selection_status() and sf::Mouse::isButtonPressed(sf::Mouse::Right) == true)  // Move order
         {
             mouse_position_window = sf::Mouse::getPosition(window);
             mouse_position_world = window.mapPixelToCoords(mouse_position_window);
             move_order(mouse_position_world);
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

    for (auto unit : player_1->units_list)  // Internal ivents
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
    if (player_1->get_camera_control_with_mouse_as_true())  // Camera control execution
    {
        player_1->move_camera(sf::Mouse::getPosition(window));
    }

}   

void game::draw()  // (view)
{

    player_1->camera.setCenter(player_1->camera_position.x, player_1->camera_position.y);
    window.setView(player_1->camera);
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
