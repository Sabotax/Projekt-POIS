#ifndef HERO_H
#define HERO_H

#include "Header.h"

class Hero : public Character {
public:
    Hero(const sf::Texture& texture, std::shared_ptr<Tile> tile);
};

#endif // HERO_H
