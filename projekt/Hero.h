#ifndef HERO_H
#define HERO_H

#include "Header.h"

class Hero : public Character {
public:
    Hero(const sf::Texture& texture, std::shared_ptr<Tile> tile);
    void strzel(std::string zwrot);
    bool czy_strzelil_w_tej_turze = false;
    static std::shared_ptr<Hero> hero1;
};

#endif // HERO_H
