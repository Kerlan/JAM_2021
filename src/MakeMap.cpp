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
    addObjectInMap();
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

void MakeMap::addObjectInMap()
{
    std::pair<int, int> p;

    for (int i = 1; i < 6; i++) {
        p.first = rand() % cl;
        p.second = rand() % ln;
        for (int j = 0; j < this->objects.size(); j++) {
            if (this->objects[j] == p) {
                j = 0;
                p.first = rand() % cl;
                p.second = rand() % ln;
            }
        }
        this->objects.push_back(p);
    }
    for (int i = 0; i < this->objects.size(); i++) {
        this->map[this->objects[i].first][this->objects[i].second] = i + 49;
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

char MakeMap::findObjectInMap(int x, int y)
{
    int s = 0;

    for (int i = 0; i < this->objects.size(); i++) {
        if (abs((x + y) - (this->objects[i].first + this->objects[i].second)) < s)
            s = i;
    }
    
    if (abs(x - this->objects[s].first) > abs(y - this->objects[s].second)) {
        if ((x - this->objects[s].first) > 0) {
            return 'R';
        } else {
            return 'L';
        }
    } else {
        if ((y - this->objects[s].second) > 0) {
            return 'B';
        } else {
            return 'T';
        }
    }
}

std::vector<std::vector<char>> MakeMap::getMap()
{
    return this->map;
}