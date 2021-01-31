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
#include <string>
#include <vector>

#include "tile.hpp"
#include "MakeMap.hpp"


class game
{
    private:
        sf::RenderWindow window;
        std::vector<std::vector<tile *>> tile_board;
        sf::Event event;
        void draw_board();
        void create_board(void);
        void check_hover();
        sf::Sprite *background;
        sf::Sprite *background_double;
        sf::Sprite *title_1;
        sf::Sprite *title_2;
        sf::Sprite *life_1;
        sf::Sprite *winscreen;
        sf::Sprite *won_2;
        sf::Sprite *won_1;
        sf::Sprite *restart;
        void draw_life();
        sf::Sprite *life_2;
        sf::Clock clock_paralax;
        void move_paralax(void);
        float window_height;
        float window_width;
        sf::Sound sound_hover;
        sf::Sound sound_good_select;
        sf::Sound sound_impact;
        int player;
        int nb_life1;
        int nb_life2;
        void remove_tile();
        std::vector<std::vector<char>> map;
        MakeMap *text_map;
        void win_screen();

        // sf::Event event;
        // game_status game_status;
        // int host_status;
        // menu *manage_menu;
        // play *manage_play;
        // menu_page previous_page_menu;
        // menu_page current_page_menu;
        // sf::UdpSocket socket;
        // sf::UdpSocket socketBis;
        // int socket_stat;
        // int status;
        // std::string ip_adress;
        // void manage_data_event_menu();
        // void sendMove(int data1);
        // void connect_server_tcp(const std::string &ip_address);
        // UDPClient *_client;
        // std::shared_ptr<Queue<struct UDPServerData>> _queue;
        // std::queue<struct UDPClientData> _action;
        // UDPServerData receiveMove();
        // boost::asio::ip::udp::endpoint _endpoint;
        // void start_server_tcp(const std::string &ip_address);
        // void connect_server_udp(void);
        // void sendMoveBis(int data1);
        // UDPServerData receiveMoveBis();
        // void connect_server_udp_bis(void);

    public:
        int game_loop();
        game(void);
        // game(boost::asio::io_service &ioService);
        // int game_loop();
        // ~game();
};

