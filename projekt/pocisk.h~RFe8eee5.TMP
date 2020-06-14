#ifndef POCISK_H
#define POCISK_H
#include "Header.h"

class pocisk
{
public:
    std::string zwrot;
    int speed = 1000;
    std::shared_ptr<sf::RectangleShape> sprite;
    pocisk(std::string zwrot, std::shared_ptr<Tile> startowy_tile);
    void animuj(double elapsed);
    static std::vector<std::shared_ptr<pocisk>> pociski;
    std::shared_ptr<pocisk> getptr();
};

#endif // POCISK_H
