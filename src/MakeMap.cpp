/*
** EPITECH PROJECT, 2021
** 123Boom
** File description:
** JAM_2021
*/

#include "include/MakeMap.hpp"

MakeMap::MakeMap(int cl, int ln) : cl(cl), ln(ln)
{
    createMap();
}

MakeMap::~MakeMap()
{
}

void MakeMap::createMap()
{
    for (int i = 0; i < this->cl; i++) {
        std::vector<char> line;
        for (int j = 0; j < this->ln; j++) {
            line.push_back('X');
        }
        this->map.push_back(line);
    }
}

void MakeMap::printMap()
{
    for (int i = 0; i < this->map.size(); i++) {
        for (int j = 0; j < this->map[i].size(); j++) {
            std::cout<<this->map[i][j];
        }
        std::cout<<std::endl;
    }
}