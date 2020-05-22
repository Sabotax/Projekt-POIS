#ifndef CHARACTER_H
#define CHARACTER_H
#include "Header.h"

class Character {
public:
    std::shared_ptr< Tile > polozenie_tile;
    std::string test;
    std::shared_ptr< sf::Sprite > sprite;
    double moment_animacji;
    static double czas_animacji;
    bool czy_w_trakcie_animacji;
    void move(const std::string& direction, const double& elapsed);
    void start_move();
    Character();
};
#endif // CHARACTER_H
