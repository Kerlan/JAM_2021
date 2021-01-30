/*
** EPITECH PROJECT, 2020
** rtype
** File description:
** display
*/

#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

enum tile_type {EMPTY, NORMAL, HORIZONTAL, VERTICAL, LEFT_UP, LEFT_DOWN, RIGHT_UP, RIGHT_DOWN, BOUTON, DYNAMITE, CORDE};

class tile
{
    private:
        sf::RenderWindow *window;
        sf::Sprite *sprite;
        sf::Sprite *sprite_hover_1;
        sf::Sprite *sprite_hover_2;
        sf::Sprite *sprite_activate;
        sf::Texture *create_texture(std::string name) const;
        sf::Sprite *create_sprite(sf::Texture *texture) const;
        sf::Sprite *create_sprite(std::string name) const;
        int pos_x;
        int pos_y;

    public:
        //int tile();
        void clickOn(std::string buffer);
        tile(sf::RenderWindow *isWindow, tile_type type, int isPos_x, int isPos_y);
        void draw_tile(int player);
        int click_tile();
        sf::Vector2f getpos();
        tile_type type;
        int status;
        // game(boost::asio::io_service &ioService);
        // int game_loop();
        // ~game();
};