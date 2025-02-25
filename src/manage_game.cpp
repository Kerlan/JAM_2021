#include "../include/manage_game.hpp"

sf::Texture *create_texture(std::string name)
{
     sf::Texture *texture = new sf::Texture;
    if (texture->loadFromFile(name))
        return (texture);
    texture = NULL;
    return (texture);
}
sf::Sprite *create_sprite(sf::Texture *texture)
{
    sf::Sprite *sprite = new sf::Sprite;
    sprite->setTexture(*texture);
    return (sprite);
}
sf::Sprite *create_sprite(std::string name)
{
    sf::Texture *tmp = new sf::Texture;
    tmp = create_texture(name);
    if (tmp == NULL)
        create_sprite(name);
    return (create_sprite(tmp));
}

int main()
{
    game *ol = new game();
}

void game::draw_life()
{
    int x = 0;

    for (int i = 0; i != nb_life1; i++) {
        life_1->setPosition(x + 100, 100);
        window.draw(*life_1);
        x += 300;
    }
    x = 2880;
    for (int i = 0; i != nb_life2; i++) {
        life_2->setPosition(x - 350, 100);
        window.draw(*life_2);
        x -= 300;
    }
}

game::game(void)
{
    player = 2;
    background = create_sprite("img/background.png");
    background_double = create_sprite("img/background.png");
    title_1 = create_sprite("img/title_1.png");
    title_2 = create_sprite("img/title_2.png");
    life_1 = create_sprite("img/life_1.png");
    life_2 = create_sprite("img/life_2.png");
    winscreen = create_sprite("img/winscreen.png");
    won_1 = create_sprite("img/won_1.png");
    won_2 = create_sprite("img/won_2.png");
    restart = create_sprite("img/restart.png");
    restart_no = create_sprite("img/restart_no.png");
    nb_life1 = 0;
    nb_life2 = 3;

    background->setPosition(0,0);
    game_loop();
} 

void game::draw_board()
{
     for(int i = 0; i != tile_board.size(); i++) {
        for (int j = 0; j != tile_board[i].size(); j++) {
            tile_board[i][j]->draw_tile(player);
        }
    }
}

void game::create_board(void)
{
    text_map = new MakeMap(15, 15);
    map = text_map->map;
    int pos_x = 0;
    int pos_y = 0;

    for(int i = 0; i != map.size(); i++) {
        std::vector<tile *> line;

        for (int j = 0; j != map[i].size(); j++) {
            line.push_back(new tile(&window, NORMAL, pos_x +(1440 - 375), pos_y + 500));
            pos_x += 50;
        }

        pos_y += 50;
        pos_x = 0;
        tile_board.push_back(line);
    }
}

void game::check_hover()
{
    sf::Vector2i cursorPos = sf::Mouse::getPosition(window);
   // (cursorPos.x >= joinPos.x && cursorPos.y >= joinPos.y &&
     //           cursorPos.x <= joinPos.x + joinSize.x && cursorPos.y <= joinPos.y + joinSize.y)
    for(int i = 0; i != tile_board.size(); i++) {
        for (int j = 0; j != tile_board[i].size(); j++) {
            sf::Vector2f tile_pos = tile_board[i][j]->getpos();
            if (cursorPos.x >= tile_pos.x + 1 && cursorPos.y >= tile_pos.y + 1 &&
                cursorPos.x <= tile_pos.x + 49 && cursorPos.y <= tile_pos.y + 49) {
                if (tile_board[i][j]->status == 0 || tile_board[i][j]->status == 1) {
                    if (tile_board[i][j]->status == 0)
                        sound_hover.play();
                    tile_board[i][j]->status = 1;
                }
            }
            else if (tile_board[i][j]->status == 1)
                tile_board[i][j]->status = 0;
        }
    }
}

void game::move_paralax(void)
{
    sf::Vector2f simple_pos = background->getPosition();
    sf::Vector2f double_pos = background_double->getPosition();
    if (double_pos.x == 0)
        background->setPosition(window_width, 0);
    else if (simple_pos.x == 0)
        background_double->setPosition(window_width, 0);
    sf::Time time = clock_paralax.getElapsedTime();
    int layer = -1;
    if (time.asMicroseconds() / 10000 > 1) {
        background->move(-1, 0);
        background_double->move(-1, 0);
        clock_paralax.restart();
    }
}

void game::remove_tile()
{

    sf::Vector2i cursorPos = sf::Mouse::getPosition(window);
   // (cursorPos.x >= joinPos.x && cursorPos.y >= joinPos.y &&
     //           cursorPos.x <= joinPos.x + joinSize.x && cursorPos.y <= joinPos.y + joinSize.y)
    for(int i = 0; i != tile_board.size(); i++) {
        for (int j = 0; j != tile_board[i].size(); j++) {
            sf::Vector2f tile_pos = tile_board[i][j]->getpos();
            if (cursorPos.x >= tile_pos.x + 1 && cursorPos.y >= tile_pos.y + 1 &&
                cursorPos.x <= tile_pos.x + 49 && cursorPos.y <= tile_pos.y + 49) {
                if (tile_board[i][j]->status == 0 || tile_board[i][j]->status == 1) {
                    if (tile_board[i][j]->status == 1) {
                        if (map[i][j] == 'A') {
                            sound_impact.play();
                            tile_board[i][j]->clickOn("img/asteroide.png");
                            if (player == 1)
                                nb_life1 -= 1;
                            else
                                nb_life2 -= 1;
                        }
                        if (map[i][j] == 'X') {
                            sound_good_select.play();
                            char arrow = text_map->findObjectInMap(i, j);
                            if (arrow == 'R')
                                tile_board[i][j]->clickOn("img/right.png");
                            if (arrow == 'B')
                                tile_board[i][j]->clickOn("img/bottom.png");
                            if (arrow == 'L')
                                tile_board[i][j]->clickOn("img/left.png");
                            if (arrow == 'T')
                                tile_board[i][j]->clickOn("img/top.png");
                        }
                        if (player == 2)
                            player = 1;
                        else
                            player = 2;
                        return;
                    }
                }
            }
        }
    }
}

void game::win_screen()
{
    window.draw(*winscreen);
    if (nb_life1 == 0)
        window.draw(*won_2);
    else
        window.draw(*won_1);
    if (hover_status == 0)
        window.draw(*restart_no);
    if (hover_status == 1)
        window.draw(*restart);
}

void game::check_restart()
{
    sf::Vector2i cursorPos = sf::Mouse::getPosition(window);
    sf::Vector2f buttonPos = restart_no->getPosition();


            if (cursorPos.x >= buttonPos.x && cursorPos.y >= buttonPos.y &&
                cursorPos.x <= buttonPos.x + 450 && cursorPos.y <= buttonPos.y + 132) {
                if (hover_status == 0)
                    sound_hover.play();
                hover_status = 1;
            }
            else
                hover_status = 0;
}

void game::restart_game()
{
    nb_life1 = 3;
    nb_life2 = 3;

    map.clear();
    tile_board.clear();
    create_board();
}

int game::game_loop()
{
    int instruction;
    window_height = sf::VideoMode::getDesktopMode().height;
    window_width = sf::VideoMode::getDesktopMode().width;

    window.create(sf::VideoMode(window_width, window_height), "123BooM");

    background->scale(window_width/4096, window_height/4096);
    background_double->scale(window_width/4096, window_height/4096);
    winscreen->scale(window_width, window_height);
    background_double->setPosition(window_width, 0);
    won_1->setPosition(window_width/2 - 500, 100);
    won_2->setPosition(window_width/2 - 500, 100);
    restart->setPosition(window_width/2 - 225, 650);
    restart_no->setPosition(window_width/2 - 225, 650);
    create_board();

    sf::SoundBuffer buffer;
    sf::SoundBuffer buffer_2;
    sf::SoundBuffer buffer_3;
    buffer.loadFromFile("img/hover.wav");
    sound_hover.setBuffer(buffer);
    buffer_2.loadFromFile("img/good_select.wav");
    sound_good_select.setBuffer(buffer_2);
    buffer_3.loadFromFile("img/impact.wav");
    sound_impact.setBuffer(buffer_3);
    title_1->setPosition(50,window_height/2 - 12);
    title_2->setPosition(window_width - 807, window_height/2 - 12);
    //UDPServerData data;
    //data.id = -1;


    while (window.isOpen()) {
        // data = receiveMove();
        // manage_play->move_player_2(data.id, data.x);
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                //destroy_objct();
                window.close();
                return 1;
            }
            if (nb_life1 > 0 && nb_life2 > 0) {
                check_hover();
            //         current_page_menu = manage_menu->manage_event();
            //         manage_data_event_menu();
            //     }
                if (event.type == sf::Event::MouseButtonReleased) {
                // sound_good_select.play();
                    remove_tile();
                }
            }
            else if (nb_life1 == 0 || nb_life2 == 0) {
                if (event.type == sf::Event::MouseButtonReleased) {
                    restart_game();
                }
                check_restart();
            }
        }
        move_paralax();
        window.clear(sf::Color::Black);
        window.draw(*background);
        window.draw(*background_double);
        if (player == 2 && nb_life2 > 0 && nb_life1 > 0)
            window.draw(*title_1);
        else if (nb_life1 > 0 && nb_life2 > 0)
            window.draw(*title_2);
        draw_board();
        draw_life();

        if (nb_life1 == 0 || nb_life2 == 0) {
            win_screen();
        }
        // if (game_status == MENU || game_status == WAIT)
        //     manage_menu->display_object();
        // if (game_status == GAME) {
        //  //   manage_play->move_player(_client->getData());
        //     manage_play->display();
        // }s
        window.display();
    }
    return 0;
}
