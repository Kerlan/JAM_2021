/*
** EPITECH PROJECT, 2021
** 123Boom
** File description:
** JAM_2021
*/

#ifndef MAKAMAP_HPP
#define MAKAMAP_HPP

#include <vector>
#include <utility>
#include <iostream>
#include "Constants.hpp"
#include <time.h>
#include <stdlib.h>

class MakeMap
{
private:
    void createMap();
    void addObjectInMap();
    int cl;
    int ln;
public:
    MakeMap(int cl, int ln);
    ~MakeMap();
    void printMap();
    char findObjectInMap(int x, int y);
    std::vector<std::vector<char>> getMap();
    std::vector<std::vector<char>> map;
    std::vector<std::pair<int, int>> objects;
};


#endif /* !MAKAMAP_HPP */
