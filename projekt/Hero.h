#ifndef HERO_H
#define HERO_H

#include "Header.h"

class Hero : public Character {
public:
    Hero(const sf::Texture& texture, std::shared_ptr<Tile> tile);
    void strzel(std::string zwrot);
};

#endif // HERO_H
