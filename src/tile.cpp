#include "../include/tile.hpp"

tile::tile(sf::RenderWindow *isWindow, tile_type isType,  int isPos_x, int isPos_y)
{
    window = isWindow;
    //tile_type = isType;
    sprite = create_sprite("img/tile.png");
    sprite_hover_2 = create_sprite("img/tile_hover_2.png");
    sprite_hover_1 = create_sprite("img/tile_hover_1.png");
    pos_x = isPos_x;
    pos_y = isPos_y;
    sprite->setPosition(pos_x, pos_y);
    sprite_hover_1->setPosition(pos_x, pos_y);
    sprite_hover_2->setPosition(pos_x, pos_y);
    status = 0;
}

sf::Texture *tile::create_texture(std::string name) const
{
     sf::Texture *texture = new sf::Texture;
    if (texture->loadFromFile(name))
        return (texture);
    texture = NULL;
    return (texture);
}

void tile::draw_tile(int player)
{
    if (status == 0)
        window->draw(*sprite);
    if (status == 2)
        window->draw(*sprite_activate);
    if (status == 1 && player == 1)
        window->draw(*sprite_hover_1);
    if (status == 1 && player == 2)
        window->draw(*sprite_hover_2);
}

sf::Sprite *tile::create_sprite(sf::Texture *texture) const
{
    sf::Sprite *sprite = new sf::Sprite;
    sprite->setTexture(*texture);
    return (sprite);
}

void tile::clickOn(std::string buffer)
{
    sprite_activate = create_sprite(buffer);
    sprite_activate->setPosition(pos_x, pos_y);
    status = 2;
}

sf::Vector2f tile::getpos()
{
    sf::Vector2f pos;
    pos.x = pos_x;
    pos.y = pos_y;
    return pos;
}

sf::Sprite *tile::create_sprite(std::string name) const
{
    sf::Texture *tmp = new sf::Texture;
    tmp = create_texture(name);
    if (tmp == NULL)
        create_sprite(name);
    return (create_sprite(tmp));
}
