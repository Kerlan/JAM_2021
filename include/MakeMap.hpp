/*
** EPITECH PROJECT, 2021
** 123Boom
** File description:
** JAM_2021
*/

#ifndef MAKAMAP_HPP
#define MAKAMAP_HPP

#include <vector>
#include <iostream>
#include "Constants.hpp"

class MakeMap
{
private:
    void createMap();
    int cl;
    int ln;
public:
    MakeMap(int cl, int ln);
    ~MakeMap();
    void printMap();
    std::vector<std::vector<char>> map;
};


#endif /* !MAKAMAP_HPP */
